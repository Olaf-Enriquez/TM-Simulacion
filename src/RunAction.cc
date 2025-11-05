#include "RunAction.hh"

RunAction::RunAction(){

	auto AnalysisManager = G4AnalysisManager::Instance();
	AnalysisManager -> CreateH1("Histo","Ejemplo",10,0,100);//Histograma1D("nombre","Titulo",#bins,min dbl,max dbl)
	AnalysisManager -> CreateNtuple("Tupla","Ejemplo2");//Tupla("nombre","Titulo")
	AnalysisManager -> CreateNtupleIColumn("EventIDEjemplo2");///Integers("nombre") 1ra col Tupla
	AnalysisManager -> CreateNtupleDColumn("GTimeEjemplo2");
	AnalysisManager -> CreateNtupleDColumn("PosXEjemplo2");///Doubles("nombre") 2da col Tupla
	AnalysisManager -> CreateNtupleDColumn("PosYEjemplo2");
	AnalysisManager -> CreateNtupleDColumn("PosZEjemplo2");
	AnalysisManager -> CreateNtupleDColumn("WLEjemplo2");
	AnalysisManager -> FinishNtuple(0);//No siempre es 0, depende del numero de tupla
	AnalysisManager -> CreateNtuple("Tupla2","Eficiencia Cuantica");
	AnalysisManager -> CreateNtupleIColumn("EventIDEffCuantica");///Integers("nombre") 1ra col Tupla
	AnalysisManager -> CreateNtupleDColumn("PosXEffCuantica");///Doubles("nombre") 2da col Tupla
	AnalysisManager -> CreateNtupleDColumn("PosYEffCuantica");///Doubles("nombre") 2da col Tupla
	AnalysisManager -> CreateNtupleDColumn("PosZEffCuantica");///Doubles("nombre") 2da col Tupla
	AnalysisManager -> FinishNtuple(1);//Depende del numero de tupla

};

RunAction::~RunAction(){};

void RunAction::BeginOfRunAction(const G4Run *SimulacionRun){

	auto AnalysisManager = G4AnalysisManager::Instance();
	RunID = SimulacionRun -> GetRunID();
	std::stringstream RunIDString;
	RunIDString << RunID; //Pasar IDs a strings
	AnalysisManager -> OpenFile("ResultadoSim_"+RunIDString.str()+".root");//Abre archivo para data

};

void RunAction::EndOfRunAction(const G4Run *SimulacionRun){

	auto AnalysisManager = G4AnalysisManager::Instance();
	AnalysisManager -> Write();//Guarda data en archivo abierto
	AnalysisManager -> CloseFile();//Cerrar
	RunID = SimulacionRun -> GetRunID();
	G4cout << "Terminando simulacion: " << RunID << G4endl;//Print RunID
	

};
