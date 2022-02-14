#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
	char str1[101] = {0,};
	char str2[101] = {0,};

	scanf("%s",&str1);
	scanf(" %s" ,&str2);
	
	if (strlen(str1) < strlen(str2))
		cout << strlen(str2);
	else
		cout << strlen(str1);
	return 0;
}
