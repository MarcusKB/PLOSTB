
*3. PARAMETER DECLARATIONS ##########################################

PARAMETER
a_TB0(h)           Proportion progressing directly to disease on infection
a_TB00             Proportion progressing directly to disease on infection - zero risk household
q_TB              Relative risk of active TB following re-infection (constant across households)
q_TB00            Relative risk of active TB following re-infection (constant across households) - zero risk household
tau_TB(h)         Propoertion successfully treated
tau_TB00          Propoertion successfully treated - zero risk household
betaREL_TB(h)     Relative effective contact rate
betaREL_TB00      Relative effective contact rate - zero risk household

betaIN_TB(h)      Baseline Effective contact between those in same SES quintile
betaIN_TB00       Effective contact between those in same SES quintile - zero risk household
u_TB(h)           Background mortality
u_TB00            Background mortality - zero risk household
m_TB(h)           Excess mortality due to active TB
m_TB00            Excess mortality due to active TB - zero risk household
eps_TB            Self-cure of active TB (constant across households)
eps_TB00          Self-cure of active TB (constant across households) - zero risk household
c_TB0(h)           Developing active TB from latent infection
c_TB00             Developing active TB from latent infection - zero risk household
d_TB(h)           Diagnosis of active TB
d_TB00            Diagnosis of active TB - zero risk household
nu_TB             Completion of treatment (constant across households)
nu_TB00           Completion of treatment (constant across households) - zero risk household

TBincid_share(h,gen,age5)
TBmort_share(h,gen,age5)

S_TB0(h,t1_tb)     Susceptible populaton (share)
L_TB0(h,t1_tb)     Latently infected populaton (share)
I_TB0(h,t1_tb)     TB disease populaton (share)
Ir_TB0(h,t1_tb)    TB disease reinfection populaton (failed treatment)(share)
T_TB0(h,t1_tb)     On TB treatment populaton (share)
Tr_TB0(h,t1_tb)    On TB retreatment populaton (share)
POP_TB0(h,t1_tb)   Total Population (equal to 1)
Lambda_TB0(h,t1_tb) Force of Infection definition
Incid_TB0(h,t1_tb) TB incidence (populaton share)
Prev_TB0(h,t1_tb)  TB prevalence (populaton share)
Notif_TB0(h,t1_tb) TB notifications (populaton share)
Mort_TB0(h,t1_tb)  TB excess mortality (populaton share)

RISKfact_RR(RISKfact_set) relative risk of TB risk factors (by TB risk factor)
betaINCID(RISKfact_set)   log relative risk of TB risk factors (by TB risk factor)
RISKfact_prev0(RISKfact_set,h)  TB risk factor prevalence (by household)
RISKfact_LowBMI_DHS_prev0(h)  TB risk factor prevalence for Low BMI derived from DHS data (by household)
RR_TB0(h)          Relative Risk of TB - relative to zero risk factor household (by household)

EPIparm_data(EPIparm_set,*) TB model parameter - zero Relative Risk hhld values
EPIparm_data_h(EPIparm_set,*) TB model parameter - zero Relative Risk hhld values
EPIvar_data(EPIvar_set,h)   TB model state variables - initial values
EPIvar_data_h(EPIvar_set,h)   TB model state variables - initial values
RISKfact_data(Riskfact_set,Riskdim_set)  Risk factor data set (by risk factor and risk dimension incl household- and risk factor-sepcific RRs and prevalence rates)
CLINOUT_data0(gen,age5,CLINOUTdata_set) TB Clinical Outcome rates incl Incidence and Mortality rates by age group (same across households)
CLINOUT_data(H,gen,age5,CLINOUTdata_set) TB Clinical Outcome rates incl Incidence and Mortality rates by age group

AIRpol_data(AIRpol_set,c)   Air pollution data from GTAP database 10A (year 2014)
IAP_coeff(c)       Indoor Air Pollution coefficients (approximated by sum of PM2_5 and PM10 emissions from GTAP 10A database)

IAP_index0(h)      Indoor Air Pollution index by household (approximated by sum of PM2_5 and PM10 emissions from GTAP 10A database)
alphaIAP0(h)       Indoor Air Pollution exposure-to-prevalence parameter
alphaIAP(h)        Indoor Air Pollution exposure-to-prevalence parameter

NUTdata0(c,NUTdata_set) Baseline household metric consumption and nutrition intake data by food commodity c
QHfood_NUTcap0(c)       Baseline nutrition intake per capita data by food commodity c (kcal per g per day)

QHfood_metric0(c,h)     Baseline household metric consumption data by food commodity c (tonnes)
QHnut_cap_day0(h)       Baseline Intermeidcate non-scaled per capita nutrition intake by household c (kcal per capita per day)
QHnut_cap_day_scale0(H) Baseline Scaling factor for Per capita nutrition intake by household c (to keep baseline nutritional intakes constant over time)
QHnut_cap_day_final0(H) Baseline Final scaled Per capita nutrition intake by household c (kcal per capita per day)

DHSdata0(h,PersonID,BMIset)  DHS data set of height and weight by personID (787840 persons) and by household h
DHSdata_weight0(h)           DHS household-specific sample person weight by household h

DSMDR_data(DSMDRset,DSMDRdata_set) DS and MDR prevalence rates & duration and cost of treatment regimens
DSMDRshr(DSMDRset)                 Baseline prevalence shares of DS and MDR TB cases

TBTREATunitcost(DSMDRset)    Treatment unit cost parameter (136.15 USD per treat regimen for DS-TB)
TBTREATcover(DSMDRset)       Treatment coeverage parameter (share of incident TB population)
TBTREAT01(DSMDRset)          zero-one indicator for treatment unit cost parameter

