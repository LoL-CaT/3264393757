	(define "self_ram_damage"
	{call "ram_effects"}
	{if relation "enemy"
		{if effector_velocity 100
			{call "crash_from_taran"}
			{with_effector
				{armor_health_damage (* %damage 1.3 %k)}
				{call "crash_from_taran"}
			}
		else effector_velocity %speed
			{call "crash_from_taran"}
			{with_effector
				{armor_health_damage  (* %damage %k)}
				{call "crash_from_taran"}
			}
		else effector_velocity (* %speed 0.34)
			{call "crash_from_taran"}
			{with_effector
				{armor_health_damage (* %damage 0.34 %k)}
				{call "crash_from_taran"}
			}
		else effector_velocity 2
		}
	}
	)
	(define "ram_damage"
	{call "ram_effects"}
	{if relation "enemy"
		{if effector_velocity 100
			{armor_health_damage (* %damage 2)}
			{call "crash_from_taran"}
			{if %component_damage3	{call "ram_component_damage"}}
			{with_effector
				{armor_health_damage (* %damage 1.3 %k)}
				{call "crash_from_taran"}
			}
		else effector_velocity %speed
			{armor_health_damage %damage}
			{call "crash_from_taran"}
			{if %component_damage2	{call "ram_component_damage"}}
			{with_effector
				{armor_health_damage  (* %damage %k)}
				{call "crash_from_taran"}
			}
		else effector_velocity (* %speed 0.34)
			{armor_health_damage (* %damage 0.34)}
			{call "crash_from_taran"}
			{if %component_damage1	{call "ram_component_damage"}}
			{with_effector
				{armor_health_damage (* %damage 0.34 %k)}
				{call "crash_from_taran"}
			}
		else effector_velocity 2
		}
	}
	)

{"ram_lvl1"
	{on contact
		{if not flag "no_slam"
			{set "no_slam" 1}
			{if effector "ram_lvl1"
				("ram_damage" damage(310) speed(32.55) k(0.5) component_damage3(true) component_damage2(true) component_damage1(false))
			else effector "ram_lvl2"
				("ram_damage" damage(332) speed(24.72) k(0.33) component_damage3(true) component_damage2(true) component_damage1(true))
			else effector "ram_lvl3"
				("ram_damage" damage(356) speed(27.56) k(0.1) component_damage3(true) component_damage2(true) component_damage1(true))
			else effector "ram_lvl4"
				("ram_damage" damage(381) speed(21.62) k(0) component_damage3(true) component_damage2(true) component_damage1(true))
			else effector "ram_lvl5"
				("ram_damage" damage(407) speed(19.24) k(0) component_damage3(true) component_damage2(true) component_damage1(true))
			else effector "ram_lvl6"
				("ram_damage" damage(435) speed(20.79) k(0) component_damage3(true) component_damage2(true) component_damage1(true))
			else effector "ram_lvl7"
				("ram_damage" damage(466) speed(19.4) k(0) component_damage3(true) component_damage2(true) component_damage1(true))
			else effector "ram_lvl8"
				("ram_damage" damage(499) speed(17.7) k(0) component_damage3(true) component_damage2(true) component_damage1(true))
			else effector "ram_lvl9"
				("ram_damage" damage(534) speed(14.89) k(0) component_damage3(true) component_damage2(true) component_damage1(true))
			else effector "ram_lvl10"
				("ram_damage" damage(571) speed(11.63) k(0) component_damage3(true) component_damage2(true) component_damage1(true))
			}
			{delay 1
				{set "no_slam" 0}
			}
		}
	}
}

{"ram_lvl2"
	{on contact
		{if not flag "no_slam"
			{set "no_slam" 1}
			{if effector "ram_lvl1"
				("ram_damage" damage(294) speed(32.55) k(1) component_damage3(true) component_damage2(false) component_damage1(false))
			else effector "ram_lvl2"
				("ram_damage" damage(374) speed(24.72) k(0.5) component_damage3(true) component_damage2(true) component_damage1(false))
			else effector "ram_lvl3"
				("ram_damage" damage(400) speed(27.56) k(0.33) component_damage3(true) component_damage2(true) component_damage1(true))
			else effector "ram_lvl4"
				("ram_damage" damage(428) speed(21.62) k(0.1) component_damage3(true) component_damage2(true) component_damage1(true))
			else effector "ram_lvl5"
				("ram_damage" damage(458) speed(19.24) k(0) component_damage3(true) component_damage2(true) component_damage1(true))
			else effector "ram_lvl6"
				("ram_damage" damage(490) speed(20.79) k(0) component_damage3(true) component_damage2(true) component_damage1(true))
			else effector "ram_lvl7"
				("ram_damage" damage(524) speed(19.4) k(0) component_damage3(true) component_damage2(true) component_damage1(true))
			else effector "ram_lvl8"
				("ram_damage" damage(561) speed(17.7) k(0) component_damage3(true) component_damage2(true) component_damage1(true))
			else effector "ram_lvl9"
				("ram_damage" damage(600) speed(14.89) k(0) component_damage3(true) component_damage2(true) component_damage1(true))
			else effector "ram_lvl10"
				("ram_damage" damage(624) speed(11.63) k(0) component_damage3(true) component_damage2(true) component_damage1(true))
			}
			{delay 1
				{set "no_slam" 0}
			}
		}
	}
}

{"ram_lvl3"
	{on contact
		{if not flag "no_slam"
			{set "no_slam" 1}
			{if effector "ram_lvl1"
				("ram_damage" damage(330) speed(32.55) k(1.2) component_damage3(false) component_damage2(false) component_damage1(false))
			else effector "ram_lvl2"
				("ram_damage" damage(419) speed(24.72) k(1) component_damage3(true) component_damage2(false) component_damage1(false))
			else effector "ram_lvl3"
				("ram_damage" damage(532) speed(27.56) k(0.5) component_damage3(true) component_damage2(true) component_damage1(false))
			else effector "ram_lvl4"
				("ram_damage" damage(570) speed(21.62) k(0.33) component_damage3(true) component_damage2(true) component_damage1(true))
			else effector "ram_lvl5"
				("ram_damage" damage(610) speed(19.24) k(0.1) component_damage3(true) component_damage2(true) component_damage1(true))
			else effector "ram_lvl6"
				("ram_damage" damage(652) speed(20.79) k(0) component_damage3(true) component_damage2(true) component_damage1(true))
			else effector "ram_lvl7"
				("ram_damage" damage(698) speed(19.4) k(0) component_damage3(true) component_damage2(true) component_damage1(true))
			else effector "ram_lvl8"
				("ram_damage" damage(747) speed(17.7) k(0) component_damage3(true) component_damage2(true) component_damage1(true))
			else effector "ram_lvl9"
				("ram_damage" damage(799) speed(14.89) k(0) component_damage3(true) component_damage2(true) component_damage1(true))
			else effector "ram_lvl10"
				("ram_damage" damage(855) speed(11.63) k(0) component_damage3(true) component_damage2(true) component_damage1(true))
			}
			{delay 1
				{set "no_slam" 0}
			}
		}
	}
}

