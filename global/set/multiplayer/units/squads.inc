;SDL
;------------------------------------------------------------------------------
;	Содержимое content поля:
; 		content поле содержит список unitId (bread или entity). 
;		Символ ':' после unitId указывает на количество юнитов данного типа.
;		Символ '*' указывает на id текущего блока юнита. 
;		Юниты в круглых скобках будут посажены(прилинкованы) к юниту указанному перед '(' скобкой.
;		Спец символы '*','(',')' обязательно должны быть окружены пробелами!
;		Первый в списке юнит становиться командиром. 
;------------------------------------------------------------------------------
;
;	Пример:	{"t34m"	{content "mp/rus/oficer * ( mp/rus/tankman:4 ) m72 ( mp/rus/smg:3 ) mp/rus/sturmovik:2"}}
;								
;		mp/rus/oficer - будет командиром
;		'*' заменяется на t34m
;		mp/rus/tankman:4 - 4 танкиста, экипаж t34m
;		mp/rus/smg:3 - 3 smg-ника, разъезжающие на m72
;		mp/rus/sturmovik:2 - 2 штурмовика, чтоб офицеру не было скучно :)
;
;------------------------------------------------------------------------------

;================================ CONTENT =====================================

(define "content_fighters_light_bot"
	{content "arena_mp/%side/light_assault_commander:1 arena_mp/%side/light_assault_rifle_rookie:2 arena_mp/%side/light_assault_smg_rookie:2"}
)
(define "content_fighters_bot"
	{content "arena_mp/%side/assault_commander:1 arena_mp/%side/assault_rifle_rookie:2 arena_mp/%side/assault_smg_rookie:2 arena_mp/%side/assault_mgun:1 arena_mp/%side/assault_at_rifle:1"}
)
(define "content_fighters_heavy_bot"
	{content "arena_mp/%side/heavy_assault_commander:1 arena_mp/%side/heavy_assault_rifle:3 arena_mp/%side/heavy_assault_smg:3 arena_mp/%side/heavy_assault_mgun:2 arena_mp/%side/heavy_assault_bazooker:1"}
)
(define "content_fighters_light"
	{content "arena_mp/%side/light_assault_smg_rookie arena_mp/%side/light_assault_rifle_rookie arena_mp/%side/light_assault_commander arena_mp/%side/light_assault_rifle_rookie arena_mp/%side/light_assault_smg_rookie"}
)
(define "content_fighters_light_fra"
	{content "arena_mp/%side/light_assault_smg_rookie_fra arena_mp/%side/light_assault_rifle_rookie_fra arena_mp/%side/light_assault_commander_fra arena_mp/%side/light_assault_rifle_rookie_fra arena_mp/%side/light_assault_smg_rookie_fra"}
)
(define "content_fighters"
	{content "arena_mp/%side/assault_smg_rookie arena_mp/%side/assault_rifle_rookie arena_mp/%side/assault_mgun arena_mp/%side/assault_commander arena_mp/%side/assault_at_rifle arena_mp/%side/assault_rifle_rookie arena_mp/%side/assault_smg_rookie"}
)
(define "content_fighters_heavy"
	{content "arena_mp/%side/heavy_assault_smg arena_mp/%side/heavy_assault_rifle arena_mp/%side/heavy_assault_rifle arena_mp/%side/heavy_assault_mgun arena_mp/%side/heavy_assault_commander arena_mp/%side/heavy_assault_mgun arena_mp/%side/heavy_assault_bazooker arena_mp/%side/heavy_assault_rifle arena_mp/%side/heavy_assault_smg arena_mp/%side/heavy_assault_smg"}
)
(define "content_ai_hunters"
	{content "arena_mp/%side/hunter_ai arena_mp/%side/hunter_ai arena_mp/%side/hunter_ai_commander arena_mp/%side/hunter_ai_overwatch arena_mp/%side/hunter_ai arena_mp/%side/hunter_ai"}
)
(define "content_ur_squad"
	{content "arena_mp/%side/ur_squad_supporter arena_mp/%side/ur_squad_at_rifle arena_mp/%side/ur_squad_commander arena_mp/%side/ur_squad_saper arena_mp/%side/ur_squad_at_rifle arena_mp/%side/ur_squad_supporter"}
)
(define "content_riflemans_rookie"
	{content "arena_mp/%side/rifle_rookie:5"}
)
(define "content_smgs_rookie"
	{content "arena_mp/%side/smg_rookie:5"}
)
(define "content_smgs_rookie_ppd"
	{content "arena_mp/%side/smg_rookie_ppd:5"}
)
(define "content_riflemans"
	{content "arena_mp/%side/rifle:5"}
)
(define "content_riflemans_reserv"
	{content "arena_mp/%side/rifle_reserv:5"}
)
(define "content_smgs"
	{content "arena_mp/%side/smg:5"}
)
(define "content_riflemans_veteran"
	{content "arena_mp/%side/rifle_veteran:5"}
)
(define "content_smgs_veteran"
	{content "arena_mp/%side/smg_veteran:5"}
)
(define "content_artman"
	{content "arena_mp/%side/artilleryman:4"}
)
(define "content_tankmans"
	{content "arena_mp/%side/tankman:5"}
)
(define "content_ap_miners"
	{content "arena_mp/%side/antipersonel_miner:5"}
)
(define "content_at_miners"
	{content "arena_mp/%side/antitank_miner:5"}
)
(define "content_sappers"
	{content "arena_mp/%side/saper:5"}
)
(define "content_combat_medics"
	{content "arena_mp/%side/combat_medic:2"}
)
(define "content_sappers_veteran"
	{content "arena_mp/%side/saper_veteran:5"}
)
(define "content_arty_spotters"
	{content "arena_mp/%side/arty_spotter:2"}
)
(define "content_engineers"
	{content "arena_mp/%side/engineer:5"}
)
(define "content_corpsman"
	{content "arena_mp/%side/corpsman:1"}
)
(define "content_uni_miners"
	{content "arena_mp/%side/universal_miner:5"}
)
(define "content_at_rifle"
	{content "arena_mp/%side/at_rifle:4"}
)
(define "content_rifle_grenadiers"
	{content "arena_mp/%side/rifle_grenadier:4"}
)
(define "content_bombermans"
	{content "arena_mp/%side/bomberman:5"}
)
(define "content_rifle_panzerfaust"
	{content "arena_mp/%side/rifle_panzerfaust:5"}
)
(define "content_at_rifle_ptrs"
	{content "arena_mp/%side/at_rifle_ptrs:4"}
)
(define "content_at_rifle_solothurn"
	{content "arena_mp/%side/at_rifle_solothurn:4"}
)
(define "content_bottle_throwers"
	{content "arena_mp/%side/bottle_thrower:4"}
)
(define "content_mgs"
	{content "arena_mp/%side/mgun_supporter:1 arena_mp/%side/mgun:1 arena_mp/%side/mgun_commander:1 arena_mp/%side/mgun:1 arena_mp/%side/mgun_supporter:1"}
)
(define "content_mgs_mg26"
	{content "arena_mp/%side/mgun_supporter_mg26:1 arena_mp/%side/mgun_mg26:1 arena_mp/%side/mgun_commander_mg26:1 arena_mp/%side/mgun_mg26:1 arena_mp/%side/mgun_supporter_mg26:1"}
)
(define "content_storm_squad"
	{content "arena_mp/%side/storm_smg:1 arena_mp/%side/storm_rifle:1 arena_mp/%side/storm_commander:1 arena_mp/%side/storm_rifle:1 arena_mp/%side/storm_smg:1"}
)
(define "content_bazookers"
	{content "arena_mp/%side/bazooker:2"}
)
(define "content_bazookers_m18"
	{content "arena_mp/%side/bazooker_m18:2"}
)
(define "content_mgs_late"
	{content "arena_mp/%side/mgun_supporter_late:1 arena_mp/%side/mgun_late:1 arena_mp/%side/mgun_commander_late:1 arena_mp/%side/mgun_late:1 arena_mp/%side/mgun_supporter_late:1"}
)
(define "content_mgs_late_dusty_faces"
	{content "arena_mp/ger/dusty_faces/lischewski:1 arena_mp/ger/dusty_faces/degen:1 arena_mp/ger/dusty_faces/feldmann:1 arena_mp/ger/dusty_faces/jansen:1 arena_mp/ger/dusty_faces/kowalski:1 arena_mp/ger/dusty_faces/kruger:1 arena_mp/ger/dusty_faces/freischmidt:1 arena_mp/ger/dusty_faces/ilgen:1 arena_mp/ger/dusty_faces/fuchs:1"}
)
(define "content_flamers"
	{content "arena_mp/%side/flamer:2"}
)
(define "content_edelweiss"
	{content "arena_mp/%side/edelweiss:1 arena_mp/%side/edelweiss_g43:2 arena_mp/%side/edelweiss_fg42:1 arena_mp/%side/edelweiss_mgun:1"}
)
(define "content_grenadiers"
	{content "arena_mp/ger/grenadier:1 arena_mp/ger/grenadier_pfaust:1 arena_mp/ger/grenadier_mgun:1 arena_mp/ger/grenadier_pfaust:1 arena_mp/ger/grenadier:1"}
)
(define "content_marines_rus"
	{content "arena_mp/%side/marine_avs:1 arena_mp/%side/marine:3 arena_mp/%side/marine_mgun:1"}
)
(define "content_marines_usa"
	{content "arena_mp/%side/marine_bar:1 arena_mp/%side/marine:1 arena_mp/%side/marine_radioman:1 arena_mp/%side/marine:1 arena_mp/%side/marine_mgun:1"}
)
(define "content_stormtroopers_ger"
	{content "sdkfz251d_g (arena_mp/%side/ss_driver:1 arena_mp/%side/ss_rifle:2  arena_mp/%side/ss:2 arena_mp/%side/ss_faust:2 arena_mp/%side/ss_mgun:1)"}
)
(define "content_stormtroopers_rus"
	{content "arena_mp/%side/sturmovik:1 arena_mp/%side/sturmovik_atr:1 arena_mp/%side/sturmovik_flame:1  arena_mp/%side/sturmovik_mgun:1 arena_mp/%side/sturmovik_rifle:1"}
)
(define "content_stormtroopers_usa"
	{content "arena_mp/%side/ranger:1 arena_mp/%side/ranger_shotgun:2  arena_mp/%side/ranger_mgun:1 arena_mp/%side/ranger:1"}
)
(define "content_hunters"
	{content "arena_mp/%side/hunter:5"}
)
(define "content_mps"
	{content "arena_mp/usa/mp:5"}
)
(define "content_snipers"
	{content "arena_mp/%side/sniper:2"}
)
(define "content_officer"
	{content "arena_mp/%side/officer:1"}
)
(define "content_scouts"
	{content "arena_mp/%side/scout:5"}
)
(define "content_paratroopers_ger"
	{content "ju-52 ( arena_mp/%side/pilot:3 arena_mp/%side/paratrooper:4 arena_mp/%side/paratrooper_mgun:1 )"}
)
(define "content_paratroopers_rus"
	{content "dc-47_rus ( arena_mp/%side/pilot:2 arena_mp/%side/paratrooper:4 arena_mp/%side/paratrooper_mgun:1 )"}
)
(define "content_paratroopers_usa"
	{content "dc-47 ( arena_mp/%side/pilot:2 arena_mp/%side/paratrooper:4 arena_mp/%side/paratrooper_mgun:1 )"}
)
(define "content_paratroopers_preview_ger"
	{content "arena_mp/%side/paratrooper:4 arena_mp/%side/paratrooper_mgun:1"}
)
(define "content_paratroopers_preview_rus"
	{content "arena_mp/%side/paratrooper:4 arena_mp/%side/paratrooper_mgun:1"}
)
(define "content_paratroopers_preview_usa"
	{content "arena_mp/%side/paratrooper:4 arena_mp/%side/paratrooper_mgun:1"}
)
(define "content_paratroopers_elite_usa"
	{content "dc-47 ( arena_mp/%side/pilot:2 arena_mp/%side/paratrooper_elite:2 arena_mp/%side/paratrooper_elite_mgun:1 arena_mp/%side/paratrooper_elite_smg:2 )"}
)
(define "content_paratroopers_elite_preview_usa"
	{content "arena_mp/%side/paratrooper_elite:2 arena_mp/%side/paratrooper_elite_mgun:1 arena_mp/%side/paratrooper_elite_smg:2"}
)
(define "content_saboteurs"
	{content "arena_mp/%side/saboteur:1 arena_mp/%side/saboteur_smg:3 arena_mp/%side/saboteur_sniper:1"}
)
(define "content_nkvd"
	{content "arena_mp/%side/nkvd_smg:1 arena_mp/%side/nkvd_sniper:1 arena_mp/%side/nkvd_commander:1 arena_mp/%side/nkvd_mgun:1 arena_mp/%side/nkvd_rifle:1"}
)
(define "content_brandenburgers"
	{content "sdkfz251b ( arena_mp/%side/brandenburger_driver:1 arena_mp/%side/brandenburger_rifle:2 arena_mp/%side/brandenburger_smg:1 arena_mp/%side/brandenburger_commander:1 arena_mp/%side/brandenburger_radioman:1 arena_mp/%side/brandenburger_sniper:1 )"}
)
(define "content_patrol"
	{content "sdkfz251d ( arena_mp/%side/tankman:1 arena_mp/%side/artilleryman:2 arena_mp/%side/patrol_commander:1 arena_mp/%side/patrol_saper:1 arena_mp/%side/patrol_mgun:1 arena_mp/%side/patrol_smg:1 arena_mp/%side/patrol_smg:2)"}
)
(define "content_devils_usa"
	{content "cg-4a (arena_mp/%side/pilot:2 arena_mp/%side/devil_commander:1 arena_mp/%side/devil_mgun:1 arena_mp/%side/devil_saboteur:3 )"}
)
(define "content_devils_preview_usa"
	{content "arena_mp/%side/devil_commander:1 arena_mp/%side/devil_mgun:1 arena_mp/%side/devil_saboteur:3"}
)
(define "content_jaeger_snipers"
	{content "arena_mp/%side/jaeger_sniper:2"}
)
(define "content_sniper_elite"
	{content "arena_mp/%side/sniper_elite:2"}
)
(define "content_sturmpioneers"
	{content "arena_mp/ger/sturmpioneer_saper:1 arena_mp/ger/sturmpioneer_flamer:1 arena_mp/ger/sturmpioneer_commander:1 arena_mp/ger/sturmpioneer_radioman:1 arena_mp/ger/sturmpioneer_mgun:1"}
)
(define "content_ger_riflemen41"
	{content "arena_mp/%side/rifle:4 arena_mp/ger/mgun_commander:1 arena_mp/ger/mgun_supporter:1 arena_mp/ger/mgun:1 arena_mp/%side/rifle:3"}
)
(define "content_rus_riflemen41"
	{content "arena_mp/rus/rifle:3 arena_mp/rus/mgun_supporter:1 arena_mp/rus/mgun:1 arena_mp/rus/mgun_commander:1 arena_mp/rus/rifle:4"}
)
(define "content_usa_riflemen41"
	{content "arena_mp/usa/rifle:2 arena_mp/usa/mgun:2 arena_mp/usa/mgun_commander:2 arena_mp/usa/rifle:2 arena_mp/usa/rifle:4"}
)
(define "content_recruits_squad"
	{content "arena_mp/%side/rifle_rookie:3 arena_mp/%side/mgun_commander:1 arena_mp/%side/smg_rookie:3"}
)
(define "content_assault_squad"
	{content "arena_mp/%side/heavy_assault_commander:1 arena_mp/%side/smg_veteran:2 arena_mp/%side/saper_veteran:4"}
)
(define "content_infantry_squad"
	{content "arena_mp/%side/light_assault_commander:1 arena_mp/%side/smg:2 arena_mp/%side/rifle:2 arena_mp/%side/mgun_supporter:1 arena_mp/%side/mgun:1"}
)
;=========================== SET =============================

