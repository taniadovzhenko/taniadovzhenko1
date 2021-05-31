#include <iostream>
#include <cmath>
#include <string>

using namespace std;

double task1_2_8(int n)
{
	int i;
	double res = 0;
	double res_old = 0;
	for (i = n;i >= 1;i--)
	{

		double res_old = res;
		res = sqrtl((double)i * 3 + res_old);

	}
	return res;
}

double task1_2_19_a(int k, double x)
{
	int i = 1;
	double res_x = 1;
	double res;

	for (i;i <= k;i++)
	{
		res_x *= x;
		res = res_x / i;
	}
	return res;
}
/*
double task1_2_25(int n)
{

	string n;
	for (int i = 0; i < n.size(); i++)
		if (n[i] == '0' || n[i] == '5') 
		{
			n.erase(i, 1);
			i--;
		}
	cout << endl << n;
	}
}

/*
int main()
{

	int x;
	cout << "x = ";
	cin >> x;

	// cout << x / 10;
	cout << "x_n = " << task1_2_25(x) << endl;
}
*/