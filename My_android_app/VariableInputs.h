#pragma once
#ifndef VARIABLE_IN_H
#define VARIABLE_IN_H
#include <string>
#include <vector>
#include "MathOperation.h"
#include "LinkedList.h"
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
		typdef funcPtr is for descerte pointers to functions
		idnentity 
	*/
	typedef int(*funcPtr)(string);
	int execute(string input);
	int preParser(string rawString);


protected:
	/*
		List contains data extracted from string as well as other nesscary functions
		typdefs are for special use cases; u8 = boolean
	*/
	LinkedList* List = new LinkedList();
	typedef uint8_t u8;
	typedef uint16_t u16;
	

private:
	/*
		basic operations for special use cases
		use variables [a-z] lowercase only 
	*/
	const char varTypeFind(string input);
	short multiVarFind(string input);
	const char getSign(char input);
	int findNextSign(string input, short index, int counter);	// find next sign of Nth occurance of sign excluding negative numbers
	int findN(string input, short N, char hayStack);			// this will find the Nth occurance of char in a string
	int termIdenifier(string input);							// ab^(c) will find if 'a' 'b' or 'c' is present; should only contain a single ter
	int operatorIdentity(string expression);					// used to identity if a link contains an operator such as "+"
	int simplestTerms(string expression);
	int isAllDigits(const string input);
	void clearSpaces(string& item);

	/*
		identifires, looks for what function name is
		any char [a-z] lower case only may be used as variable
	*/
	int basicOperations(string expression);			// if there is ONLY basic arithmatic such as + - * / 
	int deriativeStatus(string polynomial);			// d/dx thru -> d^(6)/dx^(6)
	int deriativeOfYWithX(string expression);		// dy/dx
	int intergralStatus(string polynomial);			// to be decided 
	int algerbraVariableStatus(string equation);	// , [a-z] at end of equation
	int limitStatus(string expression);				// x->[val] at start of equation
	int equationStatus(string equation);			// if '=' is present
	int trigStatus(string equation);				// if cos, sin, tan, etc are present
	int polynomialStatus(string equation);			// looks to see if equation is a quadratic
	// sub identification
	int encapsultedTerms(string polynomial);		// looks for items in parathesis

	/*
		extractors
		adds matched elements List 
		each extractor has indiviual rules
	*/
	void generalExtract(string expression);			// all elements w/out spaces are extracted
	void expoenentExtract(string polynomial);		// extracts eponents only
	void termExtract(string polynomial);			// extracts items withing parathesis
	void parathesisExtract(string equation);		// special uses case for division takes a term in paranthesis
	void indivialTermExtract(string expression);	// extracts individual ab^(c) or ab or a

	/// create a methods for : 
	/// @ base extract
	/// @ variable extract
	/// @ sign extract
	/// @ term extracts ex: ab^(c) -> ab^(c)
	/// @ encapsulted Terms extract : meaning any terms with paranthesis will be extraced
	

	/*
		processors / error handling
	*/
	int divideByZero(string expression);
	int badExpression(string expression);



};

#endif // !VARIABLE_IN_H

