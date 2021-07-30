Hash
====================
* **Hash는 데이터를 최대한 빠른 속도로 도와주는 자료구조이다**
* **메모리 공간이 많이 소모되지만, 매우 빠른 속도로 데이터를 처리할 수 있다**
* 빠르게 접근할 수 있다는 점에서 데이터베이스 등의 소프트웨어에서 활용
* **특정한 value를 찾고자 할 때는 그 값의 key로 접근 가능하다 O(1)만에 값에 접근 가능하다**
![image](https://user-images.githubusercontent.com/50229148/108972420-a2b05780-76c6-11eb-9738-b7de76f333f2.png)

## 해시의 충돌
* **key의 경우 한정적이기 때문에 충돌(중복)이 발생한다**
* 생일의 역설 : 57명중 2명의 생일이 같은 확률이 99% -> 무조건 충돌 발생한다는 예시
![image](https://user-images.githubusercontent.com/50229148/108972628-dc815e00-76c6-11eb-9b79-2c8dc3b890e4.png)
> **collision을 해결할 2가지 방법**
**1) 충돌을 발생시키는 항복을 해시 테이블의 다른 위치에 저장 : 선형 조사법, 이차 조사법**
**2) 해시 테이블의 하나의 버킷에 여러 개의 항복을 저장 : 체이닝**

### 선형 조사법
![image](https://user-images.githubusercontent.com/50229148/108973181-692c1c00-76c7-11eb-9afb-b592bb0afcd5.png)
* 충돌이 발생하기 시작하면 유사한 값을 가지는 데이터끼리 서로 밀집되는 집중 결합이 발생한다는 문제점이 있다
<pre><code>
struct Student {
	int id;
	string name;
};
void init(Student** hashTable)
{
	for (int i = 0; i < TABLE_SIZE; i++) {
		hashTable[i] = NULL;
	}
}

void destructor(Student** hashTable) {
	for (int i = 0; i < TABLE_SIZE; i++) {
		if (hashTable[i] != NULL)
			delete hashTable[i];
	}
}

// Empty 공간의 index return
int findEmpty(Student** hashTable, int id)
{
	int i = id % TABLE_SIZE;
	while (1) {
		if (hashTable[i] == NULL) { // Break; 
			return i % TABLE_SIZE;
			break;
		}
		i++; // if hashTable[i] isn't empty!
	}
}

int search(Student** hashTable, int id)
{
	int i = id & TABLE_SIZE;
	while (1) {
		if (hashTable[i % TABLE_SIZE] == NULL) return -1; // empty!
		else if (hashTable[i % TABLE_SIZE]->id == id) return i; // id가 아닌 hash값이 같은 id가 존재하는 경우 생각
		i++;
	}
}

void add(Student** hashTable, Student* input, int key)
{
	hashTable[key] = input;
}

Student* getValue(Student** hashTable, int key) {
	return hashTable[key];
}

void print(Student** hashTable)
{
	for (int i = 0; i < TABLE_SIZE; i++) {
		if (hashTable[i] != NULL) {
			cout << "키: [" << i << "].  이름: " << hashTable[i]->name << endl;
		}
	}
}</code></pre>
### 이차 조사법
* **선형 조사법을 약간 변형한 형태로 key를 선택할 때 완전 제곱수를 더해 나가는 방식이다**
* 테이블의 크기가 가득 차면, 크기를 확장하여 계속해서 테이블을 유지

### 체이닝
* **체이닝 기법은 연결 리스트를 활용해 특정한 키를 가지는 항목들을 연결하여 저장**
* **연결리스트를 사용한다는 점에서 삽입과 삭제가 용이. 동적할당을 통해 크기 재설정 용이.**
![image](https://user-images.githubusercontent.com/50229148/108973702-02f3c900-76c8-11eb-9f06-32ef5a1caa1d.png)
<pre><code>
struct Student {
	int id;
	char name[20];
};

struct Bucket {
	Student* data;
	Bucket* next;
};

void constructor(Bucket** hashTable)
{
	for (int i = 0; i < TABLE_SIZE; i++) {
		hashTable[i] = NULL;
	}
}

void destructor(Bucket** hashTable) {
	for (int i = 0; i < TABLE_SIZE; i++) {
		if (hashTable[i] != NULL) {
			delete hashTable[i];
		}
	}
}

int isExist(Bucket** hashTable, int id)
{
	int i = id % TABLE_SIZE;
	if (hashTable[i] == NULL) return 0;
	else {
		Bucket* cur = hashTable[i];
		while (cur != NULL) {
			if (cur->data->id == id) { return i; break; }
			cur = cur->next;
		}
	}
	return 0; // not Found!
}

void add(Bucket** hashTable, Student* input) // addFront!
{
	int i = input->id % TABLE_SIZE;
	if (hashTable[i] == NULL) { // empty table에 삽입
		hashTable[i] = new Bucket;
		hashTable[i]->data = input;
		hashTable[i]->next = nullptr;
	}
	else { // exist한 hash에 삽입
		Bucket* cur = new Bucket;
		cur->data =input;
		cur->next = hashTable[i];
		hashTable[i] = cur;
	}
}</code></pre>
