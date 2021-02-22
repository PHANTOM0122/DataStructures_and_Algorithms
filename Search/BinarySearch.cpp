#include <iostream>
#include <vector>
using namespace std;


int Binarysearch(vector<int>, int, int, int target);

int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; i++)
		cin >> a[i];

	int target;
	cin >> target;

	cout << Binarysearch(a, 0, N - 1, target);
}

int Binarysearch(vector<int> a, int start, int end, int target) {
	if (start > end)return -1;
	int mid = (start + end) / 2;
	if (target > a[mid]) return Binarysearch(a, mid+1, end, target);
	else if (target < a[mid]) return Binarysearch(a, start, mid-1, target);
	else return mid;
}