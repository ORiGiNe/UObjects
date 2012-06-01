#ifndef UPATHFINDING_HH 
#define UPATHFINDING_HH 

// Include the UObject declarations. 
#include <urbi/uobject.hh> 

#include <iostream>

// include custom lib
#include "UGaop.hh"

// A UObject wrapping a custom object. 
class UPathFind : public urbi::UObject
{ 
         public:
              	// C++ contructor. 
		// @param name  name given to the instance. 
                UPathFind(const std::string& name);
                //~UPathFind();

                // Urbi constructor
  int init ( string id);
  list::list std::vector calculate (Map map);

};

#endif // ! UPATHFINDING_HH 
