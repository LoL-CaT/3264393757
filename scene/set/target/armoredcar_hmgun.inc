{selector
 	{type "armoredcar_hmgun"}; бронеавтомобиль или бтр с пулемётом 12-14мм или пт ружьём
	{group
		{ignore {class airborne}}		
		{select {in_range 25}}
		{sort {class human}}
		{sort {weapon "ap"}}		
	}	
	{group	
		{select {in_range 50}}
		{sort {class human}}			
		{sort {class light_tank}}
		{sort {class armoredcar}}		
		{sort {class car}}
		{sort {class cannon}}
		{sort {class cannon_howitzer}}
		{sort {class cannon_tower}}				
		{sort {class house}}
		{sort {class tank}}		
		{sort distance}
	}
	{group
		{select{in_range 100}}
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
		{sort {class human}}			
		{sort {class house}}
		{sort {class tank}}		
		{sort distance}
	}	
}
