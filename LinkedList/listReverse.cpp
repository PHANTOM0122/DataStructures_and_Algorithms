#include "DoubleLinkedList.h"
#include <iostream>

using namespace std;

void listReverse(DLinkedList& L) {
	DLinkedList T; // temp list 생성
	while (!L.empty()) {
		string s = L.front();
		L.removeFront();
		T.addFront(s); // L을 T로 임시 복사
	}
	while (!T.empty()) {
		string s = T.front();
		T.removeFront(); // 다시 T를 L로 복사!
		L.addBack(s);
	}
}
