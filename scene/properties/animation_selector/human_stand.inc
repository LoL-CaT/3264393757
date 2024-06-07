;SDL

; === INVENTORY OPERATIONS ===
{stand_inventory_in
	{if human_stuff holding "mgun"
		{anm "stand_take_mgun_down" -1}
	}
	{anm "stand_take_gun_down" -1}
}
{stand_inventory_out
	{if human_stuff holding "mgun"
		{anm "stand_take_mgun_down"}
	}
	{anm "stand_take_gun_down"}
}
{stand_item_in_begin
	{if human_stuff holding "2hands"
		{anm "stand_pick_2hand_end" -1}
	}
	{anm "stand_pick_small_end" -1}
}
{stand_item_in_end
	{anm "stand_pick_small_end"}
}
{stand_item_out_begin
	{if human_stuff mounting "2hands"
		{anm "stand_pick_2hand_begin"}
	}
	{anm "stand_pick_small_begin"}
}
{stand_item_out_end
	{if human_stuff mounting "2hands"
		{anm "stand_pick_2hand_end"}
	}
	{anm "stand_pick_small_end"}
}

; === MOVE WEAPON AWAY FROM WALLS ===
{stand_holdback_in
	{if human_stuff holding "flamer" "mgun"
		{anm "stand_holdback_mgun_down"}
	}
	{if human_stuff holding "rifle"
		{anm "stand_holdback_rifle_down"}
	}
	{if human_stuff holding "smg"
		{anm "stand_holdback_gun_down"}
	}
	{if human_stuff holding "pistol"
		{anm "stand_holdback_pistol_down"}
	}
	{anm ""}
}
{stand_holdback_out
	{if human_stuff holding "flamer" "mgun"
		{anm "stand_holdback_mgun_down" -1}
	}
	{if human_stuff holding "rifle"
		{anm "stand_holdback_rifle_down" -1}
	}
	{if human_stuff holding "smg"
		{anm "stand_holdback_gun_down" -1}
	}
	{if human_stuff holding "pistol"
		{anm "stand_holdback_pistol_down" -1}
	}
	{anm ""}
}

; === THROWING ITEMS ===
{stand_throw_begin
	{if human_stuff holding "small"
		{if item_in_hand "grenade"
			{if human_throw_type "forward"
				{anm "stand_throw_grenade_1_begin"}
			}
			{if human_throw_type "side"
				{anm "stand_throw-side_grenade_begin"}
			}
			{if human_throw_type "force"
				{anm "stand_throw_grenade_2_begin"}
			}
			{anm "stand_throw_grenade_begin"}
		}
		{if item_in_hand "chicken"
			{anm "stand_throw_grenade_1_begin"}
		}
		{if item_in_hand "axe" "knife"
			; can't use random_select here - because of stand_throw_end
			{if human_fsm_counter "knife" inc 0 of 2
				{anm "stand_front_throw_knife_1_begin"}
			}
			{anm "stand_back_throw_knife_begin"}
		}
		{anm "stand_throw_small_begin"}
	}
	{anm "stand_throw_1hand_begin"}
}
{stand_throw_end
	{if human_stuff holding "small"
		{if item_in_hand "grenade"
			{if human_throw_type "forward"
				{anm "stand_throw_grenade_1_end"}
			}
			{if human_throw_type "side"
				{anm "stand_throw-side_grenade_end"}
			}
			{if human_throw_type "force"
				{anm "stand_throw_grenade_2_end"}
			}
			{anm "stand_throw_grenade_end"}
		}
		{if item_in_hand "chicken"
			{anm "stand_throw_grenade_1_end"}
		}
		{if item_in_hand "axe" "knife"
			{if human_fsm_counter "knife" get 0 of 2
				{anm "stand_front_throw_knife_1_end"}
			}
			{anm "stand_back_throw_knife_end"}
		}
		{anm "stand_throw_small_end"}
	}
	{anm "stand_throw_1hand_end"}
}

; === STEP ASIDE ===
{stand_step_aside_left_in
	{if human_stuff holding "flamer" "mgun" "rifle" "smg"
		{anm "pose_step_aside_left_gun"}
	}
	{anm "pose_step_aside_left"}
}
{stand_step_aside_left_out
	{if human_stuff holding "flamer" "mgun" "rifle" "smg"
		{anm "stand_step_aside_left_gun" -1}
	}
	{anm "stand_step_aside_left" -1}
}
{stand_step_aside_right_in
	{if human_stuff holding "flamer" "mgun" "rifle" "smg"
		{anm "pose_step_aside_right_gun"}
	}
	{anm "pose_step_aside_right"}
}
{stand_step_aside_right_out
	{if human_stuff holding "flamer" "mgun" "rifle" "smg"
		{anm "stand_step_aside_right_gun" -1}
	}
	{anm "stand_step_aside_right" -1}
}

; === GRENADE ALERT ===
{stand_to_grenade_lie
	{anm "lie_grenade_alert"}
}
{stand_to_grenade_cover
	{if human_stuff holding "flamer" "mgun" "rifle" "smg"
		{random_select
			{weight 1 "cover_grenade_alert_left_gun"}
			{weight 1 "cover_grenade_alert_right_gun"}
		}
	}
	{anm "cover_grenade_alert_left"}
}

; === HAND-TO-HAND COMBAT REACTION ===
{stand_kick
	{random_select
		{weight 1 "step_back_after_hit"}
		{weight 1 "step_back_after_hit_1"}
		{weight 1 "step_back_after_body-hit"}
		{weight 1 "step_back_after_body-hit"}
		{weight 1 "step_back_after_body-hit"}
		{weight 1 "stand_after_body-hit"}
		{weight 1 "stand_after_straight_hit"}
		{weight 1 "stand_after_hit"}
		{weight 1 "stand_after_hit_1"}
	}	
}
; animations without placement
{stand_kick_spot
	{random_select
		{weight 1 "stand_after_straight_hit"}
		{weight 1 "stand_after_body-hit"}
		{weight 1 "stand_after_hit"}
		{weight 1 "stand_after_hit_1"}
	}
}

{stand_healing_head_begin
	{anm "squat_self-treatment_head_begin"}
}
{stand_healing_head
	{anm "squat_self-treatment_head"}
}
{stand_healing_head_end
	{anm "squat_self-treatment_head_end"}
}
{stand_healing_hand_begin
	{anm "squat_self-treatment_hand_begin"}
}
{stand_healing_hand
	{anm "squat_self-treatment_hand"}
}
{stand_healing_hand_end
	{anm "squat_self-treatment_hand_end"}
}
{stand_healing_leg_begin
	{anm "squat_self-treatment_leg_begin"}
}
{stand_healing_leg
	{anm "squat_self-treatment_leg"}
}
{stand_healing_leg_end
	{anm "squat_self-treatment_hand_end"}
}