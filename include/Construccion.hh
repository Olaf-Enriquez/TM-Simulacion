

#ifndef CONSTRUCCION_HH	//Definir Constructor
#define CONSTRUCCION_HH
#include "G4VUserDetectorConstruction.hh" //Clase base (hereda)
#include "G4Box.hh" //Crear formas (cajas)
#include "G4Tubs.hh" //Crear formas (tubos)
#include "G4LogicalVolume.hh" //Bibliotecas para crear volúmenes
#include "G4VPhysicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4Material.hh"
#include "G4Element.hh"
#include "G4NistManager.hh" //Crear materiales
#include "G4SystemOfUnits.hh" //Unidades
#include "G4SubtractionSolid.hh"//Cajas huecas
#include "G4VisAttributes.hh"
#include "G4Color.hh"

class Construccion : public G4VUserDetectorConstruction //Declaración de clase
{
public:
	Construccion();
	virtual ~Construccion();
	virtual G4VPhysicalVolume *Construct(); //Funcion principal para construir
private: 
	G4int natoms;
	G4bool CheckTraslapes; //Detectar traslapes de volumenes
	G4Box *MundoSolido, *ReflectorSolido, *AceroSolido, *IntnmSolido, *ProductorPlacaSolido, *ProductorPlacaSolido2, *CentelladorSolido; //Declarar mundo, caja del 6nm64, acero
	G4Box *GondolaExterior, *GondolaSolido, *GondolaIntSolido;
	G4Tubs *ProductorTuboSolido, *ModeradorSolido, *ContenedorSolido, *ContenedorTapasSolido, *TrifluoruroSolido; //Declara tubo prod
	G4LogicalVolume *MundoLogico, *ReflectorLogico, *AceroLogico, *IntnmLogico, *ProductorPlacaLogico, *ProductorPlacaLogico2, *CentelladorLogico;//Declarar lógica del mundo, caja del 6nm64, acero
	G4LogicalVolume *ProductorTuboLogico, *ModeradorLogico, *ContenedorLogico, *ContenedorTapasLogico, *TrifluoruroLogico;//Declarar lógica de tubos prod
	G4LogicalVolume *GondolaLogico, *GondolaIntLogico;
	G4VPhysicalVolume *MundoFisico, *ReflectorFisico, *AceroFisico, *IntnmFisico, *ProductorPlacaFisico, *ProductorPlacaFisico2, *CentelladorFisico;//Declarar mundo físico, caja física del 6nm64, acero
	G4VPhysicalVolume *GondolaFisico, *GondolaIntFisico;
	G4VPhysicalVolume *ProductorTuboFisico, *ModeradorFisico, *ContenedorFisico, *ContenedorTapasFisico, *TrifluoruroFisico;
	G4double CoorX, CoorY, CoorZ, ReflectorX, ReflectorY, ReflectorZ, AceroX, AceroY, AceroZ, IntnmX, IntnmY, IntnmZ, ProductorPlacaX, ProductorPlacaY, ProductorPlacaZ, ProductorPlacaX2; //Coordenadas mundo, caja del 6nm64, soporte acero
	G4double CentelladorX, CentelladorY, CentelladorZ;
	G4double GondolaX, GondolaY, GondolaZ, GondolaGrosorX, GondolaGrosorY, GondolaGrosorZ;
	G4double RadInProductorTubo, RadExProductorTubo, HZProductorTubo, AnguloInicialProductorTubo, AnguloArcoProductorTubo;//radios,half lenght y  angulos productores 
	G4double RadInModerador, RadExModerador, HZModerador, AnguloInicialModerador, AnguloArcoModerador;//radios,half lenght y  angulos moderadores
	G4double RadInContenedor, RadExContenedor, HZContenedor, AnguloInicialContenedor, AnguloArcoContenedor;//radios,half lenght y  angulos contenedores
	G4double RadInContenedorTapas, RadExContenedorTapas, HZContenedorTapas, AnguloInicialContenedorTapas, AnguloArcoContenedorTapas;//radios,half lenght y  angulos tapas de contenedores
	G4double RadInTrifluoruro, RadExTrifluoruro, HZTrifluoruro, AnguloInicialTrifluoruro, AnguloArcoTrifluoruro;//radios,half lenght y  angulos Trifluoruros
	G4Material *MaterialMundo, *MaterialReflector, *Acero, *MaterialIntnm, *MaterialProductor, *MaterialModerador, *MaterialCentellador, *MaterialGondola; //material del fondo, caja del 6nm64, acero
	G4VisAttributes *AtributosAluminio, *AtributosAcero, *AtributosReflector, *AtributosCentellador;
	
};
#endif
