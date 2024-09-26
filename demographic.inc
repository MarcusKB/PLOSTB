
*###############################################################################
*########################### Demographic data inputs ###########################
*###############################################################################

SETS
gentot       gender types             /m,f,total/
gen(gentot)  gender types             /m,f/
age5tot      five-year age groups     /00_04, 05_09, 10_14, 15_19, 20_24, 25_29, 30_34, 35_39, 40_44, 45_49,
                                                     50_54, 55_59, 60_64, 65_69, 70_74, 75_79, 80_, total /
age5(age5tot) five-year age groups     /00_04, 05_09, 10_14, 15_19, 20_24, 25_29, 30_34, 35_39, 40_44, 45_49,
                                                     50_54, 55_59, 60_64, 65_69, 70_74, 75_79, 80_ /

age3aggtot            three aggregate age groups /00_14, 15_64, 65_, total/
age3agg(age3aggtot) three aggregate age groups no totals /00_14, 15_64, 65_/

age5_fert(age5) Fertility five-year age groups    /15_19, 20_24, 25_29, 30_34, 35_39, 40_44, 45_49/
;

ALIAS (gen,genp), (age5,age5p), (age5tot, age5totp);

SETS
mapage3agg(age3aggtot,age5tot)
/
00_14.(00_04,
       05_09,
       10_14)
15_64.(15_19,
       20_24,
       25_29,
       30_34,
       35_39,
       40_44,
       45_49,
       50_54,
       55_59,
       60_64)
65_  .(65_69,
       70_74,
       75_79,
       80_ )
total.(00_04, 05_09, 10_14, 15_19, 20_24, 25_29, 30_34, 35_39, 40_44, 45_49,
       50_54, 55_59, 60_64, 65_69, 70_74, 75_79, 80_)
/
;



PARAMETERS                POP0(t1,gen,age5tot)             Baseline one-year household-specific five-year-age-group population projections (UN World Population Prospects 2019 India population projections)
                          POP00(h,gen,age5tot,t1)          Baseline one-year household-specific five-year-age-group population projections (UN World Population Prospects 2019 India population projections)
                          POP_H0(h,gen,age5tot,t1)         Baseline one-year household-specific five-year-age-group population projections (UN World Population Prospects 2019 India population projections)
                          POP_H00(h,gen,age5tot,t1)        Baseline one-year household-specific five-year-age-group population projections (UN World Population Prospects 2019 India population projections)
                          POP(h,gen,age5tot,t1)            one-year household-specific five-year-age-group population outcomes
                          POPbase(h)                       Base-year (2014) population levels by household h


                          POPTOT0(t1)                      Baseline one-year total population projections (UN World Population Prospects 2019 India population projections)
                          POPTOT(t1)                       Baseline one-year total population projections (UN World Population Prospects 2019 India population projections)
                          POPTOT00(t1)                     CHECK
;

*## Read-in of 2014-2100 part of 2000-2100 UN World Population Prospects 2019 India population projections ('1000)
*$libinclude XLIMPORT POP0 IndiaData2014.xlsx POP0
$libinclude XLIMPORT POP_H0 IndiaData2014.xlsx POP_H0

*POP00(h,gen,age5,t1)  = POP0(t1,gen,age5);
*POP_H0(h,gen,age5,t1) = POP00(h,gen,age5,t1);
POP_H0(h,gen,'total',t1) = SUM(age5,POP_H0(h,gen,age5,t1));

*POP(h,gen,age5tot,t1)$(ord(t1) eq 1) = POP_H0(h,gen,age5tot,t1);
POP(h,gen,age5tot,t1) = POP_H0(h,gen,age5tot,t1);

POPbase(h) = SUM((gen,age5),SUM(t1$(ord(t1) eq 1),POP(h,gen,age5,t1)));

POPTOT(t1) = SUM((h,gen,age5),POP(h,gen,age5,t1));

