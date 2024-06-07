
{units
	(define "armored_capture"
		{cw 10 15 20 0} {cwe 1} {cwa 1} {cwn 1}
	)
	(define "charge_level_3_medium+"
		{charge 1} {fore -120}
	)	
	(define "charge_level_3_heavy"
		{charge 1} {fore -220}
	)	
	(define "charge_level_4_light"
		{charge 1} {fore -100}
	)	
	(define "charge_level_4"
		{charge 1} {fore -190}
	)
	(define "charge_level_4_heavy"
		{charge 1} {fore -460}
	)
	(define "charge_level_5_light"
		{charge 1} {fore -220}
	)	
	(define "charge_level_5"
		{charge 1} {fore -410}
	)
	(define "charge_level_5_heavy"
		{charge 1} {fore -560}
	)
	(define "charge_level_6_light"
		{charge 1} {fore -340}
	)	
	(define "charge_level_6"
		{charge 1} {fore -660}
	)
	(define "charge_level_6_heavy"
		{charge 1} {fore -720}
	)	
;[Moto]_____________________________________________________________________________________________________________________________________________________________________
;level_1	
	{"r12"				("armored_capture")}
	{"m72"				("armored_capture")}
	{"hd"				("armored_capture")}
	{"type97"			("armored_capture")}
;[Car]_____________________________________________________________________________________________________________________________________________________________________
;level_1
	{"kubel_mgun"		("armored_capture")}
	{"gaz67b"			("armored_capture")}
	{"willysmb_maxim"	("armored_capture")}
	{"willysmb"			("armored_capture")}
	;level_2
	{"willysat"			("armored_capture")}
	{"willysat_mgun"	("armored_capture")}	
	;level_4
	{"dodgewc51_m2hb"	("armored_capture") ("charge_level_4")}
;[APC]_____________________________________________________________________________________________________________________________________________________________________
;level_2
	{"sdkfz251_17"				("armored_capture")}
	{"sdkfz222"					("armored_capture")}
	{"sdkfz221"					("armored_capture")}
	{"m20"						("armored_capture")}
;level_3
	{"ab41"						("armored_capture")}
	{"sdkfz232"					("armored_capture")}
	{"ba11"						("armored_capture")}
	{"m8grayhound"				("armored_capture")}
;level_4
	{"sdkfz234"					("armored_capture") ("charge_level_4_light")}
;level_5
	{"sdkfz251_16"				("armored_capture") ("charge_level_5_light")}
;level_6
	{"pz4f2_inf"				("armored_capture") ("charge_level_6")}
	{"pz4g_inf"					("armored_capture") ("charge_level_6")}
	{"t34_76_inf"				("armored_capture") ("charge_level_6")}
	{"t34_2_inf"				("armored_capture") ("charge_level_6")}
	{"m4a1_inf"					("armored_capture") ("charge_level_6")}
	{"m4a3dd_inf"				("armored_capture") ("charge_level_6")}
;Reactive
	;level_5
	{"bm13"						("armored_capture") ("charge_level_5_light")}
	;level_6
	{"sdkfz4"					("armored_capture") ("charge_level_6")}		
;[Zenite_Vehicle]___________________________________________________________________________________________________________________________________________________________
;level_2
	{"pz1"				("armored_capture")}
	{"dshk_aaa"			("armored_capture")}
	{"m16"				("armored_capture")}
;level_3
	{"sdkfz7_1"			("armored_capture")}
	{"zsu37"			("armored_capture")}
;level_4
	{"29k"				("armored_capture") ("charge_level_4_light")}
	{"welberwind"		("armored_capture") ("charge_level_4_light")}
	{"m19"				("armored_capture") ("charge_level_4")}
;[Tank Light]______________________________________________________________________________________________________________________________________________________________
;level_1
	{"pz1b"				("armored_capture")}
	{"t40"				("armored_capture")}
	{"t40_tns"			("armored_capture")}
;level_2
	{"pz1c"  			("armored_capture")}
	{"pz38g"			("armored_capture")}
	{"pz35t"			("armored_capture")}
	{"pz2f"				("armored_capture")}
	{"pz2l"				("armored_capture")}
	{"pz2c"				("armored_capture")}
	{"bt7_ger"			("armored_capture")}
	{"t26"				("armored_capture")}
	{"t26e"				("armored_capture")}
	{"bt7"				("armored_capture")}
	{"t60"				("armored_capture")}
	{"t70"				("armored_capture")}
	{"m3a1"				("armored_capture")}
	{"m3a1_rus"			("armored_capture")}
	{"m5a1"				("armored_capture")}
	{"lvt1"				("armored_capture")}
;level_3
	{"ht26"				("armored_capture")}
	{"carro15"			("armored_capture")}
	{"pz2h"				("armored_capture")}
	{"bt7a"				("armored_capture")}
	{"m24"				("armored_capture")}
	{"lvt4"				("armored_capture")}
;[Minetral]______________________________________________________________________________________________________________________________________________________________
;level_2
	{"pz3m"				("armored_capture")}
	{"t34m"				("armored_capture") ("charge_level_6")}
	{"m4a3m"			("armored_capture") ("charge_level_6")}
;[Tank Medium]______________________________________________________________________________________________________________________________________________________________
;level_1
	{"m2a1_med"			("armored_capture")}
;level_2
	{"pz3f"				("armored_capture")}
	{"pz3f_rus"			("armored_capture")}
	{"t28"				("armored_capture")}
	{"valentine_rus"	("armored_capture")}
	{"mk2a"				("armored_capture")}
	{"chi-he"			("armored_capture")}
;level_3
	{"pz3"				("armored_capture")}
	{"pz3j"				("armored_capture")}
	{"pz3n"				("armored_capture")}
	{"pz4e"				("armored_capture")}
	{"pz4f2"			("armored_capture") ("charge_level_3_medium+")}
	{"t34_76"			("armored_capture") ("charge_level_3_medium+")}
	{"t34_0"			("armored_capture") ("charge_level_3_medium+")}
	{"t28e"				("armored_capture")}
	{"grant_m3"			("armored_capture")}
	{"m3_lee"			("armored_capture")}
	{"m4a1"				("armored_capture") ("charge_level_3_medium+")}
	{"mk8"				("armored_capture")}
	{"chi-nu"			("armored_capture")}
;level_4
	{"pz4d"				("armored_capture") ("charge_level_4")}
	{"pz4g"				("armored_capture") ("charge_level_4")}
	{"pz4h"				("armored_capture") ("charge_level_4")}
	{"t34_2"			("armored_capture") ("charge_level_4")}
	{"t34_armored"		("armored_capture") ("charge_level_4")}
	{"t34_76_41"		("armored_capture") ("charge_level_4")}
	{"m4a2_rus"			("armored_capture") ("charge_level_4")}
	{"t34_1"			("armored_capture") ("charge_level_4")}
	{"t34_57_43"		("armored_capture") ("charge_level_4")}
	{"m4a1_eng"			("armored_capture") ("charge_level_4")}
	{"m4a2"				("armored_capture") ("charge_level_4")}
	{"m4a3_75"			("armored_capture") ("charge_level_4")}
	{"m4a4"				("armored_capture") ("charge_level_4")}
	{"m4a3dd"			("armored_capture") ("charge_level_4")}
	{"m4a3_105"			("armored_capture") ("charge_level_4")}
	{"chi-to"			("armored_capture") ("charge_level_4")}
;level_5
	{"pz5a"				("armored_capture") ("charge_level_5")}
	{"pz5a_po"			("armored_capture") ("charge_level_5")}
	{"t34_3"			("armored_capture") ("charge_level_5")}
	{"ot34_76_42"		("armored_capture") ("charge_level_5")}
	{"t34_85"			("armored_capture") ("charge_level_5")}
	{"t34_85_po"		("armored_capture") ("charge_level_5")}
	{"m4a2_76w_rus"		("armored_capture") ("charge_level_5")}
	{"m4a3e8"			("armored_capture") ("charge_level_5")}
	{"m4a3e8_po"		("armored_capture") ("charge_level_5")}
	{"m4a2_76w"			("armored_capture") ("charge_level_5")}
	{"m4a2_76w_thunderbolt"		("armored_capture") ("charge_level_5")}
	{"m4a3vc"			("armored_capture") ("charge_level_5")}
	{"m4a3e2"			("armored_capture") ("charge_level_5")}
	{"m4a3_zippo"		("armored_capture") ("charge_level_5")}
;level_6
	{"pz5g"				("armored_capture") ("charge_level_6")}
	{"t34_85m"			("armored_capture") ("charge_level_6")}
	{"t34_85m_po"		("armored_capture") ("charge_level_6")}
	{"m4a3e2_jumbo_76"	("armored_capture") ("charge_level_6")}
	{"m4a3c"			("armored_capture") ("charge_level_6")}
;[Tank Heavy]_______________________________________________________________________________________________________________________________________________________________
;level_1
;level_2
	{"t35"				("armored_capture")}
	{"pzb2740f"			("armored_capture")}
;level_3
	{"kv1"				("armored_capture") ("charge_level_3_heavy")}
	{"kv1_za_rodinu"	("armored_capture") ("charge_level_3_heavy")}
	{"mk4_rus"			("armored_capture") ("charge_level_3_heavy")}
	{"mk4"				("armored_capture") ("charge_level_3_heavy")}
;level_4
	{"pz6h"				("armored_capture") ("charge_level_4_heavy")}
	{"kv1e"				("armored_capture") ("charge_level_4_heavy")}
	{"kv2"				("armored_capture") ("charge_level_4_heavy")}
	{"kv1s"				("armored_capture") ("charge_level_4_heavy")}
	{"kv85"				("armored_capture") ("charge_level_4_heavy")}
	{"kv1_zis5"			("armored_capture") ("charge_level_4_heavy")}
;level_5
	{"pz6e"				("armored_capture") ("charge_level_5_heavy")}
	{"kv8"				("armored_capture") ("charge_level_5_heavy")}
	{"m26"				("armored_capture") ("charge_level_5_heavy")}
	{"is1"				("armored_capture") ("charge_level_5_heavy")}
	{"centurion"		("armored_capture") ("charge_level_5_heavy")}
	{"chi-ri"			("armored_capture") ("charge_level_5_heavy")}
;level_6
	{"pz6b"				("armored_capture") ("charge_level_6_heavy")}
	{"pz6bh"			("armored_capture") ("charge_level_6_heavy")}
	{"is2_44"			("armored_capture") ("charge_level_6_heavy")}
	{"is2_early"		("armored_capture") ("charge_level_6_heavy")}
	{"is2"				("armored_capture") ("charge_level_6_heavy")}
	{"is3"				("armored_capture") ("charge_level_6_heavy")}
	{"t29"				("armored_capture") ("charge_level_6_heavy")}
	{"m26e4"			("armored_capture") ("charge_level_6_heavy")}
;[SPG]______________________________________________________________________________________________________________________________________________________________________
;level_2
	{"sdkfz251_9"		("armored_capture")}
;level_3
	{"m8"				("armored_capture")}
	{"stug3b"			("armored_capture")}
	{"sdkfz124"			("armored_capture")}
;level_4
	{"stuh42"			("armored_capture") ("charge_level_4")}
	{"su122"			("armored_capture") ("charge_level_4")}
	{"m7"				("armored_capture") ("charge_level_4_light")}
	{"sturmpz1"			("armored_capture") ("charge_level_4_light")}
;level_5
	{"brumbar"			("armored_capture") ("charge_level_5")}
	{"hummel"			("armored_capture") ("charge_level_5_light")}
	{"su152"			("armored_capture") ("charge_level_5")}	
	{"m12gmc"			("armored_capture") ("charge_level_5_light")}
;level_6
	{"sturmtiger"		("armored_capture") ("charge_level_6_heavy")}
	{"karlthor"			("armored_capture") ("charge_level_6_heavy")}
;[Tank_Hunter]______________________________________________________________________________________________________________________________________________________________________
;level_2
	{"pzjager1"			("armored_capture")}
	{"dodgewc51_m6"		("armored_capture")}
;level_3
	{"su76"				("armored_capture")}
	{"marder2"			("armored_capture")}
	{"marder3"			("armored_capture")}
	{"zis_30"			("armored_capture")}
	{"m1_t48"			("armored_capture")}
;level_4
	{"hetzer"			("armored_capture") ("charge_level_4_light")}
	{"stug3g"			("armored_capture") ("charge_level_4")}
	{"jagdpanzer"		("armored_capture") ("charge_level_4")}
	{"stug3f"			("armored_capture") ("charge_level_4")}
	{"sdkfz251_22"		("armored_capture") ("charge_level_4_light")}
	{"su85"				("armored_capture") ("charge_level_4")}
	{"m18"				("armored_capture") ("charge_level_4_light")}
	{"m10wolverine"		("armored_capture") ("charge_level_4")}
;level_5
	{"stug4g"			("armored_capture") ("charge_level_5")}
	{"nashorn"			("armored_capture") ("charge_level_5_light")}
	{"jagdpanzer_iv"	("armored_capture") ("charge_level_5")}
	{"jagdpanzer_iv_wacher"	("armored_capture") ("charge_level_5")}
	{"su100"			("armored_capture") ("charge_level_5")}
	{"m36"				("armored_capture") ("charge_level_5")}
;level_6
	{"elefant"			("armored_capture") ("charge_level_6_heavy")}
	{"ferdinand"		("armored_capture") ("charge_level_6_heavy")}
	{"jagdpanther"		("armored_capture") ("charge_level_6")}
	{"jagdtiger"		("armored_capture") ("charge_level_6_heavy")}
	{"isu122"			("armored_capture") ("charge_level_6_heavy")}
	{"isu152"			("armored_capture") ("charge_level_6_heavy")}
	{"t95"				("armored_capture") ("charge_level_6_heavy")}	
}