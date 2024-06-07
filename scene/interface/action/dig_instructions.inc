		{bind range 1.5}
		{crush_area
			{box 1 1 0.5}
			{collider "trench"}
			{pather "trench"}
		}
		{bind_install_position {tag "trench"}}
		{disable_action_restart}
		{free_hands}	
		{take_item}
		{reserve_hands}
		{dig_animation 
			{crawl "lie_trenching_start lie_trenching"}
			{squat "squat_saper_shovel_dig_start squat_saper_shovel_dig"}
			{normal "squat_saper_shovel_dig_start squat_saper_shovel_dig"}
			{terrain_damping
				{"ice" 1.5} ; terrain_fx time_multiplier
			}
		}
		{unreserve_hands}
