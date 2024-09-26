
*###############################################################################
*######### SECTION 1.1: Basic Characteristics of Economy (Macro Level) #########
*###############################################################################

*Macro Targets
 TARGETS('GDPDEF',t1) = GDPDEF.L;
 TARGETS('CPI',t1)    = CPI.L;
 TARGETS('TFPadj',t1) = TFPadj.L;
 TARGETS('YG',t1)     = YG.L;
 TARGETS('GDN',t1)    = GDN.L;
 TARGETS('GADJ',t1)   = GADJ.L;
 TARGETS('RGCONS',t1) = SUM(C,PQ0(C)*QG.L(C));
 TARGETS('GSAV',t1)   = GSAV.L;

 QHnut_scale(H,t1)     = QHnut_cap_day_scale.L(H);

*Nominal Macro aggregates
 MACRO('GDP_N',t1)    = NGDP.L;
 MACRO('ABSORP_N',t1) = TABS.L;
 MACRO('CP_N',t1)     = NCP.L;
 MACRO('CG_N',t1)     = NCG.L;
 MACRO('IV_N',t1)     = NINV.L + NDST.L;
 MACRO('EXP_N',t1)    = NEXP.L;
 MACRO('IMP_N',t1)    = NIMP.L;

*NB: (real) MACRO variables calculated at bottom after demographic section
 MACRO('GDP_R',t1)    = SUM((C,H),PQ0(C)*QH.L(C,H)) + SUM((A,C,H),PXAC0(A,C)*QHA.L(A,C,H))
                      + SUM(C,PQ0(C)*QG.L(C)) + SUM(C,PQ0(C)*QINV.L(C)) + SUM(C,PQ0(C)*QDSTadj.L*qdst(C))
                      + SUM(C,PWElev0*pwe0(C)*QE.L(C))*EXR0 - SUM(C,PWMlev0*pwm0(C)*QM.L(C))*EXR0;
 MACRO('ABSORP_R',t1) = SUM((C,H),PQ0(C)*QH.L(C,H)) + SUM((A,C,H),PXAC0(A,C)*QHA.L(A,C,H))
                      + SUM(C,PQ0(C)*QG.L(C)) + SUM(C,PQ0(C)*QINV.L(C)) + SUM(C,PQ0(C)*QDSTadj.L*qdst(C));
 MACRO('CP_R',t1)     = SUM((C,H),PQ0(C)*QH.L(C,H)) + SUM((A,C,H),PXAC0(A,C)*QHA.L(A,C,H));
 MACRO('CG_R',t1)     = SUM(C,PQ0(C)*QG.L(C));
 MACRO('IV_R',t1)     = SUM(C,PQ0(C)*(QINV.L(C) + QDSTadj.L*qdst(C)));
 MACRO('EXP_R',t1)    = SUM(C,PWElev0*pwe0(C)*QE.L(C))*EXR0;
 MACRO('IMP_R',t1)    = SUM(C,PWMlev0*pwm0(C)*QM.L(C))*EXR0;

*###############################################################################
*########## SECTION 1.2: Basic Characteristics of Economy (Macro SAMs) #########
*###############################################################################


 MACSAM(t1,'COM','ACT')    = SUM((C,A),PQ.L(C)*QINT.L(C,A));
* MACSAM(t1,'FAC','ACT')    = SUM(A,PVA.L(A)*(1-tva(a))*QVA.L(A));
 MACSAM(t1,'FAC','ACT')    = SUM((A,F),WF.L(F)*wfdist.L(F,A)*QF.L(F,A));
 MACSAM(t1,'VATAX','ACT')  = SUM(A,tva(A)*PVA.L(A)*QVA.L(A));
* MACSAM(t1,'FACTAX','ACT') = SUM((A,F),(twfa_scale(F,A)*WF.L(F)*wfdist.L(F,A) + twfa_add(F,A))*QF.L(F,A));
 MACSAM(t1,'FACTAX','ACT') = SUM((A,F),(WFA.L(F,A)-WF.L(F)*wfdist.L(F,A))*QF.L(F,A));
 MACSAM(t1,'ACTTAX','ACT') = SUM(A,TA.L(A)*PA.L(A)*QA.L(A));

 MACSAM(t1,'COM','COM')    = SUM(C,PQ.L(C)*QT.L(C));
 MACSAM(t1,'ACT','COM')    = SUM((C,A),QXAC.L(A,C)*PXAC.L(A,C));
 MACSAM(t1,'ROW','COM')    = SUM(C,PWMlev.L*pwm.L(C)*QM.L(C))*EXR.L;
 MACSAM(t1,'COMTAX','COM') = SUM(C,TQ.L(C)*PQ.L(C)*QQ.L(C));
* MACSAM(t1,'IMPTAX','COM') = SUM(C,tm(C)*PWMlev.L*pwm.L(C)*QM.L(C))*EXR.L;
 MACSAM(t1,'IMPTAX','COM') = SUM(C,TM.L(C)*PWMlev.L*pwm.L(C)*QM.L(C))*EXR.L;
 MACSAM(t1,'EXPTAX','COM') = SUM(C,te(C)*PWElev.L*pwe.L(C)*QE.L(C))*EXR.L;

 MACSAM(t1,'HOU','FAC')    = SUM((INSDNG,F),YIF.L(INSDNG,F));
 MACSAM(t1,'GOV','FAC')    = SUM(F,YIF.L('GOV',F));
 MACSAM(t1,'ROW','FAC')    = SUM(F,trnsfr('ROW',F))*EXR.L;
 MACSAM(t1,'FACTAX','FAC') = SUM(f,TF.L(f)*YF.L(F));

 MACSAM(t1,'COM','HOU')    = SUM((C,H),PQ.L(C)*QH.L(C,H));
 MACSAM(t1,'ACT','HOU')    = SUM((A,C,H),PXAC.L(A,C)*QHA.L(A,C,H));
 MACSAM(t1,'INSTAX','HOU') = SUM(INSDNG,TINS.L(INSDNG)*YI.L(INSDNG));
 MACSAM(t1,'HOU','HOU')    = SUM((INSDNG,INSDNGP),TRII.L(INSDNG,INSDNGP));
 MACSAM(t1,'S-I','HOU')    = SUM(INSDNG,MPS.L(INSDNG) * (1 - TINS.L(INSDNG)) * YI.L(INSDNG));

 MACSAM(t1,'COM','GOV')    = SUM(C,PQ.L(C)*QG.L(C));
 MACSAM(t1,'HOU','GOV')    = SUM(INSD,trnsfr(INSD,'GOV'))*CPI.L;
 MACSAM(t1,'S-I','GOV')    = GSAV.L ;

 MACSAM(t1,'GOV','ACTTAX') = MACSAM(t1,'ACTTAX','ACT');
 MACSAM(t1,'GOV','COMTAX') = MACSAM(t1,'COMTAX','COM');
 MACSAM(t1,'GOV','IMPTAX') = MACSAM(t1,'IMPTAX','COM');
 MACSAM(t1,'GOV','EXPTAX') = MACSAM(t1,'EXPTAX','COM');
 MACSAM(t1,'GOV','FACTAX') = MACSAM(t1,'FACTAX','FAC') + MACSAM(t1,'FACTAX','ACT');
 MACSAM(t1,'GOV','INSTAX') = MACSAM(t1,'INSTAX','HOU');

 MACSAM(t1,'COM','ROW')    = SUM(C,PWElev.L*pwe.L(C)*QE.L(C))*EXR.L;
 MACSAM(t1,'HOU','ROW')    = SUM(INSDNG,trnsfr(INSDNG,'ROW'))*EXR.L;
 MACSAM(t1,'GOV','ROW')    = trnsfr('GOV','ROW')*EXR.L;
 MACSAM(t1,'S-I','ROW')    = FSAV.L*EXR.L ;

 MACSAM(t1,'COM','S-I')
  = SUM(C,PQ.L(C)*(QINV.L(C))) + SUM(C,PQ.L(C)*qdst(C));

 MACSAM(t1,'TOTAL',MACP)   = 0;
 MACSAM(t1,MAC,'TOTAL')    = 0;

 MACSAM(t1,'TOTAL',MACNTP) = SUM(MACNT, MACSAM(t1,MACNT,MACNTP));
 MACSAM(t1,MACNT,'TOTAL')  = SUM(MACNTP,MACSAM(t1,MACNT,MACNTP));

 MACSAM(t1,'DUMMY',MACP)   = 0;
 MACSAM(t1,MAC,'DUMMY')    = 0;


