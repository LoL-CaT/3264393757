{"airborne"
;	{friction 0.2}
;	{restitution 0.01}
	{on spawn
		{able inventory_operation 0}
;		{link_sound "fall"				"vehicle/airborne/fw_deep"			}
		{add_view 	"smoke_aero_dead_big" 	"fire" 				"body"}
		{add_view 	"smoke_aero_dead_big" 	"prepare_to_fall" 	"body"}
		{add_view 	"smoke_aero_dead_big" 	"fire_2" 	"flap2"}

		{add_view	"exhaust_dark_big"	"engine_exhaust"		"FXsmoke1"	}
		{add_view	"exhaust_dark_big"	"engine_exhaust" 		"FXsmoke2"	}
		{add_view	"exhaust_dark_big"	"engine_exhaust"		"FXsmoke3"	}
		{add_view	"exhaust_dark_big"	"engine_exhaust" 		"FXsmoke4"	}
		{add_view	"exhaust_dark_big"	"engine_exhaust"		"FXsmoke5"	}
		{add_view	"exhaust_dark_big"	"engine_exhaust" 		"FXsmoke6"	}
		{add_view	"exhaust_dark_big"	"engine_exhaust"		"FXsmoke7"	}
		{add_view	"exhaust_dark_big"	"engine_exhaust" 		"FXsmoke8"	}
		{set "engine_started" 0}
		{call "init_gun"}
	}
	{on "add_movement_sound"
		{link_sound "fly"				"vehicle/airborne/p_51/p_51_fly"	}
		{link_sound "engine_start"		"vehicle/airborne/p_51/p_51_start"	}
		{link_sound "engine_work"		"vehicle/airborne/p_51/p_51_engine"	}
		{link_sound "engine_stop"		"vehicle/airborne/p_51/p_51_stop"	}
	}
	{on "takeoff"
		{if not tagged "destroyed"
			{ani_play "wheels" 0.2}
			{play_sound "fly" 1 0.5}
			{call "vol_sphere_on"}
		}
	}
	{on "takeoff_load"
		{ani_wind "wheels" end}
	}
	{on "landing"
		{ani_play "wheels" -0.2}
		{stop_sound "fly"}
		{call "vol_sphere_off"}
	}
	{on engine on overload
		{call "engine_on"}
		{if altitude 5 {ani_play "wheels" 10.0}}
	}
	{on animation_end "engine_start"
		{ani_play "engine_work" loop}
		{play_sound "engine_work" 1 0.5}
	}
	{on engine off overload
		{call "engine_stop"}
		{play_sound "engine_stop"}
	}
	{on "engine_on"
		{if not flag "engine_started"
			{set "engine_started" 1}
			{view start "engine_exhaust"}
			{delay 1
				{view pause "engine_exhaust"}
			}
			{if chassis "airborne"
				{call "vol_sphere_on"}
				{ani_play "engine_work" loop}
				{play_sound "fly" 1 3}
				{play_sound "engine_work" 1 3}
			else
				{ani_play "engine_start" callback}
				{play_sound "fly" 1 3}
				{play_sound "engine_work" 1 3}
				{play_sound "engine_start"}
			}
		}
	}
	{on "update_moveable" overload
		{if not chassis "airborne"
			{inherited}
		}
	}
	{on "engine_stop"
		{kill_delay "engine_stopped"}
		{if flag "engine_started"
			{set "engine_started" 0}
			{ani_stop "engine_start"}
			{ani_stop "engine_work"}
			{ani_play "engine_stop"}
			{delay 1.0
				{stop_sound "engine_start"}
				{stop_sound "engine_work"}
				{stop_sound "fly"}
			}
			{play_sound "engine_stop"}
		}
	}
	{on break_armor
		{if name "pierce"
			{if stuff "shell"
				{call "pierce"}
			else stuff "zenite"
				{if rand 0.3
					{call "pierce"}
				}
			}
		else name "blast"
			{if volume "body"
				{impulse up 1 0.5 dir 0.3 0.2}
				{call "explosion"}
			}
		}
	}
	{on "pierce"
		{if work
			{component break}
			{spawn "aero_die_particle"}
			{if volume "engine"
				{burn fx "smoke_aero_big" fake}
			else volume "body"
				{burn fx "smoke_aero_big" fake}
			else;volume "inflammable"
				{burn fx "smoke_aero_small" fake}
			}
		}	
		{##if not volume "sphere"
			{tags add "000"}
		}		
	}
	{on bullet_hit
		{attack_save}
		{if volume "sphere" and chassis "airborne"
			{if stuff "shell fx20" and rand 0.5					{spawn "ex_air_zenith_20"}}
			{if stuff "shell fx37_46"							{spawn "ex_air_zenith_40"}}
			{if stuff "shell fx77_90" or stuff "shell fx61_76"	{spawn "ex_air_zenith_80"}}
		}
		{##if not volume "sphere"
			{tags add "000"}
		}
	}
	{on "vol_sphere_off"
		{volumes "sphere" disable all}
	}
	{on "vol_sphere_on"
		{volumes "sphere" enable bullet}
	}
	{on "got_any_damage"
		{if armor_health 1 and not flag "broken" and not tagged "destroyed"
			{if chassis "airborne"
				{call "fall"};{tags add "dam1"}
			else
				{call "pierce"}
				{crew_emit}
				{call "mp_destroy"};{tags add "dam2"}
			}
		else
			{call "fire"};{tags add "dam3"}
			{if auto_withdraw_reason "damage_any" or auto_withdraw_reason "damage_percent" and armor_health_percent 0.7
				{withdraw}
			}
		}
	}
	{on pierce
		{call "check_ur_pierce"}
		{call "got_any_damage"};{if volume "sphere" {tags add "323232"}}
	}
	{on blast
		{attack_save}
		{call "got_any_damage"};{tags add "blast"}
	}
	{on "fall"
		{if not flag "fall"
			{set "fall" 1}
			{if territory_type "enemy" 
				{manual_shot}
			}
			{parachute
				{entity "paratrooper_attach"} 
				{place_groups "crew passengers"}
				{interval 0.15}
			}
			{delay 0.5
				{attack_load {kill_crew}}
			}
			{call "pre_die"}
			{delay 3
				{impulse up 0.1 com}
				{explosive 1}
;				{play_sound "fall"}
				{call "fall_fx"}
			}
		}
	}
	{on "fall_fx"
		{delay 0.2
			{view stop "prepare_to_fall"}
			{view start "fire"}
			{delay 10
				{view stop "fire"}
			}
			{burn volume "body" fx "smoke_aero_big" time 10 fake}
			{burn volume "engine" fx "smoke_aero_big" time 10 fake}
			{delay 10.1
				{burn volume "body" fx "smoke_black" time 40 10 fake}
			}
;			{burn volume "wingr1" fx "smoke_aero_big" time 5 fake}
;			{burn volume "wingl1" fx "smoke_aero_big" time 5 fake}
		}
	}
	{on "fire"
		{if chassis "airborne"
			{if not flag "fall"
				{if armor_health 100
					{view start "prepare_to_fall"}
				}
			}
		}
	}
	{on ground_hit
		{stop_sound "fly"}
		{stop_sound "engine_work"}
		{if not armor_health 1
			{armor_health_damage_fatal}
		}
		{if not tagged "ground_fire_detonation"
			{spawn "circledust_big"}
			{call "collide"}
			{delay 2.5 1
				{call "explosion"}
			}
		else
			{spawn "tank_die"}
			{call "collide"}
			{delay 5 2
				{call "explosion_var_2"}
			}
		}
	}
	{on contact overload
		{if effector "vehicle" and not chassis "airborne"
			{call "collide"}
		else effector "construction"
			{call "collide"}
		else effector "tree" and not chassis "airborne"
			{call "collide"}
		else effector "fence"
			{if volume "part"
				{call "tear_part"}
			}
		}
	}
	{on "collide"
		{if volume "part"
			{call "tear_part"}
		}
	}
	{on "tear_part"
		{spawn "spheredust_big_short"}
		{component destroy}
		{components "engine" destroy}
		{volume disable contact contact_ground}
		{chassis_work 0}
		{tear "piece_big_airborne_wing" bone from_volume
			{impulse up 2 1 dir 2 1}
		}
		{impulse up 0.1 com}
	}

	(define "burn_part"
		{on "burn_%0_start"
			{add_view "smoke_aero_big"		"fire%0" "fx_fire%0_1"}
			{add_view "smoke_aero_big"		"fire%0" "fx_fire%0_2"}
			{add_view "smoke_aero_big"		"fire%0" "fx_fire%0_3"}
			{add_view "smoke_aero_small"	"fire%0" "fx_smoke%0_1"}
			{add_view "smoke_aero_small"	"fire%0" "fx_smoke%0_2"}
			{add_view "smoke_aero_small"	"fire%0" "fx_smoke%0_3"}
			{view start "fire%0"}
		}
		{on "burn_%0_stop"
			{view stop "fire%0"}
		}
	)
	("burn_part" args 1)
	("burn_part" args 2)
	("burn_part" args 3)
	("burn_part" args 4)

	{on "pre_die"
		{able select 0}
		{drop_orders}
		{components destroy}
		{call "engine_stop"}
		{stop_sound "engine_stop"}
		{bone hide "engine_work"}
		{weapon_work "zenite" 0}
	}
	{on "die"
		{call "pre_die"}
		{chassis_work 0}
;		{stop_sound "fall"}
		{explosive 0}
		{burn stop}
		{call "vol_sphere_off"}
	}
	
	(define "cut_part"
		{if rand %1
			{tear "piece_big_airborne_wing" bone %0
				{impulse up 2.5 1 dir 2.5 1}
			}
		}
	)
	(define "cut_part_big"
		{if rand %1
			{tear "piece_big_airborne_wing" bone %0
				{impulse up 3 4 dir 3 4}
			}
		}
	)
	(define "cut_part_flame"
		{if rand %1
			{tear "piece_big_airborne_wing" bone %0
				{impulse up 2 3 dir 4 5}
				{if rand 0.6
					{add_view "smoke_aero_small" "fx_fire" "basis"}
					{view start "fx_fire"}
				else rand 0.6
					{add_view "smoke_black_big" "fx_fire" "basis"}
					{view start "fx_fire"}				
				else
				}
			}
		}
	)	
	{on "__explosion" overload
		{attack_load {kill_crew}}
		{clear_inventory}
		{call "die"}
		{add_view "aero_die" "fire" "body"}
		{add_view "aero_die_fire" "fire" "body"}
		{view start "fire"}
		{spawn "aero_die_particle"}
		{tags add "destroyed"}
		{tags remove "air"}

		{impulse up -0.1 com}
		{delay 0.25 {impulse up -0.1 com}}
		{delay 0.1
			{if rand 0.33
				{if stuff "fg"
					{if rand 0.25
						{call "explosion_var_1"}
					else rand 0.5
						{call "explosion_var_2"}
					else
						{call "explosion_var_3"}
					}
				else stuff "shell"
					{if rand 0.33
						{call "explosion_var_2"}
					else rand 0.33
						{call "explosion_var_3"}
					else rand 0.33
						{tags add "ground_fire_detonation"}{view start "fire_2"}
					else
						{call "explosion_var_2"}
					}				
				else
					{if rand 0.25
						{tags add "ground_fire_detonation"}{view start "fire_2"}
					else
						{call "explosion_var_2"}
					}
				}
			else rand 0.49
				{if stuff "fg"
					{if rand 0.25
						{call "explosion_var_2"}
					else
						{call "explosion_var_1"}
					}
				else stuff "shell"
					{if rand 0.5
						{call "explosion_var_2"}
					else rand 0.5
						{call "explosion_var_1"}
					else
						{tags add "ground_fire_detonation"}{view start "fire_2"}
					}				
				else
					{tags add "ground_fire_detonation"}{view start "fire_2"}
				}			
			else
				("cut_part" args "wingr1"		0.5)
				("cut_part" args "wingl1"		0.5)
				("cut_part" args "wingr2"		0.5)
				("cut_part" args "wingl2"		0.5)
				("cut_part" args "body_back"	0.5)
				("cut_part" args "propeller"	1.0)
			}
			{volumes disable obstacle touch}
			{volumes "body" enable obstacle}
			{volumes "body_back" disable obstacle}
			{area rebuild}
		}
		{fragments c4 7 r0 5 r1 8}
	}
	
	{on "explosion_var_1"
		{spawn "ex_air_big2" "body"}
		{delay 2 {spawn "ex_air_big2" "body"}}
		{delay 0.1
			("cut_part_big" args "wingr1"		1.0)
			("cut_part_big" args "wingl1"		1.0)
			("cut_part_big" args "wingr2"		1.0)
			("cut_part_big" args "wingl2"		1.0)
			("cut_part_big" args "body_back"	1.0)
			("cut_part_big" args "propeller"	1.0)
		}
	}
	{on "explosion_var_2"
		{spawn "ex_air_detonation" "body"}
		{if not tagged "ground_fire_detonation" {delay 2 1 {spawn "fuel_die" "body"}}}
		{delay 0.1
			("cut_part_big" args "wingr1"		1.0)
			("cut_part_big" args "wingl1"		1.0)
			("cut_part_big" args "wingr2"		1.0)
			("cut_part_big" args "wingl2"		1.0)
			("cut_part_big" args "body_back"	1.0)
			("cut_part_big" args "propeller"	1.0)
		}
	}
	{on "explosion_var_3"
		{spawn "ex_air_zenith_80" "body"}
		{delay 0.1
			{delay 1.5 1	("cut_part_flame" args "wingr1"		1.0)}
			{delay 2.5 1	("cut_part_flame" args "wingl1"		1.0)}
			{delay 2.5 1	("cut_part_flame" args "wingr2"		1.0)}
			{delay 1.5 1	("cut_part_flame" args "wingl2"		1.0)}
			{delay 1.5 1	("cut_part_flame" args "body_back"	1.0)}
			{delay 0.5		("cut_part_big" args "propeller"	1.0)}
		}	
	}
	
	{on "_explosion" overload
		{start_sound "crush/big/airborne"}
		{call "__explosion"}
	}
	{on "mp_destroy" ;hack for "burn_damage"	
		{if not tagged "destroyed"
			{start_sound "detonation/hit_huge/hit_huge"}
			{call "__explosion"}
		}
	}
	{on "spawn_bomb"
		{spawn "air_bomb_small"}
	}
	{on "kick"
		{impulse up 0.1 com}
	}
	{on "area_disable"
		{area disable}
	}
	{on "area_enable"
		{area enable}
	}
	{on "air_attack"
		{start_sound "vehicle/airborne/air_attack"}
	}

	{on "init_gun"
		(define "view_x3_barrel_x2"
			{add_view "%view1"	"%name001"		"%barrel00"}
			{add_view "%view1"	"%name011"		"%barrel01"}
		)
		(define "view_x3_barrel_x5"
			("view_x3_barrel_x2"
				view1(%view1)
				barrel(%barrel)
				name(%name)
			)
			{add_view "%view1"	"%name021"		"%barrel02"}
			{add_view "%view1"	"%name031"		"%barrel03"}
			{add_view "%view1"	"%name041"		"%barrel04"}
		)
		("view_x3_barrel_x5"
			view1(flash_zenit01)
			barrel(barrel)
			name(flashbarrel)
		)
		(define "fire_mgun"
			(define "flash_barrel"
				{view start "%2%0%1"}
				{delay 0.42
					{view pause "%2%0%1"}
				}
			)
			(define "fire_barrel"
				name "%0"
					("flash_barrel" args %0 1 %1)
			)
			{if ("fire_barrel" args 00 %name)
			else ("fire_barrel" args 01 %name)
			}
		)
	}
	{on fire "zenite"
		(define "flash_barrel"
			{view start "flashbarrel%0%1"}
			{delay 0.42
				{view pause "flashbarrel%0%1"}
			}
		)
		(define "fire_barrel"
			name "%0"
				("flash_barrel" args %0 1)
		)
		
		{if ("fire_barrel" args 00)
		else ("fire_barrel" args 01)
		else ("fire_barrel" args 02)
		else ("fire_barrel" args 03)
		else ("fire_barrel" args 04)
		}
	}
}

