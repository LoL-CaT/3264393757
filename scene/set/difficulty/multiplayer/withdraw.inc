	{withdraw_time 1
		{if props "reactive_artyllery" 3}
		{if props "airborne" 1};перекрываем vehicle
		{if props "vehicle" 2}
	}
	{withdraw_cooldown 0.5
		{if breed_mask "*/engineer" "*/corpsman" "*/universal_miner" 0}
		{if props "airborne" 0}
	}