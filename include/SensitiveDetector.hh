#ifndef SENSITIVE_DETECTOR_HH
#define SENSITIVE_DETECTOR_HH

#include "G4VSensitiveDetector.hh"
#include "G4SystemOfUnits.hh"
#include "G4RunManager.hh"
#include "G4AnalysisManager.hh"
#include "G4UnitsTable.hh"

class SensitiveDetector : public G4VSensitiveDetector{

public : 

	SensitiveDetector(G4String);
	~SensitiveDetector();

private :

	G4double TotalEnergyDep, EnergyDepByStep, GlobalTime, MomentumMagPhoton, Wavelength;
	G4ThreeVector PhotonPos, PhotonMom;
	G4int EventID;

	virtual void Initialize(G4HCofThisEvent *) override;
	virtual void EndOfEvent(G4HCofThisEvent *) override;
	virtual G4bool ProcessHits(G4Step *, G4TouchableHistory *);
	G4StepPoint *PreStep;
};

#endif
