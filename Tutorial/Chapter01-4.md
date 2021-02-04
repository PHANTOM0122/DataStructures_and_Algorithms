함수
=========================
* return type : 함수에 의해 반환되는 값 또는 객체의 타입을 가리킨다
* Function name : 함수에게 주어진 이름을 가리킨다. 변수, 함수의 이름은 그 주소값(첫번째 elemet의)을 나타낸다!!
* Argument list(매개변수 리스트) : 함수로 전달될 값을 위한 리스트
* Function body : 수행될 계산을 정의하는 C++ 명령문들의 모임이다.
* **선언과 정의의 분리 -> Declare: compiler가 함수의 존재를 인식하도록 만드록, 그 함수가 올바르도록 사용됐는지 compiler가 확인 가능!**

> ### 1.4-1)매개변수 전달
  * **call-by-value**
    * 기본적으로 C++에서는 매개변수가 value값으로 전달된다.
    * 매개변수가 시스템에 전달될 때에는 **시스템이 함수에 전달될 변수의 복사본을 만든다 -> 매개변수를 수정해도 실제 매개변수는 수정되지 않는다.**
  * **call-by-reference** 
    * referece type으로 전달 -> **수정시 실제 값에도 영향을 끼친다.**
    * 대형 구조체나 클래스 매개변수는 특히 by value를 사용할 시, 복사를 해야하므로 상당히 비효율적이서 by reference를 사용한다.
    * **constant reference: compiler에게 refrence로 전달하지만 값을 수정을 못하게 하는 것을 통보하는 것이다**
    <pre><code>
    void someFunction(const Passenger& pass) { pass.name = "new name"; } // Error!
    </code></pre>
  * **call-by-pointer**
    * **매개변수 자체를 전달하는 대신, 매개변수의 주소를 전달 -> 주소값을 수정하진 못하더라도 포인터를 엑세스해서 이것이 가리키는 값을 변경할 수 있다**
    * **배열 매개변수: 배열역시 전체를 복사하기 보다는, 첫 번째 원소에 대한 포인터로 변환된다. 즉 T[]인 객체가 "T*"로 변환된다. -> T는 배열의 첫 원소를 가리킨다.**

> ### 1.4-2)Overloading&Inlining
 * **Function overloading**
   * 두 개 이상의 함수가 같은 이름을 가졌지만, 서로 다른 매개변수 리스트를 가질 때 발생한다.
   ### Example 
   <pre><code>
   void print(int x) {cout << x;} // 정수를 프린트하다.
   void print(const Passenger& pass){ // passenger를 프린트하다
         cout << pass.name << " " << pass.meal << " " << pass.FlyerNo << endl;
         }
   </code></pre>
   
 * **연산자 오버로딩**
   * **class 외부에서 선언 및 정의시, friend함수를 사용해야 한다**
   ### 이진 operator Example
   <pre><code>
   bool operator == (const Passenger& x, const Passenger& y){
    return x.name == y.name; && x.meal == y.meal && x.FlyerNo == y.FlyerNo;
   }
   </code> </pre>
   ### 단일 operator Example
   <pre> <code>
   ostream& operator << (ostream& out, const Passenger& pass){
    out << pass.name << pass.meal << pass.FlyerNo;
   }
   </code></pre>
 * **In-line 함수**
   * 매우 짧은 함수.
   * inline int min(int x, int y) { return (x < y ? x : y); }