(define "set_squad_base"
		{tags "squad %name_%side %side %t"}
		{side "%side"}
		{fore 1}
		{level %lvl}		
)
(define "set_squad_default"
		("content_%name"			side(%side))
		("set_squad_base"			name(%name) side(%side) t(%t) lvl(%lvl))
		("spawn_distance_default")
)
(define "set_squad_no_sale"
		("content_%name"			side(%side))
		("set_squad_base"			name(%name) side(%side) t(%t) lvl(%lvl))
		{not_for_sale}
		{actions "worker"} ; see actions.set
		("spawn_distance_corpsman")
		{inventory %inv}
)
(define "set_squad_no_sale_sd150"
		("content_%name"			side(%side))
		("set_squad_base"			name(%name) side(%side) t(%t) lvl(%lvl))
		{not_for_sale}
		{actions "worker"} ; see actions.set
		("spawn_distance_miner")
		{inventory %inv}
)
(define "set_squad_spec_content"
		("content_%name_%side"		side(%side))
		("set_squad_base"			name(%name) side(%side) t(%t) lvl(%lvl))
		("spawn_distance_default")
)
(define "set_squad_fighters_bot"
		("set_squad_default"		name(%name) side(%side) t(%t) lvl(%lvl))
;		{actions "fighter"}
)
(define "set_squad_fighters"
		("set_squad_fighters_bot"	name(%name) side(%side) t(%t) lvl(%lvl))
		{locked_squad}
)
(define "set_squad_ur"
		("set_squad_default"		name(%name) side(%side) t(%t) lvl(%lvl))
;		{actions "ur_squad"}
;		{locked_squad}
)
(define "set_squad_paratroopers"
		("content_%name_%side"		side(%side))
		("set_squad_base"			name(%name) side(%side) t(%t) lvl(%lvl))
		{actions "paratroopers"}
		("spawn_distance_airborne")
		{charge 15}
		{dont_unfog_by_territory}		
)

