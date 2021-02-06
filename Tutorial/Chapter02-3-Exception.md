예외 처리
===================
## 2.4-1 예외 객체
* **예외가 발생하면 throw -> 예외를 처리하는 코드에 의해 catch**
* 오류가 발생하는 경우가 많아지기 때문에 타입으로 구별한다.
* **Derived class: 상속을 받는 calss(자식 class)**
### Exmaple 1 // Vector bound except
<pre><code>
try{ cout << v.at(i) << endl;}
catch (std::exception& e){ cout << e.what() << endl}
or 
catch (std::exception& ){cout << "Index out of range" << endl;}

class Mathexception{
public:
  Mathexception(const string& err) : errMsg(err) {}
  string getError() {return errMsg;}
private:
  string errMsg;
};

class Zerodivide : class Mathexception{
public:
  Zerodivide(const string& m) : Mathexception(m) {}
};
</code></pre>
* **try block에서 예외가 발생하면 즉시 catch block으로 제어권이 넘어간다**
> **throw(예외이름1, 예외이름2)**
  * try{ try 명령문 } -> catch(예외타입  식별자) { catch 명령문 }
  ##### Example code
  <pre><code>
  try{ if(divisor==0){throw ZeroDivide("Divide by zero in module x");}}
  catch (ZeroDivide& zde) { // 0으로 나누는걸 처리하는 코드}
  cathc (MathException& me) { //0으로 나눈 것과 다른 산술 예외 처리 }
  </code></pre>
### 예외 명시
* **함수를 선언할 때 발생할 수 있는 예외들을 지정해야 한다**
* 예외 지정을 통해 컴파일러에게 어떤 예외를 준비해야 할지 알려준다.
> void cacular() throw(ZeroDivide, NegativeRoot) { // 함수 본체 }
  * **위와 같은 정의는 함수가 이러한 2개의 예외나 이들 타입으로 유도된 예외가 던져질 수 있고, 다른 예외는 던저지지 않는다**
* 함수가 **throw문을 포함하지 않는 경우에는 어떠한 예외도 던질 수 있따**
<pre><code>
void func1(); // 어떤 예외도 던질 수 있다
void func2(); // 아무런 예외도 던질 수 있다
</code></pre>
### 일반적인 예외 class
* **C++에서는 일반적인 예외를 제공하지 않아서 사용자 지정 클래스를 만들어야 한다.**
* **std::exception class**의 경우가 많이 사용되는 것 같다.
<pre><code>
catch (std::out_of_range& e) {
std::cout << "Error: vector bounds exceeded\n";
std::cout << e.what() << '\n';
}

class RuntimeException{
private:
  string errMsg;
public:
  RuntimeException(const string& err) {errorMsg = err;}
  string getMessage() const {return errMsg;}
};
</code></pre>
* 아니면 RuntimeException과 같이 내가 스스로 지정해서 기본 예외 클래스를 만들수 있다. 
-> **모든 예외 e에 대해 기본 클래스로부터 모든 예외를 상속받음으로써 상속된 출력 연산자를 이용하여 e의 오류 메시지를 출력 가능하다**
