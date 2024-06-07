{"railway"} ; register props

{"railway_switch"
	{on "switch"
		{rail_switch -1}
	}
	{on "switchr"
		{rail_switch 0}
	}
	{on "switchl"
		{rail_switch 1}
	}
	{on "switch_left"
		{volumes "body" disable touch}
		{volumes "body1" enable touch}
		{tags add "switch_left"}
		{tags remove "switch_right"}
	}
	{on "switch_right"
		{volumes "body" enable touch}
		{volumes "body1" disable touch}
		{tags add "switch_right"}
		{tags remove "switch_left"}
	}
}

{"railway_part"
	{on "break"
		{tags add "broken"}
		{rail_break}
	}
	{on break_armor
		{call "break"}
	}
}

{"train_part"
;	{on "add_movement_sound"
;		{link_sound "accelerating" "vehicle/wheels/train_end"}
;		{link_sound "moving" "world/railway"}
;		{link_sound "braking" "vehicle/wheels/train_end"}
;	}
	{on accelerate on
		{play_sound "accelerating"}
		{delay 1
			{view pause "warm_smoke"}
		}
		{view start "accelerate_smoke"}
		{view start "accelerate_steam"}
		{delay 2
			{view pause "accelerate_steam"}
		}
	}
	{on accelerate off
		{stop_sound "accelerating"}
		{delay 2
			{view pause "accelerate_smoke"}
		}
		{call "update_moving"}
	}
	{on "update_moving"
		{if not simulating
			{if velocity 0 ; > 0 km/h
				{play_sound "moving" 1}
				{if velocity 8 ;fast
					{view start "move_smoke_fast"}
				else
					{view start "move_smoke_slow"}
				}
				{call "moving"}
			}
		}
	}
	{on "moving"
		{if velocity 8
			{delay 15 2 "moving"
				{view start "move_steam_fast"}
				{delay 0.7
					{view pause "move_steam_fast"}
				}
				{call "moving"}
			}
		else
			{delay 8 2 "moving"
				{view start "move_steam_slow"}
				{delay 0.5
					{view pause "move_steam_slow"}
				}
				{call "moving"}
			}
		}
	}
	{on brake on
		{stop_sound "moving"}
		{play_sound "braking"}
		{view pause "move_smoke_fast"}
		{view pause "move_smoke_slow"}
		{kill_delay "moving"}
		{view start "brake_smoke"}
		{view start "brake_steam"}
		{delay 2
			{view pause "brake_steam"}
		}
	}
	{on brake off
		{stop_sound "braking"}
		{view pause "brake_smoke"}
		{call "update_moving"}
	}
	{on move off
		{stop_sound "moving"}
		{play_sound "braking"}
	}

	{on "_explosion"
	    {tags add "destroyed"}
	    {kill_crew}
		{clear_inventory}
		{impulse up 1 dir 1}
		{start_sound "detonation/hit_huge/hit_huge"}
		{delay_ex 0
			{set_skeleton "_xx" sync}
		}
	}
	{on "start_break" overload	
		{if not tagged "body_break"
			{if not flag "broken"
				{set "broken" 1}
				{tags add "body_break"}				
				{delay_ex 0
			        {set_skeleton "_x" sync}
		        }
				{spawn "car_die"}
                {spawn "car_die_particle" "Basis"}		
			}
		}		
	}
	{on pierce
	    {if armor_health 1 
		    {call "start_break"}
		}
	}
	{on blast
	    {if armor_health 1		
		        {call "start_break"}
	    }
		{if min_energy 16 {if not tagged "destroyed" {call "_explosion"}}}
	}
}

