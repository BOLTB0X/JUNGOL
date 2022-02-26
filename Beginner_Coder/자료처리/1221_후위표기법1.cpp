#include <iostream>
#include <vector>

using namespace std;

int stack[11];
int top = -1;

void push(int data) {
	stack[++top] = data;
	return;
}

int pop(void) {
	return stack[top--];
}

int solution(int n, vector<char>& v) {
	int answer = 0;

	for (char& c : v) {
		//정수일 경우
		if (c >= '1' && c <= '9') 
			push(c - '0');
		
		//연산자들 만나다면
		else {
			if (c == '+') 
				stack[top] += pop();
			else if (c == '-')
				stack[top] -= pop();
			else if (c == '*')
				stack[top] *= pop();
			else if (c == '/')
				stack[top] /= pop();
		}
	}
	
	//최상단 pop
	answer = pop();
	return answer;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	vector<char> v;

	cin >> n;
	v.resize(n, 0);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int ret = solution(n, v);

	cout << ret;
	return 0;
}
