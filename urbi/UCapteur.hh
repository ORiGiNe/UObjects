#ifndef UTEST_HH 
#define UTEST_HH 

// Include the UObject declarations. 
#include <urbi/uobject.hh> 

#include <iostream>

// include custom lib
#include "Capteur.h"
#include "UGaop.hh"

// A UObject wrapping a custom object. 
class UCapteur : public urbi::UObject
{ 
	public: 
		// C++ contructor. 
		// @param name  name given to the instance. 
		UCapteur(const std::string& name);
	        //~UCapteur();	

		// Urbi constructor. 
		int init(int odid, UObject* g); 

		int get();

	protected:
		Capteur* capteur;
}; 
#endif // ! UTEST_HH 
