;SDL
{lie_holdback_in
	{if human_stuff holding "pistol" 
		{anm "lie_holdback_pistol"}
	}
	{anm  "lie_holdback_gun"}
}
{lie_holdback_out
	{if human_stuff holding "pistol"
		{anm "lie_holdback_pistol" -1}
	}
	{anm  "lie_holdback_gun" -1}
}
{crawl_from_walk
	{if human_stuff holding "flamer" "rifle"
		{anm "run_to_lie_rifle"}
	}
	{if human_stuff holding "bazooka"
		{anm "run_to_lie_bazooka"}
	}
	{if human_stuff holding "pistol"
		{anm "run_to_lie_pistol"}
	}
	{if human_stuff holding "smg"
		{anm "run_to_lie_gun"}
	}
	{if human_stuff holding "mgun"
		{anm "run_to_lie_mgun"}
	}
	{anm "run_to_lie_empty"}
}
{lie_from_stand
	{anm "lie_from_stand"}
}
{stand_from_lie
	{anm "lie_from_stand" -1}
}
{crawl
	{if human_stuff holding "rifle" "smg" "mgun" "flamer" "bazooka"
		{anm "crawl_gun"}
	}
	{anm "crawl"}
}
{lie_rotate
	{if human_stuff holding "rifle" "smg" "mgun" "flamer" "bazooka"
		{anm "crawl_gun" 0.75}
	}
	{anm "crawl" 0.75}
}
{lie_rotate_l45
	{if human_stuff holding "rifle" "smg" "mgun" "flamer" "bazooka"
		{anm "lie_rotate_l45_gun"}
	}
	{anm "lie_rotate_l45"}
}
{lie_rotate_r45
	{if human_stuff holding "rifle" "smg" "mgun" "flamer" "bazooka"
		{anm "lie_rotate_r45_gun"}
	}
	{anm "lie_rotate_r45"}
}
{lie_inventory_in
	{if human_stuff holding "rifle"
		{anm "lie_take_rifle" -1}
	}
	{if human_stuff holding "smg" "flamer" "bazooka"
		{anm "lie_take_gun" -1}
	}
	{if human_stuff holding "mgun"
		{anm "lie_take_mgun" -1}
	}
	{anm "lie_put_small"}
}
{lie_reload
	{if human_stuff holding "rifle"
		{if item_in_hand "piatrocket"
			{anm "lie_reload_piat"}
		}
		{anm "lie_reload_rifle"}
	}
	{if human_stuff holding "smg" "flamer"
		{anm "lie_reload_gun"}
	}
	{if human_stuff holding "mgun"
		{anm "lie_reload_mgun"}
	}
	{if human_stuff holding "bazooka"
		{anm "lie_reload_bazooka"}
	}
	{anm "lie_reload_pistol"}
}
{lie_unload
	{if human_stuff holding "rifle"
		{if item_in_hand "piatrocket"
			{anm "lie_reload_piat" -1}
		}
		{anm "lie_reload_rifle" -1}
	}
	{if human_stuff holding "smg" "flamer"
		{anm "lie_reload_gun" -1}
	}
	{if human_stuff holding "mgun"
		{anm "lie_reload_mgun" -1}
	}
	{if human_stuff holding "bazooka"
		{anm "lie_reload_bazooka" -1}
	}
	{anm "lie_reload_pistol" -1}
}
{lie_fire
	{anm ""}
}
{lie_belt_in
	{if human_stuff holding "pistol"
		{anm "lie_take_pistol" -1}
	}
	{anm "lie_put_small"}
}
{lie_belt_out
	{if human_stuff mounting "pistol"
		{anm "lie_take_pistol"}
	}
	{anm "lie_take_small"}
}
{lie_inventory_out
	{if human_stuff mounting "rifle"
		{anm "lie_take_rifle"}
	}
	{if human_stuff mounting "smg" "flamer"
		{anm "lie_take_gun"}
	}
	{if human_stuff mounting "mgun" "bazooka"
		{anm "lie_take_mgun"}
	}
	{if human_stuff mounting "pistol"
		{anm "lie_take_pistol"}
	}
	{anm "lie_take_small"}
}
{lie_throw_begin
	{if human_throw_type "force" "mega"
		{anm "lie_throw_grenade_1_begin"}
	}
	{anm "lie_throw_grenade_begin"}
}
{lie_throw_end
	{if human_throw_type "force" "mega"
		{anm "lie_throw_grenade_1_end"}
	}
	{anm "lie_throw_grenade_end"}
}
{lie_kick
	{anm ""} ; no animations yet
}


{lie_healing_head_begin
	{anm "lie_self-treatment_head_begin"}
}
{lie_healing_head
	{anm "lie_self-treatment_head"}
}
{lie_healing_head_end
	{anm "lie_self-treatment_head_end"}
}

{lie_healing_hand_begin
	{anm "lie_self-treatment_hand_begin"}
}
{lie_healing_hand
	{anm "lie_self-treatment_hand"}
}
{lie_healing_hand_end
	{anm "lie_self-treatment_hand_end"}
}

{lie_healing_leg_begin
	{anm "lie_self-treatment_leg_begin"}
}
{lie_healing_leg
	{anm "lie_self-treatment_leg"}
}
{lie_healing_leg_end
	{anm "lie_self-treatment_leg_end"}
}