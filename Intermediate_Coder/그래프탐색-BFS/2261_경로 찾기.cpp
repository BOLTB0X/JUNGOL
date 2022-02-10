#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int idx;
    vector<int> path;
} NODE;

NODE q[1001];
int head = 0, tail = 0;

int n, k;
int start, e;

string codes[1001];
int visited[1001];

void enqueue(NODE data) {
    q[tail++] = data;
    return;
}

NODE dequeue(void) {
    return q[head++];
}

//해밍경로 체크
bool is_process(int i, NODE data) {
    int cnt = 0;
    for (int j = 0; j < k; ++j) {
        if (codes[data.idx][j] != codes[i][j]) {
            cnt++;
        }
    }

    return cnt >= 2 ? false : true;
}

vector<int> solution() {
    NODE tmp = { start };
    tmp.path.push_back(start);

    enqueue(tmp);
    visited[start] = 1;

    //BFS탐색 시작
    while (head != tail) {
        NODE cur = dequeue();

        if (codes[cur.idx] == codes[e])
            return cur.path;

        for (int i = 1; i <= n; ++i) {
            //미방문, 해밍경로 조건
            if (visited[i] == 0 && is_process(i, cur)) {
                NODE next = { i, cur.path };
                next.path.push_back(i);
                //다음 경로들
                enqueue(next);
                visited[i] = 1;
            }
        }
    }

    tmp.path.clear();
    return tmp.path;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for (int i = 0; i <= n; ++i)
        visited[i] = 0;

    for (int i = 1; i <= n; ++i)
        cin >> codes[i];
    cin >> start >> e;

    vector<int> ret = solution();

    if (ret.empty())
        cout << "-1";
    else {
        for (int i = 0; i < ret.size(); ++i)
            cout << ret[i] << ' ';
    }

    return 0;
}
