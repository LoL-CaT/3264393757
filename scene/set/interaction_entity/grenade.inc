{"grenade"
	{on "pin_sound"
		{link_sound "pin"			"weapon/shot/pistol/tt/tt_shot"}
		{set "pin_sound" 1}
	}
	{on "pin_sound_play"
		{if flag "pin_sound"
			{play_sound "pin"}
		}
	}
	{on spawn
		{add_view "grenade_tail" "trace" "root"}
		{add_view "grenade_icon" "grenade_ico" "root"}
		{call "pin_sound"}
	}
	{on "onThrow"
		{view start "trace"}
		{volumes "body" disable contact}
		{call "pin_sound_play"}
		{delay 1.5
			{view start "grenade_ico"}
		}
	}
	{on "onThrowActivate"
		{volumes "body" enable contact}
	}
	{on contact
		{view stop "trace"}
		{if stuff_activated
			{if effector "human"
				{call "fall_down"}
			else effector "cannon"
				{link_grenade_to_nearest_human teleport}
			}
		}
	}
	{on "in_hole"
		{break_window_in_hole}
		{link_grenade_to_nearest_human}
	}
	{on ground_hit
		{view stop "trace"}
	}
	{on "fall_down"
		{volumes disable contact}
		{fall_down}
	}
	{on overlap begin
		{if effector "trench"
			{link_grenade_to_nearest_human teleport}
		}
	}
}
{"grenade antipersonnel"
{on spawn {explosive 1}}
}
{"dynamite"
    {on "onThrowActivate"
	    ;{set "activated_dynamite" 1}
		{delay 6 {stuff_detonate breakout}}
    }
    ;{on contact
	;    {if flag "activated_dynamite" {delay 6 {stuff_detonate breakout}}}
    ;}
    ;{on ground_hit
	;    {if flag "activated_dynamite" {delay 6 {stuff_detonate breakout}}}
    ;}

}

{"grenade training"
	{on spawn
		{tags add "grenade"}
	}
}

{"grenade contact"
	{on "pin_sound" overload}
	{on ground_hit
		{if stuff_activated
			{if not name "water"
				{call "ground_detonate"}
			}
		}
	}
	{on "in_hole" overload}
	{on contact overload
		{view stop "trace"}
		{if stuff_activated
			{call "contact_detonate"}
			{if effector "human"
				{call "fall_down"}
			else effector "vehicle"
				{if tagged "gr_ic"
					{spawn "ex_tank_incendiary_shell"}
				}
			}
		}
	}
	{on "ground_detonate"
		{call "detonate"}
	}
	{on "contact_detonate"
		{call "detonate"}
	}
	{on "detonate"
		{stuff_detonate breakout}
	}
	{on "fall_down" overload}
	{on overlap begin overload ;нужно чтобы граната взрывалась после линковки в окоп, иначе подрыв не происходит, т.к. на OnThrow и onThrowActivate выключается contact, а overlap происходит раньше
		{if effector "trench" and stuff_activated
			{link_grenade_to_nearest_human teleport}
			{call "detonate"}
		}
	}
}

{"grenade cumul"
	{on contact
		{if stuff_activated
			{if effector "vehicle"
				{spawn "ex_tank_incendiary_shell"}
			}
		}
	}
}