*###############################################################################
*######### SECTION 1.3: Basic Characteristics of Economy (Sector Level) ########
*###############################################################################

 STRUCHAR(t1,C,'VAshr')            = SUM(A$MAPAC(A,C),(PXAC.L(A,C)*QXAC.L(A,C)/SUM(CP,PXAC.L(A,CP)*QXAC.L(A,CP)))*
                                   ((PVA.L(A)*(1-tva(A))*QVA.L(A))/SUM(AP,PVA.L(AP)*(1-tva(AP))*QVA.L(AP))) );
 STRUCHAR(t1,'Total','VAshr')      = SUM(C,STRUCHAR(t1,C,'VAshr'));

 STRUCHAR(t1,C,'OUTshr')           = PX.L(C)*QX.L(C)/SUM(CP,PX.L(CP)*QX.L(CP)) ;
 STRUCHAR(t1,'Total','OUTshr')     = SUM(C,STRUCHAR(t1,C,'OUTshr'));

 STRUCHAR(t1,C,'DEMshr')           = PQ.L(C)*(1 - TQ.L(C))*QQ.L(C)/SUM(CP,PQ.L(CP)*(1 - TQ.L(CP))*QQ.L(CP));
 STRUCHAR(t1,'Total','DEMshr')     = SUM(C,STRUCHAR(t1,C,'DEMshr'));

 STRUCHAR(t1,C,'EXPshr')           = PWElev.L*pwe.L(C)*QE.L(C)/SUM(CP,PWElev.L*pwe.L(CP)*QE.L(CP));
 STRUCHAR(t1,'Total','EXPshr')     = SUM(C,STRUCHAR(t1,C,'EXPshr'));

 STRUCHAR(t1,C,'IMPshr')           = PWMlev.L*pwm.L(C)*QM.L(C)/SUM(CP,PWMlev.L*pwm.L(CP)*QM.L(CP));
 STRUCHAR(t1,'Total','IMPshr')     = SUM(C,STRUCHAR(t1,C,'IMPshr'));

 STRUCHAR(t1,C,'EXP-OUTshr')$(PX.L(C)*QX.L(C))
                                  = PE.L(C)*QE.L(C)/(PX.L(C)*QX.L(C));
 STRUCHAR(t1,'Total','EXP-OUTshr') = SUM(C$(PX.L(C)*QX.L(C)),PE.L(C)*QE.L(C))/SUM(CP,(PX.L(CP)*QX.L(CP)) );

 STRUCHAR(t1,C,'IMP-DEMshr')$(PQ.L(C)*(1 - TQ.L(C))*QQ.L(C))
                                  = PM.L(C)*QM.L(C)/(PQ.L(C)*(1 - TQ.L(C))*QQ.L(C));
 STRUCHAR(t1,'Total','IMP-DEMshr') = SUM(C$(PQ.L(C)*QQ.L(C)),PM.L(C)*QM.L(C))/SUM(CP,(PQ.L(CP)*(1 - TQ.L(CP))*QQ.L(CP)) );

display 'here is structchar,', STRUCHAR ;

*###############################################################################
*################### SECTION 2: Real multi-sector quantities ###################
*###############################################################################

*$ontext
*Commodities quantities
 QUANT_C('QD_CT',C,t1) = QD.L(C) ;
 QUANT_C('QE_CT',C,t1) = QE.L(C) ;
 QUANT_C('QG_CT',C,t1) = QG.L(C) ;
 QUANT_C('QINV_CT',C,t1) = QINV.L(C) ;
 QUANT_C('QM_CT',C,t1) = QM.L(C) ;
 QUANT_C('QQ_CT',C,t1) = QQ.L(C) ;
 QUANT_C('QT_CT',C,t1) = QT.L(C) ;
 QUANT_C('QX_CT',C,t1) = QX.L(C) ;

*Commodities prices
 PRICE_C('PDD_CT',C,t1) = PDD.L(C) ;
 PRICE_C('PDS_CT',C,t1) = PDS.L(C) ;
 PRICE_C('PE_CT',C,t1)  = PE.L(C) ;
 PRICE_C('PM_CT',C,t1)  = PM.L(C) ;
 PRICE_C('PQ_CT',C,t1)  = PQ.L(C) ;
 PRICE_C('PX_CT',C,t1)  = PX.L(C) ;

*Production quantities
 QUANT_A('QA_AT',A,t1)    = QA.L(A) ;
 QUANT_A('QINTA_AT',A,t1) = QINTA.L(A) ;
 QUANT_A('QVA_AT',A,t1)   = QVA.L(A) ;

*Production prices
 PRICE_A('PA_AT',A,t1)    = PA.L(A) ;
 PRICE_A('PINTA_AT',A,t1) = PINTA.L(A) ;
 PRICE_A('PVA_AT',A,t1)   = PVA.L(A) ;

*Factor demand
 QUANT_F('QF_FT',F,t1) = SUM(A,QF.L(F,A)) ;

*Factor prices
 PRICE_F('WF_FT',F,t1) = SUM(A,wfdist.L(F,A)*WF.L(F)*QF.L(F,A))/SUM(A,QF.L(F,A));
 PRICE_F('WF_FT',FLAB,t1) = 1E09*SUM(A,wfdist.L(FLAB,A)*WF.L(FLAB)*QF.L(FLAB,A))/(1E03*SUM(A,QF.L(FLAB,A)));

display 'here are prices', PRICE_A, PRICE_C, QUANT_A, QUANT_C ;
*$offtext


