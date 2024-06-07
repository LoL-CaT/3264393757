;SDL
{stand_drop
	{if human_stuff holding "2hands"
		{anm "stand_pick_2hand_end" -1}
	}
	{if human_stuff holding "body"
		{anm "stand_drop_corpse"}
	}
	{anm "stand_pick_small_end" -1}
}
{stand_drop_end
	{anm "stand_pick_small_end"}
}
{stand_pickup
	{if human_stuff picking "2hands"
		{anm "stand_pick_2hand_begin"}
	}
	{anm "stand_pick_small_begin"}
}
{stand_pickup_end
	{if human_stuff holding "2hands"
		{anm "stand_pick_2hand_end"}
	}
	{anm "stand_pick_small_end"}
}
{lie_drop
	{anm "lie_take_item_end" -1}
}
{lie_drop_end
	{anm "lie_take_item_end"}
}
{lie_pickup
	{anm "lie_take_item_begin"}
}
{lie_pickup_end
	{anm "lie_take_item_end"}
}