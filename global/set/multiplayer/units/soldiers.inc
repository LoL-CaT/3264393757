;SDL
;==============================		SET		==================================
(define "set_breed"
	{tags   "%name %side man %tag"}
	("score" sc(%sc))
	{cp %cp}
	{order  10}
	{basic}
	{breed}
	{side "%side"}
	("cw_%cw")
	{cost 1}
	("spawn_distance_%sd")
)
(define "auto_recovering_time"
	{auto_recovering_time  540}
)
(define "set_breed_auto"
	("set_breed"								name(%name)	side(%side) tag(%tag)	sc(%sc)	cp(%cp)	cw(%cw)	sd(%sd))
	("auto_recovering_time")
)
(define "set_breed_withdrawn"
	("set_breed"								name(%name)	side(%side) tag(%tag)	sc(%sc)	cp(%cp)	cw(%cw)	sd(%sd))
	{withdrawn_instant_recovery}
)
(define "set_breed_withdrawn_sale"
	("set_breed_withdrawn"						name(%name)	side(%side) tag(%tag)	sc(%sc)	cp(%cp)	cw(%cw)	sd(%sd))
	{not_for_sale}
)
(define "set_breed_auto_cw"
	("set_breed_auto"							name(%name)	side(%side) tag(%tag)	sc(%sc)	cp(%cp)	cw(%cw)	sd(%sd))
	{cw_ignore_owner}
)

;============================== MAIN_DEFINES ==================================
;Примечание:
;	tag(reg) и sd(default) - не отмечаются в имени макроса, т.к эти значения принимаются по умолчанию

(define "dusty_faces"
	{"arena_mp/%side/dusty_faces/%name"
		("set_breed%set"	name(%name)	side(%side)	tag(%tag)	sc(%sc)	cp(%cp)	cw(%cw)	sd(%sd))
	}
)
(define "narrator"
	{"special/narrator/%side/%name"
		("set_breed%set"	name(%name)	side(%side)	tag(%tag)	sc(%sc)	cp(%cp)	cw(%cw)	sd(%sd))
	}
)
(define "hero"
	{"special/heroes/%name"
		("set_breed%set"	name(%name)	side(%side)	tag(%tag)	sc(%sc)	cp(%cp)	cw(%cw)	sd(%sd))
	}
)
(define "dusty_faces_g"			("dusty_faces"		set()				name(%name)	side(ger)	tag(reg)	sc(%sc)	cp(%cp)	cw(%cw)	sd(default)))
(define "hero_r"				("hero"		set()				name(%name)	side(rus)	tag(reg)	sc(%sc)	cp(%cp)	cw(%cw)	sd(default)))
(define "narrator_r"			("narrator"	set()				name(%name)	side(rus)	tag(reg)	sc(%sc)	cp(%cp)	cw(%cw)	sd(default)))
(define "breed"
	{"arena_mp/%side/%name"
		("set_breed%set"	name(%name)	side(%side) tag(%tag)	sc(%sc)	cp(%cp)	cw(%cw)	sd(%sd))
	}
)
(define "breed_g"				("breed"	set()				name(%name)	side(ger)	tag(reg)	sc(%sc)	cp(%cp)	cw(%cw)	sd(default)))
(define "breed_auto_g"			("breed"	set(_auto)			name(%name)	side(ger)	tag(reg)	sc(%sc)	cp(%cp)	cw(%cw)	sd(default)))
(define "breed_spe_g"			("breed"	set()				name(%name)	side(ger)	tag(spe)	sc(%sc)	cp(%cp)	cw(%cw)	sd(default)))

(define "breed_r"				("breed"	set()				name(%name)	side(rus)	tag(reg)	sc(%sc)	cp(%cp)	cw(%cw)	sd(default)))
(define "breed_auto_r"			("breed"	set(_auto)			name(%name)	side(rus)	tag(reg)	sc(%sc)	cp(%cp)	cw(%cw)	sd(default)))
(define "breed_auto_spe_r"		("breed"	set(_auto)			name(%name)	side(rus)	tag(spe)	sc(%sc)	cp(%cp)	cw(%cw)	sd(default)))

