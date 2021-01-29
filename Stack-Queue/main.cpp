#include "ArrayStack.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	try {
		ArrayStack<int> A;
		A.push(7);
		A.push(5);
		A.pop();
		cout << A.top();
	}
	catch (StackOutOfRange& e) {
		cout << e.what() << endl;
	}

	return 0;
}