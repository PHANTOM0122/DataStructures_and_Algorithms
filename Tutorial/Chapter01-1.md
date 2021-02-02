### 1.1) 기본적인 C++ 프로그래밍 요소


#### 1.1-1 간단한 C++ 프로그램의 예
C++ 프로그램을 생성하고 실행하기 위해서는 여러 단계가 필요하다.
1) C++ 소스파일을 생성하고 명령어 라인을 입력한다
2) 파일 저장 후, Compiler가 프로그램을 실행하며, **이 프로그램을 기계어로 변환한다.**
3) Linker라 불리는 다른 프로그램은(보통 컴파일러에 의해 자동으로 실행) **필요한 라이브러리 함수들을 포함시켜 최종적인 기계실행 파일을 생산한다.**
4) 이 프로그램을 실행하기 위해서는 사용자는 시스템이 이 파일을 실행하도록 요청한다.

### Example code
<pre>
<code>
#include <cstdlib>
#include <iostream>
int main(){
  int x, y;
  std::cout << "Please enter two numbers : ";
  std::cin >> x >> y;
  int sum = x+y;
  std::cout << "Their sum is " << sum << std::endl;
  return EXIT_SUCCESS;
}
</code>
</pre>

###### 프로그램 요소들
* '#include headerfile" -> 헤더파일은 특별한 선언과 정의를 제공하기 위해 사용.</br>
* int main() -> C++ 프로그램의 초기 진입점. main 함수가 매개변수를 받지 않고 종료 후 정수를 결과로 반환한다고 선언. </br>
함수 몸체는 4~11번 라인이며, return문이 실행되면 종료된다. 통상 main함수는 성공의 의미로 0을 반환한다. </br>
* Std:: 객체들이 시스템의 표준 라이브러리에 정의되어 있다는 의미이다. 'using namespace std'로 대체 가능하다.



#### 1.1-2 기본 타입
C++의 기본 타입을 알아보고 이들 타입이 상수나 변수로 표현되는 방법을 알아본다.

* **bool** : True or False
* **char** : 문자
* **short** : 짧은 정수 
* **int** : 정수
* **long** : 긴 정수
* **float** : 단일 정밀도 부동소수점 수
* **double** : 두배 정밀도 부동소수점 수

###### 문자
* **char**변수는 문자 하나를 저장한다. C++에서 보통 8비트이지만, 비트 수는 구현 방법에 따라 달라진다.
 '\b' -> backspace  '\0' -> null  '\'' -> single quote  '\"' double quote  '\\' backslash
###### 정수
* **int**변수는 3가지 크기가 있다. shrot int, int, long int. 
###### Enumeration(열거형)
* **Enumeration**변수는 discrete value들의 집합의 임의 원소를 가질 수 있는 사용자-정의 타입이다. 열거형이 정의되면 하나의 정수타입처럼 동작한다. 열거형의 사용이유는 관련된 값들의 집합에 의미 있는 이름을 제공하기 위함이다. 열거형의 각 요소는 정수값을 가지고 있는데, 기본적으로 0부터 시작하지만 다음과 같이 명시적인 상수값을 지정 가능하다.
<pre>
<code>
**enum** Day { SUN, MON, TUE, WED, THU, FRI, SAT };
**enum** Mood { Happy = 3, Sad = 1, Anxious = 4, Sleepy = 2 };

Day today = THU;
Mood myMood = Sleepy;
</code>
</pre>
###### 부동 소수점
* **float**변수는 single-precision 부동 소수점 숫자를 저장하고, **double**변수는 double-precision 부동 소수점 숫자를 저정한다. 기본적으로 3.14159와 -1234.567같은 부동 소수점 실수는 **double** 타입이 된다. 과학적,지수 표기법은 3.14E5와 같이 "E", "e"를 사용하여 가수와 지수를 구분할 수 있다. 실수를 **float**으로 만들기 위해서는 20.f나 1.234E-3f와 같이 "f"나'F'를 붙인다.

#### 1.1-3 포인터, 배열 , 구조체

##### 포인터
* 각 변수는 컴퓨터 메모리의 어떤 위치, **address**에 저장된다. **pointer**는 그러한 메모리 주소값을 갖는 변수이다. 주어진 T타입에 대하여 'T*'는 타입 T 변수에 대한 포인터를 나타낸다. 예를 들어 'int*'는 정수에 대한 포인터이다.
* **참조(referencing)**: 객체의 메모리 내의 주소를 반환한다. **'&'**연산자에 의해 수행된다. 예를 들면 X가 정수형 변수라면, &X는 메모리상에서 X의 주소를 나타낸다.
* **역참조(dereferencing)**: 주소의 contents를 반환한다. 이는 **'*'** 연산자에 의해 수행된다. 예를 들어 q를 정수를 가리키는 포인터이고, q=&X 로 설정하면 X의 값을 * q로 접근할 수 있다.
* 포인터를 사용하여 다른 객체에 연결할 수 있기 때문에 자료구조를 구성할 때 포인터가 유용하다는 것을 알 수 있다. 
* 종종 pointer의 값으로 아무것도 가리키지 않는 nullptr을 사용하며, nullptr을 역참조하면 run-time-error가 발생한다. 
* pointer를 **void*** 타입으로 사용시, **어떤 타입의 변수도 가리킬 수 있다** 하지만 컴파일러가 이러한 참조의 정확성을 체크할 수 없기 때문에 컴퓨터 메모리의 직접적인 접근을 제외하고는 사용을 권장하지는 않는다.
### Example code
<pre>
<code>
char ch = 'Q'; // 
char *p = &ch; // p는 ch의 주소를 갖는다
cout << *p; // 문자 Q가 출력된다
ch = 'Z'; // ch는 문자 'Z'를 갖는다.
cout << *p; // 문자 z가 출력된다
*p = 'X'; // ch는 'X'를 갖는다
cout << *p; // 문자 X가 출력된다
</code>
</pre>
##### 배열
* 배열(array)은 **같은 타입을 갖는 요소들의 모임이다. Index에 의하여 참조된다.** 
* C++는 인덱스가 배열의 범위를 벗어나는지 확인하는 기능을 제공하지 않는다.(실행속도를 늦츨 수 있는 요소를 배제하는 C++의 원칙에 따른 것)
* 2차원 배열은 **배열의 배열로 구성된다. A[i][j]로 인덱스 된다.**
##### 포인터와 배열
### Example code 1
<pre>
<code>
char c[] = {'c','a','t'};
char* p = c; // address : 'c'
char* q = &c[0]; // address : 'c'
cout << c[2] << p[2] << q[2];  // address : 'c' 
</code>
</pre>
### Example code 2 // 2차원 배열과 pointer
<pre>
<code>
#include <stdio.h>

