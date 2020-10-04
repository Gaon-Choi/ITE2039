// 2019009261_최가온_12838

#include <stdio.h>
using namespace std;

int n, cnt = 0, cnt_ = 0, data, index;
int v[100005];
int w[100005];

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
		if (2 * idx > cnt || (v[idx] >= v[2 * idx] && v[idx] >= v[2 * idx + 1]))
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

void re_heapify(int index) {
	// current node > parent node --> GO UP
	if (index!=1 && v[index] > v[index / 2]) {
		while (1) {
			if (index == 1)break;
			if (v[index] > v[index / 2]) {
				swap(&v[index], &v[index / 2]);
				index /= 2;
			}
			else break;
		}
	}
	// current node < child node --> GO DOWN
	else {
		while (1) {
			if (2* index > cnt)break;
			if (v[index] >= v[2 * index] && v[index] >= v[2 * index + 1])break;
			if (v[2 * index + 1] == v[2 * index]) {
				swap(&v[index], &v[2 * index + 1]);
				index = 2 * index + 1;
			}
			else if (v[2 * index + 1] < v[2 * index]) {
				swap(&v[index], &v[2 * index]);
				index = 2 * index;
			}
			else {
				swap(&v[index], &v[2 * index + 1]);
				index = 2 * index + 1;
			}
		}
	}
}

int main() {
	int mode;
	while (true) {
		scanf("%d", &mode);
		// quit
		if (mode == 0) break;
		// insertion
		if (mode == 1) {
			scanf("%d", &data);
			insert(data);
		}
		// extract_max
		if (mode == 2) {
			w[++cnt_] = pop();
		}
		// substitute
		if (mode == 3) {
			scanf("%d %d", &index, &data);
			v[index] = data;
			re_heapify(index);
		}
	}
	for (int i = 1; i <= cnt_; i++)
		printf("%d ", w[i]);
	printf("\n");
	for (int i = 1; i <= cnt; i++)
		printf("%d ", v[i]);
	return 0;
}