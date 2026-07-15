
$ifi not %baloptfuelbridge%==yes $goto nofuelbridge

*** IFFLOW: Balmorel fuel (FFF) mapped to OptiFlow flow (FLOW)
SET IFFLOW(FFF,FLOW)    "Fuel in Balmorel that corresponds to a flow in OptiFlow";
IFFLOW(FFF,FLOW)=0;

IFFLOW('STRAW','BIOMASS_FLOW_STRAW')    = YES;
IFFLOW('WOODCHIPS','BIOMASS_FLOW_WOOD') = YES;

*** IFPROC: Balmorel fuel (FFF) mapped to OptiFlow process (PROC)
SET IFPROC(FFF,PROC)    "Fuel in Balmorel that corresponds to a flow in OptiFlow";
IFPROC(FFF,PROC)=0;

IFPROC('STRAW','Straw_Source')     = YES;
IFPROC('WOODCHIPS','Wood_Source')  = YES;

$label nofuelbridge

*** Biogas bridge (Balmorel biogas ↔ OptiFlow gas buffer and flow)
*** Extends IFFLOW and IFPROC when baloptgasbridge is enabled.
$ifi not %baloptgasbridge%==yes $goto nogasbridge

*IFFLOW('STRAW','STRAW_FLOW_BIOGAS') = YES;
IFFLOW('BIOGAS','SNG_FLOW') = YES;
IFPROC('BIOGAS','Gas_Buffer') = YES;

$label nogasbridge


*** CO2 source bridge (Balmorel capture ↔ OptiFlow CO2 sourcing and accounting)
*** Initialises CO2 linkage sets when baloptCCU is enabled.
$ifi not %baloptCCU%==yes $goto noCCUopti


*** CO2 point sources linked to Balmorel capture
*** ICO2(PROCSOURCE,FLOW) constrains OptiFlow CO2 source flows using Balmorel-captured CO2.
SET ICO2(PROCSOURCE,FLOW)       "Set of CO2 SOURCE/FLOW linked to point sources in Balmorel";
ICO2(PROCSOURCE,FLOW)=0;

ICO2('CO2_Source_Biogen','CO2_FLOW_BIO') = YES;
ICO2('CO2_Source_Fossil','CO2_FLOW_FOSSIL') = YES;

*** Subtracting CO2 captured in OptiFlow from the Balmorel carbon balance
*** ICO2_CC(PROC,FLOW) identifies OptiFlow capture flows routed to CS/CU pools.
SET ICO2_CC(PROC,FLOW)          "Set of PROC/FLOW pairs that deliver CO2 captured in OptiFlow to a pool for CS/CU";
ICO2_CC(PROC,FLOW)=0;

ICO2_CC('CO2_Source_DAC','CO2_FLOW') = YES;
ICO2_CC('CO2_Biochar_Sum','CO2_FLOW') = YES;
ICO2_CC('Biogas_Upgrading_30','CO2_FLOW') = YES;
ICO2_CC('Biogas_Upgrading_35','CO2_FLOW') = YES;
ICO2_CC('Biogas_Upgrading_40','CO2_FLOW') = YES;
ICO2_CC('Biogas_Upgrading_45','CO2_FLOW') = YES;
ICO2_CC('Biogas_Upgrading_50','CO2_FLOW') = YES;

*** OCC accounting note
*** MDO emissions are added in SOSIBU2INDIC. OCC captured share is subtracted here, yielding a net reduction in residual emissions.
*** For fossil drop-in fuels, OCC captured share is simply subtracted. This yields carbon neutral cycling for CCU and net removal for CCS.
ICO2_CC('OCC_30','CO2_FLOW') = YES;
ICO2_CC('OCC_35','CO2_FLOW') = YES;
ICO2_CC('OCC_40','CO2_FLOW') = YES;
ICO2_CC('OCC_45','CO2_FLOW') = YES;
ICO2_CC('OCC_50','CO2_FLOW') = YES;


*** Re-adding CO2 used for utilisation in OptiFlow
*** ICO2_CU(PROC,FLOW) identifies CO2 flows consumed for CU pathways.
SET ICO2_CU(PROC,FLOW)          "Set of PROC/FLOW pairs that deliver CO2 for CU";
ICO2_CU(PROC,FLOW)=0;
ICO2_CU('CO2_CU','CO2_FLOW_FOSSIL') = YES;
ICO2_CU('CO2_CU','CO2_FLOW_BIO') = YES;
ICO2_CU('CO2_CU','CO2_FLOW') = YES;

*Add maritime fuel direct and process emissions
SET ICO2_FUELPROC(PROC,FLOW)		"Set of PROC/FLOW pairs that deliver CO2eq process emissions from fuel production PROCs";
ICO2_FUELPROC(PROC,FLOW) = 0;
ICO2_FUELPROC('Ammonia_Buffer','CO2PROC_FLOW') = YES;
ICO2_FUELPROC('Methanol_LPG_Buffer','CO2PROC_FLOW') = YES;
ICO2_FUELPROC('EFT_Diesel_Buffer','CO2PROC_FLOW') = YES;
ICO2_FUELPROC('Biooil_Buffer','CO2PROC_FLOW') = YES;

ICO2_FUELPROC('MDO_Eff','CO2PROC_FLOW') = YES;
ICO2_FUELPROC('MDO_Eff','CO2DIR_FLOW') = YES;
ICO2_FUELPROC('MDO_Eff_OCC','CO2PROC_FLOW') = YES;
ICO2_FUELPROC('MDO_Eff_OCC','CO2DIR_FLOW') = YES;

ICO2_FUELPROC('LNG_Eff','CO2PROC_FLOW') = YES;
ICO2_FUELPROC('LNG_Eff','CO2DIR_FLOW') = YES;
ICO2_FUELPROC('LNG_Eff_OCC','CO2PROC_FLOW') = YES;
ICO2_FUELPROC('LNG_Eff_OCC','CO2DIR_FLOW') = YES;

ICO2_FUELPROC('Hydrogen_Eff','CO2PROC_FLOW') = YES;

$label noCCUopti


*** End of file
$label endoffile
