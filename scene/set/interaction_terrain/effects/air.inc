;SDL
{"air"
	{on detonate
		{if stuff "shell size2 ph_shell"
			{spawn "ex_ph_big"}
			{spawn "fx_sphere_ph"}
			;{delay 3 {spawn "smoke_gen_big"}}
			("dummy_smoke_ph")		
		else stuff "fr fx61_76"
			{spawn "fr_size_med"};{spawn "smoke_gen_big"}
		else stuff "fr fx91_130"
			{spawn "fr_size_big"};{spawn "smoke_gen_big"}	
		else stuff "molotov_coctail"
			{spawn "ex_molot"}{spawn "storm_botter"}
		else stuff "grenade"
			{spawn "ex_air_big"}
		else stuff "big shell flame bomb"
			{spawn "ex_flame_shell01"};{spawn "smoke_gen_med"}			
		else stuff "big shell fg bomb"
			{spawn "ex_reactive_shell01"};{spawn "smoke_gen_med"}
		else stuff "size4"
			{spawn "ex_air_big2"}
;		else stuff "zenite"
;			{spawn "ex_air_norm"}
;		else stuff "shell fg"
;			{spawn "ex_air_big"}
		else stuff "mortar"
			{spawn "ex_air_big"}
;		else stuff "bazooka"
;			{spawn "ex_air_big"}
		}
	}
}
