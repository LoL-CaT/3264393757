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

(define "cut_subpieces"
	("cut_subpiece" args 0)	("cut_subpiece" args 1)
	("cut_subpiece" args 2)	("cut_subpiece" args 3)
	("cut_subpiece" args 4)	("cut_subpiece" args 5)
	("cut_subpiece" args 6)	("cut_subpiece" args 7)
	("cut_subpiece" args 8)	("cut_subpiece" args 9)
	("cut_subpiece" args 00)("cut_subpiece" args 01)
	("cut_subpiece" args 02)("cut_subpiece" args 03)
	("cut_subpiece" args 04)("cut_subpiece" args 05)
	("cut_subpiece" args 06)("cut_subpiece" args 07)
	("cut_subpiece" args 08)("cut_subpiece" args 09)
	("cut_subpiece" args 10)("cut_subpiece" args 11)
	("cut_subpiece" args 12)("cut_subpiece" args 13)
	("cut_subpiece" args 14)("cut_subpiece" args 15)
	("cut_subpiece" args 16)("cut_subpiece" args 17)
)

{"parts construction windowed"
	{on bullet_hit
		{if stuff "ph_shell"
			{call "change_model"}
		}
	}
	{on contact
		{if effector "fx_sphere_ph"
			{delay 0.1
				{call "break_windows"}
				{if not flag "fire_window"
					{delay 0.1
						{set "fire_window" 1}{delay 2.6 {set "fire_window" 0}}
						{spawn "fire_window_big" "window1" x}{spawn "fire_window_big" "window2" x}{spawn "fire_window_big" "window3" x}{spawn "fire_window_big" "window4" x}{spawn "fire_window_big" "window5" x}{spawn "fire_window_big" "window6" x}{spawn "fire_window_min" "window7" x}
					}
				}
			}
		else effector "fx_sphere_ph_cas"
			{delay 0.2
				{call "break_windows"}
				{if not flag "fire_window"
					{delay 0.55
						{set "fire_window" 1}{delay 2.4 {set "fire_window" 0}}
						{spawn "fire_window_min" "window1" x}{spawn "fire_window_min" "window2" x}{spawn "fire_window_min" "window3" x}{spawn "fire_window_min" "window4" x}{spawn "fire_window_min" "window5" x}{spawn "fire_window_min" "window6" x}{spawn "fire_window_min" "window7" x}
					}
				}
			}	
		}
	}	
}

{"parts construction"
	{on spawn
		{add_view "smoke_house" "burn_fx" "attach1"}
	}
	{on break_armor
		{if volume "body" or volume "roof"
			{call "change_model"}
		}
	}
	{on blast_hit
		{if stuff "dynamite"
			{if tagged "can_crushed" ;специально для разрушения объектов(в частности мостов), которые по броне устойчивы к любым взрывам, но в миссии их нужно разрушить раньше
				{if not flag "can_crushed_bit1" and not flag "can_crushed_bit0" ;00 -> 01
					{set "can_crushed_bit0" 1}
				else not flag "can_crushed_bit1" and flag "can_crushed_bit0" ;01 -> 10
					{set "can_crushed_bit1" 1}
					{set "can_crushed_bit0" 0}
				else flag "can_crushed_bit1" and not flag "can_crushed_bit0" ;10 -> 11
					{set "can_crushed_bit0" 1}
					{call "break"}
				}
			}
		}
	}
	{on bullet_hit
		{if volume "body"
			{if stuff "shell"
				{call "break_windows"}
;				{delay_ex 0.1
;					{weakness_tex_morph}
;				}
			}
		}
	}
	{on contact
		{set "blast" 0}
		{if effector "airborne"
			{call "change_model"}
		else effector "air_part"
			{if min_speed 5
				{call "change_model"}
			}
		}
	}
	{on "enable_volumes_body"
		{volumes "body" enable bullet blast visible contact}
	}
	{on "change_model"
		{if not flag "sliced"
			;{if not tagged "crushed"
				{tags add "crushed"}
				{set "sliced" 1}
				{call "disable_volumes"}
				{call "check_structure"}
				{if min_energy 7 
					{set "blast_1" 1}
				else min_energy 3
					{set "blast_2" 1}
				}				
				{delay_ex 0.1
					{set_skeleton "_x"}	
					{call "disable_volumes"}
					{call "update_fx"}
					{set "first_stage" 1}
					{set "last_stage" 1}
					{call "effects"}
					{use_blend_tex 1}
					{call "cut_pieces"}
					{ani_play "crush"}
					;{delay 1.5
						{break_fortification "debris_001"}
						{setup_house_piece} ;update "target" volumes here
					;}
					{delay 0.1
						{call "enable_volumes_body"}
;						{volumes "body" enable bullet blast visible contact}
						{volumes "roof" enable bullet blast visible contact}
						{update_visibility_patch}
						{rebuild_boundary}
					}
				}
				{if name "trench" 
					{delay 0.2 {delete}}
				}
			;}
		}
	}
	{on "break"
		{call "change_model"}
	}
	{on "prepare_fortification"
		{set_skeleton "_x"}
		{break_fortification "debris_001"}
		{delete}
	}
	{on "smoke_for_burn"
		{if not flag "smoke_for_burn"
			{set "smoke_for_burn" 1}
			{view start "burn_fx"}
			{delay 60 30 {view stop "burn_fx"}}
		}
	}
	{on "burn_end"
		{bone hide "roof_hide"}
		{tex_morph "burned" 3}
		{if rand 0.5
			{call "smoke_for_burn"}
		}
	}
	{on "ground_lost"
		{if effector "bridge"
			{call "break"}
		}
	}
}

