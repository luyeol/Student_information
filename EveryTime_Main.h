#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class MainMenu {
public:
	int row;
	MainMenu(int row) :row(row) {
		MainStart();
	}
	void MainStart();

};

