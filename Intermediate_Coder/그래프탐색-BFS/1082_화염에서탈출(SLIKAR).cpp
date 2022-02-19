#include <iostream>
#define ML 251100

using namespace std;

typedef struct {
	int y, x, dist;
} Node;

int r, c;
int sec[51][51];
Node que[ML];
int head = 0, tail = 0;

const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,1,-1 };

void enqueue(Node data) {
	que[tail++] = data;
	return;
}

Node dequeue(void) {
	return que[head++];
}

//해당 큐의 진행과정의 선행과정
void check(int y, int x, int dist) {
	//중복 방지
	if (sec[y][x] <= dist)
		return;

	sec[y][x] = dist;
	enqueue({ y,x,dist });
	return;
}

//너비우선탐색
void BFS(void) {
	while (head < tail) {
		Node cur = dequeue();

		for (int dir = 0; dir < 4; ++dir) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];
			int nd = cur.dist + 1;

			check(ny, nx, nd);
		}
	}

	return;
}

void solution(int sy, int sx, int ey, int ex) {
	//화염의 이동경로 체크
	sec[ey][ex] = 0;
	BFS();

	//초기화 후 재우의 탈출 경로 체크
	head = 0, tail = 0;
	sec[ey][ex] = ML;
	check(sy, sx, 0);
	BFS();
	
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//비어있는 칸 '.', 불은 '*', 바위 'X', 용사의 집 'D', 재우의 위치 'S'
	char ch;
	int sy = 0, sx = 0, ey = 0, ex = 0;
	cin >> r >> c;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> ch;
			sec[i][j] = ML;

			//바위는 접근 불가
			if (ch == 'X')
				sec[i][j] = 0;

			//목적지
			else if (ch == 'D') 
				ey = i, ex = j;
			
			//출발지
			else if (ch == 'S') 
				sy = i, sx = j;
			
			//불
			else if (ch == '*') {
				check(i, j, 0);
			}
		}
	}

	solution(sy, sx, ey, ex);
	
	if (sec[ey][ex] < ML)
		cout << sec[ey][ex];
	else
		cout << "impossible";
	return 0;
}
