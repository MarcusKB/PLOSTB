
*## Pre-simulation running-forward of recursively-dynamic CGE model (over pre-simulation period tp)

PARAMETER TARGETS_SIM(NMACRO_AGG,t1)    Nominal Macro Aggregates for Pre-simulation Targeting
;

*$libinclude xlimport POP_PRESIM0    SAM.xlsx POP_PRESIM
$libinclude xlimport TARGETS_SIM IndiaData2014.xlsx TARGETS_SIM

*TARGETS_SIM(NMACRO_AGG,tp) = TARGETS_SIM(NMACRO_AGG,tp)/TARGETscale;
TARGETS_SIM(NMACRO_AGG,tp) = TARGETS_SIM(NMACRO_AGG,tp);

*Use GDP deflator as price numeraire (it will be allowed to vary to target nominal GDP below)
 GDPDEF.FX = GDPDEF0;
 CPI.LO = -inf;
 CPI.UP = +inf;

*Use Balanced Macro Closure
* GADJ.LO     = -inf;
* GADJ.UP     = +inf;
* GOVSHR.FX   = GOVSHR0 ;


loop(t1$tp(t1),

IF(ORD(t1) gt 1,
*Use final week solution from previous year as initial week value for new year
S_TB.FX(h,t1_tb)$(ord(t1_tb) eq 1) = SUM(t1_tbp$(ord(t1_tbp) eq card(t1_tbpp)),S_TB.L(h,t1_tbp)) ;
L_TB.FX(h,t1_tb)$(ord(t1_tb) eq 1) = SUM(t1_tbp$(ord(t1_tbp) eq card(t1_tbpp)),L_TB.L(h,t1_tbp)) ;
I_TB.FX(h,t1_tb)$(ord(t1_tb) eq 1) = SUM(t1_tbp$(ord(t1_tbp) eq card(t1_tbpp)),I_TB.L(h,t1_tbp)) ;
Ir_TB.FX(h,t1_tb)$(ord(t1_tb) eq 1) = SUM(t1_tbp$(ord(t1_tbp) eq card(t1_tbpp)),Ir_TB.L(h,t1_tbp)) ;
T_TB.FX(h,t1_tb)$(ord(t1_tb) eq 1) = SUM(t1_tbp$(ord(t1_tbp) eq card(t1_tbpp)),T_TB.L(h,t1_tbp)) ;
Tr_TB.FX(h,t1_tb)$(ord(t1_tb) eq 1) = SUM(t1_tbp$(ord(t1_tbp) eq card(t1_tbpp)),Tr_TB.L(h,t1_tbp)) ;
*Use Balanced Macro Closure
 GADJ.LO     = -inf;
 GADJ.UP     = +inf;
 GOVSHR.FX   = GOVSHR0 ;
* GSAV.FX     = (TARGETS_SIM('NGDP',t1)/TARGETS_SIM('RGDP',t1))*GSAV0 ;

*Fix Nominal GDP + release GDP deflator (price numeraire)
 GDPDEF.LO = -inf;
 GDPDEF.UP = +inf;
 NGDP.FX   = TARGETS_SIM('NGDP',t1) ;

*Fix Real GDP + release (avg.) Total Factor Productivity parameter
 TFPadj.LO = -inf;
 TFPadj.UP = +inf;
 RGDP.FX   = TARGETS_SIM('RGDP',t1) ;

*$ontext
*Fix Nominal Government Consumption + release fixed Government Share parameter
* GADJ.LO   = -inf;
* GADJ.UP   = +inf;
* NCG.FX    = TARGETS_PRESIM('NCG',t1) ;

*Fix Nominal Investment + release proportional Haousehold Savings Rate parameter
* mps01(INSDNG) = 1;
* MPSADJ.LO  = -inf;
* MPSADJ.UP  = +inf;
* DMPS.FX    = DMPS0;
* NINV.FX    = TARGETS_PRESIM('NINV',t1) ;
*$ontext
*Fix Nominal Exports + release fixed Avg Level of World Market Expport Price parameter
* PWElev.LO = -inf;
* PWElev.UP = +inf;
* DELTATadj.LO = -inf;
* DELTATadj.UP = +inf;
* NEXP.FX   = TARGETS_PRESIM('NEXP',t1) ;

*Fix Nominal Imports + release fixed Avg Level of World Market Impport Price parameter
* PWMlev.LO = -inf;
* PWMlev.UP = +inf;
* DELTAQadj.LO = -inf;
* DELTAQadj.UP = +inf;
* NIMP.FX   = TARGETS_PRESIM('NIMP',t1) ;

*Fix Exchange Rate + release Current Account Deficit parameter
* FSAV.LO = -inf;
* FSAV.UP = +inf;
* EXR.FX  = (TARGETS_PRESIM('EXR',t1)/TARGETS_PRESIM('EXR','t004'))*EXR0;
*$offtext

* QFS.FX(flab)      = QFS_PRESIM(flab,t1);
* QFH.FX(insd,flab) = QFH_PRESIM(insd,flab,t1);
* QFS.FX(flab)                    = SUM(gen$mapgflab(gen,flab),SUM(h$maphflab(h,flab),
*                         SKLshr0(h,flab)*SUM(age$mapage3agg('15_64',age),PART_RATE(gen,'p_rate')*POP0(h,gen,age,t1))));
* QFH.FX(h,flab)$maphflab(h,flab) = SUM(gen$mapgflab(gen,flab),
*                         SKLshr0(h,flab)*SUM(age$mapage3agg('15_64',age),PART_RATE(gen,'p_rate')*POP0(h,gen,age,t1)));

* QFS.FX(flab) = QFS00(flab,t1);
* QFH.FX(h,flab)$maphflab(h,flab) = QFH00(h,flab,t1);
);


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

 display 'here is walras', WALRAS.L, NGDP.L, RGDP.L, NCG.L, NINV.L, NEXP.L, NIMP.L, EXR.L, FSAV.L, CPI_H.L, QH.L, QFS.L, TFPadj.L;

$batinclude modDEMOG.inc

 display 'here are demographics', BIRTHS, DEATHS, IntlMIGR, POP;


$include output_cal_s.inc
$include output_s.inc


IF(ORD(t1) lt card(tp),
 QFH.FX(h,flnd) = QFH0(h,flnd);
* QFH.FX(h,flab) = (1+FLABGROWTH(h,flab,t1))*QFH.L(h,flab);
 QFH.FX(h,flab) = SKLshr0(h,flab)*SUM((genp,age5p),part_rate(genp,age5p)*POP(h,genp,age5p,t1+1));
 QFH.FX(insd,fcap) = QFH.L(insd,fcap)*(1-DPR) + QFHshr(insd,fcap)*(SUM(C, PQ.L(C)*QINV.L(C))/IPI.L)/INVscale;
);


*Display 'here is flabgrowth', FLABGROWTH_PRESIM, TFPadj.L;

);

