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
  > **bool_exp가 참이면 true_exp반환, 그렇지 않으면 false_exp가 반환된다.**
  smaller = (x < y ? x : y); // smaller = min(x,y) 