PARAMETERS                BIRTHS00(h,gen,t1)        Baseline one-year births
                          BIRTHS(h,gen,t1)          one-year birth outcomes
                          DEATHS00(h,gen,age5,t1)   Baseline one-year deaths
                          DEATHS(h,gen,age5,t1)     one-year death outcomes
                          IntlMIGR00(h,gen,age5,t1) Baseline one-year int'l migrants (net)
                          IntlMIGR(h,gen,age5,t1)   one-year int'l migrant outcomes (net)
                          PROBtrans00(h,gen,age5,t1) Baseline transition probabilities
                          PROBtrans(h,gen,age5,t1)  Baseline transition probabilities

                          m_5qx0(t1,gen,age5tot)    Baseline one-year mortality rates
                          m_5qx(gen,age5tot,t1)     one-year mortality rates

                          asfr0(t1,age5_fert)  Baseline one-year age-specific fertility rates
                          asfr(age5_fert,t1)   one-year age-specific fertility rates

                          sr0(t1,gen)                Baseline one-year gender shares at birth (one-year intervals)
                          sr(gen,t1)                 one-year gender shares at birth (one-year intervals)

                          imr0(t1,gen,age5tot)    Baseline one-year int'l migration rates (net)
                          imr00(h,gen,age5tot,t1)    Baseline one-year int'l migration rates (net)
                          imr_h0(h,gen,age5tot,t1)  Baseline one-year int'l migration rates (net)
                          imr_h00(h,gen,age5tot,t1)  Baseline one-year int'l migration rates (net)
                          imr(h,gen,age5tot,t1)     one-year int'l migration rates (net)
                          imr_s0(h,gen,age5tot,t1)    Baseline one-year int'l migration rates (net)

                          PROBtrans_H0(h,gen,age5,t1) Baseline transition probabilities

                          PROBtranstrunc(*,*)
;

*## Read-in of 2014-2100 parameter assumptions derived from 2000-2100 UN World Population Prospects 2019 India population projections
*$libinclude xlimport m_5qx0 IndiaData2014.xlsx m_5qx0
$libinclude xlimport m_5qx0 IndiaData2014.xlsx m_5qx_h0
*$libinclude xlimport asfr0 IndiaData2014.xlsx asfr0
$libinclude xlimport asfr0 IndiaData2014.xlsx asfr_h0
*$libinclude xlimport sr0 IndiaData2014.xlsx sr0
$libinclude xlimport sr0 IndiaData2014.xlsx sr_h0
*$libinclude xlimport imr0 IndiaData2014.xlsx imr0
$libinclude xlimport imr_h0 IndiaData2014.xlsx imr_h0
*$libinclude xlimport PROBtranstrunc IndiaData2014.xlsx PROBtranstrunc
$libinclude xlimport PROBtrans_H0 IndiaData2014.xlsx PROBtrans_H0

option decimals=5;
*Display POP0, m_5qx0, asfr0, sr0, imr0;
Display POP_H0, m_5qx0, asfr0, sr0, imr_h0;

m_5qx(gen,age5tot,t1)   = m_5qx0(t1,gen,age5tot);
asfr(age5_fert,t1)      = asfr0(t1,age5_fert);
sr(gen,t1)              = sr0(t1,gen);

*imr00(h,gen,age5tot,t1) = imr0(t1,gen,age5tot);
imr00(h,gen,age5tot,t1) = imr_h0(h,gen,age5tot,t1);
imr(h,gen,age5tot,t1)   = imr00(h,gen,age5tot,t1);

PROBtrans00(h,gen,age5,t1) = PROBtrans_H0(h,gen,age5,t1);
PROBtrans(h,gen,age5,t1) = PROBtrans00(h,gen,age5,t1);


$ontext


*###############################################################################
*######################## Derive Demographic Projections #######################
*###############################################################################

*## Calculate births by gender
BIRTHS00(h,gen,t1) = sr(gen,t1)*SUM(age5_fert,asfr(age5_fert,t1)*POP00(h,'f',age5_fert,t1-1));

*## Calibrate transition probabilities for first age group 0-4
PROBtrans00(h,gen,'00_04',t1+1) = 1 + (BIRTHS00(h,gen,t1+1)-POP00(h,gen,'00_04',t1+1))/((1-m_5qx(gen,'00_04',t1+1))*(1-imr(h,gen,'00_04',t1+1))*POP00(h,gen,'00_04',t1));

