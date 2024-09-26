$TITLE Input file: SAMAGG.GMS. SAM aggregation program. Standard CGE Modeling System, ver. 1.01.
$OFFSYMLIST OFFSYMXREF OFFUPPER

$ontext

This file provides programming code for aggregating and/or renaming
selected accounts in a Social Accounting Matrix (SAM) using GAMS.

Source of the SAM (used for illustration purposes only):
 Thomas, Marcelle, and Romeo M. Bautista (January 1999). "A 1991 Social
      Accounting Matrix (SAM) for Zimbabwe" Trade and Macroeconomics
      Division, Discussion Paper No. 36, Washington, D.C.: International
      Food Policy Research Institute (http://www.ifpri.cgiar.org).

SAM features, include:
 1. Home consumption
 2. Trade and transport marketing margins
 3. Multiple activity producing a single commodity (large scale and
    (small holder production yield a single commodity)


Notes:

When working with SAMs (or input-output tables), one often wishes to
aggregate one or more SAM accounts with another account or into a new
account. Given the consistent structure of a SAM as a square matrix with
equal row and column sums, a seemingly simple task can turn into a
tedious and time consuming one.

The following code provides a facility to overcome this issue in a fast
and consistent way. To use it, the user needs to include the information
related to the problem (the SAM and its accounts) and determine a
desired level of aggregation. The code is written to be consistent with
the "Standard model" notation.

$offtext
*##################### 1. SET DECLARATION ###########################
$ontext

Instructions:

!!-1. In this section, the user should DEFINE all sets (by entering
the names of set elements).

Note: If the SAM includes a government, the rest of the world, savings-
investment and/or stock changes, the account names GOV, ROW, S-I, DSTK,
resp. should be used in order for the SAM to work with the standard
model.

$offtext

SET

*!!-start entering information here
*Note: global set with all elements that appear in the initial-
*disaggregated and the final-aggregated SAM.
*The order of first appearances of an element determines its position
*relative to other elements in GAMS displays.

AC  all accounts (initial-disaggregated and final-aggregated SAM)
/
*Activities in initial SAM
      AMZLC             Maize large scale
      AMZSH             Maize small holder
      AWT               Wheat
      AOGRNLC           Other grain large scale
      AOGRNSH           Other grain small holder
      AHORTLC           Horticulture large scale
      AHORTSH           Horticulture small holder
      ACOF              Coffee
      ATEA              Tea
      AGRNTLC           Groundnuts large scale
      AGRNTSH           Groundnuts small holder
      ACOTLC            Cotton large scale
      ACOTSH            Cotton small holder
      ASUG              Sugar
      ATOB              Tobacco
      AOCRPLC           Other crops large scale
      AOCRPSH           Other crops small holder
      ACATLC            Cattle large scale
      ACATSH            Cattle small holder
      AOLVKLC           Other livestock large scale
      AOLVKSH           Other livestock small holder
      AFISH             Fishery
      AFORLC            Forestry large scale
      AFORSH            Forestry small holder
      AMIN              Mining
      AGRMIL            Grain milling
      AOFDP             Other food processing
      ATEXT             Textiles
      AOLGT             Other light manufacturing
      AFERT             Fertilizer & agr. chemicals
      AOMAN             Other manufacturing
      AELWA             Electricity and water
      ACONS             Construction
      ATDTP             Trade & transport
      APUB              Public services
      APRIV             Private services
*Activities in final SAM
      A-AGR-LS          Large scale agriculture
      A-AGR-SH          Small holder agriculture
      A-IND             Industry
      A-TRAN            Transport services
      A-SERV            Other services
*Commodities in initial SAM
      CMZ               Maize
      CWT               Wheat
      COGRN             Other grain
      CHORT             Horticulture
      CCOF              Coffee
      CTEA              Tea
      CGRNT             Groundnuts
      CCOT              Cotton
      CSUG              Sugar
      CTOB              Tobacco
      COCRP             Other crops
      CCAT              Cattle
      COLVK             Other livestock
      CFISH             Fishery
      CFOR              Forestry
      CMIN              Mining
      CGRMIL            Grain milling
      COFDP             Other food processing
      CTEXT             Textiles
      COLGT             Other light manufacturing
      CFERT             Fertilizer & agr. chemicals
      COMAN             Other manufacturing
      CELWA             Electricity and water
      CCONS             Construction
      CTDTP             Trade & transport
      CPUB              Public services
      CPRIV             Private services
*Commodities in final SAM
      C-AGR             Agriculture
      C-IND             Industry
      C-TRAN            Transport services
      C-SERV            Other services
*Transactions cost accounts in initial SAM
      CTDTP-E           Export trade & transport marketing margin
      CTDTP-M           Import trade & transport marketing margin
      CTDTP-D           Domestic trade & transport marketing margin
*Transactions cost accounts in final SAM
      MM-D              Export trade & transport marketing margin
      MM-M              Import trade & transport marketing margin
      MM-E              Domestic trade & transport marketing margin
*Factors in initial SAM
      LABUSKLS          LSC-unskilled workers
      LABUSKF           Unskilled labor - formal
      LABUSKIF          Unskilled labor-SH
      LABSK             Skilled labor
      LANDLS            Land - large scale
      LANDSH            Land - Small holder
      CAPLSC            Capital - large scale
      CAPSH             Capital - Small holder
      CAPOT             Capital - Other
*Factors in final SAM
      LABOR             Labor
      CAPITAL           Capital
      LAND              Land
*Households in initial SAM
      HLSUPP            large scale owner-manager hh
      HLSLOW            large scale farm worker hh
      HSHHLD            Small holder hh
      HURBUPP           URBAN-high income hh
      HURBLOW           URBAN-low income  hh
*Households in final SAM
      RUR-HH            Rural households
      URB-HH            Urban households
*Other institutions and tax accounts (same in both SAMs)
      ENT               Enterprise
      GOV               Government
      DTAX              Direct taxes
      ITAX              Indirect taxes
      IMPTAR            Import taxes
      ROW               Rest of the world
      S-I               Saving-Investment
      DSTK              Changes in inventories
*Totals
      TOT               total (name of total account in initial SAM)
      TOTAL             total (name of total account in final SAM)
/

ACNT(AC) all accounts except totals
;
ACNT(AC) = YES;  ACNT('TOT') = NO;  ACNT('TOTAL') = NO;

ALIAS
 (AC,ACP,ACPP)
 (ACNT,ACNTP,ACNTPP)
 ;

*#################### 2. Include SAM data file   ########################

* Common methods to include your data:
*  1. In an include file. the following GAMS command should be used:
*       "$INCLUDE <<Name>>.DAT"
*  2. Directly as part of the contents of this file.
*  3. Import from a spreadsheet-requires additional software (Xllink)
*     written by Tom Rutherford. Downloadable from the following webpage:
*         http://www.gams.com/contrib/sslink/ssdoc.htm

*!!- Zimbabwe SAM included following method 2 above

TABLE ZIMSAM(AC,ACP)        microsam (possibly adjusted)
                   AMZLC      AMZSH        AWT    AOGRNLC    AOGRNSH
AMZLC
AMZSH
AWT
AOGRNLC
AOGRNSH
AHORTLC
AHORTSH
ACOF
ATEA
AGRNTLC
AGRNTSH
ACOTLC
ACOTSH
ASUG
ATOB
AOCRPLC
AOCRPSH
ACATLC
ACATSH
AOLVKLC
AOLVKSH
AFISH
AFORLC
AFORSH
AMIN
AGRMIL
AOFDP
ATEXT
AOLGT
AFERT
AOMAN
AELWA
ACONS
ATDTP
APUB
APRIV
CMZ
CWT
COGRN
CHORT
CCOF
CTEA
CGRNT
CCOT
CSUG
CTOB
COCRP
CCAT
COLVK
CFISH
CFOR
CMIN
CGRMIL
COFDP             3.629      4.364      4.134      0.532      1.837
CTEXT
COLGT             4.632     25.902      5.362      0.693     13.408
CFERT            45.018     49.769     30.655      2.967      0.428
COMAN             0.542                 0.461      0.054
CELWA             2.936                 3.343      0.449
CCONS
CTDTP             2.029      4.571      1.681      0.212      1.957
CTDTP-E
CTDTP-M
CTDTP-D
CPUB                         1.011
CPRIV            13.821      1.874     14.620      1.733      0.189
LABUSKLS          5.806                 4.857      0.551
LABUSKF
LABUSKIF                   156.666                           33.415
LABSK            19.809                16.452      1.789
LANDLS           28.150                43.362      2.577
LANDSH                      47.910                            9.108
CAPLSC           83.663                49.660      7.651
CAPSH                       62.263                           11.938
CAPOT
HLSUPP
HLSLOW
HSHHLD
HURBUPP
HURBLOW
ENT
GOV
DTAX
ITAX            -12.229    -18.273    -50.053      1.594      4.886
IMPTAR
S-I
DSTK
ROW
TOT             197.806    336.057    124.534     20.802     77.166


+                AHORTLC    AHORTSH       ACOF       ATEA    AGRNTLC
AMZLC
AMZSH
AWT
AOGRNLC
AOGRNSH
AHORTLC
AHORTSH
ACOF
ATEA
AGRNTLC
AGRNTSH
ACOTLC
ACOTSH
ASUG
ATOB
AOCRPLC
AOCRPSH
ACATLC
ACATSH
AOLVKLC
AOLVKSH
AFISH
AFORLC
AFORSH
AMIN
AGRMIL
AOFDP
ATEXT
AOLGT
AFERT
AOMAN
AELWA
ACONS
ATDTP
APUB
APRIV
CMZ
CWT
COGRN
CHORT
CCOF
CTEA
CGRNT
CCOT
CSUG
CTOB
COCRP
CCAT
COLVK
CFISH
CFOR                                    1.571      1.400
CMIN
CGRMIL
COFDP             2.728      5.587      3.885      3.036      0.622
CTEXT
COLGT             5.738                 0.277      0.210      0.045
CFERT            40.004      5.035     10.912      8.249      1.738
COMAN             0.476                 0.309      0.235      0.049
CELWA             2.223                 3.663      2.902      0.522
CCONS
CTDTP             1.240      4.901      1.823      1.384      0.278
CTDTP-E
CTDTP-M
CTDTP-D
CPUB
CPRIV             9.795      0.303     13.162      9.863      2.184
LABUSKLS          4.594                 3.107      2.344      0.509
LABUSKF
LABUSKIF                    37.074
LABSK            15.443                15.331     10.957      1.689
LANDLS           21.520                11.483      8.725      2.080
LANDSH                      11.192
CAPLSC           65.519                42.331     32.167      7.368
CAPSH                       12.341
CAPOT
HLSUPP
HLSLOW
HSHHLD
HURBUPP
HURBLOW
ENT
GOV
DTAX
ITAX             43.531      7.368      6.699      5.086      1.789
IMPTAR
S-I
DSTK
ROW
TOT             212.811     83.801    114.553     86.558     18.873


+                AGRNTSH     ACOTLC     ACOTSH       ASUG       ATOB
AMZLC
AMZSH
AWT
AOGRNLC
AOGRNSH
AHORTLC
AHORTSH
ACOF
ATEA
AGRNTLC
AGRNTSH
ACOTLC
ACOTSH
ASUG
ATOB
AOCRPLC
AOCRPSH
ACATLC
ACATSH
AOLVKLC
AOLVKSH
AFISH
AFORLC
AFORSH
AMIN
AGRMIL
AOFDP
ATEXT
AOLGT
AFERT
AOMAN
AELWA
ACONS
ATDTP
APUB
APRIV
CMZ
CWT
COGRN
CHORT
CCOF
CTEA
CGRNT
CCOT
CSUG
CTOB
COCRP
CCAT
COLVK
CFISH
CFOR                         1.396                 1.936
CMIN
CGRMIL
COFDP             9.968      4.441      1.095      9.301     39.936
CTEXT
COLGT                       11.572      0.731      0.636      8.220
CFERT             0.585     24.181     35.231     25.225    345.106
COMAN                        0.487                 0.723      6.912
CELWA                        4.130                 8.425     17.963
CCONS
CTDTP             6.577      1.893      1.646      4.224     18.929
CTDTP-E
CTDTP-M
CTDTP-D
CPUB                                                          5.516
CPRIV             0.224     20.559      1.057     33.004    434.179
LABUSKLS                     4.538                 6.953     47.559
LABUSKF
LABUSKIF         40.115                79.059
LABSK                       22.696                35.462    440.242
LANDLS                      16.748                26.328    264.813
LANDSH           12.431                50.391
CAPLSC                      61.662                97.087    982.019
CAPSH            13.917                21.609
CAPOT
HLSUPP
HLSLOW
HSHHLD
HURBUPP
HURBLOW
ENT
GOV
DTAX
ITAX              6.474      9.582      9.729     14.431     51.995
IMPTAR
S-I
DSTK
ROW
TOT              90.291    183.885    200.548    263.735   2663.389


+                AOCRPLC    AOCRPSH     ACATLC     ACATSH    AOLVKLC
AMZLC
AMZSH
AWT
AOGRNLC
AOGRNSH
AHORTLC
AHORTSH
ACOF
ATEA
AGRNTLC
AGRNTSH
ACOTLC
ACOTSH
ASUG
ATOB
AOCRPLC
AOCRPSH
ACATLC
ACATSH
AOLVKLC
AOLVKSH
AFISH
AFORLC
AFORSH
AMIN
AGRMIL
AOFDP
ATEXT
AOLGT
AFERT
AOMAN
AELWA
ACONS
ATDTP
APUB
APRIV
CMZ
CWT
COGRN
CHORT
CCOF
CTEA
CGRNT
CCOT
CSUG
CTOB
COCRP                                  40.308      5.049     49.295
CCAT                                   81.038
COLVK                                                        64.382
CFISH
CFOR                                    1.346                 1.223
CMIN
CGRMIL
COFDP             8.703      2.680    144.140      4.425    171.103
CTEXT
COLGT             0.591
CFERT            23.536      2.399     60.666
COMAN             0.675                29.864                36.379
CELWA             6.826                10.604                12.084
CCONS
CTDTP             3.840      2.352                 7.036
CTDTP-E
CTDTP-M
CTDTP-D
CPUB
CPRIV            29.692      0.144     22.223     25.263     28.500
LABUSKLS          6.651                 3.025                 6.791
LABUSKF
LABUSKIF                    17.553               216.606
LABSK            22.933                12.207                33.887
LANDLS           31.745
LANDSH                       5.771
CAPLSC           96.875                38.604               109.285
CAPSH                        5.684                88.754
CAPOT
HLSUPP
HLSLOW
HSHHLD
HURBUPP
HURBLOW
ENT
GOV
DTAX
ITAX             13.644      3.167     22.401     20.328     33.584
IMPTAR
S-I
DSTK
ROW
TOT             245.711     39.750    466.426    367.461    546.513


+                AOLVKSH      AFISH     AFORLC     AFORSH       AMIN
AMZLC
AMZSH
AWT
AOGRNLC
AOGRNSH
AHORTLC
AHORTSH
ACOF
ATEA
AGRNTLC
AGRNTSH
ACOTLC
ACOTSH
ASUG
ATOB
AOCRPLC
AOCRPSH
ACATLC
ACATSH
AOLVKLC
AOLVKSH
AFISH
AFORLC
AFORSH
AMIN
AGRMIL
AOFDP
ATEXT
AOLGT
AFERT
AOMAN
AELWA
ACONS
ATDTP
APUB
APRIV
CMZ
CWT
COGRN
CHORT
CCOF
CTEA
CGRNT
CCOT
CSUG
CTOB
COCRP             1.489
CCAT
COLVK
CFISH
CFOR
CMIN                                                         92.012
CGRMIL
COFDP             1.372      9.957
CTEXT                                                        15.787
COLGT                                                        16.260
CFERT                                                        19.163
COMAN                                   5.646               527.548
CELWA                                                        47.655
CCONS
CTDTP                                                        22.327
CTDTP-E
CTDTP-M
CTDTP-D
CPUB
CPRIV                                                         6.247
LABUSKLS                     0.916      1.473
LABUSKF                                                      35.565
LABUSKIF         74.392                           29.312
LABSK                        2.870      3.910               327.036
LANDLS
LANDSH
CAPLSC                      15.964     29.216
CAPSH            40.674                            2.868
CAPOT                                                       821.400
HLSUPP
HLSLOW
HSHHLD
HURBUPP
HURBLOW
ENT
GOV
DTAX
ITAX              7.527     29.981      4.119      2.137     88.876
IMPTAR
S-I
DSTK
ROW
TOT             125.454     59.688     44.364     34.317   2019.876


+                 AGRMIL      AOFDP      ATEXT      AOLGT      AFERT
AMZLC
AMZSH
AWT
AOGRNLC
AOGRNSH
AHORTLC
AHORTSH
ACOF
ATEA
AGRNTLC
AGRNTSH
ACOTLC
ACOTSH
ASUG
ATOB
AOCRPLC
AOCRPSH
ACATLC
ACATSH
AOLVKLC
AOLVKSH
AFISH
AFORLC
AFORSH
AMIN
AGRMIL
AOFDP
ATEXT
AOLGT
AFERT
AOMAN
AELWA
ACONS
ATDTP
APUB
APRIV
CMZ              57.693     15.130
CWT             150.165     19.378
COGRN
CHORT             3.761
CCOF                        54.186
CTEA                        58.267
CGRNT             5.599      9.728
CCOT              2.444               282.212
CSUG              1.308    210.465
CTOB                                             849.988
COCRP            13.611     54.967
CCAT              1.855    530.841                12.396
COLVK             1.586    224.164                 7.253
CFISH
CFOR
CMIN              1.873     37.581     12.668     12.356     38.918
CGRMIL            5.231     20.310                 1.422
COFDP            16.420    223.650      4.464      5.244      1.325
CTEXT             8.305     68.673    509.853    190.949      1.335
COLGT             2.798     60.174     16.270    140.933      3.205
CFERT             1.902      4.368     23.809      3.339    176.500
COMAN            14.659    293.611     51.813     92.303     44.651
CELWA             3.291     13.449     15.521      7.464     38.064
CCONS             1.058      8.155                 5.142      1.239
CTDTP             6.291     43.630     23.942     20.871      9.643
CTDTP-E
CTDTP-M
CTDTP-D
CPUB              1.049      7.975      4.432      5.086      1.231
CPRIV             3.519     27.616      6.018      6.645      5.470
LABUSKLS
LABUSKF           5.985     23.833     26.686     52.979      6.180
LABUSKIF                              106.130    252.141
LABSK            45.582    200.872    234.437    528.899     47.053
LANDLS
LANDSH
CAPLSC
CAPSH
CAPOT            97.249   1581.316    417.892    733.119     75.616
HLSUPP
HLSLOW
HSHHLD
HURBUPP
HURBLOW
ENT
GOV
DTAX
ITAX             -8.029    -36.197     65.549    148.650     25.145
IMPTAR
S-I
DSTK
ROW
TOT             445.205   3756.142   1801.696   3077.179    475.575


+                  AOMAN      AELWA      ACONS      ATDTP       APUB
AMZLC
AMZSH
AWT
AOGRNLC
AOGRNSH
AHORTLC
AHORTSH
ACOF
ATEA
AGRNTLC
AGRNTSH
ACOTLC
ACOTSH
ASUG
ATOB
AOCRPLC
AOCRPSH
ACATLC
ACATSH
AOLVKLC
AOLVKSH
AFISH
AFORLC
AFORSH
AMIN
AGRMIL
AOFDP
ATEXT
AOLGT
AFERT
AOMAN
AELWA
ACONS
ATDTP
APUB
APRIV
CMZ
CWT
COGRN
CHORT
CCOF
CTEA
CGRNT             6.508                                       3.928
CCOT
CSUG
CTOB
COCRP            66.327                                      24.617
CCAT             40.713                                      10.943
COLVK            16.220                                       9.850
CFISH
CFOR
CMIN            905.706     40.827    270.254     84.680     11.724
CGRMIL                                                        3.917
COFDP            27.448                           32.629     36.191
CTEXT            66.531      2.853     26.739    185.439    186.177
COLGT            54.448      6.279     17.373    115.206     35.094
CFERT            20.585      7.049      3.407      7.863      2.726
COMAN          2022.752     42.255   1548.602   2648.697    483.929
CELWA            14.242    186.655     10.147     14.819      8.705
CCONS            12.634               109.810     96.710     34.868
CTDTP            49.256     21.991     56.105    182.636     35.773
CTDTP-E
CTDTP-M
CTDTP-D
CPUB             12.383               160.411    278.453     64.396
CPRIV            25.542      3.092      9.152     30.870     12.667
LABUSKLS
LABUSKF          76.422     24.788     51.159    129.132    205.837
LABUSKIF                               53.739    503.413
LABSK           965.888    217.756    513.037   1814.440   2591.149
LANDLS
LANDSH
CAPLSC
CAPSH
CAPOT          1659.721    457.456    195.065   1949.681    897.681
HLSUPP
HLSLOW
HSHHLD
HURBUPP
HURBLOW
ENT
GOV
DTAX
ITAX            240.353     58.277    159.646    188.471    203.298
IMPTAR
S-I
DSTK
ROW
TOT            6283.679   1069.278   3184.646   8263.139   4863.470


+                  APRIV        CMZ        CWT      COGRN      CHORT
AMZLC                      197.804
AMZSH                      131.903
AWT                                   124.535
AOGRNLC                                           20.804
AOGRNSH                                            4.492
AHORTLC                                                     212.813
AHORTSH                                                      10.870
ACOF
ATEA
AGRNTLC
AGRNTSH
ACOTLC
ACOTSH
ASUG
ATOB
AOCRPLC
AOCRPSH
ACATLC
ACATSH
AOLVKLC
AOLVKSH
AFISH
AFORLC
AFORSH
AMIN
AGRMIL
AOFDP
ATEXT
AOLGT
AFERT
AOMAN
AELWA
ACONS
ATDTP
APUB
APRIV
CMZ
CWT
COGRN
CHORT
CCOF
CTEA
CGRNT             2.494
CCOT
CSUG
CTOB
COCRP            22.645
CCAT             22.806
COLVK
CFISH
CFOR
CMIN             21.789
CGRMIL
COFDP            83.473
CTEXT           127.269
COLGT           110.904
CFERT
COMAN           550.250
CELWA            10.845
CCONS           131.328
CTDTP           167.899
CTDTP-E                     12.135                            3.180
CTDTP-M                                 3.099      1.821      0.935
CTDTP-D                     33.860     22.210      4.541     48.935
CPUB            917.260
CPRIV            25.529
LABUSKLS
LABUSKF         113.727
LABUSKIF        577.891
LABSK          1679.413
LANDLS
LANDSH
CAPLSC
CAPSH
CAPOT          1973.636
HLSUPP
HLSLOW
HSHHLD
HURBUPP
HURBLOW
ENT
GOV
DTAX
ITAX            124.461
IMPTAR                                  3.033      1.964      1.077
S-I
DSTK
ROW                                    16.666     11.017      4.764
TOT            6663.619    375.702    169.543     44.639    282.574


+                   CCOF       CTEA      CGRNT       CCOT       CSUG
AMZLC
AMZSH
AWT
AOGRNLC
AOGRNSH
AHORTLC
AHORTSH
ACOF            114.552
ATEA                        86.560
AGRNTLC                                18.874
AGRNTSH                                12.172
ACOTLC                                           183.886
ACOTSH                                           200.549
ASUG                                                        263.735
ATOB
AOCRPLC
AOCRPSH
ACATLC
ACATSH
AOLVKLC
AOLVKSH
AFISH
AFORLC
AFORSH
AMIN
AGRMIL
AOFDP
ATEXT
AOLGT
AFERT
AOMAN
AELWA
ACONS
ATDTP
APUB
APRIV
CMZ
CWT
COGRN
CHORT
CCOF
CTEA
CGRNT
CCOT
CSUG
CTOB
COCRP
CCAT
COLVK
CFISH
CFOR
CMIN
CGRMIL
COFDP
CTEXT
COLGT
CFERT
COMAN
CELWA
CCONS
CTDTP
CTDTP-E          16.394      8.983      1.751     32.678     20.167
CTDTP-M
CTDTP-D           6.764      8.493      4.382     34.035     30.621
CPUB
CPRIV
LABUSKLS
LABUSKF
LABUSKIF
LABSK
LANDLS
LANDSH
CAPLSC
CAPSH
CAPOT
HLSUPP
HLSLOW
HSHHLD
HURBUPP
HURBLOW
ENT
GOV
DTAX
ITAX
IMPTAR
S-I
DSTK
ROW
TOT             137.710    104.036     37.179    451.148    314.523


+                   CTOB      COCRP       CCAT      COLVK      CFISH
AMZLC
AMZSH
AWT
AOGRNLC
AOGRNSH
AHORTLC
AHORTSH
ACOF
ATEA
AGRNTLC
AGRNTSH
ACOTLC
ACOTSH
ASUG
ATOB           2663.388
AOCRPLC                    245.711
AOCRPSH                     39.749
ACATLC                                466.426
ACATSH                                266.225
AOLVKLC                                          546.514
AOLVKSH                                            3.540
AFISH                                                        59.689
AFORLC
AFORSH
AMIN
AGRMIL
AOFDP
ATEXT
AOLGT
AFERT
AOMAN
AELWA
ACONS
ATDTP
APUB
APRIV
CMZ
CWT
COGRN
CHORT
CCOF
CTEA
CGRNT
CCOT
CSUG
CTOB
COCRP
CCAT
COLVK
CFISH
CFOR
CMIN
CGRMIL
COFDP
CTEXT
COLGT
CFERT
COMAN
CELWA
CCONS
CTDTP
CTDTP-E         479.364                            5.380
CTDTP-M           3.056
CTDTP-D         127.272     55.495    149.756    112.072     11.392
CPUB
CPRIV
LABUSKLS
LABUSKF
LABUSKIF
LABSK
LANDLS
LANDSH
CAPLSC
CAPSH
CAPOT
HLSUPP
HLSLOW
HSHHLD
HURBUPP
HURBLOW
ENT
GOV
DTAX
ITAX
IMPTAR            3.643
S-I
DSTK
ROW              15.568
TOT            3292.291    340.955    882.407    667.506     71.081


+                   CFOR       CMIN     CGRMIL      COFDP      CTEXT
AMZLC
AMZSH
AWT
AOGRNLC
AOGRNSH
AHORTLC
AHORTSH
ACOF
ATEA
AGRNTLC
AGRNTSH
ACOTLC
ACOTSH
ASUG
ATOB
AOCRPLC
AOCRPSH
ACATLC
ACATSH
AOLVKLC
AOLVKSH
AFISH
AFORLC           44.364
AFORSH            0.342
AMIN                      2019.876
AGRMIL                                445.203
AOFDP                                           3756.142
ATEXT                                                      1801.696
AOLGT
AFERT
AOMAN
AELWA
ACONS
ATDTP
APUB
APRIV
CMZ
CWT
COGRN
CHORT
CCOF
CTEA
CGRNT
CCOT
CSUG
CTOB
COCRP
CCAT
COLVK
CFISH
CFOR
CMIN
CGRMIL
COFDP
CTEXT
COLGT
CFERT
COMAN
CELWA
CCONS
CTDTP
CTDTP-E                    137.907                44.271     18.695
CTDTP-M                     14.486                32.710     55.140
CTDTP-D           6.853    123.469    320.797    830.084    273.487
CPUB
CPRIV
LABUSKLS
LABUSKF
LABUSKIF
LABSK
LANDLS
LANDSH
CAPLSC
CAPSH
CAPOT
HLSUPP
HLSLOW
HSHHLD
HURBUPP
HURBLOW
ENT
GOV
DTAX
ITAX
IMPTAR                      24.471                38.337     82.522
S-I
DSTK
ROW                        100.162               158.322    296.536
TOT              51.559   2420.371    766.000   4859.866   2528.076


+                  COLGT      CFERT      COMAN      CELWA      CCONS
AMZLC
AMZSH
AWT
AOGRNLC
AOGRNSH
AHORTLC
AHORTSH
ACOF
ATEA
AGRNTLC
AGRNTSH
ACOTLC
ACOTSH
ASUG
ATOB
AOCRPLC
AOCRPSH
ACATLC
ACATSH
AOLVKLC
AOLVKSH
AFISH
AFORLC
AFORSH
AMIN
AGRMIL
AOFDP
ATEXT
AOLGT          3077.177
AFERT                      475.574
AOMAN                                6283.679
AELWA                                           1069.277
ACONS                                                      3184.646
ATDTP
APUB
APRIV
CMZ
CWT
COGRN
CHORT
CCOF
CTEA
CGRNT
CCOT
CSUG
CTOB
COCRP
CCAT
COLVK
CFISH
CFOR
CMIN
CGRMIL
COFDP
CTEXT
COLGT
CFERT
COMAN
CELWA
CCONS
CTDTP
CTDTP-E          22.437      1.448    181.197
CTDTP-M          43.936     50.138   1483.960
CTDTP-D         368.540    136.235    735.079
CPUB
CPRIV
LABUSKLS
LABUSKF
LABUSKIF
LABSK
LANDLS
LANDSH
CAPLSC
CAPSH
CAPOT
HLSUPP
HLSLOW
HSHHLD
HURBUPP
HURBLOW
ENT
GOV
DTAX
ITAX
IMPTAR          139.019     48.527   1466.925
S-I
DSTK
ROW             425.317    323.567   6245.708
TOT            4076.426   1035.489  16396.548   1069.277   3184.646


+                  CTDTP    CTDTP-E    CTDTP-M    CTDTP-D       CPUB
AMZLC
AMZSH
AWT
AOGRNLC
AOGRNSH
AHORTLC
AHORTSH
ACOF
ATEA
AGRNTLC
AGRNTSH
ACOTLC
ACOTSH
ASUG
ATOB
AOCRPLC
AOCRPSH
ACATLC
ACATSH
AOLVKLC
AOLVKSH
AFISH
AFORLC
AFORSH
AMIN
AGRMIL
AOFDP
ATEXT
AOLGT
AFERT
AOMAN
AELWA
ACONS
ATDTP          8263.137
APUB                                                       4863.472
APRIV
CMZ
CWT
COGRN
CHORT
CCOF
CTEA
CGRNT
CCOT
CSUG
CTOB
COCRP
CCAT
COLVK
CFISH
CFOR
CMIN
CGRMIL
COFDP
CTEXT
COLGT
CFERT
COMAN
CELWA
CCONS
CTDTP                      985.989   1689.281   3444.372
CTDTP-E
CTDTP-M
CTDTP-D
CPUB
CPRIV
LABUSKLS
LABUSKF
LABUSKIF
LABSK
LANDLS
LANDSH
CAPLSC
CAPSH
CAPOT
HLSUPP
HLSLOW
HSHHLD
HURBUPP
HURBLOW
ENT
GOV
DTAX
ITAX
IMPTAR
S-I
DSTK
ROW
TOT            8263.137    985.989   1689.281   3444.372   4863.472


+                  CPRIV   LABUSKLS    LABUSKF   LABUSKIF      LABSK
AMZLC
AMZSH
AWT
AOGRNLC
AOGRNSH
AHORTLC
AHORTSH
ACOF
ATEA
AGRNTLC
AGRNTSH
ACOTLC
ACOTSH
ASUG
ATOB
AOCRPLC
AOCRPSH
ACATLC
ACATSH
AOLVKLC
AOLVKSH
AFISH
AFORLC
AFORSH
AMIN
AGRMIL
AOFDP
ATEXT
AOLGT
AFERT
AOMAN
AELWA
ACONS
ATDTP
APUB
APRIV          6663.621
CMZ
CWT
COGRN
CHORT
CCOF
CTEA
CGRNT
CCOT
CSUG
CTOB
COCRP
CCAT
COLVK
CFISH
CFOR
CMIN
CGRMIL
COFDP
CTEXT
COLGT
CFERT
COMAN
CELWA
CCONS
CTDTP
CTDTP-E
CTDTP-M
CTDTP-D
CPUB
CPRIV
LABUSKLS
LABUSKF
LABUSKIF
LABSK
LANDLS
LANDSH
CAPLSC
CAPSH
CAPOT
HLSUPP                                                      810.446
HLSLOW                      99.675
HSHHLD                                           694.726
HURBUPP                                                    8984.794
HURBLOW                               752.294   1482.780
ENT
GOV
DTAX
ITAX
IMPTAR           51.483
S-I
DSTK
ROW             450.372                                      26.000
TOT            7165.476     99.675    752.294   2177.506   9821.240


+                 LANDLS     LANDSH     CAPLSC      CAPSH      CAPOT
AMZLC
AMZSH
AWT
AOGRNLC
AOGRNSH
AHORTLC
AHORTSH
ACOF
ATEA
AGRNTLC
AGRNTSH
ACOTLC
ACOTSH
ASUG
ATOB
AOCRPLC
AOCRPSH
ACATLC
ACATSH
AOLVKLC
AOLVKSH
AFISH
AFORLC
AFORSH
AMIN
AGRMIL
AOFDP
ATEXT
AOLGT
AFERT
AOMAN
AELWA
ACONS
ATDTP
APUB
APRIV
CMZ
CWT
COGRN
CHORT
CCOF
CTEA
CGRNT
CCOT
CSUG
CTOB
COCRP
CCAT
COLVK
CFISH
CFOR
CMIN
CGRMIL
COFDP
CTEXT
COLGT
CFERT
COMAN
CELWA
CCONS
CTDTP
CTDTP-E
CTDTP-M
CTDTP-D
CPUB
CPRIV
LABUSKLS
LABUSKF
LABUSKIF
LABSK
LANDLS
LANDSH
CAPLSC
CAPSH
CAPOT
HLSUPP          457.532              1719.072
HLSLOW
HSHHLD                     136.802               260.048
HURBUPP
HURBLOW                                                     126.709
ENT                                                       10733.122
GOV
DTAX
ITAX
IMPTAR
S-I
DSTK
ROW
TOT             457.532    136.802   1719.072    260.048  10859.831


+                 HLSUPP     HLSLOW     HSHHLD    HURBUPP    HURBLOW
AMZLC
AMZSH                                 204.154
AWT
AOGRNLC
AOGRNSH                                72.672
AHORTLC
AHORTSH                                72.930
ACOF
ATEA
AGRNTLC
AGRNTSH                                78.119
ACOTLC
ACOTSH
ASUG
ATOB
AOCRPLC
AOCRPSH
ACATLC
ACATSH                                101.236
AOLVKLC
AOLVKSH                               121.914
AFISH
AFORLC
AFORSH                                 33.976
AMIN
AGRMIL
AOFDP
ATEXT
AOLGT
AFERT
AOMAN
AELWA
ACONS
ATDTP
APUB
APRIV
CMZ                         12.789     37.758               178.911
CWT
COGRN            14.452      2.218      6.375     21.593
CHORT            45.547      6.338      7.885    111.947     90.893
CCOF
CTEA
CGRNT
CCOT
CSUG
CTOB
COCRP                        3.012     13.116                46.521
CCAT            167.654      1.995     25.362
COLVK           160.820      7.787     49.162               118.593
CFISH            24.604      0.551      6.558     29.673      9.695
CFOR              9.343                12.533     20.809
CMIN
CGRMIL          306.765     11.757     60.628    175.286    180.684
COFDP          1468.304     11.213    192.417   1895.538    371.624
CTEXT           405.294      3.017     38.187    500.178     70.843
COLGT          1271.068     23.715    277.276   1375.635    488.545
CFERT                                             43.729
COMAN          1081.586      4.902     80.241   1968.591    185.273
CELWA           114.110      0.831     10.492    406.835     70.500
CCONS
CTDTP           542.576      3.007     59.692    591.971     69.938
CTDTP-E
CTDTP-M
CTDTP-D
CPUB            219.442      3.478     84.366    163.983     48.476
CPRIV          1387.398      1.139     91.684   1704.714    166.578
LABUSKLS
LABUSKF
LABUSKIF
LABSK
LANDLS
LANDSH
CAPLSC
CAPSH
CAPOT
HLSUPP
HLSLOW
HSHHLD                                            79.105    180.345
HURBUPP
HURBLOW
ENT
GOV
DTAX            687.887                20.947   1239.894    111.273
ITAX
IMPTAR
S-I            1343.487      1.925     69.263   2068.071    212.253
DSTK
ROW
TOT            9250.337     99.674   1828.943  12397.552   2600.945


+                    ENT        GOV       DTAX       ITAX     IMPTAR
AMZLC
AMZSH
AWT
AOGRNLC
AOGRNSH
AHORTLC
AHORTSH
ACOF
ATEA
AGRNTLC
AGRNTSH
ACOTLC
ACOTSH
ASUG
ATOB
AOCRPLC
AOCRPSH
ACATLC
ACATSH
AOLVKLC
AOLVKSH
AFISH
AFORLC
AFORSH
AMIN
AGRMIL
AOFDP
ATEXT
AOLGT
AFERT
AOMAN
AELWA
ACONS
ATDTP
APUB
APRIV
CMZ
CWT
COGRN
CHORT
CCOF
CTEA
CGRNT
CCOT
CSUG
CTOB
COCRP
CCAT
COLVK
CFISH
CFOR
CMIN
CGRMIL
COFDP                       39.749
CTEXT
COLGT                       66.853
CFERT
COMAN                      203.824
CELWA                       19.582
CCONS
CTDTP                      169.376
CTDTP-E
CTDTP-M
CTDTP-D
CPUB                      2884.525
CPRIV                     1391.092
LABUSKLS
LABUSKF
LABUSKIF
LABSK
LANDLS
LANDSH
CAPLSC
CAPSH
CAPOT
HLSUPP         5526.096    635.190
HLSLOW
HSHHLD                     477.915
HURBUPP        3306.025    106.734
HURBLOW                    239.161
ENT                       1209.000
GOV                                  3727.000   1478.000   1861.000
DTAX           1667.000
ITAX
IMPTAR
S-I             908.000   -504.000
DSTK
ROW             535.000    418.000
TOT           11942.121   7357.001   3727.000   1478.000   1861.000


+                    S-I     DSTK        ROW        TOT
AMZLC                                            197.804
AMZSH                                            336.057
AWT                                              124.535
AOGRNLC                                           20.804
AOGRNSH                                           77.164
AHORTLC                                          212.813
AHORTSH                                           83.800
ACOF                                             114.552
ATEA                                              86.560
AGRNTLC                                           18.874
AGRNTSH                                           90.291
ACOTLC                                           183.886
ACOTSH                                           200.549
ASUG                                             263.735
ATOB                                            2663.388
AOCRPLC                                          245.711
AOCRPSH                                           39.749
ACATLC                                           466.426
ACATSH                                           367.461
AOLVKLC                                          546.514
AOLVKSH                                          125.454
AFISH                                             59.689
AFORLC                                            44.364
AFORSH                                            34.318
AMIN                                            2019.876
AGRMIL                                           445.203
AOFDP                                           3756.142
ATEXT                                           1801.696
AOLGT                                           3077.177
AFERT                                            475.574
AOMAN                                           6283.679
AELWA                                           1069.277
ACONS                                           3184.646
ATDTP                                           8263.137
APUB                                            4863.472
APRIV                                           6663.621
CMZ                                    73.421    375.702
CWT                                              169.543
COGRN                                             44.638
CHORT                                  16.203    282.574
CCOF                                   83.523    137.709
CTEA                                   45.768    104.035
CGRNT                                   8.924     37.181
CCOT                                  166.491    451.147
CSUG                                  102.750    314.523
CTOB                                 2442.304   3292.292
COCRP                                            340.957
CCAT                       -13.197               882.406
COLVK                      -17.109     24.798    667.506
CFISH                                             71.081
CFOR                                              51.557
CMIN                                  889.986   2420.374
CGRMIL                                           766.000
COFDP                     -165.863    178.565   4859.866
CTEXT                                 120.649   2528.078
COLGT                     -228.426    144.800   4076.427
CFERT                                   9.344   1035.488
COMAN          3399.004   -100.112   1169.355  16396.546
CELWA                                           1069.277
CCONS          2783.702                         3184.646
CTDTP                                           8263.139
CTDTP-E                                          985.987
CTDTP-M                                         1689.281
CTDTP-D                                         3444.372
CPUB                                            4863.473
CPRIV                                1598.118   7165.479
LABUSKLS                                          99.674
LABUSKF                                          752.293
LABUSKIF                                        2177.506
LABSK                                           9821.239
LANDLS                                           457.531
LANDSH                                           136.803
CAPLSC                                          1719.071
CAPSH                                            260.048
CAPOT                                          10859.832
HLSUPP                                102.000   9250.336
HLSLOW                                            99.675
HSHHLD                                          1828.941
HURBUPP                                        12397.553
HURBLOW                                         2600.944
ENT                                            11942.122
GOV                                   291.000   7357.000
DTAX                                            3727.001
ITAX                                            1477.997
IMPTAR                                          1861.001
S-I                                  1559.000   5657.999
DSTK         -524.706                         -524.706
ROW                                             9026.999
TOT            5658.000   -524.707   9026.999 211466.147

;
*==============


PARAMETER

 TDIFF0(AC)     column minus row sum for the initial SAM
;

ZIMSAM('TOT',ACNTP)       = SUM(ACNT,  ZIMSAM(ACNT,ACNTP));
ZIMSAM(ACNT,'TOT')        = SUM(ACNTP, ZIMSAM(ACNT,ACNTP));
TDIFF0(ACNT)              = ZIMSAM('TOT',ACNT) - ZIMSAM(ACNT,'TOT') ;
 ;

DISPLAY TDIFF0;

*######################3. SAM AGGREGATION ##############################

SET

*!!- Here: specify the accounts that are part of aggregation
*and/or renamed. There is no need to manually specify accounts
*that appear both in the disaggregated and aggregated SAMs (in
*the example all non-government institutions and tax accounts).

MAPSAM(AC,ACP)  account acp in initial SAM is mapped to ac in final SAM
        /
     A-AGR-LS       .(AMZLC
                      AOGRNLC
                      AHORTLC
                      AGRNTLC
                      ACOTLC
                      AOCRPLC
                      ACATLC
                      AOLVKLC
                      AFORLC
                      AWT
                      ACOF
                      ATEA
                      ASUG
                      ATOB
                      AFISH )
     A-AGR-SH       .(AMZSH
                      AOGRNSH
                      AHORTSH
                      AGRNTSH
                      ACOTSH
                      AOCRPSH
                      ACATSH
                      AOLVKSH
                      AFORSH )
     A-IND          .(AGRMIL
                      AOFDP
                      ATEXT
                      AOLGT
                      AFERT
                      AOMAN
                      AMIN  )
     A-TRAN         .(ATDTP )
     A-SERV         .(AELWA
                      ACONS
                      APUB
                      APRIV )
     C-AGR          .(CMZ
                      CWT
                      COGRN
                      CHORT
                      CCOF
                      CTEA
                      CGRNT
                      CCOT
                      CSUG
                      CTOB
                      COCRP
                      CCAT
                      COLVK
                      CFISH
                      CFOR  )
     C-IND          .(CGRMIL
                      COFDP
                      CTEXT
                      COLGT
                      CFERT
                      COMAN
                      CMIN  )
     C-TRAN         .(CTDTP )
     C-SERV         .(CELWA
                      CCONS
                      CPUB
                      CPRIV )

     MM-D           .(CTDTP-D)
     MM-M           .(CTDTP-M)
     MM-E           .(CTDTP-E)

     LABOR          .(LABUSKLS
                      LABUSKF
                      LABUSKIF
                      LABSK  )
     CAPITAL        .(CAPLSC
                      CAPSH
                      CAPOT  )
     LAND           .(LANDLS
                      LANDSH )
     RUR-HH         .(HLSUPP
                      HLSLOW
                      HSHHLD )
     URB-HH         .(HURBUPP
                      HURBLOW)
     /
   ;


*Completing the definition of MAPSAM to include accounts that
*should appear unchanged in both SAMs.

*Element ACNT is mapped to the identical element ACNT
*1. if it appears inside the disaggregated SAM (the starting point); and
*2. if it does not appear in the mapping MAPSAM (as defined above)

 MAPSAM(ACNT,ACNT)
 $(( SUM(ACNTP, ZIMSAM(ACNTP,ACNT)) + SUM(ACNTP, ZIMSAM(ACNT,ACNTP)))
 $(( NOT SUM(ACNTP, MAPSAM(ACNT,ACNTP)) + SUM(ACNTP, MAPSAM(ACNTP,ACNT)))))
 = YES
;

DISPLAY MAPSAM;


PARAMETER
 EMPTYMAP(AC) error if mapping of empty accounts into non-empty account
 ;
*Error (EMPTYMAP = UNDF) for target account ACNT if it is non-zero
*in the original SAM and if the original account(s) (which ACNT is
*an aggregation of) have no values in the SAM. If this is done, then
*there is probably an error in the mapping that should be corrected.

*In words: EMPTYMAP(ACNT) = 1/0 IF
*Line 1 of condition:
*a. ACNT is in the first index of MAPSAM -- a target element; AND
*b. ACNT has a non-zero total. AND
*Line 2 of condition:
*The sum of all totals for the elements that are mapped into ACNT
*are zero.

EMPTYMAP(ACNT)
 $(SUM(ACNTP$SUM(ACNTPP, MAPSAM(ACNT,ACNTPP)), ZIMSAM(ACNT,ACNTP))
  AND SUM((ACNTP,ACNTPP)$MAPSAM(ACNT,ACNTP), ZIMSAM(ACNTP,ACNTPP)) EQ 0)
 = 1/0;

DISPLAY EMPTYMAP;


PARAMETER
 SAM(AC,ACP)  aggregated SAM
 TDIFF(AC)    column minus row sum for accounts in aggregated SAM
;

*Aggregating
 SAM(ACNT,ACNTP)
 = SUM((AC,ACP)$(MAPSAM(ACNT,AC)$MAPSAM(ACNTP,ACP)),
                                                ZIMSAM(AC,ACP));

*Computing and checking totals
 SAM('TOTAL',ACNTP)  = SUM(ACNT,  SAM(ACNT,ACNTP));
 SAM(ACNT,'TOTAL')   = SUM(ACNTP, SAM(ACNT,ACNTP));
 TDIFF(ACNT)         = SAM('TOTAL',ACNT) - SAM(ACNT,'TOTAL') ;
 ;

DISPLAY SAM, TDIFF;


*#######################   Optional   ###################################
* Exporting data to a spreadsheet-SAM parameter
* Exporting to a spreadsheet requires additional software (Xllink)
*   written by Tom Rutherford. Downloadable from the following webpage:
*        http://www.gams.com/contrib/sslink/ssdoc.htm

*$libinclude xlexport SAM  aggSAM.xls sheet1!newsam

* To export the parameter SAM to an Excel spreadsheet, the above command
* line assumes an Excel spreadsheet file "aggSAM.xls" exists with a
* named range "newsam" defined in worksheet "sheet1"
*########################################################################


*#*#*#*#*# THE END OF SAMAGG.GMS #*#*#*#*