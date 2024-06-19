#pragma once
#include<iostream>
using namespace std;

class Grade {
public:
	int row;

	Grade(int row) :row(row) {
		//grade();
	}
	void grade();
	void CheckGrade();
	double ConvertTatalGrade();	//성적계산기
	double SemGrade();	//해당 학기 성적 입력
	void Cal();	//학기 성적 계산
	void Cal(int input);
};