{"airborne no_explosion"
	{on contact
;		{components "wingleft" destroy}
;		{components "wingright" destroy}
	}
	{on ground_hit
		{call "die"}
		{impulse up 0.1 com}
	}
	{on "_explosion" overload
		{call "die"}
		{impulse up 0.1 com}
		("cut_part" args "wingr2"		0.5)
		("cut_part" args "wingl2"		0.5)
	}
	{on "fall_fx" overload
	}
}

{"air_part"
	{on spawn
		{delay 0.1
			{volumes enable contact contact_ground}
		}
		{view stop ""}
		{add_view "smoke_black" "smoke" "root"}
		{view start "smoke"}
		{delay 180 30
			{view stop "smoke"}
		}
	}
	{on ground_hit
		{if min_speed 5
			{spawn "spheredust_big_short"}
		}
	}
}

{"air_part wing"
	{on ground_hit
		{if volume "part"
			{if volume_bone_level 3
				{call "tear_part"}
			}
		}
	}
	{on "tear_part"
		{tear "piece_big_airborne_wing" bone from_volume
			{impulse up 0.1 0.05}
		}
	}
}

(define "p51"
	{on "add_movement_sound" overload
		{link_sound "fly"				"vehicle/airborne/p_51/p_51_fly"	}
		{link_sound "engine_start"		"vehicle/airborne/p_51/p_51_start"	}
		{link_sound "engine_work"		"vehicle/airborne/p_51/p_51_engine"	}
		{link_sound "engine_stop"		"vehicle/airborne/p_51/p_51_stop"	}
	}
	{on "update_lights" overload}
)
{"airborne p-51mustang"
	("p51")
}
{"airborne p51"
	("p51")
}
{"airborne p51d"
	("p51")
}

