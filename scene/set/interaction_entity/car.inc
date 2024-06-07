{"car"
	{on spawn
		{link_sound "flame" "fire/big"}

		{if not rain
			{add_view	"dustrun_small"			"on_grass"			"FXtraceR1"}
			{add_view	"dustrun_small"			"on_grass"			"FXtraceL1"}
			{add_view	"dustrun_sand_small"	"on_sand"			"FXtraceR1"}
			{add_view	"dustrun_sand_small"	"on_sand"			"FXtraceL1"}
			{add_view	"dustrun_snow_small"	"on_snow"			"FXtraceR1"}
			{add_view	"dustrun_snow_small"	"on_snow"			"FXtraceL1"}
			{add_view	"dustrun_small"			"on_country_road"	"FXtraceR1"}
			{add_view	"dustrun_small"			"on_country_road"	"FXtraceL1"}
			{add_view	"dustrun_small"			"on_ground"			"FXtraceR1"}
			{add_view	"dustrun_small"			"on_ground"			"FXtraceL1"}
		else
			{add_view	"engine_steam"			"engine_steam"		"FXfire1"}
		}
		{add_view	"wash_moto_dipper"			"on_water"			"FXtraceR1"}
		{add_view	"wash_moto_dipper"			"on_water"			"FXtraceL1"}
;		{add_view	"wash_moto_dipper"			"on_mud"			"FXtraceR1"}
;		{add_view	"wash_moto_dipper"			"on_mud"			"FXtraceL1"}
		{add_view	"wash_moto"		"on_puddle"			"FXtraceR1"}
		{add_view	"wash_moto"		"on_puddle"			"FXtraceL1"}

		{add_view	"smoke_black"			"smoke1"			"FXfire1"}
		{add_view	"smoke_black"			"smoke2"			"engine"}
		{add_view	"steam"					"steam"				"FXsteam"}
		{add_view	"exhaust_dark_small"	"exhaust"			"FXsmoke1"}
	}

	{on "add_movement_sound"
		{link_sound "move"				"vehicle/groundborne/#parts/wheels/00" user_control}
		{link_sound "move_end"			"vehicle/groundborne/gmc/gmc_wheels_stop"}		
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/02" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/02" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/02"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/02"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/car_door_open"}	
		{link_sound "close"			"vehicle/groundborne/motions/car_door_close"}		
	}
	{on "bullet_reflect"
		{if not armor_health 1 and not flag "broken"
			{if not stuff "bullet" and not stuff "fg" and not stuff "fr"
				{talk "tank_bullet_reflect"}
				{call "talk_target_bullet_reflected"}
			}
		}
	}
	{on "talk_target_destroyed"
		{call "destroyed_by_spy"}
		{talk "tank_leave"}
		{call "talk_target_destroyed_car"}
	}
	{on pierce
		{call "check_ur_pierce"}
		{if armor_health 1 and not flag "broken"
			{call "mp_destroy"}
		else
			{if component "body" or component "turret"
				{talk "tank_pierce"}
				{call "talk_target_pierced"}
			}
			{if component "engine" and armor_health 50
				{if stuff "shell"
					{if rand 0.6
						{components "engine" break}
						{call "burn"}
					}
				else rand 0.15
					{components "engine" break}
				}
			}
		}
	}
	{on "mp_destroy" ;hack for "burn_damage"
			{if not tagged "destroyed"
				{tags add "destroyed"}
				{components break}
				{drop_orders}
				{reset_manual_control}
				{able select 0}
				{able repaired 0}
				{unlink_trailer}
				{call "weapons_off"}
			}
			{if tagged "burned"
				{call "explosion"}
			}
	}
	{on break_armor
		{if armor_health 1 and not flag "broken"
			{if name "pierce"
				{if volume "fuel"
					{call "pierce_fuel"}
				}
			else name "blast"
				{call "blast_body"}
			}
		else {call "check_talk_target_broke_component"}
		}
	}
	{on break_armor_again
		{if armor_health 1 and not flag "broken"
			{if name "blast"
				{call "blast_body"}
			}
		}
	}
	{on bullet_hit
		{if relation "enemy" and stuff "rocketlauncher"
			{if volume "cabin"
				{if rand 0.5	 	
					{call "blast_body"}
				else			
					{components "body" break}
				}
			 else volume "body"	
			 	{if rand 0.5	 	
					{call "blast_body"}
				else			
					{components "body" break}
				}
			 else volume "engine"
			 	{if rand 0.5
					{call "burn"}
				else
					{call "blast_body"}
				}
			}
		}
		{if volume "glass"
		 	{call "break_glass"}
		 else volume "cabin"
		 	{call "break_glass"}
		}
	}
	{on "blast_body"
		{if min_energy 40
			{impulse up 0.5 dir 1.5 0.5}
		 else min_energy 25
			{impulse up 0.1 dir 0.8 0.3}
		}
		{call "explosion"}
	}
	{on "pierce_fuel"
		{if rand 0.5
			{volumes "fuel" disable bullet contact blast}
			{spawn "tank_die_particle"}
			{call "burn"}
		}
	}
	{on "break_glass"
		{volumes "glass" disable bullet contact}
	 	{spawn "glass_hit2" "glass" x}
	 	{delay 0.1
;	 		{con "cut glass"}
		 	{bone cut "glass"}
	 	}
	}
	{on contact
		{if not impregnable
			{if effector_velocity 5
				{if effector "tank" and relation "enemy"
					{call "crush"}
				else effector "railway"
					{call "crush"}
				}
;			else effector_velocity 3
;				{if effector "big part"
;					{call "component_break"}
;				}
			}
		}
	}
	{on break
		{if component "cabin"
			{spawn "car_die_particle"}
			{volumes "cabin" disable bullet}
			{volumes "glass" disable bullet contact}
			{crew_enable group "crew" 0}
			{view start "smoke3"}
    		{delay 10 {view stop "smoke3"}}
    	else component "body"
		{if armor_health 1
			{call "mp_destroy"}
		}
			{spawn "car_die_particle"}
		else component "engine"
                        {spawn "car_die_particle"}
			{view start "smoke2"}
			{delay 40 {view stop "smoke2"}}
			{view start "steam"}
			{delay 2  {view stop "steam"}}
		}
	}
	{on repair
		{if component "cabin"
			{crew_enable group "crew" 1}
			{view stop "smoke2"}
		}
	}

	{on "burn"
		{if not burned
			{call "_burn"}
		}
	}
	{on "check_burn_emit"
		{call "burn_emit"}
	}
	{on "_explosion"
		{add_view "smoke_dead_norm" "deathfx" "fxfire1"}
		{if not flag "crush"
			{spawn "tank_die" "Basis"}
			{spawn "tank_die_particle"}
			{impulse up 0.5 dir 2 1}
		}
	}
	{on "spawn_shellhole"
;		{spawn "crater_big" "Basis" no_normal terrain_texmod}
		{spawn "shellhole_dead_car" "Basis"}
	}
	{on "tear"
		{if game_param 	"biom" "snow"
			{spawn	"spheredust_small_w"}
		else
			{spawn	"spheredust_small"}
		}
		{component destroy}
		{if volume "bodyback"
			{volume disable visible bullet contact}
		}
		{tear "piece_medium_steel" bone from_volume
			{impulse up 2 1 dir 2 1}
;			{burn first_volume fx "smoke_black" time 10 5}
			{add_view "smoke_black" "smoke" "basis"}
			{view start "smoke"}
			{delay_effect 10 5 "pause"}
		}
	}
	{on "slice_load"
		{if name "car_part"
			{with_effector
				{add_view "smoke_black" "smoke" "basis"}
			}
		}
	}
	{on "cut_parts"
		{add_view "smoke_dead_norm" "deathfx" "fxfire1"}
		{view start "deathfx"}
		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 4 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 6 no_position}
;				{burn first_volume fx "smoke_dead_wheel" time 20 5}
;				{add_view "smoke_dead_wheel" "smoke" "basis"}
;				{view start "smoke"}
				{delay_effect 20 5 "stop"}
			}
		)
		("cut_part" args "part1")
		("cut_part" args "part2")
		("cut_part" args "part3")
		("cut_part" args "part4")
		("cut_part" args "part5")
		("cut_part" args "part6")
		;cut teared bones after SetSkeleton
		{if flag "cabine_teared"
			{bone cut "cabin"}
		}
		{if flag "engine_teared"
			{bone cut "engine"}
		}
		{delay 14 5 {view stop "deathfx"}}
	}
	{on "crush"
    	{component destroy}
		{set "crush" 1}
		{call "explosion"}
	}
}

