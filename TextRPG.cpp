#include<iostream>
#include<time.h>
using namespace std;


// 숙제
//1. 무기상점에서 판매할 아이템 목록을 만들어주고 해당 목록을 출력해준다.
//2. 출력할때 앞에 번호를 부여해주고 번호를 입력받아서 해당 번호의 아이템을
//구입하게 해준다. 가장 마지막 번호에 뒤로가기 기능을 만든다.
//단, 가방이 꽉 찼거나 돈이 부족할 경우 구매하지 못하게 한다.
//3. 가방을 선택하면 가방안의 아이템을 보여준다.

enum MAIN_MENU 
{
	MM_NONE,
	MM_MAP,
	MM_STORE,
	MM_INVENTORY,
	MM_EXIT
};

enum MAP_TYPE 
{
	MT_NONE,
	MT_EASY,
	MT_NORMAL,
	MT_HARD,
	MT_BACK
};

enum JOB 
{
	JOB_NONE,
	JOB_KNIGHT,
	JOB_ARCHER,
	JOB_WIZARD,
	JOB_END
};

enum BATTLE 
{
	BATTLE_NONE,
	BATTLE_ATTACK,
	BATTLE_BACK
};

enum ITEM_TYPE
{
	IT_NONE,
	IT_WEAPON,
	IT_ARMOR,
	IT_BACK
};

enum STORE_MENU
{
	SM_NONE,
	SM_WEAPON,
	SM_ARMOR,
	SM_BACK
};

#define NAME_SIZE	32
#define ITEM_DESC_LENGTH	512
#define INVENROTY_MAX		20
#define STORE_WEAPON_MAX	3
#define STORE_ARMOR_MAX		3
struct _tagItem
{
	char	strName[NAME_SIZE];
	char	strTypeName[NAME_SIZE];
	ITEM_TYPE	eType;
	int		iMin;
	int		iMax;
	int		iPrice;
	int		iSell;
	char	strDesc[ITEM_DESC_LENGTH];	// 아이템 설명
};

struct _tagInventory 
{
	_tagItem	tItem[INVENROTY_MAX];
	int			iCount;
	int			iGold;
};
struct _tagPlayer
{
	char	strName[NAME_SIZE];
	char	strJobName[NAME_SIZE];
	JOB		eJob;
	int		iAttackMin;
	int		iAttackMax;
	int		iArmorMin;
	int		iArmorMax;
	int		iHP;
	int		iHPMAX;
	int		iMP;
	int		iMPMAX;
	int		iExp;
	int		iLevel;
	_tagInventory	tInventory;
};