{"airborne cg-4a"
	{on spawn
		{add_view	"smoke_plane"	"smoke01"		"fx_smoke01"}
		{add_view	"smoke_plane"	"smoke02"		"fx_smoke02"}
		{add_view	"smoke_plane"	"smoke03"		"fx_smoke03"}
		{add_view	"smoke_plane"	"smoke04"		"fx_smoke04"}
		{add_view	"smoke_plane"	"smoke05"		"fx_smoke05"}
		{add_view	"smoke_plane"	"smoke06"		"fx_smoke06"}
		{add_view	"smoke_plane"	"smoke07"		"fx_smoke07"}
		{add_view	"smoke_plane"	"smoke08"		"fx_smoke08"}
		{add_view	"smoke_plane"	"smoke09"		"fx_smoke09"}
		{add_view	"smoke_plane"	"smoke10"		"fx_smoke10"}
		{add_view	"smoke_plane"	"smoke11"		"fx_smoke11"}
		{add_view	"smoke_plane"	"smoke12"		"fx_smoke12"}
	}
	{on "tear_part"
		{view start "smoke01"}
		{view start "smoke02"}
		{view start "smoke03"}
		{view start "smoke04"}
		{view start "smoke05"}
		{view start "smoke06"}
		{view start "smoke07"}
		{view start "smoke08"}
		{view start "smoke09"}
		{view start "smoke10"}
		{view start "smoke11"}
		{view start "smoke12"}
	}
	{on "add_movement_sound" overload
		{link_sound "fly"				"vehicle/airborne/cg_4a/cg_4a_fly"		}
		{link_sound "engine_start"		"vehicle/airborne/cg_4a/cg_4a_start"	}
		{link_sound "engine_work"		"vehicle/airborne/cg_4a/cg_4a_engine"	}
		{link_sound "engine_stop"		"vehicle/airborne/cg_4a/cg_4a_stop"		}
	}
}