{"enable_volumes_body_off"
	{on "enable_volumes_body" overload}
}

{"wood parts construction fortification"
	{on spawn
		{add_view "wood_install_norm" "fortification" "root"}
		{view start "fortification"}
		{start_sound "fortification/install/window"}
	}
}

{"construction physical"
	{on blast overload
		{if min_energy 1.5
			{physics_work 1}{impulse up 5 1 dir 8 2 no_position}
		else min_energy 1
			{physics_work 1}{impulse up 5 1 dir 7 1 no_position}
		else min_energy 0.75
			{physics_work 1}{impulse up 4 1 dir 6 1 no_position}
		else min_energy 0.25
			{physics_work 1}{impulse up 3 0.5 dir 5 0.75 no_position}
		else min_energy 0.05
			{physics_work 1}{impulse up 2 0.5 dir 3 0.5 no_position}
		}
	}
	{on break_armor overload
		{if volume "body" or volume "roof"
			{if min_energy 3
				{call "change_model"}
			else min_energy 2
				{if rand 0.5
					{delay 0.1 {call "change_model"}}
				else
					{delay 0.8 0.4 {call "change_model"}}
				}
			else
			}		
		}
	}
}

{"concrete parts construction fortification"
	{on spawn
		{add_view "circledust_norm3" "fortification" "root"}
		{view start "fortification"}
		{start_sound "fortification/install/sandbag"}
	}
}

{"break_on_burn parts construction"
	{on "burn_end"
		{call "break"}
	}
}

{"small parts construction"
	{on contact
		{set "blast" 0}
		{if can_crush
			{call "change_model"}
		}
	}
}

{"entanglement parts construction"
	{on contact
		{set "blast" 0}
		{if can_crush
			{call "change_model"}
		}
	}
}


{"concrete small parts construction"
	{on "cut_pieces"
		{volumes disable contact}
		(define "cut_piece"
			{if min_energy 5
				{tear "piece_small_concrete" bone "piece%0"
					{volumes enable contact}
					{if rand 0.75 
						{add_view "piece_dust_small" "smoke" "root"}
						{view start "smoke"}
						{delay 3 0.5 {view pause "smoke"}}
					}
					{if rand 0.75 {spawn "spheredust_norm" "piece%0"}}
					{impulse up 5 1 dir 2.5 8 no_position}
				}
			else min_energy 2
				{tear "piece_small_concrete" bone "piece%0"
					{volumes enable contact}
					{if rand 0.5 
						{add_view "piece_dust_small" "smoke" "root"}
						{view start "smoke"}
						{delay 2 0.5 {view pause "smoke"}}
					}
					{if rand 0.5 {spawn "spheredust_norm" "piece%0"}}
					{impulse up 3 0.9 dir 2.5 6 no_position}
				}
			else
				{tear "piece_small_concrete" bone "piece%0"
					{volumes enable contact}
					{if rand 0.25 {spawn "spheredust_norm" "piece%0"}}
					{impulse up 1 0.7 dir 2.5 0.3 no_position}
				}	
			}
		)
		("cut_pieces")
	}
}


