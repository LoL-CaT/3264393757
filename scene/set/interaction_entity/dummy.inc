{"dummy"
	{on "stop"	{view stop ""}}
	{on "pause"	{view pause ""}}
	{on "delete"{delete}}
}

{"ps_dummy"
	{on "delete"{hide 3}}
}

{"physics_damping"
;	{friction 1000}
;	{restitution 0.001}
}

(define "throwing_weapon"
	{on contact
		{if effector "human"
			{delay 0
				{constrain_velocity 1}
			}
		}
	}
	{on "onThrow"
	    {tags add "throwed"}
	}
)

{"knife" ("throwing_weapon")}
{"axe" ("throwing_weapon")}
{"soldiers_flashlight"
	{on "light_on"
		{if not sunlight
			{view start "light"}
			{view show "light"}
		else
			{view stop "light"}
			{view hide "light"}
		}
	}
	{on "light_off"
		{if not sunlight
			{view hide "light"}
			{bone cut "fx_light"}
		}
	}
	{on spawn
		{add_view 	"soldier_headlight"	"light"		"fx_light"}
		{add_view 	"light_vehicle"		"light"		"fx_light"}
		{delay 0.1
			{call "light_on"}
		}
	}
	{on bullet_hit
		{call "light_off"}
	}
}
{"detect_throwing"
	{on "onThrow"
		{with_effector
			{if against_humans
				{if not territory_type "friendly"
					{if spy
						{detect 5}
					}
				}
			}	
		}
	}
}

{"warehouse"
	{on spawn
		{volumes disable all}
		{volumes enable contact obstacle}
	}
	{on contact
		{if effector "vehicle"
		else effector "human"
		else
		}
	}
}

{"mwp_weather"
	{on spawn
		{add_view "winter_test_slow" "weather1" "basis"}
		{add_view "winter_test" "weather2" "basis"}
	}
	{on "on_snow"
		{if not flag "snow1" and not flag "snow2" 
			{view start "weather1"}
			{set "snow1" 1}
			{tags add "snow1"}
		else flag "snow1" and not flag "snow2"
			{view stop "weather1"}
			{view start "weather2"}
			{set "snow2" 1}
			{tags add "snow2"}
		else flag "snow2" and flag "snow1"
			{view stop "weather2"}
			{view start "weather1"}
			{set "snow1" 0}
			{tags add "snow3"}
		else flag "snow2" and not flag "snow1"	
			{view stop "weather1"}	
			{set "snow2" 0}	
			{tags remove "snow3"}
			{tags remove "snow2"}
			{tags remove "snow1"}
		}
	}
}

{"stone"
	{on bullet_hit
		{bullet_detonate}
	}
}

{"part"
	{on "check_delete_part" ; called only inside tear, so with_effector swaps entity&effector for flag check
		{with_effector
			{if flag "delete_parts"
				{with_effector
					{delay 20
						{hide 3}
					}
				}
			}
		}
	}
}

{"flesh part"
	{on blast  {spawn "bloodsparks_small"}}
	{on bullet_hit {spawn "bloodsparks_small"}}
	{on contact
		{spawn "bloodsparks_small"}
	}
	{on ground_hit
		{if min_speed 10
			{spawn "bloodsparks_small"}

		}
	}
}

{"piece_small_detonation"
	{on spawn 
		{if rand 0.5
			{start_sound "weapon/shot/traces"}
		else rand 0.15
			{start_sound "hit/big/metal_recochet"}
		else rand 0.4
			{start_sound "detonation/hit_big/hit_big_medium"}
		else
			{start_sound "detonation/hit_small/hit_small"}
		}
	}
}

{"small part"
	{on spawn
;		{con "spawn small part"}
		;{delay 0.1
		;	{volumes disable bullet contact blast touch}	;prevent destroing at spawn moment
		;}
		;{delay 2 {volumes enable bullet contact blast}}
		{call "stop_view"}
		{delay 15 5 {hide 3}}
	}
	{on blast_hit
;		{con "blast small part"}
		{if min_energy 0.7
			{hide 1}
		else min_energy 0.4
			{impulse up 4 2 dir 2 1}
		else 
			{impulse up 2 1 dir 1 1}			
		}
	}
	{on bullet_hit
;		{con "bullet small part"}
		{if stuff "bullet"
			{impulse up 2 1 dir 1 0.5}
		else stuff "shell"
			{hide 1}
		}
	}
	{on contact
;		{con "contact small part"}
		{if effector "vehicle"
			;{volumes disable bullet contact blast}	;prevent destroing at spawn moment
			{delay 4 1 {hide 2}}
		}
	}
}

{"small part fx"
	{on "stop_view"
		{delay 0.5 0.3 {view stop ""}}
	}
}

{"medium part"
;	{friction 2}
;	{restitution 0.2}
	{on spawn
		;{delay 0.1
		;	{volumes disable bullet contact blast touch}	;prevent destroing at spawn moment
		;}
		;{delay 2 {volumes enable bullet contact blast}}
		{delay 20 7 {hide 3}}
	}
	{on blast_hit
		{if min_energy 1.0
			{hide 1}
		else min_energy 0.6
			{impulse up 3 1 dir 3 1}
		else 
			{impulse up 1 1 dir 1 1}			
		}
	}
	{on bullet_hit
		{if stuff "bullet"
			{impulse up 1 0.5 dir 0.5 0.5}
		else stuff "shell"
			{hide 1}		
		}
	}
	{on contact
		{impulse up 0.5 0.25 dir 0.4 0.2}
	}
}

