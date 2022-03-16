#include <iostream>
#include <string>
#define LL long long

using namespace std;

string get_trans_number(int t1, int t2, string n) {
	LL tot = 0, size = n.length();
	string tmp = "", ret = "";

	//t1진수 -> 10진수
	for (LL i = size - 1, j = 1; i >= 0; --i, j *= t1) {
		if (n[i] >= 'A')
			n[i] = '9' + (n[i] - 'A') + 1;
		tot += j * (n[i] - '0');
	}

	//10진수 -> t2진수 
	while (tot > 0) {
		if (tot % t2 > 9)
			tmp.push_back((tot % t2) - 10 + 'A');
		else
			tmp.push_back((tot % t2) + '0');

		tot /= t2;
	}

	size = tmp.length();
	//결과 반환을 위한 뒤집기
	for (LL i = size - 1; i >= 0; --i)
		ret.push_back(tmp[i]);

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

		if (number == "0")
			cout << "0" << '\n';
		else {
			string ret = get_trans_number(type1, type2, number);
			cout << ret << '\n';
		}
	}

	return 0;
}
