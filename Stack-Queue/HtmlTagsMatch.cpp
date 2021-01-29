#include <string>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<string> getHtmlTags() {
	vector<string> tags;

	while (cin) {
		string line;
		getline(cin, line);
		int pos = 0; // 현재의 스캔 위치
		int ts = line.find("<", pos); // 태그의 시작
		while(ts != string::npos) { // 문자열의 끝까지 반복한다
			int te = line.find(">", ts + 1); // 태그 끝을 찾는다.
			tags.push_back(line.substr(ts, te - ts + 1)); // 태그를 백터에 추가
			pos = te + 1; // 시작 위치를 전진
			ts = line.find("<", pos); // 또 다시 태크 찾기
		}
	}
	return tags;
}

bool isHtmlMatched(const vector<string>& tags) {
	stack<string> S; // 여는 태그를 저장하는 스택
	typedef vector<string>::const_iterator Iter; 

	for (Iter p = tags.begin(); p != tags.end(); p++) {
		if (p->at(1) != '/') // 여는 태그일때
			S.push(*p);
		else { // 닫는 태그일때
			if (S.empty()) return false;
			string open = S.top().substr(1); // '<'를 제외한 여는 태그
			string close = p->substr(2); // '</'를 제외한 닫는 태그
			if (open.compare(close) != 0) return false; // 맞지 않음
			else S.pop();
		}
	}
	if (S.empty())
		return true;
	else
		return false;
}

int main() {
	if (isHtmlMatched(getHtmlTags()))
		cout << "The input file is a matched HTML document" << endl;
	else
		cout << "The input file is not a matched HTML document" << endl;
}