(define "breed_u"				("breed"	set()				name(%name)	side(usa)	tag(reg)	sc(%sc)	cp(%cp)	cw(%cw)	sd(default)))
(define "breed_auto_u"			("breed"	set(_auto)			name(%name)	side(usa)	tag(reg)	sc(%sc)	cp(%cp)	cw(%cw)	sd(default)))
(define "breed_auto_cw_u"		("breed"	set(_auto_cw)		name(%name)	side(usa)	tag(reg)	sc(%sc)	cp(%cp)	cw(%cw)	sd(default)))

(define "breed_e"				("breed"	set()				name(%name)	side(eng)	tag(reg)	sc(%sc)	cp(%cp)	cw(%cw)	sd(default)))
(define "breed_j"				("breed"	set()				name(%name)	side(jap)	tag(reg)	sc(%sc)	cp(%cp)	cw(%cw)	sd(default)))

(define "temp_g_r"
	("breed"								set(%set)			name(%name)	side(ger)	tag(%tag)	sc(%sc)	cp(%cp)	cw(%cw)	sd(%sd))
	("breed"								set(%set)			name(%name)	side(rus)	tag(%tag)	sc(%sc)	cp(%cp)	cw(%cw)	sd(%sd))
)
(define "breeds_g_r"
	("temp_g_r"								set()				name(%name)				tag(reg)	sc(%sc)	cp(%cp)	cw(%cw)	sd(default))
)
(define "breeds_auto_g_r"
	("temp_g_r"								set(_auto)			name(%name)				tag(reg)	sc(%sc)	cp(%cp)	cw(%cw)	sd(default))
)

(define "temp_r_u"
	("breed"								set(%set)			name(%name)	side(rus)	tag(%tag)	sc(%sc)	cp(%cp)	cw(%cw)	sd(%sd))
	("breed"								set(%set)			name(%name)	side(usa)	tag(%tag)	sc(%sc)	cp(%cp)	cw(%cw)	sd(%sd))
)
(define "breeds_r_u"
	("temp_r_u"								set()				name(%name)				tag(reg)	sc(%sc)	cp(%cp)	cw(%cw)	sd(default))
)
(define "breeds_auto_r_u"
	("temp_r_u"								set(_auto)			name(%name)				tag(reg)	sc(%sc)	cp(%cp)	cw(%cw)	sd(default))
)

(define "temp_g_r_u"
	("breed"								set(%set)			name(%name)	side(ger)	tag(%tag)	sc(%sc)	cp(%cp)	cw(%cw)	sd(%sd))
	("breed"								set(%set)			name(%name)	side(rus)	tag(%tag)	sc(%sc)	cp(%cp)	cw(%cw)	sd(%sd))
	("breed"								set(%set)			name(%name)	side(usa)	tag(%tag)	sc(%sc)	cp(%cp)	cw(%cw)	sd(%sd))
)
(define "breeds_g_r_u"
	("temp_g_r_u"							set()				name(%name)				tag(reg)	sc(%sc)	cp(%cp)	cw(%cw)	sd(default))
)
(define "breeds_auto_g_r_u"
	("temp_g_r_u"							set(_auto)			name(%name)				tag(reg)	sc(%sc)	cp(%cp)	cw(%cw)	sd(default))
)
(define "breeds_auto_spe_g_r_u"
	("temp_g_r_u"							set(_auto)			name(%name)				tag(spe)	sc(%sc)	cp(%cp)	cw(%cw)	sd(default))
)
(define "breeds_auto_cw_g_r_u"
	("temp_g_r_u"							set(_auto_cw)		name(%name)				tag(reg)	sc(%sc)	cp(%cp)	cw(%cw)	sd(default))
)
(define "breeds_spe_g_r_u"
	("temp_g_r_u"							set()				name(%name)				tag(spe)	sc(%sc)	cp(%cp)	cw(%cw)	sd(default))
)
(define "breeds_spe_corpsman_g_r_u"
	("temp_g_r_u"							set()				name(%name)				tag(spe)	sc(%sc)	cp(%cp)	cw(%cw)	sd(corpsman))
)
(define "breeds_withdrawn_g_r_u"
	("temp_g_r_u"							set(_withdrawn)		name(%name)				tag(reg)	sc(%sc)	cp(%cp)	cw(%cw)	sd(default))
)
(define "breeds_withdrawn_sale_spe_g_r_u"
	("temp_g_r_u"							set(_withdrawn_sale)	name(%name)			tag(spe)	sc(%sc)	cp(%cp)	cw(%cw)	sd(default))
)
(define "breeds_withdrawn_sale_corpsman_g_r_u"
	("temp_g_r_u"							set(_withdrawn_sale)	name(%name)			tag(reg)	sc(%sc)	cp(%cp)	cw(%cw)	sd(corpsman))
)

