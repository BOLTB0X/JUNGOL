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

bool is_Empty(void) {
    if (head == tail)
        return false;
    return true;
}

void input(void) {
    cin >> n >> k;

    for (int i = 0; i <= n; ++i)
        visited[i] = 0;

    for (int i = 1; i <= n; ++i)
        cin >> codes[i];
    cin >> start >> e;

    return;
}

//�عְ�� üũ
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
    NODE tmp = {start};
    tmp.path.push_back(start);

    enqueue(tmp);
    visited[start] = 1;

    //BFSŽ�� ����
    while (is_Empty()) {
        NODE cur = dequeue();

        if (codes[cur.idx] == codes[e]) 
            return cur.path;
        
        for (int i = 1; i <= n; ++i) {
            //�̹湮, �عְ�� ����
            if (visited[i] == 0 && is_process(i, cur)) {
                NODE next = {i, cur.path};
                next.path.push_back(i);
                //���� ��ε�
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

    input();
    vector<int> ret = solution();

    if (ret.empty())
        cout << "-1";
    else {
        for (int i = 0; i < ret.size(); ++i)
            cout << ret[i] << ' ';
        cout << "\n";
    }

    return 0;
}