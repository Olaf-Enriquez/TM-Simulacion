#include <iostream>
//Clases requeridas para main
#include "G4RunManager.hh"
#include "G4MTRunManager.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
//Clases definida por el usuario
#include "PhysList.hh"
#include "Construccion.hh"
#include "Inizializador.hh"

int main(int argc, char** argv)
{	
	#ifdef G4MULTITHREADED	//Definir RunManager (MT o no)
		G4MTRunManager *RunManager = new G4MTRunManager;
	#else
		G4RunManager *RunManager = new G4RunManager;
	#endif

	RunManager->SetUserInitialization(new PhysList());//Incluir el PhysList
	RunManager->SetUserInitialization(new Construccion());//Incluir la construccion
	RunManager->SetUserInitialization(new action());//Incluir inizializacion
	
	G4UIExecutive *UIExecutive = new G4UIExecutive(argc, argv);
	G4UImanager *UImanager = G4UImanager::GetUIpointer();
	
	G4VisManager *VisManager = new G4VisExecutive();
	VisManager->Initialize();
	
	UImanager->ApplyCommand("/control/execute Visualizar.mac");//Aplicar macros de visualización
	UIExecutive->SessionStart();
	
	return 0;
	
}
