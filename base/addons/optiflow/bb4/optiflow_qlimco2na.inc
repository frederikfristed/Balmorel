* CCU in optiflow, requires CCS add-on. Added by Theis Madsen

*Re-adding utilizes CO2 for fuels
$ifi not %CCS%==yes $goto NOCCUS

$ifi %baloptCCU%==yes -SUM(C,SUM((IA,IPROCFROM,IPROCTO,FLOW)$(ICA(C,IA) AND ICO2_CU(IPROCFROM,FLOW)), SUM((IS3,T), IHOURSINST(IS3,T) * IHOURFRAC * VFLOW(IY411,IA,IPROCFROM,IPROCTO,FLOW,IS3,T))))

$label NOCCUS

- SUM(C,SUM((IA,PROCSOURCE,FLOW)$(ICA(C,IA) AND PROC_T(PROCSOURCE) AND SOSIBU2INDIC(IY411,PROCSOURCE,FLOW,'GHGEMISSION_nonbio')),  SUM((IS3,T), IHOURSINST(IS3,T) * VFLOWSOURCE(IY411,IA,PROCSOURCE,FLOW,IS3,T)$(SUM(IPROCTO,FLOWFROMTOPROC(IY411,IA,PROCSOURCE,IPROCTO,FLOW))))* SOSIBU2INDIC(IY411,PROCSOURCE,FLOW,'GHGEMISSION_nonbio')))
