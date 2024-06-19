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
		cout << "�ȳ��ϼ���! " << name << "��! ���Ͻô� �۾��� �������ּ���." << endl;
		cout << "==============================================" << endl;
		cout << "1.����" << endl;
		cout << "2.����������� Ȯ��" << endl;
		cout << "3.���� ��Ȳ Ȯ��" << endl;
		cout << "4.�α׾ƿ�" << endl;
		cout << "���Ḧ ���Ͻø� q�� �����ּ���." << endl;
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
			cout << "�α׾ƿ� �Ǿ����ϴ�." << endl;
			T = false;
			break;
		case 'q':
			exit(0);
			break;
		default:
			system("cls");
			cout << "�߸��� �Է��Դϴ�.";
			break;
		}
	}


}