{"wheeled vehicle"
	{on blast
		{if volume "wheel" and can_be_damaged
			{if stuff "mine"
				{if min_energy 2.5
					{call "tear_wheel"}
				}
;			else min_energy 4
;				{call "tear_wheel"}
			else min_energy 2
				{component break}
			}
		}
	}
	{on break_armor
		{if volume "wheel"
			{if name "pierce"
				{component break}
			}
		}
	}
	{on "dont_move"
		{set "wheel_teared" 1}
		{call "check_work_mover"}
		{crew_enable place "driver" 0}
	}
	{on "tear_wheel"
		{set "wheel_teared" 1}
		{if game_param 	"biom" "snow"
			{spawn	"spheredust_small_w"}
		else
			{spawn	"spheredust_small"}
		}
		{component destroy}
;		{con "effect tear wheel"}
		{tear "piece_medium_steel" bone from_volume id "wheel"
			{volumes disable bullet contact blast}	;prevent destroing at spawn moment
			{impulse up 6 4 dir 7 3}
;			{burn first_volume fx "smoke_dead_wheel" time 10 5}
			{add_view "smoke_dead_wheel" "smoke" "basis"}
			{fire radius 0.5 time 12 follow}
			{view start "smoke"}
			{delay_effect 10 5 "pause"}
		}
		{impulse up 0.3}
	}
	{on break
		{if component "wheel"
			{if not linked
		 		{if not velocity 0.5
		 			{impulse up 0.05}
		 		}
			}
		}
	}
	{on "check_work_mover" overload
		{if flag "wheel_teared"
			{chassis_work 0}
		else
			{if not work "mover"
				{chassis_work 0}
			else not work "track"
				{chassis_work 0}
			else work "wheel" 1
				{chassis_work 1}
				{if broken "wheel" 2
					{movement_limit slow}
				else broken "wheel" 1
					{movement_limit normal}
				else
					{movement_limit fast}
				}
			else
				;{chassis_work 0}
				{movement_limit slow}
			}
		}
	}
	{on "_explosion"
		(define "rand_tear_wheel"
			{if rand 0.5
;				{con "rnd tear wheel"}
				{components %0 destroy}
				{tear "piece_medium_steel" bone %0 id "wheel"
					{volumes disable bullet contact blast}	;prevent destroing at spawn moment
					{impulse up 0.1 dir 7 4}
;					{burn first_volume fx "smoke_dead_wheel" time 10 5}
					{add_view "smoke_dead_wheel" "smoke" "basis"}
					{view start "smoke"}
					{delay_effect 10 5 "pause"}
				}
			}
		)
;		("rand_tear_wheel" args "wheelleft1")
;		("rand_tear_wheel" args "wheelleft2")
;		("rand_tear_wheel" args "wheelright1")
;		("rand_tear_wheel" args "wheelright2")
	}
}

