{extender "action_target"
	{max_effectors 1}
	{action custom
		{condition breed_mask "*civilian"}
		{instructions
			{bind range 1}
			{disable_action_restart}
			{free_hands}	
			{effect "barricade_start_sound"}
			{animations "build_bruster" loop totaltime 15}
			{effect "barricade_stop_sound"}
		}
	}
}