#include <iostream>
#include <vector>

using namespace std;

/*
* less_than(a, b)
* Returns true if a < b; otherwise, returns false.
*/
bool less_than(int a, int b) {
	return a < b;
}

/*
* greater_than(a, b)
* Returns true if a > b; otherwise, returns false.
*/
bool greater_than(int a, int b) {
	return a > b;
}

/*
* selection_sort(v, compare)
* Arranges the elements of v in an order determined by the compare function.
* v is a vector of integers.
* compare is a function that compares the ordering of two integers.
*/
void selection_sort(vector<int>& v, bool (*compare)(int, int)) {
	int n = v.size();
	for (int i = 0; i < n - 1; i++) {
		int small = i;
		for (int j = i + 1; j < n; j++) {
			if (compare(v[j], v[small]))
				small = j;
		}
		if (small != i)
			swap(v[small], v[i]);
	}
}

void print(const std::vector<int>& a) {
	int n = a.size();
	std::cout << '{';
	if (n > 0) {
		std::cout << a[0]; // Print the first element
		for (int i = 1; i < n; i++)
			std::cout << ',' << a[i]; // Print the rest
	}
	std::cout << '}';
	cout << endl;
}

int main() {
	std::vector<int> list{ 23, -3, 4, 215, 0, -3, 2, 23, 100, 88, -10 };
	cout << "Original: ";
	print(list);
	selection_sort(list, less_than);
	std::cout << "Ascending: ";
	print(list);
	selection_sort(list, greater_than);
	std::cout << "Descending: ";
	print(list);
	std::cout << '\n';
}