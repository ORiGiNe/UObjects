#ifndef UTEST_HH 
#define UTEST_HH 

// Include the UObject declarations. 
#include <urbi/uobject.hh> 

#include <iostream>

// include custom lib
#include "Asserv.h"
#include "UGaop.hh"

// A UObject wrapping a custom object. 
class UAsserv : public urbi::UObject
{ 
	public: 
		// C++ contructor. 
		// @param name  name given to the instance. 
		UAsserv(const std::string& name);
	        //~UAsserv();	

		// Urbi constructor. 
		int init(int odid, UObject* g); 

		int avancer(int vitesse);
		void tourner(int angle);
		int arreter();

	protected:
		Asserv* asserv;
}; 
#endif // ! UTEST_HH 
