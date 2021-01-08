#include <iostream>
#include <vector>

using namespace std;

/*
* swap(a, b)
* Interchanges the values of memory referenced by its parameters a and b.
* It effectively interchanges the values of variables in the caller's context.
*/
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
/*
* selection_sort
* Arranges the elements of vector v into ascending order.
* v is a vector that contains integers.
*/
void selection_sort(vector<int>& v) {
	int n = v.size();
	for(int i = 0;i < n-1; i++){
		int small = i; // small represent position that contains smallest value;
		for (int j = i + 1; j < n; j++) {
			if (v[j]<v[small])
				small = j;
		}
		// Swap if smaller value was found!
		if (small != i)
			swap(v[i], v[small]);
	}
}

/*
* print
* Prints the contents of a vector of integers.
* v is the vector to print.
* v is not modified.
*/
void print(const vector<int>& v) {
	cout << "{";
	for (int elem : v)
		cout << elem << ", ";
	cout << "} " << endl;
}

int main() {
	vector<int> list{ 23, -3, 4, 215, 0, -3, 2, 23, 100, 88, 10 };
	cout << "Before: ";
	print(list);
	selection_sort(list);
	cout << "After: ";
	print(list);

}