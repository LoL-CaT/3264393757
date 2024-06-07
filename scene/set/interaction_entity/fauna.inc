{"animal"
	{inflammation_time 2.0}
	{on blast
		{health_damage_blast
			{effects "" "" "damage" "die" "explosion" "explosion" "explosion"}
		}
	}
	{on blow opponent
		{health_damage_blow
			{effects "hit" "hit" "die" "die" "explosion" "explosion" "explosion"}
		}
		{call "damage"}
	}
	{on bullet_hit
		{call "pierce_damage"}
	}
	{on "pierce_damage"
		{health_damage_pierce
			{effects "" "" "damage" "die" "explosion" "explosion" "explosion"}
		}
	}
	{on contact 
		{if effector "vehicle"
			{if effector_velocity 0.1
				{health_damage_crush "die" "explosion"}
			}
		else effector "knife"
			{if contact_velocity 5
				{health_damage_count 110 {effects "" "hit" "damage" "die" "die"}}
			}
		else effector "axe"
			{if contact_velocity 5
				{health_damage_count 180 {effects "" "hit" "damage" "die" "die"}}
			}
		else effector "big part"
			{if contact_velocity 3
				{health_damage_count 60 {effects "" "hit" "damage" "die" "crush"}}
			}
		else effector "medium part"
			{if contact_velocity 6
				{health_damage_count 40 {effects "" "hit" "damage" "die" "crush"}}
			}
		else effector "small part"
			{if contact_velocity 10
				{health_damage_count 20 {effects "" "hit" "damage" "die" "die"}}
			}
		}
	}
	{on "die"
		{volumes disable contact}
		{die}
		{delay 3
			{volumes enable contact}
			{update_visibility_patch}
		}
	}
	{on "explosion"
		{delete}
	}
	{on "burn_volume"
		{if volume "body" or volume "body01"
			{call "_burn"}
		}
	}
	{on "_burn"
		{if not burned
			{able "burning" 1}
			{able select 0}
			{delay 0.5 1 "burn_die"	
				{kill_flags reset}
				{kill_flags piercing}
				{if not dead
					{call "die"}
				}
			}
		}
	}	
	{on "idle"
		{if name "enter"
			{call "idle_try"}
		else name "exit"
			{ani_stop "passive"}
			{ani_stop "eat"}
			{kill_delay "idle_try"}
			{kill_delay "idle_noanm"}
		}
	}
	{on "idle_try"
		{delay 0.2 0.1 "idle_try"
			{if rand 0.4
				{ani_play "eat" callback}
			else rand 0.4
				{ani_play "passive" callback}
			else
				{delay 5 3 "idle_noanm"
					{call "idle_try"}
				}
			}
		}
	}
	{on animation_end "passive"
		{call "idle_try"}
	}
	{on animation_end "eat"
		{call "idle_try"}
	}
}

{"chicken"
	{on "damage"
		{spawn "pero_hit_small"}
		{start_sound "animal/chicken/chicken_cluck"}
	}
	{on "die"
		{call "explosion"}
	}
	{on "explosion"
		{start_sound "animal/chicken/chicken_die"}
		{spawn "pero_hit"}
		{spawn "blood_small"}
		{delete}
	}
	{on "avoid"
		{if rand 0.3
			{start_sound "animal/chicken/chicken_cackles_walk"}
		}
	}
	{on ground_hit
		{call "feather"}
	}
	{on contact
		{if velocity 4
			{call "feather"}
		}
	}
	{on "feather"
		{if not flag "feather"
			{set "feather" 1}
			{spawn "pero_hit_small"}
			{start_sound "animal/chicken/chicken_cackles_walk"}
			{delay 0.2
				{set "feather" 0}
			}
		}
	}
}

(define "imp"
	{spawn %0 %1
		{impulse	up 1 0.5 dir 8 4
					cx 0 12 cy 0 12
					fx 0 60 fy 0 60 fz 80 40
		}
	}
)

{"dog"
	{on spawn
		{add_view	"drops_water_small3"	"on_water"	"leg1"}
		{add_view	"drops_water_small3"	"on_water"	"leg2"}
		{add_view	"drops_water_small3"	"on_water"	"leg3"}
		{add_view	"drops_water_small3"	"on_water"	"leg4"}
	}
	{on "damage"
		{spawn "bloodsparks_small"}
;		{if not dead
;			{start_sound "animal/dog/dog_bark_hit_whimper"}
;		}
	}
	{on "die"
;		{if not dead
;			{start_sound "animal/dog/dog_die"}
;		}
		{spawn "blood_small"}
	}
	{on "explosion"
		{if rand 0.7	("imp" args "head"	"basis")}
		{if rand 0.7	("imp" args "head"	"basis")}
		{if rand 0.7	("imp" args "hand1"	"basis")}
		{if rand 0.7	("imp" args "hand2"	"basis")}
		{if not dead
			{start_sound "animal/dog/dog_die"}
		}
		{spawn "blood"}
		{delete}
	}
	{on "avoid"
;		{if rand 0.3
;			{start_sound "animal/dog/dog_bark_friendly_whimper"}
;		}
	}

	(define "terrain_fx_dog"
		{on terrain_fx %0 enter
			{view start "on_%1"}
		}
		{on terrain_fx %0 leave
			{view pause "on_%1"}
		}
	)
	("terrain_fx_dog" args "shallow_water" 	water)
	("terrain_fx_dog" args "puddle"			water)
}

