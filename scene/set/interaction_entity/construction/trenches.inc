{"trench_construct"
	{on "install"
		{if terrain_fx "snow"		{spawn "circledust_norm2_w"}
            else 		        	{spawn "circledust_norm2"}
        }
		{remove_grass 1}
	}
	{on "got_any_damage"
		{if game_param 	"biom" "snow"
			{spawn "spheredust_small_w" "root"}
;			{con "-------circledust_norm2_w"}
		else
			{spawn "spheredust_small" "root"}
;			{con "-------circledust_norm2"}
		}
	}
	{on contact
		{if not fortification_crushed
			{if effector "tank"
				{fortification_damage_contact
					; impulse = speed * mass
					{linear_impulse_to_damage 
						0 0
						1000000 0.1
					}
					{angular_impulse_to_damage
						0 0
						1000000 0.05
					}
				}
				{if not flag "fx_damage"
					{set "fx_damage" 1}
					{call "got_any_damage"}
				}
				{delay 0.3
					{set "fx_damage" 0}
				}
			}
		}
	}
	{on seismic
		{if not fortification_crushed
			{fortification_damage_seismic
				{energy_fading  ; distance to epicenter - koefficient
					0 1   	
					100 0
				}
				{energy_to_health_dec 
					0 	0
					3.4 2.5
					7.4 4
					8.4	7.5
					32 	50
					50	100
				}
			}
			{call "got_any_damage"}
		}
	}
	{on bullet_hit
		{if stuff "flaergun strike"
	        ("grenade_signal_without_physics_mortar")
		else stuff "smoke_gr"
			("grenade_smoke")			
		}
	}
}

{"remove_grass_2_5"	{on spawn		{remove_grass 2.5}}}
{"remove_grass_4"	{on spawn		{remove_grass 4}}}
{"remove_grass_4_5"	{on spawn		{remove_grass 4.5}}}
{"remove_grass_5"	{on spawn		{remove_grass 5}}}
{"remove_grass_5_5"	{on spawn		{remove_grass 5.5}}}
{"remove_grass_6_5"	{on spawn		{remove_grass 6.5}}}
{"remove_grass_7"	{on spawn		{remove_grass 7}}}
{"remove_grass_7_5"	{on spawn		{remove_grass 7.5}}}
{"remove_grass_9"	{on spawn		{remove_grass 9}}}
{"texmod_construct"
	{on spawn
	    {if terrain_fx "snow"		{spawn "circledust_norm2_w"}
            else 		        	{spawn "circledust_norm2"}
        }
	}
}
{"tex_sample_build"
	{on "tex_refresh"
		{if game_param "biom" "snow"
			{tex_mod "winter"}
		else 
			{tex_mod ""}
		}
	}
	{on spawn
		{call "tex_refresh"}
		{if terrain_fx "snow"		{spawn "circledust_norm2_w"}
		else 		        	{spawn "circledust_norm2"}
		}
	}
}
{"tex_sample_build roof"
	{on "tex_refresh" overload
		{if game_param "biom" "snow"
			{tex_mod "winter"}
		else game_param "biom" "desert"
			{tex_mod "sand"}
		else 
			{tex_mod ""}
		}
	}
}