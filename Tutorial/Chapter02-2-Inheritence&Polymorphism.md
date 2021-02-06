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
## 2.2-2 Polymorphism 다형성
* C++에서는 pointer를 사용하여 다형성을 적용한다.
* **어떤 class S를 가리키는 pointer * P는 S로부터 유도된 T에 속한 객체도 point 할 수 있다는 것을 의미**
#### Example
p -> a()를 호출할 때, p가 T타입의 객체를 가리키면 T::a()가 호출된다. 이 경우, T가 S로 부터 a()함수를 **override**한 것이다.
대신에 p가 S타입을 가리키면 S::a()가 호출된다.
* **p는 참조하는 객체의 특성 class에 따라 많은 행태를 취할 수 있다**
#### 특수화
* 특수화를 사용함에 있어 우리는 general-class를 특정한 유도된 class들로 특수화할 수 있다.
* 유도된 특수화된 class들은 전형적으로 **is-a** relationship을 가지고 있다.
> **is-a relationship: derieved 객체는 base 객체의 특성을 갖지만, base 객체는 derived 객체의 특성을 완전히 갖진 않는다. 일방향성!!**
* **override: derieved 객체의 함수는 base 객체의 함수를 받는다. base함수가 잘 작동되지 않는 경우, derived class에서 잘 작동시키기 위해서 override를 해야한다**
* Dog라는 객체의 sniff, drink함수는 Booldok라는 객체에서는 drink는 같은 메커니즘이지만, sniff는 종마다 다르므로 override를 해야한다.
#### 확장
* **확장을 사용함에 있어서 base-class 함수를 위해 코드를 재활용한다. 다만, 기본 클래스에 없던 함수를 추가한다**
* base-class에는 derived 객체의 함수가 존재하지 않을 것이다.
#### 상속 계층에서의 형변환
* **dynamic_cast<desired_type> (expression)**
* derived-class에만 존재하는 함수를 사용하기 위한 예시
<pre><code>
Person * p[100];
p[0] = new Person()
p[1] = new Student()
Student* sp = dynamic_cast<Student*>(p[1]); // p[1]을 student로 형변환
sp -> changeMajor("Chemistry") // derived만의 함수 사용 가능
</code></pre>
* 부당한 형변환이 일어날 경우 **nullptr**이 된다. (ex. p[0]를 형변환 할 경우)
#### 추상 클래스와 인터페이스
* 객체가 상호작용하기 위해서는 서로의 멤버 함수에 대해 알아야한다. 클래스들이 자신들의 객체를 다른 객체에 보여주는 API 등을 요청한다.
> **추상 클래스(Abstract-class)**
* **오직 상속에 대한 base-class로만으로 사용된다. 직접 객체를 만들 수 없다**
* Abstract class에서 **pure virtual function(순수 가상함수)를 사용하여 선언만 가능하며, 정의는 derived-class에서만 가능하다.(직접 객체생산X)**
* 함수 뒤에 "=0"을 사용함으로써 순수 가상함수임을 나타낸다.
> **인터페이스와 추상 기본 클래스**
* C++에서는 ADT에 대한 인터페이스를 직접 정의하는 메커니즘을 제공하지는 않는다.
* 위의 목적을 수행하기 위해 추상적인 기본 클래스들을 사용 가능하다.
#### Example
<pre><code>
class Stack{
public:
	virtual bool isEmpty() const = 0;
	virtual void push(int x) = 0;
	virtual int pop() = 0;
}
class ConcreteStack : public Stack{
public:
	virtual bool isEmpty() { ... }
	virtual void push(int x) { ... }
	virtual int pop() {...}
{
</code></pre>





