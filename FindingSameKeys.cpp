// 2019009261_최가온_12838

#include <stdio.h>
using namespace std;

int n;	// the number of keys in set A
int m;  // the number of keys in set B

bool v[1000005];

int main() {
	scanf("%d %d", &n, &m);
	int i, num, dup=0;
	for (i = 0; i < n; i++) {
		scanf("%d", &num);
		v[num] = 1;
	}
	for (i = 0; i < m; i++) {
		scanf("%d", &num);
		dup += v[num];
	}

	printf("%d", dup);

	return 0;
}