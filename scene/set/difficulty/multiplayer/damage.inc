	{translate_damage 1		; насколько умножается урон от blastwave
		{if in_fortification "trench" 0.9
			{if attacker ammo_tag "field" 0.9}
			{if attacker ammo_tag "damage_mortar" 1}			
			{if attacker ammo_tag "size2" 1}			
			{if attacker ammo_tag "size3" 1}
			{if attacker ammo_tag "size4" 1}			
		}
		{if in_house 0.9
			{if fsm_tags "squat squat-hide hold-back" 0.8
				{if attacker ammo_tag "dynamite" 1.5}
				{if attacker weapon "caliber100" 1}
			}
			{if attacker ammo_tag "dynamite" 1.5}
			{if attacker ammo_tag "grenade" 2.5}			
			{if attacker weapon "caliber100" 1}
		}
	}
	{translate_stun 1		; насколько умножается урон от shockwave
		{if in_fortification "trench" 0.5}
		{if in_house 0.5}
		{if cover_kind "vertical" "horizontal" "terrain" 0.5}
		{if cover_kind "bush" 1}		
		{if fsm_tags "down" 0.8}
	}
	{damage 1			; коэф. урона в бойца
		{if in_house 0.2
			{if attacker weapon "sniper" 1.5}		
			{if attacker weapon "gun" 0.5}				
		}
		;{if human and attacker human and in_fortification "trench" and attacker in_fortification "trench" 0.12
		;	{if fsm_tags "down" or fsm_tags "squat" 0.08}
		;}
		{if fsm_tags "squat" 1	
			{if attacker ammo_tag "fg" 0.75}	
		}	
		{if fsm_tags "down" 1
				{if attacker ammo_tag "fg" 0.5}		
		}
		{if cover_kind "vertical" "horizontal" "terrain" 0.5
			{if fsm_tags "down" 0.5		
				{if attacker ammo_tag "fg" 0.33}
			}		
		}	
	}		
	{damage_pierce 1}		; коэф. урона в бойца при проникающем попадании пули