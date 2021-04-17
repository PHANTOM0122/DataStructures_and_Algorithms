Data Design and Implementation
==================================
* **Data: representation of information(정보의 표현)**
* **Data abstraction: logical properties를 implementation으로부터 분리하는 것**
* **Data encapsulation: Application 단계(logical level)에서 필요한 data들만 남겨두고 나머지 data는 information-hiding을 통해 은닉하는 것**
* **Abstract Data Type(ADT): properties와 implementation이 분리된 data type**
* **Data Structure: Data가 여러개 존재해야 하며, components elements로 분리될 수 있으며, 저장하는 방법에 따라 data에 access하는 방법이 달라진다**

## Data from 3 diffrent levels
* **Application level: modeling real-life data in a specific context**
* **Logical level: (WHAT) abstract view of domain and operations**
* **Implemenatition level: (HOW) 어떻게 기계에서 작동되고 표현되는지에 대한 단계**

> **4 basic kinds of ADT operations**
  1) Constructor: create new obejct
  2) Transformer: data value를 변경
  3) Observer: data value를 변경하지 않고 얻기만 한다.,
  4) Iterator: 반복자. 일정한 순서로 data components에 접근 가능하게 해준다**

* built-in types: 더 쪼갤 수 없는(machine-level operation으로 정의된) data type. 
* composite data type: collection of individual data in One variable name. **components의 type은 달라도 된다. Ex) struct, class** C++의 composite 경우는 array, struct, class

## Two forms of Composite Data types
1) **Structed: 일정한 순서로 data가 조직화되어 있어서, organization에 따라 access 방법이 달라진다 Ex) Array**
2) **Unstructed: not organized(순서가 없는) data type. Ex) classes, structs**

## Record at logical level
* **Record: 유한한 갯수의 elements의 모음. composite data type, 동일한 종류의 elements를 가질 필요는 없다** (Array와 대비된다)
<pre><code>
struct CarType{
  int year;
  char name[10];
  float price;
};</code></pre>
* . 연산자를 이용하여 struct member에 접근이 가능하다
* valid struct operations : = (등호), pass as parameter(입력), return(출력) 값으로 될 수 있다
**구조체, class는 기본적으로 parameter로 전달될 시 pass by value로 진행된다. 따라서 & 를 이용하여 pass by reference를 이용하기도 한다**

# Records at Implementation level
* 실행하기 위해서는 메모리 공간을 할당 받아야 한다
* **Base address: first cell of record의 memory address**
* Member-length-offset-table을 이용하여 메모리 주소 계산 가능

## 1차원 배열의 logical level
* **1차원 배열은 finited,fixed size,homogenous elements 해야한다**
* **상대적인 위치가 존재하며, 어떤 elements도 즉시 access가 가능하다**
* **Array operation: creation, storing value, retrieving value. -> assign(=)은 불가하다, return type이 될 수도 없다**
* **Array가 parameter로 전달될 시, 자동으로 pass by refrence로 넘어간다**
<pre><code>
int a = 4; int b[a]; -> 안되는 이유: a의 값은 compile시 결정되는데 array크기는 compile할 때 알려줘야 하므로 compile전에 이미 결정되어야 한다
</code></pre>
![image](https://user-images.githubusercontent.com/50229148/109772954-f92b1200-7c41-11eb-80c7-65edc9a8c946.png)
![image](https://user-images.githubusercontent.com/50229148/109773384-7bb3d180-7c42-11eb-929d-abe95e27386a.png)

## 2차원 배열의 logical level
* **Array operation: creation, storing value, retrieving value. -> assign(=)은 불가하다, return type이 될 수도 없다**
* [ row ] [ col ]을 이용하여 component position에 접근가능하다
* memory는 linear 함으로, 2차원 배열을 저장할 시 row major. column major방식이 존재한다(아래와 같이 row major를 많이 사용)
![image](https://user-images.githubusercontent.com/50229148/109773827-fb41a080-7c42-11eb-957e-da4a6736b109.png)

## C++ class data type
* **class: unsturcted type으로써 data member와 member function을 encapsulate한 data type이다**
* client: class와 객체를 이용하는 software
* 선언 헤더 파일과 구현 파일을 분리하여 사용 -> client에게는 header파일만 보여주면 된다
* :: 연산자를 이용하여 class member fuction에 접근할 수 있다
> Three inter-related constructs
  * class: object 구조를 결정한다
  * object: 기본적인 run-time 요소
  * inheritance: 상속을 통해 is-a relation ship 형성. **다형성(polymorphism의 경우 runtime시 결정)**

## Offset table
![image](https://user-images.githubusercontent.com/50229148/115098262-0be77500-9f6a-11eb-881c-83cc92252265.png)
![image](https://user-images.githubusercontent.com/50229148/115098277-24578f80-9f6a-11eb-802a-95ec8a89a4ef.png)

