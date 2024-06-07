;--LOUDNESS_INC--
	(define "cal75_100"
		{if props	"pak40" "sdkfz251_22" "zis3" "m5" "1943_cannon"
					"lelg18" "1927_cannon" "pak43" "bs3"
		(* %0 %1)
		}
	)
	(define "cal101_plus"
		{if props	"lg_40"	(* %0 %1 1.2)}
	)
	(define "mortar75_100"
		{if props	"sgrw34" "bm37" "m1mortar" "sdkfz251m" (* %0 %1)}
	)
	(define "mortar101_plus"
		{if props	"sgrw42" "pm41" "m2mortar107mm"	(* %0 %1)}
	)
	(define "aa_cannon"
		{if props "flak18" "flak18_stan" "52k" "29k" "m2cannon90mm" (* %0 %1)}
	)
	(define "suspect_loudness_inc"
		{if props "sturmtiger" (* %0 5)}
		{if props "tank_hunt" "howitzer" "reactive_artyllery" (* %0 2)}
		("mortar75_100" args %0 1.25)
		("mortar101_plus" args %0 1.5)
		("cal75_100" args %0 1.5)
		("cal101_plus" args %0 1.75)
		("aa_cannon" args %0 2)
	;default
		{if props "cannon" (* %0 1)}
		{if props "tank" (* %0 2)}
		{if props "sdkfz251_6" (* %0 2)}
		{if weapon "g41" "mosin_s" "m1903a4" "g43_s" "svt40_sniper" "garand_sniper"	(* %0 1.8)}
		{if weapon "mosin_pb_s"	(* %0 1)}		
		{if weapon "at_rifle" "rifle_grenade" "berdan2" "berdan2a" "panzershreck" "bazooka" "panzerfaust150" "panzerfaust100" "panzerfaust" "uber_bazooka" "piatrocket" "flaergun"	(* %0 2)}
	)
