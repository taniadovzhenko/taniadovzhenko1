/*Обчислити кінетичну енергію тіла масою m, що рухається зі
швидкістю v відносно поверхні Землі.
*/
#include<stdio.h>
int main() {
	float m, v, E;
	printf("m=");
	scanf("%f", &m);
	printf("v=");
	scanf("%f", &v);
	E = (m * v * v) / 2;
	printf("%f", E);

}