{"hamilcar"
	{on spawn
		{add_view	"smoke_plane"	"smoke01"		"fx_smoke01"}
		{add_view	"smoke_plane"	"smoke02"		"fx_smoke02"}
		{add_view	"smoke_plane"	"smoke03"		"fx_smoke03"}
		{add_view	"smoke_plane"	"smoke04"		"fx_smoke04"}
		{add_view	"smoke_plane"	"smoke05"		"fx_smoke05"}
		{add_view	"smoke_plane"	"smoke06"		"fx_smoke06"}
		{add_view	"smoke_plane"	"smoke07"		"fx_smoke07"}
		{add_view	"smoke_plane"	"smoke08"		"fx_smoke08"}
		{add_view	"smoke_plane"	"smoke09"		"fx_smoke09"}
		{add_view	"smoke_plane"	"smoke10"		"fx_smoke10"}
		{add_view	"smoke_plane"	"smoke11"		"fx_smoke11"}
		{add_view	"smoke_plane"	"smoke12"		"fx_smoke12"}
	}
	{on "tear_part"
		{view start "smoke01"}
		{view start "smoke02"}
		{view start "smoke03"}
		{view start "smoke04"}
		{view start "smoke05"}
		{view start "smoke06"}
		{view start "smoke07"}
		{view start "smoke08"}
		{view start "smoke09"}
		{view start "smoke10"}
		{view start "smoke11"}
		{view start "smoke12"}
	}
	{on "add_movement_sound" overload
		{link_sound "fly"				"vehicle/airborne/hamilcar/hamilcar_fly"	}
		{link_sound "engine_start"		"vehicle/airborne/hamilcar/hamilcar_start"	}
		{link_sound "engine_work"		"vehicle/airborne/hamilcar/hamilcar_engine"	}
		{link_sound "engine_stop"		"vehicle/airborne/hamilcar/hamilcar_stop"	}
	}
	{on "cut_wheels"
		{ani_play "drift"}
		("cut_part" args "wheell"		1.0)
		("cut_part" args "wheelr"		1.0)
		("cut_part" args "wheel_back"	1.0)
;		("cut_part" args "part2"		0.7)
		("cut_part" args "part3"		1.0)
		{add_view "spheredust_big" "ground_dust" "support1"}
		{add_view "spheredust_big" "ground_dust" "support2"}
		{view start "ground_dust"}
		{delay 4
			{view stop "ground_dust"}
		}
	}
}