{"truck"
;	{on blast overload	
;		{if volume "body"
;			{if min_energy 4
;				{call "blast_body"}
;				{con "truck 3"}
;			else min_energy 1.1
;				{if rand 0.25
;					{call "blast_body"}
;				{con "truck 1.1"}
;				}
;			else stuff "grenade"
;				{if rand 0.25
;					{call "blast_body"}
;					{con "truck 0.5"}
;				}
;			}
;		}
;	}
}

{"katusha car"
	{on fire "gun"
		{spawn "startsmoke_big"}
		{spawn "startdust_big" "FXdust"}
	}
	{on "__explosion"
		{set "big_explosion" 0}
		{if explosive_amount 50
			{fragments c4 20 r0 10 r1 25}
			{spawn "train_die" "basis"}
			{set "big_explosion" 1}
;			{con "big explosive"}
		}
	}
	{on "spawn_shellhole"
		{if flag "big_explosion"
;			{spawn "crater_extra_big" "basis" terrain_texmod}
			{spawn "shellhole_size5" "basis"}
		}
	}
	{on blast
		{if volume "body"
			{if min_energy 3
				{call "blast_body"}
			else min_energy 1
				{if rand 0.6
					{call "blast_body"}
				}			
			else stuff "grenade"
				{if rand 0.4
					{call "blast_body"}
				}
			}	
		}
	}
}

