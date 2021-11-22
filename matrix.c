#define _CRT_SECURE_NO_WARNINGS	
#include <stdio.h>
#include <stdlib.h>
void print(char** arr, int h, int w) {
	int i,r;
	for (i = 0; i < h; i++) {
		for (r = 0; r < w; r++)
			putchar(arr[i][r]);
		putchar('\n');
	}
}
char** intit_mat(int h, int w) {
	char** res = (char**)malloc(sizeof(char*) * h);
	int i;
	for (i = 0; i < h; i++)
		res[i] = (char*)malloc(sizeof(char) * w);
	return res;
}
void main(){
	int height, width,i,r;
	do {
		printf("Please enter the squre odd height 5-21\n");
		scanf("%d", &height);
		printf("Please enter the squre odd width 5-21\n");
		scanf("%d", &width);
	} while (height % 2 == 0 || height > 21 || height < 5 || width % 2 == 0 || width>21 || width < 5);
	int O, M, I,run=1,run2=1,run3=1,run4=1,run5=1,run6=1;
	O = height * 2 + width *2 - 4;
	M = height * width - O;
	run3 = height - run2 * 2;
	run4 = width - run * 2;
	run5 = run3 - 2;
	run6 = run4 - 2;
	M -= run5 * run6;
	while (O < height * width - O||(run3*run4)%2==0||(run5*run6)%2==0 ) {
		if (height * 2 * (run+1) + (width*(run2)*2 - 4 * run) < height * 2 * run  + (width*(run2+1)*2 - 4 * run))
			run++;
		else
			run2++;
		O = height * 2 * run  + width * run2*2-4 * run;
		M = height * width - O;
		run3 = height - run2*2;
		run4 = width - run*2;
		run5 = run3 - 2;
		run6 = run4 - 2;
		while (run5 * run6 > M-(run5*run6)) {
			if (run6 > run5)
				run6 -= 2;
			else
				run5 -= 2;
		}
		M -= run5 * run6;
	}
	char** mat = intit_mat(height, width);
	for (i = 0; i < run2; i++)
		for (r = 0; r < width; r++)
			mat[i][r] = 'O';
	for (i = 0; i < run2; i++)
		for (r = 0; r < width; r++)
			mat[height - i-1][r] = 'O';
	for (i = 0; i < run; i++)
		for (r = 0; r < height; r++)
			mat[r][i] = 'O';
	for (i = 0; i < run; i++)
		for (r = 0; r < height; r++)
			mat[r][width - i-1] = 'O';
	for (i = run2; i < height - run2; i++)
		for (r = run; r < width - run; r++)
			mat[i][r] = 'M';
	for (i = run2+(run3-run5)/2; i < height - run2 - (run3-run5)/2; i++)
		for (r = run+(run4-run6)/2; r < width - run - (run4-run6)/2; r++)
			mat[i][r] = 'I';
	print(mat, height, width);
	system("pause");
}

