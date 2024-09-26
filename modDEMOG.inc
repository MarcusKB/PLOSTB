
$ontext
BIRTHS(h,gen,t1+1)          = sr(gen,t1+1)*SUM(age5_fert,asfr(age5_fert,t1+1)*POP(h,'f',age5_fert,t1));

DEATHS(h,gen,age5,t1+1) = m_5qx(gen,age5,t1+1)*POP(h,gen,age5,t1);

IntlMIGR(h,gen,age5,t1+1) = imr_s0(h,gen,age5,t1+1)*(1-m_5qx(gen,age5,t1+1))*POP(h,gen,age5,t1);

POP(h,gen,'00_04',t1+1)     = BIRTHS(h,gen,t1+1) + (1-PROBtrans00(h,gen,'00_04',t1+1))*(1-m_5qx(gen,'00_04',t1+1))*(1-imr_s0(h,gen,'00_04',t1+1))*POP(h,gen,'00_04',t1);

POP(h,gen,age5+1,t1+1)$(ord(age5)+1 < card(age5p))  = PROBtrans00(h,gen,age5,t1+1)*(1-m_5qx(gen,age5,t1+1))*(1-imr_s0(h,gen,age5,t1+1))*POP(h,gen,age5,t1)
                                                 + (1-PROBtrans00(h,gen,age5+1,t1+1))*(1-m_5qx(gen,age5+1,t1+1))*(1-imr_s0(h,gen,age5+1,t1+1))*POP(h,gen,age5+1,t1);

POP(h,gen,age5+1,t1+1)$(ord(age5)+1 = card(age5p))  = PROBtrans00(h,gen,age5,t1+1)*(1-m_5qx(gen,age5,t1+1))*(1-imr_s0(h,gen,age5,t1+1))*POP(h,gen,age5,t1)
                                                 + (1-m_5qx(gen,age5+1,t1+1))*(1-imr_s0(h,gen,age5+1,t1+1))*POP(h,gen,age5+1,t1);
$offtext

*$ontext
BIRTHS(h,gen,t1+1)          = sr(gen,t1+1)*SUM(age5_fert,asfr(age5_fert,t1+1)*POP(h,'f',age5_fert,t1));

DEATHS(h,gen,age5,t1+1) = m_5qx(gen,age5,t1+1)*POP(h,gen,age5,t1);

IntlMIGR(h,gen,age5,t1+1) = imr_s0(h,gen,age5,t1+1)*(1-m_5qx(gen,age5,t1+1))*POP(h,gen,age5,t1);

POP(h,gen,'00_04',t1+1)     = BIRTHS(h,gen,t1+1) + (1-PROBtrans00(h,gen,'00_04',t1+1))*(1-m_5qx(gen,'00_04',t1+1))*(1-imr_s0(h,gen,'00_04',t1+1))*POP(h,gen,'00_04',t1);

POP(h,gen,age5+1,t1+1)$(ord(age5)+1 < card(age5p))  = PROBtrans00(h,gen,age5,t1+1)*(1-m_5qx(gen,age5,t1+1))*(1-imr_s0(h,gen,age5,t1+1))*POP(h,gen,age5,t1)
                                                 + (1-PROBtrans00(h,gen,age5+1,t1+1))*(1-m_5qx(gen,age5+1,t1+1))*(1-imr_s0(h,gen,age5+1,t1+1))*POP(h,gen,age5+1,t1);

POP(h,gen,age5+1,t1+1)$(ord(age5)+1 = card(age5p))  = PROBtrans00(h,gen,age5,t1+1)*(1-m_5qx(gen,age5,t1+1))*(1-imr_s0(h,gen,age5,t1+1))*POP(h,gen,age5,t1)
                                                 + (1-m_5qx(gen,age5+1,t1+1))*(1-imr_s0(h,gen,age5+1,t1+1))*POP(h,gen,age5+1,t1);
*$offtext
