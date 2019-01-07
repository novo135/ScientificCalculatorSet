#include "MathOperation.h"
#include "VariableInputs.h"
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

VariableInputs VAR;

// construct
MathOperation::MathOperation()
	: gcf_var(0),
	pwr_var(0),
	e(2.718281828459045235360287471352)
{

}

// desctuct
MathOperation::~MathOperation()
{

}

int MathOperation::mod_two(int a)
{
	if (a % 2 == 0)
	{
		return 1;
	}
	return 0;
}

int MathOperation::mod_three(int a)
{
	if (a % 3 == 0)
	{
		return 1;
	}
	return 0;
}

int MathOperation::mod_five(int a)
{
	if (a % 5 == 0)
	{
		return 1;
	}
	return 0;
}

int MathOperation::primeSquared(float a)
{
	if ( is_int(sqrtf(a)) ) {
		return 1;
	}
	return 0;
}

int MathOperation::is_int(float a)
{
	if (floor(a) == a)
	{
		return 1;
	}
	return 0;
}

int MathOperation::even_num(int a)
{
	if (a % 2 == 0)
	{
		return 1;
	}
	return 0;
}

int MathOperation::prf_root(float a)
{
	if (a == 1) 
	{
		return 1;
	}

	for (short i = 2; i < a; ++i)
	{
		if (i * i == a)
		{
			return 1;
		}
	}
	return 0;
}

int MathOperation::least_com_multi(int a, int b)
{
	// need to build this

	return 0;
}

template<class T, class E>
double MathOperation::add(T var, E var2)
{
	return (var + var2);
}

template<class T, class E>
double MathOperation::subtract(T var, E var2)
{
	return (var - var2);
}

template<class T, class E>
double MathOperation::multiply(T var, E var2)
{
	return (var * var2);
}

template<class T, class E>
double MathOperation::divide(T var, E var2)
{
	return (var / var2);
}

int MathOperation::single_factor(float input, bool print_to_screen)
{
	vector <int> bar;

	for (int i = 1; i <= input; ++i)
	{
		if (is_int(input / i))
		{	
			// std::cout << i << std::endl;
			bar.push_back(i);
		}
	}

	if (print_to_screen)
	{
		for (vector<int>::reverse_iterator j = bar.rbegin(); j != bar.rend(); ++j)
		{
			std::cout << *j << std::endl;
		}
	}

	return 0;
}

int MathOperation::interation_factoring(int & a, int & b)
{
	int gcf = 0;
	bool factorable = 1;

	do
	{
		if (mod_three(a) && mod_three(b))
		{
			if (!gcf) {
				gcf = 3;
			}

			else {
				gcf = gcf * 3;
			}

			a = a / 3;
			b = b / 3;
		}

		else if (mod_two(a) && mod_two(b))
		{
			if (!gcf) {
				gcf = 2;
			}

			else {
				gcf = gcf * 2;
			}

			a = a / 2;
			b = b / 2;
		}

		else if (mod_five(a) && mod_five(b))
		{
			if (!gcf) {
				gcf = 5;
			}

			else {
				gcf = gcf * 5;
			}

			a = a / 5;
			b = b / 5;
		}

		else if (primeSquared(a) && primeSquared(b))
		{
			// need to figure out how to handle this
		}

		else
		{
			factorable = 0;
		}

	} while (factorable);

	return gcf;
}

float MathOperation::calc_triangle_side(float side_a, float side_b, float hypotenuse)
{
	if (side_a && side_b) {
		return sqrt((side_b * side_b) + (side_a * side_a));
	}

	else if (side_b && hypotenuse) {
		return sqrt((hypotenuse * hypotenuse) - (side_b * side_b));
	}

	else if (side_a && hypotenuse) {
		return sqrt((hypotenuse * hypotenuse) - (side_a * side_a));
	}

	else {
		return 0.0f;
	}
}

inline void angle_calc(float side_a, float hypotenuse, float &angle_a, float &angle_b)
{
	// descrete case function pointer used in calc triangle
	angle_a = sin(side_a / hypotenuse);
	angle_b = 90.0f - angle_a;
}

void side_calc(float &hypotenuse, float &side_a, float &side_b, float &angle_a)
{
	// descrete case funciton pointer used in calc triangle
	if (!hypotenuse && side_a && !side_b) {
		hypotenuse = side_a / sin(90.0f - angle_a);				/// check to see if this is correct
		side_b = (hypotenuse)*(hypotenuse) - (side_a)*(side_a);
	}

	else if (!hypotenuse && !side_a && side_b) {
		hypotenuse = side_b / sin(angle_a);						/// check to this if this is correct
		side_a = (hypotenuse)*(hypotenuse) - (side_b)*(side_b);
	}

	else if (hypotenuse && !side_a && !side_b) {
		side_b = hypotenuse * sin(angle_a);						/// check to see if this is correct
		side_a = (hypotenuse)*(hypotenuse) - (side_b)*(side_b);
	}
}

uint8_t MathOperation::calc_spc_triangle(float& side_a, float& side_b, float& hypotenuse, float& angle_a, float& angle_b)
{
	if (angle_a or angle_b)
	{
		if (side_a)
		{
			if (angle_b && !angle_a) {
				hypotenuse = side_a / sinf(angle_b);
				side_b = sqrt((hypotenuse * hypotenuse) - (side_a * side_a));
				angle_a = 90.0f - angle_b;
			}
			
			else if (!angle_b && angle_a)
			{

			}

			else if (angle_a && angle_b)
			{

			}
		}

		else if (side_b)
		{
			if (angle_a && !angle_b) {
				hypotenuse = side_b / sinf(angle_a);
				side_a = sqrt((hypotenuse*hypotenuse) - (side_b*side_b));
				angle_b = 90.0f - angle_a;
			}

			else if (!angle_a && angle_b) {


			}

			else if (angle_a && angle_b)
			{

			}
		}

		else if (hypotenuse)
		{
			if (angle_a && !angle_b)
			{
				side_b = hypotenuse * sinf(angle_a);
				side_a = sqrt( (hypotenuse*hypotenuse)-(side_b*side_b) );
				angle_b = 90.0f - angle_a;
			}

			else if (!angle_a && angle_b) {


			}

			else if (angle_a && angle_b)
			{

			}
		}
	}
	return 0;
}

long double MathOperation::factorial(int factorial)
{
	long double sum = 1;

	for (int i = 1; i < factorial; ++i)
	{
		sum += sum * i;
	}

	return sum;
}

long double MathOperation::power(int base, int expo)
{
	return pow(base, expo);
}

