#include <string>
#include <vector>
#include "LinkedList.h"

#ifndef VARIABLE_IN_H
#define VARIABLE_IN_H

using std::string;
using std::vector;

class VariableInputs
{
public:
	// constructor and destructor
	VariableInputs();
	virtual ~VariableInputs();

	/*
		Various identifires for equations
		power must be noted as ^(n) no space! -> EX: x^(3)
	*/
	unsigned int numOfTerms(string input);
	unsigned int numOfExponents(string input);
	unsigned int numOfVars(string input);

	/*
		extractors, all objects without spaces will be added to list
	*/
	void allElements(string polynomial);
	void allNumberExtract(string polynomial);
	int simplestTerms(string expression);										// returns 1 if there is only a number and no addanital processing is needed 


protected:
	LinkedList* List = new LinkedList();


private:
	/*
	looks for certain value in a string
	same rules apply as for above methods
	*/
	const char varTypeFind(string input);
	const char multiVarFind(string input);
	const char getSign(char input);
	int equationStatus(string polynomial);
	int findNextSign(string input, short index, int counter);	// find next sign of Nth occurance of sign excluding negative numbers
	int findN(string input, short N, char hayStack);			// this will find the Nth occurance of char in a string
	int termIdenifier(string input);							// ab^(c) will find if 'a' 'b' or 'c' is present; should only contain a single term
	int deriativeStatus(string polynomial);
	int operatorIdentity(string expression);					// used to identity if a link contains an operator such as "+"

	/*
		testing for illegial paramenters
	*/
	int invaildExponent(string expression);
	int badExpression(string expression);

};

#endif // !VARIABLE_IN_H

