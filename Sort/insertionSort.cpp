#include <iostream>
#include <vector>

using namespace std;

void insertionSort(char* A, int n) { // n개의 문자의 배열을 정렬
	for (int i = 1; i < n-1; i++) { // 삽입 루프
		char cur = A[i]; // 삽입하려는 현재의 문자
		int j = i - 1; // 바로 앞의 문자에서 시작
		while ((j >= 0) && (A[j] > cur)) { // A[j]가 순서에 어긋나 있는 동안
			A[j + i] = A[j]; // A[i]를 오른쪽으로 이동
			j--; // j를 감소
		}
		A[j + i] = cur; // 이곳이 cur에게 맞는 위치
	}
}

void InsertSort(vector<int>& v) {
	int n = v.size();
	for (int i = 0; i < n - 1; i++) {
		int j = i; // j is insert index
		while (j >= 0 && v[j] > v[j + 1]) {
			swap(v[j], v[j + 1]); // v[j]와 v[j+1]의 원소를 비교
			j--; // 원래 v[j+1]과 v[j-1]이 sort!
		}
	}
}

int main() {
	char list[3] = { 'C', 'A', 'F' };
	insertionSort(list, 3);
	for (int i = 0; i < 3; i++)
		cout << list[i] << ' ';
}
