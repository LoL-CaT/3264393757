
{difficulty
	{any
		{vision_angle_h 1
			{if human 1
				{if mp_team "b" 0.25}
			}	
		}		
	}	
}
{difficulty
	{ally
		{vision_range 1.3}
		{vision_angle_h 2.5}		
		{accuracy 1
			{if control_user 1.3
				{if ability {"sniper" none} and weapon "sniper" 60
					{if manual_control 90}
				}
				{if ability {"rocketlauncher" none} weapon "rocketlauncher" 2
					{if manual_control 3}
				}				
				{if manual_control 1.5}				
			}
		}	
		{damage 1 
			{if control_user 1.3
				{if manual_control 1.5}
			}	
		}
	}	
}
{difficulty
	{enemy
		{suspect_noise_inc 1.25}	
		{recognition_time 7}
		{vision_range 0.85}
		{accuracy 0.7
			{if props "flak" "truck_mortar" "howitzer" 0.5}
			{if props "cannon" and props "medium" 0.4}
			{if props "cannon" and props "heavy" 0.4}			
		}
		{aim_range 0.95
			{if props "t35" 0.6}
			{if props "vehicle" 0.9			
				{if props "flak" "truck_mortar" "howitzer" 0.6}						
			}
		}
		{inform_range	0.7}
		{reload_timeout	1.1	
			{if props "flak" "truck_mortar" "howitzer" 1.25}		
		}
	}	
}	