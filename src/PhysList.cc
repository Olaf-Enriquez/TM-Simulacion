#include "PhysList.hh"

PhysList::PhysList() //Incluir constructor
{
	RegisterPhysics(new G4EmStandardPhysics());
	RegisterPhysics(new G4OpticalPhysics());
	RegisterPhysics(new G4DecayPhysics());
	RegisterPhysics(new G4RadioactiveDecayPhysics());
	
}

PhysList::~PhysList() //Incluir destructor
{
}
