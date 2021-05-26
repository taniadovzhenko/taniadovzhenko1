#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846

using namespace std;

int main()
{
    double a, b, c;
    double angle_a, angle_b, angle_c;
    do
    {
        cout << "Enter three sides of a triangle - ";
        cin >> a >> b >> c;

        if (a+b > c && a+c > b && b+c > a)
        {
            cout << "The sides form a triangle" << endl;
        }
        else
        {
            cout << "The sides do not form a triangle." << endl;
        }
        cout << endl;
    }while(!(a+b > c && a+c > b && b+c > a));

    angle_a = acos((b*b + c*c - a*a) / (2*b*c));
    angle_b = acos((a*a + c*c - b*b) / (2*a*c));
    angle_c = acos((a*a + b*b - c*c) / (2*a*b));

    cout << "Angles (A, B, C) in radians - " << angle_a << " " << angle_b << " " << angle_c << endl;
    cout << "Angles (A, B, C) in degrees - " << angle_a * 180 / M_PI<< " " << angle_b * 180 / M_PI << " " << angle_c * 180 / M_PI;

    return 0;
}
