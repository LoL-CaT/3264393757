{extender "action_target"
	{max_effectors 1}
	{action custom
		{condition breed_mask "*civilian"}
		{instructions
			{bind range 1}
			{disable_action_restart}
			{free_hands}	
			{reserve_hands}
			{add_view "shovel" "right_hand"}
			{view show "shovel" "right_hand"}
			{effect "camouflage_start_sound"}
			{animations "stand_dig_trench_2" loop totaltime 15}
			{effect "camouflage_stop_sound"}
			{view hide "shovel" "right_hand"}
			{unreserve_hands}
		}
	}
}