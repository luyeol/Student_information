#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Control_CSV.h"
#include "EveryTime_Graduate.h"
#include "EveryTime_Main.h"
#include <Windows.h>
using namespace std;

void Graduate::start() {
	int input_graduate = 0;
	char input_ok = NULL;

	cout << "=======================================" << endl;
	cout << "졸업 사정 결과 확인란 입니다." << endl;
	cout << "졸업하기 위해서는 130학점 이상이여야 합니다." << endl;
	cout << "그리고, 자격증 또는 현장학습을 이수하셔야 합니다." << endl;
	cout << "=======================================" << endl;
	cout << "업데이트를 원하시면 1번을, 조회를 하고 싶으면 2번을 누르세요." << endl;

	cin >> input_graduate;

	switch (input_graduate) {
	case 1:
		Graduate::survey();
		cout << "확인을 완료 하셨으면 아무키나 입력해주세요.";
		cin >> input_ok;
		system("cls");
		break;
	case 2:
		Graduate::condition();
		cout << "확인을 완료 하셨으면 아무키나 입력해주세요.";
		cin >> input_ok;
		system("cls");
		break;
	default:
		system("cls");
		cout << "잘못 입력하셨습니다." << endl;
		break;
	}
}


void Graduate::condition() {
	int can_graduate = 0;
	string grade_input = CSV::returnToCSV(row, col);
	string degree = CSV::returnToCSV(row, col+1);
	string work = CSV::returnToCSV(row, col+2);
	string homework = CSV::returnToCSV(row, col+3);

	if ((grade_input == "null") || (degree == "null") || (work == "null") || (homework == "null")) {
		cout << "오류 : 데이터가 없습니다." << endl;
		return;
	}
	int grade = stoi(CSV::returnToCSV(row, col));
	cout << "자격증 :" << degree << " /현장학습 :" << work << " /졸업작품 :" << homework << endl;
	cout << "현재 총 학점은 " << grade << "점입니다." << endl;



	if (grade < 130)
		cout << "현재 졸업학점에 충족하지 않으며,";
	else
		cout << "현재 졸업학점에 충족하며,";


	if ((degree[0] == 'o' || work[0] == 'o' || homework[0] == 'o') && grade >= 130)
		can_graduate = 1;
	else
		can_graduate = 0;


	if (can_graduate == 1)
		cout << "졸업요건이 충족합니다." << endl;
	else
		cout << "졸업요건이 충족하지 않습니다." << endl;
	cout << "=======================================" << endl;
}


void Graduate::survey() {

	string degree_ok;
	string work_ok;
	string homework_ok;
	string grade;
	bool degree_ok_flag = false;
	bool work_ok_flag = false;
	bool homework_ok_flag = false;

	cout << "업데이트 항목 설문입니다." << endl;
	cout << "현재 자격증을 취득하셨습니까? (o,x)" << endl;
	cin >> degree_ok;

	cout << "현장학습을 이수한 적이 있습니까? (o,x)" << endl;
	cin >> work_ok;


	cout << "졸업작품을 진행한 적이 있습니까? (o,x)" << endl;
	cin >> homework_ok;


	cout << "총 학점을 입력하시오 : " << endl;
	cin >> grade;

	if ((degree_ok[0] != 'o') && (degree_ok[0] != 'x')) {
		cout << "자격증 입력 내용이 정확하지 않습니다." << endl;
		degree_ok_flag = true;
	}
	if ((work_ok[0] != 'o') && (work_ok[0] != 'x')) {
		cout << "현장학습 입력 내용이 정확하지 않습니다." << endl;
		work_ok_flag = true;
	}

	if ((homework_ok[0] != 'o') && (homework_ok[0] != 'x')) {
		cout << "졸업작품 입력 내용이 정확하지 않습니다." << endl;
		homework_ok_flag = true;
	}

	if ((!degree_ok_flag) && (!work_ok_flag) && (!homework_ok_flag)) {
		CSV::writeToCSV(row, col, grade);
		CSV::writeToCSV(row, col+1, degree_ok);
		CSV::writeToCSV(row, col+2, work_ok);
		CSV::writeToCSV(row, col+3, homework_ok);
	}

}



void Graduate::return_grade(int can_graduate) {

	if (can_graduate == 1)
		cout << "졸업요건이 충족합니다." << endl;
	else
		cout << "졸업요건이 충족하지 않습니다." << endl;
	cout << "=======================================" << endl;

}