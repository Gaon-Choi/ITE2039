// 2019009261_최가온_12838

#include <stdio.h>
using namespace std;

int n, i, j;
int e1, e2, x1, x2;
int a1[102], a2[102];
int t1[101], t2[101];
int s[2][102], l[2][102];
int fast[102];
int S, L;

void line_scheduling() {
	// entrance
	s[0][1] = e1 + a1[1];
	s[1][1] = e2 + a2[1];

	for (int j = 2; j <= n; ++j) {
		if (s[0][j - 1] <= s[1][j - 1] + t2[j - 1]) {
			s[0][j] = s[0][j - 1] + a1[j];
			l[0][j] = 1;
		}
		else {
			s[0][j] = s[1][j - 1] + t2[j - 1] + a1[j];
			l[0][j] = 2;
		}
		if (s[1][j - 1] <= s[0][j - 1] + t1[j - 1]) {
			s[1][j] = s[1][j - 1] + a2[j];
			l[1][j] = 2;
		}
		else {
			s[1][j] = s[0][j - 1] + t1[j - 1] + a2[j];
			l[1][j] = 1;
		}
	}

	// termination
	if (s[0][n] + x1 <= s[1][n] + x2) {
		S = s[0][n] + x1;
		L = 1;
	}
	else {
		S = s[1][n] + x2;
		L = 2;
	}
}

void print_station() {
	i = L;
	fast[n] = i;
	// printf("%d %d\n", i, n);
	for (j = n; j >= 2; --j) {
		i = l[i-1][j];
		// printf("%d %d\n", i, j - 1);
		fast[j - 1] = i;
	}
	for (i = 1; i <= n; ++i) printf("%d %d\n", fast[i], i);
}

int main() {
	scanf("%d", &n);
	scanf("%d %d", &e1, &e2);
	scanf("%d %d", &x1, &x2);
	for (i = 1; i <= n; i++)		scanf("%d", &a1[i]);
	for (i = 1; i <= n; i++)		scanf("%d", &a2[i]);
	for (i = 1; i <= n - 1; i++)	scanf("%d", &t1[i]);
	for (i = 1; i <= n - 1; i++)	scanf("%d", &t2[i]);
	line_scheduling();
	printf("%d\n", S);
	/*
	for (i = 0; i < 2; ++i) {
		for (j = 1; j <= n; ++j) printf("%d ", s[i][j]);
		printf("\n");
	}
	for (i = 0; i < 2; ++i) {
		for (j = 1; j <= n; ++j) printf("%d ", l[i][j] );
		printf("\n");
	}
	*/
	print_station();
	return 0;
}