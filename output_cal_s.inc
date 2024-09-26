
*###############################################################################
*################ VARIABLE VALUES FOR CALIBRATION OF INDEX MODEL ###############
*###############################################################################

  CPI_T0(t1)           = CPI.L;
  CPI_H_T0(H,t1)       = CPI_H.L(H);
  IPI_T0(t1)           = IPI.L;
  DMPS_T0(t1)          = DMPS.L;
  DPI_T0(t1)           = DPI.L;
  DTINS_T0(t1)         = DTINS.L;
  EG_T0(t1)            = EG.L;
  EH_T0(H,t1)         = EH.L(H);
  EXR_T0(t1)           = EXR.L;
  FSAV_T0(t1)          = FSAV.L;
  GADJ_T0(t1)          = GADJ.L;
*  GDN_T0(t1)           = GDN.L;
  GOVSHR_T0(t1)        = GOVSHR.L;
  GSAV_T0(t1)          = GSAV.L;
  IADJ_T0(t1)          = IADJ.L;
  INVSHR_T0(t1)        = INVSHR.L;
  MPS_T0(INSDNG,t1)   = MPS.L(INSDNG);
  MPSADJ_T0(t1)        = MPSADJ.L;
  PA_T0(A,t1)         = PA.L(A);
  PDD_T0(C,t1)        = PDD.L(C);
  PDS_T0(C,t1)        = PDS.L(C);
  PINTA_T0(A,t1)      = PINTA.L(A);
  PE_T0(C,t1)         = PE.L(C);
  PM_T0(C,t1)         = PM.L(C);
  PQ_T0(C,t1)         = PQ.L(C);
  PVA_T0(A,t1)        = PVA.L(A);
  PWE_T0(C,t1)        = PWE.L(C);
  PWM_T0(C,t1)        = PWM.L(C);
  PX_T0(C,t1)         = PX.L(C);
  PXAC_T0(A,C,t1)     = PXAC.L(A,C);
  QA_T0(A,t1)         = QA.L(A);
  QD_T0(C,t1)         = QD.L(C);
  QE_T0(C,t1)         = QE.L(C);
  QF_T0(F,A,t1)       = QF.L(F,A);
  QFS_T0(F,t1)        = QFS.L(F);
  QG_T0(C,t1)         = QG.L(C);
  QH_T0(C,H,t1)       = QH.L(C,H);
  QHA_T0(A,C,H,t1)    = QHA.L(A,C,H);
  QINT_T0(C,A,t1)     = QINT.L(C,A);
  QINTA_T0(A,t1)      = QINTA.L(A);
  QINV_T0(C,t1)       = QINV.L(C);
  QM_T0(C,t1)         = QM.L(C);
  QQ_T0(C,t1)         = QQ.L(C);
  QT_T0(C,t1)         = QT.L(C);
  QVA_T0(A,t1)        = QVA.L(A);
  QX_T0(C,t1)         = QX.L(C);
  QXAC_T0(A,C,t1)     = QXAC.L(A,C);
  TABS_T0(t1)          = TABS.L;
*  TAADJ_T0(A,t1)       = TAADJ.L(A);
*  TQ_T0(C,t1)          = TQ.L(C);
  TRII_T0(INSDNG,INSDNGP,t1) = TRII.L(INSDNG,INSDNGP);
  TINS_T0(INSDNG,t1)  = TINS.L(INSDNG);
  TINSADJ_T0(t1)       = TINSADJ.L;
  WALRAS_T0(t1)        = WALRAS.L;
  WALRASSQR_T0(t1)     = WALRASSQR.L ;
  WF_T0(F,t1)         = WF.L(F);
  WFA_T0(F,A,t1)      = WFA.L(F,A);
  WFDIST_T0(F,A,t1)   = WFDIST.L(F,A);
  YF_T0(f,t1)         = YF.L(f);
  YG_T0(t1)            = YG.L;
  YI_T0(INS,t1)       = YI.L(INS);
  YIF_T0(INS,F,t1)    = YIF.L(INS,F);

