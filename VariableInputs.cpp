#include "VariableInputs.h"
#include <iostream>
#include <string>
#include <vector>
#include <regex>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;


VariableInputs::VariableInputs()
{
}


VariableInputs::~VariableInputs()
{
	delete List;
}

unsigned int VariableInputs::numOfTerms(string input)
{
	/// account for multiple parathesis
	int parathesisCounter = 0;
	bool exponent = 0;
	bool lastCharacterSign = 0;
	int term = 1;

	for (int i = 0; i < input.size(); ++i)
	{
		switch (input[i])
		{
			case('+'):
				lastCharacterSign = 1;
				++term;
				break;

			case('-'):

				if (i != 0 ^ i != 1 && 
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
				else {
					parathesisCounter = 0;
				}
				break;

			case('('):
				if (!exponent) {
					++parathesisCounter;
				}

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

int VariableInputs::equationStatus(string polynomial)
{
	if (polynomial.find('=')) {
		return 1;
	}
	return 0;
}

int VariableInputs::findNextSign(string input, short termLocate, int counter)
{
	int i = termLocate + 1;
	int encapTerm = 0;
	short instanceCounter = 0;
	bool exponent = 0;

	for (i; i < input.size(); ++i)
	{
		if (!exponent && !encapTerm)
		{
			if (getSign(input[i])) 
			{
				if (input[i] == '-' && isdigit(input[i + 1])) {
					/// don't know what goes here
				}
				else if (counter != instanceCounter) {
					++instanceCounter;
				}
				else if (counter == instanceCounter) {
					break;
				}
			}
		}
		else if (input[i] == '^') {
			exponent = 1;
		}
		else if (input[i] == ')') {
			exponent = 0;
		}
		else if (input[i] == '(' && input[i - 1] != '^') {
			++encapTerm;
		}
		else if (input[i] && !exponent) {
			--encapTerm;
		}
	}

	if (i == input.size()) {
		return 0;
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
		if (isdigit(c) && !expo && !num) 
		{
			intermeidate.push_back('1');
			num = 1;
		}

		else if (c == 'x' || c == 'y' || c == 'z') {
			intermeidate.push_back('2');
		}

		else if (c == '^')
		{
			expo = 1;
			intermeidate.push_back('3');
			break;
		}
	}

	try {
		return stoi(intermeidate);
	}
	catch (const std::invalid_argument) {
		return 0;
	}
}

int VariableInputs::deriativeStatus(string polynomial)
{
	if (polynomial[0] == 'd' && polynomial[1] == '/' && polynomial[2] == 'd') 
	{
		return 1;
	}
	return 0;
}

int VariableInputs::operatorIdentity(string expression)
{
	if (expression.size() <= 1)
	{
		char c = expression[0];
		switch (c)
		{
		case('+'):
			return 1;
			break;
		case('-'):
			return 2;
			break;
		case('/'):
			return 3;
			break;
		case('*'):
			return 4;
			break;
		default:
			return 0;
			break;
		}
	}
	return 0;
}

int VariableInputs::simplestTerms(string expression)
{
	int factor = 0;
	for (char&c : expression)
	{
		if (!isdigit(c) || c == ' ') {
			factor = 1;
		}
		else if (factor) {
			break;
		}
	}
	return 0;
}

int VariableInputs::invaildExponent(string expression)
{
	return 0;
}

int VariableInputs::badExpression(string expression)
{
	return 0;
}

void VariableInputs::allElements(string polynomial)
{
	/// this is the be all end all
	using std::smatch;
	using std::regex;
	regex takeFloat("([^\\s]+)");
	smatch matches;
	string* temp = new string;
	while (regex_search(polynomial, matches, takeFloat))
	{
		*temp = matches.str();
		polynomial = matches.suffix().str();
		List->addLink(*temp);
	}
	List->printList();
	delete temp;
}

void VariableInputs::allNumberExtract(string input)
{
	using std::smatch;
	using std::regex;				
	regex takeFloat("([\\^*\\(]*[+-]?([\\d]*[\.])?[\\d]+)");	
	smatch matches;
	string* temp = new string;
	while (regex_search(input, matches, takeFloat))
	{
		*temp = matches.str();
		input = matches.suffix().str();
		cout << *temp << endl;
		
	}
	delete temp;
}

