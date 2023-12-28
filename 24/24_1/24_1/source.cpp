#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long fuct(int n) {
	if (n == 0) {
		return 1;
	}

	long res = fuct(n - 1) * n;
	return res;
}

void main() {
	int n = 5;
	long f = fuct(n);

	printf("%d! = %ld", n, f);
}