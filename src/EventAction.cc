#include "EventAction.hh"

EventAction::EventAction(RunAction *){
	TotalEnergyDep=0;
}

EventAction::~EventAction(){}

void EventAction::BeginOfEventAction(const G4Event *){
	TotalEnergyDep =0;	
}

void EventAction::EndOfEventAction(const G4Event *){

	G4cout << "Energia depositada: " << TotalEnergyDep << G4endl;
	auto AnalysisManager = G4AnalysisManager::Instance();
	AnalysisManager -> FillNtupleDColumn(1,0,TotalEnergyDep);
	AnalysisManager -> AddNtupleRow(1);

}
