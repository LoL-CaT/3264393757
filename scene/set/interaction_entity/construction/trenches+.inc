{"trench_construct"
	{on seismic
		{if not fortification_crushed
			{fortification_damage_seismic
				{energy_fading  ; distance to epicenter - koefficient
					0 1   	
					100 0
				}
				{energy_to_health_dec 
					0 	0
					3.4 5.0
					7.3 10
					7.4 20
					8.3	25.0
					8.4	60.0
					29 	100
					50	150
				}
			}
			{call "got_any_damage"}
		}
	}
}