*###############################################################################
*######################### SECTION 3: Government budget ########################
*###############################################################################

 GOV('CG',t1) = SUM(C,PQ.L(C)*QG.L(C)) ;
 GOV('TG',t1) = SUM(INSDNG,trnsfr(INSDNG,'GOV'))*CPI.L ;
 GOV('YG',t1) = YG.L ;

* Tax rates
 TAXRATE('TA',A,t1) = TA.L(A) ;
 TAXRATE('TQ',C,t1) = TQ.L(C) ;
 TAXRATE('TH',H,t1) = TINS.L(H) ;


*###############################################################################
*####################### SECTION 4: HOUSEHOLD ##################################
*###############################################################################
$ontext
 HCON(C,H,t1) = QH.L(C,H) ;
 HWELF(H,t1)  = YH_EV_S.L(h) ;
$offtext
*###############################################################################
*######################### SECTION 5: OTHER ####################################
*###############################################################################

*###############################################################################
*######################### SECTION 6: Share ####################################
*###############################################################################

 AGSHARE('VAshr',t1)       = SUM(AAGR,PVA.L(AAGR)*QVA.L(AAGR))/SUM(A,PVA.L(A)*QVA.L(A));
 AGSHARE('VAshrN',t1)      = SUM(ANAGR,PVA.L(ANAGR)*QVA.L(ANAGR))/SUM(A,PVA.L(A)*QVA.L(A));

 AGSHARE('OUTshr',t1)      = SUM(AAGR,PA.L(AAGR)*QA.L(AAGR))/SUM(A,PA.L(A)*QA.L(A));
 AGSHARE('OUTshrN',t1)     = SUM(ANAGR,PA.L(ANAGR)*QA.L(ANAGR))/SUM(A,PA.L(A)*QA.L(A));

 AGSHARE('EXPshr',t1)      = SUM(CAGR,PE.L(CAGR)*QE.L(CAGR))/SUM(C,PE.L(C)*QE.L(C));
 AGSHARE('EXPshrN',t1)     = SUM(CNAGR,PE.L(CNAGR)*QE.L(CNAGR))/SUM(C,PE.L(C)*QE.L(C));

 AGSHARE('EXP-OUTshr',t1)  = SUM(CAGR,PE.L(CAGR)*QE.L(CAGR))/SUM(AAGR,PA.L(AAGR)*QA.L(AAGR)) ;
 AGSHARE('EXP-OUTshrN',t1) = SUM(CNAGR,PE.L(CNAGR)*QE.L(CNAGR))/SUM(ANAGR,PA.L(ANAGR)*QA.L(ANAGR)) ;

 AGSHARE('IMPshr',t1)      = SUM(CAGR,PM.L(CAGR)*QM.L(CAGR))/SUM(C,PM.L(C)*QM.L(C));
 AGSHARE('IMPshrN',t1)     = SUM(CNAGR,PM.L(CNAGR)*QM.L(CNAGR))/SUM(C,PM.L(C)*QM.L(C));

 AGSHARE('DEMshr',t1)      = SUM(CAGR,PQ.L(CAGR)*QQ.L(CAGR))/SUM(C,PQ.L(C)*QQ.L(C));
 AGSHARE('DEMshrN',t1)     = SUM(CNAGR,PQ.L(CNAGR)*QQ.L(CNAGR))/SUM(C,PQ.L(C)*QQ.L(C));

 AGSHARE('IMP-DEMshr',t1)  = SUM(CAGR,PM.L(CAGR)*QM.L(CAGR))/SUM(CAGR,PQ.L(CAGR)*QQ.L(CAGR));
 AGSHARE('IMP-DEMshrN',t1) = SUM(CNAGR,PM.L(CNAGR)*QM.L(CNAGR))/SUM(CNAGR,PQ.L(CNAGR)*QQ.L(CNAGR));

display 'here is agshare', AGSHARE ;

*###############################################################################
*########################### SECTION 7: Price Indices ##########################
*###############################################################################

*## Price Indices
* Calcuate using Laspeyres price index
 PINDICES('PIND',t1)  = DPI.L ;
 PINDICES('PINDD',t1) = SUM(C,PDD.L(C)*QD0(C))/SUM(CP,PDD0(CP)*QD0(CP)) ;
 PINDICES('PINDQ',t1) = SUM(C,PQ.L(C)*QQ0(C))/SUM(CP,PQ0(CP)*QQ0(CP)) ;
 PINDICES('PINDA',t1) = SUM(A,PA.L(A)*QA0(A))/SUM(AP,PA0(AP)*QA0(AP) );
 PINDICES('PINDVA',t1) = SUM(A,PVA.L(A)*QVA0(A))/SUM(AP,PVA0(AP)*QVA0(AP)) ;
 PINDICES('PINDE',t1)= SUM(C,PE.L(C)*QE0(C))/SUM(CP,PE0(CP)*QE0(CP)) ;
 PINDICES('PINDM',t1) = SUM(C,PM.L(C)*QM0(C))/SUM(CP,PM0(CP)*QM0(CP)) ;
 PINDICES('PINDC',t1) = CPI.L/CPI0;
 PINDICES('PINDT',t1) = SUM(CP,PE.L(CP)*QE0(CP) + PM.L(CP)*QM0(CP))/SUM(CP,PE0(CP)*QE0(CP) + PM0(CP)*QM0(CP)) ;
 PINDICES('PINDNT',t1) = SUM(CP,PDD.L(CP)*QD0(CP)+SUM((AP,H),PXAC.L(AP,CP)*QHA0(AP,CP,H)))/SUM(CP,PDD0(CP)*QD0(CP)+SUM((AP,H),PXAC0(AP,CP)*QHA0(AP,CP,H))) ;
$ontext
*## Factor Return Indices
 PINDICES('USKIND',t1) = SUM(A,WF.L('f05')*WFDIST.L('f01',A)*QF0('f01',A))/SUM(AP,WF0('f01')*WFDIST0('f01',AP)*QF0('f01',AP)) ;
 PINDICES('SKIND',t1) =SUM(A,WF.L('f06')*WFDIST.L('f02',A)*QF0('f02',A))/SUM(AP,WF0('f02')*WFDIST0('f02',AP)*QF0('f02',AP)) ;
 PINDICES('CAPIND',t1) =SUM(A,WF.L('f07')*WFDIST.L('f03',A)*QF0('f03',A)) /SUM(AP,WF0('f03')*WFDIST0('f03',AP)*QF0('f03',AP)) ;
$offtext

*## Nominal and Real Exchange Rate Indices
 PINDICES('NEXR',t1) = EXR.L/EXR0 ;
 PINDICES('REXR',t1) = PINDICES('PINDT',t1)/PINDICES('PINDNT',t1) ;