{"concrete small parts construction big_impulse"
	{on "cut_pieces" overload
		{if flag "blast"
			{volumes disable contact}
			(define "cut_piece"
				{tear "piece_small_concrete" bone "piece%0"
					{volumes enable contact}
					{impulse up 5 2 dir 3.5 2.5 rnd_dir 5 no_position}
				}
			)
			("cut_pieces")
		else
			{inherited}
		}
	}
}


{"big steel parts construction"
	{on "cut_pieces_base"
		(define "cut_piece"
			{tear "building_part_steel" bone "piece%0"
				{volumes enable contact}
				{impulse up 2.5 1.7 dir 3.5 1.3 no_position}
			}
		)
		("cut_pieces")
	}
	{on "cut_pieces"
		{call "cut_pieces_base"}
		(define "cut_subpiece"
			{tear "piece_medium_steel_construction" bone "sub_piece%0"
				{volumes enable contact}
				{spawn "spheredust_norm" "sub_piece%0"}
				{impulse up 2.5 1.7 dir 3.5 1.3 no_position}
			}
		)
		("cut_subpieces")
	}
}
{"big steel parts construction brittle"
	{on contact overload
		{set "blast" 0}
		{if can_crush
			{call "change_model"}
		}
	}
	{on "cut_pieces_base" overload
		(define "cut_piece"
			{tear "building_part_steel_brittle" bone "piece%0"
				{volumes enable contact}
				{impulse up 2.5 1.7 dir 3.5 1.3 no_position}
			}
		)
		("cut_pieces")
	}
}

{"small steel parts construction"
	{on "cut_pieces"
		{volumes disable contact}
		(define "cut_piece"
			{tear "piece_medium_steel_construction" bone "piece%0"
				{volumes enable contact}
				{if flag "blast"
					{impulse up 4 2 dir 2.5 1.3 no_position}
				else
					{impulse up 1 0.7 dir -4.5 0.3 no_position}
				}
			}
		)
		("cut_pieces")
	}
}

{"wood parts construction"
	{on bullet_hit
		{if volume "body"
			{if stuff "shell"
				{set "blast" 0}
				{call "change_model"}
			}
		}
	}
	{on contact
		{set "velocity_high" 0} {set "velocity_medium" 0}
		{if effector_velocity 16
			{set "velocity_high" 1}
		else effector_velocity 8
			{set "velocity_medium" 1}
		}
	}
	{on "cut_pieces"
		(define "cut_piece"
			{if flag "velocity_high"
				{tear "building_part_wood" bone "piece%0"
					{volumes enable float contact}
					{physics_work 1}
					{impulse up 3.4 0.7 dir 10 1 no_position}
				}
			else flag "velocity_medium"
				{tear "building_part_wood" bone "piece%0"
					{volumes enable float contact}
					{physics_work 1}
					{impulse up 2.2 0.7 dir 7 1 no_position}
				}
			else
				{tear "building_part_wood" bone "piece%0"
					{volumes enable float contact}
					{physics_work 1}
					{impulse up 1 0.7 dir 2.5 0.3 no_position}
				}
			}
		)
		("cut_pieces")
	}
}

{"small wood parts construction"
	{on "cut_pieces" overload
		{volumes disable contact blast}
		(define "cut_piece"
			{if flag "velocity_high"
				{tear "piece_small_wood" bone "piece%0"
					{volumes enable float contact}
					{physics_work 1}
					{impulse up 3.4 0.7 dir 10 1 no_position}
				}
			else flag "velocity_medium"
				{tear "piece_small_wood" bone "piece%0"
					{volumes enable float contact}
					{physics_work 1}
					{impulse up 2.2 0.7 dir 7 1 no_position}
				}
			else
				{tear "piece_small_wood" bone "piece%0"
					{volumes enable float contact}
					{physics_work 1}
					{impulse up 1 0.7 dir 4 0.5 no_position}
				}
			}
		)
		("cut_pieces")
		(define "cut_subpiece"
			{tear "piece_small_wood" bone "sub_piece%0"
				{volumes enable float}
				{if rand 0.25 {spawn "spheredust_norm" "sub_piece%0"}}
				{impulse dir 0.1 no_position}
			}
		)
		("cut_subpieces")
	}
}

