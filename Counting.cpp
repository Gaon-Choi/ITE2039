// 2019009261_최가온_12838

#include <stdio.h>

using namespace std;

int n, m, k;
int v[100005][2];
int cnt[100005];

int main() {
	int i, num;
	scanf("%d %d %d", &n, &m, &k);
	for (i = 0; i < k; i++) {
		scanf("%d %d", &v[i][0], &v[i][1]);
	}
	// n: the number of input keys (1 <= n <= 100000)
	for (i = 0; i < n; i++) {
		scanf("%d", &num);
		cnt[num]++;
	}
	// m: the range of input keys (1 <= m <= 100000)
	// accumulated counts
	for (i = 1; i <= m; i++)
		cnt[i] = cnt[i] + cnt[i - 1];
	// k: the number of query ranges (1 <= k <= 100000)
	for (i = 0; i < k; i++) {
		int a = v[i][0];
		int b = v[i][1];
		printf("%d\n", cnt[b] - cnt[a - 1]);
	}
	return 0;
}