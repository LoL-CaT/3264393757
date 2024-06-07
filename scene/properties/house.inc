;SDL
{groupmesh}
{lodclass "building"}
{skeleton
	{bone "flag"}
}
{extender "structure"
	{place "flag" "house_flag"}
}
{volume "bottom_floor"
	{tags "body"}
	{able clear {touch 1} {visible 1}}
}
{placer}
{boarder}
{extender "structure_placer"
	{tracked_cover_types "snipe_cover" "squat_lie"}
	{mover "house"}
}
{brain "structure"
	{state "structure"}
	{const "place_change_period" 2}
	{place_changer
		{subjects_priority "cannon" "tank heavy" "vehicle"}
		{move_time_limit 20}
		{distance_to_subject_limit 75}
	}
}
{props "concrete" "trace_interceptor" "select_interceptor" "house" "fogged_as_gameentity" "mp_gather_for_linked" "slow_on_crush" "no_board_through_walls"}
{fogable never}
{extender "house"}
{extender "assault"}
{obstacleid "building"}
{targetClass "house"}
{extender "house_fortification"
	{work_amount 100.0}
	{work_amount_min 50.0}
	{work_time_min 30.0}
	{dweller_damage_resistance
		{unfortified 0.0 0.0} ; dweller in unfortified piece: use fortification progress to lerp between first and second values
		{fortified 0.0 0.5} ; dweller in fortified piece: use fortification progress to lerp between first and second values
	}
	{dweller_work_speed 0.25}
}
{able "ally_crew"}
