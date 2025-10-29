#ifndef EVENT_ACTION_HH
#define EVENT_ACTION_HH

#include "G4UserEventAction.hh"
#include "G4Event.hh"
#include "RunAction.hh"

class EventAction : public G4UserEventAction{

	public :
		EventAction(RunAction *);
		~EventAction();
		virtual void BeginOfEventAction(const G4Event *);
		virtual void EndOfEventAction(const G4Event *);
		void SumarEnergiaDep(G4double EnergyDepByStep){
			if (EnergyDepByStep>0){		
				TotalEnergyDep += EnergyDepByStep;	
			}};
	private:
		G4double TotalEnergyDep;
};

#endif