(define "temp_g_r_u_e_j"
	("breed"								set(%set)	name(%name)	side(ger)	tag(%tag)	sc(%sc)	cp(%cp)	cw(%cw)	sd(%sd))
	("breed"								set(%set)	name(%name)	side(rus)	tag(%tag)	sc(%sc)	cp(%cp)	cw(%cw)	sd(%sd))
	("breed"								set(%set)	name(%name)	side(usa)	tag(%tag)	sc(%sc)	cp(%cp)	cw(%cw)	sd(%sd))
	("breed"								set(%set)	name(%name)	side(eng)	tag(%tag)	sc(%sc)	cp(%cp)	cw(%cw)	sd(%sd))	
	("breed"								set(%set)	name(%name)	side(jap)	tag(%tag)	sc(%sc)	cp(%cp)	cw(%cw)	sd(%sd))		
)
(define "breeds_g_r_u_e_j"
	("temp_g_r_u_e_j"						set()		name(%name)				tag(reg)	sc(%sc)	cp(%cp)	cw(%cw)	sd(default))
)
(define "breeds_spe_g_r_u_e_j"
	("temp_g_r_u_e_j"						set()		name(%name)				tag(spe)	sc(%sc)	cp(%cp)	cw(%cw)	sd(default))
)
(define "breeds_auto_spe_g_r_u_e_j"
	("temp_g_r_u_e_j"						set(_auto)	name(%name)				tag(spe)	sc(%sc)	cp(%cp)	cw(%cw)	sd(default))
)
;___________________________________________________________________________________________________________________________________________________________________________

;assault_soldier
("breeds_g_r_u"						name(assault_commander)				sc(6.14)	cp(0.7)	cw(s4))
("breeds_g_r_u"						name(light_assault_commander)		sc(5.2)		cp(0.7)	cw(s4))
("breeds_g_r_u"						name(heavy_assault_commander)		sc(6.1)		cp(0.7)	cw(s4))
("breeds_g_r_u"						name(assault_rifle_rookie)			sc(6.14)	cp(0.7)	cw(s4))
("breeds_g_r_u"						name(light_assault_rifle_rookie)	sc(5.2)		cp(0.7)	cw(s4))
("breeds_g_r_u"						name(heavy_assault_rifle)			sc(6.1)		cp(0.7)	cw(s4))
("breeds_g_r_u"						name(assault_smg_rookie)			sc(6.14)	cp(0.7)	cw(s4))
("breeds_g_r_u"						name(light_assault_smg_rookie)		sc(5.2)		cp(0.7)	cw(s4))
("breeds_g_r_u"						name(heavy_assault_smg)				sc(6.1)		cp(0.7)	cw(s4))
("breeds_g_r_u"						name(assault_mgun)					sc(6.14)	cp(0.7)	cw(s4))
("breeds_g_r_u"						name(heavy_assault_mgun)			sc(6.1)		cp(0.7)	cw(s4))
("breeds_g_r_u"						name(assault_at_rifle)				sc(6.14)	cp(0.7)	cw(s4))
("breeds_g_r_u"						name(heavy_assault_bazooker)		sc(6.1)		cp(0.7)	cw(s4))
("breed_u"							name(light_assault_commander_fra)   sc(5.2)	cp(0.7)	cw(s4))
("breed_u"							name(light_assault_rifle_rookie_fra)   sc(5.2)	cp(0.7)	cw(s4))
("breed_u"							name(light_assault_smg_rookie_fra)   sc(5.2)		cp(0.7)	cw(s4))

