
CSCENshocks(H,SCENshock_set,t1) = SCENshocks(H,SCENshock_set,t1);

CKEY_INDIC(KeyIndicSet,t1) = KEY_INDIC(KeyIndicSet,t1);
CKEY_INDIC_H(KeyIndicSet_H,h,t1) = KEY_INDIC_H(KeyIndicSet_H,h,t1);
CKEY_INDIC_H(KeyIndicSet_H,Hagg,t1) = KEY_INDIC_H(KeyIndicSet_H,Hagg,t1);
CKEY_INDIC_MAC(KeyIndicMacSet,C,t1) = KEY_INDIC_MAC(KeyIndicMacSet,C,t1);
CQFS(f,t1) = QFS_T0(f,t1);
CWF(f,t1) = WF_T0(f,t1);
CWFA(f,a,t1) = WFA_T0(f,a,t1);
CQFA(f,a,t1) = QF_T0(f,a,t1);
CQFH(insd,f,t1) = QFH_T0(insd,f,t1);

*###############################################################################
*######### SECTION 1.1: Basic Characteristics of Economy (Macro Level) #########
*###############################################################################

 CTARGETS(TARGETSET,t1) = TARGETS(TARGETSET,t1);
 CQHnut_scale(H,t1) = QHnut_scale(H,t1);
 CMACRO(MACSET,t1) = MACRO(MACSET,t1);

 CMACROpercap(MACSET,t1) = MACROpercap(MACSET,t1);

*###############################################################################
*########## SECTION 1.2: Basic Characteristics of Economy (Macro SAMs) #########
*###############################################################################

 CMACSAM(t1,MAC,MACP) = MACSAM(t1,MAC,MACP);

*###############################################################################
*######### SECTION 1.3: Basic Characteristics of Economy (Sector Level) ########
*###############################################################################

 CSTRUCHAR(t1,AC,STRUCHARSET) = STRUCHAR(t1,AC,STRUCHARSET);

*###############################################################################
*################### SECTION 2: Real multi-sector quantities ###################
*###############################################################################

 CQUANT_C(QUANTSET_C,C,t1) = QUANT_C(QUANTSET_C,C,t1);
 CPRICE_C(PRICESET_C,C,t1) = PRICE_C(PRICESET_C,C,t1);

 CQUANT_A(QUANTSET_A,A,t1) = QUANT_A(QUANTSET_A,A,t1);
 CPRICE_A(PRICESET_A,A,t1) = PRICE_A(PRICESET_A,A,t1);

 CQUANT_F(QUANTSET_F,F,t1) = QUANT_F(QUANTSET_F,F,t1);
 CPRICE_F(PRICESET_F,F,t1) = PRICE_F(PRICESET_F,F,t1);

*###############################################################################
*######################### SECTION 3: Government budget ########################
*###############################################################################

 CGOV(GSET,t1) = GOV(GSET,t1);
 CTAXRATE(TAXRATESET,AC,t1) = TAXRATE(TAXRATESET,AC,t1);

*###############################################################################
*############################# SECTION 4: Household ############################
*###############################################################################
$ontext
 CHCON(C,H,t1) = HCON(C,H,t1);
* CHWELF(H,t1)  = HWELF(H,t1);
$offtext
*###############################################################################
*############################### SECTION 5: Other ##############################
*###############################################################################

*###############################################################################
*############################## SECTION 6: Share ##############################
*###############################################################################

 C_AGSHARE(t1,AGSHARESET,'TOTAL') = AGSHARE(AGSHARESET,t1);

*###############################################################################
*########################### SECTION 7: Price Indices ##########################
*###############################################################################

 CPINDICES(PRICEINDEXSET,t1)     = PINDICES(PRICEINDEXSET,t1);
 CAGPINDICES(AGPRICEINDEXSET,t1) = AGPINDICES(AGPRICEINDEXSET,t1);

*###############################################################################
*################# SECTION 8: Health & Epidemiological Effects #################
*###############################################################################

 CEPIagg(h,EPIset,t1) = EPIagg(h,EPIset,t1);
 CEPIdisagg(h,EPIset,t1_tb,t1) = EPIdisagg(h,EPIset,t1_tb,t1);

*###############################################################################
*######################## SECTION 9: Simulation Targets ########################
*###############################################################################

* See under Macro Indicators (Section 1)

*###############################################################################
*############################ SECTION 10: Demography ###########################
*###############################################################################

CDEMOG(H,DEMOGset,age5tot,t1) = DEMOG(H,DEMOGset,age5tot,t1);
CCLINOUToutput(h,CLINOUToutput_set,gentot,age5tot,t1) = CLINOUToutput(h,CLINOUToutput_set,gentot,age5tot,t1);

*###############################################################################
*################## SECTION 11: Deflation and NPV Calculations #################
*###############################################################################

 CNPVMAC(MACSET) = NPVMAC(MACSET);
 CDEFMAC(MACSET) = DEFMAC(MACSET);

*###############################################################################
*######################### SECTION 12: Macro Indicators ########################
*###############################################################################

CINDIC_SC(IndicSCset,t1) = INDIC_SC(IndicSCset,t1);
CINDIC_A(IndicAset,A,t1) = INDIC_A(IndicAset,A,t1);
CINDIC_C(IndicCset,C,t1) = INDIC_C(IndicCset,C,t1);
CINDIC_F(IndicFset,F,t1) = INDIC_F(IndicFset,F,t1);
CINDIC_INS(IndicINSset,INS,t1) = INDIC_INS(IndicINSset,INS,t1);
CINDIC_FA(IndicFset,F,A,t1) = INDIC_FA(IndicFset,F,A,t1);
CINDIC_QH(H,C,t1) = INDIC_QH(H,C,t1);

CHHAGG(HHAGGset,H) = HHAGG(HHAGGset,H);

*###############################################################################
*######################### SECTION 13: Results Tables ##########################
*###############################################################################

*see top of this file