{"big part"
;	{friction 2}
;	{restitution 0.1}
	{on spawn
		{delay 0.1
			{volumes disable touch}
		}
		{delay 24 6 {hide 3}}
	}
	{on blast_hit
		{if min_energy 8 
			{impulse up 6 2 dir 6 1}
		  else min_energy 0.5
			{impulse up 2 0.4 dir 1 0.5}
		}
	}
	{on bullet_hit
		{if stuff "big shell extra"
			{impulse up 5 1 dir 5 1}
		 else stuff "shell"
			{impulse up 1 0.3 dir 1 0.5}
		 else stuff "zenite"
			{impulse up 0.2 0.1 dir 0.1 0.05}
		}
	}
}

{"big part delete"
	{on spawn
		{delay 20
			{delete}
		}
	}
}

{"wood part"
	{on spawn
		{delay 2
			{volumes enable float}
		}
	}
;	{on ground_hit
;		{if terrain "water"
;			{call "kick"}
;		else terrain "deep_water"
;			{call "kick"}
;		}
;	}
;	{on "kick"
;		{delay 15
;			{kill_delay "kick_process"}
;		}
;		{call "kick_process"}
;	}
;	{on "kick_process"
;		{delay 0.3 0.1 "kick_process"
;			{impulse up 1}
;			{call "kick_process"}
;		}
;	}
}
{"fog_open_point_tailed"
	{on spawn
		{tags add "zonehit"}
		{delay 2 {delete}}
	}
}
{"fx_piece_flame"
	{on spawn
		{volumes "body" disable contact}
		;{gravity 30}
		{gravity 10}
		{delay 0
			{add_view "fire_flame_thrower_fly" "fire0" "root"}
			{view start "fire0"}
		}
		{delay 0.12 0.04
			{add_view "fire_flame_thrower_fly4" "fire2" "root"}
			{view start "fire2"}
		}
		{delay 0.2
			{add_view "fire_flame_thrower_fly5" "fire1" "root"}
			{view start "fire"}
		}
		{delay 0.1
			{volumes "body" enable contact}
			{fire radius 0.5 time 0.7 heating 1.5 follow}
		}
		{delay 0.5
			{view stop "fire0"}
		}
	}
	{on contact
		{volumes disable contact}
		{view stop "fire1"}{view stop "fire0"}
		{call "end_object"}
	}
	{on ground_hit
		{view stop "fire1"}{view stop "fire0"}
		{view stop "fire2"}

		{call "end"}
	}
	{on "end_object"
		{if rand 0.2
			{spawn "fire_die"}
		}
		{call "end"}
	}
	{on "ineffective_range"
		{view stop "fire1"}{view stop "fire0"}
		{view stop "fire2"}
		{view stop "fire"}
		{delete}
	}
	{on "end"
		{if rand 0.5
			{fire radius 3 time 4 heating 0.3}
			{fire radius 1.5 time 0.8 heating 0.5}
			
			{if not air
				{if not under_water
					{if rand 0.75 
						{spawn "fire_flame_thrower" dir_velocity}
					else
						{spawn "fire_flame_thrower_min" dir_velocity}
					}
					{if rand 0.075
						{spawn "fx_piece_flame_end"}
					}
				}
			}
		}
		{delete}
	}
}
{"fx_piece_phosphor"
	{on spawn
		{volumes "body" disable contact}
		{gravity 7}
		{delay 0.05
			{volumes "body" enable contact}
		}
		{delay 0.4 {gravity 10}}
	}
	{on contact
		{volumes disable contact}
		{call "end"}
	}
	{on ground_hit
		{call "end"}
	}
	{on "ineffective_range"
	}
	{on "end"
		{fire radius 2 time 2 heating 0.5}
		{if not under_water
			{spawn "smoke_ph" dir_velocity}
		}
		{delete}
	}
}

{"fx_sphere_ph"
	{on spawn overload
		{physics_work 0}
		{delay 0.1 {delete}}
	}
}

{"aoe_heal_med"
	{on spawn overload
		{physics_work 0}
		{delay 0.15 {delete}}
	}
}

{"fx_sphere_ph_cas"
	{on spawn overload
		{physics_work 0}
		{delay 0.1 {delete}}
	}
}

{"fx_detonation_flame"
	{on spawn overload
		{physics_work 0}
		{delay 0.1 {delete}}
	}
}

{"smoke_gen"
	{on spawn overload
		{physics_work 0}
;		{delay 0.25 {tags add "stage_1"}}
		{delay 0.1 {delete}}
;		{delay 16 4 {delete}}
	}
	{on contact overload
;		{if effector "smoke_gen"
;			{if tagged "block"
;			else not tagged "stage_1"
;				{tags add "stage_1"}{spawn "smoke_on_map_from_exp"}{tags add "block"}{delay 1 {tags remove "block"}}
;			else not tagged "stage_2"
;				{tags add "stage_2"}{delay 0.1 {delete}}
;			else
;			}
;		else 
;		}
	}	
}

{"storm_botter"
	{on spawn overload
		{physics_work 0}
		{delay 0.1 {delete}{spawn "storm_botter_stack" "basis"}}
	}
	{on contact overload
		{if effector "storm_botter"
		else effector "storm_botter_stack"
			{delete}
		else 
		}
	}	
}

{"storm_botter_inter"
	{on spawn overload
		{physics_work 0}
		{delay 5 {delete}}
	}
	{on contact overload
		{if effector "storm_botter"
			{spawn "ex_molot_storm" "basis"}{fire radius 6 time 3 heating 6}{delete}
		else effector "storm_botter_stack"
			{spawn "ex_molot_storm" "basis"}{fire radius 6 time 3 heating 6}{delete}
		else 
		}
	}	
}

{"storm_botter_stack"
	{on spawn overload
		{physics_work 0}
		{delay 7.5 {delete}}
	}
	{on contact overload
		{if effector "storm_botter"
			{if not tagged "stage_1"
				{tags add "stage_1"}
			else
				{call "detonate"}
			}
		else effector "storm_botter_stack"
			{delete}{spawn "storm_botter_inter" "basis"}
		else
		}
	}
	{on "detonate" overload
		{spawn "ex_molot_storm" "basis"}{fire radius 6 time 3 heating 6}{delete}
	}	
}

