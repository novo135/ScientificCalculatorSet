#include "VariableInputs.h"
#include "Utilitites.h"
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;


VariableInputs::VariableInputs()
	: stringIndex(0)
{

}


VariableInputs::~VariableInputs()
{

}

unsigned int VariableInputs::numOfTerms(string input)
{
	bool exponent = 0;
	bool lastCharacterSign = 0;
	int term = 1;

	for (int i = 0; i < input.size(); ++i)
	{
		switch (input[i])
		{
			case(' '):
				break;

			case('+'):
				lastCharacterSign = 1;
				++term;
				break;

			case('-'):

				if (i != 0 && 
					!lastCharacterSign &&
					!exponent) 
				{
					++term;
				}
				break;

			case('*'):
				lastCharacterSign = 1;
				++term;
				break;

			case('/'):
				lastCharacterSign = 1;
				++term;
				break;

			case('^'):
				exponent = 1;
				break;

			case(')'):
				if (exponent) {
					exponent = 0;
				}
				break;

			default:
				lastCharacterSign = 0;
				break;
		}
	}
	return term;
}

unsigned int VariableInputs::numOfExponents(string input)
{
	unsigned int expo = 0;

	for (char&c : input)
	{
		if (c == '^') {
			++expo;
		}
	}

	return expo;
}

unsigned int VariableInputs::numOfVars(string input)
{
	unsigned int times = 0;

	for (char&c : input)
	{
		if (c == 'x' ||
			c == 'y' ||
			c == 'z') 
		{
			++times;
		}
	}

	return times;
}

const char VariableInputs::varTypeFind(string input)
{
	if (input.find('x')) {
		return 'x';
	}
	else if (input.find('y')) {
		return 'y';
	}
	else if (input.find('z')) {
		return 'z';
	}
	else {
		return 0;
	}
}

const char VariableInputs::multiVarFind(string input)
{
	/// needs to be built
	return 0;
}

bool VariableInputs::isSign(char input)
{
	if (input == '+') {
		return 1;
	}
	else if (input == '-') {
		return 1;
	}
	else if (input == '*') {
		return 1;
	}
	else if (input == '/') {
		return 1;
	}
	return 0;
}

const char VariableInputs::getSign(char input)
{
	if (input == '+') {
		return '+';
	}
	else if (input == '-') {
		return '-';
	}
	else if (input == '*') {
		return '*';
	}
	else if (input == '/') {
		return '/';
	}
	return 0;
}

int VariableInputs::findNextSign(string input, short termLocate)
{
	short lastSignLoc = termLocate;
	bool exponent = 0;
	int i = termLocate + 1;

	for (i; i < input.size(); ++i)
	{
		if (getSign(input[i]))
		{
			/// todo:
			// pusdo code:
			// if '-'sign 
			// ignore 
			// unless there is no digit after the negative
		}
		else if (input[i] == '^') {
			exponent = 1;
		}
		else if (input[i] == ')') {
			exponent = 0;
		}

	}
	return i;
}

int VariableInputs::findN(string input, short N, char hayStack)
{
	int counter = 0;
	int varCounter = 0;

	if (hayStack != ' ')
	{
		for (char&c : input)
		{
			if (c == hayStack)
			{
				if (varCounter == N) {
					return counter;
				}
				++varCounter;
			}
			++counter;
		}
	}
	else
	{
		for (char&c : input)
		{
			if (getSign(c))
			{
				if (varCounter == N) {
					return counter;
				}
				++varCounter;
			}
			++counter;
		}
	}

	return 0;
}

int VariableInputs::termIdenifier(string input)
{
	bool num = 0;
	bool expo = 0;
	string intermeidate;

	for (char&c : input) 
	{
		if (isdigit(c) && !expo && !num) {
			intermeidate.push_back('1');
			num = 1;
		}

		else if (c == 'x' || c == 'y' || c == 'z') {
			intermeidate.push_back('2');
		}

		else if (c == '^') {
			expo = 1;
			intermeidate.push_back('3');
			break;
		}
	}

	try
	{
		return stoi(intermeidate);
	}
	catch (const std::invalid_argument)
	{
		return 0;
	}
}

void VariableInputs::clearSpaces(string &polynomial)
{
	for (int i = 0; i < polynomial.size(); ++i)
	{
		if (polynomial[i] == ' ')
		{
			polynomial.erase(polynomial.begin() + i);
			--i;
		}
	}
}

