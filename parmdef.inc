
SET
MAPAC(A,C)  Mapping between activities and commodities (with non-diagonal MAKE matrix)
/
a001.c001
a002.c002
a003.c003
a004.c004
a005.c005
a006.c006
a007.c007
a008.c008
a009.c009
a010.c010
a011.c011
a012.c012
a013.c013
a014.c014
a015.c015
a016.c016
a017.c017
a018.c018
a019.c019
a020.c020
a021.c021
a022.c022
a023.c023
a024.c024
a025.c025
a026.c026
a027.c027
a028.c028
a029.c029
a030.c030
a031.c031
/
;

*###############################################################################
*############ SECTION 1: Basic Structural Characteristics of Economy ###########
*###############################################################################

SET     NMACRO_AGG  Macro Aggregates for targeting over pre-simulation period / NGDP, RGDP, GDP_DEF /
;

SET
MACSET              Macroeconomic aggregates set
/
GDP_R               Real GDP
ABSORP_R            Real Absorption
CP_R                Real Private Consumption
CG_R                Real Government Consumption
IV_R                Real Investment
EXP_R               Real Exports
IMP_R               Real Imports
GDP_N               Nominal GDP
ABSORP_N            Nominal Absorption
CP_N                Nominal Private Consumption
CG_N                Nominal Government Consumption
IV_N                Nominal Investment
EXP_N               Nominal Exports
IMP_N               Nominal Imports
/

MAC                 Macro SAM accounts set incl. TOTAL
/
ACT                 Activity account
COM                 Commodity account
TRD                 Trade & Transport account
FAC                 Factor account
HOU                 Household account
GOV                 Government account
ACTTAX              Activity Tax account
VATAX               Value Added Tax account
COMTAX              Commodity Tax account
IMPTAX              Import Tax account
EXPTAX              Export Tax account
FACTAX              Factor Tax account
INSTAX              Institutional Tax account
S-I                 Savings-Investment account
ROW                 Rest of the World account
TOTAL               Totals
DUMMY               Dummy
/

MACNT(MAC)          Macro SAM accounts set excl. TOTAL

STRUCHARSET         Sectoral structural characteristics set
/
VAshr               Value Added share by commodity c
OUTshr              Output share by commodity c
DEMshr              Demand share by commodity c
EXPshr              Export share by commodity c
IMPshr              Import share by commodity c
EXP-OUTshr          Export-Output share by commodity c
IMP-DEMshr          Import-Demand share by commodity c
/
;

MACNT(MAC) = yes;
MACNT('TOTAL') = no;
MACNT('DUMMY') = no;

ALIAS (MAC,MACP), (MACNT,MACNTP) ;

;

