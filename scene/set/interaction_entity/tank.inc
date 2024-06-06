{"tank"
;   {friction 1}
;   {restitution 0.3}
    (include "tank_general_scripts_defines.inc")
    (include "tank_kill_crew.inc")
    (include "base_strikes.inc")
    (include "flamer.inc")
	
;MEGA BUILDING BEGIN =============================================================================================================================================================================
	(define "contusion"
		{delay 0.1			;need to check destruction
			{call "check_access_to_contusion"}
			{if flag "access_to_contusion"
				{call "%name"}
				{icon_event "contusion" %time}
				{kill_delay "contusion"}
				{delay %time "contusion"
					{call "contusion_off"}
				}
			}
		}
	)
	(define "crew_kill_place"
		{if crew_in_place "%place"
			{kill_crew_by_weapon
				{weapon ""}
				{max_kill 1}
				{place "%place" 1}
			}
			{icon_event "crew_dead" %t}
			{crew_enable place "%place" 0}
			{delay %t {crew_enable place "%place" 1}}
			
		}
	)
    (define "damage_process_pierce" ;define's call's see in tank-armoredcar.inc, tank-light.inc, tank-medium.inc & tank-heavy.inc.
		{if stuff "%staff"
			(define "component_turret"
			{if component "turret%num"
				{if hit_side front
					{if rand %pierce_turret_front__turret_brake {call "turret%num_broken"}}

				else hit_side back
					{if rand %pierce_turret_back__turret_brake {call "turret%num_broken"}}

				else
					{if rand %pierce_turret_left_right__turret_brake {call "turret%num_broken"}}
				}
				;("set_all_params_kill_crew"
				;	max_kill(%max_kill)
				;	charger(%charger)
				;	charger2(%charger2)
				;	driver(%driver)
				;	gunner(%gunner)
				;	commander(%commander)
				;	gunner2(%gunner2)
				;	gunner3(%gunner3)
				;	gunner4(%gunner4)
				;)
				;---contusion---
				{if operatable
					{if rand %pierce_rand_contusion
						("contusion" name(contusion_on_turret) time(%crew_shock_time))
					}
				}
				{if stuff "shell ap" {bullet_detonate}}
			}
			)
			{if rand %insta_kill {set "insta_kill" 1}}
			{if flag "open_wheelhouse"
				{if component "gun"
					{if rand (* 0.5 %pierce_gun) {call "gun_broken"}}
				}
			}
			;("track_hit" max_rand(%pierce_front_back_track) min_rand(%pierce_left_right_track))
			{if component "body"
				{burn fx "smoke_dead_tank3" fake}			
				;("set_all_params_kill_crew"
				;	max_kill(%max_kill)
				;	charger(%pierce_body__kill_charger)
				;	charger2(%pierce_body__kill_charger2)
				;	driver(%pierce_body__kill_driver)
				;	gunner(%pierce_body__kill_gunner)
				;	commander(%pierce_body__kill_commander)
				;	gunner2(%pierce_body__kill_gunner2)
				;	gunner3(%pierce_body__kill_gunner3)
				;	gunner4(%pierce_body__kill_gunner4)
				;)
				{if not flag "broken"
					{if flag "insta_kill"
						{if rand (* 0.5 %pierce_body__body_destroy) and explosive_amount 300 and inventory_item "shell fg"
							;{call "stat_break"} 
							{call "_explosion"} 
							{damage_report "inventory" "broken"}
						else rand (* 0.66 %pierce_body__body_brake) {call "mp_destroy"}
						else
							{call "mp_destroyed_off_realism"} 
						}
					else hit_side front or hit_side top or hit_side bottom
						{if flag "pierced" and rand (* 0.66 %pierce_body__body_destroy)
								{if rand 0.5 and explosive_amount 300 and inventory_item "shell fg"
									;{call "stat_break"} 
									{call "_explosion"} 
									{damage_report "inventory" "broken"}
									else
									{call "mp_destroyed_off_realism"} 
								}
							else flag "pierced" and rand (* 0.66 %pierce_body__body_brake) {call "mp_destroy"}
							else {damage_report "body" "pierced"} {set "pierced" 1}
						}
					else
						{if rand %pierce_body__body_destroy
							{if rand 0.5 and explosive_amount 300 and inventory_item "shell fg"
								;{call "stat_break"} 
								{call "_explosion"} 
								{damage_report "inventory" "broken"}
								else
								{call "mp_destroyed_off_realism"} 	
							}
						else rand %pierce_body__body_brake		{call "mp_destroy"}	
						else {damage_report "body" "pierced"} {set "pierced" 1}
						}
					}
					;---contusion---
					{if operatable
						{if rand %pierce_rand_contusion
							("contusion" name(contusion_on_body) time(%crew_shock_time))
						}
						{if hit_side front
							{if rand (* 0.5 %pierce_body__kill_charger) and not props "turret" ("crew_kill_place" place(charger) t(5))}
							{if rand (* 0.5 %pierce_body__kill_charger2) ("crew_kill_place" place(charger2) t(5))}
							{if rand (* 2 %pierce_body__kill_gunner) and not props "turret" ("crew_kill_place" place(gunner) t(5))}
							{if rand (* 0.5 %pierce_body__kill_gunner2) ("crew_kill_place" place(gunner2) t(5))}
							{if rand (* 0.5 %pierce_body__kill_gunner3) ("crew_kill_place" place(gunner3) t(5))}
							{if rand (* 0.5 %pierce_body__kill_gunner4) ("crew_kill_place" place(gunner4) t(5))}
							{if rand (* 2 %pierce_body__kill_driver) ("crew_kill_place" place(driver) t(5))}
							{if rand (* 1 %pierce_body__kill_commander) and not props "turret" ("crew_kill_place" place(commander) t(5))}							
						else hit_side back	
							{if rand (* 0.2 %pierce_body__kill_charger) and not props "turret" ("crew_kill_place" place(charger) t(5))}
							{if rand (* 0.2 %pierce_body__kill_charger2) ("crew_kill_place" place(charger2) t(5))}
							{if rand (* 1 %pierce_body__kill_gunner) and not props "turret" ("crew_kill_place" place(gunner) t(5))}
							{if rand (* 0.2 %pierce_body__kill_gunner2) ("crew_kill_place" place(gunner2) t(5))}
							{if rand (* 0.2 %pierce_body__kill_gunner3) ("crew_kill_place" place(gunner3) t(5))}
							{if rand (* 0.2 %pierce_body__kill_gunner4) ("crew_kill_place" place(gunner4) t(5))}
							{if rand (* 0 %pierce_body__kill_driver) ("crew_kill_place" place(driver) t(5))}
							{if rand (* 0.5 %pierce_body__kill_commander) and not props "turret" ("crew_kill_place" place(commander) t(5))}
						else
							{if rand (* 1 %pierce_body__kill_charger) ("crew_kill_place" place(charger) t(5))}
							{if rand (* 1 %pierce_body__kill_charger2) ("crew_kill_place" place(charger2) t(5))}
							{if rand (* 1 %pierce_body__kill_gunner) ("crew_kill_place" place(gunner) t(5))}
							{if rand (* 1 %pierce_body__kill_gunner2) ("crew_kill_place" place(gunner2) t(5))}
							{if rand (* 1 %pierce_body__kill_gunner3) ("crew_kill_place" place(gunner3) t(5))}
							{if rand (* 1 %pierce_body__kill_gunner4) ("crew_kill_place" place(gunner4) t(5))}
							{if rand (* 1 %pierce_body__kill_driver) ("crew_kill_place" place(driver) t(5))}
							{if rand (* 1 %pierce_body__kill_commander) ("crew_kill_place" place(commander) t(5))}	
						}
					}
				}
				{if stuff "shell ap" {bullet_detonate}}
			}
			{if component "turret"
				{burn fx "smoke_dead_tank3" fake}
				{if flag "insta_kill"
						{if rand (* 0.66 %pierce_body__body_destroy) and explosive_amount 300 and inventory_item "shell fg"
							;{call "stat_break"} 
							{call "_explosion"} 
							{damage_report "inventory" "broken"}
						else rand (* 0.66 %pierce_body__body_brake) {call "mp_destroy"}
						else
							{call "mp_destroyed_off_realism"} 
						}
					else hit_side front or hit_side top or hit_side bottom
						{if flag "pierced" and rand (* 0.66 %pierce_body__body_destroy)
								{if rand 0.5 and explosive_amount 300 and inventory_item "shell fg"
									;{call "stat_break"} 
									{call "_explosion"} 
									{damage_report "inventory" "broken"}
									else
									{call "mp_destroyed_off_realism"} 
								}
							else flag "pierced" and rand (* 0.66 %pierce_body__body_brake) {call "mp_destroy"}
							else {damage_report "body" "pierced"} {set "pierced" 1}
						}
					else
						{if rand %pierce_body__body_destroy
							{if rand 0.5 and explosive_amount 300 and inventory_item "shell fg"
								;{call "stat_break"} 
								{call "_explosion"} 
								{damage_report "inventory" "broken"}
								else
								{call "mp_destroyed_off_realism"} 	
							}
						else rand %pierce_body__body_brake		{call "mp_destroy"}	
						else {damage_report "body" "pierced"} {set "pierced" 1}
						}
				}
				{if hit_side front
					{if rand %pierce_turret_front__gun_brake {call "gun_broken"}}
					{if flag "open_wheelhouse" and stuff "ptr"
						{if rand (+ %pierce_turret_front__turret_brake 0.25) {call "turret_broken"}}
					else
						{if rand %pierce_turret_front__turret_brake {call "turret_broken"}}
					}
					{if operatable
						{if rand (* 0.5 %pierce_turret__kill_charger) ("crew_kill_place" place(charger) t(5))}
						{if rand (* 0.5 %pierce_turret__kill_charger2) ("crew_kill_place" place(charger2) t(5))}
						{if rand (* 2 %pierce_turret__kill_gunner) ("crew_kill_place" place(gunner) t(5))}
						{if rand (* 2 %pierce_turret__kill_gunner2) ("crew_kill_place" place(gunner2) t(5))}
						{if rand (* 2 %pierce_turret__kill_gunner3) ("crew_kill_place" place(gunner3) t(5))}
						{if rand (* 2 %pierce_turret__kill_gunner4) ("crew_kill_place" place(gunner4) t(5))}
						{if rand (* 1 %pierce_turret__kill_commander) ("crew_kill_place" place(commander) t(5))}
					}

				else hit_side back
					{if rand %pierce_turret_back__gun_brake {call "gun_broken"}}
					{if flag "open_wheelhouse" and stuff "ptr"
						{if rand (+ %pierce_turret_back__turret_brake 0.35) {call "turret_broken"}}
					else
						{if rand %pierce_turret_back__turret_brake {call "turret_broken"}}
					}
					{if operatable
						{if rand (* 2 %pierce_turret__kill_charger) ("crew_kill_place" place(charger) t(5))}
						{if rand (* 2 %pierce_turret__kill_charger2) ("crew_kill_place" place(charger2) t(5))}
						{if rand (* 0.5 %pierce_turret__kill_gunner) ("crew_kill_place" place(gunner) t(5))}
						{if rand (* 0.5 %pierce_turret__kill_gunner2) ("crew_kill_place" place(gunner2) t(5))}
						{if rand (* 0.5 %pierce_turret__kill_gunner3) ("crew_kill_place" place(gunner3) t(5))}
						{if rand (* 0.5 %pierce_turret__kill_gunner4) ("crew_kill_place" place(gunner4) t(5))}
						{if rand (* 1 %pierce_turret__kill_commander) ("crew_kill_place" place(commander) t(5))}
					}

				else
					{if rand %pierce_turret_left_right__gun_brake {call "gun_broken"}}
					{if flag "open_wheelhouse" and stuff "ptr"
						{if rand (+ %pierce_turret_left_right__turret_brake 0.3) {call "turret_broken"}}
					else
						{if rand %pierce_turret_left_right__turret_brake {call "turret_broken"}}
					}
					{if operatable
						{if rand (* 2 %pierce_turret__kill_charger) ("crew_kill_place" place(charger) t(5))}
						{if rand (* 2 %pierce_turret__kill_charger2) ("crew_kill_place" place(charger2) t(5))}
						{if rand (* 2 %pierce_turret__kill_gunner) ("crew_kill_place" place(gunner) t(5))}
						{if rand (* 2 %pierce_turret__kill_gunner2) ("crew_kill_place" place(charger2) t(5))}
						{if rand (* 2 %pierce_turret__kill_gunner3) ("crew_kill_place" place(gunner3) t(5))}
						{if rand (* 2 %pierce_turret__kill_gunner4) ("crew_kill_place" place(gunner4) t(5))}
						{if rand (* 2 %pierce_turret__kill_commander) ("crew_kill_place" place(commander) t(5))}
					}
				}
				;("set_all_params_kill_crew"
				;	max_kill(%max_kill)
				;	charger(%pierce_turret__kill_charger)
				;	charger2(%pierce_turret__kill_charger2)
				;	driver(%pierce_turret__kill_driver)
				;	gunner(%pierce_turret__kill_gunner)
				;	commander(%pierce_turret__kill_commander)
				;	gunner2(%pierce_turret__kill_gunner2)
				;	gunner3(%pierce_turret__kill_gunner3)
				;	gunner4(%pierce_turret__kill_gunner4)
				;)
				;---contusion---
				{if operatable
					{if rand %pierce_rand_contusion
						("contusion" name(contusion_on_turret) time(%crew_shock_time))
					}
				}
				{if stuff "shell ap" {bullet_detonate}}
			}
			{if component "engine"
				{if hit_side back or hit_side bottom
					{if rand (* 2 %pierce_engine__engine_brake)
						{call "engine_broken"}
						{if rand (* 2 %pierce_engine__engine_burn)
							{delay 3 2
								{call "_burn"}
							}
						}
					else
						{if not flag "broken" 
							{damage_report "engine" "injured"}
						}	
					}
				else
					{if rand %pierce_engine__engine_brake
						{call "engine_broken"}
						{if rand %pierce_engine__engine_burn
							{delay 5 1
								{call "_burn"}
							}
						}
					}
				else
					{if not flag "broken" 
						{damage_report "engine" "injured"}
					}
				}
				{if flag "insta_kill"
					{if rand (* 0.66 %pierce_body__body_destroy) and explosive_amount 300 and inventory_item "shell fg"
						;{call "stat_break"} 
						{call "_explosion"} 
						{damage_report "inventory" "broken"}
					else rand (* 0.66 %pierce_body__body_brake) {call "mp_destroy"}
					else
						{call "mp_destroyed_off_realism"} 
					}
				}
				{if stuff "shell ap" {bullet_detonate}}
			}
			("component_turret" num(1)
				pierce_turret_front__turret_brake(%pierce_turret_front__turret_brake)
				pierce_turret_back__turret_brake(%pierce_turret_back__turret_brake)
				pierce_turret_left_right__turret_brake(%pierce_turret_left_right__turret_brake)
				;max_kill(%max_kill)
				;charger(%pierce_turret__kill_charger)
				;charger2(%pierce_turret__kill_charger2)
				;driver(%pierce_turret__kill_driver)
				;gunner(%pierce_turret__kill_gunner)
				;commander(%pierce_turret__kill_commander)
				;gunner2(%pierce_turret__kill_gunner2)
				;gunner3(%pierce_turret__kill_gunner3)
				;gunner4(%pierce_turret__kill_gunner4)
				;pierce_rand_contusion(%pierce_rand_contusion)
			)
			("component_turret" num(2)
				pierce_turret_front__turret_brake(%pierce_turret_front__turret_brake)
				pierce_turret_back__turret_brake(%pierce_turret_back__turret_brake)
				pierce_turret_left_right__turret_brake(%pierce_turret_left_right__turret_brake)
				;max_kill(%max_kill)
				;charger(%pierce_turret__kill_charger)
				;charger2(%pierce_turret__kill_charger2)
				;driver(%pierce_turret__kill_driver)
				;gunner(%pierce_turret__kill_gunner)
				;commander(%pierce_turret__kill_commander)
				;gunner2(%pierce_turret__kill_gunner2)
				;gunner3(%pierce_turret__kill_gunner3)
				;gunner4(%pierce_turret__kill_gunner4)
				;pierce_rand_contusion(%pierce_rand_contusion)
			)
			("component_turret" num(3)
				pierce_turret_front__turret_brake(%pierce_turret_front__turret_brake)
				pierce_turret_back__turret_brake(%pierce_turret_back__turret_brake)
				pierce_turret_left_right__turret_brake(%pierce_turret_left_right__turret_brake)
				;max_kill(%max_kill)
				;charger(%pierce_turret__kill_charger)
				;charger2(%pierce_turret__kill_charger2)
				;driver(%pierce_turret__kill_driver)
				;gunner(%pierce_turret__kill_gunner)
				;commander(%pierce_turret__kill_commander)
				;gunner2(%pierce_turret__kill_gunner2)
				;gunner3(%pierce_turret__kill_gunner3)
				;gunner4(%pierce_turret__kill_gunner4)
				;pierce_rand_contusion(%pierce_rand_contusion)
			)
			("component_turret" num(4)
				pierce_turret_front__turret_brake(%pierce_turret_front__turret_brake)
				pierce_turret_back__turret_brake(%pierce_turret_back__turret_brake)
				pierce_turret_left_right__turret_brake(%pierce_turret_left_right__turret_brake)
				;max_kill(%max_kill)
				;charger(%pierce_turret__kill_charger)
				;charger2(%pierce_turret__kill_charger2)
				;driver(%pierce_turret__kill_driver)
				;gunner(%pierce_turret__kill_gunner)
				;commander(%pierce_turret__kill_commander)
				;gunner2(%pierce_turret__kill_gunner2)
				;gunner3(%pierce_turret__kill_gunner3)
				;gunner4(%pierce_turret__kill_gunner4)
				;pierce_rand_contusion(%pierce_rand_contusion)
			)
			{if component "shield"
				{if rand %pierce_shield
					{component break}
				}
			}
		};stuff
    )

    (define "blast_damage_contusion" ;by Svoyak
		{if not flag "already_blasted"
			{if volume "trackleft"
				;do nothing
			else volume "trackright"
				;do nothing
			else volume "roller"
				;do nothing
			else volume "wheel_work"
				;do nothing
			else volume "wheel"
				;do nothing
			else
				{if operatable
					{if min_energy %blast_energy
						{set "already_blasted" 1}
						{if rand %blast_rand_contusion
							{delay 0.5
								{set "already_blasted" 0}
							}
							("contusion" name(contusion_on_body) time(%blast_crew_shock_time))
						else
							{delay 0.5
								{set "already_blasted" 0}
							}
						}
					}
				}
			}
		}
    )
;MEGA BUILDING END =============================================================================================================================================================================

	{on repair
	    {if component "turret"
    		{view stop "smoke3"}
            {call "update_turret"}
            {tags remove "turret_brake"}
        else component "body"
            {view stop "smoke4"} {view stop "smoke1"} {view stop "smoke4_2"}
            {call "update_turret"}
            {tags remove "turret_stopped_by_body"}
            {tags remove "body_brake"}
			{tags remove "body_break"}
			{set "broken" 0}
			{call "repair_body"}
			{call "mp_repair"}
        else component "engine"
            {tags remove "engine_brake"}
        }
    }
	
	 {on "repair_body"
		{if armor_health_percent 0.25
			{armor_health_damage -50}
			{delay 0.01 {call "repair_body"}}
		else
		}
	}
	
	(define "update_turret"
		{if work "turret%n"
			{if work "body"
				{ik_enable "turret%n" 1}
			 else
				{ik_enable "turret%n" 0}
			}
		else
			{ik_enable "turret%n" 0}
		}
	)
	{on "update_turret"
		("update_turret" n())
    }
	{on "bullet_stuck"	
		{if not stuff "ic" and not stuff "gr_ic"
			{if not stuff "fg" and not stuff "fr" and not stuff "bullet"
				{burn fx "hit_tank_armor_not_pierce" fake}
			}
		}
		{if not armor_health 1 and not flag "broken"
			{if not stuff "bullet" and not stuff "fg" and not stuff "fr"
				{talk "tank_bullet_reflect"}
				{call "talk_target_bullet_reflected"}
			}
		}
	}
	{on "bullet_reflect"	
		{if not armor_health 1 and not flag "broken"
			{if not stuff "bullet" and not stuff "fg" and not stuff "fr"
				{talk "tank_bullet_reflect"}
				{call "talk_target_bullet_reflected"}
			}
		}
	}
	{on pierce
		{if component "body" or component "turret"
			{burn fx "hit_tank_armor_pierce_wind" fake}
		else
			{burn fx "smoke_tank_damaged_armor_wind" fake}
		}
		{if not armor_health -399
			{if component "body" or component "turret" or component "turret1" or component "turret2" or component "turret3" or component "turret4"
				{talk "tank_pierce"}
				{call "talk_target_pierced"}
			}
		}
	}
	{on "talk_target_destroyed"
		{call "destroyed_by_spy"}
		{talk "tank_leave"}; это заглушка! удалить после того, как для talk "body_broken" добавят озвучку - пустой толк скипается системой
		{call "talk_target_destroyed_tank"}
	}
}; end of "tank"


