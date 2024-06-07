;SDL
(define "seismic_low"
	{damage seismic		{energy %energy}	{radius 0.75}}
)
(define "seismic_medium"
	{damage seismic		{energy %energy}	{radius 2.25}}
)
(define "seismic_heavy"
	{damage seismic		{energy %energy}	{radius 2.475}}
)
(define "seismic_custom"
	{damage seismic		{energy %energy}	{radius %radius}}
)
;g_humanStunTimeMmin 2
;g_humanStunTimeMax 7
;g_humanStunDamageMin 1 ;default=2
;g_humanStunDamageMin 5
(define "stun_koef"
	{damage add shockwave
		{if fsm_tags "down" or in_fortification "trench" or in_house or cover_kind "vertical" "horizontal" "bush" "terrain"
			{energy
				0											2.6 	;4sec
				(* 0.335 (- %range_end  0.01) %range_k)		2.6
				(* 0.335 %range_end %range_k)				0
			}
		}
		{energy
			0												2.6 	;4sec
			(* 0.67 (- %range_end  0.01) %range_k)			2.6
			(* 0.67 %range_end %range_k)					0
		}
	}
)
(define "stun_75plus"
	{damage add shockwave
		{if fsm_tags "down" or in_fortification "trench" or in_house or cover_kind "vertical" "horizontal" "bush" "terrain"
			{energy
				0														2.6 	;4sec
				(* 0.335 (+ (- %range_end 0.01) (* 0.09 (- %cal 75))))	2.6
				(* 0.335 (+ %range_end (* 0.09 (- %cal 75))))			0
			}
		}
		{energy
			0															2.6 	;4sec
			(* 0.67 (+ (- %range_end 0.01) (* 0.09 (- %cal 75))))		2.6
			(* 0.67 (+ %range_end (* 0.09 (- %cal 75))))				0
		}
	}
)
(define "stun_low"			("stun_koef"	range_end(6.5) range_k(%range_k)))
(define "stun_medium"		("stun_75plus"	range_end(10.5) cal(%cal)))
(define "stun_medium_plus"	("stun_75plus"	range_end(10.5) cal(%cal)))
(define "stun_heavy"		("stun_75plus"	range_end(12) cal(%cal)))
(define "stun_mortar"		("stun_koef"	range_end(%range_end) range_k(1)))

(define "e_spread"
	{energyspread (* -1 0.02 %energy_base) (* 0.02 %energy_base) 1}
)
(define "ea_spread" ; macro to spread energy and damage
	("e_spread" energy_base(%energy_base))
	{armorhealthspread (* -1 0.1 %armorhealth_base 0.5) (* 0.1 %armorhealth_base 0.5) 1}
)

;75mm: 6-20
;150mm: 35-88
(define "base_formula"
	(+ (/ (* %armor_min %energy_base) %energy_min)  (* (/ (- (/	(* %armor_max %energy_base)	%energy_max) (/	(* %armor_min %energy_base)	%energy_min)) (- %energy_max %energy_min)) (- %energy_base %energy_min)))
)
;20-57mm
(define "breakout_k0"	("base_formula"	energy_base(%energy_base) energy_min(1.2) energy_max(7.6) armor_min(%armor_min) armor_max(%armor_max)))
(define "armor1_k0"		("breakout_k0"	energy_base(%energy_base) armor_min(5)	armor_max(5.5)))
(define "armor2_k0"		("breakout_k0"	energy_base(%energy_base) armor_min(6)	armor_max(11)))

;75mm+
(define "breakout_k1"	("base_formula"	energy_base(%energy_base) energy_min(7.6) energy_max(32.8) armor_min(%armor_min) armor_max(%armor_max)))
(define "armor1_k1"		("breakout_k1"	energy_base(%energy_base) armor_min(6)	armor_max(11)))
(define "armor2_k1"		("breakout_k1"	energy_base(%energy_base) armor_min(35)	armor_max(55)))

