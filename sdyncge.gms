
PARAMETER TQ00(C), TAB_Scen02_1;

TQ00(C) = TQ0(C);

*###############################################################################
*########## Policy Simulation Dynamic CGE (cdyncge) simulation program #########
*###############################################################################

*Tab for Scenario 1
*NB: Need to adjust decomposition below:
*(1) TOTBURDENcost01, (2) TOTBURDENisolat01,
*(3) TOTBURDENhosp01, (4) TOTBURDENmort01
TAB_Scen01=0;

*Tab for Scenario 2 (treatment success rate 95%)
TAB_Scen02=0;
*Tab for Scenario 2_1 (adjusted treatment succes rate 91.5% based on NSP strategy doc)
TAB_Scen02_1=1;

*Tab for Scenario 3
TAB_Scen03=1;

*Tab for Scenario 4
TAB_Scen04=0;

*Tab for Scenario 5
TAB_Scen05=0;

*Tab for Scenario 5
TAB_Scen06=0;

*##Policy parameters

*1. Treatment regimen unit cost for DS-TB
TBTREATunitcost(DSMDRset) = DSMDR_data(DSMDRset,'COSTregimen');
TBTREATcover(DSMDRset)   = 0;
TBTREAT01('DS')          = 1;
TBTREAT01('MDR')         = 1;

*2. Isolation period (4-12 weeks)
TBISOLATperiod(DSMDRset) = DSMDR_data(DSMDRset,'DURregimen');
TBISOLATadhere(DSMDRset) = 0;
TBISOLAT01('DS')         = 1;
TBISOLAT01('MDR')        = 1;

*2a. Hospitalization period (9.6 work-days)
TBHOSPperiod   = 9.6/(52*5);
TBHOSP01       = 0;

*3. Excess TM mortality impacts on demographics and economics
TBMORT01       = 1;

*TOTAL DISEASE BURDEN ASSESSMENT
TOTBURDENcost01   = 0;
TOTBURDENisolat01 = 0;
TOTBURDENmort01   = 0;

TOTBURDENhosp01   = 0;

$libinclude xlimport CTARGETS counterfactual.xlsx CTARGETS
$libinclude xlimport CQHnut_scale counterfactual.xlsx CQHnut_scale
$libinclude xlimport CCLINOUToutput results.xlsx CCLINOUToutput

*Use GDP deflator as price numeraire (it will be allowed to vary to target nominal GDP below)
 GDPDEF.FX = GDPDEF.L;
 CPI.LO = -inf;
 CPI.UP = +inf;
* CPI.FX = CPI.L;
* GDPDEF.LO = -inf;
* GDPDEF.UP = +inf;

