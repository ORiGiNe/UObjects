#include "UCapteur.hh"

// Register the UObject in the Urbi world. 
UStart(UCapteur); 
 

UCapteur::UCapteur(const std::string& name) : urbi::UObject(name) {
	// Register the Urbi constructor.  
	// This is the only mandatory part of the C++ constructor.
	UBindFunction(UCapteur, init); 
}

/*UCapteur::~UCapteur() {
	 capteur;
}*/
 
int UCapteur::init(int odid, UObject* g) {
	// Bind the functions, i.e., declare them to the Urbi world
	// LOCK_INSTANCE Prevent parallel call to any function of this object.. 
	UBindThreadedFunction(UCapteur, get, urbi::LOCK_INSTANCE);
	
	capteur = new Capteur (odid);
	UGaop* ugaop = dynamic_cast<UGaop*>(g);
	ugaop->add(capteur);
	return 0; 
}

int UCapteur::get() {
	return capteur->get();
}
