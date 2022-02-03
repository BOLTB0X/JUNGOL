#include <cstdio>
#include <vector>
using namespace std;

int main(void) {
	vector<char> arr;
	arr.resize(26, 0);

	char alp = 'A';
	for (int i = 0; i < 26; ++i)
		arr[i] = alp++;

	for (char& a : arr)
		printf("%c ", a);
	return 0;
}