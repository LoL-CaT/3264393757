;SDL

; === LOOK LEFT ===
{look_left_in
	{if human_stuff holding "pistol"
		{anm "rlook_pistol"}
	}
	{if human_stuff holding "nothing" "small"
		{anm "rlook_item"}
	}
	{anm "rlook_gun"}
}
{look_left_out
	{if human_stuff holding "pistol"
		{anm "rlook_pistol" -1}
	}
	{if human_stuff holding "nothing" "small"
		{anm "rlook_item" -1}
	}
	{anm "rlook_gun" -1}
}
{look_left_throw_begin
	{anm "rlook_throw_item_begin"}
}
{look_left_throw_end
	{anm "rlook_throw_item_end"}	
}

; === LOOK RIGHT ===
{look_right_in
	{if human_stuff holding "pistol"
		{anm "llook_pistol"}
	}
	{if human_stuff holding "nothing" "small"
		{anm "llook_item"}
	}
	{anm "llook_gun"}
}
{look_right_out
	{if human_stuff holding "pistol"
		{anm "llook_pistol" -1}
	}
	{if human_stuff holding "nothing" "small"
		{anm "llook_item" -1}
	}
	{anm "llook_gun" -1}
}
{look_right_throw_begin
	{anm "llook_throw_item_begin"}
}
{look_right_throw_end
	{anm "llook_throw_item_end"}
}

; === LOOK STEALTH LEFT ===
{look_sleft_in
	{if human_stuff holding "nothing" "small" "pistol"
		{anm "rlook_stealth_item"}
	}
	{anm "rlook_stealth_gun"}
}
{look_sleft_out
	{if human_stuff holding "nothing" "small" "pistol"
		{anm "rlook_stealth_item" -1}
	}
	{anm "rlook_stealth_gun" -1}
}
{look_sleft_throw_begin
	{anm "rlook_stealth_throw_item_begin"}
}
{look_sleft_throw_end
	{anm "rlook_stealth_throw_item_end"}
}

; === LOOK STEALTH RIGHT ===
{look_sright_in
	{if human_stuff holding "nothing" "small" "pistol"
		{anm "llook_stealth_item"}
	}
	{anm "llook_stealth_gun"}
}
{look_sright_out
	{if human_stuff holding "nothing" "small" "pistol"
		{anm "llook_stealth_item" -1}
	}
	{anm "llook_stealth_gun" -1}
}
{look_sright_throw_begin
	{anm "llook_stealth_throw_item_begin"}
}
{look_sright_throw_end
	{anm "llook_stealth_throw_item_end"}
}

; === PEEP RIGHT ===
{peep_right_in
	{anm "llook_peep_gun"}	
}
{peep_right_out
	{anm "llook_peep_gun" -1}	
}

; === PEEP LEFT ===
{peep_left_in
	{anm "rlook_peep"}
}
{peep_left_out
	{anm "rlook_peep" -1}
}
