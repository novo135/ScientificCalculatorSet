# ScientificCalculatorSet
calculator for solving more absract math problems.

nothing to see here :) for the moment anyway

scientifc calculator usage guide

operators
	basic arthimatic ('+' '-' '/' '*')

	n%c = modulus (remainder when divided by c, where n & c are both consts)

	n! = factorial (where n is const or variable)

	pi = the value of pi

	e = eulers const

	^(c) = exponent operator (where c is const/variable/expression)

	log(c) = base 10 logrithm of c (where c is a const/expression/variable)

	logb(c) = base n logrithm (where b is const and c is a const/expression/variable)

	&(c) = square root of c (where c is a const/expression)

	&^n(c) = nth square root of c (where n is a const and and c is a const/expression)

	|x| = asbsoulte value of x (where x is a const/const expression) 

	trig functions:
		-cos(x)
		-sin(x)
		-tan(x)
		-csc(x)
		-sec(x)
		-cot(x)
		'x' must be a const/expression

syntax
	-all operators ('+' '-' '*' '/' '%') NEED to be sperated by spaces 
	-- failure to do this will create a parser error --
	
	-operators ('!' '%') should be placed to the right of the value with out spaces

	-exponents:
		denoted as a^(c) 
		where 'a' is const/variable/expression 
		and c is a const/variable/expression
			

	-encapulation of terms:
		-use '(' to start an encapsulted term
		-use ')' to end an encapsulted term	
		-encapsulted terms, when solving, will be completed first
		-encapsluated terms must be used when diving terms that are greater than one number
		-nest encapsultaion is supported along with exponents

	-equlility operator('='): 
		-when there is a CSV variable at the end of the equation this implies solivng for said vairable
		-when a CSV variable is not present this will implies a true/false statement

	-derivaites:
		denoted as d/dx or d^(c)/dx^(c)
		where c is an int from 2-6

	-intergrals:
		under construction :)

	-limits:
		denoted as x->c
		where x is vairble used in the corrospoinding expression 
		and c is const
		-> finds general limit
		