int main()
{
    int numArr[3][4] = {    // 세로 3, 가로 4 크기의 int형 2차원 배열 선언
        { 11, 22, 33, 44 },
        { 55, 66, 77, 88 },
        { 99, 110, 121, 132 }
    };

    int (*numPtr)[4] = numArr;

    printf("%p\n", *numPtr); // 002BFE5C: 2차원 배열 포인터를 역참조하면 세로 첫 번째의 주소가 나옴
                             // 컴퓨터마다, 실행할 때마다 달라짐

    printf("%p\n", *numArr); // 002BFE5C: 2차원 배열을 역참조하면 세로 첫 번째의 주소가 나옴
                             // 컴퓨터마다, 실행할 때마다 달라짐

    printf("%d\n", numPtr[2][1]);    // 110: 2차원 배열 포인터는 인덱스로 접근할 수 있음

    printf("%d\n", sizeof(numArr));  // 48: sizeof로 2차원 배열의 크기를 구하면 배열이 메모리에 
                                     // 차지하는 공간이 출력됨

    printf("%d\n", sizeof(numPtr));  // 4 : sizeof로 2차원 배열 포인터의 크기를 
                                     // 구하면 포인터의 크기가 출력됨(64비트라면 8)

    return 0;
}
</code>
</pre>
![pointer_doublearray](https://user-images.githubusercontent.com/50229148/106553365-9ff59300-655c-11eb-95a4-b77d2a7e51ed.png)
##### 스트링(STL String)
<pre>
<code>
#include <string>
using std::string;

string s = "to be";
stirng t = "not" + s;
if(s>t)
  cout << t;
 char c = s[1] // c = 'o'; 
</code>
</pre>
##### C-style Struct
* **구조체(Struct)**는 요소들의 집합을 저장하는데 유용하다. 배열과는 다르게 구조체의 구성요소들은 **서로 다른 타입일 수 있다.** 구조체의 각 멤버 또는 필드는 주어진 이름을 가지고 있다.
<pre>
<code>
enum Mealtype{ NO_pref, Regular, Low_Fat, Vegetarian };
struct Passenger{
  string name; 
  Mealtype meal;
  bool isFreqFlyer;
  string freqFlyerNo;
}
Passenger pass = {"Heejoon Moon", No_pref, true, "293145"};
pass.name = "John smith"; // 이름을 바꾼다!
pass.meal = Low_Fat; // 식사를 바꾼다!
</code>
</pre>
##### 포인터, 동적 메모리, "new"연산자
* 많은 자료구조에서 객체를 동적으로 생성해야 하는 필요성을 자주 느낀다. 이러한 이유로 C++ 실행 시스템은 **자유 저장소(free store)"라 불리는 큰 블록의 메모리를 확보한다.
연산자 **new는 주어진 타입의 객체를 생성하는데 필요한 메모리를 자유저장소부터 동적으로 할당하여 이 객체에 대한 포인터를 반환한다. 즉, 이 포인터의 값은 이 객체가 위치한 메모리 주소이다.** 
* **delete**연산자를 통해 **new**를 통해 할당받은 메모리를 프로그램 종료 후에 다시 반납한다.(C++은 garbage collection)을 제공하지 않는다.
<pre>
<code>
Passenger *p;
p = new Passenger;
p->name = "Pocha";
p->meal = Regular;
p->isFreqFlyer = false;
p->freqFlyer = "None";

char* buffer = new char [500];
buffer[3] = 'a';
delete[] buffer;
</code>
</pre>
##### Reference
* 레퍼런스는 단순히 객체에 대한 다른 이름이다. 레퍼런스는 반드시 실제 변수를 가르켜야 한다. 선언될 때 반드시 초기화되어야 한다. 
* 함수에 매게변수를 전달하는데 많이 사용되고 함수로 부터 결과를 반환하는 데에도 많이 사용된다.
<pre>
<code>
string author = "Sam smith";
string& penName = author; // penName은 author에 대한 별칭이다
penName = "Mark Twain"; // author = "Mark Twain"
</code>
</pre>
###### 1.1-4 named constant, scope, namespaces

<pre>
<code>
Mat& MAt::SetTo(InputArray value, InputArray mask = noArray());
</code>
</pre>
