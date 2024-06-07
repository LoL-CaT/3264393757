;SDL
{squat_holdback_in
	{if human_stuff holding "flamer" "mgun" "smg"
		{anm "squat_holdback_gun"}
	}
	{if human_stuff holding "rifle"
		{anm "squat_holdback_rifle"}
	}
	{if human_stuff holding "pistol"
		{anm "squat_holdback_pistol"}
	}
	{anm ""}
}
{squat_holdback_out
	{if human_stuff holding "flamer" "mgun" "smg"
		{anm "squat_holdback_gun" -1}
	}
	{if human_stuff holding "rifle"
		{anm "squat_holdback_rifle" -1}
	}
	{if human_stuff holding "pistol"
		{anm "squat_holdback_pistol" -1}
	}
	{anm ""}
}
{squat_reload
	{if human_stuff holding "pistol"
		{anm "squat_reload_pistol"}
	}
	{if human_stuff holding "flamer" "smg"
		{anm "squat_reload_gun"}
	}
	{if human_stuff holding "mgun"
		{anm "squat_reload_mgun"}
	}
	{if human_stuff holding "rifle"
		{if item_in_hand "piatrocket"
			{anm "squat_reload_piat"}
		}
		{anm "squat_reload_rifle"}
	}
	{if human_stuff holding "bazooka"
		{anm "squat_reload_bazooka"}
	}
	{anm ""}
}
{squat_unload
	{if human_stuff holding "pistol"
		{anm "squat_reload_pistol" -1}
	}
	{if human_stuff holding "flamer" "smg"
		{anm "squat_reload_gun" -1}
	}
	{if human_stuff holding "mgun"
		{anm "squat_reload_mgun" -1}
	}
	{if human_stuff holding "rifle"
		{if item_in_hand "piatrocket"
			{anm "squat_reload_piat" -1}
		}
		{anm "squat_reload_rifle" -1}
	}
	{if human_stuff holding "bazooka"
		{anm "squat_reload_bazooka" -1}
	}
	{anm ""}
}
{squat_inventory_in
	{if human_stuff holding "bazooka"
		{anm "squat_take_bazooka" -1}
	}
	{anm "squat_take_gun" -1}
}
{squat_inventory_out
	{if human_stuff mounting "bazooka"
		{anm "squat_take_bazooka"}
	}
	{anm "squat_take_gun"}
}
{squat_belt_in
	{if human_stuff holding "pistol"
		{anm "squat_take_pistol" -1}
	}
	{anm "squat_put_small"}
}
{squat_belt_out
	{if human_stuff mounting "pistol"
		{anm "squat_take_pistol"}
	}
	{anm "squat_take_small"}
}
{squat_throw_begin
	{if human_stuff holding "small"
		{if item_in_hand "grenade"
			{if human_throw_type "force" "mega"
				{anm "squat_throw_grenade_1_begin"}
			}
			{anm "squat_throw_grenade_begin"}
		}
		{if item_in_hand "chicken"
			{anm "squat_throw_grenade_begin"}
		}
		{if item_in_hand "axe" "knife"
			{anm "squat_throw_knife_begin"}
		}
		{anm "squat_throw_small_begin"}
	}
	{anm "squat_throw_small_begin"}
}
{squat_throw_end
	{if human_stuff holding "small"
		{if item_in_hand "grenade"
			{if human_throw_type "force" "mega"
				{anm "squat_throw_grenade_1_end"}
			}
			{anm "squat_throw_grenade_end"}
		}
		{if item_in_hand "chicken"
			{anm "squat_throw_grenade_end"}
		}
		{if item_in_hand "axe" "knife"
			{anm "squat_throw_knife_end"}
		}
		{anm "squat_throw_small_end"}
	}
	{anm "squat_throw_small_end"}
}
{squat_from_stand
	{if human_stuff holding "nothing" "small"
		{anm "squat_from_stand_empty"}
	}
	{if human_stuff holding "flamer" "smg"
		{anm "squat_from_stand_gun"}
	}
	{if human_stuff holding "mgun"
		{anm "squat_from_stand_mgun"}
	}
	{if human_stuff holding "rifle"
		{anm "squat_from_stand_rifle"}
	}
	{if human_stuff holding "pistol"
		{anm "squat_from_stand_pistol"}
	}
	{if human_stuff holding "bazooka"
		{anm "squat_from_stand_bazooka"}
	}
	{anm ""}
}
{squat_to_stand
	{if human_stuff holding "nothing" "small"
		{anm "squat_from_stand_empty" -1}
	}
	{if human_stuff holding "flamer" "smg"
		{anm "squat_from_stand_gun" -1}
	}
	{if human_stuff holding "mgun"
		{anm "squat_from_stand_mgun" -1}
	}
	{if human_stuff holding "rifle"
		{anm "squat_from_stand_rifle" -1}
	}
	{if human_stuff holding "pistol"
		{anm "squat_from_stand_pistol" -1}
	}
	{if human_stuff holding "bazooka"
		{anm "squat_from_stand_bazooka" -1}
	}
	{anm ""}
}
{squat_to_lie
	{if human_stuff holding "nothing" "small"
		{anm "lie_from_squat_empty"}
	}
	{if human_stuff holding "flamer" "smg"
		{anm "lie_from_squat_gun"}
	}
	{if human_stuff holding "mgun"
		{anm "lie_from_squat_mgun"}
	}
	{if human_stuff holding "rifle"
		{anm "lie_from_squat_rifle"}
	}
	{if human_stuff holding "pistol"
		{anm "lie_from_squat_pistol"}
	}
	{if human_stuff holding "bazooka"
		{anm "lie_from_squat_bazooka"}
	}
	{anm ""}
}
{squat_from_lie
	{if human_stuff holding "nothing" "small"
		{anm "lie_from_squat_empty" -1}
	}
	{if human_stuff holding "flamer" "smg"
		{anm "lie_from_squat_gun" -1}
	}
	{if human_stuff holding "mgun"
		{anm "lie_from_squat_mgun" -1}
	}
	{if human_stuff holding "rifle"
		{anm "lie_from_squat_rifle" -1}
	}
	{if human_stuff holding "pistol"
		{anm "lie_from_squat_pistol" -1}
	}
	{if human_stuff holding "bazooka"
		{anm "lie_from_squat_bazooka" -1}
	}
	{anm ""}
}

{squat_healing_head_begin
	{anm "squat_self-treatment_head_begin"}
}
{squat_healing_head
	{anm "squat_self-treatment_head"}
}
{squat_healing_head_end
	{anm "squat_self-treatment_head_end"}
}
{squat_healing_hand_begin
	{anm "squat_self-treatment_hand_begin"}
}
{squat_healing_hand
	{anm "squat_self-treatment_hand"}
}
{squat_healing_hand_end
	{anm "squat_self-treatment_hand_end"}
}
{squat_healing_leg_begin
	{anm "squat_self-treatment_leg_begin"}
}
{squat_healing_leg
	{anm "squat_self-treatment_leg"}
}
{squat_healing_leg_end
	{anm "squat_self-treatment_hand_end"}
}

{squat_hide_in
	{anm "squat_hide"}
}
{squat_hide_out
	{anm "squat_hide" -1}
}
{squat_repair
	{random_select
		{weight 1 "squat_repair_1"}
		{weight 1 "squat_repair_2"}
	}
}
