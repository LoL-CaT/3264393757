;SDL

(define "water_bullets"
	{if stuff "shell ap fx20"
		{spawn "ex_water_sm"}
	else stuff "shell fg fx20"
		{spawn "ex_water_sm"}	
    else stuff "zenite"
		{spawn "ex_bul_big_w"}
	else stuff "bullet"
		{spawn "ex_bul_sm_w"}
	else stuff "big shell extra"
;    	{spawn "shockwave"}
		{spawn "ex_water_extra_big"}
		{spawn "fish_black"}
	else stuff "big shell ap"
;   	{spawn "shockwave"}
		{spawn "ex_water_big"}
		{spawn "fish_black"}
	else stuff "big shell fg"
;    	{spawn "shockwave"}
		{spawn "ex_water_big"}
		{spawn "fish_black"}
	else stuff "shell ap"
		{spawn "ex_water_sm"}
	else stuff "mortar"
		{spawn "ex_water_extra_big"}
		{spawn "fish_black"}
	else stuff "mortar_smoke"
		{spawn "ex_bul_sm_w"}
		{spawn "drops_puddle_small2"}
		{spawn "dustrun_snow_small2"}
	else stuff "big mortar"
;    	{spawn "shockwave"}
		{spawn "ex_water_big"}
		{spawn "fish_black"}
	}
)
	
(define "shallow_water_bullets"
	{if stuff "shell ap fx20"
		{spawn "ex_water_sm"}
	else stuff "shell fg fx20"
		{spawn "ex_water_sm"}
	else stuff "zenite"
		{spawn "ex_bul_big_w"}
	else stuff "bullet"
		{spawn "hit_bul_water01"}
	else stuff "big shell extra"
;    	{spawn "shockwave"}
		{spawn "ex_water_extra_big"}
	else stuff "big shell ap"
;    	{spawn "shockwave"}
		{spawn "ex_watersh_big"}
	else stuff "big shell fg"
;    	{spawn "shockwave"}
		{spawn "ex_watersh_big"}
	else stuff "shell ap"
		{spawn "ex_water_sm"}
	else stuff "mortar"
		{spawn "ex_water_extra_big"}
	else stuff "big mortar"
;   	{spawn "shockwave"}
		{spawn "ex_watersh_big"}

  }
)

(define "water_hits"
  {if min_mass 50
    {spawn "spherewater_big"}
  else min_mass 0.5
    {spawn "spherewater_small"}
  else effector "human"
    {spawn "spherewater_big"}
  else effector "steel"
    {spawn "spherewater_small"}
  }
; {if min_mass 100
;   {spawn "spheredust_small"}
; else min_mass 10
;   {spawn "spheredust_small_short"}
; }
)

(define "water_detonate"
	{if stuff "shell fg fx20"
		{spawn "ex_water_sm"}
  else stuff "molotov_coctail"
    {spawn "spherewater_small"}
  else stuff "goliath"
	{spawn "ex_water_big"}
  else stuff "dynamite"
;    {spawn "shockwave"}
    {spawn "ex_water_big"}
    {spawn "fish_black"}
  else stuff "dynamite_clockwork"
;    {spawn "shockwave"}
    {spawn "ex_water_big"}
    {spawn "fish_black"}
  else stuff "flaergun strike"
	("grenade_signal_without_physics_mortar")
  else stuff "grenade big"
;    {spawn "shockwave"}
    {spawn "ex_water_big"}
    {spawn "fish_black"}
  else stuff "grenade"
;    {spawn "shockwave"}
    {spawn "ex_water_sm"}
  else stuff "mine antipersonnel"
;    {spawn "shockwave"}
    {spawn "ex_water_sm"}
  else stuff "mine antitank"
;    {spawn "shockwave"}
    {spawn "ex_water_big"}
    {spawn "fish_black"}
  else stuff "mine clockwork"
    {spawn "ex_water_big"}
    {spawn "fish_black"}
  else stuff "tnt_bag"
;    {spawn "shockwave"}
    {spawn "ex_water_big"}
    {spawn "fish_black"}
  else stuff "shell fg"
;    {spawn "shockwave"}
    {spawn "ex_water_big"}
    {spawn "fish_black"}
  else stuff "smoke_gr"
	("grenade_smoke_without_physics")
  else stuff "signal_gr"
	("grenade_signal_without_physics")
    else stuff "mortar 120"
      {spawn "ex_water_extra_big"}
    else stuff "mortar 80"
      {spawn "ex_water_big"}
    else stuff "mortar 50"
      {spawn "ex_water_sm"}
  }
)

