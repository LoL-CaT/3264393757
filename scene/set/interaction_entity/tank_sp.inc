{"tank"

;	{friction 1}
;	{restitution 0.3}
	{on spawn
		{link_sound "flame"			"fire/big"}
		{link_sound "move"			"vehicle/tracks/trackclank"}
		{link_sound "heavy_move"	"vehicle/tracks/heavy"}

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
		else
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

		{add_view	"drops_water"			"on_water"				"FXtraceR1"}
		{add_view	"drops_water"			"on_water"				"FXtraceL1"}
		{add_view	"tank_grit_big_mud"		"on_mud"				"FXtraceR2"}
		{add_view	"tank_grit_big_mud"		"on_mud"				"FXtraceL2"}
		{add_view	"tank_grit_big_snow"	"on_snow"				"FXtraceR2"}
		{add_view	"tank_grit_big_snow"	"on_snow"				"FXtraceL2"}
		{add_view	"drops_water_moto"		"on_puddle"				"FXtraceR1"}
		{add_view	"drops_water_moto"		"on_puddle"				"FXtraceL1"}
		{add_view	"tank_grit_small_w"		"on_puddle"				"FXtraceR2"}
		{add_view	"tank_grit_small_w"		"on_puddle"				"FXtraceL2"}

;		{add_view	"flash_cannon_big"		"flashbarrel1"			"Foresight1"}
		{add_view	"powdersmoke_big"		"flashbarrel1s"			"Foresight1"}
;		{add_view	"powdersmoke_small2" 	"flashbarrel1s" 		"Foresight1"}
;		{add_view	"flash_gun_big"			"flashbarrel2"			"Foresight3"}

		{add_view	"smoke_white_steam"		"smoke1"				"FXfire1"}
		{add_view	"smoke_black"			"smoke2"				"FXfire2"}
		{add_view	"smoke_black"			"smoke3"				"FXfire2"}
		{add_view	"smoke_black"			"smoke4"				"FXfire1"}
		{add_view	"smoke_dead_small2"		"smoke4_1"				"FXfire3"}
		{add_view	"smoke_dead_small2a"	"smoke4_2"				"FXfire3"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmoke1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmoke2"}
		{set "smoke3" 0}
		{set "smoke4" 0}

		{call "update_hatch_on_spawn"}
	}

	{on "add_movement_sound"
		{link_sound "engine"		"vehicle/engine/tank"}
		{link_sound "engine_end"	"vehicle/engine/tank_end"}
		{link_sound "exhaust"		"vehicle/engine/tank_up"}

	}

	{on "gunner_hatch_open"
		{ani_wind "open" end}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
			else
				{ani_play "open" +1.0 resume}
			}
		else
			{if crew_in_place "gunner2"
				{call "gunner_hatch_open"}
			else
				{if %wind
					{ani_wind "open" begin}
				else
					{ani_play "open" -1.0 resume}
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

	(define "gun_hit"
		{if volume "gun"
			{if rand (* 0.6 %rand)
				{components "gun" break}
				{damage_report "gun" "broken"}		
			}
		}
	)
	
	(define "track_hit"
		{if hit_side front
 			{if rand %max_rand
				{if volume "trackleft"
					{burn fx "smoke_dead_tank2" fake}	
					{components "trackleft" break}	
					{if work "trackleft" {damage_report "trackleft" "track:broken"}}				
				else volume "trackright"				
					{burn fx "smoke_dead_tank2" fake}
					{components "trackright" break}	
					{if work "trackright" {damage_report "trackright" "track:broken"}}			
				}
			}
		else hit_side back
				{if rand %max_rand
					{if volume "trackleft"	
						{burn fx "smoke_dead_tank2" fake}
						{components "trackleft" break}	
						{if work "trackleft" {damage_report "trackleft" "track:broken"}}													
					else volume "trackright"
						{burn fx "smoke_dead_tank2" fake}
						{components "trackright" break}	
						{if work "trackright" {damage_report "trackright" "track:broken"}}			
					}				
				}
		else rand %min_rand
			{if volume "trackleft"	
				{components "trackleft" break}
				{burn fx "smoke_dead_tank2" fake}	
				{if work "trackleft" {damage_report "trackleft" "track:broken"}}				
			else volume "trackright"
				{components "trackright" break}	
				{burn fx "smoke_dead_tank2" fake}
				{if work "trackright" {damage_report "trackright" "track:broken"}}			
			}				
		}
	)

	{on "emit_on_hit"
		{call "burn_emit"}
		{able select 0}
		
		{view start "smoke4_1"}
		{set "smoke4_1" 1}
		
		{delay 8
			{view stop "smoke4_1"}
			{set "smoke4_1" 0} 	
		}
		{delay 11
			{able select 1}
			{if not flag "burn_fire"
				{able "burning" 0}
				{able repaired 1}			
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
			{stat_notify break}
			{tags add "body_break"}	
		}	
	}
		
	{on pierce
		{if stuff "zenite 20to57"
			("gun_hit" rand(0.5))
			("track_hit" max_rand(0.25) min_rand(0.15))
;/////////////////////////////////////////////////////////	
		else stuff "hmgun"
			("gun_hit" rand(0.5))
			("track_hit" max_rand(0.25) min_rand(0.15))
;/////////////////////////////////////////////////////////	
 		else stuff "zenite ptr"
			("gun_hit" rand(0.5))
			("track_hit" max_rand(0.6) min_rand(0.4))
;/////////////////////////////////////////////////////////
		else stuff "20to57"
			("gun_hit" rand(0.5))
			("track_hit" max_rand(0.5) min_rand(0.4))
;/////////////////////////////////////////////////////////
		else stuff "rocketlauncher"
			("gun_hit" rand(0.5))
			("track_hit" max_rand(0.6) min_rand(0.4))
;/////////////////////////////////////////////////////////
		else stuff "75to76"
			("gun_hit" rand(0.6))
			("track_hit" max_rand(0.6) min_rand(0.5))
;/////////////////////////////////////////////////////////
		else stuff "85to93"
			("gun_hit" rand(0.6))
			("track_hit" max_rand(1) min_rand(0.6))
;/////////////////////////////////////////////////////////
		else stuff "100to152"
			("gun_hit" rand(0.8))
			("track_hit" max_rand(1) min_rand(0.8))
			(mod "mp"		
				{if volume "body"
					{burn fx "smoke_dead_tank1" fake}
					{call "mp_destroy"}
				else volume "turret"
					{if rand 0.8 {kill_crew "charger"}}
					{if rand 0.6 {kill_crew "driver"}}											
					{kill_crew "gunner"}
					{kill_crew "gunner2"}
					{kill_crew "commander"}
					{if stuff "size3"
						{if rand 0.3
							{call "tear_turret"}
							{call "mp_destroy"}
						}
					}
				}
			)
		}
		
	} ; on pierce END
	
	{on break_armor
		{if volume "body"
			{if not tagged "destroyed"
				{call "mp_destroy"}
			}
		}		
		{if not user_control
			{if volume "body"
				{if rand 0.1 {kill_crew "gunner"}}
				{if rand 0.1 {kill_crew "charger"}}
				{if rand 0.1 {kill_crew "commander"}}
				{if rand 0.1 {kill_crew "driver"}}
			}		
		}
		{if volume "explosive"
			(mod not "mp"
				{call "explosive_broken"}
			)			
		else not flag "no_burn_volumes"
			{if name "pierce"
				{if volume "body"
					{burn fx "smoke_dead_tank1" fake}
					(mod not "mp"
						{call "rand_burn"}
					)
				else volume "track"
					{burn fx "smoke_dead_tank1" fake}
				}
			}
		}
	}
	{on break_armor_again
		{if component "engine"
			{if not work "engine"
				{call "burn_by_engine"}
			}
		}
		{if component "body"		
			{call "mp_destroy"}
		}
		{if component "turret"		
			{if  stuff "100to152"
				{if rand 0.4 
					{call "tear_turret"}
					{call "mp_destroy"}
				}
			}	
		}
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

	{on break
		{if component "body"
			(mod not "mp"
				{if not user_control
					{if rand 0.5 {kill_crew "gunner"}}
					{if rand 0.5 {kill_crew "charger"}}
					{if rand 0.5 {kill_crew "commander"}}
					{if rand 0.5 {kill_crew "driver"}}
				}
			)
			{spawn "tank_die_particle" "Body"}
;			{call "emit_crew"}
			{view start "smoke4"}
			{set "smoke4" 1}
			(mod not "mp"
				{delay 2.3
					{view start "smoke4_1"}
				}
				{call "check_burn_emit"}
			)	    
			{delay 25                       
				{view start "smoke4_2"}     
				{delay 30                   
		   	 		{view stop "smoke4_2"}  
				}                           
			}								
			
   			{delay 30
   				{view stop "smoke4"}
  				(mod not "mp" 
  					{view stop "smoke4_1"}
  				)
				{set "smoke4" 0}
				(mod not "mp"
					{call "check_burn_emit"}
				)
   			}
   		else component "engine"
			{spawn "tank_die_particle" "engine"}
			{view start "smoke1"}
			{set "smoke1" 1}
   			(mod not "mp"
				{call "check_burn_emit"}
			)
   			{delay 30
   				{view stop "smoke1"}
				{set "smoke1" 0}
   				(mod not "mp"
					{call "check_burn_emit"}
				)
   			}
   			{call "burn_by_engine"}
  			
    		else component "shield"
				(define "cut_shield_part"
					{if component %0
						{delay_ex 0.11
							{tear "piece_medium_steel" bone %0
								{impulse up 2 1 dir 2 1}
							}
						}
					}
				)
				("cut_shield_part" args "shieldr1")
				("cut_shield_part" args "shieldr2")
				("cut_shield_part" args "shieldr3")
				("cut_shield_part" args "shieldr4")
				("cut_shield_part" args "shieldr5")
				("cut_shield_part" args "shieldr6")
				("cut_shield_part" args "shieldl1")
				("cut_shield_part" args "shieldl2")
				("cut_shield_part" args "shieldl3")
				("cut_shield_part" args "shieldl4")
				("cut_shield_part" args "shieldl5")
				("cut_shield_part" args "shieldl6")
	    	}
		}    	
	)
	
	
	
	{on "mp_destroy"
		{if not tagged "destroyed"
			{damage_report "body" "broken"}
			{if not tagged "body_break"
				{components "body" break}
				{call "stat_break"}
			}
		}
		
		{delay 0.2
			;{components "body" destroy}
			{tags add "destroyed"}
			{kick_entity_manager}
		}

		{if rand 0.5	
			("cut_shield_part" args "shieldl4")
			("cut_shield_part" args "shieldl5")
			("cut_shield_part" args "shieldr2")
			("cut_shield_part" args "shieldr3")
		}
		{if rand 0.5	
			("cut_shield_part" args "shieldl2")
			("cut_shield_part" args "shieldl3")
			("cut_shield_part" args "shieldr4")
			("cut_shield_part" args "shieldr1")
		}
		{call "check_burn_emit"}
		{delay 2.3
			{view start "smoke4_1"}
		}
		{delay 30
  			{view stop "smoke4_1"}
  		}
											
		{reset_manual_control}
		{able select 0}
		{able repaired 0}
		{unlink_trailer}
	}

	{on "_burn"
		{add_view		"smoke_dead_norm"	"burn_fire"		"FXfire1"}
		{view start "burn_fire"}
	}
	{on "_explosion"
		{add_view "smoke_dead_norm" "deathfx" "FXfire1"}
		{spawn "tank_die" "Basis"}
	}
	{on "spawn_shellhole"
;		{spawn "crater_big_tank" "Basis" no_normal terrain_texmod}
		{spawn "shellhole_dead_tank2" "Basis"}
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
					{call "burn_emit"}
				}
			else
				{call "burn_emit"}
			}
		else
			{call "burn_emit"}
		}
	}
	{on fire "gun"
        {view start "flashbarrel1"}
		{view start "flashbarrel1s"}
		{ani_play "fire"}
		{delay 0.8
			{view pause "flashbarrel1"}
		}
		{delay 0.2
			{view pause "flashbarrel1s"}
		}
	}
    {on "criticalhit" overload
    	{if component "body"
    		{if not hit_side front
    			{components "engine" break}
    		}
    	else component "turret"
			{components "gun" break}
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
				{damage_report "gun" "empty"}
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

}

{"opened tank"
	{on "explosive_broken" overload
		{call "explosion"}
    }
}

{"m4a3c"
	{on fire "gun2"
		{spawn "startsmoke_cali"}
	}
}

{"m4calliope"	; must be placed before	the props "turret"
	{on blast
		{if volume "gun"
			{if min_energy 2
				{call "tear_gun"}
			}
		}
	}
	{on bullet_hit
		{if volume "gun"
			{if stuff "big shell"
				{if rand 0.5
					{call "tear_gun"}
				}
			}			
		}		
	}
	{on "tear_turret"
		{if flag "roof_broken"
			{bone cut "gun"}
		else
			{call "tear_gun"}
		}		
	}
	{on "tear_gun"
		{if not flag "roof_broken"
			{set "roof_broken" 1}
			{components "gun" destroy}
			{delay_ex 0
				(define "teargun"
					{tear "piece_large_steel" bone "%gun"
						{impulse up 5 2.3 dir 3 1.5 cx 5 2 cy 5 2 rnd_dir 10 no_position}
						{add_view "smoke_black" "smoke" "basis"}
						{view start "smoke"}
						{delay_effect 20 5 "pause"}
					}
				)
				("teargun" gun(gun1))
				("teargun" gun(gun2))
				("teargun" gun(gun3))
				("teargun" gun(gun4))
				("teargun" gun(gun5))
;				{tear "piece_large_steel" bone "gun"
;					{impulse up 5 2.3 dir 3 1.5 cx 5 2 cy 5 2 rnd_dir 10 no_position}
;					{add_view "smoke_black" "smoke" "basis"}
;					{view start "smoke"}
;					{delay_effect 20 5 "pause"}
;				}
			}
		}
	}
}

{"turret"
	{on spawn
		{call "update_turret"}
	}
	{on break
		{if component "turret"
			{if not user_control
				{if rand 0.5 {kill_crew "gunner"}}
				{if rand 0.5 {kill_crew "charger"}}
				{if rand 0.5 {kill_crew "commander"}}
			}
			{call "update_turret"}
			{spawn "tank_die_particle" "Turret"}
			{spawn "circledust_norm" "Turret"}
;			{ani_play "open" -1.0 resume}
			{view start "smoke3"}
			(mod not "mp"
				{set "smoke3" 1}
				{call "check_burn_emit"}
			)
    		{delay 10
    			{view stop "smoke3"}
				{set "smoke3" 0}
				(mod not "mp"
					{call "check_burn_emit"}
				)
    		}
    	else component "body"
			{spawn "circledust_norm" "Turret"}
			{call "update_turret"}
		}
	}
	{on repair
		{if component "turret"
			{view stop "smoke3"}
			{call "update_turret"}
		else component "body"
			{view stop "smoke4"}
			{call "update_turret"}
		}
	}
	{on "tear_turret"
		{if not flag "turret_teared"
			{set "turret_teared" 1}
			{components "turret" destroy}
			{add_view "smoke_black_big5" "smoke_turret" "basis"}
			{view start "smoke_turret"}
			{delay 60 15		
				{view stop "smoke_turret"}
			}
			{delay_ex 0
				{tear "piece_large_steel" bone "turret" id "turret"
					{impulse up 5 2.3 dir 3 1.5 cx 5 2 cy 5 2 rnd_dir 10 no_position}
					{if rand 0.2
						{add_view "smoke_dead_norm" "smoke" "basis"}
					else 
						{add_view "smoke_black" "smoke" "basis"}
					}
					{view start "smoke"}
					{delay_effect 30 5 "pause"}
					{delay 0.1
						{volumes "gun" disable obstacle}
					}
				}
			}
		}
	}
	{on "slice_load"
		{if name "turret"
			{with_effector
				{add_view "smoke_black" "smoke" "basis"}
			}
		}
	}

	{on "cut_parts"
		{if flag "turret_teared"
			{bone cut "turret"}
		else
		    {call "tear_turret"}
		}
	}
	{on "update_turret"
		{if work "turret"
			{if work "body"
				{ik_enable "turret" 1}
			 else 
				{ik_enable "turret" 0}
			}
		 else
			{ik_enable "turret" 0}
		}
	}
}

;{"medium tank turret"
;	{on bullet_hit
;		{if stuff "big shell fg"
;			{if rand 0.2
;				{call "tear_turret"}
;			}
;		}
;	}
;}

{"light tank turret"
	{on bullet_hit
		{if volume "turret"
			{if stuff "big shell fg"
				{if rand 0.8
					{call "tear_turret"}
				}
			}
		}
	}
}

{"light_turret" ; turret for btr, car, ...
	{on bullet_hit
		{if volume "turret"
			{if stuff "shell"
				{call "tear_turret"}
			}
		}
	}
}

{"armored_car"
	{on spawn
		{add_view	"flash_cannon_small"		"flashbarrel1"			"Foresight1"}
	}
	{on bullet_hit
 		{if stuff "big shell extra"
		 	{ani_play "hit"}
;			{impulse up 6 2 dir 5 1}
		 else stuff "big shell"
		 	{ani_play "hit"}
;			{impulse up 1.9 0.7 dir 1.7 0.8}
		 else stuff "shell"
		 	{ani_play "hit"}
		}
	}
	{on fire "gun"
       	{spawn "dust_shot_small" "basis"}
        {spawn "tank_canon_fire_small" "Foresight1" x}
	}
	{on blast_hit
		{if min_energy 8
			{impulse up 2 0.5 dir 1 0.2}
		 else min_energy 1
			{impulse up 0.4 0.2 dir 0.4 0.2}
		 else min_energy 0.4
		 	{ani_play "hit"}
		}
	}
	{on "_explosion"	
		{blastwave c4 2 r0 3 r1 9}
		{impulse up 0.7 0.3 dir 0.2 0.1}
	}
	{on pierce
		{if stuff "zenite 20to57"
			("track_hit" max_rand(0.4) min_rand(0.3))
		else stuff "hmgun"
			("track_hit" max_rand(0.4) min_rand(0.3))
 		else stuff "zenite ptr"
			("track_hit" max_rand(0.8) min_rand(0.4))
		else stuff "20to57"
			("track_hit" max_rand(0.6) min_rand(0.4))
		else stuff "rocketlauncher"
			("track_hit" max_rand(1) min_rand(0.4))
		else stuff "75to76"
			("track_hit" max_rand(1) min_rand(0.6))
		else stuff "85to93"
			("track_hit" max_rand(1) min_rand(0.8))
		else stuff "100to152"
			("track_hit" max_rand(1) min_rand(1))
		}	
	}
}

{"light tank"
	{on spawn
		{add_view	"flash_cannon_small"		"flashbarrel1"			"Foresight1"}
	}
	{on fire "gun"
       	{spawn "dust_shot_small" "basis"}
        {spawn "tank_canon_fire_small" "Foresight1" x}
	}
	{on bullet_hit
 		{if stuff "big shell extra"
		 	{ani_play "hit"}
;			{impulse up 7 1 dir 5 0.5}
		 else stuff "big shell"
		 	{ani_play "hit"}
;			{impulse up 1.9 0.7 dir 1.7 0.8}
		 else stuff "shell"
		 	{ani_play "hit"}
		}
	}
	{on blast_hit
		{if min_energy  9
			{impulse up 0.5 0.2 dir 1 0.2}
			{call "tear_turret"}
		 else min_energy 6
			{impulse up 0.4 0.1 dir 0.7 0.2}
			{if rand 0.6 {call "tear_turret"}}
		 else min_energy 1
		 	{ani_play "hit"}
		}
	}
	{on "_explosion"
		{blastwave c4 2 r0 6 r1 12}
		{impulse up 0.5}
	}
	{on pierce
		{if stuff "zenite 20to57"
			("track_hit" max_rand(0.3) min_rand(0.15))
		else stuff "hmgun"
			("track_hit" max_rand(0.25) min_rand(0.15))
 		else stuff "zenite ptr"
			("track_hit" max_rand(0.8) min_rand(0.4))
		else stuff "20to57"
			("track_hit" max_rand(0.6) min_rand(0.4))
		else stuff "rocketlauncher"
			("track_hit" max_rand(1) min_rand(0.4))
		else stuff "75to76"
			("track_hit" max_rand(1) min_rand(0.6))
		else stuff "85to93"
			("track_hit" max_rand(1) min_rand(0.8))
		else stuff "100to152"
			("track_hit" max_rand(1) min_rand(1))
		}	
	}
}

{"medium tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel1"			"Foresight1"}
	}
	{on fire "gun"
       	{spawn "dust_shot_norm" "basis"}
        {spawn "tank_canon_fire" "Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.5 bone "Foresight1"}
	}
	{on bullet_hit
 		{if stuff "big shell extra"
		 	{ani_play "hit"}
;			{impulse up 5 dir 4}
		 else stuff "big shell"
		 	{ani_play "hit"}
;			{impulse up 1.0 0.3 dir 1.0 0.3}
		 else stuff "shell"
		 	{ani_play "hit"}
		}
	}
	{on blast_hit
		{if min_energy 12
			{impulse up 0.8 0.2 dir 1.5 0.2}
			{if volume "turret"
				{if rand 0.5 
					{call "tear_turret"}
				}
			}
		 else min_energy 9
			{impulse up 0.4 0.2 dir 1 0.2}
		 else min_energy 7
			{impulse up 0.3 0.1 dir 0.4 0.1}
		 else min_energy 1
		 	{ani_play "hit"}
		}
	}
	{on "_explosion"
		{blastwave c4 2 r0 6 r1 12}
		{impulse up 2 0.5 dir 0.4 0.2}
	}
	{on "check_water_level" overload
		{if water_level 1.6
			{able "sinking" 1}
		}
	}
	{on pierce
		{if stuff "zenite 20to57"
			("track_hit" max_rand(0.15) min_rand(0.1))
		else stuff "hmgun"
			("track_hit" max_rand(0.15) min_rand(0.1))
 		else stuff "zenite ptr"
			("track_hit" max_rand(0.45) min_rand(0.3))
		else stuff "20to57"
			("track_hit" max_rand(0.45) min_rand(0.3))
		else stuff "rocketlauncher"
			("track_hit" max_rand(0.6) min_rand(0.4))
		else stuff "75to76"
			("track_hit" max_rand(0.7) min_rand(0.5))
		else stuff "85to93"
			("track_hit" max_rand(0.8) min_rand(0.6))
		else stuff "100to152"
			("track_hit" max_rand(1) min_rand(0.7))
		}	
	}
}

{"heavy tank"
	{inflammation_time 30}
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel1"			"Foresight1"}
	}
	{on fire "gun"
       	{spawn "dust_shot_big" "basis"}
        {spawn "tank_canon_fire" "Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.5 bone "Foresight1"}
	}
	{on bullet_hit
 		{if stuff "big shell extra"
		 	{ani_play "hit"}
;			{impulse up 4 1 dir 4}
		 else stuff "big shell"
		 	{ani_play "hit"}
;			{impulse up 0.6 0.2 dir 0.3 0.05}
		 else stuff "shell"
		 	{ani_play "hit"}
		}
	}
	{on blast_hit
		{if min_energy 14
			{impulse up 0.25 0.1 dir 0.35 0.1}
			{if volume "turret"
				{if rand 0.3
					{call "tear_turret"}
				}			
			}
		 else min_energy 8
			{impulse up 0.2 0.1 dir 0.3 0.1}
		 else min_energy 3
		 	{ani_play "hit"}
		}
	}
	{on "_explosion"
		{impulse up 3 1 dir 0.6 0.2}
	}
	{on "check_water_level" overload
		{if water_level 1.8
			{able "sinking" 1}
		}
	}
	{on pierce
		{if stuff "zenite 20to57"
			("track_hit" max_rand(0.1) min_rand(0.05))
		else stuff "hmgun"
			("track_hit" max_rand(0.1) min_rand(0.05))
 		else stuff "zenite ptr"
			("track_hit" max_rand(0.35) min_rand(0.2))
		else stuff "20to57"
			("track_hit" max_rand(0.35) min_rand(0.2))
		else stuff "rocketlauncher"
			("track_hit" max_rand(0.5) min_rand(0.35))
		else stuff "75to76"
			("track_hit" max_rand(0.6) min_rand(0.35))
		else stuff "85to93"
			("track_hit" max_rand(0.7) min_rand(0.4))
		else stuff "100to152"
			("track_hit" max_rand(1) min_rand(0.6))
		}		
	}
}

{"mine_exploder"
	{on spawn
		{bone hide "wheel_work"}
		{add_view "dustrun_sand_big"	"wheel_work_dust"	"FXWheel_Work1"}
		{add_view "dustrun_sand_big"	"wheel_work_dust"	"FXWheel_Work2"}
		{volumes "wheel_work" disable all}
		{ani_play "wheel_stop"}
	}
	{on move on
		{bone hide "wheel"}
		{bone show "wheel_work"}
		{view start "wheel_work_dust"}
		{volumes "wheel_work" enable all}
		{volumes "wheel" disable all}
	}
	{on move off
		{bone hide "wheel_work"}
		{bone show "wheel"}
		{ani_play "wheel_stop"}
		{view pause "wheel_work_dust"}
		{volumes "wheel_work" disable all}
		{volumes "wheel" enable all}
	}
	{on blast overload
		{if not volume "wheel_work"
			{inherited}
		else
			{ani_play "explosion"}
		}
	}
}

(define "burn_by_engine"
	{on "burn_by_engine"
		{if not tagged "burning"
			{if rand %0
				{call "_burn"}
				{damage_report "engine" "burn"}
				{tags add "burning"}
			}
		}
		{delay 30
			{tags remove "burning"}
		}
	}
)

{"pz1b tank"
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"	}	
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"	}
		{link_sound "move"				"vehicle/tracks/pz1"	}
		{link_sound "engine"			"vehicle/engine/pz1"	}
		{link_sound "engine_end"		"vehicle/engine/pz1_end"}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine/pz1_up"	}
	}
	{on fire "mgun" overload
		{if  name "00"
			{view start "flashbarrel00"}
		else name "01"
			{view start "flashbarrel01"}
		}
	}
	("burn_by_engine" args 0.3)
}
(define "pz1_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/pz1"}
		{link_sound "engine"			"vehicle/engine/pz1"		}
		{link_sound "engine_end"		"vehicle/engine/pz1_end"	}
		{link_sound "exhaust"			"vehicle/engine/pz1_up"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}

	}
)
{"pz1 tank"
	("pz1_sound")
	("burn_by_engine" args 0.3)
}
{"pz1b tank"
	("pz1_sound")
	("burn_by_engine" args 0.3)
}
{"sturmpz1 tank"
	("pz1_sound")
	("burn_by_engine" args 0.3)
}
(define "t26_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/bt"			}
		{link_sound "rotate_turret" 	"vehicle/turret/light"		}
		{link_sound "engine"			"vehicle/engine/t26"		}
		{link_sound "engine_end"		"vehicle/engine/t26_end"	}
		{link_sound "exhaust"			"vehicle/engine/t26_up"	}
	}
)
{"t26 tank"
	("t26_sound")
	("burn_by_engine" args 0.2)
}
{"carro15 tank"
	("t26_sound")
	("burn_by_engine" args 0.3)
}
(define "su76_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/t-70"}
		{link_sound "engine"			"vehicle/engine/t26"		}
		{link_sound "engine_end"		"vehicle/engine/bt_end"	}
		{link_sound "exhaust"			"vehicle/engine/bt_up"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}

	}
)
{"su76 tank"
	("su76_sound")
	("burn_by_engine" args 0.2)
}
{"t70 tank"
	("su76_sound")
	("burn_by_engine" args 0.2)
}
{"zsu37 tank"
	("su76_sound")
	("burn_by_engine" args 0.2)
}
{"bt7a tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/bt"		}
		{link_sound "engine"			"vehicle/engine/bt"		}
		{link_sound "engine_end"		"vehicle/engine/bt_end"	}
		{link_sound "exhaust"			"vehicle/engine/bt_up"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
	}
	("burn_by_engine" args 0.2)
}

