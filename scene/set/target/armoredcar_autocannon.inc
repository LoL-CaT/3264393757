{selector
 	{type "armoredcar_autocannon"}; бронеавтомобиль или бтр с автопушкой
	{group
		{ignore {class airborne}}		
		{select {in_range 25} {accessible}}
		{sort {class human}}
		{sort {weapon "ap"}}	
		{sort {weapon "fg"}}		
	}	
	{group
		{select {in_range 50} {accessible}}
		{sort {class light_tank}}
		{sort {class armoredcar}}		
		{sort {class car}}
		{sort {class human}}		
		{sort {class cannon}}
		{sort {class cannon_howitzer}}
		{sort {class cannon_tower}}			
		{sort {class house}}
		{sort {class tank}}		
		{sort distance}
	}
	{group
		{select {in_range 100} {accessible}}
		{sort {class light_tank}}
		{sort {class armoredcar}}		
		{sort {class car}}	
		{sort {class cannon}}
		{sort {class cannon_howitzer}}
		{sort {class cannon_tower}}	
		{sort {class human}}			
		{sort {class house}}
		{sort {class tank}}		
		{sort distance}
	}
	{group
		{select}	
		{sort {class light_tank}}
		{sort {class armoredcar}}		
		{sort {class car}}
		{sort {class cannon}}
		{sort {class cannon_howitzer}}
		{sort {class cannon_tower}}	
		{sort {class human} {weapon}}
		{sort {class human}}			
		{sort {class house}}
		{sort {class tank}}		
		{sort distance}
	}	
}