void VariableInputs::clearExponents(string &polynomial)
{
	clearPara(polynomial);
	int* begin = new int;
	int* end = new int;

	for (short i = 0; i <= numOfExponents(polynomial); ++i)
	{
		*begin = polynomial.find_first_of('^');

		if (begin != nullptr) 
		{
			*end = polynomial.find_first_of(')') + 1;
			if (*begin < *end) 
			{
				polynomial.erase(*begin, *end - *begin);
				i = 0;
				*begin = 0;
				*end = 0;
			}
		}
	}
	
	delete[] begin, end;
}

void VariableInputs::clearVariables(string &polynomial)
{
	for (int i = 0; i < polynomial.size(); ++i)
	{
		if (polynomial[i] == 'x' ||
			polynomial[i] == 'y' ||
			polynomial[i] == 'z')
		{
			polynomial.erase(i,1);
			--i;
		}
	}
}

void VariableInputs::clearSigns(string & polynomial)
{
	for (int i = 0; i < polynomial.size(); ++i)
	{
		if (polynomial[i] == '-' ||
			polynomial[i] == '+' ||
			polynomial[i] == '*')
		{
			polynomial.erase(i, 1);
			--i;
		}
	}
}

void VariableInputs::clearNotNums(string & polynomial)
{
	proTerm = polynomial;
	++stringIndex;
	if (stringIndex < polynomial.size())
	{
		if (!isdigit(polynomial[stringIndex]))
		{
			polynomial.erase(stringIndex, 1);
			--stringIndex;
			clearNotNums(polynomial);
		}
	}
	else {
		polynomial = proTerm;
		stringIndex = 0;
	}
}

void VariableInputs::clearPara(string & para)
{
	bool exponent = 0;
	for (int i = 0; i < para.size(); ++i)
	{
		char c = para[i];

		if (c == '(') 
		{
			if (!exponent)
			{
				para.erase(i , 1);
				--i;
			}
		}
		else if (c == ')') 
		{
			if (!exponent) 
			{
				para.erase(i , 1);
				--i;
			}
			else {
				exponent = 0;
			}
		}
		else if (c == '^') {
			exponent = 1;
		}
	}
}

int VariableInputs::invaildExponent(string input)
{
	int look = 0;
	for (short i = numOfExponents(input); i != 0; --i)
	{
		look = findN(input, i, '^');
		if (look)
		{
			/// need to decide illegial paramaters
		}
	}
	return 0;
}

int VariableInputs::invalidDoubleSign(string input)
{

	return 0;
}

int VariableInputs::invalidExpression(string input)
{

	return 0;
}

int VariableInputs::invaiidSyntax(string input)
{

	return 0;
}

int VariableInputs::findDoubleSign(string input, short range)
{
	int hayStack = 0;

	for (short i = range + 1; i < input.size(); ++i)
	{
		if (input[i] == '+' || input[i] == '-' || 
			input[i] == '*' || input[i] == '/')
		{
			if (input[i + 1] == '-')
			{
				if (isdigit(input[i + 2])) {
					hayStack = i + 1;
				}
			}
			else if (input[i + 2] == '-') 
			{
				if (isdigit(input[i + 3])) {
					hayStack = i + 2;
				}
				else if (isdigit(input[i + 4])) {
					hayStack = i + 2;
				}
			}
		}
	}

	return hayStack;
}

int VariableInputs::doubleSign(string input)
{
	clearSpaces(input);

	char* lastChar = new char;
	short counter = 0;

	for (char&c : input)
	{
		if (getSign(c) == '-' && *lastChar == '+' ||
			getSign(c) == '-' && *lastChar == '-')
		{
			delete lastChar;
			if (!counter) {
				return 1;
			}
			else {
				return counter;
			}
		}
		*lastChar = c;
		++counter;
	}

	return 0;
}

void VariableInputs::clearY(string & polynomial)
{
	if (polynomial.find('='))
	{
		if (polynomial.find_first_of('y') == 0)
		{
			if (polynomial.find(' ')) {
				polynomial.erase(0, polynomial.find_first_of('=') + 1);
			}
			else {
				polynomial.erase(0, polynomial.find_first_of('=') + 1);
			}
		}

		else if (polynomial.find_first_of('y') == polynomial.size())
		{
			if (polynomial.find(' ')) {
				polynomial.erase(polynomial.find_first_of('=') + 1, polynomial.size());
			}
			else {
				polynomial.erase(polynomial.find_first_of('='), polynomial.size());
			}
		}
	}
}