*## Recursively calibrate transition probabilities for later age groups
loop(age5,
loop(t1,
  PROBtrans00(h,gen,age5+1,t1+1)$(ord(age5)+1 <card(age5p))
                              = 1 + (PROBtrans00(h,gen,age5,t1+1)*(1-m_5qx(gen,age5,t1+1))*(1-imr(h,gen,age5,t1+1))*POP00(h,gen,age5,t1) - POP00(h,gen,age5+1,t1+1))
                                                           /((1-m_5qx(gen,age5+1,t1+1))*(1-imr(h,gen,age5+1,t1+1))*POP00(h,gen,age5+1,t1));
);
);


*## Truncate transition probabilities: transition prob's for 80+ age groups = transition prob for 75-79 age group
PROBtrans00(h,gen,age5,t1+1)$(PROBtrans00(h,gen,age5,t1+1) < PROBtranstrunc('PROBtranstrunc','value')) = PROBtranstrunc('PROBtranstrunc','value');


loop(t1,

imr_s0(h,gen,'00_04',t1+1) = 1 + (BIRTHS00(h,gen,t1+1) - POP00(h,gen,'00_04',t1+1))
                                /((1-PROBtrans00(h,gen,'00_04',t1+1))*(1-m_5qx(gen,'00_04',t1+1))*POP00(h,gen,'00_04',t1));

  loop(age5,
  imr_s0(h,gen,age5+1,t1+1)$(ord(age5)+1 < card(age5p))
                              = 1 + (PROBtrans00(h,gen,age5,t1+1)*(1-m_5qx(gen,age5,t1+1))*(1-imr_s0(h,gen,age5,t1+1))*POP00(h,gen,age5,t1) - POP00(h,gen,age5+1,t1+1))
                                   /((1-PROBtrans00(h,gen,age5+1,t1+1))*(1-m_5qx(gen,age5+1,t1+1))*POP00(h,gen,age5+1,t1));
  );

imr_s0(h,gen,age5+1,t1+1)$(ord(age5)+1 = card(age5p))
                              = 1 + (PROBtrans00(h,gen,age5,t1+1)*(1-m_5qx(gen,age5,t1+1))*(1-imr_s0(h,gen,age5,t1+1))*POP00(h,gen,age5,t1) - POP00(h,gen,age5+1,t1+1))
                                   /((1-m_5qx(gen,age5+1,t1+1))*POP00(h,gen,age5+1,t1));
);


loop(t1,

POP00(h,gen,'00_04',t1+1)   = BIRTHS00(h,gen,t1+1) + (1-PROBtrans00(h,gen,'00_04',t1+1))*(1-m_5qx(gen,'00_04',t1+1))*(1-imr_s0(h,gen,'00_04',t1+1))*POP00(h,gen,'00_04',t1);

  loop(age5,
  POP00(h,gen,age5+1,t1+1)$(ord(age5)+1 < card(age5p))
                              = PROBtrans00(h,gen,age5,t1+1)*(1-m_5qx(gen,age5,t1+1))*(1-imr_s0(h,gen,age5,t1+1))*POP00(h,gen,age5,t1)
                              + (1-PROBtrans00(h,gen,age5+1,t1+1))*(1-m_5qx(gen,age5+1,t1+1))*(1-imr_s0(h,gen,age5+1,t1+1))*POP00(h,gen,age5+1,t1);
  );

POP00(h,gen,age5+1,t1+1)$(ord(age5)+1 = card(age5p))
                              = PROBtrans00(h,gen,age5,t1+1)*(1-m_5qx(gen,age5,t1+1))*(1-imr_s0(h,gen,age5,t1+1))*POP00(h,gen,age5,t1)
                              + (1-m_5qx(gen,age5+1,t1+1))*(1-imr_s0(h,gen,age5+1,t1+1))*POP00(h,gen,age5+1,t1);
);

DEATHS00(h,gen,age5,t1+1) = m_5qx(gen,age5,t1+1)*POP00(h,gen,age5,t1);
IntlMIGR00(h,gen,age5,t1+1) = imr_s0(h,gen,age5,t1+1)*(1-m_5qx(gen,age5,t1+1))*POP00(h,gen,age5,t1);


POP(h,gen,age5,t1)      = POP00(h,gen,age5,t1);
BIRTHS(h,gen,t1)        = BIRTHS00(h,gen,t1);
DEATHS(h,gen,age5,t1)   = DEATHS00(h,gen,age5,t1);
IntlMIGR(h,gen,age5,t1) = IntlMIGR00(h,gen,age5,t1);