{"flora_shak_min"
	{on spawn overload
		{physics_work 0}
		{blastwave c4 0.01 r0 10 r1 15}
		{delete}
	}	
}


{"fx_mine_ap"
	{on spawn
		{volumes "body" enable contact}
		{delay 5{delete}}	
		{gravity 25}
	}
	{on ground_hit
		{call "end"}
	}
	{on "end"
		{spawn "mine_antipersonnel"}{delete}
	}
}

{"fx_piece_flame_end"
	{on spawn
		{add_view "fire_flame_thrower_light" "light" "root"}
		{view start "light"}
		{delay 7
			{delete}
		}
	}
}

{"napalm"
	{on "start"
		{add_view "fire_napalm" "flame" "root"}
		{view start "flame"}
		{fire radius 2 time 1000000 heating 70 follow}
	}
	{on "end"
		{delete}
	}
}

{## "tagged_piece"
	{on spawn
		{tags add "isu_fire"}
		{delay 25
			{delete}
		}
	}
}

{"inventory_box"
	{on "break"
		{explode_inventory
			{5			"ex_arm_sm"		3	}
			{30			"ex_bomb"	8	}
			{100		"ex_bomb_big"	11	}
			{1000		"train_die"		15	}
			{10000		"train_die"		20	}
			{100000		"train_die"		25	}
			{1000000	"train_die"		30	}
		}
	}
}

{"flag"
	{on spawn
		{call "start"}
		{if tagged "disputed_zone_hide"
			{call "call_spawn_pointer"}
			{volumes disable all}
			{bone hide "flag_point"}
			{bone hide "basis"}
		}
	}
	{on "call_spawn_pointer"
		{if tagged "actual_a"
			{spawn "scout_02"}
		}
	}
	{on "stop"
		{ani_stop "flattern"}
		{ani_play "stop"}
	}
	{on "start"
		{ani_play "flattern" loop}
	}
}

{"flag captureable"
	{on "capture"
		{if tex_mod "1"
			{ani_play "up" resume callback}
		else
			{ani_play "down" resume callback}
		}
	}
	{on "cancel"
		{set "stop" 1}
		{ani_stop "up"}
		{ani_stop "down"}
		{set "stop" 0}
	}
	{on "enable"
		{volumes "activate" enable contact}
	}
	{on "disable"
		{volumes "activate" disable contact}
	}
	{on animation_end "down"
		{if not flag "stop"
			{tex_mod "1"}
			{call "capture"}
		}
	}
	{on animation_end "up"
		{if not flag "stop"
			{tags add "captured"}
		}
	}
}
{"flag flag_point"
	(define "set_tex_mod"
		{on "tex_mod_%0"
			{tex_mod "%0"}
		}
	)
	("set_tex_mod" args ger)
	("set_tex_mod" args rus)
	("set_tex_mod" args usa)
	("set_tex_mod" args jap)
	("set_tex_mod" args eng)
	
	("set_tex_mod" args aus)
	("set_tex_mod" args fra)
	("set_tex_mod" args gbr)
}
{"map_point"
	{on "start"
		{ani_play "rotate" loop}
	}
}


{"starshell"
	{on spawn
		{add_view "starshell_light"	"light" "root"}
		{delay 0.4
			{view start "light"}
		}
		{impulse up 40 fx 10 20 fy 10 20}
		{delay 4 1
			{delete}
		}
	}
}
{"water"
	{on spawn
		{ani_play "wave" loop}
		{add_view "wash_big_flow" "wash" "FX_wash"}
		{add_view "wash_big_flow" "wash" "FX_wash1"}
		{add_view "wash_big_flow" "wash" "FX_wash2"}
		{add_view "wash_big_flow" "wash" "FX_wash3"}
		{add_view "wash_big_flow" "wash" "FX_wash4"}
		{add_view "wash_big_flow" "wash" "FX_wash5"}
		{add_view "wash_big_flow" "wash" "FX_wash6"}
		{add_view "wash_big_flow" "wash" "FX_wash7"}
		{add_view "wash_big_flow" "wash" "FX_wash8"}
		{add_view "wash_big_flow" "wash" "FX_wash9"}
		{view start "wash"}
	}
}

{"water_animation_pingpong"
	{on spawn
		{set "backward" 0}
		{call "animate"}
	}
	{on animation_end "wave"
		{call "animate"}
	}
	{on "animate"
		{if flag "backward"
			{ani_play "wave" -1 callback}
			{set "backward" 0}
		else
			{ani_play "wave" 1 callback}
			{set "backward" 1}
		}
	}
}

{"cord_wood"
	{inflammation_time 3}
	
	{on "burn_start"
		{if not flag "burning"
			{set "burning" 1}
			{view start "fire"}
		}
		{burn time 10}
		{fire radius 0.7 time 10 heating 0.3 follow}
		{delay 10 "burn_start" {delay_effect 0 "burn_start"}}
	}
	{on "burn_stop"
		{kill_delay "burn_start"}
		{view stop "fire"}
		{set "burning" 0}
		{tags remove "burned"}
		{burn stop}
	}
	{on spawn
		{add_view "smoke_camp_norm" "fire" "fx_light"}
		{if flag "burning"
			{view start "fire"}
		}
	}
	{on "_burn"
		{if flag "poured"
			{tags add "burned"}
			{call "burn_start"}
		}
	}
	{on "burn"
		{if not burned
			{call "_burn"}
		}
	}
	{on contact
		{if effector "vehicle"
			{call "break"}
		}
	}
	{on blast
		{if volume "body"
			{if min_energy 0.5
				{call "break"}
			}
		}
	}
	{on "break"
		{if flag "burning"
			{spawn "camp_die" no_position offset 0 0 5}
			{call "burn_stop"}
		else
			{spawn "wood_hit_small" no_position}
		}
		{delete}
	}
	{on "pour_over"
		{if name "fuel"
			{tags add "poured"}
			{set "poured" 1}
		}
	}
}

