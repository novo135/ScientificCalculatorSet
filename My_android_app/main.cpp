// Math program
// Writen by Steven Novorita
// version 1.1.0

#include <iostream>
#include <string>
#include "VariableInputs.h"
#include "MathOperation.h"

int main(void)
{
	using std::endl;
	using std::cout;
	using std::cin;
	using std::string;

	string poly = "(-16x)^(-10) + (-200x^(2))^(-6) * (-29)^(1.5) -  -4 + 456 + 8x^(x) + 12 * 18";		
	string def = "-19x^(2)";
	string p1 = "23 - x^(-12.23) + 20x^(2.2) + 159";
	string terms = "170x^(10) - 10x^(1504) + -1x^(4) + 123 + 11238x = y";
	string divide = "(2x - 12)/5"; 
	string equ = "y = 2x^(2) + 12x - 200";
	string dri = "d/dx 2x^(3)";
	string simple = "23 + 8";

	
	VariableInputs Varin;

	Varin.allElements(poly);

	
	
	if (getchar()) {
		return 0;
	}
}
