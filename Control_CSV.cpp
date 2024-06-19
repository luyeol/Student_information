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

	// CSV 파일 읽기
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

	// 데이터 수정
	if (row < data.size() && column < data[row].size()) {
		data[row][column] = content; // 변경하고자 하는 데이터로 대체
	}
	else {
		cerr << "Invalid row or column index." << endl;
	}

	// 수정된 데이터를 CSV 파일로 쓰기
	dataInCSV(data, filename);
	//cout << "요청한 값을 작성 완료했습니다. " << filename << endl;
}

void CSV::addToCSV(string student_number, string password, string name) {

	// CSV 파일 읽기
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

		// 새로운 행 추가
		vector<string> new_row;
		new_row.push_back(student_number); // 학번 추가
		new_row.push_back(password);      // 비밀번호 추가
		new_row.push_back(name);          // 이름 추가
		for(int i=0;i<14;i++)
			new_row.push_back("null");        // 비어있는 열 추가
		data.push_back(new_row);

		// CSV 파일에 데이터 쓰기
		dataInCSV(data, filename);
		//cout << "New row added to " << filename << endl;
	}
	else {
		// 파일이 열리지 않을 때 오류 메시지 출력
		cerr << "파일이 존재하지 않습니다. 새 파일을 만듭니다." << filename << endl;

		vector<string> Field;
		Field.push_back("학번");
		Field.push_back("비밀번호");
		Field.push_back("이름");
		Field.push_back("1학기 평점");
		Field.push_back("2학기 평점");
		Field.push_back("3학기 평점");
		Field.push_back("4학기 평점");
		Field.push_back("5학기 평점");
		Field.push_back("6학기 평점");
		Field.push_back("7학기 평점");
		Field.push_back("8학기 평점");
		Field.push_back("평균 평점");
		Field.push_back("누적 학점");
		Field.push_back("자격증");
		Field.push_back("현장학습");
		Field.push_back("졸업작품");
		Field.push_back("대출현황");

		// 새로운 행 추가
		vector<string> new_row;
		new_row.push_back(student_number); // 학번 추가
		new_row.push_back(password);      // 비밀번호 추가
		new_row.push_back(name);          // 이름 추가
		for (int i = 0; i < 14; i++)
			new_row.push_back("null");        // 비어있는 열 추가

		vector<vector<string>> data;
		data.push_back(Field);
		data.push_back(new_row);

		// CSV 파일에 데이터 쓰기
		dataInCSV(data, filename);
		//cout << "New CSV file created: " << filename << endl;
	}
}

int CSV::findToCSV(string student_number) {

	// CSV 파일 읽기
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

	// 데이터 수정
	size_t target_col = 0; // 탐색할 열 인덱스
	string target_value = student_number; // 탐색할 값
	size_t target_row = 0; // 결과로 나올 행 인덱스

	// 열 순회하며 탐색
	for (size_t i = 0; i < data.size(); ++i) {
		if (data[i].size() > target_col && data[i][target_col] == target_value) {
			target_row = i + 1; // 원하는 값이 발견되면 해당 행 인덱스를 저장하고 루프 종료
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

	// CSV 파일 읽기
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

	// 요청된 행과 열에 있는 데이터 반환
	if (row < data.size() && column < data[row].size()) {
		return data[row][column];
	}
	else {
		cerr << "Invalid row or column index." << endl;
		return "";
	}
}