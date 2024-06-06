(define "seismic_low"
	{damage seismic		{energy %energy}	{radius 1.0}}
)
(define "seismic_medium"
	{damage seismic		{energy %energy}	{radius 2.25}}
)
(define "seismic_heavy"
	{damage seismic		{energy %energy}	{radius 2.5}}
)
(define "seismic_custom"
	{damage seismic		{energy %energy}	{radius %radius}}
)

(define "breakout_k0"	("base_formula"	energy_base(%energy_base) energy_min(2.4) energy_max(7.6) armor_min(%armor_min) armor_max(%armor_max)))
(define "armor1_k0"		("breakout_k0"	energy_base(%energy_base) armor_min(3)	armor_max(7.5)))
(define "armor2_k0"		("breakout_k0"	energy_base(%energy_base) armor_min(8)	armor_max(20)))

;75mm+
(define "breakout_k1"	("base_formula"	energy_base(%energy_base) energy_min(17.68) energy_max(110.8) armor_min(%armor_min) armor_max(%armor_max)))
(define "armor1_k1"		("breakout_k1"	energy_base(%energy_base) armor_min(30)	armor_max(55)))
(define "armor2_k1"		("breakout_k1"	energy_base(%energy_base) armor_min(70)	armor_max(150)))

(define "breakout" ; effect of armor on direct hit damage
	{breakout
		{breakoutenergy 0 %energy_base}
		{breakoutarmorhealth
			("armor1_k%k" energy_base(%energy_base))	(* %armorhealth_base %hp_k 2.5)
			("armor2_k%k" energy_base((/ %energy_base 2)))	(* %armorhealth_base %hp_k 1.25)
			("armor2_k%k" energy_base((/ %energy_base 1.75)))	(* %armorhealth_base %hp_k 0.0)
		}
	}
)
(define "armor_strength_to_damage_k" ; effect of armor on blast damage
	{armor_strength_to_damage_k
		{0.1
			{("armor1_k%k" energy_base(%energy_base))	1.0}
			{("armor2_k%k" energy_base((* 0.6 %energy_base)))	0.15}
		}
		{%range_end
			{("armor1_k%k" energy_base(%energy_base))	0.6}
			{("armor2_k%k" energy_base((* 0.6 %energy_base)))	0.1}
		}
	}
)
(define "armorhealth" ; distance - damage
	{armorhealth
		(* 0.1 %range_k) 					(* %armorhealth_base %hp_k)
		(* %range_end %range_k)				(* %armorhealth_base 0.25 %hp_k)
		(+ (* %range_end %range_k) 0.01)	0
	}
)
(define "antitank_range_base_air_bomb" ;air_bomb
		{damage blastwave
			{if props "human"}
			{if props "vehicle"
				{if props "tank heavy"
					("energy_k1"					energy_base(%energy_base) range_end(%range_end) range_base(1.5) range_apc(1.5) range_k(1))
					("armorhealth"					armorhealth_base(%armorhealth_base) range_end(%range_end) range_k(1.5) hp_k(2.5))
					("breakout"						energy_base(%energy_base) armorhealth_base(%armorhealth_base) k(1) hp_k(2.5))
					("ea_spread" 					energy_base(%energy_base) armorhealth_base(%armorhealth_base))
					("armor_strength_to_damage_k" 	energy_base(%energy_base) range_end(%range_end) k(1))
				}
				{if props "car" or props "moto"
					("energy_k1"					energy_base(%energy_base) range_end(%range_end) range_base(1.5) range_apc(1.5) range_k(1.5))
					("armorhealth"					armorhealth_base(%armorhealth_base) range_end(%range_end) range_k(1.5) hp_k(1.5))
					("ea_spread" 					energy_base(%energy_base) armorhealth_base(%armorhealth_base))
				}
				("energy_k1"					energy_base(%energy_base) range_end(%range_end) range_base(1.5) range_apc(1.5) range_k(1))
				("armorhealth"					armorhealth_base(%armorhealth_base) range_end(%range_end) range_k(1.5) hp_k(2.5))
				("breakout"						energy_base(%energy_base) armorhealth_base(%armorhealth_base) k(1) hp_k(2.5))
				("ea_spread" 					energy_base(%energy_base) armorhealth_base(%armorhealth_base))
				("armor_strength_to_damage_k" 	energy_base(%energy_base) range_end(%range_end) k(1))
			}
			{energy
				0.5 					(* %energy_base 0.5)
				0.51					(* %energy_base 0.25)	
				%range_end	 			(* %energy_base 0.125)
				(+ %range_end 0.01)		0
			}
			("e_spread" energy_base(%energy_base))
		}
		("truck_mortar" energy_base(%energy_base) range_end(%range_end))
)
(define "blast_mortar" ;mortar
	{damage blastwave		;antitank
		{if props "human"}
		{if props "vehicle"
			{if props "car" or props "moto"
				("energy_k0"					energy_base(%energy_apc) range_end(%range_end_apc) range_k(1.5))
				("armorhealth"					armorhealth_base(%armorhealth) range_end(%range_end_apc) range_k(1.5) hp_k(1))
				{armorhealthspread (* -1 0.1 %armorhealth 0.5) (* 0.1 %armorhealth 0.5) 1}
			}
			("energy_k0"					energy_base(%energy_apc) range_end(%range_end_apc) range_k(2))
			("armorhealth"					armorhealth_base(%armorhealth) range_end(%range_end_apc) range_k(2) hp_k(2))
			("breakout"						energy_base(%energy_apc) armorhealth_base(%armorhealth) k(1) hp_k(1))
	;		("ea_spread"					energy_base(%energy_apc) armorhealth_base(%armorhealth))
			("armor_strength_to_damage_k"	energy_base(%energy_apc) range_end(%range_end) k(1))
			{armorhealthspread (* -1 0.1 %armorhealth 0.5) (* 0.1 %armorhealth 0.5) 1}
		}
		{energy
			0.5							(* %energy_construction 0.5)
			0.51						(* %energy_construction 0.25)
			%range_end_apc				(* %energy_construction 0.125)
			(+ %range_end_apc 0.01)		0
		}
		("e_spread" energy_base(%energy_construction))
	}
	;("antipersonnel_mortar" energy_base(%energy_base) range_end(%range_end) cal(%cal))
)
(define "antitank_range_grenade"; grenade
		{damage blastwave
			{if props "human"}
			{if props "vehicle"
				{if props "tank heavy"
					("energy_grenade"				energy_base(%energy_base) energy_apc(%energy_apc) range_base(%range_base) range_apc(%range_apc) range_end(%range_end) range_k(1))
					("armorhealth_apc"				armorhealth_base(%armorhealth_base) range_base(%range_base) range_end(%range_end) range_k(1) hp_k(0.75))
					("breakout"						energy_base(%energy_base) armorhealth_base(%armorhealth_base) k(%k) hp_k(0.75))
					("ea_spread" 					energy_base(%energy_base) armorhealth_base(%armorhealth_base))
					("armor_strength_to_damage_k" 	energy_base(%energy_base) range_end(%range_end) k(%k))
				}
				{if props "car" or props "moto"
					("energy_grenade"			energy_base(%energy_base) energy_apc(%energy_apc) range_base(%range_base) range_apc(%range_apc) range_end(%range_end) range_k(1.5))
					("armorhealth_apc"			armorhealth_base(%armorhealth_base) range_base(%range_base) range_end(%range_end) range_k(1.5) hp_k(1))
					("ea_spread" 				energy_base(%energy_base) armorhealth_base(%armorhealth_base))
				}
				("energy_grenade"				energy_base(%energy_base) energy_apc(%energy_apc) range_base(%range_base) range_apc(%range_apc) range_end(%range_end) range_k(1))
				("armorhealth_apc"				armorhealth_base(%armorhealth_base) range_base(%range_base) range_end(%range_end) range_k(1) hp_k(1.25))
				("breakout"						energy_base(%energy_base) armorhealth_base(%armorhealth_base) k(%k) hp_k(1.25))
				("ea_spread" 					energy_base(%energy_base) armorhealth_base(%armorhealth_base))
				("armor_strength_to_damage_k" 	energy_base(%energy_base) range_end(%range_end) k(%k))
			}
			{energy
				0.5 					(* %energy_base 0.5)
				0.51					(* %energy_base 0.25)	
				%range_end	 			(* %energy_base 0.125)
				(+ %range_end 0.01)		0
			}
			("e_spread" energy_base(%energy_base))
		}
)