{"opened tank"
	{on "explosive_broken" overload
			{call "explosion"}
	}
}
{"open_wheelhouse"
	{on spawn
		{set "open_wheelhouse" 1}
	}
}

{"turret"
	{on spawn
		{call "update_turret"}
	}
	{on "turret_break" overload
		{components "turret" break}
	}
	{on "turret_break_effects"
		{if not user_control
			{if rand 0.5 {kill_crew "gunner"}}
			{if rand 0.5 {kill_crew "charger"}}
			{if rand 0.5 {kill_crew "commander"}}
		}
;		{ani_play "open" -1.0 resume}
		{view start "smoke3"}
		{delay 10
			{view stop "smoke3"}
			{set "smoke3" 0}
		}
	}
	{on break
		(define "turret_break_effects"
			{call "update_turret%n"}
			{spawn "tank_die_particle" "turret%n"}
			{spawn "circledust_norm" "turret%n"}
			{call "turret_break_effects"}
		)
		{if component "turret"
			("turret_break_effects" n())
        else component "body"
			{spawn "circledust_norm" "Turret"}
			{call "update_turret"}
		}
	}
	{on "tear_turret"
		{if not flag "turret_teared"
			{set "turret_teared" 1}
			{components "turret" destroy}
			{if not flag "broken"				{call "mp_destroy"}}
			{add_view "smoke_black_big5" "smoke_turret" "basis"}
			{view start "smoke_turret"}
			{delay 60 15
				{view stop "smoke_turret"}
			}
			{delay_ex 0
				{tear "piece_large_steel" bone "turret" id "turret"
					{impulse up 3.0 2.5 dir 1.5 0.5 cx -0.5 1.0 cy -0.5 1.0 rnd_dir 0.5 0.1 no_position}
					{if rand 0.25 {impulse up 3.0 no_position}}
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
}

{"medium tank turret"
	{on bullet_hit
		{if relation "enemy" and component "turret"
			{if stuff "big shell"
				{if rand 0.2
					{call "turret_break"}
				}
			}
		}
	}
}
{"heavy tank turret"
	{on bullet_hit
		{if relation "enemy" and component "turret"
			{if stuff "big shell"
				{if rand 0.1
					{call "turret_break"}
				}
			}
		}
	}
}

{"light tank turret"
	{on bullet_hit
		{if relation "enemy" and component "turret"
			{if stuff "big shell fg" or stuff "big shell fr"
				{if rand 0.8
					{call "tear_turret"}
				}
			}
		}
	}
}

{"light_turret" ; turret for btr, car, ...
	{on bullet_hit
		{if relation "enemy" and component "turret"
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
	{on fire "gun"
            {spawn "dust_shot_small" "basis"}
            {spawn "tank_canon_fire_small" "Foresight1" x}
			{ani_play "fire"}			
	}
	{on armor_health_damage
		{if name "blastwave" and not flag "in_water"
			{if min_energy 8.7;105mm	;8
				{impulse up 0.1 dir 0.3 0.1}
			 ;else min_energy 1
				;{impulse up 0.4 0.2 dir 0.4 0.2}
			 ;else min_energy 0.4
				;{ani_play "hit"}
			}
		}
	}
	{on "_explosion"
		{fragments c4 1 r0 1 r1 5}
		{impulse up 0.1 dir 0.3 0.1}
	}
	{on "talk_target_destroyed" overload
		{call "destroyed_by_spy"}
		{talk "tank_leave"}
		{call "talk_target_destroyed_armored_car"}
	}
	{on "mp_destroy" overload
		{call "mp_destroy_main"}
	}
(include "tank-armoredcar.inc")
(include "tank-armoredcar_strikes.inc")
}

{"armored_car muzzle_brake"
	{on fire "gun" overload
            {spawn "dust_shot_small" "basis"}
            {spawn "tank_canon_fire_small_muz" "Foresight1" x}
			{ani_play "fire"}			
	}
}

{"light tank"
	{on spawn
		{add_view	"flash_cannon_small"		"flashbarrel1"			"Foresight1"}
		{add_view "flash_gun_big01" "light_tank_mgun1" "foresight3"}
	}
	{on fire "mgun" 
		{view start	"light_tank_mgun1"}
		{delay 0.5 
			{view pause	"light_tank_mgun1"}
		}
	}
	{on fire "gun"
		{spawn "dust_shot_small" "basis"}
        {spawn "tank_canon_fire_small" "Foresight1" x}
		{ani_play "fire"}		
	}
	{on armor_health_damage
		{if name "blastwave" and not flag "in_water"
			{if min_energy 30
				{if stuff "mine antitank"
					{impulse up 0.1 dir 0.3 0.1}
				else
					{impulse up 0.1 dir 0.3 0.1}
					{##if volume "turret"
						{call "tear_turret"}
					}
				}
			else min_energy  8.7;105mm		;9
				{impulse up 0.1 dir 0.3 0.1}
	;			{call "tear_turret"}
			 ;else min_energy 6
				;{impulse up 0.4 0.1 dir 0.7 0.2}
	;			;{if rand 0.6 {call "tear_turret"}}
			 ;else min_energy 1
				;{ani_play "hit"}
			}
		}
	}
	{on "_explosion"
		{fragments c4 4 r0 2 r1 8}
		{impulse up 0.1 dir 0.4 0.1}
	}
(include "tank-light.inc")
(include "tank-light_strikes.inc")
}

{"light tank muzzle_brake"
	{on fire "gun" overload
		{spawn "dust_shot_small" "basis"}
        {spawn "tank_canon_fire_small_muz" "Foresight1" x}
		{ani_play "fire"}		
	}
}

{"medium tank"
	{inflammation_time 30}
	{on fire "gun"
       	{spawn "dust_shot_norm" "basis"}
        {spawn "tank_canon_fire" "Foresight1" x}
		{fragments c4 0.2 r0 1 r1 2.5 bone "Foresight1"}
		{ani_play "fire"}		
	}

	{on armor_health_damage
		{if name "blastwave" and not flag "in_water"
			{if min_energy 30
				{if stuff "mine antitank"
					{impulse up 0.1 dir 0.3 0.1}
				else
					{impulse up 0.1 dir 0.3 0.1}
					{##if volume "turret"
						{if rand 0.8
							{call "tear_turret"}
						}
					}
				}
			else min_energy 12
				{impulse up 0.1 dir 0.3 0.1}
				{##if volume "turret"
					{if rand 0.5
						{call "tear_turret"}
					}
				}
			 else min_energy 9
				{impulse up 0.1 dir 0.3 0.1}
			 else min_energy 8.7;105mm		;7
				{impulse up 0.1 dir 0.1}
			 ;else min_energy 1
				;{ani_play "hit"}
			}
		}
	}
	{on "_explosion"
		{fragments c4 8 r0 3 r1 10}
		{impulse up 0.1 dir 0.4 0.1}
	}
	{on "check_water_level" overload
		{if water_level 1.6
			{able "sinking" 1}
		}
	}
(include "tank-medium.inc")
(include "tank-medium_strikes.inc")
}

{"heavy tank"
	{inflammation_time 35}
	{on fire "gun"
		{spawn "dust_shot_big" "basis"}
		{spawn "tank_canon_fire" "Foresight1" x}
		{fragments c4 0.2 r0 1 r1 2.5 bone "Foresight1"}
		{ani_play "fire"}		
	}
	{on armor_health_damage
		{if name "blastwave" and not flag "in_water"
			{if min_energy 30
				{if stuff "mine antitank"
					{impulse up 0.1 dir 0.3 0.1}
				else
					{impulse up 0.1 dir 0.3 0.1}
					{##if volume "turret"
						{if rand 0.5
							{call "tear_turret"}
						}
					}
				}
			else min_energy 14
				{impulse up 0.1 dir 0.3 0.1}
				{##if volume "turret"
					{if rand 0.3
						{call "tear_turret"}
					}
				}
			else min_energy 8.7;105mm		;8
				{impulse up 0.1 dir 0.1}
			;else min_energy 3
				;{ani_play "hit"}
			}
		}
	}
	{on "_explosion"
                {fragments c4 10 r0 6 r1 12}
		{impulse up 0.1 dir 0.4 0.1}
	}
	{on "check_water_level" overload
		{if water_level 1.8
			{able "sinking" 1}
		}
	}
(include "tank-heavy.inc")
(include "tank-heavy_strikes.inc")
}

{"mine_exploder"
	{on spawn
		{bone hide "wheel_work"}
		{add_view "dustrun_sand_dirt"	"wheel_work_dust"	"FXWheel_Work1"}
		{add_view "dustrun_sand_dirt"	"wheel_work_dust"	"FXWheel_Work2"}
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
(define "flakpz1_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/01" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/00" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/01"	 user_control}		
		{link_sound "rotate_turret"			"vehicle/groundborne/motions/weapon_manual_rotate" user_control}		
	}
)
(define "pz1_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/01" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/00" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_light_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_light_close" user_control}		
		("%rotate_turret")
	}
)

(define "rotate_turret_light"
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/01" user_control}
)
{"pz1 tank"
	("flakpz1_sound")
}

{"pz1c tank"
	("pz1_sound"	rotate_turret(none))
}
{"sturmpz1 tank"
	("flakpz1_sound")
}
(define "pz1c_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/00" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/01" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/02" user_control}		
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_light_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_light_close" user_control}			
	}
)
{"pz1c tank"
	("pz1c_sound")
}
{"ht26 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/01" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/00" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/02" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_light_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_light_close" user_control}		
	}
	{on bullet_hit
	    {if relation "enemy" or relation "neutral"
	    	{if stuff "150to152"
			    {call "_explosion"}
	    	else stuff "122to128"
			    {call "_explosion"}
	    	else stuff "88to105"
			    {call "_burn"}
			}
	    }
	}
}
(define "t26_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/01" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/00" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/01" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_light_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_light_close" user_control}		
	}
)
(define "lt_turret_sound"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/02" user_control}
	}
)
{"t26 tank"
	("t26_sound")
}
{"t26e tank"
	("t26_sound")
}
{"carro15 tank"
   {on spawn
		{add_view	"flash_gun_big01"	"flashbarrel01"	"shooter00"	}
		{add_view	"flash_gun_big01"	"flashbarrel011"	"shooter01"	}
		{add_view "flash_gun_big01" "light_tank_mgun1_a" "foresight5"}
	}
	{on fire "mgun" overload
		{view start	"light_tank_mgun1_a"}
		{delay 0.5 
			{view pause	"light_tank_mgun1_a"}
		}
	}
	{on fire "mgun1" overload
		{if  name "00"
			{view start "flashbarrel01"}
		else name "01"
			{view start "flashbarrel011"}
		}
	}
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/02" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/02" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/02"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/02"	 user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/02" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_light_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_light_close" user_control}
	}
}
(define "su76_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/01" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/00" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/01"	 user_control}
	}
)
{"su76 tank"
	("su76_sound")
}
(define "t40_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/01" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/00" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/motions/weapon_manual_rotate" user_control}		
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_light_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_light_close" user_control}		
	}
)
{"t40 tank"
	("t40_sound")
}
{"t40_tns tank"
	("t40_sound")
}
{"t60 tank"
	("t40_sound")
}
(define "t70_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/01" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/00" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/02" user_control}		
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_light_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_light_close" user_control}		
	}
)
{"t70 tank"
	("t70_sound")
}
{"zsu37 tank"
	("t70_sound")
}
{"bt7a tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/02" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/02" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/02"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/02"	 user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/03" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_light_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_light_close" user_control}			
	}
}
(define "bt7_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/02" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/02" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/02"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/02"	 user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/02" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_light_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_light_close" user_control}	
	}
)
{"bt7 tank"
	("bt7_sound")
}
{"bt7_ger tank"
	("bt7_sound")
}

