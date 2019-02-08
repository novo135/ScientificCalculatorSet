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

			case '-':

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
	std::regex varFind("\\^");
	std::smatch matches;
	unsigned int expo = 0;
	while (std::regex_search(input, matches, varFind))
	{
		++expo;
		input = matches.suffix().str();
	}
	return expo;
}

unsigned int VariableInputs::numOfVars(string input)
{
	std::regex varFind("[a-z]");
	std::smatch matches;
	unsigned int times = 0;
	while (std::regex_search(input, matches, varFind))
	{
		++times;
		input = matches.suffix().str();
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

short VariableInputs::multiVarFind(string input)
{
	std::regex multiVar("[a-z]");
	std::smatch matches;
	short counter = 0;
	while (std::regex_search(input, matches, multiVar))
	{
		++counter;
		input = matches.suffix().str();
	}
	return counter;
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
	else if (input == ' ') {
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
		case(' '):
			return 5;
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
	int counter = 0;
	for (char&c : expression)
	{
		if (!counter) 
		{
			if (expression.size() == 1) {
				factor = 1;
			}
		}
		else if (!isdigit(c)) {
			factor = 1;
		}
		++counter;
	}
	return factor;
}

int VariableInputs::isAllDigits(const string input)
{
	return std::all_of(input.begin(), input.end(), ::isdigit);
}

void VariableInputs::clearSpaces(string & item)
{
	for (int i = 0; i < item.size(); ++i)
	{
		if (item[i] == ' ')
		{
			item.erase(i,1);
			--i;
		}
	}
}

int VariableInputs::divideByZero(string expression)
{
	std::regex derative("\\/([ ]|0)");
	std::smatch matches;
	int counter = 0;
	while (std::regex_search(expression, matches, derative))
	{
		expression = matches.suffix().str();
		++counter;
	}
	return counter;
}

int VariableInputs::badExpression(string expression)
{
	return 0;
}

int VariableInputs::basicOperations(string expression)
{
	std::regex derative("[a-z]");
	std::smatch matches;
	int counter = 0;
	while (std::regex_search(expression, matches, derative))
	{
		expression = matches.suffix().str();
		++counter;
	}
	return counter;
}

int VariableInputs::deriativeStatus(string polynomial)
{
	std::regex derative("\\b\d+(\\^+\\(+[2-6]+\\)\\/\d[a-z]\\^\\([2-6]\\)|/\d[a-z])");
	std::smatch matches;
	int counter = 0;
	while (std::regex_search(polynomial, matches, derative))
	{
		polynomial = matches.suffix().str();
		++counter;
	}
	return counter;
}

int VariableInputs::deriativeOfYWithX(string expression)
{
	std::regex derative("\\b\d\[a-z]\/\d\[a-z]");
	std::smatch matches;
	int counter = 0;
	while (std::regex_search(expression, matches, derative))
	{
		//cout << matches.str() << endl;
		expression = matches.suffix().str();
		++counter;
	}
	return counter;
}

int VariableInputs::intergralStatus(string polynomial)
{
	std::regex intergral("\\b\s\\(()");
	std::smatch matches;
	int counter = 0;
	while (std::regex_search(polynomial, matches, intergral))
	{
		//cout << matches.str() << endl;
		polynomial = matches.suffix().str();
		++counter;
	}
	return counter;
}

int VariableInputs::algerbraVariableStatus(string equation)
{
	std::regex variable(",([a-z]| [a-z])");
	std::smatch matches;
	int counter = 0;
	while (std::regex_search(equation, matches, variable))
	{
		//cout << matches.str() << endl;
		equation = matches.suffix().str();
		++counter;
	}
	return counter;
}

int VariableInputs::equationStatus(string equation)
{
	std::regex variable("=");
	std::smatch matches;
	int counter = 0;
	while (std::regex_search(equation, matches, variable))
	{
		//cout << matches.str() << endl;
		equation = matches.suffix().str();
		++counter;
	}
	return counter;
}

int VariableInputs::trigStatus(string equation)
{
	std::regex variable("(cos|sin|tan|csc|cot|sec)\\(([+-]?([\\d]*[\.])?[\\d]+|[a-z])+\\)");
	std::smatch matches;
	int counter = 0;
	while (std::regex_search(equation, matches, variable))
	{
		//cout << matches.str() << endl;
		equation = matches.suffix().str();
		++counter;
	}
	return counter;
}

int VariableInputs::polynomialStatus(string equation)
{
	std::regex poly("");
	std::smatch matches;
	int counter = 0;
	while (std::regex_search(equation, matches, poly))
	{
		//cout << matches.str() << endl;
		equation = matches.suffix().str();
		++counter;
	}
	return counter;
}

int VariableInputs::encapsultedTerms(string polynomial)
{
	std::regex poly("[\\^]\\(");
	std::smatch matches;
	int counter = 0;
	while (std::regex_search(polynomial, matches, poly))
	{
		polynomial = matches.suffix().str();
		++counter;
	}
	return counter;
}

int VariableInputs::limitStatus(string expression)
{
	std::regex limit("[a-z](->|<-)\([\\d]|\-[\\d])+");
	std::smatch matches;
	int counter = 0;
	while (std::regex_search(expression, matches, limit))
	{
		//cout << matches.str() << endl;
		expression = matches.suffix().str();
		++counter;
	}
	return counter;
}

void VariableInputs::generalExtract(string expression)
{
	std::regex takeAll("([^\\s]+)");
	std::smatch matches;
	string temp;
	while (std::regex_search(expression, matches, takeAll))
	{
		temp = matches.str();
		expression = matches.suffix().str();
		List->pushBack(temp);
	}
}

void VariableInputs::expoenentExtract(string polynomial)
{
	std::regex variable("\\^\\(([+-]?([\\d]*[\.])?[\\d]+|[a-z])");
	std::smatch matches;
	string temp;
	int counter = 1;
	char c = ' ';
	while (std::regex_search(polynomial, matches, variable))
	{
		temp = matches.str();
		temp.push_back('|');
		c = counter;
		temp.push_back(c);
		cout << temp << endl;
		polynomial = matches.suffix().str();
		++counter;
	}
}

void VariableInputs::termExtract(string polynomial)
{
	std::regex termFind("([-]?\\d+[a-z]\\^\\((\\d+|[-]?\\d+)\\)|[-]?\\d+[a-z][^\\^])");
	std::smatch matches;
	string temp;
	while (std::regex_search(polynomial, matches, termFind))
	{
		temp = matches.str();
		cout << temp << endl;
		polynomial = matches.suffix().str();
		//List->addLink(temp);
	}
}

void VariableInputs::parathesisExtract(string equation)
{
	int expoFlag = 0;
	int insideParaCounter = 0;
	int startTerm = 0;
	int endTerm = 0;
	int spcFlag = 0;
	char c = ' ';
	string temp;

	for (short i = 0; i < equation.size(); ++i)
	{
		c = equation[i];
		if (!i && c == '(') 
		{
			startTerm = 0;
			spcFlag = 1;
		}
		else
		{
			switch (c)
			{
			case('('):
				if (!startTerm && !spcFlag) {
					startTerm = i;
				}
				else if (startTerm || spcFlag) {
					++insideParaCounter;
				}
				break;

			case(')'):
				if (expoFlag)
				{
					--insideParaCounter;
					expoFlag = 0;
				}
				else if (insideParaCounter) {
					--insideParaCounter;
				}
				else if (!insideParaCounter && !expoFlag && (startTerm || spcFlag) ) {
					endTerm = i;
				}
				break;

			case('^'):
				expoFlag = 1;
				break;

			default:
				break;
			}
		}

		if (startTerm && endTerm)
		{
			temp = equation.substr(startTerm, endTerm + 1);
			equation.erase(startTerm, endTerm + 1);
			cout << equation << endl;
			cout << temp << endl;
			break;
		}
		else if (!startTerm && endTerm && spcFlag)
		{
			temp = equation.substr(startTerm, endTerm + 1);
			equation.erase(startTerm, endTerm + 1);
			cout << equation << endl;
			cout << temp << endl;
			endTerm = 0;
			spcFlag = 0;
		}
	}
}

void VariableInputs::indivialTermExtract(string expression)
{
	std::regex termFind("([-]?[\\d]{0,12}[a-z]{0,1}?(\\^+\\(?[-]?\\d+\\))|[-]?[\\d]+?[a-z]|[-]?[\\d]+)");
	std::smatch matches;
	string temp;
	while (std::regex_search(expression, matches, termFind))
	{
		temp = matches.str();
		cout << temp << endl;
		expression = matches.suffix().str();
		//List->pushBack(temp);
	}
}

int VariableInputs::preParser(string input)
{
	cout << basicOperations(input) << endl;
	indivialTermExtract(input);
	for (int i = 0; i < List->getSize(); ++i)
	{
		cout << isAllDigits(input) << endl;
	}
	List->printList();
	return 0;
}

int VariableInputs::execute(string rawString)
{
	cout << basicOperations(rawString) << endl;

	///@ these need to be tested for accuracy

	if (!basicOperations(rawString))
	{
		for (int i = 0; i < List->getSize(); ++i)
		{
			string temp = List->iterator(i);
			if (isAllDigits(temp))
			{
				// add strings method	
			}
			else
			{
				// simplify then add strings
			}
		}
	}
	if (deriativeStatus(rawString)) 
	{

	}
	if (deriativeOfYWithX(rawString))
	{

	}
	if (intergralStatus(rawString))
	{
		
	}
	if (algerbraVariableStatus(rawString))
	{
		if (equationStatus(rawString)) 
		{

		}
	}
	if (limitStatus(rawString))
	{

	}
	if (polynomialStatus(rawString))
	{

	}
	return 0;
}