(define "breakout" ; effect of armor on direct hit damage
	{breakout
		{breakoutenergy 0 %energy_base}
		{breakoutarmorhealth
			;(+ (/ (* 6 %energy_base) 7.6) (* %k (/ (- (/ (* 35 %energy_base) 32.8) (/ (* 6 %energy_base) 7.6)) (- 32.8 7.6)) (- %energy_base 7.6)))		(* %armorhealth_base %hp_k 1)
			;(+ (/ (* 11 %energy_base) 7.6) (* %k (/ (- (/ (* 55 %energy_base) 32.8) (/ (* 11 %energy_base) 7.6)) (- 32.8 7.6)) (- %energy_base 7.6)))	(* %armorhealth_base %hp_k 0.5)
			("armor1_k%k" energy_base(%energy_base))	(* %armorhealth_base %hp_k 1)
			("armor2_k%k" energy_base(%energy_base))	(* %armorhealth_base %hp_k 0.5)
			(* %energy_base 5)							(* %armorhealth_base %hp_k 0.2)
		}
	}
)
(define "armor_strength_to_damage_k" ; effect of armor on blast damage
	{armor_strength_to_damage_k
		{0.1
			;{(+ (/ (* 6 %energy_base) 7.6) (* %k (/ (- (/ (* 35 %energy_base) 32.8) (/ (* 6 %energy_base) 7.6)) (- 32.8 7.6)) (- %energy_base 7.6))) 	1}
			;{(+ (/ (* 11 %energy_base) 7.6) (* %k (/ (- (/ (* 55 %energy_base) 32.8) (/ (* 11 %energy_base) 7.6)) (- 32.8 7.6)) (- %energy_base 7.6))) 	0.5}
			{("armor1_k%k" energy_base(%energy_base))	1}
			{("armor2_k%k" energy_base(%energy_base))	0.5}
			{(* %energy_base 5) 						0.2}
		}
		{%range_end
			;{(+ (/ (* 6 %energy_base) 7.6) (* %k (/ (- (/ (* 35 %energy_base) 32.8) (/ (* 6 %energy_base) 7.6)) (- 32.8 7.6)) (- %energy_base 7.6))) 	0.5}
			;{(+ (/ (* 11 %energy_base) 7.6) (* %k (/ (- (/ (* 55 %energy_base) 32.8) (/ (* 11 %energy_base) 7.6)) (- 32.8 7.6)) (- %energy_base 7.6))) 	0.25}
			{("armor1_k%k" energy_base(%energy_base))	0.5}
			{("armor2_k%k" energy_base(%energy_base))	0.25}
			{(* %energy_base 5) 						0.2}
		}
	}
)
(define "energy_k0" ; distance - energy (energy * 5 = penetration)
	{energy
		(* 0.1 %range_k)									%energy_base
		(* 0.11 %range_k)									(/ (+ (* 9.118 (/ (/ %energy_base 1.2) (/ 7.6 1.2))) (* 5.6 (/ 1.2 %energy_base))) 5)	;(/ (* 6 (/ %energy_base 1.2)) 5)
		(* %range_end %range_k)								(/ (+ (* 9.118 (/ (/ %energy_base 1.2) (/ 7.6 1.2))) (* 5.6 (/ 1.2 %energy_base))) 10)	;(/ (* 6 (/ %energy_base 1.2) 0.5) 5)
		(+ (* %range_end %range_k) 0.01)					0
	}
)
(define "energy_k1_old"
	{energy
		(* (+ 0.1 %range_base) %range_k)					%energy_base
		(* (+ 0.11	%range_apc)	%range_k)					(/ (+ (* 19 (/ (/ %energy_base 7.6) (/ 32.8 7.6))) (* 5.6 (/ 7.6 %energy_base))) 5)	;(/ (* 8 (/ %energy_base 7.6)) 5)
		(* %range_end %range_k)								(/ (+ (* 19 (/ (/ %energy_base 7.6) (/ 32.8 7.6))) (* 5.6 (/ 7.6 %energy_base))) 10)	;(/ (* 8 (/ %energy_base 7.6) 0.5) 5)
		(+ (* %range_end %range_k) 0.01)					0
	}
)
(define "energy_k1"
	{energy
		(* (+ 0.1 %range_base) %range_k)					%energy_base
		(* (+ (* 0.5 %range_end)	%range_apc)	%range_k)	(/ (+ (* 19 (/ (/ %energy_base 7.6) (/ 32.8 7.6))) (* 5.6 (/ 7.6 %energy_base))) 5)	;(/ (* 8 (/ %energy_base 7.6)) 5)
		(* %range_end %range_k)								(/ (+ (* 19 (/ (/ %energy_base 7.6) (/ 32.8 7.6))) (* 5.6 (/ 7.6 %energy_base))) 10)	;(/ (* 8 (/ %energy_base 7.6) 0.5) 5)
		(+ (* %range_end %range_k) 0.01)					0
	}
)
(define "energy_apc"
	{energy
		(* %range_base %range_k)			%energy_base
		(* %range_apc %range_k)				%energy_apc
		(* %range_end %range_k)	 			(* %energy_base 0.2)
		(+ (* %range_end %range_k) 0.01)	0
	}
)
(define "energy_grenade"
	{energy
		(* %range_base %range_k)			%energy_base
		(* %range_apc %range_k)				(* %energy_apc 0.25) ;
		(* %range_end %range_k)	 			(* %energy_base 0.1)
		(+ (* %range_end %range_k) 0.01)	0
	}
)
(define "armorhealth" ; distance - damage
	{armorhealth
		(* 0.1 %range_k) 					(* %armorhealth_base %hp_k)
		(* %range_end %range_k)				(* %armorhealth_base 0.5 %hp_k)
		(+ (* %range_end %range_k) 0.01)	0
	}
)
(define "armorhealth_apc"
	{armorhealth
		(* %range_base %range_k)			(* %armorhealth_base %hp_k)
		(* %range_end %range_k)	 			(* %armorhealth_base 0.5 %hp_k)
		(+ (* %range_end %range_k) 0.01)	0
	}
)
(define "truck_mortar" ;extra damage
	{damage add blastwave
		{if props "truck_mortar"
			{energy
				%range_end				%energy_base
				(+ %range_end 0.01)		0
			}
			{armorhealth
				%range_end 				40
				(+ %range_end 0.01)		0
			}
		}
	}
)
; antitank
(define "antitank_car"
	{damage blastwave
		{if props "car" or props "moto"
			("energy_k0"					energy_base(%energy_base) range_end(%range_end) range_k(1.5))
			("armorhealth"					armorhealth_base(%armorhealth_base) range_end(%range_end) range_k(1.5) hp_k(1))
			("ea_spread" 					energy_base(%energy_base) armorhealth_base(%armorhealth_base))
		}
	}
)
(define "antitank_range_base" ; 20-57mm fg
		{damage blastwave
			{if props "human"}
			{if props "vehicle"
				{if props "tank heavy"
					("energy_k0"					energy_base(%energy_base) range_end(%range_end) range_k(1))
					("armorhealth"					armorhealth_base(%armorhealth_base) range_end(%range_end) range_k(1) hp_k(0.5))
					("breakout"						energy_base(%energy_base) armorhealth_base(%armorhealth_base) k(0) hp_k(0.5))
					("ea_spread" 					energy_base(%energy_base) armorhealth_base(%armorhealth_base))
					("armor_strength_to_damage_k" 	energy_base(%energy_base) range_end(%range_end) k(0))
				}
				{if props "car" or props "moto"
					("energy_k0"					energy_base(%energy_base) range_end(%range_end) range_k(1.5))
					("armorhealth"					armorhealth_base(%armorhealth_base) range_end(%range_end) range_k(1.5) hp_k(1))
					("ea_spread" 					energy_base(%energy_base) armorhealth_base(%armorhealth_base))
				}
				("energy_k0"					energy_base(%energy_base) range_end(%range_end) range_k(1))
				("armorhealth"					armorhealth_base(%armorhealth_base) range_end(%range_end) range_k(1) hp_k(1))
				("breakout"						energy_base(%energy_base) armorhealth_base(%armorhealth_base) k(0) hp_k(1))
				("ea_spread" 					energy_base(%energy_base) armorhealth_base(%armorhealth_base))
				("armor_strength_to_damage_k" 	energy_base(%energy_base) range_end(%range_end) k(0))
			}
			{energy
				0.5 					(* %energy_construction 0.6)
				0.51					(* %energy_construction 0.25)	
				%range_end	 			(* %energy_construction 0.125)
				(+ %range_end 0.01)		0
			}
			("e_spread" energy_base(%energy_base))
		}
		("truck_mortar" energy_base(%energy_base) range_end(%range_end))
)
(define "antitank_range_base_75" ;75mm+ fg
		{damage blastwave
			{if props "human"}
			{if props "vehicle"
				{if props "tank heavy"
					("energy_k%energy_def"			energy_base(%energy_base) range_end(%range_end) range_base(0)range_apc(0) range_k(1))
					("armorhealth"					armorhealth_base(%armorhealth_base) range_end(%range_end) range_k(1) hp_k(0.5))
					("breakout"						energy_base(%energy_base) armorhealth_base(%armorhealth_base) k(1) hp_k(1.0))
					("ea_spread" 					energy_base(%energy_base) armorhealth_base(%armorhealth_base))
					("armor_strength_to_damage_k" 	energy_base(%energy_base) range_end(%range_end) k(1))
				}
				{if props "car" or props "moto"
					("energy_k%energy_def"			energy_base(%energy_base) range_end(%range_end) range_base(0)range_apc(0) range_k(1.5))
					("armorhealth"					armorhealth_base(%armorhealth_base) range_end(%range_end) range_k(1.5) hp_k(1))
					("ea_spread" 					energy_base(%energy_base) armorhealth_base(%armorhealth_base))
				}
				{if props "armored_car"
				   ("energy_k%energy_def"				energy_base(%energy_base) range_end(%range_end) range_base(0)range_apc(0) range_k(1))
				   ("armorhealth"					armorhealth_base(%armorhealth_base) range_end(%range_end) range_k(1) hp_k(1.65))
				   ("breakout"						energy_base(%energy_base) armorhealth_base(%armorhealth_base) k(1) hp_k(1.65))
				   ("ea_spread" 					energy_base(%energy_base) armorhealth_base(%armorhealth_base))
				   ("armor_strength_to_damage_k" 	energy_base(%energy_base) range_end(%range_end) k(1))
				}
				("energy_k%energy_def"				energy_base(%energy_base) range_end(%range_end) range_base(0)range_apc(0) range_k(1))
				("armorhealth"					armorhealth_base(%armorhealth_base) range_end(%range_end) range_k(1) hp_k(1))
				("breakout"						energy_base(%energy_base) armorhealth_base(%armorhealth_base) k(1) hp_k(1))
				("ea_spread" 					energy_base(%energy_base) armorhealth_base(%armorhealth_base))
				("armor_strength_to_damage_k" 	energy_base(%energy_base) range_end(%range_end) k(1))
			}
			{energy
				0.5 					(* %energy_construction 0.5)
				0.51					(* %energy_construction 0.25)
				%range_end	 			(* %energy_construction 0.125)
				(+ %range_end 0.01)		0
			}
			("e_spread" energy_base(%energy_base))
		}
		("truck_mortar" energy_base(%energy_base) range_end(%range_end))
)
(define "antitank_range_base_energy6" ;75mm+  energy_k1
	("antitank_range_base_75"
		energy_def(1)
		energy_base(%energy_base)
		energy_construction(%energy_construction)
		armorhealth_base(%armorhealth_base)
		range_end(%range_end)
	)
)
(define "antitank_range_base_energy6_old" ;75mm+ energy_k1_old
	("antitank_range_base_75"
		energy_def(1_old)
		energy_base(%energy_base)
		energy_construction(%energy_construction)
		armorhealth_base(%armorhealth_base)
		range_end(%range_end)
	)
)
(define "antitank_range_base_air_bomb" ;air_bomb
		{damage blastwave
			{if props "human"}
			{if props "vehicle"
				{if props "tank heavy"
					("energy_k1"					energy_base(%energy_base) range_end(%range_end) range_base(0.5) range_apc(1.5) range_k(1))
					("armorhealth"					armorhealth_base(%armorhealth_base) range_end(%range_end) range_k(1) hp_k(0.5))
					("breakout"						energy_base(%energy_base) armorhealth_base(%armorhealth_base) k(1) hp_k(1.0))
					("ea_spread" 					energy_base(%energy_base) armorhealth_base(%armorhealth_base))
					("armor_strength_to_damage_k" 	energy_base(%energy_base) range_end(%range_end) k(1))
				}
				{if props "car" or props "moto"
					("energy_k1"					energy_base(%energy_base) range_end(%range_end) range_base(0.5) range_apc(1.5) range_k(1.5))
					("armorhealth"					armorhealth_base(%armorhealth_base) range_end(%range_end) range_k(1.5) hp_k(1))
					("ea_spread" 					energy_base(%energy_base) armorhealth_base(%armorhealth_base))
				}
				("energy_k1"					energy_base(%energy_base) range_end(%range_end) range_base(0.5) range_apc(1.5) range_k(1))
				("armorhealth"					armorhealth_base(%armorhealth_base) range_end(%range_end) range_k(1) hp_k(1))
				("breakout"						energy_base(%energy_base) armorhealth_base(%armorhealth_base) k(1) hp_k(1))
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
(define "antitank_range_apc"; reactive
		{damage blastwave
			{if props "human"}
			{if props "vehicle"
				{if props "tank heavy"
					("energy_apc"					energy_base(%energy_base) energy_apc(%energy_apc) range_base(%range_base) range_apc(%range_apc) range_end(%range_end) range_k(1))
					("armorhealth_apc"				armorhealth_base(%armorhealth_base) range_base(%range_base) range_end(%range_end) range_k(1) hp_k(0.5))
					("breakout"						energy_base(%energy_base) armorhealth_base(%armorhealth_base) k(%k) hp_k(1.0))
					("ea_spread" 					energy_base(%energy_base) armorhealth_base(%armorhealth_base))
					("armor_strength_to_damage_k" 	energy_base(%energy_base) range_end(%range_end) k(%k))
				}
				{if props "car" or props "moto"
					("energy_apc"				energy_base(%energy_base) energy_apc(%energy_apc) range_base(%range_base) range_apc(%range_apc) range_end(%range_end) range_k(1.5))
					("armorhealth_apc"			armorhealth_base(%armorhealth_base) range_base(%range_base) range_end(%range_end) range_k(1.5) hp_k(1))
					("ea_spread" 				energy_base(%energy_base) armorhealth_base(%armorhealth_base))
				}
				("energy_apc"					energy_base(%energy_base) energy_apc(%energy_apc) range_base(%range_base) range_apc(%range_apc) range_end(%range_end) range_k(1))
				("armorhealth_apc"				armorhealth_base(%armorhealth_base) range_base(%range_base) range_end(%range_end) range_k(1) hp_k(1))
				("breakout"						energy_base(%energy_base) armorhealth_base(%armorhealth_base) k(%k) hp_k(1))
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
(define "antitank_range_grenade"; grenade
		{damage blastwave
			{if props "human"}
			{if props "vehicle"
				{if props "tank heavy"
					("energy_grenade"				energy_base(%energy_base) energy_apc(%energy_apc) range_base(%range_base) range_apc(%range_apc) range_end(%range_end) range_k(1))
					("armorhealth_apc"				armorhealth_base(%armorhealth_base) range_base(%range_base) range_end(%range_end) range_k(1) hp_k(0.5))
					("breakout"						energy_base(%energy_base) armorhealth_base(%armorhealth_base) k(%k) hp_k(0.5))
					("ea_spread" 					energy_base(%energy_base) armorhealth_base(%armorhealth_base))
					("armor_strength_to_damage_k" 	energy_base(%energy_base) range_end(%range_end) k(%k))
				}
				{if props "car" or props "moto"
					("energy_grenade"			energy_base(%energy_base) energy_apc(%energy_apc) range_base(%range_base) range_apc(%range_apc) range_end(%range_end) range_k(1.5))
					("armorhealth_apc"			armorhealth_base(%armorhealth_base) range_base(%range_base) range_end(%range_end) range_k(1.5) hp_k(1))
					("ea_spread" 				energy_base(%energy_base) armorhealth_base(%armorhealth_base))
				}
				("energy_grenade"				energy_base(%energy_base) energy_apc(%energy_apc) range_base(%range_base) range_apc(%range_apc) range_end(%range_end) range_k(1))
				("armorhealth_apc"				armorhealth_base(%armorhealth_base) range_base(%range_base) range_end(%range_end) range_k(1) hp_k(1))
				("breakout"						energy_base(%energy_base) armorhealth_base(%armorhealth_base) k(%k) hp_k(1))
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
(define "construction_range_grenade"; grenade
		{damage blastwave
			{if props "human"}
			{if props "vehicle"}
			{energy
				0.5 					(* %energy_base 0.5)
				0.51					(* %energy_base 0.25)	
				%range_end	 			(* %energy_base 0.125)
				(+ %range_end 0.01)		0
			}
			("e_spread" energy_base(%energy_base))
		}
)
; antipersonnel
(define "blast_base";  explosive, calliope
	{damage blastwave		;antitank
		{if props "human"}
		{if props "vehicle"
			{energy
				%range_start_apc			%energy_apc
				%range_end_apc				(* %energy_apc 0.25)	;6
				(+ %range_end_apc 0.01)		0
			}
			{armorhealth
				%range_start_apc			(* %armorhealth 1)
				%range_end_apc				(* %armorhealth 0.5)
				(+ %range_end_apc 0.01)		0
			}
			;("breakout"						energy_base(%energy_apc) armorhealth_base(%armorhealth) k(%k) hp_k(1))
			("ea_spread" 					energy_base(%energy_apc) armorhealth_base(%armorhealth))
			;("armor_strength_to_damage_k" 	energy_base(%energy_apc) range_end(%range_end) k(%k))
			{armorhealthspread (* -1 0.1 %armorhealth 0.5) (* 0.1 %armorhealth 0.5) 1}
		}
		{energy
			%range_start_apc			%energy_apc
			%range_end_apc				(* %energy_apc 0.25)
			(+ %range_end_apc 0.01)		0
		}
		("e_spread" energy_base(%energy_base))
	}
	{damage add blastwave
		{if props "human"
			{energy
				0.9					5		;ultimate dmg
				1					0
			}
		}
	}
	{damage add fragments
		("set_antipersonnel_base"	ult(0) energy_base_start(5) energy_base(%energy_base) range_start(%range_start) range_end(%range_end))
	}
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
			("energy_k0"					energy_base(%energy_apc) range_end(%range_end_apc) range_k(1))
			("armorhealth"					armorhealth_base(%armorhealth) range_end(%range_end_apc) range_k(1) hp_k(1))
			("breakout"						energy_base(%energy_apc) armorhealth_base(%armorhealth) k(0) hp_k(1))
	;		("ea_spread"					energy_base(%energy_apc) armorhealth_base(%armorhealth))
			("armor_strength_to_damage_k"	energy_base(%energy_apc) range_end(%range_end) k(0))
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
(define "set_antipersonnel_base"
	{if props "human"
		{energy
			0.9						%ult				;500 - ultimate dmg
			1	 					%energy_base_start

			%range_start 			%energy_base
			%range_end	 			0
		}
		{chance
			(* %range_end 0.5)	1
			%range_end			0.5
		}
		{if fsm_tags "down"
			{chance
				0					1
				(* %range_end 0.5)	0.33
				%range_end			0
			}
		}
		{if in_fortification "trench"
			{chance
				0					0
				;0					1
				;(* %range_end 0.5)	0.33
				;%range_end			0
			}
		}
	}
)
(define "antipersonnel_base"
	{damage fragments
		("set_antipersonnel_base" ult(5) energy_base_start(%energy_base) energy_base(%energy_base) range_start(%range_start) range_end(%range_end))
	}
)
(define "antipersonnel_low_ext_chance"
			{chance
				3.25	1
				6.4		0.5
			}
)
(define "antipersonnel_low_ext_test_chance"
			{chance
				6.4		1
			}
)
(define "antipersonnel_low_ext_chance_down"
				{chance
					0		1
					3.25	0.33
					6.4		0
				}
)
(define "antipersonnel_low_ext_chance_trench"
				{chance
					0		0
					;0		1
					;3.25	0.2
					;6.4	0
				}
)
(define "antipersonnel_low_ext_mortar_chance_trench"
				{chance
					0		1
					3.25	0.2
					6.4		0
				}
)
(define "antipersonnel_low_ext_main"
	{damage add fragments
		{if props "human"
			{energy
				(* 0.9 %range_k)	%ult						;5=500 - ultimate dmg
				(* 2.4 %range_k)	(* 1.5555	%energy_k)		;155.55

				(* 3.9 %range_k)	(* 1.275	%energy_k)		;127.5
				(* 4.4 %range_k)	(* 0.425	%energy_k)		;42.5
				(* 5.4 %range_k)	(* 0.34		%energy_k)		;34
				(* 6.4 %range_k)	(* 0.085	%energy_k)		;8.5
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
(define "antipersonnel_low_ext"
	("antipersonnel_low_ext_main"
		range_k(%range_k)
		energy_k(%energy_k)
		ult(%ult)
		chmain(antipersonnel_low_ext_test_chance)
		chdown(antipersonnel_low_ext_chance_down)
		chtrench(antipersonnel_low_ext_chance_trench)
	)
)
(define "antipersonnel_low_ext_mortar"
	("antipersonnel_low_ext_main"
		range_k(%range_k)
		energy_k(%energy_k)
		ult(%ult)
		chmain(antipersonnel_low_ext_test_chance)
		chdown(antipersonnel_low_ext_chance_down)
		chtrench(antipersonnel_low_ext_mortar_chance_trench)
	)
)
(define "antipersonnel_air_zenite"
	{damage fragments
		{if props "human"
			{energy
				(* 0.9 %range_k)	5						;5=500 - ultimate dmg

				(* 6.4 %range_k)	5
				(* 6.5 %range_k) 	0					;
			}
		}
	}
)
(define "antipersonnel_low"
	("antipersonnel_low_ext" range_k(1) energy_k(1) ult(5))
)
(define "antipersonnel_75plus_blastwave_energy"
	{energy
		(+ 1 (* 0.02666666667 (- %cal 75)))				(* 5 %k %energy_k)		;ultimate dmg
		(+ 2.5 (* 0.02666666667 (- %cal 75)))			0
	}

)
(define "antipersonnel_75plus_fragments_energy"
	{energy
		(+ 1 (* 0.02666666667 (- %cal 75)))				0
		(+ 2.5 (* 0.02666666667 (- %cal 75)))			(* 5 %k %energy_k)

		(+ 3.5 (* 0.07666666667 (- %cal 75)))	 		(* (+ 1 (* 0.0036 (- %cal 75))) %k %energy_k)
		(+ 5 (* 0.07666666667 (- %cal 75)))				(* (+ 0.75 (* 0.0036 (- %cal 75))) %k %energy_k)
		(+ 6 (* 0.09 (- %cal 75)))	 					(* (+ 0.5 (* 0.0036 (- %cal 75))) %k %energy_k)
		(+ 8 (* 0.09 (- %cal 75)))	 					(* (+ 0.3 (* 0.0036 (- %cal 75))) %k %energy_k)
		(+ 10.4 (* 0.09 (- %cal 75))) 					(* (+ 0.2 (* 0.0036 (- %cal 75))) %k %energy_k)
		(+ 10.5 (* 0.09 (- %cal 75))) 					0
	}
)
(define "antipersonnel_75plus_chance"
			{chance
				(+ 5.25 (* 0.045 (- %cal 75)))			1
				(+ 10.4 (* 0.09 (- %cal 75)))			0.5
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
					(+ 5.25 (* 0.045 (- %cal 75)))		0.33
					(+ 10.4 (* 0.09 (- %cal 75)))		0
				}
)
(define "antipersonnel_75plus_chance_trench"
				{chance
					0									0
					;0									1
					;(+ 5.25 (* 0.045 (- %cal 75)))		0.2
					;(+ 10.4 (* 0.09 (- %cal 75)))		0
				}
)
(define "antipersonnel_75plus_mortar_chance_trench"
				{chance
					0									1
					(+ 5.25 (* 0.045 (- %cal 75)))		0.2
					(+ 10.4 (* 0.09 (- %cal 75)))		0
				}
)
(define "antipersonnel_75plus_main"
	{damage add blastwave
		{if props "human"
			{if in_house
				("antipersonnel_75plus_blastwave_energy" k(0.8) energy_k(%energy_k) cal(%cal))
			}
			("antipersonnel_75plus_blastwave_energy" k(1) energy_k(%energy_k) cal(%cal))
		}
	}
	{damage add fragments
		{if props "human"
			{if in_house
				("antipersonnel_75plus_fragments_energy" k(0.8) energy_k(%energy_k) cal(%cal))
			}
			("antipersonnel_75plus_fragments_energy" k(1) energy_k(%energy_k) cal(%cal))
			("%chmain" cal(%cal))
			{if fsm_tags "down"
				("%chdown" cal(%cal))
			}
			{if in_fortification "trench"
				("%chtrench" cal(%cal))
			}
		}
	}
)
(define "antipersonnel_75plus"
	("antipersonnel_75plus_main"
		cal(%cal)
		energy_k(1)
		chmain(antipersonnel_75plus_test_chance)
		chdown(antipersonnel_75plus_chance_down)
		chtrench(antipersonnel_75plus_chance_trench)
	)
)
(define "antipersonnel_75plus_mortar"
	("antipersonnel_75plus_main"
		cal(%cal)
		energy_k(%energy_k)
		chmain(antipersonnel_75plus_test_chance)
		chdown(antipersonnel_75plus_chance_down)
		chtrench(antipersonnel_75plus_mortar_chance_trench)
	)
)

;[___ ANTIPERSONNEL GRENADE ___
;	{___ DEFINES INPUT ___
(define "antipersonnel_grenade_blastwave_energy"
			{energy
				(* 1 %k)		5		;ultimate dmg
				(* 2 %k)		0
			}
)

(define "antipersonnel_grenade_fragments_energy"
			{energy
				(* 1	%k)		0		
				(* 2	%k)		5		;500 - ultimate dmg
				
				(* %r3	%k) 	1.5		;150
				(* 4.8	%k)	 	0.5		;50
				(* 6.8	%k)		0.4		;40
				(* 8.8	%k)		0.1		;10
				(* 8.9	%k)		0		;
			}
)
(define "antipersonnel_grenade_chance"
			{chance
				(* 4.5	%k)	1
				(* 8.8	%k)	0.5
			}
)
(define "antipersonnel_grenade_chance_down"
			{chance
				0			1
				(* 4.5 %k)	0.33
				(* 8.8 %k)	0
			}
)
(define "antipersonnel_grenade_fragments_cortege"
	("antipersonnel_grenade_fragments_energy" r3(%r3) k(%k))
	("antipersonnel_grenade_chance%chance" k(%k))
)
(define "antipersonnel_grenade_base"
	{damage add blastwave
		{if props "human"			("antipersonnel_grenade_blastwave_energy" k(%k))}
	}
	{damage add fragments
		{if props "human"
			{if in_house			("antipersonnel_grenade_fragments_cortege"	r3(%r3_in_house)	k(%k)	chance())}
			{if fsm_tags "down"		("antipersonnel_grenade_fragments_cortege"	r3(%r3)				k(%k)	chance(_down))}
									("antipersonnel_grenade_fragments_cortege"	r3(%r3)				k(%k)	chance())
		}
	}
)
;}
;	{___ DEFINES OUTPUT ___
(define "antipersonnel_grenade"		("antipersonnel_grenade_base"	r3(4)	r3_in_house(4)	k(%k)))
(define "antipersonnel_grenade_pp"	("antipersonnel_grenade_base"	r3(3)	r3_in_house(4)	k(%k)))
;}
;]

(define "antipersonnel_mortar"
	(define "fragments_energy_default"
		{energy
			(+ 0.9 (* 0.01 (- %cal 50)))						0		;500 - ultimate dmg
			(+ (* 1 %range_start_k) (* 0.01 (- %cal 50)))	 	5

			(+ 2 (* 0.02 (- %cal 50)))							%energy_base
			(+ %range_end (* 0.02 (- %cal 50)))	 				0
		}
	)
	{damage add blastwave
		{if props "human"
			{if in_fortification "trench"
				{energy
					(+ 0	(* 0.01 (- %cal 50)))				5		;ultimate dmg
					(+ 1	(* 0.01 (- %cal 50)))				1
					(+ 2	(* 0.01 (- %cal 50)))				0
				}
			}
			{energy
				(+ 0.9	(* 0.01 (- %cal 50)))					5		;ultimate dmg
				(+ 1	(* 0.01 (- %cal 50)))					0
			}
		}
	}
	{damage add fragments
		{if props "human"
			("fragments_energy_default" energy_base(%energy_base) range_start_k(1) range_end(%range_end) cal(%cal))
			{if fsm_tags "down"
				{chance
					0					1
					(+ (* %range_end 0.5) (* 0.01 (- %cal 50)))	0.33
					(+ %range_end (* 0.02 (- %cal 50)))			0
				}
			}
			{if in_fortification "trench"
				;("fragments_energy_default" energy_base(%energy_base) range_start_k(2) range_end(%range_end) cal(%cal))
				{chance
					0					0
					;0					1
					;(+ (* %range_end 0.5) (* 0.01 (- %cal 50)))	0.33
					;(+ %range_end (* 0.02 (- %cal 50)))			0
				}
			}
			{chance
				(+ (* %range_end 0.5) (* 0.01 (- %cal 50)))			1
				(+ %range_end (* 0.02 (- %cal 50)))					0.5
			}
		}
	}
)