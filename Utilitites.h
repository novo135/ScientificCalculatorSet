#include <iostream>
#include "VariableInputs.h"
#include "MathOperation.h"

#ifndef UTILITITES_H
#define UTILITITES_H

class Utilitites : VariableInputs, MathOperation
{
public:
	Utilitites();
	Utilitites(float data);
	virtual ~Utilitites();
	
protected:
	char* numBuff[65];

};

#endif // !UTILITITES_H