PARAMETER MACRO(MACSET,t1)               Macro-level structure of the economy (demand side aggregates)
          CMACRO(MACSET,t1)              Counterfactual macro-level structure of the economy (demand side aggregates) (for calculation of simulation results)
          SMACRO(MACSET,t1)              Simulation macro-level structure of the economy (demand side aggregates)
          PREMACRO(MACSET,t1)            Pre-simulation macro-level structure of the economy (demand side aggregates)
          MACRO_DEF(MACSET,t1)           Macro-level deflated nominal structure of the economy (nominal demand side aggregates deflated by price numeraire)
          CMACRO_DEF(MACSET,t1)          Counterfactual deflated nominal macro-level structure of the economy (nominal demand side aggregates deflated by price numeraire) (for calculation of simulation results)
          SMACRO_DEF(MACSET,t1)          Simulation deflated nominal macro-level structure of the economy (nominal demand side aggregates deflated by price numeraire)
          PREMACRO_DEF(MACSET,t1)        Pre-simulation deflated nominal macro-level structure of the economy (nominal demand side aggregates deflated by price numeraire)
          C_MACRO(t1,MACSET,*)           Counterfactual macro-level structure of the economy (demand side aggregates) (for calculation of structural characteristics of economy)
          S_MACRO(t1,MACSET,*)           Simulation macro-level structure of the economy (demand side aggregates) (for calculation of structural characteristics of economy)
          PRE_MACRO(t1,MACSET,*)         Pre-simulation macro-level structure of the economy (demand side aggregates) (for calculation of structural characteristics of economy)
          MACROpercap(MACSET,t1)         Macro-level (per capita) structure of the economy (demand side aggregates) (for calculation of simulation results)
          CMACROpercap(MACSET,t1)        Counterfactual macro-level (per capita) structure of the economy (demand side aggregates) (for calculation of simulation results)
          SMACROpercap(MACSET,t1)        Simulation macro-level (per capita) structure of the economy (demand side aggregates) (for calculation of simulation results)
          PREMACROpercap(MACSET,t1)      Pre-simulation macro-level (per capita) structure of the economy (demand side aggregates) (for calculation of simulation results)
          MACROpercap_DEF(MACSET,t1)     Deflated nominal macro-level (per capita) structure of the economy (nominal demand side aggregates deflated by price numeraire) (for calculation of simulation results)
          CMACROpercap_DEF(MACSET,t1)    Counterfactual deflated nominal macro-level (per capita) structure of the economy (nominal demand side aggregates deflated by price numeraire) (for calculation of simulation results)
          SMACROpercap_DEF(MACSET,t1)    Simulation deflated nominal macro-level (per capita) structure of the economy (nominal demand side aggregates deflated by price numeraire) (for calculation of simulation results)
          PREMACROpercap_DEF(MACSET,t1)  Pre-simulation deflated nominal macro-level (per capita) structure of the economy (nominal demand side aggregates deflated by price numeraire) (for calculation of simulation results)
          MACSAM(t1,MAC,MACP)            Macro-level structure of the economy (Macro SAMs)
          CMACSAM(t1,MAC,MACP)           Counterfactual macro-level structure of the economy (Macro SAMs)
          SMACSAM(t1,MAC,MACP)           Simulation macro-level structure of the economy (Macro SAMs)
          STRUCHAR(t1,AC,STRUCHARSET)    Sector-level structural characteristics (demand and supply side)
          CSTRUCHAR(t1,AC,STRUCHARSET)   Counterfactual sector-level structural characteristics (demand and supply side)
          SSTRUCHAR(t1,AC,STRUCHARSET)   Simulation sector-level structural characteristics (demand and supply side)

          MACRO_CO(MACSET)               Macro-level structure of the economy (demand side aggregates)
          CMACRO_CO(MACSET)              Counterfactual macro-level structure of the economy (demand side aggregates) (for calculation of simulation results)
          SMACRO_CO(MACSET)              Simulation macro-level structure of the economy (demand side aggregates)
          PREMACRO_CO(MACSET)            Pre-simulation macro-level structure of the economy (demand side aggregates)
          MACRO_DEF_CO(MACSET)           Macro-level deflated nominal structure of the economy (nominal demand side aggregates deflated by price numeraire)
          CMACRO_DEF_CO(MACSET)          Counterfactual deflated nominal macro-level structure of the economy (nominal demand side aggregates deflated by price numeraire) (for calculation of simulation results)
          SMACRO_DEF_CO(MACSET)          Simulation deflated nominal macro-level structure of the economy (nominal demand side aggregates deflated by price numeraire)
          PREMACRO_DEF_CO(MACSET)        Pre-simulation deflated nominal macro-level structure of the economy (nominal demand side aggregates deflated by price numeraire)
          C_MACRO_CO(MACSET,*)           Counterfactual macro-level structure of the economy (demand side aggregates) (for calculation of structural characteristics of economy)
          S_MACRO_CO(MACSET,*)           Simulation macro-level structure of the economy (demand side aggregates) (for calculation of structural characteristics of economy)
          PRE_MACRO_CO(MACSET,*)         Pre-simulation macro-level structure of the economy (demand side aggregates) (for calculation of structural characteristics of economy)
          MACROpercap_CO(MACSET)         Macro-level (per capita) structure of the economy (demand side aggregates) (for calculation of simulation results)
          CMACROpercap_CO(MACSET)        Counterfactual macro-level (per capita) structure of the economy (demand side aggregates) (for calculation of simulation results)
          SMACROpercap_CO(MACSET)        Simulation macro-level (per capita) structure of the economy (demand side aggregates) (for calculation of simulation results)
          PREMACROpercap_CO(MACSET)      Pre-simulation macro-level (per capita) structure of the economy (demand side aggregates) (for calculation of simulation results)
          MACROpercap_DEF_CO(MACSET)     Deflated nominal macro-level (per capita) structure of the economy (nominal demand side aggregates deflated by price numeraire) (for calculation of simulation results)
          CMACROpercap_DEF_CO(MACSET)    Counterfactual deflated nominal macro-level (per capita) structure of the economy (nominal demand side aggregates deflated by price numeraire) (for calculation of simulation results)
          SMACROpercap_DEF_CO(MACSET)    Simulation deflated nominal macro-level (per capita) structure of the economy (nominal demand side aggregates deflated by price numeraire) (for calculation of simulation results)
          PREMACROpercap_DEF_CO(MACSET)  Pre-simulation deflated nominal macro-level (per capita) structure of the economy (nominal demand side aggregates deflated by price numeraire) (for calculation of simulation results)
          MACSAM_CO(MAC,MACP)            Macro-level structure of the economy (Macro SAMs)
          CMACSAM_CO(MAC,MACP)           Counterfactual macro-level structure of the economy (Macro SAMs)
          SMACSAM_CO(MAC,MACP)           Simulation macro-level structure of the economy (Macro SAMs)
          STRUCHAR_CO(AC,STRUCHARSET)    Sector-level structural characteristics (demand and supply side)
          CSTRUCHAR_CO(AC,STRUCHARSET)   Counterfactual sector-level structural characteristics (demand and supply side)
          SSTRUCHAR_CO(AC,STRUCHARSET)   Simulation sector-level structural characteristics (demand and supply side)
;

*###############################################################################
*################### SECTION 2: Real multi-sector quantities ###################
*###############################################################################

*$ontext
SET
QUANTSET_C          Quantities set for commodities
/
  QD_CT             Domestic sales
  QE_CT             Exports
  QG_CT             Government consumption
  QINV_CT           Fixed investment demand
  QM_CT             Imports
  QQ_CT             Composite goods supply
  QT_CT             Trade and transport demand
  QX_CT             Aggregate marketed commodity output
