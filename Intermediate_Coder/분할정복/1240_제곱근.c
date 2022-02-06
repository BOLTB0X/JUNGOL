#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//이분탐색
unsigned long long binary_Search(unsigned long long start, unsigned long long end, unsigned long long target) {
	unsigned long long ret = target, mid;

	while (start <= end) {
		mid = (start + end) / 2;

		if (mid <= target / mid) {
			ret = mid;
			start = mid + 1;
		}
		else
			end = mid - 1;
	}

	return ret;
}

int main(void) {
	unsigned long long n;
	scanf("%lld", &n);
	
	unsigned long long ret = binary_Search(1, n, n);
	
	printf("%lld\n", ret);
	return 0;
}
