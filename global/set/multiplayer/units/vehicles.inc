;SDL
;============================ TERRITORY HOLDER ============================
(define "territory_holder_apc"
	{cwe 0}			; capture enemy territory
	{cwa 1.0} 		; hold ally territory / support ally advancement
	{cwn 1.0} 		; capture neutral territory
)
(define "territory_holder_commander_apc"
	{cwe 1.0}		; capture enemy territory
	{cwa 1.5} 		; hold ally territory / support ally advancement
	{cwn 1.0} 		; capture neutral territory
)
(define "territory_holder_tanks"
	{cwe 0.0}		; capture enemy territory
	{cwa 0.0} 		; hold ally territory / support ally advancement
	{cwn 1.0} 		; capture neutral territory
)
(define "territory_holder_tanks_bonus"
	{cwe 0.0}		; capture enemy territory
	{cwa 0.5} 		; hold ally territory / support ally advancement
	{cwn 1.0} 		; capture neutral territory
)
(define "territory_holder_heavy_tanks"
	{cwe 0.0}		; capture enemy territory
	{cwa 2.0} 		; hold ally territory / support ally advancement
	{cwn 1.0} 		; capture neutral territory
)
(define "territory_holder_heavy_tanks_bonus"
	{cwe 0.0}		; capture enemy territory
	{cwa 2.5} 		; hold ally territory / support ally advancement
	{cwn 1.0} 		; capture neutral territory
)
(define "territory_holder_spg"
	{cwe 0.0}		; capture enemy territory
	{cwa 0.0} 		; hold ally territory / support ally advancement
	{cwn 1.0} 		; capture neutral territory
)
(define "territory_holder_gun"
	{cwe 0.1}		; capture enemy territory
	{cwa 2.0} 		; hold ally territory / support ally advancement
	{cwn 1.0} 		; capture neutral territory
)
(define "territory_holder_house"
	{cw		0 50 20 50}	; (range - weight) ...
	{cwe	1.0}		; capture enemy territory
	{cwa	1.0} 		; hold ally territory / support ally advancement
	{cwn	1.0} 		; capture neutral territory
)
(define "territory_holder_bunker"
	{cw		0 50 35 50}	; (range - weight) ...
	{cwe	1.0}		; capture enemy territory
	{cwa	1.0} 		; hold ally territory / support ally advancement
	{cwn	1.0} 		; capture neutral territory
)
(define "territory_holder_сommand_post"
	{cw		0 50 50 50}	; (range - weight) ...
	{cwe	1.0}		; capture enemy territory
	{cwa	1.0} 		; hold ally territory / support ally advancement
	{cwn	1.0} 		; capture neutral territory
)
(define "territory_holder_helper"
	{cw  	20 15 30 0}
	{cwe 	1.0}		; capture enemy territory
	{cwa 	1.0} 		; hold ally territory / support ally advancement
	{cwn 	1.0} 		; capture neutral territory
)
(define "territory_holder_airborne"
	{cwe 0}		; capture enemy territory
	{cwa 0} 		; hold ally territory / support ally advancement
	{cwn 0} 		; capture neutral territory
)
(define "territory_holder_marine"
	{cw  	15 5 20 0}
	{cwe 1.0}		; capture enemy territory
	{cwa 1.0} 		; hold ally territory / support ally advancement
	{cwn 1.0} 		; capture neutral territory
)

;================================ CONTENT =====================================
(define "content_none")
(define "content_v"				{content "* ( arena_mp/%side/tankman:%n )"})
(define "content_v_officer"		{content "* ( arena_mp/%side/tankman:%n arena_mp/%side/tankman_officer:1)"})
(define "content_vs"			{content "* ( arena_mp/%side/artilleryman:%n )"})
(define "content_v_p"			{content "* ( arena_mp/%side/pilot:%n )"})
(define "content_v_ap"			{content "* ( arena_mp/%side/artilleryman_paratrooper:%n )"})
(define "content_opel_mgun"		{content "* ( arena_mp/%side/artilleryman:%n arena_mp/ger/apc_opel_blitz_mgun_commander:1 arena_mp/ger/apc_opel_blitz_mgun_rifle:2 arena_mp/ger/apc_opel_blitz_mgun_smg:2"})
(define "content_opel"			{content "* ( arena_mp/%side/artilleryman:%n arena_mp/ger/apc_opel_blitz_commander:1 arena_mp/ger/apc_opel_blitz_rifle:2 arena_mp/ger/apc_opel_blitz_smg:2"})
(define "content_251_1"			{content "* ( arena_mp/%side/artilleryman:%n arena_mp/ger/apc_251_1_commander:1 arena_mp/ger/apc_251_1_rifle:2 arena_mp/ger/apc_251_1_smg:2"})
(define "content_251_10"		{content "* ( arena_mp/%side/artilleryman:%n arena_mp/ger/apc_251_10_commander:1 arena_mp/ger/apc_251_10_rifle:2 arena_mp/ger/apc_251_10_smg:2"})
(define "content_gmc_inf"			{content "* ( arena_mp/%side/artilleryman:%n arena_mp/%side/apc_gmc_commander:1 arena_mp/%side/apc_gmc_rifle:2 arena_mp/%side/apc_gmc_smg:2"})
(define "content_gaz"			{content "* ( arena_mp/%side/artilleryman:%n arena_mp/%side/apc_gaz_aa_commander:1 arena_mp/%side/apc_gaz_aa_rifle:2 arena_mp/%side/apc_gaz_aa_smg:2"})
(define "content_m3a1"			{content "* ( arena_mp/%side/artilleryman:%n arena_mp/%side/apc_m3a1_commander:1 arena_mp/%side/apc_m3a1_rifle:2 arena_mp/%side/apc_m3a1_smg:2"})
(define "content_m3a2"			{content "* ( arena_mp/%side/artilleryman:%n arena_mp/%side/apc_m3a2_commander:1 arena_mp/%side/apc_m3a2_rifle:2 arena_mp/%side/apc_m3a2_smg:2"})
(define "content_t20"			{content "* ( arena_mp/%side/artilleryman:%n arena_mp/%side/apc_t20_commander:1 arena_mp/%side/apc_t20_rifle:2 arena_mp/%side/apc_t20_smg:2"})
(define "content_u_c_inf_usa"			{content "* ( arena_mp/%side/artilleryman:%n arena_mp/%side/apc_uc_commander:1 arena_mp/%side/apc_uc_rifle:2 arena_mp/%side/apc_uc_smg:2"})
(define "content_m3_ally_g"			{content "* ( arena_mp/%side/guard_driver:1 arena_mp/%side/guard_gunner:1 arena_mp/%side/guard_commander:1 arena_mp/%side/guard_bazooker:1 arena_mp/%side/guard_mgun:1 arena_mp/%side/guard_rifle:2"})
(define "content_m3_g"			{content "* ( arena_mp/%side/guard_driver:1 arena_mp/%side/guard_gunner:1 arena_mp/%side/guard_commander:1 arena_mp/%side/guard_smg:1 arena_mp/%side/guard_mgun:1 arena_mp/%side/guard_rifle:1 arena_mp/%side/guard_sniper:1"})
(define "content_m3_scout"			{content "* ( arena_mp/%side/apc_m3scout_driver:1 arena_mp/%side/apc_m3scout_gunner:3 arena_mp/%side/apc_m3scout_scout:5"})
(define "content_pz4f2_inf"			{content "* ( arena_mp/%side/tankman:5 arena_mp/%side/apc_pz4f2_rifle:1 arena_mp/%side/apc_pz4f2_smg:1 arena_mp/%side/apc_pz4f2_smg:1 arena_mp/%side/apc_pz4f2_rifle:1 arena_mp/%side/apc_pz4f2_commander:1"})
(define "content_t34_76_inf"			{content "* ( arena_mp/%side/tankman:4 arena_mp/%side/apc_t34_76_rifle:1 arena_mp/%side/apc_t34_76_smg:1 arena_mp/%side/apc_t34_76_smg:1 arena_mp/%side/apc_t34_76_rifle:1 arena_mp/%side/apc_t34_76_commander:1"})
(define "content_m4a1_inf"			{content "* ( arena_mp/%side/tankman:4 arena_mp/%side/apc_m4a1_rifle:1 arena_mp/%side/apc_m4a1_smg:1 arena_mp/%side/apc_m4a1_smg:1 arena_mp/%side/apc_m4a1_rifle:1 arena_mp/%side/apc_m4a1_commander:1"})
(define "content_pz4g_inf"			{content "* ( arena_mp/%side/tankman:5 arena_mp/%side/apc_pz4g_grenadier:5"})
(define "content_t34_2_inf"			{content "* ( arena_mp/%side/tankman:4 arena_mp/%side/apc_t34_2_sturmovik:5"})
(define "content_m4a3dd_inf"		{content "* ( arena_mp/%side/tankman:5 arena_mp/%side/apc_m4a3dd_marine:5"})
(define "content_dodgewc51_m2hb"	{content "* ( arena_mp/%side/mp_driver:1 arena_mp/%side/mp_gunner:2 arena_mp/%side/mp_veteran:5"})
(define "content_251d"				{content "* ( arena_mp/%side/tankman:1 arena_mp/%side/artilleryman:2 arena_mp/%side/patrol_commander:1 arena_mp/%side/patrol_saper:1 arena_mp/%side/patrol_mgun:1 arena_mp/%side/patrol_smg:1 arena_mp/%side/patrol_smg2:1"})
;================================== SET =======================================
(define "set_generic"
    {charge %ch}
    ("score" sc(%sc))
    {tags "%tag %side"}
	{side "%side"}
    ("cw_%cw")
    {cp %cp}
	{level %lvl}
	{cost 0}
	{fore 1}
)
(define "set_default"
	("content_%con"		side(%side) n(%n))
	("set_generic"		ch(%ch) sc(%sc) tag(%tag) side(%side) cw(%cw) cp(%cp) lvl(%lvl))
	("spawn_distance_%sd")
	("territory_holder_%th")
)

; vehicle with tankmans
(define "set_v"		("set_default"		con(v) ch(0) sc(%sc) tag(%tag) side(%side) n(%n) cw(%cw) cp(%cp) lvl(%lvl) sd(default) th(%th)))

; vehicle with supporters
(define "set_vs"	("set_default"		con(vs) ch(0) sc(%sc) tag(%tag) side(%side) n(%n) cw(%cw) cp(%cp) lvl(%lvl) sd(default) th(%th)))

; mortars
(define "set_vsm"	("set_default"		con(vs) ch(0) sc(%sc) tag(%tag) side(%side) n(%n) cw(%cw) cp(%cp) lvl(%lvl) sd(mortar) th(%th)))

;btr
(define "set_251_1"	("set_default"		con(251_1) ch(0) sc(%sc) tag(%tag) side(%side) n(%n) cw(%cw) cp(%cp) lvl(%lvl) sd(default) th(%th)))

;техника под управлением лётчиков
(define "set_v_p"	("set_default"		con(v_p) ch(30) sc(%sc) tag(%tag) side(%side) n(%n) cw(s0) cp(0) lvl(%lvl) sd(airborne) th(airborne)))

;-------------------

(define "how_base"
	{"%name(%side)"
   		{charge %ch}
    	("score" sc(%sc))
		{content "%c1 ( arena_mp/%side/artilleryman:%m1 ) %c2 ( arena_mp/%side/artilleryman:%n )"}
		{tags "all cannon heavy_art fixed %side %t"}
		{side "%side"}
		{cost 0}
		{fore 1}
		{info "%c2"}
		{level %lvl}		
		{main "%c2"}
		("spawn_distance_default")
	}
)
(define "airstrike"
	{"%name(%side)"
		{charge 60}		
		{content "%c1 ( arena_mp/%side/pilot:%n )"}
		{tags "all independent_delivery fixed %side %t"}
		{side "%side"}
		{fore 0.3}		
		{actions "air_attack"}
		("spawn_distance_airborne")
		{level %lvl}		
		{main "%c1"}		
	}
)
(define "how"		("how_base" name(%name) side(%side) ch(0) sc(%sc)	c1(%c1) m1(2) c2(%c2) n(%n) t(%t)	lvl(%lvl)))
(define "art_point"	("how_base" name(%name) side(%side) ch(0) sc(%sc)	c1(%c1) m1(2) c2(%c2) n(%n) t(%t)	lvl(%lvl)))

