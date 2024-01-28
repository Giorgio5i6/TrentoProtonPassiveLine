#ifndef RidgeFilter_PassiveScanning_hh
#define RidgeFilter_PassiveScanning_hh

#include "TsVGeometryComponent.hh"

class RidgeFilter_PassiveScanning : public TsVGeometryComponent
{    
public:
	RidgeFilter_PassiveScanning(TsParameterManager* pM, TsExtensionManager* eM, TsMaterialManager* mM, TsGeometryManager* gM,
				  TsVGeometryComponent* parentComponent, G4VPhysicalVolume* parentVolume, G4String& name);
	~RidgeFilter_PassiveScanning();
	
	G4VPhysicalVolume* Construct();
};

#endif