;apc_troopers
("breed_auto_g"						name(apc_opel_blitz_mgun_commander)	sc(3.5)		cp(1)	cw(s4))
("breed_auto_g"						name(apc_opel_blitz_mgun_rifle)		sc(3.5)		cp(1)	cw(s4))
("breed_auto_g"						name(apc_opel_blitz_mgun_smg)		sc(5.25)	cp(1)	cw(s4))
("breed_auto_g"						name(apc_opel_blitz_commander)		sc(4.17)	cp(1)	cw(s4))
("breed_auto_g"						name(apc_opel_blitz_rifle)			sc(4.17)	cp(1)	cw(s4))
("breed_auto_g"						name(apc_opel_blitz_smg)			sc(6.25)	cp(1)	cw(s4))
("breed_auto_g"						name(apc_251_1_commander)			sc(5)		cp(1)	cw(s4))
("breed_auto_g"						name(apc_251_1_rifle)				sc(5)		cp(1)	cw(s4))
("breed_auto_g"						name(apc_251_1_smg)					sc(7.5)		cp(1)	cw(s4))
("breed_auto_g"						name(apc_251_10_commander)			sc(4.5)		cp(1)	cw(s4))
("breed_auto_g"						name(apc_251_10_rifle)				sc(4.5)		cp(1)	cw(s4))
("breed_auto_g"						name(apc_251_10_smg)				sc(6.75)	cp(1)	cw(s4))
("breed_auto_r"						name(apc_gaz_aa_commander)			sc(4.17)	cp(1)	cw(s4))
("breed_auto_r"						name(apc_gaz_aa_rifle)				sc(4.17)	cp(1)	cw(s4))
("breed_auto_r"						name(apc_gaz_aa_smg)				sc(6.25)	cp(1)	cw(s4))
("breeds_auto_r_u"					name(apc_m3a1_commander)			sc(5.33)	cp(1)	cw(s4))
("breeds_auto_r_u"					name(apc_m3a1_rifle)				sc(5.33)	cp(1)	cw(s4))
("breeds_auto_r_u"					name(apc_m3a1_smg)					sc(8)		cp(1)	cw(s4))
("breeds_auto_r_u"					name(apc_m3a2_commander)			sc(5.33)	cp(1)	cw(s4))
("breeds_auto_r_u"					name(apc_m3a2_rifle)				sc(5.33)	cp(1)	cw(s4))
("breeds_auto_r_u"					name(apc_m3a2_smg)					sc(8)		cp(1)	cw(s4))
("breeds_auto_r_u"					name(apc_t20_commander)				sc(5.33)	cp(1)	cw(s4))
("breeds_auto_r_u"					name(apc_t20_rifle)					sc(5.33)	cp(1)	cw(s4))
("breeds_auto_r_u"					name(apc_t20_smg)					sc(8)		cp(1)	cw(s4))
("breed_auto_u"						name(apc_gmc_commander)				sc(5)		cp(1)	cw(s4))
("breed_auto_u"						name(apc_gmc_rifle)					sc(5)		cp(1)	cw(s4))
("breed_auto_u"						name(apc_gmc_smg)					sc(5)		cp(1)	cw(s4))
("breed_auto_u"						name(apc_uc_commander)				sc(5.33)	cp(1)	cw(s4))
("breed_auto_u"						name(apc_uc_rifle)					sc(5.33)	cp(1)	cw(s4))
("breed_auto_u"						name(apc_uc_smg)					sc(8)		cp(1)	cw(s4))

;tank_troopers
("breed_auto_g"						name(apc_pz4f2_commander)			sc(8.6)		cp(2)	cw(s5))
("breed_auto_g"						name(apc_pz4f2_rifle) 				sc(8.6)		cp(2)	cw(s5))
("breed_auto_g"						name(apc_pz4f2_smg) 				sc(8.6)		cp(2)	cw(s5))
("breed_auto_g"						name(apc_pz4g_grenadier)			sc(8.6)		cp(2)	cw(s5))
("breed_auto_r"						name(apc_t34_76_commander)			sc(8.6)		cp(2)	cw(s5))
("breed_auto_r"						name(apc_t34_76_rifle)				sc(8.6)		cp(2)	cw(s5))
("breed_auto_r"						name(apc_t34_76_smg) 				sc(8.6)		cp(2)	cw(s5))
("breed_auto_r"						name(apc_t34_2_sturmovik) 			sc(8.6)		cp(2)	cw(s5))
("breed_auto_u"						name(apc_m4a1_commander)			sc(8.6)		cp(2)	cw(s5))
("breed_auto_u"						name(apc_m4a1_rifle) 				sc(8.6)		cp(2)	cw(s5))
("breed_auto_u"						name(apc_m4a1_smg) 					sc(8.6)		cp(2)	cw(s5))
("breed_auto_u"						name(apc_m4a3dd_marine) 			sc(8.6)		cp(2)	cw(s5)))

