
$STITLE Input file: VARINIT_T.INC. Initialization of dynamic variables. Standard CGE modeling system, Version 1.01

  CPI_T.L(t1)           = CPI_T0(t1);
  IPI_T.L(t1)           = IPI_T0(t1);
  DMPS_T.L(t1)          = DMPS_T0(t1);
  DPI_T.L(t1)           = DPI_T0(t1);
  DTINS_T.L(t1)         = DTINS_T0(t1);
  EG_T.L(t1)            = EG_T0(t1);
  EH_T.L(H,t1)          = EH_T0(H,t1);
  EXR_T.L(t1)           = EXR_T0(t1);
  FSAV_T.L(t1)          = FSAV_T0(t1);
  GADJ_T.L(t1)          = GADJ_T0(t1);
  GOVSHR_T.L(t1)        = GOVSHR_T0(t1);
  GSAV_T.L(t1)          = GSAV_T0(t1);
  IADJ_T.L(t1)          = IADJ_T0(t1);
  INVSHR_T.L(t1)        = INVSHR_T0(t1);
  MPS_T.L(INSDNG,t1)    = MPS_T0(INSDNG,t1);
  MPSADJ_T.L(t1)        = MPSADJ_T0(t1);
  PA_T.L(A,t1)          = PA_T0(A,t1);
  PDD_T.L(C,t1)         = PDD_T0(C,t1);
  PDS_T.L(C,t1)         = PDS_T0(C,t1);
  PINTA_T.L(A,t1)       = PINTA_T0(A,t1) ;
  PE_T.L(C,t1)          = PE_T0(C,t1);
  PM_T.L(C,t1)          = PM_T0(C,t1);
  PQ_T.L(C,t1)          = PQ_T0(C,t1);
  PVA_T.L(A,t1)         = PVA_T0(A,t1);
  PWE_T.L(C,t1)         = PWE_T0(C,t1);
  PWM_T.L(C,t1)         = PWM_T0(C,t1);
  PX_T.L(C,t1)          = PX_T0(C,t1);
  PXAC_T.L(A,C,t1)      = PXAC_T0(A,C,t1);
  QA_T.L(A,t1)          = QA_T0(A,t1);
  QD_T.L(C,t1)          = QD_T0(C,t1);
  QE_T.L(C,t1)          = QE_T0(C,t1);
  QF_T.L(F,A,t1)        = QF_T0(F,A,t1);
  QFS_T.L(F,t1)         = QFS_T0(F,t1);
  QG_T.L(C,t1)          = QG_T0(C,t1);
  QH_T.L(C,H,t1)        = QH_T0(C,H,t1);
  QHA_T.L(A,C,H,t1)     = QHA_T0(A,C,H,t1);
  QINT_T.L(C,A,t1)      = QINT_T0(C,A,t1);
  QINTA_T.L(A,t1)       = QINTA_T0(A,t1) ;
  QINV_T.L(C,t1)        = QINV_T0(C,t1);
  QM_T.L(C,t1)          = QM_T0(C,t1);
  QQ_T.L(C,t1)          = QQ_T0(C,t1);
  QT_T.L(C,t1)          = QT_T0(C,t1);
  QVA_T.L(A,t1)         = QVA_T0(A,t1);
  QX_T.L(C,t1)          = QX_T0(C,t1);
  QXAC_T.L(A,C,t1)      = QXAC_T0(A,C,t1);
  TABS_T.L(t1)          = TABS_T0(t1);
  TRII_T.L(INSDNG,INSDNGP,t1) = TRII_T0(INSDNG,INSDNGP,t1);
  TINS_T.L(INSDNG,t1)   = TINS_T0(INSDNG,t1);
  TINSADJ_T.L(t1)       = TINSADJ_T0(t1);
  WALRAS_T.L(t1)        = WALRAS_T0(t1);
*  WALRASSQR_T.L(t1)     = 0 ;
  WF_T.L(F,t1)          = WF_T0(F,t1);
  WFDIST_T.L(F,A,t1)    = WFDIST_T0(F,A,t1);
  YF_T.L(F,t1)          = YF_T0(F,t1);
  YG_T.L(t1)            = YG_T0(t1);
  YI_T.L(INS,t1)        = YI_T0(INS,t1);
  YIF_T.L(INS,F,t1)     = YIF_T0(INS,F,t1);

  NGDP_T.L(t1)          = NGDP_T0(t1);
  NCP_T.L(t1)           = NCP_T0(t1);
  NCG_T.L(t1)           = NCG_T0(t1);
  NINV_T.L(t1)          = NINV_T0(t1);
  NDST_T.L(t1)          = NDST_T0(t1);
  NEXP_T.L(t1)          = NEXP_T0(t1);
  NIMP_T.L(t1)          = NIMP_T0(t1);
  GDPDEF_T.L(t1)        = GDPDEF_T0(t1);
  RGDP_T.L(t1)          = RGDP_T0(t1);
  GDN_T.L(t1)           = GDN_T0(t1);

  TFPadj_T.L(t1)        = TFPadj_T0(t1);

*Initalization of vars for household-specific factor ownership and factor returns
  QFH_T.L(insd,f,t1)    = QFH_T0(insd,f,t1);
  WFH_T.L(f,t1)         = WFH_T0(f,t1);
  WFHDIST_T.L(insd,f,t1) = wfhdist_T0(insd,f,t1);

*Initalization of vars for EV houshold welfare calculations
  QH_EV_T.L(C,H,t1)     = QH_EV_T0(C,H,t1);
  QHA_EV_T.L(A,C,H,t1)  = QHA_EV_T0(A,C,H,t1);
  YH_EV_T.L(H,t1)       = YH_EV_T0(H,t1);
  YH_EV_TOT_T.L(t1)     = YH_EV_TOT_T0(t1);
  U_H_T.L(H,t1)         = U_H_T0(H,t1);

*Initalization of vars for labour factor accumulation
  FLABGROWTH_T.L(flab,t1) = FLABGROWTH_T0(flab,t1);

*Initalization of vars for demographic module
  BIRTHS_T.L(t1,h,gen) = BIRTHS_T0(t1,h,gen);
  DEATHS_T.L(t1,h,gen,age5_100) = DEATHS_T0(t1,h,gen,age5_100);
  IntlMIGR_T.L(t1,h,gen,age5_100) = IntlMIGR_T0(t1,h,gen,age5_100);
  POP_T.L(t1,h,gen,age5_100) = POP_T0(t1,h,gen,age5_100);

  m_5qx_T.L(t1,h,gen,age5_100) = m_5qx_T0(t1,h,gen,age5_100);

*Initalization of vars for TB module
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


*#*#*#*#*# THE END OF VARINIT.INC #*#*#*#*
