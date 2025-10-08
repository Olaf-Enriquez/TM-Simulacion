#ifndef PHYSLIST_HH
#define PHYSLIST_HH

#include "G4VModularPhysicsList.hh"
#include "G4EmStandardPhysics.hh"

class PhysList : public G4VModularPhysicsList
{
	public : 
		PhysList();//Constructor
		~PhysList();//Destructor
};

#endif