;========================== SQUADS ============================

;inf_basic
(define "riflemans_rookie"		("set_squad_default" 				name(%name) side(%side) t(infantry all inf_basic level_1 can_push) lvl(1)))
(define "smgs_rookie"			("set_squad_default" 				name(%name) side(%side) t(infantry all inf_basic level_1 can_push) lvl(1)))
(define "smgs_rookie_ppd"		("set_squad_default" 				name(%name) side(%side) t(infantry all inf_basic level_1 can_push) lvl(1)))
(define "riflemans"				("set_squad_default" 				name(%name) side(%side) t(infantry all inf_basic level_3 can_push) lvl(3)))
(define "riflemans_reserv"		("set_squad_default" 				name(%name) side(%side) t(infantry all inf_basic level_3 can_push) lvl(3)))
(define "smgs"					("set_squad_default" 				name(%name) side(%side) t(infantry all inf_basic level_3 can_push) lvl(3)))
(define "storm_squad"			("set_squad_default" 				name(%name) side(%side) t(infantry all inf_basic level_2 can_push) lvl(3)))
(define "riflemans_veteran"		("set_squad_default" 				name(%name) side(%side) t(infantry all inf_basic level_4 can_push) lvl(4)))
(define "smgs_veteran"			("set_squad_default" 				name(%name) side(%side) t(infantry all inf_basic level_4 can_push) lvl(4)))

