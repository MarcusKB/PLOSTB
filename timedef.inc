
SET
t1          time /t014*t040 /
t1_pop(t1)  UNFPA population projection time period (2 rural & urban household population groups) / t014*t040 /
tp(t1)      Pre-simulation time periods 2014-2021 / t014*t021 /
ts(t1)      Simulation (total) time periods 2015-2040 / t021*t040 /
t1_base(t1) Simulation (base) time period 2014 (2014 base for NPV calculations) / t014 /
*ts_base(ts) Simulation (base) time period 2014 (2014 base for NPV calculations) / t021 /
;

ALIAS(t1,t1p,t1pp), (t1_pop,t1_popp), (tp,tpp,tppp), (ts,tsp,tspp)
;

SET
map_t1_pop(t1,t1_pop)
/
t014.t014
t015.t015
t016.t016
t017.t017
t018.t018
t019.t019
t020.t020
t021.t021
t022.t022
t023.t023
t024.t024
t025.t025
t026.t026
t027.t027
t028.t028
t029.t029
t030.t030
t031.t031
t032.t032
t033.t033
t034.t034
t035.t035
t036.t036
t037.t037
t038.t038
t039.t039
t040.t040
/
;

