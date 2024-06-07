(define "handle_ik"
	{on ik begin "basis"}
	{on ik end "basis"}
	{on ik begin "gun_rot"}
	{on ik end "gun_rot"}
	{on ik begin "turret_rotator"}
	{on ik end "turret_rotator"}
)

(define "damage_cannon_process_pierce" ;by Svoyak
{if stuff "%staff"
    {if component "body"
        {burn fx "smoke_dead_tank3" fake}
        {if rand %pierce_turret__crew_die
            {kill_crew "commander"}
            {kill_crew "driver1"}
        else rand %pierce_turret__crew_die
            {kill_crew "driver2"}
            {kill_crew "gunner"}
        else rand %pierce_turret__crew_die
            {kill_crew "commander1"}
        ;{damage_report "crew" "die"}
        }

        {if rand %pierce_turret__crew_contusion
            {crew_throw_off up 2 1 dir 2 1 turn 0 180 forward 2 force}

            {if operatable
                {weapon_work "gun" 0}
                {tags add "contused"}
                {delay 2
                    {if not tagged "gun_brake"
                        {weapon_work "gun" 1}
                    }
                    {tags remove "contused"}
                }
            }
        }
        {if rand %pierce_turret__gun_brake
			{call "gun_broken"}
        }
    }
}
)

(define "detach_and_explosion"
	{detach}
	{call "explosion"}
)