{"camp_fire"
	{on spawn
		{link_sound "camp_fire" "fire/fireplace"}
		{call "burn"}
	}
	{on "_burn" overload
		{call "burn_start"}
		{play_sound_in_channel "camp_fire" "camp_fire_ch" 1}
	}
}

{"camp_fire_o"
	{on "_burn" overload}
}

{"camp_fire2"
	{on contact overload}
}

{"post_way"
	{on "hide"
		{bone hide "root"}
	}
	{on "show"
		{bone show "root"}
	}
}

{"barrel_opel"
	{on "drop_item" overload
		{delete}
	}
}

{"stuff"
	{on "crush_container"
;		{impulse up 2 1 cx 0 1 cy 0 1}
		{impulse dir 2 1 up 2 1 dir 7 2 cx 0 0.5 cy 0 0.5}
	}
	{on "drop_item"
		{impulse dir 2 1 cx 0 1 cy 0 1}
	}
	{on blast_hit
		{if not linked
			{call "blast_physics"}
		}
	}
	{on bullet_hit
		{if not linked
			{impulse up 0.4 0.2 dir 1 0.5}
		}
	}
	{on "blast_physics"
		{if min_energy 0.3
			{impulse up 5 1 dir 7 2}
		}
	}
}
{"stuff no_blast_physics"
	{on "blast_physics" overload}
}

{"paratrooper"
	{on spawn
		{tags add "paratrooper_air"}
		{view hide "parachute_x"}
	}
	{on "start"
		{ani_play "flight" callback}
	}
	{on animation_end "flight"
		;{tags add "paratrooper"}
		{ani_play "landing" callback}
	}
	{on animation_end "landing"
		{view show "parachute_x"}
	}
}

{"paratrooper_attach"
	{on "start"
		{animate_place "attach" "paratruper_flight"}
		{tags add "paratrooper_in_flight"}
	}
	{on animation_end "flight"
		{with_linked_entity "attach"
			{weapon_prepare}
			{get_off}
			{tags add "paratrooper"}
			{tags remove "paratrooper_in_flight"}
		}
	}
}

{"paradrop"
	{on spawn
		{start_sound "world/ambient/bomber_flyby.wav"}
		{ani_play "flight"}
		{delay 4.0
			{ani_play "landing"}
		}
	}
}

{"paradrop_base"
	{on spawn
		{tags add "can_spawn"}
		{delay 1
			{if tagged "can_spawn"
				{spawn "paradrop_ammo"}
			}
		}
	}
}

{"auto_landing"
	{on spawn
		{call "start"}
;		{link_sound "flyby" "world/ambient/bomber_flyby"}
;		{start_sound "world/ambient/bomber_flyby"}		
	}
	{on animation_end "flight"
		{with_linked_entity "attach"
			{weapon_prepare}
		}
	}
	{on animation_end "landing"
		{delete}
	}
}

{"random_animation"
	{on spawn
		{call "random_animation"}
	}

	(define "random_animation"
		rand 0.1
		{ani_play "animation%0" callback}
	)
	{on "random_animation"
		{if  ("random_animation" args 0)
		else ("random_animation" args 1)
		else ("random_animation" args 2)
		else ("random_animation" args 3)
		else ("random_animation" args 4)
		else ("random_animation" args 5)
		else ("random_animation" args 6)
		else ("random_animation" args 7)
		else ("random_animation" args 8)
		else rand 0.1
			{call "delay"}
		else
			{call "random_animation"}
		}
	}

	(define "random_animation_end"
		{on animation_end "animation%0"
			{call "random_animation"}
		}
	)
	("random_animation_end" args 0)
	("random_animation_end" args 1)
	("random_animation_end" args 2)
	("random_animation_end" args 3)
	("random_animation_end" args 4)
	("random_animation_end" args 5)
	("random_animation_end" args 6)
	("random_animation_end" args 7)
	("random_animation_end" args 8)

	{on "delay"
		{call "random_animation"}
	}
}

{"random_animation with_delay"
	{on "delay" overload
		{delay 12 4
			{call "random_animation"}
		}
	}
}

{"blast_flattern"
	{on blast
		{if volume "flattern"
			{if min_energy 0.3
				{ani_play "flattern"}
			}
		}
	}
}

{"pointer"
	{on spawn
		{tags add "pointer"}
	}
	{on "show"
		{inactive 0}
		{delay 5
			{inactive 1}
		}
	}
}

{"user_guide"
	{on spawn
		{tags add "user_guide"}
		{inactive 0}
		{delay 10
			{hide 5}
		}
	}
}
{"antena"
	{on spawn
		{add_view "stop_signal" "lamp" "fx_lamp"}
	}
	{on "beacon_start"
		{view start "lamp"}
	}
	{on "beacon_stop"
		{view stop "lamp"}
	}
}
{"radio_beacon"
	{on spawn
		{add_view "stop_signal" "lamp" "fx_lamp"}
		{view start "lamp"}
	}
}

{"sandstorm"
	{on spawn
		{add_view "desert2_fx" "lamp" "fx_lamp"}
		{view start "super"}
	}
}
{"big_flying_rocket"
	{on spawn
		{link_sound "fly" "weapon/shot/reactive/rocket"}
		{play_sound "fly" 1}
	}
}

