{"human"
	{on bullet_hit overload
		{kill_flags reset}
		{call "detect_by_hit"}
		{call "bound_by_battle"}
		("spawn_bloodsparks" n("bloodsparks_small2"))		; to generate hit signal
		{if stuff "shell fg" or stuff "shell fr"
			;{bullet_detonate}
			{call "process_bullet_hit"}
		else stuff "bazooka"
			{bullet_detonate}
			{call "process_bullet_hit"}
		else stuff "bullet" and relation "enemy"
			{if volume_armored
				{bullet_detonate}
			}
			{call "process_bullet_hit"}
		else stuff "bullet" and relation "ally"
			{if volume_armored
				{bullet_detonate}
			}
			{if effector "airborne"
				{call "process_bullet_hit"}
			else
				{with_effector
					{if manual_control
						{with_effector {call "process_bullet_hit"}}
					}
				}
			}										
		else stuff "flaergun strike"
			("health_damage" c(5))
	        ("grenade_signal")			
		else stuff "smoke_gr"
			("health_damage" c(5))
			("grenade_smoke")				
		else
			{call "process_bullet_hit"}
			
		}
	}

	{on "detect_by_hit" overload}
	
	{on "observed_by_enemy" overload}
}