;[MGUN Stan]_________________________________________________________________________________________________________________________________________________________________
;level_1
{"mg34_stan"		("set_vs"	lvl(1)	tag(all sup level_1)	side(ger)	n(2)	sc(3)	cw(s1)	cp(2)	th(gun))}
{"mg34_dot"			("set_vs"	lvl(1)	tag(all sup level_1)	side(ger)	n(1)	sc(3)	cw(s1)	cp(2)	th(gun))}
{"mg34_dot2"		("set_vs"	lvl(1)	tag(all sup level_1)	side(ger)	n(1)	sc(3)	cw(s1)	cp(2)	th(gun))}
{"mg34_tower"		("set_vs"	lvl(1)	tag(all sup level_1)	side(ger)	n(1)	sc(3)	cw(s1)	cp(2)	th(gun))}
{"mg42_stan"		("set_vs"	lvl(1)	tag(all sup level_1)	side(ger)	n(2)	sc(5)	cw(s1)	cp(2)	th(gun))}
{"mg34_sit"			("set_vs"	lvl(1)	tag(all sup level_1)	side(ger)	n(2)	sc(3)	cw(s1)	cp(2)	th(gun))}
{"degtyarev_stan"	("set_vs"	lvl(1)	tag(all sup level_1)	side(rus)	n(2)	sc(3)	cw(s1)	cp(2)	th(gun))}
{"maxim"			("set_vs"	lvl(1)	tag(all sup level_1)	side(rus)	n(1)	sc(3)	cw(s1)	cp(1)	th(gun))}
{"browning_stan"	("set_vs"	lvl(1)	tag(all sup level_1)	side(usa)	n(2)	sc(3)	cw(s1)	cp(2)	th(gun))}
{"vickers_mgun"		("set_vs"	lvl(1)	tag(all sup level_1)	side(eng)	n(2)	sc(3)	cw(s1)	cp(2)	th(gun))}
{"type99_stan"		("set_vs"	lvl(1)	tag(all sup level_1)	side(jap)	n(2)	sc(3)	cw(s1)	cp(2)	th(gun))}
{"maxson"			("set_vs"	lvl(1)	tag(all art_spec level_1)	side(usa)	n(3)	sc(14)	cw(s1)	cp(3)	th(gun))}

;level_2
{"dshk_stan"		("set_vs"	lvl(2)	tag(all sup level_2)		side(rus)	n(2)	sc(7)	cw(s1)	cp(3)	th(gun))}
{"kpvt"				("set_vs"	lvl(2)	tag(all sup level_2)		side(rus)	n(4)	sc(9)	cw(s1)	cp(3)	th(gun))}
{"maxim_quad"		("set_vs"	lvl(2)	tag(all sup level_2)		side(rus)	n(1)	sc(9)	cw(s1)	cp(3)	th(gun))}
{"browning_m2_stan"	("set_vs"	lvl(2)	tag(all sup level_2)		side(usa)	n(2)	sc(9)	cw(s1)	cp(3)	th(gun))}
{"type1hmg_stan"	("set_vs"	lvl(2)	tag(all sup level_2)		side(jap)	n(2)	sc(9)	cw(s1)	cp(3)	th(gun))}


;[Zenite_Autocannon]________________________________________________________________________________________________________________________________________________________
;level_1
{"flak-38-1"		("set_vs"	lvl(1)	tag(all art_spec level_1)	side(ger) n(2)	sc(20)	cw(s1)	cp(2)	th(gun))}
{"kp42"				("set_vs"	lvl(1)	tag(all art_spec level_1)	side(rus) n(4)	sc(1)	cw(s1)	cp(1)	th(gun))}
{"flak38"			("set_vs"	lvl(1)	tag(all art_spec level_1)	side(ger) n(2)	sc(23)	cw(s1)	cp(2)	th(gun))}
{"flak38_platform"	("set_vs"	lvl(1)	tag(all art_spec level_1)	side(ger) n(2)	sc(20)	cw(s1)	cp(2)	th(gun))}
{"flak38_wheeled"	("set_vs"	lvl(1)	tag(all art_spec level_1)	side(ger) n(4)	sc(17)	cw(s1)	cp(3)	th(gun))}
{"20mm_u_boat"		("set_vs"	lvl(1)	tag(all art_spec level_1)	side(ger) n(2)	sc(20)	cw(s1)	cp(3)	th(gun))}
{"oerlikon"			("set_vs"	lvl(1)	tag(all art_spec level_1)	side(usa) n(1)	sc(13)	cw(s1)	cp(3)	th(gun))}
{"mk10"				("set_vs"	lvl(1)	tag(all art_spec level_1)	side(usa) n(2)	sc(20)	cw(s1)	cp(3)	th(gun))}
{"oerlikon_eng"		("set_vs"	lvl(1)	tag(all art_spec level_1)	side(eng) n(1)	sc(13)	cw(s1)	cp(3)	th(gun))}
{"type2_20mm"		("set_vs"	lvl(1)	tag(all art_spec level_1)	side(jap) n(2)	sc(20)	cw(s1)	cp(3)	th(gun))}

;level_2
{"61k"				("set_vs"	lvl(2) tag(all art_spec level_2)	side(rus) n(4)	sc(34)	cw(s1)	cp(5)	th(gun))}
{"m1_aa"				("set_vs"	lvl(2) tag(all art_spec level_2)	side(usa) n(4)	sc(26)	cw(s1)	cp(5)	th(gun))}
;level_3
{"bofors"			("set_vs"	lvl(3) tag(all art_spec level_3)	side(usa) n(4)	sc(37)	cw(s1)	cp(6)	th(gun))}
{"bofors_eng"		("set_vs"	lvl(3) tag(all art_spec level_3)	side(eng) n(4)	sc(37)	cw(s1)	cp(6)	th(gun))}

;[Zenite_Gun]______________________________________________________________________________________________________________________________________________________________
;level_4
{"flak18"			("set_vs"	lvl(4)	tag(all art_spec level_4)	side(ger) n(6) 	sc(42)	cw(s1) cp(6)	th(gun))}
{"flak18_stan"			("set_vs"	lvl(4)	tag(all art_spec level_4)	side(ger) n(6) 	sc(42)	cw(s1) cp(6)	th(gun))}
{"52k"				("set_vs"	lvl(4)	tag(all art_spec level_4)	side(rus) n(6) 	sc(42)	cw(s1) cp(6)	th(gun))}
;level_5
{"m2cannon90mm"		("set_vs"	lvl(4)	tag(all art_spec level_4)	side(usa) n(6) 	sc(57)	cw(s1) cp(7)	th(gun))}


;[Mortars]_________________________________________________________________________________________________________________________________________________________________
;level_1
{"legrw36"			("set_vsm"	lvl(1)	tag(all sup level_1)		side(ger) n(1) 	sc(14)  cw(s1)	cp(1)	th(gun))}
{"rm38"				("set_vsm"	lvl(1)	tag(all sup level_1)		side(rus) n(1) 	sc(14)  cw(s1)	cp(1)	th(gun))}
{"m2mortar"			("set_vsm"	lvl(1)	tag(all sup level_1)		side(usa) n(1) 	sc(14)  cw(s1)	cp(1)	th(gun))}
;level_2	
{"sgrw34"			("set_vsm"	lvl(2)	tag(all sup level_2)		side(ger) n(2) 	sc(25)  cw(s1)	cp(2)	th(gun))}
{"bm37"				("set_vsm"	lvl(2)	tag(all sup level_2)		side(rus) n(2) 	sc(25)  cw(s1)	cp(2)	th(gun))}
{"m1mortar"			("set_vsm"	lvl(2)	tag(all sup level_2)		side(usa) n(2) 	sc(25)  cw(s1)	cp(2)	th(gun))}
;level_3	
{"sgrw42"			("set_vsm"	lvl(3)	tag(all sup level_3)		side(ger) n(2) 	sc(32) cw(s1)	cp(3)	th(gun))}
{"pm41"				("set_vsm"	lvl(3)	tag(all sup level_3)		side(rus) n(2) 	sc(32) cw(s1)	cp(3)	th(gun))}
{"m2mortar107mm"	("set_vsm"	lvl(3)	tag(all sup level_3)		side(usa) n(2) 	sc(31) cw(s1)	cp(3)	th(gun))}

;[Field guns]_______________________________________________________________________________________________________________________________________________________________
;level_2
{"lelg18"			("set_vs"		lvl(2)	tag(all sup level_2)	side(ger)	n(4)	sc(30)	cw(s1)	cp(4)	th(gun))}
{"lg_40"			("set_default"	lvl(2)	tag(all sup level_2)	side(ger)	n(2)	sc(37)	cw(s1)	cp(3)	th(gun)	sd(default)	con(v_ap) ch(0))}
{"spzb41"			("set_vs"		lvl(2)	tag(all sup level_2)	side(ger)	n(2)	sc(10)	cw(s1)	cp(2)	th(gun))}
{"1943_cannon"		("set_vs"		lvl(2)	tag(all sup level_2)	side(rus)	n(4)	sc(30)	cw(s1)	cp(4)	th(gun))}
{"1927_cannon"		("set_vs"		lvl(2)	tag(all sup level_2)	side(rus)	n(4)	sc(28)	cw(s1)	cp(4)	th(gun))}


;[AT_Cannon]________________________________________________________________________________________________________________________________________________________________
;level_1
{"pak35"			("set_vs"	lvl(1) tag(all art_point level_1)	side(ger)	n(4)	sc(12)	cw(s1) cp(2)	th(gun))}
{"53k"				("set_vs"	lvl(1) tag(all art_point level_1)	side(rus)	n(4)	sc(17)	cw(s1) cp(2)	th(gun))}
{"m3cannon"			("set_vs"	lvl(1) tag(all art_point level_1)	side(usa)	n(4)	sc(16)	cw(s1) cp(2)	th(gun))}
;level_2
{"pak41-le"			("set_vs"	lvl(2) tag(all art_point level_2)	side(ger)	n(4)	sc(15)	cw(s1) cp(3)	th(gun))}
{"pak38"			("set_vs"	lvl(2) tag(all art_point level_2)	side(ger)	n(4)	sc(26)	cw(s1) cp(3)	th(gun))}
{"pak37-t"			("set_vs"	lvl(2) tag(all art_point level_2)	side(ger)	n(4)	sc(24)	cw(s1) cp(3)	th(gun))}
{"m42"				("set_vs"	lvl(2) tag(all art_point level_2)	side(rus)	n(4)	sc(20)	cw(s1) cp(3)	th(gun))}
;level_3
{"pak36"			("set_vs"	lvl(3) tag(all art_point level_3)	side(ger)	n(4)	sc(38)	cw(s1) cp(5)	th(gun))}
{"f22"				("set_vs"	lvl(3) tag(all art_point level_3)	side(rus)	n(4)	sc(25)	cw(s1) cp(4)	th(gun))}
{"zis3"				("set_vs"	lvl(3) tag(all art_point level_3)	side(rus)	n(4)	sc(28)	cw(s1) cp(4)	th(gun))}
{"m1"				("set_vs"	lvl(3) tag(all art_point level_3)	side(usa)	n(4)	sc(30)	cw(s1) cp(4)	th(gun))}
;level_4
{"pak40"			("set_vs"	lvl(4) tag(all art_point level_4)	side(ger)	n(4)	sc(48)	cw(s1) cp(5)	th(gun))}
{"sk18"				("set_vs"	lvl(4) tag(all art_point level_4)	side(ger)	n(6)	sc(48)	cw(s1) cp(4)	th(gun))}
{"zis2"				("set_vs"	lvl(4) tag(all art_point level_4)	side(rus)	n(4)	sc(29)	cw(s1) cp(4)	th(gun))}
{"m5"				("set_vs"	lvl(3) tag(all art_point level_4)	side(usa)	n(4)	sc(45)	cw(s1) cp(5)	th(gun))}
;level_5
{"pak43"			("set_vs"	lvl(5) tag(all art_point level_5)	side(ger)	n(4)	sc(64)	cw(s1) cp(7)	th(gun))}
{"bs3"				("set_vs"	lvl(5) tag(all art_point level_5)	side(rus)	n(4)	sc(58)	cw(s1) cp(7)	th(gun))}


