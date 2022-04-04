#include <iostream>
#include "Complex.h"

#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

int main()
{
	for (float a = 0; a <= 2 * M_PI;a += M_PI / 10)
	{
		float x = cos(a);
		float y = sin(a);
		TComplex z(x,y); cout << "z=" << z << endl;
		
		TComplex z1 = z;
		cout << "z^2=" << z1.Pow(2) << endl;
		z1 = z;
		cout << "z^0.5=" << z1.Pow(0.5) << endl;
		z1 = z;
		cout << "z^-3=" << z1.Pow(-3) << endl;
		z1 = z;
		cout << "z^-0.4=" << z1.Pow(-0.4) << endl << endl;
	}
	
	TComplex z2(3, 4);
	z2.PrintTrig();

	TComplex z3;
	z3 += z2;
	z3.PrintTrig();
	z3 = z3 - z2 - z2;
	z3.PrintTrig();

	TComplex z4 = z3;
	cin >> z4;

	if (z4 == z3)
	{
		cout << "z3=" << z3 << endl;
	}
	else
	{
		cout << "z4=" << z4 << endl;
	}

	TComplex z5;
	z5 = z3 * z4;
	cout << "z5=" << z5 << endl;

	TComplex z6;
	z6 = z3 / z4;
	z6.PrintTrig();

	return 0;
}