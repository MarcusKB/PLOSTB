$STITLE Input file: VARINIT.INC. Initialization of variables. Standard CGE modeling system, Version 1.01

  CPI.L           = CPI0;
  CPI_H.L(H)      = CPI_H0(H);
  DMPS.L          = DMPS0;
  DPI.L           = DPI0;
  DTINS.L         = DTINS0;
  EG.L            = EG0;
  EH.L(H)         = EH0(H);
  EXR.L           = EXR0;
  FSAV.L          = FSAV0;
  GADJ.L          = GADJ0;
  GOVSHR.L        = GOVSHR0;
  GSAV.L          = GSAV0;
  IADJ.L          = IADJ0;
  INVSHR.L        = INVSHR0;
  MPS.L(INSDNG)   = MPS0(INSDNG);
  MPSADJ.L        = MPSADJ0;
  PA.L(A)         = PA0(A);
  PDD.L(C)        = PDD0(C);
  PDS.L(C)        = PDS0(C);
  PINTA.L(A)      = PINTA0(A) ;
  PE.L(C)         = PE0(C);
  PM.L(C)         = PM0(C);
  PQ.L(C)         = PQ0(C);
  PVA.L(A)        = PVA0(A);
  PWE.L(C)        = PWE0(C);
  PWM.L(C)        = PWM0(C);
  PX.L(C)         = PX0(C);
  PXAC.L(A,C)     = PXAC0(A,C);
  QA.L(A)         = QA0(A);
  QD.L(C)         = QD0(C);
  QE.L(C)         = QE0(C);
  QF.L(F,A)       = QF0(F,A);
  QFS.L(F)        = QFS0(F);
  QG.L(C)         = QG0(C);
  QH.L(C,H)       = QH0(C,H);
  QHA.L(A,C,H)    = QHA0(A,C,H);
  QINT.L(C,A)     = QINT0(C,A);
  QINTA.L(A)      = QINTA0(A) ;
  QINV.L(C)       = QINV0(C);
  QM.L(C)         = QM0(C);
  QQ.L(C)         = QQ0(C);
  QT.L(C)         = QT0(C);
  QVA.L(A)        = QVA0(A);
  QX.L(C)         = QX0(C);
  QXAC.L(A,C)     = QXAC0(A,C);
  TABS.L          = TABS0;
  TRII.L(INSDNG,INSDNGP) = TRII0(INSDNG,INSDNGP);
  TINS.L(INSDNG)  = TINS0(INSDNG);
  TINSADJ.L       = TINSADJ0;
  WALRAS.L        = WALRAS0;
  WALRASSQR.L     = 0 ;
  WF.L(F)         = WF0(F);
  WFA.L(F,A)      = WFA0(F,A);
  WFDIST.L(F,A)   = WFDIST0(F,A);
  YF.L(f)         = YF0(f);
  YG.L            = YG0;
  YI.L(INS)       = YI0(INS);
  YIF.L(INS,F)    = YIF0(INS,F);

  NGDP.L          = NGDP0;
  NCP.L           = NCP0;
  NCG.L           = NCG0;
  NINV.L          = NINV0;
  NDST.L          = NDST0;
  NEXP.L          = NEXP0;
  NIMP.L          = NIMP0;
  GDPDEF.L        = GDPDEF0;
  RGDP.L          = RGDP0;
  GDN.L           = GDN0;

  TFPadj.L        = TFPadj0;
  QDSTadj.L       = QDSTadj0;
  DELTATadj.L     = DELTATadj0;
  DELTAQadj.L     = DELTAQadj0;

  PWElev.L        = PWElev0;
  PWMlev.L        = PWMlev0;

  IPI.L           = IPI0;

  TFPadj.L        = TFPadj0;

  TA.L(A)         = ta0(A);
  TM.L(C)         = tm0(C);
  TQ.L(C)         = tq0(C);
  TF.L(F)         = tf0(F);

  TMscale.L       = TMscale0;
  TQscale.L       = TQscale0;
  TMadd.L         = TMadd0;
  TQadd.L         = TQadd0;

  TWFA_add.L      = TWFA_add0;
  TWFA_scale.L    = TWFA_scale0;

  QFH.L(insd,f)   = QFH0(insd,f);
  WFH.L(f)        = WFH0(f);
  WFHDIST.L(insd,f) = wfhdist0(insd,f);

*EV3. Initalization of vars for EV houshold welfare calculations
  QH_EV.L(C,H)    = QH_EV0(C,H);
  QHA_EV.L(A,C,H) = QHA_EV0(A,C,H);
  YH_EV.L(h)      = YH_EV0(h);
  YH_EV_TOT.L     = YH_EV_TOT0;
  U_H.L(h)        = U_H0(h);

*#*#*#*#*# THE END OF VARINIT.INC #*#*#*#*
