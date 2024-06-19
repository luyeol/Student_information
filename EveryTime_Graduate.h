#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Graduate {
public:
	int row;
	int col;

	Graduate(int row) :row(row) {
		col = 13;
	}

	void start();
	void return_grade(int can_graduate);
	void condition();
	void survey();

};