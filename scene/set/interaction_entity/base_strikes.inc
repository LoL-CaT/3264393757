(define "contusion_srike"
	{delay 0.1
		{call "check_access_to_contusion"}
		{if flag "access_to_contusion"
			{call "%name"}
			{icon_event "contusion" (* %time %k)}
			{kill_delay "contusion"}
			{delay (* %time %k 0.8) "contusion"
				{call "contusion_off"}
			}
		}
	}
)
(define "contusion_turret"
	{if operatable
		{if rand (* %hit_turret_contusion %koef)
			("contusion_srike" name(contusion_on_turret) time(%crew_shock_time) k(%koef))
		}
	}
)
(define "contusion_body"
	{if operatable
		{if rand (* %hit_body_contusion %koef)
			("contusion_srike" name(contusion_on_body) time(%crew_shock_time) k(%koef))
		}
	}
)
(define "damage_turret"
	{if rand (* %hit_turret_brake %koef)	{call "turret_broken"}}
)
(define "damage_engine"
	{if rand (* %hit_engine_brake %koef)	{call "engine_broken"}}
)
(define "damage_crew_strike"
	{##kill_crew_by_weapon
		{weapon ""}
		{max_kill %max_kill}
		{place "charger" (* %kill_crew_prob %koef)}
		{place "charger2" (* %kill_crew_prob %koef)}
		{place "gunner" (* %kill_crew_prob %koef)}
		{place "driver" (* %kill_crew_prob %koef)}
		{place "commander" (* %kill_crew_prob %koef)}
		{place "gunner2" (* %kill_crew_prob %koef)}
		{place "gunner3" (* %kill_crew_prob %koef)}
		{place "gunner4" (* %kill_crew_prob %koef)}
	}
)
(define "damage_crew_turret"
	("damage_crew_strike" kill_crew_prob(%hit_turret__kill_crew) max_kill(%max_kill) koef(%koef))
)
(define "damage_crew_body"
	("damage_crew_strike" kill_crew_prob(%hit_body__kill_crew) max_kill(%max_kill) koef(%koef))
)
(define "damage_process_bullet_stuck"
	{if relation "enemy" or relation "neutral"
		{if component "body"
		    {ani_play "hit"}
			{damage_report "body" "strike"}
			{if armor_health_percent 0.1
				("damage_engine" hit_engine_brake(%hit_engine_brake_prob) koef(1))
				("contusion_body" hit_body_contusion(%hit_body_contusion_prob) crew_shock_time(%c_time) koef(1))
				("damage_crew_body" hit_body__kill_crew(%hit_body__kill_crew_prob) max_kill(%max_kill) koef(1))
				{armor_health_damage_part (* %health_damage_part 1.7)}
			else armor_health_percent 0.5
				("damage_engine" hit_engine_brake(%hit_engine_brake_prob) koef(0.6))
				("contusion_body" hit_body_contusion(%hit_body_contusion_prob) crew_shock_time(%c_time) koef(0.75))
				("damage_crew_body" hit_body__kill_crew(%hit_body__kill_crew_prob) max_kill(%max_kill) koef(0.75))
				{armor_health_damage_part (* %health_damage_part 1.5)}
			else
				("damage_engine" hit_engine_brake(%hit_engine_brake_prob) koef(0.1))
				("contusion_body" hit_body_contusion(%hit_body_contusion_prob) crew_shock_time(%c_time) koef(0.5))
				("damage_crew_body" hit_body__kill_crew(%hit_body__kill_crew_prob) max_kill(%max_kill) koef(0.5))
				{armor_health_damage_part  (* %health_damage_part 1.0)}
			}
			{call "destroy_or_explosion"}
		else component "turret" or volume "mantlet" or volume "gun_rot"
			{damage_report "turret" "strike"}
			{if armor_health_percent 0.1
				("damage_turret" hit_turret_brake(%hit_turret_brake_prob) koef(1))
				("contusion_turret" hit_turret_contusion(%hit_turret_contusion_prob) crew_shock_time(%c_time) koef(1))
				("damage_crew_turret" hit_turret__kill_crew(%hit_turret__kill_crew_prob) max_kill(%max_kill) koef(1))
				{armor_health_damage_part (* %health_damage_part 1.5)}
			else armor_health_percent 0.5
				("damage_turret" hit_turret_brake(%hit_turret_brake_prob) koef(0.6))
				("contusion_turret" hit_turret_contusion(%hit_turret_contusion_prob) crew_shock_time(%c_time) koef(0.75))
				("damage_crew_turret" hit_turret__kill_crew(%hit_turret__kill_crew_prob) max_kill(%max_kill) koef(0.75))
				{armor_health_damage_part (* %health_damage_part 1.3)}
			else
				("damage_turret" hit_turret_brake(%hit_turret_brake_prob) koef(0.1))
				("contusion_turret" hit_turret_contusion(%hit_turret_contusion_prob) crew_shock_time(%c_time) koef(0.5))
				("damage_crew_turret" hit_turret__kill_crew(%hit_turret__kill_crew_prob) max_kill(%max_kill) koef(0.5))
				{armor_health_damage_part (* %health_damage_part 0.8)}
			}
			{call "destroy_or_explosion"}
		}
	}
)