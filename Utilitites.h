#include <iostream>
#include "VariableInputs.h"
#include "MathOperation.h"
#include <thread>
#include <mutex>
#include <chrono>
#include <ctime>


#ifndef UTILITITES_H
#define UTILITITES_H

class Utilitites : MathOperation
{
public:
	Utilitites();
	Utilitites(float data);
	virtual ~Utilitites();
	

protected:
	char* genBuff[128];
	void packGenBuff(string items);
	void clearGenBuff();


private:


};

#endif // !UTILITITES_H