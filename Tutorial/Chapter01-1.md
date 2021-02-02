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

#### 프로그램 요소들
* '#include headerfile" -> 헤더파일은 특별한 선언과 정의를 제공하기 위해 사용.</br>
* int main() -> C++ 프로그램의 초기 진입점. main 함수가 매개변수를 받지 않고 종료 후 정수를 결과로 반환한다고 선언. </br>
함수 몸체는 4~11번 라인이며, return문이 실행되면 종료된다. 통상 main함수는 성공의 의미로 0을 반환한다. </br>
* Std:: 객체들이 시스템의 표준 라이브러리에 정의되어 있다는 의미이다. 'using namespace std'로 대체 가능하다.



###### 1.1-2 기본 타입
C++의 기본 타입을 알아보고 이들 타입이 상수나 변수로 표현되는 방법을 알아본다.

* **bool** : True or False
* **char** : 문자
* **short** : 짧은 정수 
* **int** : 정수
* **long** : 긴 정수
* **float** : 단일 정밀도 부동소수점 수
* **double** : 두배 정밀도 부동소수점 수
###### 1.1-3 포인터, 배열 , 구조체
###### 1.1-4 named constant, scope, namespaces

<pre>
<code>
Mat& MAt::SetTo(InputArray value, InputArray mask = noArray());
</code>
</pre>
