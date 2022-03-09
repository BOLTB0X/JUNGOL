#include <iostream>
#include <vector>
#define INF 26 * 26 * 26 * 26 //ť�� �ִ����

using namespace std;

vector<vector<int>> board;
int visited[26][26][26][26];

const int dy[9] = { -1, 1, 0, 0, -1, -1, 1, 1, 0 };
const int dx[9] = { 0, 0, -1, 1, -1, 1, -1, 1, 0 };

typedef struct {
	int gy, gx, sy, sx, dist;
} Go;

Go que[INF];
int fr = 0, re = 0;

int Abs(int a) {
	return a < 0 ? -a : a;
}

void enqueue(Go data) {
	que[re++] = data;
	return;
}

Go dequeue(void) {
	return que[fr++];
}

//���� �ʰ�
int in_Range(int y, int x, int n) {
	return 1 <= y && y <= n && 1 <= x && x <= n;
}

//�ʺ�켱Ž��
int BFS(int n, int end_gy, int end_gx, int end_sy, int end_sx) {
	while (fr < re) {
		Go cur = dequeue();

		//���� �������� �����ߴٸ�
		if (cur.gy == end_gy && cur.gx == end_gx && cur.sy == end_sy && cur.sx == end_sx) 
			return cur.dist;
		
		// �� ����ġ�� ���� �� �ִ� ��� ���
		for (int i = 0; i < 9; ++i) {
			int ngy = cur.gy + dy[i];
			int ngx = cur.gx + dx[i];

			//�����ʰ�
			if (in_Range(ngy, ngx, n) == 0)
				continue;
			
			//���������� ���
			if (board[ngy][ngx] == 1)
				continue;

			for (int j = 0; j < 9; ++j) {
				int nsy = cur.sy + dy[j];
				int nsx = cur.sx + dx[j];

				//���� �ʰ��� ���
				if (in_Range(nsy, nsx, n) == 0)
					continue;

				//���������� ���
				if (board[nsy][nsx] == 1)
					continue;

				//��湮�ΰ��
				if (visited[ngy][ngx][nsy][nsx] == 1)
					continue;

				//�� ��ġ�� �Ÿ��� 1������ ���
				if (Abs(ngy - nsy) <= 1 && Abs(ngx - nsx) <= 1)
					continue;

				visited[ngy][ngx][nsy][nsx] = 1;
				enqueue({ ngy, ngx, nsy, nsx, cur.dist + 1 });
			}
		}
	}
	return -1;
}

int solution(int n, int gy1, int gx1, int gy2, int gx2, int sy1, int sx1, int sy2, int sx2) {
	int answer = 0;

	enqueue({ gy1, gx1, sy1, sx1, 0 });
	visited[gy1][gx1][sy1][sx1] = 1; //�湮ó��

	answer = BFS(n, gy2, gx2, sy2, sx2);

	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	int gy1, gx1, gy2, gx2 ,sy1, sx1, sy2, sx2; // �� , ���

	cin >> n;
	cin >> gy1 >> gx1 >> gy2 >> gx2;
	cin	>> sy1 >> sx1 >> sy2 >> sx2;
	board.resize(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> board[i][j];
		}
	}

	int ret = solution(n, gy1, gx1, gy2, gx2, sy1, sx1, sy2, sx2);
	cout << ret;

	return 0;
}