(define "kv_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/kv1/kv1_tracks" user_control}	
		{link_sound "engine"			"vehicle/groundborne/kv1/kv1_engine" user_control}
		{link_sound "engine_idle"		""}
		{link_sound "engine_end"		"vehicle/groundborne/kv1/kv1_engine_stop" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/kv1/kv1_engine_start" user_control}
		{link_sound "exhaust"			"vehicle/groundborne/kv1/kv1_exhaust" user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/kv1/kv1_turret" user_control}
		{link_sound "open"				"vehicle/groundborne/motions/tank_hatch_heavy_open"	 user_control}	
		{link_sound "close"				"vehicle/groundborne/motions/tank_hatch_heavy_close" user_control}	
	}
	{on "delay_play_engine" overload
		{delay_effect 1.5 "play_engine"}
	}	
)
(define "is_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/is1/is1_tracks"				 user_control}	
		{link_sound "engine"			"vehicle/groundborne/is1/is1_engine"				 user_control}
		{link_sound "engine_idle"		""													 user_control}
		{link_sound "engine_end"		"vehicle/groundborne/is1/is1_engine_stop"			 user_control}
		{link_sound "engine_start"		"vehicle/groundborne/is1/is1_engine_start"			 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/is1/is1_exhaust"				 user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/is1/is1_turret"				 user_control}
		{link_sound "open"				"vehicle/groundborne/motions/tank_hatch_heavy_open"	 user_control}	
		{link_sound "close"				"vehicle/groundborne/motions/tank_hatch_heavy_close" user_control}	
	}
	{on "delay_play_engine" overload
		{delay_effect 1.5 "play_engine"}
	}	
)
{"kv1_za_rodinu tank"
	("kv_sound")
}
{"kv1 tank"
	("kv_sound")
}
{"kv1e tank"
	("kv_sound")
}
{"su152 tank"
	("kv_sound")
}
{"kv8 tank"
	("kv_sound")
	{on spawn
		{add_view "flamer_fire" "flame1" "foresight5"}
		{add_view "flamer_fire_barrel" "fire1" "foresight5"}
		{view show	"fire1"}
		{view start	"fire1"}
		("jet_of_fire_sound_init_default")
	}
	{on fire "flamer1"
		{view start	"flame1"}
		{kill_delay "fire1"}
		("jet_of_fire_sound_play_default")
		{delay 0.5 "fire1"
			{view pause	"flame1"}
		}
		("jet_of_fire_sound_stop_default")
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{fragments c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	{on bullet_hit
	    {if relation "enemy" or relation "neutral"
	    	{if stuff "150to152"
			    {call "_burn"}
	    	else stuff "ap 122to128"
			    {if rand 0.5 {call "_burn"}}
	    	else stuff "ap 88to105"
			    {if rand 0.25 {call "_burn"}}
			}
	    }
	}
	{on pierce
	    {if bullet_damage
	    {if stuff "gr_ic"
		    {if rand 0.5 {call "_burn"}}
		else
			{if rand 0.15 {call "_burn"}}
		}
		}		
	}
}
{"kv1s tank"
	("kv_sound")
}
{"kv1_zis5 tank"
	("kv_sound")
}
{"kv2 tank"
	("kv_sound")
}
{"kv85 tank"
	("kv_sound")
}
{"is1 tank"
	("is_sound")
}
{"is2 tank"
	("is_sound")
}
{"is2_early"
	("is_sound")
}
{"is2_44 tank"
	("is_sound")
}
{"is3 tank"
	{on spawn
		{bone show "bdsh1"} {bone show "bdsh2"} 
		{volumes "bdsh1" enable bullet blast}
		{volumes "bdsh2" enable bullet blast}
		{tags remove "smoke_gl_reload"}
		{tags remove "bdsh1_damaged"}
		{tags remove "bdsh2_damaged"}
	}
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/is3/is3_tracks"				 user_control}	
		{link_sound "engine"			"vehicle/groundborne/is3/is3_engine"				 user_control}
		{link_sound "engine_idle"		""													 user_control}
		{link_sound "engine_end"		"vehicle/groundborne/is3/is3_engine_stop"			 user_control}
		{link_sound "engine_start"		"vehicle/groundborne/is3/is3_engine_start"			 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/is3/is3_exhaust"				 user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/is3/is3_turret"				 user_control}
		{link_sound "open"				"vehicle/groundborne/motions/tank_hatch_heavy_open"	 user_control}	
		{link_sound "close"				"vehicle/groundborne/motions/tank_hatch_heavy_close" user_control}	
	}
	{on "delay_play_engine" overload
		{delay_effect 1.5 "play_engine"}
	}
	(define "spawn_grenade_smoke"
		{bone hide "%bone"} {volumes "%bone" disable bullet blast}
		{spawn "bdsh_is" "%bone" x
			{call "add_smoke"}
			{call "onThrow"}
			{call "activate"}
			{impulse up 0 forward -5 1}
		}
	)
	{on "smoke_shot" overload
		{if not tagged "smoke_gl_reload"
			{if tagged "1st_shot"
				("spawn_grenade_smoke" bone(bdsh2))
				{tags add "smoke_gl_reload"} {tags remove "1st_shot"} 
				{delay 120 
					{bone show "bdsh1"} {bone show "bdsh2"} 
					{volumes "bdsh1" enable bullet blast}
					{volumes "bdsh2" enable bullet blast}
					{tags remove "smoke_gl_reload"}
					{tags remove "bdsh1_damaged"}
					{tags remove "bdsh2_damaged"}
				}
				else 
				("spawn_grenade_smoke" bone(bdsh1))
				{tags add "1st_shot"}
			}
		}
	}
	(define "smoke_gl_damaged"
		{if volume "bdsh1" or volume "bdsh2"
			{if volume "bdsh1" and not tagged "bdsh1_damaged" {add_view "smoke_cover-up_small"	"smoke1" "bdsh1"} {view start "smoke1"} {tags add "bdsh1_damaged"}
			else volume "bdsh2" and not tagged "bdsh2_damaged" {add_view "smoke_cover-up_small"	"smoke2" "bdsh2"} {view start "smoke2"} {tags add "bdsh2_damaged"}
			{link_sound "smoke" "detonation/smoke_grenade/smoke_grenade"}
			{play_sound "smoke"}
			}
			{delay 3 {view stop "smoke1"} {stop_sound "smoke"} {call "smoke_shot"}}
			{delay 4 {view stop "smoke2"} {call "smoke_shot"}}
		}
	)
	{on pierce
		("smoke_gl_damaged")
	}
	{on blast
		{if min_energy 2 ("smoke_gl_damaged")}
	}	
}
{"m26 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/01" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/00" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/01" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/00" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_heavy_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_heavy_close" user_control}		
	}
}
{"m26e4 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/01" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/00" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/01" user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/00" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_heavy_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_heavy_close" user_control}			
	}
}
{"t95 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/is1/is1_tracks"	user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/00" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/01" user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_heavy_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_heavy_close" user_control}			
	}
}
{"t28 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/01" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/00" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/01" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_heavy_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_heavy_close" user_control}		
	}
}
{"t29 tank"
	{on spawn
		{add_view	"flash_gun_big01"	"flashbarrel00"	"shooter00"}
		{add_view	"flash_gun_big01"	"flashbarrel011"	"shooter01"}
	}
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/01" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/00" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/01" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/00" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_heavy_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_heavy_close" user_control}			
	}
	{on fire "mgun2"
		{if  name "00"
			{view start "flashbarrel00"}
		else name "01"
			{view start "flashbarrel011"}
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
					{impulse up 15 5 rnd_dir 3}
				}
				{tear "piece_medium_steel" bone "part4" id "turret"
					{impulse up 15 5 rnd_dir 3}
				}
				{tear "piece_large_steel" bone "turret" id "turret"
					{impulse up 1.5 0.3 dir 3 1.5 cx 5 2 cy 5 2 rnd_dir 10 no_position}
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
}
{"isu152 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/is1/is1_tracks" user_control}	
		{link_sound "engine"			"vehicle/groundborne/is1/is1_engine"	 user_control}
		{link_sound "engine_idle"		""}
		{link_sound "engine_end"		"vehicle/groundborne/is1/is1_engine_stop"	 user_control}
		{link_sound "engine_start"		"vehicle/groundborne/is1/is1_engine_start" user_control}
		{link_sound "exhaust"			"vehicle/groundborne/is1/is1_exhaust" user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/is1/is1_turret" user_control}
		{link_sound "open"				"vehicle/groundborne/motions/tank_hatch_heavy_open"	 user_control}	
		{link_sound "close"				"vehicle/groundborne/motions/tank_hatch_heavy_close" user_control}	
	}
	{on "delay_play_engine" overload
		{delay_effect 1.5 "play_engine"}
	}	
;	{on fire "gun"
;		{spawn "tagged_piece"}
;	}
}
{"isu122 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/is1/is1_tracks" user_control}	
		{link_sound "engine"			"vehicle/groundborne/is1/is1_engine"	 user_control}
		{link_sound "engine_idle"		""}
		{link_sound "engine_end"		"vehicle/groundborne/is1/is1_engine_stop"	 user_control}
		{link_sound "engine_start"		"vehicle/groundborne/is1/is1_engine_start" user_control}
		{link_sound "exhaust"			"vehicle/groundborne/is1/is1_exhaust" user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/is1/is1_turret" user_control}
		{link_sound "open"				"vehicle/groundborne/motions/tank_hatch_heavy_open"	 user_control}	
		{link_sound "close"				"vehicle/groundborne/motions/tank_hatch_heavy_close" user_control}	
	}
	{on "delay_play_engine" overload
		{delay_effect 1.5 "play_engine"}
	}	
}	
(define "t34_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/t34/t34_tracks" user_control}
		{link_sound "engine"			"vehicle/groundborne/t34/t34_engine" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/00" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/t34/t34_engine_start" user_control}
		{link_sound "exhaust"			"vehicle/groundborne/t34/t34_exhaust" user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/t34/t34_turret"	 user_control}
		{link_sound "open"				"vehicle/groundborne/motions/tank_hatch_medium_open" user_control}	
		{link_sound "close"				"vehicle/groundborne/motions/tank_hatch_medium_close" user_control}			
	}
	{on "delay_play_engine" overload
		{delay_effect 1.5 "play_engine"}
	}
)
(define "t34_spg_sound"	
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/t34/t34_tracks" user_control}
		{link_sound "engine"			"vehicle/groundborne/t34/t34_engine" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/00" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/t34/t34_engine_start" user_control}
		{link_sound "exhaust"			"vehicle/groundborne/t34/t34_exhaust" user_control}
		{link_sound "open"				"vehicle/groundborne/motions/tank_hatch_medium_open" user_control}	
		{link_sound "close"				"vehicle/groundborne/motions/tank_hatch_medium_close" user_control}		
	}
	{on "delay_play_engine" overload
		{delay_effect 1.5 "play_engine"}
	}
)
{"t34_0 tank"
	("t34_sound")
}
{"t34_76 tank"
	{on "init_gun"
		{call "add_view_mgun"}
	}
	("t34_sound")
}
{"t34_76_inf tank"
	{on "init_gun"
		{call "add_view_mgun"}
	}
	("t34_sound")
}
{"t34_76_41 tank"
	("t34_sound")
}
{"t34_armored tank"
	{on "init_gun"
		{call "add_view_mgun"}
	}
	("t34_sound")
}
{"t34_1 tank"
	("t34_sound")
}
{"t34_57_43 tank"
	("t34_sound")
}
{"t34_2 tank"
	("t34_sound")
}
{"ot34_76_42 tank"
	("t34_sound")
	{on spawn	
		{add_view "flamer_fire" "flame1" "foresight9"}
		{add_view "flamer_fire_barrel" "fire1" "foresight9"}
		{add_view "flamer_fire_barrel_active" "fire_1" "foresight9"}
		
		{view show	"fire1"}
		{view start	"fire1"}
		
		("jet_of_fire_sound_init_default")
	}
	{on bullet_hit
	    {if relation "enemy" or relation "neutral"
	    	{if stuff "150to152"
			    {call "_burn"}
	    	else stuff "ap 122to128"
			    {if rand 0.5 {call "_burn"}}
	    	else stuff "ap 88to105"
			    {if rand 0.25 {call "_burn"}}
			}
	    }
	}
	{on pierce
	    {if bullet_damage
			{if stuff "gr_ic"
				{if rand 0.5 {call "_burn"}}
			else
				{if rand 0.15 {call "_burn"}}
			}
		}		
	}
	{on fire "flamer1"
		{view start	"flame1"}{view pause "fire1"}{view start	"fire_1"}
		{kill_delay "fire1"}
		("jet_of_fire_sound_play_default")
		{delay 0.5 "fire1"
			{view pause	"flame1"}{view start "fire1"}{view pause	"fire_1"}
		}
		("jet_of_fire_sound_stop_default")
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{fire radius 8 time 15 heating 10}
	}
}
{"t34_3 tank"
	("t34_sound")
}
{"su85 tank"
	("t34_spg_sound")
}
{"su122 tank"
	("t34_spg_sound")
}
{"su100 tank"
	("t34_spg_sound")
}
{"t34_3 tank"
	("t34_sound")
}
{"t34_85 tank"
	("t34_sound")
}
{"t34_85_po tank"
	("t34_sound")
}
{"t34_85m tank"
	("t34_sound")
}
{"t34_85m_po tank"
	("t34_sound")
}
(define "pz5g_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/jagdpanther/jagdpanther_tracks" user_control}	
		{link_sound "engine"			"vehicle/groundborne/jagdpanther/jagdpanther_engine" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/jagdpanther/jagdpanther_engine_stop" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/jagdpanther/jagdpanther_engine_start" user_control}
		{link_sound "exhaust"			"vehicle/groundborne/jagdpanther/jagdpanther_exhaust" user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/03" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_medium_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_medium_close" user_control}	
		{link_sound "engine_idle"		""}				
	}
	{on "delay_play_engine" overload
		{delay_effect 1.5 "play_engine"}
	}	
)
{"pz5a tank"
	("pz5g_sound")
}
{"pz5a_po tank"
	("pz5g_sound")
}
{"pz5g tank"
	("pz5g_sound")
}

