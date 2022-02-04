#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int board[101][101];
bool visited[101][101][5];

const int dy[5] = { 0,0,0,1,-1 };
const int dx[5] = { 0,1,-1,0,0 };

int solution(int m, int n, pair<pair<int, int>, int> start, pair<pair<int, int>, int> end) {
    int answer = -1;
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({ {start.first.first, start.first.second}, {start.second, 0} });
    visited[start.first.first][start.first.second][start.second] = true;

    while (!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int dir = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();

        if (y == end.first.first && x == end.first.second && dir == end.second) {
            answer = cnt;
            break;
        }

        for (int k = 1; k <= 3; ++k) {
            int ny = y + dy[dir] * k;
            int nx = x + dx[dir] * k;

            if (visited[ny][nx][dir])
                continue;
            if (1 <= ny && ny <= m && 1 <= nx && nx <= n && board[ny][nx] == 0) {
                visited[ny][nx][dir] = true;
                q.push({ {ny, nx}, {dir, cnt + 1} });
            }
            else
                break;
        }

        for (int d = 1; d <= 4; ++d) {
            if (dir != d && !visited[y][x][d]) {
                visited[y][x][d] = true;
                if ((dir == 1 && d == 2) || (dir == 2 && d == 1) || (dir == 3 && d == 4) || (dir == 4 && d == 3))

                    q.push({ { y, x }, { d, cnt + 2 } });

                else

                    q.push({ { y, x }, { d, cnt + 1 } });
            }
        }

    }
    return answer;
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n;
    int y, x, d;
    pair<pair<int, int>, int> start;
    pair<pair<int, int>, int> end;

    cin >> m >> n;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> board[i][j];
        }
    }

    cin >> y >> x >> d;
    start.first.first = y;
    start.first.second = x;
    start.second = d;
    
    cin >> y >> x >> d;
    end.first.first = y;
    end.first.second = x;
    end.second = d;

    int ret= solution(m, n, start, end);

    cout << ret;
    return 0;
}