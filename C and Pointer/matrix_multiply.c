  #include<stdio.h>
#include<stdlib.h>
#include <string.h>

void matrix_multiply(int *m1, int *m2, int *r, int x, int y, int z) {
	int  rx, ry;
	rx = ry=0;
	

	while (true)
	{
		for (int i = 0; i < y; i++) {

			r[rx + ry*z] += m1[i + ry*y] * m2[rx + i*z];

		}
		if (rx == z - 1) {
			if (ry != x - 1)
			{
				ry++;
				rx = 0;
			}
			else
				return;
		}
		else
			rx++;
	}
}
int main() {

	int x = 3, y = 2, z = 4;
	int m1[] = { 2,-6,3,5,1,-1 };
	int m2[] = { 4,-2,-4,-5,-7,-3,6,7 };
	int r[12] = {};
	matrix_multiply(m1, m2, r, x, y, z);
	int count=0;
	while (count<12)
	{
		printf(" %d ", r[count]);
		count++;
	}
	printf("\n");
	

	return 0;

}
