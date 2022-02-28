#include <iostream>
#include <string>

using namespace std;

//��͹���
int recursive_func(string bin, int idx) {
	if (idx == 0)
		return 0;
	return recursive_func(bin, idx - 1) * 2 + (bin[idx - 1] - '0');
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string input;
	cin >> input;

	int tot = 0;
	int size = input.size();

	//�ݺ��� ����
	for (int i = size - 1, j = 1; i >= 0; i--, j *= 2) 
		tot += ((input[i] - '0') * j);
	//cout << tot;
	cout << recursive_func(input, size); //���
	return 0;
}