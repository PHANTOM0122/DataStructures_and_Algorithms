Standard Template Library
=========================
* **일반적인 자료구조를 위한 유용한 클래스들의 모음이다**
  * **String: **문자열을 포함한 자료구조
  * **stack**: lifo 구조의 container
  * **queue**: fifo 구조의 container
  * **deque**: 양쪽으로 출입하는 큐
  * **vector**: 크기를 바꿀 수 있는 resized 배열
  * **list**: 이중으로 링크된 리스트
  * **priority_queue**: 값을 기준으로 정렬된 큐
  * **set: 집합**
  * **map: 연관 리스트**
  
  ## 탬플릿과 STL vector 클래스
  * **vector의 경우 index를 확인하여 벗어날 경우 error를 발생시킨다!**
  * #include<vector>를 사용하여야 한다.
  * 크기를 resize 가능하다!
  
  ## STL string에 대한 추가 사항
  * **+:**스트링을 연결시키는 연산자
  * **str.size():**스트링의 길이를 알려주는 함수
  * **str[i]:**스트링의 각각의 문자에 접근 하기 위한 index 연산자
  * **str.find(p):**str에서 string p 가 처음 출현한 index 반환
  * **str.find(p,i):**str에서 index i 이후에 srtring p가 처음 출현한 index 반환, string p가 발견되지 않은 것을 가리키기 위해 string::npos반환.
  * **str.substr(i,m):**str에서 i위치에서 시작하고 m개의 문자로 이루어진 sub-string 반환
  * **str.insert(i,p):**string p를 str[i] 앞에 삽입
  * **str.erase(i,m):**str[i]에서부터 길이 m만큼의 sub-string을 삭제
  * **str.replace(i,m,p):**index[i]에서 시작해서 길이 m만큼의 sub-string을 p로 대체
  * **getline(is,str):**입력 stream is에서 단일 라인을 읽고, str에 결과를 저장
  #####Example code
  <pre><code>
  string s = "a dog";
  s += "is a dog"; 
  cout << s.find("dog"); // 2반환
  if(s.find("doug") == string::npos) {} // True
  cout << s.substr(7,5); // "s a d"
  s.replace(2,3,"frog"); // "a frog is a dog"
  s.erase(6,3); // "a frog a dog"
  </code></pre>
  
  