TBHOSPperiod       Hospitalization period parameter for DS TB (intensive phase 7.8 days continuation phase 1.8 days) /0/
TBHOSP01           zero-one indicator for hospitalization morbidity parameter /0/

TBISOLATperiod(DSMDRset)     Isolation period parameter until sputum smear conversion (4-12 weeks)
TBISOLATadhere(DSMDRset)     Isolation adherence parameter until sputum smear conversion (share of incident TB population)
TBISOLAT01(DSMDRset)         zero-one indicator for isolation period parameter until sputum smear conversion

TBMORT01           zero-one indicator for mortality impacts /0/

TOTBURDENcost01    zero-one indicator for total disease burden of treatment unit cost impacts /0/
TOTBURDENisolat01  zero-one indicator for total disease burden of isolation morbidity impacts /0/
TOTBURDENhosp01    zero-one indicator for total disease burden of hospitalization morbidity impacts /0/
TOTBURDENmort01    zero-one indicator for total disease burden of mortality impacts /0/
;

$libinclude XLIMPORT DSMDR_data IndiaData2014.xlsx DSMDR_data

*1. Treatment regimen unit cost for DS-TB
TBTREATunitcost(DSMDRset) = DSMDR_data(DSMDRset,'COSTregimen');
TBTREATcover(DSMDRset)   = 1;
TBTREAT01(DSMDRset)      = 0;

*2. Isolation period (4-12 weeks)
TBISOLATperiod(DSMDRset) = DSMDR_data(DSMDRset,'DURregimen');
TBISOLATadhere(DSMDRset) = 1;
TBISOLAT01(DSMDRset)     = 0;

*2a. Hospitalization period (9.6 work-days)
TBHOSPperiod   = 9.6/(52*5);
TBHOSP01       = 0;

*3. Excess TM mortality impacts on demographics and economics
TBMORT01       = 0;

DSMDRshr(DSMDRset) = DSMDR_data(DSMDRset,'PREVshr');
*DSMDRdata(DSMDRset,DSMDRdata_set)        PREVshr  DURregimen   COSTregimen


*4. PARAMETER DEFINITIONS ###########################################

$libinclude XLIMPORT RISKfact_data IndiaData2014.xlsx RISKfact_data
$libinclude XLIMPORT CLINOUT_data0 IndiaData2014.xlsx CLINOUT_data0

CLINOUT_data(H,gen,age5,CLINOUTdata_set) = CLINOUT_data0(gen,age5,CLINOUTdata_set);

Display RISKfact_data, CLINOUT_data;

*## NB: Code flexible wrt to #households=1 or 5
RISKfact_prev0(RISKfact_set,h) = SUM(Riskdim_set$mapRISKdim(h,Riskdim_set), RISKfact_data(Riskfact_set,Riskdim_set))*(card(h)/5);
RISKfact_RR(RISKfact_set)      = RISKfact_data(Riskfact_set,"RR");

TBincid_share(h,gen,age5) = CLINOUT_data(H,gen,age5,'INCIDshare');
TBmort_share(h,gen,age5)  = CLINOUT_data(H,gen,age5,'MORTshare');

Display RISKfact_prev0, RISKfact_RR, TBincid_share, TBmort_share ;

*## Parameters of log-RR relation between (1) Household TB relative risk,
*## and (2) household risk factor prevalence rates
betaINCID(RISKfact_set)  = log(RISKfact_RR(RISKfact_set));

*## Incidence of wealthiest inferred from assuming alphaINCID constant &
*## independent of household type
RR_TB0(h) = exp(SUM(RISKfact_set,betaINCID(RISKfact_set)*RISKfact_prev0(RISKfact_set,h)));

display betaINCID, RR_TB0;


*$libinclude XLIMPORT EPIparm_data IndiaData2014.xlsx EPIparm_data
$libinclude XLIMPORT EPIparm_data_h IndiaData2014.xlsx EPIparm_data_h
*$libinclude XLIMPORT EPIvar_data IndiaData2014.xlsx EPIvar_data
$libinclude XLIMPORT EPIvar_data_h IndiaData2014.xlsx EPIvar_data_h

EPIparm_data(EPIparm_set,'h_RRzero') = EPIparm_data_h(EPIparm_set,'h_RRzero');
EPIvar_data(EPIvar_set,h) = EPIvar_data_h(EPIvar_set,h);

Display EPIparm_data, EPIvar_data;

$ontext
*NEW parameters (8. October 2021)
a_TB(h)            = 0.084;
q_TB               = 0.6;
tau_TB(h)          = 0.71;
betaREL_TB(h)      = 0.07186036;

betaIN_TB(h)       = 0.1212616;
u_TB(h)            = 0.0003845414;
m_TB(h)            = 0.002305032;
eps_TB             = 0.003647179;
c_TB(h)            = 0.0000142301;
d_TB(h)            = 0.01399591;
nu_TB              = 0.03773129;
$offtext

a_TB00            = EPIparm_data('a_TB','h_RRzero');
q_TB00            = EPIparm_data('q_TB','h_RRzero');
tau_TB00          = EPIparm_data('tau_TB','h_RRzero');
betaREL_TB00      = EPIparm_data('betaREL_TB','h_RRzero');

betaIN_TB00       = EPIparm_data('betaIN_TB','h_RRzero');
u_TB00            = EPIparm_data('u_TB','h_RRzero');
m_TB00            = EPIparm_data('m_TB','h_RRzero');
eps_TB00          = EPIparm_data('eps_TB','h_RRzero');
c_TB00            = EPIparm_data('c_TB','h_RRzero');
d_TB00            = EPIparm_data('d_TB','h_RRzero');
nu_TB00           = EPIparm_data('nu_TB','h_RRzero');

a_TB0(h)            = a_TB00*RR_TB0(h);
q_TB               = q_TB00;
tau_TB(h)          = tau_TB00;
betaREL_TB(h)      = betaREL_TB00;

