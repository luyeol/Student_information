#include "EveryTime_Start.h"
#include "EveryTime_Main.h"
#include "Control_CSV.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

void EveryTime::Start() {
	char n;
	cout << "모블 에브리타임에 오신것을 환영합니다!" << endl;
	cout << "먼저 로그인을 해주세요." << endl;
	cout << "종료를 원하시면 q를 눌러주세요." << endl;
	cout << "1.로그인" << endl;
	cout << "2.회원가입" << endl;
	cout << "3.비밀번호 찾기" << endl;
	cin >> n;
	switch (n)
	{
	case '1':
		system("cls");
		EveryTime::Login();
		break;
	case '2':
		system("cls");
		EveryTime::AddMember();
		break;
	case '3':
		system("cls");
		EveryTime::FindPassword();
		break;
	case 'q':
		exit(0);
		break;
	default:
		system("cls");
		cout << "잘못된 입력입니다.";
	}
}

void EveryTime::Login() {
	string student_number;
	string password;
	cout << "학번을 입력해주세요." << endl;
	cin >> student_number;
	int row = CSV::findToCSV(student_number);
	if (!row) {
		cout << "조회된 학번이 없습니다." << endl;
		return;
	}
	cout << "비밀번호를 입력해주세요." << endl;
	cin >> password;
	if (password == CSV::returnToCSV(row, 2)) {
		system("cls");
		cout << "로그인 성공!" << endl;
		MainMenu menu(row);
	}
	else
		cout << "비밀번호가 다릅니다." << endl;
}

void EveryTime::AddMember() {
	string student_number;
	string password;
	string name;
	cout << "학번을 입력해주세요." << endl;
	cin >> student_number;
	if (CSV::findToCSV(student_number)) {
		cout << "이미 있는 학번입니다. 로그인을 이용해주세요" << endl;
		return;
	}
	cout << "비밀번호를 입력해주세요." << endl;
	cin >> password;
	cout << "이름을 입력해주세요." << endl;
	cin >> name;
	CSV::addToCSV(student_number, password, name);
	system("cls");
	cout << "회원가입이 완료되었습니다." << endl;
}

void EveryTime::FindPassword() {
	string student_number;
	string password;
	string name;
	int row;
	cout << "학번을 입력해주세요." << endl;
	cin >> student_number;
	row = CSV::findToCSV(student_number);
	if (!row) {
		cout << "학번이 존재하지 않습니다.";
		return;
	}
	cout << "이름을 입력해주세요." << endl;
	cin >> name;
	if (name != CSV::returnToCSV(row, 3)) {
		system("cls");
		cout << "이름이 맞지 않습니다." << endl;
		return;
	}
	cout << "새 비밀번호를 입력해주세요." << endl;
	cin >> password;
	CSV::writeToCSV(row, 2, password);
	system("cls");
	cout << "변경되었습니다.";

}