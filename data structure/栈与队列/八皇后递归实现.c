#include <stdio.h>

int count = 0;

int Notdanger(int row, int j, int(*chess)[8]) {
	int i, k;

	//判断列
	for (i = 0; i<8; i++) {
		if (chess[i][j] == 1)
			return 0;
	}
	//判断左上
	for (i = row, k = j; i >= 0 && k >= 0; i--, k--) {
		if (chess[i][k] == 1)
			return 0;
	}
	//判断右下
	for (i = row, k = j; i<8 && k<8; i++, k++) {
		if (chess[i][k] == 1)
			return 0;
	}
	//判断右上
	for (i = row, k = j; i >= 0 && k<8; i--, k++) {
		if (chess[i][k] == 1)
			return 0;
	}
	//判断左下
	for (i = row, k = j; i<8 && k >= 0; i++, k--) {
		if (chess[i][k] == 1)
			return 0;
	}

	return 1;
}


//参数row表示起始行，参数n表示列数，参数(*chess)[8]代表行是指针，列是数组
void EightQueen(int row, int n, int(*chess)[8]) {
	int chess2[8][8], i, j;
	for (i = 0; i<8; i++)
		for (j = 0; j<8; j++)
			chess2[i][j] = chess[i][j];
	if (row == 8) {
		printf("第%d种\n",count + 1);
		for (i = 0; i<8; i++) {
			for (j = 0; j<8; j++) {
				printf("%d ", chess2[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		count++;
	}
	else {
		for (j = 0; j<n; j++) {                                  //循环开始下一列
			if (Notdanger(row, j, chess)) {                      //判断是否能放
				for (i = 0; i<8; i++) {
					chess2[row][i] = 0;
				}
				chess2[row][j] = 1;
				EightQueen(row + 1, n, chess2);                 //递归开始下一行
			}
		}
	}
}

int main() {
	int chess[8][8] = { 0 };
	EightQueen(0, 8, chess);
	printf("总共有%d种解法!\n",count);

	return 0;

}