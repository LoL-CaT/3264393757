; this selects not an animation, but throw type - this will be checked later in as condition
; forward - throw by swing near head
; side - throw by side swing
; force - throw with effort
; mega - throw with great effor
{grenade_throw_type
	{if cover_type "snipe_cover"
		{type "forward"}
	}
	{if item_in_hand "m24" "f1" "mk1" "m39" "m61"	; light frag grenades
		{if throwing_range 0 5 
			{type "forward"}
		}
		{if throwing_range 5 10
			{type "side"}
		}
		{if throwing_range 10 20
			{type "force"}
		}
		{type "mega"}
	}
	{if item_in_hand "rpg40" "rpg43" "pwm1"	; anti-tank grenades
		{if throwing_range 0 10
			{type "side"}
		}
		{type "mega"}
	}
	{if item_in_hand "m24x5" 	; pack of grenades
		{if throwing_range 0 5
			{type "side"}
		}
		{type "mega"}
	}
	{if item_in_hand "molotov_coctail" 	; bottle
		{type "side"}
	}
	{type "side"}
}