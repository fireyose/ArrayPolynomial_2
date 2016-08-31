// Author:              Youssef Almkari
// Course:              CSC136
// Assignment:          Project 2
// Filename:            poly.cpp
// Purpose:             Implementation of Class poly
//                      Produce an interface that handles polynomials
//
//**UPDATE**:		The Polynomial Class now handles Arrays which handle specific Terms.
//			Access to Terms now can only be done through termList of type Array.

#include "poly.h"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

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

  Polynomial::Polynomial()
  {}

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

  void Polynomial::setTerm(int index, double co, int ex)
  { termList[index].setCoefficient (co);
    termList[index].setExponent (ex);
  }
  
/*
Function: 	setCoeff
Member Type:	Mutator
Description: 	Sets the coefficient for a term in the variable at a specific index
Parameters: 	int index - input - the index at which the values are stored
		float co  - input - the coefficient for the user
Returns:      	void
*/ 

  void Polynomial::setCoeff(int index, double co)
  { termList[index].setCoefficient (co); }
  
/*
Function: 	setExponent
Member Type:	Mutator
Description: 	Sets the exponent for the term in the variable at a specific index
Parameters: 	int index - input - the index at which the values are stored
		int ex    - input - the exponent for the user
Returns:      	void
*/

  void Polynomial::setExponent(int index, int ex)
  { termList[index].setExponent (ex); }
  
  // Gets

/*
Function: 	getTerm
Member Type:	Inspector
Description: 	Gives the user the values associated with the terms at the index
Parameters: 	int index - input - the index at which the values are stored
Returns:        Term 	  - from requested index
*/

  Term Polynomial::getTerm(int index) const
  { return (termList[index].getExponent()); }

/*
Function: 	getCoeff
Member Type:	Inspector
Description: 	Gets the user the coefficient at a certain index
Parameters: 	int index - input - the index at which the values are stored
Returns:        double	  - coefficient from requested index
*/

  double Polynomial::getCoeff(int index) const
  { return (termList[index].getCoefficient()); }

/*
Function: 	getExponent
Member Type:	Inspector
Description:  	Gets the user the exponent for a certain index
Parameters: 	int index - input - the index at which the values are stored
Returns:      	int	  - exponent from requested index
*/

  int Polynomial::getExponent(int index) const
  { return (termList[index].getExponent()); }

/*
Function: 	getTermList
Member Type:	Inspector
Description:  	returns object ternList to be used with  outside class scope functions
Parameters: 	none
Returns:      	Array termList
*/

  const Array& Polynomial::getTermList() const
  { return (termList); }
  
/*
Function: 	operator ()
Member Type:	Facilitator
Description: 	Evaluate the polynomial for variable x
Parameters: 	x 	- input - variable that is standing for value of x
Returns:      	double	- fully evaluated polynomial value
*/

  double Polynomial::operator()(double x)
  { double total = 0;
    for (int i = 0; i < termList.getEltsInUse(); i++)
      total = total + termList[i](x);
    return total;
  }
  
/*
Function: 	multiply
Member Type:	Mutator
Description: 	Multiply each coefficient by the scalar arg factor
Parameters: 	factor  - input - variable that is multiplying against all the coefficents
Returns:      	void
*/

  void Polynomial::operator *=(float factor)
  { for (int i = 0; i < termList.getEltsInUse(); i++)
      termList[i]*= factor;
  }

/*
Function: 	add
Member Type:	Mutator
Description: 	Add a term to the polynomial
Parameters: 	T  - input - the Term being added
Returns:      	true if the term is added, false otherwise
*/

  bool Polynomial::add(Term &T)
  { return (termList.addTerm (T)); }
  
/*
Function: 	operator >>
Description: 	Reads in a Term from a file
Parameters: 	ifstream    - input/output - the input stream
		Polynomial  - input        - holds add function
Returns:      	file 
*/

  ifstream &operator>>(ifstream &file, Polynomial &P)
  { Term aTerm;
    while (file >> aTerm)
      P.add(aTerm);
    file.close();
    return(file);
  }

/*
Function: 	operator <<
Description: 	Print a Polynomial to the screen
Parameters: 	ostream      - input/output - output stream
		Polynomial   - output       - The Polynomial to access termList array
Returns:        out
*/

  ostream &operator<<(ostream &out,const Polynomial &P)
  { out << P.getTermList();
    return out;
  }

  
