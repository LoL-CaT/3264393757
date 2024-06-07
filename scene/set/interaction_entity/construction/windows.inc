{"windowed"
	(define "break_window"
		{if bone "window%n" visible
			{if bone "fx_glass%n"
				{spawn "glass_hit" "fx_glass%n" x}
			}
			{if bone "fx_glass0%n"
				{spawn "glass_hit" "fx_glass0%n" x}
			}
			{if not bone "fx_glass%n"
				{if not bone "fx_glass0%n"
					{spawn "glass_hit" "window%n" x}
				}
			}
;			{volumes "window%n" disable all}
;			{delay 0.1
				{bone hide	"window%n"}
				{bone show	"window%n_x"}
;			}
		}
	)
	(define "try_break_window"
		{if volume "window%n"
			("break_window" n(%n))
			{call "damage_human_in_window"}
		}
	)
	{on spawn
		{add_view	"smoke_window_flame"	"window_flame"	"window1"}
		{add_view	"smoke_window_flame"	"window_flame"	"window2"}
		{add_view	"smoke_window_flame"	"window_flame"	"window3"}
		{add_view	"smoke_window_flame"	"window_flame"	"window4"}
		{add_view	"smoke_window_flame"	"window_flame"	"window5"}
		{add_view	"smoke_window_flame"	"window_flame"	"window6"}
		{add_view	"smoke_window_flame"	"window_flame"	"window7"}
		
		{add_view	"smoke_window"	"window_smoke"	"window1"}
		{add_view	"smoke_window"	"window_smoke"	"window2"}
		{add_view	"smoke_window"	"window_smoke"	"window3"}
		{add_view	"smoke_window"	"window_smoke"	"window4"}		
		{add_view	"smoke_window"	"window_smoke"	"window5"}
		{add_view	"smoke_window"	"window_smoke"	"window6"}	
		{add_view	"smoke_window"	"window_smoke"	"window7"}	
	}
	
	{on contact
		{if effector "fx_piece_flame"
			{if not flag "burn_window_1"
				{if rand 0.15 {set "burn_window_1" 1}{delay 3 {set "burn_window_1" 0}}}
			else not flag "burn_window_2"
				{if rand 0.25 {set "burn_window_2" 1}{delay 2 {set "burn_window_2" 0}}}
			else not flag "burn_lock"
				{call "window_detonation_flame"}{set "burn_window_1" 0}{set "burn_window_2" 0}
				{set "burn_lock" 1}{delay 0.5 {set "burn_lock" 0}}
			}
		else effector "fx_detonation_flame"
			{if not flag "burn_lock"
				{call "window_flame_process"}
			else
				{call "window_smoke_process"}
			}
		}
	}

	{on "window_detonation_flame"
		{call "break_window"}{spawn "fx_box_detonation_1" "window1"}{spawn "fx_box_detonation_1" "window2"}{spawn "fx_box_detonation_1" "window3"}
		{spawn "fx_box_detonation_1" "window4"}{spawn "fx_box_detonation_1" "window5"}{spawn "fx_box_detonation_1" "window6"}{spawn "fx_box_detonation_1" "window7"}
	}
	
	{on "window_flame_process"
		{call "break_window"}{view show	"window_flame"}{view start	"window_flame"}{view pause	"window_smoke"}
		{kill_delay "fire"}
		{delay 1 0.25 "fire"
			{call "window_smoke_process"}
		}
	}
	
	{on "window_smoke_process"
		{call "break_window"}
		{kill_delay "fire_smoke"}
		{view show	"window_smoke"}{view start	"window_smoke"}{view pause	"window_flame"}
		{delay 12 2 "fire_smoke"
			{view pause	"window_smoke"}
		}	
	}

	{on "damage_human_in_window"
		{if flag "bullet_hit"
			{set "bullet_hit" 0}
			{damage_human_in_window}
			{if not stuff "rocketlauncher"
				{bullet_detonate}
			}
		}
	}
	{on bullet_hit
		{set "bullet_hit" 1}
		{call "break_window"}
		{if volume "target" or volume_able window
			{call "damage_human_in_window"}
		}
		{set "bullet_hit" 0}
	}

	{on overlap begin
		{call "break_window"}
		{if volume "target" or volume_able hole or volume_able window
			{if effector "grenade"
				{with_effector
					{link_grenade_to_nearest_dweller
						{except_fortified "wood fence parts construction"}	; not link if windows fortified
						{stuff "fg"}										; link works only for fg grenades
					}
				}
			}
		}
	}

	{on blast 
		{if min_energy 0.2
			{call "break_window"}
		}
	}
	{on "break_window"
		{if not flag "windows_broken"
			("try_break_window" n())
			("try_break_window" n(0))		("try_break_window" n(1))
			("try_break_window" n(2))		("try_break_window" n(3))
			("try_break_window" n(4))		("try_break_window" n(5))
			("try_break_window" n(6))		("try_break_window" n(7))
			("try_break_window" n(8))		("try_break_window" n(9))
			("try_break_window" n(10))		("try_break_window" n(11))
			("try_break_window" n(12))		("try_break_window" n(13))
			("try_break_window" n(14))		("try_break_window" n(15))
			("try_break_window" n(16))		("try_break_window" n(17))
			("try_break_window" n(18))		("try_break_window" n(19))
			("try_break_window" n(20))		("try_break_window" n(21))
			("try_break_window" n(22))		("try_break_window" n(23))
		}
	}
	{on "break_windows"
		{if not flag "windows_broken"
			{set "windows_broken" 1}
			("break_window" n())
			("break_window" n(0))		("break_window" n(1))
			("break_window" n(2))		("break_window" n(3))
			("break_window" n(4))		("break_window" n(5))
			("break_window" n(6))		("break_window" n(7))
			("break_window" n(8))		("break_window" n(9))
			("break_window" n(10))		("break_window" n(11))
			("break_window" n(12))		("break_window" n(13))
			("break_window" n(14))		("break_window" n(15))
			("break_window" n(16))		("break_window" n(17))
			("break_window" n(18))		("break_window" n(19))
			("break_window" n(20))		("break_window" n(21))
			("break_window" n(22))		("break_window" n(23))
		}
	}
	{on "next_stage"
		{call "break_windows"}
	}
	{on "last_stage"
		{call "break_windows"}
	}
	{on "break_windows_delayed"
		{delay 0.2
			{call "break_windows"}
		}
	}
}
{"windowed without_damage"
	{on "damage_human_in_window" overload}
}