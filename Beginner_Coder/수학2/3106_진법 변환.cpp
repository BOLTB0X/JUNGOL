#include <iostream>
#include <string>
#define LL long long

using namespace std;

string get_trans_number(int t1, int t2, string n) {
	LL tot = 0, size = n.length();
	string tmp = "", ret = "";

	//t1���� -> 10����
	for (LL i = size - 1, j = 1; i >= 0; --i, j *= t1) {
		if (n[i] >= 'A' && n[i] <= 'Z')
			n[i] = '9' + (n[i] - 'A' + 1);
		tot += j * (n[i] - '0');
	}

	//10���� -> t2���� 
	while (tot > 0) {
		if (tot % t2 > 9)
			tmp += (tot % t2) - 10 + 'A';
		else
			tmp += (tot % t2) + '0';

		tot /= t2;
	}
	size = tmp.length() - 1;
	//��� ��ȯ�� ���� ������
	for (LL i = size; i >= 0; --i)
		ret += tmp[i];

	return ret;
}

int main(void) {
	int type1, type2;
	string number;

	while (1) {
		cin >> type1;
		if (type1 == 0)
			break;
		cin >> number >> type2;

		string ret = get_trans_number(type1, type2, number);

		cout << ret << '\n';
	}

	return 0;
}