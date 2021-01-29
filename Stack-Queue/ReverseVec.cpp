#include <iostream>
#include <vector>
#include <stack>
using namespace std;

template<typename T>
void reserve(vector<T>& v) {
	
	stack<T> S;
	for (unsigned i = 0; i < 5; i++)
		S.push(v[i]);
	for (unsigned i = 0; i < 5; i++) {
		v[i] = S.top();
		S.pop();
	}
}

int main() {
	vector<string> list{ "Jack", "Kate", "Hurely", "Jin", "Michael" };
	reserve(list);
	for (auto elem : list)
		cout << elem << ' ';
}