{"il-2"
	{on "die"
		{bone hide "rocket00"}
		{bone hide "rocket01"}
		{bone hide "rocket02"}
		{bone hide "rocket03"}
		{bone hide "rocket04"}
		{bone hide "rocket05"}
		{bone hide "rocket06"}
		{bone hide "rocket07"}
		{bone hide "bomb00"}
		{bone hide "bomb01"}
	}
	{on "init_gun"
		{add_view "flash_zenit01"	"zenite1_00"	"shooter_m00"}
		{add_view "flash_zenit01"	"zenite1_01"	"shooter_m01"}
	}
	{on fire "zenite1" overload
		(define "flash_barrel"
		name "%0"
			{view start "zenite1_%0"}
			{delay 0.42
				{view pause "zenite1_%0"}
			}
		)
		{if	("flash_barrel" args 00)
		else	("flash_barrel" args 01)
		}
	}
}
{"il-2_collection"
	{on "die"
		{bone hide "rocket00"}
		{bone hide "rocket01"}
		{bone hide "rocket02"}
		{bone hide "rocket03"}
		{bone hide "rocket04"}
		{bone hide "rocket05"}
		{bone hide "rocket06"}
		{bone hide "rocket07"}
		{bone hide "bomb00"}
		{bone hide "bomb01"}
	}
	{on "init_gun"
		{add_view "flash_zenit01"	"zenite1_00"	"shooter_m00"}
		{add_view "flash_zenit01"	"zenite1_01"	"shooter_m01"}
	}
	{on fire "zenite1" overload
		(define "flash_barrel"
		name "%0"
			{view start "zenite1_%0"}
			{delay 0.42
				{view pause "zenite1_%0"}
			}
		)
		{if	("flash_barrel" args 00)
		else	("flash_barrel" args 01)
		}
	}
}

