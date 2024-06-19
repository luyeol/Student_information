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
		cout << "도서 시스템에 방문하셨습니다." << endl;
		cout << "*번호를 눌러주세요.*\n'1'.대출 \n'2'.반납.\n'3'.대출 현황.\n'4'.종료" << endl;
		cin >> Choice;

		switch (Choice)
		{
			//대출
		case(1): {
			system("cls");
			if (conbookString.empty() || conbookString == "null") {
				cout << "대출을 시작하겠습니다." << endl;
				//cout << "대출할 책을 선택하시오.(띄어쓰기는 '_'로 대신) " << endl;
				cout << "대출할 책 권수는?(4권이상 대출불가)" << endl;
				int unm;
				cin >> unm;
				if (unm < 4) {
					for (int i = 0; i < unm; i++) {
						cout << "도서" << i + 1 << endl;
						cin >> books[i];
					}
					string separator = "/"; // 구분자로 쉼표를 사용
					conbookString = Choicebooks(books, unm, separator);
					CSV::writeToCSV(row, col, conbookString);
					system("cls");
					cout << "열람 중인 책:" << conbookString << std::endl;
				}
				else { 
					system("cls");
					cout << "4권이상 대출불가." << endl;
				}
			}
			else {
				cout << "대출한 책이 있어. 대출할수 없습니다." << endl;

			}
			break;
		}
			   //반납
		case(2): {
			system("cls");
			if (conbookString.empty() || conbookString == "null") {
				cout << "반납할 책이 없어 반납을 할 수 없습니다." << endl;
			}
			else {
				int cohis2;
				cout << "반납을 시작하겠습니다." << endl;
				cout << "모두 반납은 '1',개별반납은 '2',반납하지 않으면 '3'" << endl;
				cin >> cohis2;
				if (cohis2 == 1) {
					conbookString = {};
					CSV::writeToCSV(row, col, conbookString);
					system("cls");
					cout << "모두 반납 되었습니다." << std::endl;
				}
				else if (cohis2 == 2) {
					vector<string> split_result = split(conbookString, "/");
					
						for (int i = 0; i < split_result.size(); i++) {
							cout << "도서 " << i + 1 << " : " << split_result[i] << endl;
						}
					cout << "반납할 도서는 무엇입니까?" << endl;
					int sh;
					cin >> sh;
					system("cls");
					cout << "도서" << sh << " 반납" << endl;
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
					cout << "열람 중인 책:" << conbookString << std::endl;
				}
				else {
					cout << "반납하지 않음" << endl;
				}
			}
			break;
		}
		case(3): {
			system("cls");
			cout << "-대출상태-" << endl;
			conbookString = CSV::returnToCSV(row, col);
			if (conbookString.empty()|| conbookString == "null") {
				conbookString = {};
				cout << "열람 중인 책은 없습니다." << endl;
			}
			else {
				cout << "열람 중인 책: " << conbookString << std::endl;
			}
			
			break;
		}
		case(4): {
			system("cls");
			cout << "종료하겠습니다." << endl;
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