{"ho-ri tank"
	("pz5g_sound")
}
{"ho-ri_1 tank"
	("pz5g_sound")
}
{"chi-ri tank"
	("pz5g_sound")
}

(define "m8_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/00" user_control}	
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/00" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/01" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/01" user_control}		
	}
)
{"m8 tank"
	("m8_sound")
}
(define "m3a1_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/00" user_control}	
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/00" user_control}		
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/01" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/01" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_light_open user_control"}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_light_close" user_control}		
	}
)
{"m3a1 tank"
	("m3a1_sound")
}
{"m5a1 tank"
	("m3a1_sound")
}
{"lvt1 tank"
	("m3a1_sound")
}
{"lvt4 tank"
	("m3a1_sound")
}
{"mk2a tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/01" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/00" user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/00" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_heavy_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_heavy_close" user_control}			
	}
}

(define "mk7_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/01" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/00" user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/00" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_light_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_light_close" user_control}			
	}
)
{"mk7 tank"
	("mk7_sound")
}
(define "bishop_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/01" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/02" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/02" user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/01" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/02"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/02"	 user_control}
	}
)
{"bishop tank"
	("bishop_sound")
}
(define "valentine_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/01" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/02" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/02" user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/01" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/02"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/02"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_medium_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_medium_close" user_control}		
	}
)
{"mk3 tank"
	("valentine_sound")
}
{"valentine_rus tank"
	("valentine_sound")
}
(define "mk6_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/01" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/00" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/01" user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/02" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_medium_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_medium_close" user_control}		
	}
)
{"mk6 tank"
	("mk6_sound")
}
{"crusaderaa1 tank"
	("mk6_sound")
}
{"crusaderaa2 tank"
	("mk6_sound")
}
(define "mk4_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/02" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/02" user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/02" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/02"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/02"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_heavy_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_heavy_close" user_control}			
	}
)
{"mk4 tank"
	("mk4_sound")
}
{"mk4_rus tank"
	("mk4_sound")
}

