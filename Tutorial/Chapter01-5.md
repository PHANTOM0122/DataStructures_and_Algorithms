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
