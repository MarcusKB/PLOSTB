
*###############################################################################
*##########  Counterfactual Dynamic CGE (cdyncge) simulation program  ##########
*###############################################################################




*Use GDP deflator as price numeraire (it will be allowed to vary to target nominal GDP below)
 GDPDEF.FX = GDPDEF.L;
 CPI.LO = -inf;
 CPI.UP = +inf;
* CPI.FX    = CPI.L;
* GDPDEF.LO = -inf;
* GDPDEF.UP = +inf;

loop(t1$ts(t1),

*In counterfactual: Use balanced macro closure, i.e. constant government consumption share of total absorption
*In simulation: Use counterfactual growth path of government demand (GDN)
*NB: GOVSHR.L refers to the govt consumption share of absorption in the model solution for 2010 (tp07) in presim.gms
 GADJ.LO     = -inf;
 GADJ.UP     = +inf;
 GOVSHR.FX   = GOVSHR.L ;
* GSAV.FX   = (TARGETS_SIM('NGDP',t1)/TARGETS_SIM('RGDP',t1))*GSAV0 ;
* GADJ.LO     = -inf;
* GADJ.UP     = +inf;

* GDN.FX      = CTARGETS('GDN',t1) ;
*);

IF(ord(t1) gt card(tp),
*Use final week solution from previous year as initial week value for new year
S_TB.FX(h,t1_tb)$(ord(t1_tb) eq 1) = SUM(t1_tbp$(ord(t1_tbp) eq card(t1_tbpp)),S_TB.L(h,t1_tbp)) ;
L_TB.FX(h,t1_tb)$(ord(t1_tb) eq 1) = SUM(t1_tbp$(ord(t1_tbp) eq card(t1_tbpp)),L_TB.L(h,t1_tbp)) ;
I_TB.FX(h,t1_tb)$(ord(t1_tb) eq 1) = SUM(t1_tbp$(ord(t1_tbp) eq card(t1_tbpp)),I_TB.L(h,t1_tbp)) ;
Ir_TB.FX(h,t1_tb)$(ord(t1_tb) eq 1) = SUM(t1_tbp$(ord(t1_tbp) eq card(t1_tbpp)),Ir_TB.L(h,t1_tbp)) ;
T_TB.FX(h,t1_tb)$(ord(t1_tb) eq 1) = SUM(t1_tbp$(ord(t1_tbp) eq card(t1_tbpp)),T_TB.L(h,t1_tbp)) ;
Tr_TB.FX(h,t1_tb)$(ord(t1_tb) eq 1) = SUM(t1_tbp$(ord(t1_tbp) eq card(t1_tbpp)),Tr_TB.L(h,t1_tbp)) ;
*Fix Nominal GDP + release GDP deflator (price numeraire)
 GDPDEF.LO = -inf;
 GDPDEF.UP = +inf;
 NGDP.FX   = TARGETS_SIM('NGDP',t1) ;
* GDPDEF.FX = TARGETS_SIM('NGDP',t1)/TARGETS_SIM('RGDP',t1) ;
* NGDP.LO = -inf;
* NGDP.UP = +inf;

*Fix Real GDP + release (avg.) Total Factor Productivity parameter
 TFPadj.LO = -inf;
 TFPadj.UP = +inf;
 RGDP.FX = TARGETS_SIM('RGDP',t1) ;
* TFPadj.FX = CTARGETS('TFPadj',t1) ;
* RGDP.LO = -inf;
* RGDP.UP = +inf;

* YG.FX = CTARGETS('YG',t1) ;
* DTINS.LO = -inf;
* DTINS.UP = +inf;
);

*Solve statement
OPTIONS ITERLIM = 5000, MCP=PATHC, DNLP=CONOPT3 ;

*$ontext
*RISKfact_prev.LO('r02',h) = -inf;
*RISKfact_prev.UP('r02',h) = +inf;

* SOLVE STANDCGE USING MCP;
 SOLVE STANDCGE_TB USING MCP ;
*$offtext

RISKfact_prev.FX('r03',h) = SUM(PersonID$(((DHSdata0(h,PersonID,'Weight')+(365*(QHnut_cap_day_final.L(H)-QHnut_cap_day_final0(H))/7715))/POWER(DHSdata0(h,PersonID,'Height')/100,2))<18.5),1)/card(PersonID);

$ontext
RISKfact_prev.FX(RISKfact_set,h) = RISKfact_prev0(RISKfact_set,h);

 SOLVE STANDCGE_TB_exog USING MCP ;
$offtext

display 'here is walras', WALRAS.L, RGDP.L, RISKFACT_prev.L;

display 'here are demographics', BIRTHS, DEATHS, IntlMIGR, POP;

*EV household welfare calculations
*$include welfare_s.inc
*$include welfare.inc

*Retain time-specific output variables in output parameters
$include output_cal_s.inc
$batinclude modDEMOG.inc
$include output_s.inc

FLABGROWTH(h,flab,t1+1) = SUM((gen,age5),part_rate(gen,age5)*POP(h,gen,age5,t1+1))/SUM((genp,age5p),part_rate(genp,age5p)*POP(h,genp,age5p,t1))-1;


IF(ORD(t1) lt CARD(t1p),
 QFH.FX(h,flnd) = QFH0(h,flnd);
* QFH.FX(h,flab) = (1+FLABGROWTH(h,flab,t1+1))*QFH.L(h,flab);
 QFH.FX(h,flab) = SKLshr0(h,flab)*SUM((genp,age5p),part_rate(genp,age5p)*POP(h,genp,age5p,t1+1));
 QFH.FX(insd,fcap) = QFH.L(insd,fcap)*(1-DPR) + QFHshr(insd,fcap)*(SUM(C, PQ.L(C)*QINV.L(C))/IPI.L)/INVscale;
);

Display 'here is QFS', QFS.L, QFH.L, FLABGROWTH, FLABGROWTH0;

);

$include cresults_s_t.inc

$batinclude counterfactual_s_t.inc 'counterfactual.xlsx'
$batinclude cexport_s_t.inc 'results.xlsx'

Display RGDP.L, NGDP.L, GDPDEF.L;

Display S_TB_T0, POP_TB_T0;