{"mk8 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/01" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/00" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/01" user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/02" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_medium_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_medium_close" user_control}		
	}
}
{"tortez tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/01" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/00" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/01" user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/02" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_heavy_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_heavy_close" user_control}		
	}
}
{"m4a3m tank"
	{on spawn
		{delay 0.1 
			{view hide "light"}{bone cut "headlightL"}{bone cut "headlightR"}
		}
	}
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/01" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/00" user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/00" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_medium_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_medium_close" user_control}		
	}
}
(define "m4_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/01" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/00" user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/00" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_medium_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_medium_close" user_control}		
	}
)
(define "m4_turret_sound"
	{on "add_movement_sound"
		{link_sound "rotate_turret"     "vehicle/groundborne/m4/m4_turret"}
	}
)
{"m12gmc tank"
	("m4_sound")
}
{"m4a3_105 tank"
	("m4_sound")
}
{"m4a3_75 tank"
	("m4_sound")
}
{"m4a4 tank"
	("m4_sound")
}
{"m4a3e8 tank"
	("m4_sound")
}
{"m4a3e8_po tank"
	("m4_sound")
}
{"m4a3_zippo tank"
	{on spawn
		{add_view "flamer_fire_far" "flame1" "foresight9"}
		{add_view "flamer_fire_barrel" "fire1" "foresight9"}
		{view show	"fire1"}
		{view start	"fire1"}
		("jet_of_fire_sound_init_default")
	}
	{on operatable on	
		{view start	"fire1"}
	}	
	{on operatable off		
		{view stop	"fire1"}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{fragments c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	{on fire "flamer1"
		{view start	"flame1"}
		{kill_delay "fire1"}

		("jet_of_fire_sound_play_default")
		{delay 0.5 "fire1"
			{view pause	"flame1"}
		}
		("jet_of_fire_sound_stop_default")
	}
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/01" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/00" user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/00" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_medium_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_medium_close" user_control}		
	}
	{on bullet_hit
	    {if relation "enemy" or relation "neutral"
	    	{if stuff "150to152"
			    {call "_explosion"}
	    	else stuff "ap 122to128"
			    {call "_burn"}
	    	else stuff "ap 88to105"
			    {if rand 0.5 {call "_burn"}}
			}
	    }
	}
	{on pierce
	    {if bullet_damage
	    {if stuff "gr_ic"
		    {if rand 0.5 {call "_burn"}}
		else
			{if rand 0.15 {call "_burn"}}
		}
		}		
	}
}
{"m4a3e2_jumbo_76 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/01" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/00" user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/00" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_medium_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_medium_close" user_control}		
	}
	("burn_by_engine" args 0.3)
}
{"m4a1 tank"
	("m4_sound")
}
{"m4a1_inf tank"
	("m4_sound")
}
{"m4a1_eng tank"
	("m4_sound")
}
{"m4_105 tank"
	("m4_sound")
}
{"m4a3c tank"
	("m4_sound")
	{on fire "guns"
		(define "fire_barrel"
			name "%0"
				{spawn "startsmoke_cali" "barrel%0" x}
		)
		
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		  else ("fire_barrel" args 04)
		  else ("fire_barrel" args 05)
		  else ("fire_barrel" args 06)
		  else ("fire_barrel" args 07)
		  else ("fire_barrel" args 08)
		  else ("fire_barrel" args 09)

		  else ("fire_barrel" args 10)
		  else ("fire_barrel" args 11)
		  else ("fire_barrel" args 12)
		  else ("fire_barrel" args 13)
		  else ("fire_barrel" args 14)
		  else ("fire_barrel" args 15)
		  else ("fire_barrel" args 16)
		  else ("fire_barrel" args 17)
		  else ("fire_barrel" args 18)
		  else ("fire_barrel" args 19)

		  else ("fire_barrel" args 20)
		  else ("fire_barrel" args 21)
		  else ("fire_barrel" args 22)
		  else ("fire_barrel" args 23)
		  else ("fire_barrel" args 24)
		  else ("fire_barrel" args 25)
		  else ("fire_barrel" args 26)
		  else ("fire_barrel" args 27)
		  else ("fire_barrel" args 28)
		  else ("fire_barrel" args 29)

		  else ("fire_barrel" args 30)
		  else ("fire_barrel" args 31)
		  else ("fire_barrel" args 32)
		  else ("fire_barrel" args 33)
		  else ("fire_barrel" args 34)
		  else ("fire_barrel" args 35)
		  else ("fire_barrel" args 36)
		  else ("fire_barrel" args 37)
		  else ("fire_barrel" args 38)
		  else ("fire_barrel" args 39)

		  else ("fire_barrel" args 40)
		  else ("fire_barrel" args 41)
		  else ("fire_barrel" args 42)
		  else ("fire_barrel" args 43)
		  else ("fire_barrel" args 44)
		  else ("fire_barrel" args 45)
		  else ("fire_barrel" args 46)
		  else ("fire_barrel" args 47)
		  else ("fire_barrel" args 48)
		  else ("fire_barrel" args 49)

		  else ("fire_barrel" args 50)
		  else ("fire_barrel" args 51)
		  else ("fire_barrel" args 52)
		  else ("fire_barrel" args 53)
		  else ("fire_barrel" args 54)
		  else ("fire_barrel" args 55)
		  else ("fire_barrel" args 56)
		  else ("fire_barrel" args 57)
		  else ("fire_barrel" args 58)
		  else ("fire_barrel" args 59)
		}
	}
}
{"m4a3dd tank"
	("m4_sound")
}
{"m4a2 tank"
	("m4_sound")
}
{"m4a2_rus tank"
	("m4_sound")
}
(define "m10wolverine_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/01" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/00" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/01" user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/02" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_medium_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_medium_close" user_control}		
	}
)
{"m10wolverine tank"
	("m10wolverine_sound")
	{on "gunner_hatch_open" overload
		{ani_play "open" -1.0 resume}
	}
	("burn_by_engine" args 0.3)
}
{"m36 tank"
	("m4_sound")
}
{"m4a3vc tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/01" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/00" user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/00" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_medium_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_medium_close" user_control}		
	}
}
{"m4a3e2 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/01" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/00" user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/00" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_medium_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_medium_close" user_control}		
	}
}

(define "m7_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/01" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/00" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/01" user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/02" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/00"	 user_control}
	}
)
{"m7 tank"
	("m7_sound")
}
{"m19 tank"
	("m7_sound")
}
{"m10wolverine tank"
	("m7_sound")
}
{"m10achilles tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/01" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/00" user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/00" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/01"	 user_control}
	}
}
{"jagdpanther tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/jagdpanther/jagdpanther_tracks" user_control}	
		{link_sound "engine"			"vehicle/groundborne/jagdpanther/jagdpanther_engine" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/jagdpanther/jagdpanther_engine_stop" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/jagdpanther/jagdpanther_engine_start" user_control}
		{link_sound "exhaust"			"vehicle/groundborne/jagdpanther/jagdpanther_exhaust" user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/jagdpanther/jagdpanther_turret" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_medium_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_medium_close" user_control}		
	}
	{on "delay_play_engine" overload
		{delay_effect 1.5 "play_engine"}
	}	
}



