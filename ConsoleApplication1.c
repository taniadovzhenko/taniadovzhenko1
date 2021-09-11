/*Трикутник заданий довжиною своїх сторін. Знайти та вивести влечину
кутів трикутника у радіанах та градусах.
*/
#include<stdio.h>
#include<math.h>
int main() {
	float x, y, z, X, Y, Z, a, b, c;
	printf("x=");
	scanf("%f", &x);
	printf("y=");
	scanf("%f", &y);
	printf("z=");
	scanf("%f", &z);
	Z = (x * x + y * y - z * z) / (2 * x * y); //косинус кута між x та y
	X = (y * y + z * z - x * x) / (2 * y * z);
	Y = (x * x + z * z - y * y) / (2 * x * z);
	a = cos(Z);
	b = cos(X);
	c = cos(Y);
	printf("%f %f %f", a, b, c);


}