{"ju-87g"
	{on "init_gun"
		("view_x3_barrel_x2"
			view1(flash_cannon_small01)
			barrel(barrel_z)
			name(mgun)
		)
		("view_x3_barrel_x2"
			view1(flash_cannon_small01)
			barrel(barrel_m)
			name(mgun1)
		)
	}
	{on fire "mgun" overload
		("fire_mgun" name(mgun))
	}
	{on fire "mgun1" overload
		("fire_mgun" name(mgun1))
	}
}
{"ju-87"
	{on "die"
		{bone hide "bomb00"}
		{bone hide "bomb01"}
		{bone hide "bomb02"}
		{bone hide "bomb03"}
		{bone hide "bomb_main"}
	}
	{on "init_gun"
		("view_x3_barrel_x2"
			view1(flash_zenit01)
			barrel(barrel_m)
			name(flashbarrel)
		)
		("view_x3_barrel_x2"
			view1(flash_cannon_small01)
			barrel(barrel_z)
			name(mgun)
		)
	}
	{on fire "mgun" overload
		("fire_mgun" name(mgun))
	}
}

{"kill_pass"
	{on "kill_pass"
			(define "seat_places"
				{place "seat1" %0}
				{place "seat2" %0}
				{place "seat3" %0}
				{place "seat4" %0}
				{place "seat5" %0}
				{place "seat6" %0}
				{place "seat7" %0}
				{place "seat8" %0}
				{place "seat9" %0}
				{place "seat10" %0}
				{place "seat11" %0}
				{place "seat12" %0}
				{place "seat13" %0}
			)
			(define "kill_pass"
				{kill_crew_by_weapon
					{weapon ""}
					{max_kill 1}
					{min_crew_count 1}
					("seat_places" args %0)
				}
			)
			{if armor_health_percent 0.5
				("kill_pass" args 1)
			else
				("kill_pass" args 0.5)
			}
	}
	{on "step_killing_of_passengers"
			(define "step_killing"
				{if armor_health_percent %hp and %not1 flag "kill_crew_state1" and %not2 flag "kill_crew_state2" and %not3 flag "kill_crew_state3"
					{call "kill_pass"}
					{set "kill_crew_state1"	%set1}
					{set "kill_crew_state2"	%set2}
					{set "kill_crew_state3"	%set3}
				}
			)
			("step_killing" hp(0.5)	not1(not)	not2(not)	not3(not)		set1(0) set2(0) set3(1))
			("step_killing" hp(0.25)	not1(not)	not2(not)	not3() 			set1(0) set2(1) set3(0))
			("step_killing" hp(0.003)	not1(not)	not2()		not3(not) 		set1(0) set2(1) set3(1))
			("step_killing" hp(0.002)	not1(not)	not2()		not3() 			set1(1) set2(0) set3(0))
			("step_killing" hp(0.001)	not1()		not2(not)	not3(not) 		set1(1) set2(0) set3(1))
	}
	{on "got_any_damage" overload
		{if armor_health 1
			{if chassis "airborne"
				{call "fall"}
			else
				{call "pierce"}
				{crew_emit}
				{call "mp_destroy"}
			}
		else
			;{call "step_killing_of_passengers"}
			{call "fire"}
		}
	}
}
(define "recon_plane_sound"
	{on "add_movement_sound" overload
		{link_sound "fly"				"vehicle/airborne/ju_52/ju_52_fly"}
		{link_sound "engine_start"		"vehicle/airborne/p_51/p_51_start"}
		{link_sound "engine_work"		"vehicle/airborne/p_51/p_51_engine"}
		{link_sound "engine_stop"		"vehicle/airborne/ju_52/ju_52_stop"}
	}
)
{"fi156"
	("recon_plane_sound")
}
{"po-2"
	("recon_plane_sound")
}
{"po-2_scout"
	("recon_plane_sound")
}
{"po2_snow"
	("recon_plane_sound")
}
{"po2_snow_test"
	("recon_plane_sound")
}
{"l-4"
	("recon_plane_sound")
}

