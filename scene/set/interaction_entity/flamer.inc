(define "jet_of_fire_sound_init"
	{link_sound "jet_loop" "weapon/shot/flame/jet_%name/loop"}
)

(define "jet_of_fire_sound_play"
	{if stuff "flame_thrower"
		{if not flag "jet_of_fire_sound_playing"
			{start_sound "weapon/shot/flame/jet_%name/start"}
			{play_sound "jet_loop" 1 %loop_fade_in}
			{set "jet_of_fire_sound_playing" 1}
		}
	}
)

(define "jet_of_fire_sound_stop"
	{if stuff "flame_thrower"
		{kill_delay "flame_fire"}
		{delay 0.5 "flame_fire"
			{start_sound "weapon/shot/flame/jet_%name/stop"}
			{stop_sound "jet_loop" 0 %loop_fade_out}
			{set "jet_of_fire_sound_playing" 0}
		}
	}
)

(define "jet_of_fire_sound_init_default"
	("jet_of_fire_sound_init" name(default))
)

(define "jet_of_fire_sound_play_default"
	("jet_of_fire_sound_play" name(default) loop_fade_in(0.15))
)

(define "jet_of_fire_sound_stop_default"
	("jet_of_fire_sound_stop" name(default) loop_fade_out(0.15))
)