(define "kv_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/is"}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy"	}
		{link_sound "engine"			"vehicle/engine/kv"			}
		{link_sound "engine_end"		"vehicle/engine/kv_end"		}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"		}
	}
)
(define "is_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks/is"		}
		{link_sound "rotate_turret" 		"vehicle/turret/heavy1"		}
		{link_sound "engine"			"vehicle/engine/is"		}
		{link_sound "engine_end"		"vehicle/engine/is_end"		}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"	}
	}
)
{"kv1 tank"
	("kv_sound")
	("burn_by_engine" args 0.2)
}
{"kv2 tank"
	("kv_sound")
	("burn_by_engine" args 0.2)
}
{"kv85 tank"
	("kv_sound")
	("burn_by_engine" args 0.2)
}
{"is1 tank"
	("is_sound")
	("burn_by_engine" args 0.2)
}
{"is2 tank"
	("is_sound")
	("burn_by_engine" args 0.2)
}
{"is2_44 tank"
	("is_sound")
	("burn_by_engine" args 0.2)
}
{"is3 tank"
	("is_sound")
	("burn_by_engine" args 0.2)
}
{"m26 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/m26"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pershing"		}
		{link_sound "engine"			"vehicle/engine/m26"		}
		{link_sound "engine_end"		"vehicle/engine/m4a2_end"	}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"t29 tank"
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"	}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"	}
	}
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/m26"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pershing"		}
		{link_sound "engine"			"vehicle/engine/m26"		}
		{link_sound "engine_end"		"vehicle/engine/m4a2_end"	}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"	}
	}
	{on fire "mgun2"
		{if  name "00"
			{view start "flashbarrel00"}
		else name "01"
			{view start "flashbarrel01"}
		}
	}
	{on "gunner_hatch_open" overload
		{ani_wind "open2" end}
	}
	{on "tear_turret" overload
		{if not flag "turret_teared"
			{set "turret_teared" 1}
			{components "turret" destroy}
			{add_view "smoke_black_big5" "smoke_turret" "basis"}
			{view start "smoke_turret"}
			{delay 60 15		
				{view stop "smoke_turret"}
			}
			{delay_ex 0
				{tear "piece_medium_steel" bone "part3" id "turret"
					{impulse up 3 5 rnd_dir 3}
				}
				{tear "piece_medium_steel" bone "part4" id "turret"
					{impulse up 3 5 rnd_dir 3}
				}
				{tear "piece_large_steel" bone "turret" id "turret"
					{impulse up 5 2.3 dir 3 1.5 cx 5 2 cy 5 2 rnd_dir 10 no_position}
					{if rand 0.2
						{add_view "smoke_dead_norm" "smoke" "basis"}
					else 
						{add_view "smoke_black" "smoke" "basis"}
					}
					{view start "smoke"}
					{delay_effect 30 5 "pause"}
					{delay 0.1
						{volumes "gun" disable obstacle}
					}
				}
			}
		}
	}
	("burn_by_engine" args 0.3)
}
{"isu152 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/is"		}
		{link_sound "engine"			"vehicle/engine/isu"		}
		{link_sound "engine_end"		"vehicle/engine/isu_end"	}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"		}
	}
