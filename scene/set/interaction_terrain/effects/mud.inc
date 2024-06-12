;SDL
{"mud"
  {on hit
    {if min_mass 100
      {spawn "spheredust_small"}
    else min_mass 10
      {spawn "spheredust_small_short"}
    }
  }
  {on detonate
    {if stuff "molotov_coctail"
		{spawn "ex_molot"}{spawn "storm_botter"}
	else stuff "goliath"
		{spawn "ex_goliath"}
    else stuff "dynamite"
;	  	{spawn "shockwave"}
      ;	{spawn "ex_bomb_big"}
		{spawn "hit_shellfg_ground_131_190"};{spawn "smoke_gen_big"}
		("shellhole" args 4)
    else stuff "dynamite_clockwork"
;	  	{spawn "shockwave"}
     ; 	{spawn "ex_bomb_big"}
		{spawn "hit_shellfg_ground_131_190"};{spawn "smoke_gen_big"}
		("shellhole" args 4)
	else stuff "flaergun strike"
	    ("grenade_signal_without_physics_mortar")
    else stuff "grenade big"
		{spawn "hit_shellfg_metal_47_60"};{spawn "ex_grenade_big"}
		("shellhole" args 3)
    else stuff "grenade"
		{spawn "ex_grenade_sm"}
		("shellhole" args 2)
    else stuff "small bullet"
		{spawn "hit_bul_mud01" terrain_texmod}
    else stuff "pierce bullet"
		{spawn "hit_bul_big_mud01" terrain_texmod}		
	else stuff "smoke_gr"
		("grenade_smoke_without_physics")
	else stuff "signal_gr"
		("test")
		("grenade_signal_without_physics")
;-------------new fg fx:
	else stuff "shell ap fx20"
		{spawn "hit_bulbig_dust01" terrain_texmod}
	else stuff "shell fg fx20"
		{spawn "hit_shellfg_ground_37_46"}
		{spawn "hit_bulbig_mud01" terrain_texmod}
		("shellhole" args 1)
    else stuff "shell fg fx37_46"
		{spawn "hit_shellfg_ground_37_46"}
		("shellhole" args 1)
    else stuff "shell fr fx61_76"
		{spawn "fr_size_med"};{spawn "smoke_gen_big"}	  
		("shellhole" args 1)
    else stuff "shell fg fx47_60"
		{spawn "hit_shellfg_ground_47_60"}
		("shellhole" args 1)
    else stuff "shell fg fx61_76"
		{spawn "hit_shellfg_ground_61_76"}
		("shellhole" args 2)
    else stuff "shell sr fx61_76"
		{spawn "srapnel"};{spawn "smoke_gen_med"}
	else stuff "shell sr fx131_190"
		{spawn "srapnel_big"};{spawn "smoke_gen_med"}		
    else stuff "shell fg fx77_90"
		{spawn "hit_shellfg_ground_77_90"};{spawn "smoke_gen_med"}
		("shellhole" args 2)
    else stuff "shell fg fx91_130"
		{spawn "hit_shellfg_ground_91_130"};{spawn "smoke_gen_big"}
		("with_crater" name(norm))
	  ;	("shellhole" args 3)
	else stuff "shell fg fx131_190"
		{spawn "hit_shellfg_ground_131_190"};{spawn "smoke_gen_big"}
		("with_crater" name(norm))
	  ;	("shellhole" args 4)
    else stuff "zenite"
		{spawn "ex_bul_zenit"}
		("shellhole" args 0)
    else stuff "bullet"
		{spawn "hit_bulbig_mud01" terrain_texmod}
	else stuff "shell size1 fg"
		{spawn "hit_shellfg_mud1"}
		("shellhole" args 2)
    else stuff "shell size1"
		{spawn "hit_shellap_mud1"}
	else stuff "shell size2 ph_shell"
		{spawn "ex_ph_big"}
		{spawn "fx_sphere_ph"};{delay 3 {spawn "smoke_gen_big"}}
		("dummy_smoke_ph")	  	  
    else stuff "shell size2 fg"
		{spawn "hit_shellfg_mud2"}
		("with_crater" name(norm))
    else stuff "shell size2"
		{spawn "hit_shellap_mud2"}
		{if stuff "sm_shell"
			("dummy_smoke")
		}
    else stuff "shell size3 fg"
		{spawn "hit_shellfg_mud3"};{spawn "smoke_gen_med"}
		("with_crater" name(norm))
    else stuff "shell size3"
		{spawn "hit_shellap_mud3"}
		{if stuff "sm_shell"
			("dummy_smoke")
		}
    else stuff "shell size4"
		{spawn "hit_shellap_mud4"}
		("with_crater" name(big))
    else stuff "mortar 120"
		{spawn "ex_grenade_120"}
		("shellhole" args 3)
    else stuff "mortar 80"
		{spawn "ex_grenade_82"}
		("shellhole" args 2)
    else stuff "mortar 50"
		{spawn "ex_grenade_50"}
		("shellhole" args 1)
	else stuff "big mortar_smoke"
		{spawn "mortar_smoke"}
		{spawn "spheredust_small_short"}
    else stuff "shell sturmtiger"
		{spawn "1ex_sturmtiger"};{spawn "smoke_gen_big"}
		("with_crater" name(big))
    else stuff "big shell extra"
;      	{spawn "shockwave"}
		{spawn "ex_bomb_big"};{spawn "smoke_gen_big"}
		("with_crater" name(norm))
    else stuff "big shell fg bomb"
;      	{spawn "shockwave"}
		{spawn "hit_shellfg_mud4"};{spawn "smoke_gen_med"}
		("with_crater" name(norm))
    else stuff "big shell fg"
		{spawn "shockwave"}
		{spawn "ex_anti_big"};{spawn "smoke_gen_big"}
		("with_crater" name(norm))
    else stuff "big shell ap"
		{spawn "ex_arm_big"}
		("with_crater" name(small))
    else stuff "small shell fg"
		{spawn "shockwave"}
		{spawn "ex_anti_small"}
		("shellhole" args 3)
    else stuff "shell fg"
		{spawn "shockwave"}
		{spawn "ex_anti_big"};{spawn "smoke_gen_big"}
		("with_crater" name(norm))
    else stuff "shell ap"
		{spawn "ex_arm_sm"}
		("with_crater" name(small))
    else stuff "mine antipersonnel"
		{spawn "ex_grenade_big"}
		("shellhole" args 2)
    else stuff "mine antitank"
		{spawn "ex_arm_big"}
		("shellhole" args 3)
	else stuff "mine clockwork"
		{spawn "ex_anti_big"};{spawn "smoke_gen_big"}
		("shellhole" args 3)
    else stuff "tnt_bag"
;		{spawn "shockwave"}
		{spawn "ex_bomb_big"};{spawn "smoke_gen_big"}
		("shellhole" args 4)
    }
  }
}
