{"mine"
	{inflammation_time 3}
	{on spawn
		{volumes "body" disable all}
		{volumes "body1" disable all}
		{add_view "mined_view_own"		"mined_own"		"mined_view"}
		{add_view "mined_view_enemy"	"mined_enemy"	"mined_view"}
		{add_view "mined_view_defused"	"defused"		"mined_view"}
		{add_view "mined_view_discovered"	"mined_discovered"		"mined_view"}
		{call "change_state"}
	}
	{on "_explosion"
		{explosive 1}
		{volumes "body1" disable blast}
		{volumes "body" disable blast}
		{stuff_detonate}
	}
	{on "explosion"
		{if mined
			{call "_explosion"}
		}
	}
	{on "change_state"
		{if mined
			{tags add "mine_planted"}
			{volumes "body1" disable all}
			{volumes "body" enable select touch contact contact_ground} ;blast}
		 else
			{tags remove "mine_planted"}
			{volumes "body" disable all}
			{volumes "body1" enable select touch contact contact_ground} ;blast}
		}
	}
	{on "undermine"
		{tags add "fuse"}
		{add_view "flash_fuse_small" "fire" "fire"}
		{view start "fire"}
		{ani_play "fire" 0.06}
		{##delay 1
			{explosive 1}
		}
		{volumes enable touch}
		{##delay 8
			{call "explosion"}
		}
	}
	{on blast
		{call "explosion"}
	}
	{on "break"
		{delete}
	}
}

{"kamikaze_bomb"
	{on blast_hit
		{if min_energy 0.5
			{stuff_detonate}
		}	
	}
}

{"mine_antipersonnel"
	{on spawn	{tags add "mine_antipersonnel"}}
	{on "delay_exp"
		{delay 0.5 0.2	{call "explosion"}}
	}
	{on contact
		{if mine_effector "human"
			{call "delay_exp"}
		else mine_effector "vehicle"
			{call "delay_exp"}
		else mine_effector "animal"
			{call "delay_exp"}
		}
	}
;	{on blast_hit
;		{if min_energy 1.5
;			{if not stuff "mine"
;				{stuff_detonate}
;			}
;		}	
;	}
}

{"mine_antitank"
	{on spawn	{tags add "mine_antitank"}}
;	{on blast_hit
;		{if min_energy 2.5
;			{if not stuff "mine"
;				{stuff_detonate}
;			}
;		}				
;	}
	{on contact
		{if mine_effector "mine_exploder"
			{delay 0
				{call "explosion"}
			}
		else mine_effector "vehicle"
			{if mined
				{volumes disable contact}
				{delay 0.1
					{call "explosion"}
				}
			}
		}
	}
}

{"dynamite"
	{on "undermine"
		{tags add "fuse"}
		{add_view "flash_fuse_small" "fire" "fire"}
		{view start "fire"}
		{ani_play "fire" 0.06}
		{delay 1
			{explosive 1}
		}
		{volumes disable touch select}
		{delay 5
			{call "explosion"}
		}
	}
	{on "explosion"
		{explosive 1}
		{stuff_detonate}
	}
	{##on blast
		{call "explosion"}
	}
	{on spawn
		{add_view "dynamite_icon" "dynamite_ico" "root"}
		{add_view "grenade_tail" "trace" "root"}
		{add_view "flash_fuse_small" "fire_on_throw" "fire"}
	}
	{on "onThrow"
		{delay 0.5		{view start "dynamite_ico"}}
		{view start "trace"}
		{view start "fire_on_throw"}
		{ani_play "fire" 0.1}
	}
	{on ground_hit
		{view stop "trace"}
	}
}

{"art_bomb"
	{on "explosion"
		{stuff_detonate}
		{view stop "trace"}
	}
	{on spawn
		{add_view "art_bomb_tail" "trace" "basis"}
		{add_view "art_bomb_tail2" "trace" "basis"}
		{view start "trace"}
		{start_sound "weapon/shot/artillery"}
		{impulse fz -50000 fx 25000 2500 rnd_dir 8 2 com}
		{delay 0.5
			{volumes enable contact}
		}
	}
	{on ground_hit
		{if min_speed 10
			{physics_work 0}
			{call "explosion"}
		}
	}
	{on contact
		{if min_speed 8
			{physics_work 0}
			{call "explosion"}
		}
	}
}