(define "antipersonnel_low_ext_chance"
			{chance
				3.25	1
				6.4		0.75
			}
)
(define "antipersonnel_low_ext_chance_down"
				{chance
					0		1
					3.25	0.75
					6.4		0
				}
)
(define "antipersonnel_low_ext_mortar_chance_trench"
				{chance
					0		1
					3.25	0.65
					6.4		0
				}
)
(define "antipersonnel_low_ext_main"
	{damage add fragments
		{if props "human"
			{energy
				(* 0.9 %range_k)	%ult						;5=500 - ultimate dmg
				(* 3.4 %range_k)	(* 2.5555	%energy_k)		;155.55

				(* 3.9 %range_k)	(* 2.275	%energy_k)		;127.5
				(* 4.4 %range_k)	(* 1.425	%energy_k)		;42.5
				(* 5.4 %range_k)	(* 1.34		%energy_k)		;34
				(* 6.4 %range_k)	(* 0.585	%energy_k)		;8.5
				(* 6.5 %range_k) 	0					;
			}
			("%chmain")
			{if fsm_tags "down"
				("%chdown")
			}
			{if in_fortification "trench"
				("%chtrench")
			}
		}
	}
	{damage add blastwave {if props "human"} {energy 0.01 0.1}}
)

(define "antipersonnel_75plus_fragments_energy"
	{energy
		(+ 1 (* 0.02666666667 (- %cal 75)))				0
		(+ 2.5 (* 0.02666666667 (- %cal 75)))			(* 5 %k %energy_k)

		(+ 3.5 (* 0.07666666667 (- %cal 75)))	 		(* (+ 2 (* 0.0036 (- %cal 75))) %k %energy_k)
		(+ 5 (* 0.07666666667 (- %cal 75)))				(* (+ 1.85 (* 0.0036 (- %cal 75))) %k %energy_k)
		(+ 6 (* 0.09 (- %cal 75)))	 					(* (+ 1.65 (* 0.0036 (- %cal 75))) %k %energy_k)
		(+ 8 (* 0.09 (- %cal 75)))	 					(* (+ 1.35 (* 0.0036 (- %cal 75))) %k %energy_k)
		(+ 10.4 (* 0.09 (- %cal 75))) 					(* (+ 1.25 (* 0.0036 (- %cal 75))) %k %energy_k)
		(+ 10.5 (* 0.09 (- %cal 75))) 					0
	}
)
(define "antipersonnel_75plus_chance"
			{chance
				(+ 5.25 (* 0.045 (- %cal 75)))			1
				(+ 10.4 (* 0.09 (- %cal 75)))			0.75
			}
)
(define "antipersonnel_75plus_test_chance"
			{chance
				(+ 10.4 (* 0.09 (- %cal 75)))			1
			}
)
(define "antipersonnel_75plus_chance_down"
				{chance
					0									1
					(+ 5.25 (* 0.045 (- %cal 75)))		0.75
					(+ 10.4 (* 0.09 (- %cal 75)))		0
				}
)
(define "antipersonnel_75plus_chance_trench"
				{chance
					0									0
					;0									1
					;(+ 5.25 (* 0.045 (- %cal 75)))		0.65
					;(+ 10.4 (* 0.09 (- %cal 75)))		0
				}
)
(define "antipersonnel_75plus_mortar_chance_trench"
				{chance
					0									1
					(+ 5.25 (* 0.045 (- %cal 75)))		0.65
					(+ 10.4 (* 0.09 (- %cal 75)))		0
				}
)