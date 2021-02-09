#include "CircularLinkedList.h"
#include <iostream>

using namespace std;

int main() {
	CircleList playList;
	playList.add("Stayin Alive");// [Stayin*]
	playList.add("Le Freak");// [Le, Stayin* ]
	playList.add("Jelive Talking");// [Jive, Le, Stayin*]

	playList.advance(); // [Jive*, Le, Stayin]
	playList.advance(); // [Jive, Le*, Stayin]
	playList.remove(); // [Jive, Le*]

	cout << playList.front(); // Jive


	return 0;
}