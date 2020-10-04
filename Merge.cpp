// 2019009261_최가온_12838

#include <stdio.h>
using namespace std;

int arr[100001], v[100001];

void merge(int arr[], int p, int q, int r) {
	int i = p, j = q + 1, k = p, l;

	// compare [left, mid] block and [mid+1, right] block
	while (i <= q && j <= r) {
		// if left index value > right index value --> copy the left index value
		if (arr[i] > arr[j])
			v[k] = arr[i++];
		else
		// if not -> copy the right index value
			v[k] = arr[j++];
		k++;
	}
	// when left block finished, right block has remains.
	if (i > q) {
		for (l = j; l <= r; l++)
			v[k++] = arr[l];
	}
	else {
		for (l = i; l <= q; l++)
			v[k++] = arr[l];
	}
	for (l = p; l <= r; l++)
		arr[l] = v[l];
}

void mergesort(int arr[], int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		mergesort(arr, p, q);
		mergesort(arr, q + 1, r);
		merge(arr, p, q, r);
	}
}


int main() {
	int n;
	scanf("%d", &n);

	int i = 0;
	while (i < n)
		scanf("%d", &arr[i++]);

	mergesort(arr, 0, n - 1);
	i = 0;
	while (i < n)
		printf("%d\n", arr[i++]);

	return 0;
}