*  PAAC_T0(A,C,t1)     = PAAC.L(A,C);
*  QAAC_T0(A,C,t1)     = QAAC.L(A,C);

  NGDP_T0(t1)          = NGDP.L;
  NCP_T0(t1)           = NCP.L;
  NCG_T0(t1)           = NCG.L;
  NINV_T0(t1)          = NINV.L;
  NDST_T0(t1)          = NDST.L;
  NEXP_T0(t1)          = NEXP.L;
  NIMP_T0(t1)          = NIMP.L;
  GDPDEF_T0(t1)        = GDPDEF.L;
  RGDP_T0(t1)          = RGDP.L;
  GDN_T0(t1)           = GDN.L;

  TFPadj_T0(t1)        = TFPadj.L;
  QDSTadj_T0(t1)       = QDSTadj.L;
  DELTATadj_T0(t1)     = DELTATadj.L;
  DELTAQadj_T0(t1)     = DELTAQadj.L;

  PWElev_T0(t1)        = PWElev.L;
  PWMlev_T0(t1)        = PWMlev.L;

  TA_T0(A,t1)          = TA.L(A);
  TM_T0(C,t1)          = TM.L(C);
  TQ_T0(C,t1)          = TQ.L(C);
  TF_T0(F,t1)          = TF.L(F);

  TQscale_T0(t1)       = TQscale.L;
  TQadd_T0(t1)         = TQadd.L;
  TMscale_T0(t1)       = TMscale.L;
  TMadd_T0(t1)         = TMadd.L;
  TWFAscale_T0(t1)     = TWFA_scale.L;
  TWFAadd_T0(t1)       = TWFA_add.L;

  QFH_T0(insd,f,t1)    = QFH.L(insd,f);
  WFH_T0(f,t1)         = WFH.L(f);
  WFHDIST_T0(insd,f,t1) = wfhdist.L(insd,f);

  QH_EV_T0(C,H,t1)     = QH_EV.L(C,H);
  QHA_EV_T0(A,C,H,t1)  = QHA_EV.L(A,C,H);
  YH_EV_T0(H,t1)       = YH_EV.L(H);
  YH_EV_TOT_T0(t1)     = YH_EV_TOT.L;
  U_H_T0(h,t1)         = U_H.L(h);

  FLABGROWTH_T0(h,flab,t1p) = FLABGROWTH(h,flab,t1p);

  POP_T0(t1,h,gen,age5) = POP(h,gen,age5,t1);

 S_TB_T0(t1,h,t1_tb)    = S_TB.L(h,t1_tb);
 L_TB_T0(t1,h,t1_tb)    = L_TB.L(h,t1_tb);
 I_TB_T0(t1,h,t1_tb)    = I_TB.L(h,t1_tb);
 Ir_TB_T0(t1,h,t1_tb)   = Ir_TB.L(h,t1_tb);
 T_TB_T0(t1,h,t1_tb)    = T_TB.L(h,t1_tb);
 Tr_TB_T0(t1,h,t1_tb)   = Tr_TB.L(h,t1_tb);
 POP_TB_T0(t1,h,t1_tb)  = POP_TB.L(h,t1_tb);
 Lambda_TB_T0(t1,h,t1_tb) = Lambda_TB.L(h,t1_tb);
 Incid_TB_T0(t1,h,t1_tb) = Incid_TB.L(h,t1_tb);
 Prev_TB_T0(t1,h,t1_tb) = Prev_TB.L(h,t1_tb);
 Notif_TB_T0(t1,h,t1_tb) = Notif_TB.L(h,t1_tb);
 Mort_TB_T0(t1,h,t1_tb) = Mort_TB.L(h,t1_tb);

 Riskfact_prev_T0(t1,RISKfact_set,h) = RISKfact_prev.L(RISKfact_set,h);
 RR_TB_T0(t1,h)   = RR_TB.L(h);

 QHfood_metric_T0(c,h,t1) = QHfood_metric.L(c,h);
 QHnut_cap_day_T0(h,t1)   = QHnut_cap_day.L(h);
 QHnut_cap_day_final_T0(h,t1) = QHnut_cap_day_final.L(h);

 a_TB_T0(t1,h)    = a_TB.L(h);
 q_TB_T0(t1,h)    = q_TB;
 tau_TB_T0(t1,h)  = tau_TB(h);
 betaREL_TB_T0(t1,h) = betaREL_TB(h);
 betaIN_TB_T0(t1,h) = betaIN_TB(h);
 u_TB_T0(t1,h)    = u_TB(h);
 m_TB_T0(t1,h)    = m_TB(h);
 eps_TB_T0(t1,h)  = eps_TB;
 c_TB_T0(t1,h)    = c_TB.L(h);
 d_TB_T0(t1,h)    = d_TB(h);
 nu_TB_T0(t1,h)   = nu_TB;