*## Agricultural and Non-agricultural Price Indices
 AGPINDICES('AGTOTD',t1) = (SUM(CAGR,(PDD.L(CAGR)*QD0(CAGR))/SUM(CNAGR,PDD.L(CNAGR)*QD0(CNAGR))))/(SUM(CAGRP,PDD0(CAGRP)*QD0(CAGRP))/SUM(CNAGRP,PDD0(CNAGRP)*QD0(CNAGRP)))  ;
 AGPINDICES('AGTOTQ',t1) = (SUM(CAGR,PQ.L(CAGR)*QQ0(CAGR))/(SUM(CNAGR,PQ.L(CNAGR)*QQ0(CNAGR))))/(SUM(CAGRP,PQ0(CAGRP)*QQ0(CAGRP))/SUM(CNAGRP,PQ0(CNAGRP)*QQ0(CNAGRP))) ;
 AGPINDICES('AGTOTA',t1) = (SUM(AAGR,PA.L(AAGR)*QA0(AAGR))/SUM(ANAGR,PA.L(ANAGR)*QA0(ANAGR)))/(SUM(AAGRP,PA0(AAGRP)*QA0(AAGRP))/SUM(ANAGRP,PA0(ANAGRP)*QA0(ANAGRP)) ) ;
 AGPINDICES('AGTOTVA',t1) = (SUM(AAGR,PVA.L(AAGR)*QVA0(AAGR))/SUM(ANAGR,PVA.L(ANAGR)*QVA0(ANAGR)))/(SUM(AAGRP,PVA0(AAGRP)*QVA0(AAGRP))/SUM(ANAGRP,PVA0(ANAGRP)*QVA0(ANAGRP))) ;
 AGPINDICES('AGTOTE',t1) = (SUM(CAGR,PE.L(CAGR)*QE0(CAGR))/SUM(CNAGR,PE.L(CNAGR)*QE0(CNAGR)))/(SUM(CAGRP,PE0(CAGRP)*QE0(CAGRP))/SUM(CNAGRP,PE0(CNAGRP)*QE0(CNAGRP))) ;
 AGPINDICES('AGTOTM',t1) =(SUM(CAGR,PM.L(CAGR)*QM0(CAGR))/SUM(CNAGR,PM.L(CNAGR)*QM0(CNAGR)))/(SUM(CAGRP,PM0(CAGRP)*QM0(CAGRP))/SUM(CNAGRP,PM0(CNAGRP)*QM0(CNAGRP)) ) ;
 AGPINDICES('AGTOTC',t1) =(SUM(CAGR,PQ.L(CAGR)*SUM(H,QH0(CAGR,H)))/SUM(CNAGR,PQ.L(CNAGR)*SUM(H,QH0(CNAGR,H))))/(SUM((CAGRP,HP),PQ0(CAGRP)*QH0(CAGRP,HP))/SUM((CNAGRP,HP),PQ0(CNAGRP)*QH0(CNAGRP,HP))) ;

display 'here are indices', PRICE_A, PRICE_C, QUANT_A, QUANT_C ;

*###############################################################################
*################# SECTION 8: Health & Epidemiological Effects #################
*###############################################################################

$ontext
 EPIagg(h,'S_TB',t1)     = SUM(t1_tb$(ord(t1_tb) eq card(t1_tbp)),S_TB_T0(t1,h,t1_tb))/52;
 EPIagg(h,'L_TB',t1)     = SUM(t1_tb$(ord(t1_tb) eq card(t1_tbp)),L_TB_T0(t1,h,t1_tb))/52;
 EPIagg(h,'I_TB',t1)     = SUM(t1_tb$(ord(t1_tb) eq card(t1_tbp)),I_TB_T0(t1,h,t1_tb))/52;
 EPIagg(h,'Ir_TB',t1)    = SUM(t1_tb$(ord(t1_tb) eq card(t1_tbp)),Ir_TB_T0(t1,h,t1_tb))/52;
 EPIagg(h,'T_TB',t1)     = SUM(t1_tb$(ord(t1_tb) eq card(t1_tbp)),T_TB_T0(t1,h,t1_tb))/52;
 EPIagg(h,'Tr_TB',t1)    = SUM(t1_tb$(ord(t1_tb) eq card(t1_tbp)),Tr_TB_T0(t1,h,t1_tb))/52;
 EPIagg(h,'POP_TB',t1)   = SUM(t1_tb$(ord(t1_tb) eq card(t1_tbp)),POP_TB_T0(t1,h,t1_tb))/52;
 EPIagg(h,'Lambda_TB',t1) = SUM(t1_tb$(ord(t1_tb) eq card(t1_tbp)),Lambda_TB_T0(t1,h,t1_tb));
 EPIagg(h,'Incid_TB',t1) = SUM(t1_tb$(ord(t1_tb) eq card(t1_tbp)),Incid_TB_T0(t1,h,t1_tb));
 EPIagg(h,'Prev_TB',t1)  = SUM(t1_tb$(ord(t1_tb) eq card(t1_tbp)),Prev_TB_T0(t1,h,t1_tb));
 EPIagg(h,'Notif_TB',t1) = SUM(t1_tb$(ord(t1_tb) eq card(t1_tbp)),Notif_TB_T0(t1,h,t1_tb));
 EPIagg(h,'Mort_TB',t1)  = SUM(t1_tb$(ord(t1_tb) eq card(t1_tbp)),Mort_TB_T0(t1,h,t1_tb));