{"welding"
	{on spawn
		{add_view "spark_electro02a" "welding" "root"}
		{view start "welding"}
	}
}
{"air_cloud"
	{on spawn
		{add_view "dustrun_snow_big" "air_cloud" "root"}
		{view start "air_cloud"}
	}
}
{"exp_det_dust"
	{on "explode"
		{if game_param 	"biom" "snow"
			{add_view "ex_det_w" "detonation" "basis"}
		else
			{add_view "ex_det" "detonation" "basis"}
		}
		{view start "detonation"}
	}
}
{"flash_gun_big_entity"
	{on "explode"
		{add_view "flash_gun_big01" "detonation1" "basis"}
		{view start "detonation1"}
	}
}
{"light_plafond_dim_entity"
	{on spawn
		{add_view "light_plafond_dim" "welding" "root"}
		{view start "welding"}
	}
}
{"light_plafond_dim_w_entity"
	{on spawn
		{add_view "light_plafond_dim_w" "welding" "root"}
		{view start "welding"}
	}
}

{"art_piece_one" ;Снаряд вызываемого арт удара
	{on spawn
		{gravity 9}
		{volumes enable contact contact_ground}
	}
	{on contact
		{call "detonate"}
	}
	{on ground_hit
		{call "detonate"}
	}
	{on "detonate"
		{spawn "test_fg_v1"}
		{spawn "crater_norm"}
		;{spawn "smoke_gen_big"} ;Генератор дыма, вызрывы стакаются и генерируют дым.
		{blastwave c4 18 r0 7 r1 18}
		{fragments c4 25 r0 5 r1 16}
		{delete}
	}	
}


{"xmas"
	{on spawn
		{add_view "xmas_smoke"	"smoke" "root"}
		{view start "smoke"}
		{start_sound "weapon/shot/gift/gift_spawn"}
		{tags add "gift_pointer"}
		{impulse up 8 0 rnd_dir 8 0 no_position}
	}
	{on contact
		{if can_crush
			;{call "break"}
		}
	}
	{on "smoke"
		{spawn "grenade_smoke"
			{call "activate"}
			{delay 0.05 0.025
				{impulse up 0.3 0.1 dir 0.5 0.2 cx 0.5 0.2 cy 0.5 0.2 rnd_dir 0.5 0.2 com}
			}
		}
		{call "break"}
	}
	{on "signal"
		{spawn "grenade_signal"
			{call "activate"}
			{delay 0.05 0.025
				{impulse up 0.3 0.1 dir 0.5 0.2 cx 0.5 0.2 cy 0.5 0.2 rnd_dir 0.5 0.2 com}
			}
		}
		{call "break"}
	}
	{on "f_explosion"
		{spawn "explosion_203mm"}
		{delay 1
			{delete}
		}
		{call "break"}
	}
	{on "break"
		{start_sound "weapon/shot/gift/gift_explosion"}
		{spawn "xmas_present_destroy" "root"}
		{delay 1
			{delete}
		}
	}
}
{"xmas_a"
	{on spawn overload
	}
}
(define "shellhole_show_with_delay"
	{on spawn
		{remove_grass %1}
		{view hide "shellhole"}
		{delay %0
			{view show "shellhole"}
		}
	}
)

{"shellhole_dead_moto"
	("shellhole_show_with_delay" args 0.1 2)
}
{"shellhole_dead_car"
	("shellhole_show_with_delay" args 0.2 4)
}
{"shellhole_dead_tank"
	("shellhole_show_with_delay" args 0.35 6)
}
{"shellhole_size2"
	("shellhole_show_with_delay" args 0.1 1.5)
}
{"shellhole_size3"
	("shellhole_show_with_delay" args 0.1 2)
}
{"shellhole_size4"
	("shellhole_show_with_delay" args 0.2 4)
}
{"shellhole_size5"
	("shellhole_show_with_delay" args 0.3 6)
}

{"crater big"
	{on spawn
		{remove_grass 4}
	}
}
{"crater normal"
	{on spawn
		{remove_grass 3.5}
	}
}
{"crater small"
	{on spawn
		{remove_grass 3}
	}
}

