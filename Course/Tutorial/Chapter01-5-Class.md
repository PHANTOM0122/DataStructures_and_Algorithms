Class
==================
#### C++의 근간이다. 객체지향 프로그래밍의 기본이다.

## 1.5-1) Class 구조
* **클래스는 member들로 구성된다. Data member, member Function이 있다.**
### Example 1.
<pre><code>
class Counter{
public:
  Counter();
  int getCount();
  void increaseBy(int x); 
private:
  int count; // 카운터의 값
}
</code></pre>
  * **public: 공용 인터페이스로서, 클래스의 사용자가 접근할 수 있는 부분이다.**
  * **private: 사용자가 직접 접근할 수 없는 개체를 선언한다**
  * **범주지정자(::): 멤버 함수를 정의하는 것을 컴파일러에게 명확하게 만들어주기 위해서다**
  * **Constructor(생성자): class member 변수들의 값을 초기화시키는 역할. 반환 타입을 갖지 않는다.**
  * **getter함수: class의 private 멤버로의 접근을 제공한다**

### 접근 제어 (Access control)
* **public member들은 class 외부에서도 접근 가능하지만, private은 내부에서만 가능하다.** (protected는 후에 설명)
* 만일 access specifier가 주어지지 않으면, class는 기본으로 **private**, 구조체에서는 **public**이다.
* 대부분의 C++에서는 public 멤버들이 관심부분이기 때문에, public 멤버들을 먼저 쓰는 것을 권고

### 멤버 함수
### Example 2.
<pre><code>
class Passenger{
public:
  Passenger(); // 생성자
  bool isFrequentFlyer(); // 상용 고객?
  void makeFrequentFlyer(); // 상용 고객으로 만든다
private:
  string name;
  Mealtype meal;
  bool isFreqFlyer;
  string freqFlyerNo;
};
</code></pre>
* class member 함수들은 크게 **접근 함수(access function)**, **수정 함수(update function)**으로 나뉜다.
* makeFrequentFlyer() 함수는 접근 함수인데, **const**를 사용하여 **멤버 변수들을 수정하지 않는 다는 것을 알려준다. 수정시 Error!**
* C++스타일의 클래스 정의 내의 깔끔한 public interface를 위해 정의는 외부에 하는 것을 권고
* class외부에서 정의시 함수 이름 앞에 지정자(**class_name :: member_name**)을 두어서 할 수 있다.
### In-Class 함수 정의]
* member함수를 class 내에서 정의할 수도 있는데, 이 역시 in-line을 확장한다.
* 함수 정의는 반복문이나 조건문이 포함되지 않는다.

## 1.5-2) 생성자와 소멸자
* 객체가 생성될 때 생성자가 호출되며, 소멸 시 소멸자가 호출된다.
  ### 생성자
  * **객체의 멤버 변수를 초기화 시키는 함수이다**
  * 생성자 멤버 함수의 이름은 클래스와 같고 반환 타입이 없다
  * 여러개의 생성자가 정의될 수 있으며 함수 오버로딩에 의존하여 사용된다
  * **Default constructor:** 아무 초기화 정보가 없을 시에 사용
  * **Copy constructor: ** 초기화될 멤버 변수들이 주어질 때 사용
  * **Default 매개변수들은 생성자뿐 아니라 모든 함수에 사용가능하며, 선언에는 제공되지만 정의에는 포함되지 않는다!**
  ### Example code
  <pre><code>
  class Passenger{
  public:
    Passenger(); // 디폴트 생성자
    Passenger(const string& nm, Mealtype mp. const string& ffn = "NONE"); // 복사 생성자
    Passenger(const Passenger& pass); // 복사 생성자
  }
  
 Passenger::Passenger() { // 디폴트 생성자
  name = "--No Name--";
  meal = NO_PREF;
  isFreqFlyer = false;
  freqFlyerNO = "None";
 }

Passenger::Passenger(const string& nm, Mealtype mp, const string& ffn){
  name = nm; 
  mealpref = mp;
  isFreqFlyer = (ffn != "None"); // ffn이 주어질 경우 참이 된다.
  freqFlyerNo = ffn;
}
    
Passenger::Passenger(const Passenger& pass){
  name = pass.name; mealPref = pass.mealPref; isFreqFlyer = pass.isFreqFlyer; freqFlyerNo = pass.freqFlyerNo;
}
</code></pre>
 ### Example case
 <pre><code>
 Passenger p1; // Default
 Passenger p2("joon",vegeterian, 293145); // 2번째 생성자 - 상용고객
 Passenger p3("pocan",regular); // 2번째 생성자 - 상용고객이 아님
 Passenger p4(p3); // 3번째 생성자
 Passenger p5 = p2; // p2로부터 복제, 3번째 
 Passenger* pp1 = new Passenger; // 디폴트 생성자
 Passenger* pp2 = new Passenger("Joe",No_pref); // 두번째 생성자
 Passenger pa[20]; // default 생성자
