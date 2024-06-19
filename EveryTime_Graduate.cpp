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
	cout << "���� ���� ��� Ȯ�ζ� �Դϴ�." << endl;
	cout << "�����ϱ� ���ؼ��� 130���� �̻��̿��� �մϴ�." << endl;
	cout << "�׸���, �ڰ��� �Ǵ� �����н��� �̼��ϼž� �մϴ�." << endl;
	cout << "=======================================" << endl;
	cout << "������Ʈ�� ���Ͻø� 1����, ��ȸ�� �ϰ� ������ 2���� ��������." << endl;

	cin >> input_graduate;

	switch (input_graduate) {
	case 1:
		Graduate::survey();
		cout << "Ȯ���� �Ϸ� �ϼ����� �ƹ�Ű�� �Է����ּ���.";
		cin >> input_ok;
		system("cls");
		break;
	case 2:
		Graduate::condition();
		cout << "Ȯ���� �Ϸ� �ϼ����� �ƹ�Ű�� �Է����ּ���.";
		cin >> input_ok;
		system("cls");
		break;
	default:
		system("cls");
		cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
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
		cout << "���� : �����Ͱ� �����ϴ�." << endl;
		return;
	}
	int grade = stoi(CSV::returnToCSV(row, col));
	cout << "�ڰ��� :" << degree << " /�����н� :" << work << " /������ǰ :" << homework << endl;
	cout << "���� �� ������ " << grade << "���Դϴ�." << endl;



	if (grade < 130)
		cout << "���� ���������� �������� ������,";
	else
		cout << "���� ���������� �����ϸ�,";


	if ((degree[0] == 'o' || work[0] == 'o' || homework[0] == 'o') && grade >= 130)
		can_graduate = 1;
	else
		can_graduate = 0;


	if (can_graduate == 1)
		cout << "��������� �����մϴ�." << endl;
	else
		cout << "��������� �������� �ʽ��ϴ�." << endl;
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

	cout << "������Ʈ �׸� �����Դϴ�." << endl;
	cout << "���� �ڰ����� ����ϼ̽��ϱ�? (o,x)" << endl;
	cin >> degree_ok;

	cout << "�����н��� �̼��� ���� �ֽ��ϱ�? (o,x)" << endl;
	cin >> work_ok;


	cout << "������ǰ�� ������ ���� �ֽ��ϱ�? (o,x)" << endl;
	cin >> homework_ok;


	cout << "�� ������ �Է��Ͻÿ� : " << endl;
	cin >> grade;

	if ((degree_ok[0] != 'o') && (degree_ok[0] != 'x')) {
		cout << "�ڰ��� �Է� ������ ��Ȯ���� �ʽ��ϴ�." << endl;
		degree_ok_flag = true;
	}
	if ((work_ok[0] != 'o') && (work_ok[0] != 'x')) {
		cout << "�����н� �Է� ������ ��Ȯ���� �ʽ��ϴ�." << endl;
		work_ok_flag = true;
	}

	if ((homework_ok[0] != 'o') && (homework_ok[0] != 'x')) {
		cout << "������ǰ �Է� ������ ��Ȯ���� �ʽ��ϴ�." << endl;
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
		cout << "��������� �����մϴ�." << endl;
	else
		cout << "��������� �������� �ʽ��ϴ�." << endl;
	cout << "=======================================" << endl;

}