;	{on fire "gun"
;		{spawn "tagged_piece"}
;	}
	("burn_by_engine" args 0.2)
}
(define "t34_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks/t34"	}
		{link_sound "rotate_turret" 	"vehicle/turret/medium"		}
		{link_sound "engine"			"vehicle/engine/t34"		}
		{link_sound "engine_end"		"vehicle/engine/t34_end"	}
		{link_sound "exhaust"			"vehicle/engine/m3a1_up"		}
	}
)
{"t34_0 tank"
	("t34_sound")
	("burn_by_engine" args 0.2)
}
{"t34_1 tank"
	("t34_sound")
	("burn_by_engine" args 0.2)
}
{"t34_2 tank"
	("t34_sound")
	("burn_by_engine" args 0.2)
}
{"su85 tank"
	("t34_sound")
	("burn_by_engine" args 0.2)
}
{"su100 tank"
	("t34_sound")
	("burn_by_engine" args 0.2)
}
{"t34_3 tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks/t34"	}
		{link_sound "rotate_turret" 	"vehicle/turret/t34"		}
		{link_sound "engine"			"vehicle/engine/t3485"		}
		{link_sound "engine_end"		"vehicle/engine/t3485_end"	}
		{link_sound "exhaust"			"vehicle/engine/m3a1_up"	}
	}
	("burn_by_engine" args 0.2)
}
{"pz5g tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks/jugdpanther"		}
		{link_sound "engine"			"vehicle/engine/jugdpanther"		}
		{link_sound "engine_idle"		"vehicle/engine/jugdpanther_idle"	}
		{link_sound "engine_end"		"vehicle/engine/jugdpanther_end"	}
		{link_sound "rotate_turret" 		"vehicle/turret/heavy"	}
		{link_sound "exhaust"			"vehicle/engine/jugdpanther_up"	}
	}
	("burn_by_engine" args 0.3)
}
(define "m8_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/wheels/m8grayhound"		}
		{link_sound "engine"			"vehicle/engine/m8grayhound"		}
		{link_sound "engine_end"		"vehicle/engine/m8grayhound_end"	}
		{link_sound "rotate_turret" 		"vehicle/turret/mk7_turret"		}
		{link_sound "exhaust"			"vehicle/engine/m8grayhound_up" 	}
	}
)
{"m8 tank"
	("m8_sound")
	("burn_by_engine" args 0.3)
}
{"m3stuart tank"
	("m8_sound")
	("burn_by_engine" args 0.3)
}
{"mk2 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/mk2"	}
		{link_sound "engine"			"vehicle/engine/pz2"		}
		{link_sound "engine_end"		"vehicle/engine/pz2_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/medium1"		}
		{link_sound "exhaust"			"vehicle/engine/pz2_up" 	}
	}
	("burn_by_engine" args 0.3)
}
(define "mk7_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/mk7"	}
		{link_sound "engine"			"vehicle/engine/mk7"		}
		{link_sound "engine_end"		"vehicle/engine/mk7_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/mk7_turret"		}
		{link_sound "exhaust"			"vehicle/engine/mk7_up" 	}
	}
)
{"mk7 tank"
	("mk7_sound")
	("burn_by_engine" args 0.3)
}
{"mk2a tank"
	("mk7_sound")
	("burn_by_engine" args 0.3)
}
(define "bishop_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/bishop"	}
		{link_sound "engine"			"vehicle/engine/bishop"		}
		{link_sound "engine_end"		"vehicle/engine/bishop_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/medium1"		}
		{link_sound "exhaust"			"vehicle/engine/bishop_up" 	}
	}
)
{"bishop tank"
	("bishop_sound")
	("burn_by_engine" args 0.3)
}
{"mk3 tank"
	("bishop_sound")
	("burn_by_engine" args 0.3)
}
(define "mk6_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/crusader"	}
		{link_sound "engine"			"vehicle/engine/crusader"		}
		{link_sound "engine_end"		"vehicle/engine/crusader_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/medium1"		}
		{link_sound "exhaust"			"vehicle/engine/crusader_up" 	}
	}
)
{"mk6 tank"
	("mk6_sound")
	("burn_by_engine" args 0.3)
}
{"crusaderaa2 tank"
	("mk6_sound")
	("burn_by_engine" args 0.3)
}
{"mk4 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/churchill"		}
		{link_sound "engine"			"vehicle/engine/churchill"		}
		{link_sound "engine_end"		"vehicle/engine/churchill_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "exhaust"			"vehicle/engine/churchill_up" 	}
	}
	("burn_by_engine" args 0.3)
}
{"mk8 tank"
	{on "add_movement_sound" overload
		{link_sound "move"		    	"vehicle/tracks/cromwell"	}
		{link_sound "engine"			"vehicle/engine/cromwell"		}
		{link_sound "engine_end"		"vehicle/engine/cromwell_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "exhaust"			"vehicle/engine/cromwell_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"tortez tank"
	{on "add_movement_sound" overload
		{link_sound "move"		    	"vehicle/tracks/turtoise.wav"	}
		{link_sound "engine"			"vehicle/engine/turtoise"		}
		{link_sound "engine_end"		"vehicle/engine/turtoise_end"	}
		{link_sound "exhaust"			"vehicle/engine/turtoise_up"	}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy"	}
	}
	("burn_by_engine" args 0.3)
}
{"m4a3m tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/m4a2"  }
		{link_sound "engine"			"vehicle/engine/m4a2"		}
		{link_sound "engine_end"		"vehicle/engine/m4a2_end"	}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"	}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy"	}
	}
	("burn_by_engine" args 0.3)
}
(define "m4_sound"
	{on "add_movement_sound" overload
		{link_sound "move"					"vehicle/tracks/m4"			}
		{link_sound "engine"				"vehicle/engine/m4"			}
		{link_sound "engine_end"			"vehicle/engine/m4_end"		}
		{link_sound "exhaust"				"vehicle/engine/m4a2_up"		}
		{link_sound "rotate_turret"     	"vehicle/turret/sherman"   	}
	}
)
{"m4a1 tank"
	("m4_sound")
	("burn_by_engine" args 0.3)
}
{"m4a1_eng tank"
	("m4_sound")
	("burn_by_engine" args 0.3)
}
{"m4_105 tank"
	("m4_sound")
	("burn_by_engine" args 0.3)
}
{"m4a3c tank"
	("m4_sound")
	("burn_by_engine" args 0.3)
}
{"m4a3e2 tank"
	("m4_sound")
	("burn_by_engine" args 0.3)
}
{"m4a3dd tank"
	("m4_sound")
	("burn_by_engine" args 0.3)
}
{"m4a2 tank"
	("m4_sound")
	("burn_by_engine" args 0.3)
}
{"m36 tank"
	("m4_sound")
	("burn_by_engine" args 0.3)
}
{"m4a3vc tank"
	{on "add_movement_sound" overload
		{link_sound "move"					"vehicle/tracks/m4a2"		}
		{link_sound "engine"				"vehicle/engine/m4"		}
		{link_sound "engine_end"			"vehicle/engine/m4_end"	}
		{link_sound "exhaust"				"vehicle/engine/m4a2_up"	}
		{link_sound "rotate_turret" 	    "vehicle/turret/sherman"	}
	}
	("burn_by_engine" args 0.3)
}
{"lvt4 tank"
	("m4_sound")
	("burn_by_engine" args 0.3)
}
(define "m7_sound"
	{on "add_movement_sound" overload
		{link_sound "move"					"vehicle/tracks/m7"		}
		{link_sound "engine"				"vehicle/engine/m7"		}
		{link_sound "engine_end"			"vehicle/engine/m7_end"	}
		{link_sound "exhaust"				"vehicle/engine/m4a2_up"	}
		{link_sound "rotate_turret" 	    "vehicle/turret/sherman"	}
	}
)
{"m7 tank"
	("m7_sound")
	("burn_by_engine" args 0.3)
}
{"m19 tank"
	("m7_sound")
	("burn_by_engine" args 0.3)
}
{"m10wolverine tank"
	("m7_sound")
	("burn_by_engine" args 0.3)
}
{"m10achilles tank"
	{on "add_movement_sound" overload
		{link_sound "move"					"vehicle/tracks/m4a2"		}
		{link_sound "engine"				"vehicle/engine/m4"		}
		{link_sound "engine_end"			"vehicle/engine/m7_end"	}
		{link_sound "exhaust"				"vehicle/engine/m4a2_up"	}
		{link_sound "rotate_turret" 	    "vehicle/turret/sherman"	}
	}
	("burn_by_engine" args 0.3)
}
{"jugdpanther tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/jugdpanther"  		}
		{link_sound "engine"			"vehicle/engine/jugdpanther"		}
		{link_sound "engine_end"		"vehicle/engine/jugdpanther_end"	}
		{link_sound "exhaust"			"vehicle/engine/jugdpanther_up" 	}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy1"	}
	}
	("burn_by_engine" args 0.3)
}
{"jagdpanther tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/jugdpanther"  		}
		{link_sound "engine"			"vehicle/engine/jugdpanther"		}
		{link_sound "engine_end"		"vehicle/engine/jugdpanther_end"	}
		{link_sound "exhaust"			"vehicle/engine/jugdpanther_up" 	}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy1"	}
	}
	("burn_by_engine" args 0.3)
}
(define "pz6_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/pz6"	}
		{link_sound "engine"			"vehicle/engine/pz6"		}
		{link_sound "engine_end"		"vehicle/engine/pz6_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pz6"	}
		{link_sound "exhaust"			"vehicle/engine/pz6_up"	}
	}
)
{"pz6 tank"
	("pz6_sound")
	("burn_by_engine" args 0.3)
}
{"pz6b tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/jugdpanther"	}
		{link_sound "engine"			"vehicle/engine/jagdtiger"		}
		{link_sound "engine_end"		"vehicle/engine/jagdtiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy2"	}
		{link_sound "exhaust"			"vehicle/engine/pz6_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"pz6e tank"
	("pz6_sound")
	("burn_by_engine" args 0.3)
}
{"pz6bh tank"
	("pz6_sound")
	("burn_by_engine" args 0.3)
}
{"elefant tank"
	("pz6_sound")
	("burn_by_engine" args 0.3)
}
{"jagdtiger tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/jugdpanther"	}
		{link_sound "engine"			"vehicle/engine/jagdtiger"		}
		{link_sound "engine_end"		"vehicle/engine/jagdtiger_end"	}
		{link_sound "exhaust"			"vehicle/engine/pz6_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"hetzer tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/hetzer"	}
		{link_sound "engine"			"vehicle/engine/hetzer"		}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"	}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"sdkfz223 tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"wheels.move"			}
		{link_sound "move_end"		"wheels.move_end"		}
		{link_sound "engine"		"engine.car"			}
		{link_sound "engine_end"	"engine.car_end"		}
		{link_sound "exhaust"		"engine.car_up"			}
	}
	("burn_by_engine" args 0.3)
}
{"sdkfz222 tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"wheels.move"			}
		{link_sound "move_end"		"wheels.move_end"		}
		{link_sound "engine"		"engine.car"			}
		{link_sound "engine_end"	"engine.car_end"		}
		{link_sound "exhaust"		"engine.car_up"			}
	}
	("burn_by_engine" args 0.3)
}
{"ba64 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/wheels"	}
		{link_sound "engine"			"vehicle/engine/ba11"		}
		{link_sound "engine_end"		"vehicle/engine/ba11_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine/ba11_up"	}
	}
	("burn_by_engine" args 0.2)
}
{"lancia_iz tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/wheels"	}
		{link_sound "engine"			"vehicle/engine/ba11"		}
		{link_sound "engine_end"		"vehicle/engine/ba11_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine/ba11_up"	}
	}
}
{"pz2l tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/pz2"	}
		{link_sound "engine"			"vehicle/engine/pz2"		}
		{link_sound "engine_end"		"vehicle/engine/pz2_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine/pz2_up" 	}
	}
	("burn_by_engine" args 0.3)
}
(define "pz3_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/pz3"	}
		{link_sound "engine"			"vehicle/engine/pz3"		}
		{link_sound "engine_end"		"vehicle/engine/pz3_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pz3"	}
		{link_sound "exhaust"			"vehicle/engine/pz3_up"	}
	}
)
{"pz3g tank"
	("pz3_sound")
	("burn_by_engine" args 0.3)
}
{"pz3f tank"
	("pz3_sound")
	("burn_by_engine" args 0.3)
}
{"pz3 tank"
	("pz3_sound")
	("burn_by_engine" args 0.3)
}
{"pz3m tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/pz3"	}
		{link_sound "engine"			"vehicle/engine/pz3"		}
		{link_sound "engine_end"		"vehicle/engine/pz3_end"	}
		{link_sound "exhaust"			"vehicle/engine/pz3_up" 	}
	}
	("burn_by_engine" args 0.3)
}
(define "pz4_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/pz4"	}
		{link_sound "engine"			"vehicle/engine/pz4"		}
		{link_sound "engine_end"		"vehicle/engine/pz4_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy1"	}
		{link_sound "exhaust"			"vehicle/engine/pz4_up"	  	}
	}
)
{"ger_trailer tank"  
	("pz3_sound")
	("burn_by_engine" args 0.3)
}
{"pz4d tank"  
	("pz4_sound")
	("burn_by_engine" args 0.3)
}
{"welberwind tank"  
	("pz4_sound")
	("burn_by_engine" args 0.3)
}
{"pz4g tank"
	("pz4_sound")
	("burn_by_engine" args 0.3)
}
{"pz4h tank"
	("pz4_sound")
	("burn_by_engine" args 0.3)
}
{"pz4e tank"
	("pz4_sound")
	("burn_by_engine" args 0.3)
}
{"stug4g tank"
	("pz4_sound")
	("burn_by_engine" args 0.3)
}
{"stuh42 tank"
	("pz4_sound")
	("burn_by_engine" args 0.3)
}
{"hummel tank"
	("pz4_sound")
	("burn_by_engine" args 0.3)
}
{"nashorn tank"
	("pz4_sound")
	("burn_by_engine" args 0.3)
}
(define "sdkfz_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/wheels"			}
		{link_sound "engine"			"vehicle/engine/sdkfz232"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz232_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"			}
		{link_sound "exhaust"			"vehicle/engine/sdkfz232_up"	}
	}
)
{"sdkfz222 tank"
	("sdkfz_sound")
	("burn_by_engine" args 0.3)
}
{"sdkfz223 tank"
	("sdkfz_sound")
	("burn_by_engine" args 0.3)
}
(define "sdkfz234_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz234"		}
		{link_sound "engine"			"vehicle/engine/sdkfz234"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz234_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"			}
		{link_sound "exhaust"			"vehicle/engine/sdkfz234_up"	}
	}
)
{"sdkfz234 tank"
	("sdkfz234_sound")
	("burn_by_engine" args 0.3)
}
{"ba11 tank"
	("sdkfz234_sound")
	("burn_by_engine" args 0.3)
}
{"sdkfz232 tank"
	("sdkfz234_sound")
	("burn_by_engine" args 0.3)
}
{"autoblinda_fiat_611 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/sdkfz234"			}
		{link_sound "engine"			"vehicle/engine/sdkfz234"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz234_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/medium"			}
		{link_sound "exhaust"			"vehicle/engine/sdkfz234_up"	}
	}
	("burn_by_engine" args 0.3)
}
(define "m8grayhound_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/m8grayhound"	}
		{link_sound "engine"			"vehicle/engine/m8grayhound"		}
		{link_sound "engine_end"		"vehicle/engine/m8grayhound_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine/m8grayhound_up"	}
	}
)
{"m8grayhound tank"
	("m8grayhound_sound")
	("burn_by_engine" args 0.3)
}
{"ab41 tank"
	("m8grayhound_sound")
	("burn_by_engine" args 0.3)
}
{"mk2daimler tank"
	("m8grayhound_sound")
	("burn_by_engine" args 0.3)
}
{"m20 tank"
	("m8grayhound_sound")
	("burn_by_engine" args 0.3)
}
{"daimler tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/wheels"			}
		{link_sound "engine"			"vehicle/engine/sdkfz234"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz234_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/medium"			}
		{link_sound "exhaust"			"vehicle/engine/sdkfz234_up"	}
	}
	("burn_by_engine" args 0.3)
}
(define "hanomag_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz251"	}
		{link_sound "engine"			"vehicle/engine/sdkfz251"	}
		{link_sound "engine_end"		"vehicle/engine/sdkfz251_end"}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"		}
		{link_sound "exhaust"			"vehicle/engine/sdkfz251_up"	}
	}
)
{"sdkfz4 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz10"	 }
		{link_sound "engine"			"vehicle/engine/sdkfz250"	 }
		{link_sound "engine_end"		"vehicle/engine/sdkfz250_end"}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"		 }
		{link_sound "exhaust"			"vehicle/engine/sdkfz250_up" }
	}
	("burn_by_engine" args 0.3)
}
{"SdKfz251_1 tank"
	("hanomag_sound")
	("burn_by_engine" args 0.3)
}
{"SdKfz251 tank"
	("hanomag_sound")
	("burn_by_engine" args 0.3)
}
{"SdKfz251_10 tank"
	("hanomag_sound")
	("burn_by_engine" args 0.3)
}
{"SdKfz251_10c tank"
	("hanomag_sound")
	{on "gunner_hatch_open" overload}
	("burn_by_engine" args 0.3)
}
{"SdKfz251m tank"
	("hanomag_sound")
	{on "gunner_hatch_open" overload}
	("burn_by_engine" args 0.3)
}
{"sdkfz7_1 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz10"	}
		{link_sound "engine"			"vehicle/engine/blitz"	}
		{link_sound "engine_end"		"vehicle/engine/blitz_end"}
		{link_sound "rotate_turret" 	"vehicle/turret/flak38"		}
		{link_sound "exhaust"			"vehicle/engine/blitz_up"	}
	}
	("burn_by_engine" args 0.3)
}
(define "m3_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/m3a1"	}
		{link_sound "engine"			"vehicle/engine/m3a1"		}
		{link_sound "engine_end"		"vehicle/engine/m3a1_end"	}
