{selector
	{type "cannon_mortar"};миномёты
	{group
		{ignore {class airborne}}	
		{select {in_range 100}}			
		{sort {class cannon}}
		{sort {class cannon_howitzer}}
		{sort {class cannon_tower}}	
		{sort {class human}}		
		{sort {class house}}
		{sort {class car}}		
		{sort {class armoredcar}}
		{sort {class light_tank}}
		{sort {class tank}}		
		{sort {weapon "fg"}}
		{sort {weapon}}	
		{sort distance}
	}	
	{group
		{select {in_range 250}}			
		{sort {class cannon}}
		{sort {class cannon_howitzer}}
		{sort {class cannon_tower}}	
		{sort {class human}}		
		{sort {class house}}
		{sort {class car}}		
		{sort {class armoredcar}}
		{sort {class light_tank}}
		{sort {class tank}}		
		{sort {weapon "fg"}}
		{sort {weapon}}	
		{sort distance}
	}
	{group
		{select}			
		{sort {class cannon}}
		{sort {class cannon_howitzer}}
		{sort {class cannon_tower}}	
		{sort {class human}}		
		{sort {class house}}
		{sort {class car}}		
		{sort {class armoredcar}}
		{sort {class light_tank}}
		{sort {class tank}}		
		{sort {weapon "fg"}}
		{sort {weapon}}
		{sort {attacking}}		
		{sort distance}
	}
}
