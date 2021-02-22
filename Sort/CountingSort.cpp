#include <iostream>
#define MAX_VALUE 10001

using namespace std;

int n, m;
int a[MAX_VALUE];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> m; a[m]++; }
	for (int i = 0; i < MAX_VALUE; i++) {
		while (a[i] != 0) {cout << i << ' '; a[i]--;}
	}
	return 0;
}