{"ram_lvl4"
	{on contact
		{if not flag "no_slam"
			{set "no_slam" 1}
			{if effector "ram_lvl1"
				("self_ram_damage" damage(380) speed(32.55) k(1) component_damage3(false) component_damage2(false) component_damage1(false))
			else effector "ram_lvl2"
				("ram_damage" damage(372) speed(24.72) k(1.2) component_damage3(false) component_damage2(false) component_damage1(false))
			else effector "ram_lvl3"
				("ram_damage" damage(472) speed(27.56) k(1) component_damage3(true) component_damage2(false) component_damage1(false))
			else effector "ram_lvl4"
				("ram_damage" damage(600) speed(21.62) k(0.5) component_damage3(true) component_damage2(true) component_damage1(false))
			else effector "ram_lvl5"
				("ram_damage" damage(642) speed(19.24) k(0.33) component_damage3(true) component_damage2(true) component_damage1(true))
			else effector "ram_lvl6"
				("ram_damage" damage(687) speed(20.79) k(0.1) component_damage3(true) component_damage2(true) component_damage1(true))
			else effector "ram_lvl7"
				("ram_damage" damage(734) speed(19.4) k(0) component_damage3(true) component_damage2(true) component_damage1(true))
			else effector "ram_lvl8"
				("ram_damage" damage(786) speed(17.7) k(0) component_damage3(true) component_damage2(true) component_damage1(true))
			else effector "ram_lvl9"
				("ram_damage" damage(841) speed(14.89) k(0) component_damage3(true) component_damage2(true) component_damage1(true))
			else effector "ram_lvl10"
				("ram_damage" damage(900) speed(11.63) k(0) component_damage3(true) component_damage2(true) component_damage1(true))
			}
			{delay 1
				{set "no_slam" 0}
			}
		}
	}
}

{"ram_lvl5"
	{on contact
		{if not flag "no_slam"
			{set "no_slam" 1}
			{if effector "ram_lvl1"
				("self_ram_damage" damage(407) speed(32.55) k(1) component_damage3(false) component_damage2(false) component_damage1(false))
			else effector "ram_lvl2"
				("self_ram_damage" damage(458) speed(24.72) k(1) component_damage3(false) component_damage2(false) component_damage1(false))
			else effector "ram_lvl3"
				("ram_damage" damage(493) speed(27.56) k(1.2) component_damage3(false) component_damage2(false) component_damage1(false))
			else effector "ram_lvl4"
				("ram_damage" damage(626) speed(21.62) k(1) component_damage3(true) component_damage2(false) component_damage1(false))
			else effector "ram_lvl5"
				("ram_damage" damage(795) speed(19.24) k(0.5) component_damage3(true) component_damage2(true) component_damage1(false))
			else effector "ram_lvl6"
				("ram_damage" damage(851) speed(20.79) k(0.33) component_damage3(true) component_damage2(true) component_damage1(true))
			else effector "ram_lvl7"
				("ram_damage" damage(910) speed(19.4) k(0.1) component_damage3(true) component_damage2(true) component_damage1(true))
			else effector "ram_lvl8"
				("ram_damage" damage(974) speed(17.7) k(0) component_damage3(true) component_damage2(true) component_damage1(true))
			else effector "ram_lvl9"
				("ram_damage" damage(1042) speed(14.89) k(0) component_damage3(true) component_damage2(true) component_damage1(true))
			else effector "ram_lvl10"
				("ram_damage" damage(1115) speed(11.63) k(0) component_damage3(true) component_damage2(true) component_damage1(true))
			}
			{delay 1
				{set "no_slam" 0}
			}
		}
	}
}

{"ram_lvl6"
	{on contact
		{if not flag "no_slam"
			{set "no_slam" 1}
			{if effector "ram_lvl1"
				("self_ram_damage" damage(436) speed(32.55) k(1) component_damage3(false) component_damage2(false) component_damage1(false))
			else effector "ram_lvl2"
				("self_ram_damage" damage(490) speed(24.72) k(1) component_damage3(false) component_damage2(false) component_damage1(false))
			else effector "ram_lvl3"
				("self_ram_damage" damage(652) speed(27.56) k(1) component_damage3(false) component_damage2(false) component_damage1(false))
			else effector "ram_lvl4"
				("ram_damage" damage(490) speed(21.62) k(1.2) component_damage3(false) component_damage2(false) component_damage1(false))
			else effector "ram_lvl5"
				("ram_damage" damage(623) speed(19.24) k(1) component_damage3(true) component_damage2(false) component_damage1(false))
			else effector "ram_lvl6"
				("ram_damage" damage(791) speed(20.79) k(0.5) component_damage3(true) component_damage2(true) component_damage1(false))
			else effector "ram_lvl7"
				("ram_damage" damage(846) speed(19.4) k(0.33) component_damage3(true) component_damage2(true) component_damage1(true))
			else effector "ram_lvl8"
				("ram_damage" damage(906) speed(17.7) k(0.1) component_damage3(true) component_damage2(true) component_damage1(true))
			else effector "ram_lvl9"
				("ram_damage" damage(969) speed(14.89) k(0) component_damage3(true) component_damage2(true) component_damage1(true))
			else effector "ram_lvl10"
				("ram_damage" damage(1037) speed(11.63) k(0) component_damage3(true) component_damage2(true) component_damage1(true))
			}
			{delay 1
				{set "no_slam" 0}
			}
		}
	}
}

{"ram_lvl7"
	{on contact
		{if not flag "no_slam"
			{set "no_slam" 1}
			{if effector "ram_lvl1"
				("self_ram_damage" damage(466) speed(32.55) k(1) component_damage3(false) component_damage2(false) component_damage1(false))
			else effector "ram_lvl2"
				("self_ram_damage" damage(524) speed(24.72) k(1) component_damage3(false) component_damage2(false) component_damage1(false))
			else effector "ram_lvl3"
				("self_ram_damage" damage(698) speed(27.56) k(1) component_damage3(false) component_damage2(false) component_damage1(false))
			else effector "ram_lvl4"
				("self_ram_damage" damage(735) speed(21.62) k(1) component_damage3(false) component_damage2(false) component_damage1(false))
			else effector "ram_lvl5"
				("ram_damage" damage(613) speed(19.24) k(1.2) component_damage3(false) component_damage2(false) component_damage1(false))
			else effector "ram_lvl6"
				("ram_damage" damage(779) speed(20.79) k(1) component_damage3(true) component_damage2(false) component_damage1(false))
			else effector "ram_lvl7"
				("ram_damage" damage(989) speed(19.4) k(0.5) component_damage3(true) component_damage2(true) component_damage1(false))
			else effector "ram_lvl8"
				("ram_damage" damage(1059) speed(17.7) k(0.33) component_damage3(true) component_damage2(true) component_damage1(true))
			else effector "ram_lvl9"
				("ram_damage" damage(1133) speed(14.89) k(0.1) component_damage3(true) component_damage2(true) component_damage1(true))
			else effector "ram_lvl10"
				("ram_damage" damage(1212) speed(11.63) k(0) component_damage3(true) component_damage2(true) component_damage1(true))
			}
			{delay 1
				{set "no_slam" 0}
			}
		}
	}
}