$offtext

 EPIagg(h,'S_TB',t1)     = SUM(t1_tb,S_TB_T0(t1,h,t1_tb))/52;
 EPIagg(h,'L_TB',t1)     = SUM(t1_tb,L_TB_T0(t1,h,t1_tb))/52;
 EPIagg(h,'I_TB',t1)     = SUM(t1_tb,I_TB_T0(t1,h,t1_tb))/52;
 EPIagg(h,'Ir_TB',t1)    = SUM(t1_tb,Ir_TB_T0(t1,h,t1_tb))/52;
 EPIagg(h,'T_TB',t1)     = SUM(t1_tb,T_TB_T0(t1,h,t1_tb))/52;
 EPIagg(h,'Tr_TB',t1)    = SUM(t1_tb,Tr_TB_T0(t1,h,t1_tb))/52;
 EPIagg(h,'POP_TB',t1)   = SUM(t1_tb,POP_TB_T0(t1,h,t1_tb))/52;
 EPIagg(h,'Lambda_TB',t1) = SUM(t1_tb,Lambda_TB_T0(t1,h,t1_tb))/52;
 EPIagg(h,'Incid_TB',t1) = SUM(t1_tb,Incid_TB_T0(t1,h,t1_tb));
 EPIagg(h,'Prev_TB',t1)  = SUM(t1_tb,Prev_TB_T0(t1,h,t1_tb))/52;
 EPIagg(h,'Notif_TB',t1) = SUM(t1_tb,Notif_TB_T0(t1,h,t1_tb));
 EPIagg(h,'Mort_TB',t1)  = SUM(t1_tb,Mort_TB_T0(t1,h,t1_tb));

 EPIagg(h,'RR_r01_prev_TB',t1)    = Riskfact_prev_T0(t1,'r01',h);
 EPIagg(h,'RR_r02_prev_TB',t1)    = Riskfact_prev_T0(t1,'r02',h);
 EPIagg(h,'RR_r03_prev_TB',t1)    = Riskfact_prev_T0(t1,'r03',h);
 EPIagg(h,'RR_r04_prev_TB',t1)    = Riskfact_prev_T0(t1,'r04',h);
 EPIagg(h,'RR_r05_prev_TB',t1)    = Riskfact_prev_T0(t1,'r05',h);
 EPIagg(h,'RR_r06_prev_TB',t1)    = Riskfact_prev_T0(t1,'r06',h);
 EPIagg(h,'RR_TB',t1)    = RR_TB_T0(t1,h);

 EPIagg(h,'a_TB',t1)     = a_TB_T0(t1,h);
 EPIagg(h,'q_TB',t1)     = q_TB_T0(t1,h);
 EPIagg(h,'tau_TB',t1)   = tau_TB_T0(t1,h);
 EPIagg(h,'betaREL_TB',t1) = betaREL_TB_T0(t1,h);
 EPIagg(h,'betaIN_TB',t1) = betaIN_TB_T0(t1,h);
 EPIagg(h,'u_TB',t1)     = u_TB_T0(t1,h);
 EPIagg(h,'m_TB',t1)     = m_TB_T0(t1,h);
 EPIagg(h,'eps_TB',t1)   = eps_TB_T0(t1,h);
 EPIagg(h,'c_TB',t1)     = c_TB_T0(t1,h);
 EPIagg(h,'d_TB',t1)     = d_TB_T0(t1,h);
 EPIagg(h,'nu_TB',t1)    = nu_TB_T0(t1,h);

 EPIdisagg(h,'S_TB',t1_tb,t1)     = S_TB_T0(t1,h,t1_tb);
 EPIdisagg(h,'L_TB',t1_tb,t1)     = L_TB_T0(t1,h,t1_tb);
 EPIdisagg(h,'I_TB',t1_tb,t1)     = I_TB_T0(t1,h,t1_tb);
 EPIdisagg(h,'Ir_TB',t1_tb,t1)    = Ir_TB_T0(t1,h,t1_tb);
 EPIdisagg(h,'T_TB',t1_tb,t1)     = T_TB_T0(t1,h,t1_tb);
 EPIdisagg(h,'Tr_TB',t1_tb,t1)    = Tr_TB_T0(t1,h,t1_tb);
 EPIdisagg(h,'POP_TB',t1_tb,t1)   = POP_TB_T0(t1,h,t1_tb);
 EPIdisagg(h,'Lambda_TB',t1_tb,t1) = Lambda_TB_T0(t1,h,t1_tb);
 EPIdisagg(h,'Incid_TB',t1_tb,t1) = Incid_TB_T0(t1,h,t1_tb);
 EPIdisagg(h,'Prev_TB',t1_tb,t1)  = Prev_TB_T0(t1,h,t1_tb);
 EPIdisagg(h,'Notif_TB',t1_tb,t1) = Notif_TB_T0(t1,h,t1_tb);
 EPIdisagg(h,'Mort_TB',t1_tb,t1)  = Mort_TB_T0(t1,h,t1_tb);

*###############################################################################
*######################## SECTION 9: Simulation Targets ########################
*###############################################################################

* See under Macro Indicators (Section 1)

*###############################################################################
*############################ SECTION 10: Demography ###########################
*###############################################################################

DEMOG(H,'POP',age5,t1)         = SUM(gen,       POP(h,gen,age5,t1));
DEMOG(H,'POP','total',t1)      = SUM((age5,gen),POP(h,gen,age5,t1));
*DEMOG(H,'BIRTHS',age5,t1)      = SUM(gen,       BIRTHS(h,gen,t1));
DEMOG(H,'BIRTHS','total',t1)   = SUM(gen,       BIRTHS(h,gen,t1));
DEMOG(H,'DEATHS',age5,t1)      = SUM(gen,       DEATHS(h,gen,age5,t1));
DEMOG(H,'DEATHS','total',t1)   = SUM((age5,gen),DEATHS(h,gen,age5,t1));
DEMOG(H,'IntlMIGR',age5,t1)    = SUM(gen,       IntlMIGR(h,gen,age5,t1));
DEMOG(H,'IntlMIGR','total',t1) = SUM((age5,gen),IntlMIGR(h,gen,age5,t1));

CLINOUToutput(h,'MORT',gen,age5,t1)        = (EPIagg(H,'Mort_TB',t1)/EPIagg(h,'POP_TB',t1))*DEMOG(H,'POP','total',t1)*TBmort_share(h,gen,age5);
CLINOUToutput(h,'MORT','total',age5,t1)    = SUM(gen,CLINOUToutput(h,'MORT',gen,age5,t1));
CLINOUToutput(h,'MORT',gentot,'total',t1)  = SUM(age5,CLINOUToutput(h,'MORT',gentot,age5,t1));

CLINOUToutput(h,'INCID',gen,age5,t1)       = (EPIagg(H,'Incid_TB',t1)/EPIagg(h,'POP_TB',t1))*DEMOG(H,'POP','total',t1)*TBincid_share(h,gen,age5);
CLINOUToutput(h,'INCID','total',age5,t1)   = SUM(gen,CLINOUToutput(h,'INCID',gen,age5,t1));
CLINOUToutput(h,'INCID',gentot,'total',t1) = SUM(age5,CLINOUToutput(h,'INCID',gentot,age5,t1));

CLINOUToutput(h,'PREV','total',age5,t1)    = (EPIagg(H,'Prev_TB',t1)/EPIagg(h,'POP_TB',t1))*DEMOG(H,'POP',age5,t1);
CLINOUToutput(h,'Prev','total','total',t1) = SUM(age5,CLINOUToutput(h,'Prev','total',age5,t1));

*###############################################################################
*################## SECTION 11: Deflation and NPV Calculations #################
*###############################################################################

 dGDPDEF_t(t1) = 1/GDPDEF_T0(t1);

 NPVMAC(MACSET) = SUM(t1p$(ord(t1p) gt (card(tp)-1)),dfactor_t(t1p)*MACRO(MACSET,t1p));
 DEFMAC(MACSET) = SUM(t1p$(ord(t1p) gt (card(tp)-1)),dGDPDEF_t(t1p)*MACRO(MACSET,t1p));

