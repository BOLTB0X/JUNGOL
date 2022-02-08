#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int y, x, dir, cnt;
} ROBOT;

typedef struct {
    int y, x, dir;
} INF;

ROBOT que[101 * 101];
int head = 0, tail = 0;

int board[101][101];
int visited[101][101][5];

//동서남북
const int dy[5] = { 0, 0, 0, 1, -1 };
const int dx[5] = { 0, 1, -1, 0, 0 };

void enqueue(ROBOT data) {
    que[tail++] = data;
    tail = tail % (101*101);
    return;
}

void dequeue(void) {
    head++;
    head = head % (101*101);
    return;
}

int turn_dir(int dir, char d) {
    if (d == 'L') {
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

int solution(int n, int m, INF start, INF end) {
    int answer = -1;

    int size = m * n + 1;
    ROBOT data = { start.y, start.x, start.dir, 0 };
    enqueue(data);
    visited[start.y][start.x][start.dir] = 1;

    //BFS
    while (head != tail) {
        int cy = que[head].y;
        int cx = que[head].x;
        int cd = que[head].dir;
        int cnt = que[head].cnt;
        dequeue();

        if (cy == end.y && cx == end.x && cd == end.dir) {
            answer = cnt;
            break;
        }

        for (int k = 1; k <= 3; ++k) {
            int ny = cy + (dy[cd] * k);
            int nx = cx + (dx[cd] * k);

            if (ny < 1 || ny > n || nx < 1 || nx > m)
                break;
            if (board[ny][nx] == 1)
                break;
            if (visited[ny][nx][cd] == 1)
                continue;

            visited[ny][nx][cd] = 1;
            ROBOT next = { ny,nx,cd, cnt + 1 };
            enqueue(next);
        }

        //방향전환
        int next_dir;
        next_dir = turn_dir(cd, 'L');

        if (visited[cy][cx][next_dir] == 0) {
            visited[cy][cx][next_dir] = 1;
            ROBOT next = { cy, cx, next_dir, cnt + 1 };
            enqueue(next);
        }
        next_dir = turn_dir(cd, 'R');

        if (visited[cy][cx][next_dir] == 0) {
            visited[cy][cx][next_dir] = 1;
            ROBOT next = { cy, cx, next_dir, cnt + 1 };
            enqueue(next);
        }
    }

    return answer;
}

int main(void) {
    int n, m;
    INF start, end;

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            scanf("%d", &board[i][j]);
    }

    scanf("%d %d %d", &start.y, &start.x, &start.dir);
    scanf("%d %d %d", &end.y, &end.x, &end.dir);

    int ret = solution(n, m, start, end);
    printf("%d", ret);

    return 0;
}