(define "shallow_water_detonate"
	{if stuff "shell fg fx20"
		{spawn "ex_water_sm"}
  else stuff "molotov_coctail"
    {spawn "spherewater_small"}
	else stuff "goliath"
	{spawn "ex_watersh_big"}	
  else stuff "dynamite"
    {spawn "ex_watersh_big"}
  else stuff "dynamite_clockwork"
    {spawn "ex_watersh_big"}
  else stuff "flaergun strike"
	("grenade_signal_without_physics_mortar")
  else stuff "grenade big"
    {spawn "ex_watersh_big"}
  else stuff "grenade"
    {spawn "ex_water_sm"}
  else stuff "mine antipersonnel"
    {spawn "ex_water_sm"}
  else stuff "mine antitank"
    {spawn "ex_watersh_big"}
  else stuff "mine clockwork"
    {spawn "ex_watersh_big"}
  else stuff "tnt_bag"
    {spawn "ex_watersh_big"}
  else stuff "shell fg"
    {spawn "ex_watersh_big"}
  else stuff "smoke_gr"
	("grenade_smoke_without_physics")
  else stuff "signal_gr"
	("grenade_signal_without_physics")
  }
)

{"shallow_water"
  {on bullet  ("shallow_water_bullets") }
  {on hit   ("water_hits")    }
  {on detonate
	("shallow_water_detonate")
	("water_bullets")
  }
}
{"water"
  {on bullet  ("water_bullets") }
  {on hit   ("water_hits")    }
  {on detonate("water_detonate")  }
}
{"underwater"
; {on hit   {con "underwater hit"}    }
  {on detonate
    ("water_detonate")
    {if stuff "shell size2"
		("shellhole" args 2)
	else stuff "shell size3" or stuff "shell size4"
		("shellhole" args 3)
    }
  }
}

