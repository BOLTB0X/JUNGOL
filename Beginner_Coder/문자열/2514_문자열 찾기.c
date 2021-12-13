#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int compare_KOI(char str[], int idx) {
	if (str[idx] == 'K' && str[idx + 1] == 'O' && str[idx + 2] == 'I')
		return 1;
	return 0;
}

int compare_IOI(char str[], int idx) {
	if (str[idx] == 'I' && str[idx + 1] == 'O' && str[idx + 2] == 'I')
		return 1;
	return 0;
}

void solution(void) {
	char str[10001];
	int k_cnt = 0, i_cnt = 0;

	scanf("%s", str);

	for (int i = 0; i < strlen(str) - 2; ++i) {
		if (str[i] == 'K')
			k_cnt += compare_KOI(str, i);
		else if (str[i] == 'I')
			i_cnt += compare_IOI(str, i);
	}
	
	
	printf("%d\n", k_cnt);
	printf("%d\n", i_cnt);
	return;

}

int main(void) {
	solution();
	return 0;
}