{"fuel_tank"
	{on blast_hit
		{if min_energy 2
			{call "explosion"}
		else min_energy 0.5
			{if rand 0.5
				{call "explosion"}
			}
		}
	}
	{on break_armor
		{call "pierce_bodyback"}
	}
	{on break_armor_again
		{call "pierce_bodyback"}
	}
	{on "pierce_bodyback"
		{if name "pierce"
			{if not able "exploded"
				{if volume "bodyback"
					{if stuff "bullet"
						{burn fx "drops_water_small_short" fake}
					}
				}
			}
		}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{fragments c4 5 r0 4 r1 15}
		{fire radius 8 time 15 heating 10}
	}
}

{"dead_vehicle"
	{on blast
		{if volume "body"
			{if min_energy 0.7
				{call "explosion"}
			}
		}
	}
	{on "explosion"
		{if not flag "exploded"
			{set "exploded" 1}
			{call "_explosion"}
		}
	}
	{on "_explosion"
		{start_sound "detonation/hit_huge/hit_huge"}
		{delay_ex 0
			{set_skeleton "_x" sync}
			{ani_play "death"}
			{call "cut_parts"}
		}
	}
	{on "cut_parts"
		{add_view "smoke_dead_wheel" "smoke" "basis"}
		{view start "smoke"}
		{delay 20 10
			{view stop "smoke"}
		}
		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 4 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 6 no_position}
;				{add_view "smoke_dead_wheel" "smoke" "basis"}
;				{view start "smoke"}
				{delay_effect 20 5 "stop"}
			}
		)
		("cut_part" args "part1")
		("cut_part" args "part2")
		("cut_part" args "part3")
		("cut_part" args "part4")
		("cut_part" args "part5")
		("cut_part" args "part6")
	}
}

{"buldozer"
	{on move on
		{ani_play "liftup" +1}
	}
	{on move off
		{ani_play "liftup" -1 resume}
	}
}



(define "zis_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/zis/zis_wheels" user_control}
		{link_sound "engine"			"vehicle/groundborne/zis/zis_engine" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/zis/zis_engine_stop" user_control}
		{link_sound "exhaust"			"vehicle/groundborne/zis/zis_exhaust"	 user_control}
		{link_sound "engine_start"		"vehicle/groundborne/zis/zis_engine_start"	 user_control}
		{link_sound "doorleft"			"vehicle/groundborne/motions/car_door_open"}	
		{link_sound "doorright"			"vehicle/groundborne/motions/car_door_open"}	
	}
	{on "delay_play_engine" overload
		{delay_effect 1.1 "play_engine"}
	}	
)
{"zis5eng car"
	("zis_sound")
}
{"zis5 car"
	("zis_sound")
}
{"gaz_aa car"
	("zis_sound")
}
{"gaz_aa_med"
	("zis_sound")
}
{"gaz_aa_supp"
	("zis_sound")
}
{"gaz_aa_untented car"
	("zis_sound")
}
{"gaz_aa_untented_fuel car"
	("zis_sound")
	{on "inventory_transfer"
		{if name "DropToGround" and stuff "barrel"
			{ani_play "open" 1.0 resume}
			{delay 0.2
				{spawn "barrelmetal3a_g2_fuel" "barrel_dropper" x scale 0.75
				{impulse up 0.5 forward 2.5 1 rnd_dir 0.5 com}
				}
			}
			{delay 1.0 {ani_play "open" -0.5 resume}}
		}
	}
}
{"gaz_aa_fuel car"
	("zis_sound")
}

