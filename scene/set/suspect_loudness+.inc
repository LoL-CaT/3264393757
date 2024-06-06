(define "suspect_loudness_inc"
		{if props "sturmtiger" (* %0 5)}
		{if props "tank_hunt" "howitzer" "reactive_artyllery" (* %0 2)}
		("mortar75_100" args %0 1.25)
		("mortar101_plus" args %0 1.5)
		("cal75_100" args %0 2.0)
		("cal101_plus" args %0 2.0)
		("aa_cannon" args %0 2)
	;default
		{if props "cannon" (* %0 2.0)}
		{if props "tank" (* %0 2)}
		{if props "sdkfz251_6" (* %0 2)}
		{if weapon "g41" "mosin_s" "m1903a4" "g43_s" "svt40_sniper" "garand_sniper"	(* %0 1.8)}
		{if weapon "mosin_pb_s"	(* %0 1)}		
		{if weapon "at_rifle" "rifle_grenade" "berdan2" "berdan2a" "panzershreck" "bazooka" "panzerfaust150" "panzerfaust100" "panzerfaust" "uber_bazooka" "piatrocket"	(* %0 2)}
)
(define "suspect_loudness_dec+"
;===============VEHICLE==============
	{if props "vehicle"
		{if props "cannon"
			{if weapon "76mm_f22"																	("75to85"			cam(%0) re(6.75))}
			{if weapon "76mm_zis3"																	("75to85"			cam(%0) re(6.5))}
			{if weapon "76mm_pak36r_stan"															("75to85"			cam(%0) re(7))}
			{if weapon "76mm_1943" "76mm_1927" "75mm_lelg18"										("75to85"			cam(%0) re(6.5))}		
		;---------------------------Howitzers----------------------------
		;light
			{if weapon "75mm_m2_how"																("75to85"			cam(%0) re(6.8))}
		;medium
			{if weapon "105mm_lefh18" 																	("101more"			cam(%0) re(8.0))}
			{if weapon "105mm_m2a1_stan"																	("101more"			cam(%0) re(8.0))}				
			{if weapon "122mm_m30"																	("101more"			cam(%0) re(8.0))}
		;heavy
			{if weapon "155mm_m114" 													("101more"			cam(%0) re(14.0))}				
			{if weapon "152mm_ml20"																	("101more"			cam(%0) re(14.0))}
			{if weapon "152mm_d1" 																			("101more"			cam(%0) re(14.0))}				
			{if weapon "150mm_sig33_stan"												("101more"			cam(%0) re(14.0))}
			{if weapon "152mm_m1909" 														("101more"			cam(%0) re(16.0))}				
		;super heavy
			{if weapon "203mm_gun"																	("101more"			cam(%0) re(20.0))}
			{if weapon "210mm_mrs18"																("101more"			cam(%0) re(20.0))}
			{if weapon "203mm_m1"																	("101more"			cam(%0) re(20.0))}				
		};cannon

	;===============TANK==============
		{if props "tank"
		;---------------------------Howitzers SPG-----------------------
			{if weapon "75mm_m2_how_vh"																("75to85"			cam(%0) re(6.8))}				
			{if weapon "105mm_lefh18_wespe" "105mm_stuh42" "105mm_m2a1"								("101more"			cam(%0) re(12.0))}
			{if weapon "105mm_m2a1"																	("101more"			cam(%0) re(12))}				
			{if weapon "122mm_m30s"																	("101more"			cam(%0) re(12.0))}
			{if weapon "105mm_m4"																	("101more"			cam(%0) re(12))}
		;---------------------------Tank Hunt----------------------------
		;light
			{if weapon "76mm_pak36r"																("75to85"			cam(%0) re(7.0))}
			{if weapon "76mm_su76"																	("75to85"			cam(%0) re(7.5))}
		;heavy
			{if weapon "152mm_ml20a"																("101more"			cam(%0) re(16))}
			{if weapon "152mm_ml20a_su152"															("101more"			cam(%0) re(18))}				
			
			{if weapon "152mm_m10t"																	("101more_kv"		cam(%0) re(20.0))}
			
			{if weapon "122mm_d25"																	("101more_div"		cam(%0) re(15))}
			};tank
	};vehicle	
)
