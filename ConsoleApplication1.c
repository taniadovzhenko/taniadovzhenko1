#include<stdio.h>
#include<math.h>
double task_03_1gg(double x) {
	double y = 16 * x * x * x * x + 8 * x * x * x + 4 * x * x + 2 * x + 1;
	return y;
}

int main() {
	double x, y;
	scanf("%lf", &x);
	y = task_03_1gg(x);
	printf("y=%lf", y);
}