{"flare"
	{on spawn
		{gravity 1.3}
		{tags add "flare"}
		{add_view "signal_rocket" "flare" "root"}
		{view start "flare"}
		{delay 15.5
			{delete}
		}
	}
}
{"parachute_signal_fire"
	{on spawn
		{add_view "signal_rocket2" "signal" "fx_signal"}
		{view start "signal"}
		{ani_play "flight" 0.5}
		{delay 3
			{ani_stop "flight"}
			{delay 35
				{ani_play "flight" resume callback}
			}
		}
	}
	{on animation_end "flight"
		{delay 0
			{delete}
		}
	}
}
{"gmc_cckw"
	{on "broken_component_truck"
		{if tagged "broken_component"
			{tags add "broken_component"}
			{add_view "smoke_black_big" "smoke" "steer_l"}
			{view start "smoke"}
			
		else 
			{view stop "smoke"}
		}
	}
}
{"fx_spawner"
	{on "blizzard"
		{if tagged "start_blizzard"
				{view stop "winter_wind"}
				{tags remove "start_blizzard"}
				{add_view "winter_test_slow" "winter_wind_slow" "root"}
				{view start "winter_wind_slow"}
		
		else
			{tags add "start_blizzard"}
			{view stop "winter_wind_slow"}
			{add_view "winter_test" "winter_wind" "root"}
			{view start "winter_wind"}
		}
		
			
		
			
		
		
		
	}
}
{"zone_borders"
	{on spawn
		{if tagged "_1a"
		{add_view "border_neutral" "border0" "decal001"}
		{add_view "border_neutral" "border0" "decal002"}
		{add_view "border_neutral" "border0" "decal003"}
		{add_view "border_neutral" "border0" "decal004"}
		{add_view "border_neutral" "border0" "decal005"}
		{add_view "border_neutral" "border0" "decal006"}
		{add_view "border_neutral" "border0" "decal007"}
		{add_view "border_neutral" "border0" "decal008"}
		{add_view "border_neutral" "border0" "decal009"}
		{add_view "border_neutral" "border0" "decal010"}
		{add_view "border_neutral" "border0" "decal011"}
		{add_view "border_neutral" "border0" "decal012"}
		{add_view "border_neutral" "border0" "decal013"}
		{add_view "border_neutral" "border0" "decal014"}
		{add_view "border_neutral" "border0" "decal015"}
		{add_view "border_neutral" "border0" "decal016"}
		{add_view "border_neutral" "border0" "decal017"}
		{add_view "border_neutral" "border0" "decal018"}
		{add_view "border_neutral" "border0" "decal019"}


		{add_view "border_ally" "border1" "decal001"}
		{add_view "border_ally" "border1" "decal002"}
		{add_view "border_ally" "border1" "decal003"}
		{add_view "border_ally" "border1" "decal004"}
		{add_view "border_ally" "border1" "decal005"}
		{add_view "border_ally" "border1" "decal006"}
		{add_view "border_ally" "border1" "decal007"}
		{add_view "border_ally" "border1" "decal008"}
		{add_view "border_ally" "border1" "decal009"}
		{add_view "border_ally" "border1" "decal010"}
		{add_view "border_ally" "border1" "decal011"}
		{add_view "border_ally" "border1" "decal012"}
		{add_view "border_ally" "border1" "decal013"}
		{add_view "border_ally" "border1" "decal014"}
		{add_view "border_ally" "border1" "decal015"}
		{add_view "border_ally" "border1" "decal016"}
		{add_view "border_ally" "border1" "decal017"}
		{add_view "border_ally" "border1" "decal018"}
		{add_view "border_ally" "border1" "decal019"}

		{add_view "border_ally_between" "border-1" "decal001"}
		{add_view "border_ally_between" "border-1" "decal002"}
		{add_view "border_ally_between" "border-1" "decal003"}
		{add_view "border_ally_between" "border-1" "decal004"}
		{add_view "border_ally_between" "border-1" "decal005"}
		{add_view "border_ally_between" "border-1" "decal006"}
		{add_view "border_ally_between" "border-1" "decal007"}
		{add_view "border_ally_between" "border-1" "decal008"}
		{add_view "border_ally_between" "border-1" "decal009"}
		{add_view "border_ally_between" "border-1" "decal010"}
		{add_view "border_ally_between" "border-1" "decal011"}
		{add_view "border_ally_between" "border-1" "decal012"}
		{add_view "border_ally_between" "border-1" "decal013"}
		{add_view "border_ally_between" "border-1" "decal014"}
		{add_view "border_ally_between" "border-1" "decal015"}
		{add_view "border_ally_between" "border-1" "decal016"}
		{add_view "border_ally_between" "border-1" "decal017"}
		{add_view "border_ally_between" "border-1" "decal018"}
		{add_view "border_ally_between" "border-1" "decal019"}

		{add_view "border_enemy" "border2" "decal001"}
		{add_view "border_enemy" "border2" "decal002"}
		{add_view "border_enemy" "border2" "decal003"}
		{add_view "border_enemy" "border2" "decal004"}
		{add_view "border_enemy" "border2" "decal005"}
		{add_view "border_enemy" "border2" "decal006"}
		{add_view "border_enemy" "border2" "decal007"}
		{add_view "border_enemy" "border2" "decal008"}
		{add_view "border_enemy" "border2" "decal009"}
		{add_view "border_enemy" "border2" "decal010"}
		{add_view "border_enemy" "border2" "decal011"}
		{add_view "border_enemy" "border2" "decal012"}
		{add_view "border_enemy" "border2" "decal013"}
		{add_view "border_enemy" "border2" "decal014"}
		{add_view "border_enemy" "border2" "decal015"}
		{add_view "border_enemy" "border2" "decal016"}
		{add_view "border_enemy" "border2" "decal017"}
		{add_view "border_enemy" "border2" "decal018"}
		{add_view "border_enemy" "border2" "decal019"}

			{if tagged "_2a"
				{add_view "border_neutral" "border0" "decal020"}
				{add_view "border_neutral" "border0" "decal021"}
				{add_view "border_neutral" "border0" "decal022"}
				{add_view "border_neutral" "border0" "decal023"}
				{add_view "border_neutral" "border0" "decal024"}
				{add_view "border_neutral" "border0" "decal025"}
				{add_view "border_neutral" "border0" "decal026"}
				{add_view "border_neutral" "border0" "decal027"}
				{add_view "border_neutral" "border0" "decal028"}
				{add_view "border_neutral" "border0" "decal029"}
				{add_view "border_neutral" "border0" "decal030"}
				{add_view "border_neutral" "border0" "decal031"}
				{add_view "border_neutral" "border0" "decal032"}
				{add_view "border_neutral" "border0" "decal033"}
				{add_view "border_neutral" "border0" "decal034"}
				{add_view "border_neutral" "border0" "decal035"}
				{add_view "border_neutral" "border0" "decal036"}
				{add_view "border_neutral" "border0" "decal037"}
				{add_view "border_neutral" "border0" "decal038"}
	
				{add_view "border_ally" "border1" "decal020"}
				{add_view "border_ally" "border1" "decal021"}
				{add_view "border_ally" "border1" "decal022"}
				{add_view "border_ally" "border1" "decal023"}
				{add_view "border_ally" "border1" "decal024"}
				{add_view "border_ally" "border1" "decal025"}
				{add_view "border_ally" "border1" "decal026"}
				{add_view "border_ally" "border1" "decal027"}
				{add_view "border_ally" "border1" "decal028"}
				{add_view "border_ally" "border1" "decal029"}
				{add_view "border_ally" "border1" "decal030"}
				{add_view "border_ally" "border1" "decal031"}
				{add_view "border_ally" "border1" "decal032"}
				{add_view "border_ally" "border1" "decal033"}
				{add_view "border_ally" "border1" "decal034"}
				{add_view "border_ally" "border1" "decal035"}
				{add_view "border_ally" "border1" "decal036"}
				{add_view "border_ally" "border1" "decal037"}
				{add_view "border_ally" "border1" "decal038"}
	
				{add_view "border_ally_between" "border-1" "decal020"}
				{add_view "border_ally_between" "border-1" "decal021"}
				{add_view "border_ally_between" "border-1" "decal022"}
				{add_view "border_ally_between" "border-1" "decal023"}
				{add_view "border_ally_between" "border-1" "decal024"}
				{add_view "border_ally_between" "border-1" "decal025"}
				{add_view "border_ally_between" "border-1" "decal026"}
				{add_view "border_ally_between" "border-1" "decal027"}
				{add_view "border_ally_between" "border-1" "decal028"}
				{add_view "border_ally_between" "border-1" "decal029"}
				{add_view "border_ally_between" "border-1" "decal030"}
				{add_view "border_ally_between" "border-1" "decal031"}
				{add_view "border_ally_between" "border-1" "decal032"}
				{add_view "border_ally_between" "border-1" "decal033"}
				{add_view "border_ally_between" "border-1" "decal034"}
				{add_view "border_ally_between" "border-1" "decal035"}
				{add_view "border_ally_between" "border-1" "decal036"}
				{add_view "border_ally_between" "border-1" "decal037"}
				{add_view "border_ally_between" "border-1" "decal038"}

				{add_view "border_enemy" "border2" "decal020"}
				{add_view "border_enemy" "border2" "decal021"}
				{add_view "border_enemy" "border2" "decal022"}
				{add_view "border_enemy" "border2" "decal023"}
				{add_view "border_enemy" "border2" "decal024"}
				{add_view "border_enemy" "border2" "decal025"}
				{add_view "border_enemy" "border2" "decal026"}
				{add_view "border_enemy" "border2" "decal027"}
				{add_view "border_enemy" "border2" "decal028"}
				{add_view "border_enemy" "border2" "decal029"}
				{add_view "border_enemy" "border2" "decal030"}
				{add_view "border_enemy" "border2" "decal031"}
				{add_view "border_enemy" "border2" "decal032"}
				{add_view "border_enemy" "border2" "decal033"}
				{add_view "border_enemy" "border2" "decal034"}
				{add_view "border_enemy" "border2" "decal035"}
				{add_view "border_enemy" "border2" "decal036"}
				{add_view "border_enemy" "border2" "decal037"}
				{add_view "border_enemy" "border2" "decal038"}
				
				{if tagged "_3a"
					{add_view "border_neutral" "border0" "decal039"}
					{add_view "border_neutral" "border0" "decal040"}
					{add_view "border_neutral" "border0" "decal041"}
					{add_view "border_neutral" "border0" "decal042"}
					{add_view "border_neutral" "border0" "decal043"}
					{add_view "border_neutral" "border0" "decal044"}
					{add_view "border_neutral" "border0" "decal045"}
					{add_view "border_neutral" "border0" "decal046"}
					{add_view "border_neutral" "border0" "decal047"}

					{add_view "border_ally" "border1" "decal039"}
					{add_view "border_ally" "border1" "decal040"}
					{add_view "border_ally" "border1" "decal041"}
					{add_view "border_ally" "border1" "decal042"}
					{add_view "border_ally" "border1" "decal043"}
					{add_view "border_ally" "border1" "decal044"}
					{add_view "border_ally" "border1" "decal045"}
					{add_view "border_ally" "border1" "decal046"}
					{add_view "border_ally" "border1" "decal047"}

					{add_view "border_ally_between" "border-1" "decal039"}
					{add_view "border_ally_between" "border-1" "decal040"}
					{add_view "border_ally_between" "border-1" "decal041"}
					{add_view "border_ally_between" "border-1" "decal042"}
					{add_view "border_ally_between" "border-1" "decal043"}
					{add_view "border_ally_between" "border-1" "decal044"}
					{add_view "border_ally_between" "border-1" "decal045"}
					{add_view "border_ally_between" "border-1" "decal046"}
					{add_view "border_ally_between" "border-1" "decal047"}

					{add_view "border_enemy" "border2" "decal039"}
					{add_view "border_enemy" "border2" "decal040"}
					{add_view "border_enemy" "border2" "decal041"}
					{add_view "border_enemy" "border2" "decal042"}
					{add_view "border_enemy" "border2" "decal043"}
					{add_view "border_enemy" "border2" "decal044"}
					{add_view "border_enemy" "border2" "decal045"}
					{add_view "border_enemy" "border2" "decal046"}
					{add_view "border_enemy" "border2" "decal047"}
				}
			}
		}
		{view hide "border1"}
		{view hide "border-1"}
		{view hide "border2"}
	}
	{on "show0"
		{view hide "border0"}
		{view hide "border1"}
		{view hide "border-1"}
		{view hide "border2"}
		{view show "border0"}
	}
	{on "show1"
		{view hide "border0"}
		{view hide "border1"}
		{view hide "border-1"}
		{view hide "border2"}
		{view show "border1"}
	}
	{on "show-1"
		{view hide "border0"}
		{view hide "border1"}
		{view hide "border-1"}
		{view hide "border2"}
		{view show "border-1"}
	}
	{on "show2"
		{view hide "border0"}
		{view hide "border1"}
		{view hide "border-1"}
		{view hide "border2"}
		{view show "border2"}
	}
}