loop(t1$ts(t1),

*In counterfactual: Use balanced macro closure, i.e. constant government consumption share of total absorption
*In simulation: Use counterfactual growth path of government demand (GDN)
*NB: GOVSHR.L refers to the govt consumption share of absorption in the model solution for 2010 (tp07) in presim.gms
 GOVSHR.LO = -inf;
 GOVSHR.UP = +inf;
 GADJ.FX   = CTARGETS('GADJ',t1) ;
* GADJ.LO     = -inf;
* GADJ.UP     = +inf;
* GOVSHR.FX   = GOVSHR0 ;
* GDN.FX      = CTARGETS('GDN',t1) ;

 QHnut_cap_day_scale.FX(H) = CQHnut_scale(H,t1);
 QHnut_cap_day_final.LO(H) = -inf;
 QHnut_cap_day_final.UP(H) = +inf;

IF(ord(t1) gt card(tp),
*Use final week solution from previous year as initial week value for new year
S_TB.FX(h,t1_tb)$(ord(t1_tb) eq 1) = SUM(t1_tbp$(ord(t1_tbp) eq card(t1_tbpp)),S_TB.L(h,t1_tbp)) ;
L_TB.FX(h,t1_tb)$(ord(t1_tb) eq 1) = SUM(t1_tbp$(ord(t1_tbp) eq card(t1_tbpp)),L_TB.L(h,t1_tbp)) ;
I_TB.FX(h,t1_tb)$(ord(t1_tb) eq 1) = SUM(t1_tbp$(ord(t1_tbp) eq card(t1_tbpp)),I_TB.L(h,t1_tbp)) ;
Ir_TB.FX(h,t1_tb)$(ord(t1_tb) eq 1) = SUM(t1_tbp$(ord(t1_tbp) eq card(t1_tbpp)),Ir_TB.L(h,t1_tbp)) ;
T_TB.FX(h,t1_tb)$(ord(t1_tb) eq 1) = SUM(t1_tbp$(ord(t1_tbp) eq card(t1_tbpp)),T_TB.L(h,t1_tbp)) ;
Tr_TB.FX(h,t1_tb)$(ord(t1_tb) eq 1) = SUM(t1_tbp$(ord(t1_tbp) eq card(t1_tbpp)),Tr_TB.L(h,t1_tbp)) ;
*Fix Nominal GDP + release GDP deflator (price numeraire)
* GDPDEF.LO = -inf;
* GDPDEF.UP = +inf;
* NGDP.FX   = TARGETS_SIM('NGDP',t1) ;
* CPI.FX = CTARGETS('CPI',t1) ;
 GDPDEF.FX = CTARGETS('GDPDEF',t1) ;
 NGDP.LO = -inf;
 NGDP.UP = +inf;

*Fix Real GDP + release (avg.) Total Factor Productivity parameter
* TFPadj.LO = -inf;
* TFPadj.UP = +inf;
* RGDP.FX = TARGETS_SIM('RGDP',t1) ;
 TFPadj.FX = TFPadj.L + 0.5*(CTARGETS('TFPadj',t1) - TFPadj.L) ;
 RGDP.LO = -inf;
 RGDP.UP = +inf;

);

 SOLVE STANDCGE USING MCP;

 TFPadj.FX = CTARGETS('TFPadj',t1) ;


*Use revenue-neutral government budget closure
*IF((ord(t1) gt card(tp)),
 YG.FX = CTARGETS('YG',t1) ;
 DTINS.LO = -inf;
 DTINS.UP = +inf;
* RGCONS.FX = CTARGETS('RGCONS',t1) ;
* TINSADJ.LO = -inf;
* TINSADJ.UP = +inf;
*);


*Scenario 2
IF(TAB_Scen02 eq 1,
tau_TB(h) = 0.95
);

*Scenario 2_1
IF(TAB_Scen02_1 eq 1,
tau_TB(h) = 0.915
);

*Scenario 3
IF(TAB_Scen03 eq 1,
*d_TB(h) = 0.0555
*Run1 Diagnostic rate intervention
d_TB(h) = 0.0385848553382241
);

*Scenario 4
IF(TAB_Scen04 eq 1,
*TQ0('c001') = TQ0('c001') - 0.05;
*TQ0('c002') = TQ0('c002') - 0.05;
*TQ0('c003') = TQ0('c003') - 0.05;
*TQ0('c015') = 0;
*TQ.FX('c015') = 0;
TQ0('c015') = -0.05;
 SOLVE STANDCGE_TB USING MCP ;
TQ0('c015') = -0.10;
*TQ0('c015') = TQ00('c015') - 0.1;
*TQ0('c017') = TQ00('c017') - 0.1;
);

*Scenario 5
IF(TAB_Scen05 eq 1,
*RISKfact_prev.FX(RISKfact_set,h)$(ord(RISKfact_set) <> 2) = 0;
RISKfact_prev.FX('r01',h) = 0;
);

*Scenario 6
IF(TAB_Scen06 eq 1,
IF(ord(t1) eq card(tp),
tm0(C) = 0.5*tm00(C);
 SOLVE STANDCGE_TB USING MCP ;
*tm0(C) = 0.001*tm0(C);
);
tm0(C) = 0;
);

*Solve statement
OPTIONS ITERLIM = 5000, MCP=PATHC, DNLP=CONOPT3 ;

*IF(ord(t1) eq card(tp),
*S_TB.FX(h,t1_tb)$(ord(t1_tb) eq 1) = SUM(t1_tbp$(ord(t1_tbp) eq card(t1_tbpp)),S_TB_T0(t1-1,h,t1_tbp)) - 0.05 ;
*L_TB.FX(h,t1_tb)$(ord(t1_tb) eq 1) = SUM(t1_tbp$(ord(t1_tbp) eq card(t1_tbpp)),L_TB_T0(t1-1,h,t1_tbp)) + 0.05 ;
*);

*RISKfact_prev.FX(RISKfact_set,h)$(ord(RISKfact_set) <> 2) = 0;
*RISKfact_prev.FX(RISKfact_set,h) = 0;
*RISKfact_prev.FX('r06',h) = 0;

IF((ord(t1) gt card(tp)),
*qbarg('c064') = qbarg0('c064') + (TBTREAT01*TBTREATcover*TBTREATunitcost*SUM((h,gen,age5),CLINOUToutput(h,'INCID',gen,age5,t1)-CCLINOUToutput(h,'INCID',gen,age5,t1))/CTARGETS('GADJ',t1))*(POPscale/TARGETscale);
qbarg('c029') = qbarg0('c029') + (SUM(DSMDRset,TBTREAT01(DSMDRset)*TBTREATcover(DSMDRset)*TBTREATunitcost(DSMDRset)*DSMDRshr(DSMDRset))*SUM((h,gen,age5),(1-TAB_Scen01*TOTBURDENcost01)*CLINOUToutput(h,'INCID',gen,age5,t1-1)-CCLINOUToutput(h,'INCID',gen,age5,t1-1))/CTARGETS('GADJ',t1))*(POPscale/TARGETscale);
);

*$ontext
*RISKfact_prev.LO('r02',h) = -inf;
*RISKfact_prev.UP('r02',h) = +inf;

* SOLVE STANDCGE USING MCP;
 SOLVE STANDCGE_TB USING MCP ;
*$offtext

RISKfact_prev.FX('r03',h) = SUM(PersonID$(((DHSdata0(h,PersonID,'Weight')+(365*(QHnut_cap_day_final.L(H)-QHnut_cap_day_final0(H))/7715))/POWER(DHSdata0(h,PersonID,'Height')/100,2))<18.5),1)/card(PersonID);
*RISKfact_prev.FX('r03',h) = SUM(PersonID$(((DHSdata0(h,PersonID,'Weight')+((QHnut_cap_day_final.L(H)-QHnut_cap_day_final0(H))/7715))/POWER(DHSdata0(h,PersonID,'Height')/100,2))<18.5),1)/card(PersonID);

$ontext
RISKfact_prev.FX('r02',h) = RISKfact_prev0('r02',h);

 SOLVE STANDCGE_TB_exog USING MCP ;
$offtext

display 'here is walras', WALRAS.L, RGDP.L;

*EV household welfare calculations
*$include welfare_s.inc
*$include welfare.inc

*Retain time-specific output variables in output parameters
$include output_cal_s.inc
$batinclude modDEMOG_sim.inc
$include output_s.inc

*FLABGROWTH(h,flab,t1+1) = SUM((gen,age5),part_rate(gen,age5)*POP(h,gen,age5,t1+1))/SUM((genp,age5p),part_rate(genp,age5p)*POP(h,genp,age5p,t1))-1;
*FLABGROWTH(h,flab,t1+1) = (SUM((gen,age5),part_rate(gen,age5)*(POP(h,gen,age5,t1+1)-(TBHOSP01*TBHOSPperiod + TBISOLAT01*TBISOLATadhere*TBISOLATperiod)*(CLINOUToutput(h,'INCID',gen,age5,t1)-CCLINOUToutput(h,'INCID',gen,age5,t1)))))/SUM((genp,age5p),part_rate(genp,age5p)*POP(h,genp,age5p,t1))-1;
*FLABGROWTH(h,flab,t1+1) = (SUM((gen,age5),part_rate(gen,age5)*(POP(h,gen,age5,t1+1)-((1-TOTBURDENhosp01)*TBHOSP01*TBHOSPperiod + (1-TOTBURDENisolat01)*SUM(DSMDRset,TBISOLAT01(DSMDRset)*TBISOLATadhere(DSMDRset)*TBISOLATperiod(DSMDRset)*DSMDRshr(DSMDRset)))*((1-TAB_Scen01)*CLINOUToutput(h,'INCID',gen,age5,t1)-CCLINOUToutput(h,'INCID',gen,age5,t1)))))/SUM((genp,age5p),part_rate(genp,age5p)*POP(h,genp,age5p,t1))-1;
FLABGROWTH(h,flab,t1+1) = (SUM((gen,age5),part_rate(gen,age5)*(POP(h,gen,age5,t1+1)-(SUM(DSMDRset,TBISOLAT01(DSMDRset)*TBISOLATadhere(DSMDRset)*TBISOLATperiod(DSMDRset)*DSMDRshr(DSMDRset)))*((1-TAB_Scen01*TOTBURDENisolat01)*CLINOUToutput(h,'INCID',gen,age5,t1)-CCLINOUToutput(h,'INCID',gen,age5,t1)))))/SUM((genp,age5p),part_rate(genp,age5p)*POP(h,genp,age5p,t1))-1;

IF(ORD(t1) lt CARD(t1p),
 QFH.FX(h,flnd) = QFH0(h,flnd);
* QFH.FX(h,flab) = (1+FLABGROWTH(h,flab,t1+1))*QFH.L(h,flab);
 QFH.FX(h,flab) = SKLshr0(h,flab)*SUM((gen,age5),part_rate(gen,age5)*(POP(h,gen,age5,t1+1)-(SUM(DSMDRset,TBISOLAT01(DSMDRset)*TBISOLATadhere(DSMDRset)*TBISOLATperiod(DSMDRset)*DSMDRshr(DSMDRset)))*((1-TAB_Scen01*TOTBURDENisolat01)*CLINOUToutput(h,'INCID',gen,age5,t1)-CCLINOUToutput(h,'INCID',gen,age5,t1))));
 QFH.FX(insd,fcap) = QFH.L(insd,fcap)*(1-DPR) + QFHshr(insd,fcap)*(SUM(C, PQ.L(C)*QINV.L(C))/IPI.L)/INVscale;
);

Display 'here is QFS', QFS.L, QFH.L;

);

$include sresults_s_t.inc


$batinclude sexport_s_t.inc 'results.xlsx'

Display RGDP.L, NGDP.L, GDPDEF.L;

