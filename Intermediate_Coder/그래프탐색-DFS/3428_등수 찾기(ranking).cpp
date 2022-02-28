#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m, x;
vector<int> adj[100001]; //나보다 큰 넘들
vector<int> r_adj[100001]; //나보다 작은 넘들
bool visited[100001];

int cnt = 0;
int r_cnt = 0;

void DFS(int cur) {
    if (visited[cur])
        return;
    visited[cur] = true;
    cnt++;

    for (int& next : adj[cur])
        DFS(next);
    return;
}

void R_DFS(int cur) {
    if (visited[cur])
        return;
    visited[cur] = true;
    r_cnt++;

    for (int& next : r_adj[cur])
        R_DFS(next);
    return;
}

void solution(void) {
    memset(visited, 0, sizeof(bool) * n + 1);
    DFS(x);
    memset(visited, 0, sizeof(bool) * n + 1);
    R_DFS(x);

    cout << r_cnt << ' ' << n - cnt + 1 << '\n';
    return;
}

int main(void) {
    //초기화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> x;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        r_adj[b].push_back(a);
    }

    solution();
    return 0;
}
