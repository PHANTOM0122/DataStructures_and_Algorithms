#pragma once
#include <string>
#include <iostream>
using namespace std;

class StackOutOfRange :public exception {
public:
	StackOutOfRange(const string& err) :errorMSg(err) {
		cout << what() << endl;
		exit(1);
	}
private:
	string errorMSg;
};