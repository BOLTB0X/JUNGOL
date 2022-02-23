#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef struct {
    int idx;
    vector<int> path;
} Node;

Node que[1001];
int fr = 0, re = 0;

void enqueue(Node data) {
    que[re++] = data;
    return;
}

Node dequeue(void) {
    return que[fr++];
}

//해밍 경로인지 체크
int is_haming_dist(int k, string next, string cur) {
    int cnt = 0;
    for (int i = 0; i < k; ++i) {
        if (next[i] != cur[i]) {
            cnt++;
        }
    }
    return cnt == 1 ? 1 : 0;
}

void solution(int n, int k, int start, int end, vector<string>& haming) {
    vector<int> answer;
    vector<int> tmp, visited(n + 1, 0);

    tmp.push_back(start);

    enqueue({ start, tmp });
    visited[start] = 1;

    while (fr != re) {
        Node cur = dequeue();

        //탈출조건
        if (cur.idx == end) {
            for (int& c : cur.path)
                answer.push_back(c);
            break;
        }

        //순회
        for (int i = 1; i <= n; ++i) {
            //재방문 
            if (visited[i] == 1)
                continue;

            //해밍 거리가 1인지 확인
            if (is_haming_dist(k, haming[i], haming[cur.idx]) == 1) {
                //경로 및 현재 인덱스 업데이트
                Node next = { i, cur.path };
                next.path.push_back(i);
                visited[next.idx] = 1; //방문 처리
                enqueue(next);
            }
        }
    }

    if (answer.size() == 0)
        cout << -1;
    else {
        for (int& a : answer)
            cout << a << ' ';
    }

    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k, start, end;
    vector<string> haming;

    cin >> n >> k;
    haming.resize(n + 1);

    for (int i = 1; i <= n; ++i) 
        cin >> haming[i];
    
    cin >> start >> end;

    solution(n, k, start, end, haming);
    return 0;
}
