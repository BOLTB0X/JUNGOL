#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int result = 0;
int alp[26] = { 0, };

//���̿켱Ž��
void DFS(char* cur, int str_idx, int level, int size) {
	//Ż������
	if (level == size) {
		result++;
		return;
	}

	for (int i = 0; i < 26; ++i) {
		//�ش� ���ĺ��� ������� ���� ���
		if (alp[i] == 0)
			continue;

		//���� ���ڿ��� ���̰� 0�� �ƴϰ� ���� ���ڿ��� ���ڶ��� i�� ���ٸ�
		if (str_idx != 0 && cur[str_idx - 1] == (char)i + 'a')
			continue;

		alp[i]--;
		cur[str_idx++] = (char)i + 'a';
		DFS(cur, str_idx, level + 1, size);
		cur[--str_idx] = 0;
		alp[i]++;
	}
	return;
}

int solution(char* str) {
	int answer = 0;
	int size = strlen(str);
	char voca[11] = { 0, };

	//���ĺ� ī��Ʈ
	for (int i = 0; i < size; ++i)
		alp[str[i] - 'a'] ++;
	
	DFS(voca, 0, 0, size);
	
	answer = result;
	return answer;
}

int main(void) {
	char str[11] = { 0, };
	
	scanf("%s", &str);

	int ret = solution(str);
	printf("%d", ret);

	return 0;
}