#include "Construccion.hh"
Construccion::Construccion(){}
Construccion::~Construccion(){}
G4VPhysicalVolume *Construccion::Construct()
{
	CheckTraslapes=true;
	G4NistManager *Nist=G4NistManager::Instance();
	EnergiaALongitud = 1.239841939 *eV;
	Energia = {EnergiaALongitud/0.52,EnergiaALongitud/0.5,EnergiaALongitud/0.48,EnergiaALongitud/0.46,EnergiaALongitud/0.44,EnergiaALongitud/0.42,EnergiaALongitud/0.4};//Tesis Karl
	//G4double Energia[6]={EnergiaALongitud/0.9,EnergiaALongitud/0.8,EnergiaALongitud/0.7,EnergiaALongitud/0.6,EnergiaALongitud/0.5,EnergiaALongitud/0.4,EnergiaALongitud/0.3}	
	
////////Elementos

	G4Element* elFe = Nist->FindOrBuildElement("Fe");//Definir elemento Hierro
	G4Element* elC = Nist->FindOrBuildElement("C");;//Definir elemento Carbono
	G4Element* elF = Nist->FindOrBuildElement("F");;//Definir elemento Fluor
	G4Element* elB = Nist->FindOrBuildElement("B");;//Definir elemento Boro
	G4Element* elO = Nist->FindOrBuildElement("O");;//Definir elemento Oxígeno
	G4Element* elN = Nist->FindOrBuildElement("N");;//Definir elemento Nitrógeno
	G4Element* elH = Nist->FindOrBuildElement("H");;//Definir elemento Hidrogeno
	G4Element* elSi = Nist->FindOrBuildElement("Si");;//Definir elemento Silico
	G4Element* elNa = Nist->FindOrBuildElement("Na");;//Definir elemento Sodio
	G4Element* elK = Nist->FindOrBuildElement("K");;//Definir elemento Potasio
	G4Element* elCa = Nist->FindOrBuildElement("Ca");;//Definir elemento Calcio
	G4Element* elAl = Nist->FindOrBuildElement("Al");;//Definir elemento Aluminio

////////Mundo
	
	MaterialMundo=Nist->FindOrBuildMaterial("G4_AIR");//Material Mundo
	PropiedadesMundo = new G4MaterialPropertiesTable();
	RefraccionMundo = {1.0,1.0,1.0,1.0,1.0,1.0,1.0};
	PropiedadesMundo -> AddProperty("RINDEX", Energia, RefraccionMundo, 2);//(Etiqueta indice, rango de enrgia, indices en rango, #argumentos)
	MaterialMundo->SetMaterialPropertiesTable(PropiedadesMundo);
	CoorX=4. *m;//Tamaño mundo
	CoorY=6. *m;
	CoorZ=4. *m;
	MundoSolido=new G4Box("MundoSolido", 0.5*CoorX, 0.5*CoorY, 0.5*CoorZ); //Cajita de mundo
	MundoLogico=new G4LogicalVolume(MundoSolido, MaterialMundo, "MundoLogico"); //Lógica de mundo
	MundoFisico=new G4PVPlacement(0,G4ThreeVector(0.,0.,0.),MundoLogico, "MundoFisico", 0,false, 0, CheckTraslapes); 
	//G4PVPlacement(rotacion,3D pos vector, volumen logico, nombre, nivel de volumen,devolver booleano, # de replica, CheckTraslapes)
	
////////Soporte de acero	
	
	G4Material *Acero =new G4Material("Acero", 7.9 *g/cm3, 2);//Definir Acero (Etiqueta, densidad, No de elementos)
	Acero->AddElement(elFe, 80*perCent);//Definir composicion para acero
	Acero->AddElement(elC, 20*perCent);
	AtributosAcero=new G4VisAttributes(G4Color(169,169,169,1));
	AtributosAcero->SetForceSolid(true);
	AceroX=3.15*m;//Tamaño Acero
	AceroY=0.245*m;
	AceroZ=2.225*m;
	AceroSolido=new G4Box("AceroSolido", 0.5*AceroX, 0.5*AceroY, 0.5*AceroZ); //Cajita de Acero
	AceroLogico=new G4LogicalVolume(AceroSolido, Acero, "AceroLogico"); //Lógica de Acero
	AceroLogico->SetVisAttributes(AtributosAcero);
	AceroFisico=new G4PVPlacement(0,G4ThreeVector(0.,0.0175 *m,0.),AceroLogico, "AceroFisico", MundoLogico, false, 0, CheckTraslapes);

////////Reflector 6NM64
	
	MaterialReflector=Nist->FindOrBuildMaterial("G4_POLYETHYLENE");//Material reflector
	AtributosReflector=new G4VisAttributes(G4Color(255, 232, 65,0.8));
	AtributosReflector->SetForceSolid(true);
	ReflectorX=3.15*m;//Tamaño Reflector
	ReflectorY=0.52*m;
	ReflectorZ=2.225*m;
	ReflectorSolido=new G4Box("ReflectorSolido", 0.5*ReflectorX, 0.5*ReflectorY, 0.5*ReflectorZ); //Cajita de Reflector
	ReflectorLogico=new G4LogicalVolume(ReflectorSolido, MaterialReflector, "ReflectorLogico"); //Lógica de Reflector
	ReflectorLogico->SetVisAttributes(AtributosReflector);
	ReflectorFisico=new G4PVPlacement(0,G4ThreeVector(0.,0.4 *m,0.),ReflectorLogico, "ReflectorFisico", MundoLogico, false, 0, CheckTraslapes);
	
////////Interior 6nm64

	MaterialIntnm=Nist->FindOrBuildMaterial("G4_AIR");//Material interior
	IntnmX=3.05*m;//Tamaño Intnm
	IntnmY=0.42*m;
	IntnmZ=2.125*m;
	IntnmSolido=new G4Box("IntnmSolido", 0.5*IntnmX, 0.5*IntnmY, 0.5*IntnmZ); //Cajita de Intnm
	IntnmLogico=new G4LogicalVolume(IntnmSolido, MaterialIntnm, "IntnmLogico"); //Lógica de Intnm
	IntnmFisico=new G4PVPlacement(0,G4ThreeVector(0.,0.4 *m,0.),IntnmLogico, "IntnmFisico", MundoLogico, false, 0, CheckTraslapes);

////////Productor 6nm64
	MaterialProductor=Nist->FindOrBuildMaterial("G4_Pb");//Material productor
//Placas horizontales (en medio)
	ProductorPlacaX=0.24*m;//Tamaño ProductorPlaca
	ProductorPlacaY=0.15*m;
	ProductorPlacaZ=2.125*m;
	ProductorPlacaSolido=new G4Box("ProductorPlacaSolido", 0.5*ProductorPlacaX, 0.5*ProductorPlacaY, 0.5*ProductorPlacaZ); //Cajita de ProductorPlaca
	ProductorPlacaLogico=new G4LogicalVolume(ProductorPlacaSolido, MaterialProductor, "ProductorPlacaLogico"); //Lógica de ProductorPlaca
	for(G4int i=0; i<5; i++){
		ProductorPlacaFisico=new G4PVPlacement(0,G4ThreeVector(-1.0 *m + i*0.5 *m,0.4 *m,0.),ProductorPlacaLogico, "ProductorPlacaFisico", MundoLogico, false, i, CheckTraslapes);
		};
//Placas extremos
	ProductorPlacaX2=0.145*m;
	ProductorPlacaSolido2=new G4Box("ProductorPlacaSolido2", 0.5*ProductorPlacaX2, 0.5*ProductorPlacaY, 0.5*ProductorPlacaZ); //Cajita de ProductorPlaca
	ProductorPlacaLogico2=new G4LogicalVolume(ProductorPlacaSolido2, MaterialProductor, "ProductorPlacaLogico2"); //Lógica de ProductorPlaca
	for(G4int i=0; i<2; i++){
		ProductorPlacaFisico2=new G4PVPlacement(0,G4ThreeVector(-1.452 *m + i*2.905 *m,0.4 *m,0.),ProductorPlacaLogico2, "ProductorPlacaFisico2", MundoLogico, false, i, CheckTraslapes);
		};
//Cilindros
	RadInProductorTubo=0.23*m;//Tamaño ProductorPlaca
	RadExProductorTubo=0.245*m;
	HZProductorTubo=1.062*m;//Medio largo del tubo
	AnguloInicialProductorTubo=0. *deg;
	AnguloArcoProductorTubo=360. *deg;
	ProductorTuboSolido=new G4Tubs("ProductorTuboSolido", 0.5*RadInProductorTubo, 0.5*RadExProductorTubo, HZProductorTubo, AnguloInicialProductorTubo, AnguloArcoProductorTubo);
	ProductorTuboLogico=new G4LogicalVolume(ProductorTuboSolido, MaterialProductor, "ProductorTuboLogico"); //Lógica de ProductorTubo
	for(G4int i=0; i<6; i++){	
		ProductorTuboFisico=new G4PVPlacement(0,G4ThreeVector(-1.25 *m +i*0.5 *m,0.4 *m,0.),ProductorTuboLogico, "ProductorTuboFisico", MundoLogico, false, i, CheckTraslapes);
		};

////////Moderador 6nm64
	
	RadInModerador=0.225*m;//Tamaño ProductorPlaca
	RadExModerador=0.244*m;
	HZModerador=1.062*m;
	AnguloInicialModerador=0. *deg;
	AnguloArcoModerador=360. *deg;
	ModeradorSolido=new G4Tubs("ModeradorSolido", 0.5*RadInModerador, 0.5*RadExModerador, HZModerador, AnguloInicialModerador, AnguloArcoModerador);
	ModeradorLogico=new G4LogicalVolume(ModeradorSolido, MaterialReflector, "ModeradorLogico"); //Lógica de Moderador
	for(G4int i=0; i<6; i++){	
		ModeradorFisico=new G4PVPlacement(0,G4ThreeVector(-1.25 *m +i*0.5 *m,0.4 *m,0.),ModeradorLogico, "ModeradorFisico", MundoLogico, false, i, CheckTraslapes);
		};

////////Contadores proporcionales 6nm64
////Contenedor
//Tubo
	RadInContenedor=0.216*m;//Tamaño Contenedores Tubos
	RadExContenedor=0.225*m;
	HZContenedor=1.052*m;
	AnguloInicialContenedor=0. *deg;
	AnguloArcoContenedor=360. *deg;
	ContenedorSolido=new G4Tubs("ContenedorSolido", 0.5*RadInContenedor, 0.5*RadExContenedor, HZContenedor, AnguloInicialContenedor, AnguloArcoContenedor);
	ContenedorLogico=new G4LogicalVolume(ContenedorSolido, Acero, "ContenedorLogico"); //Lógica de Contenedor
	for(G4int i=0; i<6; i++){	
		ContenedorFisico=new G4PVPlacement(0,G4ThreeVector(-1.25 *m +i*0.5 *m,0.4 *m,0.),ContenedorLogico, "ContenedorFisico", MundoLogico, false, i, CheckTraslapes);
		};
//Tapas

	RadInContenedorTapas=0.*m;//Tamaño Contenedor Tapas
	RadExContenedorTapas=0.224*m;
	HZContenedorTapas=0.005*m;
	AnguloInicialContenedorTapas=0. *deg;
	AnguloArcoContenedorTapas=360. *deg;
	ContenedorTapasSolido=new G4Tubs("ContenedorTapasSolido", 0.5*RadInContenedorTapas, 0.5*RadExContenedorTapas, HZContenedorTapas, AnguloInicialContenedorTapas, AnguloArcoContenedorTapas);
	ContenedorTapasLogico=new G4LogicalVolume(ContenedorTapasSolido, Acero, "ContenedorTapasLogico"); //Lógica de ContenedorTapas
	for(G4int j=0; j<2; j++){
		for(G4int i=0; i<6; i++){	
		ContenedorTapasFisico=new G4PVPlacement(0,G4ThreeVector(-1.25 *m +i*0.5 *m,0.4 *m,1.057 *m - 2.114*j *m),ContenedorTapasLogico, "ContenedorTapasFisico", MundoLogico, false, i+j, CheckTraslapes);
		}};

//Tubo Trifluoruro De Boro

	G4Material *BF3 =new G4Material("BF3", 2.178 *g/cm3, 2);//Definir Trifloururo (Etiqueta, densidad, No de elementos)
	BF3->AddElement(elF, natoms=3);//Definir composicion para acero
	BF3->AddElement(elB, natoms=1);
	RadInTrifluoruro=0.*m;//Tamaño ProductorPlaca
	RadExTrifluoruro=0.216*m;
	HZTrifluoruro=0.955 *m;
	AnguloInicialTrifluoruro=0. *deg;
	AnguloArcoTrifluoruro=360. *deg;
	TrifluoruroSolido=new G4Tubs("TrifluoruroSolido", 0.5*RadInTrifluoruro, 0.5*RadExTrifluoruro, HZTrifluoruro, AnguloInicialTrifluoruro, AnguloArcoTrifluoruro);
	TrifluoruroLogico=new G4LogicalVolume(TrifluoruroSolido, BF3, "TrifluoruroLogico"); //Lógica de Trifluoruro
	for(G4int i=0; i<6; i++){	
		TrifluoruroFisico=new G4PVPlacement(0,G4ThreeVector(-1.25 *m +i*0.5 *m,0.4 *m,0.),TrifluoruroLogico, "TrifluoruroFisico", MundoLogico, false, i, CheckTraslapes);
		};
	
////////Tubos 6nm64

////////Bases Góndolas

	MaterialGondola=Nist->FindOrBuildMaterial("G4_Al");//Material reflector
	AtributosAluminio=new G4VisAttributes(G4Color(120,120,120,0.5));
	AtributosAluminio->SetForceSolid(true);
	GondolaX=1. *m;
	GondolaY=0.215 *m;
	GondolaZ=1. *m;
	GondolaGrosorX=0.01 *m;
	GondolaGrosorY=0.01 *m;
	GondolaGrosorZ=0.01 *m;
	GondolaSolido=new G4Box("GondolaSólido", 0.5*GondolaX, 0.5*GondolaY, 0.5*GondolaZ);
	GondolaLogico = new G4LogicalVolume(GondolaSolido, MaterialGondola, "GondolaLogico");
	GondolaIntSolido=new G4Box("GondolaIntSólido", 0.5*(GondolaX-GondolaGrosorX), 0.5*(GondolaY-0.5*GondolaGrosorY), 0.5*(GondolaZ-GondolaGrosorZ));
	GondolaIntLogico = new G4LogicalVolume(GondolaIntSolido, MaterialMundo, "GondolaIntLogico");
	GondolaLogico->SetVisAttributes(AtributosAluminio);
	for(G4int i=0; i<2; i++){
			for(G4int k=0; k<2; k++){
				GondolaFisico=new G4PVPlacement(0,G4ThreeVector(-0.25*ReflectorX + i*0.5*ReflectorX ,0.7678 *m,-0.25*ReflectorZ + k*0.5*ReflectorZ),GondolaLogico, "GondolaFisico", MundoLogico, false, i+k, CheckTraslapes);
				GondolaIntFisico=new G4PVPlacement(0,G4ThreeVector(0.,0.0025 *m,0.),GondolaIntLogico, "GondolaIntFisico", GondolaLogico, true, i+k, CheckTraslapes);
		}};
	for(G4int i=0; i<2; i++){
			for(G4int k=0; k<2; k++){
				GondolaFisico=new G4PVPlacement(0,G4ThreeVector(-0.25*ReflectorX + i*0.5*ReflectorX ,0.7678 *m -(ReflectorY+AceroY+0.2153*m),-0.25*ReflectorZ + k*0.5*ReflectorZ),GondolaLogico, "GondolaFisico", MundoLogico, false, -(i+k), CheckTraslapes);
				GondolaIntFisico=new G4PVPlacement(0,G4ThreeVector(0.,-0.002509 *m,0.),GondolaIntLogico, "GondolaFisico", GondolaLogico, true, -(i+k), CheckTraslapes);
		}};
///////Trapezoides Góndolas

	TrapX1= 1.0 *m;
	TrapX2= 0.2 *m;
	TrapY1= 1.0 *m;
	TrapY2= 0.2 *m;
	TrapZ= 0.763 *m;
	TrapSolido=new G4Trd("TrapSólido", 0.5*TrapX1, 0.5*TrapX2, 0.5*TrapY1, 0.5*TrapY2, 0.5*TrapZ);
	TrapLogico = new G4LogicalVolume(TrapSolido, MaterialGondola, "TrapLogico");
	TrapIntSolido=new G4Trd("TrapSólido", 0.5*(TrapX1-0.01 *m), 0.5*(TrapX2-0.01 *m), 0.5*(TrapY1-0.01 *m), 0.5*(TrapY2-0.01 *m), 0.5*(TrapZ));
	TrapIntLogico = new G4LogicalVolume(TrapIntSolido, MaterialMundo, "TrapIntLogico");
	TrapLogico->SetVisAttributes(AtributosAluminio);

	for(G4int i=0; i<2; i++){
			for(G4int k=0; k<2; k++){
				G4Rotate3D Rota(90.*deg, G4ThreeVector(1,0,0));
  				G4Translate3D Tras(G4ThreeVector(-0.25*ReflectorX + i*0.5*ReflectorX ,-0.25*ReflectorZ + k*0.5*ReflectorZ,0.7015 *m ));
  				G4Transform3D TransTrap = Rota*Tras;
				TrapFisico=new G4PVPlacement(TransTrap, TrapLogico, "TrapFisico", MundoLogico, false, i+k, CheckTraslapes);
				TrapIntFisico=new G4PVPlacement(0,G4ThreeVector(0.,0.,0),TrapIntLogico, "TrapIntFisico", TrapLogico, true, i+k, CheckTraslapes);
		}};
	for(G4int i=0; i<2; i++){
			for(G4int k=0; k<2; k++){
				G4Rotate3D Rota1(90.*deg, G4ThreeVector(-1,0,0));
  				G4Translate3D Tras1(G4ThreeVector(-0.25*ReflectorX + i*0.5*ReflectorX,-0.25*ReflectorZ + k*0.5*ReflectorZ, 0.7678 *m -(ReflectorY+AceroY+0.2153*m -1.46931*m)));
  				G4Transform3D TransTrap1 = Rota1*Tras1;
				TrapFisico=new G4PVPlacement(TransTrap1,TrapLogico, "TrapFisico", MundoLogico, false, -(i+k), CheckTraslapes);
				TrapIntFisico=new G4PVPlacement(0,G4ThreeVector(0.,0.,0.),TrapIntLogico, "TrapFisico", TrapLogico, true, -(i+k), CheckTraslapes);
		}};

///////Centelladores

	G4Material *Terfenilo =new G4Material("Terfenilo", 1.24 *g/cm3, 2);//Definir P-Terfenilo (Etiqueta, densidad, No de elementos)
	Terfenilo->AddElement(elC, natoms=18);//Definir composicion para P-Terfenilo
	Terfenilo->AddElement(elH, natoms=14);
	G4Material *POPOP =new G4Material("POPOP", 1.06 *g/cm3, 4);//Definir POPOP (Etiqueta, densidad, No de elementos)
	POPOP->AddElement(elC, natoms=24);//Definir composicion para POPOP
	POPOP->AddElement(elH, natoms=16);
	POPOP->AddElement(elN, natoms=2);
	POPOP->AddElement(elO, natoms=2);
	G4Material *PPO =new G4Material("PPO", 1.09 *g/cm3, 4);//Definir PPO (Etiqueta, densidad, No de elementos)
	PPO->AddElement(elC, natoms=24);//Definir composicion para PPO
	PPO->AddElement(elH, natoms=16);
	PPO->AddElement(elN, natoms=2);
	PPO->AddElement(elO, natoms=2);
	
	G4Material *MaterialCentellador =new G4Material("MaterialCentellador", 1.2 *g/cm3, 3);//Definir centellador (Etiqueta, densidad, No de elementos)
	MaterialCentellador->AddMaterial(Terfenilo, 98.5*perCent);//Definir composicion para Centellador
	MaterialCentellador->AddMaterial(PPO, 1*perCent);
	MaterialCentellador->AddMaterial(POPOP, 0.5*perCent);
	PropiedadesCentellador = new G4MaterialPropertiesTable();//Propiedades opticas centellador
	RefraccionCentellador = {1.581,1.581,1.581,1.581,1.581,1.581,1.581};
	FraccionCentellador = {1.0,1.0,1.0,1.0,1.0,1.0,1.0};
	ReflectividadCentellador = {1.0,1.0,1.0,1.0,1.0,1.0,1.0};
	PropiedadesCentellador-> AddProperty("RINDEX", Energia, RefraccionCentellador, 2);//(Etiqueta indice, rango de enrgia, indices en rango, #argumentos)
	PropiedadesCentellador-> AddProperty("SCINTILLATIONCOMPONENT1", Energia, FraccionCentellador, 2);
	PropiedadesCentellador-> AddProperty("RAYLEIGH", Energia, RefraccionCentellador, 2);
	PropiedadesCentellador-> AddConstProperty("RESOLUTIONSCALE", 1.0);
	PropiedadesCentellador-> AddConstProperty("SCINTILLATIONYIELD", 8000.0/MeV);
	PropiedadesCentellador-> AddConstProperty("SCINTILLATIONTIMECONSTANT1", 3.0 *ns);
	MaterialCentellador-> SetMaterialPropertiesTable(PropiedadesCentellador);
	MaterialCentellador-> GetIonisation() -> SetBirksConstant(0.0208 *cm/MeV);
	SuperficieCentellador =new G4OpticalSurface("SuperficieCentellador");//Propiedades superficie opticas centellador
	SuperficieCentellador->SetType(dielectric_dielectric);
	SuperficieCentellador->SetFinish(polished);
	SuperficieCentellador -> SetPolish(0.8);
	SuperficieCentellador->SetModel(glisur);
	PropiedadesCentelladorSup = new G4MaterialPropertiesTable();
	PropiedadesCentelladorSup -> AddProperty("REFLECTIVITY", Energia, ReflectividadCentellador);
	SuperficieCentellador->SetMaterialPropertiesTable(PropiedadesCentelladorSup);
	AtributosCentellador=new G4VisAttributes(G4Color(255,255,255,0.7));
	AtributosCentellador->SetForceSolid(true);
	
	CentelladorX=0.5*m;//Tamaño Centellador
	CentelladorY=0.05*m;
	CentelladorZ=0.5*m;
	CentelladorSolido=new G4Box("CentelladorSolido", 0.5*CentelladorX, 0.5*CentelladorY, 0.5*CentelladorZ); //Cajita de Centellador
	CentelladorLogico=new G4LogicalVolume(CentelladorSolido, MaterialCentellador, "CentelladorLogico"); //Lógica de Centellador
	CentelladorLogico->SetVisAttributes(AtributosCentellador);
	new G4LogicalSkinSurface("SuperficieCentelladorLogico", CentelladorLogico, SuperficieCentellador);//Activar superficie centellador
	for(G4int i=0; i<2; i++){	
		for(G4int j=0; j<2; j++){
			for(G4int k=0; k<2; k++){
				CentelladorFisico=new G4PVPlacement(0,G4ThreeVector(0. *m, 0. *m, 0. *m),CentelladorLogico, "CentelladorFisico", GondolaIntLogico, false, i+j+k, CheckTraslapes);
		}}};
	

///////Fotomultiplicadores
	
	/*G4Material *SiO2 =new G4Material("Silice", 2.634 *g/cm3, 3);//Definir Silice (Etiqueta, densidad, No de elementos)
	Silice->AddElement(Nist->FindOrBuildElement("Si"), natoms=1);//Definir composicion para Silice
	Silice->AddElement(Nist->FindOrBuildElement("O"), natoms=2);
	G4Material *B2O3 =new G4Material("OxidoBorico", 2.46 *g/cm3, 2);//Definir Oxido de Boro (Etiqueta, densidad, No de elementos)
	OxidoBorico->AddElement(elB, natoms=2);//Definir composicion para Oxido de Boro
	OxidoBorico->AddElement(elO, natoms=3);
	G4Material *Na2O =new G4Material("OxidoSodio", 2.49 *g/cm3, 2);//Definir Oxido de Sodio (Etiqueta, densidad, No de elementos)
	OxidoSodio->AddElement(elNa, natoms=2);//Definir composicion para Oxido de Sodio
	OxidoSodio->AddElement(elO, natoms=1);
	G4Material *K2O =new G4Material("OxidoPotasio", 2.32 *g/cm3, 2);//Definir Oxido de Sodio (Etiqueta, densidad, No de elementos)
	OxidoPotasio->AddElement(elK, natoms=2);//Definir composicion para Oxido de Sodio
	OxidoPotasio->AddElement(elO, natoms=1);
	G4Material *CaO =new G4Material("OxidoCalcio", 3.34 *g/cm3, 2);//Definir Oxido de Sodio (Etiqueta, densidad, No de elementos)
	OxidoCalcio->AddElement(elCa, natoms=1);//Definir composicion para Oxido de Sodio
	OxidoCalcio->AddElement(elO, natoms=1);
	G4Material *Al3O2 =new G4Material("OxidoAluminio", 3.987 *g/cm3, 2);//Definir Oxido de Sodio (Etiqueta, densidad, No de elementos)
	OxidoAluminio->AddElement(elAl, natoms=3);//Definir composicion para Oxido de Sodio
	OxidoAluminio->AddElement(elO, natoms=2);
	
	G4Material *Borosilicato =new G4Material("Borosilicato", 2.22 *g/cm3, 6);//Definir centellador (Etiqueta, densidad, No de elementos)
	Borosilicato->AddMaterial(Silice, 70*perCent);//Definir composicion para Centellador
	Borosilicato->AddMaterial(OxidoBorico, 10*perCent);
	Borosilicato->AddMaterial(OxidoSodio, 8*perCent);
	Borosilicato->AddMaterial(OxidoPotasio, 8*perCent);
	Borosilicato->AddMaterial(OxidoCalcio, 1*perCent);
	Borosilicato->AddMaterial(OxidoAluminio, 2*perCent);*/
	
	Pyrex=Nist->FindOrBuildMaterial("G4_Pyrex_Glass");//Material Mundo
	
	PMTRadIn=0.*m;//Tamaño Contenedor Tapas
	PMTRadExt=66.5*mm;
	PMTz=194.*mm;
	PMTAnguloIni=0. *deg;
	PMTAnguloArco=360. *deg;
	PMTSolido=new G4Tubs("PMTSolido", 0.5*PMTRadIn, 0.5*PMTRadExt, 0.5*PMTz, PMTAnguloIni, PMTAnguloArco);
	PMTLogico=new G4LogicalVolume(PMTSolido, Pyrex, "PMTLogico"); //Lógica de ContenedorTapas*/
	
	for(G4int i=0; i<2; i++){
			for(G4int k=0; k<2; k++){
				G4Rotate3D Rota2(90.*deg, G4ThreeVector(1,0,0));
  				G4Translate3D Tras2(G4ThreeVector(-0.25*ReflectorX + i*0.5*ReflectorX ,-0.25*ReflectorZ + k*0.5*ReflectorZ,1.18 *m ));
  				G4Transform3D TransTrap2 = Rota2*Tras2;
				PMTFisico=new G4PVPlacement(TransTrap2, PMTLogico, "-PMTFisico", MundoLogico, false, i+k, CheckTraslapes);
		}};
		
	for(G4int i=0; i<2; i++){
			for(G4int k=0; k<2; k++){
				G4Rotate3D Rota3(90.*deg, G4ThreeVector(-1,0,0));
  				G4Translate3D Tras3(G4ThreeVector(-0.25*ReflectorX + i*0.5*ReflectorX,-0.25*ReflectorZ + k*0.5*ReflectorZ, 1.5678 *m -(ReflectorY+AceroY-0.93251*m)));
  				G4Transform3D TransTrap3 = Rota3*Tras3;
				PMTFisico=new G4PVPlacement(TransTrap3,PMTLogico, "PMTFisico", MundoLogico, false, -(i+k), CheckTraslapes);
		}};
		
///////Tapas PMTs

	TapaPMTX=0.2 *m;
	TapaPMTY=0.01 *m;
	TapaPMTZ=0.2 *m;
	TapaPMTSolido=new G4Box("TapaPMTSólido", 0.5*TapaPMTX, 0.5*TapaPMTY, 0.5*TapaPMTZ);
	TapaPMTLogico = new G4LogicalVolume(TapaPMTSolido, MaterialGondola, "TapaPMTLogico");
	TapaPMTLogico->SetVisAttributes(AtributosAluminio);
	for(G4int i=0; i<2; i++){
			for(G4int k=0; k<2; k++){
				TapaPMTFisico=new G4PVPlacement(0,G4ThreeVector(-0.25*ReflectorX + i*0.5*ReflectorX ,1.83731 *m,-0.25*ReflectorZ + k*0.5*ReflectorZ),TapaPMTLogico, "TapaPMTFisico", 						MundoLogico, false, i+k, CheckTraslapes);
		}};
	for(G4int i=0; i<2; i++){
			for(G4int k=0; k<2; k++){
				TapaPMTFisico=new G4PVPlacement(0,G4ThreeVector(-0.25*ReflectorX + i*0.5*ReflectorX ,-0.3017 *m -(ReflectorY+AceroY+0.2153*m),-0.25*ReflectorZ + k*0.5*ReflectorZ),TapaPMTLogico, "TapaPMTFisico", MundoLogico, false, -(i+k), CheckTraslapes);
		}};
		
//////Paredes PMTs		
	
	/*TapaPMTX=0.2 *m;
	TapaPMTY=0.01 *m;
	TapaPMTZ=0.2 *m;
	TapaPMTSolido=new G4Box("TapaPMTSólido", 0.5*TapaPMTX, 0.5*TapaPMTY, 0.5*TapaPMTZ);
	TapaPMTLogico = new G4LogicalVolume(TapaPMTSolido, MaterialGondola, "TapaPMTLogico");
	TapaPMTLogico->SetVisAttributes(AtributosAluminio);
	for(G4int i=0; i<2; i++){
			for(G4int k=0; k<2; k++){
				TapaPMTFisico=new G4PVPlacement(0,G4ThreeVector(-0.25*ReflectorX + i*0.5*ReflectorX ,1.83731 *m,-0.25*ReflectorZ + k*0.5*ReflectorZ),TapaPMTLogico, "TapaPMTFisico", 						MundoLogico, false, i+k, CheckTraslapes);
		}};
	for(G4int i=0; i<2; i++){
			for(G4int k=0; k<2; k++){
				TapaPMTFisico=new G4PVPlacement(0,G4ThreeVector(-0.25*ReflectorX + i*0.5*ReflectorX ,-0.3017 *m -(ReflectorY+AceroY+0.2153*m),-0.25*ReflectorZ + k*0.5*ReflectorZ),TapaPMTLogico, "TapaPMTFisico", MundoLogico, false, -(i+k), CheckTraslapes);
		}};*/	
		
	
	return MundoFisico;
}

void Construccion::ConstructSDandField(){

	Sensor = new SensitiveDetector("Sensor");
	PMTLogico -> SetSensitiveDetector(Sensor);
	G4SDManager::GetSDMpointer() -> AddNewDetector(Sensor);

}