{"small wood parts construction big_impulse"
	{on "cut_pieces" overload
		{if flag "blast"
			{volumes disable contact blast}
			(define "cut_piece"
				{tear "piece_small_wood" bone "piece%0"
					{volumes enable float}
					{physics_work 1}
					{impulse up 5 2 dir 3.5 2.5 rnd_dir 5 no_position}
				}
			)
			("cut_pieces")
		else
			{inherited}
		}
	}
}

{"big wood parts construction"
	{on "cut_pieces" overload
		(define "cut_piece"
			{if flag "velocity_high"
				{tear "building_part_wood" bone "piece%0"
					{volumes enable contact}
					{physics_work 1}
					{impulse up 3.5 0.7 dir 6.5 1.3 no_position}
				}
			else flag "velocity_medium"
				{tear "building_part_wood" bone "piece%0"
					{volumes enable contact}
					{physics_work 1}
					{impulse up 3 0.7 dir 5 1.3 no_position}
				}
			else
				{tear "building_part_wood" bone "piece%0"
					{volumes enable contact}
					{physics_work 1}
					{impulse up 2.5 1.7 dir 3.5 1.3 no_position}
				}
			}
		)
		("cut_pieces")
		(define "cut_subpiece"
			{if flag "velocity_high"
				{tear "piece_big_wood" bone "sub_piece%0"
					{volumes enable contact}
					{spawn "spheredust_norm" "sub_piece%0"}
					{physics_work 1}
					{impulse up 3.5 0.7 dir 6.5 1.3 no_position}
				}
			else flag "velocity_medium"
				{tear "piece_big_wood" bone "sub_piece%0"
					{volumes enable contact}
					{spawn "spheredust_norm" "sub_piece%0"}
					{physics_work 1}
					{impulse up 3 0.7 dir 5 1.3 no_position}
				}
			else
				{tear "piece_big_wood" bone "sub_piece%0"
					{volumes enable contact}
					{spawn "spheredust_norm" "sub_piece%0"}
					{physics_work 1}
					{impulse up 2.5 1.7 dir 3.5 1.3 no_position}
				}
			}
		)
		("cut_subpieces")
	}
}


{"small sand parts construction"
	{on "cut_pieces" overload
		{volumes disable contact blast}
		(define "cut_piece"
			{tear "piece_medium_sand" bone "piece%0"
				{impulse up 1 0.7 dir 2.5 0.3 no_position}
			}
		)
		("cut_pieces")
	}
}

{"piece_large_concrete"
	{on spawn
		{delay 6 1
			{set "en_crush" 1}
		}	
		{delay 10 3 {hide 2}}	
	}	
	{on ground_hit
		{if flag "en_crush"
			{spawn "piece_crush"}
			{delete}
		}
	}
	{on contact
		{if flag "en_crush"
			{if can_crush
				{spawn "piece_crush"}
				{delete}
			}
		}
	}
}

{"building_part"
;	{friction 2}
;	{restitution 0.3}
	{on spawn
		{volumes enable blast}
		{delay 6 1
			{set "en_crush" 1}
		}	
		{delay 18 5 {hide 4}}	
	}
	{on "sliced"
		{if not flag "sliced"
			{spawn "spheredust_big_short"}
			{call "cut_subpieces"}
		}
	}
	{on ground_hit 
		{if flag "en_crush"
			{call "sliced"}
		}
	}
	
	{on contact 
		{if flag "en_crush"
			{call "sliced"}
		}
	}
}


