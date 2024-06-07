;SDL
{stand_dying
	{if terrain_pp "swamp"
		{anm "stand_die_drowin"}
	}

	{if human_kill_flags "cover_in_trench"
		; it's possible to do front / back / on spot checks here
		{random_select
			{weight 1 "stand_die_trench_1"}
			{weight 1 "stand_die_trench_2"}
			{weight 1 "stand_die_trench_3"}
		}
	}

	{if human_kill_flags "front"
		{if human_kill_flags "piercing"
			{if human_kill_flags "go"
				{random_select
					{weight 1 "stand_die_back_3"}
					{weight 1 "stand_die_front_2"}
					{weight 1 "stand_die_front_3"}
					{weight 1 "stand_die_front_4"}
					{weight 1 "stand_scenic-die_front_1"}
					{weight 1 "stand_scenic-die_front_2"}
					{weight 1 "stand_scenic-die_back_1"}
					{weight 1 "stand_scenic-die_back_2"}
				}
			}
			{if human_kill_flags "run"
				{random_select
					{weight 1 "stand_die_front_2"}
					{weight 1 "stand_die_front_3"}
					{weight 1 "stand_die_front_4"}
				}
			}
			{random_select
				{weight 1 "stand_die_back_1"}
				{weight 1 "stand_die_back_2"}
				{weight 1 "stand_die_back_3"}
				{weight 1 "stand_die_back_4"}
				{weight 1 "stand_die_back_5"}
				{weight 1 "stand_scenic-die_front_1"}
				{weight 1 "stand_scenic-die_front_2"}
				{weight 1 "stand_scenic-die_back_1"}
				{weight 1 "stand_scenic-die_back_2"}
			}
		}
		{if human_kill_flags "blast"
			{random_select
				{weight 1 "death_from_explosion_front"}
				{weight 1 "death_from_explosion_front02"}
				{weight 1 "death_from_explosion_front03"}
				{weight 1 "death_from_explosion_front04"}
				{weight 1 "death_from_explosion_front05"}				
				;{weight 1 "stand_die_back_4_blast"}
				{weight 0.5 "stand_die_back_5_blast"}
				{weight 1 "stand_die-force_back_1"}
				{weight 1 "stand_die-force_back_2_far"}
				{weight 1 "stand_die-force_back_3_far"}
			}
		}
	}
	{if human_kill_flags "back"
		{if human_kill_flags "piercing"
			{if human_kill_flags "go"
				{random_select
					{weight 1 "stand_scenic-die_front_1"}
					{weight 1 "stand_scenic-die_front_2"}
				}
			}
			{random_select
				{weight 1 "stand_die_front_2"}
				{weight 1 "stand_die_front_3"}
				{weight 1 "stand_die_front_4"}
				{weight 1 "stand_scenic-die_front_1"}
				{weight 1 "stand_scenic-die_front_2"}
			}
		}
		
		{if human_kill_flags "blast"
			{random_select
				{weight 1 "death_from_explosion_back"}
				{weight 1 "death_from_explosion_back02"}
				{weight 1 "death_from_explosion_back03"}
				{weight 1 "death_from_explosion_back04"}				
				{weight 1 "death_from_explosion_back05"}				
				{weight 0.5 "stand_die_front_1_blast"}
				{weight 1 "stand_die-force_front_1"}
				{weight 1 "stand_die-force_front_2"}
				{weight 1 "stand_die-force_front_3_far"}
				{weight 1 "stand_die-force_front_4_far"}
			}
		}
	}
	; die on spot - without moving around
	{random_select
		{weight 1 "stand_die_spot"}
		{weight 1 "stand_die_spot_1"}
	}
}
{squat_dying
	{if human_kill_flags "front"
		{if human_kill_flags "blast"
			{random_select
				{weight 1 "death_from_explosion_front"}
				{weight 1 "death_from_explosion_front02"}
				{weight 1 "death_from_explosion_front03"}
				{weight 1 "death_from_explosion_front04"}
				{weight 1 "death_from_explosion_front05"}				
				;{weight 1 "stand_die_back_4_blast"}
				{weight 0.5 "stand_die_back_5_blast"}
				{weight 1 "stand_die-force_back_1"}
				{weight 1 "stand_die-force_back_2_far"}
				{weight 1 "stand_die-force_back_3_far"}
			}
		}
		{random_select
			{weight 1 "squat_die"}
			{weight 1 "squat_die_back_1"}
			{weight 1 "squat_die_back_2"}
			{weight 1 "squat_die_force-back"}
		}
	}
	{if human_kill_flags "back"
		{if human_kill_flags "blast"
			{random_select
				{weight 1 "death_from_explosion_back"}
				{weight 1 "death_from_explosion_back02"}
				{weight 1 "death_from_explosion_back03"}
				{weight 1 "death_from_explosion_back04"}				
				{weight 1 "death_from_explosion_back05"}				
				{weight 0.5 "stand_die_front_1_blast"}
				{weight 1 "stand_die-force_front_1"}
				{weight 1 "stand_die-force_front_2"}
				{weight 1 "stand_die-force_front_3_far"}
				{weight 1 "stand_die-force_front_4_far"}
			}
		}
	}
	{anm "squat_die"}
}
{lie_dying
	{if terrain_pp "swamp"
		{anm "lie_die_drowin"}
	}
	{anm "lie_die"}
}
{lie_knock_down
	{anm "lie_die"}
}
{swim_dying
		{random_select
				{weight 1 "swim_dying_1"}
				{weight 1 "swim_dying_2"}
				{weight 1 "swim_dying_3"}
			}
}
{corpse_drop
	{anm "corpse_drop"}
}
{corpse_drag
	{anm "pose_corpse"}
}
{default_dying 
	{anm "stand_die_back_2"}
}