/

PRICESET_C          Quantities set for commodities
/
  PDD_CT            Domestic sales prices (demand)
  PDS_CT            Domestic sales prices (supply)
  PE_CT             Export prices
  PM_CT             Import prices
  PQ_CT             Composite goods prices
  PX_CT             Aggregate marketed commodity output
/
;

*Consumption quantities and prices
PARAMETER QUANT_C(QUANTSET_C,C,t1)       Quantities for commodity by time
          CQUANT_C(QUANTSET_C,C,t1)      Counterfactual Quantities for commodity by time
          SQUANT_C(QUANTSET_C,C,t1)      Simulation Quantities for commodity by time
          PRICE_C(PRICESET_C,C,t1)       Prices for commodity by time
          CPRICE_C(PRICESET_C,C,t1)      Counterfactual Prices for commodity by time
          SPRICE_C(PRICESET_C,C,t1)      Simulation Prices for commodity by time
;

*$offtext
SET
QUANTSET_A          Quantities set for activities
/
  QA_AT             Aggregate production activity output
  QINTA_AT          Aggregate intermediate input
  QVA_AT            Aggregate value added
/

PRICESET_A          Prices set for activities
/
  PA_AT             Aggregate production activity prices
  PINTA_AT          Aggregate intermediate input prices
  PVA_AT            Aggregate value added prices
/
;

*Production quantities and prices
PARAMETER QUANT_A(QUANTSET_A,A,t1)       Quantities for commodity by time
          CQUANT_A(QUANTSET_A,A,t1)      Counterfactual Quantities for commodity by time
          SQUANT_A(QUANTSET_A,A,t1)      Simulation Quantities for commodity by time
          PRICE_A(PRICESET_A,A,t1)       Price for commodity by time
          CPRICE_A(PRICESET_A,A,t1)      Counterfactual Price for commodity by time
          SPRICE_A(PRICESET_A,A,t1)      Simulation Price for commodity by time
;

SET
QUANTSET_F          Quantities set for factors
/
  QF_FT             Factor demand by production activity
/

PRICESET_F          Quantities set for factors
/
  WF_FT             Factor price by production activity
/
;

*Factor demand and prices
PARAMETER QUANT_F(QUANTSET_F,F,t1)    Quantities for factor demand (and supply) by time
          CQUANT_F(QUANTSET_F,F,t1)   Counterfactual Quantities for factor demand (and supply) by time
          SQUANT_F(QUANTSET_F,F,t1)   Simulation Quantities for factor demand (and supply) by time
          PRICE_F(PRICESET_F,F,t1)    Factor prices by time
          CPRICE_F(PRICESET_F,F,t1)   Counterfactual Factor prices by time
          SPRICE_F(PRICESET_F,F,t1)   Simulation Factor prices by time
;


*###############################################################################
*######################### SECTION 3: Government budget ########################
*###############################################################################

SET       GSET      Government budget set
/
  CG                Government consumption
  TG                Government transfers
  YG                Government income
/ ;

PARAMETER GOV(GSET,t1)                   Government budget variables
          CGOV(GSET,t1)                  Counterfactual Government budget variables
          SGOV(GSET,t1)                  Simulation Government budget variables

          GOV_CO(GSET)                   Government budget variables
          CGOV_CO(GSET)                  Counterfactual Government budget variables
          SGOV_CO(GSET)                  Simulation Government budget variables
;

SET TAXRATESET      Government tax rates set
/
TA                  producer output value tax rates
TQ                  sales tax rates
TH                  household direct tax rates
/
;

PARAMETER TAXRATE(TAXRATESET,AC,t1)      Government tax rates
          CTAXRATE(TAXRATESET,AC,t1)     Counterfactual Government tax rates
          STAXRATE(TAXRATESET,AC,t1)     Simulation Government tax rates

          TAXRATE_CO(TAXRATESET,AC)      Government tax rates
          CTAXRATE_CO(TAXRATESET,AC)     Counterfactual Government tax rates
          STAXRATE_CO(TAXRATESET,AC)     Simulation Government tax rates
;


*###############################################################################
*######################### SECTION 4: Household budget #########################
*###############################################################################

SET
QUANTSET_CH
/
  QH_CHT            Quantity consumed commodity c by h
/
;

SET
QUANTSET_ACH
/
  QHA_ACHT          Quantity consumed of home commodity c from a by h
/
;

PARAMETER HCON(C,H,t1)                   Real household consumption
          CHCON(C,H,t1)                  Counterfactual real household consumption
          SHCON(C,H,t1)                  Simulation real household consumption
          HWELF(H,t1)                  Household welfare (EV)
          CHWELF(H,t1)                 Counterfactual household welfare (EV)
          SHWELF(H,t1)                 Simulation household welfare (EV)
;

*###############################################################################
*############################### SECTION 5: Other ##############################
*###############################################################################

SET
QUANTSET_CA
/
  QINT_CAT          Quantity of intermediate demand for c from a
/
;

SET
QUANTSET_AC
/
  QXAC_AC           Quantity of ouput of commodity c from activity a
/

;


*###############################################################################
*############################### SECTION 6: Share ##############################
*###############################################################################

