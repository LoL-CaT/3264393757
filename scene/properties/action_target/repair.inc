{extender "action_target"
	{max_effectors 2}
	{action custom
		{condition breed_mask "*civilian"}
		{instructions
			{bind range 1}
			{disable_action_restart}
			{free_hands}	
			{effect "repair_start_sound"}
			{animations "wire_setup" loop totaltime 15}
			{effect "repair_stop_sound"}
		}
	}
}