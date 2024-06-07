{selector
 	{type "armoredcar_flame"}; бронеавтомобиль или бтр с огнемётом
	{group
		{ignore {class airborne}}		
		{select {in_range 15}}
		{sort {class human}}
		{sort {class house}}		
		{sort {class light_tank}}
		{sort {class armoredcar}}		
		{sort {class car}}
		{sort {class cannon}}
		{sort {class cannon_howitzer}}
		{sort {class cannon_tower}}	
		{sort {class human} {weapon}}			
		{sort {class tank}}			
		{sort {weapon "ap"}}		
	}	
	{group	
		{select {in_range 50}}
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
