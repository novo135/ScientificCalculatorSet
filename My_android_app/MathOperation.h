#include <vector>
#include <string>
#include "VariableInputs.h"

#ifndef MATH_OPERATIONS_H
#define MATH_OPERATIONS_H

using std::vector;
using std::string;

class MathOperation : VariableInputs
{
public:
	MathOperation();
	virtual ~MathOperation();

	int is_int(float a);				// checking for non decimal value
	int even_num(int a);				// true if num is non decimal after / 2
	int prf_root(float a);				// true if num is a prf root
	int least_com_multi(int a, int b);	// find least common multiple

	template<class T, class E>
	double add(T var, E var2);

	template<class T, class E>
	double subtract(T var, E var2);

	template<class T, class E>
	double multiply(T var, E var2);

	template<class T, class E>
	double divide(T var, E var2);

	/*
		very efficent ways of factoring
		iteration factoring can be used on hardware w/ less memory
		first arg must be set to NULL
		ZERO CANNOT BE AN INPUT!
	*/
	int factoringTwoVars(int &a, int &b);
	int factoringThreeVars(int &a, int &b, int &c);
	int single_factor(float input, bool print_to_screen);	// debugging only :)

	/*
		calculates the sides and angles of triangle
		needs at least: two angles and one side or, one angle and two sides 
		THIS ONLY WORKS WITH SPECIAL RIGHT TRIANGLES
		returns one in the event of a computation or input error
	*/
	float calc_triangle_side(float side_a, float side_b, float hypotenuse);	// needs at least two inputs


	long double factorial(int input);
	long double power(int base, int expo);


private:
	int gcf_var;				// special var for step factoring
	long int pwr_var;
	const double e;				// eulers' const

};

#endif // _MATH_OPER