{"steam_locomotive"
	{on spawn
		{call "update_fx"}
	}
	{on "add_movement_sound" ;overload
		{link_sound "accelerating"	"vehicle/train/accelerate"}
		{link_sound "moving"		"vehicle/wheels/train"}
		{link_sound "braking"		"vehicle/train/brake"}
	}
	{on "update_fx"
		{add_view	"smoke_train_grey"			"warm_smoke"				"fx_exhaust"}
		{add_view	"smoke_train_steam_norm"	"warm_steam1"				"fxsmoke1"}
		{add_view	"smoke_train_steam_norm"	"warm_steam2"				"fxsmoke2"}
		{add_view	"smoke_train_steam_norm"	"warm_steam3"				"fxsmoke3"}
		{add_view	"smoke_train_steam_norm"	"warm_steam4"				"fxsmoke4"}
		{add_view	"smoke_train_grey_slow"		"accelerate_smoke"			"fx_exhaust"}
		{add_view	"smoke_train_steam_norm"	"accelerate_steam"			"fxsmoke1"}
		{add_view	"smoke_train_steam_norm"	"accelerate_steam"			"fxsmoke2"}
		{add_view	"smoke_train_steam_small"	"accelerate_steam"			"fxsmoke3"}
		{add_view	"smoke_train_steam_small"	"accelerate_steam"			"fxsmoke4"}
		{add_view	"smoke_train_grey_slow2"	"move_smoke_slow"			"fx_exhaust"}
		{add_view	"smoke_train_steam_norm"	"move_steam_slow"			"fxsmoke1"}
		{add_view	"smoke_train_steam_norm"	"move_steam_slow"			"fxsmoke2"}
		{add_view	"smoke_train_steam_small"	"move_steam_slow"			"fxsmoke3"}
		{add_view	"smoke_train_steam_small"	"move_steam_slow"			"fxsmoke4"}
		{add_view	"smoke_train_grey_slow2"	"move_smoke_fast"			"fx_exhaust"}
		{add_view	"smoke_train_steam_norm"	"move_steam_fast"			"fxsmoke1"}
		{add_view	"smoke_train_steam_norm"	"move_steam_fast"			"fxsmoke2"}
		{add_view	"smoke_train_steam_small"	"move_steam_fast"			"fxsmoke3"}
		{add_view	"smoke_train_steam_small"	"move_steam_fast"			"fxsmoke4"}
		{add_view	"smoke_train_grey_slow"		"brake_smoke"				"fx_exhaust"}
		{add_view	"smoke_train_steam_norm"	"brake_steam"				"fxsmoke1"}
		{add_view	"smoke_train_steam_norm"	"brake_steam"				"fxsmoke2"}
		{add_view	"smoke_train_steam_small"	"brake_steam"				"fxsmoke3"}
		{add_view	"smoke_train_steam_small"	"brake_steam"				"fxsmoke4"}

		{add_view	"smoke_train_steam_norm"	"engine_steam"				"fx_smoke_engine1"}
		{add_view	"smoke_train_steam_norm"	"engine_steam"				"fx_smoke_engine2"}

		{add_view "aero_die_fire"		"fire_big"	"fx_fire_big_engine"}
		{add_view "smoke_dead_norm"		"fire1"		"fx_fire_small_engine1"}
		{add_view "smoke_dead_norm"		"fire2"		"fx_fire_small_engine2"}
		{add_view "smoke_dead_norm"		"fire3"		"fx_fire_small_engine3"}
		{add_view "smoke_dead_norm"		"fire4"		"fx_fire_small_engine4"}
		{add_view "smoke_dead_norm"		"fire5"		"fx_fire_small_engine5"}
		{add_view "smoke_dead_small"	"smoke"		"fx_smoke_engine1"}
		{add_view "smoke_dead_small"	"smoke"		"fx_smoke_engine2"}

		{add_view "steam"				"steam"		"fx_steam_small_engine1"}
		{add_view "steam"				"steam"		"fx_steam_small_engine2"}
		{add_view "steam"				"steam"		"fx_steam_small_engine3"}
		{add_view "steam"				"steam"		"fx_steam_small_engine4"}
		{add_view "steam"				"steam"		"fx_steam_small_engine5"}
		{add_view "steam"				"steam"		"fx_steam_small_engine6"}
		{add_view "steam"				"steam"		"fx_steam_small_engine7"}

		{add_view "smoke_train_steam_norm" "steam_big"	"fx_steam_big_engine1"}
		{add_view "smoke_train_steam_norm" "steam_big"	"fx_steam_big_engine2"}
	}
	
	{on bullet_hit
		{if volume "cistern"
			{if stuff "bullet"
				{if rand 0.4
					{burn fx "smoke_fx_cistern" time 4 fake even_law}
				}
			else stuff "shell"
				{burn fx "smoke_train_steam_small" time 10 fake even_law}		
			}
		}
	}
	
	{on "start_break" overload	
		{if not tagged "body_break"
			{if not flag "broken"
				{set "broken" 1}
				{tags add "body_break"}
				{tags add "destroyed"}					
				{delay_ex 0
			        {set_skeleton "_x" sync}
		        }
                {spawn "car_die_particle" "Basis"}
				{spawn "car_die"}
				{if volume "cistern"
					{spawn "ex_train_big" "root"}
					{fragments c4 5 r0 4 r1 15}
					{fire radius 8 time 15 heating 10}
				}
			}
		}		
	}	
	
	{on "warm"
		{if name "on"
			{delay 0.1
				{view start	"warm_smoke"}
			}
			{call "warming"}
		else name "off"
			{kill_delay "warming"}
			{delay 1
				{view pause "warm_smoke"}
			}
		}
	}
	{on "warming"
		{delay 5 2 "warming"
			{if not velocity 0 ; == 0 km/h
				(define "rand_start"
					{if rand 0.25
									{view start %0} {delay 0.7 {view pause %0}}
					else rand 0.5
						{delay 0.3	{view start %0} {delay 0.7 {view pause %0}}}
					else rand 0.75
						{delay 0.6	{view start %0} {delay 0.7 {view pause %0}}}
					else
						{delay 0.9	{view start %0} {delay 0.7 {view pause %0}}}
					}
				)
				("rand_start" args "warm_steam1")
				("rand_start" args "warm_steam2")
				("rand_start" args "warm_steam3")
				("rand_start" args "warm_steam4")
				{call "warming"}
			}
		}
	}
	{on "slice_load"
		{if name "hatch"
			{with_effector
				{add_view "smoke_black" "smoke" "basis"}
			}
		}
	}
	{on "_explosion"
		{delay 1
			{stop_sound "accelerating"}
			{stop_sound "moving"}
			{stop_sound "braking"}
		}
	}
	{on "cut_parts"
		{call "update_fx"}

		{tear "piece_big_steel" bone "hatch" id "hatch"
			{impulse forward 10 3 no_position cx 5 2 cy 5 2 cz 5 2}
			{add_view "smoke_black" "smoke" "root"}
			{view start "smoke"}
			{delay_effect 20 5 "pause"}
		}

		(define "rand_fire"
			{if rand 0.7
				{delay 0.3 0.2
					{view start "fire%0"}
				}
				{delay 40 10
					{view stop "fire%0"}
				}
			}
		)
		("rand_fire" args 1)
		("rand_fire" args 2)
		("rand_fire" args 3)
		("rand_fire" args 4)
		("rand_fire" args 5)
		{view start "fire_big"}
		{view start "smoke"}
		{view start "steam"}
		{view start "steam_big"}
		{delay 3
			{view stop "steam_big"}
		}
		{delay 10
			{view stop "steam"}
		}
		{delay 40 10
			{view stop "smoke"}
		}
	}
	{on break
		{if component "engine"
			{set "crush" 1}
			{call "explosion"}
		}
	}	
}