IF(ord(t1) = card(t1),
 HHAGG('NPV_EH',h) = SUM(t1p$(ord(t1p) gt (card(tp)-1)),dfactor_t(t1p)*EH_T0(h,t1p));
 HHAGG('NPV_YH',h) = SUM(t1p$(ord(t1p) gt (card(tp)-1)),dfactor_t(t1p)*YI_T0(h,t1p));
 HHAGG('NPV_FLAB',h) = SUM(t1p$(ord(t1p) gt (card(tp)-1)),dfactor_t(t1p)*SUM(flab,YIF_T0(h,flab,t1p)));
 HHAGG('NPV_FCAP',h) = SUM(t1p$(ord(t1p) gt (card(tp)-1)),dfactor_t(t1p)*SUM(fcap,YIF_T0(h,fcap,t1p)));

 HHAGG('LAB_unskl',h) = SUM(ts,QFH_T0(h,'f01',ts));
 HHAGG('LAB_skill',h) = SUM(ts,QFH_T0(h,'f02',ts));

 HHAGG('POP',h)             = SUM(ts,SUM((gen,age5),POP_T0(ts,h,gen,age5)));
 HHAGG('POPsuscpt',h)       = (1-TAB_Scen01)*SUM(ts,(EPIagg(h,'S_TB',ts)/EPIagg(h,'POP_TB',ts))*SUM((gen,age5),POP_T0(ts,h,gen,age5)));
 HHAGG('POPlatent',h)       = (1-TAB_Scen01)*SUM(ts,(EPIagg(h,'L_TB',ts)/EPIagg(h,'POP_TB',ts))*SUM((gen,age5),POP_T0(ts,h,gen,age5)));
 HHAGG('POPinfect',h)       = (1-TAB_Scen01)*SUM(ts,(EPIagg(h,'I_TB',ts)/EPIagg(h,'POP_TB',ts))*SUM((gen,age5),POP_T0(ts,h,gen,age5)));
 HHAGG('POPinfect_r',h)     = (1-TAB_Scen01)*SUM(ts,(EPIagg(h,'Ir_TB',ts)/EPIagg(h,'POP_TB',ts))*SUM((gen,age5),POP_T0(ts,h,gen,age5)));
 HHAGG('POPtreat',h)        = (1-TAB_Scen01)*SUM(ts,(EPIagg(h,'T_TB',ts)/EPIagg(h,'POP_TB',ts))*SUM((gen,age5),POP_T0(ts,h,gen,age5)));
 HHAGG('POPtreat_r',h)      = (1-TAB_Scen01)*SUM(ts,(EPIagg(h,'Tr_TB',ts)/EPIagg(h,'POP_TB',ts))*SUM((gen,age5),POP_T0(ts,h,gen,age5)));
 HHAGG('POPincid',h)        = (1-TAB_Scen01)*SUM(ts,(EPIagg(h,'Incid_TB',ts)/EPIagg(h,'POP_TB',ts))*SUM((gen,age5),POP_T0(ts,h,gen,age5)));
 HHAGG('POPprev',h)         = (1-TAB_Scen01)*SUM(ts,(EPIagg(h,'Prev_TB',ts)/EPIagg(h,'POP_TB',ts))*SUM((gen,age5),POP_T0(ts,h,gen,age5)));
 HHAGG('POPnotif',h)        = (1-TAB_Scen01)*SUM(ts,(EPIagg(h,'Notif_TB',ts)/EPIagg(h,'POP_TB',ts))*SUM((gen,age5),POP_T0(ts,h,gen,age5)));
 HHAGG('POPfatal',h)        = (1-TAB_Scen01)*SUM(ts,(EPIagg(h,'Mort_TB',ts)/EPIagg(h,'POP_TB',ts))*SUM((gen,age5),POP_T0(ts,h,gen,age5)));

 HHAGG('RR_r01_prev_avg',h) = (1-TAB_Scen01)*SUM(ts,EPIagg(h,'RR_r01_prev_TB',ts))/card(ts);
 HHAGG('RR_r02_prev_avg',h) = (1-TAB_Scen01)*SUM(ts,EPIagg(h,'RR_r02_prev_TB',ts))/card(ts);
 HHAGG('RR_r03_prev_avg',h) = (1-TAB_Scen01)*SUM(ts,EPIagg(h,'RR_r03_prev_TB',ts))/card(ts);
 HHAGG('RR_r04_prev_avg',h) = (1-TAB_Scen01)*SUM(ts,EPIagg(h,'RR_r04_prev_TB',ts))/card(ts);
 HHAGG('RR_r05_prev_avg',h) = (1-TAB_Scen01)*SUM(ts,EPIagg(h,'RR_r05_prev_TB',ts))/card(ts);
 HHAGG('RR_r06_prev_avg',h) = (1-TAB_Scen01)*SUM(ts,EPIagg(h,'RR_r06_prev_TB',ts))/card(ts);
 HHAGG('RR_avg',h)          = (1-TAB_Scen01)*SUM(ts,EPIagg(h,'RR_TB',ts))/card(ts);

 HHAGG('NUTcapday_avg',h) = SUM(ts,QHnut_cap_day_final_T0(h,ts))/card(ts);
);

 MACROpercap(MACSET,t1p)$POPTOT(t1p) = TARGETscale*MACRO(MACSET,t1p)/(TARGETscale_POP*POPTOT(t1p));

*###############################################################################
*###################### SECTION 12: Indicator Calculations #####################
*###############################################################################


INDIC_SC('CPI',t1)           = CPI_T0(t1);
INDIC_SC('IPI',t1)           = IPI_T0(t1);
INDIC_SC('DMPS',t1)          = DMPS_T0(t1);
INDIC_SC('DPI',t1)           = DPI_T0(t1);
INDIC_SC('DTINS',t1)         = DTINS_T0(t1);
INDIC_SC('EG',t1)            = EG_T0(t1);
INDIC_SC('EXR',t1)           = EXR_T0(t1);
INDIC_SC('FSAV',t1)          = FSAV_T0(t1);
INDIC_SC('GADJ',t1)          = GADJ_T0(t1);
*  INDIC_SC('GDN',t1)           = GDN_T0(t1);
INDIC_SC('GOVSHR',t1)        = GOVSHR_T0(t1);
INDIC_SC('GSAV',t1)          = GSAV_T0(t1);
INDIC_SC('IADJ',t1)          = IADJ_T0(t1);
INDIC_SC('INVSHR',t1)        = INVSHR_T0(t1);
INDIC_SC('MPSADJ',t1)        = MPSADJ_T0(t1);
INDIC_SC('TABS',t1)          = TABS_T0(t1);
INDIC_SC('TINSADJ',t1)       = TINSADJ_T0(t1);
INDIC_SC('WALRAS',t1)        = WALRAS_T0(t1);
INDIC_SC('WALRASSQR',t1)     = WALRASSQR_T0(t1);
INDIC_SC('YG',t1)            = YG_T0(t1);

INDIC_A('PA',A,t1)         = PA_T0(A,t1);
INDIC_A('PINTA',A,t1)      = PINTA_T0(A,t1);
INDIC_A('PVA',A,t1)        = PVA_T0(A,t1);
INDIC_A('QA',A,t1)         = QA_T0(A,t1);
INDIC_A('QINTA',A,t1)      = QINTA_T0(A,t1);
INDIC_A('QVA',A,t1)        = QVA_T0(A,t1);

