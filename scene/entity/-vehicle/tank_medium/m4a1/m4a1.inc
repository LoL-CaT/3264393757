{entity
	(include "/properties/tank_without_mgun.ext")
	(include "/properties/shadow/tank.inc"  scale(1.2))
	(include "/properties/selection/vehicle.inc"  scale(1.2))
	("bone_rotator")
	{props "medium" "turret_rotator" "vision_lev05" "ram_lvl7" "texmod_w_cf_cd" "anm_tank"}
	{able "%ableoffemit_passangers_on_enemy"}

	{extender "enumerator"
		{group "usa"}
	}
	("crew_4_human")

	("v_body" n(01) t())
	("v_body" n(02) t())
	("v_body" n(03) t())
	("v_body" n(04) t(04))
	("v_engine" n(01) t())
	("v_engine" n(02) t(02))
	("v_turret" n(01) t())
	("v_turret" n(02) t(02))
	("v_turret" n(03) t(03))

	("arena_armor_mantlet" t(50.8))
	("arena_armor_medium" turret(76.2 50.8 50.8 25.4) gun(30) engine(30 38.1 38.1 19.5) body(50.8 38.1 38.1 19.5) track(20) hp(647))
	{armor
		("module_body_medium" 		n(04)					body(50.8 38.1))
		("module_engine_medium" 	n(02)					engine(38.1))
		("module_detail_shield"		n(1)	vol("gun_rot")	t(50.8))
		("module_turret_medium" n(02) turret(50.8 50.8 50.8 25.4) hp_k(0.95))
		("module_turret_medium" n(03) turret(76.2) hp_k(1))
		("module_other" t(4))
	}
	{boarder
		{anm "left"
			{forward	{begin	"board_sherman_left"} {end "seat_m7_mgunner"}}
			{reverse 	{end	"emit_tank_2_hold"}}
		}
		{anm "right"
			{forward	{begin	"board_sherman_right"} {end "seat_m7_mgunner"}}
			{reverse 	{end	"emit_tank_2_hold"}}
		}
		{anm "armor"
			{forward	{begin	"board_HighArmor"} 	{end "idle_onboard_m"}}
			{reverse 	{end	"emit_tank_2"}}
		}
		{anm "armor1"
			{forward	{begin	"board_HighArmor"} {end "idle_onboard"}}
			{reverse 	{end	"emit_body"}}
		}
	}
	(define "seat_human_set1"
		("seat_human" place(seat_m1) bone(seat01) door(emit3)  animation(armor))
		("seat_human" place(seat_m2) bone(seat02) door(emit3)  animation(armor))
		("seat_human" place(seat_m3) bone(seat03) door(emit4)  animation(armor))
		("seat_human" place(seat_m4) bone(seat04) door(emit4)  animation(armor))
	)
	(define "seat_human_set2"
		("seat_human_set1")
		("seat_human" place(seat5) bone(seat05) door(emit5)  animation(armor1))
	)
	("seat_human_set%seat")

	{extender "inventory"
		{weapon "mgun1"
			{mask "weapon mgun"}
		}
		{box
			{item "ammo mgun" 3000}
			{item "ammo hmgun" 300}
			{item "ammo bullet75 ap ally std" 45}
			{item "ammo bullet75 fg ally std" 45}
			{item "ammo bullet75 ph ally std" %ph}
			{item "browning_m19" filled {user "mgun1"}}
		}
	}
	{Weaponry
		("restore_ik_time")
		{place "gun"
			{RestoreIKAfterAim}
			{weapon "75mm_m3" filled}
			{gunner "gunner"}
			{charger "gunner"}
			("abm_tank_cannon_stab")
			{basic}
		}
		{place "mgun2"
			{type "coaxial"}
			{weapon "browning_m19" filled}
			{foresight "foresight5"}
			{gunner "gunner"}
			{charger "gunner"}
			("sequential_aim")
			("abm_mgun")
			{basic}
		}
		{place "mgun1"
			{type "hull"}
			{foresight "foresight4"}
			{gunner "driver"}
			{charger "driver"}
			("abm_mgun")
			{basic}
		}
	}
	{mass 30600}
	{Chassis
		("tank_trace" fx("tracks_sm") step(0.3)  len(0.56))
		{Locomotion ("locomotion")
			{MaxSpeed	       42}
			{maxSpeedAtMaxTurn 14.25}
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
			volume(188)
			rate(50)
			remain(188)
		)
	}
	("chassis_add_medium" speed(42))
	{Extension "m4a1.mdl"}
	("animation_resume")
	{extension "sensor.ext"}
	{extension "camouflage.ext"}
	
	{bone "gun_rot"
		{limits -15 25}
        {speed 0.004}
	}
	{bone "turret"
		("arena_turret_speed" args 0.0143)	
	}
	{bone "mgun1"
		{limits 15}
		{speed2 80}
	}
	{bone "basis"
		{parameters "WheelRadius=0.3;"}
	}
	{bone "wheell1"
		{parameters "ID=trackleft;Radius=0.57;"}
	}
	{bone "wheelr1"
		{parameters "ID=trackright;Radius=0.57;"}
	}
	{bone "wheell8"
		{parameters "ID=trackleft;Radius=0.42;"}
	}
	{bone "wheelr8"
		{parameters "ID=trackright;Radius=0.42;"}
	}
	(define "support_bones_std"
		("support_bones" n(%n) r(%r) lname(trackl) rname(trackr))
	)
	("support_bones_std" n(1) r(0.57))
	("support_bones_std" n(2) r(0.34))
	("support_bones_std" n(3) r(0.34))
	("support_bones_std" n(4) r(0.34))
	("support_bones_std" n(5) r(0.34))
	("support_bones_std" n(6) r(0.34))
	("support_bones_std" n(7) r(0.34))
	("support_bones_std" n(8) r(0.42))
}