SET AGSHARESET       Agricultural share sets
/
VAshr        Value Added share of agriculture
VAshrN       Value Added share of non-agriculture
OUTshr       Production share of agriculture
OUTshrN      Production share of non-agriculture
EXPshr       Export share of agriculture
EXPshrN      Export share of non-agriculture
EXP-OUTshr   Export-to-Output ratio in agriculture
EXP-OUTshrN  Export-to-Output ratio in non-agriculture
IMPshr       Import share of agriculture
IMPshrN      Import share of non-agriculture
DEMshr       Composite demand share of agriculture
DEMshrN      Composite demand share of non-agriculture
IMP-DEMshr   Import-to-Demand share in agriculture
IMP-DEMshrN  Import-to-Demand share in non-agriculture
/
;

PARAMETER C_AGSHARE(t1,AGSHARESET,*)      Counterfactual Agricultural share parameters (for calculation of structural characteristics of economy)
          S_AGSHARE(t1,AGSHARESET,*)      Simulation Agricultural share parameters (for calculation of structural characteristics of economy)
          AGSHARE(AGSHARESET,t1)          Agricultural share parameters
          CAGSHARE(AGSHARESET,t1)         Counterfactual  Agricultural share parameters (for calculation of simulation results)
          SAGSHARE(AGSHARESET,t1)         Simulation Agricultural share parameters

*          C_AGSHARE_CO(AGSHARESET)        Counterfactual Agricultural share parameters (for calculation of structural characteristics of economy)
*          S_AGSHARE_CO(AGSHARESET)        Simulation Agricultural share parameters (for calculation of structural characteristics of economy)
          AGSHARE_CO(AGSHARESET)          Agricultural share parameters
          CAGSHARE_CO(AGSHARESET)         Counterfactual  Agricultural share parameters (for calculation of simulation results)
          SAGSHARE_CO(AGSHARESET)         Simulation Agricultural share parameters
;


ALIAS(CAGR,CAGRP), (CNAGR,CNAGRP), (AAGR,AAGRP), (ANAGR,ANAGRP)
;

*###############################################################################
*########################### SECTION 7: Price Indices ##########################
*###############################################################################

Set PRICEINDEXSET    Price index sets
/
PIND         Domestically produced demand price (PD) index (Just DPI)
PINDD        Domestically produced and consumed demand price (PDD) index
PINDQ        Composite demand price (PQ) index
PINDA        Output price (PA) index
PINDVA       Value added price (PVA) index
PINDE        Export price (PE) index
PINDM        Import price (PM) index
PINDC        Commodity price index
PINDT        Tradeables price index
PINDNT       Non-tradeables price index
*LNDIND       Land factor return index
USKIND       Unskilled labour factor return index
SKIND        Skilled labour factor return index
CAPIND       Capital factor return index
NEXR         Nominal exchange rate index
REXR         Real exchange rate index
/
;

PARAMETER PINDICES(PRICEINDEXSET,t1)      Price indices
          CPINDICES(PRICEINDEXSET,t1)     Counterfactual price indices
          SPINDICES(PRICEINDEXSET,t1)     Simulation price indices

          PINDICES_CO(PRICEINDEXSET)      Price indices
          CPINDICES_CO(PRICEINDEXSET)     Counterfactual price indices
          SPINDICES_CO(PRICEINDEXSET)     Simulation price indices
;


Set AGPRICEINDEXSET  Agricutural price index sets
/
AGTOTD       Ratio of ag and non-agg price indices PD
AGTOTQ       Ratio of ag and non-agg price indices PQ
AGTOTA       Ratio of ag and non-agg price indices PA
AGTOTVA      Ratio of ag and non-agg price indices PVA
AGTOTE       Ratio of ag and non-agg price indices PQ
AGTOTM       Ratio of ag and non-agg price indices PM
AGTOTC       Ratio of ag and non-agg price indices PC (HH)
/
;

PARAMETER AGPINDICES(AGPRICEINDEXSET,t1)  Agricultural price indices
          CAGPINDICES(AGPRICEINDEXSET,t1) Counterfactual agricultural price indices
          SAGPINDICES(AGPRICEINDEXSET,t1) Simulation agricultural price indices

          AGPINDICES_CO(AGPRICEINDEXSET)  Agricultural price indices
          CAGPINDICES_CO(AGPRICEINDEXSET) Counterfactual agricultural price indices
          SAGPINDICES_CO(AGPRICEINDEXSET) Simulation agricultural price indices
;


*###############################################################################
*########################## SECTION 8: Health Effects ##########################
*###############################################################################

SETS
NUTdata_set
/
CHkcal_unit     kcal contents per gram of commodity c
CHmetric_H01    tonnes of consumption of commodity c by hhld H01
CHmetric_H02    tonnes of consumption of commodity c by hhld H02
CHmetric_H03    tonnes of consumption of commodity c by hhld H03
CHmetric_H04    tonnes of consumption of commodity c by hhld H04
CHmetric_H05    tonnes of consumption of commodity c by hhld H05
/

mapNUTdataHH(NUTdata_set,h)
/
CHmetric_H01.H01
CHmetric_H02.H02
CHmetric_H03.H03
CHmetric_H04.H04
CHmetric_H05.H05
/

