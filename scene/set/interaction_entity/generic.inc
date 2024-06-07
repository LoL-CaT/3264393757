(include "defines_effects.inc")
{"generic"
	{on "shell_sturmtiger"
		{spawn "1ex_sturmtiger"}
		;{if stuff "with_crater"	{spawn "crater_big" terrain_texmod}}
	}
	{on "shell_sturmtiger_w"
		{spawn "1ex_sturmtiger_w"}
	}
	{on "hit_fx_flesh"
		{if stuff "zenite"
			;{spawn "ex_air_norm"}
		else stuff "shell sturmtiger"
			{call "shell_sturmtiger"}
		else stuff "fx20"
			{spawn "bloodsparks_big"}
		else stuff "mortar"
			{spawn "ex_air_big"}
;		else stuff "fx20 fg"
;			{spawn "hit_shellfg_metal_37_46"}
;		else stuff "shell fg fx37_46"
;			{spawn "hit_shellfg_ground_37_46"}
;		else stuff "shell fg fx47_60"
;			{spawn "hit_shellfg_ground_47_60"}
;		else stuff "shell fg fx61_76"
;			{spawn "hit_shellfg_ground_61_76"}
;		else stuff "shell fg fx77_90"
;			{spawn "hit_shellfg_ground_77_90"}
;		else stuff "shell fg fx91_130"
;			{spawn "hit_shellfg_ground_91_130"}
;		else stuff "shell fg fx131_190"
;			{spawn "hit_shellfg_ground_131_190"}
		else stuff "size4"
			{spawn "ex_air_big2"}
		else stuff "shell fg"
;			{spawn "ex_air_big"}
			{spawn "bloodsparks_big"}
		else stuff "bazooka"
			{spawn "ex_air_big"}
		else stuff "signal_gr"
			{spawn "grenade_signal"
				{call "activate"}
				{delay 0.05 0.025
					{impulse up 0.3 0.1 dir 0.5 0.2 cx 0.5 0.2 cy 0.5 0.2 rnd_dir 0.5 0.2 com}
				}
			}
		}
	}
	(define "hit_fx_steel_part1"
		else stuff "fg fx20"
		{spawn "hit_shellfg_metal_37_46"}
		else stuff "shell fg fx37_46"
		  {spawn "hit_shellfg_metal_37_46"}
		  {spawn "grenade_shellhole" terrain_texmod}
		else stuff "shell fg fx47_60"
		  {spawn "hit_shellfg_metal_47_60"}
		  {spawn "grenade_shellhole" terrain_texmod}
		else stuff "shell fg fx61_76"
		  {spawn "hit_shellfg_metal_61_76"}
		  {spawn "grenade_shellhole" terrain_texmod}
		else stuff "shell fg fx77_90"
		  {spawn "hit_shellfg_metal_77_90"}
		  {spawn "grenade_shellhole" terrain_texmod}
		else stuff "shell fg fx91_130"
		  {spawn "hit_shellfg_metal_91_130"}
		  {spawn "grenade_shellhole" terrain_texmod}
		else stuff "shell fg fx131_190"
		  {spawn "hit_shellfg_metal_131_190"}
		  {spawn "grenade_shellhole" terrain_texmod}
	)
	(define "hit_fx_steel_part2"
		else stuff "size4"
			{spawn "metal_hit_fg_big"}
			{spawn "ex_tank_HE_shell"}
		else stuff "shell small fg"
			{spawn "metal_hit_fg"}
			{spawn "ex_tank_HE_shell"}
	)
	(define "hit_fx_steel_part3"
		else stuff "shell fg"
			{spawn "metal_hit_fg"}
			{spawn "ex_tank_HE_shell"}
	)
	(define "hit_fx_steel_off")
	(define "hit_fx_steel"
		{if stuff "bullet"
			{spawn "metal_hit_bul"}
		else stuff "shell sturmtiger"
			{call "shell_sturmtiger"}
		else stuff "mortar 120"
			{spawn "metal_hit_fg_size3"}
		else stuff "mortar 80"
			{spawn "metal_hit_fg_size2"}
		else stuff "mortar 50"
			{spawn "metal_hit_fg"}
		else stuff "mortar"
			{spawn "metal_hit_br"}
		else stuff "ap fx20"
			{spawn "metal_hit_bul"}
		else stuff "bzt fx20"
			{spawn "metal_hit_bul"}	
		;("hit_fx_steel_%n1")
		else stuff "zenite"
			{spawn "metal_hit_bul"}
			{spawn "ex_air_sm"}
		;("hit_fx_steel_%n2")
		else stuff "shell small"
			{spawn "metal_hit_br_small"}
		;("hit_fx_steel_%n3")
		else stuff "shell ap fx37_46"
			{spawn "metal_hit_br_small"}
			{spawn "sparks_flow01_div2"}
			{spawn "sparks_flow01_div2"}
		else stuff "shell ap fx47_60"
			{spawn "metal_hit_br_small"}
			{spawn "sparks_flow01_div2"}
			{spawn "sparks_flow01"}
		else stuff "shell ap fx61_76"
			{spawn "metal_hit_br"}
			{spawn "sparks_flow01"}
			{spawn "sparks_flow02_div2"}
		else stuff "shell ap fx77_90"
			{spawn "metal_hit_br"}
			{spawn "sparks_flow02_div2"}
			{spawn "sparks_flow02"}
		else stuff "shell ap fx91_130"
			{spawn "metal_hit_br"}
			{spawn "sparks_flow02"}
			{spawn "sparks_flow03"}
		else stuff "shell ap fx131_190"
			{spawn "metal_hit_br"}
			{spawn "sparks_flow03"}
			{spawn "sparks_flow03"}
		else stuff "shell sr fx61_76"
			{spawn "srapnel"}
		else stuff "shell sr fx131_190"
			{spawn "srapnel_big"}
		else stuff "shell fr fx61_76"
		  {spawn "fr_size_med"}
		else stuff "shell fr fx91_130"
		  {spawn "fr_size_big"}				
		else stuff "fg"
			{spawn "ex_tank_HE_shell"}
		else stuff "fg_gr"
			{spawn "ex_tank_HE_shell"}
		else stuff "gr_ic"
			{spawn "ex_tank_incendiary_shell"}
		else stuff "shell"
			{spawn "metal_hit_br"}
		else stuff "signal_gr"
			{spawn "grenade_signal"
				{call "activate"}
				{delay 0.05 0.025
					{impulse up 0.3 0.1 dir 0.5 0.2 cx 0.5 0.2 cy 0.5 0.2 rnd_dir 0.5 0.2 com}
				}
			}
		}
	)
	{on "hit_fx_steel_pass"
		("hit_fx_steel" n1(off) n2(off) n3(off))
	}
	{on "hit_fx_steel"
		("hit_fx_steel" n1(part1) n2(part2) n3(part3))
	}
	(define "hit_fx_wood_part1"
		else stuff "shell sturmtiger"
			{call "shell_sturmtiger"}
		else stuff "fx20 fg"
			{spawn "hit_shellfg_metal_37_46"}
		else stuff "shell fg fx37_46"
			{spawn "hit_shellfg_ground_37_46"}
		else stuff "shell fg fx47_60"
			{spawn "hit_shellfg_ground_47_60"}
		else stuff "shell fg fx61_76"
			{spawn "hit_shellfg_ground_61_76"}
		else stuff "shell fg fx77_90"
			{spawn "hit_shellfg_ground_77_90"}
		else stuff "shell fg fx91_130"
			{spawn "hit_shellfg_ground_91_130"}
		else stuff "shell fg fx131_190"
			{spawn "hit_shellfg_ground_131_190"}
		else stuff "shell sr fx61_76"
			{spawn "srapnel"}
		else stuff "shell sr fx131_190"
			{spawn "srapnel_big"}
		else stuff "shell fr fx61_76"
		  {spawn "fr_size_med"}
		else stuff "shell fr fx91_130"
		  {spawn "fr_size_big"}				
	)
	(define "hit_fx_wood_part2"
		else stuff "shell fg"
			{spawn "ex_mort_big"}
	)
	(define "hit_fx_wood_off")
	(define "hit_fx_wood"
		{if stuff "bullet"
			{spawn "wood_hit_bul"}
		else stuff "ap fx20"
			{spawn "wood_hit_bul"}
		else stuff "bzt fx20"
			{spawn "wood_hit_bul"}	
		("hit_fx_wood_%n1")
		else stuff "mortar"
			{spawn "wood_hit_fg"}
		else stuff "zenite"
			{spawn "wood_hit_bul"}
		else stuff "shell small"
			{spawn "wood_hit_br_small"}
		("hit_fx_wood_%n2")
		else stuff "signal_gr"
			{spawn "grenade_signal"
				{call "activate"}
				{delay 0.05 0.025
					{impulse up 0.3 0.1 dir 0.5 0.2 cx 0.5 0.2 cy 0.5 0.2 rnd_dir 0.5 0.2 com}
				}
			}
		else stuff "shell"
			{spawn "wood_hit_br"}
		}
	)
	{on "hit_fx_wood_pass"
		("hit_fx_wood" n1(off) n2(off))
	}
	{on "hit_fx_wood"
		("hit_fx_wood" n1(part1) n2(part2))
	}
	(define "hit_fx_concrete_part1"
		else stuff "fx20 fg"
			{spawn "hit_shellfg_metal_37_46"}
		else stuff "shell fg fx37_46"
			{spawn "hit_shellfg_ground_37_46"}
		else stuff "shell fg fx47_60"
			{spawn "hit_shellfg_ground_47_60"}
		else stuff "shell fg fx61_76"
			{spawn "hit_shellfg_ground_61_76"}
		else stuff "shell fg fx77_90"
			{spawn "hit_shellfg_ground_77_90"}
		else stuff "shell fg fx91_130"
			{spawn "hit_shellfg_ground_91_130"}
		else stuff "shell fg fx131_190"
			{spawn "hit_shellfg_ground_131_190"}
		else stuff "shell sr fx61_76"
			{spawn "srapnel"}
		else stuff "shell sr fx131_190"
			{spawn "srapnel_big"}
		else stuff "shell fr fx61_76"
		  {spawn "fr_size_med"}
		else stuff "shell fr fx91_130"
		  {spawn "fr_size_big"}				
	)
	(define "hit_fx_concrete"
		{if stuff "bullet"
			{spawn "stone_hit_bul"}
			{spawn "ex_air_sm"}
		else stuff "shell sturmtiger"
			{call "shell_sturmtiger"}
		else stuff "mortar 120"
			{spawn "stone_hit_big"}
		else stuff "mortar 80"
			{spawn "stone_hit_br"}
		else stuff "mortar 50"
			{spawn "stone_hit_small"}
		else stuff "ap fx20"
			{spawn "stone_hit_bul"}
		else stuff "bzt fx20"
			{spawn "stone_hit_bul"}	
		("hit_fx_concrete_%n1")
		else stuff "zenite"
			{spawn "stone_hit_bul"}
			{spawn "ex_air_sm"}
		else stuff "big shell fg"
			{spawn	"stone_hit_br_big"}
		else stuff "shell small"
			{spawn	"stone_hit_br_small"}
		else stuff "signal_gr"
			{spawn "grenade_signal"
				{call "activate"}
				{delay 0.05 0.025
					{impulse up 0.3 0.1 dir 0.5 0.2 cx 0.5 0.2 cy 0.5 0.2 rnd_dir 0.5 0.2 com}
				}
			}
		else stuff "shell ap gr_ic"
			{spawn	"stone_hit_br"}
			{spawn	"metal_hit_fg_a"}
		else
			{spawn	"stone_hit_br"}
		}
	)
	(define "hit_fx_concrete_off")
	{on "hit_fx_concrete_pass"
		("hit_fx_concrete" n1(off))
	}
	{on "hit_fx_concrete"
		("hit_fx_concrete" n1(part1))
	}
	(define "hit_fx_sand_part1"
		else stuff "fx20 fg"
			{spawn "hit_shellfg_metal_37_46"}
		else stuff "fx37_46 fg"
			{spawn "hit_shellfg_metal_37_46"}
	)
	(define "hit_fx_sand_off")
	(define "hit_fx_sand"
		{if stuff "zenite"
			{spawn "ex_air_sm"}
			{spawn "sand_hit_bul"}
		else stuff "shell sturmtiger"
			{call "shell_sturmtiger"}
		else stuff "ap fx20"
			{spawn "stone_hit_bul"}
		else stuff "bzt fx20"
			{spawn "stone_hit_bul"}	
		("hit_fx_sand_%n1")
		else stuff "mortar"
			{spawn "ex_mort_sm"}
		else stuff "shell fg"
			{spawn "ex_mort_big"}
		else stuff "shell sr fx61_76"
			{spawn "srapnel"}
		else stuff "shell sr fx131_190"
			{spawn "srapnel_big"}
		else stuff "shell fr fx61_76"
		  {spawn "fr_size_med"}
		else stuff "shell fr fx91_130"
		  {spawn "fr_size_big"}				
		else stuff "bazooka"
			{spawn "ex_air_big"}
		else stuff "signal_gr"
			{spawn "grenade_signal"
				{call "activate"}
				{delay 0.05 0.025
					{impulse up 0.3 0.1 dir 0.5 0.2 cx 0.5 0.2 cy 0.5 0.2 rnd_dir 0.5 0.2 com}
				}
			}
		else
			{spawn "sand_hit_small"}
		}
	)
	{on "hit_fx_sand_pass"
		("hit_fx_sand" n1(off))
	}
	{on "hit_fx_sand"
		("hit_fx_sand" n1(part1))
	}
	{on "hit_fx_ice"
		{if stuff "shell fg"
			{spawn "ex_mort_sm_snow"}
		else stuff "shell sturmtiger"
			{call "shell_sturmtiger_w"}
		else stuff "signal_gr"
			{spawn "grenade_signal"
				{call "activate"}
				{delay 0.05 0.025
					{impulse up 0.3 0.1 dir 0.5 0.2 cx 0.5 0.2 cy 0.5 0.2 rnd_dir 0.5 0.2 com}
				}
			}
		else
			{spawn "snow_hit_small"}
		}
	}
	; When a bullet hits, the scripts are called in the following sequence:
	; 1. bullet_hit
	;	- have no specified hit info;
	;	- detonate must be called there, because it can interrupt other hit processing;
	;	- called once per entity;
	; 2. bullet_hit_info 
	;	- conditions available: bullet_ricochet, bullet_pass, bullet_stuck, bullet_detonate, *bullet_pierce, *bullet_damage, *bullet_wreak, *obstacle_hit;
	;	- prefer to use it for visualization information;
	;	- called once per entity
	; 3. bullet_pierce
	;	- called for each pierced volume
	; 4. bullet_reflect or bullet_stuck
	;	- called once per entity if not pierced, destroyed or weaked
	; * bullet_wreak - checking that there was a weakening of the armor
	; * bullet_pierce - pierce only
	; * bullet_damage - pierce and damage
	; * obstacle_hit - not a player pointed or manual control target; can be combained with bullet_* conditions;
	{on bullet_hit_info
		{if not under_water
			{if bullet_pass
				{if material "flesh"
					{call "hit_fx_flesh"}
				else material "steel"
					{call "hit_fx_steel_pass"}
				else material "steelball"
					{spawn "metal_hit_bul"}
				else material "wood"
					{call "hit_fx_wood_pass"}
				else material "concrete"
					{call "hit_fx_concrete_pass"}
				else material "sand"
					{call "hit_fx_sand_pass"}
				else material "ice"
					{call "hit_fx_ice"}
				}
			else
				{if material "flesh"
					{call "hit_fx_flesh"}
				else material "steel"
					{call "hit_fx_steel"}
				else material "steelball"
					{spawn "metal_hit_bul"}
				else material "wood"
					{call "hit_fx_wood"}
				else material "concrete"
					{call "hit_fx_concrete"}
				else material "sand"
					{call "hit_fx_sand"}
				else material "ice"
					{call "hit_fx_ice"}
				}
			}
			{if material "flesh"
				{start_sound "human/hit" user_control}
			}
			{if material "steel"
			    {if stuff "bullet"
	                {start_sound "hit/small/metal" user_control}
			    else
			        {if stuff "shell ap" or stuff "shell apcr" or stuff "ptr" or stuff "bzt"
				        {if not stuff "gr_ic"
			                {if bullet_pierce
			                   {start_sound "hit/big/metal_penetration" user_control}
			  	            else bullet_damage
			                   {start_sound "hit/big/metal_penetration" user_control}
			                else bullet_ricochet
			                   {start_sound "hit/big/metal_recochet" user_control}
			                else
			                   {start_sound "hit/big/metal_hit" user_control}
			                }
						}
		 	        }
			    }
			}
		}
	}
}