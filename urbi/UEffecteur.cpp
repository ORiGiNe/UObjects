#include "UEffecteur.hh"

// Register the UObject in the Urbi world. 
UStart(UEffecteur); 
 

UEffecteur::UEffecteur(const std::string& name) : urbi::UObject(name) {
	// Register the Urbi constructor.  
	// This is the only mandatory part of the C++ constructor.
	UBindFunction(UEffecteur, init); 
}

/*UEffecteur::~UEffecteur() {
	 effecteur;
}*/
 
int UEffecteur::init(int odid, UObject* g) {
	// Bind the functions, i.e., declare them to the Urbi world
	// LOCK_INSTANCE Prevent parallel call to any function of this object.. 
	UBindThreadedFunction(UEffecteur, set, urbi::LOCK_INSTANCE);
	
	effecteur = new Effecteur (odid);
	UGaop* ugaop = dynamic_cast<UGaop*>(g);
	ugaop->add(effecteur);
	return 0; 
}

bool UEffecteur::set(int valeur) {
	return effecteur->set(valeur);
}
