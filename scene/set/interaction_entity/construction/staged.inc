{"watch_tower construction"
	{on "next_stage"
		{call "throw_human"}
	}
	{on "last_stage"
		{call "throw_human"}
	}
	{on "throw_human"
		{crew_throw_off up 4 1 dir 5 1 turn 0 180 forward 2 die}
	}
}

{"staged construction"
	{on spawn
		{set "stage1" 0}
		{set "last_stage" 0}
		{set "change_skeleton" 0}
		{set "first_stage" 1}
		{call "init_vars"}
	}
	{on break_armor
		{if volume "body"
			{delay 0.1
				{call "next_stage"}
			}
		}
	}
	{on contact
		{if volume "body"
			{if can_crush
				{volumes disable contact}
				{delay 0.1
					{call "last_stage"}
				}
			}
		}
		{if volume "body"
			{if effector "molotov_coctail"
;				{con "burn from contact"}
				{call "burn_body"}
			else effector "vehicle"
				{if not volume "body"
					{volume disable contact}
				}
			}
		}
	}
	{on "switch_stage"
		{tags add "crushed"}
		{if flag "change_skeleton"
			{set "change_skeleton" 0}
			{call "set_skeleton"}
			{call "update_fx"}
		}
		{call "effects"}
		{volumes "roof" disable bullet contact blast visible}
	}
	{on "set_skeleton"
		{set_skeleton "_x" nosync}
	}
	{on "last_stage"
		{set "stop_burn" 1}
		{burn stop}
		{delay 0.1
			{call "check_structure"}
		}
	}
	{on "next_stage"
		{delay 0.1
			{call "check_structure"}
		}
	}
	{on animation_end "crush1"
;		{con "crush2"}
		{if not flag "no_continue_anm"
			{ani_play "crush2" callback}
		}
		{set "no_continue_anm" 0}
		{update_shadow}
	}
	{on animation_end "crush2"
;		{con "vis_patch"}
		{update_visibility_patch}
		{update_shadow}
	}
	{on animation_end "crush3"
;		{con "vis_patch"}
		{update_visibility_patch}
		{update_shadow}
	}
	{on "break"
		{call "last_stage"}
	}
}


{"two staged construction"
	{on "init_vars"
		{set "change_skeleton" 1}
	}
	{on "next_stage"
		{if not flag "stage1"
			{set "stage1" 1}
			{call "switch_stage"}
			{set "no_continue_anm" 1}
			{ani_play "crush1" callback}
;		else not flag "stage2"
;			{set "stage2" 1}
		else
			{call "last_stage"}
		}
	}
	{on "last_stage"
		{if not flag "last_stage"
			{set "last_stage" 1}
;			{con "switch to last stage"}
			{call "disable_volumes"}
			{call "switch_stage"}
			{if not flag "stage1"
				{set "stage1" 1}
;				{con "crush1"}
				{ani_play "crush1" callback}
			else
				{ani_play "crush2" callback}
			}
		}
	}
}

{"one staged construction"
	{on "init_vars"
		{set "change_skeleton" 1}
	}
	{on "next_stage"
		{if not flag "stage1"
			{call "last_stage"}
		}
	}
	{on "last_stage"
;		{con "last_stage entering"}
		{if not flag "last_stage"
			{set "last_stage" 1}
;			{con "switch to last stage"}
			{call "disable_volumes"}
			{call "switch_stage"}
			{if not flag "stage1"
				{set "stage1" 1}
;				{con "crush1"}
				{ani_play "crush1" callback}
			else
				{ani_play "crush2" callback}
			}
		}
	}
}

{"massive construction"
	{on "init_vars"
		{set "change_skeleton" 1}
	}
	{on "next_stage"
		{if not flag "stage1"
			{set "stage1" 1}
			{call "switch_stage"}
			{ani_play "crush1"}
;		else not flag "stage2"
;			{set "stage2" 1}
		else
			{call "last_stage"}
		}
	}
	{on "last_stage"
		{if not flag "last_stage"
			{set "last_stage" 1}
;			{con "switch to last stage"}
			{call "switch_stage"}
			{if not flag "stage1"
				{set "stage1" 1}
;				{con "crush1"}
				{ani_play "crush1" callback}
			else
				{ani_play "crush2" callback}
			}
		else
			{call "crush_stage"}
		}
	}
	{on "crush_stage"
		{call "disable_volumes"}
		{call "switch_stage"}
		{ani_play "crush3" callback}
	}
}

{"no_destroyed_stamp"
	{on "destroyed_stamp" overload
	}
}
{"wood_floor_destroyed_stamp"
	{on "destroyed_stamp" overload
		{if rand 0.4
			{spawn "crash_build_04"		no_position}
		else rand 0.15
			{spawn "crash_build_05"		no_position}
		}
	}
}

{"no_disable_volumes"
	{on "disable_volumes" overload
	}
}

{"disable_area construction"
	{on "last_stage"
		{area disable}
	}
}
