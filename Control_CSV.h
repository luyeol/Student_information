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
	//row행 col열에 content 작성
	static void addToCSV(string student_number, string password, string name); 
	// 새행 추가후 학번과 비밀번호, 이름 설정
	static int findToCSV(string student_number); 
	// 학번이 있는 행을 int형으로 반환, 없으면 0반환
	static string returnToCSV(int row, int column); 
	// row행 col열에 있는 데이터를 string으로 반환
	
	//학번,비밀번호,이름,null,null,null 형태
};