;[Howitzer]_________________________________________________________________________________________________________________________________________________________________
;level_1
{"m8_howitzer"		("set_vs"	lvl(1)	tag(all art level_1)	side(usa)	n(4)	sc(36)	cw(s1)	cp(5)	th(gun))}
;level_2
{"lefh18"			("set_vs"	lvl(2)	tag(all art level_2)	side(ger)	n(6)	sc(51)	cw(s1)	cp(6)	th(gun))}
{"m30"				("set_vs"	lvl(2)	tag(all art level_2)	side(rus)	n(6)	sc(56)	cw(s1)	cp(6)	th(gun))}
{"m2a1l"			("set_vs"	lvl(2)	tag(all art level_2)	side(usa)	n(6)	sc(51)	cw(s1)	cp(6)	th(gun))}
;level_3
{"sfh18"			("set_vs"	lvl(3)	tag(all art level_3)	side(ger)	n(6)	sc(68)	cw(s1)	cp(7)	th(gun))}
{"sig33"			("set_vs"	lvl(3)	tag(all art level_3)	side(ger)	n(6)	sc(65)	cw(s1)	cp(7)	th(gun))}
{"ml20"				("set_vs"	lvl(3)	tag(all art level_3)	side(rus)	n(6)	sc(68)	cw(s1)	cp(7)	th(gun))}
{"d1"				("set_vs"	lvl(3)	tag(all art level_3)	side(rus)	n(6)	sc(68)	cw(s1)	cp(7)	th(gun))}
{"m1909"			("set_vs"	lvl(3)	tag(all art level_3)	side(rus)	n(6)	sc(65)	cw(s1)	cp(7)	th(gun))}
{"m114"				("set_vs"	lvl(3)	tag(all art level_3)	side(usa)	n(6)	sc(68)	cw(s1)	cp(7)	th(gun))}
;level_5
{"mrs18"			("set_vs"	lvl(5)	tag(all art level_5)	side(ger)	n(6)	sc(77)	cw(s1)	cp(8)	th(gun))}
{"203b4"			("set_vs"	lvl(5)	tag(all art level_5)	side(rus)	n(6)	sc(77)	cw(s1)	cp(8)	th(gun))}
{"203_m1"			("set_vs"	lvl(5)	tag(all art level_5)	side(rus)	n(6)	sc(77)	cw(s1)	cp(8)	th(gun))}

;[Rocket_Launcher_Stan]_____________________________________________________________________________________________________________________________________________________
;level_4
{"nebelwerfer41"	("set_vs"	lvl(4)	tag(all sup level_4)	side(ger)	n(4)	sc(68)	cw(s1)	cp(8)	th(gun))}
;level_5
{"nebelwerfer42"	("set_vs"	lvl(5)	tag(all sup level_5)	side(ger)	n(4)	sc(77)	cw(s1)	cp(9)	th(gun))}

;[Rocket_Launcher_Vehicle]_____________________________________________________________________________________________________________________________________________________
;level_5
{"bm13"				("set_vs"	lvl(5)	tag(all sup level_5)	side(rus)	n(2)	sc(86)	cw(s2)	cp(11)	th(apc))}
;level_6
{"sdkfz4"			("set_v"	lvl(6)	tag(all sup level_6)	side(ger)	n(4)	sc(106)	cw(s2)	cp(12)	th(apc))}
{"m4a3c"			("set_v"	lvl(6)	tag(all sup level_6)	side(usa)	n(4)	sc(128)	cw(s2)	cp(14)	th(apc))}

;[Moto]_____________________________________________________________________________________________________________________________________________________________________
;level_1
{"r12"				("set_vs"	lvl(1)	tag(all apc level_1 independent_delivery)	side(ger)	n(3)	sc(7)	cw(s2)	cp(2)	th(apc)) {dont_unfog_by_territory}}
{"m72"				("set_vs"	lvl(1)	tag(all apc level_1 independent_delivery)	side(rus)	n(3)	sc(7)	cw(s2)	cp(2)	th(apc)) {dont_unfog_by_territory}}
{"hd"				("set_vs"	lvl(1)	tag(all apc level_1 independent_delivery)	side(usa)	n(3)	sc(7)	cw(s2)	cp(2)	th(apc)) {dont_unfog_by_territory}}
{"type97"			("set_vs"	lvl(1)	tag(all apc level_1 independent_delivery)	side(jap)	n(3)	sc(7)	cw(s2)	cp(2)	th(apc)) {dont_unfog_by_territory}}

;[Car]_____________________________________________________________________________________________________________________________________________________________________
;level_1
{"kubel_mgun"		("set_vs"	lvl(1)	tag(all apc level_1)	side(ger)	n(3)	sc(12)	cw(s2)	cp(3)	th(apc)) {dont_unfog_by_territory}}
{"gaz67b"			("set_vs"	lvl(1)	tag(all apc level_1)	side(rus)	n(3)	sc(12)	cw(s2)	cp(3)	th(apc)) {dont_unfog_by_territory}}
{"willysmb_maxim"	("set_vs"	lvl(1)	tag(all apc level_1)	side(rus)	n(3)	sc(12)	cw(s2)	cp(3)	th(apc)) {dont_unfog_by_territory}}
{"willysmb"			("set_vs"	lvl(1)	tag(all apc level_1)	side(usa)	n(3)	sc(12)	cw(s2)	cp(3)	th(apc)) {dont_unfog_by_territory}}
;level_2
{"willysat"			("set_vs"	lvl(2)	tag(all apc level_2)	side(usa)	n(2)	sc(20)	cw(s2)	cp(4)	th(apc)) {dont_unfog_by_territory}}
{"willysat_mgun"	("set_vs"	lvl(2)	tag(all apc level_2)	side(usa)	n(3)	sc(17)	cw(s2)	cp(3)	th(apc)) {dont_unfog_by_territory}}
;level_4
{"dodgewc51_m2hb"	("set_default" 	lvl(4)	tag(all apc level_4)	side(usa)	n(1)	sc(12)	cw(s2)	cp(3)	th(apc)	sd(default)	con(dodgewc51_m2hb)	ch(0)) {dont_unfog_by_territory}}

;[Car Carrier]_______________________________________________________________________________________________________________________________________________________________
;level_1
{"kubel"			("set_vs"	lvl(1)	tag(carrier level_1 independent_delivery)	side(ger)	n(1)	sc(3)	cw(s2)	cp(0)	th(spg))}
{"kettenkrad"		("set_vs"	lvl(1)	tag(carrier level_1 independent_delivery)	side(ger)	n(1)	sc(3)	cw(s2)	cp(0)	th(spg)) {dont_unfog_by_territory}}
{"gaz67"			("set_vs"	lvl(1)	tag(carrier level_1 independent_delivery)	side(rus)	n(1)	sc(3)	cw(s2)	cp(0)	th(spg))}
{"dodge"			("set_vs"	lvl(1)	tag(carrier level_1 independent_delivery)	side(usa)	n(1)	sc(3)	cw(s2)	cp(0)	th(spg))}
{"willysmb_tent"	("set_vs"	lvl(1)	tag(carrier level_1 independent_delivery)	side(usa)	n(1)	sc(3)	cw(s2)	cp(0)	th(spg))}

;[Truck]_____________________________________________________________________________________________________________________________________________________________________
;level_1
{"blitz3_6art"		("set_vs"	lvl(1)	tag(carrier level_1 independent_delivery)	side(ger)	n(2)	sc(3)	cw(s2)	cp(0)	th(spg))}
{"blitz3_6eng"		("set_vs"	lvl(1)	tag(carrier level_1 independent_delivery)	side(ger)	n(2)	sc(3)	cw(s2)	cp(0)	th(spg))}
{"blitz3_6f"		("set_vs"	lvl(1)	tag(carrier level_1 independent_delivery)	side(ger)	n(2)	sc(3)	cw(s2)	cp(0)	th(spg))}
{"opel_blitz"		("set_vs"	lvl(1)	tag(carrier level_1 independent_delivery)	side(ger)	n(2)	sc(3)	cw(s2)	cp(0)	th(spg))}
{"opel_blitz_supp"		("set_vs"	lvl(1)	tag(carrier level_1 independent_delivery)	side(ger)	n(2)	sc(3)	cw(s2)	cp(0)	th(spg))}
{"zis5art"			("set_vs"	lvl(1)	tag(carrier level_1 independent_delivery)	side(rus)	n(2)	sc(3)	cw(s2)	cp(0)	th(spg))}
{"gaz_aa"			("set_vs"	lvl(1)	tag(carrier level_1 independent_delivery)	side(rus)	n(2)	sc(3)	cw(s2)	cp(0)	th(spg))}
{"gaz_aa_supp"			("set_vs"	lvl(1)	tag(carrier level_1 independent_delivery)	side(rus)	n(2)	sc(3)	cw(s2)	cp(0)	th(spg))}
{"gaz_aa_untented_fuel"		("set_vs"	lvl(1)	tag(carrier level_1 independent_delivery)	side(rus)	n(2)	sc(3)	cw(s2)	cp(0)	th(spg))}
{"gaz_aa_fuel"			("set_vs"	lvl(1)	tag(carrier level_1 independent_delivery)	side(rus)	n(2)	sc(3)	cw(s2)	cp(0)	th(spg))}
{"gmc_inf_fuel"			("set_vs"	lvl(1)	tag(carrier level_1 independent_delivery)	side(usa)	n(2)	sc(3)	cw(s2)	cp(0)	th(spg))}
{"gmc_fuel"			("set_vs"	lvl(1)	tag(carrier level_1 independent_delivery)	side(usa)	n(2)	sc(3)	cw(s2)	cp(0)	th(spg))}
{"opel_blitz_highback_fuel"	("set_vs"	lvl(1)	tag(carrier level_1 independent_delivery)	side(ger)	n(2)	sc(3)	cw(s2)	cp(0)	th(spg))}
{"opel_blitz_fuel"		("set_vs"	lvl(1)	tag(carrier level_1 independent_delivery)	side(ger)	n(2)	sc(3)	cw(s2)	cp(0)	th(spg))}
{"gmc_art"			("set_vs"	lvl(1)	tag(carrier level_1 independent_delivery)	side(usa)	n(2)	sc(3)	cw(s2)	cp(0)	th(spg))}
{"gmc"			("set_vs"	lvl(1)	tag(carrier level_1 independent_delivery)	side(usa)	n(2)	sc(3)	cw(s2)	cp(0)	th(spg))}
{"gmc_supp"			("set_vs"	lvl(1)	tag(carrier level_1 independent_delivery)	side(usa)	n(2)	sc(3)	cw(s2)	cp(0)	th(spg))}
;level_2
{"blitz3_6_mgun"	("set_vs"	lvl(2)	tag(carrier level_2 independent_delivery)	side(ger)	n(2)	sc(2)	cw(s2)	cp(1)	th(spg))}
;{"opel_blitz_mgun"	("set_vs"	lvl(2)	tag(carrier level_2 independent_delivery)	side(ger)	n(2)	sc(2)	cw(s2)	cp(1)	th(spg))}; дублирует [APC]

;Medic car
{"blitz3_6m"		("set_vs"	lvl(1)	tag(carrier level_1 independent_delivery)	side(ger)	n(2)	sc(1)	cw(s2)	cp(0)	th(spg))}
{"opel_blitz_med"	("set_vs"	lvl(1)	tag(carrier level_1 independent_delivery)	side(ger)	n(2)	sc(1)	cw(s2)	cp(0)	th(spg))}
{"gaz_aa_med"		("set_vs"	lvl(1)	tag(carrier level_1 independent_delivery)	side(rus)	n(2)	sc(1)	cw(s2)	cp(0)	th(spg))}
{"dodge_med"		("set_vs"	lvl(1)	tag(carrier level_1 independent_delivery)	side(usa)	n(2)	sc(1)	cw(s2)	cp(0)	th(spg))}

;[Horse]_______________________________________________________________________________________________________________________________________________________________
;level_1
{"horse_double"		("set_default"	lvl(1)	tag(carrier level_1)	side(ger)	n(0)	sc(3)	cw(s2)	cp(0)	th(spg)	sd(default)	con(none) ch(0))}

;Tractor
;level_1
{"bulldog_lanz_38"	("set_vs"	lvl(1)	tag(carrier level_1)	side(ger)	n(1)	sc(3)	cw(s2)	cp(0)	th(spg))}

