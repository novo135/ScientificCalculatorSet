#include "Utilitites.h"
#include <iostream>

Utilitites::Utilitites()
{
	
}

Utilitites::Utilitites(float data)
{
	// use memeset
	// pack numBuff 
	
	
}

Utilitites::~Utilitites()
{
}

void Utilitites::packGenBuff(string items)
{
	int counter = 0;
	for (char&c : items)
	{
		memset(genBuff, c , counter);
		++counter;
	}
}

void Utilitites::clearGenBuff()
{

}
