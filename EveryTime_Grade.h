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
	double ConvertTatalGrade();	//��������
	double SemGrade();	//�ش� �б� ���� �Է�
	void Cal();	//�б� ���� ���
	void Cal(int input);
};