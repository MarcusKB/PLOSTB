
*NB: Values in the code - see notes at bottom of this file

*## Initial static CGE model set-up (for dynamically-recursive simulations over pre-simulation period tp)

PARAMETERS SAMscale        conversion from SAM import unit (bn INR) to basic unit /1E9/
           TARGETscale     conversion from basic unit to TARGET unit (bn INR) model unit /1E9/
           IMPORTscale_POP conversion from population import unit (1) to basic unit /1/
           TARGETscale_POP conversion from basic unit to TARGET population (1E3) model unit /1E3/
           INVscale        conversion from Investent units (bn INR) to Capital stock units (bn INR) /1/
           POPscale        conversion from demographic and TB model unit (1000' persons) to basic unit /1E3/
;

*## static CGE model
$include mod101.gms

SET t1_tb /1*52/
    nonH(h,hp)
;

ALIAS (t1_tb,t1_tbp,t1_tbpp);

nonH(h,hp) = no;
nonH(h,hp)$(ord(h) <> ord(hp)) = yes;

*## parameter
$include parmdef.inc

*Scenario TABs
TAB_Scen01=0;
TAB_Scen02=0;
TAB_Scen03=0;
TAB_Scen04=0;
TAB_Scen05=0;
TAB_Scen06=0;

*## TB-extended model
$include modTB.gms


*## NB: World Development Indicators, accessed...
********  CHANGE  ************
*##     Monday 13 Oct 2014 (weekly rates for the week 13-17 Oct 2014)
*##     1 Yr Note 22.50%
*##     2 Yr Fixed Rate Note 23.00%

PARAMETER            dfactor        discount factor for NPV calculations (5-6% inflation rate + 4-5% real interest rate)  / 0.100 /
                     dfactor_t(t1)  discount factor for NPV calculations by time period (t1)
                     dGDPDEF_t(t1)   GDP deflator discount factor for NPV calculations by time period (t1)
;

*dfactor_t(ts)$(ord(ts) eq 1) = 1;
*loop(ts, dfactor_t(ts+1) = (1/(1+dfactor))*dfactor_t(ts));

dfactor_t(ts)$(ord(ts) eq 1) = 1;
loop(ts, dfactor_t(ts+1) = (1+dfactor)*dfactor_t(ts));
dfactor_t(ts) = SUM(tsp$(ord(tsp) eq 1),dfactor_t(tsp))/dfactor_t(ts);

Display dfactor_t;

ALIAS(tp,tpp), (insd,insdp)
;
