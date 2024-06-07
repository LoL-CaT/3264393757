;SDL
{"bridge"
	{on hit
		{spawn "spheredust_small_short"}
	}
	{on detonate
		{if stuff "molotov_coctail"
			{spawn "ex_molot"}
			{spawn "fire_molot_ground"}{spawn "storm_botter"}
		else stuff "goliath"
			{spawn "ex_goliath"}
		else stuff "dynamite"
			{spawn "ex_bomb_big"};{spawn "smoke_gen_big"}
		else stuff "dynamite_clockwork"
;			{spawn "shockwave"}
			{spawn "ex_bomb_big"};{spawn "smoke_gen_big"}
		else stuff "flaergun strike"
	        ("grenade_signal_without_physics_mortar")	
		else stuff "grenade big"
			{spawn "hit_shellfg_metal_47_60"};{spawn "ex_grenade_big"}
		else stuff "grenade"
			{spawn "ex_grenade_sm"}
		else stuff "small bullet"
			{spawn "hit_bul_rock01" terrain_texmod}			
		else stuff "pierce bullet"
			{spawn "hit_bul_big_rock01" terrain_texmod}
		else stuff "mortar 120"
			{spawn "ex_grenade_120"}
		else stuff "mortar 80"
			{spawn "ex_grenade_82"}
		else stuff "mortar 50"
	;	  	{spawn "shockwave"}
			{spawn "ex_grenade_50"}
		else stuff "mortar_smoke"
			{spawn "mortar_smoke"}
			{spawn "spheredust_small_short"}
		else stuff "smoke_gr"
			("grenade_smoke_without_physics")
		else stuff "signal_gr"
			("grenade_signal_without_physics")
;-------------new fg fx:
	else stuff "shell ap fx20"
		{spawn "hit_bulbig_dust01" terrain_texmod}
	else stuff "shell fg fx20"
		{spawn "hit_shellfg_ground_37_46"}
		{spawn "hit_bulbig_mud01" terrain_texmod}
	  ;	("shellhole" args 1)
    else stuff "shell fg fx37_46"
		{spawn "hit_shellfg_ground_37_46"}
      ;	("shellhole" args 1)	  
    else stuff "shell fg fx47_60"
		{spawn "hit_shellfg_ground_47_60"}
      ;	("shellhole" args 1)
    else stuff "shell fr fx61_76"
		{spawn "fr_size_med"};{spawn "smoke_gen_big"}
	else stuff "shell fr fx91_130"
		{spawn "fr_size_big"};{spawn "smoke_gen_big"}
		("shellhole" args 2)	  
    else stuff "shell fg fx61_76"
		{spawn "hit_shellfg_ground_61_76"}
	  ;	("shellhole" args 2)
    else stuff "shell sr fx61_76"
		{spawn "srapnel"};{spawn "smoke_gen_med"}
    else stuff "shell sr fx131_190"
		{spawn "srapnel_big"};{spawn "smoke_gen_big"}	  
    else stuff "shell fg fx77_90"
		{spawn "hit_shellfg_ground_77_90"};{spawn "smoke_gen_med"}
	  ;	("shellhole" args 2)
    else stuff "shell fg fx91_130"
		{spawn "hit_shellfg_ground_91_130"};{spawn "smoke_gen_big"}
	  ;	("shellhole" args 3)
	else stuff "shell fg fx131_190"
		{spawn "hit_shellfg_ground_131_190"};{spawn "smoke_gen_big"}
	  ;	("shellhole" args 4)
;-----------------------------------------------	  
	else stuff "zenite"
		{spawn "ex_bul_zenit"}
	else stuff "bullet"
		{spawn "hit_bulbig_rock01" terrain_texmod}
;-----------------------------------------------	
	else stuff "shell size1 fg"
;	  	{spawn "shockwave"}
		{spawn "hit_shellfg_rock1"}
;	  	{spawn "grenade_shellhole" terrain_texmod}
	else stuff "shell size1"
;		{spawn "shockwave"}
		{spawn "hit_shellap_rock1"}
;		{spawn "grenade_shellhole"}
	else stuff "shell size2 ph_shell"
		{spawn "ex_ph_big"}
		{spawn "fx_sphere_ph"};{delay 3 {spawn "smoke_gen_big"}}
		("dummy_smoke_ph")	  
	else stuff "shell size2 fg"
		{spawn "shockwave"}
		{spawn "hit_shellfg_rock2"}		
	else stuff "shell size2"
		{spawn "shockwave"}
		{spawn "hit_shellap_rock2"}
		{if stuff "sm_shell"
			("dummy_smoke")
		}
;		{spawn "shellhole_big_ground"}
	else stuff "shell size3 fg"
		{spawn "shockwave"}
		{spawn "hit_shellfg_rock3"}
	else stuff "shell size3"
		{spawn "shockwave"}
		{spawn "hit_shellfg_rock3"}
;		{spawn "shellhole_big_ground"}
		{if stuff "sm_shell"
			("dummy_smoke")
		}
    else stuff "shell size4"
		{spawn "shockwave"}
		{spawn "hit_shellfg_rock4"};{spawn "smoke_gen_med"}
	else stuff "shell sturmtiger"
		{spawn "1ex_sturmtiger"};{spawn "smoke_gen_big"}
		;("with_crater" name(big))
	else stuff "ap shell"
    	{spawn "ex_grenade_sm"}
	else stuff "big shell extra"
;		{spawn "shockwave"}
		{spawn "ex_bomb_big"};{spawn "smoke_gen_big"}
	else stuff "big shell flame bomb"
		{spawn "ex_flame_shell01"};{spawn "smoke_gen_med"}			
	else stuff "big shell fg bomb"
;		{spawn "shockwave"}
		{spawn "ex_reactive_shell01"};{spawn "smoke_gen_med"}
	else stuff "mine antipersonnel"
		{spawn "ex_grenade_big"}
	else stuff "mine antitank"
		{spawn "ex_arm_big"}
	else stuff "mine clockwork"
		{spawn "ex_anti_big"};{spawn "smoke_gen_big"}
		else stuff "tnt_bag"
;			{spawn "shockwave"}
			{spawn "ex_bomb_big"};{spawn "smoke_gen_big"}
		}
	}
}

