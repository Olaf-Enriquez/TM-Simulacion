#ifndef STEPPING_HH
#define STEPPING_HH

#include "G4UserSteppingAction.hh"
#include "G4Step.hh"
#include "Construccion.hh"
#include "EventAction.hh"
#include "G4RunManager.hh"
class  SteppingAction: public G4UserSteppingAction{

	public:
		SteppingAction(EventAction *SteppingEventAction);
		~SteppingAction();
		virtual void UserSteppingAction(const G4Step *);
	private:
		EventAction *SteppingEvent;
		G4double EnergyDepByStep;
		

};

#endif
