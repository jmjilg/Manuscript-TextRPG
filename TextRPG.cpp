﻿#include<iostream>
#include<time.h>
using namespace std;

enum MAIN_MENU {
	MM_NONE,
	MM_MAP,
	MM_STORE,
	MM_INVENTORY,
	MM_EXIT
};

enum MAP_TYPE {
	MT_NONE,
	MT_EASY,
	MT_NORMAL,
	MT_HARD,
	MT_BACK
};

enum JOB {
	JOB_NONE,
	JOB_KNIGHT,
	JOB_ARCHER,
	JOB_WIZARD,
	JOB_END
};

#define NAME_SIZE	32
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
};

struct _tagMonster {
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
	while (iJob == JOB_NONE) {
		system("cls");
		cout << "1. 기사" << endl;
		cout << "2. 궁수" << endl;
		cout << "3. 마법사" << endl;
		cout << "직업을 선택하세요 : ";
		cin >> iJob;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		else if (iJob <= JOB_NONE || iJob >= JOB_END) {
			iJob = JOB_NONE;
		}

		tPlayer.iLevel = 1;
		tPlayer.iExp = 0;
		tPlayer.eJob = (JOB)iJob;

		switch (tPlayer.eJob) {
		case JOB_KNIGHT:
			strcpy_s(tPlayer.strJobName, "기사");
			tPlayer.iAttackMax= 5;
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
	tMonsterArr[0].iAttackMin = 80;
	tMonsterArr[0].iAttackMax = 130;
	tMonsterArr[0].iArmorMin = 60;
	tMonsterArr[0].iArmorMax = 90;
	tMonsterArr[0].iHP = 2000;
	tMonsterArr[0].iHPMAX = 2000;
	tMonsterArr[0].iMP = 100;
	tMonsterArr[0].iMPMAX = 100;
	tMonsterArr[0].iLevel = 5;
	tMonsterArr[0].iExp = 7000;
	tMonsterArr[0].iGoldMin = 6000;
	tMonsterArr[0].iGoldMax = 8000;
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
	// 
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
	while (true) {
		system("cls");
		cout << "*********************** 로비 ***********************" << endl;
		cout << "1. 맵" << endl;
		cout << "2. 상점" << endl;
		cout << "3. 가방" << endl;
		cout << "4. 종료" << endl;
		cout << "메뉴를 선택하세요 : ";
		int iMenu;
		cin >> iMenu;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (iMenu == MM_EXIT) {
			break;
		}

		switch (iMenu) {
		case MM_MAP:
			while (true) {
				system("cls");
				cout << "*********************** 맵 ***********************" << endl;
				cout << "1. 쉬움" << endl;
				cout << "2. 보통" << endl;
				cout << "3. 어려움" << endl;
				cout << "4. 뒤로가기" << endl;
				cout << "맵을 선택하세요 : ";
				cin >> iMenu;

				if (cin.fail()) {
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

				while (true) {
					switch (iMenu) {
					case MT_EASY:
					cout << "*********************** 쉬움 ***********************" << endl;
					break;
					case MT_NORMAL:
					cout << "*********************** 보통 ***********************" << endl;
					break;
					case MT_HARD:
					cout << "*********************** 어려움 ***********************" << endl;
					break;

					// 플레이어 정보를 출력한다.
					}

				}

				switch (iMenu) {

				}
			}
			break;
		case MM_STORE:
			break;
		case MM_INVENTORY:
			break;
		default:
			cout << "잘못 선택하였습니다." << endl;
			break;
		}
	}
	return 0;
}