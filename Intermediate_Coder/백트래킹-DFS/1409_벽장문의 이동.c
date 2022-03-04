#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MS 21

int result = 0x7fffffff; //최솟값을 위한
int cmd[MS];

//최솟값반환
int MIN(int a, int b) {
	return a < b ? a : b;
}

//절댓값 반환
int Abs(int a) {
	return a < 0 ? -a : a;
}

//DFS를 이용한 백트래킹
void DFS(int n, int door_size, int open_door1, int open_door2, int tot, int level) {
	//탈출 조건
	if (door_size == level) {
		result = MIN(result, tot);
		return;
	}

	//열린 문을 수정하여 다시 호출
	DFS(n, door_size, cmd[level], open_door2, tot + Abs(open_door1 - cmd[level]), level + 1);
	DFS(n, door_size, open_door1, cmd[level] ,tot + Abs(open_door2 - cmd[level]), level + 1);
	return;
}

int solution(int n, int m, int open_door1, int open_door2) {
	int answer = 0;

	DFS(n, m, open_door1, open_door2, 0, 0);
	answer = result;
	return answer;
}

int main(void) {
	int n, m, open_door1, open_door2;
	
	scanf("%d", &n);
	scanf("%d %d", &open_door1, &open_door2);
	scanf("%d", &m);

	for (int i = 0; i < m; ++i) 
		scanf("%d", &cmd[i]);
	
	int ret = solution(n, m, open_door1, open_door2);
	printf("%d", ret);
	return 0;
}
