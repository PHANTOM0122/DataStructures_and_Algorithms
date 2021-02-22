#include <iostream>

using namespace std;

int v[100];

void swap(int& a, int& b);
void QuickSort(int start, int end);

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	QuickSort(0, n - 1);
	for (int elem : v)
		cout << elem << ' ';
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void QuickSort(int start, int end) {
	if (start > end) return; // 
	int pivot = start, i = start + 1, j = end, temp; // 가장 왼쪽을 pivot이라 가정

	while (i <= j) { // left <= right 일 경우에만 작동
		while (i <= end && v[i] <= v[pivot]) i++; // i는 left에서 시작하여 v[pivot] 보다 큰 값의 index
		while (j > start && v[j] >= v[pivot]) j--; // j는 right에서 시작하여 v[pivot] 보다 작은 값의 index
		if (i > j) swap(v[pivot], v[j]); // left > right인 경우 pivot값과 right값 swap (right이 pivot보다 작은 값이므로!)
		else swap(v[i], v[j]); // left<=right인 경우 left, right swap
	}
}