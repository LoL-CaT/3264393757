(define "on_play_sound_action"
	{on "play_sound_%action"
		{play_sound_in_channel "%action" "%action_ch"}
		{delay_effect 0 "%action_next_sound"}
	}
)
(define "on_action_next_sound"
	{on "%action_next_sound"
		{if flag "%action_play_sound"
			{delay %delay_next_sound "%action_next_sound"
				{call "play_sound_%action"}
			}
		}
	}
)
(define "start_check_stop_sound"
	{delay_effect 0.1 "%action_stop_sound"}
)
(define "on_action_start_sound"
	{on "%action_start_sound"
		{set "%action_play_sound" 1}
		{call "play_sound_%action"}
		("%check_stop" action(%action))
	}
)
(define "set_action_stop_sound_nocheck"
		{set "%action_play_sound" 0}
		{kill_delay "%action_next_sound"}
		{stop_sound "%action" 0 0.1}
)
(define "set_action_stop_sound_check"
		{if bodykit "%action" "in_progress"
			{delay_effect 0.1 "%action_stop_sound"}
		else
			("set_action_stop_sound_nocheck" action(%action))
		}

)
(define "on_action_stop_sound"
	{on "%action_stop_sound"
		("set_action_stop_sound_%check" action(%action))
	}

)
(define "action_play_sound_and_check_stop"
	("on_play_sound_action"			action(%action))
	("on_action_start_sound"		action(%action) delay_next_sound(%delay_next_sound) check_stop(start_check_stop_sound))
	("on_action_next_sound"			action(%action)	delay_next_sound(%delay_next_sound))
	("on_action_stop_sound"			action(%action)	check(check))
)
(define "action_play_sound"
	("on_play_sound_action"			action(%action))
	("on_action_start_sound"		action(%action)	delay_next_sound(%delay_next_sound) check_stop(none))
	("on_action_next_sound"			action(%action)	delay_next_sound(%delay_next_sound))
	("on_action_stop_sound"			action(%action)	check(nocheck))
)