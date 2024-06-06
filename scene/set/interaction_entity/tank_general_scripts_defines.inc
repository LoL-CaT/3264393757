	{on spawn
		{link_sound "flame"			"fire/big"}
		{link_sound "move"			"vehicle/tracks/trackclank"}
		{link_sound "heavy_move"	"vehicle/tracks/heavy"}
		{link_sound "crush"	"crush/big/vehicle"}
		{link_sound "ammo_fire"	"detonation/ammo_fire"}

		{if not rain
			{add_view	"dustrun_big"			"on_ground"				"FXtraceR1"}
			{add_view	"dustrun_big"			"on_ground"				"FXtraceL1"}
			{add_view	"dustrun_small"			"on_grass"				"FXtraceR1"}
			{add_view	"dustrun_small"			"on_grass"				"FXtraceL1"}
			{add_view	"dustrun_sand_big" 		"on_sand"				"FXtraceR1"}
			{add_view	"dustrun_sand_big" 		"on_sand"				"FXtraceL1"}
			{add_view	"dustrun_snow_big" 		"on_snow"				"FXtraceR1"}
			{add_view	"dustrun_snow_big" 		"on_snow"				"FXtraceL1"}
			{add_view	"dustrun_small"			"on_country_road"		"FXtraceR1"}
			{add_view	"dustrun_small"			"on_country_road"		"FXtraceL1"}
			
			{add_view	"exhaust_dark_temp_big"			"tube_steam1"			"FXsmoke1"}
			{add_view	"exhaust_dark_temp_big"			"tube_steam2"			"FXsmoke2"}			
		else
			{add_view	"engine_steam_old"			"tube_steam1"			"FXsmoke1"}
			{add_view	"engine_steam_old"			"tube_steam2"			"FXsmoke2"}
                }

		{if game_param 	"biom" "snow"
			{add_view	"engine_steam"			"engine_steam"			"FXfire1"}
		}

		{add_view	"tank_grit_small"		"on_ground"				"FXtraceR2"}
		{add_view	"tank_grit_small"		"on_ground"				"FXtraceL2"}
		{add_view	"tank_grit_big"			"on_ground_time_short"	"FXtraceR2"}
		{add_view	"tank_grit_big"			"on_ground_time_short"	"FXtraceL2"}

		{add_view	"tank_grit_small"		"on_grass"				"FXtraceR2"}
		{add_view	"tank_grit_small"		"on_grass"				"FXtraceL2"}
		{add_view	"tank_grit_big"			"on_grass_time_short"	"FXtraceR2"}
		{add_view	"tank_grit_big"			"on_grass_time_short"	"FXtraceL2"}

		{add_view	"wash_moto_dipper"			"on_water"				"FXtraceR1"}
		{add_view	"wash_moto_dipper"			"on_water"				"FXtraceL1"}
		{add_view	"tank_grit_big_mud"		"on_mud"				"FXtraceR2"}
		{add_view	"tank_grit_big_mud"		"on_mud"				"FXtraceL2"}
		{add_view	"tank_grit_big_snow"	"on_snow"				"FXtraceR2"}
		{add_view	"tank_grit_big_snow"	"on_snow"				"FXtraceL2"}
		{add_view	"wash_moto"		"on_puddle"				"FXtraceR1"}
		{add_view	"wash_moto"		"on_puddle"				"FXtraceL1"}
		{add_view	"tank_grit_small_w"		"on_puddle"				"FXtraceR2"}
		{add_view	"tank_grit_small_w"		"on_puddle"				"FXtraceL2"}

;		{add_view	"flash_cannon_big"		"flashbarrel1"			"Foresight1"}
;		{add_view	"powdersmoke_big"		"flashbarrel1s"			"Foresight1"}
		{add_view 	"flash_zenit01"			"flashbarrel2s"			"foresight2"}	;flash_zenit->flash_zenit01
;		{add_view	"powdersmoke_small2" 	"flashbarrel1s" 		"Foresight1"}
;		{add_view	"flash_gun_big"			"flashbarrel2"			"Foresight3"}

		{add_view	"smoke_white_steam"		"smoke1"				"FXfire1"}
		{add_view	"smoke_black"			"smoke2"				"FXfire2"}
		{add_view	"smoke_black"			"smoke3"				"FXfire2"}
		{add_view	"smoke_black"			"smoke4"				"FXfire1"}
		{add_view	"smoke_dead_small2"		"smoke4_1"				"FXfire3"}
		{add_view	"exp_tank_ammunition"		"smoke5"				"FXfire3"}
		{add_view	"smoke_dead_small2a"	"smoke4_2"				"FXfire3"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmoke1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmoke2"}

		{add_view	"exp_tank_ammunition"		"exp_ammo_1"				"FXfire3"}
		{add_view	"exp_tank_ammunition_round"	"exp_ammo_3"				"FXfire3"}
		{add_view	"exp_tank_ammunition_gun"	"exp_ammo_2"				"Foresight1"}
		{add_view	"smoke_tank_closed"		"smoke_ammo_1"				"FXfire3"}
		{add_view	"smoke_tank_gun"		"smoke_ammo_2"				"Foresight1"}

		{set "smoke3" 0}
		{set "smoke4" 0}

		{call "update_hatch_on_spawn"}
		{call "talk_scanner"}			
	}

	{on "talk_scanner"			
		{if attacking_weapon or attacked	
			{talk "tank_in_action" {audience all}}			
		}				
		{delay 3 "talk_scanner"
			{call "talk_scanner"}
		}
	}

	{on "add_movement_sound"
		{link_sound "engine"		"vehicle/engine/tank"}
		{link_sound "engine_end"	"vehicle/engine/tank_end"}
		{link_sound "engine_start"	"vehicle/engine/tank_up"}
		{link_sound "exhaust"		"vehicle/engine/tank_up"}
	}

	{on "gunner_hatch_open"
		{if not flag "gunner_hatch_open"
			{set "gunner_hatch_open" 1}
			{ani_wind "open" end}
			{ani_wind "mgun_aa" end}
			{play_sound "open"}
		}
	}
	{on "not_operatable_open_wind"
		{if not flag "gunner_hatch_open"
			{set "gunner_hatch_open" 1}
			{ani_wind "open" end}
			{ani_wind "open_driver" end}
			{ani_wind "mgun_aa" begin}
			{play_sound "open"}
		}
	}
	{on "not_operatable_open_play"
		{if not flag "gunner_hatch_open"
			{set "gunner_hatch_open" 1}
			{ani_play "open" +1.0 resume}
			{ani_play "open_driver" +1.0 resume}
			{ani_play "mgun_aa" -1.0 resume}
			{play_sound "open"}
		}
	}
	{on "gunner_hatch_close_wind"
		{if flag "gunner_hatch_open"
			{set "gunner_hatch_open" 0}
			{ani_wind "open" begin}
			{ani_wind "open_driver" begin}
			{ani_wind "mgun_aa" begin}
			{play_sound "close"}
		}
	}
	{on "gunner_hatch_close_play"
		{if flag "gunner_hatch_open"
			{set "gunner_hatch_open" 0}
			{ani_play "open" -1.0 resume}
			{ani_play "open_driver" -1.0 resume}
			{ani_play "mgun_aa" -1.0 resume}
			{play_sound "close"}
		}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{call "not_operatable_open_wind"}
			else
				{call "not_operatable_open_play"}
			}
		else
			{if crew_in_place "gunner2"
				{call "gunner_hatch_open"}
			else
				{if %wind
					{call "gunner_hatch_close_wind"}
				else
					{call "gunner_hatch_close_play"}
				}
			}
		}
	)
	{on "update_hatch_on_spawn"
		("update_hatch" wind(true))
	}
	(define "update_hatch_event"
		{on %event
			("update_hatch" wind(false))
		}
	)
	("update_hatch_event" event(operatable on))
	("update_hatch_event" event(operatable off))
	("update_hatch_event" event(crew in))
	("update_hatch_event" event(crew out))
        
	{on "emit_on_hit"
		{call "burn_emit"}
		{able select 0}
		
		{view start "smoke4_1"}
		{set "smoke4_1" 1}
		
		{delay 8
			{view stop "smoke4_1"}
			{set "smoke4_1" 0} 	
			{if not flag "burn_fire"
				{able "burning" 0}
				{able repaired 1}			
			}
		}
		{delay 11
			{able select 1}
			{if not flag "burn_fire"
				{able "burning" 0}
				{able repaired 1}			
			}
		}
		{delay 20
			{if not flag "burn_fire"
				{able "burning" 0}			
			}		
		}
	}
        
        {on "emit_on_rocketlauncher"
		{if rand 0.5
			{call "burn_emit"}
		else
			{crew_emit}
		}
		{able select 0}	
		{delay 4
			{if not flag "burn_fire"
				{able select 1}
				{able "burning" 0}
				{able repaired 1}			
			}
		}
		{burn fx "smoke_dead_tank2" fake}
	}
	
	{on "stat_body_break"
		{if not broken
;			{stat_notify break}
			{tags add "body_break"}	
		}	
	}
        
	(define "cut_shield_part"
		{if component %0
			{delay_ex 0.11
						{tear "piece_medium_steel" bone %0
							{impulse up 2 1 dir 2 1}
				}
			}
		}
	)
	{on "contusion_off"
		{if not tagged "gun_brake"
			{weapon_work "gun" 1}
		}
		{weapon_work "gun2" 1}{weapon_work "gun3" 1}{weapon_work "mgun" 1}{weapon_work "mgun1" 1}{weapon_work "mgun2" 1}{weapon_work "mgun3" 1}{weapon_work "mgun4" 1}{weapon_work "mgun5" 1}{weapon_work "mgun6" 1}{weapon_work "mgun7" 1}
		{if tagged "stopped"
			{tags remove "stopped"}
			{if work "mover"
				{if not tagged "engine_brake"
					{chassis_work 1}
				}
			}
		}
		{if tagged "turr_jummed"
			{if tagged "turret_brake"
				{tags remove "turr_jummed"}
			else tagged "turret_stopped_by_body"
				{tags remove "turr_jummed"}
			else
				{tags remove "turr_jummed"}
				{ik_enable "turret" 1}
			}
		}
	}
	{on "destroy_or_explosion"
		{if armor_health -399 and not tagged "destroyed"
			{call "mp_destroy"}
		else armor_health 1 and not flag "broken"
			{if stuff "150to152" or stuff "rocketlauncher" or stuff "cumulative_charge" or stuff "mine antitank"
				{if rand 0.5
					{call "explosion"}
				else
					{call "mp_destroy"}
				}
			else
				{call "mp_destroy"}
			}
		}
	}
	
	{on "pierce_or_blast"
		{if name "pierce"
			{call "mp_destroy"}
		else
			{if min_energy 5 {call "explosion"}}
		}
	}
	
	{on "destroy_or_explosion_break_armor"
		{if armor_health -399 and not tagged "destroyed"
			{if min_energy 3
				{call "explosion"}
			else
				{call "mp_destroy"}
			}
		else armor_health 1 and not tagged "broken_body"
			{call "pierce_or_blast"}
		else
			{call "check_talk_target_broke_component"}
		}	
	}
	
	{on "check_access_to_contusion"
		{if armor_health 1 or flag "broken"
			{set "access_to_contusion" 0}
		else
			{set "access_to_contusion" 1}
		}
	}
	{on "contusion_on_turret"
		{damage_report "crew" "shock"}
		{if work "turret"
			{ik_enable "turret" 0}
			{tags add "turr_jummed"}
		}
		{weapon_work "gun" 0}{weapon_work "gun2" 0}{weapon_work "gun3" 0}{weapon_work "mgun" 0}{weapon_work "mgun1" 0}{weapon_work "mgun2" 0}{weapon_work "mgun3" 0}{weapon_work "mgun4" 0}{weapon_work "mgun5" 0}{weapon_work "mgun6" 0}{weapon_work "mgun7" 0}
	}
	{on "contusion_on_body"
		{call "contusion_on_turret"}
		{if work "mover"
				{chassis_work 0}
				{tags add "stopped"}
		}
	}
	(define "turret_broken"
	{on "turret%n_broken"
		{components "turret%n" break}
		{ik_enable "turret%n" 0}
	}
	)
	;("turret_broken" n())
	{on "turret_broken"
		{components "turret" break}
		{ik_enable "turret" 0}
		{if not flag "broken"
			{call "talk_target_broke_turret"}
		}
	}
	("turret_broken" n(1))
	("turret_broken" n(2))
	("turret_broken" n(3))
	("turret_broken" n(4))
	{on "breakage"
		{if stuff "breakage"
			{if flag "with_gun"
				{if	component "gun"			{call "gun_broken"}}
			}
			{if	component "trackleft"	{call "trackleft_broken"}}
			{if component "trackright"  {call "trackright_broken"}}
			{if	component "engine"		{call "engine_broken"}}
		}
	}
	{on "body_broken"
		{if work "body"
			{components "body" break}
			;{unlink_trailer}
			{call "stat_body_break"}
			{damage_report "body" "break"}
		}
	}
	{on "engine_broken"
		{if work "engine"
			{components "engine" break}
			{if not flag "broken"
				{call "talk_target_broke_engine"}
			}
		}
	}
	{on "gun_broken"
		{if flag "with_gun"
			{if work "gun"
				{components "gun" break}
				{if not flag "broken"
					{damage_report "gun" "broken"}
					{call "talk_target_broke_gun"}
				}
			}
		}
	}
	{on "trackleft_broken"
		{if work "trackleft"
			{components "trackleft" break}
			{if not flag "broken"
				{damage_report "trackleft" "track:broken"}
				{call "talk_target_broke_track"}
			}
		}				
	}
	{on "trackright_broken"
		{if work "trackright"
			{components "trackright" break}
			{if not flag "broken"
				{damage_report "trackright" "track:broken"}
				{call "talk_target_broke_track"}
			}
		}			
	}
	(define "track_hit"
		{if hit_side front
			{if rand %max_rand
				{if volume "trackleft" {call "trackleft_broken"}
				else volume "trackright" {call "trackright_broken"}
				}
			}
		else hit_side back
				{if rand %max_rand
					{if volume "trackleft" {call "trackleft_broken"}
					else volume "trackright" {call "trackright_broken"}
					}				
				}
		else rand %min_rand
			{if volume "trackleft" {call "trackleft_broken"}
			else volume "trackright" {call "trackright_broken"}
			}				
		}
	)
	
	{on "ram_effects"
		{start_sound "crush/medium/metal"}
		{burn fx "smoke_dead_tank3" fake}
	}
	
	{on "crash_from_taran"
		{if armor_health -399 and not flag "broken"
			{set "crash_from_taran" 1}
			{call "mp_destroy"}
		else armor_health 1 and not tagged "broken_body"
			{set "crash_from_taran" 1}
			{call "mp_destroy"}
		}	
	}
	
	{on "ram_component_damage"
		{if volume "wheel"			{component break}}
		{if	component "trackleft"	{call "trackleft_broken"}}
		{if component "trackright"  {call "trackright_broken"}}
		{if	component "engine"		{call "engine_broken"}}
	}
	
	{on "mp_destroy_off"
		{if tagged "in_mp_d"
			{if armor_health -399 and not tagged "destroyed"
				{call "mp_destroyed_off_realism"}
			else
			}		
		else not tagged "broken_body"
			{if rand 0.25
				{call "mp_destroyed_off_realism"}
			else flag "broken_body_one"
				{call "mp_destroyed_off_realism"}
			else
				{call "talk_target_destroyed"}
				{reset_manual_control}
				{drop_orders}{crew_emit}
				{able select 0}
	;			{able repaired 0}
	;			{unlink_trailer}
				{call "body_broken"}
				{chassis_work 0}{ik_enable "turret" 0}
	;			{volumes disable touch}
	;			{call "weapons_off"}
	;			{call "check_burn_emit"}
	;			{kick_entity_manager}
				{tags add "broken_body"}
				{call "detect_broken_body"}
				{set "broken_body_one" 1}
				{call "burn_stop"}
				{call "timer_for_destroyed"}
				{set "broken" 1}
;				{stat_notify break}
				
			}
		else not tagged "in_mp_d"
			{if armor_health -399 and not tagged "destroyed"
				{call "mp_destroyed_off_realism"}
			else
			}
		}
	}
	{on "detect_broken_body"
		{if tagged "broken_body" 
			{detect 15}
			{delay 15 {call "detect_broken_body"}}
		}
	}
	{on "timer_for_destroyed"
		{if not tagged "em_notouch"
			{add_view "smoke_black" 	"t_for_des_1" "engine"}
			{add_view "smoke_black_big" "t_for_des_2" "engine"}
			{add_view "smoke_aero_big" 	"t_for_des_3" "engine"}
			{delay 60 "t_for_des_1"
				{view start "t_for_des_1"}
			}		
			{delay 120 "t_for_des_2"
				{view start "t_for_des_2"}{view stop "t_for_des_1"}
			}
			{delay 300 "t_for_des_3"
				{view start "t_for_des_3"}{view stop "t_for_des_2"}
			}	
			{delay 360 "timer_for_destroyed"
				{call "mp_destroyed_off_realism"}
			}
		}
	}
	
	{on "mp_destroyed_off_realism"
		{kill_delay "timer_for_destroyed"}{kill_delay "t_for_des_1"}{kill_delay "t_for_des_2"}{kill_delay "t_for_des_3"}
		{delay 30 
			{view stop "t_for_des_1"}
			{view stop "t_for_des_2"}
			{view stop "t_for_des_3"}
		}
		{call "talk_target_destroyed"}
		{reset_manual_control}
		{drop_orders}
		{able select 0}
		{able repaired 0}
		{unlink_trailer}
;		{call "weapons_off"}
		{call "check_burn_emit"}
		{kick_entity_manager}	
		{tags add "in_mp_d"}{tags remove "broken_body"}
		{call "mp_destroyed"}
	}
	
	{on "mp_destroyed"
		{if not tagged "destroyed" and tagged "in_mp_d"
			{tags add "destroyed"}
			{damage_report "body" "broken"}
			{if not tagged "body_break"
				{components "body" break}
				{components "engine" break}
				{components "trackleft" break}
				{components "trackright" break}
				{if flag "with_gun"
					{components "gun" break}
					{components "gun2" break}
					{components "gun3" break}
					{components "guns" break}
				}
				{components "shield" break}
				{components "turret" destroy}
				{components "turret1" break}
				{components "turret2" break}
				{components "turret3" break}
				{components "turret4" break}
				{call "stat_break"}
				{delay 30 5
					{view stop "smoke4_1"}
					{view stop "exp_ammo_3"}
					{view stop "exp_ammo_2"}
					{view stop "exp_ammo_1"}
					{view stop "smoke_ammo_2"}
					{view stop "smoke_ammo_1"}
					{stop_sound "ammo_fire"}
				}				
			}
		else
			{call "mp_destroy_main"}
		}
	}
	
	{on "mp_destroy"
		{if rand 0.3
			{call "mp_destroy_main"}
		else rand 0.5
			{if not flag "crash_from_taran"		
				{call "mp_destroy_burn"}
			else
				{call "mp_destroy_main"}
			}
		else rand 0.5
			{if not flag "crash_from_taran"	
				{call "mp_destroy_smoke"}
			else
				{call "mp_destroy_main"}
			}
		else 
			{call "mp_destroy_main"}
		}
	}
	
	{on "mp_destroy_burn"
		{clear_inventory}
		{call "mp_destroy_off"}
		{call "mp_destroyed"}
		{if tagged "in_mp_d"
			{play_sound "ammo_fire" 1}
			{view start "exp_ammo_1"}
			{delay 2.5
				{view start "exp_ammo_3"}
				{delay 15 10
					{view stop "exp_ammo_3"}
				}
			}
			{if not flag "open_wheelhouse"
				{if rand 0.34
					{delay 1
						{view start "exp_ammo_2"} {delay 25 10 {view stop "exp_ammo_3"}}
					}
				else rand 0.5
					{delay 1
						{view start "smoke_ammo_2"} {delay 25 10 {view stop "exp_ammo_3"}}
					}
				}
			}
			{delay 5
				{if rand 0.5
					{call "mp_destroy_main"}
				else rand 0.5
					{stop_sound "ammo_fire"}
					{call "explosion"}
				else
					{stop_sound "ammo_fire"}
					{call "mp_destroy_burn_out"}
				}
			}
			{delay 15 10
				{view stop "exp_ammo_1"}
				{stop_sound "ammo_fire"}
			}
			{if rand 0.25 {spawn "smoke_on_map_med_temp"}}
		}
	}
	
	{on "mp_destroy_smoke"
		{call "mp_destroy_off"}
		{call "mp_destroyed"}
		{view start "smoke_ammo_1"}
		{if not flag "open_wheelhouse"
			{if rand 0.5
				{delay 1
					{view start "smoke_ammo_2"}
				}
			}
		}
		{delay 5
			{if rand 0.5
				{call "mp_destroy_main"}
			else rand 0.5
				{call "mp_destroy_burn"}
				{view stop "smoke_ammo_1"}
			else
				{call "explosion"}
				{view stop "smoke_ammo_1"}
			}
		}
		{delay 15 10
			{view stop "smoke_ammo_1"}
		}
	}
	
	{on "mp_destroy_burn_out"
		{delay 0.5 1.5
			{view stop "exp_ammo_1"}
		}
		{delay 2 3
			{view stop "exp_ammo_2"}
		}
		{delay 3 4
			{view stop "exp_ammo_3"}
		}
		{view start "smoke_ammo_1"}
		{if not flag "open_wheelhouse"
			{if rand 0.5
				{delay 1
					{view start "smoke_ammo_2"}
				}
			}
		}
		{delay 4
			{call "mp_destroy_main"}
		}
		{if rand 0.25 {spawn "smoke_on_map_med_temp"}}
	}
	
	{on "mp_destroy_main"
		{if not tagged "broken_body"
			{call "mp_destroy_off"}
		else tagged "in_mp_d"
			{call "mp_destroy_off"}
			{if not tagged "destroyed"
				{call "mp_destroyed"}
				{damage_report "body" "broken"}
				{components "body" break}
				{able repaired 0}
				
				{if not tagged "body_break"
					{components break}
					{call "stat_break"}
				}
			}
			{delay 5
				{if rand 0.3 and not flag "crash_from_taran" 
					{if terrain_fx "water" or terrain_fx "deep_water" or terrain_fx "swamp" or terrain_fx "shallow_water" 
					else
						{if rand 0.34
							{spawn "fire_tank_fuel" "basis"}
						else rand 0.33
							{spawn "fire_tank_fuel" "fxtracer2"}
						else 
							{spawn "fire_tank_fuel" "fxtracel2"}
						}
					}
				}
			}
			{delay 2.3
				{view start "smoke4_1"}
			}
			{delay 30
				{view stop "smoke4_1"}
				{view stop "exp_ammo_3"}
				{view stop "exp_ammo_2"}
				{view stop "exp_ammo_1"}
				{view stop "smoke_ammo_2"}
				{view stop "smoke_ammo_1"}
				{stop_sound "ammo_fire"}
			}
		else 
			{call "mp_destroy_off"}
		}
	}
	
	{on "mp_repair"
		{kill_delay "timer_for_destroyed"}{kill_delay "t_for_des_1"}{kill_delay "t_for_des_2"}{kill_delay "t_for_des_3"}
		{view stop "t_for_des_1"}
		{view stop "t_for_des_2"}
		{view stop "smoke_ammo_2"}
		{able select 1}
		{able repaired 1}
		{volumes enable touch}
		{if work "engine" and work "trackleft" and work "trackright"
			{chassis_work 1}
		}
		{if work "turret"
			{ik_enable "turret" 1}
		}
		{tags remove "in_mp_d"}
		{tags remove "broken_body"}
	}	
	
	{on "upside_down"
		{reset_manual_control}
		{able select 0}
		{unlink_trailer}
		{if not burned
			{call "_burn"}
			{able repaired 0}
		}
		{set "upended" 1}
	}

	{on "_explosion"
		{add_view "smoke_dead_norm" "deathfx" "FXfire1"}
		{spawn "tank_die" "Basis"}
	}
	{on "spawn_shellhole"
;		{spawn "crater_big" "Basis" no_normal terrain_texmod}
		{spawn "shellhole_dead_tank" "Basis"}
	}
	{on "cut_parts"
		{spawn "tank_die" "Basis"}
		{add_view "smoke_black_big2" "deathfx" "basis"}
		{view start "deathfx"}
		(define "cut_part"
			{if rand 0.5
				{tear "piece_medium_steel" bone %0
					{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
;					{add_view "smoke_dead_wheel" "smoke" "basis"}
;					{view start "smoke"}
					{delay_effect 20 5 "stop"}
				}
			}
		)
		("cut_part" args "part1")
		("cut_part" args "part2")
		("cut_part" args "part3")
		("cut_part" args "part4")
		("cut_part" args "part5")
		("cut_part" args "part6")
		{delay 25 5	{view stop "deathfx"}}
	}

	{on "check_burn_emit"
		{if not flag "burn_fire"
			{if not flag "smoke3"
				{if not flag "smoke4"
					{able "burning" 0}
				else
                                    {delay 5
					{call "burn_emit"}
                                    }
				}
			else
                            {delay 5
				{call "burn_emit"}
                            }
			}
		else
                    {delay
			{call "burn_emit"}
                    }
		}
	}
	{on fire "gun"
       	{view start "flashbarrel1"}
;		{view start "flashbarrel1s"}
		{ani_play "fire"}
		{delay 0.8
			{view pause "flashbarrel1"}
		}
;		{delay 0.2
;			{view pause "flashbarrel1s"}
;		}
	}
	{on fire "gun2"
		{view start "flashbarrel2s"}
		{delay 0.2
			{view pause "flashbarrel2s"}
		}
		;{view start "flashbarrel"}
	}
        {on "criticalhit" overload
        	{if component "body"
        		{if not hit_side front
					{call "engine_broken"}
        		}
        	else component "turret"
				{if flag "with_gun"
					{components "gun" break}
				}
        	}
        }
	{on "explosive_broken"
		{if not work "body"
			{delay 0.1 0.1
				{call "explosion"}
				{damage_report "body" "empty"}
				{damage_report "engine" "empty"}
				{damage_report "trackright" "empty"}
				{damage_report "trackleft" "empty"}
				{damage_report "turret" "empty"}
				{if flag "with_gun"
					{damage_report "gun" "empty"}
				}
			}
		}
    }
    {on "burn_hatch"
		{add_view	"smoke_dead_norm2"	"smoke_hatch"	"FXfire3"}
		{view start "smoke_hatch"}
    }
    {on "burn_engine"
		{add_view	"fire_napalm"	"fire_napalm"	"engine"}
		{view start "fire_napalm"}
	}
    
	{on "rand_burn"
		{if rand 0.2
			{if not burned
				{burn time 17}
				{delay 1
					{call "_burn"}
				}
			}
		}
	}
	{on "burn_crew_mp"
		{if rand 0.6 {kill_crew "gunner"}}
		{if rand 0.6 {kill_crew "charger"}}
		{if rand 0.6 {kill_crew "commander"}}
		{if rand 0.6 {kill_crew "driver"}}
	}
        (define "burn_by_engine"
        	{on "burn_by_engine"
        		{if not tagged "burned"
        			{if rand %0
        				{call "_burn"}
        			}
        		}
            	}
        )

{on contact
	{if effector "mine_antitank"
		{if volume "body"	{set "mine_under_track" 0}
		else {set "mine_under_track" 1}
		}
	}
}
;============================================================================
	{on break_armor
		{if name "blast"
			{if volume "body"
				;{if rand 0.5 {kill_crew "gunner"}}
				;{if rand 0.5 {kill_crew "charger"}}
				;{if rand 0.5 {kill_crew "commander"}}
				;{if rand 0.5 {kill_crew "driver"}}
				;{if rand 0.5 {kill_crew "gunner2"}}
				
				{##if not tagged "destroyed"
					{call "mp_destroy"}
				}
			;else volume "trackleft"
			;else volume "trackright"
			}
			{##if volume "explosive"
			   {if rand 0.5 {call "explosive_broken"}}
			}
		}
		{##if not user_control
			{if volume "body"
				{if rand 0.1 {kill_crew "gunner"}}
				{if rand 0.1 {kill_crew "charger"}}
				{if rand 0.1 {kill_crew "commander"}}
				{if rand 0.1 {kill_crew "driver"}}
			}
		}

		{if not flag "no_burn_volumes"
			{if name "pierce"
				{if volume "body"
					{burn fx "smoke_dead_tank1" fake}
				else volume "track"
					{burn fx "smoke_dead_tank2" time 10 fake}
				}
			}
		}
	}
 
	{on break_armor_again
		{if armor_health -399 and not tagged "destroyed"
			{call "mp_destroy"}
		else armor_health 1 and not tagged "broken_body"
			{call "pierce_or_blast"}
		else
			{if component "engine"
				;{call "burn_by_engine"}
			}
			{if name "blast"
				{if volume "body"
					{if not tagged "destroyed"
						{call "mp_destroy"}
					}
				}
				{if volume "explosive"
					{if rand 0.8 {call "explosive_broken"}}
				}
			}
		}
	}
	
	{on break
		{if component "body"
			{play_sound "crush"}
			{tags add "body_brake"}
			{tags add "turret_stopped_by_body"}
			{spawn "tank_die_particle" "Body"}
;			{call "emit_crew"}
			{view start "smoke4"}
			{set "smoke4" 1}
			{delay 25
				{view start "smoke4_2"}
				{delay 30
			 		{view stop "smoke4_2"}
				}
			}
			
			{delay 30
				{view stop "smoke4"}
				{set "smoke4" 0}
			}
		else component "engine"
            {tags add "engine_brake"}
			{spawn "tank_die_particle" "engine"}
			{view start "smoke1"}
			{set "smoke1" 1}
			{delay 30
				{view stop "smoke1"}
				{set "smoke1" 0}
			}
			;{call "burn_by_engine"}
		else component "shield"
			("cut_shield_part" args "shieldr1")
			("cut_shield_part" args "shieldr2")
			("cut_shield_part" args "shieldr3")
			("cut_shield_part" args "shieldr4")
			("cut_shield_part" args "shieldr5")
			("cut_shield_part" args "shieldr6")
			("cut_shield_part" args "shieldr7")
			("cut_shield_part" args "shieldr8")
			("cut_shield_part" args "shieldr9")
			("cut_shield_part" args "shieldr10")
			("cut_shield_part" args "shieldr11")
			("cut_shield_part" args "shieldr12")
			("cut_shield_part" args "shieldr13")
			("cut_shield_part" args "shieldr14")
			("cut_shield_part" args "shieldr15")

			("cut_shield_part" args "shieldl1")
			("cut_shield_part" args "shieldl2")
			("cut_shield_part" args "shieldl3")
			("cut_shield_part" args "shieldl4")
			("cut_shield_part" args "shieldl5")
			("cut_shield_part" args "shieldl6")
			("cut_shield_part" args "shieldl7")
			("cut_shield_part" args "shieldl8")
			("cut_shield_part" args "shieldl9")
			("cut_shield_part" args "shieldl10")
			("cut_shield_part" args "shieldl11")
			("cut_shield_part" args "shieldl12")
			("cut_shield_part" args "shieldl13")
			("cut_shield_part" args "shieldl14")
			("cut_shield_part" args "shieldl15")
		else component "turret"
			{tags add "turret_brake"}
		;else component "trackright"
			;{tags add "chassis_brake"}
		;else component "trackleft"
			;{tags add "chassis_brake"}
		}
	}