{"air_bomb"
	{on "explosion"
		{stuff_detonate}
	}
	{on spawn
		{ani_play "start"}
		{delay 0.7
			{volumes enable contact}
		}
	}
	{on ground_hit
		{if min_speed 10
			{call "explosion"}
		}
	}
	{on contact
		{if min_speed 8
			{call "explosion"}
		}
	}
}

{"air_bomb_stuff"
	{on "explosion"
		{stuff_detonate}
	}
	{on break_armor
		{call "explosion"}
	}
	{on contact
		{if min_speed 8
			{call "explosion"}
		}
	}
}

{"artillery_explosion"
	{on "explosion"
		{stuff_detonate}
	}
	{on spawn
		{delay 0
			{start_sound "weapon/shot/artillery"}
			{delay 2
				{call "explosion"}
			}
		}
	}
}

{"explosion"
	{on "explosion"
		{stuff_detonate}
	}
	{on spawn
		{setup_stuff_activator}
		{call "explosion"}
	}
}

{"explosion_p"
	{on "explosion"
		{stuff_detonate}
	}
	{on "play_sound"
		{start_sound "weapon\shot\background\howitzer"}
        }
	{on spawn
		{setup_stuff_activator}
		{call "play_sound"}
		{add_view "rocket_smoke" "trace" "fx_t"}
		{delay 8.45
			{view start "trace"}
			{ani_play "strike"}
		}
		{delay 9
			{call "explosion"}
		}
	}
}


{"explosive_barrel"
	{inflammation_time 3}
	{on spawn
		{set "explosioned" 0}
	}
	{on break_armor
		{if name "pierce"
			{if stuff_filled "fuel" 20 or tagged "barrel_ent"
				{call "explosion"}
			else stuff "bullet"
				{if stuff_filled "water" 20
					{burn fx "drops_water_small_short" fake}
				}
			else stuff "shell"
				{call "break"}
			}
	else name "blast"
			{call "break"}
		}
	}
	{on contact
;		{if effector "vehicle"
;			{if effector_velocity 5
;				{call "break"}
;			}
;		}
	}
	{on "burn"
		{call "break"}
	}
	{on "break"
		{if stuff_filled "fuel" 20 or tagged "barrel_ent"
			{call "explosion"}
		else
			{spawn "car_die_particle"}
			{volumes disable bullet blast contact}
			{hide 0.3}
		}
	}
	{on "fire_dmg"
		{fire radius 10 time 3 heating 6}
	}
	{on "explosion"
		{if not flag "explosioned"
			{set "explosioned" 1}
			{volumes disable bullet blast contact}
			{delay 1
				{volumes enable contact}
			}
			{fragments c4 5 r0 4 r1 6}
			{call "fire_dmg"}
			{spawn "barrel_die_big"}
			{spawn "fire_shellhole"}
			{add_view "smoke_barrel" "smoke" "root"}
			{view start "smoke"}
			{impulse up 15 3 dir 3 1 cx 0 1 cy 0 1 rnd_dir 8 5 com}
			{delay 25
				{view stop "smoke"}
				{hide 1}
			}
		}
	}
	{on ground_hit
		{if flag "explosioned"
			{fragments c4 2 r0 4 r1 6}
			{call "fire_dmg"}
			{spawn "barrel_die" offset 0 0 7}
			{delete}
		}
	}
}

{"balloon"
	{on break_armor
		{bullet_detonate}
		{if stuff_filled "fuel" 5
			{call "explosion"}
		}
	}
	{on "explosion"
		{if not flag "explosioned"
			{set "explosioned" 1}
			{spawn "flamer_die"}
			{spawn "fire_molot_ground"}
			{fragments c4 10 r0 1 r1 1.5}
			{fire radius 6 time 2 heating 6}
			{delete}
		}
	}
}

{"explosive_stuff"
	{inflammation_time 7}
	{on break_armor
		{call "explosion"}
	}
	{on "burn"
		{call "explosion"}
	}
	{on "explosion"
		{if not flag "explosioned"
			{set "explosioned" 1}
;			{con "explosion"}
			{stuff_detonate}
		}
	}
}