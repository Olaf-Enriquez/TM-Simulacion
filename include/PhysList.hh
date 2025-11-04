#ifndef PHYSLIST_HH
#define PHYSLIST_HH

#include "G4VModularPhysicsList.hh"
#include "G4EmStandardPhysics.hh"
#include "G4OpticalPhysics.hh"
#include "G4DecayPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"
//#include ".hh"

class PhysList : public G4VModularPhysicsList
{
		public : 
		PhysList();//Constructor
		~PhysList();//Destructor
};

#endif
