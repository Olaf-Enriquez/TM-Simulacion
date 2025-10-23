#include "SensitiveDetector.hh"

SensitiveDetector::SensitiveDetector(G4String NombreSensor):G4VSensitiveDetector(NombreSensor){

	TotalEnergyDep = 0. ;

}
SensitiveDetector::~SensitiveDetector(){}


void SensitiveDetector::Initialize(G4HCofThisEvent *){

	TotalEnergyDep = 0. ;

}

void SensitiveDetector::EndOfEvent(G4HCofThisEvent *){

	G4cout << "Energia depositada: " << TotalEnergyDep << G4endl;
	auto AnalysisManager = G4AnalysisManager::Instance();
	AnalysisManager -> FillH1(0, TotalEnergyDep);
}


G4bool SensitiveDetector::ProcessHits(G4Step *Step, G4TouchableHistory *){

	PreStep = Step -> GetPreStepPoint();
	EnergyDepByStep = Step -> GetTotalEnergyDeposit();
	if (EnergyDepByStep>0){
		
		TotalEnergyDep += EnergyDepByStep;
	
	}
	
	EventID = G4RunManager::GetRunManager() -> GetCurrentEvent() -> GetEventID();
	auto AnalysisManager = G4AnalysisManager::Instance();
	GlobalTime = PreStep-> GetGlobalTime();
	PhotonPos = PreStep -> GetPosition();
	PhotonMom = PreStep -> GetMomentum();
	MomentumMagPhoton = PhotonMom.mag();
	Wavelength = (1.2398411939 *eV/MomentumMagPhoton)*1E+03;
	AnalysisManager -> FillNtupleIColumn(0, 0, EventID);//FillNtupleIColumn(Tupla ID, Columna, Data)
	AnalysisManager -> FillNtupleDColumn(0, 1, GlobalTime);
	AnalysisManager -> FillNtupleDColumn(0, 2, PhotonPos[0]);
	AnalysisManager -> FillNtupleDColumn(0, 3, PhotonPos[1]);
	AnalysisManager -> FillNtupleDColumn(0, 4, PhotonPos[2]);
	AnalysisManager -> FillNtupleDColumn(0, 5, Wavelength);
	AnalysisManager -> AddNtupleRow(0);
	return true;
}
