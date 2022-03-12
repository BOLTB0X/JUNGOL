#include <iostream>
#include <vector>

using namespace std;

typedef struct {
	int idx, dist;
} Candi;

Candi que[2501];
int fr, re;

void enqueue(Candi data) {
	que[re++] = data;
	return;
}

Candi dequeue(void) {
	return que[fr++];
}

int result;
vector<int> adj[51]; 
int candi_cnt[51] = { 0, };

//�ʺ�켱Ž��
void BFS(int n, int start) {
	vector<int> visited(n+1, 0); //�湮����Ʈ ����
	fr = 0, re = 0; //ť �ʱ�ȭ
	int max_dist = -1;
	enqueue({ start, 0 });
	visited[start] = 1;

	while (fr < re) {
		Candi cur = dequeue();

		for (int& next : adj[cur.idx]) {
			//��湮
			if (visited[next] == 1)
				continue;

			visited[next] = 1;

			//�ִ� ����
			if (max_dist < cur.dist + 1)
				max_dist = cur.dist + 1;
			enqueue({ next, cur.dist + 1 });
		}
	}
	//üũ
	candi_cnt[start] = max_dist; 

	return;
}

vector<int> solution(int n) {
	vector<int> answer;
	for (int i = 1; i <= n; ++i) 
		BFS(n, i);
	
	int min_dist = candi_cnt[1];

	for (int i = 2; i <= n; ++i) {
		if (min_dist > candi_cnt[i])
			min_dist = candi_cnt[i];
	}

	//ȸ�� �ĺ� ��
	result = min_dist;
	
	for (int i = 1; i <= n; ++i) {
		if (min_dist == candi_cnt[i])
			answer.push_back(i);
	}

	return answer;
}
int main(void) {
	int n;

	cin >> n;
	while (1) {
		int a, b;
		cin >> a >> b;

		if (a == -1 && b == -1)
			break;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> ret = solution(n);
	cout << result << ' ' << ret.size() << '\n';
	for (int& r : ret)
		cout << r << ' ';
	return 0;
}
