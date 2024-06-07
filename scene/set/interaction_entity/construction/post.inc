{"post"
	{inflammation_time 4}
	{on break_armor
		{if volume "body"
			{call "break"}
		}
	}
	{on contact 
		{if can_crush
			{call "break"}
		}
	}
	{on bullet_hit
		{if stuff "shell fg" or stuff "shell fr"
			{if can_crush {call "break"}}
		}
	}
	{on "break"
		{volumes "body" disable contact blast}
		{call "light_break"}
		{if not fallen
			{pillar_fall}
		}
	}
	{on "light_break"} ; handled in extender
	{on pierce
		{if volume "body"
			{call "break"}
		}
	}
}

{"post wood"
	{on "burn_volume"
		{if not burned
			{if volume "body"
				{burn volume fx "smoke_dead_tree1" time 15 2 even_law}
				{delay 8
					{call "break"}
				}
			}
		}
	}
	{on blast_hit
		{if min_energy 0.8
			{call "break"}
		}
	}
}

{"post concrete"
	{inflammation_time 10000}
}

{"post steel"
	{inflammation_time 10000}
	{on blast_hit
		{if min_energy 0.8
			{call "break"}
		}
	}
}

{"disable_area post"
	{on "break"
		{area disable}
		{volumes disable obstacle}
	}
}

{"ring_post"
	{on "ring"
		{delay 0.5
			{ani_play "gong"}
			{start_sound "push/ring"}
			{tags add "gong"}
		}
	}
}
