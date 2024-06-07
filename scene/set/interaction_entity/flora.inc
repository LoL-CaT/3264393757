{"tree"
	{inflammation_time 3}
	{on "xmas_light" {burn volume "crown" fx "xmas_light" time 60}}
	{on spawn
		{view hide "shadow_fall"}
		{call "update_texmod"}
	}
	(define "stir"
		{if not flag "bare"
			{if not flag "started"
				{ani_play "%name" 0.2 %params}
				{set "started" 1}
			}
			{if not burned
				{start_sound "push/tree_crown"}
			}
		}
	)
	{on "stir"
		{call "snow_fall"}
		("stir" name(stir) params(loop callback))
	}
	{on "stir_vehicle"
		{call "snow_fall"}
		("stir" name(stir_vehicle) params(loop callback))
	}
	{on "stir_contact"
		{if effector "human"
			{if volume "crown"
				{call "stir"}
			}
		else
			{call "stir_vehicle"}
		}
	}
	{on overlap begin
		{if not fallen
			{if not flag "overlap"
				{set "overlap" 1}
				{call "stir"}
			}
		}
	}
	{on overlap end
		{set "overlap" 0}
	}
	{on animation_end "stir"
		{if not flag "overlap"
			{if flag "started"
				{set "started" 0}
				{set "stir_contact" 0}
				{ani_stop "stir"}
			}
		}
	}
	{on animation_end "stir_vehicle"
		{if not flag "overlap"
			{if flag "started"
				{set "started" 0}
				{set "stir_contact" 0}
				{ani_stop "stir_vehicle"}
			}
		}
	}
	{on bullet_hit overload
		{if volume "crown"
			{spawn "tree_hit_small"}
		 else
			{if stuff "bullet"
				{spawn "wood_hit_bul"}
			 else stuff "shell"
				{spawn "tree_crush"}
				{call "stir"}
;				{call "start_fall"}
			else stuff "flaergun strike"
				("grenade_signal")	
			else stuff "smoke_gr"
				("grenade_smoke")
			}
		}
	}
	{on blast_hit
		{call "stir"}
		{call "leafs_fall"}
	}
	
	{on blast
		{if min_energy 1.4
			{call "start_fall"}{if rand 0.5 {call "burn"}}
		else min_energy 0.9
			{if rand 0.4 {call "fire_burn_process_med"}}
		else min_energy 0.4
			{if rand 0.2 {call "fire_burn_process_min"}}
		}
	}
	
	{on "fire_burn_process_min"
		{if not flag "fire_burn_process"
			{set "fire_burn_process" 1}{delay 10 2 {set "fire_burn_process" 0}}
			{spawn "fire_burn_start"} {delay 6 1 {if rand 0.4 {call "burn"} else {spawn "fire_burn"}}}
		}
	}
	
	{on "fire_burn_process_med"
		{if not flag "fire_burn_process"
			{set "fire_burn_process" 1}{delay 14 2 {set "fire_burn_process" 0}}
			{spawn "fire_burn_start"} {delay 4 1 {if rand 0.6 {call "burn"} else {spawn "fire_burn"}}}
		}
	}	
	
	{on contact
		{if not flag "stir_contact"
			{if not flag "started"
				{call "stir_contact"}
			else
				{set "stir_contact" 1}
				{volumes "crown" disable overlap}
				{set "overlap" 0}
				{set "started" 0}
				{ani_stop "stir"}
				{ani_stop "stir_vehicle"}
				{call "stir_contact"}
				{volumes "crown" enable overlap}
			}
		}
		{if effector "tank" or effector "car" or effector "cannon" or effector "moto"
			{call "start_fall"}
		else effector "airborne"
			{with_effector
				{if not chassis "airborne"
					{with_effector
						{call "start_fall"}
					}
				}
			}
		}
	}
	{on "snow_fall"
		{if flag "snow"
			{if not flag "snow_fall"
				{set "snow_fall" 1}
				{burn volume "crown" fx "snow_fir" time 0.5 fake even_law}
				{tex_morph "_win0" 2}
			}
		}
	}
	{on "start_fall"
	   	{start_sound "crush/medium/tree"}
		{volumes disable contact blast touch}
		{volumes "crown" enable blast}
		{call "check_structure"}
   		{pillar_fall}
		{call "regenerate"}
	}
	{on "fallen"
		{volumes "crown" enable overlap visible}
		{start_sound "crush/medium/tree"}
		{call "update_wind"}
	}
	{on "burn"
		{if not burned
			{fire volume "crown" time 12 heating 0.2}
			{burn volume "crown" fx "smoke_dead_tree" time 20 2}
			{tags add "burned"}
			{if rand 0.6
				{delay 16 2 {spawn "coal_mass"}}
			else
				{delay 8 2 {spawn "burn_grass1"}}
			}
			{if flag "bare"
				{tex_morph "_burned1" 10}
			else
				{tex_morph "_burned0" 12 "_burned1" 8}
			}
			{call "update_crown_visibility"}
		}
		{call "regenerate"}
	}
	(define "set_crown_visible"
		{volumes "crown" %0 visible}
		{update_visibility_patch}
	)
	{on "update_crown_visibility"
		{if burned
			("set_crown_visible" args disable)
		else flag "bare"
			("set_crown_visible" args disable)
		else
			("set_crown_visible" args enable)
		}
	}
	{on "update_wind"
		{if flag "bare"
			{depend_on_wind 0}
		else fallen
			{depend_on_wind 0}
		else
			{depend_on_wind 1}
		}
	}
	{on "update_texmod"
		{set "bare" 0}
		{set "snow" 0}
		{set "autlate" 0}
		{if tex_mod "bare" "bare1" "broken" "_burned1" "_burned3" "win3" "dry" "dry2" "winter"
			{set "bare" 1}
		else tex_mod "win" "win1" "win2" "winter"
			{set "snow" 1}
		else tex_mod "aut" "aut1" "aut2" "aut3" "autlate" "autlate1" "autlate2" "autlate3" "1autlate"
			{set "autlate" 1}
		}
		{if tex_mod "_crushed"
			{set "crushed" 1}
		}
		{call "update_crown_visibility"}
		{call "update_wind"}
	}
	{on "texmod_changed"
		{call "update_texmod"};
	}
	{on "texmod_bare"
		{tex_mod "bare"}
	}
	{on "leafs_fall"
		{if not burned
			{if not flag "bare" and not flag "crushed" and not tex_mod "needles"
				{if flag "snow"
					{burn volume "crown" fx "snow_fir" time 0.5 fake even_law}
				else flag "autlate"
					{burn volume "crown" fx "tree_blast_hit_autlate" time 0.5 fake even_law}
				else
					{burn volume "crown" fx "tree_blast_hit" time 0.5 fake even_law}
				}
				{call "texmod_bare"}
			}
		}
	}
	{on "regenerate"
		{if flora_regenerate
			{delay 140
				{set "crown_fall" 0}
				{burn stop_retry}
				{volumes enable contact blast}
				{volumes "crown" disable contact}
				{tex_mod reset}
				{pillar_up}
				{scale from 0.1 to 1 time 10}
				{call "update_visibility_10_sec"}
			}
		}
	}
	{on "plant"
		{scale from 0.1 to 1 time 10}
		{call "update_visibility_10_sec"}
	}
	{on "update_visibility_10_sec"
		{delay 4	{update_visibility_patch}}
		{delay 7	{update_visibility_patch}}
		{delay 10	{update_visibility_patch}}
    }
	{on "break"
		{call "start_fall"}
	}
	{on "check_structure"} ; handled in StructureBone extender
	{on "crush_structure"  ; called from StructureBone extender
		{delay 0.1
			{call "break"}
		}
	}
}

