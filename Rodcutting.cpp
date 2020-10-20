// 2019009261_최가온_12838

#include <stdio.h>
#include <limits.h>
using namespace std;

int p[101];
int r[101];
int s[101];

void extended_bottom_up_cut_rod(int* p, int n) {
	r[0] = 0;
	int i, j;
	for (j = 1; j <= n; j++) {
		int max = INT_MIN;
		for (i = 1; i <= j; i++) {
			if (max < p[i] + r[j - i]) {
				max = p[i] + r[j - i];
				s[j] = i;
			}
		}
		r[j] = max;
	}
}

void print_cut_rod_solution(int* p, int n) {
	printf("%d\n", r[n]);
	while (n > 0) {
		printf("%d ", s[n]);
		n -= s[n];
	}
}

int main() {
	int n, i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &p[i]);
	p[0] = 0;
	extended_bottom_up_cut_rod(p, n);
	print_cut_rod_solution(p, n);
	return 0;
}