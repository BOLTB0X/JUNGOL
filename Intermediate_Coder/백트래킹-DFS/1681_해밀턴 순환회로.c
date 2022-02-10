#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int n, flag = 0, result = 0x7fffffff;
int board[14][14];
int visited[14];

void check(int cur, int tot) {
	//������ ���ư��� ����� 0�� �ƴϰ� ���� ��뺸�� �� �۴ٸ�
	if (board[cur][1] != 0 && tot + board[cur][1] < result) {
		flag = 1;
		result = tot + board[cur][1];
	}
	return;
}

void DFS(int cur, int level, int tot) {
	if (level == n) {
		check(cur, tot);
		return;
	}

	for (int i = 2; i <= n; ++i) {
		//��湮
		if (visited[i] == 1)
			continue;
		//�̵��Ұ�, �� i -> i�� 0�� Ž�� �� �ʿ䰡 ����
		if (board[cur][i] == 0)
			continue;
		//ū ���
		if (tot + board[cur][i] > result)
			continue;
		visited[i] = 1;
		DFS(i, level + 1, tot + board[cur][i]);
		visited[i] = 0;
	}

	return;
}

void solution(void) {
	//�湮����Ʈ �ʱ�ȭ
	memset(visited, 0, sizeof(int) * 14);
	//��Ʈ��ŷ ����
	DFS(1, 1, 0);

	return;
}

int main(void) {
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			scanf("%d", &board[i][j]);
	}

	solution();

	if (flag == 0)
		result = 0;

	printf("%d", result);
	return 0;
}