{"tree_part"
	{on "leafs_fall" overload
		{if not burned
			{if not flag "bare" and not flag "crushed" and not tex_mod "needles"
				{if flag "snow"
					{burn volume "crown" fx "snow_fir_min" time 0.4 fake even_law}
				else flag "autlate"
					{burn volume "crown" fx "tree_blast_hit_autlate_min" time 0.4 fake even_law}
				else
					{burn volume "crown" fx "tree_blast_hit_min" time 0.4 fake even_law}
				}
				{call "texmod_bare"}
			}
		}
	}
	{on "burn" overload
		{if not burned
			{burn volume "crown" fx "smoke_dead_tree_min" time 12 4}
			{tags add "burned"}
			{if rand 0.2
				{delay 10 2 {spawn "coal_mass"}}
			else
				{delay 6 2 {spawn "burn_grass1"}}
			}
			{if flag "bare"
				{tex_morph "_burned1" 16 "_burned3" 16}
			else
				{tex_morph "_burned0" 11 "_burned1" 11 "_burned3" 10}
			}
			{call "update_crown_visibility"}
		}
	}	
}

{"tree without_leaves"
	{on "leafs_fall" overload}
}
{"tree texmod_dry"
	{on "texmod_bare" overload
		{tex_mod "dry"}
	}
}

