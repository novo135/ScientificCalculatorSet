#include "VariableInputs.h"
#include <string>

#ifndef MATH_OPERATIONS_H
#define MATH_OPERATIONS_H

class MathOperation : VariableInputs
{
public:
	MathOperation();
	virtual ~MathOperation();

	
	void(*p);

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
		ZERO CANNOT BE AN INPUT!
	*/
	int factoringTwoVars(int &a, int &b);
	int factoringThreeVars(int &a, int &b, int &c);

	/*
		calculates the sides and angles of triangle
		needs at least: two angles and one side or, one angle and two sides 
		THIS ONLY WORKS WITH SPECIAL RIGHT TRIANGLES
		returns one in the event of a computation or input error
	*/
	float calc_triangle_side(float side_a, float side_b, float hypotenuse);	// needs at least two inputs


protected:
	double addStrings(std::string arg1, std::string arg2);

private:
	
	/*
		useful mathmathical constants
	*/
	const double e;											// eulers' const
	const double pi;
	int single_factor(float input, bool print_to_screen);	// debugging only :)

	/*
		descrete trig operations
	*/
	double cosine(double arc);
	double sine(double arc);
	double tangent(double arc);
	double cosecant(double arc);
	double secant(double arc);
	double cotan(double arc);

	/*
		number tools
	*/
	int is_int(float a);				// checking for non decimal value
	int even_num(int a);				// true if num is non decimal after / 2
	int prf_root(float a);				// true if num is a prf root
	int least_com_multi(int a, int b);	// find least common multiple


	double square(int base);
	double squareRoot(double val);
	double inverseSquare(int base);
	double inversePower(double base, double exp);
	double power(int base, int expo);
	long double factorial(int input);

	int solveQuadratic(int a, int b, int c);



};

#endif // _MATH_OPER