;		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "exhaust"			"vehicle/engine/m3a1_up"	}
	}
)
{"m3 tank"
	("m3_sound")
	("burn_by_engine" args 0.3)
}
{"m2 tank"
	("m3_sound")
	("burn_by_engine" args 0.3)
}
{"m2_ally tank"
	("m3_sound")
	("burn_by_engine" args 0.3)
}
{"m16 tank"
	("m3_sound")
	("burn_by_engine" args 0.3)
}
{"mkdaimler tank"
	("m3_sound")
	("burn_by_engine" args 0.3)
}
{"centurion tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/heavy"	}
	}
	("burn_by_engine" args 0.3)
}
{"m18 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/medium2"	}
	}
	("burn_by_engine" args 0.3)
}
{"m24 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/sherman"	}
	}
	("burn_by_engine" args 0.3)
}
{"achilles tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/medium"	}
	}
	("burn_by_engine" args 0.3)
}
{"archer tank"
	("burn_by_engine" args 0.3)
}
{"m5a1 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/sherman"	}
	}
	("burn_by_engine" args 0.3)
}
{"m4a2_76w tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/sherman"	}
	}
	("burn_by_engine" args 0.3)
}
{"zis30 tank"
	("burn_by_engine" args 0.3)
}
{"t20 tank"
	("burn_by_engine" args 0.3)
}
{"chi-ri tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/heavy2"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/heavy"	}
		{link_sound "engine_end"		"vehicle/engine/heavy_end"}
		{link_sound "exhaust"			"vehicle/engine/heavy_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"chi-ha120 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"chi-ha47 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"chi-ha57 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"ha-go tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "move"				"vehicle/tracks/pz1"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/mb_end"}
		{link_sound "exhaust"			"vehicle/engine/mb_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"ke-nu tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "move"				"vehicle/tracks/m26"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/mb_end"}
		{link_sound "exhaust"			"vehicle/engine/mb_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"chi-he tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/medium"	}
		{link_sound "move"				"vehicle/tracks/m26"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/tank_end"}
		{link_sound "exhaust"			"vehicle/engine/tank_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"chi-nu tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/medium1"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/mb_end"}
		{link_sound "exhaust"			"vehicle/engine/mb_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"chi-to tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/medium1"	}
		{link_sound "move"				"vehicle/tracks/mk7"	}
		{link_sound "engine"			"vehicle/engine/mk7"	}
		{link_sound "engine_end"		"vehicle/engine/mk7_end"}
		{link_sound "exhaust"			"vehicle/engine/mk7_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"ho-i tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/medium3"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/t34"	}
		{link_sound "engine_end"		"vehicle/engine/t34_end"}
		{link_sound "exhaust"			"vehicle/engine/t34_up"	}
	}
	("burn_by_engine" args 0.3)
}