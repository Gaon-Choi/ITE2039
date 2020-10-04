// 2019009261_최가온_12838

#include <stdio.h>
using namespace std;

int n, k, cnt = 0;
int v[100005];

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void insert(int data) {
	v[++cnt] = data;
	int t = cnt;
	while (t != 1) {
		if (v[t] > v[t / 2]) {
			swap(&v[t], &v[t / 2]);
			t /= 2;
		}
		else break;
	}
}

int pop() {
	int max = v[1];
	v[1] = v[cnt];
	v[cnt--] = 0;
	int idx = 1;
	// v[idx / 2] --> parent
	// v[idx]     --> left child
	// v[idx + 1] --> right child
	while (1) {
		// don't need to swap nodes anymore
		if(2 * idx > cnt || (v[idx] >= v[2 * idx] && v[idx] >= v[2 * idx + 1]))
			break;
		// need to swap nodes
		if (v[2 * idx] > v[2 * idx + 1]) {
			swap(&v[idx], &v[2 * idx]);
			idx = 2 * idx;
		}
		else {
			swap(&v[idx], &v[2 * idx + 1]);
			idx = 2 * idx + 1;
		}
	}
	
	return max;
}

int main() {
	scanf("%d %d", &n, &k);
	int data_;
	for (int i = 0; i < n; i++) {
		scanf("%d", &data_);
		insert(data_);
	}
	for (int i = 0; i < k; i++) {
		printf("%d ", pop());
	}
	printf("\n");
	for (int i = 1; i <= cnt; i++)
		printf("%d ", v[i]);
	return 0;
}