*PARAMETER DIFF(h,gen,age5,t1)
*;


*## CHECKS
*DIFF(h,gen,age5,t1) = POP00(h,gen,age5,t1) - POP0(t1,gen,age5);
*DIFF(h,gen,age5,t1) = POP00(h,gen,age5,t1) - POP(h,gen,age5,t1);
*DIFF(h,gen,age5,t1) = imr_s0(h,gen,age5,t1) - imr(h,gen,age5,t1);

*option decimals=5;
*Display PROBtrans00, POP00, DIFF;
*Display imr, DIFF;

*loop(t1,
*$batinclude modDEMOG.inc
*);

*DIFF(h,gen,age5,t1) = POP00(h,gen,age5,t1) - POP(h,gen,age5,t1);
*Display DIFF;


$offtext


imr_s0(h,gen,age5,t1) = imr00(h,gen,age5,t1)

loop(t1,
BIRTHS(h,gen,t1+1)          = sr(gen,t1+1)*SUM(age5_fert,asfr(age5_fert,t1+1)*POP(h,'f',age5_fert,t1));

DEATHS(h,gen,age5,t1+1) = m_5qx(gen,age5,t1+1)*POP(h,gen,age5,t1);

IntlMIGR(h,gen,age5,t1+1) = imr_s0(h,gen,age5,t1+1)*(1-m_5qx(gen,age5,t1+1))*POP(h,gen,age5,t1);

POP(h,gen,'00_04',t1+1)     = BIRTHS(h,gen,t1+1) + (1-PROBtrans00(h,gen,'00_04',t1+1))*(1-m_5qx(gen,'00_04',t1+1))*(1-imr_s0(h,gen,'00_04',t1+1))*POP(h,gen,'00_04',t1);

POP(h,gen,age5+1,t1+1)$(ord(age5)+1 < card(age5p))  = PROBtrans00(h,gen,age5,t1+1)*(1-m_5qx(gen,age5,t1+1))*(1-imr_s0(h,gen,age5,t1+1))*POP(h,gen,age5,t1)
                                                 + (1-PROBtrans00(h,gen,age5+1,t1+1))*(1-m_5qx(gen,age5+1,t1+1))*(1-imr_s0(h,gen,age5+1,t1+1))*POP(h,gen,age5+1,t1);

POP(h,gen,age5+1,t1+1)$(ord(age5)+1 = card(age5p))  = PROBtrans00(h,gen,age5,t1+1)*(1-m_5qx(gen,age5,t1+1))*(1-imr_s0(h,gen,age5,t1+1))*POP(h,gen,age5,t1)
                                                 + (1-m_5qx(gen,age5+1,t1+1))*(1-imr_s0(h,gen,age5+1,t1+1))*POP(h,gen,age5+1,t1);
);





PARAMETER DIFF01(h,gen,age5,t1), DIFF02(h,gen,age5,t1), DIFF03(h,gen,age5,t1), DIFF04(h,gen,age5,t1), DIFF05(h,gen,age5,t1);

*DIFF01(h,gen,age5,t1) = BIRTHS(h,gen,t1) - BIRTHS00(h,gen,t1);
*DIFF02(h,gen,age5,t1) = DEATHS(h,gen,age5,t1) - DEATHS00(h,gen,age5,t1);
*DIFF03(h,gen,age5,t1) = IntlMIGR(h,gen,age5,t1) - IntlMIGR00(h,gen,age5,t1);
*DIFF04(h,gen,age5,t1) = POP(h,gen,age5,t1) - POP00(h,gen,age5,t1);
DIFF04(h,gen,age5,t1) = POP(h,gen,age5,t1) - POP_H0(h,gen,age5,t1);

*Display 'here are births', DIFF01, BIRTHS, BIRTHS00;
*Display 'here are deaths', DIFF02, DEATHS, DEATHS00;
*Display 'here is migration', DIFF03, IntlMIGR, IntlMIGR00;
*Display 'here is population',  DIFF04, POP, POP00;
Display 'here is population',  DIFF04, POP, POP_H0;