BMIset
/
Height
Weight
BMI
/

PersonID /1*157568/

DSMDRset /DS, MDR/
DSMDRdata_set /PREVshr, DURregimen, COSTregimen /
;

*###############################################################################
*######################## SECTION 9: Simulation Targets ########################
*###############################################################################

SET TARGETSET        Target Parameters set
/
GDPDEF       GDP Deflator
CPI          Consumer Price Index
CPI_S        New consumer Price Index
TFPadj       Total Factor Productivity adjustment factor
YG           Total government revenue
GDN          Total government consumption
GADJ         Government demand scaling factor
RGCONS       Total real government consumption
GSAV         Government budget deficit
/

    PPSET    Public and private impact set /pub,prv/
;

PARAMETER TARGETS(TARGETSET,t1)           Target parameters
          CTARGETS(TARGETSET,t1)          Counterfacutal target parameters
          STARGETS(TARGETSET,t1)          Simulation target parameters

          QHnut_scale(H,t1)               Scaling factor for Per capita nutrition intake by household c (to keep baseline nutritional intakes constant over time)
          CQHnut_scale(H,t1)              Counterfactual Scaling factor for Per capita nutrition intake by household c (to keep baseline nutritional intakes constant over time)
$ontext
          PRETARGETS(TARGETSET,t1)        Pre-simulation target parameters

          TARGETSeh(h,t1)   Household consumption expenditure target parameters
          CTARGETSeh(h,t1)  Counterfactual consumption expenditure counterfacutal target parameters
          STARGETSeh(h,t1)  Simulation consumption expenditure simulation target parameters

          TARGETSrhcons(h,t1)   Real household consumption expenditure target parameters
          CTARGETSrhcons(h,t1)  Counterfactual real household consumption expenditure counterfacutal target parameters
          STARGETSrhcons(h,t1)  Simulation real household consumption expenditure simulation target parameters

          TARGETS_CO(TARGETSET)           Target parameters
          CTARGETS_CO(TARGETSET)          Counterfacutal target parameters
          STARGETS_CO(TARGETSET)          Simulation target parameters
$offtext
;

*###############################################################################
*########################## SECTION 10: Demographics ###########################
*###############################################################################

SET DEMOGset / POP, BIRTHS, DEATHS, IntlMIGR /
*    RISKfact_set /SMOKING, IAPollution, LowBMI, ALCOHOL, DIABETES, HIV/
    RISKfact_set /r01*r06/
    RISKdim_set /h01*h05, RR/
    CLINOUTdata_set /INCIDrate, INCIDshare, MORTrate, MORTshare/
    CLINOUToutput_set /MORT, PREV, INCID/

    EPIset     / S_TB, L_TB, I_TB, Ir_TB, T_TB, Tr_TB,
                 POP_TB, Lambda_TB, Incid_TB, Prev_TB, Notif_TB, Mort_TB,
                 RR_r01_prev_TB, RR_r02_prev_TB, RR_r03_prev_TB,
                 RR_r04_prev_TB, RR_r05_prev_TB, RR_r06_prev_TB, RR_TB,
                 a_TB, q_TB, tau_TB, betaREL_TB, betaIN_TB, u_TB, m_TB,
                       eps_TB, c_TB, d_TB, nu_TB /
    EPIparm_set / a_TB, q_TB, tau_TB, betaREL_TB, betaIN_TB, u_TB, m_TB,
                        eps_TB, c_TB, d_TB, nu_TB /
    EPIvar_set  / S_TB, L_TB, I_TB, Ir_TB, T_TB, Tr_TB /
    AIRpol_set  / AIRpol01*AIRpol09 /
    IAP_set(AIRpol_set)  / AIRpol07*AIRpol08 /

mapRISKdim(h,RISKdim_set)
/
*h.(h01*h05)
H01.h01
H02.h02
H03.h03
H04.h04
H05.h05
/
;


PARAMETER DEMOG(H,DEMOGset,age5tot,t1)
          CDEMOG(H,DEMOGset,age5tot,t1)
          SDEMOG(H,DEMOGset,age5tot,t1)

          CLINOUToutput(h,CLINOUToutput_set,gentot,age5tot,t1)
          CCLINOUToutput(h,CLINOUToutput_set,gentot,age5tot,t1)
          SCLINOUToutput(h,CLINOUToutput_set,gentot,age5tot,t1)
;

*###############################################################################
*######################### SECTION 11: Scenario Shocks #########################
*###############################################################################

SET
INTERFACESHOCKTYPEset
/
BALMACRO_CLOSE    Balanced Macro Closure switch
REVNEUTRAL_CLOSE  Revenue-neutral closure switch
KCAL_PALM         Energy intake shock (palm oil)
KCAL_OIL_OTH      Energy intake shock (other edible oils)
KCAL_OIL_ALL      Energy intake shock (all edible oils)
CONS_PALM         Consumption shock (palm oil)
CONS_OIL_OTH      Consumption shock (other edible oils)
CONS_OIL_ALL      Consumption shock (all edible oils)
STAX_PALM         Sales tax shock (palm oil)
STAX_OIL_OTH      Sales tax shock (other edible oils)
STAX_OIL_ALL      Sales tax shock (all edible oils)
PROD_PALM         Production shock (palm oil)
PROD_OIL_OTH      Production shock (other edible oils)
PROD_OIL_ALL      Production shock (all edible oils)
PTAX_PALM         Production tax shock (palm oil)
PTAX_OIL_OTH      Production tax shock (other edible oils)
PTAX_OIL_ALL      Production tax shock (all edible oils)
/