;[Carrier]___________________________________________________________________________________________________________________________________________________________________
;level_2
{"steyr_rso"  					("set_vs"	lvl(2)	tag(carrier level_2 independent_delivery)	side(ger)	n(2)	sc(4)	cw(s2)	cp(0)	th(spg))}
{"stz5"  						("set_vs"	lvl(2)	tag(carrier level_2 independent_delivery)	side(rus)	n(2)	sc(4)	cw(s2)	cp(0)	th(spg))}
;level_3
{"t20_tent"						("set_vs"	lvl(3)	tag(carrier level_3 independent_delivery)	side(rus)	n(2)	sc(18)	cw(s2)	cp(0)	th(spg))}
{"universal_carrier_usa"		("set_vs"	lvl(3)	tag(carrier level_3 independent_delivery)	side(usa)	n(2)	sc(15)	cw(s2)	cp(0)	th(spg))}
{"universal_carrier"		("set_vs"	lvl(3)	tag(carrier level_3 independent_delivery)	side(eng)	n(2)	sc(15)	cw(s2)	cp(0)	th(spg))}
{"m4_tractor_c"				("set_vs"	lvl(3)	tag(carrier level_3 independent_delivery)	side(usa)	n(3)	sc(20)	cw(s2)	cp(0)	th(spg))}
{"m4_tractor"				("set_vs"	lvl(3)	tag(carrier level_3 independent_delivery)	side(usa)	n(3)	sc(22)	cw(s2)	cp(0)	th(spg))}

;[APC]_____________________________________________________________________________________________________________________________________________________________________
;level_2
{"sdkfz251m"				("set_vs"		lvl(2)	tag(all apc level_2)	side(ger)	n(4)	sc(30)	cw(s2)	cp(4)	th(apc))}
{"opel_blitz_highback"		("set_default"	lvl(2)	tag(all apc level_2 can_push)	side(ger)	n(2)	sc(6)	cw(s2)	cp(0)	th(apc)	sd(default)	con(opel)		ch(0))}
{"opel_blitz_mgun"			("set_default"	lvl(2)	tag(all apc level_2 can_push)	side(ger)	n(6)	sc(12)	cw(s2)	cp(1)	th(apc)	sd(default)	con(opel_mgun)	ch(0))}
{"sdkfz251c"				("set_251_1"	lvl(2)	tag(all apc level_2 can_push)	side(ger)	n(3)	sc(14)	cw(s2)	cp(4)	th(apc))}
{"sdkfz251b"				("set_251_1"	lvl(2)	tag(all apc level_2)	side(ger)	n(3)	sc(14)	cw(s2)	cp(4)	th(apc))}; squad branderburgers
{"sdkfz251"					("set_251_1"	lvl(2)	tag(all apc level_2 can_push)	side(ger)	n(5)	sc(14)	cw(s2)	cp(4)	th(apc))}
{"sdkfz251d_g"				("set_251_1"	lvl(2)	tag(all apc level_2 can_push)	side(ger)	n(2)	sc(14)	cw(s2)	cp(4)	th(apc))}; squad ss
{"sdkfz251_10"				("set_default"	lvl(2)	tag(all apc level_2 can_push)	side(ger)	n(5)	sc(24)	cw(s6)	cp(5)	th(commander_apc)	sd(default)	con(251_10)	ch(0))}
{"sdkfz251_10c"				("set_vs" 		lvl(2)	tag(all apc level_2 can_push)	side(ger)	n(3)	sc(24)	cw(s6)	cp(5)	th(commander_apc))}
{"sdkfz251_17"				("set_vs"		lvl(2)	tag(all apc level_2)	side(ger)	n(4)	sc(30)	cw(s2)	cp(4)	th(apc))}
{"sdkfz223"					("set_vs"		lvl(2)	tag(all apc level_2)	side(ger)	n(3)	sc(14)	cw(s2)	cp(4)	th(apc)) {dont_unfog_by_territory}}
{"sdkfz222"					("set_vs"		lvl(2)	tag(all apc level_2)	side(ger)	n(3)	sc(22)	cw(s2)	cp(4)	th(apc)) {dont_unfog_by_territory}}
{"sdkfz221"					("set_vs"		lvl(2)	tag(all apc level_2)	side(ger)	n(2)	sc(18)	cw(s2)	cp(3)	th(apc)) {dont_unfog_by_territory}}
{"gaz_aa_untented"			("set_default"	lvl(2)	tag(all apc level_2 can_push)	side(rus)	n(2)	sc(6)	cw(s2)	cp(0)	th(apc)	sd(default)	con(gaz)	ch(0))}
{"t20"						("set_default" 	lvl(2)	tag(all apc level_2 can_push)	side(rus)	n(2)	sc(12)	cw(s2)	cp(3)	th(apc)	sd(default)	con(t20)	ch(0))}
{"m3"						("set_default"	lvl(2)	tag(all apc level_2 can_push)	side(rus)	n(2)	sc(12)	cw(s2)	cp(4)	th(apc)	sd(default)	con(m3a1)	ch(0))}
{"m3_g"						("set_default"	lvl(2)	tag(all apc level_2 can_push)	side(rus)	n(2)	sc(12)	cw(s2)	cp(4)	th(apc)	sd(default)	con(m3a1)	ch(0))}
{"ba20"						("set_vs"		lvl(2)	tag(all apc level_2)	side(rus)	n(2)	sc(13)	cw(s2)	cp(4)	th(apc)) {dont_unfog_by_territory}}
{"ba64"						("set_vs"		lvl(2)	tag(all apc level_2)	side(rus)	n(2)	sc(15)	cw(s2)	cp(4)	th(apc)) {dont_unfog_by_territory}}
{"gmc_inf"						("set_default"	lvl(2)	tag(all apc level_2 can_push)	side(usa)	n(2)	sc(6)	cw(s2)	cp(0)	th(apc)	sd(default)	con(gmc_inf)	ch(0))}
{"m3_ally"					("set_default"	lvl(2)	tag(all apc level_2 can_push)	side(usa)	n(2)	sc(12)	cw(s2)	cp(4)	th(apc)	sd(default)	con(m3a1)	ch(0))}
{"m20"						("set_vs"		lvl(2)	tag(all apc level_2) 	side(usa)	n(3)	sc(20)	cw(s6)	cp(4)	th(commander_apc))}
{"universal_carrier_inf_usa"	("set_default" 	lvl(2)	tag(all apc level_2 can_push)	side(usa)	n(2)	sc(12)	cw(s2)	cp(3)	th(apc)	sd(default)	con(u_c_inf_usa)	ch(0))}
;level_3
{"ab41"						("set_vs" 		lvl(3)	tag(all apc level_3)	side(ger)	n(4)	sc(20)	cw(s2)	cp(5)	th(apc))}
{"sdkfz232"					("set_vs" 		lvl(3)	tag(all apc level_3)	side(ger)	n(4)	sc(23)	cw(s2)	cp(5)	th(apc))}
{"m2"						("set_default" 	lvl(3)	tag(all apc level_3 can_push)	side(rus)	n(4)	sc(21)	cw(s2)	cp(5)	th(apc)	sd(default)	con(m3a2)	ch(0))}
{"ba11"						("set_vs" 		lvl(3)	tag(all apc level_3)	side(rus)	n(4)	sc(20)	cw(s2)	cp(5)	th(apc))}
{"m2_ally"					("set_default" 	lvl(3)	tag(all apc level_3 can_push)	side(usa)	n(4)	sc(21)	cw(s2)	cp(5)	th(apc)	sd(default)	con(m3a2)	ch(0))}
{"m8grayhound"				("set_vs" 		lvl(3)	tag(all apc level_3)	side(usa)	n(4)	sc(24)	cw(s2)	cp(5)	th(apc))}
{"m2_ally_m"				("set_vs" 		lvl(3)	tag(all apc level_3)	side(usa)	n(4)	sc(32)	cw(s2)	cp(5)	th(apc))}
;level_4
{"sdkfz234"					("set_vs" 		lvl(4)	tag(all apc level_4)	side(ger)	n(4)	sc(29)	cw(s2)	cp(6)	th(apc))}
{"m3_scout_rus"				("set_default" 	lvl(4)	tag(all apc level_4)	side(rus)	n(4)	sc(21)	cw(s2)	cp(4)	th(apc)	sd(default)	con(m3_scout)	ch(0)) {dont_unfog_by_territory}}
{"m3_scout"					("set_default" 	lvl(4)	tag(all apc level_4)	side(usa)	n(4)	sc(21)	cw(s2)	cp(4)	th(apc)	sd(default)	con(m3_scout)	ch(0)) {dont_unfog_by_territory}}
;level_5
{"sdkfz251_16"				("set_vs" 		lvl(5)	tag(all apc level_5)	side(ger)	n(5)	sc(29)	cw(s2)	cp(7)	th(apc))}
{"m3_g"					("set_default"	lvl(5)	tag(all apc level_5)	side(rus)	n(5)	sc(13)	cw(s6)	cp(4)	th(apc)	sd(default)	con(m3_g)	ch(0))}
{"m3_ally_g"					("set_default"	lvl(5)	tag(all apc level_5)	side(usa)	n(5)	sc(13)	cw(s6)	cp(4)	th(apc)	sd(default)	con(m3_ally_g)	ch(0))}
{"sdkfz251d"				("set_default"		lvl(5)	tag(all apc level_5)	side(ger)	n(2)	sc(14)	cw(s6)	cp(4)	th(apc)	sd(default)	con(251d)	ch(0))}; squad patrol
;level_5
{"pz4f2_inf"				("set_default"	lvl(6)	tag(all apc level_6 can_push)	side(ger)	n(2)	sc(43)	cw(s2)	cp(9)	th(apc)	sd(default)	con(pz4f2_inf)	ch(0))}
{"pz4g_inf"				("set_default"	lvl(6)	tag(all apc level_6 can_push)	side(ger)	n(2)	sc(43)	cw(s2)	cp(10)	th(apc)	sd(default)	con(pz4g_inf)	ch(0))}
{"t34_76_inf"				("set_default"	lvl(6)	tag(all apc level_6 can_push)	side(rus)	n(2)	sc(43)	cw(s2)	cp(9)	th(apc)	sd(default)	con(t34_76_inf)	ch(0))}
{"t34_2_inf"				("set_default"	lvl(6)	tag(all apc level_6 can_push)	side(rus)	n(2)	sc(43)	cw(s2)	cp(10)	th(apc)	sd(default)	con(t34_2_inf)	ch(0))}
{"m4a1_inf"				("set_default"	lvl(6)	tag(all apc level_6 can_push)	side(usa)	n(2)	sc(43)	cw(s2)	cp(9)	th(apc)	sd(default)	con(m4a1_inf)	ch(0))}
{"m4a3dd_inf"				("set_default"	lvl(6)	tag(all apc level_6 can_push)	side(usa)	n(2)	sc(43)	cw(s2)	cp(10)	th(apc)	sd(default)	con(m4a3dd_inf)	ch(0))}

;[Zenite_Vehicle]___________________________________________________________________________________________________________________________________________________________
;level_2
{"pz1"				("set_v" 	lvl(2)	tag(all art_spec level_2)	side(ger)	n(3)	sc(23)	cw(s2)	cp(3)	th(tanks))}
{"dshk_aaa"			("set_vs"	lvl(2)	tag(all art_spec level_2)	side(rus)	n(4)	sc(13)	cw(s2)	cp(3)	th(tanks))}
{"m16"				("set_v" 	lvl(2)	tag(all art_spec level_2)	side(usa)	n(3)	sc(17)	cw(s2)	cp(3)	th(tanks))}
;level_3
{"sdkfz7_1"			("set_vs"	lvl(3)	tag(all art_spec level_3)	side(ger)	n(5)	sc(23)	cw(s2)	cp(4)	th(tanks))}
{"zsu37"			("set_v" 	lvl(3)	tag(all art_spec level_3)	side(rus)	n(4)	sc(34)	cw(s2)	cp(5)	th(tanks))}
;level_4
{"29k"				("set_vs"	lvl(4)	tag(all art_spec level_4)	side(rus)	n(4)	sc(40)	cw(s2)	cp(7)	th(tanks))}
{"welberwind"		("set_v" 	lvl(4)	tag(all art_spec level_4)	side(ger)	n(5)	sc(32)	cw(s2)	cp(6)	th(tanks))}
{"m19"				("set_v" 	lvl(4)	tag(all art_spec level_4)	side(usa)	n(6)	sc(36)	cw(s2)	cp(6)	th(tanks))}

;[Tracked mine]______________________________________________________________________________________________________________________________________________________________
;level_1
{"goliath"			("set_v"	lvl(1)	tag(all sup level_2)	side(ger)	n(0)	sc(15)	cw(s2)	cp(0)	th(tanks)) {dont_unfog_by_territory}}