</code></pre>
  ### 소멸자
  * **클래스가 시스템부터 메모리와 같은 리소스를 할당 받았으면 반드시 필요하다**
  * **new**연산을 통해 메모리 할당을 받은 경우 **delete**를 통해 메모리를 반납해야 한다.

## 1.5-3) 클래스와 메모리 할당
* **class에서 new를 이용하여 메모리 할당을 하는 경우, 메모리를 할당하는 복사 생성자나 배정 연산자를 제공하지 않으면 큰 문제가 생길 수 있다**
  ### problem case
  <pre><code>
  Vect a(100);
  Vect b = a;
  Vect c;
  c = a;
  </code></pre>
  * **"Vect b = a"에서는 복사 생성자가 제공되지 않았기 때문에, 배열의 내용을 복사하는 것이 아니라 첫 번째 요소에 대한 포인터를 복사(Shallow copy)하는 것이다!!**
  * **shallow copy**의 경우 위처럼 a,b,c가 **모두 free storage의 같은 배열을 가리키는 멤버를 가지고 있다**
  * **shallow copy**는 메모리를 할당하고 시스템의 디폴트 복사 생성자와 배정 연산자를 이용하기 때문이다.
  * **따라서 new를 사용하여 자신의 객체를 할당하는 모든 class는 다음 사항을 정의해야 한다(Deep copy)**
    1) 할당된 객체를 반환할 소멸자
    2) 자신의 새로운 멤버 저장소를 할당하고(새로운 메모리를 할당) 멤버 변수의 contents를 복사하는 복사 생성자 -> Deep copy를 위해 
    3) 오래된 저장소는 할당을 해제하고 새로운 저장소를 할당하며 모든 멤버 변수를 복사할 배정 연산자
    **복사 생성자의 경우 같은 클래스의 객체를 참조하는 단일 매개변수를 갖도록 선언한다**
### Example code
<pre><code>
  Vect::Vect(const Vect& a){ // a로부터의 복사 생성자
    size = a.size(); // 크기 복사
    data = new int [size]; // 새 배열을 할당
    for(int i=0; i<size;i++)
       data[i] = a.data[i];} // 벡터의 내용을 복사
  }
</code></pre>
<pre><code>
 Vect& vect::operator=(const Vect& a){ // a로부터의 배정 연산자
      if(this != a) { // 자체 배정을 피한다
        delete[] data; // 존재하는(this) 배열 공간을 파괴!
        size = a.size(); // 새 크기를 설정
        data = new int [size]; // 새 배열을 할당
        for(int i=0; i<size; i++)
          data[i] = a.data[i]; // 벡터의 내용을 복사한다.
      }
      return *this // 현재 객체의 레퍼런스를 반환한다. -> a=b=c처럼 배정을 함께 묶는 것을 지원하기 위해서다.
   }  
</code></pre>
## 1.5-4) Class friend & Static member data,functuions
  * **어떤 함수를 friend로 선언하여 그 함수에게 private 데이터 접근을 허용할 수 있다**
  * **다른 클래스에서 friend를 사용해서 class안의 데이터를 사용할 수 있다**
  * 서로 다른 두 클래스가 밀집되어 있는 경우 사용한다
  * **Static data: class의 모든 객체가 share하는 data이다**
  ### Example code
 <pre><code>
#include <iostream>
using namespace std;
class Point {
double x;
double y;
static int countCreatedObjects;
public:
Point();
Point(int x, int y);
void setPoint(int x, int y);
int getX(void) const;
int getY(void) const;
static int getCreatedObject(void);
Point operator+(const Point& point); 
Point& operator=(const Point& point);
friend ostream& operator<<(ostream& os, const Point& pt);
};

// Initialize the static variables.
int Point::countCreatedObjects = 0;

Point::Point()
{x = y = 0; countCreatedObjects++;}

Point::Point(int x, int y)
{this->x = x;this->y = y;countCreatedObjects++;}

void Point::setPoint(int x, int y) { this->x = x; this->y = y;}
int Point::getX (void) const {return this->x;}
int Point::getY (void) const {return this->y;}
int Point::getCreatedObject(void) {return countCreatedObjects;}

Point Point::operator+(const Point& point)
{Point result(this->x + point.getX(), this->y + point.getY()); 
  return result;}

Point& Point::operator=(const Point& point)
{this->x = point.getX(); this->y = point.getY(); return * this;}

ostream& operator<<(ostream& os, const Point& pt)
{ os << pt.x << pt.y << endl; }
</code></pre>
* **실행결과**
 <br> Number of created object is : 0 </br>
 <br> [X:10][Y:20] </br>
 <br> (11,22) </br>
 <br> Number of created object is : 3  </br>
  