INTERFACESHOCKVALset
/
ON_OFF
SHKVALUE
/
;

PARAMETER INTERFACE_SHOCKS0(INTERFACESHOCKTYPEset,INTERFACESHOCKVALset)
          INTERFACE_SHOCKS(INTERFACESHOCKTYPEset,INTERFACESHOCKVALset)
          InterfaceShockVar(INTERFACESHOCKTYPEset,t1)
          CInterfaceShockVar(INTERFACESHOCKTYPEset,t1)
          SInterfaceShockVar(INTERFACESHOCKTYPEset,t1)
;

*###############################################################################
*########################## SECTION 12: Indicator Sets #########################
*###############################################################################

SETS
IndicSCset   Scalar variable indicator set
/
CPI
IPI
DMPS
DPI
DTINS
EG
EXR
FSAV
GADJ
* GDN
GOVSHR
GSAV
IADJ
INVSHR
MPSADJ
TABS
TINSADJ
WALRAS
WALRASSQR
YG
/

IndicAset    Activities variable indicator set
/
PA
PINTA
PVA
QA
QINTA
QVA
/

IndicCset    Commodities variable indicator set
/
PDD
PDS
PE
PM
PQ
PWE
PWM
PX
QD
QE
QG
QINV
QM
QQ
QT
QX
/

IndicFset    Factor variable indicator set
/
QF
QFS
WF
YF
/

IndicINSset  Institutional variable indicator set
/
EH
MPS
TINS
YI
/
;

PARAMETER INDIC_SC(IndicSCset,t1)    Scalar variable indicators
          CINDIC_SC(IndicSCset,t1)   Counterfactual Scalar variable indicators
          SINDIC_SC(IndicSCset,t1)   Simulation Scalar variable indicators
          INDIC_A(IndicAset,A,t1)    Activities variable indicators
          CINDIC_A(IndicAset,A,t1)   Counterfactual Activities variable indicators
          SINDIC_A(IndicAset,A,t1)   Simulation Activities variable indicators
          INDIC_C(IndicCset,C,t1)    Commodities variable indicators
          CINDIC_C(IndicCset,C,t1)   Counterfactual Commodities variable indicators
          SINDIC_C(IndicCset,C,t1)   Simulation Commodities variable indicators
          INDIC_F(IndicFset,F,t1)    Factor variable indicators
          CINDIC_F(IndicFset,F,t1)   Counterfactual Factor variable indicators
          SINDIC_F(IndicFset,F,t1)   Simulation Factor variable indicators
          INDIC_INS(IndicINSset,INS,t1)   Institutional variable indicators
          CINDIC_INS(IndicINSset,INS,t1)  Counterfactual Institutional variable indicators
          SINDIC_INS(IndicINSset,INS,t1)  Simulation Institutional variable indicators
          INDIC_FA(IndicFset,F,A,t1)    Factor variable indicators (by activity)
          CINDIC_FA(IndicFset,F,A,t1)   Counterfactual Factor variable indicators (by activity)
          SINDIC_FA(IndicFset,F,A,t1)   Simulation Factor variable indicators (by activity)
          INDIC_QH(H,C,t1)             Household consumption variable indicators (by commodity)
          CINDIC_QH(H,C,t1)            Counterfactual Household consumption variable indicators (by commodity)
          SINDIC_QH(H,C,t1)            Simulation Household consumption variable indicators (by commodity)

          INDIC_SC_CO(IndicSCset)    Scalar variable indicators
          CINDIC_SC_CO(IndicSCset)   Counterfactual Scalar variable indicators
          SINDIC_SC_CO(IndicSCset)   Simulation Scalar variable indicators
          INDIC_A_CO(IndicAset,A)    Activities variable indicators
          CINDIC_A_CO(IndicAset,A)   Counterfactual Activities variable indicators
          SINDIC_A_CO(IndicAset,A)   Simulation Activities variable indicators
          INDIC_C_CO(IndicCset,C)    Commodities variable indicators
          CINDIC_C_CO(IndicCset,C)   Counterfactual Commodities variable indicators
          SINDIC_C_CO(IndicCset,C)   Simulation Commodities variable indicators
          INDIC_F_CO(IndicFset,F)    Factor variable indicators
          CINDIC_F_CO(IndicFset,F)   Counterfactual Factor variable indicators
          SINDIC_F_CO(IndicFset,F)   Simulation Factor variable indicators
          INDIC_INS_CO(IndicINSset,INS)   Institutional variable indicators
          CINDIC_INS_CO(IndicINSset,INS)  Counterfactual Institutional variable indicators
          SINDIC_INS_CO(IndicINSset,INS)  Simulation Institutional variable indicators
;


PARAMETER

