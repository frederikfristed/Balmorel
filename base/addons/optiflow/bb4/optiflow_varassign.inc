* File hydrogen_varassign.inc for addon hydrogen.

$ifi %inv%==yes   LOOP(Y$(YVALUE(Y) LE YVALUE(IYALIAS)),VPROCKAPNEW.FX(Y,IA,PROC)$IAPROCKAPNEW(Y,IA,PROC)= VPROCKAPNEW.L(Y,IA,PROC););
$ifi %inv%==yes   VPROCKAPACCUMNET.FX(IY411FIRST,IA,PROC)$SUM(Y$(YVALUE(Y) LE YVALUE(IY411FIRST)),IAPROCKAPNEW(Y,IA,PROC)) = VPROCKAPACCUMNET.L(IY411FIRST,IA,PROC);
* Also fix transport (PROCEXIM) investments from the current and earlier years before the next myopic solve.
* Ported from navigating_maritime_transition_pathways 23dbd93.
$ifi %inv%==yes   LOOP(Y$(YVALUE(Y) LE YVALUE(IYALIAS)),VPROCEXIMKAPNEW.FX(Y,IAE,IAI,PROC)$IAPROCEXIMKAPNEW(Y,IAE,IAI,PROC)= VPROCEXIMKAPNEW.L(Y,IAE,IAI,PROC););