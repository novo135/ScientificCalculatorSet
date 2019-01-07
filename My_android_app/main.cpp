// Math program
// Writen by Steven Novorita
// version 1.1.0

#include <iostream>
#include <string>
#include "MathOperation.h"
#include "VariableInputs.h"
#include "Utilitites.h"

using std::endl;
using std::cout;
using std::cin;
using std::string;

MathOperation* MATH;
VariableInputs VARIN;

int main(void)
{
	string poly = "(-16x)^(-10) + (-200x^(2))^(-6) * (-29)^(1.5) - (4 + 456)";		
	string def = "-19x^()";
	string p1 = "23 - x^(-12.23) + 20x^(2.2) + 159";
	string terms = "y = 170x^(10) - 10x^(1504) + -1x^(4) + 123 + 11238x";
	string divide = "(2x - 12)/5"; 
	string equ = "y = 2x^(2) + 12x - 200";
	
	//VARIN.numExtract(equ);
	//for (vector<int>::reverse_iterator j = VARIN.collector.rbegin(); j != VARIN.collector.rend(); ++j)
	//	cout << *j << endl;
	
	//VARIN.exponentExtract(poly);
	//for (vector<float>::reverse_iterator j = VARIN.exponentCollector.rbegin(); j != VARIN.exponentCollector.rend(); ++j)
	//	cout << *j << endl;

	//cout << VARIN.singleNumberExtract(poly, 0);
	
	VARIN.singleNumberExtract(poly, 1);

	if (getchar()) {
		return 0;
	}
}


