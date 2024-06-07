{Entity
	(include "/properties/tank_without_mgun.ext")
	(include "/properties/shadow/tank.inc"  scale(1.2))
	(include "/properties/selection/vehicle.inc"  scale(1.2))
	("bone_rotator")
	{props "medium" "turret_rotator" "vision_lev05" "ram_lvl6" "texmod_w_cf_c2f_cd" "muzzle_brake" "anm_tank"}
	{able "%ableoffemit_passangers_on_enemy"}
	
	("v_body" n(01) t(01))
	("v_body" n(02) t(02))
	("v_body" n(03) t())
	("v_body" n(04) t(02))
	("v_engine" n(01) t())
	("v_turret" n(01) t())
	("v_turret" n(02) t())
	("v_turret" n(03) t(1))
	("v_gun" n(_rot_01) t(_rot))
	("v_gun" n(_rot_02) t())

	("arena_armor_mantlet" t(50))
	("arena_armor_medium" turret(50 30 30 10) gun(20) engine(20 20 20 10) body(50 30 20 11) track(20) hp(560))
	{armor
		("module_body_medium" 	n(02) body(20 30 20 20))
		("module_body_medium" 	n(01) body(50 30 20 20))

		("module_gun_medium" 	n(_rot) gun(50 20 20 20))
		("module_turret_medium" n(1) turret(80 80 80 8) hp_k(0.95))
		("module_other" 		t(5))
	}

	("crew_4_human_extended")
	("crew_human" place(gunner3) door1(emit2) door2(emit1) visor(main))

	{boarder
		{anm "driver"
			{forward	{begin	"board_pz4_driver"} {end "seat_gunner_stand"} {base "open_driver"}}
			{reverse 	{end	"board_pz4_driver" -1} {base "open_driver" -1}}
		}
		{anm "left"
			{forward	{begin	"board_Is-2"} {end "seat_gunner_stand_ferd"}}
			{reverse 	{end	"emit_tank_1_hold"}}
		}
		{anm "right"
			{forward	{begin	"board_Is-2"} {end "seat_gunner_stand_ferd"}}
			{reverse 	{end	"emit_tank_1_hold"}}
		}
		{anm "armor"
			{forward	{begin	"board_MiddleArmor"} 	{end "idle_onboard"}}
			{reverse 	{end	"emit_tank_1"}}
		}
		{anm "armor1"
			{forward	{begin	"board_MiddleArmor"} 	{end "idle_onboard_l"}}
			{reverse 	{end	"emit_body"}}
		}
		{anm "armor2"
			{forward	{begin	"board_MiddleArmor"} 	{end "idle_onboard_r"}}
			{reverse 	{end	"emit_body"}}
		}
	}

	(define "seat_human_set1"
		("seat_human" place(seat_l1) bone(seat01) door(emit3)  animation(armor1))
		("seat_human" place(seat_r1) bone(seat02) door(emit5)  animation(armor2))
		("seat_human" place(seat3) bone(seat03) door(emit7)  animation(armor))
		("seat_human" place(seat4) bone(seat04) door(emit4)  animation(armor))
	)
	(define "seat_human_set2"
		("seat_human" place(seat_l1) bone(seat01) door(emit3)  animation(armor))
		("seat_human" place(seat_r1) bone(seat02) door(emit5)  animation(armor1))
		("seat_human" place(seat3) bone(seat03) door(emit7)  animation(armor))
		("seat_human" place(seat4) bone(seat04) door(emit4)  animation(armor1))
		("seat_human" place(seat5) bone(seat05) door(emit6)  animation(armor))
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
			{item "ammo mgun" 3000}
			{item "ammo bullet75 ap ger std" 50}
			{item "ammo bullet75 fg ger std" 15}
			{item "ammo bullet75 fr ger std" %fr}
		}
	}
	{Weaponry
		("restore_ik_time")
		{place "gun"
			{RestoreIKAfterAim}
			{weapon "75mm_kwk40" filled}
			{gunner "gunner"}
			{charger "gunner"}
			("abm_tank_cannon")
			{basic}
		}
		{place "mgun2"
			{type "coaxial"}
			{weapon "mg34_vh" filled}
			{foresight "foresight5"}
			{gunner "gunner"}
			{charger "gunner"}
			("sequential_aim")
			("abm_mgun")
			{basic}
		}
		{place "mgun1"
			{type "hull"}
			{weapon "mg34_vh" filled}
			{foresight "foresight4"}
			{gunner "driver"}
			{charger "driver"}
			("abm_mgun")
			{basic}
		}
	}

	{mass 23000}
	{Chassis
		("tank_trace" fx("tracks_mid") step(0.52) len(0.7))
		{Locomotion ("locomotion")
			{MaxSpeed	       38}
			{maxSpeedAtMaxTurn 13.875}
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
			volume(163)
			rate(50)
			remain(163)
		)
	}
	{extension "pz4f2%mdl.mdl"}
	("animation_resume")
	{bone "gun_rot"
		{limits -15 25}
		{speed 0.007}
	}
	{bone "turret"
		("arena_turret_speed" args 0.0063)
	}
	{bone "mgun"
		{limits 15}
		{speed2 80}
	}
	("chassis_add_medium" speed(37))
	{extension "sensor.ext"}
	{extension "camouflage.ext"}
	(define "support_bones_std"
		("support_bones" n(%n) r(%r) lname(trackl) rname(trackr))
	)
	("support_bones_std" n(1) r(0.42))
	("support_bones_std" n(2) r(0.28))
	("support_bones_std" n(3) r(0.28))
	("support_bones_std" n(4) r(0.28))
	("support_bones_std" n(5) r(0.28))
	("support_bones_std" n(6) r(0.28))
	("support_bones_std" n(7) r(0.28))
	("support_bones_std" n(8) r(0.28))
	("support_bones_std" n(9) r(0.28))
	("support_bones_std" n(10) r(0.4))
}