;inf_sup
(define "artman"				("set_squad_default" 				name(%name) side(%side) t(infantry all inf_sup level_1 independent_delivery cant_push) lvl(1)))
(define "tankmans"				("set_squad_default" 				name(%name) side(%side) t(infantry all inf_sup level_1 independent_delivery cant_push) lvl(1)))
(define "ap_miners"				("set_squad_default" 				name(%name) side(%side) t(infantry all inf_sup level_1 independent_delivery cant_push transfer_forbiden) lvl(1)))
(define "at_miners"				("set_squad_default" 				name(%name) side(%side) t(infantry all inf_sup level_1 independent_delivery cant_push transfer_forbiden) lvl(1)))
(define "sappers"				("set_squad_default" 				name(%name) side(%side) t(infantry all inf_sup level_1 independent_delivery cant_push) lvl(1)))
(define "sappers_veteran"		("set_squad_default" 				name(%name) side(%side) t(infantry all inf_sup level_4 independent_delivery cant_push) lvl(4)))
(define "arty_spotters"			("set_squad_default" 				name(%name) side(%side) t(infantry all inf_sup level_4 independent_delivery cant_push) lvl(4)))
(define "sturmpioneers"		("set_squad_default" 				name(%name) side(%side) t(infantry all inf_sup level_6 independent_delivery cant_push) lvl(6)))
(define "combat_medics"			("set_squad_default" 				name(%name) side(%side) t(infantry all inf_sup level_3 independent_delivery cant_push) lvl(4)))