{"grenade smoke"
	{on spawn
		{call "add_smoke"}
		{link_sound "smoke" "detonation/smoke_grenade/smoke_grenade"}
	}
	{on "add_smoke"
		{add_view "smoke_cover-up_small"	"smoke1" "smoke"}
		{add_view "smoke_cover-up_norm"		"smoke2" "smoke"}
		{add_view "smoke_cover-up_big"		"smoke3" "smoke"}
	}
	{on "onThrow"
		{volumes disable touch select}
	}
	{on "activate"
		(define "spawn_vol"
			{spawn "smoke_vol_%0" offset %1 %2 0
				{delay %3 {hide 1}}
			}
		)
		{play_sound "smoke"};{play_sound "smoke" 1}
		{tags add "smoke"}
		{view start "smoke1"}
		{add_smoke_obstacle radius 220 fill_time 5 rise_time 5 dissolve_period 56 62}
		{delay 62 {remove_smoke_obstacle}}
		{spawn "smoke_vol_cylinder" {delay 60 {hide 1}}}
		{delay 1
			{view start "smoke2"}
		}
		{delay 3
			{view start "smoke3"}
			("spawn_vol" args cylinder 100 0 57)
			("spawn_vol" args cylinder -100 0 57)
			("spawn_vol" args cylinder 0 100 57)
			("spawn_vol" args cylinder 0 -100 57)
			("spawn_vol" args sphere 100 100 57)
			("spawn_vol" args sphere -100 -100 57)
			("spawn_vol" args sphere -100 100 57)
			("spawn_vol" args sphere 100 -100 57)
			{delay 2
				{view stop "smoke1"}
				{view stop "smoke2"}
			}
		}
		{delay 5
			("spawn_vol" args sphere 150 0 55)
			("spawn_vol" args sphere -150 0 55)
			("spawn_vol" args sphere 0 150 55)
			("spawn_vol" args sphere 0 -150 55)
		}
		{delay 60
			{view stop "smoke3"}
			{stop_sound "smoke"}
		}
		{delay 62
			{hide 1}
		}
	}
	{on ground_hit
		{if stuff_activated
			{if not flag "activated"
				{set "activated" 1}
				{if under_water
					{hide 1}
				else
					{delay 3
						{call "activate"}
					}
				}
			}
		}
	}
	{on contact
		{if stuff_activated
			{if not flag "activated"
				{set "activated" 1}
				{delay 3
					{call "activate"}
				}
			}
		}
	}
}
{"grenade smoke_ph"
	{on spawn
		{call "add_smoke"}
		;{link_sound "smoke" "detonation/smoke_grenade/smoke_grenade"}
	}
	{on "add_smoke"
		{add_view "smoke_cover-up_ph"	"smoke1" "smoke"}
	}
	{on "onThrow"
		{volumes disable touch select}
	}
	{on "activate"
		(define "spawn_vol"
			{spawn "smoke_vol_%0" offset %1 %2 0
				{delay %3 {hide 1}}
			}
		)
		{tags add "smoke"}
		{add_smoke_obstacle radius 180 fill_time 5 rise_time 5 dissolve_period 56 62}
		{delay 32 {remove_smoke_obstacle}}
		{spawn "smoke_vol_cylinder" {delay 32 {hide 1}}}
		{delay 0.2
			{view start "smoke1"}
		}
		{delay 0.8
			("spawn_vol" args cylinder 80 0 28)
			("spawn_vol" args cylinder -80 0 28)
			("spawn_vol" args cylinder 0 80 28)
			("spawn_vol" args cylinder 0 -80 28)
			("spawn_vol" args sphere 80 80 28)
			("spawn_vol" args sphere -80 -80 28)
			("spawn_vol" args sphere -80 80 28)
			("spawn_vol" args sphere 80 -80 28)
		}
		{delay 30
			{view stop "smoke1"}
		}
		{delay 32
			{hide 1}
		}
	}
	{on ground_hit
		{if stuff_activated
			{if not flag "activated"
				{set "activated" 1}
				{if under_water
					{hide 1}
				else
					{delay 0.2
						{call "activate"}
					}
				}
			}
		}
	}
	{on contact
		{if stuff_activated
			{if not flag "activated"
				{set "activated" 1}
				{delay 0.2
					{call "activate"}
				}
			}
		}
	}
}
{"grenade signal"
	{on "smoke_view"
		{add_view "smoke_red_test"	"smoke1" "smoke"}
	}
	{on spawn
		{call "smoke_view"}
		{link_sound "smoke" "detonation/smoke_grenade/smoke_grenade"}
	}
	{on "onThrow"
		{volumes disable touch select}
	}
	(define "_x"
		(+ (* %n %range) -500)
	)
	(define "art_bomb"
		{if rand 0.125
			{spawn "%name" offset ("_x" n(-1) range(%range)) 0 %z}
		else
			{if rand 0.1428
				{spawn "%name" offset ("_x" n(1) range(%range)) 0 %z}
			else
				{if rand 0.1666
					{spawn "%name" offset ("_x" n(1) range(0)) -%range %z}
				else
					{if rand 0.2
						{spawn "%name" offset ("_x" n(1) range(0)) %range %z}
					else
						{if rand 0.25
							{spawn "%name" offset ("_x" n(-1) range(%range)) -%range %z}
						else
							{if rand 0.33
								{spawn "%name" offset ("_x" n(1) range(%range)) %range %z}
							else
								{if rand 0.5
									{spawn "%name" offset ("_x" n(-1) range(%range)) %range %z}
								else
									{spawn "%name" offset ("_x" n(1) range(%range)) -%range %z}
								}
							}
						}
					}
				}
			}
		}
	)
	(define "art_bomb_test"
		{spawn "%name" offset ("_x" range(%range) n(-1)) 0 %z}
		{spawn "fx_link" offset ("_x" range(%range) n(-1)) 0 0}

		{spawn "%name" offset ("_x" range(%range) n(1)) 0 %z}
		{spawn "fx_link" offset ("_x" range(%range) n(1)) 0 0}

		{spawn "%name" offset ("_x" range(0) n(1)) -%range %z}
		{spawn "fx_link" offset ("_x" range(0) n(1)) -%range 0}

		{spawn "%name" offset ("_x" range(0) n(1)) %range %z}
		{spawn "fx_link" offset ("_x" range(0) n(1)) %range 0}

		{spawn "%name" offset ("_x" range(%range) n(-1)) -%range %z}
		{spawn "fx_link" offset ("_x" range(%range) n(-1)) -%range 0}

		{spawn "%name" offset ("_x" range(%range) n(1)) %range %z}
		{spawn "fx_link" offset ("_x" range(%range) n(1)) %range 0}

		{spawn "%name" offset ("_x" range(%range) n(-1)) %range %z}
		{spawn "fx_link" offset ("_x" range(%range) n(-1)) %range 0}

		{spawn "%name" offset ("_x" range(%range) n(1)) -%range %z}
		{spawn "fx_link" offset ("_x" range(%range) n(1)) -%range 0}
	)
	(define "rnd_art_bomb"
		{delay 2 1
			{if rand 0.33
				("art_bomb" name(%name) range(50) z(1000))
			else
				{if rand 0.5
					("art_bomb" name(%name) range(80) z(1000))
				else
					("art_bomb" name(%name) range(120) z(1000))
				}
			}
		}
	)
	(define "rnd_art_mortar"
		{delay 0.425 0.25
			{if rand 0.5
				("art_bomb" name(%name) range(15) z(1000))
			else
				{if rand 0.5
					("art_bomb" name(%name) range(30) z(1000))
				else
					("art_bomb" name(%name) range(50) z(1000))
				}
			}
		}
	)
	{on "stack_art_bomb"
		("rnd_art_bomb" name(art_bomb))
		("rnd_art_bomb" name(art_bomb))
		("rnd_art_bomb" name(art_bomb))
		;("art_bomb_test" name(art_bomb) range(40) z(1000))
	}
	{on "activate"
		{volumes disable blast}
		{play_sound "smoke" 1}
		{tags add "signal"}
		{view start "smoke1"}
		{delay 6 1
			{call "stack_art_bomb"}
			{delay 3
				{view stop "smoke1"}
				{stop_sound "smoke"}
				{hide 1}
			}
		}
	}
	{on ground_hit
		{if stuff_activated
			{if not flag "activated"
				{set "activated" 1}
				{if under_water
					{hide 1}
				else
					{delay 3
						{call "activate"}
					}
				}
			}
		}
	}
	{on contact
		{if stuff_activated
			{if not flag "activated"
				{set "activated" 1}
				{delay 3
					{call "activate"}
				}
			}
		}
	}
}
{"grenade signal heavy"
	{on "smoke_view" overload
		{add_view "smoke_pureyellow_test"	"smoke1" "smoke"}
	}
	{on "stack_art_bomb" overload
		("rnd_art_bomb" name(art_bomb_heavy))
		("rnd_art_bomb" name(art_bomb_heavy))
		("rnd_art_bomb" name(art_bomb_heavy))
	}
}
{"grenade mortar"
	{on "smoke_view"
		{add_view "smoke_red_test"	"smoke1" "smoke"}
	}
	{on spawn
		{call "smoke_view"}
		{link_sound "smoke" "detonation/smoke_grenade/smoke_grenade"}
	}
	{on "onThrow"
		{volumes disable touch select}
	}
	{on "stack_art_bomb"
		("rnd_art_mortar" name(art_mortar_120))
		{delay 1.5 ("rnd_art_mortar" name(art_mortar_120))}
		{delay 3 ("rnd_art_mortar" name(art_mortar_120))}
		{delay 4.5 ("rnd_art_mortar" name(art_mortar_120))}
		{delay 6 ("rnd_art_mortar" name(art_mortar_120))}
	}
	{on "activate"
	    {call "smoke_view"}
		{link_sound "smoke" "detonation/smoke_grenade/smoke_grenade"}
		{volumes disable blast}
		{play_sound "smoke" 1}
		{tags add "signal"}
		{view start "smoke1"}
		{delay 6 1
			{call "stack_art_bomb"}
			{delay 8
				{view stop "smoke1"}
				{stop_sound "smoke"}
				{hide 1}
			}
		}
	}
	{on ground_hit
		{if stuff_activated
			{if not flag "activated"
				{set "activated" 1}
				{if under_water
					{hide 1}
				else
					{delay 3
						{call "activate"}
					}
				}
			}
		}
	}
	{on contact
		{if stuff_activated
			{if not flag "activated"
				{set "activated" 1}
				{delay 3
					{call "activate"}
				}
			}
		}
	}
}
{"grenade signal mission"
	{on "stack_art_bomb" overload}
}

{"grenade smoke yellow"
	{on "add_smoke" overload
		{add_view "smoke_yellow_small"	"smoke1" "root"}
		{add_view "smoke_yellow_norm"	"smoke2" "root"}
		{add_view "smoke_yellow_big"	"smoke3" "root"}
	}
}

{"grenade smoke mortar_smoke"
	{on spawn
		{volumes disable touch select}
		{call "activate"}
	}
}

{"molotov_coctail"
	{on "pin_sound" overload}
	{on bullet_hit
		{fire radius 1.5 time 2 heating 6 effector}
		{call "detonate"}
	}
	{on blast
		{if min_energy 0.3
			{fire radius 3 time 5 heating 6 effector}
			{call "detonate"}
		}
	}
	{on "ground_detonate"
		{fire radius 3 time 5 heating 6 effector}
	}
	{on "contact_detonate" overload
		{if effector "construction"
			{volumes disable bullet contact blast}
			{fire radius 3 time 3 heating 6 effector}
			{con "construction"}
			{delay 0.1
				{call "detonate"}
			}
		else
		;	{fire radius 1.5 time 2 heating 20 effector follow}
			{fire radius 0.7 time 4 heating 60 effector}
			{call "detonate"}
		}
	}
}