CPI_T0(t1)
CPI_H_T0(H,t1)
IPI_T0(t1)
DMPS_T0(t1)
DPI_T0(t1)
DTINS_T0(t1)
EG_T0(t1)
EH_T0(H,t1)
EXR_T0(t1)
FSAV_T0(t1)
GADJ_T0(t1)
GDN_T0(t1)
GOVSHR_T0(t1)
GSAV_T0(t1)
IADJ_T0(t1)
INVSHR_T0(t1)
MPS_T0(INSDNG,t1)
MPSADJ_T0(t1)
PA_T0(A,t1)
PDD_T0(C,t1)
PDS_T0(C,t1)
PINTA_T0(A,t1)
PE_T0(C,t1)
PM_T0(C,t1)
PQ_T0(C,t1)
PVA_T0(A,t1)
PWE_T0(C,t1)
PWM_T0(C,t1)
PX_T0(C,t1)
PXAC_T0(A,C,t1)
QA_T0(A,t1)
QD_T0(C,t1)
QE_T0(C,t1)
QF_T0(F,A,t1)
QFS_T0(F,t1)
QG_T0(C,t1)
QH_T0(C,H,t1)
QH_I_T0(C,H,t1)
QHA_T0(A,C,H,t1)
QINT_T0(C,A,t1)
QINTA_T0(A,t1)
QINV_T0(C,t1)
QINV_ENERGY_T0(C,t1)
QM_T0(C,t1)
QQ_T0(C,t1)
QT_T0(C,t1)
QVA_T0(A,t1)
QX_T0(C,t1)
QXAC_T0(A,C,t1)
TABS_T0(t1)
TAADJ_T0(A,t1)
TQ_T0(C,t1)
TRII_T0(INSDNG,INSDNGP,t1)
TINS_T0(INSDNG,t1)
TINSADJ_T0(t1)
WALRAS_T0(t1)
WALRASSQR_T0(t1)
WF_T0(F,t1)
WFA_T0(F,A,t1)
WFDIST_T0(F,A,t1)
YF_T0(f,t1)
YG_T0(t1)
YI_T0(INS,t1)
YIF_T0(INS,F,t1)
EMISSIONS_T0(AC,t1)
TOTEMISSIONS_T0(t1)
PAAC_T0(A,C,t1)
QAAC_T0(A,C,t1)
PHD_T0(H,t1)
PHE_T0(H,t1)
PHH_T0(H,t1)
QHD_T0(H,t1)
QHE_T0(H,t1)
QHH_T0(H,t1)
NGDP_T0(t1)
NCP_T0(t1)
NCG_T0(t1)
NINV_T0(t1)
NDST_T0(t1)
NEXP_T0(t1)
NIMP_T0(t1)
GDPDEF_T0(t1)
RGDP_T0(t1)
TFPadj_T0(t1)
QDSTadj_T0(t1)
DELTATadj_T0(t1)
DELTAQadj_T0(t1)
PWElev_T0(t1)
PWMlev_T0(t1)

TA_T0(A,t1)
TQ_T0(C,t1)
TM_T0(C,t1)
TQscale_T0(t1)
TQadd_T0(t1)
TMscale_T0(t1)
TMadd_T0(t1)
TWFAscale_T0(t1)
TWFAadd_T0(t1)
TF_T0(F,t1)

QFH_T0(insd,f,t1)
WFH_T0(f,t1)
WFHDIST_T0(insd,f,t1)

QH_EV_T0(C,H,t1)
QHA_EV_T0(A,C,H,t1)
YH_EV_T0(H,t1)
YH_EV_TOT_T0(t1)
U_H_T0(h,t1)

FLABGROWTH_T0(h,flab,t1)

POP_T0(t1,h,gen,age5)

QFS_T0(f,t1)
WFS_T0(f,t1)


S_TB_T0(t1,h,t1_tb)     Susceptible populaton (share)
L_TB_T0(t1,h,t1_tb)     Latently infected populaton (share)
I_TB_T0(t1,h,t1_tb)     TB disease populaton (share)
Ir_TB_T0(t1,h,t1_tb)    TB disease reinfection populaton (failed treatment)(share)
T_TB_T0(t1,h,t1_tb)     On TB treatment populaton (share)
Tr_TB_T0(t1,h,t1_tb)    On TB retreatment populaton (share)
POP_TB_T0(t1,h,t1_tb)   Total Population (equal to 1)
Lambda_TB_T0(t1,h,t1_tb) Force of Infection definition
Incid_TB_T0(t1,h,t1_tb) TB incidence (populaton share)
Prev_TB_T0(t1,h,t1_tb)  TB prevalence (populaton share)
Notif_TB_T0(t1,h,t1_tb) TB notifications (populaton share)
Mort_TB_T0(t1,h,t1_tb)  TB excess mortality (populaton share)

Riskfact_prev_T0(t1,RISKfact_set,h)  TB risk factor prevalence (by household)
RR_TB_T0(t1,h)    Relative Risk of TB - relative to zero risk factor household (by household)

QHfood_metric_T0(c,h,t1) Endogenous household food consumption in metric units by commodity c and househjold h (tonnes)
QHnut_cap_day_T0(h,t1)   Endogenous Nutrition kcal intake per capita per day by household h (kcal per person per day)
QHnut_cap_day_final_T0(h,t1) Scaled endogenous Nutrition kcal intake per capita per day by household h (kcal per person per day)

