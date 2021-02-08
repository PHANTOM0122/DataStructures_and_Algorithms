#include "StringLinkedLIst.h"

stringLinkedLIst::stringLinkedLIst() { head = NULL; } // 생성자
stringLinkedLIst::~stringLinkedLIst() { while (!empty()) removeFront(); } // 소멸자
bool stringLinkedLIst::empty() const { return head == NULL; } // 빈 리스트?
const string& stringLinkedLIst::front() const { return head->elem; } // 이전 원소를 얻는다

void stringLinkedLIst::addFront(const string& e) {
	stringNode* v = new stringNode;
	v->elem = e;
	v->next = head;
	head = v;
}

void stringLinkedLIst::removeFront() {
	stringNode* old = head; // 현재 head 저장
	head = old->next; // 이전 head 건너뛴다
	delete old; // 이전 head 삭제
}