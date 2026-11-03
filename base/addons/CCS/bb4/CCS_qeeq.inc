* CCS add-on. Added by Juan Gea Bermudez

*adding electricity demand for CO2 capture, fossil and biogenic (IM_CO2+IM_CO2RE). Ported from navigating_maritime_transition_pathways 23dbd93
+ SUM((IA,G)$(IAGK_HASORPOT(IY411,IA,G) AND RRRAAA(IR,IA) AND CCS_G(G)),
 (VGF_T(IY411,IA,G,IS3,T) * (IM_CO2(G)+IM_CO2RE(G))*IOF0001 * IOF3P6 * CCS_CO2CAPTEFF_G(G)*  CCS_DECO2COMP_G(G))/(1-DISLOSS_E_AG(IA,G))
 )

