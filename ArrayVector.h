#pragma once
#include <iostream>
using namespace std;

typedef int Elem; // 기본 원소 타입
class ArrayVector {
public:
	ArrayVector();
	int size() const;
	bool empty() const;
	Elem& operator[](int i);
	Elem& at(int i) throw(out_of_range);
	void erase(int i);
	void insert(int i);
private:
	int capacity; // 배열의 크기
	int n; // 벡터에 저장된 원소들의 수
	Elem* A; // 원소를 저장하는 배열
};

