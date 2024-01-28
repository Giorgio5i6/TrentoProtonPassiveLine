// Component for RidgeFilter_PassiveScanning

#include "RidgeFilter_PassiveScanning.hh"
#include "TsParameterManager.hh"

#include "G4SystemOfUnits.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4UnionSolid.hh"
#include "G4Trd.hh"
#include "G4AssemblyVolume.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4PVReplica.hh"
#include "G4RotationMatrix.hh"
#include "G4NistManager.hh"
#include "G4NistElementBuilder.hh"
#include "globals.hh"

RidgeFilter_PassiveScanning::RidgeFilter_PassiveScanning(TsParameterManager* pM, TsExtensionManager* eM, TsMaterialManager* mM, TsGeometryManager* gM,
			 TsVGeometryComponent* parentComponent, G4VPhysicalVolume* parentVolume, G4String& name) :
TsVGeometryComponent(pM, eM, mM, gM, parentComponent, parentVolume, name)
{
}


RidgeFilter_PassiveScanning::~RidgeFilter_PassiveScanning()
{
}


G4VPhysicalVolume* RidgeFilter_PassiveScanning::Construct()
{
// ---------------------------- //
  //         THE Ridge Filter    //
  // -----------------------------//
  // Energy degreader of
  // primary beam. Made of a series of pin-substructures.
  
  BeginConstruction();
	

   //Plastic
    // ELEMENTS
    /*G4bool isotopes = false;
    G4Element* hydrogenNist = G4NistManager::Instance()->FindOrBuildElement("H");
    G4Element* oxygenNist = G4NistManager::Instance()->FindOrBuildElement("O");
    G4Element* carbonNist = G4NistManager::Instance()->FindOrBuildElement("C");
   
    G4Material* plastic = new G4Material("Plastic", 1.40*g/cm3, 3);
    plastic -> AddElement(carbonNist, 21);
    plastic -> AddElement(oxygenNist, 4);
    plastic -> AddElement(hydrogenNist, 24);
    G4String ridgeMaterial = "Plastic";
    */

    
    const G4double XBase = 0.1 *mm;
    const G4double YBase = 38.75*mm;
    const G4double TransRidgeX = -14.9*mm; //-15mm -XBase. I trapezi sono diretti verso x positivo
    G4double HLX = 15.0*mm;

   G4Box* RidgeFilter = new G4Box("RidgeFilter", HLX, YBase, YBase);
    
   fEnvelopeLog = CreateLogicalVolume(RidgeFilter);
   fEnvelopePhys = CreatePhysicalVolume(fEnvelopeLog);
    
    G4VSolid* RidgeBase = new G4Box("Base_RidgeFilter",
                                    XBase,
                                    YBase,
                                    YBase);


    
    G4LogicalVolume* RidgeBaseLog = CreateLogicalVolume("RidgeBase", RidgeBase);
    
    
    G4ThreeVector* TranBase = new G4ThreeVector(TransRidgeX, 0.*cm, 0.*cm); 
    G4VPhysicalVolume* RidgeBasePhys = CreatePhysicalVolume("RidgeFilterBase", 
						RidgeBaseLog, 
						0, 
						TranBase, 
						fEnvelopePhys);
    

  G4double x0 = 1.215*mm;
  G4double x1 = 1*mm;
  G4double x2 = 0.95*mm;
  G4double x3 = 0.87*mm;
  G4double x4 = 0.76*mm;
  G4double x5 = 0.71*mm;
  G4double x6 = 0.65*mm;
  G4double x7 = 0.56*mm;
  G4double x8 = 0.529*mm;
  G4double x9 = 0.258*mm;
  G4double x10 = 0.225*mm;
  G4double x11 = 0.144*mm;
  G4double x12 = 0.055*mm;
    
  G4double heigth = 0.13*mm;
  G4double heigth0 = 0.11*mm;
  G4double heigth1 = 2.3*mm;
  G4double heigth2 = 0.65*mm;
  G4double heigth3 = 1.9*mm;
  G4double heigth4 = 0.615*mm;
  G4double heigth5 = 2.23*mm;
  G4double heigth6 = 0.3*mm;
  G4double heigth7 = 4.1*mm;
  G4double heigth8 = 0.1*mm;
  G4double heigth9 = 0.105*mm;
  G4double heigth10 = 0.065*mm;
  
  G4VSolid* Trap00 = new G4Trd("singleTrap00", x0, x1, x0, x1, heigth);
  G4VSolid* Trap0 = new G4Trd("singleTrap0", x1, x2, x1, x2, heigth0);
  G4VSolid* Trap1 = new G4Trd("singleTrap1", x2, x3, x2, x3, heigth1);
  G4VSolid* Trap2 = new G4Trd("singleTrap2", x3, x4, x3, x4, heigth2);
  G4VSolid* Trap3 = new G4Trd("singleTrap3", x4, x5, x4, x5, heigth3);
  G4VSolid* Trap4 = new G4Trd("singleTrap4", x5, x6, x5, x6, heigth4);
  G4VSolid* Trap5 = new G4Trd("singleTrap5", x6, x7, x6, x7, heigth5);
  G4VSolid* Trap6 = new G4Trd("singleTrap6", x7, x8, x7, x8, heigth6);
  G4VSolid* Trap7 = new G4Trd("singleTrap7", x8, x9, x8, x9, heigth7);
  G4VSolid* Trap8 = new G4Trd("singleTrap8", x9, x10, x9, x10, heigth8);
  G4VSolid* Trap9 = new G4Trd("singleTrap9", x10, x11, x10, x11, heigth9);
  G4VSolid* Trap10 = new G4Trd("singleTrap10", x11, x12, x11, x12, heigth10);
  
 
  G4ThreeVector tr0(0., 0., 0.24);
  G4ThreeVector tr1(0., 0., 2.54);
  G4ThreeVector tr2(0., 0., 2.55);
  G4ThreeVector tr3(0., 0., 2.845);
  G4ThreeVector tr4(0., 0., 4.4);
  
  G4RotationMatrix* yRot = new G4RotationMatrix; 
  yRot->rotateY(0); 
  G4UnionSolid* unionTrap00 = new G4UnionSolid("Trap01", Trap00, Trap0, yRot, tr0);
  G4UnionSolid* unionTrap01 = new G4UnionSolid("Trap01", unionTrap00, Trap1, yRot, tr1);
  G4UnionSolid* unionTrap23 = new G4UnionSolid("Trap23", Trap2, Trap3, yRot, tr2);
  G4UnionSolid* unionTrap45 = new G4UnionSolid("Trap45", Trap4, Trap5, yRot, tr3);
  G4UnionSolid* unionTrap67 = new G4UnionSolid("Trap67", Trap6, Trap7, yRot, tr4);
  
  G4ThreeVector tr03(0., 0., 5.09);
  G4UnionSolid* unionTrap03 = new G4UnionSolid("unionTrap03", unionTrap01, unionTrap23, yRot, tr03);
  
  G4ThreeVector tr05(0., 0., 7.935);
  G4UnionSolid* unionTrap05 = new G4UnionSolid("unionTrap05", unionTrap03, unionTrap45, yRot, tr05);
    
  G4ThreeVector tr_blocco1(0., 0., 12.335);
  G4UnionSolid* unionTrap_blocco1 = new G4UnionSolid("unionTrap_blocco1", unionTrap05, unionTrap67, yRot, tr_blocco1);
  
  G4ThreeVector tr_blocco2( 0., 0., 12.435);
  G4UnionSolid* unionTrap_blocco2 = new G4UnionSolid("unionTrap_blocco2", unionTrap_blocco1, Trap8, yRot, tr_blocco2);
  
  G4ThreeVector tr_blocco3(0., 0., 12.54);
  G4UnionSolid* unionTrap_blocco3 = new G4UnionSolid("unionTrap_blocco3", unionTrap_blocco2, Trap9, yRot, tr_blocco3);
  
  G4ThreeVector tr_tot( 0., 0., 12.605);
  G4UnionSolid* unionTrap = new G4UnionSolid("unionTrap", unionTrap_blocco3, Trap10, yRot, tr_tot);

  //ha formato la piramide di tot trapezi e ha creato il volume logico che ripete
  //G4LogicalVolume* singleTrapLog = new G4LogicalVolume(unionTrap, singleTrapMaterial, "singleTrap");
  G4LogicalVolume* singleTrapLog = CreateLogicalVolume("SingleTrap", unionTrap);
  

  //singleTrapLog->SetVisAttributes(yellow);
  
  
    G4int numberOfLayers = 31;
    G4double minZ = -37.5*mm;
    G4double minY = -37.5*mm;
    G4double sum_space = 1.25*mm;
    

    G4double ti = -90. *deg;
    G4RotationMatrix* rt = new G4RotationMatrix;
    rt -> rotateY(ti);
    G4int N = 0;
    for (int i = 0; i < numberOfLayers; i++)
      {
    	for (int j = 0; j < numberOfLayers; j++)
    	  {
		G4ThreeVector* singleTrapPositions = new G4ThreeVector(0.08*cm+TransRidgeX,
    		  minY + 2*i*sum_space,
    		  minZ + 2*j*sum_space);
	    /*singleTrapPositions.push_back({-0.08*cm+TranBase,
    		  minY + 2*i*sum_space,
    		  minZ + 2*j*sum_space,});*/
		G4VPhysicalVolume* singleTrapPhy =  CreatePhysicalVolume("singleTrap", 
				N, 
				1, 
				singleTrapLog, 
				rt, 
				singleTrapPositions, 
				fEnvelopePhys);
		N++;
    	  }
      }

      return fEnvelopePhys;
}
