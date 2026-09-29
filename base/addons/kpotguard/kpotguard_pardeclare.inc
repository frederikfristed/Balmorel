* File kpotguard_pardeclare.inc
* Declarations for the capacity-potential guard (see kpotguard_varassign.inc).
PARAMETER IKPOTGUARD_LHS(CCCRRRAAA,TECH_GROUP,SUBTECH_GROUP) "Capacity fixed from the year just solved, by potential group (MW)";
PARAMETER IKPOTGUARD_LHST(CCCRRRAAA,TECH_GROUP)              "Capacity fixed from the year just solved, by technology group (MW)";
PARAMETER IKPOTGUARD_EXC(CCCRRRAAA,TECH_GROUP,SUBTECH_GROUP) "Excess of fixed capacity over SUBTECHGROUPKPOT (MW)";
PARAMETER IKPOTGUARD_EXCT(CCCRRRAAA,TECH_GROUP)              "Excess of fixed capacity over TECHGROUPKPOT (MW)";
PARAMETER IKPOTGUARD_SUB(YYY,CCCRRRAAA,TECH_GROUP,SUBTECH_GROUP) "Upward adjustment of SUBTECHGROUPKPOT applied after year YYY (MW)";
PARAMETER IKPOTGUARD_TG(YYY,CCCRRRAAA,TECH_GROUP)                "Upward adjustment of TECHGROUPKPOT applied after year YYY (MW)";
PARAMETER IKPOTGUARD_BIG(YYY,CCCRRRAAA,TECH_GROUP,SUBTECH_GROUP) "Excess above guard tolerance, NOT adjusted (MW) - indicates a data problem";
PARAMETER IKPOTGUARD_DEC(YYY,AAA,GGG) "Accumulated exogenous decommissioning capped at GKFX after year YYY: excess removed (MW)";
SCALAR    IKPOTGUARD_ATOL "Largest absolute excess treated as solver residual (MW)" /1/;
SCALAR    IKPOTGUARD_RTOL "Largest relative excess treated as solver residual (-)"  /1E-4/;