{"cannon"
	{on spawn
		{link_sound "round_dot" "fortification/install/reinforcement_sandbags_install"}
		{link_sound "camouflage_cannon" "fortification/install/scrim_install"}
		{call "talk_scanner"}		
	}
	{on "executing_order_weapon_fire" overload
		{if not effector ; target - ground
			{if weapon_fire_mode "non_stop" ; once short_burst long_burst smart_burst
				{if aim_mode "attack_ground_forced"  ; default anti_airborne attack_ground_forced
					{talk "cannon_executing_order_weapon_fire_barrage"}
				else
					{talk "cannon_executing_order_weapon_fire_non_stop_ground"}
				}
			}
		}
	}
	{on "bullet_reflect"
		{if not armor_health 1 and not flag "broken"
			{if not stuff "bullet" and not stuff "fg" and not stuff "fr"
				{talk "cannon_bullet_reflect"}
				{call "talk_target_bullet_reflected"}
			}
		}
	}
	{on "talk_target_destroyed"
		{call "destroyed_by_spy"}
		{talk "cannon_leave"}
		{call "talk_target_destroyed_cannon"}
	}
	{on "talk_target_broke_engine" overload}
	{on "talk_target_broke_turret" overload}
	{on "talk_target_broke_track" overload}
	{on pierce
		{if armor_health 1
			{call "do_armor_break"}
		else
			{if component "body" or component "turret" or volume "wheel"
				{talk "cannon_pierce"}
				;{call "talk_target_pierced"}
			}
			{if component "wheelright"
				{call "wheelright_broken"}
			}
			{if component "wheelleft"
				{call "wheelleft_broken"}
			}
			("damage_cannon_process_pierce"
				staff(ptr)
				pierce_turret__crew_die(0)
				pierce_turret__gun_brake(0)
				pierce_turret__crew_contusion(0)
			)
			("damage_cannon_process_pierce"
				staff(shell ap)
				pierce_turret__crew_die(0)
				pierce_turret__gun_brake(0.2)
				pierce_turret__crew_contusion(0)
			)
		}
	}
	{on break_armor
		{if armor_health 1
			{if name "blast"
				{call "do_armor_break"}
			}
		else {call "check_talk_target_broke_component"}
		}
	}
	{on break_armor_again
		{if armor_health 1
			{if name "blast"
				{call "do_armor_break"}
			}
		}
	}
	{on "do_armor_break"
		{if not flag "broken"
			{crew_throw_off up 4 1 dir 5 1 turn 0 180 forward 2 force}
			("detach_and_explosion")
		}
	}
	{on "mp_destroy" ;hack for "burn_damage"
		("detach_and_explosion")
	}
	{on blast_hit
		{if flag "broken"
			{if min_energy 5 
				{if not linked
					{impulse up 0.5 0.2 dir 1 0.2}
				}
				{if simulating
					{attack_save}
					{delay_ex 0.3
						{attack_load
	;					{crew_throw_off up 4 1 dir 5 1 turn 0 180 forward 2 force}
						{fragments c4 0.2 r0 2 r1 2 bone "pivot_back"}
						}
					}
				}
			else min_energy 1.2
				{if not linked
					{impulse up 0.3 0.2 dir 0.7 0.2}
				}
				{if simulating
					{attack_save}
					{delay_ex 0.3
						{attack_load
	;					{crew_throw_off up 4 1 dir 5 1 turn 0 180 forward 2 force}
						{fragments c4 0.2 r0 2 r1 2 bone "pivot_back"}
						}
					}
				}
			;else min_energy 0.6
			;	{ani_play "hit"}
			}
			{if stuff "ani_play_hit"
				{ani_play "hit"}
			}
		}
	}
	{on "cut_parts"
		{add_view "smoke_dead_norm" "deathfx" "FXfire1"}
		{view start "deathfx"}
		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
				{call "check_delete_part"}
			}
		)
		("cut_part" args "part1")
		("cut_part" args "part2")
		("cut_part" args "part3")
		("cut_part" args "part4")
		("cut_part" args "part5")
		("cut_part" args "part6")
		{delay 14 {view stop "deathfx"}}
	}
	{on "init_gun"
		{add_view "flash_zenit02" "flashbarrel1" "shooter00"}
		
		{add_view "smoke_zenit" "smoke_shell" "fx_invers"};for spawn_shell
	}
	{on fire "gun"
		{ani_play "recoil"}
		{view start "flashbarrel1"}
		{view start "flashbarrel1s"}
		{delay 0.15
			{view pause "flashbarrel1"}
		}
		{delay 0.3
			{view pause "flashbarrel1s"}
		}
		{call "spawn_shell"}
	}
	{on "spawn_shell"
		{start_sound "weapon/shot/shell"}
		{view start "smoke_shell"}
		{delay 2.5 0.5
			{view stop "smoke_shell"}
		}
		{spawn "shell_cannon" "fx_invers" x scale 0.014
			{impulse up 1.5 0.5 dir -4.5 0.7 cz 0.2 0.1 com}
			{add_view "smoke_zenit" "smoke_shell" "fx_shellsmoke"}
			{view start "smoke_shell"}
			{delay_effect 3 1 "stop"}
			{delay 3 0.5
				{hide 3}
			}
		}
	}	
	{on contact
		{if not flag "broken"
			{if not impregnable
				{if effector "tank" or effector "armored_car" or effector "car"
					{if attaching_trailer {tags add "attaching_trailer"}}
					{if not tagged "attaching_trailer"				
						{component destroy}
						{if volume "body" or volume "turret"
							{set "crush" 1}
							("detach_and_explosion")
						}
						{delay 5 2	{set "ready_to_delete" 1}}
					else {delay 2.0 {tags remove "attaching_trailer"}}
					}
				}
			}
		else
			{if flag "ready_to_delete"
				{set "ready_to_delete" 0}
				{spawn "metal_crush" "root"}
				{hide 2}
			}
		}
	}
	("handle_ik")
	{on "check_water_level" overload
		{if not linked
			{if water_level 1.2
				{able "sinking" 1}
			}
		}
	}
	{on "tear_wheel" overload}
	{on "fortification_crush"
		{if effector "trench"
			{kill_crew}
			{component destroy}
			{set "crush" 1}
			("detach_and_explosion")
		}
	}
	{on "gun_broken"
		{if flag "with_gun"
			{if work "gun"
				{components "gun" break}
				{damage_report "gun" "broken"}
			}
		}
	}
	{on "wheelleft_broken"
		{if work "wheelleft"
			{components "wheelleft" break}
		}
	}
	{on "wheelright_broken"
		{if work "wheelright"
			{components "wheelright" break}
		}
	}
	{on "check_work_mover" overload
		{if not work "mover"
			{chassis_work 0}
		else broken "wheel" 2
			{chassis_work 1}
			{movement_limit slow}
		else broken "wheel" 1
			{chassis_work 1}
			{movement_limit normal}
		else not broken "wheel"
			{chassis_work 1}
			{movement_limit fast}
		else
			{chassis_work 1}
		}
	}
	{on "ammo_reload_begin"
;		{if stuff "fliter by weapon"}
;		{if ammo "fliter by ammo"}
		{talk "ammo_reload_begin"}
	}
	{on "ammo_reload_end"
;		{if stuff "fliter by weapon"}
;		{if ammo "fliter by ammo"}
		{talk "ammo_reload_end"}
	}
	{on "selection" overload
		{talk "selection_support"}
	}
	{on "executing_order_move" overload
		{talk "executing_order"}
	}
	{on "bullet_hit_obstacle" overload
		{talk "human_bullet_hit_obstacle"}
	}
	{on "report_unable_move_reason" overload
		{talk "cannon_need_more_crew"}
	}
	{on "report_repairer_fail" overload
		{talk "cannon_repairer_fail"}
	}
	{on "enemy_observed" overload
		{talk "human_enemy_observed" {audience ally}}
	}
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/groundborne/motions/weapon_manual_rotate"}
	}
	{on "talk_scanner"			
		{if attacking_weapon or attacked	
			{talk "cannon_in_action" {audience all}}			
		}				
		{delay 5 "talk_scanner"
			{call "talk_scanner"}
		}
	}	
	{on "play_sound_camouflage" overload
		{play_sound_in_channel "camouflage_cannon" "camouflage_ch"}
		{delay_effect 0 "camouflage_next_sound"}
	}
	{on "camouflage_next_sound" overload
		{if flag "camouflage_play_sound"
			{delay 1.1 0.1 "camouflage_next_sound"
				{call "play_sound_camouflage"}
			}
		}
	}
	("action_play_sound_and_check_stop" action(round_dot) delay_next_sound(2))			;{on "round_dot...
}
{"cannon radar_mount"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/chi_ha_turret_move"}
	}
}
{"cannon kp42"
	{on spawn
		{link_sound "cooking" "gameplay/cooking/"}
		{add_view "smoke_grey"			"smoke"	"fx_smoke"}
	}
	{on "executing_order_weapon_fire" overload}
	{on "talk_target_destroyed" overload}
	{on "ammo_reload_begin" overload}
	{on "ammo_reload_end" overload}
	{on "spawn_shell" overload}
	{on fire "gun" overload}
	{on pierce overload
		{if armor_health 1
			{call "do_armor_break"}
		else
			{if component "wheelright"
				{call "wheelright_broken"}
			}
			{if component "wheelleft"
				{call "wheelleft_broken"}
			}
		}
	}
	{on operatable on
		{call "cooking_start_sound"}
		{view start "smoke"}
	}
	{on operatable off
		{call "cooking_stop_sound"}
		{view stop "smoke"}
	}
	("action_play_sound" 				action(cooking)					delay_next_sound(12 3))
}
(define "exp_inv"
	{on "ammunition_explosion"
		{if flag "broken" and not flag "ammunition_explosion"
;			{con "START %con %name"}
			{set "ammunition_explosion" 1}
			{if rand 0.5
				{spawn "explosion_%name"}
				{damage_report "inventory" "broken"}
;				{con "BREAK %con %name"}
			}
		}
	}
	{on break
		{call "ammunition_explosion"}
	}
)
{"cannon level01 howitzer"
	("exp_inv" name(75mm) con(HOW))
}
{"cannon level01"
	("exp_inv" name(37mm) con())
}
{"cannon level02 howitzer"
	("exp_inv" name(105mm) con(HOW))
}
{"cannon level02"
	("exp_inv" name(45mm) con())
}
{"cannon level03 howitzer"
	("exp_inv" name(150mm) con(HOW))
}
{"cannon level03"
	("exp_inv" name(76mm) con())
}
{"cannon level04 heavy"
	("exp_inv" name(85mm) con(heavy))
}
{"cannon level04"
	("exp_inv" name(76mm) con())
}
{"cannon level05 howitzer"
	("exp_inv" name(203mm) con(HOW))
}
{"cannon level05"
	("exp_inv" name(88mm) con())
}