(define "engineers"				("set_squad_no_sale" 				name(%name) side(%side) t(all inf_sup level_1 independent_delivery cant_push transfer_forbiden) lvl(1)
	inv(
		{item "barbwire_kit" {count 15} {regeneration_time 495}} ; 1 items will be regenerated for 165sec
		{item "hedgehog_kit" {count 20} {regeneration_time 660}}
		{item "sandbag_kit" {count 20} {regeneration_time 440}}
		{item "dot_kit" {count 2} {regeneration_time 1240}}
		{item "dot_wood_kit" {count 3} {regeneration_time 1240}}
		{item "blindage_wood_kit" {count 1} {regeneration_time 1240}}
		{item "tower_%side_kit" {count 2} {regeneration_time 1240}}
		{item "tower_telescope_kit" {count 1} {regeneration_time 1240}}
		{item "supp_point_kit" {count 1} {regeneration_time 1240}}
	)
))
(define "corpsman"				("set_squad_no_sale" 				name(%name) side(%side) t(all inf_sup level_2 independent_delivery cant_push transfer_forbiden) lvl(2) inv()))
(define "uni_miners"			("set_squad_no_sale_sd150" 				name(%name) side(%side) t(all inf_sup level_2 independent_delivery cant_push transfer_forbiden) lvl(2)
	inv(
		{item "mine antipersonnel" {count 40} {regeneration_time 990}} 
		{item "mine antitank" {count 25} {regeneration_time 990}}
	)
))