{"rabbit"
	{on "damage"
		{spawn "bloodsparks_small"}
	}
	{on "die"
		{spawn "rabbit_hit"}
		{spawn "blood_small"}
		{delete}
	}
	{on "explosion"
		{if rand 0.7	("imp" args "head"	"basis")}
		{if rand 0.7	("imp" args "head"	"basis")}
		{spawn "rabbit_hit"}
		{spawn "blood"}
;		{spawn "blood_small"}
		{delete}
	}
}

{"cow"
	{on "pierce_damage" overload
		{health_damage_pierce
			{effects "" "" "damage" "die" "explosion"}
		}
	}
	{on "damage"
		{spawn "bloodsparks_small"}
		{if not dead
			{start_sound "animal/cow/cow_moo"}
		}
	}
	{on "die"
		{start_sound "animal/cow/cow_die"}
		{spawn "blood_small"}
	}
	{on "explosion"
		{if rand 0.7	("imp" args "head"	"basis")}
		{if rand 0.7	("imp" args "head"	"basis")}
		{if rand 0.7	("imp" args "hand1"	"basis")}
		{if rand 0.7	("imp" args "hand2"	"basis")}
		{if not dead
			{start_sound "animal/cow/cow_die"}
		}
		{spawn "blood"}
		{delete}
	}
	{on "avoid"
		{if rand 0.3
			{start_sound "animal/cow/cow_moo"}
		}
	}
}
{"horse"
	{on spawn
		{volumes "body1" enable overlap}
		{add_view	"drops_puddle_small"	"on_puddle"	"joint1"}
		{add_view	"drops_puddle_small"	"on_puddle"	"joint2"}
		{add_view	"drops_puddle_small"	"on_puddle"	"joint3"}
		{add_view	"drops_puddle_small"	"on_puddle"	"joint4"}
		{link_sound "move" "animal/horse/move"}
		{link_sound "idle" "animal/horse/idle"}
	}
	{on contact
		{if not impregnable       
			{volumes disable contact}
		}
		{delay 2
			{volumes enable contact}
		}
	}

	{on "idle" overload
		{if name "exit"              
			{set "stop_anm" 1}
			{ani_stop "passive1"}
			{ani_stop "passive2"}    
			{set "stop_anm" 0}
		}
		{inherited}
	}
	{on "idle_try" overload
		{delay 0.15 0.05 "idle_try"
			{if rand 0.1
				{ani_play "eat" callback}  
			else rand 0.1
				{ani_play "passive" callback}
				{play_sound "idle"}
			else rand 0.1
				{ani_play "passive1" callback}
				{play_sound "idle"}
			else
				{ani_play "passive2" callback}
			}
		}
	}
	{on animation_end "passive1"
		{if not flag "stop_anm"
			{call "idle_try"}
		}
	}
	{on animation_end "passive2"
		{if not flag "stop_anm"
			{call "idle_try"}
		}
	}

	(define "terrain_fx_human"
		{on terrain_fx %0 enter
			{view start "on_%1"}
		}
		{on terrain_fx %0 leave
			{view pause "on_%1"}
		}
	)                                                             
	("terrain_fx_human" args "puddle"		puddle)
	("terrain_fx_human" args "shallow_water"	puddle)     
	
	{on "pierce_damage" overload
		{health_damage_pierce
			{effects "" "" "damage" "die" "explosion"}
		}
	}

	{on "damage"
		{spawn "bloodsparks_small"}
		{if not dead
;	        {start_sound "animal/horse/scream"}
		}
	}
	{on "die" overload
		{if not dead
			{spawn "bloodsparks_big"}
			{spawn "bloodsparks_big"}
			{spawn "bloodsparks_big"}
			{start_sound "animal/horse/death"}
			{drop_orders}
			{components destroy}
			{reset_manual_control}
			{crew_throw_off up 4 1 dir 1 0.5 turn 0 180 forward 2 rnd_die 0.1}
			{able select 0}
			{able repaired 0}
			{tags add "destroyed"}
			{unlink_trailer}
			{clear_inventory}
			{inherited}
		}
	}
	{on "burn"
		{if not burned
			{call "die"}
		}
	}
	{on "explosion"
		{call "die"}
;		{spawn "bloodsparks_big"}
;		{if not dead
;	        {start_sound "animal/horse/death"}
;		}
;		{spawn "blood"}
;		{delete}
	}
}