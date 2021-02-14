#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

bool palindrome(string input) {
	stack<char> s;
	queue<char> q;
	int mismatches = 0;
	for (char ch : input) {
		if (ch != ' ') {
			s.push(ch);
			q.push(ch);
		}
	}
	while (!s.empty() && !q.empty()) {
		if (s.top() != q.front())
			mismatches++;
		s.pop();
		q.pop();
	}

	if (mismatches > 0) {
		return false;
	}
	else
		return true;

}

int main() {
	string line = "olsldo";
	if (palindrome(line)) {
		cout << "It is palindrome" << endl;
	}
	else {
		cout << "It is not palindrome" << endl;
	}
}