{"tramway"
	{on break
		{if component "body"
			{call "break_windows"}
		}
	}
}

{"cistern"
    {on "_explosion"
		{spawn "fuel_die_big" "root"}
		{fragments c4 5 r0 4 r1 15}
		{fire radius 8 time 15 heating 10}
	}
	{on pierce
	    {if volume "fuel"
			{call "pierce_fuel"}
		}
	}
	{on blast
	    {if min_energy 3.6 {if not tagged "destroyed" {call "_explosion"}}}
	}
	{on "pierce_fuel"
		{if rand 0.5
			;{volumes "fuel" disable bullet contact blast}
			{spawn "tank_die_particle"}
			{call "burn"}
		}
	}
	{on break_armor
		{if volume "fuel"
			{call "_explosion"}
		}
	}
	{on contact
		{if volume "fuel"
			{if effector "vehicle"
				{call "_explosion"}
			}
		}
	}
	{on "cut_parts"
		{fragments c4 15 r0 8 r1 12}

		{spawn "aero_die" "fx_exp3"}
		{delay 0.15 0.05 {spawn "aero_die" "fx_exp3a"}}
		{delay 0.15 0.05 {spawn "aero_die" "fx_exp3b"}}
		{spawn "aero_die_particle" "fx_exp4a"}
		{spawn "aero_die_particle" "fx_exp4d"}

		{add_view "smoke_black_big" "deathfx" "basis"}
		{view start "deathfx"}
		{delay 40 5	{view stop "deathfx"}}

		(define "fire_start"
			{add_view "smoke_dead_wheel" "fire%0" "fx_fire%0"}
			{view start "fire%0"}
			{delay 30 5
				{view stop "fire%0"}
			}
		)
		("fire_start" args 1)
		("fire_start" args 2)
		("fire_start" args 3)
		("fire_start" args 4)
		("fire_start" args 5)
		("fire_start" args 6)

		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
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

{"tradevan_explosive"
	{on break_armor
		{if volume "body"
			{call "explosion"}
		}
	}
	{on contact
		{if volume "inventory"
			{if effector "airborne"
				{call "explosion"}
			}
		}
	}
	{on "cut_parts"
		{fragments c4 15 r0 20 r1 30}

		{spawn "train_die" "basis"}
;		{spawn "crater_extra_big" "basis"}
;		{spawn "shellhole_big_dead" "basis"}

		{add_view "smoke_black_big" "deathfx" "basis"}
		{view start "deathfx"}
		{delay 40 5	{view stop "deathfx"}}

		(define "fire_start"
			{add_view "smoke_dead_wheel" "fire%0" "fx_fire%0"}
			{view start "fire%0"}
			{delay 30 5
				{view stop "fire%0"}
			}
		)
		("fire_start" args 1)
		("fire_start" args 2)
		("fire_start" args 3)

		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
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
		("cut_part" args "part7")
		("cut_part" args "part8")
	}
}


{"platform"
	{on spawn
		{player -1}
		(define "with_linked_entity_selector"
			{with_linked_entity "%n"
				{if props "vehicle"
					{chassis_work 0}
					{bone hide "trackr"}
					{bone hide "trackl"}
					{components "trackright" destroy}
					{components "trackleft" destroy}
				}			
			}
		)
		("with_linked_entity_selector" n(1))
		("with_linked_entity_selector" n(2))
		("with_linked_entity_selector" n(3))
	}
	{on break_armor
		{if volume "body"
			{call "explosion"}
		}
	}
	{on bullet_hit
		{if stuff "flaergun strike" ("grenade_signal")
		else stuff "smoke_gr"("grenade_smoke")}	
	}
;	{on pierce
;		{if bullet "shell"
;			{if volume "body"
;				{bullet_detonate}
;			}
;		}
;	}
	{on "cut_parts"
		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
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

{"platform_can"
	{on break
		{if component "body"
			{spawn "sandbags_crush" "fx_shield1"}
			{spawn "sandbags_crush" "fx_shield2"}
			{spawn "sandbags_crush" "fx_shield3"}
			{spawn "sandbags_crush" "fx_shield4"}
;			{bone hide "shield_left"}
;			{bone hide "shield_right"}
		}
	}
}

{"crane_m"
	{on spawn
		{add_view	"smoke_train_grey_slow" "smoke" "fxsmoke1"}
		{add_view	"exhaust_dark" "work_smoke" "fxsmoke1"}
		{link_sound "rotate_turret" "vehicle/turret/mortar"}
	}
	{on ik begin "turret"
		{view start "smoke"}
		{delay 1
			{view pause "smoke"}
		}
		{if not flag "started"
			{if name "forward"
				{ani_play "hook_swing" -1 loop callback}
			else
				{ani_play "hook_swing" loop callback}
			}
			{set "started" 1}
		}
	}
	{on ik end "turret"
		{set "started" 0}
	}
	{on animation_end "hook_swing"
		{if not flag "started"
			{ani_stop "hook_swing"}
		}
	}
	{on operatable on
		{delay 0.1
			{view start "work_smoke"}
		}
	}
	{on operatable off
		{view pause "work_smoke"}
	}
}

{"carriage"
	{on break
		{if volume "body"
			{spawn "tank_die_particle"}
		}
	}
	{on "cut_parts"
		("fire_start" args 1)
		("fire_start" args 1a)
		{spawn "aero_die" "fx_exp3"}
		{spawn "aero_die" "fx_exp4"}

		(define "cut_big_part"
			{tear "piece_big_steel" bone %0
				{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
				{add_view "smoke_dead_wheel" "smoke" "basis"}
				{view start "smoke"}
				{delay_effect 20 5 "stop"}
			}
		)
		("cut_big_part" args "part_big1")
		("cut_big_part" args "part_big2")
		("cut_big_part" args "part_big3")
		("cut_big_part" args "part_big4")
		("cut_big_part" args "part_big5")
		("cut_big_part" args "part_big6")
	}
}

{"tradevan"
;	{on spawn
;		{ani_play "doorright" 1}
;		{ani_play "doorleft" 1}
;	}
	{on "cut_parts"
		("fire_start" args 1)
		("fire_start" args 2)
		("fire_start" args 3)
		{spawn "wood_hit_big" "fx_wood1"}
		{spawn "wood_hit_big" "fx_wood2"}
		{spawn "hay_hit_big" "fx_haulm1"}
	}
}

{"armored_locomotive"
	{on break_armor overload
		{component break}
	}
}

{"linked_crates"
	{on "_explosion"
		{with_linked_entity "crate1"	{call "break"}}
		{with_linked_entity "crate2"	{call "break"}}
		{with_linked_entity "crate3"	{call "break"}}
		{with_linked_entity "crate4"	{call "break"}}
		{with_linked_entity "crate5"	{call "break"}}
		{with_linked_entity "crate6"	{call "break"}}
		{with_linked_entity "crate6"	{call "break"}}
		{with_linked_entity "crate8"	{call "break"}}
		{with_linked_entity "crate9"	{call "break"}}
		{with_linked_entity "crate10"	{call "break"}}
		{with_linked_entity "crate11"	{call "break"}}
		{with_linked_entity "crate12"	{call "break"}}
		{with_linked_entity "crate13"	{call "break"}}
		{with_linked_entity "crate14"	{call "break"}}
		{with_linked_entity "crate15"	{call "break"}}
		{with_linked_entity "crate16"	{call "break"}}
		{with_linked_entity "crate17"	{call "break"}}
	}
}
