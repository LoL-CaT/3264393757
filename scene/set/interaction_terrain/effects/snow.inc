{"snow"
  {on hit
    {if min_mass 100
      {if effector "tree"
        {spawn "tree_crush"}
      else
        {spawn "spheredust_small_w"}
      }
    else min_mass 10
      {spawn "spheredust_small_short"}
    }
  }
  {on detonate
    {if stuff "molotov_coctail"
		{spawn "ex_molot"}{spawn "storm_botter"}
		{spawn "fire_molot_ground"}
		{spawn "fire_shellhole"}
	else stuff "goliath"
		{spawn "ex_goliath"}
    else stuff "dynamite"
;	  	{spawn "shockwave"}
		{spawn "ex_bomb_big"};{spawn "smoke_gen_big"}
		("shellhole" args 4)
    else stuff "dynamite_clockwork"
;	  	{spawn "shockwave"}
		{spawn "ex_bomb_big"};{spawn "smoke_gen_big"}
		("shellhole" args 4)
	else stuff "flaergun strike"
		("grenade_signal_without_physics_mortar")		
    else stuff "grenade big"
		{spawn "ex_grenade_big_snow"}
		("shellhole" args 3)
    else stuff "grenade"
		{spawn "ex_grenade_sm_snow"}
		("shellhole" args 2)
    else stuff "small bullet"
		{spawn "hit_bul_snow01" terrain_texmod}
    else stuff "pierce bullet"
		{spawn "hit_bul_big_snow01" terrain_texmod}		
    else stuff "big mortar"
		{spawn "ex_mort_big_snow"}
		("shellhole" args 3)
	else stuff "mortar_smoke"
		{spawn "mortar_smoke"}
		{spawn "ex_bul_sm_snow"}
    else stuff "mortar 120"
		{spawn "ex_grenade_120_w"}
		("shellhole" args 3)
    else stuff "mortar 80"
		{spawn "ex_grenade_82_w"}
		("shellhole" args 2)
    else stuff "mortar 50"
		{spawn "ex_grenade_50_w"}
		("shellhole" args 1)
    else stuff "mortar"
;	  	{spawn "shockwave"}
		{spawn "ex_bomb_big"};{spawn "smoke_gen_big"}
		("shellhole" args 2)
	else stuff "smoke_gr"
		("grenade_smoke_without_physics")
	else stuff "signal_gr"
		("test")
		("grenade_signal_without_physics")
;-------------new fg fx:
	else stuff "shell ap fx20"
		{spawn "ex_bul_sm_snow"}
	else stuff "shell fg fx20"
		{spawn "hit_shellfg_ground_37_46_w"}
		{spawn "ex_bul_sm_snow"}
		("shellhole" args 1)		
    else stuff "shell fg fx37_46"
		{spawn "hit_shellfg_ground_37_46_w"}
		("shellhole" args 1)
    else stuff "shell fr fx61_76"
		{spawn "fr_size_med_w"};{spawn "smoke_gen_big"}	 
		("shellhole" args 1)
	else stuff "shell fr fx91_130"
		{spawn "fr_size_big_w"};{spawn "smoke_gen_big"}
		("shellhole" args 2)  	  
    else stuff "shell fg fx47_60"
		{spawn "hit_shellfg_ground_47_60_w"}
		("shellhole" args 1)
    else stuff "shell fg fx61_76"
		{spawn "hit_shellfg_ground_61_76_w"}
		("shellhole" args 2)
    else stuff "shell sr fx61_76"
		{spawn "srapnel_w"};{spawn "smoke_gen_med"}
    else stuff "shell sr fx131_190"
		{spawn "srapnel_big_w"};{spawn "smoke_gen_big"}	 	  
    else stuff "shell fg fx77_90"
		{spawn "hit_shellfg_ground_77_90_w"};{spawn "smoke_gen_med"}
		("shellhole" args 2)
    else stuff "shell fg fx91_130"
		{spawn "hit_shellfg_ground_91_130_w"};{spawn "smoke_gen_big"}
		("with_crater" name(norm))
	  ;	("shellhole" args 3)
	else stuff "shell fg fx131_190"
		{spawn "hit_shellfg_ground_131_190_w"};{spawn "smoke_gen_big"}
		("with_crater" name(norm))
	  ;	("shellhole" args 4)
;---------------------------------------------
    else stuff "zenite"
		{spawn "ex_bul_zenit_snow"}
		("shellhole" args 0)
    else stuff "bullet"
		{spawn "hit_bulbig_snow01" terrain_texmod}
;---------------------------------------------
    else stuff "shell size1 fg"
;      	{spawn "shockwave"}
		{spawn "hit_shellfg_snow1"}
		("shellhole" args 2)
    else stuff "shell size1"
;      	{spawn "shockwave"}
		{spawn "hit_shellap_snow1"}
;      	{spawn "grenade_shellhole"}
    else stuff "shell size2 fg"
;      	{spawn "shockwave"}
		{spawn "hit_shellfg_snow2"}
		("with_crater" name(norm))
	else stuff "shell size2 ph_shell"
		{spawn "ex_ph_big"}
		{spawn "fx_sphere_ph"};{delay 3 {spawn "smoke_gen_big"}}
		("dummy_smoke_ph")	  		
    else stuff "shell size2"
;      	{spawn "shockwave"}
		{spawn "hit_shellap_snow2"}
;      	{spawn "shellhole_big_ground"}
		{if stuff "sm_shell"
			("dummy_smoke")
		}  
    else stuff "shell size3 fg"
;      	{spawn "shockwave"}
		{spawn "hit_shellfg_snow3"};{spawn "smoke_gen_med"}
		("with_crater" name(norm))
    else stuff "shell size3"
;      	{spawn "shockwave"}
		{spawn "hit_shellap_snow3"}
;      	{spawn "shellhole_big_ground"}
		{if stuff "sm_shell"
			("dummy_smoke")
		}
    else stuff "shell size4"
;      	{spawn "shockwave"}
		{spawn "hit_shellfg_snow4"};{spawn "smoke_gen_big"}
		("with_crater" name(big))
    else stuff "shell sturmtiger"
		{spawn "1ex_sturmtiger_w"};{spawn "smoke_gen_big"}
		("with_crater" name(big))
    else stuff "big shell extra"
;      	{spawn "shockwave"}
		{spawn "ex_bomb_big_snow" offset 0 0 20};{spawn "smoke_gen_big"}
		("with_crater" name(norm))
    else stuff "big shell extra305"
;      	{spawn "shockwave"}
		{spawn "ex_cannon400_w" offset 0 0 20};{spawn "smoke_gen_big"}
		("with_crater" name(big))
	else stuff "big shell flame bomb"
		{spawn "ex_flame_shell01_w"};{spawn "smoke_gen_med"}
    else stuff "big shell fg bomb"
;     	{spawn "shockwave"}
		{spawn "ex_reactive_shell01_w"};{spawn "smoke_gen_med"}
		("with_crater" name(norm))
    else stuff "big shell fg"
		{spawn "shockwave"}
		{spawn "ex_anti_big_w"};{spawn "smoke_gen_big"}
		("with_crater" name(norm))
    else stuff "big shell ap"
		{spawn "ex_arm_big_w"}
;      	{spawn "shellhole_big_ground"}
    else stuff "small shell fg"
		{spawn "shockwave"}
		{spawn "ex_anti_small_w"}
		{spawn "hit_bulbig_snow01" terrain_texmod}
		("shellhole" args 3)
    else stuff "shell fg"
		{spawn "shockwave"}
		{spawn "ex_anti_big_w"};{spawn "smoke_gen_big"}
		("with_crater" name(norm))
    else stuff "shell ap"
		{spawn "ex_arm_sm_w"}
		{spawn "hit_bulbig_snow02" terrain_texmod}
;      	{spawn "shellhole_big_ground"}
    else stuff "mine antipersonnel"
		{spawn "ex_grenade_big_snow"}
		("shellhole" args 2)
    else stuff "mine antitank"
		{spawn "ex_arm_big_w"}
		("shellhole" args 3)
	else stuff "mine clockwork"
		{spawn "ex_anti_big_w"};{spawn "smoke_gen_big"}
		("shellhole" args 3)
    else stuff "tnt_bag"
;	  	{spawn "shockwave"}
		{spawn "ex_bomb_big"};{spawn "smoke_gen_big"}
		("shellhole" args 4)
    }
  }
}
