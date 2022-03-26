#include <iostream>
#include <vector>

using namespace std;

int result;
vector<int> doors;

// 절댓값 반환
int Abs(int a) {
	return a < 0 ? -a : a;
}

// 최솟값 반환
int Min(int a, int b) {
	return a < b ? a : b;
}

void DFS(int size, int op1, int op2, int tot, int level) {
	// 다 열었다면
	if (level == size) {
		result = Min(result, tot);
		return;
	}

	// 각 여는 문을 바꾸면서 백트래킹 진행
	DFS(size, doors[level], op2, tot + Abs(doors[level] - op1), level + 1);
	DFS(size, op1, doors[level], tot + Abs(doors[level] - op2), level + 1);
	return;
}

int solution(int n, int open_door1, int open_door2, int door_size) {
	int answer = 0;
	result = 0x7fffffff; // 최솟를 위한

	// 백트래킹으로 완전탐색 시작
	DFS(door_size, open_door1, open_door2, 0, 0);
	answer = result; // 정답
	return answer;
}

int main(void) {
	int n, door_size;
	int open_door1, open_door2;

	cin >> n;
	cin >> open_door1 >> open_door2;
	cin >> door_size;
	doors.resize(door_size, 0);

	for (int i = 0; i < door_size; ++i)
		cin >> doors[i];
	
	int ret = solution(n, open_door1, open_door2, door_size);
	cout << ret;

	return 0;
}
