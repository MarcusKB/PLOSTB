
SSCENshocks(H,SCENshock_set,t1) = SCENshocks(H,SCENshock_set,t1);

SKEY_INDIC(KeyIndicSet,t1) = KEY_INDIC(KeyIndicSet,t1);
SKEY_INDIC_H(KeyIndicSet_H,h,t1) = KEY_INDIC_H(KeyIndicSet_H,h,t1);
SKEY_INDIC_H(KeyIndicSet_H,Hagg,t1) = KEY_INDIC_H(KeyIndicSet_H,Hagg,t1);
SKEY_INDIC_MAC(KeyIndicMacSet,C,t1) = KEY_INDIC_MAC(KeyIndicMacSet,C,t1);
SQFS(f,t1) = QFS_T0(f,t1);
SWF(f,t1) = WF_T0(f,t1);
SWFA(f,a,t1) = WFA_T0(f,a,t1);
SQFA(f,a,t1) = QF_T0(f,a,t1);
SQFH(insd,f,t1) = QFH_T0(insd,f,t1);

*###############################################################################
*######### SECTION 1.1: Basic Characteristics of Economy (Macro Level) #########
*###############################################################################

 STARGETS(TARGETSET,t1) = TARGETS(TARGETSET,t1);
 SMACRO(MACSET,t1) = MACRO(MACSET,t1);

 SMACROpercap(MACSET,t1) = MACROpercap(MACSET,t1);

*###############################################################################
*########## SECTION 1.2: Basic Characteristics of Economy (Macro SAMs) #########
*###############################################################################

 SMACSAM(t1,MAC,MACP) = MACSAM(t1,MAC,MACP);

*###############################################################################
*######### SECTION 1.3: Basic Characteristics of Economy (Sector Level) ########
*###############################################################################

 SSTRUCHAR(t1,AC,STRUCHARSET) = STRUCHAR(t1,AC,STRUCHARSET);

*###############################################################################
*################### SECTION 2: Real multi-sector quantities ###################
*###############################################################################

 SQUANT_C(QUANTSET_C,C,t1) = QUANT_C(QUANTSET_C,C,t1);
 SPRICE_C(PRICESET_C,C,t1) = PRICE_C(PRICESET_C,C,t1);

 SQUANT_A(QUANTSET_A,A,t1) = QUANT_A(QUANTSET_A,A,t1);
 SPRICE_A(PRICESET_A,A,t1) = PRICE_A(PRICESET_A,A,t1);

 SQUANT_F(QUANTSET_F,F,t1) = QUANT_F(QUANTSET_F,F,t1);
 SPRICE_F(PRICESET_F,F,t1) = PRICE_F(PRICESET_F,F,t1);

*###############################################################################
*######################### SECTION 3: Government budget ########################
*###############################################################################

 SGOV(GSET,t1) = GOV(GSET,t1);
 STAXRATE(TAXRATESET,AC,t1) = TAXRATE(TAXRATESET,AC,t1);

*###############################################################################
*############################# SECTION 4: Household ############################
*###############################################################################
$ontext
 SHCON(C,H,ts) = HCON(C,H,ts);
* SHWELF(H,ts)  = HWELF(H,ts);
$offtext
*###############################################################################
*############################### SECTION 5: Other ##############################
*###############################################################################

*###############################################################################
*############################## SECTION 6: Share ##############################
*###############################################################################

 S_AGSHARE(t1,AGSHARESET,'TOTAL') = AGSHARE(AGSHARESET,t1);

*###############################################################################
*########################### SECTION 7: Price Indices ##########################
*###############################################################################

 SPINDICES(PRICEINDEXSET,t1)     = PINDICES(PRICEINDEXSET,t1);
 SAGPINDICES(AGPRICEINDEXSET,t1) = AGPINDICES(AGPRICEINDEXSET,t1);

*###############################################################################
*################# SECTION 8: Health & Epidemiological Effects #################
*###############################################################################

 SEPIagg(h,EPIset,t1) = EPIagg(h,EPIset,t1);
 SEPIdisagg(h,EPIset,t1_tb,t1) = EPIdisagg(h,EPIset,t1_tb,t1);

*###############################################################################
*######################## SECTION 9: Simulation Targets ########################
*###############################################################################

* See under Macro Indicators (Section 1)

*###############################################################################
*############################ SECTION 10: Demography ###########################
*###############################################################################

SDEMOG(H,DEMOGset,age5tot,t1) = DEMOG(H,DEMOGset,age5tot,t1);
SCLINOUToutput(h,CLINOUToutput_set,gentot,age5tot,t1) = CLINOUToutput(h,CLINOUToutput_set,gentot,age5tot,t1);

*###############################################################################
*################## SECTION 11: Deflation and NPV Calculations #################
*###############################################################################

 SNPVMAC(MACSET) = NPVMAC(MACSET);
 SDEFMAC(MACSET) = DEFMAC(MACSET);

*###############################################################################
*######################### SECTION 12: Macro Indicators ########################
*###############################################################################

SINDIC_SC(IndicSCset,t1) = INDIC_SC(IndicSCset,t1);
SINDIC_A(IndicAset,A,t1) = INDIC_A(IndicAset,A,t1);
SINDIC_C(IndicCset,C,t1) = INDIC_C(IndicCset,C,t1);
SINDIC_F(IndicFset,F,t1) = INDIC_F(IndicFset,F,t1);
SINDIC_INS(IndicINSset,INS,t1) = INDIC_INS(IndicINSset,INS,t1);
SINDIC_FA(IndicFset,F,A,t1) = INDIC_FA(IndicFset,F,A,t1);
SINDIC_QH(H,C,t1) = INDIC_QH(H,C,t1);

SHHAGG(HHAGGset,H) = HHAGG(HHAGGset,H);

*###############################################################################
*######################### SECTION 13: Results Tables ##########################
*###############################################################################

*see top of this file