{"ram_lvl8"
	{on contact
		{if not flag "no_slam"
			{set "no_slam" 1}
			{if effector "ram_lvl1"
				("self_ram_damage" damage(499) speed(32.55) k(1) component_damage3(false) component_damage2(false) component_damage1(false))
			else effector "ram_lvl2"
				("self_ram_damage" damage(561) speed(24.72) k(1) component_damage3(false) component_damage2(false) component_damage1(false))
			else effector "ram_lvl3"
				("self_ram_damage" damage(747) speed(27.56) k(1) component_damage3(false) component_damage2(false) component_damage1(false))
			else effector "ram_lvl4"
				("self_ram_damage" damage(786) speed(21.62) k(1) component_damage3(false) component_damage2(false) component_damage1(false))
			else effector "ram_lvl5"
				("self_ram_damage" damage(974) speed(19.24) k(1) component_damage3(false) component_damage2(false) component_damage1(false))
			else effector "ram_lvl6"
				("ram_damage" damage(689) speed(20.79) k(1.2) component_damage3(false) component_damage2(false) component_damage1(false))
			else effector "ram_lvl7"
				("ram_damage" damage(876) speed(19.4) k(1) component_damage3(true) component_damage2(false) component_damage1(false))
			else effector "ram_lvl8"
				("ram_damage" damage(1112) speed(17.7) k(0.5) component_damage3(true) component_damage2(true) component_damage1(false))
			else effector "ram_lvl9"
				("ram_damage" damage(1189) speed(14.89) k(0.33) component_damage3(true) component_damage2(true) component_damage1(true))
			else effector "ram_lvl10"
				("ram_damage" damage(1273) speed(11.63) k(0.1) component_damage3(true) component_damage2(true) component_damage1(true))
			}
			{delay 1
				{set "no_slam" 0}
			}
		}
	}
}

{"ram_lvl9"
	{on contact
		{if not flag "no_slam"
			{set "no_slam" 1}
			{if effector "ram_lvl1"
				("self_ram_damage" damage(534) speed(32.55) k(1) component_damage3(false) component_damage2(false) component_damage1(false))
			else effector "ram_lvl2"
				("self_ram_damage" damage(600) speed(24.72) k(1) component_damage3(false) component_damage2(false) component_damage1(false))
			else effector "ram_lvl3"
				("self_ram_damage" damage(799) speed(27.56) k(1) component_damage3(false) component_damage2(false) component_damage1(false))
			else effector "ram_lvl4"
				("self_ram_damage" damage(841) speed(21.62) k(1) component_damage3(false) component_damage2(false) component_damage1(false))
			else effector "ram_lvl5"
				("self_ram_damage" damage(1042) speed(19.24) k(1) component_damage3(false) component_damage2(false) component_damage1(false))
			else effector "ram_lvl6"
				("self_ram_damage" damage(969) speed(20.79) k(1) component_damage3(false) component_damage2(false) component_damage1(false))
			else effector "ram_lvl7"
				("ram_damage" damage(808) speed(19.4) k(1.2) component_damage3(false) component_damage2(false) component_damage1(false))
			else effector "ram_lvl8"
				("ram_damage" damage(1025) speed(17.7) k(1) component_damage3(true) component_damage2(false) component_damage1(false))
			else effector "ram_lvl9"
				("ram_damage" damage(1303) speed(14.89) k(0.5) component_damage3(true) component_damage2(true) component_damage1(false))
			else effector "ram_lvl10"
				("ram_damage" damage(1394) speed(11.63) k(0.33) component_damage3(true) component_damage2(true) component_damage1(true))
			}
			{delay 1
				{set "no_slam" 0}
			}
		}
	}
}

{"ram_lvl10"
	{on contact
		{if not flag "no_slam"
			{set "no_slam" 1}
			{if effector "ram_lvl1"
				("self_ram_damage" damage(571) speed(32.55) k(1) component_damage3(false) component_damage2(false) component_damage1(false))
			else effector "ram_lvl2"
				("self_ram_damage" damage(642) speed(24.72) k(1) component_damage3(false) component_damage2(false) component_damage1(false))
			else effector "ram_lvl3"
				("self_ram_damage" damage(854) speed(27.56) k(1) component_damage3(false) component_damage2(false) component_damage1(false))
			else effector "ram_lvl4"
				("self_ram_damage" damage(900) speed(21.62) k(1) component_damage3(false) component_damage2(false) component_damage1(false))
			else effector "ram_lvl5"
				("self_ram_damage" damage(1115) speed(19.24) k(1) component_damage3(false) component_damage2(false) component_damage1(false))
			else effector "ram_lvl6"
				("self_ram_damage" damage(1037) speed(20.79) k(1) component_damage3(true) component_damage2(false) component_damage1(false))
			else effector "ram_lvl7"
				("self_ram_damage" damage(1212) speed(19.4) k(1) component_damage3(false) component_damage2(false) component_damage1(false))
			else effector "ram_lvl8"
				("ram_damage" damage(868) speed(17.7) k(1.2) component_damage3(false) component_damage2(false) component_damage1(false))
			else effector "ram_lvl9"
				("ram_damage" damage(1102) speed(14.89) k(1) component_damage3(true) component_damage2(false) component_damage1(false))
			else effector "ram_lvl10"
				("ram_damage" damage(1400) speed(11.63) k(0.5) component_damage3(true) component_damage2(true) component_damage1(false))
			}
			{delay 1
				{set "no_slam" 0}
			}
		}
	}
}

{"explosion_throw_crew vehicle"
	{on "_explosion"
		{crew_throw_off up 4 1 dir 5 1 turn 0 180 forward 2 rnd_die 0.5}
	}
}

