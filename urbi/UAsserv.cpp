#include "UAsserv.hh"

// Register the UObject in the Urbi world. 
UStart(UAsserv); 
 

UAsserv::UAsserv(const std::string& name) : urbi::UObject(name) {
	// Register the Urbi constructor.  
	// This is the only mandatory part of the C++ constructor.
	UBindFunction(UAsserv, init); 
}

/*UAsserv::~UAsserv() {
	 effecteur;
}*/
 
int UAsserv::init(int odid, UObject* g) {
	// Bind the functions, i.e., declare them to the Urbi world
	// LOCK_INSTANCE Prevent parallel call to any function of this object.. 
	UBindThreadedFunction(UAsserv, avancer, urbi::LOCK_INSTANCE);
	UBindThreadedFunction(UAsserv, tourner, urbi::LOCK_INSTANCE);
	UBindThreadedFunction(UAsserv, arreter, urbi::LOCK_INSTANCE);
	
	asserv = new Asserv (odid);
	UGaop* ugaop = dynamic_cast<UGaop*>(g);
	ugaop->add(asserv);
	return 0; 
}

int UAsserv::avancer(int vitesse) {
	asserv->avancer(vitesse,0,0);
}

void UAsserv::tourner(int angle) {
  asserv->tourner(180*angle/50,0,0);
}

int UAsserv::arreter() {
	asserv->arreter();
}
