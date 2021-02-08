이중 링크드 리스트
============================
![image](https://user-images.githubusercontent.com/50229148/107237657-4e706b00-6a6a-11eb-82ca-f9ce6f4f3896.png)
* **리스트의 양방향을 탐색하는 방법**
* **원소 멤버 이외에, 리스트의 다음 노드와 이전 노드를 각각 가리키는 next링크와 prev링크를 가진다**
* **header 노드와 trailer 노드: head앞, trailer뒤에 어떠한 원소를 저장하지 않는 node를 추가시켜서, header->next = head / trailer->prev = trail을 만든다**(강의 교재에서는 header Node만 사용한다)
## 3.3-1) 이중 링크드 리스트에 삽입하기
* **새로운 Node를 만들고 pre, next pointer를 전후의 원소들과 연결시키면 된다!**
![image](https://user-images.githubusercontent.com/50229148/107240529-5c73bb00-6a6d-11eb-920e-b04c2859f8f3.png)

