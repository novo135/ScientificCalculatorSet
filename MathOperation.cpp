#include "MathOperation.h"
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include <chrono>
#include <ctime>

using std::cout;
using std::endl;
using std::vector;
using std::string;

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
	int i;
	try 
	{
		i = (var + var2);
		return i;
	}
	catch (...)
	{
		return 1;
	}
}

template<class T, class E>
double MathOperation::subtract(T var, E var2)
{
	return (var - var2);
}

template<class T, class E>
inline double MathOperation::multiply(T var, E var2)
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

int MathOperation::factoringTwoVars(int & a, int & b)
{
	int factorable = 1;
	int gcf = 0;
	do
	{
		if (!gcf) 
		{
			if ((ceilf(sqrt(a)) == sqrt(a)) &&
				(ceilf(sqrt(b)) == sqrt(a)))
			{
				a = sqrt(a);
				b = sqrt(b);
				gcf = INT_MAX;	// flag to indicate difference of squares
				factorable = 0;
			}
			else if (floor(a / b) == a / b && 
				a / b != 0) 
			{
				int i = b;
				a = a / b;
				b = 1;
				return i;
			}
			else if (floor(b / a) == b / a && 
				b / a != 0) 
			{
				int i = a;
				b = b / a;
				a = 1;
				return i;
			}
		}
		else if (a % 3 == 0 &&
				 b % 3 == 0)
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
		else if (a % 2 == 0 &&
				 b % 2 == 0)
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
		else if (a % 5 == 0 &&
				 b % 5 == 0)
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
		else {
			factorable = 0;
		}
	} while (factorable);

	return gcf;
}

int MathOperation::factoringThreeVars(int & a, int & b, int & c)
{
	int factorable = 1;
	int gcf = 0;
	do
	{
		if (!gcf)
		{
			if ((ceilf(sqrt(a)) == sqrt(a)) &&
				(ceilf(sqrt(b)) == sqrt(a)) && 
				 ceilf(sqrt(c)) == sqrt(a))
			{
				a = sqrt(a);
				b = sqrt(b);
				c = sqrt(c);
				gcf = INT_MAX;	// flag to indicate difference of squares
				factorable = 0;
			}
		}
		else if (a % 3 == 0 &&
				 b % 3 == 0 &&
				 c % 3 == 0)
		{
			if (!gcf) {
				gcf = 3;
			}
			else {
				gcf = gcf * 3;
			}

			a = a / 3;
			b = b / 3;
			c = c / 3;
		}
		else if (a % 2 == 0 &&
			     b % 2 == 0 && 
				 c % 2 == 0)
		{
			if (!gcf) {
				gcf = 2;
			}
			else {
				gcf = gcf * 2;
			}

			a = a / 2;
			b = b / 2;
			c = c / 2;
		}
		else if (a % 5 == 0 &&
			     b % 5 == 0 && 
				 c % 5 == 0)
		{
			if (!gcf) {
				gcf = 5;
			}
			else {
				gcf = gcf * 5;
			}

			a = a / 5;
			b = b / 5;
			c = c / 5;
		}
		else {
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

