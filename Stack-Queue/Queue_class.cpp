#include <iostream>

using namespace std;

template <typename T>
class Queue {
private:
	T* p_list; // 정수형 변수들을 가지는 배열
	int size; // 현재 저장된 변수들의 개수
	int MAX_SIZE; // 최대로 저장할 수 있는 리스트의 크기
public:
	Queue(int _MAX_SIZE = 1000) {
		MAX_SIZE = _MAX_SIZE;
		size = 0;
		p_list = new T[_MAX_SIZE];
	}
	~Queue(); 
	int find_index(T _item);
	void Enqueue(T _item);
	T Dequeue(); 
	void print() const; 
	int get_size(); 
	T get_item(int _index); 
};

int main()
{
	Queue<int> int_queue;
	Queue<float> float_queue;
	Queue<char> char_queue;
	int_queue.Enqueue(1);
	int_queue.Enqueue(2);
	int_queue.Enqueue(2);
	int_queue.Enqueue(5);
	float_queue.Enqueue(4.3);
	float_queue.Enqueue(2.5);
	float_queue.Enqueue(3.7);
	float_queue.Enqueue(3.7);
	char_queue.Enqueue('b');
	char_queue.Enqueue('b');
	char_queue.Enqueue('c');
	char_queue.Enqueue('a');
	cout << "<Before Dequeue>" << endl;
	int_queue.print();
	float_queue.print();
	char_queue.print();
	int_queue.Dequeue();
	float_queue.Dequeue();
	float_queue.Dequeue();
	char_queue.Dequeue();
	char_queue.Dequeue();
	char_queue.Dequeue();
	char_queue.Dequeue();
	cout << "<After Dequeue>" << endl;
	int_queue.print();
	float_queue.print();
	char_queue.print();
	return 0;
}


// 소멸자 : p_list 의 동적 할당을 해제
template<typename T>
Queue<T>::~Queue()
{	
	delete[] p_list;
}
// p_list 에서 _item 과 동일한 값이 있는지 검색 후 발견시 index 를 반환한다 만약 발견하지 못하면 1 을 반환한다
template<typename T>
int Queue<T>::find_index(T _item)
{
	int index = -1;
	for (int i = 0; i < size; i++) {
		if (p_list[i] == _item)
			index = i;
	}
	return index;
}
/*
* 입력 item 을 p_list 의 끝에 저장한다 . 만약 _item 과 동일한 값이 p_list 에 존재할 경우 p_list 에 입력 item 을 추가하지 않는다.
* 힌트 : find_index 함수를 사용해서 중복된 값이 p_list 에 있는지 조사후 없는 경우에 입력 item 을 p_list 에 추가 ). size 가
MAX_SIZE 보다 크면 item 을 추가하지 않는다 .("Error: out of 출력
*/
template<typename T>
void Queue<T>::Enqueue(T _item)
{
	if (size > MAX_SIZE) {
		cout << "Error: out of memeory!" << endl;
	}
	
	if (find_index(_item) == -1) {
		p_list[size] = _item;
		size++;
	}
}

/* p_list 에 있는 첫번째 item 을 제거한다음 그 아이템을 return 한다
힌트 :size 값을 줄이면 p_list 의 아이템을 제거한 것과 동일한 효과 ) size 가 0 일 때는 item 을
제거하지 않는다 . ( "Error: No item exists in th e list" 출력
*/
template<typename T>
T Queue<T>::Dequeue()
{	
	if (size == 0) {
		cout << "No item exist in the list" << endl;
	}

	T item = p_list[0];

	size -= 1;
	for (int i = 0; i < size; i++) {
		p_list[i] = p_list[i + 1];
	}
	
	return item;
}
// Queue 객체의 item 들을 출력한다
template<typename T>
void Queue<T>::print() const
{
	for (int i = 0; i < size; i++)
		cout << p_list[i] << " ";
	cout << endl;
}
//Queue 객체의 크기를 출력한다
template<typename T>
int Queue<T>::get_size()
{
	return size;
}
// p_list 의 해당 index 에 있는 item 값을 리턴한다
template<typename T>
T Queue<T>::get_item(int _index)
{
	return p_list[_index];
}
