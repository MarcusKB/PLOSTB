
* Read in growth parameters

PARAMETER
DPR PWT10_0 Depreciation rate for India / 0.053 /
*CAPSCALE Scaling of investment / 0.10 /
;

* Establish base period factor ownership incl. labour force derived from household-specific population

PARAMETERS part_rate00(gentot,age5) Labour force participation rate by gender baseline
           part_rate(gentot,age5)   Labour force participation rate by gender
           SKLshr0(h,flab)          Initial labour force skill shares (by gender and household type)

           QFSBASE00(F,t1)         Baseline physical factor stocks
           QFSBASE0(F,t1)          Baseline physical factor stocks
           QFSBASE(F)              Baseline physical factor stocks (initial period)
           QFBASE0(F,A,t1)         qnty of factor f employed by activity a
           QFBASE(F,A)             qnty of factor f employed by activity a (initial period)

           QFSHBASE00(insd,f)      Baseline physical factor ownership
           QFSHBASE0(insd,f,t1)    Baseline physical factor ownership
           QFSHBASE(insd,f)        Baseline physical factor ownership (initial period)

           QFHshr(insd,f)          Factor ownership shares in initial period (focus: non-labour income allocation across institutions)

           FLABGROWTH0(h,flab,t1)  Urban-rural labor force growth rates
           FLABGROWTH(h,flab,t1)   Urban-rural labor force growth rates
;

QFBASE0(F,A,t1) = 0;
*QFBASE0(F,A,t1)$(ord(t1) eq 1) = QFBASE00(F,A);
QFBASE(F,A) = SUM(t1$(ord(t1) eq 1), QFBASE0(F,A,t1));

$libinclude XLIMPORT PART_RATE00 IndiaData2014.xlsx PART_RATE00

part_rate(gentot,age5) = part_rate00(gentot,age5);

*Household-specific 2014 labour force skill shares (non-gender specific)
*SKLshr0(h,flab) = QFSHBASE00(h,flab)/SUM(flabp,QFSHBASE00(h,flabp));
SKLshr0(h,flab) = SAM(h,flab)/SUM(flabp,SAM(h,flabp));

Display SKLshr0;

$libinclude XLIMPORT QFSBASE00 IndiaData2014.xlsx QFSBASE00

QFSBASE0(F,t1) = QFSBASE00(F,t1);
QFSBASE(F) = SUM(t1$(ord(t1) eq 1), QFSBASE0(F,t1));

$libinclude XLIMPORT QFSHBASE00 IndiaData2014.xlsx QFSHBASE00

QFSHBASE0(insd,f,t1)$(ord(t1) eq 1) = QFSHBASE00(insd,f);
QFSHBASE(insd,f) = SUM(t1$(ord(t1) eq 1), QFSHBASE0(insd,f,t1));

QFHshr(insd,f) = QFSHBASE(insd,f)/SUM(insdp,QFSHBASE(insdp,f));

Display QFSHBASE0, QFHshr;

SKLshr0(h,flab) = QFSHBASE(h,flab)/SUM(flabp,QFSHBASE(h,flabp));

Display SKLshr0;

QFSBASE(flab) = SUM(t1$(ord(t1) eq 1),SUM((hp,genp,age5p),SKLshr0(hp,flab)*part_rate(genp,age5p)*POP_H0(hp,genp,age5p,t1)));

*## HOUSEHOLD labour factor growth rates
FLABGROWTH0(h,flab,t1+1) = SUM((gen,age5),part_rate(gen,age5)*POP_H0(h,gen,age5,t1+1))/SUM((genp,age5p),part_rate(genp,age5p)*POP_H0(h,genp,age5p,t1))-1;
FLABGROWTH(h,flab,t1) = FLABGROWTH0(h,flab,t1);

Display FLABGROWTH;

loop(t1,
QFSHBASE0(h,flab,t1+1) = (1+FLABGROWTH(h,flab,t1+1))*QFSHBASE0(h,flab,t1);
);

Display QFSHBASE0;

QFSHBASE(h,flab) = SKLshr0(h,flab)*SUM(t1$(ord(t1) eq 1),SUM((genp,age5p),part_rate(genp,age5p)*POP_H0(h,genp,age5p,t1)));

*PARAMETER POPAGG1(gen,age5), POPAGG2(age5);
*POPAGG1(gen,age5) = SUM(t1$(ord(t1) eq 1),SUM(h,POP_H0(h,gen,age5,t1)));
*POPAGG2(age5) = SUM(gen,part_rate(gen,age5)*POPAGG1(gen,age5));