("breeds_spe_g_r_u_e_j"				name(tankman)						sc(1)		cp(0)	cw(s0))
("breed_auto_g"						name(tankman_officer) 				sc(3)		cp(0)	cw(s0))

;miner
("breeds_withdrawn_g_r_u"			name(antipersonel_miner)			sc(7)		cp(0)	cw(s0))
("breeds_withdrawn_g_r_u"			name(antitank_miner)				sc(7)		cp(0)	cw(s0))
("breeds_withdrawn_g_r_u"			name(universal_miner)				sc(7)		cp(0)	cw(s0))

;artilleryman
("breeds_spe_g_r_u_e_j"				name(artilleryman)					sc(2)		cp(0)	cw(s0))
("breed_spe_g"						name(artilleryman_paratrooper)		sc(2)		cp(0)	cw(s0))


("breeds_spe_g_r_u"					name(pilot)							sc(3)		cp(0)	cw(s0))

("breeds_spe_g_r_u"					name(creep)							sc(3)		cp(0)	cw(s4))

("breeds_spe_g_r_u"					name(artilleryman_veh)				sc(2)		cp(0)	cw(s4))

;at_rifle
("breeds_g_r_u"						name(at_rifle)						sc(2)		cp(1)	cw(s4))
("breed_r"							name(at_rifle_ptrs)					sc(3)		cp(1)	cw(s4))
("breed_g"							name(at_rifle_solothurn)			sc(4)		cp(1)	cw(s4))

;rifle_grenadiers
("breed_r"							name(rifle_grenadier)				sc(4)		cp(1)	cw(s4))

;at_squad
("breed_g"							name(rifle_panzerfaust)				sc(3)		cp(1)	cw(s4))
("breed_r"							name(bottle_thrower)				sc(5)		cp(1)	cw(s4))

("breeds_r_u"						name(bomberman)						sc(3)		cp(1)	cw(s4))

("breeds_g_r_u"						name(bazooker)						sc(5)		cp(1)	cw(s4))
("breed_u"							name(bazooker_m18)					sc(9.9)		cp(1)	cw(s4))

;edelweiss
("breed_auto_g"						name(edelweiss)						sc(11.8)		cp(2)	cw(s5))
("breed_auto_g"						name(edelweiss_g43)					sc(11.8)		cp(2)	cw(s5))
("breed_auto_g"						name(edelweiss_fg42)				sc(11.8)		cp(2)	cw(s5))
("breed_auto_g"						name(edelweiss_mgun)				sc(11.8)		cp(2)	cw(s5))

("breed_auto_g"						name(grenadier)						sc(11.8)		cp(2)	cw(s5))
("breed_auto_g"						name(grenadier_mgun)				sc(11.8)		cp(2)	cw(s5))
("breed_auto_g"						name(grenadier_pfaust)				sc(11.8)		cp(2)	cw(s5))

("breed_auto_r"						name(marine_avs)					sc(11.8)		cp(2)	cw(s5))

("breeds_auto_r_u"					name(marine)						sc(11.8)		cp(2)	cw(s5))
("breeds_auto_r_u"					name(marine_mgun)					sc(11.8)		cp(2)	cw(s5))

("breed_auto_u"						name(marine_bar)					sc(11.8)		cp(2)	cw(s5))
("breed_auto_u"						name(marine_radioman)				sc(11.8)		cp(2)	cw(s5))

("breeds_withdrawn_sale_spe_g_r_u"	name(engineer)						sc(3)		cp(0)	cw(s0))

("breeds_spe_corpsman_g_r_u"		name(flamer)						sc(9)		cp(1)	cw(s4))

;mgun
("breeds_auto_g_r_u"				name(mgun)							sc(6)		cp(1)	cw(s4))
("breed_auto_g"						name(mgun_late)						sc(7.4)		cp(1)	cw(s4))
("breeds_auto_r_u"					name(mgun_late)						sc(7.2)		cp(1)	cw(s4))
("breed_auto_g"						name(mgun_mg26)						sc(6.2)		cp(1)	cw(s4))