{"zis42 car"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/zis42/zis42_wheels" user_control}
		{link_sound "engine"			"vehicle/groundborne/zis/zis_engine" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/zis/zis_engine_stop" user_control}
		{link_sound "exhaust"			"vehicle/groundborne/zis/zis_exhaust"	 user_control}
		{link_sound "engine_start"		"vehicle/groundborne/zis/zis_engine_start"	 user_control}
		{link_sound "doorleft"			"vehicle/groundborne/motions/car_door_open"}	
		{link_sound "doorright"			"vehicle/groundborne/motions/car_door_open"}		
	}
	{on "delay_play_engine" overload
		{delay_effect 1.1 "play_engine"}
	}	
}
(define "dodgewc51"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/wheels/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/02" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/02" user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/02"	 user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/02"	 user_control}
		("%rotate_turret")
	}
)
{"dodge car"
	("dodgewc51" rotate_turret(none))
}
{"dodgewc51_m2hb car"
	("dodgewc51" rotate_turret(none))
}
{"dodgewc51_m6 car"
	(define "rotate_turret_sound"
		{link_sound "rotate_turret" 	"vehicle/turret/light"}
	)
	("dodgewc51" rotate_turret(rotate_turret_sound))
	{on spawn
		{add_view	"flash_cannon_small"	"flashbarrel1"	"foresight1"}
	}
	{on fire "gun"
		{ani_play "recoil" 1}
		{spawn "dust_shot_small" "basis"}
		{spawn "tank_canon_fire_small" "foresight1" x}
	}
}
(define "kubel_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/kubel/kubel_wheels" user_control}
		{link_sound "engine"			"vehicle/groundborne/kubel/kubel_engine" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/kubel/kubel_engine_stop" user_control}
		{link_sound "exhaust"			"vehicle/groundborne/kubel/kubel_exhaust" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/kubel/kubel_engine_start" user_control}
		{link_sound "open"				"vehicle/groundborne/motions/car_door_open" user_control}
		{link_sound "close"				"vehicle/groundborne/motions/car_door_close" user_control}
	}
	{on "delay_play_engine" overload
		{delay_effect 1.2 "play_engine"}	
	}
)
{"kubel car"
	("kubel_sound")
}
{"kubel_mgun car"
	("kubel_sound")
}
(define "willys_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/wheels/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/02" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/02" user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/02"	 user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/02"	 user_control}
	}
)
{"willysmb car"
	("willys_sound")
}
{"willysmb_tent car"
	("willys_sound")
}
{"willysmb_eng car"
	("willys_sound")
}
{"willysmb_maxim car"
	("willys_sound")
}
{"willysat car"
	("willys_sound")
}
{"willysat_mgun car"
	("willys_sound")
}

(define "horch_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/wheels/00" user_control}		
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/03" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/03" user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/03"	 user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/03"	 user_control}
	}
)
{"horch car"
	("horch_sound")
}
(define "gmc_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/wheels/00" user_control}
		{link_sound "move_end"			"vehicle/groundborne/gmc/gmc_wheels_stop"	}		
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/02" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/02" user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/02"	 user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/02"	 user_control}
	}
)
{"gmc_cckw car"
	("gmc_sound")
}
{"gmc_fuel car"
	("gmc_sound")
}
{"gmc car"
	("gmc_sound")
}
{"gmc_eng car"
	("gmc_sound")
}
{"gmc_art car"
	("gmc_sound")
}
{"gmc_supp car"
	("gmc_sound")
}
{"gmc_inf car"
	("gmc_sound")
}
{"gmc_inf_fuel car"
	("gmc_sound")
	{on "inventory_transfer"
		{if name "DropToGround" and stuff "barrel"
			{ani_play "open" 1.0 resume}
			{delay 0.1
				{spawn "barrelmetal3a_g2_fuel" "barrel_dropper" x scale 0.75
				{impulse up 0.25 forward 2.5 1.0 rnd_dir 0.5 com}
				}
			}
			{delay 2.0 {ani_play "open" -0.5 resume}}
		}
	}
}
(define "opel_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/opel/opel_wheels" 			user_control}
		{link_sound "engine"			"vehicle/groundborne/opel/opel_engine" 			user_control}
		{link_sound "engine_end"		"vehicle/groundborne/opel/opel_engine_stop" 	user_control}
		{link_sound "exhaust"			"vehicle/groundborne/opel/opel_exhaust" 		user_control}
		{link_sound "engine_start"		"vehicle/groundborne/opel/opel_engine_start" 	user_control}
		{link_sound "open"				"vehicle/groundborne/motions/car_door_open" 	user_control}
		{link_sound "close"				"vehicle/groundborne/motions/car_door_close" 	user_control}
	}
	{on "delay_play_engine" overload
		{delay_effect 1.1 "play_engine"}	
	}
)
{"blitz3_6 car"
	("opel_sound")
}
{"blitz3_6eng car"
	("opel_sound")
}
{"blitz3_6f car"
	("opel_sound")
}
{"blitz3_6m car"
	("opel_sound")
}
{"isuzutx40 car"
	("opel_sound")
}
{"opel_blitz car"
	("opel_sound")
}
{"opel_blitz_highback car"
	("opel_sound")
}
{"opel_blitz_highback_fuel car"
	("opel_sound")
	{on "inventory_transfer"
		{if name "DropToGround" and stuff "barrel"
			{ani_play "open" 1.0 resume}
			{delay 0.1
				{spawn "barrelmetal3a_g2_fuel" "barrel_dropper" x scale 0.9
				{impulse up 0.25 forward 2.5 1.0 rnd_dir 0.5 com}
				}
			}
			{delay 2.0 {ani_play "open" -0.5 resume}}
		}
	}
}
{"opel_blitz_fuel car"
	("opel_sound")
}
{"opel_blitz_med car"
	("opel_sound")
}
{"opel_blitz_mgun car"
	("opel_sound")
}