(define "ju-52_sound"
	{on "add_movement_sound" overload
		{link_sound "fly"				"vehicle/airborne/ju_52/ju_52_fly"}
		{link_sound "engine_start"		"vehicle/airborne/ju_52/ju_52_start"}
		{link_sound "engine_work"		"vehicle/airborne/ju_52/ju_52_engine"}
		{link_sound "engine_stop"		"vehicle/airborne/ju_52/ju_52_stop"}
	}
)

{"ju-52"
	("ju-52_sound")
	{on "wheels_fx"
		{add_view "spheredust_big" "ground_dust" "support1"}
		{add_view "spheredust_big" "ground_dust" "support2"}
		{view start "ground_dust"}
		{delay 4
			{view stop "ground_dust"}
		}
	}
	{on "fire" overload
		{if not flag "fall"
			{if armor_health 250
				{view start "prepare_to_fall"}
			}
		}
	}
}
{"dc-47"
	("ju-52_sound")
}
{"dc-47_rus"
	("ju-52_sound")
}
{"do-24t"
	("ju-52_sound")
}

{"bf109g"
	{on "init_gun"
		{add_view "flash_zenit01"	"zenite1_1"	"foresight3"}
		("view_x3_barrel_x2"
			view1(flash_cannon_small01)
			barrel(barrel_m)
			name(mgun1)
		)
	}
	{on fire "zenite1" overload
		(define "flash_barrel"
			{view start "zenite1_%0"}
			{delay 0.42
				{view pause "zenite1_%0"}
			}
		)
		("flash_barrel" args 1)
	}
	{on fire "rocket" overload
		(define "fire_barrel"
			name "%0"
				{spawn "startsmoke" "barrel_r%0" x}
		)
		
		{if ("fire_barrel" args 00)
		else ("fire_barrel" args 01)
		}
	}
	{on fire "mgun1" overload
		("fire_mgun" name(mgun1))
	}
}