{"capacity"}

{"vision_lev01_can"}
{"vision_lev02_can"}
{"vision_lev03_can"}
{"vision_lev04_can"}
{"vision_lev05_can"}

{"vision_lev00"}
{"vision_lev01"}
{"vision_lev02"}
{"vision_lev03"}
{"vision_lev04"}
{"vision_lev04_spa"}
{"vision_lev05"}
{"vision_lev06"}
{"vision_lev07"}

{"round_sandbag"}
{"round_sandbag2"}

{"sturmtiger"}
{"howitzer"}
{"seismic"}
{"place_mg_stan"}
{"paratroopers_carrier"}
{"climb"}
{"climb_trench"}
{"remote"}
{"detonate"}

{"tnk_heavy"}		;unit_info.set

{"stat_gun_hotbar"}	;для хотбара
{"art_point"}		;для селекта юнитов в триггерах (должно соответствовать типу юнита в metagame (кроме art_sup))
{"art_spec"}
{"art_sup"}
{"sup"}
{"art"}
{"apc"}
{"tank_light"}
{"tank_medium"}
{"tank_heavy"}
{"tank_hunt"}
{"spg"}

{"level01"}			;для селекта юнитов в триггерах (должно соответствовать уровню юнита в metagame)
{"level02"}
{"level03"}
{"level04"}
{"level05"}
{"level06"}

