#include "Generador.hh"

generador_primario::generador_primario(){ //Constructor

Gun = new G4ParticleGun(1);
GunX = 0. *m;//Coordenadas gun
GunY = 3. *m;
GunZ = 0. *m;
MomX = 0.;//Momentos Gun
MomY = -1.;
MomZ = 0.;

G4ThreeVector GunPosition(GunX, GunY, GunZ);//PosicionGun
G4ThreeVector GunMomentum(MomX, MomY, MomZ);//MomentoGun

G4ParticleTable *ParticleTable = G4ParticleTable::GetParticleTable();
G4ParticleDefinition *ParticleDef = ParticleTable -> FindParticle("e-");
//Definir propiedades del Gun
Gun -> SetParticlePosition(GunPosition);
Gun -> SetParticleMomentumDirection(GunMomentum);
Gun -> SetParticleEnergy(100 *MeV);
Gun -> SetParticleDefinition(ParticleDef);

}

generador_primario::~generador_primario(){ //Destructor

delete Gun;

}

void generador_primario::GeneratePrimaries(G4Event *Evento){

Gun -> GeneratePrimaryVertex(Evento);

}