{"bomber"
	{on "init_gun" overload
		{add_view "flash_gun_big" "shooter1_00" "shooter1_00"}
		{add_view "flash_gun_big" "shooter1_01" "shooter1_01"}
		{add_view "flash_gun_big" "shooter2_00" "shooter2_00"}
		{add_view "flash_gun_big" "shooter2_01" "shooter2_01"}
		{add_view "flash_gun_big" "shooter3_00" "shooter3_00"}
		{add_view "flash_gun_big" "shooter3_01" "shooter3_01"}
		{add_view "flash_gun_big" "shooter4_00" "shooter4_00"}
		{add_view "flash_gun_big" "shooter4_01" "shooter4_01"}
	}
	(define "link_flash"
		{if name "mgun_linked%0"
			{if stuff "mgun"
				{add_view "flash_gun_big" "flashbarrel%1" "Foresight%1"}
			}
		}
	)
	{on "link_weapon" overload
		("link_flash" args 1 5)
		("link_flash" args 2 6)
		("link_flash" args 3 7)
		("link_flash" args 4 8)
	}
	{on fire "mgun_linked1" {view start "flashbarrel5"}}
	{on fire "mgun_linked2" {view start "flashbarrel6"}}
	{on fire "mgun_linked3" {view start "flashbarrel7"}}
	{on fire "mgun_linked4" {view start "flashbarrel8"}}

	(define "start_shooter_flash"
		{on fire "mgun_own%0"
			{if name "00"
				{view start "shooter%0_00"}
			}
			{if name "01"
				{view start "shooter%0_01"}
			}
		}
	)
	("start_shooter_flash" args 1)
	("start_shooter_flash" args 2)
	("start_shooter_flash" args 3)
	("start_shooter_flash" args 4)

	{on "_explosion" overload}

	{on "break_part"
		{if work
			{component break}
			{burn fx "smoke_aero_small" fake}
		else broken
			{component destroy}
			{spawn "aero_die_particle"}
			{if volume "engine"
				{tear "piece_medium_steel" bone from_volume
					{impulse up 1 0.5 dir 5 2 rnd_dir 3 no_position}
					{add_view "smoke_dead_wheel" "smoke" "basis"}
					{view start "smoke"}
					{delay_effect 20 5 "stop"}
				}
			}
		else destroyed
			{spawn "aero_die_particle"}
		}
	}

	{on "pierce" overload
		{if volume "engine"
			{call "break_part"}
		else volume "wing"
			{call "break_part"}
		else volume "body"
			{call "break_part"}
		else
			{inherited}
		}
	}
	{on "die"
		{weapon_work "mgun_linked1" 0}
		{weapon_work "mgun_linked2" 0}
		{weapon_work "mgun_linked3" 0}
		{weapon_work "mgun_linked4" 0}
		{weapon_work "mgun_own1" 0}
		{weapon_work "mgun_own2" 0}
		{weapon_work "mgun_own3" 0}
		{weapon_work "mgun_own4" 0}
	}
}
{"a20"
	{on "init_gun"
		{add_view "flash_zenit01"	"flashbarrel051"	"barrel05"}
		{add_view "flash_zenit01"	"flashbarrel1001"	"barrel100"}
		{add_view "flash_zenit01"	"flashbarrel1011"	"barrel101"}
	}
	{on fire "zenite" overload
		(define "flash_barrel"
			{view start "flashbarrel%0%1"}
			{delay 0.42
				{view pause "flashbarrel%0%1"}
			}
		)
		(define "fire_barrel"
			name "%0"
				("flash_barrel" args %0 1)
		)
		
		{if ("fire_barrel" args 00)
		else ("fire_barrel" args 01)
		else ("fire_barrel" args 02)
		else ("fire_barrel" args 03)
		else ("fire_barrel" args 04)
		else ("fire_barrel" args 05)
		}
	}
	{on fire "zenite1" overload
		(define "flash_barrel"
			{view start "flashbarrel1%0%1"}
			{delay 0.42
				{view pause "flashbarrel1%0%1"}
			}
		)
		(define "fire_barrel"
			name "%0"
				("flash_barrel" args %0 1)
		)
		
		{if		("fire_barrel" args 00)
		else	("fire_barrel" args 01)
		}
	}
}