("breeds_auto_g_r_u"				name(mgun_supporter)				sc(6)		cp(1)	cw(s4))
("breed_auto_g"						name(mgun_supporter_late)			sc(7.4)		cp(1)	cw(s4))
("breeds_auto_r_u"					name(mgun_supporter_late)			sc(7.2)		cp(1)	cw(s4))
("breed_auto_g"						name(mgun_supporter_mg26)			sc(6.2)		cp(1)	cw(s4))

("breed_auto_g"						name(storm_commander)				sc(4.8)		cp(1)	cw(s4))
("breeds_auto_g_r_u"				name(mgun_commander)				sc(6.2)		cp(1)	cw(s4))

("breed_auto_g"						name(mgun_commander_late)			sc(7.4)		cp(1)	cw(s4))
("breeds_auto_r_u"					name(mgun_commander_late)			sc(7.2)		cp(1)	cw(s4))
("breed_auto_g"						name(mgun_commander_mg26)			sc(6.2)		cp(1)	cw(s4))


("breeds_auto_cw_g_r_u"				name(paratrooper)					sc(6.6)		cp(2)	cw(sp))
("breeds_auto_cw_g_r_u"				name(paratrooper_mgun)				sc(6.6)		cp(2)	cw(sp))

("breed_auto_cw_u"					name(paratrooper_elite)				sc(14.5)	cp(2)	cw(sp))
("breed_auto_cw_u"					name(paratrooper_elite_smg)			sc(14.5)	cp(2)	cw(sp))
("breed_auto_cw_u"					name(paratrooper_elite_mgun)		sc(14.5)	cp(2)	cw(sp))

;rifle
("breed_g"							name(storm_rifle)					sc(4.6)		cp(1)	cw(s6))
("breeds_g_r_u"						name(rifle)							sc(4)		cp(1)	cw(s6))
("breeds_g_r_u"						name(rifle_rookie)					sc(3)		cp(1)	cw(s6))
("breeds_g_r_u"						name(rifle_veteran)					sc(6.3)		cp(1)	cw(s6))
("breed_r"							name(rifle_reserv)					sc(4)		cp(1)	cw(s6))

;special infantry
("breeds_auto_spe_g_r_u"			name(saboteur)						sc(10.71)	cp(2)	cw(s0))
("breeds_auto_spe_g_r_u"			name(saboteur_smg)					sc(10.71)	cp(2)	cw(s0))
("breeds_auto_spe_g_r_u"			name(saboteur_sniper)				sc(10.71)	cp(2)	cw(s0))

("breeds_auto_spe_g_r_u_e_j"		name(arty_spotter)					sc(8.8)		cp(2)	cw(s0))

("breeds_g_r_u"						name(officer)						sc(17)		cp(2)	cw(officer))
("breeds_spe_g_r_u"					name(scout)							sc(8)		cp(2)	cw(s0))
("breeds_spe_g_r_u"					name(apc_m3scout_scout)				sc(10)		cp(2)	cw(s0))
("breeds_spe_g_r_u"					name(apc_m3scout_gunner)			sc(1)		cp(0)	cw(s0))
("breeds_spe_g_r_u"					name(apc_m3scout_driver)			sc(1)		cp(0)	cw(s0))

;support
("breeds_g_r_u"						name(saper)							sc(3)		cp(1)	cw(s0))

("breeds_g_r_u"						name(saper_veteran)					sc(6.3)		cp(1)	cw(s0))

("breed_g"							name(sturmpioneer_commander)		sc(9.25)		cp(1)	cw(s6))
("breed_g"							name(sturmpioneer_flamer)			sc(9.25)		cp(1)	cw(s0))
("breed_g"							name(sturmpioneer_saper)			sc(9.25)		cp(1)	cw(s0))
("breed_g"							name(sturmpioneer_mgun)				sc(9.25)		cp(1)	cw(s0))
("breed_g"							name(sturmpioneer_radioman)			sc(9.25)		cp(1)	cw(s0))

("breeds_withdrawn_sale_corpsman_g_r_u"	name(corpsman)					sc(2)		cp(0)	cw(s0))
("breeds_g_r_u"						name(combat_medic)					sc(4)		cp(1)	cw(s0))