{"jagdtiger tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/jagdpanther/jagdpanther_tracks" user_control}	
		{link_sound "engine"			"vehicle/groundborne/jagdpanther/jagdpanther_engine" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/jagdpanther/jagdpanther_engine_stop" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/jagdpanther/jagdpanther_engine_start" user_control}
		{link_sound "exhaust"			"vehicle/groundborne/jagdpanther/jagdpanther_exhaust" user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/jagdpanther/jagdpanther_turret" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_heavy_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_heavy_close" user_control}		
	}
	{on "delay_play_engine" overload
		{delay_effect 1.5 "play_engine"}
	}
}
(define "hetzer_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/01" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/00" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_light_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_light_close" user_control}		
	}
)
{"hetzer tank"
	("hetzer_sound")
}
{"pz38g tank"
	("hetzer_sound")
}
{"marder3 tank"
	("hetzer_sound")
}
{"pz35t tank"
	("hetzer_sound")
}
;________________________________________________________________________________APC
;GER
(define "ab41_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/wheels/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/00" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/01" user_control}	
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/car_door_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/car_door_close" user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/01" user_control}		
	}
)
{"ab41 tank"
	("ab41_sound")
}
(define "sdkfz222_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/wheels/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/00" user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/01" user_control}		
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/01" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/car_door_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/car_door_close" user_control}		
	}
)
{"sdkfz221 tank"
	("sdkfz222_sound")
}
{"sdkfz222 tank"
	("sdkfz222_sound")
}
{"sdkfz223 tank"
	("sdkfz222_sound")
}
(define "sdkfz232_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/wheels/00" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/01" user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/01" user_control}		
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_light_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_light_close" user_control}			
	}
)
{"sdkfz232 tank"
	("sdkfz232_sound")
}
(define "sdkfz234_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/wheels/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/00" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/01" user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/01" user_control}		
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_light_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_light_close" user_control}			
	}
)
{"sdkfz234 tank"
	("sdkfz234_sound")
}
(define "hanomag_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/01" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/00" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/01" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/car_door_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/car_door_close" user_control}			
	}
)
{"sdkfz251c tank"
	("hanomag_sound")
}
{"sdkfz251b tank"
	("hanomag_sound")
}
{"sdkfz251d tank"
	("hanomag_sound")
}
{"sdkfz251d_g tank"
	("hanomag_sound")
}
{"sdKfz251 tank"
	("hanomag_sound")
}
{"sdKfz251_1 tank"
	("hanomag_sound")
}
{"sdKfz251d tank"
	("hanomag_sound")
}
{"sdKfz251_6 tank"
	("hanomag_sound")
}
{"sdKfz251_9 tank"
	{on fire "gun"
		{call "spawn_shell"}
		{ani_play "fire"}		
	}
	{on "spawn_shell"
		{start_sound "weapon/shot/shell"}
		{add_view "smoke_zenit" "smoke_shell" "fx_invers"}
		{view start "smoke_shell"}
		{delay 2.5 0.5
			{view stop "smoke_shell"}
		}
		{spawn "shell_cannon" "fx_invers" x scale 0.014
			{impulse up 0.5 -0.5 dir -1.3 0.7 cz 0.2 0.1 com}
			{add_view "smoke_zenit" "smoke_shell" "fx_shellsmoke"}
			{view start "smoke_shell"}
			{delay_effect 3 1 "stop"}
			{delay 3 0.5
				{hide 3}
			}
		}
	}
	("hanomag_sound")
}
{"sdKfz251_10 tank"
	("hanomag_sound")
}
{"sdKfz251_10c tank"
	("hanomag_sound")
	{on "gunner_hatch_open" overload}
}
{"sdKfz251_16 tank"
	("hanomag_sound")
	{on "gunner_hatch_open" overload}
}
{"sdKfz251_17 tank"
	("hanomag_sound")
	{on "gunner_hatch_open" overload}
}
{"sdKfz251_22 tank"
	("hanomag_sound")
	{on fire "gun"
		{call "spawn_shell"}
		{ani_play "fire"}		
	}
	{on "gunner_hatch_open" overload}
	{on "spawn_shell"
		{start_sound "weapon/shot/shell"}
		{add_view "smoke_zenit" "smoke_shell" "fx_invers"}
		{view start "smoke_shell"}
		{delay 2.5 0.5
			{view stop "smoke_shell"}
		}
		{spawn "shell_cannon" "fx_invers" x scale 0.014
			{impulse up 0.5 -0.5 dir -1.5 0.7 cz 0.2 0.1 com}
			{add_view "smoke_zenit" "smoke_shell" "fx_shellsmoke"}
			{view start "smoke_shell"}
			{delay_effect 3 1 "stop"}
			{delay 3 0.5
				{hide 3}
			}
		}
	}
}
{"sdKfz251m tank"
	("hanomag_sound")
	{on "gunner_hatch_open" overload}
}
;RUS
{"ba20 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/wheels/01" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/03" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/03" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/03"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/03"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/car_door_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/car_door_close" user_control}		
	}
}
{"ba64 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/wheels/01" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/03" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/03" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/03"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/03"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/armored_car_door_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/armored_car_door_close" user_control}	
	}
}
{"ba11 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/wheels/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/03" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/03" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/03"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/03"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/armored_car_door_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/armored_car_door_close" user_control}		
	}
}
(define "m3_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/01" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/00" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/car_door_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/car_door_close" user_control}			
	}
)
{"m3 tank"
	("m3_sound")
}
{"m3_g tank"
	("m3_sound")
}
{"m2 tank"
	("m3_sound")
}
{"m4_tractor_c tank"
	("m3_sound")
}
{"m4_tractor tank"
	("m3_sound")
}
{"ha-to tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/02" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/02" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/02"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/02"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/armored_car_door_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/armored_car_door_close" user_control}	
	}
}
;USA
{"m1_t48 tank"
	("m3_sound")
}
{"m3_scout tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/wheels/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/01" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/00" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/car_door_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/car_door_close" user_control}		
	}
}
{"m3_ally tank"
	("m3_sound")
}
{"m3_ally_g tank"
	("m3_sound")
}
{"m2_ally tank"
	("m3_sound")
}
{"m2_ally_m tank"
	("m3_sound")
}
;ENG
{"m3_eng tank"
	("m3_sound")
}
{"m2_eng tank"
	("m3_sound")
}
(define "m8grayhound_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/wheels/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/00" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/01" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/01" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_light_open" user_control}
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_light_close" user_control}		
	}
)
{"m8grayhound tank"
	("m8grayhound_sound")
}
{"m20 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/wheels/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/00" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/01" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/car_door_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/car_door_close" user_control}			
	}
}
;ENG
{"mk2daimler"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/wheels/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/02" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/02" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/02"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/02"	 user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/02" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_light_open" user_control}
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_light_close" user_control}		
	}
}
;JAP
{"ho-ha3mgun"
	("hanomag_sound")
}
{"type93scout"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/wheels/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/03" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/03" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/03"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/03"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_light_open" user_control}
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_light_close" user_control}			
	}
}
;________________________________________________________________________________Light Tank
;GER
{"pz1b tank"
	{on spawn
		{add_view	"flash_gun_big01"	"flashbarrel01"	"shooter00"	}
		{add_view	"flash_gun_big01"	"flashbarrel011"	"shooter01"	}
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/01" user_control}		
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/00" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/01" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_light_open"}
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_light_close"}			
	}
	{on fire "mgun" overload
		{if  name "00"
			{view start "flashbarrel01"}
		else name "01"
			{view start "flashbarrel011"}
		}
	}
}

(define "pz6_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/01" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/00" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/00" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_heavy_open" user_control}
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_heavy_close" user_control}			
	}
)
{"pz6e tank"
	("pz6_sound")
	{on spawn
		{delay_ex 0.1
			{call "random_shield"}
		}
	}
	{on "random_shield"
		(define "delete_shield"
			{tear "piece_medium_steel" bone "shieldl%n"	{delete}}
			{tear "piece_medium_steel" bone "shieldr%n"	{delete}}
		)
		{if rand 0.5	("delete_shield" n(7))}
		{if rand 0.5	("delete_shield" n(8))}
		{if rand 0.5	("delete_shield" n(9))}
		{if rand 0.5	("delete_shield" n(10))}
	}
}
{"pz6h tank"
	("pz6_sound")
}

{"pz6b tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/jagdpanther/jagdpanther_tracks" user_control}	
		{link_sound "engine"			"vehicle/groundborne/jagdpanther/jagdpanther_engine" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/jagdpanther/jagdpanther_engine_stop" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/jagdpanther/jagdpanther_engine_start" user_control}
		{link_sound "exhaust"			"vehicle/groundborne/jagdpanther/jagdpanther_exhaust" user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/jagdpanther/jagdpanther_turret" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_heavy_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_heavy_close" user_control}		
	}
	{on "delay_play_engine" overload
		{delay_effect 1.5 "play_engine"}
	}
}
{"pz6bh tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/jagdpanther/jagdpanther_tracks" user_control}	
		{link_sound "engine"			"vehicle/groundborne/jagdpanther/jagdpanther_engine" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/jagdpanther/jagdpanther_engine_stop" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/jagdpanther/jagdpanther_engine_start" user_control}
		{link_sound "exhaust"			"vehicle/groundborne/jagdpanther/jagdpanther_exhaust" user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/jagdpanther/jagdpanther_turret" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_heavy_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_heavy_close" user_control}		
	}
	{on "delay_play_engine" overload
		{delay_effect 1.5 "play_engine"}
	}
}
{"pzb2740f tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/01" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/00" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/pzb2740f/pzb2740f_exhaust" user_control}
		{link_sound "exhaust"			"vehicle/groundborne/pzb2740f/pzb2740f_exhaust" user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/01" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_heavy_open" user_control}
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_heavy_close" user_control}		
	}
	{on "init_gun"
		{call "add_view_mgun"}
	}
	{on fire "gun" overload
		{spawn "dust_shot_small" "basis"}
		{spawn "tank_canon_fire_small" "foresight1" x}
		{fragments c4 0.2 r0 1 r1 2.5 bone "Foresight1"}
;		{ani_play "fire"}		
	}
	{on fire "gun2"
		{spawn "dust_shot_norm" "basis"}
		{spawn "tank_canon_fire" "foresight20" x}
		{fragments c4 0.2 r0 1 r1 2.5 bone "foresight20"}
		{ani_play "fire"}		
	}
}
;________________________________________________________________________________Tank Hunter
;GER
{"elefant tank"
	("pz6_sound")
}
{"ferdinand tank"
	("pz6_sound")
}
;________________________________________________________________________________SPG
;________________________________________________________________________________Other
(define "pz2_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/01" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/00" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/01" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/02" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_light_open" user_control}
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_light_close" user_control}			
	}
)
{"pz2f tank"
	("pz2_sound")
	{on spawn
		{add_view "flash_zenit02" "pz2f_fire1" "foresight1"}
		{add_view "flash_gun_big01" "pz2f_fire_gun1" "foresight3"}
	}
	{on fire "gun" 
		{view start	"pz2f_fire1"}
		{delay 0.5 
			{view pause	"pz2f_fire1"}
		}
	}
	{on fire "mgun"
		{view start	"pz2f_fire_gun1"}
		{delay 0.5 
			{view pause	"pz2f_fire_gun1"}
		}
	}
}
{"pz2l tank"
	("pz2_sound")
}
{"pz2n tank"
	("pz2_sound")
}
{"marder2 tank"
	("pz2_sound")
}
{"sdkfz124 tank"
	{on fire "gun"
		{call "spawn_shell"}
	}
	{on "spawn_shell"
		{start_sound "weapon/shot/shell"}
		{add_view "smoke_zenit" "smoke_shell" "fx_invers"}
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
	("pz2_sound")
}
{"pz2c tank"
	("pz2_sound")
}
{"pz2h tank"
	("pz2_sound")
}
(define "pz3_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/01" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/00" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/01" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/02" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_medium_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_medium_close" user_control}			
	}
)
{"pz3g tank"
	("pz3_sound")

}
{"pz3g tank"
	("pz3_sound")

}
{"pz3j tank"
	("pz3_sound")

}
{"pz3f tank"
	("pz3_sound")

}
{"pz3f_rus tank"
	("pz3_sound")

}
{"pz3n tank"
	("pz3_sound")

}
{"pz3 tank"
	("pz3_sound")
}
(define "pz3_spg_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/01" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/00" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/01" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_medium_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_medium_close" user_control}		
	}	
)
{"stug3b tank"
	("pz3_spg_sound")
}
{"stug3f tank"
	("pz3_spg_sound")
}
{"stug3g tank"
	("pz3_spg_sound")
}
{"stuh42 tank"
	("pz3_spg_sound")
}

