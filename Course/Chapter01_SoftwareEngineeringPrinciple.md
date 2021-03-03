Software engineering principle
===================================
> **Software Life Cycle**
  1) 문제 분석(problem analysis)
  2) 문제 도출(Requirements elicitation)
  3) 요구사항 기술(Software specification)
  4) High-and low-level design (설계)
  5) Implementation(구현)
  6) Testing and Verification -> debug 및 test 하는 것이 중요하다
  7) Delivery
  8) Operation
  9) Maintenance

**Software Engineering의 경우는 시간과 비용을 최대한 줄이는 것이 가장 중요한 목표이다**

> **programmer Toolboxes**
  1)**Hardware: 컴퓨터 및 기계 장치들**
  2)**Software: OS, editors, complier, interpreter etc**
  3)**Ideaware: 개발하기 위해 필요한 지식들**

> **Goals of Quaility software(다양한 quality 평가 관점들)**

  **1) 작동해야 한다
  2) 시간과 노력이 적게 들어야 한다
  3) reusable 해야 한다
  4) 시간과 예산 내에서 완성되어야 한다**

## Abstraction
: **system 관점에서 꼭 필요한 데이터만 남기는 것을 추상화(Abstraction)이라 한다**

* **information hiding: 필요하고 중요한 정보만을 detail하게 표시하고, 나머지는 숨긴다**

> **Procedure vs object-oriented Code**
* procedural(절차적 관점): verb를 강조 -> **focus on processes**
* object-oriented: nouns를 강조 -> **focus on Data objects**

> **verification vs validation**
* **verification : 설계/개발 출력 결과가 해당 단계의 입력 요구사항에 적합한지를 확인하는 평가 절차**
* **validation: 최종 설계/개발 결과물이 사용자 요구사항과 사용 목적에 적합한지를 확인하는 과정**

> **Types of Errors**
  1) specification : 기능 설명 오류
  2) design : 설계 오류
  3) coding : 구현 오류
  4) input : Test case를 잘 못 만든 경우
**단계가 내려갈수록 비용이 증가한다 -> 에러는 초기에 발견하는 것이 중요하다**

> **Controlling Errors**
1) **Robustness: 에러가 발생하더라도 죽지 않는 견고한 프로그램을 만드는 것이 중요하다**
2) **Preconditions: postconditions이 참이라 할 때, 함수나 연산의 초기 입력값이 참이라고 가정**
3) **Postconditions: preconditions이 참이라 할 때, 함수나 연산에 의해 results를 예측하는 것.
** pre&post condition 모두 valitation의 문제이다. 
