#include <stdio.h>
using namespace std;

int main() {
	int arr[30001];
	int n, key;
	scanf("%d", &n);

	int i = 0, j;
	
	while (i < n) {
		scanf("%d", &arr[i]);
		key = arr[i];
		j = i - 1;

		while (arr[j] < key && j >= 0) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
		i++;
	}

	i = 0;
	while (i < n)
		printf("%d\n", arr[i++]);
	return 0;
}