betaIN_TB(h)       = betaIN_TB00;
u_TB(h)            = u_TB00;
m_TB(h)            = m_TB00;
eps_TB             = eps_TB00;
c_TB0(h)            = c_TB00*RR_TB0(h);
d_TB(h)            = d_TB00;
nu_TB              = nu_TB00;

Display a_TB0, q_TB, tau_TB, betaREL_TB, betaIN_TB,
        u_TB, m_TB, eps_TB, c_TB0, d_TB, nu_TB ;

S_TB0(h,t1_tb)     = EPIvar_data('S_TB',h);
L_TB0(h,t1_tb)     = EPIvar_data('L_TB',h);
I_TB0(h,t1_tb)     = EPIvar_data('I_TB',h);
Ir_TB0(h,t1_tb)    = EPIvar_data('Ir_TB',h);
T_TB0(h,t1_tb)     = EPIvar_data('T_TB',h);
Tr_TB0(h,t1_tb)    = EPIvar_data('Tr_TB',h);

Display S_TB0, L_TB0, I_TB0, Ir_TB0, T_TB0, Tr_TB0 ;

POP_TB0(h,t1_tb)   = S_TB0(h,t1_tb)
                   + L_TB0(h,t1_tb)
                   + I_TB0(h,t1_tb)
                   + Ir_TB0(h,t1_tb)
                   + T_TB0(h,t1_tb)
                   + Tr_TB0(h,t1_tb);

Lambda_TB0(h,t1_tb) = betaIN_TB(h)*((I_TB0(h,t1_tb) + Ir_TB0(h,t1_tb))
                                        + betaREL_TB(h)*SUM(hp$nonH(h,hp),I_TB0(hp,t1_tb) + Ir_TB0(hp,t1_tb))) ;
Incid_TB0(h,t1_tb) = a_TB0(h)*Lambda_TB0(h,t1_tb)*S_TB0(h,t1_tb)
                     + (q_TB*a_TB0(h)*Lambda_TB0(h,t1_tb) + c_TB0(h))*L_TB0(h,t1_tb) ;
Prev_TB0(h,t1_tb)  = I_TB0(h,t1_tb) + Ir_TB0(h,t1_tb) ;
Notif_TB0(h,t1_tb) = d_TB(h)*I_TB0(h,t1_tb) ;
Mort_TB0(h,t1_tb)  = m_TB(h)*Prev_TB0(h,t1_tb) ;

Display POP_TB0, Lambda_TB0, Incid_TB0, Prev_TB0, Notif_TB0, Mort_TB0 ;


*$libinclude XLIMPORT AIRpol_data IndiaData2014.xlsx AIRpol_data
*IAP_coeff(c) = SUM(IAP_set,AIRpol_data(IAP_set,c))/SUM(h,QH0(c,h));
*IAP_index0(h) = SUM(c,IAP_coeff(c)*QH0(c,h));

*alphaIAP0(h) = -log(1-RISKfact_prev0('r02',h))/IAP_index0(h);
*alphaIAP(h) = alphaIAP0(h);

*Display AIRpol_data, IAP_coeff, IAP_index0, alphaIAP;

$libinclude XLIMPORT NUTdata0 IndiaData2014.xlsx NUTdata0

QHfood_NUTcap0(c)   = 1000000*NUTdata0(c,'CHkcal_unit');

QHfood_metric0(c,h) = SUM(NUTdata_set$mapNUTdataHH(NUTdata_set,h),NUTdata0(c,NUTdata_set));
QHnut_cap_day0(h)   = (SUM(C,QHfood_NUTcap0(C)*QHfood_metric0(C,H))/(POPscale*POPbase(h)))/365;

QHnut_cap_day_scale0(H) = 1;
QHnut_cap_day_final0(H) = QHnut_cap_day0(h);

$libinclude XLIMPORT DHSdata0 DHS_BMI_data.xlsx DHSdata0

DHSdata0(h,PersonID,'BMI') = DHSdata0(h,PersonID,'Weight')/POWER(DHSdata0(h,PersonID,'Height')/100,2);
DHSdata_weight0(h) = (POPscale*POPbase(h))/card(PersonID);

RISKfact_LowBMI_DHS_prev0(h) = SUM(PersonID$(DHSdata0(h,PersonID,'BMI')<18.5),1)/card(PersonID);
*Display RISKfact_prev0, RISKfact_LowBMI_DHS_prev0;

RISKfact_prev0('r03',h) = RISKfact_LowBMI_DHS_prev0(h);

*$stop


*5. VARIABLE DECLARATIONS ###########################################

VARIABLES
 S_TB(h,t1_tb)     Susceptible populaton (share)
 L_TB(h,t1_tb)     Latently infected populaton (share)
 I_TB(h,t1_tb)     TB disease populaton (share)
 Ir_TB(h,t1_tb)    TB disease reinfection populaton (failed treatment)(share)
 T_TB(h,t1_tb)     On TB treatment populaton (share)
 Tr_TB(h,t1_tb)    On TB retreatment populaton (share)
 POP_TB(h,t1_tb)   Total Population (equal to 1)
 Lambda_TB(h,t1_tb) Force of Infection definition
 Incid_TB(h,t1_tb) TB incidence (populaton share)
 Prev_TB(h,t1_tb)  TB prevalence (populaton share)
 Notif_TB(h,t1_tb) TB notifications (populaton share)
 Mort_TB(h,t1_tb)  TB excess mortality (populaton share)

 Incid_TBavg(t1_tb)
 Prev_TBavg(t1_tb)
 Mort_TBavg(t1_tb)

 a_TB(h)           Proportion progressing directly to disease on infection
 c_TB(h)           Developing active TB from latent infection

 betaIN_TBmult     betaIN parameter Multiplier for model fitting
 betaREL_TBmult    betaREL parameter Multiplier for model fitting
 d_TBmult          d parameter Multiplier for model fitting

 RISKfact_prev(RISKfact_set,h) Risk factor prevalence (potentially endo - by household)
 RR_TB(h)          Relative Risk of TB - relative to zero risk factor household (by household)