struct _tagMonster 
{
	char	strName[NAME_SIZE];
	int		iAttackMin;
	int		iAttackMax;
	int		iArmorMin;
	int		iArmorMax;
	int		iHP;
	int		iHPMAX;
	int		iMP;
	int		iMPMAX;
	int		iLevel;
	int		iExp;
	int		iGoldMin;
	int		iGoldMax;
};
int main() {
	srand((unsigned int)time(0));

	// 게임을 시작할때 플레이어 정보를 설정하게 한다.
	_tagPlayer	tPlayer = {};

	// 플레이어 이름을 입력받는다.
	cout << "이름 : ";
	cin.getline(tPlayer.strName, NAME_SIZE - 1);
	int iJob = JOB_NONE;
	while (iJob == JOB_NONE) 
	{
		system("cls");
		cout << "1. 기사" << endl;
		cout << "2. 궁수" << endl;
		cout << "3. 마법사" << endl;
		cout << "직업을 선택하세요 : ";
		cin >> iJob;

		if (cin.fail()) 
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		else if (iJob <= JOB_NONE || iJob >= JOB_END) 
		{
			iJob = JOB_NONE;
		}

		tPlayer.iLevel = 1;
		tPlayer.iExp = 0;
		tPlayer.eJob = (JOB)iJob;
		tPlayer.tInventory.iGold = 10000;
		switch (tPlayer.eJob) 
		{
		case JOB_KNIGHT:
			strcpy_s(tPlayer.strJobName, "기사");
			tPlayer.iAttackMax = 5;
			tPlayer.iAttackMin = 10;
			tPlayer.iArmorMax = 15;
			tPlayer.iArmorMin = 20;
			tPlayer.iHPMAX = 500;
			tPlayer.iHP = 100;
			tPlayer.iMP = 100;
			tPlayer.iMPMAX = 100;
			break;
		case JOB_ARCHER:
			strcpy_s(tPlayer.strJobName, "궁수");
			tPlayer.iAttackMax = 10;
			tPlayer.iAttackMin = 15;
			tPlayer.iArmorMax = 10;
			tPlayer.iArmorMin = 15;
			tPlayer.iHPMAX = 400;
			tPlayer.iHP = 400;
			tPlayer.iMP = 200;
			tPlayer.iMPMAX = 200;
		case JOB_WIZARD:
			strcpy_s(tPlayer.strJobName, "마법사");
			tPlayer.iAttackMax = 15;
			tPlayer.iAttackMin = 20;
			tPlayer.iArmorMax = 5;
			tPlayer.iArmorMin = 10;
			tPlayer.iHPMAX = 300;
			tPlayer.iHP = 300;
			tPlayer.iMP = 300;
			tPlayer.iMPMAX = 300;
			break;
		}
	}

	// 몬스터를 생성한다.
	_tagMonster tMonsterArr[MT_BACK - 1] = {};

	// 고블린 생성
	strcpy_s(tMonsterArr[0].strName, "고블린");
	tMonsterArr[0].iAttackMin = 20;
	tMonsterArr[0].iAttackMax = 30;
	tMonsterArr[0].iArmorMin = 2;
	tMonsterArr[0].iArmorMax = 5;
	tMonsterArr[0].iHP = 100;
	tMonsterArr[0].iHPMAX = 100;
	tMonsterArr[0].iMP = 10;
	tMonsterArr[0].iMPMAX = 10;
	tMonsterArr[0].iLevel = 1;
	tMonsterArr[0].iExp = 1000;
	tMonsterArr[0].iGoldMin = 500;
	tMonsterArr[0].iGoldMax = 1500;

	// 트롤
	strcpy_s(tMonsterArr[1].strName, "트롤");
	tMonsterArr[1].iAttackMin = 80;
	tMonsterArr[1].iAttackMax = 130;
	tMonsterArr[1].iArmorMin = 60;
	tMonsterArr[1].iArmorMax = 90;
	tMonsterArr[1].iHP = 2000;
	tMonsterArr[1].iHPMAX = 2000;
	tMonsterArr[1].iMP = 100;
	tMonsterArr[1].iMPMAX = 100;
	tMonsterArr[1].iLevel = 5;
	tMonsterArr[1].iExp = 7000;
	tMonsterArr[1].iGoldMin = 6000;
	tMonsterArr[1].iGoldMax = 8000;
	// 드래곤 생성
	strcpy_s(tMonsterArr[2].strName, "드래곤");
	tMonsterArr[2].iAttackMin = 250;
	tMonsterArr[2].iAttackMax = 500;
	tMonsterArr[2].iArmorMin = 200;
	tMonsterArr[2].iArmorMax = 400;
	tMonsterArr[2].iHP = 30000;
	tMonsterArr[2].iHPMAX = 30000;
	tMonsterArr[2].iMP = 20000;
	tMonsterArr[2].iMPMAX = 20000;
	tMonsterArr[2].iLevel = 10;
	tMonsterArr[2].iExp = 30000;
	tMonsterArr[2].iGoldMin = 20000;
	tMonsterArr[2].iGoldMax = 50000;

	// 상점에서 판매할 아이템 목록을 생성한다.
	_tagItem	tStoreWeapon[STORE_WEAPON_MAX] = {};
	_tagItem	tStoreArmor[STORE_ARMOR_MAX] = {};

	// 각 아이템 정보들을 설정해준다.
	
	while (true) 
	{
		system("cls");
		cout << "*********************** 로비 ***********************" << endl;
		cout << "1. 맵" << endl;
		cout << "2. 상점" << endl;
		cout << "3. 가방" << endl;
		cout << "4. 종료" << endl;
		cout << "메뉴를 선택하세요 : ";
		int iMenu;
		cin >> iMenu;

		if (cin.fail()) 
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (iMenu == MM_EXIT) 
		{
			break;
		}

		switch (iMenu) 
		{
		case MM_MAP:
			while (true) 
			{
				system("cls");
				cout << "*********************** 맵 ***********************" << endl;
				cout << "1. 쉬움" << endl;
				cout << "2. 보통" << endl;
				cout << "3. 어려움" << endl;
				cout << "4. 뒤로가기" << endl;
				cout << "맵을 선택하세요 : ";
				cin >> iMenu;

				if (cin.fail()) 
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				// 이 if문에 속한 break는 맵 메뉴를 돌려주기 위한 while에 속해 있으므로
				// 이 whiile문을 빠져나간다.
				if (iMenu == MT_BACK)
					break;

				// 선택한 메뉴에서 1을 빼주면 몬스터 배열의 인덱스가 된다.
				// 그렇게 해서 해당 맵의 몬스터를 생성해준다.
				_tagMonster tMonster = tMonsterArr[iMenu - 1];

				while (true) 
				{
					system("cls");
					switch (iMenu) 
					{
					case MT_EASY:
						cout << "*********************** 쉬움 ***********************" << endl;
						break;
					case MT_NORMAL:
						cout << "*********************** 보통 ***********************" << endl;
						break;
					case MT_HARD:
						cout << "*********************** 어려움 ***********************" << endl;
						break;
					}

					// 플레이어 정보를 출력한다.
					cout << "======================= Player =======================" << endl;
					cout << "이름 : " << tPlayer.strName << "\t직업 : " <<
						tPlayer.strJobName << endl;
					cout << "레벨 : " << tPlayer.iLevel << "\t경험치 : " <<
						tPlayer.iExp << endl;
					cout << "공격력 : " << tPlayer.iAttackMin << " - " <<
						tPlayer.iAttackMax << "\t방어력 : " << tPlayer.iArmorMin << " - " << tPlayer.iArmorMax << endl;
					cout << "체력 : " << tPlayer.iHP << " / " <<
						tPlayer.iHPMAX << "\t마나 : " << tPlayer.iMP << " - " << tPlayer.iMPMAX << endl;
					cout << "보유골드 : " << tPlayer.tInventory.iGold << " Gold" << endl;

					// 몬스터 정보 출력
					cout << "======================= Monster =======================" << endl;
					cout << "이름 : " << tMonster.strName << "\t레벨 : " <<
						tMonster.iLevel << endl;
					cout << "공격력 : " << tMonster.iAttackMin << " - " <<
						tMonster.iAttackMax << "\t방어력 : " << tMonster.iArmorMin << " - " << tMonster.iArmorMax << endl;
					cout << "체력 : " << tMonster.iHP << " / " <<
						tMonster.iHPMAX << "\t마나 : " << tMonster.iMP << " - " << tMonster.iMPMAX << endl;
					cout << "획득경험치 : " << tMonster.iExp << "\t획득골드 : " << tMonster.iGoldMin << " - " << tMonster.iGoldMax << endl;

					cout << "1. 공격" << endl;
					cout << "2. 도망가기" << endl;
					cout << "메뉴를 선택하세요 : " << endl;
					cin >> iMenu;

					if (cin.fail()) 
					{
						cin.clear();
						cin.ignore(1024, '\n');
						continue;
					}


					else if (iMenu == BATTLE_BACK)
						break;
					switch (iMenu) 
					{
					case BATTLE_ATTACK: 
					{
						// 예를 들어 Min 5 Max 15 라고 가정할 경우
						// 15 - 5 + 1 을 하면 11이 된다. 11로 나눈 나머지는 0~10이
						// 나오게 되고 여기에 Min값인 5를 더하게 되면
						// 5 ~ 15 사이로 값이 나오게 되는 것이다.
						int iAttack = rand() % (tPlayer.iAttackMax - tPlayer.iAttackMin + 1) +
							tPlayer.iAttackMin;
						int iArmor = rand() % (tMonster.iArmorMax - tMonster.iArmorMin + 1) +
							tMonster.iArmorMin;

						int iDamage = iAttack - iArmor;
						iDamage = iDamage < 1 ? 1 : iDamage;

						// 몬스터 HP를 감소시킨다.
						tMonster.iHP -= iDamage;

						cout << tPlayer.strName << " 가 " << tMonster.strName <<
							"에게 " << iDamage << " 피해를 입혔습니다." << endl;

						// 몬스터가 죽었을 경우를 처리한다.
						if (tMonster.iHP <= 0) 
						{
							cout << tMonster.strName << " 몬스터가 사망하였습니다." << endl;

							tPlayer.iExp += tMonster.iExp;
							int iGold = (rand() % (tMonster.iGoldMax - tMonster.iGoldMin + 1) +
								tMonster.iGoldMin);
							tPlayer.tInventory.iGold += iGold;

							cout << tMonster.iExp << " 경험치를 획득하였습니다." << endl;
							cout << iGold << " Gold를 획득하였습니다." << endl;

							tMonster.iHP = tMonster.iHPMAX;
							tMonster.iMP = tMonster.iMPMAX;

							system("pause");
							break;
						}

						// 몬스터가 살아있다면 플레이어를 공격한다.
						iAttack = rand() % (tMonster.iAttackMax - tMonster.iAttackMin + 1) +
							tMonster.iAttackMin;
						iArmor = rand() % (tPlayer.iArmorMax - tPlayer.iArmorMin + 1) +
							tPlayer.iArmorMin;

						iDamage = iAttack - iArmor;
						iDamage = iDamage < 1 ? 1 : iDamage;

						// 플레이어의 HP를 감소시킨다.
						tPlayer.iHP -= iDamage;

						cout << tMonster.strName << " 가 " << tPlayer.strName <<
							"에게 " << iDamage << " 피해를 입혔습니다." << endl;

						// 플레이어가 죽었을 경우
						if (tPlayer.iHP <= 0) 
						{
							cout << tPlayer.strName << " 플레이어가 사망하였습니다." << endl;


							int iExp = tPlayer.iExp * 0.1f;
							int iGold = tPlayer.tInventory.iGold * 0.1f;

							tPlayer.iExp -= iExp;
							tPlayer.tInventory.iGold -= iGold;

							cout << iExp << " 경험치를 잃었습니다." << endl;
							cout << iGold << " Gold를 잃었습니다." << endl;

							//플레이어의 HP와 MP를 회복한다.
							tPlayer.iHP = tPlayer.iHPMAX;
							tPlayer.iMP = tPlayer.iMPMAX;
						}

						system("pause");
					}

					}

				}
			}
			break;
		case MM_STORE:
			while (true)
			{
				system("cls");
				cout << "*********************** 상점 ***********************" << endl;
				cout << "1. 무기상점" << endl;
				cout << "2. 방어구상점" << endl;
				cout << "3. 뒤로가기" << endl;
				cout << "상점을 선택하세요 : ";
				cin >> iMenu;

				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				else if (iMenu == SM_BACK)
					break;

				switch (iMenu)
				{
				case SM_WEAPON:
					while (true)
					{
						system("cls");
						cout << "*********************** 무기상점 ***********************" << endl;
						// 판매 목록을 보여준다.
					}
					break;
				case SM_ARMOR:
					break;
				}
			}
			break;
		case MM_INVENTORY:
			break;
		default:
			cout << "잘못 선택하였습니다." << endl;
			break;
		}
	}
}