;[Tank Light]______________________________________________________________________________________________________________________________________________________________
;level_1
{"pz1b"				("set_v"	lvl(1)	tag(all tnk_light level_1)	side(ger)	n(2)	sc(10)	cw(s2)	cp(3)	th(tanks))}
{"t40"				("set_v"	lvl(1)	tag(all tnk_light level_1)	side(rus)	n(2)	sc(11)	cw(s2)	cp(4)	th(tanks)) {dont_unfog_by_territory}}
{"t40_tns"			("set_v"	lvl(1)	tag(all tnk_light level_1)	side(rus)	n(2)	sc(16)	cw(s2)	cp(4)	th(tanks)) {dont_unfog_by_territory}}
;level_2
{"pz1c"  			("set_v"	lvl(1)	tag(all tnk_light level_1)	side(ger)	n(2)	sc(18)	cw(s2)	cp(5)	th(tanks)) {dont_unfog_by_territory}}
{"pz38g"			("set_v"	lvl(2)	tag(all tnk_light level_2)	side(ger)	n(3)	sc(30)	cw(s2)	cp(6)	th(tanks))}
{"pz35t"			("set_v"	lvl(2)	tag(all tnk_light level_2)	side(ger)	n(4)	sc(18)	cw(s6)	cp(5)	th(commander_apc))}
{"pz2f"				("set_v"	lvl(2)	tag(all tnk_light level_2)	side(ger)	n(3)	sc(18)	cw(s2)	cp(4)	th(tanks)) {dont_unfog_by_territory}}
{"pz2l"				("set_v"	lvl(2)	tag(all tnk_light level_2)	side(ger)	n(4)	sc(22)	cw(s2)	cp(5)	th(tanks)) {dont_unfog_by_territory}}
{"pz2c"				("set_v"	lvl(2)	tag(all tnk_light level_2)	side(ger)	n(3)	sc(18)	cw(s2)	cp(4)	th(tanks)) {dont_unfog_by_territory}}
{"bt7_ger"			("set_v"	lvl(2)	tag(all tnk_light level_2)	side(ger)	n(3)	sc(21)	cw(s2)	cp(6)	th(tanks)) {dont_unfog_by_territory}}
{"t26"				("set_v"	lvl(2)	tag(all tnk_light level_2)	side(rus)	n(3)	sc(15)	cw(s6)	cp(5)	th(commander_apc))}
{"t26e"				("set_v"	lvl(2)	tag(all tnk_light level_2)	side(rus)	n(3)	sc(22)	cw(s2)	cp(6)	th(tanks))}
{"bt7"				("set_v"	lvl(2)	tag(all tnk_light level_2)	side(rus)	n(3)	sc(21)	cw(s2)	cp(6)	th(tanks))	{dont_unfog_by_territory}}
{"t60"				("set_v"	lvl(2)	tag(all tnk_light level_2)	side(rus)	n(2)	sc(18)	cw(s2)	cp(4)	th(tanks)) {dont_unfog_by_territory}}
{"t70"				("set_v"	lvl(2)	tag(all tnk_light level_2)	side(rus)	n(2)	sc(25)	cw(s2)	cp(6)	th(tanks))}
{"m3a1"				("set_v"	lvl(2)	tag(all tnk_light level_2)	side(usa)	n(4)	sc(24)	cw(s2)	cp(6)	th(tanks))}
{"m3a1_rus"			("set_v"	lvl(2)	tag(all tnk_light level_2)	side(rus)	n(4)	sc(24)	cw(s2)	cp(6)	th(tanks))}
{"m5a1"				("set_v"	lvl(2)	tag(all tnk_light level_2)	side(usa)	n(4)	sc(28)	cw(s2)	cp(6)	th(tanks))}
{"lvt1"				("set_v"	lvl(2)	tag(all tnk_light level_2)	side(usa)	n(6)	sc(22)	cw(s6)	cp(6)	th(commander_apc))}
;level_3
{"ht26"				("set_v"	lvl(3)	tag(all tnk_light level_3)	side(rus)	n(2)	sc(22)	cw(s2)	cp(6)	th(commander_apc))}
{"carro15"			("set_v"	lvl(3)	tag(all tnk_light level_3)	side(ger)	n(4)	sc(28)	cw(s6)	cp(7)	th(commander_apc))}
{"pz2h"				("set_v"	lvl(3)	tag(all tnk_light level_3)	side(ger)	n(3)	sc(32)	cw(s2)	cp(7)	th(tanks))}
{"bt7a"				("set_v"	lvl(3)	tag(all tnk_light level_3)	side(rus)	n(4)	sc(21)	cw(s2)	cp(6)	th(tanks))}
{"m24"				("set_v"	lvl(3)	tag(all tnk_light level_3)	side(usa)	n(5)	sc(41)	cw(s2)	cp(7)	th(tanks))}
{"lvt4"				("set_v"	lvl(3)	tag(all tnk_light level_3)	side(usa)	n(5)	sc(40)	cw(s2)	cp(6)	th(commander_apc))}

;[Minetral]______________________________________________________________________________________________________________________________________________________________
;level_2
{"pz3m"				("set_v"	lvl(2)	tag(all sup_veh level_2)	side(ger)	n(3)	sc(17)	cw(s2)	cp(4)	th(tanks))}
{"t34m"				("set_v"	lvl(6)	tag(all sup_veh level_6)	side(rus)	n(4)	sc(61)	cw(s2)	cp(10)	th(tanks))}
{"m4a3m"			("set_v"	lvl(6)	tag(all sup_veh level_6)	side(usa)	n(5)	sc(61)	cw(s2)	cp(10)	th(tanks))}


;[Tank Medium]______________________________________________________________________________________________________________________________________________________________
;level_1
{"m2a1_med"			("set_v"	lvl(1)	tag(all tnk_medium level_1)	side(usa)	n(6)	sc(32)	cw(s2)	cp(6)	th(tanks))}
;level_2
{"pz3f"				("set_v"	lvl(2)	tag(all tnk_medium level_2)	side(ger)	n(5)	sc(41)	cw(s2)	cp(7)	th(tanks))}
{"pz3f_rus"		("set_v"	lvl(2)	tag(all tnk_medium level_2)	side(rus)	n(5)	sc(41)	cw(s2)	cp(7)	th(tanks))}
{"t28"				("set_v"	lvl(2)	tag(all tnk_medium level_2)	side(rus)	n(6)	sc(43)	cw(s2)	cp(7)	th(tanks))}
{"valentine_rus"	("set_v"	lvl(2)	tag(all tnk_medium level_2)	side(rus)	n(3)	sc(40)	cw(s2)	cp(7)	th(tanks))}
{"mk2a"				("set_v"	lvl(2)	tag(all tnk_medium level_2)	side(eng)	n(4)	sc(40)	cw(s2)	cp(7)	th(tanks))}
{"chi-he"			("set_v"	lvl(2)	tag(all tnk_medium level_2)	side(jap)	n(4)	sc(40)	cw(s2)	cp(7)	th(tanks))}
;level_3
{"pz3"				("set_v"	lvl(3)	tag(all tnk_medium level_3)	side(ger)	n(5)	sc(45)	cw(s2)	cp(8)	th(tanks))}
{"pz3j"				("set_v"	lvl(3)	tag(all tnk_medium level_3)	side(ger)	n(5)	sc(45)	cw(s2)	cp(8)	th(tanks))}
{"pz3n"				("set_v"	lvl(3)	tag(all tnk_medium level_3)	side(ger)	n(5)	sc(51)	cw(s2)	cp(9)	th(tanks))}
{"pz4e"				("set_v"	lvl(3)	tag(all tnk_medium level_3)	side(ger)	n(5)	sc(37)	cw(s2)	cp(8)	th(tanks))}
{"pz4f2"			("set_v"	lvl(3)	tag(all tnk_medium level_3)	side(ger)	n(5)	sc(54)	cw(s2)	cp(9)	th(tanks))}
{"t34_76"			("set_v"	lvl(3)	tag(all tnk_medium level_3)	side(rus)	n(4)	sc(54)	cw(s2)	cp(9)	th(tanks))}
{"t34_0"			("set_v"	lvl(3)	tag(all tnk_medium level_3)	side(rus)	n(4)	sc(54)	cw(s2)	cp(9)	th(tanks))}
{"t28e"				("set_v"	lvl(3)	tag(all tnk_medium level_3)	side(rus)	n(6)	sc(51)	cw(s2)	cp(8)	th(tanks))}
{"grant_m3"		("set_v"	lvl(3)	tag(all tnk_medium level_3)	side(eng)	n(5)	sc(39)	cw(s2)	cp(8)	th(tanks))}
{"m3_lee"			("set_v"	lvl(3)	tag(all tnk_medium level_3)	side(usa)	n(5)	sc(39)	cw(s2)	cp(8)	th(tanks))}
{"m4a1"			("set_v"	lvl(3)	tag(all tnk_medium level_3)	side(usa)	n(4)	sc(56)	cw(s2)	cp(9)	th(tanks))}
{"mk8"				("set_v"	lvl(3)	tag(all tnk_medium level_3)	side(eng)	n(4)	sc(50)	cw(s2)	cp(9)	th(tanks))}
{"chi-nu"			("set_v"	lvl(3)	tag(all tnk_medium level_3)	side(jap)	n(4)	sc(50)	cw(s2)	cp(9)	th(tanks))}
;level_4
{"pz4d"				("set_v"	lvl(4)	tag(all tnk_medium level_4)	side(ger)	n(5)	sc(57)	cw(s2)	cp(10)	th(tanks))}
{"pz4g"				("set_v"	lvl(4)	tag(all tnk_medium level_4)	side(ger)	n(5)	sc(64)	cw(s2)	cp(10)	th(tanks))}
{"pz4h"				("set_v"	lvl(4)	tag(all tnk_medium level_4)	side(ger)	n(5)	sc(66)	cw(s2)	cp(11)	th(tanks))}
{"t34_2"			("set_v"	lvl(4)	tag(all tnk_medium level_4)	side(rus)	n(4)	sc(58)	cw(s2)	cp(10)	th(tanks))}
{"t34_armored"		("set_v"	lvl(4)	tag(all tnk_medium level_4)	side(rus)	n(4)	sc(59)	cw(s2)	cp(10)	th(tanks))}
{"t34_76_41"		("set_v"	lvl(4)	tag(all tnk_medium level_4)	side(rus)	n(4)	sc(58)	cw(s2)	cp(10)	th(tanks))}
{"m4a2_rus"			("set_v"	lvl(4)	tag(all tnk_medium level_4)	side(rus)	n(5)	sc(64)	cw(s2)	cp(10)	th(tanks))}
{"t34_1"			("set_v"	lvl(4)	tag(all tnk_medium level_4)	side(rus)	n(4)	sc(57)	cw(s2)	cp(9)	th(tanks))}
{"t34_57_43"		("set_v"	lvl(4)	tag(all tnk_medium level_4)	side(rus)	n(4)	sc(57)	cw(s2)	cp(9)	th(tanks))}
{"m4a1_eng"			("set_v"	lvl(4)	tag(all tnk_medium level_4)	side(eng)	n(4)	sc(59)	cw(s2)	cp(10)	th(tanks))}
{"m4a2"				("set_v"	lvl(4)	tag(all tnk_medium level_4)	side(usa)	n(5)	sc(64)	cw(s2)	cp(10)	th(tanks))}
{"m4a3_75"			("set_v"	lvl(4)	tag(all tnk_medium level_4)	side(usa)	n(5)	sc(64)	cw(s2)	cp(10)	th(tanks))}
{"m4a4"				("set_v"	lvl(4)	tag(all tnk_medium level_4)	side(usa)	n(5)	sc(64)	cw(s2)	cp(10)	th(tanks))}
{"m4a3dd"			("set_v"	lvl(4)	tag(all tnk_medium level_4)	side(usa)	n(5)	sc(62)	cw(s2)	cp(10)	th(tanks))}
{"m4a3_105"			("set_v"	lvl(4)	tag(all tnk_medium level_4)	side(usa)	n(4)	sc(68)	cw(s2)	cp(11)	th(tanks))}
{"chi-to"			("set_v"	lvl(4)	tag(all tnk_medium level_4)	side(jap)	n(5)	sc(63)	cw(s2)	cp(10)	th(tanks))}
;level_5
{"pz5a"				("set_v"	lvl(5)	tag(all tnk_medium level_5)	side(ger)	n(5)	sc(94)	cw(s2)	cp(15)	th(tanks))}
{"pz5a_po"				("set_v"	lvl(5)	tag(all tnk_medium level_5)	side(ger)	n(5)	sc(94)	cw(s2)	cp(15)	th(tanks))}
{"t34_3"			("set_v"	lvl(5)	tag(all tnk_medium level_5)	side(rus)	n(5)	sc(72)	cw(s2)	cp(11)	th(tanks))}
{"ot34_76_42"		("set_v"	lvl(5)	tag(all tnk_medium level_5)	side(rus)	n(4)	sc(63)	cw(s2)	cp(10)	th(tanks))}
{"t34_85"			("set_v"	lvl(5)	tag(all tnk_medium level_5)	side(rus)	n(5)	sc(72)	cw(s2)	cp(11)	th(tanks))}
{"t34_85_po"			("set_v"	lvl(5)	tag(all tnk_medium level_5)	side(rus)	n(5)	sc(72)	cw(s2)	cp(11)	th(tanks))}
{"m4a2_76w_rus"		("set_v"	lvl(5)	tag(all tnk_medium level_5)	side(rus)	n(5)	sc(72)	cw(s2)	cp(11)	th(tanks))}
{"m4a3e8"			("set_v"	lvl(5)	tag(all tnk_medium level_5)	side(usa)	n(5)	sc(72)	cw(s2)	cp(11)	th(tanks))}
{"m4a3e8_po"			("set_v"	lvl(5)	tag(all tnk_medium level_5)	side(usa)	n(5)	sc(72)	cw(s2)	cp(11)	th(tanks))}
{"m4a2_76w"			("set_v"	lvl(5)	tag(all tnk_medium level_5)	side(usa)	n(5)	sc(72)	cw(s2)	cp(11)	th(tanks))}
{"m4a2_76w_thunderbolt"		("set_v"	lvl(5)	tag(all tnk_medium level_5)	side(usa)	n(5)	sc(74)	cw(s2)	cp(11)	th(tanks))}
{"m4a3vc"			("set_v"	lvl(5)	tag(all tnk_medium level_5)	side(eng)	n(5)	sc(75)	cw(s2)	cp(12)	th(tanks))}
{"m4a3e2"			("set_v"	lvl(5)	tag(all tnk_medium level_5)	side(usa)	n(5)	sc(69)	cw(s2)	cp(11)	th(tanks))}
{"m4a3_zippo"		("set_v"	lvl(5)	tag(all tnk_medium level_5)	side(usa)	n(4)	sc(69)	cw(s2)	cp(11)	th(tanks))}
;level_6
{"pz5g"				("set_v"	lvl(6)	tag(all tnk_medium level_6)	side(ger)	n(5)	sc(110)	cw(s2)	cp(15)	th(tanks))}
{"t34_85m"			("set_v"	lvl(6)	tag(all tnk_medium level_6)	side(rus)	n(5)	sc(85)	cw(s2)	cp(12)	th(tanks))}
{"t34_85m_po"		("set_v"	lvl(6)	tag(all tnk_medium level_6)	side(rus)	n(5)	sc(85)	cw(s2)	cp(12)	th(tanks))}
{"m4a3e2_jumbo_76"	("set_v"	lvl(6)	tag(all tnk_medium level_6)	side(usa)	n(5)	sc(109)	cw(s2)	cp(13)	th(tanks))}

