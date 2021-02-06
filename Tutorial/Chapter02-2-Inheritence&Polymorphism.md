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
  > **Protected member**
  * **protected멤버는 모든 다른 함수들에게는 private하지만, 현재의 클래스로부터 derieved된 class에 대해서는 public하다.**
  ![image](https://user-images.githubusercontent.com/50229148/107111389-1ebb3a80-6893-11eb-968e-c0379e154cf8.png)
  > **Inheritance relation 생성자와 소멸자**
  * derieved class가 생성될 때, base class에 대한 적당한 생성자가 호출되게 하는 것은 derieved class의 책임이다.
  <pre><code>
  Person::Person(const string& nm, const string& id) : name(nm), idNum(id) {} // Base-class
  Student::Student(const string& nm, const string& id, const string& maj, int year) : Person(nm, id), major(maj), gradYear(year) {} // Derieved-class
  </code></pre>
  * Person(nm,id)호출만이 derievedclass 초기화 리스트에 있으면 된다.
  * **소멸자의 경우 derieved-class 소멸자가 먼저 호출되고 base-class소멸자가 호출되어야 한다.**
  > **Static-binding** 
  * **객체의 선언된 type을 고려하여, derieved 되더라도 base로 선언되었으면 base멤버들만 사용된다**
  * Stuendt와 Person의 관계처럼 기본 클래스로부터 상속될 때, 유도된 클래스는 기본클래스의 특수형이 된다.
  <pre><code>
  Person* pp[100];
  pp[0] = new Person(...);
  pp[1] = new Student(...);
  </code></pre>
  * getName()은 공통 함수지만, pp[i]는 **Static-binding**으로 인해 Student member에 접근하지 못한다.
  ![image](https://user-images.githubusercontent.com/50229148/107111410-4b6f5200-6893-11eb-927c-f1a4127d1391.png)
  > **Dynamic-binding** 
  * **객체의 내용이 어떠한 멤버 함수를 호출할지를 결정한다**
  * **동적 바인딩을 사용하기 위해서는 함수 앞에 virtual을 추가한다**
  <pre><code>
 #include <iostream>
using namespace std;
class Base {
public:
  void f(void) {cout << "in function 'Base::f()'\n";}
  virtual void vf(void) {cout << "in function 'Base::vf()'\n";}
};
class Derived : public Base {
public:
  void f(void) {cout << "in function 'Derived::f()'\n";}
  void vf(void) override {cout << "in function 'Derived::vf()'\n";}
};
int main()
{
Base *p; Base myB;
Derived myD;
p = &myB;
p->f(); p->vf();
p = &myD;
p->f();p->vf();}
</code></pre>
![image](https://user-images.githubusercontent.com/50229148/107111700-65119900-6895-11eb-8a73-104464f85376.png)
