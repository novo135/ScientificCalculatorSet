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
	void clearSpaces(string& item);

	/*
		identifires
		any char [a-z] lower case only may be used as variable
	*/
	int deriativeStatus(string polynomial);
	int deriativeOfYWithX(string expression);
	int intergralStatus(string polynomial);
	int algerbraVariableStatus(string equation);
	int limitStatus(string expression);
	int equationStatus(string equation);
	int trigStatus(string equation);
	int polynomialStatus(string equation);
	// sub identification
	int encapsultedTerms(string polynomial);

	/*
		extractors
		adds matched elements List 
		each extractor has indiviual rules
	*/
	void generalExtract(string expression);			// all elements w/out spaces are extracted
	void expoenentExtract(string polynomial);		// extracts eponents only
	void termExtract(string polynomial);			// extracts items withing parathesis
	void parathesisExtract(string equation);		// special uses case for division takes a term in paranthesis

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