{"pz3m tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/01" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/00" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/01" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_medium_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_medium_close" user_control}		
	}
}
{"ger_trailer tank"
	("pz3_sound")
}
(define "pz4_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/01" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/00" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/01" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/00" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_medium_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_medium_close" user_control}			
	}
)
{"pz4d tank"
	("pz4_sound")
}
{"welberwind tank"
	("pz4_sound")
}
{"pz4g tank"
	("pz4_sound")
}
{"pz4f2 tank"
	("pz4_sound")
}
{"pz4f2_inf tank"
	("pz4_sound")
}
{"pz4e tank"
	("pz4_sound")
}
{"pz4h tank"
	("pz4_sound")
}
{"stug4g tank"
	("pz4_sound")
}
{"stuh42 tank"
	("pz4_sound")
}
{"hummel tank"
	("pz4_sound")
}
{"nashorn tank"
	("pz4_sound")
}
{"jagdpanzer_iv tank"
	("pz4_sound")
}
{"jagdpanzer_iv tank"
	("pz4_sound")
}
{"jagdpanzer_iv_wacher tank"
	("pz4_sound")
}
{"jagdpanzer tank"
	("pz4_sound")
}
{"brumbar tank"
	("pz4_sound")
}


{"sdkfz4 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/01" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/00" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/01" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/01" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_light_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_light_close" user_control}		
	}
	{on ik begin "gun"
		{force_hide_gunners 1}
		{kill_delay "hide_gunners"}
	}
	{on ik begin "turret"
		{force_hide_gunners 1}
		{kill_delay "hide_gunners"}
	}
	{on ik end "gun"
		{delay 5 "hide_gunners" {force_hide_gunners 0}}
	}
	{on ik end "turret"
		{delay 5 "hide_gunners" {force_hide_gunners 0}}
	}
}

{"sdkfz7_1 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/01" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/00" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/01" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/01" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/car_door_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/car_door_close" user_control}			
	}

}

{"m16 tank"
	("m3_sound")
}

(define "m3tank_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/01" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/00" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/01" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/00"	 user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/00" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_medium_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_medium_close" user_control}			
	}
)

{"grant_m3 tank"
	("m4_sound")
	{on "init_gun"
		{add_view "flash_gun_big01"	"flashbarrel03"	"foresight3"}
	}
}
{"m3_lee tank"
	("m4_sound")
	{on "init_gun"
		{add_view	"flash_gun_big01"	"shooter00_1"	"shooter00"}
		{add_view	"flash_gun_big01"	"shooter01_1"	"shooter01"}

	}
	{on fire "mgun1" overload
		{if  name "00"
			{view start "shooter00_1"}
		else name "01"
			{view start "shooter01_1"}
		}
	}

}
{"m2a1_med tank"
	("m3a1_sound")
	{on "init_gun"
		{add_view	"flash_gun_big01"	"flashbarrel81"	"foresight8"}
		{add_view	"flash_gun_big01"	"flashbarrel91"	"foresight9"}
	}
	{on fire "mgun5"
		{view start "flashbarrel81"}
	}
	{on fire "mgun6"
		{view start "flashbarrel91"}
	}
}
{"centurion tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/01" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/00" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/01" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/00" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_heavy_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_heavy_close" user_control}			
	}
}
{"m18 tank"
	("m3a1_sound")

}
{"m24 tank"
	("m3a1_sound")
}
{"achilles tank"
	("m4_sound")
}
{"archer tank"
	("valentine_sound")
}

