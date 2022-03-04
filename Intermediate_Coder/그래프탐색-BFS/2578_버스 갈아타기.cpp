#include <iostream>
#include <vector>
#define MS 100001

using namespace std;

typedef struct {
	int sy, sx, ey, ex;
} Bus;

typedef struct {
	int s, e, idx;
} Node;

vector<Node> horiz[MS]; //수평
vector<Node> verti[MS]; //수직

Bus bus_inf[5001];
int que[MS];
int fr = 0, re = 0;

void enqueue(int data) {
	que[re++] = data;
	return;
}

int dequeue(void) {
	return que[fr++];
}

//너비우선탐색
int BFS(vector<int>& visited, int n, int m, int size, int start_y, int start_x, int end_y, int end_x) {
	while (fr < re) {
		int cur = dequeue();
		int y1 = bus_inf[cur].sy;
		int x1 = bus_inf[cur].sx;
		int y2 = bus_inf[cur].ey;
		int x2 = bus_inf[cur].ex;

		//수직
		if (x1 == x2) {
			//탈출조건
			if (x1 == end_x && end_y >= y1 && end_y <= y2)
				return visited[cur];

			//수직 진행
			for (int y = y1; y <= y2; ++y) {
				for (Node& v : verti[y]) {
					if (visited[v.idx] == 0 && x1 >= v.s && x1 <= v.e) {
						visited[v.idx] = visited[cur] + 1;
						enqueue(v.idx); //큐 삽입
					}
				}
			}

			//수평 진행
			for (Node& h : horiz[x1]) {
				if (visited[h.idx] == 0 && !(y1 > h.e || y2 < h.s)) {
					visited[h.idx] = visited[cur] + 1;
					enqueue(h.idx); //큐 삽입
				}
			}
		}

		else {
			//탈출조건
			if (y1 == end_y && end_x >= x1 && end_x <= x2)
				return visited[cur];

			//수평 진행
			for (int x = x1; x <= x2; ++x) {
				for (Node& h : horiz[x]) {
					if (visited[h.idx] == 0 && y1 >= h.s && y1 <= h.e) {
						visited[h.idx] = visited[cur] + 1;
						enqueue(h.idx); //큐 삽입
					}
				}
			}

			//수평 진행
			for (Node& v : verti[y1]) {
				if (visited[v.idx] == 0 && !(x1 > v.e || x2 < v.s)) {
					visited[v.idx] = visited[cur] + 1;
					enqueue(v.idx); //큐 삽입
				}
			}
		}
	}
}

int solution(int n, int m, int size, int start_y, int start_x, int end_y, int end_x) {
	int answer = 0;
	vector<int> visited(size + 1, 0); //방문리스트

	//수직선 부터
	for (Node& v : verti[start_y]) {
		if (start_x >= v.s && start_x <= v.e) {
			visited[v.idx] = 1;
			enqueue(v.idx);
		}
	}

	//수평선
	for (Node& h : horiz[start_x]) {
		if (start_y >= h.s && start_y <= h.e) {
			visited[h.idx] = 1;
			enqueue(h.idx);
		}
	}

	answer = BFS(visited, n, m, size, start_y, start_x, end_y, end_x);
	return answer;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, size;
	int start_y, start_x, end_y, end_x;

	cin >> n >> m >> size;

	for (int i = 1; i <= size; ++i) {
		int idx, y1, x1, y2, x2;
		cin >> idx >> y1 >> x1 >> y2 >> x2;
		if (x1 > x2) swap(x1, x2);
		
		if (y1 > y2) swap(y1, y2);
		
		if (y1 == y2)
			verti[y1].push_back({ x1,x2,idx });
		
		else if (x1 == x2)
			horiz[x1].push_back({ y1,y2,idx });
		
		bus_inf[idx] = { y1,x1,y2,x2 };		
	}

	cin >> start_y >> start_x >> end_y >> end_x;

	int ret = solution(n, m, size, start_y, start_x, end_y, end_x);
	cout << ret;
	
	return 0;
}