;[Tank Heavy]_______________________________________________________________________________________________________________________________________________________________
;level_1
;level_2
{"t35"				("set_v"	lvl(2)	tag(all tnk_heavy level_3)	side(rus)	n(10)	sc(45)	cw(s8)	cp(7)	th(heavy_tanks))}
{"pzb2740f"			("set_v"	lvl(2)	tag(all tnk_heavy level_3)	side(ger)	n(4)	sc(47)	cw(s8)	cp(8)	th(heavy_tanks))}
;level_3
{"kv1"				("set_v"	lvl(3)	tag(all tnk_heavy level_3)	side(rus)	n(4)	sc(61)	cw(s8)	cp(9)	th(heavy_tanks))}
{"kv1_za_rodinu"	("set_v"	lvl(3)	tag(all tnk_heavy level_3)	side(rus)	n(4)	sc(62)	cw(s8)	cp(9)	th(heavy_tanks_bonus))}
{"mk4_rus"			("set_v"	lvl(3)	tag(all tnk_heavy level_3)	side(rus)	n(5)	sc(60)	cw(s8)	cp(9)	th(heavy_tanks))}
{"mk4"				("set_v"	lvl(3)	tag(all tnk_heavy level_3)	side(eng)	n(4)	sc(60)	cw(s8)	cp(9)	th(heavy_tanks))}
;level_4
{"pz6h"				("set_default"	lvl(4)	tag(all tnk_heavy level_4)	side(ger)	n(4)	sc(110)	cw(s8)	cp(15)	th(heavy_tanks)	sd(default)	con(v_officer)	ch(0))}
{"kv1e"				("set_v"	lvl(4)	tag(all tnk_heavy level_4)	side(rus)	n(4)	sc(73)	cw(s8)	cp(9)	th(heavy_tanks))}
{"kv2"				("set_v"	lvl(4)	tag(all tnk_heavy level_4)	side(rus)	n(6)	sc(93)	cw(s8)	cp(11)	th(heavy_tanks))}
{"kv1s"				("set_v"	lvl(4)	tag(all tnk_heavy level_4)	side(rus)	n(4)	sc(71)	cw(s8)	cp(10)	th(heavy_tanks))}
{"kv85"				("set_v"	lvl(4)	tag(all tnk_heavy level_4)	side(rus)	n(4)	sc(93)	cw(s8)	cp(14)	th(heavy_tanks))}
{"kv1_zis5"		("set_v"	lvl(4)	tag(all tnk_heavy level_4)	side(rus)	n(4)	sc(76)	cw(s8)	cp(12)	th(heavy_tanks))}
;level_5
{"pz6e"				("set_default"	lvl(5)	tag(all tnk_heavy level_5)	side(ger)	n(4)	sc(116)	cw(s8)	cp(15)	th(heavy_tanks)	sd(default)	con(v_officer)	ch(0))}
{"kv8"				("set_v"	lvl(5)	tag(all tnk_heavy level_5)	side(rus)	n(4)	sc(83)	cw(s8)	cp(11)	th(heavy_tanks))}
{"m26"				("set_v"	lvl(5)	tag(all tnk_heavy level_5)	side(usa)	n(5)	sc(116)	cw(s8)	cp(15)	th(heavy_tanks))}
{"is1"				("set_v"	lvl(5)	tag(all tnk_heavy level_5)	side(rus)	n(4)	sc(116)	cw(s8)	cp(15)	th(heavy_tanks))}
{"centurion"		("set_v"	lvl(5)	tag(all tnk_heavy level_5)	side(eng)	n(5)	sc(110)	cw(s8)	cp(15)	th(heavy_tanks))}
{"chi-ri"			("set_v"	lvl(5)	tag(all tnk_heavy level_5)	side(jap)	n(5)	sc(110)	cw(s8)	cp(15)	th(heavy_tanks))}
;level_6
{"pz6b"				("set_default"	lvl(6)	tag(all tnk_heavy level_6)	side(ger)	n(4)	sc(136)	cw(s8)	cp(18)	th(heavy_tanks)	sd(default)	con(v_officer)	ch(0))}
{"pz6bh"			("set_default"	lvl(6)	tag(all tnk_heavy level_6)	side(ger)	n(4)	sc(141)	cw(s8)	cp(19)	th(heavy_tanks)	sd(default)	con(v_officer)	ch(0))}
{"is2_44"			("set_v"	lvl(6)	tag(all tnk_heavy level_6)	side(rus)	n(4)	sc(150)	cw(s8)	cp(18)	th(heavy_tanks))}
{"is2_early"		("set_v"	lvl(6)	tag(all tnk_heavy level_6)	side(rus)	n(4)	sc(131)	cw(s8)	cp(15)	th(heavy_tanks))}
{"is2"				("set_v"	lvl(6)	tag(all tnk_heavy level_6)	side(rus)	n(4)	sc(143)	cw(s8)	cp(17)	th(heavy_tanks))}
{"is3"				("set_v"	lvl(6)	tag(all tnk_heavy level_6)	side(rus)	n(4)	sc(156)	cw(s8)	cp(19)	th(heavy_tanks))}
{"t29"				("set_v"	lvl(6)	tag(all tnk_heavy level_6)	side(usa)	n(5)	sc(150)	cw(s8)	cp(19)	th(heavy_tanks))}
{"m26e4"			("set_v"	lvl(6)	tag(all tnk_heavy level_6)	side(usa)	n(5)	sc(156)	cw(s8)	cp(19)	th(heavy_tanks))}

;[SPG]______________________________________________________________________________________________________________________________________________________________________
;level_2
{"sdkfz251_9"		("set_vs"	lvl(2)	tag(all spg level_2)	side(ger)	n(3)	sc(20)	cw(s2)	cp(4)	th(apc))}
;level_3
{"m8"				("set_v"	lvl(3)	tag(all spg level_3)	side(usa)	n(4)	sc(39)	cw(s2)	cp(7)	th(spg))}
{"stug3b"			("set_v"	lvl(3)	tag(all spg level_3)	side(ger)	n(4)	sc(35)	cw(s2)	cp(6)	th(spg))}
{"sdkfz124"			("set_v"	lvl(3)	tag(all spg level_3)	side(ger)	n(4)	sc(50)	cw(s2)	cp(7)	th(spg))}
;level_4
{"stuh42"			("set_v"	lvl(4)	tag(all spg level_4)	side(ger)	n(4)	sc(68)	cw(s2)	cp(8)	th(spg))}
{"su122"			("set_v"	lvl(4)	tag(all spg level_4)	side(rus)	n(5)	sc(68)	cw(s2)	cp(9)	th(spg))}
{"m7"				("set_v"	lvl(4)	tag(all spg level_4)	side(usa)	n(4)	sc(63)	cw(s2)	cp(8)	th(spg))}
{"sturmpz1"			("set_v"	lvl(4)	tag(all spg level_4)	side(ger)	n(3)	sc(61)	cw(s2)	cp(8)	th(spg))}
;level_5
{"brumbar"			("set_v"	lvl(5)	tag(all spg level_5)	side(ger)	n(4)	sc(83)	cw(s2)	cp(9)	th(spg))}
{"hummel"			("set_v"	lvl(5)	tag(all spg level_5)	side(ger)	n(6)	sc(77)	cw(s2)	cp(9)	th(spg))}
{"su152"			("set_v"	lvl(5)	tag(all spg level_5)	side(rus)	n(5)	sc(83)	cw(s2)	cp(12)	th(spg))}
{"m12gmc"			("set_v"	lvl(5)	tag(all spg level_5)	side(usa)	n(4)	sc(77)	cw(s2)	cp(9)	th(spg))}
;level_6
{"sturmtiger"		("set_v"	lvl(6)	tag(all spg level_6)	side(ger)	n(6)	sc(113)	cw(s2)	cp(12)	th(spg))}
{"karlthor"			("set_v"	lvl(6)	tag(all spg level_6)	side(ger)	n(5)	sc(113)	cw(s2)	cp(12)	th(spg))}