;smg
("breed_g"							name(storm_smg)						sc(4.8)		cp(1)	cw(s4))
("breeds_g_r_u"						name(smg)							sc(6)		cp(1)	cw(s4))
("breeds_g_r_u"						name(smg_rookie)					sc(4)		cp(1)	cw(s4))
("breed_r"							name(smg_rookie_ppd)				sc(4)		cp(1)	cw(s4))
("breeds_g_r_u"						name(smg_veteran)					sc(9.45)	cp(1)	cw(s4))

("breeds_spe_g_r_u"					name(sniper)						sc(14)		cp(2)	cw(s0))
("breed_spe_g"						name(jaeger_sniper)					sc(16.8)	cp(2)	cw(s0))
("breeds_spe_g_r_u"					name(sniper_elite)					sc(25)		cp(2)	cw(s0))

("breed_auto_g"						name(ss)							sc(14.5)	cp(2)	cw(s5))
("breed_auto_g"						name(ss_faust)						sc(14.5)	cp(2)	cw(s5))
("breed_auto_g"						name(ss_mgun)						sc(14.5)	cp(2)	cw(s5))
("breed_auto_g"						name(ss_driver)						sc(14.5)	cp(0)	cw(s5));ss_rifle	; не учитывается в бре отряда
("breed_auto_g"						name(ss_rifle)						sc(7.5)		cp(0)	cw(s5));ss_rifle	; не учитывается в бре отряда


("breed_auto_r"						name(sturmovik)						sc(14.5)	cp(2)	cw(s5))
("breed_auto_spe_r"					name(sturmovik_flame)				sc(14.5)	cp(2)	cw(s5))
("breed_auto_r"						name(sturmovik_mgun)				sc(14.5)	cp(2)	cw(s5))
("breed_auto_r"						name(sturmovik_atr)					sc(14.5)	cp(2)	cw(s5))
("breed_auto_r"						name(sturmovik_rifle)				sc(14.5)	cp(2)	cw(s5))
("breed_auto_u"						name(ranger)						sc(14.5)	cp(2)	cw(s5))
("breed_auto_u"						name(ranger_shotgun)				sc(14.5)	cp(2)	cw(s5))
("breed_auto_u"						name(ranger_mgun)					sc(14.5)	cp(2)	cw(s5))

("breeds_g_r_u"						name(hunter)						sc(3)	cp(1)	cw(s0))

("breed_u"							name(mp)							sc(2)	cp(1)	cw(s0))
("breed_u"							name(mp_driver)						sc(1)	cp(0)	cw(s0))
("breed_u"							name(mp_gunner)						sc(1)	cp(0)	cw(s0))
("breed_u"							name(mp_veteran)					sc(8)	cp(1)	cw(s0))

;hunter_ai
("breeds_g_r_u"						name(hunter_ai)						sc(6.16)	cp(0.7)	cw(s7))
("breeds_g_r_u"						name(hunter_ai_commander)			sc(6.16)	cp(0.7)	cw(s7))
("breeds_g_r_u"						name(hunter_ai_overwatch)			sc(6.16)	cp(0.5)	cw(s7))

("breed_g"							name(ur_squad_at_rifle)				sc(6.16)	cp(1)	cw(s4))
("breed_g"							name(ur_squad_commander)			sc(6.16)	cp(1)	cw(s4))
("breed_g"							name(ur_squad_saper)				sc(6.16)	cp(1)	cw(s4))
("breed_g"							name(ur_squad_supporter)			sc(6.16)	cp(1)	cw(s4))

("breed_auto_g"						name(brandenburger_commander)		sc(10.35)	cp(2)	cw(s0))
("breed_auto_g"						name(brandenburger_driver)			sc(9)		cp(0)	cw(s0));premium_squad_free	; не учитывается в бре отряда
("breed_auto_g"						name(brandenburger_sniper)			sc(16.1)	cp(2)	cw(s0))
("breed_auto_g"						name(brandenburger_rifle)			sc(6)		cp(0)	cw(s0));premium_squad_free	; не учитывается в бре отряда
("breed_auto_g"						name(brandenburger_smg)				sc(10.35)	cp(2)	cw(s0))
("breed_auto_g"						name(brandenburger_radioman)		sc(9.2)		cp(2)	cw(s0))

