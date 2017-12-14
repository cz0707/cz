include <stdio.h>

#define Len 10

void bubblesort(int a[], int n) {
	int i, j;
	int temp;
	for (i = 0;i < n - 1;i++) {
		for (j = 0;j < n - i - 1;j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

int main() {
	int i;
	int a[Len] = { 9,5,6,4,7,3,2,8,1,0 };
	bubblesort(a, Len);
	for (i = 0;i < Len;i++)
		printf("%d ", a[i]);
	putchar('\n');
	return 0;
}