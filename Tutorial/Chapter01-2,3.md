연산식
=========================

> **증가와 감소 연산자**
* 후위증감소 연산자는 변수의 값을 반환한 후 변수를 1 증가시킨다 Var++, var--
* 전위증감소 연산자는 우선 변수의 값을 증가시키고, 그 값을 반환한다 ++var, --var

### Example
<pre> <code>
int a[] = {0,1,2,3};
int i = 2;
int j = i++; // j = 2, i = 3;
int k = --i; // k = 2, i = 2;
cout << a[k++]; // a[2]가 출력되고 k=3이 된다.
</code></pre>

> **other 연산자**
* class name :: member -> 클래스 영역 지정
* namespace name :: member -> 이름공간 지정
* bool_exp? ture_exp : false_exp -> 조건적 연산식
  > **bool_exp가 참이면 true_exp반환, 그렇지 않으면 false_exp가 반환된다.**</br>
  smaller = (x < y ? x : y); // smaller = min(x,y) 

> **typecast를 통한 type 변경**
* 변수의 타입을 바꾸도록 허용하는 연산이다.
### Example
<pre> <code>
int cat = 14; 
double dog = (double) cat; // 전통적인 C타입의 변환
double dog = double (cat); // C++ 함수-스타일 형변환

int i1 = 18;
int i2 = 16;
double v1 = i1 / i2; // dv1의 값은 1
double v2 = double(i1)/ double(i2); // dv2의 값은 1.125
double v3 = double(i1/i2); // dv3의 값은 1
</code></pre>

> **static_cast**
* 두 타입간의 형변환에서 사용한다.
* **잠정적으로 안전하지 않은 연산이 제기된 경우 경고를 제시할 수 있다.**
 > **static_cast <desired_type> (expression)
<pre> <code>
double d1 = 3.2;
double d2 = 3.999;
int i1 = static_cast<int> (d1); // i1의 값은 3
int t2 = static_cast<int> (d2); // i2의 값은 3
