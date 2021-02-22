#include <iostream>
#define MAX 100
using namespace std;

void radixsort(int*, int);
int main() {
	int a[MAX];
	int i, n;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	radixsort(a, n);
	for (i = 0; i < n; i++)
		cout << a[i] << ' ';
}

void radixsort(int* a, int n) {
	int result[MAX], maxValue = 0;
	int exp = 1; // 자릿수 1의 자리부터
	for (int i = 0; i < n; i++) {
		if (a[i] > maxValue) maxValue = a[i]; // find Maxvalue
	}

	while (maxValue / exp > 0) { // 1의 자리부터 최고 자릿수까지 계산
		int bucket[10] = { 0 }; // 자릿수 배열
		for (int i = 0; i < n; i++) bucket[(a[i] / exp) % 10]++; // 자릿수 배열 처리
		for (int i = 1; i < 10; i++) bucket[i] += bucket[i - 1]; // 누적 계산 처리
		for (int i = n - 1; i >= 0; i--) { // 같은 자릿수 끼리는 순서를 유지. 뒤의 원소부터 시작
			result[--bucket[(a[i] / exp) % 10]] = a[i]; // result [ 누적배열의 값-1 ]에 value입력
		}
		for (int i = 0; i < n; i++) a[i] = result[i]; // 기본 배열을 result배열로 갱신
		exp *= 10; // 자릿수 증가
	}
}