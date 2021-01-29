#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<char> list;
	string str;
	cin >> str;
	bool result = true;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(')
			list.push(str[i]);
		else if (str[i] == ')') {
			if (list.empty())
				result = false;
			else
				list.pop();
		}
	}

	if (result)
		cout << "True!" << endl;
	else
		cout << "False!" << endl;
}