;[Tank_Hunter]______________________________________________________________________________________________________________________________________________________________________
;level_2
{"pzjager1"			("set_v"	lvl(2)	tag(all tnk_hunt level_2)	side(ger)	n(3)	sc(20)	cw(s3)	cp(4)	th(spg)) {dont_unfog_by_territory}}
{"dodgewc51_m6"		("set_vs"	lvl(2)	tag(all tnk_hunt level_2)	side(usa)	n(4)	sc(18)	cw(s2)	cp(3)	th(spg)) {dont_unfog_by_territory}}
;level_3
{"su76"				("set_v"	lvl(3)	tag(all tnk_hunt level_3)	side(rus)	n(4)	sc(32)	cw(s3)	cp(5)	th(spg))}
{"marder2"			("set_v"	lvl(3)	tag(all tnk_hunt level_3)	side(ger)	n(4)	sc(45)	cw(s3)	cp(7)	th(spg))}
{"marder3"			("set_v"	lvl(3)	tag(all tnk_hunt level_3)	side(ger)	n(4)	sc(48)	cw(s3)	cp(7)	th(spg))}
{"zis_30"			("set_v"	lvl(3)	tag(all tnk_hunt level_3)	side(rus)	n(4)	sc(32)	cw(s3)	cp(5)	th(spg))}
{"m1_t48"			("set_vs"	lvl(3)	tag(all tnk_hunt level_3)	side(usa)	n(4)	sc(40)	cw(s2)	cp(5)	th(apc))}
;level_4
{"hetzer"			("set_v"	lvl(4)	tag(all tnk_hunt level_4)	side(ger)	n(4)	sc(50)	cw(s3)	cp(7)	th(spg)) {dont_unfog_by_territory}}
{"stug3g"			("set_v"	lvl(4)	tag(all tnk_hunt level_4)	side(ger)	n(4)	sc(77)	cw(s3)	cp(8)	th(spg))}
{"jagdpanzer"		("set_v"	lvl(4)	tag(all tnk_hunt level_5)	side(ger)	n(4)	sc(68)	cw(s3)	cp(8)	th(spg))}
{"stug3f"			("set_v"	lvl(4)	tag(all tnk_hunt level_4)	side(ger)	n(4)	sc(65)	cw(s3)	cp(7)	th(spg))}
{"sdkfz251_22"		("set_vs"	lvl(4)	tag(all tnk_hunt level_4)	side(ger)	n(4)	sc(53)	cw(s2)	cp(6)	th(apc))}
{"su85"				("set_v"	lvl(4)	tag(all tnk_hunt level_4)	side(rus)	n(4)	sc(71)	cw(s3)	cp(7)	th(spg))}
{"m18"				("set_v"	lvl(4)	tag(all tnk_hunt level_4)	side(usa)	n(5)	sc(63)	cw(s3)	cp(7)	th(spg))}
{"m10wolverine"		("set_v"	lvl(4)	tag(all tnk_hunt level_4)	side(usa)	n(5)	sc(63)	cw(s3)	cp(7)	th(spg))}
;level_5
{"stug4g"			("set_v"	lvl(5)	tag(all tnk_hunt level_5)	side(ger)	n(4)	sc(80)	cw(s3)	cp(8)	th(spg))}
{"nashorn"			("set_v"	lvl(5)	tag(all tnk_hunt level_5)	side(ger)	n(4)	sc(83)	cw(s3)	cp(9)	th(spg))}
{"jagdpanzer_iv"	("set_v"	lvl(5)	tag(all tnk_hunt level_5)	side(ger)	n(4)	sc(83)	cw(s3)	cp(9)	th(spg))}
{"jagdpanzer_iv_wacher"	("set_v"	lvl(5)	tag(all tnk_hunt level_5)	side(ger)	n(4)	sc(85)	cw(s3)	cp(9)	th(commander_apc))}
{"su100"			("set_v"	lvl(5)	tag(all tnk_hunt level_5)	side(rus)	n(4)	sc(94)	cw(s3)	cp(10)	th(spg))}
{"m36"				("set_v"	lvl(5)	tag(all tnk_hunt level_5)	side(usa)	n(5)	sc(86)	cw(s3)	cp(9)	th(spg))}
;level_6
{"elefant"			("set_v"	lvl(6)	tag(all tnk_hunt level_6)	side(ger)	n(4)	sc(108)	cw(s3)	cp(12)	th(spg))}
{"ferdinand"		("set_v"	lvl(6)	tag(all tnk_hunt level_6)	side(ger)	n(6)	sc(108)	cw(s3)	cp(12)	th(spg))}
{"jagdpanther"		("set_v"	lvl(6)	tag(all tnk_hunt level_6)	side(ger)	n(5)	sc(142)	cw(s3)	cp(13)	th(spg))}
{"jagdtiger"		("set_v"	lvl(6)	tag(all tnk_hunt level_6)	side(ger)	n(6)	sc(168)	cw(s3)	cp(16)	th(spg))}
{"isu122"			("set_v"	lvl(6)	tag(all tnk_hunt level_6)	side(rus)	n(5)	sc(119)	cw(s3)	cp(13)	th(spg))}
{"isu152"			("set_v"	lvl(6)	tag(all tnk_hunt level_6)	side(rus)	n(5)	sc(125)	cw(s3)	cp(13)	th(spg))}
{"isu152"			("set_v"	lvl(6)	tag(all tnk_hunt level_6)	side(rus)	n(5)	sc(125)	cw(s3)	cp(13)	th(spg))}
{"t95"				("set_v"	lvl(6)	tag(all tnk_hunt level_6)	side(usa)	n(4)	sc(168)	cw(s3)	cp(15)	th(spg))}


;[Zenite_Gun with trailer]__________________________________________________________________________________________________________________________________________________
;level_4
("how" 				t(all art_spec level_4)	side(ger)	name(flak18_trailer)		lvl(4)	c1(steyr_rso)	c2(flak18)	n(6)	sc(50))
("how" 				t(all art_spec level_4)	side(rus)	name(52k_trailer)			lvl(4)	c1(t20_tent)	c2(52k)		n(6)	sc(50))
;level_5
("how" 				t(all art_spec level_5)	side(usa)	name(m2cannon90mm_trailer)	lvl(5)	c1(m4_tractor)	c2(m2cannon90mm)	n(6)	sc(60))

;[Howitzer with trailer]____________________________________________________________________________________________________________________________________________________
;level_1
("how" 				t(all art level_1)	side(usa)	name(m8_howitzer_trailer)	lvl(1)	c1(dodge)				c2(m8_howitzer)	n(4)	sc(43))
;level_2
("how" 				t(all art level_2)	side(ger)	name(lefh18_trailer)		lvl(2)	c1(steyr_rso)				c2(lefh18)		n(6)	sc(51))
("how" 				t(all art level_2)	side(rus)	name(m30_trailer)			lvl(2)	c1(stz5)					c2(m30)			n(6)	sc(56))
("how" 				t(all art level_2)	side(usa)	name(m2a1l_trailer)			lvl(2)	c1(universal_carrier_usa)	c2(m2a1l)		n(6)	sc(51))
;level_3
("how" 				t(all art level_3)	side(ger)	name(sfh18_trailer)			lvl(3)	c1(steyr_rso)				c2(sfh18)		n(6)	sc(68))
("how" 				t(all art level_3)	side(ger)	name(sig33_trailer)			lvl(3)	c1(steyr_rso)				c2(sig33)		n(6)	sc(65))
("how" 				t(all art level_3)	side(rus)	name(ml20_trailer)			lvl(3)	c1(stz5)					c2(ml20)		n(6)	sc(68))
("how" 				t(all art level_3)	side(rus)	name(d1_trailer)			lvl(3)	c1(stz5)					c2(d1)			n(6)	sc(68))
("how" 				t(all art level_3)	side(rus)	name(m1909_trailer)			lvl(3)	c1(stz5)					c2(m1909)		n(6)	sc(65))
("how" 				t(all art level_3)	side(usa)	name(m114_trailer)			lvl(3)	c1(m4_tractor_c)	c2(m114)		n(6)	sc(68))
;level_5
("how" 				t(all art level_5)	side(ger)	name(mrs18_trailer)			lvl(5)	c1(steyr_rso)			c2(mrs18)		n(6)	sc(70))
("how" 				t(all art level_5)	side(rus)	name(203b4_trailer)			lvl(5)	c1(stz5)				c2(203b4)		n(6)	sc(70))
("how" 				t(all art level_5)	side(usa)	name(203_m1_trailer)		lvl(5)	c1(m4_tractor_c)		c2(203_m1)		n(6)	sc(70))

;[Rocket_Launcher_Stan with trailer]_____________________________________________________________________________________________________________________________________________________
;level_5
("how" 				t(all sup level_4)	side(ger)	name(nebelwerfer41_trailer)	lvl(4)	c1(kubel)	c2(nebelwerfer41)	n(4)	sc(70))
("how" 				t(all sup level_5)	side(ger)	name(nebelwerfer42_trailer)	lvl(5)	c1(kubel)	c2(nebelwerfer42)	n(4)	sc(72))


;[MGUN Stan with trailer]__________________________________________________________________________________________________________________________________________________
;level_1
("art_point" 		t(all art_spec level_1)	side(usa)	name(maxson_trailer)	lvl(1)	c1(willysmb_tent)	c2(maxson)	n(3)	sc(14))
;level_2
("art_point" 		t(all sup level_2)		side(rus)	name(kpvt_trailer)		lvl(2)	c1(gaz67)	c2(kpvt)	n(4)	sc(9))

;[Zenite_Autocannon with trailer]__________________________________________________________________________________________________________________________________________________
;level_1
("art_point" 		t(all art_spec level_1)	side(ger)	name(flak38_wheeled_trailer)	lvl(1)	c1(kubel)	c2(flak38_wheeled)	n(4)	sc(17))
("art_point" 		t(all art_spec level_1)	side(usa)	name(oerlikon_trailer)			lvl(1)	c1(willysmb_tent)	c2(oerlikon)		n(1)	sc(12))
;level_2
("art_point" 		t(all art_spec level_2)	side(rus)	name(61k_trailer)				lvl(2)	c1(gaz67)	c2(61k)				n(4)	sc(34))
("art_point" 		t(all art_spec level_2)	side(usa)	name(m1_aa_trailer)				lvl(2)	c1(gmc)	c2(m1_aa)				n(4)	sc(34))
;level_3
("art_point" 		t(all art_spec level_3)	side(usa)	name(bofors_trailer)			lvl(2)	c1(dodge)	c2(bofors)			n(4)	sc(26))

;[Field guns with trailer]__________________________________________________________________________________________________________________________________________________
;level_2
("art_point" 		t(all sup level_2)		side(ger)	name(lelg18_trailer)			lvl(2)	c1(kubel)	c2(lelg18)			n(4)	sc(34))
("art_point" 		t(all sup level_2)		side(rus)	name(1943_cannon_trailer)		lvl(2)	c1(gaz67)	c2(1943_cannon)		n(4)	sc(34))
("art_point" 		t(all sup level_2)		side(rus)	name(1927_cannon_trailer)		lvl(2)	c1(gaz67)	c2(1927_cannon)		n(4)	sc(34))

;[AT_Cannon with trailer]___________________________________________________________________________________________________________________________________________________
;level_1
("art_point" 		t(all art_point level_1)	side(ger)	name(pak35_trailer)			lvl(1)	c1(kubel)		c2(pak35)		n(4)	sc(12))
("art_point"		t(all art_point level_1)	side(rus)	name(53k_trailer)			lvl(1)	c1(gaz67)		c2(53k)			n(4)	sc(17))
("art_point"		t(all art_point level_1)	side(usa)	name(m3cannon_trailer)		lvl(1)	c1(willysmb_tent)		c2(m3cannon)	n(4)	sc(14))
;level_2
("art_point" 		t(all art_point level_2)	side(ger)	name(pak41-le_trailer)		lvl(2)	c1(kettenkrad)	c2(pak41-le)	n(4)	sc(15))
("art_point" 		t(all art_point level_2)	side(ger)	name(pak38_trailer)			lvl(2)	c1(opel_blitz)	c2(pak38)		n(4)	sc(24))
("art_point" 		t(all art_point level_2)	side(ger)	name(pak37-t_trailer)		lvl(2)	c1(kettenkrad)	c2(pak37-t)		n(4)	sc(24))
("art_point" 		t(all art_point level_2)	side(rus)	name(m42_trailer)			lvl(2)	c1(gaz67)		c2(m42)			n(4)	sc(20))
;level_3
("art_point" 		t(all art_point level_3)	side(ger)	name(pak36_trailer)			lvl(3)	c1(opel_blitz)	c2(pak36)		n(4)	sc(38))                                  
("art_point" 		t(all art_point level_3)	side(rus)	name(zis3_trailer)			lvl(3)	c1(gaz_aa)		c2(zis3)		n(4)	sc(28))
("art_point" 		t(all art_point level_3)	side(rus)	name(f22_trailer)			lvl(3)	c1(gaz_aa)		c2(f22)			n(4)	sc(25))
("art_point" 		t(all art_point level_3)	side(usa)	name(m1_trailer)			lvl(3)	c1(gmc)		c2(m1)			n(4)	sc(30))
;level_4
("art_point" 		t(all art_point level_4)	side(ger)	name(pak40_trailer)			lvl(4)	c1(opel_blitz)	c2(pak40)		n(4)	sc(46)) 
("art_point" 		t(all art_point level_4)	side(ger)	name(sk18_trailer)			lvl(4)	c1(steyr_rso)	c2(sk18)		n(6)	sc(46)) 
("art_point" 		t(all art_point level_4)	side(rus)	name(zis2_trailer)			lvl(4)	c1(gaz_aa)		c2(zis2)		n(4)	sc(28))  
("art_point" 		t(all art_point level_4)	side(usa)	name(m5_trailer)			lvl(4)	c1(gmc)		c2(m5)			n(4)	sc(46))                                  
;level_5
("art_point" 		t(all art_point level_5)	side(ger)	name(pak43_trailer)			lvl(5)	c1(steyr_rso)	c2(pak43)		n(4)	sc(58))
("art_point" 		t(all art_point level_5)	side(rus)	name(bs3_trailer)			lvl(5)	c1(stz5)		c2(bs3)			n(4)	sc(58))

