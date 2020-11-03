// 2019009261_최가온_12838

#include <stdio.h>
#include <limits.h>
using namespace std;

int p[103];
int m[105][105];
int s[105][105];
int n, i, j, l, k, q;
void matrix_chain_order(int* p) {
	for (i = 1; i <= n; ++i) m[i][i] = 0;
	for (l = 2; l <= n; ++l) {
		for (i = 1; i <= n - l + 1; ++i) {
			j = i + l - 1;
			m[i][j] = INT_MAX;
			for (k = i; k <= j - 1; ++k) {
				q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
}

void print_parenthesis(int i, int j) {
	if (i == j)
		printf("%d ", i);
	else {
		printf("( ");
		print_parenthesis(i, s[i][j]);
		print_parenthesis(s[i][j] + 1, j);
		printf(") ");
	}
}

int main() {
	scanf("%d", &n);
	for (i = 0; i < n + 1; ++i)
		scanf("%d", &p[i]);
	matrix_chain_order(p);
	printf("%d\n", m[1][n]);
	print_parenthesis(1, n);
	return 0;
}