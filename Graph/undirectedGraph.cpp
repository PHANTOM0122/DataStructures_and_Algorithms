#include <iostream>
using namespace std;

int a[1001][1001];
int n, m;

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		a[x][y] = 1;
		a[y][x] = 1;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}