bool VariableInputs::equationStatus(string polynomial)
{
	if (polynomial.find('=')) {
		return 1;
	}
	return 0;
}

void VariableInputs::numExtract(string polynomial)
{
	clearY(polynomial);
	clearExponents(polynomial);
	clearSpaces(polynomial);
	collector.clear();

	string* transfer = new string;			// used as a 'middle man' before converting to int
	short* chopper = new short;
	short* endChopper = new short;
	
	for (int i = numOfTerms(polynomial); i != 0; --i)
	{	
		try
		{
			if (i >= 2)
			{
				*endChopper = polynomial.find_last_not_of("+-*/");		// find last number of last term
				*chopper = polynomial.find_last_of("+-*/");				// find fist number of last term
				*transfer = polynomial.substr(*chopper, *endChopper);	// intermediate string for converting string to int
				polynomial.erase(*chopper, *endChopper);				// removes the extracted item(makes the simple code possable)

				try {
					collector.push_back(stoi(*transfer));				// add to collector
				}
				catch (...) 
				{
					transfer->erase(0,1);								// handles special cases of double sign or '/' or '*'
					if (!transfer->empty()) {
						collector.push_back(stoi(*transfer));
					}
				}
			}
			else {
				collector.push_back(stoi(polynomial));	
			}
		}
		catch (std::out_of_range) {	
			break;
		}
		catch (...) { // if some jackass doubles up on signs or does not have a 1 in front of coefficent
			break;
		}
	}
	
	delete transfer, chopper, endChopper;
}

void VariableInputs::exponentExtract(string polynomial)
{
	clearSpaces(polynomial); // cleans string
	exponentCollector.clear();	// ensures collector is empty

	string* transfer = new string;
	unsigned int* startChop = new unsigned int;
	unsigned int* endChop = new unsigned int;

	for (int i = numOfExponents(polynomial); i != 0; --i)
	{
		*startChop = polynomial.find_last_of('^') + 2;
		*endChop = polynomial.find_last_of(')') - *startChop;
		*transfer = polynomial.substr(*startChop, *endChop);
		polynomial.erase(*startChop - 2, polynomial.size());

		try {
			exponentCollector.push_back(stof(*transfer));
		}
		catch (std::invalid_argument)
		{
			if (transfer->find("xzy")) {
				exponentExpression.push_back(*transfer);
			}
		}
		catch(...) 
		{
			if (transfer->empty()) {
				cout << "no arguement given" << endl;
			}
		}
	}
	delete[] startChop, endChop, transfer;
}

float VariableInputs::singleExponentExtract(string input, unsigned short rangeSpecifier)
{
	clearSpaces(input);
	clearPara(input);

	unsigned short* begin = new unsigned short;
	unsigned short* end = new unsigned short;
	string* transfer = new string;
	float hairyNutSack = 0;

	if (rangeSpecifier >= numOfExponents(input))
	{
		delete[] begin, end, transfer;
		return 0;
	}

	if (!rangeSpecifier) {
		*transfer = input.substr(input.find_first_of('^') + 2, (input.find_first_of('^') + 2) - input.find_first_of(')'));
	}
	else
	{
		*begin = findN(input, rangeSpecifier, '^') + 2;
		*end = findN(input, rangeSpecifier, ')');
		*transfer = input.substr(*begin, *end - *begin);
	}

	try {
		hairyNutSack = stof(*transfer);
	}
	catch (std::invalid_argument) {
		exponentExpression.push_back(*transfer);
	}

	delete transfer, begin, end;
	return hairyNutSack;
}

double VariableInputs::singleNumberExtract(string input, unsigned short rangeSpecifier)
{
	clearPara(input);
	clearExponents(input);
	clearVariables(input);

	string* temp = new string;
	double intermidate = 0;

	if (!rangeSpecifier) 
	{
		*temp = input.substr(0, input.find_first_of("+-*/"));
		if (temp->empty()) {
			*temp = input.substr(findN(input, 1, ' '));
		}
	}
	else
	{
		short begin = findN(input, rangeSpecifier, ')');		// something wrong here
		short end = findN(input, rangeSpecifier, ')');			// something wrong here
		*temp = input.substr(begin, end - begin);
	}

	try {
		intermidate = stod(*temp);
	}
	catch (std::invalid_argument)
	{
	
	}

	delete temp;
	return intermidate;
}




