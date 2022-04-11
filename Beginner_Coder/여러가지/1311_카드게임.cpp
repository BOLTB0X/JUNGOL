#include <iostream>

using namespace std;

void quick_Sort(int* arr, int start, int end) {
	if (start >= end)
		return;

	int pivot = start, i = start + 1, j = end;

	while (i <= j) {
		while (i <= end && arr[i] <= arr[pivot]) i++;
		while (j > start && arr[j] >= arr[pivot]) j--;

		if (i > j)
			swap(arr[pivot], arr[j]);
		else
			swap(arr[i], arr[j]);
	}

	quick_Sort(arr, start, j - 1);
	quick_Sort(arr, j + 1, end);

	return;
}

int solution(char* colors, int* numbers) {
	int answer = 0;
	bool flag[9];
	
	quick_Sort(numbers, 0, 4); // 오름차순 정렬

	// 1번 조건
	flag[0] = true;
	// 같은 색 5장인지 체크
	for (int i = 1; i < 4; ++i) {
		if (colors[i - 1] != colors[i])
			flag[0] = 0;
	}

	// 순차적 증가인지 체크
	int num = numbers[0];
	for (int i = 1; i < 4; ++i) {
		if (++num != numbers[i])
			flag[0] = 0;
	}

	if (flag[0]) {
		answer = 900 + numbers[4];
		return answer;
	}
	
	// 2번 조건
	flag[1] = false;

	// 오름차순 되어있으므로
	if (numbers[1] == numbers[4] || numbers[0] == numbers[3])
		flag[1] = true;

	if (flag[1]) {
		answer = 800 + numbers[2];
		return answer;
	}

	// 3번
	flag[2] = false;
	int max_num = numbers[4];
	int min_num = numbers[0];
	int cnt1 = 0, cnt2 = 0;

	for (int i = 0; i < 5; ++i) {
		if (max_num == numbers[i])
			cnt1++;
		else if (min_num == numbers[i])
			cnt2++;
	}

	if ((cnt1 == 3 && cnt2 == 2) || (cnt1 == 2 && cnt2 == 3))
		flag[2] = true;

	if (flag[2]) {
		if (cnt1 == 3) {
			answer = max_num * 10 + min_num + 700;
			return answer;
		}
		else {
			answer = min_num * 10 + max_num + 700;
			return answer;
		}
	}

	// 4번
	flag[3] = true;
	char color = colors[0];
	for (int i = 1; i < 5; ++i) {
		if (color != colors[i])
			flag[3] = false;
	}

	if (flag[3]) {
		answer = 600 + numbers[4];
		return answer;
	}

	// 5번
	flag[4] = true;
	num = numbers[0];
	for (int i = 1; i < 5; ++i) {
		if (++num != numbers[i])
			flag[4] = false;
	}

	if (flag[4]) {
		answer = 500 + numbers[4];
		return answer;
	}

	// 6번
	flag[5] = false;
	if ((numbers[0] == numbers[2]) || (numbers[2] == numbers[4]) || (numbers[1] == numbers[3]))
		flag[5] = true;

	if (flag[5]) {
		answer = 400 + numbers[1];
		return answer;
	}

	// 7번
	flag[6] = false;
	if ((numbers[0] == numbers[1]) && (numbers[2] == numbers[3]))
		flag[6] = true;
	if ((numbers[1] == numbers[2]) && (numbers[3] == numbers[4]))
		flag[6] = true;
	if ((numbers[0] == numbers[1]) && (numbers[3] == numbers[4]))
		flag[6] = true;

	if (flag[6]) {
		answer = 300 + numbers[3] * 10 + numbers[1];
		return answer;
	}

	// 8번
	flag[7] = false;
	num;
	for (int i = 0; i < 4; ++i) {
		if (numbers[i] == numbers[i + 1]) {
			flag[7] = true;
			num = numbers[i + 1];
			break;
		}
	}

	if (flag[7]) {
		answer = 200 + num;
		return answer;
	}

	answer = 100 + numbers[4];
	return answer;
}

int main(void) {
	char colors[5];
	int numbers[5];
	for (int i = 0; i < 5; ++i) 
		cin >> colors[i] >> numbers[i];
	
	int ret = solution(colors, numbers);
	cout << ret;
	return 0;
}