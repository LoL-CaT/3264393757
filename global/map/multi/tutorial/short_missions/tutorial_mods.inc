
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
		{accuracy 1
			{if control_user 1.5
				{if ability {"sniper" none} and weapon "sniper" 60
					{if manual_control 90}
				}
				{if ability {"rocketlauncher" none} weapon "rocketlauncher" 2
					{if manual_control 3}
				}				
				{if manual_control 2}				
			}
		}	
		{damage 1 
			{if control_user 1.5
				{if manual_control 2}
			}	
		}
	}	
}
{difficulty
	{enemy
		{recognition_time 7}
		{accuracy 0.7
			{if props "flak" "truck_mortar" "howitzer" 0.6}
			{if props "cannon" and props "medium" 0.5}
			{if props "cannon" and props "heavy" 0.5}			
		}
		{inform_range	0.7}
		{reload_timeout	1.1	
			{if props "flak" "truck_mortar" "howitzer" 1.25}		
		}
	}	
}	