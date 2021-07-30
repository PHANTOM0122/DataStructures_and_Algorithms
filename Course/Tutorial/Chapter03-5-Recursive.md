Recursive
====================
* **loop를 제외한 반복을 얻는 또 다른 방법이다**
* **자신의 정의 내에서 자기 자신을 호출한다**
* Direct recursion: f(){f();}
* Indirect recursion: f()->g()->h()->f();
* **장점: 짧고, 간결하고, 이해하기 쉬운 코드가 만들어진다**
* **단범: 실행시간이 길다->비효율적**
> **Base case**
  * recursive call이 중단되는 case!
  * 모든 recursive algorithm은 base case를 적어도 1개 가져야 한다.
> **General case**
  * **작은 경우의 자기 자신을 다시 호출하는 case**
  * **결국 base case를 향해 간다.**
## 계승함수(factorial function)
> **factorial(n) = 1(if n==0) or n * factorial(n-1) (if n>=1)**
<pre><code>
int recursiveFactorial(int n){
  if(n==0) return 1;
  else return n * recursiveFactorial(n-1);} // 재귀적인 경우
</code></pre>
* recursive call이 먼저 일어나고 결과가 후에 계산된다!
![image](https://user-images.githubusercontent.com/50229148/107457281-1d408980-6b95-11eb-8341-782b884592e1.png)
## Combination
![image](https://user-images.githubusercontent.com/50229148/107457464-701a4100-6b95-11eb-842e-3e8ac3a229b3.png)
<pre><code>
int Combinations(int n, int k){
if(k==1) return n; // base case1
else if(k==n) return 1; // base case2
else 
 return(Combinations(n-1,k) + combinations(n-1,k-1));} 
</code></pre>
![image](https://user-images.githubusercontent.com/50229148/107457634-c25b6200-6b95-11eb-9bb3-119271836f4f.png)
## Verifying recursive functions (재귀 함수를 검증하는 3가지 질문) -> 수업의 핵심 주제
* Base-Case question: base case를 가지고 있나? // Ex) 0! = 1
* smaller_caller question: 재귀 call이 더 작은 case를 call 하는지? // Ex) f(n){ n * f(n-1);}
* General-Case question: recursive call이 정확하다고 할때, function이 올바르게 작동하는가?
# 3.5-1) 선형 재귀
* 재귀의 가장 간단한 형태이다.
* **선형 재귀는 호출이 발생할 때마다 최대로 하나의 재귀 호출이 이뤄지는 함수이다**
* **후미 재귀(tail recursion): 선형 재귀를 사용하는 알고리즘이 맨 마지막 연산으로 재귀적 호출을 하는 재귀 알고리즘**
## Example1) Value in list?
<pre><code>
bool ValueInList(ListType list, int value, int startIndex)
{
  if (list.info[startIndex] == value)
    return true; // Base case 1 -> search 과정중에서 발견
  else if (startIndex == list.length-1)
    return false; // Base case 2 -> list의 마지막까지 search했지만 없는 경우
  else return ValueInList(list, value, startIndex + 1); // General case
}</code></pre>
## Example2) Print ReverseArray
<pre><code>
struct NodeType {
	int info;
	NodeType* next;
};

class SortedType {
public:
	SortedType();
	~SortedType();
	void RevPrint(NodeType* listPtr);
private:
	NodeType* listData;
};

SortedType::SortedType()
{
	listData = new NodeType[100]; // Default
}

SortedType::~SortedType()
{
	delete[] listData;
}

void SortedType::RevPrint(NodeType* listPtr)
{
	if (listPtr != NULL) { // general case!
		RevPrint(listPtr->next); // process the rest
		cout << listPtr->info << endl; // After recursive call, print elements backwards!
	}
	// Base case : when list is empty, do nothing!
}</code></pre>
* 먼저 recursive call을 통해 마지막 원소까지 갔다가 print elem하는 것이다!
![image](https://user-images.githubusercontent.com/50229148/107460242-14eb4d00-6b9b-11eb-99f9-9916e7290066.png)
## Example3) ReverseArray
<pre><code>
1) loop를 사용하는 경우
Algorithm IterativeReversArray(A, start index i, end index j):
입력: 정수 배열 A와 정수 색인 i, j
출력: i~j사이 reverse 배열
while i<j do
  Swap(A[i],A[j]);
  i ++; j--;

2) 선형 재귀를 사용하는 경우
Algorithm ReverseArray(A, start index i, end index j):
입력: 정수 배열 A와 정수 색인 i, j
출력: i~j사이 reverse 배열
if i<j then
  swap(A[i],A[j]);
  ReverseArray(A,i+1,j-1); 
// Base-case : i=j(n이 홀수) or i>j(n이 짝수)
return</code></pre>
# 3.5-2) 이진 재귀
* **이진 재귀는 호출이 발생할 때마다 2개의 재귀 호출이 이뤄지는 함수이다**
## Example) Binary search function
![image](https://user-images.githubusercontent.com/50229148/107461718-f470c200-6b9d-11eb-9782-a1401dd8763f.png)
* **bool found = BinarySearch(List, item, left(front), right(end))**
<pre><code>
// Non-recursive implementation
template<class ItemType>
class SortedType {
public:
	SortedType() { info = new ItemType[length]; }
	void Retrieveitem(ItemType& item, bool& found);
private:
	ItemType* info;
	int length;
};

template<class ItemType>
void SortedType<ItemType>::Retrieveitem(ItemType& item, bool& found) {
	int midPoint;
	int first = 0;
	int last = length - 1;

	found = false;
	while ((first < last) && !found) {
		midPoint = (first + last) / 2;
		if (item < info[midPoint])
			last = midPoint - 1; // 왼쪽 part -> last 감소
		else if (item > info[midPoint])
			first = midPoint + 1; // 오른쪽 part -> first 증가
		else { // item == midPoint
			found = true;
			item = info[midPoint];
		}
	}
}

// Recursive implementation
template<class ItemType>
bool BInarSearch(ItemType list[], ItemType item, int left, int right) {
	int mid;
	if (left > right) { return false; } // Base case 1 : not found!
	else {
		mid = (left + right) / 2;
		if (list[mid] == item) // Base case 2 : found at mid
			return true;
		else if (item < list[mid]) // Search lower half
			return BInarSearch(list, ItemType item, left, mid - 1);
		else // Search upper half
			return BInarSearch(list, ItemType item, mid+1, right);
	}
}
					  </code></pre>
# Stack activation frame
* cpp파일을 분리하면 **CODE 영역과 DATA** 영역으로 나뉜다
* **DATA영역에는 **local variable, return address, parmeter, return value**가 저장된다.
* **Return address: 함수가 다른 영역의 메모리에서 실행되고 난 이후 다시 코드영역으로 반한되기 위하여 저장되는 code영역 메모리주소**
* **DATA영역을 run-time-stack으로 관리한다!**
## Example) Func(int a, int b)
<pre><code>
Func(int a, int b){
int result;
if (b==0) result = 0; // base case
else if(b>0) result = a + Func(a, b-1) ; // general case - instruction 50
else result = Func(-a,-b); // second general case - instruction 70
return result;}

X = Fucn(5,2) // original call is instruction 100
</code></pre>
* **main 함수의 return address는 100 / 이후 func내부에서 계속 호출되므로 return address는 50으로 같다!**
![image](https://user-images.githubusercontent.com/50229148/107464661-2127d800-6ba4-11eb-8f4a-0e018b93abb7.png)
# Recursive InsertItem(sortedlist)
![image](https://user-images.githubusercontent.com/50229148/107597502-29dce480-6c5e-11eb-9233-28871c409a07.png)
* **&location => refrence로 해서 이전 node와 자동으로 연결된다!**
<pre><code>
template < class ItemType >
void Insert(NodeType<ItemType>* &location, ItemType item) {
	if (location == NULL || item < location->Info) { // base cases !
		// 빈 리스트, list끝에 삽입하거나 location 앞에 item 삽입
		NodeType<ItemType>* tempPtr = location;
		location = new NodeType<ItemType>;
		location->Info = item;
		location->next = tempPtr;
	}
	else {
		Insert(location->next, ItemType item); // general case!
	}
}</code></pre>
# Recursive DeleteItem(sortedlist)
![image](https://user-images.githubusercontent.com/50229148/107466670-cb552f00-6ba7-11eb-905b-8fa7e39356b0.png)
* **&location => refrence로 해서 이전 node와 자동으로 연결된다!**
<pre><code>
template <class ItemType>
void Delete(NodeType<ItemType>* &location, ItemType item) {
	if (item == location->info) { // base cases ! , delete nodepointed by location
		NodeType<ItemType>* tempPtr = location;
		location = location->next;
		delete tempPtr;
	}
	else {
		Delete(location->next,item) // general case!
	}
}</code></pre>
# Recursion의 단점
* **아래와 같이 똑같은 경우를 다시 계산해야 하는 경우가 발생한다!**
![image](https://user-images.githubusercontent.com/50229148/107471834-23446380-6bb1-11eb-85d1-92a6f9d1db8a.png)
* **recursion vs iteration 은 가각의 장단점이 존재한다!!**
