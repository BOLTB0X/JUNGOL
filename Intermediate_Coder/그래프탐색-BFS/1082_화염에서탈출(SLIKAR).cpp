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

void check(int y, int x, int r) {
	//�ߺ� ����
	if (sec[y][x] <= r)
		return;
	sec[y][x] = r;
	enqueue({ y, x, r });
	return;
}

void BFS(int sy, int sx, int ey, int ex) {
	while (head < tail) {
		Node cur = dequeue();

		for (int dir = 0; dir < 4; ++dir) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];

			check(ny, nx, cur.dist + 1);
		}
	}
	return;
}

void solution(int sy, int sx, int ey, int ex) {
	//����� �ҿ� ���� X
	sec[ey][ex] = 0; //0 ó��
	//BFS�� �� ���� �� ���븦 ����
	BFS(sy, sx, ey, ex);

	head = 0, tail = 0;
	sec[ey][ex] = ML;
	//���� 0ó��
	check(sy, sx, 0);
	BFS(sy, sx, ey, ex);
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int sy = 0, sx = 0, ey = 0, ex = 0;
	string tmp;

	cin >> r >> c;
	for (int i = 0; i < r; ++i) {
		cin >> tmp;
		for (int j = 0; j < tmp.length(); ++j) {
			sec[i][j] = ML;
			//������ 0ó��
			if (tmp[j] == 'X')
				sec[i][j] = 0;
			//�� 
			else if (tmp[j] == '*')
				check(i, j, 0);
			//����
			else if (tmp[j] == 'S')
				sy = i, sx = j;
			//��
			else if (tmp[j] == 'D')
				ey = i, ex = j;
		}
	}

	solution(sy, sx, ey, ex);

	if (sec[ey][ex] < ML)
		cout << sec[ey][ex];
	else
		cout << "impossible";
	return 0;
}