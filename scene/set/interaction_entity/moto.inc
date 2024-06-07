{"moto"
	{on spawn
		{link_sound "flame" "fire/big"}

		{if not rain
			{add_view	"dustrun_small"			"on_ground"			"FXtrace2"}
			{add_view	"dustrun_small"			"on_ground"			"FXtrace3"}
			{add_view	"dustrun_small"			"on_grass"			"FXtrace2"}
			{add_view	"dustrun_small"			"on_grass"			"FXtrace3"}
			{add_view	"dustrun_small"			"on_country_road"	"FXtrace2"}
			{add_view	"dustrun_small"			"on_country_road"	"FXtrace3"}
			{add_view	"dustrun_sand_small"	"on_sand"			"FXtrace2"}
			{add_view	"dustrun_sand_small"	"on_sand"			"FXtrace3"}
			{add_view	"dustrun_snow_small"	"on_snow"			"FXtrace2"}
			{add_view	"dustrun_snow_small"	"on_snow"			"FXtrace3"}
		}
		{add_view	"wash_moto_dipper"			"on_water"			"FXtrace1"}
;		{add_view	"wash_moto_dipper"			"on_mud"			"FXtrace1"}
		{add_view	"wash_moto"		"on_puddle"			"FXtrace1"}

		{add_view	"smoke_black"			"smoke4"			"basis"}
		{add_view	"exhaust_dark_small"	"exhaust"			"FXsmoke1"}
	}
	{on "add_movement_sound"
		{link_sound "move"			"vehicle/wheels/bmw"}
		{link_sound "move_end"		"vehicle/wheels/bmw_end"}
		{link_sound "engine"		"vehicle/engine/bmw"}
		{link_sound "engine_end"	"vehicle/engine/moto_end"}
		{link_sound "engine_start"	"vehicle/engine/bmw_up"}
		{link_sound "exhaust"		"vehicle/engine/bmw_up"}
	}

	{on contact
		{if not impregnable
			{if effector_velocity 5
				{if effector "car" and relation "enemy"
					{call "component_break"}
				else effector "tank" and relation "enemy"
					{set "crush" 1}
					{call "explosion"}
				}
			}
		}
	}
	{on "test_contact_off"
		{volumes disable contact touch}
	}
	{on "test_contact_on"
		{volumes enable contact touch}
	}
	{on pierce
		{call "check_ur_pierce"}
		{if armor_health 1 and not flag "broken"
			{if not tagged "destroyed"
				{tags add "destroyed"}
				{components break}
				{drop_orders}
				{reset_manual_control}
				{able select 0}
				{able repaired 0}
				{unlink_trailer}
			}
		}
	}
	{on "mp_destroy" ;hack for "burn_damage" and "ur_damage"
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

	{on break
		{if component "body"
			{spawn "tank_die_particle"}
			{crew_enable group "crew" 0}
			{view start "smoke3"}
    		{delay 10 {view stop "smoke3"}}
		else component "engine"
			{spawn "tank_die_particle"}
		}
	}
	{on repair
		{if component "body"
			{crew_enable group "crew" 1}
		}
	}
	{on blast_hit
		{if min_energy 3.0
			{impulse up 0.0 dir 2.0 0.5}
		 else min_energy 0.5
			{impulse up 0.0 dir 0.5 0.2}
		}
	}
	{on "blast_body"
		{if armor_health 1 and not flag "broken"
			{if name "blast"
				{call "explosion"}
			}
		}
	}
	{on break_armor
		{call "blast_body"}
	}
	{on break_armor_again
		{call "blast_body"}
	}
	{on "_burn" overload
		{if not tagged "burned" and not able "exploded"
			{kill_delay "burn"}
			{if not flag "burn_fire"	{damage_report "body" "burn"}}
			{add_view "smoke_dead_norm" "burn_fire" "basis"}
			{play_sound "flame" 1}
			{view start "burn_fire"}
			{burn time 1}
			{set "burn_fire" 1}
			{explosive 1}
			{delay_effect 0 "burn_damage"}
			{delay 1		{burn stop_retry}}
			{icon_event "burning" 6.0}
			{delay 6 "burn"	{call "burn_stop"}}
		}
	}
	{on "burn_damage" overload
		{if flag "burn_fire"
			{armor_health_damage 75}
			{if not flag "burn_engine" and work "engine" and rand 0.04
				{set "burn_engine" 1}
				{damage_report "engine" "burn"}
				{delay 3 1
					{call "engine_broken"}
					{set "burn_engine" 0}
				}
			}
			{if armor_health 1
				{tags add "burned"}
				{call "stat_break"}
				{call "burn_stop"}
				{burn stop}
				{call "explosion"}
			else
				{delay_effect 1 "burn_damage"}
			}
		}
	}
	{on "burn_stop" overload
		{explosive 0}
		{view hide "burn_fire"}
		{view stop "burn_fire"}
		{stop_sound "flame"}
		{set "burn_fire" 0}
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
		{area disable}
		{if not flag "crush"
			{spawn "car_die" "Basis"}
			{spawn "car_die_particle" "Basis"}
			{impulse up 0.0 dir 0.5 0.2}
		}
	}

	{on "spawn_shellhole"
;		{spawn "shellhole_road_moto" "Basis"}
		{spawn "shellhole_dead_moto2" "Basis"}
	}

	{on "slice_load"
		{if name "wheel"
			{with_effector
				{add_view "smoke_dead_wheel" "smoke" "basis"}
			}
		}
	}
	{on "cut_parts"
		{add_view "smoke_dead_moto" "deathfx" "body"}
		{view start "deathfx"}

		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 4 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 6 no_position}
				{burn first_volume fx "smoke_dead_wheel" time 20 5}
;				{add_view "smoke_dead_wheel" "smoke" "basis"}
;				{view start "smoke"}
				{delay_effect 20 5 "stop"}
			}
		)
		(define "tear_wheel"
			{if rand 0.2
				{components "%0" destroy}
				{tear "piece_medium_steel" bone "%0" id "wheel"
					{volumes disable bullet contact blast}	;prevent destroing at spawn moment
					{impulse up 6 4 dir 7 3}
					{add_view "smoke_dead_wheel" "smoke" "basis"}
					{view start "smoke"}
					{delay_effect 10 5 "pause"}
				}
			}
		)

		{volumes disable contact}
		{delay 14 {view stop "deathfx"}}

		("tear_wheel" args wheel1)
		("tear_wheel" args wheel2)
		("tear_wheel" args wheel3)

		("cut_part" args "part1")
		("cut_part" args "part2")
		("cut_part" args "part3")
		("cut_part" args "part4")
		("cut_part" args "part5")
		("cut_part" args "part6")
	}
}
