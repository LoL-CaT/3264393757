{any
	{ai_damage 1}        ; modifier for damage from ai to ai units
	(include "blast.inc")
}
{enemy
	{health 0.2}
	{accuracy 0.5}
	{burst 1}
	{firing_timeout 1}
	{grenade_timeout 1.5}
	{mounted_mgun 1}
}
{ally
	; {health_increase 1} {health_increase 2.5}
	{burst 0.9}
	{health 0.2}
	{mounted_mgun 1}
}
{neutral
;	{health 0.9}
	{accuracy 0.4}
}
(include "multiplayer.inc")

