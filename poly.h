// Author: 		Dr. Spiegel
// Updater:		Youssef Almkari
// Course:		CSC136
// Assignment:		Project 2
// Filename:		poly.h
// Purpose:		Definition of the Polynomial Class
//			This class provides the user the functionality of a polynomial, including
//			the ability to add terms, evaluate, and multiply the coefficients.
//			It also provides basic set and get functionality.
//			A function is provided to read terms from a file, and two associated 
//			non-member, non-friend stream operators are present for reading a Term 
//			and outputting the Polynomial in its entirety.
//
//**UPDATE**:		The Polynomial Class now handles Arrays which handle specific Terms.
//			Access to Terms now can only be done through termList of type Array.

#ifndef POLY_H
#define POLY_H

#include <iostream>
#include <string>
#include "Array.h"

using namespace std;

class Polynomial
{
 public:
  
  //////
  // Constructor
  //////

/*
Function: 	constructor
Member Type:	N/A
Description: 	activates termList
Parameters: 	none
Returns:      	N/A
*/

  Polynomial();
  
  //////
  // Gets and Sets
  //////
  
  // Sets 
  
/*
Function: 	setTerm
Member Type:	Mutator
Description: 	Sets the term in the variable at a specific index
Parameters: 	int index - input - the index at which the values are stored
		float co  - input - the coefficient
		int ex 	  - input - the exponent 
Returns:      	void
*/
 
  void setTerm(int index, double co, int ex);

/*
Function: 	setCoeff
Member Type:	Mutator
Description: 	Sets the coefficient for a term in the variable at a specific index
Parameters: 	int index - input - the index at which the values are stored
		float co  - input - the coefficient for the user
Returns:      	void
*/ 

  void setCoeff(int index, double co);

/*
Function: 	setExponent
Member Type:	Mutator
Description: 	Sets the exponent for the term in the variable at a specific index
Parameters: 	int index - input - the index at which the values are stored
		int ex    - input - the exponent for the user
Returns:      	void
*/

  void setExponent(int index, int ex);

  // Gets

/*
Function: 	getTerm
Member Type:	Inspector
Description: 	Gives the user the values associated with the terms at the index
Parameters: 	int index - input - the index at which the values are stored
Returns:        Term 	  - from requested index
*/

  Term getTerm(int index) const;

/*
Function: 	getCoeff
Member Type:	Inspector
Description: 	Gets the user the coefficient at a certain index
Parameters: 	int index - input - the index at which the values are stored
Returns:        double	  - coefficient from requested index
*/

  double getCoeff(int index) const;

/*
Function: 	getExponent
Member Type:	Inspector
Description:  	Gets the user the exponent for a certain index
Parameters: 	int index - input - the index at which the values are stored
Returns:      	int	  - exponent from requested index
*/

  int getExponent(int index) const;
  
/*
Function: 	getTermList
Member Type:	Inspector
Description:  	returns object ternList to be used with  outside class scope functions
Parameters: 	none
Returns:      	Array termList
*/

  const Array& getTermList() const;
  
/*
Function: 	operator ()
Member Type:	Facilitator
Description: 	Evaluate the polynomial for variable x
Parameters: 	x 	- input - variable that is standing for value of x
Returns:      	double	- fully evaluated polynomial value
*/

  double operator()(double x);
  
/*
Function: 	multiply
Member Type:	Mutator
Description: 	Multiply each coefficient by the scalar arg factor
Parameters: 	factor  - input - variable that is multiplying against all the coefficents
Returns:      	void
*/

  void operator *=(float factor);

/*
Function: 	add
Member Type:	Facilitator
Description: 	Add a term to the polynomial
Parameters: 	T  - input - the Term being added
Returns:      	true if the term is added, false otherwise
*/

  bool add(Term &T);
 
 private:
  Array termList;

};

/*
Function: 	operator >>
Description: 	Reads in a Term from a file
Parameters: 	ifstream    - input/output - the input stream
		Polynomial  - input        - holds add function
Returns:      	file 
*/

  ifstream &operator>> (ifstream &file, Polynomial &P);

/*
Function: 	operator <<
Description: 	Print a Polynomial to the screen
Parameters: 	ostream      - input/output - output stream
		Polynomial   - output       - The Polynomial to access termList array
Returns:        out
*/

  ostream &operator<< (ostream &out,const Polynomial &P);

#endif