* IAP_index(h)      Indoor Air Pollution index by household (approximated by sum of PM2_5 and PM10 emissions from GTAP 10A database)
 WALRASSQR
* WALRAS

 QHfood_metric(c,h) Household metric consumption data by food commodity c (tonnes)
 QHnut_cap_day(h)   Intermediate non-scaled Per capita nutrition intake by household c (kcal per capita per day)
 QHnut_cap_day_scale(H) Scaling factor for Per capita nutrition intake by household c (to keep baseline nutritional intakes constant over time)
 QHnut_cap_day_final(H) Final scaled Per capita nutrition intake by household c (kcal per capita per day)
;


*6. VARIABLE DEFINITIONS ############################################

S_TB.L(h,t1_tb) = S_TB0(h,t1_tb) ;
L_TB.L(h,t1_tb) = L_TB0(h,t1_tb) ;
I_TB.L(h,t1_tb) = I_TB0(h,t1_tb) ;
Ir_TB.L(h,t1_tb) = Ir_TB0(h,t1_tb) ;
T_TB.L(h,t1_tb) = T_TB0(h,t1_tb) ;
Tr_TB.L(h,t1_tb) = Tr_TB0(h,t1_tb) ;
Lambda_TB.L(h,t1_tb) = Lambda_TB0(h,t1_tb) ;
Incid_TB.L(h,t1_tb) = Incid_TB0(h,t1_tb) ;
Prev_TB.L(h,t1_tb) = Prev_TB0(h,t1_tb) ;
Notif_TB.L(h,t1_tb) = Notif_TB0(h,t1_tb) ;
Mort_TB.L(h,t1_tb) = Mort_TB0(h,t1_tb) ;
POP_TB.L(h,t1_tb) = POP_TB0(h,t1_tb) ;

RR_TB.L(h) = RR_TB0(h);

a_TB.L(h) = a_TB0(h);
c_TB.L(h) = c_TB0(h);

betaIN_TBmult.L = 1;
betaREL_TBmult.L = 1;

*IAP_index.L(h) = IAP_index0(h);

QHfood_metric.L(c,h) = QHfood_metric0(c,h);
QHnut_cap_day.L(h)   = QHnut_cap_day0(h);

QHnut_cap_day_scale.L(H) = QHnut_cap_day_scale0(H);
QHnut_cap_day_final.L(H) = QHnut_cap_day_final0(H);

WALRASSQR.L = 0;
WALRAS.L = 0;


loop(t1_tb,
  S_TB.L(h,t1_tb+1) =   (1-Lambda_TB.L(h,t1_tb))*S_TB.L(h,t1_tb)
                        + u_TB(h)*(1-S_TB.L(h,t1_tb))
                        + m_TB(h)*(I_TB.L(h,t1_tb)+Ir_TB.L(h,t1_tb)) ;
  L_TB.L(h,t1_tb+1) =   L_TB.L(h,t1_tb)
                        + (1-a_TB.L(h))*Lambda_TB.L(h,t1_tb)*S_TB.L(h,t1_tb)
                        - (q_TB*a_TB.L(h)*Lambda_TB.L(h,t1_tb) + c_TB.L(h) + u_TB(h))*L_TB.L(h,t1_tb)
                        + eps_TB*(I_TB.L(h,t1_tb) + Ir_TB.L(h,t1_tb))
                        + nu_TB*tau_TB(h)*(T_TB.L(h,t1_tb) + Tr_TB.L(h,t1_tb)) ;
  I_TB.L(h,t1_tb+1) =   I_TB.L(h,t1_tb)
                        + a_TB.L(h)*Lambda_TB.L(h,t1_tb)*S_TB.L(h,t1_tb)
                        + (q_TB*a_TB.L(h)*Lambda_TB.L(h,t1_tb) + c_TB.L(h))*L_TB.L(h,t1_tb)
                        - (d_TB(h) + eps_TB + u_TB(h) + m_TB(h))*I_TB.L(h,t1_tb) ;
  Ir_TB.L(h,t1_tb+1) =   Ir_TB.L(h,t1_tb)
                         + nu_TB*(1-tau_TB(h))*(T_TB.L(h,t1_tb) + Tr_TB.L(h,t1_tb))
                         - (d_TB(h) + eps_TB + u_TB(h) + m_TB(h))*Ir_TB.L(h,t1_tb) ;
  T_TB.L(h,t1_tb+1) =   T_TB.L(h,t1_tb)
                        + d_TB(h)*I_TB.L(h,t1_tb)
                        - (nu_TB + u_TB(h))*T_TB.L(h,t1_tb) ;
  Tr_TB.L(h,t1_tb+1) =   Tr_TB.L(h,t1_tb)
                         + d_TB(h)*Ir_TB.L(h,t1_tb)
                         - (nu_TB + u_TB(h))*Tr_TB.L(h,t1_tb) ;
  Lambda_TB.L(h,t1_tb+1) = betaIN_TB(h)*((I_TB.L(h,t1_tb+1) + Ir_TB.L(h,t1_tb+1))
                                          + betaREL_TB(h)*SUM(hp$nonH(h,hp),I_TB.L(hp,t1_tb+1) + Ir_TB.L(hp,t1_tb+1))) ;
  POP_TB.L(h,t1_tb+1) =  S_TB.L(h,t1_tb)
                         + L_TB.L(h,t1_tb)
                         + I_TB.L(h,t1_tb)
                         + Ir_TB.L(h,t1_tb)
                         + T_TB.L(h,t1_tb)
                         + Tr_TB.L(h,t1_tb) ;


  Incid_TBavg.L(t1_tb) = SUM(h,Incid_TB.L(h,t1_tb))/card(h);
  Prev_TBavg.L(t1_tb) =   SUM(h,Prev_TB.L(h,t1_tb))/card(h);
  Mort_TBavg.L(t1_tb) = SUM(h,Mort_TB.L(h,t1_tb))/card(h);
);

