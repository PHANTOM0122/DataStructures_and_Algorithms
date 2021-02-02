#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

vector<string> getHtmlTags() {
	vector<string> tags;
	string line;
	while (getline(cin, line)) {// 파일 끝까지 읽는다.
		; // 텍스트의 한 줄을 입력한다
		cin >> line;
		int pos = 0;
		int ts = line.find("<", pos); // 태그의 시작
		while (ts != string::npos) { // 문자열의 끝까지 반복한다. npos - 개행문자
			int te = line.find(">", ts + 1);
			tags.push_back(line.substr(ts, te - ts + 1));// 태그 안의 문자열을 벡터에 추가
			pos = te + 1; // 시작 위치를 전진!
			ts = line.find("<", pos);
		}
	}
	return tags;
}

bool isHtmlMatched(const vector<string>& tags) { // 태그 짝인지 확인
	stack<string> S;
	typedef vector<string>::const_iterator Iter; // Iterator type!

	for (Iter p = tags.begin(); p != tags.end(); p++) {
		if (p->at(1) != '/') // 여는 태그일때
			S.push(*p); // 여는 태그이면 스택에 push
		else { // 닫는 태그일때
			if (S.empty()) return false; // 짝이 없다!
			string open = S.top().substr(1); // '<'를 제외한 여는 태그
			string close = S.top().substr(2); // '</'를 제외한 닫는 태그
			if (open.compare(close) != 0) // 동일하지 않음!
				return false;
			else S.pop(); // 동일할 경우, 짝이 맞는 원소를 pop!
		}
	}
	if (S.empty()) return true; // 스택이 비어있으면 모든 짝이 맞는 경우
	else return false; // 맞지 않는 것이 있다!
}

// Test Driver
int main() {
	if (isHtmlMatched(getHtmlTags())) // Read Tags!
		cout << "The input file is a matched Html Tags!" << endl;
	else
		cout << "The input file is not a matched Html Tags!" << endl;
}