{"cannon_small"
	{on blast_hit
		{if armor_health 1	{call "explosion"}}
	}
	{on "_explosion"
		{set "ready_to_delete" 1}
	}
	{on ground_hit
		{tags add "ground_hit"}
		{if not armor_health 1 and not flag "broken" and not linked
			{call "explosion"}
		}
	}
}

{"mg_stan"
	{on spawn
		{add_view	"flash_gun_big01"	"flashbarrel21"	"Foresight3"}
	}
	{on fire "mgun"
		{view start "flashbarrel21"}
	}
	{on "ammunition_explosion" overload}
	{on "explosion_blastwave" overload
		{impulse up 0.2 dir 0.3}
	}
	{on "add_movement_sound"
		{link_sound "move"			"human/move/ground"}
	}	
;	{on contact overload}
	{on break_armor
		{if armor_health 1
			("detach_and_explosion")
		else
			{if name "blast"
				{if ammo "size2" or ammo "size3" or ammo "size4"
					("detach_and_explosion")
				}
			}
		}
	}
	{on "talk_target_destroyed" overload
		{call "destroyed_by_spy"}
		{talk "cannon_leave"}
		{call "talk_target_destroyed_mgun"}
	}
	{on "_explosion"
		{if not tagged "ground_hit" 
			{physics_work 0}
		else
			{delay 1.0 {physics_work 0}}
		}
		{hide 3}
	}
}