Display 'here is TB', S_TB.L, L_TB.L, I_TB.L, Ir_TB.L, T_TB.L, Tr_TB.L, POP_TB.L;
Display POP_TB.L, Lambda_TB.L, Incid_TB.L, Prev_TB.L, Notif_TB.L, Mort_TB.L;



*7. EQUATION DECLARATIONS ###########################################

EQUATIONS
 S_TB_DEF(h,t1_tb)     Susceptible populaton (share)
 L_TB_DEF(h,t1_tb)     Latently infected populaton (share)
 I_TB_DEF(h,t1_tb)     TB disease populaton (share)
 Ir_TB_DEF(h,t1_tb)    TB disease reinfection populaton (failed treatment)(share)
 T_TB_DEF(h,t1_tb)     On TB treatment populaton (share)
 Tr_TB_DEF(h,t1_tb)    On TB retreatment populaton (share)
 POP_TB_DEF(h,t1_tb)   Total Population (equal to 1)
 Lambda_TB_DEF(h,t1_tb) Force of Infection definition
 Incid_TB_DEF(h,t1_tb) TB incidence (populaton share)
 Prev_TB_DEF(h,t1_tb)  TB prevalence (populaton share)
 Notif_TB_DEF(h,t1_tb) TB notifications (populaton share)
 Mort_TB_DEF(h,t1_tb)  TB excess mortality (populaton share)

 RR_DEF(h)

 a_TB_DEF(h)           Endogenous disease progression parameter "a"
 c_TB_DEF(h)           Endogenous active TB developlment parameter "c"

 Incid_TBavg_DEF(t1_tb) Average TB incidence (populaton share) - for model fitting
 Prev_TBavg_DEF(t1_tb)  Average TB prevalence (populaton share) - for model fitting
 Mort_TBavg_DEF(t1_tb)  Average TB excess mortality (populaton share) - for model fitting

* IAP_index_DEF(h)      Indoor Air Pollution index by household (approximated by sum of PM2_5 and PM10 emissions from GTAP 10A database)
* RISKfact_prev_IAP_DEF(h) Risk factor prevalence for IAP (by household)
 OBJ_TB_DEF

 QH_metric_DEF(c,h)   Endogenous household food consumption in metric units by commodity c and househjold h (tonnes)
 QHnut_cap_DEF(h)     Endogenous Nutrition kcal intake per capita per day by household h (kcal per person per day)
 QHnut_cap_scale_DEF(h)

 RISKfact_prev_LowBMI_DEF(h) Risk factor prevalence for Low BMI (by household)
;


*8. EQUATION DEFINITIONS ############################################

*Susceptible
 S_TB_DEF(h,t1_tb+1)..
  S_TB(h,t1_tb+1) =E=   (1-Lambda_TB(h,t1_tb))*S_TB(h,t1_tb)
                        + u_TB(h)*(POP_TB(h,t1_tb)-S_TB(h,t1_tb))
                        + m_TB(h)*(I_TB(h,t1_tb)+Ir_TB(h,t1_tb)) ;

*Latently infected
 L_TB_DEF(h,t1_tb+1)..
  L_TB(h,t1_tb+1) =E=   L_TB(h,t1_tb)
                        + (1-a_TB(h))*Lambda_TB(h,t1_tb)*S_TB(h,t1_tb)
                        - (q_TB*a_TB(h)*Lambda_TB(h,t1_tb) + c_TB(h) + u_TB(h))*L_TB(h,t1_tb)
                        + eps_TB*(I_TB(h,t1_tb) + Ir_TB(h,t1_tb))
                        + nu_TB*tau_TB(h)*(T_TB(h,t1_tb) + Tr_TB(h,t1_tb)) ;

*TB disease
 I_TB_DEF(h,t1_tb+1)..
  I_TB(h,t1_tb+1) =E=   I_TB(h,t1_tb)
                        + a_TB(h)*Lambda_TB(h,t1_tb)*S_TB(h,t1_tb)
                        + (q_TB*a_TB(h)*Lambda_TB(h,t1_tb) + c_TB(h))*L_TB(h,t1_tb)
                        - (d_TBmult*d_TB(h) + eps_TB + u_TB(h) + m_TB(h))*I_TB(h,t1_tb) ;

*TB disease reinfection (failed treatment)
 Ir_TB_DEF(h,t1_tb+1)..
  Ir_TB(h,t1_tb+1) =E=   Ir_TB(h,t1_tb)
                         + nu_TB*(1-tau_TB(h))*(T_TB(h,t1_tb) + Tr_TB(h,t1_tb))
                         - (d_TBmult*d_TB(h) + eps_TB + u_TB(h) + m_TB(h))*Ir_TB(h,t1_tb) ;

*On TB treatment
 T_TB_DEF(h,t1_tb+1)..
  T_TB(h,t1_tb+1)  =E=   T_TB(h,t1_tb)
                         + d_TBmult*d_TB(h)*I_TB(h,t1_tb)
                         - (nu_TB + u_TB(h))*T_TB(h,t1_tb) ;

*On TB retreatment
 Tr_TB_DEF(h,t1_tb+1)..
  Tr_TB(h,t1_tb+1) =E=   Tr_TB(h,t1_tb)
                         + d_TBmult*d_TB(h)*Ir_TB(h,t1_tb)
                         - (nu_TB + u_TB(h))*Tr_TB(h,t1_tb) ;

