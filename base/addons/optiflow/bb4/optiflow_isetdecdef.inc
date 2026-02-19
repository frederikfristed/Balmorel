*** Fuel bridge (Balmorel fuel ↔ OptiFlow flows and processes)
*** Initialises IFFLOW and IFPROC when baloptfuelbridge is enabled (TMAD).
$ifi not %baloptfuelbridge%==yes $goto nofuelbridge

*** IFFLOW: Balmorel fuel (FFF) mapped to OptiFlow flow (FLOW)
SET IFFLOW(FFF,FLOW)    "Fuel in Balmorel that corresponds to a flow in OptiFlow";
IFFLOW(FFF,FLOW)=0;

IFFLOW('STRAW','STRAW_GEN_FLOW')    = YES;
IFFLOW('WOODCHIPS','WOOD_GEN_FLOW') = YES;
*IFFLOW('WOODPELLETS','WOOD_PELLETS_GEN_FLOW') = YES;

*** IFPROC: Balmorel fuel (FFF) mapped to OptiFlow process (PROC)
SET IFPROC(FFF,PROC)    "Fuel in Balmorel that corresponds to a flow in OptiFlow";
IFPROC(FFF,PROC)=0;

IFPROC('STRAW','Straw_Gen')     = YES;
IFPROC('WOODCHIPS','Wood_Gen')  = YES;
*IFPROC('WOODPELLETS','Wood_Pellets_Gen') = YES;

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

ICO2('CO2_Source_Biogen','CO2_SOURCE_FLOW_BIOGEN') = YES;
ICO2('CO2_Source_Fossil','CO2_SOURCE_FLOW_FOSSIL') = YES;


*** Subtracting CO2 captured in OptiFlow from the Balmorel carbon balance
*** ICO2_CC(PROC,FLOW) identifies OptiFlow capture flows routed to CS/CU pools.
SET ICO2_CC(PROC,FLOW)          "Set of PROC/FLOW pairs that deliver CO2 captured in OptiFlow to a pool for CS/CU";
ICO2_CC(PROC,FLOW)=0;

ICO2_CC('CO2_DAC','CO2_FLOW_DAC')           = YES;
ICO2_CC('CO2_Biogas','CO2_FLOW_BIOGAS')     = YES;
ICO2_CC('CO2_Biochar_Sum','CO2_FLOW_BIOCHAR') = YES;

*** OCC accounting note
*** MDO emissions are added in SOSIBU2INDIC. OCC captured share is subtracted here, yielding a net reduction in residual emissions.
*** For fossil drop-in fuels, OCC captured share is simply subtracted. This yields carbon neutral cycling for CCU and net removal for CCS.
ICO2_CC('OCC_30','CO2_FLOW_OCC') = YES;
ICO2_CC('OCC_35','CO2_FLOW_OCC') = YES;
ICO2_CC('OCC_40','CO2_FLOW_OCC') = YES;
ICO2_CC('OCC_45','CO2_FLOW_OCC') = YES;
ICO2_CC('OCC_50','CO2_FLOW_OCC') = YES;


*** Re-adding CO2 used for utilisation in OptiFlow
*** ICO2_CU(PROC,FLOW) identifies CO2 flows consumed for CU pathways.
SET ICO2_CU(PROC,FLOW)          "Set of PROC/FLOW pairs that deliver CO2 for CU";
ICO2_CU(PROC,FLOW)=0;

ICO2_CU('CO2_CU_Split','CO2_FLOW_EME') = YES;
ICO2_CU('CO2_CU_Split','CO2_FLOW_FT')  = YES;

$label noCCUopti


*** End of file
$label endoffile
