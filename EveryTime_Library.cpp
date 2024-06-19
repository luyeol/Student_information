#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Control_CSV.h"
#include "EveryTime_Library.h"
using namespace std;

void Library::LibraryStart() {
	int Choice = 0;
	int col = 17;
	string books[3];
	while (Choice != 4)
	{
		string conbookString = CSV::returnToCSV(row, col);
		cout << "���� �ý��ۿ� �湮�ϼ̽��ϴ�." << endl;
		cout << "*��ȣ�� �����ּ���.*\n'1'.���� \n'2'.�ݳ�.\n'3'.���� ��Ȳ.\n'4'.����" << endl;
		cin >> Choice;

		switch (Choice)
		{
			//����
		case(1): {
			system("cls");
			if (conbookString.empty() || conbookString == "null") {
				cout << "������ �����ϰڽ��ϴ�." << endl;
				//cout << "������ å�� �����Ͻÿ�.(����� '_'�� ���) " << endl;
				cout << "������ å �Ǽ���?(4���̻� ����Ұ�)" << endl;
				int unm;
				cin >> unm;
				if (unm < 4) {
					for (int i = 0; i < unm; i++) {
						cout << "����" << i + 1 << endl;
						cin >> books[i];
					}
					string separator = "/"; // �����ڷ� ��ǥ�� ���
					conbookString = Choicebooks(books, unm, separator);
					CSV::writeToCSV(row, col, conbookString);
					system("cls");
					cout << "���� ���� å:" << conbookString << std::endl;
				}
				else { 
					system("cls");
					cout << "4���̻� ����Ұ�." << endl;
				}
			}
			else {
				cout << "������ å�� �־�. �����Ҽ� �����ϴ�." << endl;

			}
			break;
		}
			   //�ݳ�
		case(2): {
			system("cls");
			if (conbookString.empty() || conbookString == "null") {
				cout << "�ݳ��� å�� ���� �ݳ��� �� �� �����ϴ�." << endl;
			}
			else {
				int cohis2;
				cout << "�ݳ��� �����ϰڽ��ϴ�." << endl;
				cout << "��� �ݳ��� '1',�����ݳ��� '2',�ݳ����� ������ '3'" << endl;
				cin >> cohis2;
				if (cohis2 == 1) {
					conbookString = {};
					CSV::writeToCSV(row, col, conbookString);
					system("cls");
					cout << "��� �ݳ� �Ǿ����ϴ�." << std::endl;
				}
				else if (cohis2 == 2) {
					vector<string> split_result = split(conbookString, "/");
					
						for (int i = 0; i < split_result.size(); i++) {
							cout << "���� " << i + 1 << " : " << split_result[i] << endl;
						}
					cout << "�ݳ��� ������ �����Դϱ�?" << endl;
					int sh;
					cin >> sh;
					system("cls");
					cout << "����" << sh << " �ݳ�" << endl;
					split_result[sh - 1] = {};
					string new_conbookString;
					for (int i = 0; i < split_result.size(); i++) {
						if (!split_result[i].empty()) {
							if (!new_conbookString.empty())
								new_conbookString += "/";
							new_conbookString += split_result[i];
						}
					}
					conbookString = new_conbookString;
					CSV::writeToCSV(row, col, conbookString);
					cout << "���� ���� å:" << conbookString << std::endl;
				}
				else {
					cout << "�ݳ����� ����" << endl;
				}
			}
			break;
		}
		case(3): {
			system("cls");
			cout << "-�������-" << endl;
			conbookString = CSV::returnToCSV(row, col);
			if (conbookString.empty()|| conbookString == "null") {
				conbookString = {};
				cout << "���� ���� å�� �����ϴ�." << endl;
			}
			else {
				cout << "���� ���� å: " << conbookString << std::endl;
			}
			
			break;
		}
		case(4): {
			system("cls");
			cout << "�����ϰڽ��ϴ�." << endl;
			break;
		}
		default:
			break;
		}
	}
}
string Library::Choicebooks(const string strings[], int unm, const string& separator) {
	stringstream result;
	for (int i = 0; i < unm; ++i) {
		result << strings[i];
		if (i != unm - 1) {
			result << separator;
		}
	}
	return result.str();
}
vector<string> Library::split(string s, string d) {
	vector<string> result;

	auto start = 0U;
	auto end = s.find(d);
	while (end != string::npos) {
		result.push_back(s.substr(start, end - start));
		start = end + d.length();
		end = s.find(d, start);
	}
	result.push_back(s.substr(start, end));

	return result;
}