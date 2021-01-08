#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
/*
*locate(a, seek)
* Returns the index of element seek in vector a.
* Returns - 1 if seek is not an element of a.
* a is the vector to search.
*/
int locate(const vector<int>& a, int seek) {
	int n = a.size();
	for (int i = 0; i < n; i++)
		if (a[i] == seek)
			return i; // Return position immediately
	return -1; // Element not found
}

/*
* format(i)
* Prints integer i right justified in a 4-space field. Prints "****" if i > 9,999.
*/
void format(int i) {
	if (i > 9999)
		cout << "***" << endl;
	else
		cout << setw(4) << i;
}

/*
* print(v)
* Prints the contents of an int vector.
* v is the vector to print.
*/
void print(const vector<int>& v) {
	for (int elem : v)
		format(elem);
}

/*
* display(a, value)
* Draws an ASCII art arrow showing where the given value is within the vector.
* a is the vector.
* value is the element to locate.
*/
void display(const vector<int>& a, int value) {
	int position = locate(a, value);
	if (position >= 0) {
		print(a); // Print content of the vector
		cout << endl;
		position = 4 * position + 7; // Compute spacing for arrow
		cout << setw(position);
		cout << "  ^  " << endl;
		cout << setw(position);
		cout << "  |  " << endl;
		cout << setw(position);
		cout << "  +-- " << value << endl;
	}
	else {
		cout << value << "not in";
		print(a);
		cout << endl;
	}
	cout << "======" << endl;
}

int main() {
	vector<int> list{ 100, 44, 2, 80, 5, 13, 11, 2, 110 };
	display(list, 13);
	display(list, 2);
	display(list, 7);
	display(list, 100);
	display(list, 110);
}