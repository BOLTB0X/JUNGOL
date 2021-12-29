#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void* a, const void* b) {
	int n1 = *(int*)a;
	int n2 = *(int*)b;

	if (n1 < n2)
		return -1;
	if (n1 > n2)
		return 1;
	return 0;
}

void solution(void) {
	char colors[5];
	int nums[5];

	for (int i = 0; i < 5; ++i) 
		scanf(" %c %d", &colors[i], &nums[i]);

	qsort(nums, 5, sizeof(int), compare);
	
	bool check[9];

	//1번 조건
	check[0] = true;
	
	for (int i = 0; i < 4; ++i) {
		if (colors[i] != colors[i + 1])
			check[0] = false;
	}

	int tmp = nums[0];

	if (check[0]) {
		for (int i = 1; i < 5; ++i) {
			if (++tmp != nums[i])
				check[0] = false;
		}
	}
	if (check[0]) {
		printf("%d\n", 900 + nums[4]);
		return;
	}

	//2번 조건
	tmp = 0;
	check[1] = false;
	
	if (nums[1] == nums[4] || nums[0] == nums[3])
		check[1] = true;

	if (check[1]) {
		printf("%d\n", 800 + nums[2]);
		return;
	}

	//3번 조건
	check[2] = false;
	int cnt1 = 0, cnt2 = 0;
	int max_val = nums[4];
	int min_val = nums[0];

	for (int i = 0; i < 5; ++i) {
		if (nums[i] == max_val)
			cnt1++;
		if (nums[i] == min_val)
			cnt2++;
	}

	if (cnt1 == 3 && cnt2 == 2) {
		check[2] = true;
		tmp = max_val * 10 + min_val;
	}
	if (cnt1 == 2 && cnt2 == 3) {
		check[2] = true;
		tmp = min_val * 10 + max_val;
	}

	if (check[2]) {
		printf("%d\n", 700 + tmp);
		return;
	}

	//4번조건
	check[3] = true;

	for (int i = 0; i < 5; ++i) {
		if (colors[0] != colors[i])
			check[3] = false;
	}

	if (check[3]) {
		printf("%d\n", 600 + nums[4]);
		return;
	}
	
	//5번조건
	check[4] = true;
	tmp = nums[0];
	for (int i = 1; i < 5; ++i) {
		if (++tmp != nums[i])
			check[4] = false;
	}

	if (check[4]) {
		printf("%d\n", 500 + nums[4]);
		return;
	}
	
	//6번조건
	check[5] = true;
	tmp = nums[2];
	int cnt = 0;
	for (int i = 0; i < 5; ++i) {
		if (tmp == nums[i])
			cnt++;
	}

	if (cnt != 3)
		check[5] = false;

	if (check[5]) {
		printf("%d\n", 400 + nums[2]);
		return;
	}

	//7번 조건
	check[6] = false;
	tmp = 0;
	//끝만 다른 경우
	if ((nums[0] == nums[1]) && (nums[2] == nums[3]))
		check[6] = true;
	if ((nums[1] == nums[2]) && (nums[3] == nums[4]))
		check[6] = true;
	if ((nums[0] == nums[1]) && (nums[3] == nums[4]))
		check[6] = true;

	if (check[6]) {
		printf("%d\n", 300 +nums[3] * 10 + nums[1]);
		return;
	}
	
	//8번조건
	check[7] = false;
	int eq;
	for (int i = 0; i < 4; ++i) {
		if (nums[i] == nums[i + 1]) {
			check[7] = true;
			eq = nums[i];
		}
	}

	if (check[7]) {
		printf("%d\n", 200 + eq);
		return;
	}

	//9번
	printf("%d\n", 100 + nums[4]);
	return;
}

int main(void) {
	solution();
	return 0;
}