*## CHECKS
PARAMETER DIFF(h,gen,age5,t1);
*DIFF(h,gen,age5,t1) = POP(h,gen,age5,t1) - POP00(h,gen,age5,t1);
DIFF(h,gen,age5,t1) = POP(h,gen,age5,t1) - POP_H0(h,gen,age5,t1);

Display DIFF;

*$include preresults.inc

*$include preexport.inc

 NGDP.LO   = -inf;
 NGDP.UP   = +inf;
 GDPDEF.FX = GDPDEF.L ;

 RGDP.LO   = -inf;
 RGDP.UP   = +inf;
 TFPadj.FX = TFPadj.L;
*$ontext
 NCG.LO    = -inf;
 NCG.UP    = +inf;
 GADJ.FX   = GADJ.L ;

 mps01(INSDNG) = 1;
 NINV.LO   = -inf;
 NINV.UP   = +inf;
 DMPS.FX   = DMPS0;
 MPSADJ.FX = MPSADJ.L ;
*$ontext
 NEXP.LO   = -inf;
 NEXP.UP   = +inf;
 DELTATadj.FX = DELTATadj.L;
* PWElev.FX = PWElev.L ;

 NIMP.LO   = -inf;
 NIMP.UP   = +inf;
 DELTAQadj.FX = DELTAQadj.L;
* PWMlev.FX = PWMlev.L ;

 EXR.LO    = -inf;
 EXR.UP    = +inf;
 FSAV.FX   = FSAV.L;
*$offtext

 GSAV.LO   = -inf;
 GSAV.UP   = +inf;
 GOVSHR.LO = -inf;
 GOVSHR.UP = +inf;
 GADJ.FX = GADJ.L ;

$ontext
 SOLVE STANDCGE USING MCP ;

 display 'here is walras', WALRAS.L , TFPadj.L, NGDP.L, RGDP.L, NCG.L, NINV.L, NEXP.L, NIMP.L, EXR.L, FSAV.L ;
$offtext
