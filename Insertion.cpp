// 2019009261_ÃÖ°¡¿Â_12838

#include <bits/stdc++.h>
using namespace std;

int n, k, cnt = 0;
int v[100001];

void insert(int data) {
	v[cnt++] = data;
	int t = cnt;
	while (t != 1) {
		if (v[t] > v[t / 2]) {
			swap(&v[t], &v[t / 2]);
			t /= 2;
		}
		else break;
	}
}

int main() {
	scanf("%d %d", &n, &k);
	int data_;
	for (int i = 0; i < n; i++) {
		scanf("%d", &data_);
		insert(data_);
	}
	for (int i = 0; i < n; i++)
		printf("%d ", v[i]);
	return 0;
}