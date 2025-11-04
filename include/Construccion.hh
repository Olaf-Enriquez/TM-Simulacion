

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
#include "G4Trd.hh"
#include "G4RotationMatrix.hh"
#include "G4SDManager.hh"
#include "SensitiveDetector.hh"
#include "G4OpticalSurface.hh"
#include "G4LogicalSkinSurface.hh"
#include "G4MaterialPropertiesTable.hh"

class Construccion : public G4VUserDetectorConstruction //Declaración de clase
{
public:
	Construccion();
	virtual ~Construccion();
	virtual G4VPhysicalVolume *Construct(); //Funcion principal para construir
	G4LogicalVolume *GetScoringVolume() const {return ScoringVolume;}
private: 
	G4int natoms;
	G4bool CheckTraslapes; //Detectar traslapes de volumenes
	G4Box *MundoSolido, *ReflectorSolido, *AceroSolido, *IntnmSolido, *ProductorPlacaSolido, *ProductorPlacaSolido2, *CentelladorSolido; //Declarar mundo, caja del 6nm64, acero
	G4Box *GondolaExterior, *GondolaSolido, *GondolaIntSolido, *TapaPMTSolido, *TapaPMTIntSolido;
	G4Trd *TrapSolido, *TrapIntSolido;
	G4Tubs *ProductorTuboSolido, *ModeradorSolido, *ContenedorSolido, *ContenedorTapasSolido, *TrifluoruroSolido, *PMTSolido; //Declara tubo prod
	G4LogicalVolume *MundoLogico, *ReflectorLogico, *AceroLogico, *IntnmLogico, *ProductorPlacaLogico, *ProductorPlacaLogico2, *CentelladorLogico;//Declarar lógica del mundo, caja del 6nm64, acero
	G4LogicalVolume *ProductorTuboLogico, *ModeradorLogico, *ContenedorLogico, *ContenedorTapasLogico, *TrifluoruroLogico;//Declarar lógica de tubos prod
	G4LogicalVolume *GondolaLogico, *GondolaIntLogico, *TrapIntLogico, *TrapLogico, *PMTLogico, *TapaPMTLogico, *TapaPMTIntLogico, *ScoringVolume;
	G4VPhysicalVolume *MundoFisico, *ReflectorFisico, *AceroFisico, *IntnmFisico, *ProductorPlacaFisico, *ProductorPlacaFisico2, *CentelladorFisico;//Declarar mundo físico, caja física del 6nm64, acero
	G4VPhysicalVolume *GondolaFisico, *GondolaIntFisico, *TrapFisico, *TrapIntFisico, *PMTFisico, *TapaPMTFisico, *TapaPMTIntFisico;
	G4VPhysicalVolume *ProductorTuboFisico, *ModeradorFisico, *ContenedorFisico, *ContenedorTapasFisico, *TrifluoruroFisico;
	G4double CoorX, CoorY, CoorZ, ReflectorX, ReflectorY, ReflectorZ, AceroX, AceroY, AceroZ, IntnmX, IntnmY, IntnmZ, ProductorPlacaX, ProductorPlacaY, ProductorPlacaZ, ProductorPlacaX2; //Coordenadas mundo, caja del 6nm64, soporte acero
	G4double CentelladorX, CentelladorY, CentelladorZ,TrapX1, TrapX2, TrapY1, TrapY2, TrapZ, TapaPMTX, TapaPMTY, TapaPMTZ, TapaPMTGrosorX, TapaPMTGrosorY, TapaPMTGrosorZ;
	G4double GondolaX, GondolaY, GondolaZ, GondolaGrosorX, GondolaGrosorY, GondolaGrosorZ;
	G4double RadInProductorTubo, RadExProductorTubo, HZProductorTubo, AnguloInicialProductorTubo, AnguloArcoProductorTubo;//radios,half lenght y  angulos productores 
	G4double RadInModerador, RadExModerador, HZModerador, AnguloInicialModerador, AnguloArcoModerador, EnergiaALongitud;//radios,half lenght y  angulos moderadores
	G4double RadInContenedor, RadExContenedor, HZContenedor, AnguloInicialContenedor, AnguloArcoContenedor;//radios,half lenght y  angulos contenedores
	G4double RadInContenedorTapas, RadExContenedorTapas, HZContenedorTapas, AnguloInicialContenedorTapas, AnguloArcoContenedorTapas;//radios,half lenght y  angulos tapas de contenedores
	G4double RadInTrifluoruro, RadExTrifluoruro, HZTrifluoruro, AnguloInicialTrifluoruro, AnguloArcoTrifluoruro, PMTRadIn, PMTRadExt, PMTz, PMTAnguloIni, PMTAnguloArco;//radios,half lenght y  angulos Trifluoruros
	G4Material *MaterialMundo, *MaterialReflector, *Acero, *MaterialIntnm, *MaterialProductor, *MaterialModerador, *MaterialCentellador, *MaterialGondola; //material del fondo, caja del 6nm64, acero
	G4Material *Silice, *OxidoBorico, *OxidoSodio, *OxidoPotasio, *OxidoCalcio, *OxidoAluminio, *Pyrex;
	G4VisAttributes *AtributosAluminio, *AtributosAcero, *AtributosReflector, *AtributosCentellador;
	std::vector<G4double> Energia, RefraccionMundo, RefraccionCentellador, FraccionCentellador, ReflectividadCentellador; //Propiedades Opcticas gondolas/centelladores
	G4MaterialPropertiesTable *PropiedadesMundo, *PropiedadesCentellador,  *PropiedadesCentelladorSup; //Tablas propiedades ópticas
	G4OpticalSurface *SuperficieCentellador;
	
	virtual void ConstructSDandField();
	SensitiveDetector *Sensor;
};
#endif