;inf_heavy
(define "at_rifle"						("set_squad_default" 				name(%name) side(%side) t(infantry all inf_heavy level_1 can_push) lvl(1)))
(define "bombermans"					("set_squad_default" 				name(%name) side(%side) t(infantry all inf_heavy level_1 can_push) lvl(1)))
(define "rifle_panzerfaust"				("set_squad_default" 				name(%name) side(%side) t(infantry all inf_heavy level_2 can_push) lvl(2)))
(define "at_rifle_solothurn"			("set_squad_default" 				name(%name) side(%side) t(infantry all inf_heavy level_2 can_push) lvl(2)))
(define "at_rifle_ptrs"					("set_squad_default" 				name(%name) side(%side) t(infantry all inf_heavy level_2 can_push) lvl(2)))
(define "rifle_grenadiers"				("set_squad_default" 				name(%name) side(%side) t(infantry all inf_heavy level_2 can_push) lvl(2)))
(define "bottle_throwers"				("set_squad_default" 				name(%name) side(%side) t(infantry all inf_heavy level_2 can_push) lvl(2)))
(define "mgs"							("set_squad_default" 				name(%name) side(%side) t(infantry all inf_heavy level_2 can_push) lvl(2)))
(define "mgs_mg26"						("set_squad_default" 				name(%name) side(%side) t(infantry all inf_heavy level_2 can_push) lvl(2)))
(define "bazookers"						("set_squad_default" 				name(%name) side(%side) t(infantry all inf_heavy level_3 can_push) lvl(3)))
(define "bazookers_m18"					("set_squad_default" 				name(%name) side(%side) t(infantry all inf_heavy level_5 can_push) lvl(5)))
(define "mgs_late"						("set_squad_default" 				name(%name) side(%side) t(infantry all inf_heavy level_4 can_push) lvl(4)))
(define "mgs_late_dusty_faces"			("set_squad_default" 				name(%name) side(%side) t(infantry all inf_heavy level_4 can_push) lvl(4)))
(define "flamers"						("set_squad_default" 				name(%name) side(%side) t(infantry all inf_heavy level_4 can_push) lvl(4)))
(define "edelweiss"						("set_squad_default" 				name(%name) side(%side) t(infantry all inf_heavy level_5 can_push high_push) lvl(5)))
(define "grenadiers"						("set_squad_default" 				name(%name) side(%side) t(infantry all inf_heavy level_5 can_push high_push) lvl(5)))
(define "marines"						("set_squad_spec_content" 				name(%name) side(%side) t(infantry all inf_heavy level_5 can_push high_push) lvl(5)))
(define "stormtroopers"					("set_squad_spec_content" 			name(%name) side(%side) t(infantry all inf_heavy level_6 can_push high_push) lvl(6)))
(define "ur_squad"						("set_squad_ur"						name(%name) side(%side) t(infantry all inf_heavy level_2 can_push) lvl(2)))

