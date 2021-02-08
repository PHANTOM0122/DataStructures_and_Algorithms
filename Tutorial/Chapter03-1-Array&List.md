배열의 사용
==================
## 실제 자료구조인 배열(정수 색인으로 배열되는 엔트리에 접근)의 응용에 대해서 살펴본다

## 3.1-1) 배열에 게임 엔트리 저장 예시
<pre><code>
class GameEntry {
public:
	GameEntry(const string& n = "", int s = 0); // Default constructor
	string getName() const; // 선수 이름 가져오기
	int getScore() const; // 점수 가져오기
private:
	string name;
	int score;
};

GameEntry::GameEntry( const string& n, int s ) : name(n), score(s) {}
string GameEntry::getName() const { return name; }
int GameEntry::getScore const{ return score; }

class RuntimeException {
public:
	RuntimeException(const string& err) : errMsg(err) {}
	virtual string getMessage() { return errMsg; }
private:
	string errMsg;
};

class IndexOutOfBounds : public RuntimeException {
public:
	IndexOutOfBounds(const string& err) : RuntimeException(err) {}
};

class Scores {
public:
	Scores(int maxEnt = 10);
	~Scores();
	void add(const GameEntry& e);
	GameEntry remove(int i) throw(IndexOutOfBounds);
private:
	int maxEntries; // entry 갯수 최대값
	int numEntries; // entry의 현재 갯수
	GameEntry* entries; // 게임 엔트리들의 배열
};

Scores::Scores(int maxEnt) {
	maxEntries = maxEnt;
	entries = new GameEntry[maxEntries];
	numEntries = 0; // 처음에는 원소의 갯수 없음
}

Scores::~Scores() {
	delete[] entries;
}

void Scores::add(const GameEntry& e) { // sorted list에서 내림차순으로 삽입한다
	int newScore = e.getScore(); // 추가될 점수
	if (numEntries == maxEntries) { // 배열이 꽉 차 있음
		if (newScore <= entries[maxEntries - 1].getScore()) // 현재 배열의 가장 작은 원소보다 작은 경우
			return; // 무시하기
	}
	else
		numEntries++; // 꽉 안 차있으면 엔트리 원소 1개 증가

	int i = numEntries - 2; // 마지막 엔트리 왼쪽에서 시작하기(원소가 적어도 2개이상)
	while (i > 0 && newScore > entries[i].getScore()) { // newScore가 삽입될 지점을 찾기
		entries[i + 1] = entries[i]; // 오른쪽으로 1칸씩 이동
		i--; // 
	}
	entries[i + 1] = e;
}

GameEntry Scores::remove(int i) throw(IndexOutOfBounds) {
	if (i < 0 || i >= numEntries)
		throw("Index invalid");
	GameEntry e = entries[i]; // 제거할 객체 저장
	for (int j = i + 1; j < numEntries; j++) {
		entries[j-1] = entries[j]; // 원소들 왼쪽으로 1칸씩 이동
	}
	numEntries--; // 엔트리수 줄이기
	return e; // 제거된 객체를 반환
}</code></pre>
## 3.1-2) 배열 정렬
#### 삽입-정렬 알고리즘
* **배열의 첫번째부터 시작하여 원소의 적정 위치에 도달할 때까지 왼쪽으로 교체)**
###### Example
<pre><code>
void insertionSort(char * A, int n){ // n개의 문자열을 정렬
for(int i = 1; i< n; i++){
  char cur = A[i]; // 기준!
  int j = i - 1; // 바로 앞의 문자에서 시작
  while(j>=0 && A[j] > cur){ // A[j]보다 cur이 될때가지 j--하며 찾음
    A[j+1] = A[j]; // 오른쪽으로 원소 이동
    j--; 
  }
  A[j+1] = cur;
 }}
</code></pre>
