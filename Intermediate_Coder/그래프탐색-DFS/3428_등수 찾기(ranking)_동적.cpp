#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
const int MAX_LEN= 100010;

struct NODE{
	int child;
	NODE* next;

	NODE() {
		child = 0, next = NULL;
	}
	NODE(int nc, NODE* np) {
		child = nc, next = np;
	}
	~NODE() {
		delete next;
	}
};

int ucnt = 0, dcnt = 0;
NODE* upAdj[MAX_LEN], * dwAdj[MAX_LEN];
int visited[MAX_LEN];

void DFS(int n, int cur, int& cnt, NODE** adj) {
	if (visited[cur] == 1)
		return;
	
	visited[cur] = 1;
	cnt++;
	for (NODE* p = adj[cur]; p; p=p->next) {
		DFS(n, p->child, cnt, adj);
	}

	return;
}

void solution(int n, int m, int x) {
	DFS(n, x, ucnt, upAdj);
	visited[x] = 0;
	DFS(n, x, dcnt, dwAdj);

	return;
}

int main(void) {
	int n, m, x, u, v;

	scanf("%d %d %d", &n, &m, &x);

	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &u, &v);
		dwAdj[u] = new NODE(v, dwAdj[u]);
		upAdj[v] = new NODE(u, upAdj[v]);
	}

	solution(n, m, x);

	printf("%d %d", ucnt, n - dcnt + 1);

	for (int i = 1; i <= n; ++i) {
		delete upAdj[i];
		delete dwAdj[i];
	}

	return 0;
}