*Total Population
 POP_TB_DEF(h,t1_tb)..
  POP_TB(h,t1_tb)  =E=   S_TB(h,t1_tb)
                         + L_TB(h,t1_tb)
                         + I_TB(h,t1_tb)
                         + Ir_TB(h,t1_tb)
                         + T_TB(h,t1_tb)
                         + Tr_TB(h,t1_tb) ;

*Force of Infection
 Lambda_TB_DEF(h,t1_tb)..
  Lambda_TB(h,t1_tb) =E= betaIN_TBmult*betaIN_TB(h)*((I_TB(h,t1_tb) + Ir_TB(h,t1_tb))
                                          + betaREL_TBmult*betaREL_TB(h)*SUM(hp$nonH(h,hp),I_TB(hp,t1_tb) + Ir_TB(hp,t1_tb))) ;

*TB incidence
 Incid_TB_DEF(h,t1_tb)..
  Incid_TB(h,t1_tb) =E=   a_TB(h)*Lambda_TB(h,t1_tb)*S_TB(h,t1_tb)
                          + (q_TB*a_TB(h)*Lambda_TB(h,t1_tb) + c_TB(h))*L_TB(h,t1_tb) ;

*TB incidence - average for model fitting
 Incid_TBavg_DEF(t1_tb)..
  Incid_TBavg(t1_tb) =E= SUM(h,Incid_TB(h,t1_tb))/card(h);

*TB prevalence
 Prev_TB_DEF(h,t1_tb)..
  Prev_TB(h,t1_tb) =E=   I_TB(h,t1_tb) + Ir_TB(h,t1_tb) ;

*TB prevalence - average for model fitting
 Prev_TBavg_DEF(t1_tb)..
  Prev_TBavg(t1_tb) =E=   SUM(h,Prev_TB(h,t1_tb))/card(h) ;

*TB notifications
 Notif_TB_DEF(h,t1_tb)..
  Notif_TB(h,t1_tb) =E=   d_TBmult*d_TB(h)*I_TB(h,t1_tb) ;

*TB excess mortality
 Mort_TB_DEF(h,t1_tb)..
  Mort_TB(h,t1_tb) =E=   m_TB(h)*Prev_TB(h,t1_tb);

*TB excess mortality - average for model fitting
 Mort_TBavg_DEF(t1_tb)..
  Mort_TBavg(t1_tb) =E= SUM(h,Mort_TB(h,t1_tb))/card(h);

 OBJ_TB_DEF..   WALRASSQR   =E= WALRAS*WALRAS ;

*Incidence Rate Ratio (by household)
 RR_DEF(h)..
   RR_TB(h) =E= exp(SUM(RISKfact_set,betaINCID(RISKfact_set)*RISKfact_prev(RISKfact_set,h)));;

*Endogenous disease progression parameter "a"
 a_TB_DEF(h)..
   a_TB(h) =E= a_TB00*RR_TB(h);

*Endogenous active TB developlment parameter "c"
 c_TB_DEF(h)..
   c_TB(h) =E= c_TB00*RR_TB(h);

*Endogenous Indoor Air Pollution index
* IAP_index_DEF(h)..
*   IAP_index(h) =E= SUM(c,IAP_coeff(c)*QH(c,h));

*Endogenous TB risk factor prevalence of IAP
* RISKfact_prev_IAP_DEF(h)..
**   RISKfact_prev('r02',h) =E= (IAP_index(h)/IAP_index0(h))*RISKfact_prev0('r02',h)
*   -log(1-RISKfact_prev('r02',h)) =E= alphaIAP(h)*IAP_index(h);

*Endogenous household food consumption in metric units (tonnes)
 QH_metric_DEF(c,h)..
   QHfood_metric(C,H) =E= (QH(C,H)/QH0(C,H))*QHfood_metric0(C,H);

*Endogenous Nutrition kcal intake per capita per day (kcal/person/day)
 QHnut_cap_DEF(h)..
   QHnut_cap_day(H)   =E= (SUM(C,QHfood_NUTcap0(C)*QHfood_metric(C,H))/(POPscale*POPbase(h)))/365;

*Scaling of Nutrition kcal intake growth path
 QHnut_cap_scale_DEF(h)..
   QHnut_cap_day_final(H)   =E= QHnut_cap_day_scale(H)*QHnut_cap_day(H);

* RISKfact_prev_LowBMI_DEF(h)..
*   RISKfact_prev('r03',h) =E= SUM(PersonID$(((DHSdata0(h,PersonID,'Weight')+(365*(QHnut_cap_day_final(H)-QHnut_cap_day_final0(H))/7715))/POWER(DHSdata0(h,PersonID,'Height')/100,2))>18.5),1)/card(PersonID);


*9. MODEL DEFINITION ###############################################

 MODEL TBmodel  TB model
 /
 S_TB_DEF
 L_TB_DEF
 I_TB_DEF
 Ir_TB_DEF
 T_TB_DEF
 Tr_TB_DEF
 POP_TB_DEF
 Lambda_TB_DEF
 Incid_TB_DEF
 Prev_TB_DEF
 Notif_TB_DEF
 Mort_TB_DEF

 RR_DEF
 a_TB_DEF
 c_TB_DEF

* OBJ_TB_DEF
* OBJEQ
/


 MODEL STANDCGE_TB  standard CGE model w TB model
 /
*Price block (10)
 PMDEF.PM
 PEDEF.PE
 PQDEF.PQ
 PXDEF.PX
 PDDDEF.PDD
 PADEF.PA
 PINTADEF.PINTA
 PVADEF.PVA
 CPIDEF
 CPI_HDEF
 DPIDEF
 IPIDEF

