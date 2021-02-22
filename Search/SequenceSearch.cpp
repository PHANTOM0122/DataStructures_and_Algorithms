#include <iostream>

using namespace std;

bool found = false; 
void SequenceSearch(int*, int, int);

int main() {
	int n;
	cin >> n;
	int* a;
	a = new int[n];

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int target;
	cin >> target;

	SequenceSearch(a, n, target);
}

void SequenceSearch(int* a, int length, int target) {
	for (int i = 0; i < length; i++) {
		if (target == a[i]) {
			cout << target << "is in " << i + 1 << "번째 원소이다." << endl;
			found = true;
		}
	}
	if (!found){cout << "Can't found!" << endl;}
}