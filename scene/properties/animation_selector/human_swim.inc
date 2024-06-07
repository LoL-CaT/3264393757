;SDL
{swim_in_from_stand
	{if human_stuff holding "nothing" "small" "pistol"
		{anm "swim_from_stand_empty"}
	}
	{anm "swim_from_stand_gun"}
}
{swim_out_to_stand
	{anm "squat_from_stand_empty" -1}
}
{swim_out_to_squat
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
{swim
	{if human_stuff holding "nothing" "small" "pistol"
		{if movement_mode "fast"
			{anm "swim_fast_empty"}
		}
		{anm "swim_empty"}
	}
	{anm "swim_gun"}
}
{swim_idle
	{if human_stuff holding "nothing" "small" "pistol"
		{anm "swim_on_the_spot_empty"}
	}
	{anm "swim_gun"}
}