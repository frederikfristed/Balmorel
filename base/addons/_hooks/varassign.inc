* Location of variable declations used in add-ons

$ifi %testbb1234%==yes    $include "../../base/addons/bb1234compare/bb1234_varassign.inc";
$ifi %DECOM%==yes  $include   "../../base/addons/DECOM/DECOM_varassign.inc";
$ifi %HEATTRANS%==yes       $include   "../../base/addons/heattrans/bb4/heattrans_varassign.inc";
$ifi %HYDROGEN%==yes       $include   "../../base/addons/hydrogen/bb4/hydrogen_varassign.inc";
$ifi %OPTIFLOW%==yes       $include   "../../base/addons/optiflow/bb4/optiflow_varassign.inc";
$ifi %OFFSHOREGRID%==yes  $include   "../../base/addons/offshoregrid/bb4/offshoregrid_varassign.inc";
* kpotguard: BB4 only (the hook is also included from bb123.sim, where IY411FIRST does not exist)
$ifi %KPOTGUARD%==yes $ifi %BB4%==yes  $include   "../../base/addons/kpotguard/kpotguard_varassign.inc";
