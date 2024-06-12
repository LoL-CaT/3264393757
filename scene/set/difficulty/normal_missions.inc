{any
	{ai_damage 0.5}        ; modifier for damage from ai to ai units
	(include "blast.inc")
	{cover_mgun_accuracy 1}	; additionally increase accuracy of soldier with mgun in horizontal cover
	{cover_mgun_burst 3}	; increase bullet count in 1 burst of soldier with mgun in horizontal cover
	{cover_mgun_delay 0.2}	; decrease timeout between bursts of soldier with mgun in horizontal cover
	{vehicle_burst 1.5}		; increase timeout between bursts for all vehicles
}
{enemy
	{health 0.4}  				
	{accuracy 0.5}				
	{burst 0.85}
	{cover_damage 1}  			; damage when protected by cover
	{cover_hitchance 1}		; hit chance when protected by cover
	{crawl_hitchance 1}		; hit chance for prone soldier
	{firing_timeout 1.5}		
	{grenade_timeout 2.0}
	{mounted_mgun 3}			; accuracy modifier for mguns mounted on tanks
}
{ally
	{translate_damage 5}		; damage translation output modifier
	{accuracy 2}	
	{health 0.4}					; health increase
	{health_increase 1				; health regeneration
		{if tags "med_point_crew" 25}		
	}
	{burst 0.8}
	{cover_damage 0.3}
	{cover_hitchance 1}
	{crawl_hitchance 1}
	{mounted_mgun 5}
}
{neutral
	{health 0.4}
	{accuracy 0.2}
}
(include "multiplayer.inc")
