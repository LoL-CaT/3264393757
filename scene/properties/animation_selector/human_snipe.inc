;SDL
{snipe_holdback_in
	{if human_stuff holding "flamer" "mgun"
		{anm "stand_holdback_mgun_up"}
	}
	{if human_stuff holding "rifle" "smg"
		{anm "stand_holdback_gun_up"}
	}
	{if human_stuff holding "pistol"
		{anm "stand_holdback_pistol_up"}
	}
	{anm ""}
}

{snipe_holdback_out
	{if human_stuff holding "flamer" "mgun"
		{anm "stand_holdback_mgun_up" -1}
	}
	{if human_stuff holding "rifle" "smg"
		{anm "stand_holdback_gun_up" -1}
	}
	{if human_stuff holding "pistol"
		{anm "stand_holdback_pistol_up" -1}
	}
	{anm ""}
}
{snipe_to_squat
	{if human_stuff holding "nothing" "small"
		{anm "cover_from_stand_empty"}
	}
	{anm "cover_from_snipe_gun"}
}
{snipe_from_squat
	{if human_stuff holding "nothing" "small"
		{anm "cover_from_stand_empty" -1}
	}
	{anm "cover_from_snipe_gun" -1}
}