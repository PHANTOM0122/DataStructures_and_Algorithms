#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void selectionSort(vector<int>& v) {
	int n = v.size(), min, index;
	for (int i = 0; i < n; i++) {
		min = INT_MAX; // 가장 큰 값을 대입
		for (int j = i; j < n; j++) {
			if (min > v[j]) {
				min = v[j]; // i번째 원소 이후부터 계속 최소값이 저장된다.
				index = j; // 가장 작은 원소의 index
			}
		}
		swap(v[index], v[i]);
	}
}


int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	selectionSort(v);
	
	for (int elem : v)
		cout << elem << ' ';

 }