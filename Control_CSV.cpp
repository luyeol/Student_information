#include "Control_CSV.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
const string filename = "Moble_DB.csv";

void CSV::dataInCSV(const vector<vector<string>>& data, const string& filename) {
	ofstream file(filename);
	if (!file.is_open()) {
		cerr << "Failed to open file: " << filename << endl;
		return;
	}

	for (size_t i = 0; i < data.size(); ++i) {
		for (size_t j = 0; j < data[i].size(); ++j) {
			file << data[i][j];
			if (j != data[i].size() - 1)
				file << ",";
		}
		file << endl;
	}

	file.close();
}
void CSV::writeToCSV(int row, int column, string content) {
	row -= 1;
	column -= 1;

	// CSV ���� �б�
	ifstream file(filename);
	if (!file.is_open()) {
		cerr << "Failed to open file: " << filename << endl;
	}

	vector<vector<string>> data;
	string line;
	while (getline(file, line)) {
		vector<string> v_row;
		size_t start = 0, end = 0;
		while ((end = line.find(',', start)) != string::npos) {
			v_row.push_back(line.substr(start, end - start));
			start = end + 1;
		}
		v_row.push_back(line.substr(start));
		data.push_back(v_row);
	}
	file.close();

	// ������ ����
	if (row < data.size() && column < data[row].size()) {
		data[row][column] = content; // �����ϰ��� �ϴ� �����ͷ� ��ü
	}
	else {
		cerr << "Invalid row or column index." << endl;
	}

	// ������ �����͸� CSV ���Ϸ� ����
	dataInCSV(data, filename);
	//cout << "��û�� ���� �ۼ� �Ϸ��߽��ϴ�. " << filename << endl;
}

void CSV::addToCSV(string student_number, string password, string name) {

	// CSV ���� �б�
	ifstream file(filename);
	if (file.is_open()) {
		vector<vector<string>> data;
		string line;
		if (file.peek() != ifstream::traits_type::eof()) {
			while (getline(file, line)) {
				vector<string> row;
				size_t start = 0, end = 0;
				while ((end = line.find(',', start)) != string::npos) {
					row.push_back(line.substr(start, end - start));
					start = end + 1;
				}
				row.push_back(line.substr(start));
				data.push_back(row);
			}
		}
		file.close();

		// ���ο� �� �߰�
		vector<string> new_row;
		new_row.push_back(student_number); // �й� �߰�
		new_row.push_back(password);      // ��й�ȣ �߰�
		new_row.push_back(name);          // �̸� �߰�
		for(int i=0;i<14;i++)
			new_row.push_back("null");        // ����ִ� �� �߰�
		data.push_back(new_row);

		// CSV ���Ͽ� ������ ����
		dataInCSV(data, filename);
		//cout << "New row added to " << filename << endl;
	}
	else {
		// ������ ������ ���� �� ���� �޽��� ���
		cerr << "������ �������� �ʽ��ϴ�. �� ������ ����ϴ�." << filename << endl;

		vector<string> Field;
		Field.push_back("�й�");
		Field.push_back("��й�ȣ");
		Field.push_back("�̸�");
		Field.push_back("1�б� ����");
		Field.push_back("2�б� ����");
		Field.push_back("3�б� ����");
		Field.push_back("4�б� ����");
		Field.push_back("5�б� ����");
		Field.push_back("6�б� ����");
		Field.push_back("7�б� ����");
		Field.push_back("8�б� ����");
		Field.push_back("��� ����");
		Field.push_back("���� ����");
		Field.push_back("�ڰ���");
		Field.push_back("�����н�");
		Field.push_back("������ǰ");
		Field.push_back("������Ȳ");

		// ���ο� �� �߰�
		vector<string> new_row;
		new_row.push_back(student_number); // �й� �߰�
		new_row.push_back(password);      // ��й�ȣ �߰�
		new_row.push_back(name);          // �̸� �߰�
		for (int i = 0; i < 14; i++)
			new_row.push_back("null");        // ����ִ� �� �߰�

		vector<vector<string>> data;
		data.push_back(Field);
		data.push_back(new_row);

		// CSV ���Ͽ� ������ ����
		dataInCSV(data, filename);
		//cout << "New CSV file created: " << filename << endl;
	}
}

int CSV::findToCSV(string student_number) {

	// CSV ���� �б�
	ifstream file(filename);
	if (!file.is_open()) {
		//cerr << "Failed to open file: " << filename << endl;
		return 0;
	}

	vector<vector<string>> data;
	string line;
	while (getline(file, line)) {
		vector<string> row;
		size_t start = 0, end = 0;
		while ((end = line.find(',', start)) != string::npos) {
			row.push_back(line.substr(start, end - start));
			start = end + 1;
		}
		row.push_back(line.substr(start));
		data.push_back(row);
	}
	file.close();

	// ������ ����
	size_t target_col = 0; // Ž���� �� �ε���
	string target_value = student_number; // Ž���� ��
	size_t target_row = 0; // ����� ���� �� �ε���

	// �� ��ȸ�ϸ� Ž��
	for (size_t i = 0; i < data.size(); ++i) {
		if (data[i].size() > target_col && data[i][target_col] == target_value) {
			target_row = i + 1; // ���ϴ� ���� �߰ߵǸ� �ش� �� �ε����� �����ϰ� ���� ����
			break;
		}
	}

	if (target_row != 0) {
		//cout << "Found target value at row: " << target_row << endl;
		return target_row;
	}
	else {
		return 0;
	}

}

string CSV::returnToCSV(int row, int column) {
	row -= 1;
	column -= 1;

	// CSV ���� �б�
	ifstream file(filename);
	if (!file.is_open()) {
		cerr << "Failed to open file: " << filename << endl;
		return "";
	}

	vector<vector<string>> data;
	string line;
	while (getline(file, line)) {
		vector<string> row;
		size_t start = 0, end = 0;
		while ((end = line.find(',', start)) != string::npos) {
			row.push_back(line.substr(start, end - start));
			start = end + 1;
		}
		row.push_back(line.substr(start));
		data.push_back(row);
	}
	file.close();

	// ��û�� ��� ���� �ִ� ������ ��ȯ
	if (row < data.size() && column < data[row].size()) {
		return data[row][column];
	}
	else {
		cerr << "Invalid row or column index." << endl;
		return "";
	}
}