{"building_part concrete"
	{on ground_hit overload
		{if flag "en_crush"
			{if flag "crush"
				{spawn "piece_crush_big"}
				{delete}
			}
		}
	}
	{on contact overload
		{if flag "en_crush"
			{if can_crush
				{spawn "piece_crush_big"}
				{delete}
			}
		}
	}
	{on "cut_subpieces"
		{set "sliced" 1}
		(define "cut_subpiece"
			{tear "piece_large_concrete" bone "sub_piece%0" id "building_part_concrete_subpiece"
				{volumes enable contact}
				{spawn "spheredust_norm" "sub_piece%0"}
				{impulse up 1 0.7 dir 2.5 0.3 no_position}
				{add_view "smoke_black" "smoke" "root"}
				{view start "smoke"}
				{delay_effect 1 0.5 "stop"}
			}
		)
		("cut_subpieces")
	}
	{on "slice_load"
		{if name "building_part_concrete_subpiece"
			{with_effector
				{add_view "smoke_black" "smoke" "root"}
			}
		}
	}
}

{"building_part wood"
	{on "cut_subpieces"
		{set "sliced" 1}
		(define "cut_subpiece"
			{tear "piece_big_wood" bone "sub_piece%0" id "building_part_wood_subpiece"
				{volumes enable contact}
				{spawn "spheredust_norm" "sub_piece%0"}
				{impulse up 1 0.7 dir 2.5 0.3 no_position}
				{add_view "smoke_black" "smoke" "root"}
				{view start "smoke"}
				{delay_effect 5 3 "stop"}
			}
		)
		("cut_subpieces")	
	}
	{on contact overload
		{if flag "en_crush"
			{if can_crush
				{spawn "wood_hit_small"}
				{delete}
			}
		}
	}
	{on "slice_load"
		{if name "building_part_wood_subpiece"
			{with_effector
				{add_view "smoke_black" "smoke" "root"}
			}
		}
	}
}

{"building_part steel"
	{on "cut_subpieces"
		{set "sliced" 1}
		(define "cut_subpiece"
			{tear "piece_medium_steel_construction" bone "sub_piece%0"  id "building_part_steel_subpiece"
				{volumes enable contact}
				{spawn "spheredust_norm" "sub_piece%0"}
				{impulse up 2.5 1.7 dir 3.5 1.3 no_position}
			}
		)
		("cut_subpieces")
	}
	{on "slice_load"
		{if name "building_part_steel_subpiece"
			{with_effector
				{add_view "smoke_black" "smoke" "root"}
			}
		}
	}
}

{"building_part steel brittle"
	{on "cut_subpieces" overload
		{set "sliced" 1}
		(define "cut_subpiece"
			{tear "piece_medium_steel_construction" bone "sub_piece%0"  id "building_part_steel_brittle_subpiece"
				{volumes enable contact}
				{spawn "spheredust_norm" "sub_piece%0"}
				{impulse up 2.5 1.7 dir 3.5 1.3 no_position}
			}
		)
		("cut_subpieces")
	}

	{on ground_hit overload
		{if not flag "en_crush"
			{set "en_crush" 1}
		else
			{call "sliced"}
		}
	}
	{on contact overload
		{if effector "construction"
			{call "sliced"}
		else
			{inherited}
		}
	}
}

