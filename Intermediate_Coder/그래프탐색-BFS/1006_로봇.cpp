#include <iostream>

using namespace std;

typedef struct {
    int y, x, dir, cmm;
} Node;

Node que[1000201];
int fr = 0, re = 0;

void enqueue(Node data) {
    que[re++] = data;
    return;
}

void dequeue(void) {
    fr++;
    return;
}

int board[101][101];
int visited[101][101][5];
//동서남북
const int dy[5] = { 0, 0, 0, 1, -1 };
const int dx[5] = { 0, 1, -1, 0, 0 };


//방향 전환
int turn_dir(char cmd, int dir) {
    if (cmd == 'L') {
        if (dir == 1)
            return 4;
        else if (dir == 2)
            return 3;
        else if (dir == 3)
            return 1;
        else if (dir == 4)
            return 2;
    }
    else {
        if (dir == 1)
            return 3;
        else if (dir == 2)
            return 4;
        else if (dir == 3)
            return 2;
        else if (dir == 4)
            return 1;
    }
}

int solution(int n, int m, int sy, int sx, int sd, int ey, int ex, int ed) {
    int answer = -1;

    //너비우선탐색이용
    Node start = { sy,sx,sd,0 };
    enqueue(start);
    visited[sy][sx][sd] = 1;

    while (fr != re) {
        int cy = que[fr].y;
        int cx = que[fr].x;
        int cd = que[fr].dir;
        int cnt = que[fr].cmm;
        dequeue();

        //탈출조건
        if (cy == ey && cx == ex && cd == ed) {
            answer = cnt;
            break;
        }

        //명령 1: go
        for (int k = 1; k <= 3; ++k) {
            int ny = cy + (dy[cd] * k);
            int nx = cx + (dx[cd] * k);

            //범위초과 이 방향 및 k 불가 멈춰야함
            if (ny < 1 || ny > n || nx < 1 || nx > m)
                break;

            //재방문 경우는 그냥 패스
            if (visited[ny][nx][cd] == 1)
                continue;

            //벽인 경우는 방향을 틀어야 하므로
            if (board[ny][nx] == 1)
                break;

            Node next = { ny,nx,cd,cnt + 1 };
            enqueue(next);
            visited[ny][nx][cd] = 1;
        }

        //방향 전환
        int nd = turn_dir('L', cd); //L
        if (visited[cy][cx][nd] == 0) {
            Node next = { cy, cx, nd, cnt + 1 };
            enqueue(next);
            visited[cy][cx][nd] = 1;
        }

        nd = turn_dir('R', cd); //R
        if (visited[cy][cx][nd] == 0) {
            Node next = { cy, cx, nd, cnt + 1 };
            enqueue(next);
            visited[cy][cx][nd] = 1;
        }
    }

    return answer;
}

int main(void) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            cin >> board[i][j];
    }

    int sy, sx, sd, ey, ex, ed;
    cin >> sy >> sx >> sd;
    cin >> ey >> ex >> ed;

    int ret = solution(n, m, sy, sx, sd, ey, ex, ed);
    cout << ret;

    return 0;
}
