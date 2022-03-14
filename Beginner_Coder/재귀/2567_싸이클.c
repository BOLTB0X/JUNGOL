#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cnt[10001] = { 0, };

void recursive_func(int n, int p, int number) {
	//탈출조건
	if (cnt[number] == 2) 
		return;
	
	cnt[number]++;
	recursive_func(n, p, (number * n) % p);
	return;
}

int solution(int n, int p) {
	int answer = 0;

	//첫 시작 n은 제외
	recursive_func(n, p, (n * n) % p);
	for (int i = 0; i < p; ++i) 
		if (cnt[i] == 2) answer++; //싸이클이 생긴 갯수 체크
	
	return answer;
}

int main(void) {
	int n, p;

	scanf("%d %d", &n, &p);

	int ret = solution(n, p);

	printf("%d", ret);
	return 0;
}