{"turret_rotator"
	{on spawn
		{set "rotate_turret" 0}
	}
	{on ik begin "turret"
		{kill_delay "rotate_turret"}
		{if not flag "rotate_turret"
			{play_sound "rotate_turret" 1}
			{set "rotate_turret" 1}
		}
	}
	{on ik end "turret"
		{delay 0.5 "rotate_turret"
			{stop_sound "rotate_turret"}
			{set "rotate_turret" 0}
		}
	}
}
{"spawn_shell"
	{on "spawn_shell"
		{start_sound "weapon/shot/shell"}
		{add_view "smoke_zenit" "smoke_shell" "fx_invers"}
		{view start "smoke_shell"}
		{delay 2.5 0.5
			{view stop "smoke_shell"}
		}
		{spawn "shell_cannon" "fx_invers" x scale 0.014
			{impulse up 1.5 0.5 dir -4.5 0.7 cz 0.2 0.1 com}
			{add_view "smoke_zenit" "smoke_shell" "fx_shellsmoke"}
			{view start "smoke_shell"}
			{delay_effect 3 1 "stop"}
			{delay 3 0.5
				{hide 3}
			}
		}
	}
	{on fire "gun"
		{call "spawn_shell"}
	}
}
{"xmas_present_tank"
	{on spawn
		{if crew_in_place "driver"
			{set "del_block" 1}
		}
		{if crew_in_place "gunner"
			{set "del_block" 1}
		}
		{if tagged "present_tank"
			{delay 120
				{if not flag "del_block"
					{delete}
				}
			}
		}
	}
	{on operatable on 
		{set "del_block" 1}
	}
}
{"vehicle"
	{inflammation_time 20}
	{on spawn
		{add_view	"stop_signal"	"stop_signal"	"FXstop1"}
		{add_view	"stop_signal"	"stop_signal"	"FXstop2"}

		{add_view 	"car_headlight"		"light"			"headlightL"}
		{add_view 	"car_headlight"		"light"			"headlightR"}
		{add_view 	"light_vehicle"		"light"			"headlightL"}
		{add_view 	"light_vehicle"		"light"			"headlightR"}
		
		{add_view 	"light_vehicle"	"light"			"fxlight"}
		{add_view 	"light_vehicle"	"light"			"fxlight1"}
		{add_view 	"car_headlight"	"light"			"fxlight"}
		{add_view 	"car_headlight"	"light"			"fxlight1"}

		{view hide "stop_signal"}
		{view hide "light"}
		{view hide "highlight"}
		
		{link_sound "round_sandbag" "fortification/install/reinforcement_sandbags_install"}
		{link_sound "camouflage" 	"fortification/install/camouflage_bushes_install"}
		{link_sound "build_supp_point" 	"fortification/install/field_warehouse_install"}
		{link_sound "trailer_link" 	"vehicle/gun_clutch_in"}
		{link_sound "detach" 		"vehicle/gun_clutch_out"}

		{link_sound "track_broken"	"vehicle/tracks_broken_clunk"}
		{link_sound "engine_broken"	"vehicle/engine_broken"}

		{call "init_gun"}
		{call "add_movement_sound"}
		{call "update_moveable"}
		{call "update_lights"}
		{set "burn_fire" 0}
		{set "engine_on" 0}
		
		{if props "tank"
			{crew_enable place "charger" 1}
			{crew_enable place "charger2" 1}
			{crew_enable place "gunner" 1}
			{crew_enable place "gunner2" 1}
			{crew_enable place "gunner3" 1}
			{crew_enable place "gunner4" 1}
			{crew_enable place "driver" 1}
			{crew_enable place "commander" 1}
		}
	}
	{on bullet_hit
		{call "detect_by_hit"}
		{if stuff "flaergun strike" ("grenade_signal_without_physics_mortar")
		else stuff "smoke_gr"("grenade_smoke")}
		
	}
	{on "detect_by_hit"}
	
	{on "chassis_off"
		{chassis_work 0}
	}
	{on "chassis_on"
		{chassis_work 1}
	}
	{on "weapons_off"
		{weapon_work "gun" 0}
		{weapon_work "mgun" 0}
		{weapon_work "mgun1" 0}
		{weapon_work "mgun2" 0}
		{weapon_work "mgun3" 0}
		{weapon_work "mgun4" 0}
		{weapon_work "mgun5" 0}
		{weapon_work "mgun6" 0}
		{weapon_work "mgun7" 0}
	}
	{on "init_gun"
		{add_view	"flash_gun_big01"	"flashbarrel41"	"foresight4"}
		{add_view	"flash_gun_big01"	"flashbarrel51"	"foresight5"}
		{add_view	"flash_gun_big01"	"flashbarrel61"	"foresight6"}
		{add_view	"flash_gun_big01"	"flashbarrel71"	"foresight7"}
		{add_view	"flash_gun_big01"	"flashbarrel81"	"foresight8"}
		{add_view	"flash_gun_big01"	"flashbarrel91"	"foresight9"}
		{add_view	"flash_gun_big01"	"flashbarrel101"	"foresight10"}
	}
	{on animation_end "start"
		{set "start_end" 0}
	}
	{on animation_end "stop"
		{set "stop_end" 0}
	}
	{on "stop_on"
		{if not flag "start_end" and operatable
			{ani_wind "stop" begin}
			{ani_play "stop" +1 resume callback}
			{set "stop_end" 1}
			else
			{if operatable {ani_play "start" +2.0 resume callback}}
		}
		{if operatable and not tagged "destroyed"
			{view show "stop_signal"}
			{view start "stop_signal"}
			{delay 0.5
				{view hide "stop_signal"}
			}
		}
	}
	{on "exhaust_on"
		{play_sound "exhaust"}
		{view start "exhaust"}
	}
	{on "exhaust_off"
		{stop_sound "exhaust"}
		{view pause "exhaust"}
	}
	
	{on turn on
		;{call "stop_on"}
		{call "exhaust_on"}
		{delay 0.5
			{call "exhaust_off"}
		}
	}
	{on turn off
	}
	{on move on
		{stop_sound "move_end"}
		{play_sound "move" 1}
		{if not move_backward
			{if not flag "start_end" and not flag "stop_end"
				{ani_wind "start" begin}
				{ani_play "start" +1 resume callback}
				{set "start_end" 1}
			}
			else
			{if not flag "start_end" and not flag "stop_end" 
				{call "stop_on"}
			}
		}
		{if flag "engine_on"
			{call "exhaust_on"}
			{delay 1
				{call "exhaust_off"}
			}
		}
	}
	{on move off
	{if not move_backward
		{if not flag "start_end" and not flag "stop_end"
			{call "stop_on"}
		}
	}
		{stop_sound "move"}
		{play_sound "move_end"}
		{view pause "exhaust"}
	}
	{on accelerate on
		{if flag "engine_on"
			{call "exhaust_on"}
			{delay 0.5
				{call "exhaust_off"}
			}
		}
	}
	{on accelerate off
	}
	{on brake on
		{if not flag "stop_end" {call "stop_on"}}
	}
	{on "play_engine"
		{play_sound "engine" 1}
		{view pause "exhaust"}
	}
	{on "delay_play_engine"
		{delay_effect 2 "play_engine"}
	}
	{on engine on
		{kill_delay "engine_stopped"}
		{kill_delay "engine_steam_stopped"}
		{stop_sound "engine_end"}
		{if not flag "engine_on"
			{set "engine_on" 1}
			{play_sound "engine_start"}
			{view start "exhaust"}
			{call "delay_play_engine"}
		}
		{view start "engine_steam"}
		{delay 1.5
			{view start "tube_steam1"}
			{view start "tube_steam2"}
		}

	}
	{on engine off
		{delay 10 "engine_stopped"
			{set "engine_on" 0}
			{stop_sound "engine"}
			{play_sound "engine_end"}
			{delay 1
				{view pause "tube_steam1"}
				{view pause "tube_steam2"}
			}
		}
		{delay 20 "engine_steam_stopped"
			{view pause "engine_steam"}
		}
	}
	{on crew in
		{delay 1.0 {if flag "broken" {crew_emit}}}
	}
	{on break
		{if component "body"
			{armor_health_damage_fatal}
			{call "stat_break"}
		else component "turret"
;			{stat_notify break}
		else component "engine"
			{play_sound "engine_broken"}
		else component "trackleft" or component "trackright"
			{play_sound "track_broken"}
		}
		{call "update_moveable"}
		{call "break_light"}
	}
	{on blast_hit
		{if can_be_damaged
			{if stuff "mine antipersonnel" or stuff "mine antitank"
				{talk "tank_mines" {audience ally}}
			else stuff "dynamite"
				{talk "explosives" {audience ally}}
			}
		}
	}
	{on repair
		{talk "repair_end"}
		{call "update_moveable"}
		{call "repair_light"}
		{if component "body"
			{view stop "t_for_des_1"}
			{view stop "t_for_des_2"}
			{view stop "t_for_des_3"}
		}
	}

	{on "break_light"
		{if component "engine"
			{bone cut "headlightL"}
			{bone cut "headlightR"}
			{bone cut "fxlight"}
		}
	}
	{on "repair_light"
		{if component "engine"}
	}
	{on "lights_on"
		{view start "light"}
		{view show "light"}
	}
	{on "lights_off"
		{view stop "light"}
		{view hide "light"}
	}
	{on "update_lights"
		{if not sunlight
			{if operatable
				{call "lights_on"}
			else
				{call "lights_off"}
			}
		}
	}
	{on operatable on
		{call "update_lights"}
	}
	{on operatable off
		{unlink_trailer}
		{call "update_lights"}
	}
	{on "add_view_mgun"
			{add_view "flash_cannon_small01"	"flashbarrel03"	"foresight3"}
	}
	{on "link_weapon"
		{if name "mgun"
			{call "add_view_mgun"}
			{add_view "zenit_gilz"		"shell"			"fxshell"}
		else
			{view hide	"flashbarrel03"}
			{view pause	"flashbarrel03"}

			{view pause "shell"}
		}
	}
	{on fire "mgun"
		{view show	"flashbarrel03"}
		{view start "flashbarrel03"}
		{ani_play "fire_mgun"}
		{view start "shell"}
		{kill_delay "shell"}
		{delay 0.2 "shell"
			{view pause "shell"}
		}
	}
	{on fire "mgun1"
		{view start "flashbarrel41"}
	}
	{on fire "mgun2"
		{view start "flashbarrel51"}
	}
	{on fire "mgun3"
		{view start "flashbarrel61"}
	}
	{on fire "mgun4"
		{view start "flashbarrel71"}
	}
	{on fire "mgun5"
		{view start "flashbarrel81"}
	}
	{on fire "mgun6"
		{view start "flashbarrel91"}
	}
	{on fire "mgun7"
		{view start "flashbarrel101"}
	}
	{on "component_break"
		{if not component "body"
			{component break}
		}
	}
	{on contact
		{if volume "sticky"
			{if effector "grenade"
				{if not effector "contact"
					{call "grenade_stick"}
				}
			}
		}
		{if not impregnable
			{if effector_velocity 3
				{if effector "airborne"
					{call "contact_airborne"}
				else effector "piece_big_stone"
					{call "component_break"}
				}
			}
		}
	}
	{on "grenade_stick"
		{with_effector
			{link_grenade_to_nearest_human}
		}
	}
	{on "contact_airborne"
		{if not flag "contact_airborne_first"
			{set "contact_airborne_first" 1}
			{call "component_break"}
			{armor_health_damage 300}
			{if armor_health 1 and not flag "broken"	{call "explosion"}}
			{delay 0.1							{set "contact_airborne_first" 0}}
		}
	}

	{on "update_moveable"
		{if work "body"
			{view stop "smoke4"}
		else
			{view start "smoke4"}
		}
		{if work "engine"
			{call "check_work_mover"}
		else
			{chassis_work 0}
		}
	}
	{on "check_work_mover"
		{if work "mover"
			{chassis_work 1}
		else
			{chassis_work 0}
		}
	}

	{on "explosion"
		{if not able "exploded"
			{call "talk_target_destroyed"}
			{damage_report "body" "empty"}
			{damage_report "engine" "empty"}
			{damage_report "trackright" "empty"}
			{damage_report "trackleft" "empty"}
			{damage_report "turret" "empty"}
			{damage_report "gun" "empty"}
			{able "exploded" 1}
			{if not tagged "fuel_barrels" 
				{call "_explosion"}
				else {delay_ex 4 {call "_explosion"}}
			}
		}
	}
	{on "_explosion"
		{call "__explosion"}
;		{call "stat_break"}
		{call "break_all"}
		{stop_sound "move"}
		{stop_sound "move_end"}
		{stop_sound "engine"}
		{stop_sound "engine_end"}
		{stop_sound "exhaust"}
		{view stop "fire1"}
		{view stop "fire2"}
		{tags add "destroyed"}
		{kick_entity_manager}
		{call "explosion_sound"}

		{if not terrain_fx "bridge"
			{if not under_water
				{call "spawn_shellhole"}
			}
		}

		{delay_ex 0
			{set "no_burn_volumes" 1}
			{set_skeleton "_xx" sync}
			{ani_play "death"}
			{call "cut_parts"}
		}
	}
	{on "__explosion"
		{set "big_explosion" 0}
		{if explosive_amount 1000 and inventory_item "shell fg bomb" and not props "cannon" or explosive_amount 1000 and inventory_item "shell fg 150to152" and not props "cannon"
			{blastwave c4 10 r0 5 r1 10} 
			{spawn "1ex_sturmtiger" "basis"}
			{delay 0.1
				{call "_explosion"}
			}
		else explosive_amount 1000 and inventory_item "shell fg 150to152" and props "cannon"
			{blastwave c4 10 r0 5 r1 10} 
			{spawn "ex_goliath" "basis"}
			{delay 0.1
				{call "_explosion"}
			}
		}
	}
	{on "explosion_blastwave"
		{fragments c4 3 r0 3 r1 8}
	}
	{on "explosion_sound"
		{if flag "crush"
			{start_sound "crush/medium/vehicle"}
		else
			{call "explosion_blastwave"}
			{start_sound "crush/big/vehicle"}
		}
	}

	{on "break_all"
		{kill_crew}
		{drop_orders}
		{components destroy}
		{armor_health_damage_fatal}
		{reset_manual_control}
		{able select 0}
		{able repaired 0}
		{unlink_trailer}
		{clear_inventory}
	}
	
	{on "kill_crew"
		{kill_crew}
	}
	
	{on "_burn"
		{attack_save}
		{if not tagged "burned"
			{tags add "fire_burn"}
			{if not able "exploded"
				{kill_delay "burn1"}{kill_delay "burn2"}{kill_delay "burn3"}
				{if not flag "burn_fire"	{damage_report "body" "burn"}}
				{add_view		"smoke_dead_norm2"	"burn_fire"		"FXfire1"}
				{view start "burn_fire"}
				{burn time 1}
				{add_view "smoke_black" "burn_fire" "FXfire1"}
				{play_sound "flame" 1}
				{view start "burn_fire"}
				{set "burn_fire" 1}
				;{con "---burn_damage_start"}
				{delay_effect 0 "burn_damage"}
				{delay 1			{burn stop_retry}}
				(define "duration_of_the_burning"
					{delay %sound 2	"burn1"	{start_sound "crush/medium/metal"}}
					{delay %sound 2	"burn2"	{start_sound "crush/medium/metal"}}
					{delay %end	"burn3"
						{if not flag "upended" 
							{call "burn_stop"}
						else
							{call "explosion"}
						}
					}
				)
				{if flag "upended"
					{icon_event "burning" 15.0}
					("duration_of_the_burning"	emit(4)		sound(13)	end(15))
				else flag "burn_fire_last_stage"
					;{con "----fire 10sec"}
					{icon_event "burning" 10.0}
					("duration_of_the_burning"	emit(4)		sound(8)	end(10))
				else flag "burn_fire_second_stage"
					;{con "----fire 8sec"}
					{icon_event "burning" 8.0}
					("duration_of_the_burning"	emit(3.2)	sound(6)	end(8))
					{if flag "burn_fire_next_stage"
						{set "burn_fire_last_stage" 1}
						{set "burn_fire_next_stage" 0}
					}
				else
					;{con "----fire 6sec"}
					{icon_event "burning" 6.0}
					("duration_of_the_burning"	emit(2.4)	sound(4)	end(6))
					{if flag "burn_fire_next_stage"
						{set "burn_fire_second_stage" 1}
						{set "burn_fire_next_stage" 0}
					}
				}
			}
		}
	}
	
	{on "burn_emit"
		{if not able "burning"
			{able "burning" 1}
			{set_heater}
			{reset_manual_control}
			{if not tagged "in_mp_d"
				{delay 1
					{call "burn_stop"}
				}
			}
		}
	}
	
	{on "burn_damage"
		{attack_load
		{if flag "burn_fire"
			;{con "------armor_health_damage 75"}
			{if not flag "upended" 
				{armor_health_damage 75}
			}
			{if not flag "burn_fire_next_stage" and rand 0.2	{set "burn_fire_next_stage" 1}}
			{if not flag "burn_engine" and work "engine" and rand 0.3
				{set "burn_engine" 1}
				{damage_report "engine" "burn"}
				{delay 3 1
					{call "engine_broken"}
					{set "burn_engine" 0}
				}
			}
			{if not flag "upended" 
				{if armor_health -399 and tagged "broken_body"
					{tags add "burned"}{burn stop}
					{call "mp_destroy"}
				else armor_health 1 and not tagged "broken_body"
					{call "stat_break"}
					{call "burn_stop"}
					{call "check_burn_emit"}
					{burn stop}
					{if rand 0.33
						{call "explosion"}
					else 
						{call "mp_destroy"}
						{able "burning" 0}
					}
				else tagged "dampen"
					{call "burn_stop"}
				else
					{delay_effect 1 "burn_damage"}
				}
			}
		}
		}
	}
	
	{on "call_firefight"
		{if not tagged "dampen" or tagged "fire_burn" 
			{tags add "dampen"}
		}
	}
	
	{on "burn_volume"
		{if not burned
			{if component "engine" or component "body"
				{attack_save}
				{delay_effect 0 "_burn"}
			else tagged "broken_body" and not tagged "destroyed" and not flag "burning"
				{attack_save}
				{delay_effect 0 "_burn"}
			else
				{burn volume fx "smoke_dead_small" time 5 1 fake even_law}
			}
		else burned and tagged "broken_body" and not tagged "destroyed" and not flag "burning"
			{attack_save}
			{delay_effect 0 "_burn"}
		else not tagged "destroyed" and not flag "burning"
			{attack_save}
			{delay_effect 0 "_burn"}
		}
	}	

	{on "burn_stop"
		{explosive 0}
		{view hide "burn_fire"}
		{view stop "burn_fire"}
		{stop_sound "flame"}
		{set "burn_fire" 0}
		{set "burn_fire_second_stage" 0}
		{set "burn_fire_last_stage" 0}
		{set "burn_fire_next_stage" 0}
		{tags remove "dampen"}
		{tags remove "fire_burn"}
	}

	{on "ur_damage"
		{start_sound "hit/small/metal"}
		{if not flag "ur_damage_s1" and not flag "ur_damage_s2"	;00
			{if rand 0.5
				{set "ur_damage_s1" 1}							;10(2 times)
			else 
				{set "ur_damage_s1" 1}{set "ur_damage_s2" 1}	;11(3 times)
			}
		else not flag "ur_damage_s1" and flag "ur_damage_s2" 	;01
			{set "ur_damage_s1" 0}{set "ur_damage_s2" 0}		;00(0 times)
		else flag "ur_damage_s1" and not flag "ur_damage_s2" 	;10
			{set "ur_damage_s1" 0}{set "ur_damage_s2" 1}		;01(1 times)
		else flag "ur_damage_s1" and flag "ur_damage_s2" 		;11
			{set "ur_damage_s1" 1}{set "ur_damage_s2" 0}		;10(2 times)
		}
		{if rand 0.5			{armor_health_damage 17}
		else					{armor_health_damage 15}
		}
		{if else armor_health -399 and not flag "broken"			{call "mp_destroy"}
		else armor_health 1 and not flag "broken"			{call "mp_destroy"}}
		{if flag "ur_damage_s1" or flag "ur_damage_s2"		{delay_effect 0.4 0.15 "ur_damage"}}
	}
	{on "check_ur_pierce"
		{if volume "body" or volume "turret" or volume "turret1" or volume "turret2" or volume "turret3" or volume "turret4"
			{if weapon "ur" {delay_effect 0.3 0.2 "ur_damage"}}
		}
	}
	
	{on "stat_break"	
		{if not tagged "body_break"
			{if not flag "broken"
				{set "broken" 1}
				{if flag "burn_fire"
					{stat_notify break burned}
				else
					{stat_notify break}
				}
			}
		}		
	}

	{on "vehicle_mining_start"
		{if work "body"
			{if not tagged "abandoned"
				{unlink_trailer}
				{reset_manual_control}
				{damage_report "crew" "leave"}
				{crew_emit}
			}
		}
	}
	
	{on "vehicle_mining_end"
		{if not operatable
			{tags add "abandoned"}
			{set "broken" 1}
			{able select 0}
			{able repaired 0}
			{explosive 1}
			{player -1}
			{stat_notify leave}
			{kick_entity_manager}
			{explosive 1}

			{damage_report "body" "empty"}
			{damage_report "trackright" "empty"}
			{damage_report "trackleft" "empty"}
			{damage_report "gun" "empty"}
			{damage_report "turret" "empty"}
			{damage_report "engine" "empty"}
			
			{delay 1					
				{explosive 0}
				{tags add "destroyed"}
				{call "explosion"}
			}
		}
	}
	
	{on "vehicle_mining_abort"}
	{on "vehicle_mining_in_process" {crew_emit}}

	{on "selection"
		{talk "tank_selection"}
	}
	{on "executing_order_move"
		{talk "tank_executing_order"}
	}
	{##on "leave_unit"
		{if work "body"
			{if not tagged "abandoned"
				{unlink_trailer}
				{reset_manual_control}
				
				{if not tagged "emit_label"		
					{damage_report "crew" "leave"}
					{tags add "emit_label"}
					{crew_emit}
				}
				{delay 1		
					{crew_emit}
				}
				{delay 2		
					{crew_emit}
				}
				{delay 3		
					{crew_emit}
				}
				;{call "burn_emit"}
				
				{delay 4	{if operatable {tags remove "emit_label"}}}
				{delay 6	{if operatable {tags remove "emit_label"}}}
				{delay 8	{if operatable {tags remove "emit_label"}}}
				{delay 10	{if operatable {tags remove "emit_label"}}}
				{delay 12	{if operatable {tags remove "emit_label"}}}
				{delay 14	{if operatable {tags remove "emit_label"}}}
	
				{delay 15
					{if not operatable
						{tags add "abandoned"}
						{set "broken" 1}
						{able select 0}
						{able repaired 0}
						{explosive 1}
						{player -1}
						{stat_notify leave}
						{kick_entity_manager}
						{explosive 1}
						{damage_report "body" "empty"}
						{damage_report "trackright" "empty"}
						{damage_report "trackleft" "empty"}
						{damage_report "gun" "empty"}
						{damage_report "turret" "empty"}
						{damage_report "engine" "empty"}
						
						{delay 3 1					
							{explosive 0}
							{tags add "destroyed"}
							{call "explosion"}
						}
					}
				}			
			}
		}
	}

	(define "terrain_fx"
		{on terrain_fx %0 enter
			{view start "on_%1"}
			{view start "on_%1_time_short"}
			{delay 0.1
				{view pause "on_%1_time_short"}
			}
		}
		{on terrain_fx %0 leave
			{view pause "on_%1"}
		}
	)
	("terrain_fx" args "ground"			ground)
	("terrain_fx" args "sand"			sand)
	("terrain_fx" args "grass" 			grass)
	("terrain_fx" args "water" 			water)
	("terrain_fx" args "shallow_water" 	puddle)
	("terrain_fx" args "puddle"			puddle)
	("terrain_fx" args "mud"			mud)
	("terrain_fx" args "country_road"	country_road)
	("terrain_fx" args "snow"			snow)

	{on "explosion_delete"
		{set "delete_parts" 1}
		{call "explosion"}
		{delay 20
			{hide 3}
		}
	}
	{on "contact_disable"	; for triggers
		{volumes disable contact}
	}
	(define "talk_target"
		{on "talk_target_%0"
			{if effector "human" or effector "cannon"
				{with_effector
					{talk "human_target_%0"}
				}
			else
				{with_effector
					{talk "tank_target_%0"}
				}
			}
		}
	)
	("talk_target" args broke_engine)
	("talk_target" args broke_turret)
	("talk_target" args broke_gun)
	("talk_target" args broke_track)
	("talk_target" args pierced)
	("talk_target" args bullet_reflected)
	
	("talk_target" args destroyed_cannon)
	("talk_target" args destroyed_mgun)
	("talk_target" args destroyed_tank)
	("talk_target" args destroyed_mortar)
	("talk_target" args destroyed_armored_car)
	("talk_target" args destroyed_car)
	{on "destroyed_by_spy"
		{##if not flag "destroyed_by_spy"
			{if effector "human"
				{with_effector
					{if breed_mask "*/saboteur*" "*/scout" "*/sniper_elite" "*/nkvd*" "*/brandenburger*"
						{with_effector
							{tags add "destroyed_by_spy"}
							{talk "destroyed_by_spy" {audience all}}
							{delay 1
								{spawn "scout_actor"	{delay 30 {delete}}}
							}
						}
					}
				}
			}
		}
	}
	{on "check_talk_target_broke_component"
		(define "check_talk_target_broke_component"
			{if component "%0"
				{call "talk_target_broke_%0"}
			}
		)
		{if component "trackright" or component "trackleft"
			{call "talk_target_broke_track"}
		}
		("check_talk_target_broke_component" args engine)
		("check_talk_target_broke_component" args turret)
		("check_talk_target_broke_component" args gun)
	}
	{on "report_unable_move_reason"
		{if not work "trackleft" or not work "trackright"
			{talk "tank_track_broken"}
		else not work "engine"
			{talk "tank_engine_broken"}
		else not need_fuel
			{talk "tank_need_more_crew"}
		}
	}
	{on "bullet_hit_obstacle"
		{talk "tank_bullet_hit_obstacle"}
	}
	{on "executing_order_weapon_fire"
		{if not effector ; target - ground
			{if weapon_fire_mode "non_stop" ; once short_burst long_burst smart_burst
				{if aim_mode "attack_ground_forced"  ; default anti_airborne attack_ground_forced
					{talk "tank_executing_order_weapon_fire_barrage"}
				else
					{talk "tank_executing_order_weapon_fire_non_stop_ground"}
				}
			}
		}
	}
	{on "enemy_observed"
		{talk "tank_enemy_observed" {audience ally}}
	}
	{on "report_repairer_fail"
		{talk "tank_repairer_fail"}
	}
	{on "smoke_destroyed" ;for *.mi
		{spawn "smoke_on_map_med_temp"}
	}
	
	{on "trailer_link"
		{play_sound "trailer_link"}
	}
	{on "detach"
		{play_sound "detach"}
	}
	("action_play_sound_and_check_stop" action(round_sandbag)			delay_next_sound(2))			;{on "round_sandbag...
	("action_play_sound_and_check_stop" action(camouflage)				delay_next_sound(2))			;{on "camouflage...
	("action_play_sound_and_check_stop" action(build_supp_point)		delay_next_sound(3))			;{on "build_supp_point...
	{on "test_damage"
		{armor_health_damage 50}
		{if armor_health 1 and not flag "broken"
			{call "mp_destroy"}
		}
	}
	{on pierce
		{if stuff "bzt"
			{fire radius 0.5 time 1.5 heating 2}
			{if component "engine"
				{if rand 0.05
					{call "_burn"}	
				}
			}
		}
	}
}

{"emit_on_sink vehicle"
	{on operatable on
		{delay 0.3 "start_check_sinking"
			{call "check_sinking"}
		}
	}
	{on operatable off
		{kill_delay "start_check_sinking"}
		{kill_delay "check_sinking"}
	}
	(define "sink_terrain"
		{on terrain_pp "%0" enter
			{reset_manual_control}
			{able "sinking" 1}
		}
		{on terrain_pp "%0" leave
			{reset_manual_control}
;			{able "sinking" 0} ;do not use this because of leaving terrain on stop
		}
	)
;	("sink_terrain" args water)
	("sink_terrain" args swamp)
	{on "check_sinking"
		{call "check_water_level"}
		{if able "sinking"
			{reset_manual_control}
			{able select 0}
			{able repaired 0}
			{unlink_trailer}
			{tags add "destroyed"}
		}
		{delay 5.0 "check_sinking"
			{call "check_sinking"}
		}
	}
	{on "check_water_level"
		{if water_level 1.2
			{able "sinking" 1}
		}
	}
	{on "crew_emit"
		{crew_emit}
	}
}

(define "with_gun"
{"with_gun%n vehicle"
	{on spawn
		{call "update_gun"}
		{set "with_gun" 1}
	}
	{on break
		{if component "gun%n"
			{call "update_gun"}
			{tags add "gun%n_brake"}
		}
	}
	{on repair
		{if component "gun%n"
			{call "update_gun"}
			{tags remove "gun%n_brake"}
		}
	}
	{on "update_gun"
		{if work "gun%n"
			{weapon_work "gun%n" 1}
		else
			{weapon_work "gun%n" 0}
		}
	}
}
)
("with_gun" n())
("with_gun" n(2))
("with_gun" n(3))
("with_gun" n(s));for calliope

{"open_with_land"
	{on "open"
		{ani_stop "drift"}
		{ani_play "dooropen" callback}
		{land on}
		{chassis_work 0}
		{physics_work 0}
		{area enable}
	}
	{on "close"
		{ani_play "dooropen" -1 callback}
		{ani_play "drift" loop}
		{land off}
		{chassis_work 1}
		{physics_work 1}
		{area disable}
	}
	{on animation_end "dooropen"
		{update_visibility_patch}
	}
}

{"open_without_land"
	{on "open"
		{ani_stop "drift"}
		{ani_play "dooropen" callback}
	}
	{on "close"
		{ani_play "dooropen" -1 callback}
		{ani_play "drift" loop}
	}
	{on animation_end "dooropen"
		{update_visibility_patch}
	}
}

{"amphibia vehicle"
	{on spawn
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center1"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center2"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center3"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center4"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center5"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center6"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center7"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center8"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center9"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center10"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_norm_front1"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_norm_front2"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_norm_engine1"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center1"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center2"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center3"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center4"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center5"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center6"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center7"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center8"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center9"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center10"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_back1"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_back2"}
		{add_view	"wash_front_small"	"on_move"	"FX_bulb_small_front1"}
		{add_view	"wash_front_small"	"on_move"	"FX_bulb_small_front2"}
		{add_view	"wash_front_norm"	"on_move"	"FX_bulb_norm_front1"}
		{add_view	"wash_front_norm"	"on_move"	"FX_bulb_norm_front2"}
		{add_view	"wash_ship_motion_norm"	"on_move"	"FX_bulb_norm_front1"}
		{add_view	"wash_ship_motion_norm"	"on_move"	"FX_bulb_norm_front2"}
		{add_view	"wash_engine_small"	"on_move"	"FX_bulb_small_engine1"}
		{add_view	"wash_engine_norm"	"on_move"	"FX_bulb_norm_engine1"}
	}
	{on terrain_pp "deep_water" enter
		{set "in_water" 1}
		{call "update_bulbs"}
	}
	{on terrain_pp "water" enter
		{set "in_water" 1}
		{call "update_bulbs"}
	}
	{on terrain_pp "shallow_water" enter
		{set "in_water" 1}
		{call "update_bulbs"}
	}
	{on terrain_pp "shallow_water" leave
		{set "in_water" 0}
		{call "update_bulbs"}
	}
	{on "update_bulbs"
		{if flag "in_water"
			{if not velocity 0.001
				{view start "on_stead"}
				{view pause "on_move"}
			else
				{view start "on_move"}
				{view pause "on_stead"}
			}
		else
			{view pause "on_stead"}
			{view pause "on_move"}
		}
	}
	{on "check_water_level" overload}
	{on move on
		{call "update_bulbs"}
	}
	{on move off
		{call "update_bulbs"}
	}
}
{"can_destroyed_one_shot"; for missions
	{on "destroyed_one_shot"
		{if ammo "shell" and tagged "can_destroyed_one_shot"
			{call "explosion"}
		}
	}
	{on pierce
		{call "destroyed_one_shot"}
	}
	{on blast
		{call "destroyed_one_shot"}
	}
}
{"smoke_mortars"
	(define "smoke_shot"
		("spawn_grenade_smoke" bone(shooter00))
		("spawn_grenade_smoke" bone(shooter03))
	)
	(define "spawn_grenade_smoke"
		{spawn "grenade_smoke" "%bone" x
			{impulse up 4 1 forward 12 1 rnd_dir 1.5 com}
			{call "add_smoke"}
			{call "onThrow"}
			{call "activate"}
		}
	)
	{on "smoke_shot"
		{if inventory_item "tank_smoke grenade"
			{delay 0.1
				("smoke_shot")
			}
		}
	}
}

{"crate_exp"
	{on "__explosion" overload
		{volumes disable all}
		{spawn "wood_detonate_small" "basis"}{fragments c4 2 r0 2 r1 5}
		{delete}
	}
}