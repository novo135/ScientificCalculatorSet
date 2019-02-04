// Math program
// Writen by Steven Novorita
// version 1.1.0

#include <iostream>
#include <string>
#include "VariableInputs.h"
#include "MathOperation.h"
#include "Utilitites.h"

int main(int* argv[], int argc)
{
	using std::endl;
	using std::cout;
	using std::cin;
	using std::string;

	string poly = "-16x^(-10) + (-200x^(2))^(-6) * (-29)^(1.5) -  -4 + 456 + 8x^(x) + 12 * 18 + 45x ";
	string def = "-19x^(2)";
	string test = "(-256 * 512)^(2) / 2^(6) + (13 - 7) + x^(2) + 12x^(4)";
	string p1 = "23 - x^(-12.23) + 20x^(2.2) + 159";
	string terms = "170x^(10) - 10x^(1504) + -1x^(4) + 123 + 11238x = y";
	string divide = "(2x^(2) + 3x - 12)/5";
	string equ = "y = 2x^(2) + 12x - 200, x";
	string dri = "dy/dx 2x^(3) + 74x^3";
	string limit = "x->-256 (2x - 3)/(2)";
	string simple = "23 + 8";
	string cos = "cos(11.7856) = 53";

	VariableInputs* Varin = new VariableInputs();
	Varin->execute(divide);




	delete[] Varin;
	if (getchar()) {
		return 0;
	}
}