#include <iostream>
#include <vector>

using namespace std;

int result;

//�ּڰ���ȯ
int MIN(int a, int b) {
	return a < b ? a : b;
}

//���� ��ȯ
int Abs(int a) {
	return a < 0 ? -a : a;
}

//���̿켱Ž������ ��Ʈ��ŷ ����
void DFS(int open_door1, int open_door2, int door_size, vector<int>& door, int tot, int level) {
	//Ż������
	if (door_size == level) {
		result = MIN(result, tot);
		return;
	}

	//�� ���� ���幮�� �ٲٸ鼭 ��Ʈ��ŷ ¡��
	DFS(door[level], open_door2, door_size, door, tot + Abs(open_door1 - door[level]), level + 1);
	DFS(open_door1, door[level], door_size, door, tot + Abs(open_door2 - door[level]), level + 1);
	return;
}

int solution(int n, int open_door1, int open_door2, int door_size, vector<int>& door) {
	int answer = 0;
	result = 0x7fffffff; //�ּڰ��� ���� �ʱ�ȭ

	//��Ʈ��ŷ ����
	DFS(open_door1, open_door2, door_size, door, 0, 0);
	answer = result;
	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, open_door1, open_door2, door_size;
	vector<int> door;

	cin >> n >> open_door1 >> open_door2 >> door_size;
	door.resize(door_size, 0); //������ ����

	for (int i = 0; i < door_size; ++i)
		cin >> door[i];

	int ret = solution(n, open_door1, open_door2, door_size, door);
	cout << ret;

	return 0;
}