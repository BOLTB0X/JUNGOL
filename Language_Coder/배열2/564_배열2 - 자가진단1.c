#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int occ[26] = { 0, };
	char alp;

	for (int i = 0; i < 100; ++i) {
		scanf(" %c", &alp);

		if (alp < 'A' || alp > 'Z')
			break;
		occ[alp - 'A']++;
	}

	for (int i = 0; i < 26; ++i) {
		if (occ[i] == 0)
			continue;
		printf("%c : %d\n", i + 'A', occ[i]);
	}
	return;
}