{"puddle"
  {on hit
    {if min_mass 100
      {spawn "spheredust_puddle_small"}
    else min_mass 10
      {spawn "spheredust_puddle_small_short"}
    }
  }
  {on detonate
    {if stuff "molotov_coctail"
      {spawn "ex_molot"}{spawn "storm_botter"}
      {spawn "fire_molot_ground"}
      {spawn "fire_shellhole"}
	else stuff "goliath"
		{spawn "ex_goliath_puddle"}		  
    else stuff "dynamite"
      {spawn "ex_bomb_big_puddle"};{spawn "smoke_gen_big"}
      ("shellhole" args 4)
    else stuff "dynamite_clockwork"
      {spawn "ex_bomb_big_puddle"};{spawn "smoke_gen_big"}
      ("shellhole" args 3)
	else stuff "flaergun strike"
	  ("grenade_signal_without_physics_mortar")  
    else stuff "grenade big"
      {spawn "hit_shellfg_puddle_47_60"};{spawn "ex_grenade_big"}
      ("shellhole" args 3)
    else stuff "grenade"
      {spawn "ex_grenade_sm_puddle"}
      ("shellhole" args 2)
	else stuff "smoke_gr"
	  ("grenade_smoke_without_physics")
	else stuff "signal_gr"
	  ("grenade_signal_without_physics")
;-------------new fg fx:
	else stuff "shell ap fx20"
	  {spawn "hit_bulbig_dust01" terrain_texmod}
	else stuff "shell fg fx20"
      {spawn "hit_shellfg_puddle_37_46"}
      {spawn "hit_bulbig_mud01" terrain_texmod}
	  ("shellhole" args 1)
    else stuff "shell fg fx37_46"
      {spawn "hit_shellfg_puddle_37_46"}
      ("shellhole" args 1)
    else stuff "shell fr fx61_76"
      {spawn "fr_size_med"};{spawn "smoke_gen_big"}	 
	  ("shellhole" args 1)
	else stuff "shell fr fx91_130"
	  {spawn "fr_size_big"};{spawn "smoke_gen_big"}
	  ("shellhole" args 2)  	  	  
    else stuff "shell fg fx47_60"
      {spawn "hit_shellfg_puddle_47_60"}
      ("shellhole" args 1)
    else stuff "shell fg fx61_76"
      {spawn "hit_shellfg_puddle_61_76"}
	  ("shellhole" args 2)
    else stuff "shell sr fx61_76"
      {spawn "srapnel_water"};{spawn "smoke_gen_med"}
    else stuff "shell sr fx131_190"
      {spawn "srapnel_big_water"};{spawn "smoke_gen_big"}	 	  
    else stuff "shell fg fx77_90"
      {spawn "hit_shellfg_puddle_77_90"};{spawn "smoke_gen_med"}
	  ("shellhole" args 2)
    else stuff "shell fg fx91_130"
      {spawn "hit_shellfg_puddle_91_130"};{spawn "smoke_gen_big"}
	  ("with_crater" name(norm))
	  ;("shellhole" args 3)
	else stuff "shell fg fx131_190"
      {spawn "hit_shellfg_puddle_131_190"};{spawn "smoke_gen_big"}
	  ("with_crater" name(norm))
	 ;("shellhole" args 4)
    else stuff "small bullet"
		{spawn "hit_bul_water01"}
    else stuff "zenite"
      {spawn "ex_bul_big_w"}
    else stuff "bullet"
	  {spawn "hit_bul_water01"}
    else stuff "mortar 120"
      {spawn "ex_grenade_120_puddle"}
      ("shellhole" args 3)
    else stuff "mortar 80"
      {spawn "ex_grenade_82_puddle"}
      ("shellhole" args 2)
    else stuff "mortar 50"
;	  {spawn "shockwave"}
      {spawn "ex_grenade_50_puddle"}
      ("shellhole" args 1)
  	else stuff "big mortar_smoke"
	  {spawn "mortar_smoke"}
	  {spawn "spheredust_small_short"}
    else stuff "shell size1 fg"
;     {spawn "shockwave"}
      {spawn "hit_shellfg_ground1"}
      ("shellhole" args 2)
    else stuff "shell size1"
;     {spawn "shockwave"}
      {spawn "hit_shellap_mud1"}
;     {spawn "grenade_shellhole"}
    else stuff "shell size2 fg"
;     {spawn "shockwave"}
	  {spawn "hit_shellfg_ground2"};{if rand 0.4 {spawn "smoke_gen_med"}}
	  ("with_crater" name(norm))
	else stuff "shell size2 ph_shell"
	  {spawn "spherewater_small"} 		
    else stuff "shell size2"
;     {spawn "shockwave"}
      {spawn "hit_shellap_mud2"}
;     {spawn "shellhole_big_ground"}
	  {if stuff "sm_shell"
		("dummy_smoke")
	  }	  
    else stuff "shell size3 fg"
;     {spawn "shockwave"}
	  {spawn "hit_shellfg_ground3"};{spawn "smoke_gen_big"}
	  ("with_crater" name(norm))
    else stuff "shell size3"
;     {spawn "shockwave"}
      {spawn "hit_shellap_mud2"}
;     {spawn "shellhole_big_ground"}
	  {if stuff "sm_shell"
	    ("dummy_smoke")
	  }
    else stuff "shell size4"
;     {spawn "shockwave"}
	  {spawn "hit_shellfg_ground4"};{spawn "smoke_gen_big"}
	  ("with_crater" name(big))
    else stuff "shell sturmtiger"
	  {spawn "1ex_sturmtiger"};{spawn "smoke_gen_big"}
	  ("with_crater" name(big))
    else stuff "big shell extra"
;     {spawn "shockwave"}
	  {spawn "ex_bomb_big_puddle" offset 0 0 20};{spawn "smoke_gen_big"}
	  ("with_crater" name(norm))
    else stuff "big shell fg bomb"
;     {spawn "shockwave"}
	  {spawn "hit_shellfg_mud4"};{spawn "smoke_gen_med"}
      ("with_crater" name(norm))
    else stuff "big shell fg"
	  {spawn "shockwave"}
	  {spawn "ex_anti_big"};{spawn "smoke_gen_big"}
	  ("with_crater" name(norm))
    else stuff "big shell ap"
      {spawn "ex_arm_big"}
      ("shellhole" args 3)
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
      ("shellhole" args 1)
    else stuff "mine antipersonnel"
      {spawn "ex_grenade_big"}
      ("shellhole" args 2)
    else stuff "mine antitank"
      {spawn "ex_anti_big"};{spawn "smoke_gen_big"}
      ("shellhole" args 3)
	 else stuff "mine clockwork"
	  {spawn "ex_anti_big"};{spawn "smoke_gen_big"}
	  ("shellhole" args 3)
    else stuff "tnt_bag"
;	  {spawn "shockwave"}
      {spawn "ex_bomb_big"};{spawn "smoke_gen_big"}
      ("shellhole" args 4)
    }
  }
}

(define "swamp_terrain"
  {on hit   ("water_hits")    }
  {on bullet  ("water_bullets") }
  {on detonate("water_detonate")
        ("water_bullets")
    {if stuff "shell"
      ("shellhole" args 3)
    }
  }
)

{"swamp"
  ("swamp_terrain")
}