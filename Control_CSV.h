#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class CSV {
public:
	static void dataInCSV(const vector<vector<string>>& data, const string& filename);
	static void writeToCSV(int row, int column, string content); 
	//row�� col���� content �ۼ�
	static void addToCSV(string student_number, string password, string name); 
	// ���� �߰��� �й��� ��й�ȣ, �̸� ����
	static int findToCSV(string student_number); 
	// �й��� �ִ� ���� int������ ��ȯ, ������ 0��ȯ
	static string returnToCSV(int row, int column); 
	// row�� col���� �ִ� �����͸� string���� ��ȯ
	
	//�й�,��й�ȣ,�̸�,null,null,null ����
};
