Standard Template Library && C++ program files
=========================
* **일반적인 자료구조를 위한 유용한 클래스들의 모음이다**
  * **String: **문자열을 포함한 자료구조
  * **stack**: lifo 구조의 container
  * **queue**: fifo 구조의 container
  * **deque**: 양쪽으로 출입하는 큐
  * **vector**: 크기를 바꿀 수 있는 resized 배열
  * **list**: 이중으로 링크된 리스트
  * **priority_queue**: 값을 기준으로 정렬된 큐
  * **set: 집합**
  * **map: 연관 리스트**
  
  ## 탬플릿과 STL vector 클래스
  * **vector의 경우 index를 확인하여 벗어날 경우 error를 발생시킨다!**
  * #include<vector>를 사용하여야 한다.
  * 크기를 resize 가능하다!
  
  ## STL string에 대한 추가 사항
  * **+:스트링을 연결시키는 연산자**
  * **str.size():스트링의 길이를 알려주는 함수**
  * **str[i]:스트링의 각각의 문자에 접근 하기 위한 index 연산자**
  * **str.find(p):str에서 string p 가 처음 출현한 index 반환**
  * **str.find(p,i):str에서 index i 이후에 srtring p가 처음 출현한 index 반환, string p가 발견되지 않은 것을 가리키기 위해 string::npos반환.**
  * **str.substr(i,m):str에서 i위치에서 시작하고 m개의 문자로 이루어진 sub-string 반환**
  * **str.insert(i,p):string p를 str[i] 앞에 삽입**
  * **str.erase(i,m):str[i]에서부터 길이 m만큼의 sub-string을 삭제**
  * **str.replace(i,m,p):index[i]에서 시작해서 길이 m만큼의 sub-string을 p로 대체**
  * **getline(is,str):입력 stream is에서 단일 라인을 읽고, str에 결과를 저장**
  ##### Example code
  <pre><code>
  string s = "a dog";
  s += "is a dog"; 
  cout << s.find("dog"); // 2반환
  if(s.find("doug") == string::npos) {} // True
  cout << s.substr(7,5); // "s a d"
  s.replace(2,3,"frog"); // "a frog is a dog"
  s.erase(6,3); // "a frog a dog"
  s.insert(0,"is"); // "is a frog a dog"
  if(s<"is a frog a toad") // True
  if(s<"is a frog a cat") // false
  </code></pre>
  
  ## C++ 프로그램과 파일 구성
  > 소스 파일
  * 보통 대부분 명령문들과 데이터 정의를 포함한다.
  * 소스 파일들은 보통 개별적으로 컴파일 된 후 linker에 의해 하나의 프로그램으로 결합된다.
  * 전역변수와 함수는 한 번만 정의될 수 있다.
  
  > 헤더 파일
  * 공유 객체를 사용하는 파일들은 반드시 일치하는 선언을 가지고, 이는 헤더파일에 저장된다.
  * template을 사용하여 class정의하는 경우 선언과 정의가 같은 파일에서 이뤄저야 한다.
  * 일반적으로 헤더파일에는 이름공간 using 명령어를 포함하지 않는 것이 좋다.
  
<pre><code>
#ifndef CREDIT_CARD_H
#define CREDIT_CARD_H // 반복되는 포함을 방지한다

#include <iostream>
#include <string>

class CreditCard {
public:
	CreditCard(const std::string& no, const std::string& nm, int lim = 0, double bal = 0);
	std::string getNumber() const { return number; }
	std::string getName() const { return name; }
	double getBalance() const { return balance; }
	int get Limit() const { return limit; }

	bool chargeIt(double price);
	void makePayement(double payment);
private:
	std::string number;
	std::string name;
	int limit;
	double balance;
};

std::ostream& operator<<(ostream& os, const CreditCard& c);
#endif // !CREDIT_CARD_H
</code></pre>
  