{"no_exp_blast"
	{on "explosion_blastwave" overload
;		{impulse up 0.2 dir 0.3}
	}
	{on "explosion_sound" overload}
}

{"heavy cannon"
	{on "spawn_effect_gun"
		{spawn "tank_canon_fire" "Foresight1" x}
	}
	{on fire "gun"
		{if game_param 	"biom" "snow"
			{spawn "circledust_norm2_w" "basis"}
		else
			{spawn "dust_shot_norm" "basis"}
		}
		{call "spawn_effect_gun"}
		{ani_play "fire"}
	}
}

{"heavy cannon muzzle_brake"
	{on "spawn_effect_gun" overload
		{spawn "tank_canon_fire_muz" "Foresight1" x}
	}
}

{"two_barrel_cannon"
	{on pierce overload
		{if armor_health 1
			{call "do_armor_break"}
		}
	}
	{on "do_armor_break" overload
		{if not flag "broken"
			{crew_throw_off up 4 1 dir 5 1 turn 0 180 forward 2 force}
		}
		{set "big_explosion" 0}
		{if explosive_amount 50               
			{fragments c4 10 r0 8 r1 16}
			{spawn "train_die" "basis"}
			{set "big_explosion" 1}
		}
		("detach_and_explosion")
	}
	{on contact overload
	}
	{on fire "gun"
        	{spawn "tank_canon_fire" "shooter_c00" x}
        	{spawn "tank_canon_fire" "shooter_c01" x}
	}
	{on "vehicle_mining_start" overload
	}
	{on "vehicle_mining_end" overload
	}
	{on "vehicle_mining_abort" overload
	}
	{on "vehicle_mining_in_process" overload
	}
	{on "leave_unit" overload
	}
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/groundborne/pz6b/pz6b_turret"}
	}	
}

