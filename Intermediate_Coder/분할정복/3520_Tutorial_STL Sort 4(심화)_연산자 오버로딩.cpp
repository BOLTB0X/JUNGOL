#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Data {
	int id;
	char name[20] = { '\0', };
	int score;

	bool operator < (const Data& d) const {
		if (score == d.score) {
			if (strcmp(name, d.name) == 0)
				return id < d.id;
			return strcmp(name, d.name) < 0; //b가 길다면
		}
		return score > d.score;
	}
};


Data students[5000000];

int main(void) {
	int n, q, number;
	scanf("%d %d", &n, &q);

	for (int i = 0; i < n; ++i) {
		scanf("%s %d", students[i].name, &students[i].score);
		students[i].id = (i + 1);
	}

	//비교함수를 이용한 정렬
	sort(students, students + n);
	for (int i = 0; i < q; ++i) {
		scanf("%d", &number);

		//출력
		printf("%d ", students[number - 1].id);
	}
	return 0;
}