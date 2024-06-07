{selector
 	{type "cannon_howitzer"}; гаубицы, вооружённые только фугасным снарядом
	{group
		{ignore {class airborne}}		
		{select {in_range 50}}
		{sort {class tank}}
		{sort {class light_tank}}		
		{sort {class armoredcar}}
		{sort {class car}}		
		{sort {class cannon}}
		{sort {class cannon_howitzer}}
		{sort {class cannon_tower}}	
		{sort {class house}}
		{sort {weapon "sniper"}}			
		{sort {class human}}		
		{sort distance}		
	}	
	{group
		{select}	
		{sort {class cannon_howitzer}}
		{sort {class cannon_tower}}
		{sort {class cannon}}
		{sort {class house}}
		{sort {weapon "sniper"}}			
		{sort {class human}}		
		{sort {class tank}}
		{sort {class light_tank}}		
		{sort {class armoredcar}}
		{sort {class car}}					
		{sort distance}	
	}	
	{group
		{sort {attacking}}
		{sort distance}
	}
}

