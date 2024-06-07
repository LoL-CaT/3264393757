;SDL
(define "shellhole"
	{spawn "shellhole_size%0" terrain_texmod}
)
(define "with_crater"
	{if stuff "with_crater"	{spawn "crater_%name" terrain_texmod}}
)
(define "grenade_smoke"
	{spawn "grenade_smoke"
		{call "activate"}
		{delay 0.05 0.025
			{impulse up 3 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 5 2 com}
		}
	}
)
(define "grenade_signal"
	{spawn "grenade_signal"
		{call "activate"}
		{delay 0.05 0.025
			{impulse up 0.3 0.1 dir 0.5 0.2 cx 0.5 0.2 cy 0.5 0.2 rnd_dir 0.5 0.2 com}
		}
	}
)
(define "grenade_smoke_without_physics"
	{spawn "grenade_smoke"
		{call "activate"}
	}
)
(define "grenade_signal_without_physics"
	{spawn "grenade_signal"
		{call "activate"}
	}
)
(define "grenade_signal_without_physics_mortar"
	{spawn "grenade_signal_mortar"
		{call "activate"}
	}
)
(define "dummy_smoke"
	{spawn "dummy_smoke"
		{call "activate"}
	}
)

(define "dummy_smoke_ph"
	{spawn "dummy_smoke_ph"
		{call "activate"}
	}
)