*Production and trade block (17)
 CESAGGPRD
 CESAGGFOC
 LEOAGGINT
 LEOAGGVA
 CESVAPRD.QVA
 CESVAFOC
 INTDEM.QINT
 COMPRDFN.PXAC
 OUTAGGFN.QX
 OUTAGGFOC.QXAC
 CET
 CET2
 ESUPPLY
 ARMINGTON
 COSTMIN
 ARMINGTON2
 QTDEM.QT

*Institution block (12)
* YFDEF.YF
* YHFDEF.WFH
 YHFDEF
* YIFDEF.YIF
 YIFHDEF.YIF
 YIDEF.YI
 EHDEF.EH
 TRIIDEF.TRII
* HMDEM.QH
* HADEM.QHA
 HMDEM_AIDS
 EGDEF.EG
* YGDEF.YG
 YGHDEF
 GOVDEM.QG
 GOVBAL
 INVDEM.QINV

*System-constraint block (9)
 FACEQUIL
 FACEQUIL2
 COMEQUIL
 CURACCBAL
 TINSDEF.TINS
 MPSDEF.MPS
 SAVINVBAL.WALRAS
 TABSEQ.TABS
 INVABEQ
 GDABEQ

 NGDPEQ
 NCPEQ
 NCGEQ
 NINVEQ
 NDSTEQ
 NEXPEQ
 NIMPEQ
 RGDPEQ
 GDPDEFEQ
 GDNEQ

 TQ_EQ
 TM_EQ
 WFA_EQ

*EV household welfare section
* HMDEM_EV
* HADEM_EV
* UH_EV1
* UH_EV2
* TOTEXP_EV

*TB module
 S_TB_DEF
 L_TB_DEF
 I_TB_DEF
 Ir_TB_DEF
 T_TB_DEF
 Tr_TB_DEF
 POP_TB_DEF
 Lambda_TB_DEF
 Incid_TB_DEF
 Prev_TB_DEF
 Notif_TB_DEF
 Mort_TB_DEF

 Incid_TBavg_DEF
 Prev_TBavg_DEF
 Mort_TBavg_DEF

 RR_DEF
 a_TB_DEF
 c_TB_DEF
* IAP_index_DEF
* RISKfact_prev_IAP_DEF
 QH_metric_DEF
 QHnut_cap_DEF
 QHnut_cap_scale_DEF
* RISKfact_prev_LowBMI_DEF

* OBJ_TB_DEF
* OBJEQ
* OBJ_TB_DEF
 /


 MODEL STANDCGE_TB_exog  standard CGE model w TB model & exog risk factors
 /
*Price block (10)
 PMDEF.PM
 PEDEF.PE
 PQDEF.PQ
 PXDEF.PX
 PDDDEF.PDD
 PADEF.PA
 PINTADEF.PINTA
 PVADEF.PVA
 CPIDEF
 CPI_HDEF
 DPIDEF
 IPIDEF

*Production and trade block (17)
 CESAGGPRD
 CESAGGFOC
 LEOAGGINT
 LEOAGGVA
 CESVAPRD.QVA
 CESVAFOC
 INTDEM.QINT
 COMPRDFN.PXAC
 OUTAGGFN.QX
 OUTAGGFOC.QXAC
 CET
 CET2
 ESUPPLY
 ARMINGTON
 COSTMIN
 ARMINGTON2
 QTDEM.QT

*Institution block (12)
* YFDEF.YF
* YHFDEF.WFH
 YHFDEF
* YIFDEF.YIF
 YIFHDEF.YIF
 YIDEF.YI
 EHDEF.EH
 TRIIDEF.TRII
* HMDEM.QH
* HADEM.QHA
 HMDEM_AIDS
 EGDEF.EG
* YGDEF.YG
 YGHDEF
 GOVDEM.QG
 GOVBAL
 INVDEM.QINV

*System-constraint block (9)
 FACEQUIL
 FACEQUIL2
 COMEQUIL
 CURACCBAL
 TINSDEF.TINS
 MPSDEF.MPS
 SAVINVBAL.WALRAS
 TABSEQ.TABS
 INVABEQ
 GDABEQ

 NGDPEQ
 NCPEQ
 NCGEQ
 NINVEQ
 NDSTEQ
 NEXPEQ
 NIMPEQ
 RGDPEQ
 GDPDEFEQ
 GDNEQ

 TQ_EQ
 TM_EQ
 WFA_EQ

*EV household welfare section
* HMDEM_EV
* HADEM_EV
* UH_EV1
* UH_EV2
* TOTEXP_EV

*TB module
 S_TB_DEF
 L_TB_DEF
 I_TB_DEF
 Ir_TB_DEF
 T_TB_DEF
 Tr_TB_DEF
 POP_TB_DEF
 Lambda_TB_DEF
 Incid_TB_DEF
 Prev_TB_DEF
 Notif_TB_DEF
 Mort_TB_DEF

 Incid_TBavg_DEF
 Prev_TBavg_DEF
 Mort_TBavg_DEF

 RR_DEF
 a_TB_DEF
 c_TB_DEF
* IAP_index_DEF
* RISKfact_prev_IAP_DEF
 QH_metric_DEF
 QHnut_cap_DEF
 QHnut_cap_scale_DEF
* RISKfact_prev_LowBMI_DEF

* OBJ_TB_DEF
* OBJEQ
* OBJ_TB_DEF
 /
;


*10. FIXING VARIABLES NOT IN MODEL AT ZERO ##########################