{"bush"
	{inflammation_time 2}
	{on "burn" overload
		{if not burned
			{fire volume "crown" time 10 heating 0.15}
			{burn volume "crown" fx "smoke_dead_tree_min" time 16 2}
			{tags add "burned"}
			{if flag "bare"
				{tex_morph "_burned1" 6}
			else flag "snow"
				{tex_morph "_burned1" 6}
			else
				{tex_morph "_burned0" 10 "_burned1" 2}
			}
			{delay 18
				{call "burn_end"}
			}
			{call "update_crown_visibility"}
			{call "regenerate"}
		}
	}
	{on "stir" overload
		{call "snow_fall"}
		("stir" name(stir) params(loop fake callback))
	}
	{on "bush_effects"
		{if flag "snow"
			{spawn "snow_hit_small" no_position}
		else flag "autlate"
			{spawn "tree_hit_big_out"}
		else not flag "bare"
			{spawn "tree_blast_hit_min"}
		}
	}
	{on blast overload
		{if min_energy 0.75
			{if not flag "crown_fall"
				{if not burned
					{set "crown_fall" 1}
					{if flag "bare"
						{tex_morph "_burned1" 0.3 "_burned3" 0.3}
					else flag "snow"
						{tex_morph "_win0" 2}
					else
						{tex_morph "_burned0" 0.2 "_burned1" 0.2 "_burned3" 0.2}
					}
					{if rand 0.5 {call "fire_burn_process_min"}}
					{call "bush_effects"}
					{call "regenerate"}
				}
			}
		}
	}
	{on "leafs_fall" overload}
}

{"bush_camo" 
	{on spawn
		{if game_param 	"biom" "snow"
			{tex_mod "win"}
		}
	}
	{on "burn" overload
		{if not burned
			{fire volume "crown" time 10 heating 0.05}
			{burn volume "crown" fx "smoke_dead_tree1" time 12 4}
			{tags add "burned"}
			{if flag "bare"
				{tex_morph "_burned1" 10 "_burned3" 10}
			else flag "snow"
				{tex_morph "_burned1" 10 "_burned3" 10}
			else
				{tex_morph "_burned0" 6 "_burned1" 6 "_burned3" 6}
			}
			{delay 16
				{call "burn_end"}
			}
			{call "update_crown_visibility"}
			{call "regenerate"}
		}
	}	
}

{"bush crushable"
	{on overlap begin
		{if effector "vehicle"
			{if not flag "crushed"
				{set "crushed" 1}
				{tex_morph "_crushed" 0.2}
			}
		}
	}
}

{"bush crushable_model"
	(define "cut_pieces"
		("cut_piece" args 0)	("cut_piece" args 1)
		("cut_piece" args 2)	("cut_piece" args 3)
		("cut_piece" args 4)	("cut_piece" args 5)
		("cut_piece" args 6)	("cut_piece" args 7)
		("cut_piece" args 8)	("cut_piece" args 9)
		("cut_piece" args 00)	("cut_piece" args 01)
		("cut_piece" args 02)	("cut_piece" args 03)
		("cut_piece" args 04)	("cut_piece" args 05)
		("cut_piece" args 06)	("cut_piece" args 07)
		("cut_piece" args 08)	("cut_piece" args 09)
		("cut_piece" args 10)	("cut_piece" args 11)
		("cut_piece" args 12)	("cut_piece" args 13)
		("cut_piece" args 14)	("cut_piece" args 15)
	)
	{on "cut_pieces"
		(define "cut_piece"
			{tear "building_part_wood" bone "piece%0"
				{volumes enable float}
				{impulse rnd_dir 2.1 1 cx 0.2 0.1 cy 0.2 0.1 no_position}
			}
		)
		("cut_pieces")
	}
	{on overlap begin
		{if effector "vehicle"
			{if not flag "crushed"
				{set "crushed" 1}
				{call "bush_effects"}
				{delay_ex 0.1
					{set_skeleton "_x"}	
					{use_blend_tex 1}
					{call "cut_pieces"}
				}
			}
		}
	}
}

