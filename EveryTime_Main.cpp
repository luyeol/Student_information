#include "EveryTime_Main.h"
#include "EveryTime_Graduate.h"
#include "Control_CSV.h"
#include "EveryTime_Grade.h"
#include "EveryTime_Library.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>


void MainMenu::MainStart()
{

	string name = CSV::returnToCSV(row, 3);
	bool T = true;
	while (T) {
		char n;
		cout << "==============================================" << endl;
		cout << "안녕하세요! " << name << "님! 원하시는 작업을 선택해주세요." << endl;
		cout << "==============================================" << endl;
		cout << "1.성적" << endl;
		cout << "2.졸업사정결과 확인" << endl;
		cout << "3.대출 현황 확인" << endl;
		cout << "4.로그아웃" << endl;
		cout << "종료를 원하시면 q를 눌러주세요." << endl;
		cout << "==============================================" << endl;
		cin >> n;
		
		Grade page1(row);
		Graduate page2(row);
		Library page3(row);
		switch (n)
		{
		case '1':
			system("cls");
			page1.grade();
			break;
		case '2':
			system("cls");
			page2.start();
			break;
		case '3':
			system("cls");
			page3.LibraryStart();
			break;
		case '4':
			system("cls");
			cout << "로그아웃 되었습니다." << endl;
			T = false;
			break;
		case 'q':
			exit(0);
			break;
		default:
			system("cls");
			cout << "잘못된 입력입니다.";
			break;
		}
	}


}