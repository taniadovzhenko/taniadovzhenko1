#include<stdio.h>
#include<math.h>

int main() {
	double x, f, h;
	scanf("%lf", &x);
	f = x / (1 + fabs(x));
	h = ((-x * x / fabs(x)) + 1 + fabs(x)) / ((1 + fabs(x)) * (1 + fabs(x)));  //похідна
	printf("%lf %lf", f, h);
}
