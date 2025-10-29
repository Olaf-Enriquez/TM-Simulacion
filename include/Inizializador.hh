#ifndef INIZIALIZADOR_HH	//Definir Constructor
#define INIZIALIZADOR_HH

#include "G4VUserActionInitialization.hh"
#include "Generador.hh"
#include "Stepping.hh"
#include "EventAction.hh"
#include "RunAction.hh"

class action : public G4VUserActionInitialization
{
	public : 
		action();//Constructor
		~action();//Destructor
		virtual void BuildForMaster() const;
		virtual void Build() const;
};

#endif
