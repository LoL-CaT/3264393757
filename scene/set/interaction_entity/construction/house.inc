{"house"
	{on spawn
		{link_sound "fortify" "fortification/build/fortify"}
	}
	{on "start_fortification"
		{talk "house_fortification_start"}
		{play_sound "fortify" 1 0.5}
	}
	{on "stop_fortification"
		{talk "house_fortification_stop"}
		{stop_sound "fortify"}
	}
	{on "complete_fortification"
		{stop_sound "fortify"}
		{start_sound "fortification/build/dumping_trash"}
	}
}