;--LOUDNESS_DEC--
	;cam - коэффициент камуфл€жа
	;3 секунды - опорное значение перезарядки орудия для текущих настроек засвета и шума.
	;cal - делитель в зависимости от калибра: [75-85]=1.1  [86-100]=1.15 [101+]=1.2
	;div - делитель для юнитов, которые характерны быстрым засветом; используется для того, чтобы они дольше оставались видимы
	;re - время перезарядки, сек.
	;re_k - коэффциент времени перезарядки(учет коэф. в дефайне "rt")
	;s - размер магазина
	;ry - время между выстрелами, сек.
	(define "base_formula"
		(* %cam (/ 3 %cal %div (+ (* %re %re_k) (* %s %ry))))
	)
	(define "74less"			("base_formula" cam(%cam) re(%re) re_k(1.2) s(1) ry(0) cal(1) div(1)))
	(define "74less_mortar"		("base_formula" cam(%cam) re(%re) re_k(1) s(1) ry(0) cal(1) div(1)))
	(define "75to85"			("base_formula" cam(%cam) re(%re) re_k(1.2) s(1) ry(0) cal(1.1) div(1)))
	(define "75to85_mortar"		("base_formula" cam(%cam) re(%re) re_k(1) s(1) ry(0) cal(1.1) div(1)))
	(define "86to100"			("base_formula" cam(%cam) re(%re) re_k(1.2) s(1) ry(0) cal(1.15) div(1)))
	(define "101more"			("base_formula" cam(%cam) re(%re) re_k(1.2) s(1) ry(0) cal(1.2) div(1)))
	(define "101more_mortar" 	("base_formula" cam(%cam) re(%re) re_k(1) s(1) ry(0) cal(1.2) div(1)))
	
	(define "74less_s"			("base_formula" cam(%cam) re(%re) re_k(1.2) s(%s) ry(%ry) cal(1) div(1)))
		
	(define "mgun_s"			("base_formula" cam(%cam) re(%re) re_k(1) s(%s) ry(%ry) cal(1) div(1)))

	(define "signal"			("base_formula" cam(%cam) re(%re) re_k(1) s(1) ry(0) cal(1) div(4.25)))
	
	(define "74less_div"		("base_formula" cam(%cam) re(%re) re_k(1.2) s(1) ry(0) cal(1) div(1.25)))
	(define "75to85_div"		("base_formula" cam(%cam) re(%re) re_k(1.2) s(1) ry(0) cal(1.1) div(1.25)))
	(define "75to85_kv"			("base_formula" cam(%cam) re(%re) re_k(1.2) s(1) ry(0) cal(1.1) div(1.43)))
	(define "86to100_div"		("base_formula" cam(%cam) re(%re) re_k(1.2) s(1) ry(0) cal(1.15) div(1.25)))
	(define "101more_div"		("base_formula" cam(%cam) re(%re) re_k(1.2) s(1) ry(0) cal(1.2) div(1.25)))
	(define "101more_kv"		("base_formula" cam(%cam) re(%re) re_k(1.2) s(1) ry(0) cal(1.2) div(1.43)))
	
	(define "74less_div_s"			("base_formula" cam(%cam) re(%re) re_k(1.2) s(%s) ry(%ry) cal(1) div(1.25)))
	(define "75to85_div_s"			("base_formula" cam(%cam) re(%re) re_k(1.2) s(%s) ry(%ry) cal(1.1) div(1.25)))
	(define "101more_rocket_div_s"	("base_formula" cam(%cam) re(%re) re_k(1) 	s(%s) ry(%ry) cal(1.2) div(1.25)))
	
	(define "mgun_div_s"		("base_formula" cam(%cam) re(%re) re_k(1) s(%s) ry(%ry) cal(1) div(1.25)))
	(define "flame_div_s"		("base_formula" cam(%cam) re(%re) re_k(1) s(%s) ry(%ry) cal(1) div(0.25)))
	(define "weapon_div_s"		("base_formula" cam(%cam) re(%re) re_k(1) s(%s) ry(%ry) cal(1) div(0.25)))
	(define "flamer_div_s"		("base_formula" cam(%cam) re(%re) re_k(1) s(%s) ry(%ry) cal(1) div(0.2)))
	
    (define "suspect_loudness_dec+")
	(define "suspect_loudness_dec"
	;===============VEHICLE==============
		{if props "vehicle"
		;==============MGUN(not stan)================
			{if weapon "mg34" "mg34_vh_car" "mg34_tower"												("mgun_div_s"		cam(%0) re(2.5)		s(100)	ry(0.1))}
			{if weapon "mg42"																			("mgun_div_s"		cam(%0) re(3)		s(50)	ry(0.05))}
			{if weapon "browning_m19_vh_car" "browning_m19" "browning_m19_x2" "ds_vh_car"				("mgun_div_s"		cam(%0) re(7)		s(250)	ry(0.1))}
			{if weapon "maxim_inv"																		("mgun_div_s"		cam(%0) re(4)		s(250)	ry(0.1))}
			{if weapon "dp"																				("mgun_div_s"		cam(%0) re(4)		s(47)	ry(0.12))}
			{if weapon "bar"																			("mgun_div_s"		cam(%0) re(2.5)		s(20)	ry(0.12))}
			{if weapon "type99lmg" "type99_vh_car" "type99_vh"											("mgun_div_s"		cam(%0) re(2.5)		s(30)	ry(0.12))}
			{if weapon "browning" "browning_b17"														("mgun_div_s"		cam(%0) re(3.5)		s(200)	ry(0.1))}
			{if weapon "mg37t"																			("mgun_div_s"		cam(%0) re(5.5)		s(225)	ry(0.12))}
			{if weapon "mg34_vh" "ds" "ds_vh"															("mgun_div_s"		cam(%0) re(6)		s(250)	ry(0.1))}
			{if weapon "mg42_vh"																		("mgun_div_s"		cam(%0) re(2.5)		s(250)	ry(0.05))}
			{if weapon "browning_x2"																	("mgun_div_s"		cam(%0) re(6)		s(200)	ry(0.05))}
			{if weapon "dt" "dt_vh" "dt_aa"																("mgun_div_s"		cam(%0) re(4.5)		s(63)	ry(0.1))}
			{if weapon "vickers_mgun_vh"																("mgun_div_s"		cam(%0) re(4)		s(250)	ry(0.13))}
			{if weapon "bren_vh"																		("mgun_div_s"		cam(%0) re(4.5)		s(100)	ry(0.12))}
		;===============OTHER adjacent===============
			{if weapon "flame_thrower_ssd"																("flame_div_s"		cam(%0) re(2)		s(200)	ry(2))}
			{if weapon "flame_thrower_ks24" "flame_thrower_251"											("flame_div_s"		cam(%0) re(2)		s(200)	ry(1.5))}
			{if weapon "flame_thrower_zippo"															("flame_div_s"		cam(%0) re(2)		s(200)	ry(1))}
			{if weapon "flame_thrower_ato41"															("flame_div_s"		cam(%0) re(3)		s(200)	ry(2))}
			{if weapon "80mm_sgrw34"																	("75to85_mortar"	cam(%0)	re(5))}
			{if weapon "37mm_m6"																		("74less_div"		cam(%0) re(4))}
			{if weapon "28mm_pzb41"																		("74less"			cam(%0) re(2.8))}
		;===============AA cannon + marine===========
			{if weapon "88mm_flak18"																	("86to100"			cam(%0) re(7))}
			{if weapon "90mm_m2"																		("86to100"			cam(%0) re(9))}
		;===============Flaks + marine===============
			{if weapon "20mm_flak38_x4_stan"															("74less_s"			cam(%0) re(4.15)	s(80)	ry(0.08))}
			{if weapon "20mm_oerlikon"																	("74less_s"			cam(%0) re(3.75)	s(30)	ry(0.1))}
			{if weapon "40mm_bofors"																	("74less_s"			cam(%0) re(1.5)		s(4)	ry(0.3))}
			{if weapon "calliope_16"																	("101more_rocket_div_s"	cam(%0) re(35)		s(16)	ry(0.15))}
		;===============CANNON==============
			{if props "cannon"
				{if props "mg_stan"
					{if weapon "browning_stan"															("mgun_div_s"		cam(%0) re(3.5)		s(200)	ry(0.1))}
					{if weapon "type99lmg_stan"															("mgun_div_s"		cam(%0) re(2.5)		s(30)	ry(0.12))}
					{if weapon "mg34_stan"																("mgun_div_s"		cam(%0) re(2.5)		s(30)	ry(0.12))}					
					{if weapon "mg42_stan"																("mgun_div_s"		cam(%0) re(2.5)		s(250)	ry(0.05))}
					{if weapon "browning_m19_stan"														("mgun_div_s"		cam(%0) re(7)		s(250)	ry(0.1))}
					{if weapon "ds_stan"																("mgun_div_s"		cam(%0) re(6)		s(250)	ry(0.1))}
					{if weapon "maxim"																	("mgun_div_s"		cam(%0) re(8)		s(250)	ry(0.025))}
					{if weapon "maxim_inv"																("mgun_div_s"		cam(%0) re(4)		s(250)	ry(0.1))}
					{if weapon "dshk_stan"																("mgun_div_s"		cam(%0) re(3.5)		s(50)	ry(0.1))}
				}

			;-------------------------Mortars--------------------------------
				{if weapon "50mm_legrw36" "50mm_rm38"													("74less_mortar"	cam(%0) re(5))}
				{if weapon "60mm_m2"																	("74less_mortar"	cam(%0) re(6))}
				{if weapon "82mm_bm37" "81mm_m1"														("75to85_mortar"	cam(%0) re(5))}
				{if weapon "120mm_sgrw42" "120mm_pm41" "107mm_m2"										("101more_mortar"	cam(%0) re(8))}

			;---------------------------Flaks--------------------------------
				{if weapon "20mm_flak38_stan"															("74less_s"			cam(%0) re(1.625)	s(20)	ry(0.11))}
				{if weapon "37mm_61-k" "37mm_m1"																	("74less_s"			cam(%0) re(1)		s(5)	ry(0.35))}
				{if weapon "browning_x4_stan"															("mgun_s"			cam(%0) re(6)		s(200)	ry(0.03))}		;hmgun 12mm =maxson
				{if weapon "browning_x2_stan"															("mgun_s"			cam(%0) re(4)		s(200)	ry(0.05))}
			;---------------------------Cannons------------------------------
			;light
				{if weapon "37mm_pak35"																	("74less"			cam(%0) re(3.375))}
				{if weapon "37mm_m3"																	("74less"			cam(%0) re(3.5))}
				{if weapon "42mm_pak41"																	("74less"			cam(%0) re(3.75))}
				{if weapon "45mm_m42"																	("74less"			cam(%0) re(4))}
				{if weapon "45mm_53k"																	("74less"			cam(%0) re(3.5))}
				{if weapon "47mm_pak37t"																("74less"			cam(%0) re(4.375))}
			;medium
				{if weapon "50mm_pak38"																	("74less"			cam(%0) re(4.8))}
				{if weapon "57mm_oqf"																	("74less"			cam(%0) re(3.7))}; *такое же оружие у mk6
				{if weapon "57mm_zis2"																	("74less"			cam(%0) re(5.5))}
				{if weapon "75mm_pak40"																	("75to85"			cam(%0) re(5.125))}
				{if weapon "76mm_f22"																	("75to85"			cam(%0) re(5.75))}
				{if weapon "76mm_zis3"																	("75to85"			cam(%0) re(5.5))}
				{if weapon "76mm_pak36r_stan"															("75to85"			cam(%0) re(6))}
				{if weapon "76mm_m5"																	("75to85"			cam(%0) re(5.8))}
				;field
				{if weapon "76mm_1943" "76mm_1927" "75mm_lelg18"										("75to85"			cam(%0) re(5.5))}
				{if weapon "105mm_lg40"																	("75to85_div"		cam(%0) re(9))}
			;heavy
				{if weapon "88mm_pak43"																	("86to100"			cam(%0) re(7.625))}
				{if weapon "100mm_bs3"																	("86to100"			cam(%0) re(8))}
				{if weapon "105mm_sk18"																	("101more"			cam(%0) re(12))}
			;AA cannon
				{if weapon "85mm_52k"																	("75to85"			cam(%0) re(5))}

			;---------------------------Howitzers----------------------------
			;light
				{if weapon "75mm_m2_how"																("75to85"			cam(%0) re(5.8))}
			;medium
				{if weapon "105mm_lefh18" 																	("101more"			cam(%0) re(5.88))}
				{if weapon "105mm_m2a1_stan"																	("101more"			cam(%0) re(6.3))}				
				{if weapon "122mm_m30"																	("101more"			cam(%0) re(6.613))}
			;heavy
				{if weapon "150mm_sfh18" 														("101more"			cam(%0) re(14))}
				{if weapon "155mm_m114" 													("101more"			cam(%0) re(14.2))}				
				{if weapon "152mm_ml20"																	("101more"			cam(%0) re(16.25))}
				{if weapon "152mm_m1909_x2"																("101more"			cam(%0) re(19.5937))}
				{if weapon "152mm_d1" 																			("101more"			cam(%0) re(14.75))}				
				{if weapon "150mm_sig33_stan"												("101more"			cam(%0) re(13.0625))}
				{if weapon "152mm_m1909" 														("101more"			cam(%0) re(16.5937))}				
			;super heavy
				{if weapon "203mm_gun"																	("101more"			cam(%0) re(16.875))}
				{if weapon "210mm_mrs18"																("101more"			cam(%0) re(15.775))}
				{if weapon "203mm_m1"																	("101more"			cam(%0) re(15.475))}				
			;-----------------------------РСЗО-------------------------------
				{if weapon "nebel41" "nebel"														("101more_rocket_div_s"	cam(%0) re(30)		s(6)	ry(1))}	;re(180)
			};cannon

		;===============CAR================
			{if props "car"
			;-----------------------------AA car---------------------------
				{if weapon "76mm_29k"																	("75to85"			cam(%0) re(5.875))}
				{if weapon "dshk_x3"																	("mgun_div_s"		cam(%0) re(6)		s(150)	ry(0.05))}
			;-----------------------------MGUN|AT-----------------------------
				{if weapon "doublebazooka"																("mgun_div_s"		cam(%0) re(10)		s(2)	ry(1))}
			;-----------------------------РСЗО-----------------------------
				{if weapon "katusha"																("101more_rocket_div_s"	cam(%0) re(40)		s(16)	ry(0.43))}	;310mm re(240)
			};car

		;===============TANK==============
			{if props "tank"
			;---------------------------Howitzers SPG-----------------------
				{if weapon "75mm_stuk37"																("75to85"			cam(%0) re(7.0))}
				{if weapon "75mm_m2_how_vh"																("75to85"			cam(%0) re(5.8))}				
				{if weapon "75mm_kwk37_how" 															("75to85"			cam(%0) re(5.5))}
				{if weapon "150mm_sig33"																("101more"			cam(%0) re(18))}
				{if weapon "105mm_lefh18_wespe" "105mm_stuh42" "105mm_m2a1"								("101more"			cam(%0) re(8.1))}
				{if weapon "105mm_m2a1"																	("101more"			cam(%0) re(9))}				
				{if weapon "122mm_m30s"																	("101more"			cam(%0) re(10.84))}
				{if weapon "105mm_m4"																	("101more"			cam(%0) re(10))}
				{if weapon "75mm_pak40_3_l46"															("75to85"			cam(%0) re(5.225))}
				{if weapon "155mm_m1917" "150mm_sfh18a" "150mm_stuh43"									("101more"			cam(%0) re(14))}
				{if weapon "380mm_rw61"																	("101more_mortar"	cam(%0) re(105))}
			;---------------------------Tank Hunt----------------------------
			;light
				{if weapon "47mm_pak36t"																("74less"			cam(%0) re(2.6))}
				{if weapon "57mm_zis30"																	("74less"			cam(%0) re(5.375))}
				{if weapon "57mm_m1"																	("74less"			cam(%0) re(4.5))}
				{if weapon "76mm_pak36r"																("75to85"			cam(%0) re(6.25))}
				{if weapon "76mm_su76"																	("75to85"			cam(%0) re(6.5))}
				{if weapon "76mm_m1_hellcat"															("75to85"			cam(%0) re(6.5))}
				{if weapon "76mm_m7"																	("75to85"			cam(%0) re(6.5))}
				{if weapon "75mm_pak39"																	("75to85"			cam(%0) re(6.375))}
			;medium
				{if weapon "75mm_stuk40" "75mm_stuk40_l43"												("75to85"			cam(%0) re(6.0))}
				{if weapon "85mm_d5s"																	("75to85"			cam(%0) re(7))}
				{if weapon "88mm_pak43_nashorn"															("86to100"			cam(%0) re(10.625))}
				{if weapon "90mm_m3_slugger"															("86to100"			cam(%0) re(9))}
				{if weapon "75mm_pak42_jagdpz4"															("75to85"			cam(%0) re(7.625))}
				{if weapon "100mm_d10c"																	("86to100"			cam(%0) re(12))}
			;heavy
				{if weapon "105mm_t5e1"																	("101more"			cam(%0) re(10))}			
				{if weapon "128mm_pak44"																("101more"			cam(%0) re(17.25))}
				{if weapon "152mm_ml20a"																("101more"			cam(%0) re(13))}
				{if weapon "152mm_ml20a_su152"															("101more"			cam(%0) re(16))}				
				{if weapon "122mm_a19"																	("101more"			cam(%0) re(12))}
				{if weapon "88mm_pak43_jagdpanther" "88mm_pak43_elefant"								("86to100"			cam(%0) re(10.625))}
			;---------------------------IFV (БМП) mgun----------------------
				{if weapon "signal_smoke"																("signal"			cam(%0) re(20))}
			;---------------------------IFV (БМП) + light tank + medium--------------------------
				{if weapon "37mm_pak35_sdkfz251_10"														("74less_div"		cam(%0) re(4))}
				{if weapon "20mm_kwk30"																	("74less_div_s"		cam(%0) re(1.625)	s(10)	ry(0.11))}
				{if weapon "20mm_breda"																	("74less_div_s"		cam(%0) re(2.5)		s(10)	ry(0.12))}
				{if weapon "45mm_20k"																	("74less_div"		cam(%0) re(4))}
				{if weapon "50mm_kwk39"																	("74less_div"		cam(%0) re(4.8))}
				{if weapon "50mm_pak38_vh"																	("74less_div"		cam(%0) re(5.5))}				
			;------------------------------СЗУ-----------------------------
				{if weapon "20mm_flak38"																("74less_div_s"		cam(%0) re(1.625)	s(20)	ry(0.11))}
				{if weapon "browning_x4"																("mgun_div_s"		cam(%0) re(6)		s(400)	ry(0.025))}
				{if weapon "40mm_m19"																	("74less_div_s"		cam(%0) re(3)		s(8)	ry(0.3))}
				{if weapon "37mm_zsu37"																	("74less_div_s"		cam(%0) re(1.5)		s(5)	ry(0.35))}
				{if weapon "20mm_flak38_x4"																("74less_div_s"		cam(%0) re(4.15)	s(80)	ry(0.08))}
			;--------------------------Light Tank-------------------------
				{if weapon "mg34_x2"																	("mgun_div_s"		cam(%0) re(5)		s(500)	ry(0.01))}
				{if weapon "dshk"																		("mgun_div_s"		cam(%0) re(3.5)		s(50)	ry(0.1))}
				{if weapon "7_92mm_ew141"																("74less_div_s"		cam(%0) re(6)		s(40)	ry(0.15))}
				{if weapon "20mm_tns"																	("74less_div_s"		cam(%0) re(3)		s(58)	ry(0.1))}
				{if weapon "20mm_kwk38"																	("74less_div_s"		cam(%0) re(1.625)	s(10)	ry(0.11))}
				{if weapon "37mm_kwk38(l47)"															("74less_div"		cam(%0) re(3.375))}
				{if weapon "37mm_kwk34t"																("74less_div"		cam(%0) re(3.9))}
				{if weapon "37mm_m5" "37mm_type1_chiri"													("74less_div"		cam(%0) re(4))}
				{if weapon "47mm_40"																	("74less_div"		cam(%0) re(4))}
				{if weapon "75mm_m2"																	("75to85_div"		cam(%0) re(7.5))}
				{if weapon "75mm_m6"																	("75to85_div"		cam(%0) re(8))}
				{if weapon "76mm_kt28"																	("75to85_div"		cam(%0) re(8.375))}
			;--------------------------Medium Tank-------------------------
				{if weapon "50mm_kwk38"																	("74less_div"		cam(%0) re(3.4))}
				{if weapon "76mm_l10"																	("75to85_div"		cam(%0) re(8.225))}
				{if weapon "40mm_oqf2pdr"																("74less_div"		cam(%0) re(4))}
				{if weapon "76mm_l11"																	("75to85_div"		cam(%0) re(8.125))}
				{if weapon "75mm_kwk37"	"75mm_kwk40" "76mm_f34"											("75to85_div"		cam(%0) re(7.0))}
				{if weapon "57mm_zis4"																	("74less_div"		cam(%0) re(5.875))}
				{if weapon "75mm_kwk40(l48)"															("75to85_div"		cam(%0) re(7))}
				{if weapon "75mm_m3"																	("75to85_div"		cam(%0) re(6.3))}
				{if weapon "76mm_m1a2"																	("75to85_div"		cam(%0) re(6.5))}
				{if weapon "76mm_mk4"																	("75to85_div"		cam(%0) re(7.625))}
				{if weapon "85mm_zis53"																	("75to85_div"		cam(%0) re(9))}
				{if weapon "75mm_kwk42"																	("75to85_div"		cam(%0) re(8.25))}
			;--------------------------Heavy Tank------------------------
				{if weapon "45mm_20k_t35"																("74less_div"		cam(%0) re(4))}
				{if weapon "75mm_sa35"																	("75to85_div"		cam(%0) re(8.5))}
				{if weapon "47mm_sa35"																	("74less_div"		cam(%0) re(6))}
				{if weapon "76mm_f32"																	("75to85_div"		cam(%0) re(8.125))}
				{if weapon "57mm_oqf_mk4"																("74less_div"		cam(%0) re(3.7))}
				{if weapon "76mm_zis5"																	("75to85_div"		cam(%0) re(7))}
				{if weapon "152mm_m10t"																	("101more_kv"		cam(%0) re(14.5))}
				{if weapon "85mm_d5t"																	("75to85_div"		cam(%0) re(8.75))
					{if props "kv85"																	("75to85_kv"		cam(%0) re(8.75))}
				}
				{if weapon "88mm_kwk36"																	("86to100_div"		cam(%0) re(9.6))}
				{if weapon "90mm_m3"																	("86to100_div"		cam(%0) re(11))}
				{if weapon "90mm_t15"																	("86to100_div"		cam(%0) re(12))}
				{if weapon "88mm_kwk43"																	("86to100_div"		cam(%0) re(11.5))}
				{if weapon "122mm_d25"																	("101more_div"		cam(%0) re(12))}
				{if weapon "122mm_d25p"																	("101more_div"		cam(%0) re(16.8))}
				{if weapon "105mm_t5e2"																	("101more_div"		cam(%0) re(11))}
				{if weapon "75mm_type5_chiri"															("75to85_div_s"		cam(%0) re(12.5)	s(3)	ry(1.5))}
			;----------------------------РСЗО---------------------------
				{if weapon "panzerwerfer42"															("101more_rocket_div_s"	cam(%0) re(33)		s(10)	ry(0.8))}	;210mm re(200)/6=33
				{if weapon "calliope"																("101more_rocket_div_s"	cam(%0) re(35)		s(60)	ry(0.15))}	;(210/6=35)
			};tank
		};vehicle 
		("suspect_loudness_dec+") ; for realism_mode
	;===============HUMAN==============
		{if props "human"
			{if weapon "piatrocket"   																	("101more_div"		cam(%0) re(3.5)	s(1)	ry(0))}
			{if weapon "panzershreck" "bazooka" "panzerfaust150" "panzerfaust100" "panzerfaust" "uber_bazooka"	("101more_div"		cam(%0) re(4)		s(1)	ry(0))}
			{if weapon "flame_thrower"																	("flamer_div_s"		cam(%0) re(2)		s(200)	ry(1))}
		;----scoped rifle + pistol silence
			{if weapon "g41" "mosin_s" "mosin_pb_s" "m1903a4"											("mgun_div_s"		cam(%0) re(8)		s(5)	ry(4))}
			{if weapon "g43_s"																			("mgun_div_s"		cam(%0) re(3)		s(5)	ry(3))}
			{if weapon "svt40_sniper"																	("mgun_div_s"		cam(%0) re(5)		s(10)	ry(3))}
			{if weapon "garand_sniper"																	("mgun_div_s"		cam(%0) re(3)		s(8)	ry(3))}
			{if weapon "welrod"																			("mgun_div_s"		cam(%0) re(2)		s(6)	ry(0.4))}
			{if weapon "nagan_pb"																		("mgun_div_s"		cam(%0) re(2.5)		s(7)	ry(0.3))}
		;----smg
			{if weapon "mp35"																			("weapon_div_s"		cam(%0)	re(2.5)		s(32)	ry(0.12))}
			{if weapon "mp40"																			("weapon_div_s"		cam(%0) re(2.5)		s(32)	ry(0.1))}
			{if weapon "sten"																			("weapon_div_s"		cam(%0) re(2.55)		s(32)	ry(0.11))}			
			{if weapon "ppsh"																			("weapon_div_s"		cam(%0) re(4)		s(71)	ry(0.08))}
			{if weapon "ppsh_box"																		("weapon_div_s"		cam(%0) re(3)		s(35)	ry(0.08))}			
			{if weapon "pps43"																			("weapon_div_s"		cam(%0) re(3.2)		s(35)	ry(0.1))}
			{if weapon "thompson"																		("weapon_div_s"		cam(%0) re(4)		s(50)	ry(0.1))}
			{if weapon "thompson_m1a1"																	("weapon_div_s"		cam(%0) re(2.45)	s(30)	ry(0.1))}			
			{if weapon "m3a"																			("weapon_div_s"		cam(%0) re(2.5)		s(30)	ry(0.1))}
		;----assault rifle
			{if weapon "avs36"																			("weapon_div_s"		cam(%0) re(4)		s(15)	ry(0.12))}	
			{if weapon "avt40"																			("weapon_div_s"		cam(%0) re(4.3)		s(15)	ry(0.17))}				
			{if weapon "sg44"																			("weapon_div_s"		cam(%0) re(3)		s(30)	ry(0.08))}
			{if weapon "fg42_arena"																		("weapon_div_s"		cam(%0) re(3)		s(20)	ry(0.15))}
		;----carabine
			{if weapon "m1_carbine"																		("weapon_div_s"		cam(%0) re(3)		s(15)	ry(0.4))}
		;----rifle
			{if weapon "mauzer" "mosin"	"mosin_pb" "m1903" "mosin_rifle_m1891" "mauser_g33"				("weapon_div_s"		cam(%0) re(3)		s(5)	ry(1.5))}
			{if weapon "berdan2" "berdan2a"																("weapon_div_s"		cam(%0) re(2.75)		s(1)	ry(0))}
		;----automatic rifle
			{if weapon "g43"																			("weapon_div_s"		cam(%0) re(2.9)		s(10)	ry(0.5))}
			{if weapon "svt40"																			("weapon_div_s"		cam(%0) re(3)		s(10)	ry(0.5))}
			{if weapon "garand"																			("weapon_div_s"		cam(%0) re(3.2)		s(8)	ry(0.5))}
		;----at rifle
			{if weapon "boyes"																			("74less_s"		cam(%0) re(3.5)		s(5)	ry(2))}
			{if weapon "ptrd"																			("74less_s"		cam(%0) re(3.5)		s(1)	ry(0))}
			{if weapon "ptrs"																			("74less_s"		cam(%0) re(7)		s(5)	ry(2.8))}
			{if weapon "pzb39"																			("74less_s"		cam(%0) re(2.5)		s(1)	ry(0))}
			{if weapon "ur"																				("74less_s"		cam(%0) re(5)		s(4)	ry(3))}
			{if weapon "solothurn_s18_1000"																("74less_s"		cam(%0) re(3.5)		s(5)	ry(3))}
			{if weapon "type_97_antitank"																("74less_s"		cam(%0) re(4.5)		s(7)	ry(4))}
		;----rifle grenade
			{if weapon "mosin_mortir"																	("weapon_div_s"		cam(%0) re(6)		s(1)	ry(0))}
			{if weapon "m18recoilless"																	("weapon_div_s"		cam(%0) re(6)		s(1)	ry(0))}
		;----shotgun
			{if weapon "shotgun"																		("weapon_div_s"		cam(%0) re(1.5)		s(2)	ry(1))}
		;----pistol
			{if weapon "valter"																			("weapon_div_s"		cam(%0) re(2.721)	s(7)	ry(0.3))}
			{if weapon "colt"																			("weapon_div_s"		cam(%0) re(2.937)	s(7)	ry(0.3))}
			{if weapon "tt"																				("weapon_div_s"		cam(%0) re(2.86)	s(8)	ry(0.3))}
			{if weapon "nambu"																			("weapon_div_s"		cam(%0) re(2.721)	s(8)	ry(0.3))}
			{if weapon "mauser_c96"																		("weapon_div_s"		cam(%0) re(3)		s(8)	ry(0.2))}
			{if weapon "flaergun"																		("weapon_div_s"		cam(%0) re(3.5)		s(1)	ry(0))}; custom recharge: ~1 sec vision
		;----machine gun
			{if weapon "mg34" "mg34_vh_car" "mg34_tower"												("weapon_div_s"		cam(%0) re(2.5)		s(100)	ry(0.1))}
			{if weapon "mg42"																			("weapon_div_s"		cam(%0) re(3)		s(50)	ry(0.05))}
			{if weapon "dp"																				("weapon_div_s"		cam(%0) re(4)		s(47)	ry(0.12))}
			{if weapon "bar"																			("weapon_div_s"		cam(%0) re(2.5)		s(20)	ry(0.12))}
			{if weapon "m1941"																			("weapon_div_s"		cam(%0) re(2.5)		s(20)	ry(0.1))}
			{if weapon "type99lmg" "type99_vh_car" "type99_vh" "type99lmg_stan"							("weapon_div_s"		cam(%0) re(2.5)		s(30)	ry(0.12))}
			{if weapon "browning_m19_vh_car" "browning_m19" "browning_m19_x2" "ds_vh_car" "browning_m19_inf"		("weapon_div_s"	cam(%0) re(7) s(250) ry(0.1))}
			{if weapon "browning" "browning_b17"														("weapon_div_s"		cam(%0) re(3.5)		s(200)	ry(0.1))}
			{if weapon "browning_x2"																	("weapon_div_s"		cam(%0) re(6)		s(200)	ry(0.05))}
			{if weapon "browning_x4"																	("weapon_div_s"		cam(%0) re(6)		s(200)	ry(0.025))}
			{if weapon "dt" "dt_vh" "dt_aa" 															("weapon_div_s"		cam(%0) re(4.5)		s(63)	ry(0.1))}
			{if weapon "dt_inf"																			("weapon_div_s"		cam(%0) re(4)		s(63)	ry(0.1))}
			{if weapon "ds_vh"																			("weapon_div_s"		cam(%0) re(6)		s(250)	ry(0.1))}
			{if weapon "mg34_vh"																		("weapon_div_s"		cam(%0) re(2.5)		s(250)	ry(0.1))}			
			{if weapon "mg34_x2"																		("weapon_div_s"		cam(%0) re(5)		s(500)	ry(0.01))}
			{if weapon "mg42_vh"																		("weapon_div_s"		cam(%0) re(6)		s(250)	ry(0.05))}
			{if weapon "mg37t"																			("weapon_div_s"		cam(%0) re(5.5)		s(225)	ry(0.12))}
			{if weapon "ds"																				("weapon_div_s"		cam(%0) re(6)		s(250)	ry(0.1))}
			{if weapon "maxim_inv"																		("weapon_div_s"		cam(%0) re(4)		s(250)	ry(0.1))}
			{if weapon "vickers_mgun_vh"																("weapon_div_s"		cam(%0) re(4)		s(250)	ry(0.13))}
			{if weapon "bren_vh"																		("weapon_div_s"		cam(%0) re(4.5)		s(100)	ry(0.12))}
		};human
	)

;--MAIN--
	{loudness_increment_mod 1
		{if camouflaged 0.75
			("suspect_loudness_inc" args 0.75)
		}
		("suspect_loudness_inc" args 1)
	}
	
	{loudness_decrement_mod 1
		{if camouflaged 1.1
			("suspect_loudness_dec" args 1.1)
		}
		("suspect_loudness_dec" args 1)
	}