;[Air_Recon]______________________________________________________________________________________________________________________________________________________________________
{"fi156"			("set_v_p"	lvl(1) tag(all sup level_1 independent_delivery transfer_forbiden)	side(ger)	n(2)	sc(18))	{actions "air_recon"} {dont_unfog_by_territory}}
{"po2_snow"			("set_v_p"	lvl(1) tag(all sup level_1 independent_delivery transfer_forbiden)	side(rus)	n(2)	sc(18))	{actions "air_recon"} {dont_unfog_by_territory}}
{"po-2_scout"		("set_v_p"	lvl(1) tag(all sup level_1 independent_delivery transfer_forbiden)	side(rus)	n(2)	sc(18))	{actions "air_recon"} {dont_unfog_by_territory}}
{"l-4"				("set_v_p"	lvl(1) tag(all sup level_1 independent_delivery transfer_forbiden)	side(usa)	n(2)	sc(18))	{actions "air_recon"} {dont_unfog_by_territory}}
;[Air_Fighter]____________________________________________________________________________________________________________________________________________________________________
{"po-2"				("set_v_p"	lvl(3) tag(all sup level_2 independent_delivery transfer_forbiden)	side(rus)	n(2)	sc(30))}
{"p-51mustang"		("set_v_p"	lvl(2) tag(all air level_3 independent_delivery transfer_forbiden)	side(usa)	n(1)	sc(40))}
{"p51d"				("set_v_p"	lvl(2) tag(all air level_3 independent_delivery transfer_forbiden)	side(usa)	n(1)	sc(40))}
{"bf109g"			("set_v_p"	lvl(2) tag(all air level_2 independent_delivery transfer_forbiden)	side(ger)	n(1)	sc(38))}
{"i-16"				("set_v_p"	lvl(2) tag(all air level_2 independent_delivery transfer_forbiden)	side(ger)	n(1)	sc(17))}
{"p51"				("set_v_p"	lvl(2) tag(all air level_2 independent_delivery transfer_forbiden)	side(usa)	n(1)	sc(34))}
;[Air_Attack]____________________________________________________________________________________________________________________________________________________________________
{"ju-87"			("set_v_p"	lvl(4) tag(all air level_4 independent_delivery transfer_forbiden)  	side(ger)	n(2)	sc(50))	{actions "air_attack"}}
{"ju-87g"			("set_v_p"	lvl(4) tag(all air level_4 independent_delivery transfer_forbiden)  	side(ger)	n(2)	sc(50))	{actions "air_attack"}}
{"il-2"				("set_v_p"	lvl(4) tag(all air level_4 independent_delivery transfer_forbiden)  	side(rus)	n(2)	sc(52))	{actions "air_attack"}}
{"il-2_collection"	("set_v_p"	lvl(4) tag(all air level_4 independent_delivery transfer_forbiden)  	side(rus)	n(2)	sc(52))	{actions "air_attack"}}
{"a20"				("set_v_p"	lvl(4) tag(all air level_4 independent_delivery transfer_forbiden)  	side(usa)	n(2)	sc(44))	{actions "air_attack"}}
;Air_Attack defined
("airstrike"		name(airstrike_bf109g)	side(ger)	t(all air level_2 independent_delivery transfer_forbiden)	lvl(2)	c1(bf109g)		n(1)	t())
("airstrike"		name(airstrike)			side(ger)	t(all air level_4 independent_delivery transfer_forbiden)	lvl(4)	c1(ju-87)		n(2)	t())
("airstrike"		name(airstrike_ju87g)	side(ger)	t(all air level_4 independent_delivery transfer_forbiden)	lvl(4)	c1(ju-87g)		n(2)	t())
("airstrike"		name(airstrike_i-16)	side(rus)	t(all air level_2 independent_delivery transfer_forbiden)	lvl(2)	c1(i-16)		n(1)	t())
("airstrike"		name(airstrike_po-2)	side(rus)	t(all air level_2 independent_delivery transfer_forbiden)	lvl(2)	c1(po-2)		n(2)	t())
("airstrike"		name(airstrike_il-2_collection)	side(rus)	t(all air level_2 independent_delivery transfer_forbiden)	lvl(2)	c1(il-2_collection)		n(2)	t())
("airstrike"		name(airstrike)			side(rus)	t(all air level_4 independent_delivery transfer_forbiden)	lvl(4)	c1(il-2)		n(2)	t())
("airstrike"		name(airstrike_p51)		side(usa)	t(all air level_2 independent_delivery transfer_forbiden)	lvl(2)	c1(p51)			n(1)	t())
("airstrike"		name(airstrike)			side(usa)	t(all air level_3 independent_delivery transfer_forbiden)	lvl(3)	c1(p51d)		n(1)	t())
("airstrike"		name(airstrike_a20)		side(usa)	t(all air level_4 independent_delivery transfer_forbiden)	lvl(4)	c1(a20)			n(2)	t())
;Air Transport
{"ju-52"			("set_v_p"	lvl(4)	tag(all air level_4 independent_delivery transfer_forbiden)	side(ger)	n(8)	sc(10)) {dont_unfog_by_territory}}
{"dc-47"			("set_v_p"	lvl(4)	tag(all air level_4 independent_delivery transfer_forbiden)	side(ger)	n(7)	sc(10)) {dont_unfog_by_territory}}
{"dc-47_rus"			("set_v_p"	lvl(4)	tag(all air level_4 independent_delivery transfer_forbiden)	side(ger)	n(7)	sc(10)) {dont_unfog_by_territory}}
{"cg-4a"			("set_v_p"	lvl(4)	tag(all air level_4 independent_delivery transfer_forbiden)	side(usa)	n(10)	sc(10)) {dont_unfog_by_territory}}

;[Marine]_____________________________________________________________________________________________________________________________________________________________________
{"lcvp"			("set_vs"	lvl(1)	tag(all sup level_1)	side(usa)	n(3)	sc(3)	cw(s1)	cp(0) th(marine))}
{"air-bag"		("set_vs"	lvl(1)	tag(all sup level_1)	side(rus)	n(2)	sc(3)	cw(s1)	cp(0)	 th(marine))}
{"flobsack_34"		("set_vs"	lvl(1)	tag(all sup level_1)	side(ger)	n(2)	sc(3)	cw(s1)	cp(0)	 th(marine))}
{"pg1"			("set_vs"	lvl(1)	tag(all sup level_1)	side(rus)	n(2)	sc(3)	cw(s1)	cp(0)	 th(marine))}
{"sturmboot42"			("set_vs"	lvl(1)	tag(all sup level_1)	side(ger)	n(2)	sc(3)	cw(s1)	cp(0)	 th(marine))}

;[Crates]_____________________________________________________________________________________________________________________________________________________________________
{"inventory_crate"			("set_vs"	lvl(1)	tag(all art_spec level_1 independent_delivery)	side(ger) n(2)	sc(2)	cw(s1)	cp(0)	th(gun))}
{"inventory_crate_ger"		("set_vs"	lvl(1)	tag(all art_spec level_1 independent_delivery)	side(ger) n(2)	sc(2)	cw(s1)	cp(0)	th(gun))}
{"inventory_crate_rus"		("set_vs"	lvl(1)	tag(all art_spec level_1 independent_delivery)	side(rus) n(2)	sc(2)	cw(s1)	cp(0)	th(gun))}
{"inventory_crate_usa"		("set_vs"	lvl(1)	tag(all art_spec level_1 independent_delivery)	side(usa) n(2)	sc(2)	cw(s1)	cp(0)	th(gun))}

;[House]_____________________________________________________________________________________________________________________________________________________________________
{"house_001_g2"		("territory_holder_house")}
{"house_001a_g2"	("territory_holder_house")}
{"house_001b_g2"	("territory_holder_house")}
{"house_40_g2"		("territory_holder_house")}
{"house_50_g2"		("territory_holder_house")}
{"house_60_g2"		("territory_holder_house")}
{"house_70_g2"		("territory_holder_house")}
{"house_80_g2"		("territory_holder_house")}
{"house_80a_g2"		("territory_holder_house")}
{"house_90_g2"		("territory_holder_house")}
{"house_d_001"		("territory_holder_house")}
{"house_d_002"		("territory_holder_house")}
{"house_d_003"		("territory_holder_house")}
{"house_d_003_1a"	("territory_holder_house")}
{"house_d_003_2a"	("territory_holder_house")}
{"house_d_004"		("territory_holder_house")}
{"house_d_004_p1"	("territory_holder_house")}
{"house_d_004_p2"	("territory_holder_house")}
{"house_d_004_p3"	("territory_holder_house")}
{"house_d_005"		("territory_holder_house")}
{"house_d_005_1"	("territory_holder_house")}
{"house_d_005_2"	("territory_holder_house")}
{"house_d_005_3"	("territory_holder_house")}
{"house_d_006"		("territory_holder_house")}
{"shed_village_g2"	("territory_holder_house")}
{"e_hangar_111_g2"	("territory_holder_house")}
{"barn_10"			("territory_holder_house")}
{"barn_20"			("territory_holder_house")}
{"barn_30"			("territory_holder_house")}
{"barn_40"			("territory_holder_house")}
{"barn_50"			("territory_holder_house")}
{"barn_60"			("territory_holder_house")}
{"build_ua_01"		("territory_holder_house")}
{"build_ua_02"		("territory_holder_house")}
{"build_ua_03"		("territory_holder_house")}
{"build_ua_04"		("territory_holder_house")}
{"build_ua_05"		("territory_holder_house")}
{"build_ua_06"		("territory_holder_house")}
{"build_ua_08"		("territory_holder_house")}
{"build_ua_07"		("territory_holder_house")}
{"build_vil_001"	("territory_holder_house")}
{"build_vil_004"	("territory_holder_house")}
{"build_vil_003"	("territory_holder_house")}
{"build_vil_004"	("territory_holder_house")}
{"house_uk_001"	    ("territory_holder_house")}
{"barn_ger01"	    ("territory_holder_house")}
{"house_ger01"	    ("territory_holder_house")}
{"house_ger02"	    ("territory_holder_house")}
{"house_ger03"	    ("territory_holder_house")}
{"house_ger04"	    ("territory_holder_house")}
{"house_ger05"	    ("territory_holder_house")}
{"house_ger06"	    ("territory_holder_house")}
{"house_ger07"	    ("territory_holder_house")}
{"house_ger08"	    ("territory_holder_house")}
{"france_mill"	    ("territory_holder_house")}
{"station001"	    ("territory_holder_house")}
{"station002"	    ("territory_holder_house")}
{"station003"	    ("territory_holder_house")}
{"station004"	    ("territory_holder_house")}
{"control_office_001"	    ("territory_holder_house")}
{"water_tower_001"	    ("territory_holder_house")}

;builds
{"med_point"	    ("territory_holder_house")}

;[bunker]_____________________________________________________________________________________________________________________________________________________________________
{"kiur_bunker_001"		("territory_holder_bunker")}
{"kiur_bunker_002"		("territory_holder_bunker")}
{"kiur_bunker_003"		("territory_holder_bunker")}
{"dot2_v"				("territory_holder_bunker")}
{"dot_small"			("territory_holder_bunker")}
{"dot_small_buid"		("territory_holder_bunker")}
{"dot_wood"				("territory_holder_bunker")}
{"dot_wood_buid"		("territory_holder_bunker")}
{"blindage_wood"		("territory_holder_сommand_post")}

;[Helpers]________________________________________________________________________________________________________________________________________________________________________

;[Helpers]________________________________________________________________________________________________________________________________________________________________________
{"fog_open_point"			cw{0}}
{"tagged_piece"				cw{0}}
{"missionwp"				cw{0}}
{"paratrooper_attach"		cw{0}}
{"parachute_lg40_box"		cw{0}}
{"air_strike_target"		cw{0}}
{"frontline_break"			cw{0}}
{"icon_object"				cw{0}}
{"structure_object"			cw{0}}
{"capture_object"			("territory_holder_helper")}


;UNSORTED___________________________________________________________________________________________________________________________________________________________________
{"radar_mount"			("set_vs"	lvl(1) tag(all art_point level_1)	side(ger)	n(1)	sc(20)	cw(s1) cp(0)	th(gun))}