("breed_auto_r"						name(nkvd_commander)				sc(10)	cp(2)	cw(s0))
("breed_auto_r"						name(nkvd_rifle)					sc(7)	cp(2)	cw(s0))
("breed_auto_r"						name(nkvd_smg)						sc(10)	cp(2)	cw(s0))
("breed_auto_r"						name(nkvd_mgun)						sc(10)	cp(2)	cw(s0))
("breed_auto_r"						name(nkvd_sniper)					sc(14)	cp(2)	cw(s0))

("breed_auto_u"						name(devil_mgun)					sc(6.3)	cp(2)	cw(s0))
("breed_auto_u"						name(devil_rifle)					sc(6.3)	cp(2)	cw(s0))
("breed_auto_u"						name(devil_sniper)					sc(6.3)	cp(2)	cw(s0))
("breed_auto_u"						name(devil_bazooker)				sc(6.3)	cp(2)	cw(s0))
("breed_auto_u"						name(devil_commander)				sc(6.3)	cp(2)	cw(s0))
("breed_auto_u"						name(devil_saboteur)				sc(6.3)	cp(2)	cw(s0))
("breed_auto_u"						name(devil_driver)					sc(6.3)	cp(0)	cw(s0))

("breed_g"							name(patrol_commander)				sc(6.3)	cp(1)	cw(s6))
("breed_g"							name(patrol_saper)					sc(6.3)	cp(1)	cw(s0))
("breed_g"							name(patrol_mgun)					sc(6.3)	cp(1)	cw(s0))
("breed_g"							name(patrol_smg)					sc(6.3)	cp(1)	cw(s0))
("breed_g"							name(patrol_smg2)					sc(6.3)	cp(1)	cw(s0))

;elite_apc_infantry
("breed_auto_u"						name(guard_bazooker)			sc(6.82)		cp(2) cw(s4))
("breed_auto_u"						name(guard_commander)			sc(6.82)		cp(2) cw(s4))
("breed_auto_u"						name(guard_driver)				sc(6.82)		cp(0) cw(s4))
("breed_auto_u"						name(guard_gunner)				sc(6.82)		cp(0) cw(s4))
("breed_auto_u"						name(guard_mgun)				sc(6.82)		cp(2) cw(s4))
("breed_auto_u"						name(guard_rifle)				sc(6.82)		cp(2) cw(s4))

("breed_auto_r"						name(guard_commander)			sc(6.82)		cp(2) cw(s5))
("breed_auto_r"						name(guard_driver)				sc(6.82)		cp(0) cw(s5))
("breed_auto_r"						name(guard_gunner)				sc(6.82)		cp(0) cw(s5))
("breed_auto_r"						name(guard_mgun)				sc(6.82)		cp(2) cw(s5))
("breed_auto_r"						name(guard_rifle)				sc(6.82)		cp(2) cw(s5))
("breed_auto_r"						name(guard_smg)					sc(6.82)		cp(2) cw(s5))
("breed_auto_r"						name(guard_sniper)				sc(6.82)		cp(2) cw(s5))

;---------------------------SPECIAL-----------------------------
("hero_r"							name(saboteur_rus_hero)				sc(7.5)	cp(0)	cw(s0))
("narrator_r"						name(correspondent_rizin)			sc(3)	cp(0)	cw(s0))

("dusty_faces_g"					name(degen)							sc(7)	cp(1)	cw(s4)))
("dusty_faces_g"					name(feldmann)						sc(7)	cp(1)	cw(s4)))
("dusty_faces_g"					name(freischmidt)					sc(7)	cp(1)	cw(s4)))
("dusty_faces_g"					name(fuchs)							sc(7)	cp(1)	cw(s4)))
("dusty_faces_g"					name(ilgen)							sc(7)	cp(1)	cw(s4)))
("dusty_faces_g"					name(jansen)						sc(7)	cp(1)	cw(s4)))
("dusty_faces_g"					name(kowalski)						sc(7)	cp(1)	cw(s4)))
("dusty_faces_g"					name(kruger)						sc(7)	cp(1)	cw(s4)))
("dusty_faces_g"					name(lischewski)					sc(7)	cp(1)	cw(s4)))
