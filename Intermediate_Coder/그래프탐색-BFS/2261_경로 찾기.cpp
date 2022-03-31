#include <iostream>
#include <vector>

using namespace std;

typedef struct {
	int idx;
	vector<int> path;
} Node;

Node que[1000001];
int fr = 0, re = 0;

void push(Node data) {
	que[re++] = data;
	return;
}

vector<string> hamings;

// 해밍경로가 1인지 체크
int is_haming_dist(string a, string b, int k) {
	int cnt = 0;

	for (int i = 0; i < k; ++i) {
		if (a[i] != b[i])
			cnt++;
	}

	return cnt == 1 ? 1 : 0;
}

vector<int> solution(int n, int k, int start, int end) {
	vector<int> answer;
	vector<int> visited(n + 1, 0); // 방문리스트
	vector<int> tmp; // 임시

	tmp.push_back(start);
	push({start, tmp});
	visited[start] = 1;

	// 큐가 비어질때까지
	while (fr < re) {
		Node cur = que[fr];
		fr++; // pop

		// 목적지에 도달한다면
		if (cur.idx == end) {
			for (int& p : cur.path)
				answer.push_back(p);
			break;
		}

		// 순회
		for (int i = 1; i <= n;++i) {
			// 재방문
			if (visited[i] == 1)
				continue;

			// 해밍경로가 1이면
			if (is_haming_dist(hamings[cur.idx], hamings[i], k) == 1) {
				Node next = { i, cur.path };
				next.path.push_back(i);
				visited[next.idx] = 1; //방문 처리
				push(next);
			}
		}
	}

	return answer;
}

int main(void) {
	int n, k, start, end;

	cin >> n >> k;
	hamings.resize(n + 1);
	for (int i = 1; i <= n; ++i) 
		cin >> hamings[i];
	cin >> start >> end;
	
	vector<int> ret = solution(n, k, start, end);
	if (ret.size() == 0)
		cout << -1;
	else {
		for (int& r : ret)
			cout << r << ' ';
	}

	return 0;
}