{"car_with_dust"
	{on spawn
		{add_view	"dustrun_small"			"on_ground"			"FXtraceR1"}
		{add_view	"dustrun_small"			"on_ground"			"FXtraceL1"}
	}
	{on "start_fx_ground"
		{view start "on_ground"}
	}
	{on "stop_fx_ground"
		{view pause "on_ground"}
	}
}

{"soldier_us_afr_palmer_dodge"
	{on "lights_on"
		{add_view 	"car_headlight"		"light"		"headlightL"}
		{add_view 	"car_headlight"		"light"		"headlightR"}
		{add_view 	"light_vehicle"	"light"		"fxlight"}
		{view start "light"}
		{view show "light"}
	}
}
{"truck_mortar"
	{on fire "gun"
		{spawn "mortar_fire01" inv_normal}
		{ani_play "recoil"}			
	}
	{on "talk_target_destroyed" overload
		{call "destroyed_by_spy"}
		{talk "tank_leave"}
		{call "talk_target_destroyed_mortar"}
	}
}
{"29k car"
	{on spawn
		{add_view	"flash_cannon_small"	"flashbarrel1"	"foresight1"}
	}
	{on fire "gun"
		{ani_play "recoil" 1}
       	{spawn "dust_shot_small" "basis"}
        {spawn "tank_canon_fire_small" "foresight1" x}
	}
	{on "add_movement_sound"
		{link_sound "rotate_turret" 	"vehicle/turret/medium"}
	}
}
{"toss_aside_the_sides"
	{on "set_deployed"
		{if not flag "deployed"
			{if crew_in_place "gunner" or crew_in_place "charger"
				{ani_play "board" +1 resume}
				{set "deployed" 1}
			}
		}
	}
	{on "remove_deployed"
	    {delay 1.0
		    {if not crew_in_place "gunner" and not crew_in_place "charger"
		    	{ani_play "board" -1 resume}
		    	{set "deployed" 0}
		    }
		}
	}
	{on crew in
		{call "set_deployed"}
	}
	{on crew out
		{call "remove_deployed"}
	}
}
{"deploy_support"
	{on move off
		{if flag "deployed"
			{ani_play "deploy_support" +1 resume}
		}
	}
	{on move on
		{if flag "deployed"
			{ani_play "deploy_support" -1 resume}
		}
	}
	{on "set_deployed"
		{ani_play "deploy_support" +1 resume}
		{set "deployed" 1}
	}
	{on "remove_deployed"
		{ani_play "deploy_support" -1 resume}
		{set "deployed" 0}
	}
	{on crew in
		{call "set_deployed"}
	}
	{on crew out
		{call "remove_deployed"}
	}
}
{"toss_aside_the_sides deploy_support"
	{on "set_deployed" overload
		{if not flag "deployed"
			{if crew_in_place "gunner" or crew_in_place "charger"
				{ani_play "deploy_support" +1 resume}
				{ani_play "board" +1 resume}
				{set "deployed" 1}
			}
		}
	}
	{on "remove_deployed" overload
		{if not crew_in_place "gunner" and not crew_in_place "charger"
			{ani_play "deploy_support" -1 resume}
			{ani_play "board" -1 resume}
			{set "deployed" 0}
		}
	}
	{on crew in overload
		{call "set_deployed"}
	}
	{on crew out overload
		{call "remove_deployed"}
	}
}