#include "PhysList.hh"

PhysList::PhysList() //Incluir constructor
{
	RegisterPhysics(new G4EmStandardPhysics());
}

PhysList::~PhysList() //Incluir destructor
{
}
