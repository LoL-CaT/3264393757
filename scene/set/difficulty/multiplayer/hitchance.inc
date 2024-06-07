	{cover_hitchance 1		; веро€тность попадани€ в бойца за укрытием
		{if in_house 1
			{if fsm_tags "squat squat-hide hold-back" 1}
		}
	}		
	{hitchance 1	  			; веро€тность попадани€
		{if fsm_tags "squat" 1}	; веро€тность попадани€ в сид€чего бойца
		{if fsm_tags "down" 1}	; веро€тность попадани€ в лежачего бойца
		{if has_order "withdraw" 0.5}
	}