S_TB.FX(h,t1_tb)$(ord(t1_tb) eq 1) = S_TB0(h,t1_tb) ;
L_TB.FX(h,t1_tb)$(ord(t1_tb) eq 1) = L_TB0(h,t1_tb) ;
I_TB.FX(h,t1_tb)$(ord(t1_tb) eq 1) = I_TB0(h,t1_tb) ;
Ir_TB.FX(h,t1_tb)$(ord(t1_tb) eq 1) = Ir_TB0(h,t1_tb) ;
T_TB.FX(h,t1_tb)$(ord(t1_tb) eq 1) = T_TB0(h,t1_tb) ;
Tr_TB.FX(h,t1_tb)$(ord(t1_tb) eq 1) = Tr_TB0(h,t1_tb) ;
*Lambda_TB.FX(h,t1_tb)$(ord(t1_tb) eq 1) = Lambda_TB0(h,t1_tb) ;
**Incid_TB.FX(h,t1_tb)$(ord(t1_tb) eq 1) = Incid_TB0(h,t1_tb) ;
**Prev_TB.FX(h,t1_tb)$(ord(t1_tb) eq 1) = Prev_TB0(h,t1_tb) ;
**Notif_TB.FX(h,t1_tb)$(ord(t1_tb) eq 1) = Notif_TB0(h,t1_tb) ;
**Mort_TB.FX(h,t1_tb)$(ord(t1_tb) eq 1) = Mort_TB0(h,t1_tb) ;

*POP_TB.FX(h,t1_tb) = POP_TB0(h,t1_tb) ;

*WALRAS.LO = 0;

RISKfact_prev.FX(RISKfact_set,h) = RISKfact_prev0(RISKfact_set,h);

*RR_TB.FX(h) = RR_TB0(h);

*a_TB.FX(h) = a_TB0(h);
*c_TB.FX(h) = c_TB0(h);

betaIN_TBmult.FX  = 1;
betaREL_TBmult.FX = 1;
d_TBmult.FX       = 1;

*11. MODEL CLOSURE ##################################################

QHnut_cap_day_scale.LO(H) = -inf;
QHnut_cap_day_scale.UP(H) = +inf;
QHnut_cap_day_final.FX(H) = QHnut_cap_day_final0(H);

*12. DISPLAY OF MODEL PARAMETERS AND VARIABLES ######################


*13. SOLUTION STATEMENT #############################################

OPTIONS ITERLIM = 1000, LIMROW = 3, LIMCOL = 3, SOLPRINT=ON,
        MCP=PATH, NLP=CONOPT3 ;

$ontext
These options are useful for debugging. When checking whether the
initial data represent a solution, set LIMROW to a value greater than
the number of equations and search for three asterisks in the listing
file. SOLPRINT=ON provides a complete listing file. The program also
has a number of display statements, so when running experiments it is
usually not necessary to provide a solution print as well.
$offtext

 STANDCGE.HOLDFIXED   = 1 ;
 STANDCGE.TOLINFREP   = .0001 ;

$ontext
The HOLDFIXED option converts all variables which are fixed (.FX) into
parameters. They are then not solved as part of the model.
The TOLINFREP parameter sets the tolerance for determinining whether
initial values of variables represent a solution of the model
equations. Whether these initial equation values are printed is
determimed by the LIMROW option. Equations which are not satsfied to
the degree TOLINFREP are printed with three asterisks next to their
listing.
$offtext


OPTIONS ITERLIM = 5000, MCP=PATHC, DNLP=CONOPT3 ;

*S_TB.FX(h,t1_tb)$(ord(t1_tb) eq 1) = S_TB0(h,t1_tb) - 0.05 ;
*L_TB.FX(h,t1_tb)$(ord(t1_tb) eq 1) = L_TB0(h,t1_tb) + 0.05 ;

 SOLVE TBmodel USING MCP ;
* SOLVE TBmodel MINIMIZING WALRASSQR USING DNLP ;

*Display 'here is TB',S_TB.L, L_TB.L, I_TB.L, Ir_TB.L, T_TB.L, Tr_TB.L;
*Display 'here is TB',S_TB.L, L_TB.L, I_TB.L, Ir_TB.L, T_TB.L, Tr_TB.L, POP_TB.L;
*Display POP_TB.L, Lambda_TB.L, Incid_TB.L, Prev_TB.L, Notif_TB.L, Mort_TB.L;

$ontext
RISKfact_prev.LO('r02',h) = -inf;
RISKfact_prev.UP('r02',h) = +inf;
$offtext

*RISKfact_prev.LO('r03',h) = -inf;
*RISKfact_prev.UP('r03',h) = +inf;

*q_TB = 0.60*q_TB;
*a_TB(h) = 0.30*a_TB(h);
*betaIN_TB(h) = 0.30*betaIN_TB(h);
*betaREL_TB(h) = 0.30*betaREL_TB(h);
*d_TB(h) = 2.0*d_TB(h);
*d_TB(h) = 0.66866173;

*S_TB.FX(h,t1_tb)$(ord(t1_tb) eq 1) = 1.1*S_TB0(h,t1_tb) ;

*tm0(c) = 1.5*tm0(c);

* SOLVE STANDCGE_TB MINIMIZING WALRASSQR USING DNLP ;
 SOLVE STANDCGE_TB USING MCP ;

RISKfact_prev.FX('r03',h) = SUM(PersonID$(((DHSdata0(h,PersonID,'Weight')+(365*(QHnut_cap_day_final.L(H)-QHnut_cap_day_final0(H))/7715))/POWER(DHSdata0(h,PersonID,'Height')/100,2))<18.5),1)/card(PersonID);

*Display 'here is TB',S_TB.L;
*Display 'here is TB',S_TB.L, L_TB.L, I_TB.L, Ir_TB.L, T_TB.L, Tr_TB.L, POP_TB.L;
Display 'here is walras',walras.L;

Display 'here is Nutrition', QHfood_metric.L, QHnut_cap_day.L, RISKfact_prev0, RISKfact_prev.L;