{"wheat"
	{inflammation_time 2}
	{on "burn" overload
		{if not burned
			{fire radius 2 time 6 heating 0.15}
			{burn volume "crown" fx "smoke_dead_tree_min" time 6 1}
			{tags add "burned"}
			{if flag "bare"
				{tex_morph "_burned1" 3 "_burned3" 3}
			else
				{tex_morph "_burned0" 2 "_burned1" 2 "_burned3" 2}
			}
			{delay 6
				{call "burn_end"}
			}
			{call "update_crown_visibility"}
		}
		{call "regenerate"}
	}
}

{"delete_after_burn"
	{on "burn_end"
		{hide 2}
	}
	{on "break"
		{call "start_fall"}
		{hide 1}
	}
}

{"delete_after_burn stamp"
	{on "burn_end"
		{spawn "burn_grass1"}
	}
}

{"delete_after_blast"
	{on blast
		{if min_energy 0.8
			{hide 0.6}
		}
	}
}

{"no_wind"
	{on "update_wind" overload
		{depend_on_wind 0}
	}
}

{"invisible_crown"
	{on "update_crown_visibility" overload
		("set_crown_visible" args disable)
	}
}

{"cabbage"
	{inflammation_time 10000}
	{on bullet_hit overload
		{if rand 0.2
			{call "crush"}
		else
			{if rand 0.3
				{spawn "tree_hit_small"}
			}
		}
	}
	{on blast_hit
		{if min_energy 1
			{call "crush"}
		else
			{impulse up 2 1 dir 2 1}
		}
	}
	{on contact
		{if effector "human"
			{volumes "crown" disable contact}
			{if rand 0.3
				{call "crush"}
			}
			{delay 0.5
				{volumes "crown" enable contact}
			}
		else
			{call "crush"}
		}
	}
	{on "crush"
		{spawn "tree_hit_small"}
		{delay 0.2
			{spawn "cabbage_destroy1" no_position no_normal}
		}
		{hide 0.3}
	}
}

{"tree normal_light"
	{on spawn
		{use_local_light 0}
	}
}

{"stack_bush"
	{on spawn
		{use_local_light 0}
	}
}

{"tree foliage"
	(define "foliage"
		{add_view "foliage" "foliage" "foliage%0"}
	)
	{on spawn
		("foliage" args 00) ("foliage" args 01) ("foliage" args 02) ("foliage" args 03) ("foliage" args 04)
		("foliage" args 05) ("foliage" args 06) ("foliage" args 07) ("foliage" args 08) ("foliage" args 09)
		("foliage" args 10) ("foliage" args 11) ("foliage" args 12) ("foliage" args 13) ("foliage" args 14)
		("foliage" args 15) ("foliage" args 16) ("foliage" args 17) ("foliage" args 18) ("foliage" args 19)
		("foliage" args 20) ("foliage" args 21) ("foliage" args 22) ("foliage" args 23) ("foliage" args 24)
		("foliage" args 25) ("foliage" args 26) ("foliage" args 27) ("foliage" args 28) ("foliage" args 29)
		("foliage" args 30) ("foliage" args 31) ("foliage" args 32) ("foliage" args 33) ("foliage" args 34)
		("foliage" args 35) ("foliage" args 36) ("foliage" args 37) ("foliage" args 38) ("foliage" args 39)
		("foliage" args 40) ("foliage" args 41) ("foliage" args 42) ("foliage" args 43) ("foliage" args 44)
		("foliage" args 45) ("foliage" args 46) ("foliage" args 47) ("foliage" args 48) ("foliage" args 49)
	}
}
{"fir_s01_xmas"
	{on spawn			{add_view	"xmas_fir_ligts"		"xmas_fir"		"root"}		{view start "xmas_fir"}}
	{on "start_fall"	{view stop "xmas_fir"}}
}

{"ivy"
	{inflammation_time 2}
	{on "burn_volume" overload
		;{if not burned
			{burn time 38}
			{link_sound "flame" "fire/big"}
			{play_sound_in_channel "flame" "flame_ch" 1}
 			{delay 35 3
 				{stop_sound "flame" 0 0.5}
 			}
			{for_each_volume 4 0.7
				{call "burn_volume_next"}
			}
		;}
	}
	{on "burn_volume_next" overload
		{burn volume fx "smoke_fire_window" time 38 fake even_law}
		{fire radius 2 time 38}
		{tex_morph "burned" 8}
		
		{burn fx "smoke_dead_tree" time 38 fake even_law}
		{fire radius 2 time 38}
		{tex_morph "burned" 8}
	}
	{on blast_hit
		{delay 0.3 {delete}}
	}
}