INDIC_C('PDD',C,t1)        = PDD_T0(C,t1);
INDIC_C('PDS',C,t1)        = PDS_T0(C,t1);
INDIC_C('PE',C,t1)         = PE_T0(C,t1);
INDIC_C('PM',C,t1)         = PM_T0(C,t1);
INDIC_C('PQ',C,t1)         = PQ_T0(C,t1);
INDIC_C('PWE',C,t1)        = PWE_T0(C,t1);
INDIC_C('PWM',C,t1)        = PWM_T0(C,t1);
INDIC_C('PX',C,t1)         = PX_T0(C,t1);
INDIC_C('QD',C,t1)         = QD_T0(C,t1);
INDIC_C('QE',C,t1)         = QE_T0(C,t1);
INDIC_C('QG',C,t1)         = QG_T0(C,t1);
INDIC_C('QINV',C,t1)       = QINV_T0(C,t1);
INDIC_C('QM',C,t1)         = QM_T0(C,t1);
INDIC_C('QQ',C,t1)         = QQ_T0(C,t1);
INDIC_C('QT',C,t1)         = QT_T0(C,t1);
INDIC_C('QX',C,t1)         = QX_T0(C,t1);

INDIC_F('QFS',F,t1)        = QFS_T0(F,t1);
INDIC_F('WF',F,t1)         = WF_T0(F,t1);
INDIC_F('YF',f,t1)         = SUM(H, WFH.L(F)*wfhdist.L(H,F)*QFH.L(H,F));

INDIC_INS('EH',H,t1)      = EH_T0(H,t1);
INDIC_INS('MPS',INSDNG,t1)   = MPS_T0(INSDNG,t1);
INDIC_INS('TINS',INSDNG,t1)  = TINS_T0(INSDNG,t1);
INDIC_INS('YI',INS,t1)       = YI_T0(INS,t1);

INDIC_FA('QF',F,A,t1)        = QF_T0(F,A,t1);

INDIC_QH(H,C,t1)             = QH_T0(c,h,t1);

Display 'here are indicators', INDIC_SC, INDIC_A, INDIC_C, INDIC_F, INDIC_INS, INDIC_FA, INDIC_QH;

*###############################################################################
*######################## SECTION 13: TABLE Calculations #######################
*###############################################################################



*## KEY INDICATORS

KEY_INDIC('Walras',t1) = Walras.L;

KEY_INDIC('NomGDP',t1) = NGDP_T0(t1);
KEY_INDIC('RealGDP',t1) = RGDP_T0(t1);

KEY_INDIC('NomGDPfac',t1) = SUM((A,F),WF.L(F)*wfdist.L(F,A)*QF.L(F,A));
KEY_INDIC('RealGDPfac',t1) = SUM((A,F),WF0(F)*wfdist0(F,A)*QF.L(F,A));

KEY_INDIC('NomHCONS',t1) = MACRO('CP_N',t1);
KEY_INDIC('RealHCONS',t1) = MACRO('CP_R',t1);

KEY_INDIC('NomGCONS',t1) = MACRO('CG_N',t1);
KEY_INDIC('RealGCONS',t1) = MACRO('CG_R',t1);

KEY_INDIC('NomINV',t1) = MACRO('IV_N',t1);
KEY_INDIC('RealINV',t1) = MACRO('IV_R',t1);

KEY_INDIC('NomEXP',t1) = MACRO('EXP_N',t1);
KEY_INDIC('RealEXP',t1) = MACRO('EXP_R',t1);

KEY_INDIC('NomIMP',t1) = MACRO('IMP_N',t1);
KEY_INDIC('RealIMP',t1) = MACRO('IMP_R',t1);

KEY_INDIC('GDPDEF',t1) = GDPDEF_T0(t1);
KEY_INDIC('CPI',t1) = CPI_T0(t1);
KEY_INDIC('IPI',t1) = IPI_T0(t1);
KEY_INDIC('EXR',t1) = EXR_T0(t1);

KEY_INDIC('YH',t1) = SUM(h,YI_T0(h,t1));
KEY_INDIC('YFLND',t1) = SUM((flnd,h),YIF_T0(h,flnd,t1));
KEY_INDIC('YFLAB',t1) = SUM((flab,h),YIF_T0(h,flab,t1));
KEY_INDIC('YFCAP',t1) = SUM((fcap,insd),YIF_T0(insd,fcap,t1));

KEY_INDIC('HCON',t1) = (SUM((C,H), PQ.L(C)*QH.L(C,H)) + SUM((A,C,H), PXAC.L(A,C)*QHA.L(A,C,H)));

KEY_INDIC('GovRevenue',t1) = TARGETS('YG',t1);
KEY_INDIC('TQ',t1)         = SUM(C, TQ.L(c)*PQ0(C)*QQ0(C))/SUM(C, PQ0(C)*QQ0(C));
KEY_INDIC('TQadd',t1)      = TQadd_T0(t1);
KEY_INDIC('TQscale',t1)    = TQscale_T0(t1);
KEY_INDIC('TM',t1)         = SUM(C, TM.L(c)*PWMlev0*pwm0(C)*QM0(C))/SUM(C, PWMlev0*pwm0(C)*QM0(C));
KEY_INDIC('TMadd',t1)      = TMadd_T0(t1);
KEY_INDIC('TMscale',t1)    = TMscale_T0(t1);
$ontext
KEY_INDIC('TWFA_f01',t1)   = SUM(A, (twfa_scale01('f01')*TWFA_scale.L*WF0('f01')*wfdist0('f01',A) + twfa_add01('f01')*TWFA_add.L)*QF0('f01',A))/SUM(A,WF0('f01')*wfdist0('f01',A)*QF0('f01',A));
KEY_INDIC('TWFA_f02',t1)   = SUM(A, (twfa_scale01('f02')*TWFA_scale.L*WF0('f02')*wfdist0('f02',A) + twfa_add01('f02')*TWFA_add.L)*QF0('f02',A))/SUM(A,WF0('f02')*wfdist0('f02',A)*QF0('f02',A));
KEY_INDIC('TWFA_f03',t1)   = SUM(A, (twfa_scale01('f03')*TWFA_scale.L*WF0('f03')*wfdist0('f03',A) + twfa_add01('f03')*TWFA_add.L)*QF0('f03',A))/SUM(A,WF0('f03')*wfdist0('f03',A)*QF0('f03',A));
KEY_INDIC('TWFA_f04',t1)   = SUM(A, (twfa_scale01('f04')*TWFA_scale.L*WF0('f04')*wfdist0('f04',A) + twfa_add01('f04')*TWFA_add.L)*QF0('f04',A))/SUM(A,WF0('f04')*wfdist0('f04',A)*QF0('f04',A));
KEY_INDIC('TWFA_f05',t1)   = SUM(A, (twfa_scale01('f05')*TWFA_scale.L*WF0('f05')*wfdist0('f05',A) + twfa_add01('f05')*TWFA_add.L)*QF0('f05',A))/SUM(A,WF0('f05')*wfdist0('f05',A)*QF0('f05',A));
KEY_INDIC('TWFA_f06',t1)   = SUM(A, (twfa_scale01('f06')*TWFA_scale.L*WF0('f06')*wfdist0('f06',A) + twfa_add01('f06')*TWFA_add.L)*QF0('f06',A))/SUM(A,WF0('f06')*wfdist0('f06',A)*QF0('f06',A));
KEY_INDIC('TWFA_f07',t1)   = SUM(A, (twfa_scale01('f07')*TWFA_scale.L*WF0('f07')*wfdist0('f07',A) + twfa_add01('f07')*TWFA_add.L)*QF0('f07',A))/SUM(A,WF0('f07')*wfdist0('f07',A)*QF0('f07',A));
KEY_INDIC('TWFA_f08',t1)   = SUM(A, (twfa_scale01('f08')*TWFA_scale.L*WF0('f08')*wfdist0('f08',A) + twfa_add01('f08')*TWFA_add.L)*QF0('f08',A))/SUM(A,WF0('f08')*wfdist0('f08',A)*QF0('f08',A));
KEY_INDIC('TWFAadd',t1)    = TWFAadd_T0(t1);
KEY_INDIC('TINS_ent',t1)   = TINS_T0('ENT',t1);
KEY_INDIC('TWFAscale',t1)  = TWFAscale_T0(t1);
$offtext
KEY_INDIC('POP',t1) = SUM((h,gen,age5),POP_H0(h,gen,age5,t1));

