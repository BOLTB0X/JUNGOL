#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MS 21

int result = 0x7fffffff;
int cmd[MS] = { 0, };

//�ּڰ���ȯ
int MIN(int a, int b) {
	return a < b ? a : b;
}

//���� ��ȯ
int Abs(int a) {
	return a < 0 ? -a : a;
}

//DFS�� �̿��� Ż�� ����
void DFS(int n, int o1, int o2, int size, int level, int tot) {
	//Ż�� ����
	if (size < level) {
		result = MIN(result, tot);
		return;
	}
	
	//���� ���� �����Ͽ� �ٽ� ȣ��
	DFS(n, cmd[level], o2, size, level + 1, tot + Abs(o1 - cmd[level]));
	DFS(n, o1, cmd[level], size, level + 1, tot + Abs(o2 - cmd[level]));
	return; 
}

int solution(int n, int size, int op1, int op2) {
	int answer = 0;

	DFS(n, op1, op2, size, 1, 0);

	answer = result;
	return answer;
}

int main(void) {
	int n, door_size;
	int open_door1, open_door2;

	scanf("%d", &n);
	scanf("%d %d", &open_door1, &open_door2);
	scanf("%d", &door_size);
	
	for (int i = 1; i <= door_size; ++i) 
		scanf("%d", &cmd[i]);

	int ret = solution(n, door_size,open_door1, open_door2);
	printf("%d", ret);

	return 0;
}