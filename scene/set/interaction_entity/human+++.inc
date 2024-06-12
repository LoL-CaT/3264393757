(include "flamer.inc")

{"human"
	{inflammation_time 4.25}
	{on spawn
		{add_view	"cigarettesmoke"		"smoke"		"head"}
		{add_view	"drops_water_small2"	"on_water"	"foot3r"}
		{add_view	"drops_water_small2"	"on_water"	"foot3l"}
		{add_view	"drops_water_small3"	"swim"		"foot3r"}
		{add_view	"drops_water_small3"	"swim"		"foot3l"}
		{add_view	"drops_water_small3"	"swim"		"hand2r"}
		{add_view	"drops_water_small3"	"swim"		"hand2l"}
		{add_view	"wash_human_small"		"swim_move"	"head"}
		{add_view	"drops_water_small2"	"on_puddle"	"foot3r"}
		{add_view	"drops_water_small2"	"on_puddle"	"foot3l"}
		{add_view	"drops_water_small2"	"die_in_swamp"	"foot3r"}
		{add_view	"drops_water_small2"	"die_in_swamp"	"foot3l"}
		
		{add_view	"healing" 				"healing" "head"}
		{add_view	"attention" 				"attention" "head"}
		
;		{link_sound "move_ground" "human/move/ground"}
;		{link_sound "move_road"   "human/move/road"}
;		{link_sound "move_sand"   "human/move/sand"}
;		{link_sound "move_snow"   "human/move/snow"}
;		{link_sound "move_grass"  "human/move/grass"}

;		{link_sound "swim" "human/move/swim"}

		{link_sound "repair" "vehicle/repair"}
		{link_sound "barricade" "fortification/install/human_sandbags_install"}
		{link_sound "barbwire" "fortification/install/barber_wire_install"}
		{link_sound "camouflage" "fortification/install/camouflage_bushes_install"}
		{link_sound "mine" "weapon/mining"}
		{link_sound "hedgehog" "fortification/antitank_hedgehog_disassemble"}
		{link_sound "put_dynamite" "weapon/mine_activation"}
		{link_sound "detonation" "weapon/detonation_click"}
		{link_sound "knife_stub" "weapon/melee/knife_stub"}
		{link_sound "shovel_stub" "weapon/melee/shovel_stub"}
		{link_sound "mine_detected" "weapon/demining"}
;		{link_sound "pose_changed" "human/pose_change"}
;		{link_sound "heal" "human/healing"}
		{link_sound "cut_wire" "human/barber_wire_cut"}
		{link_sound "burn" "detonation/matches_install"}
;		{link_sound "trench" "fortification/build/trench_digging"}
		
		{link_sound "pour" "vehicle/refueling"}
			
		{if able "burning"
			{call "add_burn_fx"}
			{view start "burn_fire"}
		}
		{delay 0.1
			{if breed_mask "*/arty_spotter" "*/hunter_ai_overwatch" {able inventory_operation 0}}
			{if breed_mask "*sniper*" {tags add "sniper"}}	;for special minimap icon		
			{if not tagged "disable_change_texmod"
				{if breed_mask "arena_mp/rus/*"
					{if			rand 0.2	{tex_mod ""}
						else	rand 0.25	{tex_mod "1"}
						else	rand 0.3333	{tex_mod "2"}
						else	rand 0.5	{tex_mod "3"}
						else				{tex_mod "4"}
					}
				else breed_mask "arena_mp/usa/*"
					{if			rand 0.166	{tex_mod ""}
						else	rand 0.2	{tex_mod "1"}
						else	rand 0.25	{tex_mod "2"}
						else	rand 0.33	{tex_mod "3"}
						else	rand 0.5	{tex_mod "4"}
						else				{tex_mod "5"}
					}
				else breed_mask "arena_mp/ger/*"
					{if breed_mask "*/arty_spotter" "*/scout" "*/saboteur*" "*/sniper_elite"
						{if			rand 0.5	{tex_mod "saboteur"}
						else					{call "apply_tex_mod_ger"}
						}
					else						{call "apply_tex_mod_ger"}
					}
				}
				{if game_param 	"biom" "snow"
					{if		rand 0.2		{tex_mod ""}
					else 	rand 0.25		{tex_mod "wear1"}
					else 	rand 0.33		{tex_mod "wear2"}
					else 	rand 0.5		{tex_mod "wear3"}
					else					{tex_mod "wear4"}
					}
				}
			}
		}
		{call "talk_scanner"}		
	}
	{on "apply_tex_mod_ger"
		{if			rand 0.2	{tex_mod ""}
			else	rand 0.25	{tex_mod "1"}
			else	rand 0.3333	{tex_mod "2"}
			else	rand 0.5	{tex_mod "3"}
			else				{tex_mod "4"}
		}
	}
	{on "cannot_move_low_morale"
		{talk "drop_morale"}
	}
	{on "talk_scanner"
		{##if ai_squad
			{if morale 0 30
				{delay 4 3 "drop_morale"
					{talk "drop_morale" {audience all}}
					;{con "--==============DROP MORALE--"}
				}
			}
		}
		{if attacking_weapon "rocketlauncher"
			{talk "shot_from_a_bazooka" {audience all}}			
		}		
		{if attacking_weapon "sniper"
			{talk "shot_from_a_sniper_rifle" {audience all}}
			{con "--==============Sniper shot--"}			
		}
;		{if fsm_tags "throw" and item_in_hand "grenade"
;			{talk "throwing_a_grenade" {audience all}}			
;		}		
		{if health_percent 0.1 and attacked
			{talk "drop_morale" {audience all}}				
		}		
		{##if suppressed 2 and attacked
			{talk "things_look_blue" {audience all}}			
		}		
		{if attacking_weapon or attacked
			{talk "in_action" {audience all}}		
		}				
		{delay 10 "talk_scanner"
			{call "talk_scanner"}
		}
	}
	{on "talk_scanner_off"
		{kill_delay "drop_morale"}
		{kill_delay "talk_scanner"}
	}
	{on "throw_off_by_collision_with_vehicle_die"
		{if terrain_fx "water" or terrain_fx "shallow_water"
			{spawn "bloodsparks_drops_water" "body"}
		else
			{spawn "bloodsparks_drops" "body"}
		}
		{throw_off up 1.3 0.5 dir 5.5 2 force die}
	}
	{on contact
		{if not impregnable
			{kill_flags reset}
			{volumes disable contact}
			{delay 2
				{volumes enable contact}
			}
			{if effector "vehicle"
				{call "crush"}
				{if not dead
					{if relation "enemy"
						{if not user_control	;AI
							{call "throw_off_by_collision_with_vehicle_die"}
						 else			;USER
							{call "throw_off_by_collision_with_vehicle_die"}
						}
					}
				else
					{spawn "bloodsparks_small"}
				}
			else effector "instant_fire"
				{able "burning" 1}
				{health_damage_count 100
					{effects "" "hit" "hit" "die" "die"}
				}
				;{able "burning" 1}
            	{able select 0}	
            	{call "add_burn_fx"}
                {view start "burn_fire"}
            	{delay 3
            	    {able "burning" 0}
            	    {able select 1}	
                    {view stop "burn_fire"}
            	}
			else effector "aoe_heal_max"
				{call "heal_process"}				
			else effector "aoe_heal_med"
				{call "heal_process"}
			else effector "aoe_heal_min"
				{call "heal_process"}				
			else effector "knife"
				{with_effector
					{if not linked and tagged "throwed"
						{with_effector
							{if contact_velocity 5
								{health_damage_count 500
									{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
								}
								{if effector "sapper_shovel"
									{play_sound "shovel_stub"}
								else
									{play_sound "knife_stub"}
								}
							}
						}
					}
				}
			(define "health_damage"
				{health_damage_count %c
					{effects "" "hit" "damage" "die" "die"}
				}
  	        )
			else effector "axe"
				{if contact_velocity 5
  		        	("health_damage" c(500))
					{play_sound "knife_stub"}
  		        }
			(define "contact_part"
			else effector %e
				{if contact_velocity %v
					{if not linked
						("health_damage" c(%d))
					}
				}
  	        )
			("contact_part" e("building_part")	v(3)	ud(20)	d(120))
			("contact_part" e("big part")		v(3)	ud(20)	d(120))
			("contact_part" e("medium part")	v(6)	ud(10)	d(20))
			("contact_part" e("small part")		v(10)	ud(3)	d(10))
			else effector "chicken"
				("health_damage" c(4))
				{play_sound "knife_stub"}
			else effector "wire"
				{health_damage_count 20
					{effects "" "hit" "damage" "die" "die"}
				}
			else effector "flame_piece"
				{health_damage_count 15
					{effects "" "hit" "hit" "die" "die"}
				}
			else effector "fx_piece_flame"
				{able "burning" 1}
				{health_damage_count 201
					{effects "" "hit" "hit" "die" "die"}
				}
				;{able "burning" 1}
            	{able select 0}	
            	{call "add_burn_fx"}
                {view start "burn_fire"}
            	{delay 3
            	    {able "burning" 0}
            	    {able select 1}	
                    {view stop "burn_fire"}
            	}		
			}			
		}
	}
	{on "heal_process_max"
		{if health_percent 1 and not flag "bound_by_battle"
			{tags add "med_point_crew_max"}
			{kill_delay "heal_max"}
			{delay 3.1 "heal_max"
				{tags remove "med_point_crew_max"}
			}
		else
			{tags remove "med_point_crew_max"}
		}
	}
	{on "heal_process"
		{if health_percent 1 and not flag "bound_by_battle"
			{tags add "med_point_crew"}
			{kill_delay "heal"}
			{delay 3.1 "heal"
				{tags remove "med_point_crew"}
			}
		else
			{tags remove "med_point_crew"}
		}
	}
	{on "heal_process_min"
		{if health_percent 1 and not flag "bound_by_battle"
			{tags add "med_point_crew_min"}
			{kill_delay "heal_min"}
			{delay 3.1 "heal_min"
				{tags remove "med_point_crew_min"}
			}
		else
			{tags remove "med_point_crew_min"}
		}
	}	
	{on "bound_by_battle"
		{if not flag "bound_by_battle"
			{set "bound_by_battle" 1}	
			{tags remove "med_point_crew"}{tags remove "med_point_crew_min"}{tags remove "med_point_crew_max"}
		}
		{kill_delay "no_battle"}
		{delay 7.1 "no_battle"
			{set "bound_by_battle" 0}
		}		
	}
	(define "spawn_bloodsparks"
		{if linked_root "house"
			{if rand 0.08 {spawn %n}}
		else
			{spawn %n}
		}
	)
	{on bullet_hit
		{kill_flags reset}
		{call "detect_by_hit"}
		{call "bound_by_battle"}
		("spawn_bloodsparks" n("bloodsparks_small2"))		; to generate hit signal
		{if stuff "shell fg" or stuff "shell fr"
			;{bullet_detonate}
			{call "process_bullet_hit"}
		else stuff "bazooka"
			{bullet_detonate}
			{call "process_bullet_hit"}
		else stuff "bullet"
			{if volume_armored
				{bullet_detonate}
			}
			{call "process_bullet_hit"}
		else stuff "flaergun strike"
			("health_damage" c(5))
	        ("grenade_signal")			
		else stuff "smoke_gr"
			("health_damage" c(5))
			("grenade_smoke")				
		else
			{call "process_bullet_hit"}
			
		}
	}
	{on "detect_by_hit"
	    {if relation "enemy" and weapon "detect"			{detect 1}}
	}
	{on blow
		{if not name "knife"
			{start_sound "human/blow"}
		}
	}
	{on blow opponent
		{if name "knife"
			{health_damage_blow
				{effects "" "hit" "hit" "die_from_knife" "die_from_knife"}
			}
		else
			{if name "head"
				{spawn "bloodsparks_small" "head"}
			}
			{health_damage_blow
				{effects "" "hit" "hit" "die" "die"}
			}
		}
	}
	{on "blow_in_house"
		{start_sound "human/blow"}
	}
	{on "blow_in_house_opponent"
		{if name "head"
			{spawn "bloodsparks_small" "head"}
		}
	}
	{on "auto_withdraw_reason"
		{if breed_mask "*/*miner*" "*/engineer" "*/corpsman"
			{if auto_withdraw_reason "damage_any" or auto_withdraw_reason "damage_percent" and health_percent 0.7
				{withdraw}
			}
		}
	}
	{on "process_bullet_hit"
		{if hit_side front	{kill_flags front}
		else hit_side back	{kill_flags back}
		else				{kill_flags front back}
		}
		{if velocity 7		{kill_flags run}
		else velocity 0.1	{kill_flags go}
		}
		{kill_flags piercing}
		; weapon is not used in selection
		;{if	stuff "rifle"	{kill_flags rifle}}
		;{if	stuff "mgun"	{kill_flags mgun}}
		;{if	stuff "smg"	{kill_flags smg}}
		;{if	stuff "pistol"	{kill_flags pistol}}
		
		{icon_event "human_damage" 2.0}
		{if selected
			{with_effector
				{icon_event "damage_current_user" 2.0}
			}
		}
		{call "auto_withdraw_reason"}
		{##if ammo "hmgun" or ammo "ptr"
			{con "----health_damage_pierce_no_absorb----"}
		}
		{health_damage_pierce
			{effects	"hit-scream"
						"hit-light" "hit-heavy"
						"die" "hit-explosion"
						"throw-off" "throw-off-and-die"
			}
			{explosive_treshold 70}
			{table {30 1} {200 2.5} {500 3} {5000 5}}
			{movement_modifier						;фича, уменьшающая дамаг от стрейфа
				{"smg" 
					{0 ;дистанция до цели
						{0 1}{4 1} ; 1й аргумент скорость в м/с, 2й - множитель
					}
					{100
						{0 1}{4 0.8}
					}
					{300	
						{0 1}{4 0.5}
					}
				}
				{"pistol" 
					{0
						{0 1}{4 1}
					}
					{100
						{0 1}{4 0.8}
					}
					{300	
						{0 1}{4 0.5}
					}
				}
				{"rifle" 
					{0
						{0 1}{4 1}
					}
					{100
						{0 1}{4 0.8}
					}
					{300	
						{0 1}{4 0.5}
					}
				}
				{"mgun" 
					{0
						{0 1}{4 1}
					}
					{100
						{0 1}{4 0.8}
					}
					{300	
						{0 1}{4 0.5}
					}
				}				
			}			
		}
		{if volume "head"
			{if not volume_armored
				{if	stuff "sniper" {die}}
				{if	stuff "pistol"	{if rand 0.85 {call "die"} ("health_damage" c(35))}}
				{if	stuff "smg"	{if rand 0.85 {call "die"} ("health_damage" c(35))}}
				{if	stuff "mgun" {if rand 0.95 {call "die"} ("health_damage" c(35))}}
				{if	stuff "rifle" {if rand 0.9 {call "die"} ("health_damage" c(35))}}
			}
			{if rand 0.3
				{take_off "head"
					{impulse up 5 2 dir 7 3}
				}
			}
		}
		{if volume "body"
			{if not volume_armored
				{if	stuff "sniper" {die}}
				{if	stuff "pistol"	{if rand 0.5 {call "die"} ("health_damage" c(35))}}
				{if	stuff "smg"	{if rand 0.5 {call "die"} ("health_damage" c(35))}}
				{if	stuff "mgun" {if rand 0.75 {call "die"} ("health_damage" c(35))}}
				{if	stuff "rifle" {if rand 0.55 {call "die"} ("health_damage" c(35))}}			
			}
		}
		
	}
	{on "health_damage_blast"
		{set "dmg_blast" 1} ;for hit-heavy
		{icon_event "human_damage" 2.0}
		{call "bound_by_battle"}
		{if can_be_damaged and not linked
			{if stuff "mine antipersonnel" or stuff "mine antitank"
				{talk "human_mines" {audience ally}}
			else stuff "dynamite"
				{talk "explosives" {audience ally}}
				;{self_damage}
			}
		}
		{call "auto_withdraw_reason"}
		(define "a_health_damage_blast"
			{effects	"hit-scream"
					"hit-light" "hit-heavy"
					"die" "hit-explosion"
					"throw-off" "throw-off-and-die"
			}
			{table {0.5 0.25} {2 0.4} {10 1} {50 2}}
			{damage_table {0.1 10} {0.15 15} {0.2 20} {0.3 30} {0.35 35} {0.75 75} {1.5 150} {3 300} {5 500}}
		)
		{if stuff "dynamite" or stuff "grenade"
			{health_damage_blast
				{self_damage}
				("a_health_damage_blast")
			}
		else
			{health_damage_blast
				("a_health_damage_blast")
			}
                }
	}
	{on blast_hit
		{call "health_damage_blast"}
	}
	{on fragments_hit overload
		{##if min_energy 0.8
			("health_damage" c(100))
		}
		{if stuff "kamikaze"
			{call "die"}
			("health_damage" c(250))
			;{con "kamikaze"}
		}
		
		{kill_flags reset}
		{if hit_side front	{kill_flags front}
		else hit_side back	{kill_flags back}
		else			{kill_flags front back}
		}
		{kill_flags blast}
		{call "health_damage_blast"}
	}
	{on "die_throw_high"
		{set "die_after_throw" 1}
		{spawn "bloodsparks_small"}
		{call "die_scream"}
		{call "throw_high"}
	}
	
	{on "hit-scream"
		{if not flag "talk"
			{set "talk" 1}
			{talk "injuring" {audience all} {ambient_for_selection 0}}
			{delay 10 2
				{set "talk" 0}
			}
		}
	}
	
	{on "talk_in_action"
		{if not flag "talk"
			{set "talk" 1}
			{talk "in_action" {audience all} {ambient_for_selection 0}}
			{delay 10 2
				{set "talk" 0}
			}
		}
	}	

	{on "hit-light"
		("spawn_bloodsparks" n("bloodsparks_small"))
	}
	
	{on "hit-heavy"
		{if not flag "dmg_blast"
			{if stuff "zenite" or stuff "bullet20"
				("spawn_bloodsparks" n("bloodsparks_zenite"))
			else stuff "shell" and not flag "die_sound" and health_percent 0.0
				("spawn_bloodsparks" n("bloodsparks_shell"))
			else
				("spawn_bloodsparks" n("bloodsparks_big"))
			}
		else
			{set "dmg_blast 0"}
			{if ammo "zenite" or ammo "shell small"
				{spawn "bloodsparks_zenite"}
			else not flag "die_sound" and health_percent 0.0
				{if ammo "shell" or stuff "mine antipersonnel"
					("spawn_bloodsparks" n("bloodsparks_shell"))
				}
			else
				{spawn "bloodsparks_big"}
			}
		}	
	}
	{on "hit-explosion"
		{if tagged "no_explosion"
			{call "die"}
		else
			{call "die_scream"}
			{call "explosion"}
		}
	}
	{on "throw-off"
		{set "die_after_throw" 0}
		{if not in_fortification "trench" and not ammo "not_throw"
			{call "throw_high"}
		}
	}
	{on "throw-off-and-die"
		{set "die_after_throw" 1}
		{call "die_scream"}
		{if weapon "sniper"
			{icon_event "killed_by_sniper" 2.0}
			{talk_nearest_ally "killed_by_sniper" 40}
		}
		{if in_fortification "trench"
			{if min_energy 1
				{if ammo "size3" or ammo "size4"
					{call "throw_high"}
				else
					{call "die"}
				}
			else
				{call "die"}
			}
		else
			;{if ammo "shell small" {spawn "bloodsparks_shell"}}
			{call "throw_high"}
		}
	}
	
	{on "hit"
		{call "hit-scream"}
	}
	{on "damage"
		{if not able "burning" and not flag "burning" and not burned {spawn "bloodsparks_small"}}
		{call "hit"}
	}

	{on "throw_high"
		{if senseless
			{if not dead
				{if not user_control
					{call "die"}
				}
			}
		else
			{if not dead
				{if linked "vehicle"
					{if flag "die_after_throw"
						{if linked "cannon"
							{call "die"}							
						else
							{throw_off up 1.3 0.5 dir 3.5 1 forward 2 turn 0 180 die force}
						}
;					else
;						{throw_off up 1.3 0.5 dir 5.5 2 forward 4 turn 0 180 force}
					}
				else
					{if flag "die_after_throw"
						{throw_off up 2 0.8 dir 2.5 0.5 forward 0 0 die}
					else
						{if not linked "windowed"
							{throw_off up 4 0.8 dir 3.5 0.5 forward 0 0}
						}
					}
				}
			else
				{call "explosion"}
			}
		}
	}
	{on "throw_off_end"
		{call "knock_down"}
	}
	{on "throw_off_end_stumble"
		{call "stumble"}
	}
	{on "throw_off_end_die"
		{call "die"}
	}
	{on "throw_off_from_tower"
		{throw_off up 1 forward 2 die force}
	}
	{on "throw_off_from_ladder"
		{throw_off up 1 forward -2 die force}
	}
	{on "throw_off_from_ship"
		{throw_off up 4 dir 3 1 die force}
	}
	{on "throw_off_from_vehicle"
		{if user_control
			{throw_off up 1.3 0.5 dir 3.5 1 forward 2 turn 0 180 force}
		else
			{throw_off up 1.3 0.5 dir 3 1 forward 2 turn 0 180 rnd_die 0.7 force}
		}
	}
	{on "throw_off_from_vehicle_die"
		{if user_control
			{throw_off up 1.3 0.5 dir 3.5 1 forward 2 turn 0 180 die force}
		else
			{throw_off up 1.3 0.5 dir 3 1 forward 2 turn 0 180 die force}
		}
	}
	{on "throw_off_from_house_die"
		{throw_off up 1.3 0.5 dir 5 1 forward 1 turn 0 60 die force}
	}
	{on "linker_simulation"
		{if effector "airborne"
;		 else effector "cannon"
;			{throw_off up 2.25 0.75 forward 2.25 0.75 turn 0 180 force}
		 else altitude 3
			{throw_off up 1 forward 2 die force}
		}
	}

	{on "knock_down"
		{if not water_level -0.1
			{knockdown 12 3}
		}
	}
	{on "stumble"
		{if not water_level -0.1
			{knockdown 0.5 0}
		}
	}

	{on "die"
		{if linked_root "house"
			{reserve_structure_place 5}
		}
		{if weapon "sniper"
			{icon_event "killed_by_sniper" 2.0}
		}
		{hide_gunners 1.5}
		{if not dead
			{if not able "burning" and not flag "burning" and not burned {spawn "bloodsparks_small"}}
			{delay 1.2 0.2
				{if not able "burning" and not flag "burning" and not burned
					{if terrain_fx "water" or terrain_fx "shallow_water"
						{spawn "bloodsparks_drops_water" "body"}
					else
						{spawn "bloodsparks_drops" "body"}
					}
				}
			}
			{if linked
				{if linked "shipflak"
					{call "throw_off_from_ship"}
				else linked "doublecolt"
					{call "throw_off_from_ship"}
				else linked "car"
					{if place "driver"
						{throw_off up 1.6 forward 2 turn -90 die force rotate_to_dir}
					else place "commander"
						{throw_off up 1.6 forward 2 turn +90 die force rotate_to_dir}
					else
						{call "die_with_blood"}
					}
				else altitude 2
					{if boarding
						{call "throw_off_from_ladder"}
					else
						{call "throw_off_from_tower"}
					}
				else linked_root "radar_mount"
					{call "throw_off_from_house_die"}		
				else linked "cannon"
					{call "die_with_blood"}
				else linked "trench"
					{if cover_type "snipe_cover"
						; we have special die animations
						{call "die_with_blood"} 
					else
						{call "throw_off_from_vehicle_die"}
					}
				else linked_root "house"
					{call "throw_off_from_house_die"}
				else
					{call "throw_off_from_vehicle_die"}
				}
			else
				{call "die_with_blood"}
			}
		}
		{drop_item "mine_fuze"}
	}
	{on "die_with_blood"
		{if not senseless
			{if not able "burning" and not flag "burning" and not burned {spawn "blood"}}
		}
		{call "die_without_blood"}
	}
	{on "die_without_blood"
;		{con "die"}
		{view pause "swim"}
		{call "die_scream"}
		{if not kill_flags blast
			{kill_flags piercing}
		}
		{die}
;		{able collect 1}
		{volumes disable bullet}
		{delay 3
			{volumes enable contact}
		}
;		{delay 30 {delete}}
	}
	{on "die_scream"
		{if not flag "die_sound"
			{set "die_sound" 1}
			{call "talk_scanner_off"}
			{talk "death_cry" {audience all} {ambient_for_selection 0}}
;			{signal mandie 5}
;			{if flag "die_from_knife"
;				{start_sound "human/die/from_knife"}
;			else
;				{start_sound "human/die"}
;			}
		}
	}
	{on "die_from_knife"
		{set "die_from_knife" 1}
		{call "die"}
	}

;	{on "die_contused"
;		{able select 0}
;		{delay 2 0.5 "die_contused"
;			{if inactive
;				{call "die_contused"}
;			else
;				{call "die"}
;			}
;		}
;	}

	{on "sensible"
		{volumes enable bullet}
		{set "die_sound" 0}
	}

	{on ground_hit
		{spawn "blood"}
	}

	(define "piece_explosion"
		{spawn %0 %1
			{impulse	up 1 0.5 dir 8 4
						cx 0 12 cy 0 12
						fx 0 60 fy 0 60 fz 80 40
			}
		}
	)
	(define "piece_crush"
		{spawn %0 %1
			{impulse	up 0.1 0.1
						fx 0 7 fy 0 7 fz 0 7
			}
			{add_view "blood_tail01" "tail" "root"}
			{view start "tail"}
		}
	)
	(define "spawn_pieces"
		;head
		{if rand 0.75	(%0 args "#tete01" "head")}
		
		;torse
		{if rand 0.9	(%0 args "#torse01" "body")}
		
		;left hand
		{if rand 0.33	(%0 args "#bras01" "hand2l")
		else rand 0.5	(%0 args "#main01" "hand2l")}
		
		;right hand
		{if rand 0.33	(%0 args "#bras01" "hand2r")
		else rand 0.5	(%0 args "#main01" "hand2r")}
		
		;left foot
		{if rand 0.33	(%0 args "#membre01" "foot1l")
		else rand 0.5	(%0 args "#membre02" "foot2l")}
		
		;right foot
		{if rand 0.33	(%0 args "#membre01" "foot1r")
		else rand 0.5	(%0 args "#membre02" "foot2r")}
		
		;tripe
						(%0 args "#tripe01" "body")
						(%0 args "#tripe02" "body")
						(%0 args "#tripe03" "body")
						(%0 args "#tripe04" "body")
	)

	{on "explosion"
		{if personage
			{call "die"}
		else
;			{spawn "bloodsparks_big"}
;			{spawn "bloodsparks_shell"}
;			("spawn_pieces" args "piece_explosion")
			{call "delete"}
		}
	}
	{on "crush"
		{if can_be_damaged and flag "die_sound"
			{if terrain_fx "water" or terrain_fx "shallow_water"
				{spawn "bloodsparks_drops_water" "body"}
			else
				{spawn "bloodsparks_drops"}
			}
			("spawn_pieces" args "piece_crush")
			{call "delete"}
		}
	}
	{on "delete"
		{##if not dead
			{stat_notify die}
		}
		{delete}
	}
	{on "burn_volume"
		{if volume "body"
			{call "_burn"}
		}
	}
	{on "_burn"
		{if not burned
			{able "burning" 1}
			{able select 0}			
			(define "try_get_off"
				{delay %0 0.5
					{get_off}
				}
			)
			("try_get_off" args 1.0)
			("try_get_off" args 2.0)
			("try_get_off" args 3.0)
			("try_get_off" args 4.0)
			("try_get_off" args 5.0)
			{tex_morph "burned" 10}
			{call "add_burn_fx"}
			{view start "burn_fire"}				
			{delay_effect 0.3 0.1 "burn_scream"}
			{delay 0.5 1 "burn_die"
				{able "burning" 0}			
				{kill_flags reset}
				{kill_flags piercing}
				("health_damage" c(150))
				{if not dead
					{call "die"}
				}
				{view stop "burn_fire"}
				{if terrain_fx "puddle"
					{call "stop_burn"}
				else
					{add_view "smoke_dead_small1" "burn_fire_b" 	"body"}
					{add_view "smoke_dead_small1" "burn_fire_hl"	"hand1l"}
					{add_view "smoke_dead_small1" "burn_fire_hr"	"hand1r"}
					{add_view "smoke_dead_small1" "burn_fire_fl"	"foot2l"}
					{add_view "smoke_dead_small1" "burn_fire_fr"	"foot2r"}
					{view start "burn_fire_b"}
					{view start "burn_fire_hl"}
					{view start "burn_fire_hr"}
					{view start "burn_fire_fl"}
					{view start "burn_fire_fr"}
					{delay 7.5 1.5	
						{view stop "burn_fire_b"}
					}
					{delay 3.5 2.0	
						{view stop "burn_fire_hl"}
					}
					{delay 3.8 1.5	
						{view stop "burn_fire_hr"}
					}
					{delay 4.3 1.5	
						{view stop "burn_fire_fl"}
					}
					{delay 4.5 1.5	
						{view stop "burn_fire_fr"}
					}
				}
			}
			{delay 3
				{able "burning" 0}
				{able select 1}
			}
			{burn time 17} ; total burn time
		}
	}
	{on "add_burn_fx"
		{add_view "smoke_dead_small" "burn_fire"	"body"}
		{add_view "smoke_dead_small" "burn_fire"	"hand1l"}
		{add_view "smoke_dead_small" "burn_fire"	"hand1r"}
;		{add_view "smoke_dead_small" "burn_fire"	"hand2l"}
;		{add_view "smoke_dead_small" "burn_fire"	"hand2r"}
		{add_view "smoke_dead_small" "burn_fire"	"foot2l"}
		{add_view "smoke_dead_small" "burn_fire"	"foot2r"}
	}
	{on "burn_scream"
		{if not dead
			{if not senseless
				{if not flag "quench"
					{talk "death_cry" {audience all} {ambient_for_selection 0}}
;					{start_sound "human/die" }
					{delay_effect 1.2 0.5 "burn_scream"}
				else
					{kill_delay "burn_die"}
					{view stop "burn_fire"}
					{set "quench" 0}
					{able "burning" 0}
				}
			}
		}
	}
	{on "smoke"
		{smoke}
	}
	{on "smoking"
;		{con "smoke start"}
		{view start "smoke"}
		{delay 0.3 0.15
			{view pause "smoke"}
;			{con "smoke end"}
		}
	}
	(define "weapon_effects"
		{if stuff "pistol"
			{add_view "flash_gun_small03%name" "flashbarrel" "foresight3"}
		else stuff "shotgun"
			{add_view "flash_shotgun01" "flashbarrel01" "foresight3"}
			{add_view "flash_shotgun02" "flashbarrel02" "foresight3"}
		else stuff "at_rifle"
			{add_view "flash_ptrd" "flashbarrel" "foresight3"}
			{add_view "flash_ptrd_dust_ground" "ptr_dust" "foresight3"}
			{add_view "flash_ptrd_shell" "shell" "foresight3"};need another bone
		else stuff "rifle"
			{add_view "flash_gun_small01%name" "flashbarrel01" "foresight3"}
		else stuff "smg"
			{add_view "flash_gun_small01%name" "flashbarrel01" "foresight3"}
		else stuff "mgun"
			{add_view "flash_gun_big01%name" "flashbarrel01" "foresight3"}
		else stuff "flame_thrower"
			{add_view "flamer_fire" "flame" "foresight3"}
			{add_view "flamer_fire_barrel" "fire" "foresight3"}
			{add_view "flamer_fire_barrel_active" "fire_1" "foresight3"}
			{view show	"fire"}
			{view start	"fire"}
			("jet_of_fire_sound_init" name(human))
		else
			{view hide	"flashbarrel"}
			{view pause	"flashbarrel"}
			{view pause	"flame"}
		}

	)
	{on "lights_on"
		("weapon_effects" name())
	}
	{on "lights_off"
		("weapon_effects" name(_without_light))
	}
	{on "update_effects"
		{if not sunlight
			{call "lights_on"}
		else
			{call "lights_off"}
		}
	}
	{on "link_weapon"
		{call "update_effects"}
	}
	{on fire "hand_right"
		{call "bound_by_battle"}
		{view show	"flashbarrel"}
		{view start	"flashbarrel"}
		{view start	"flame"}{view pause "fire"}{view start	"fire_1"}
		("jet_of_fire_sound_play" name(human) loop_fade_in(0.1))
		{kill_delay "fire"}
		{delay 0.5 "fire"
			{view hide	"flashbarrel"}
			{view pause	"flashbarrel"}
			{view pause	"flame"}{view start "fire"}{view pause	"fire_1"}
			
		}
		
		("jet_of_fire_sound_stop" name(human) loop_fade_out(0.1))
		{spawn "bazooka_shot" "fxshot" x}
		{if stuff "rifle"
			{view show "flashbarrel01"}
			{view start "flashbarrel01"}
		else stuff "shotgun"
			{if rand 0.5
				{view show "flashbarrel01"}
				{view start "flashbarrel01"}
			else
				{view show "flashbarrel02"}
				{view start "flashbarrel02"}			
			}
		else
			{view show "flashbarrel01"}
			{view start "flashbarrel01"}			
		}
		{kill_delay "fire1"}
		{delay 0.5 "fire1"
			{view hide	"flashbarrel01"}
			{view hide	"flashbarrel02"}
			{view pause	"flashbarrel01"}
			{view pause	"flashbarrel02"}
		}
		{view show	"shell"}
		{view start "shell"}
		{kill_delay "shell"}
		{delay 0.5 "shell"
			{view hide "shell"}
			{view pause "shell"}
		}
		{if lying
			{view show	"ptr_dust"}
			{view start	"ptr_dust"}
			{kill_delay "fire2"}
			{delay 0.5 "fire2"
				{view hide	"ptr_dust"}
				{view pause	"ptr_dust"}
			}
		}
	}

	(define "terrain_fx_human"
		{on terrain_fx %0 enter
			{if not swimming
				{view start "on_%1"}
				{view start "on_%1_time_short"}
				{delay 0.1
					{view pause "on_%1_time_short"}
				}
			}
		}
		{on terrain_fx %0 leave
			{view pause "on_%1"}
		}
	)
	("terrain_fx_human" args "water" 			water)
	("terrain_fx_human" args "puddle"			puddle)
	("terrain_fx_human" args "shallow_water"	puddle)
	("terrain_fx_human" args "mud" 				mud)

	{on terrain_pp "swamp" enter
		{delay 0							; without delay will crash in Die()
			{call "die_without_blood"}
			{view start "die_in_swamp"}
			{delay 10
				{view stop "die_in_swamp"}
				{delete}
			}
		}
	}

	{on "diving"
		{delay 0.3
			{spawn "spherewater_big"}
		}
	}
	{on "movement_type_changed"
		{if name = "swim"
			{set "swim" 1}
			{view pause "on_water"}
			{view start "swim"}
			{call "stop_burn"}
			{kill_delay "after_swim"}
		else
			{if flag "swim"
				{set "swim" 0}
				{delay 1.5 "after_swim"
					{view pause "swim"}
				}
			}
;			{play_sound "pose_changed"}
		}
	}
	{on "selection"
		{if breed_mask "*/artilleryman*" "*/tankman" "*/*miner*" "*/engineer" "*/corpsman" "*/sapper"
			{talk "selection_support"}
		else
			{talk "selection"}
		}
	}
	{on "executing_order_move"
		{if charge 
			{talk "attack"}
		else
			{talk "executing_order"}
		}
	}
	{on move on
		{if swimming
			{view start "swim_move"}
		}
		;{call "update_move_sounds"}
		{if flag "barricade_play_sound"		{call "barricade_stop_sound"}}
		{if flag "barbwire_play_sound"		{call "barbwire_stop_sound"}}
		{if flag "hedgehog_play_sound"		{call "hedgehog_stop_sound"}}
		{if flag "cut_wire_play_sound"		{call "cut_wire_stop_sound"}}
		{if flag "trench_play_sound"		{call "trench_stop_sound"}}
	}
;	{on "update_move_sounds"
;		{if moving_fast
;			{if swimming
;				{play_sound_in_channel "swim" "steps" 1}
;			else not lying
;				{if terrain_fx "road"
;					{play_sound_in_channel "move_road" "steps" 1}
;				else terrain_fx "country_road"
;					{play_sound_in_channel "move_road" "steps" 1}
;				else terrain_fx "ice"
;					{play_sound_in_channel "move_snow" "steps" 1}
;				else terrain_fx "snow"
;					{play_sound_in_channel "move_snow" "steps" 1}
;				else terrain_fx "sand"
;					{play_sound_in_channel "move_sand" "steps" 1}
;				else terrain_fx "grass"
;					{play_sound_in_channel "move_grass" "steps" 1}
;				else
;					{play_sound_in_channel "move_ground" "steps" 1}
;				}
;			else
;				{play_sound_in_channel "" "steps" 1} ; stop sound if lying
;			}
;		else
;			{play_sound_in_channel "" "steps" 1} ; stop sound if moving slow
;		}
;	}
;	{on "stop_move_sounds"
;		{play_sound_in_channel "" "steps" 1} ; stop sound in steps channel
;	}
;	{on movement_mode_changed
;		{call "update_move_sounds"}
;	}
	{on move off
		{view pause "swim_move"}
		;{call "stop_move_sounds"}
	}
	{on "stop_burn"
		{if burned
			{burn stop_retry}
			{set "quench" 1}
		}
	}
	{on "falldown" overload
		{if installing
			{throw_on_ground}
		else altitude 3
			{throw_off up 1 forward 0.01 die force}
		else altitude 1
			{throw_off up 1 forward 0.01 force}
		else       
			{throw_on_ground}
		}
	}
	{on "fortification_crush"
		{if effector "trench"
			{throw_off up 1 forward 0.01 die force}
		}
	}
	{on board in
		{view pause "swim"}
	}
	{on board out
		{if effector "mtb_d3"
			{if name "emit1" "emit2" "emit3" "emit4"
				{delay 0.7
					{spawn "spherewater_big"}
				}
			}
		}
		{delay_effect 2 "repair_start_sound"}
	}
	{on "start_heal"
		;{view start "healing"}
		;{call "heal_start_sound"}
	}
	{on "stop_heal"
		;{view pause "healing"}
		;{call "heal_stop_sound"}
	}
	{on "capture"
		{tags add "capturer"}
	}
	{on "start_target"
		{view start "attention"}
	}
	{on "stop_target"
		{view pause "attention"}
	}
	{on "fx_link"
		(define "spwn_link"
			{if rand 0.125
				{spawn "%name" local_offset -%range 0 0}
			else
				{if rand 0.1428
					{spawn "%name" local_offset %range 0 0}
				else
					{if rand 0.1666
						{spawn "%name" local_offset 0 -%range 0}
					else
						{if rand 0.2
							{spawn "%name" local_offset 0 %range 0}				
						else
							{if rand 0.25
								{spawn "%name" local_offset -%range -%range 0}
							else
								{if rand 0.33
									{spawn "%name" local_offset %range %range 0}
								else
									{if rand 0.5
										{spawn "%name" local_offset -%range %range 0}
									else
										{spawn "%name" local_offset %range -%range 0}
									}
								}
							}
						}
					}
				}
			}
		)
		(define "rnd_spwn_link"
				{if rand 0.33
					("spwn_link" name(%name) range(100))
				else
					{if rand 0.5
						("spwn_link" name(%name) range(200))
					else
						("spwn_link" name(%name) range(300))
					}
				}
		)
		("rnd_spwn_link" name(fx_link))
	}
	{on "observed_by_enemy"
		{if spy and not breed_mask "*/paratrooper*" "*/hunter*"
			{talk "observed_by_enemy"}
			{if territory_type "enemy" ; шпион забрался на чужую территорию
				{marker "enemy_in_the_rear" 5 enemy {chat_message "mp/game/user_guide/enemy_in_rear/desc"}} ; поставим маркер на шпионе, видимый его врагам 3 секунды и крикнем им же в чат
				{with_effector
					{call "enemy_observed"} ; и сообщим союзникам
				}
			}
		}
	}
	{on "enemy_observed"
		{talk "human_enemy_observed" {audience ally}}
	}
	{on "bullet_hit_obstacle"
		{talk "human_bullet_hit_obstacle"}
	}
	{on "add_tags_on_saboteurs" 	;for missions
		{if breed_mask "*/saboteur"
			{tags add "saboteur"}
		else breed_mask "*/saboteur_smg"
			{tags add "saboteur_smg"}
		else breed_mask "*/saboteur_sniper"
			{tags add "saboteur_sniper"}
		}
	}
	{on "repair_next_sound"
		{if tagged "repairing"
			{delay 4 "repair_next_sound"
				{play_sound_in_channel "repair" "repair_ch"}
				{delay_effect 0 "repair_next_sound"}
			}
		else
			{kill_delay "repair_next_sound"}
		}
	}
	{on "repair_start_sound"
		{if tagged "repairing"
			{play_sound_in_channel "repair" "repair_ch"}
			{call "repair_next_sound"}
			{delay_effect 2 "repair_stop_sound"}
		}
	}
	{on "repair_stop_sound"
		{if not tagged "repairing"
			{kill_delay "repair_next_sound"}
			{stop_sound "repair" 0 0.1}
		else
			{delay_effect 0.5 "repair_stop_sound"}
		}
	}
	{on "put_dynamite_start_sound"
		{play_sound "put_dynamite"}
	}
	{on "detonation_start_sound"
		{play_sound "detonation"}
	}
	{on "mine_start_sound"
		{play_sound "mine"}
	}
	{on "mine_detected"
		{play_sound "mine_detected"}
	}
	{on "burn_start_sound"
		{play_sound "burn"}
	}
	("action_play_sound" 				action(barricade)				delay_next_sound(1))			;{on "barricade...
	("action_play_sound" 				action(barbwire) 				delay_next_sound(2.5 0.5))		;{on "barbwire...
	("action_play_sound" 				action(hedgehog) 				delay_next_sound(2))			;{on "hedgehog...
	("action_play_sound_and_check_stop" action(camouflage)				delay_next_sound(2))			;{on "camouflage...
;	("action_play_sound" 				action(heal) 					delay_next_sound(2))			;{on "heal...(start_heal & stop_heal)
	("action_play_sound" 				action(cut_wire) 				delay_next_sound(2))			;{on "cut_wire...
;	("action_play_sound" 				action(trench) 					delay_next_sound(2))			;{on "trench...
	
	("action_play_sound" 				action(pour)					delay_next_sound(5))			;{on "pour(_in|_out)...
	
	{on bullet_hit overload
		{kill_flags reset}
		{call "detect_by_hit"}
		{call "bound_by_battle"}
		("spawn_bloodsparks" n("bloodsparks_small2"))		; to generate hit signal
		{if stuff "shell fg" or stuff "shell fr"
			;{bullet_detonate}
			{call "process_bullet_hit"}
		else stuff "bazooka"
			{bullet_detonate}
			{call "process_bullet_hit"}
		else stuff "bullet" and relation "enemy"
			{if volume_armored
				{bullet_detonate}
			}
			{call "process_bullet_hit"}
		else stuff "bullet" and relation "ally"
			{if volume_armored
				{bullet_detonate}
			}
			{if effector "airborne"
				{call "process_bullet_hit"}
			else
				{with_effector
					{if manual_control
						{with_effector {call "process_bullet_hit"}}
					}
				}
			}										
		else stuff "flaergun strike"
			("health_damage" c(5))
	        ("grenade_signal")			
		else stuff "smoke_gr"
			("health_damage" c(5))
			("grenade_smoke")				
		else
			{call "process_bullet_hit"}
			
		}
	}

	{on "detect_by_hit" overload}
	
	{on "observed_by_enemy" overload}	
}