KEY_INDIC_H('YH',h,t1) = YI_T0(h,t1);
KEY_INDIC_H('YH_R',h,t1) = (YI_T0(h,t1)/(CPI_H_T0(H,t1)/SUM(t1_base,CPI_H_T0(H,t1_base))));
KEY_INDIC_H('CPI_H',h,t1) = CPI_H_T0(H,t1);
KEY_INDIC_H('YFLND',h,t1) = SUM(flnd,YIF_T0(h,flnd,t1));
KEY_INDIC_H('YFLAB',h,t1) = SUM(flab,YIF_T0(h,flab,t1));
KEY_INDIC_H('YFCAP',h,t1) = SUM(fcap,YIF_T0(h,fcap,t1)) + SUM(en,TRII.L(h,en));
KEY_INDIC_H('HCON',h,t1) = (SUM(C, PQ.L(C)*QH.L(C,H)) + SUM((A,C), PXAC.L(A,C)*QHA.L(A,C,H)));
*KEY_INDIC_H('HCON_R',h,t1) = SUM(t1_base,SUM(C,PQ_T0(C,t1_base)*QH_T0(C,H,t1)) + SUM((A,C),PXAC_T0(A,C,t1_base)*QHA_T0(A,C,H,t1)));
KEY_INDIC_H('HCON_R',h,t1) = SUM(C,PQ0(C)*QH_T0(C,H,t1)) + SUM((A,C),PXAC0(A,C)*QHA_T0(A,C,H,t1));
KEY_INDIC_H('QFH',h,t1) = SUM(flab,QFH.L(h,flab));

KEY_INDIC_H('POP',h,t1) = SUM((gen,age5),POP_T0(t1,h,gen,age5));
KEY_INDIC_H('QHnut_cap_day_final',h,t1) = QHnut_cap_day_final.L(h);
KEY_INDIC_H('QHnut_cap_day_scale',h,t1) = QHnut_cap_day_scale.L(h);

KEY_INDIC_H('YH',Hagg,t1) = SUM(h$mapHagg(Hagg,h),KEY_INDIC_H('YH',h,t1));
KEY_INDIC_H('YH_R',Hagg,t1) = SUM(h$mapHagg(Hagg,h),KEY_INDIC_H('YH_R',h,t1));
KEY_INDIC_H('YFLND',Hagg,t1) = SUM(h$mapHagg(Hagg,h),KEY_INDIC_H('YFLND',h,t1));
KEY_INDIC_H('YFLAB',Hagg,t1) = SUM(h$mapHagg(Hagg,h),KEY_INDIC_H('YFLAB',h,t1));
KEY_INDIC_H('YFCAP',Hagg,t1) = SUM(h$mapHagg(Hagg,h),KEY_INDIC_H('YFCAP',h,t1));
KEY_INDIC_H('HCON',Hagg,t1) = SUM(h$mapHagg(Hagg,h),KEY_INDIC_H('HCON',h,t1));
KEY_INDIC_H('HCON_R',Hagg,t1) = SUM(h$mapHagg(Hagg,h),KEY_INDIC_H('HCON_R',h,t1));
KEY_INDIC_H('QFH',Hagg,t1) = SUM(h$mapHagg(Hagg,h),KEY_INDIC_H('QFH',h,t1));
KEY_INDIC_H('POP',Hagg,t1) = SUM(h$mapHagg(Hagg,h),KEY_INDIC_H('POP',h,t1));



KEY_INDIC_MAC('PQ',C,t1) = PQ_T0(C,t1);
KEY_INDIC_MAC('QQ',C,t1) = QQ_T0(C,t1);
KEY_INDIC_MAC('PX',C,t1) = PX_T0(C,t1);
KEY_INDIC_MAC('QX',C,t1) = QX_T0(C,t1);
KEY_INDIC_MAC('PE',C,t1) = PE_T0(C,t1);
KEY_INDIC_MAC('QE',C,t1) = QE_T0(C,t1);
KEY_INDIC_MAC('PM',C,t1) = PM_T0(C,t1);
KEY_INDIC_MAC('QM',C,t1) = QM_T0(C,t1);
KEY_INDIC_MAC('QH',C,t1) = SUM(H,QH_T0(C,H,t1));
KEY_INDIC_MAC('TQ',C,t1) = TQ_T0(C,t1);
KEY_INDIC_MAC('QH01',C,t1) = QH_T0(C,'H01',t1);
KEY_INDIC_MAC('QH02',C,t1) = QH_T0(C,'H02',t1);
KEY_INDIC_MAC('QH03',C,t1) = QH_T0(C,'H03',t1);
KEY_INDIC_MAC('QH04',C,t1) = QH_T0(C,'H04',t1);
KEY_INDIC_MAC('QH05',C,t1) = QH_T0(C,'H05',t1);

SCENshocks(H,'TREATcost_DS',t1) = (TBTREATcover('DS')*TBTREATunitcost('DS')*DSMDRshr('DS')*SUM((gen,age5),CLINOUToutput(h,'INCID',gen,age5,t1))/GADJ.L)*(POPscale/TARGETscale);
SCENshocks(H,'TREATcost_MDR',t1) = (TBTREATcover('MDR')*TBTREATunitcost('MDR')*DSMDRshr('MDR')*SUM((gen,age5),CLINOUToutput(h,'INCID',gen,age5,t1))/GADJ.L)*(POPscale/TARGETscale);
SCENshocks(H,'dLABforce_isolat_DS',t1) = TBISOLATadhere('DS')*TBISOLATperiod('DS')*DSMDRshr('DS')*SUM((gen,age5),CLINOUToutput(h,'INCID',gen,age5,t1));
SCENshocks(H,'dLABforce_isolat_MDR',t1) = TBISOLATadhere('MDR')*TBISOLATperiod('MDR')*DSMDRshr('MDR')*SUM((gen,age5),CLINOUToutput(h,'INCID',gen,age5,t1));
*SCENshocks(H,'dLABforce_hosp',t1) = (1-TOTBURDENhosp01)*TBHOSPperiod*SUM((gen,age5),CLINOUToutput(h,'INCID',gen,age5,t1));

