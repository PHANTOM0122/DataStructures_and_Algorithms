상속과 다형성
===================
## 2.2-1 C++에서의 상속
* **객체지향 패러다임은 상속을 통해 코드를 재활용하기 위한 모듈과 계층적 구조를 제공한다**
* **Base class: 일반적인 멤버들로 정의된다(부모 class)**
* **Derived class: 상속을 받는 calss(자식 class)**
### Exmaple class // Person class를 상속받는 Student class
<pre><code>
class Person {
private:
	string name;
	string idNum;
public:
	// ....
	void print();
	string getName() const;
};

class Student : public Person { // class가 student부터 유도되었다는 것
private:
	string major;
	int gradYear;
public:
	// ... 
	void print();
	void changeMajor(const string& newmajor);
};</code></pre>
  > **멤버 함수**
  * print()함수처럼 **어떤 class의 함수가 사용되었는지 나타내기 위해서 class범위 연산자(::)를 사용한다.**
  * derived class 객체들은 base class의 public 영역에 접근이 가능하다.
  <pre><code>
  void Person::print(){
    cout << "Name: " << name << endl;
    cout << "IDnum: " << idNum << endl;
  }
  void Student::print(){
    Person::print() // "Person::"지정자를 통해 자기 자신 호출을 막는다
    cout << "Major" << major << endl;
    cout << "Year" << year << endl;
  }</code></pre>