{"two_barrel_cannon_ny"
	{on spawn
		{add_view "xmas_smoke"	"smoke" "basis"}
		{add_view "xmas_light"	"light1" "fx_point1"}
		{add_view "xmas_light"	"light2" "fx_point2"}
		{add_view "xmas_light"	"light3" "fx_point3"}
		{add_view "xmas_light"	"light4" "fx_point4"}
		{add_view "xmas_light"	"light5" "fx_point5"}
		{view start "smoke"}
		{view start "light1"}
		{view start "light2"}
		{view start "light3"}
		{view start "light4"}
		{view start "light5"}
		{ani_play "xmas" loop}
	}
	{on "do_armor_break" overload
		{if not flag "broken"
			{crew_throw_off up 4 1 dir 5 1 turn 0 180 forward 2 force}
		}
		{set "big_explosion" 0}
		{if explosive_amount 50               
			{fragments c4 10 r0 8 r1 16}
			{spawn "train_die" "basis"}
			{set "big_explosion" 1}
		}
		("detach_and_explosion")
	}
	{on "vehicle_mining_start" overload
	}
	{on "vehicle_mining_end" overload
	}
	{on "vehicle_mining_abort" overload
	}
	{on "vehicle_mining_in_process" overload
	}
	{on "leave_unit" overload
	}
	{on pierce overload
		{if armor_health 1
			{call "do_armor_break"}
		}
	}
	{on contact overload
	}
	{on fire "gun"
        	{spawn "xmas_smoke" "shooter_c00" x}
        	{spawn "xmas_smoke" "shooter_c01" x}
	}
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/groundborne/pz6b/pz6b_turret"}
	}	
}

{"medium cannon"
	{on spawn
		{add_view	"flash_cannon_small"	"flashbarrel1"	"Foresight1"}
	}
	{on "add_movement_sound"
		{link_sound "move"			"human/move/ground"}
	}
	{on "spawn_effect_gun"
		{spawn "tank_canon_fire_small" "Foresight1" x}
	}
	{on fire "gun"
		{if game_param 	"biom" "snow"
			{spawn "circledust_norm2_w" "basis"}
		else
			{spawn "dust_shot_norm" "basis"}
		}
		{call "spawn_effect_gun"}
		{ani_play "fire"}
	}
}

{"medium cannon muzzle_brake"
	{on "spawn_effect_gun" overload
		{spawn "tank_canon_fire_small_muz" "Foresight1" x}
	}
}

