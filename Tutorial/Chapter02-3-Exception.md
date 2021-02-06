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
