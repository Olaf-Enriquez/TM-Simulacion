#ifndef GENERADOR_HH	//Definir Constructor
#define GENRADOR_HH

#include "G4VUserPrimaryGeneratorAction.hh" //Clase base (generador de eventos "particulas")
//Definición de partículas y sus propiedades
#include "G4ParticleDefinition.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"

class generador_primario : public G4VUserPrimaryGeneratorAction{

	public : 
		generador_primario();//Constructor
		~generador_primario();//Destructor
		virtual void GeneratePrimaries(G4Event *);
	private :
		G4double GunX, GunY, GunZ, MomX, MomY, MomZ; //Coordenadas y momento de "pistola" de particulas
		G4ParticleGun *Gun;
		G4ParticleTable *Table;

};

#endif
