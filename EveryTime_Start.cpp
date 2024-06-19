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
	cout << "��� ���긮Ÿ�ӿ� ���Ű��� ȯ���մϴ�!" << endl;
	cout << "���� �α����� ���ּ���." << endl;
	cout << "���Ḧ ���Ͻø� q�� �����ּ���." << endl;
	cout << "1.�α���" << endl;
	cout << "2.ȸ������" << endl;
	cout << "3.��й�ȣ ã��" << endl;
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
		cout << "�߸��� �Է��Դϴ�.";
	}
}

void EveryTime::Login() {
	string student_number;
	string password;
	cout << "�й��� �Է����ּ���." << endl;
	cin >> student_number;
	int row = CSV::findToCSV(student_number);
	if (!row) {
		cout << "��ȸ�� �й��� �����ϴ�." << endl;
		return;
	}
	cout << "��й�ȣ�� �Է����ּ���." << endl;
	cin >> password;
	if (password == CSV::returnToCSV(row, 2)) {
		system("cls");
		cout << "�α��� ����!" << endl;
		MainMenu menu(row);
	}
	else
		cout << "��й�ȣ�� �ٸ��ϴ�." << endl;
}

void EveryTime::AddMember() {
	string student_number;
	string password;
	string name;
	cout << "�й��� �Է����ּ���." << endl;
	cin >> student_number;
	if (CSV::findToCSV(student_number)) {
		cout << "�̹� �ִ� �й��Դϴ�. �α����� �̿����ּ���" << endl;
		return;
	}
	cout << "��й�ȣ�� �Է����ּ���." << endl;
	cin >> password;
	cout << "�̸��� �Է����ּ���." << endl;
	cin >> name;
	CSV::addToCSV(student_number, password, name);
	system("cls");
	cout << "ȸ�������� �Ϸ�Ǿ����ϴ�." << endl;
}

void EveryTime::FindPassword() {
	string student_number;
	string password;
	string name;
	int row;
	cout << "�й��� �Է����ּ���." << endl;
	cin >> student_number;
	row = CSV::findToCSV(student_number);
	if (!row) {
		cout << "�й��� �������� �ʽ��ϴ�.";
		return;
	}
	cout << "�̸��� �Է����ּ���." << endl;
	cin >> name;
	if (name != CSV::returnToCSV(row, 3)) {
		system("cls");
		cout << "�̸��� ���� �ʽ��ϴ�." << endl;
		return;
	}
	cout << "�� ��й�ȣ�� �Է����ּ���." << endl;
	cin >> password;
	CSV::writeToCSV(row, 2, password);
	system("cls");
	cout << "����Ǿ����ϴ�.";

}