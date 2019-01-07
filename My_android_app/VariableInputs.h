#ifndef VARIABLE_IN_H__
#define VARIABLE_IN_H__

#include <string>
#include <vector>
using std::string;
using std::vector;

class VariableInputs
{
public:
	// constructor and destructor
	VariableInputs();
	virtual ~VariableInputs();

	vector <int> collector;			// these will hold all the variables when extracting variabels from a string
	vector <float> exponentCollector;
	vector <string> exponentExpression;

	/*
		VARIABLE MUST BE (x, y, z) NO UPPERCASE
		Various identifires for equations
		power must be noted as ^(n) no space! -> EX: x^(3)
	*/
	unsigned int numOfTerms(string input);
	unsigned int numOfExponents(string input);
	unsigned int numOfVars(string input);

	/*
		looks for certain value in a string
		same rules apply as for above methods
	*/
	const char varTypeFind(string input);
	const char multiVarFind(string input);
	const char getSign(char input);
	bool isSign(char input);
	int findNextSign(string input, short index);			// 
	int findN(string input, short N, char hayStack);		// this will find the Nth occurance of char in a string
	int termIdenifier(string input);						// ab^(c) will find if 'a' 'b' or 'c' is present; should only contain a single term

	void clearSpaces(string &polynomial);					// removes spaces
	void clearExponents(string &polynomial);				// removes exponents
	void clearVariables(string &polynomial);				// remove variables
	void clearSigns(string &polynomial);					// remove signs
	void clearNotNums(string &polynomial);					// removes everything ececpt numbers
	void clearPara(string &para);							// removes parethesis that are not an exponent

	int invaildExponent(string input);						// returns first instance of invaild exponent arg
	int invalidDoubleSign(string input);					// returns first instacne of invalid sign placement/expression
	int invalidExpression(string input);					// returns first instance of out of range expression or other nonsense
	int invaiidSyntax(string input);

	void clearY(string &polynomial);						// removes "y = "  if present 
	bool equationStatus(string polynomial);					// returns one if the expression is an equation

	/*
		error checking processes
		returns location of the problem expression
		find double sign looks for valid negative numbers
	*/
	int findDoubleSign(string input, short range);	
	int doubleSign(string input);

	/*
		extracts numbers in a polynomial first character must be a number
		///////////////////////////////////////////////////////////////////////////////////////////////////////////
		//! -----> !* USE REVERSE ITERATOR WHEN COLLECTING VARIABLES FROM VECTOR CORROSPONDING VECTOR *! <----- //
		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		if you dont like it make your own
		does not work with adding negatives
		ONLY EXTRACTS CONSTANTS!
	*/
	void numExtract(string polynomial);			// adds items to collector	
	void exponentExtract(string polynomial);	// adds values to exponentColl

	float singleExponentExtract(string input, unsigned short rangeSpecifier);	// extracts exponents zero indexed from left to right
	double singleNumberExtract(string input, unsigned short rangeSpecifier);		// zero indexed

	//////////////////////////////////////////////////////////////////////////////////////////////////////
	// ---->> the following methods are for finding the operations in the string itself <<----		   //  
	////////////////////////////////////////////////////////////////////////////////////////////////////	





private:
	string proTerm;
	string proString;
	int stringIndex;

};

#endif // !VARIABLEIN

