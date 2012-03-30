#ifndef UTEST_HH 
#define UTEST_HH 

// Include the UObject declarations. 
#include <urbi/uobject.hh> 

#include <iostream>

// include custom lib
#include "Effecteur.h"
#include "UGaop.hh"

// A UObject wrapping a custom object. 
class UEffecteur : public urbi::UObject
{ 
	public: 
		// C++ contructor. 
		// @param name  name given to the instance. 
		UEffecteur(const std::string& name);
	        //~UEffecteur();	

		// Urbi constructor. 
		int init(int odid, UObject* g); 

		bool set(int valeur);

	protected:
		Effecteur* effecteur;
}; 
#endif // ! UTEST_HH 