{"m4a2_76w tank"
	("m4_sound")
}
{"m4a2_76w_rus tank"
	("m4_sound")
}
{"m4a2_76w_thunderbolt tank"
	("m4_sound")
}
{"zis30 tank"
	("t26_sound")
}
{"t20 tank"
	("t26_sound")
}
{"t20 tank"
	("t26_sound")
}
{"t20_tent tank"
	("t26_sound")
}
{"universal_carrier tank"
	("t26_sound")
}
{"universal_carrier_inf_usa tank"
	("t26_sound")
}
{"universal_carrier_usa tank"
	("t26_sound")
}
{"sturmtiger"
	("pz6_sound")
	{on fire "gun"
		{spawn "sturmtiger_fire" inv_normal}
		{tags add "WOW"}{delay 1 {tags remove "WOW"}}
	}
	{on "spawn_shellhole"
		{if flag "big_explosion"
			{spawn "crater_big_tank" "basis" terrain_texmod}
			{spawn "shellhole_dead_car" "basis"}
		}
	}
	{on pierce
;		{if not flag "broken"
			{if volume "gun" 
				{if hit_side front            
					{if rand 0.40
						;{call "stat_break"}
						{call "__explosion"}
						{delay 0.01
							{call "spawn_shellhole"}
						}
					} 
				}
			}
		}
;	}
}
{"sdkfz251_16"
	{on spawn	
		{add_view "flamer_fire" "flame1" "foresight4"}
		{add_view "flamer_fire" "flame2" "foresight5"}
		
		{add_view "flamer_fire_barrel" "fire1" "foresight4"}
		{add_view "flamer_fire_barrel" "fire2" "foresight5"}
	
		{view show	"fire1"}
		{view show	"fire2"}
		
		{view start	"fire1"}
		{view start	"fire2"}
		
		("jet_of_fire_sound_init_default")
	}
	{on break_armor
		{if name "pierce"
			{if rand 0.3
				{if volume "body"
					{call "explosion"}
				}
                        }
                else name "blast"
			{if volume "body"
				{call "explosion"}
			}
                }
	}
	{on "_explosion"
		{fragments c4 5 r0 4 r1 15}
		{fire radius 8 time 15 heating 10}
	}
	{on fire "flamer1"
		{view start	"flame1"}
		{kill_delay "fire1"}
		("jet_of_fire_sound_play_default")
		{delay 0.5 "fire1"
			{view pause	"flame1"}
		}
		("jet_of_fire_sound_stop_default")
	}
	{on fire "flamer2"
		{view start	"flame2"}
		{kill_delay "fire2"}
		("jet_of_fire_sound_play_default")
		{delay 0.5 "fire2"
			{view pause	"flame2"}
		}
		("jet_of_fire_sound_stop_default")
	}
	{on bullet_hit
	    {if relation "enemy" or relation "neutral"
	    	{if stuff "150to152"
			    {call "_explosion"}
	    	else stuff "122to128"
			    {call "_explosion"}
	    	else stuff "88to105"
			    {call "_burn"}
			}
	    }
	}
}
{"ss-d tank"
	("t26_sound")
	{on spawn	
		{add_view "flamer_fire" "flame1" "foresight9"}
		{add_view "flamer_fire" "flame2" "foresight10"}
		{add_view "flamer_fire" "flame3" "foresight13"}
		{add_view "flamer_fire" "flame4" "foresight12"}
		{add_view "flamer_fire" "flame5" "foresight11"}
		
		{add_view "flamer_fire_barrel" "fire1" "foresight9"}
		{add_view "flamer_fire_barrel" "fire2" "foresight10"}
		{add_view "flamer_fire_barrel" "fire3" "foresight13"}
		{add_view "flamer_fire_barrel" "fire4" "foresight12"}
		{add_view "flamer_fire_barrel" "fire5" "foresight11"}
	
		{view show	"fire1"}
		{view show	"fire2"}
		{view show	"fire3"}
		{view show	"fire4"}
		{view show	"fire5"}
		
		{view start	"fire1"}
		{view start	"fire2"}
		{view start	"fire3"}
		{view start	"fire4"}
		{view start	"fire5"}

		("jet_of_fire_sound_init_default")
	}
	{on break_armor
		{if name "pierce"
			{if rand 0.3
				{if volume "body"
					{call "explosion"}
				}
                        }
                else name "blast"
			{if volume "body"
				{call "explosion"}
			}
                }
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{fragments c4 5 r0 4 r1 15}
		{fire radius 8 time 15 heating 10}
	}
	
	{on fire "flamer1"
		{view start	"flame1"}
		{kill_delay "fire1"}
		("jet_of_fire_sound_play_default")
		{delay 0.5 "fire1"
			{view pause	"flame1"}
		}
		("jet_of_fire_sound_stop_default")
	}
	{on fire "flamer2"
		{view start	"flame2"}
		{kill_delay "fire2"}
		{delay 0.5 "fire2"
			{view pause	"flame2"}
		}
	}
	{on fire "flamer3"
		{view start	"flame3"}
		{kill_delay "fire3"}
		{delay 0.5 "fire3"
			{view pause	"flame3"}
		}
	}
	{on fire "flamer4"
		{view start	"flame4"}
		{kill_delay "fire4"}
		{delay 0.5 "fire4"
			{view pause	"flame4"}
		}
	}
	{on fire "flamer5"
		{view start	"flame5"}
		{kill_delay "fire5"}
		{delay 0.5 "fire5"
			{view pause	"flame5"}
		}
	}
		
}
{"chi-ri tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/00" user_control}	
		{link_sound "engine"			"vehicle/groundborne/chi-ri/chi-ri_engine_loop" user_control}		
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/00" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/00" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_medium_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_medium_close" user_control}		
	}
}
{"chi-ha120 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/00" user_control}	
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/01" user_control}		
		{link_sound "engine"			"vehicle/groundborne/#parts/stop/00" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/chi-ha120/chi-ha120_exhaust" user_control}
		{link_sound "exhaust"			"vehicle/groundborne/chi-ha120/chi-ha120_exhaust" user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/00" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_heavy_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_heavy_close" user_control}		
	}
}
{"chi-ha47 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/01" user_control}		
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/00" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/00" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_medium_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_medium_close" user_control}	
	}

}
{"chi-ha57 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/00" user_control}	
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/01" user_control}		
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/00" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/00" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_light_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_light_close" user_control}		
	}

}
{"ha-go tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light"	 user_control}
		{link_sound "move"				"vehicle/tracks/pz1"	 user_control}
		{link_sound "engine"			"vehicle/engine/chi-ha"	 user_control}
		{link_sound "engine_end"		"vehicle/engine/mb_end" user_control}
		{link_sound "engine_start"		"vehicle/engine/mb_up"	 user_control}
		{link_sound "exhaust"			"vehicle/engine/mb_up"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_light_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_light_close" user_control}			
	}

}
{"ke-nu tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light"	 user_control}
		{link_sound "move"				"vehicle/tracks/m26"	 user_control}
		{link_sound "engine"			"vehicle/engine/chi-ha"	 user_control}
		{link_sound "engine_end"		"vehicle/engine/mb_end" user_control}
		{link_sound "engine_start"		"vehicle/engine/mb_up"	 user_control}
		{link_sound "exhaust"			"vehicle/engine/mb_up"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_light_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_light_close" user_control}		
	}

}
{"chi-he tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/medium" user_control}
		{link_sound "move"				"vehicle/tracks/m26" user_control}
		{link_sound "engine"			"vehicle/engine/chi-ha" user_control}
		{link_sound "engine_end"		"vehicle/engine/tank_end" user_control}
		{link_sound "engine_start"		"vehicle/engine/tank_up" user_control}
		{link_sound "exhaust"			"vehicle/engine/tank_up" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_medium_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_medium_close" user_control}		
	}

}
{"chi-nu tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/medium1" user_control}
		{link_sound "move"				"vehicle/tracks/chi-ha" user_control}
		{link_sound "engine"			"vehicle/engine/chi-ha" user_control}
		{link_sound "engine_end"		"vehicle/engine/mb_end" user_control}
		{link_sound "engine_start"		"vehicle/engine/mb_up"	 user_control}
		{link_sound "exhaust"			"vehicle/engine/mb_up"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_medium_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_medium_close" user_control}		
	}

}
{"chi-to tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/medium1" user_control}
		{link_sound "move"				"vehicle/tracks/mk7"	 user_control}
		{link_sound "engine"			"vehicle/engine/mk7"	 user_control}
		{link_sound "engine_end"		"vehicle/engine/mk7_end" user_control}
		{link_sound "engine_start"		"vehicle/engine/mk7_up" user_control}
		{link_sound "exhaust"			"vehicle/engine/mk7_up" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_light_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_light_close" user_control}		
	}

}
{"ho-i tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/medium3" user_control}
		{link_sound "move"				"vehicle/tracks/chi-ha" user_control}
		{link_sound "engine"			"vehicle/engine/t34" user_control}
		{link_sound "engine_end"		"vehicle/engine/t34_end" user_control}
		{link_sound "engine_start"		"vehicle/engine/t34_up"	 user_control}
		{link_sound "exhaust"			"vehicle/engine/t34_up"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_medium_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_medium_close" user_control}		
	}
}
{"black_prince tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/churchill" user_control}
		{link_sound "engine"			"vehicle/engine/churchill" user_control}
		{link_sound "engine_end"		"vehicle/engine/churchill_end" user_control}
		{link_sound "rotate_turret" 	"vehicle/turret/t34" user_control}
		{link_sound "engine_start"		"vehicle/engine/churchill_up" user_control}
		{link_sound "exhaust"			"vehicle/engine/churchill_up" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_heavy_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_heavy_close" user_control}		
	}
}
{"churchill_avre tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/churchill" user_control}
		{link_sound "engine"			"vehicle/engine/churchill" user_control}
		{link_sound "engine_end"		"vehicle/engine/churchill_end" user_control}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret" user_control}
		{link_sound "engine_start"		"vehicle/engine/churchill_up" user_control}
		{link_sound "exhaust"			"vehicle/engine/churchill_up" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_heavy_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_heavy_close" user_control}		
	}
}
{"churchill_crocodile tank"
	{on spawn
		{add_view "flamer_fire" "flame1" "foresight4"}
		{add_view "flamer_fire_barrel" "fire1" "foresight4"}
		{view show	"fire1"}
		{view start	"fire1"}
		("jet_of_fire_sound_init_default")
	}
	{on operatable on	
		{view start	"fire1"}
	}	
	{on operatable off		
		{view stop	"fire1"}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{fragments c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	{on fire "flamer1"
		{view start	"flame1"}
		{kill_delay "fire1"}
		("jet_of_fire_sound_play_default")
		{delay 0.5 "fire1"
			{view pause	"flame1"}
		}
		("jet_of_fire_sound_stop_default")
	}
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/churchill" user_control}
		{link_sound "engine"			"vehicle/engine/churchill" user_control}
		{link_sound "engine_end"		"vehicle/engine/churchill_end" user_control}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret" user_control}
		{link_sound "engine_start"		"vehicle/engine/churchill_up" user_control}
		{link_sound "exhaust"			"vehicle/engine/churchill_up" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_heavy_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_heavy_close" user_control}		
	}	
}
{"churchill_mk_vii tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/churchill" user_control}
		{link_sound "engine"			"vehicle/engine/churchill" user_control}
		{link_sound "engine_end"		"vehicle/engine/churchill_end" user_control}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret" user_control}
		{link_sound "engine_start"		"vehicle/engine/churchill_up" user_control}
		{link_sound "exhaust"			"vehicle/engine/churchill_up" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_heavy_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_heavy_close" user_control}		
	}
	("burn_by_engine" args 0.3)
}
(define "cometa34_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/kv" user_control}
		{link_sound "engine"			"vehicle/engine/m7" user_control}
		{link_sound "engine_end"		"vehicle/engine/m7_end" user_control}
		{link_sound "rotate_turret" 	"vehicle/turret/t34" user_control}
		{link_sound "engine_start"		"vehicle/engine/t26_up" user_control}
		{link_sound "exhaust"			"vehicle/engine/t26_up"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_medium_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_medium_close" user_control}		
	}
)
{"cometa34 tank"
	("cometa34_sound")
}
{"cromwell_mk_vi tank"
	{on "add_movement_sound" overload
		{link_sound "move"		    	"vehicle/tracks/cromwell" user_control}
		{link_sound "engine"			"vehicle/engine/cromwell" user_control}
		{link_sound "engine_end"		"vehicle/engine/cromwell_end" user_control}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret" user_control}
		{link_sound "engine_start"		"vehicle/engine/cromwell_up" user_control}
		{link_sound "exhaust"			"vehicle/engine/cromwell_up" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_medium_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_medium_close" user_control}		
	}
}
{"m4a4_tulip"
	("m4_sound")
}
(define "ho-ri_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/is" user_control}
		{link_sound "engine"			"vehicle/engine/jagdpanther"	 user_control}
		{link_sound "engine_end"		"vehicle/engine/jagdpanther_end" user_control}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy" user_control}
		{link_sound "engine_start"		"vehicle/engine/jagdpanther_up" user_control}
		{link_sound "exhaust"			"vehicle/engine/jagdpanther_up" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_heavy_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_heavy_close" user_control}				
	}
)
{"ho-ri_1 tank"
	("ho-ri_sound")
}
{"ho-ni_3 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light" user_control}
		{link_sound "move"				"vehicle/tracks/chi-ha" user_control}
		{link_sound "engine"			"vehicle/engine/chi-ha" user_control}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end" user_control}
		{link_sound "engine_start"		"vehicle/engine/hetzer_up" user_control}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_medium_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_medium_close" user_control}			
	}
}
(define "sdkfz234_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz234" user_control}
		{link_sound "engine"			"vehicle/engine/sdkfz234" user_control}
		{link_sound "engine_end"		"vehicle/engine/sdkfz234_end" user_control}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy1" user_control}
		{link_sound "engine_start"		"vehicle/engine/sdkfz234_up" user_control}
		{link_sound "exhaust"			"vehicle/engine/sdkfz234_up" user_control}
		{link_sound "open"			"vehicle/groundborne/motions/armored_car_door_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/armored_car_door_close" user_control}		
	}
)
{"sdkfz234_1 tank"
	("sdkfz234_sound")
	("burn_by_engine" args 0.3)
}
{"sdkfz234_3 tank"
	("sdkfz234_sound")
	("burn_by_engine" args 0.3)
}
{"sdkfz234_4 tank"
	("sdkfz234_sound")
	("burn_by_engine" args 0.3)
}
{"sdkfz250_1 tank"
	("hanomag_sound")
	("burn_by_engine" args 0.3)
}
{"sdkfz250_11 tank"
	("hanomag_sound")
	("burn_by_engine" args 0.3)
}
{"sdkfz251 tank"
	("hanomag_sound")
	("burn_by_engine" args 0.3)
}
{"sdkfz251_1_stuka tank"
	("hanomag_sound")
	("burn_by_engine" args 0.3)
}
{"sdkfz7 tank"
	("hanomag_sound")
	("burn_by_engine" args 0.3)
}
{"sdkfz7_2 tank"
	("hanomag_sound")
	("burn_by_engine" args 0.3)
}
{"sdkfz8 tank"
	("hanomag_sound")
	("burn_by_engine" args 0.3)
}
{"t35"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/t34/t34_tracks" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/02" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/02" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/02"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/02"	 user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/#parts/turret/02" user_control}		
		{link_sound "open"			"vehicle/groundborne/motions/tank_hatch_heavy_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/tank_hatch_heavy_close" user_control}		
	}
	{on "init_gun"
		{call "add_view_mgun"}
	}
	{on fire "gun2"
       	{spawn "dust_shot_small" "basis"}
        {spawn "tank_canon_fire_small" "foresight20" x}
	}
	{on fire "gun3"
       	{spawn "dust_shot_small" "basis"}
        {spawn "tank_canon_fire_small" "foresight21" x}
	}
}

(define "t28_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/t34/t34_tracks" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/01" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/00" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "rotate_turret" 	"vehicle/groundborne/t34/t34_turret"	 user_control}
		{link_sound "open"				"vehicle/groundborne/motions/tank_hatch_medium_open" user_control}	
		{link_sound "close"				"vehicle/groundborne/motions/tank_hatch_medium_close" user_control}			
	}
	{on "delay_play_engine" overload
		{delay_effect 0.5 "play_engine"}
	}
)
{"t28 tank"
	("t28_sound")
}
{"t28e tank"
	("t28_sound")
}
(define "rso_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/00" user_control}
		{link_sound "engine"			"vehicle/groundborne/#parts/engine/01" user_control}
		{link_sound "engine_end"		"vehicle/groundborne/#parts/stop/00" user_control}
		{link_sound "engine_start"		"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/01"	 user_control}
		{link_sound "open"			"vehicle/groundborne/motions/armored_car_door_open" user_control}	
		{link_sound "close"			"vehicle/groundborne/motions/armored_car_door_close" user_control}			
	}
	{on "delay_play_engine" overload
		{delay_effect 0.5 "play_engine"}
	}
)
{"steyr_rso tank"
	("rso_sound")
}
{"stz5 tank"
	("rso_sound")
}
{"goliath tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/groundborne/#parts/tracks/00" user_control}
		{link_sound "engine"		"vehicle/engine/bmw"}
		{link_sound "engine_end"	"vehicle/engine/moto_end"}
		{link_sound "engine_start"	"vehicle/engine/bmw_up"}
		{link_sound "exhaust"			"vehicle/groundborne/#parts/exhaust/02"	 user_control}
	}
	{on "delay_play_engine" overload
		{delay_effect 0.5 "play_engine"}
	}
	{on fire "gun"
		{call "stuff_detonate"}
	}
	{on "stuff_detonate"
		{delay 0.1
			{setup_stuff_activator}
			{volumes disable all}
			{stuff_detonate}
			{delete}
		}
	}
	{on break
		{call "stuff_detonate"}
	}
}
{"heavy tank muzzle_brake"
	{on fire "gun" overload
		{spawn "dust_shot_big" "basis"}
		{spawn "tank_canon_fire_muz" "Foresight1" x}
		{fragments c4 0.2 r0 1 r1 2.5 bone "Foresight1"}
		{ani_play "fire"}		
	}
}

{"medium tank muzzle_brake"
	{on fire "gun" overload
       	{spawn "dust_shot_norm" "basis"}
        {spawn "tank_canon_fire_muz" "Foresight1" x}
		{fragments c4 0.2 r0 1 r1 2.5 bone "Foresight1"}
		{ani_play "fire"}			
	}
}


(define "turret_number"
{"turret%0"
	{on spawn
		{call "update_turret%0"}
	}
	{on "update_turret%0"
		("update_turret" n(%0))
    }
	{on bullet_hit
		{if component "turret%0"
			{if stuff "big shell"
				{if rand 0.15
					{call "turret%0_broken"}
				}
			}
		}
	}
	{on break
		{if component "turret%0"
			("turret_break_effects" n(%0))
		}
	}
    {on repair
	    {if component "turret%0"
    		{view stop "smoke3"}
            {call "update_turret%0"}
		}
	}
}
)
("turret_number" args 1)
("turret_number" args 2)
("turret_number" args 3)
("turret_number" args 4)