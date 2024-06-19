#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
class Library {
public:
	int row;
	Library(int row) :row(row) {


	}
	void LibraryStart();
	string Choicebooks(const string strings[], int unm, const string& separator);
	vector<string> split(string s, string d);
	
};