;inf_spec
(define "hunters"						("set_squad_default" 				name(%name) side(%side) t(infantry all inf_spec level_2 cant_push) lvl(2)))
(define "mps"							("set_squad_default" 				name(%name) side(%side) t(infantry all inf_spec level_2 cant_push) lvl(2)))
(define "snipers"						("set_squad_default" 				name(%name) side(%side) t(infantry all inf_spec level_2 cant_push) lvl(2)))
(define "officer"						("set_squad_default" 				name(%name) side(%side) t(infantry all inf_spec level_3) lvl(3)))
(define "scouts"						("set_squad_default" 				name(%name) side(%side) t(infantry all inf_spec level_3 cant_push) lvl(3)))
(define "paratroopers"					("set_squad_paratroopers" 			name(%name) side(%side) t(all inf_spec level_4 independent_delivery can_push high_push) lvl(4)))
(define "paratroopers_preview"			("set_squad_paratroopers" 			name(%name) side(%side) t(all inf_spec level_4 independent_delivery can_push high_push) lvl(4)))
(define "paratroopers_elite"			("set_squad_paratroopers" 			name(%name) side(%side) t(all inf_spec level_6 independent_delivery can_push high_push) lvl(6)))
(define "paratroopers_elite_preview"	("set_squad_paratroopers" 			name(%name) side(%side) t(all inf_spec level_6 independent_delivery can_push high_push) lvl(6)))
(define "saboteurs"						("set_squad_default" 				name(%name) side(%side) t(infantry all inf_spec level_4 cant_push) lvl(4)))
(define "nkvd"							("set_squad_default" 				name(%name) side(%side) t(infantry all inf_spec level_4 cant_push) lvl(4)))
(define "brandenburgers"				("set_squad_default"		 		name(%name) side(%side) t(all inf_spec level_4  cant_push) lvl(4)))
(define "devils"						("set_squad_paratroopers"		 	name(%name) side(%side)	t(all inf_spec level_4 independent_delivery cant_push) lvl(4)))
(define "devils_preview"				("set_squad_paratroopers"		 	name(%name) side(%side)	t(all inf_spec level_4 independent_delivery cant_push) lvl(4)))
(define "jaeger_snipers"				("set_squad_default" 				name(%name) side(%side) t(infantry all inf_spec level_4 cant_push) lvl(4)))
(define "sniper_elite"					("set_squad_default" 				name(%name) side(%side) t(infantry all inf_spec level_6 cant_push) lvl(6)))

;inf_ai
(define "fighters_light_bot"			("set_squad_fighters_bot"			name(%name) side(%side) t(all inf_ai level_1 can_push) lvl(1)))
(define "fighters_bot"					("set_squad_fighters_bot"			name(%name) side(%side) t(all inf_ai level_3 can_push) lvl(3)))
(define "fighters_heavy_bot"			("set_squad_fighters_bot"			name(%name) side(%side) t(all inf_ai level_5 can_push) lvl(5)))
(define "fighters_light"				("set_squad_fighters"				name(%name) side(%side) t(infantry all inf_ai level_1 can_push) lvl(1)))
(define "fighters_light_fra"				("set_squad_fighters"				name(%name) side(%side) t(infantry all inf_ai level_1 can_push) lvl(1)))
(define "fighters"						("set_squad_fighters"				name(%name) side(%side) t(infantry all inf_ai level_3 can_push) lvl(3)))
(define "fighters_heavy"				("set_squad_fighters"				name(%name) side(%side) t(infantry all inf_ai level_5 can_push) lvl(5)))
(define "ai_hunters"					("set_squad_fighters"				name(%name) side(%side) t(infantry all inf_ai level_2 can_push low_push) lvl(2)))

;inf manpower squads
(define "ger_riflemen41"				("set_squad_default" 				name(%name) side(%side) t(infantry all inf_spec level_2 can_push) lvl(2)))
(define "rus_riflemen41"				("set_squad_default" 				name(%name) side(%side) t(infantry all inf_spec level_2 can_push) lvl(2)))
(define "usa_riflemen41"				("set_squad_default" 				name(%name) side(%side) t(infantry all inf_spec level_2 can_push) lvl(2)))
(define "recruits_squad"				("set_squad_default" 				name(%name) side(%side) t(infantry all inf_spec level_2 can_push) lvl(2)))
(define "assault_squad"				    ("set_squad_default" 				name(%name) side(%side) t(infantry all inf_spec level_2 can_push) lvl(2)))
(define "infantry_squad"				("set_squad_default" 				name(%name) side(%side) t(infantry all inf_spec level_2 can_push) lvl(2)))
;============================== MAIN_DEFINES ==================================
(define "squad"
	{"%name(%side)"
		("%name" name(%name) side(%side))
	}
)
(define "squads_g_r"
	("squad" side(ger) name(%name))
	("squad" side(rus) name(%name))
)
(define "squads_r_u"
	("squad" side(rus) name(%name))
	("squad" side(usa) name(%name))
)
(define "squads_g_r_u"
	("squad" side(ger) name(%name))
	("squad" side(rus) name(%name))
	("squad" side(usa) name(%name))
)
(define "squads_g_r_u_e_j"
	("squad" side(ger) name(%name))
	("squad" side(rus) name(%name))
	("squad" side(usa) name(%name))
	("squad" side(eng) name(%name))	
	("squad" side(jap) name(%name))		
)

;=========================		[INIT SQUADS]		==========================

