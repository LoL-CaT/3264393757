{extender "action_target"
	{max_effectors 4}
	{action custom
		{condition not breed_mask "*civilian"}
		{instructions
			{bind range 4 volume "safe_range"}
			{disable_action_restart}
			{free_hands}	
			{animations "artillery_support_idle_l artillery_support_idle_l_1 artillery_support_idle_l_2 artillery_support_idle_l_3 artillery_support_idle_r artillery_support_idle_r_1 artillery_support_idle_r_2 artillery_support_idle_r_3 squat_idle_empty_1 squat_idle_empty_2 squat_idle_empty_3" loop random totaltime 15}
		}
	}
}