{"cornered parts construction"
	{on bullet_hit
		{if not under_water
			{if stuff "shell small"
			 	{spawn	"stone_hit_br_small" inv_normal}
			else stuff "big shell fg" or stuff "big shell fr"
			 	{spawn	"stone_hit_br_big" inv_normal}
			else stuff "shell"
			 	{spawn	"stone_hit_br" inv_normal}
			}
		}
	}
	{on blast_hit
		{if min_energy 1
			{set "en_blast" 1}
		}
	}
	{on "cut_pieces"
		(define "cut_piece"
			{if min_energy 7
				{tear "building_part_concrete" bone "piece%0"
					{volumes enable contact}
					{if rand 0.75 
						{add_view "piece_dust_small" "smoke" "root"}
						{view start "smoke"}
						{delay 4 1 {view pause "smoke"}}
					}
					{if rand 0.75 {spawn "spheredust_norm" "piece%0"}}
					{impulse up 7 2 dir -5 8 no_position}			
				}
			else min_energy 3
				{tear "building_part_concrete" bone "piece%0"
					{volumes enable contact}
					{if rand 0.5 
						{add_view "piece_dust_small" "smoke" "root"}
						{view start "smoke"}
						{delay 3 1 {view pause "smoke"}}
					}
					{if rand 0.5 {spawn "spheredust_norm" "piece%0"}}
					{impulse up 4 1 dir -5 7 no_position}			
				}			
			else
				{tear "building_part_concrete" bone "piece%0"
					{volumes enable contact}				
					{if rand 0.25 {spawn "spheredust_norm" "piece%0"}}
					{impulse up 1 0.7 dir -4 1.3 no_position}			
				}	
			}
		)
		("cut_pieces")
		(define "cut_subpiece"
			{if min_energy 5
				{tear "piece_large_concrete" bone "sub_piece%0" id "cornered_parts_construction_piece"
					{volumes enable contact}
					{if rand 0.7 
						{add_view "piece_dust_small" "smoke" "root"}
						{view start "smoke"}
						{delay 3 1 {view pause "smoke"}}
					}
					{if rand 0.7 {spawn "spheredust_norm" "sub_piece%0"}}
					{impulse up 6 1 dir 3 7 no_position}
				}
			else min_energy 2
				{tear "piece_large_concrete" bone "sub_piece%0" id "cornered_parts_construction_piece"
					{volumes enable contact}
					{if rand 0.45 
						{add_view "piece_dust_small" "smoke" "root"}
						{view start "smoke"}
						{delay 2 1 {view pause "smoke"}}
					}
					{if rand 0.45 {spawn "spheredust_norm" "sub_piece%0"}}
					{impulse up 3 0.7 dir 3 5 no_position}
				}			
			else
				{tear "piece_large_concrete" bone "sub_piece%0" id "cornered_parts_construction_piece"
					{volumes enable contact}				
					{if rand 0.25 {spawn "spheredust_norm" "sub_piece%0"}}
					{impulse up 1 0.7 dir 2.5 0.3 no_position}
				}			
			}
		)
		("cut_subpieces")
	}
	{on "slice_load"
		{if name "cornered_parts_construction_piece"
			{with_effector
				{add_view "smoke_black" "smoke" "root"}
			}
		}
	}
	{on "destroyed_stamp" overload
		{if rand 0.25
			{spawn "crash_brick3"		no_position}
		else rand 0.33
			{spawn "stonechip1"		no_position}
		else rand 0.5
			{spawn "crash_stone2"		no_position}
		else
			{spawn "crash_brick3a"		no_position}
		}
	}
}

{"concrete parts construction small"
	{on "effects"
		{start_sound "crush/medium/concrete"}
	}
}

{"concrete parts construction wall"
	{on "effects"
		{start_sound "crush/big/concrete"}
	}
}

{"wall parts construction"
	{on contact
		{if can_crush
			{set "blast" 0}
			{call "change_model"}
		}
	}
}

{"concrete dot parts construction"
}

{"dot_wood_roof"
	{on bullet_hit overload}
}

{"blindage_wood_roof"
	{on bullet_hit overload}
}
{"unbreakable parts construction"
	{on break_armor overload}
	{on "destroyed_stamp" overload}
}

{"ice parts construction"
;	{on overlap begin
;		{if effector "vehicle"		{start_sound "crush/medium/ice"}}
;		{if not tagged "strong"
;			{set "blast" 0}
;			{if effector "tank"
;				{call "delayed_change_model"}
;			else effector "car"
;				{call "delayed_change_model"}
;			}
;		}
;	}
	{on "delayed_change_model"
		{if not flag "delayed_change_model"
			{set "delayed_change_model" 1}
			{delay 2
				{call "change_model"}
			}
		}
	}
	{on blast_hit
		{if min_energy 10
			{call "change_model"}
		else min_energy 7
			{if rand 0.5
				{call "change_model"}
			}
		}	
	}	
	{on contact overload}
	{on "cut_pieces"
		{volumes "body" disable overlap blast}
		{spawn "iceblock_hit01"}
		(define "cut_piece"
			{tear "piece_medium_ice" bone "piece%0"
				{volumes enable contact}
				{impulse up 1 0.7 dir 2.5 0.3 no_position}
			}
		)
		("cut_pieces")
	}
}
