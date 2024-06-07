;SDL
{pose_for_aim_and_run
	{if human_stuff holding "nothing" "small"
		{if item_in_hand "binocular"
			{anm "pose_watch_binocular"}
		}
		{anm ""}
	}
	{if human_stuff holding "flamer" "mgun"
		{anm "pose_stand_fire_mgun_up_old"}
	}
	{if human_stuff holding "rifle"
		{anm "pose_stand_fire_rifle_up"}
	}
	{if human_stuff holding "smg"
		{anm "pose_stand_fire_gun_up_old"}
	}
	{if human_stuff holding "pistol"
		{anm "pose_stand_pistol_up"}
	}
	{anm ""}
}

{move_recoil
	{if human_stuff holding "mgun"
		{anm "stand_fire_mgun_up_old"}
	}
	{if human_stuff holding "rifle"
		{anm "stand_fire_rifle_up"}
	}
	{if human_stuff holding "smg"
		{anm "stand_fire_gun_up_old"}
	}
	{if human_stuff holding "pistol"
		{anm "stand_fire_pistol"}
	}
	{anm ""}
}
{holdback_in
	{if human_stuff holding "flamer" "mgun"
		{anm "stand_holdback_mgun_up"}
	}
	{if human_stuff holding "rifle"
		{anm "stand_holdback_rifle_up"}
	}
	{if human_stuff holding "smg"
		{anm "stand_holdback_gun_up"}
	}
	{if human_stuff holding "pistol"
		{anm "stand_holdback_pistol_up"}
	}
	{anm ""}
}
{holdback_out
	{if human_stuff holding "flamer" "mgun"
		{anm "stand_holdback_mgun_up" -1}
	}
	{if human_stuff holding "rifle"
		{anm "stand_holdback_rifle_up" -1}
	}
	{if human_stuff holding "smg"
		{anm "stand_holdback_gun_up" -1}
	}
	{if human_stuff holding "pistol"
		{anm "stand_holdback_pistol_up" -1}
	}
	{anm ""}
}
{inventory_in
	{if human_stuff holding "small"
		{anm "stand_put_small"}
	}
	{if human_stuff holding "flamer" "mgun"
		{anm "stand_take_mgun_up" -1}
	}
	{if human_stuff holding "rifle"
		{anm "stand_take_rifle_up" -1}
	}
	{if human_stuff holding "smg"
		{anm "stand_take_gun_up" -1}
	}
	{anm ""}
}
{inventory_out
	{if human_stuff mounting "small"
		{anm "stand_put_small" -1}
	}
	{if human_stuff mounting "flamer" "mgun"
		{anm "stand_take_mgun_up" +1}
	}
	{if human_stuff mounting "rifle"
		{anm "stand_take_rifle_up" +1}
	}
	{if human_stuff mounting "smg"
		{anm "stand_take_gun_up" +1}
	}
	{anm ""}
}
{belt_in
	{anm "stand_put_small"}
}
{belt_out
	{anm "stand_take_small"}
}
{pistol_in
	{if human_stuff holding "pistol"
		{anm "stand_take_pistol_up_end" -1}
	}
	{anm "stand_take_pistol_up_begin"}
}
{pistol_out
	{if human_stuff mounting "pistol"
		{anm "stand_take_pistol_up_end"}
	}
	{anm "stand_take_pistol_up_begin" -1}
}
{reload
	{if human_stuff holding "rifle"
		{if item_in_hand "piatrocket"
			{anm "stand_reload_piat"}
		}
		{anm "stand_reload_rifle"}
	}
	{if human_stuff holding "smg"
		{anm "stand_reload_gun"}
	}
	{if human_stuff holding "mgun" "flamer"
		{anm "stand_reload_mgun"}
	}
	{anm "stand_reload_pistol"}
}
{unload
	{if human_stuff holding "rifle"
		{if item_in_hand "piatrocket"
			{anm "stand_reload_piat" -1}
		}
		{anm "stand_reload_rifle" -1}
	}
	{if human_stuff holding "smg"
		{anm "stand_reload_gun" -1}
	}
	{if human_stuff holding "mgun" "flamer"
		{anm "stand_reload_mgun" -1}
	}
	{anm "stand_reload_pistol" -1}
}