{entity
	(include "/properties/tank_without_mgun.ext")
	(include "/properties/shadow/tank.inc"  scale(1.3))
	(include "/properties/selection/vehicle.inc"  scale(1.2))
	("bone_rotator")
	
	{props "medium" "turret_rotator" "vision_lev05" "ram_lvl5" "texmod_w_cf_cd" "anm_tank"}
	{able "%ableoffemit_passangers_on_enemy"}

	("sandbags_t34_76")
	
	("v_body" n(1) t())
	("v_body" n(2) t())
	("v_gun" n(_rot) t(_rot))

	("arena_armor_mantlet" t(35))
	("arena_armor_medium" turret(45 45 45 15) gun(20) engine(45 40 40 30) body(45 40 40 20) track(20) hp(645))
	{armor
		("module_gun_medium" n(_rot) gun(25))
	}

	
	{extender "enumerator"}

	("crew_4_human_extended")
	{boarder
		{anm "driver"
			{forward	{begin	"board_t34_driver"} {end "seat_gunner_stand"} {base "open_driver"}}
			{reverse 	{end	"emit_t34_hold"} {base "close_driver"}}
		}
		{anm "left"
			{forward	{begin	"board_Is-2"}}
			{reverse 	{end	"emit_tank_1_hold"}}
		}
		{anm "right"
			{forward	{begin	"board_Is-2"}}
			{reverse 	{end	"emit_tank_1_hold"}}
		}
		{anm "armor"
			{forward	{begin	"board_HighArmor"} 	{end "idle_onboard_m"}}
			{reverse 	{end	"emit_tank_2"}}
		}
	}
	(define "seat_human_set1"
	("seat_human" place(seat_m1) bone(seat01) door(emit3)  animation(armor))
	("seat_human" place(seat_m2) bone(seat02) door(emit4)  animation(armor))
	("seat_human" place(seat_m3) bone(seat03) door(emit5)  animation(armor))
	("seat_human" place(seat_m4) bone(seat04) door(emit6)  animation(armor))
	)
	(define "seat_human_set2"
		("seat_human_set1")
		("seat_human" place(seat_m5) bone(seat05) door(emit7)  animation(armor))
	)
	("seat_human_set%seat")

	("components_tank" 
		repair_body(5)
		repair_engine(31)
		repair_turret(31)
		repair_gun(21)
		repair_track(14)
	)

	{extender "inventory"
		{box
			{clear}
			("base_inventory")
			{item  "ammo mgun" 1800}
			{item "ammo bullet76 ap rus std" 40}
			{item "ammo bullet76 fg rus std" 37}
			{item "ammo bullet76 fr rus std" %fr}
			{item "sandbag_kit2"}
		}
	}
	{Weaponry
		("restore_ik_time")
		{place "gun"
			{RestoreIKAfterAim}
			{weapon "76mm_l11" filling "ammo bullet76 ap rus std" 1}
			("abm_tank_cannon") 
		}
		{place "mgun2"
			{type "coaxial"}
			{weapon "dt_vh" filled}
			{foresight "foresight5"}
			{gunner "gunner"}
			{charger "gunner"}
			("sequential_aim")
			("abm_mgun")
			{basic}
		}
		{place "mgun1"
			{type "hull"}
			{weapon "dt_vh" filled}
			{foresight "foresight4"}
			{gunner "driver"}
			{charger "driver"}
			("abm_mgun")
			{basic}
		}
	}

	{mass 25600}
	{Chassis
		("tank_trace" fx("tracks_mid") step(0.52) len(1.3))
		{Locomotion ("locomotion")
			{MaxSpeed	       49}
			{maxSpeedAtMaxTurn 18.375}
			{StartTime	       4}
			{TurnTime	        8}
			{TurnStart        1.1} 
			{BrakeTime        0.5}
			{StopTime         0.5} 
			{TurnRadius         4} 
			{TurnStop         0.7} 
			{Gears      0.2 0.5 1.0}
			{RearGears       0.2 0.45}
		}
		("fuelbag"
			volume(288)
			rate(50)
			remain(288)
		)
	}

	{extension "t34_76.mdl"}
	("animation_resume")

	{bone "gun_rot"
		("arena_turret_speed" args 0.0149)
		{limits -8 29}
	}
	{bone "turret"
		("arena_turret_speed" args 0.0149)
	}	
	{bone "foresight5"
		{limits -1 1}
	}
	{bone "mgun"
		{limits 15}
		{speed2 80}
	}
	("chassis_add_medium" speed(49))
	{extension "sensor.ext"}
	{extension "camouflage.ext"}
	(define "support_bones_std"
		("support_bones" n(%n) r(%r) lname(trackl) rname(trackr))
	)
	("support_bones_std" n(1) r(0.23))
	("support_bones_std" n(2) r(0.46))
	("support_bones_std" n(3) r(0.46))
	("support_bones_std" n(4) r(0.46))
	("support_bones_std" n(5) r(0.46))
	("support_bones_std" n(6) r(0.46))
	("support_bones_std" n(7) r(0.32))
}