{"unarmed"} 		;для техники без оружия (чтобы в панели хот-групп было ниже других вихеклов)

{"glider"}				;для планеров (чтобы настроить им отдельные правила видимости)

{"inventory_crate_icon"} ;для иконки ящика с раздачей боеприпасов

{"stationary"} ;для юнит инфо не перемещаемых орудий

{"mg_stan_small"} ;для небольших станковых пулемётов, чтобы дать бонус незаметности

{"icon_for_linked"} ;для того, чтобы рисовать иконку состояния у некоторых линкуемых сущностей

{"anm_empty"} ;для моделей орудий без анимаций стрелка и заряжающего

{"anm_stereoscope"} ;для анимаций екипажа нового стереоскопа

{"anm_heavy_2"} ;для тяжелых орудий без анимаций стрелка и заряжающего

{"anm_empty_aa"} ;для анимаций зенитных установок без командира

{"anm_52k"} ;для анимаций экипажа 52к

{"m1_aa_anm"} ;для анимаций экипажа m1_aa

{"anm_61k"} ;для анимаций экипажа 61k

{"anm_flak18"} ;для анимаций экипажа flak18

{"anm_flak"} ;для анимаций экипажа flak

{"anm_aa_heavy"} ;для анимаций тяжелых пушек

{"anm_searchlight"} ;для анимаций прожектора

{"anm_mortar_empty"} ;для минометов без анимаций экипажа

{"anm_mortar"} ;для анимаций экипажа минометов

{"anm_aa"} ;для анимаций зенитных установок

{"anm_empty_commander_small"} ;для малых пушек без анимации стрелка

{"anm_empty_commander_big"} ;для тяжелых пушек без анимации стрелка

{"anm_heavy"} ;для экипажей тяжелых пушек

{"anm_mgun_stan"} ;для экипажа пулеметов со станиной

{"anm_mgun_lie"} ;для анимации пулеметов в лежачей позе

{"anm_multigun"} ;для анимаций авто с несколькими пулеметами

{"one_hand_mgun_anm"} ;анимации для стрелков автомобилей с хватом пулемета одной рукой

{"anm_bazooka"} ;анимации для стрелков автомобилей с базукой

{"29k_anm"} ;для анимаций экипажа 29к

{"aaa_anm"} ;для анимаций экипажа зениток на базе авто

{"anm_moto"} ;анимации для экипажа мотоциклов

{"moto_2h"} ;для анимации экипажа мотоциклов с анимацией хвата пулемета двумя руками

{"anm_m8grayhound"} ;для анимаций экипажа m8grayhound

{"anm_ac_2hand_mgun"} ;для анимаций экипажа бранетранспортера с хватом пулемета двумя руками

{"anm_251_17"} ;для анимаций экипажа 251_17

{"anm_251_9"} ;для анимаций экипажа 251_9

{"anm_ac_zenit"} ;для анимаций бронепранспортеров з зенитным орудием

{"anm_ac_2hand_mgun_com"} ;для анимаций бронепранспортеров з зенитным орудием но хватом двумя руками

{"m2"} ;для анимаций экипажа m2

{"m3"} ;для анимаций экипажа m3

{"m2_m"} ;для анимаций экипажа m2м

{"anm_ac_mortair"} ;для анимаций экипажа бтр с минометом 

{"anm_cannon"} ;для анимаций экипажа бтр с пушкой

{"anm_cannon_big"} ;для анимаций экипажа бтр с тяжелым орудием

{"airborne"} ;для анимаций экипажа самолетов

{"anm_tank"} ;для анимаций экипажа танков

{"anm_tank_aa"} ;для анимаций экипажа танков с зенитным пулеметом

{"anm_tank_2h"} ;для анимаций экипажа танков с зенитным пулеметом хватом двумя руками

{"anm_tank_2h_ext"} ;для анимаций экипажа танков с зенитным пулеметом хватом двумя руками с дополнительными членами экипажа

{"anm_tank_ext"} ;для анимаций экипажа танков с зенитным пулеметом с дополнительными членами экипажа

{"anm_m19"} ;для анимаций экипажа танка м19

{"anm_marder3"} ;для анимаций экипажа marder3

{"anm_tank_cannon"} ;для анимаций экипажа танков с видимыми стрелком и заряжающим

{"anm_tank_m7"} ;для анимаций экипажа танка м7

{"anm_tank_cannon_ext"} ;для анимаций экипажа танков с видимыми стрелком и заряжающим и дополнительными членами экипажа

{"anm_tank_cannon_2h_ext"} ;для анимации

{"anm_hummel"} ;для анимаций экипажа танка hummel

{"anm_welberwind"} ;для анимаций экипажа welberwind

{"platform_attach_icon_rules"} ;для настроек иконок относительно платформы с линковкой