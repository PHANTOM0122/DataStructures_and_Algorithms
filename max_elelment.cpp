#include <vector>
#include <iostream>
using namespace std;

// 직접짠 max_element구하는 알고리즘!
int main() {
	vector<int> list{ 2,5,7,6 };
	int max_index = 0;
	for (int i = 0; i < 4; i++) {
		if (list[max_index] < list[i]) {
			max_index = i;
		}
	}
	cout << max_index;
}