{"mortar"
	{on spawn overload
		{link_sound "rotate_turret" "vehicle/turret/mortar"}
		{link_sound "rotate_gun" "vehicle/turret/medium"}
		{add_view	"spheredust_big"	"dust"			"turret"}
	}	
	{on fire "gun" overload
		{ani_play "recoil"}
        {spawn "canon_gaub_fire" "Foresight1" x}
		{view start "flashbarrel1s"}
       	{view start "dust"}
		{delay 1
			{view pause "dust"}
		}
		{delay 2
			{view pause "flashbarrel1"}
		}
		{fragments c4 0.6 r0 3 r1 5 bone "Foresight1" offset 40 0 0}
		{call "spawn_shell"}
		{ani_play "recoil"}			
	}
	{on "cut_parts" overload
		{spawn "tank_die" "Basis"}
		{add_view "smoke_aero_big" "deathfx1" "fx_smoke1"}
		{add_view "smoke_black" "deathfx2" "fx_smoke2"}
		{view start "deathfx1"}
		{view start "deathfx2"}
		(define "cut_part"
			{tear "piece_big_steel" bone %0
				{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
				{call "check_delete_part"}
			}
		)
		("cut_part" args "part1")
		("cut_part" args "part2")
		("cut_part" args "part3")
		("cut_part" args "part4")
		("cut_part" args "part5")
		("cut_part" args "part6")
		{delay 10 2 {view stop "deathfx1"}}
		{delay 6 2 {view stop "deathfx2"}}
	}
	{on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	{on contact overload}
}
{"mortar_launch_sound"
	{on fire "gun"
		{delay 2
			{start_sound "weapon/shot/reactive/mortar_scream"}
		}
	}
	{on "add_movement_sound"
		{link_sound "move"			"human/move/ground"}
	}		
}
{"cannon flak"
	{on spawn overload
		{call "init_gun"}
		{call "add_movement_sound"}
	}
}

{"vickers"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" "vehicle/turret/medium3"}
	}
}
{"flak41"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" "vehicle/turret/medium3"}
	}
}
{"52k"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" "vehicle/turret/medium3"}	
	}
}
{"m2cannon90mm"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" "vehicle/turret/medium3"}
	}
}
{"m1_aa"
	{on spawn
		{add_view	"flash_gun_big01"	"flashbarrel21"	"shooter01"}
		{add_view	"flash_gun_big01"	"flashbarrel22"	"shooter02"}
	}
	{on fire "mgun"
		{if rand 0.5
			{view start "flashbarrel21"}
		else
			{view start "flashbarrel22"}
		}
	}
}
{"flak"
	("handle_ik")
	{on "init_gun"
		{add_view "flash_zenit01"			"flashbarrel00_1"	"shooter00"}
		{add_view "flash_zenit01"			"flashbarrel01_1"	"shooter01"}
		{add_view "flash_zenit01"			"flashbarrel02_1"	"shooter02"}
		{add_view "flash_zenit01"			"flashbarrel03_1"	"shooter03"}
		{add_view "smoke_zenit"			"smoke00"		"shooter00"}
		{add_view "smoke_zenit"			"smoke01"		"shooter01"}
		{add_view "smoke_zenit"			"smoke02"		"shooter02"}
		{add_view "smoke_zenit"			"smoke03"		"shooter03"}
		{add_view "zenit_gilz"			"shell"			"FXshell1"}
		{add_view "zenit_gilz"			"shell"			"FXshell2"}
		{add_view "zenit_gilz"			"shell"			"FXshell3"}
		{add_view "zenit_gilz"			"shell"			"FXshell4"}
		{if game_param 	"biom" "snow"
			{add_view "circledust_norm2_w"	"zenite_dust"	"turret"}
		else
			{add_view "circledust_norm2"	"zenite_dust"	"turret"}
		}
		{call "update_gun"}
	}
	{on "add_movement_sound"
		{link_sound "rotate_turret" "vehicle/turret/light"}
	}
	{on fire "gun" overload
		(define "fire_barrel"
			name "%0"
				{call "fire_barrel%0"}
				{view start "flashbarrel%0_1"}
				{delay 0.42
					{view pause "flashbarrel%0_1"}
				}
				{ani_play "fire%0"}
				{ani_play "recoil"}				
				{delay 0.12 
					{view start "smoke%0"}
					{delay 5
						{view pause "smoke%0"}
					}
				}
		)
		
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		}

		{if name "00"
			{call "fire_gun_common"}
		}
	}
	{on "fire_gun_common"
		{view start "flashbarrel"}
		{ani_play "recoil"}
		{kill_delay "shell_off"}
		{view start "shell"}
		{view start "dust"}
		{delay 0.12 "shell_off"
			{view pause "shell"}
			{view pause "dust"}
		}
	}
}

{"flak barrel1"
	{on "init_gun"
		{add_view "flash_zenit02"			"flashbarrel00_2"	"shooter00"}
		{add_view "flash_zenit02"			"flashbarrel01_2"	"shooter01"}
		{add_view "flash_zenit02"			"flashbarrel02_2"	"shooter02"}
		{add_view "flash_zenit02"			"flashbarrel03_2"	"shooter03"}
	}
	{on fire "gun" overload
			{view start "flashbarrel00_2"}
		{delay 0.42
			{view pause "flashbarrel00_2"}
		}
		{ani_play "fire00"}
		{ani_play "recoil"}		
		{delay 0.12 
			{view start "smoke00"}
			{delay 3.5
				{view pause "smoke00"}
			}
		}
		{call "fire_gun_common"}
	}
}

{"small cannon"
	{on spawn overload
		{link_sound "rotate_turret" "turret.flak"}
		{add_view "flash_zenit02"		"flashbarrel01"	"foresight1"}
		{add_view "smoke_zenit"			"smoke"			"foresight1"}
		{add_view "zenit_gilz"			"shell"			"FXshell1"}
		{call "update_gun"}
		
		{add_view	"human_linked_selection" "linked_selection" "visor"}
		{view hide "linked_selection"}
	}
	{on fire "gun" overload
		{view start "flashbarrel01"}
		{ani_play "fire"}
		{ani_play "recoil"}
		{kill_delay "shell_off"}
		{view start "shell"}
		{delay 0.12 "shell_off"
			{view pause "shell"}
			{view start "smoke"}
			{delay 0.3
				{view pause "flashbarrel01"}
			}
			{delay 5
				{view pause "smoke"}
			}
		}
	}
}