a_TB_T0(t1,h)     Proportion progressing directly to disease on infection
q_TB_T0(t1,h)     Relative risk of active TB following re-infection (constant across households)
tau_TB_T0(t1,h)   Proportion successfully treated - zero risk household
betaREL_TB_T0(t1,h) Relative effective contact rate
betaIN_TB_T0(t1,h) Effective contact between those in same SES quintile
u_TB_T0(t1,h)     Background mortality
m_TB_T0(t1,h)     Excess mortality due to active TB
eps_TB_T0(t1,h)   Self-cure of active TB (constant across households)
c_TB_T0(t1,h)     Developing active TB from latent infection
d_TB_T0(t1,h)     Diagnosis of active TB
nu_TB_T0(t1,h)    Completion of treatment (constant across households)

;

PARAMETER NPVMAC(MACSET)
          CNPVMAC(MACSET)
          SNPVMAC(MACSET)
          DEFMAC(MACSET)
          CDEFMAC(MACSET)
          SDEFMAC(MACSET)
          NPVFAC(*)
          CNPVFAC(*)
          SNPVFAC(*)
          NPVHH(*)
          CNPVHH(*)
          SNPVHH(*)
;


*## KEY INDICATOR SET

SET
KeyIndicSet
/
Walras
RealGDP
NomGDP
NomGDPfac
RealGDPfac
RealHCONS
NomHCONS
RealGCONS
NomGCONS
RealINV
NomINV
RealEXP
NomEXP
RealIMP
NomIMP
GDPDEF
CPI
IPI
EXR
GovRevenue
TQ
TQscale
TQadd
TM
TMscale
TMadd
TWFA_f01
TWFA_f02
TWFA_f03
TWFA_f04
TWFA_f05
TWFA_f06
TWFA_f07
TWFA_f08
TWFAscale
TWFAadd
TINS_ent
YH
YFLND
YFLAB
YFCAP
HCON
POP
/

KeyIndicSet_H
/
YH
YH_R
CPI_H
YFLND
YFLAB
YFCAP
HCON
HCONR
HCON_R
QFH
POP
QHnut_cap_day_final
QHnut_cap_day_scale
/

KeyIndicMacSet
/
PQ
QQ
PX
QX
PE
QE
PM
QM
QH
TQ
QH01
QH02
QH03
QH04
QH05
rGDPfac
INDtax_nom
INDtax_real
rGDPMrk_inc_nom
rGDPMrk_inc_real
rGDPMrk_exp
/

SCENshock_set
/
TREATcost_DS
TREATcost_MDR
dLABforce_isolat_DS
dLABforce_isolat_MDR
dLABforce_hosp
/

Hagg
/
hrur   Rural households
hurb   Urban households
/

mapHagg(Hagg,h)
/
hrur.(h01*h05)
hurb.(h01*h05)
/

HHAGGset
/
NPV_EH
NPV_YH
NPV_FLAB
NPV_FCAP

LAB_unskl
LAB_skill

POP
POPsuscpt
POPlatent
POPinfect
POPinfect_r
POPtreat
POPtreat_r
POPincid
POPprev
POPnotif
POPfatal

RR_r01_prev_avg
RR_r02_prev_avg
RR_r03_prev_avg
RR_r04_prev_avg
RR_r05_prev_avg
RR_r06_prev_avg
RR_avg

NUTcapday_avg
/
;

PARAMETER KEY_INDIC(KeyIndicSet,t1)
          CKEY_INDIC(KeyIndicSet,t1)
          SKEY_INDIC(KeyIndicSet,t1)
          KEY_INDIC_H(KeyIndicSet_H,*,t1)
          CKEY_INDIC_H(KeyIndicSet_H,*,t1)
          SKEY_INDIC_H(KeyIndicSet_H,*,t1)
          KEY_INDIC_MAC(KeyIndicMacSet,C,t1)
          CKEY_INDIC_MAC(KeyIndicMacSet,C,t1)
          SKEY_INDIC_MAC(KeyIndicMacSet,C,t1)
          CQFA(f,a,t1)
          SQFA(f,a,t1)
          CQFS(f,t1)
          SQFS(f,t1)
          CWF(f,t1)
          SWF(f,t1)
          CWFA(f,a,t1)
          SWFA(f,a,t1)
          CQFH(insd,f,t1)
          SQFH(insd,f,t1)


          EPIagg(H,EPIset,t1)
          CEPIagg(H,EPIset,t1)
          SEPIagg(H,EPIset,t1)

          EPIdisagg(H,EPIset,t1_tb,t1)
          CEPIdisagg(H,EPIset,t1_tb,t1)
          SEPIdisagg(H,EPIset,t1_tb,t1)

          SCENshocks(H,SCENshock_set,t1)
          CSCENshocks(H,SCENshock_set,t1)
          SSCENshocks(H,SCENshock_set,t1)

          HHAGG(HHAGGset,H)
          CHHAGG(HHAGGset,H)
          SHHAGG(HHAGGset,H)
;


*Scenario TABs
PARAMETER TAB_Scen01
          TAB_Scen02
          TAB_Scen03
          TAB_Scen04
          TAB_Scen05
          TAB_Scen06
;
