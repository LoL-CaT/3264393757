{any
	(include "multiplayer/hitchance.inc")
	(include "multiplayer/damage.inc")
	(include "multiplayer/morale.inc")
	(include "multiplayer/firing_timeout.inc")
	(include "multiplayer/withdraw.inc")
	(include "multiplayer/reload_timeout.inc")
	{vehicle_burst 1}		; increase timeout between bursts for all vehicles
	{cover_mgun_burst 1}		; increase bullet count in 1 burst of soldier with mgun in horizontal cover
	{cover_mgun_delay 1}		; decrease timeout between bursts of soldier with mgun in horizontal cover
	(include "multiplayer/fragments.inc")
	{fragments_cover 2.2}        	; in cover from protected side
	{fragments_crawl 1.8}			; simply lying on the ground
	{fragments_crawl_prepared 2}	; lying on the ground & waiting for explosion
	{fragments_cover_prepared 2.5}	; in cover not from protected side, but waiting for explosion
	{fragments_squat 1.3}			; on the knees
	{mounted_mgun 1}
	{aim_range 1
		{if in_house 1.25
			{if weapon "rocketlauncher" 1.1}
			{if weapon "fg" 1.2}		
		}
	}
	{vision_range 1
		{if in_house 1.0}
	}
	{accuracy 1
		{if in_house 1.25}	
		{if tags "creep" and use_budget 0.5}
	}	
	{burst 1
		{if in_house 2}		
	}
	{health 0.2}
		{if tags "creep" and use_budget 0.5}
	}
	{health_increase 0.1
		{if tags "med_point_crew" 25}
		{if withdrawn_recovering 10}
	}
}