{"sg_small"
	{on "add_movement_sound" overload}
}

{"nebelwerfer"
	{on fire "gun"
		{spawn "startsmoke" inv_normal}
	}
	{on "__explosion"
		{set "big_explosion" 0}
		{if explosive_amount 50               
			{fragments c4 10 r0 8 r1 16}
			{spawn "train_die" "basis"}
			{set "big_explosion" 1}
		}
	}
	{on "spawn_shellhole"
		{##if flag "big_explosion"
			{spawn "crater_extra_big" "basis" terrain_texmod}
			{spawn "shellhole_big_dead" "basis"}
		}
	}
	{on blast
		{if armor_health 1
			{if volume "body" or volume "turret"
				{if min_energy 4
					{delay 0.1
						("detach_and_explosion")
					}
				}
			}
		}
	}
}

{"lg_40"
	{on fire "gun"
		{spawn "bazooka_shot" "fxshot" x}
		{spawn "tank_canon_fire" "fxshot" x}
	}
}

{"52k cannon"
	{on "add_movement_sound"
		{link_sound "rotate_turret" 	"vehicle/turret/medium"}
	}
}

{"flak18 cannon"
	{on "add_movement_sound"
		{link_sound "rotate_turret" 	"vehicle/turret/medium"}
	}
}

{"zenite" ;gun mounted on car or tank
	("handle_ik")
	{on spawn
		{add_view "flash_zenit02"			"zenite_flash01"	"foresight1"}
		{add_view "smoke_zenit"			"zenite_smoke"	"foresight1"}
		{add_view "zenit_gilz"			"zenite_shell"	"FXshell1"}
		{if game_param 	"biom" "snow"
			{add_view "circledust_norm2_w"	"zenite_dust"	"turret"}
		else
			{add_view "circledust_norm2"	"zenite_dust"	"turret"}
		}
	}
	{on fire "gun" overload
		{ani_play "fire"}
		{ani_play "recoil"}		
		{view start "zenite_flash01"}
		{kill_delay "shell_off"}
		{view start "zenite_shell"}
		{view start "zenite_dust"}
		{delay 0.12 "shell_off"
			{view pause "zenite_shell"}
			{view pause "zenite_dust"}
			{view start "zenite_smoke"}
			{delay 0.3
				{view pause "zenite_flash01"}
			}
			{delay 5
				{view pause "zenite_smoke"}
			}
		}
	}
}

{"searchlight"
	{on blast_hit
		{if min_energy 0.4
			{call "light_break"}
		}
	}
	{on "light_break" ; handled in extender
		{call "lamp_broken"}
	}
	{on bullet_hit
		{if volume "lamp1"
			{call "lamp_broken"}
		}
	}
	{on "lamp_broken"
		{tags add "lamp_broken"}
	}
	{on ground_hit
		{call "explosion"}
	}
	{on "_explosion"
		{drop_orders}
		{call "light_break"}
	}
	{on operatable on}	; handled in extender
	{on operatable off}	; handled in extender
}

{"305mm"
	{on fire "gun"
		{tags add "fire_gun"}
		{spawn "spheredust_big2" "basis"}
	}
}

{"flak mortar"
	("handle_ik")
	{on "init_gun" overload
		{add_view "smoke_cannon400"			"smoke00"		"shooter00"}
		{add_view "smoke_cannon400"			"smoke01"		"shooter01"}
		{add_view "smoke_cannon400"			"smoke02"		"shooter02"}
		{call "update_gun"}
	}
	{on "fire_barrel00"
 	   {spawn "cannon400_fire" "shooter00" x}
	}
	{on "fire_barrel01"
 	   {spawn "cannon400_fire" "shooter01" x}
	}
	{on "fire_barrel02"
 	   {spawn "cannon400_fire" "shooter02" x}
	}
}

{"bkg_sound"
	{on "play_bkg_sound"
		{start_sound "weapon\shot\background\howitzer"}
        }
	{##on fire "gun"
		{call "play_bkg_sound"}
	}		
}