;--------------------------- Regular infantry ---------------------------------
;level_1
("squads_g_r_u"					name(riflemans_rookie))
("squads_g_r_u"					name(smgs_rookie))
("squad"			side(rus)	name(smgs_rookie_ppd))
;level_3
("squads_g_r_u"					name(riflemans))
("squads_g_r_u"					name(smgs))
("squad"			side(rus)	name(riflemans_reserv))
("squad"			side(ger)	name(storm_squad))
;level_4
("squads_g_r_u"					name(riflemans_veteran))
("squads_g_r_u"					name(smgs_veteran))

;--------------------------- Support infantry ---------------------------------
;level_1
("squads_g_r_u"					name(artman))
("squads_g_r_u"					name(tankmans))
("squads_g_r_u"					name(ap_miners))
("squads_g_r_u"					name(at_miners))
("squads_g_r_u"					name(sappers))
("squads_g_r_u"					name(engineers))
;level_2
("squads_g_r_u"					name(corpsman))
("squads_g_r_u"					name(uni_miners))
;level_3
("squads_g_r_u"					name(combat_medics))
;level_4
("squads_g_r_u"					name(sappers_veteran))
("squads_g_r_u_e_j"			name(arty_spotters))
;level_6
("squad"			side(ger)	name(sturmpioneers))

;------------------------------ Heavy infantry --------------------------------
;level_1
("squads_g_r_u"					name(at_rifle))
("squads_r_u"					name(bombermans))
;level_2
("squad"			side(ger)	name(rifle_panzerfaust))
("squad"			side(ger)	name(at_rifle_solothurn))
("squad"			side(rus)	name(at_rifle_ptrs))
("squad"			side(rus)	name(bottle_throwers))
("squad"			side(rus)	name(rifle_grenadiers))
("squads_g_r_u"					name(mgs))
("squad"			side(ger)	name(mgs_mg26))
;level_3
("squads_g_r_u"					name(bazookers))
("squad"			side(usa)	name(bazookers_m18))
;level_4
("squads_g_r_u"					name(mgs_late))
("squad"			side(ger)	name(mgs_late_dusty_faces))
("squads_g_r_u"					name(flamers))
;level_5
("squad"			side(ger)	name(edelweiss))
("squad"			side(ger)	name(grenadiers))
("squads_r_u"					name(marines))
("squad"				side(ger)	name(ur_squad))

;--------------------------- Specialized infantry ----------------------------
;level_2
("squads_g_r_u"					name(hunters))
("squads_g_r_u"					name(snipers))
("squad"			side(usa)		name(mps))
;level_3
("squads_g_r_u"					name(scouts))
;level_4
("squads_g_r_u"					name(saboteurs))
("squad"			side(rus)	name(nkvd))
("squad"			side(ger)	name(jaeger_snipers))
("squads_g_r_u"					name(paratroopers_preview))
("squad"			side(usa)	name(paratroopers_elite_preview))
("squads_g_r_u"					name(officer))
;level_6
("squads_g_r_u"					name(sniper_elite))
("squad"			side(usa)	name(devils_preview))

;--------------------------- AI_Fighters ------------------------------------
;level_1
("squads_g_r_u"					name(fighters_light))
("squad"			side(usa)	name(fighters_light_fra))
;level_2
("squads_g_r_u"					name(ai_hunters))
;level_3
("squads_g_r_u"					name(fighters))
;level_5
("squads_g_r_u"					name(fighters_heavy))

;--------------------------- AI_Fighters_Bot---------------------------------
;level_1
("squads_g_r_u"					name(fighters_light_bot))
;level_3
("squads_g_r_u"					name(fighters_bot))
;level_5
("squads_g_r_u"					name(fighters_heavy_bot))
;--------------------------- Manpower special ------------------------------
("squad"			side(ger)	name(ger_riflemen41))
("squad"			side(rus)	name(rus_riflemen41))
("squad"			side(usa)	name(usa_riflemen41))
("squad"			side(ger)	name(recruits_squad))
("squad"			side(rus)	name(recruits_squad))
("squad"			side(usa)	name(recruits_squad))
("squad"			side(ger)	name(assault_squad))
("squad"			side(rus)	name(assault_squad))
("squad"			side(usa)	name(assault_squad))
("squad"			side(ger)	name(infantry_squad))
("squad"			side(rus)	name(infantry_squad))
("squad"			side(usa)	name(infantry_squad))
;--------------------------- Misssions special ------------------------------