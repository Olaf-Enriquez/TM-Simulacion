#include "Stepping.hh"

SteppingAction::SteppingAction(EventAction *SteppingEventAction){
	SteppingEvent = SteppingEventAction;
}

SteppingAction::~SteppingAction(){}

void SteppingAction::UserSteppingAction(const G4Step *Step){
	EnergyDepByStep = Step -> GetTotalEnergyDeposit();
	SteppingEvent -> SumarEnergiaDep(EnergyDepByStep);
	G4LogicalVolume *StepVolume = Step-> GetPreStepPoint() -> GetTouchableHandle() -> GetVolume() -> GetLogicalVolume();
	const Construccion *ConstruccionExistente = static_cast < const Construccion* > (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
	G4LogicalVolume *ScoreVolume = ConstruccionExistente -> GetScoringVolume();
	if(StepVolume != ScoreVolume);
		return;
}
