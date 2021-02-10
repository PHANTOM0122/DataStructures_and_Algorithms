Recursive
====================
* **loop를 제외한 반복을 얻는 또 다른 방법이다**
* **자신의 정의 내에서 자기 자신을 호출한다**
* Direct recursion: f(){f();}
* Indirect recursion: f()->g()->h()->f();
* **장점: 짧고, 간결하고, 이해하기 쉬운 코드가 만들어진다**
* **단범: 실행시간이 길다->비효율적**
> **Base case**
  * recursive call이 중단되는 case!
> **General case**
  * **작은 경우의 자기 자신을 다시 호출하는 case**
  * **결국 base case를 향해 간다.**
  
## 계승함수(factorial function)
> **factorial(n) = 1(if n==0) or n * factorial(n-1) (if n>=1)**
<pre><code>
int recursiveFactorial(int n){
  if(n==0) return 1;
  else return n * recursiveFactorial(n-1);} // 재귀적인 경우
</code></pre>
