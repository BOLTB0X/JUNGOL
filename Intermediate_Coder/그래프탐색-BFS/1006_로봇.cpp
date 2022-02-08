#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;
int board[101][101];
bool visited[101][101][5];

const int dy[5] = { 0,0,0,1,-1 };
const int dx[5] = { 0,1,-1,0,0 };

int turn_Left(int cd) {
    if (cd == 1) 
        return 4;
    else if (cd == 2) 
        return 3;
    else if (cd == 3) 
        return 1;
    else if (cd == 4) 
        return 2;
}

int turn_Right(int cd) {
    if (cd == 1) 
        return 3;
    else if (cd == 2) 
        return 4;
    else if (cd == 3) 
        return 2;
    else if (cd == 4) 
        return 1;
}

int BFS(queue<pair<pair<int, int>, pair<int, int>>>& que, pair<pair<int, int>, int> start, pair<pair<int, int>, int> end) {
    int result = -1;
    int sy, sx, sd, ey, ex, ed;
    sy = start.first.first;
    sx = start.first.second;
    sd = start.second;
    ey = end.first.first;
    ex = end.first.second;
    ed = end.second;

    que.push({ {sy,sx},{sd,0} });
    visited[sy][sx][sd] = true;

    while (!que.empty()) {
        int cy = que.front().first.first;
        int cx = que.front().first.second;
        int cd = que.front().second.first;
        int cnt = que.front().second.second;
        que.pop();

        if (cy == ey && cx == ex && cd == ed) {
            result = cnt;
            break;
        }

        for (int k = 1; k <= 3; ++k) {
            int ny = cy + (dy[cd] * k);
            int nx = cx + (dx[cd] * k);

            //이 방향으로 더이상 진행 불가
            if (ny < 1 || ny > n || nx < 1 || nx > m)
                break;
            //이 방향으로 더이상 진행 불가
            if (board[ny][nx] == 1)
                break;
            //재방문이면 
            if (visited[ny][nx][cd])
                continue;

            visited[ny][nx][cd] = 1;
            que.push({ { ny,nx }, { cd,cnt + 1 } });
        }

        int nd;
        nd = turn_Left(cd);
        if (!visited[cy][cx][nd]) {
            visited[cy][cx][nd] = true;
            que.push({ { cy, cx }, { nd,cnt + 1 } });
        }
        
        nd = turn_Right(cd);
        if (!visited[cy][cx][nd]) {
            visited[cy][cx][nd] = true;
            que.push({ { cy, cx }, { nd,cnt + 1 } });
        }
    }

    return result;
}

int solution(pair<pair<int, int>, int> start, pair<pair<int, int>, int> end) {
    int answer = 0;

    queue<pair<pair<int, int>, pair<int, int>>> que;
    answer = BFS(que, start, end);
    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            cin >> board[i][j];
    }

    int y, x, d;
    pair<pair<int, int>, int> start, end;
    cin >> y >> x >> d;
    start.first.first = y;
    start.first.second= x;
    start.second = d;
    
    cin >> y >> x >> d;
    end.first.first = y;
    end.first.second= x;
    end.second = d;

    int ret = solution(start, end);
    cout << ret;
    return 0;
}
