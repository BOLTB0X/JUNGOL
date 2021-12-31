#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int pane[101][101];

void fill_pane(int n) {
    int x = 1; // �� - ó������ 1
    int y = n / 2 + 1; // �� - �ʱⰪ �߾�

    int end = n * n; // �迭�� ä�� ������ ��

    for (int i = 1; i <= end; i++) {  // �迭�� ä�� �� 1���� end����
        pane[x][y] = i; // i�� �迭�� ���� ��ġ�� �ִ´�.
        if (i % n == 0) 
            x++;  // ���� ������ ���� n�� ����̸� �Ʒ��� �̵�
        else {
            x--, y--; // ���� ���� �̵�
            if (x < 1) 
                x = n; // x�� 0�̸� n����
            if (y < 1) 
                y = n; // y�� 0�̸� n����
        }
    }

    return;
}

void print_pane(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) 
            printf("%d ", pane[i][j]);
        printf("\n");
    }

    return;
}

void solution(void) {
	int n;
	scanf("%d", &n);

	fill_pane(n);
    print_pane(n);

    return;
}

int main(void) {
	solution();

	return 0;
}