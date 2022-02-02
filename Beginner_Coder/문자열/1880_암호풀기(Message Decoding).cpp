#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void solution(char key[], char encoding[]) {
	int size = strlen(encoding);
	if (encoding[size - 1] == '\n')
		encoding[--size] = 0;
	for (int i = 0; i < size; ++i) {
		if (encoding[i] >= 'A' && encoding[i] <= 'Z')
			cout << (char)(key[encoding[i] - 'A'] - 32);
		else if (encoding[i] >= 'a' && encoding[i] <= 'z')
			cout << key[encoding[i] - 'a'];
		else
			cout << ' ';
	}

	return;
}

int main(void) {
	char key[30];
	char encoding[90];
	
	scanf("%s ", key);
	fgets(encoding, sizeof(encoding), stdin);

	solution(key, encoding);
	return 0;
}