{"bridge_wood"
	{on hit
		{spawn "spheredust_small_short"}
	}
	{on detonate
		{if stuff "molotov_coctail"
			{spawn "ex_molot"}{spawn "storm_botter"}
			{spawn "fire_molot_ground"}
		else stuff "goliath"
			{spawn "ex_goliath"}
		else stuff "dynamite"
;			{spawn "shockwave"}
			{spawn "ex_bomb_big_wood"};{spawn "smoke_gen_big"}
		else stuff "flaergun strike"
	        ("grenade_signal_without_physics_mortar")	
		else stuff "grenade big"
			{spawn "hit_shellfg_metal_47_60"};{spawn "ex_grenade_big"}
		else stuff "grenade"
			{spawn "ex_grenade_sm"}
		else stuff "small bullet"
			{spawn "ex_bul_sm01"}
		else stuff "pierce bullet"
			{spawn "ex_bul_big_sm01" terrain_texmod}			
		else stuff "zenite"
			{spawn "ex_bul_zenit"}
		else stuff "bullet"
			{spawn "wood_hit_bul"}
		else stuff "mortar 120"
			{spawn "ex_mort_big_wood"}
		else stuff "mortar 80"
			{spawn "ex_mort_big_wood"}
		else stuff "mortar 50"
			{spawn "ex_mort_sm_wood"}
		else stuff "mortar"
;			{spawn "shockwave"}
			{spawn "ex_bomb_big_wood"};{spawn "smoke_gen_big"}
		else stuff "smoke_gr"
			("grenade_smoke_without_physics")
		else stuff "signal_gr"
		    ("grenade_signal_without_physics")
		else stuff "shell ap fx20"
			{if rand 0.5
				{spawn "hit_bulbig_dust01" terrain_texmod}
			else
				{spawn "hit_bulbig_dust02" terrain_texmod}
			}
		else stuff "shell fr fx61_76"
			{spawn "fr_size_med"};{spawn "smoke_gen_big"}
		else stuff "shell fr fx91_130"
			{spawn "fr_size_big"};{spawn "smoke_gen_big"}
			("shellhole" args 2)		
		else stuff "shell fg fx20"
			{spawn "hit_shellfg_ground_37_46"}
			{spawn "wood_hit_bul"}	 
		else stuff "shell fg fx37_46"
			{spawn "hit_shellfg_ground_37_46"}
			{spawn "wood_hit_bul"}
		else stuff "shell fg fx47_60"
			{spawn "hit_shellfg_ground_47_60"}
			{spawn "wood_hit_bul"}
		else stuff "shell fg fx61_76"
			{spawn "hit_shellfg_ground_61_76"}
			{spawn "wood_hit_bul"}	  
		else stuff "shell sr fx61_76"
			{spawn "srapnel"};{spawn "smoke_gen_med"}
		else stuff "shell sr fx131_190"
			{spawn "srapnel_big"};{spawn "smoke_gen_big"}	 	  
		else stuff "shell fg fx77_90"
			{spawn "hit_shellfg_ground_77_90"};{spawn "smoke_gen_med"}
			{spawn "wood_hit_bul"}	  
		else stuff "shell fg fx91_130"
			{spawn "hit_shellfg_ground_91_130"};{spawn "smoke_gen_big"}
			{spawn "wood_hit_br"}	  
		else stuff "shell fg fx131_190"
			{spawn "hit_shellfg_ground_131_190"};{spawn "smoke_gen_big"}	
			{spawn "wood_hit_br"}		  
		else stuff "big shell extra"
;			{spawn "shockwave"}
			{spawn "ex_bomb_big_wood"};{spawn "smoke_gen_big"}
			{spawn "wood_hit_br"}				
		else stuff "big shell fg bomb"
;			{spawn "shockwave"}
			{spawn "ex_bomb_big_wood"};{spawn "smoke_gen_big"}
		else stuff "big shell fg"
			{spawn "shockwave"}
			{spawn "ex_anti_big_wood"};{spawn "smoke_gen_big"}
		else stuff "big shell ap"
			{spawn "ex_mort_big_wood"}
		else stuff "small shell fg"
			{spawn "shockwave"}
			{spawn "ex_mort_sm_wood"}
		else stuff "shell size2 ph_shell"
			{spawn "ex_ph_big"}
			{spawn "fx_sphere_ph"};{spawn "smoke_gen_big"} 
			("dummy_smoke_ph")	  				
		else stuff "shell fg"
			{spawn "shockwave"}
			{spawn "ex_anti_big_wood"};{spawn "smoke_gen_big"}
		else stuff "shell ap"
			{spawn "ex_mort_sm_wood"}
		else stuff "mine antipersonnel"
			{spawn "ex_grenade_big"}
		else stuff "mine antitank"
			{spawn "ex_mort_big_wood"}
		else stuff "mine clockwork"
			{spawn "ex_anti_big_wood"};{spawn "smoke_gen_big"}
		}
	}
}