
{difficulty
	{ally
		{vision_range 1}
		{accuracy 1
			{if control_user 1.3
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
			{if control_user 1.3
				{if manual_control 2}
			}	
		}
	}	
}
{difficulty
	{enemy
		{recognition_time 7}
		{vision_range 0.85}
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