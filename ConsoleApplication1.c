/*Визначити більше та менше з двох чисел, введених з клавіатури */

#include<stdio.h>
#include<math.h>

int main() {
	double x, y, min, max;
	scanf("%lf", &x);
	scanf("%lf", &y);
	min = x;
	max = x;
	if (y < min) {
		y = min;
	}
	if (y > max) {
		y = max;
	}
	printf("%lf %lf", min, max);



}

