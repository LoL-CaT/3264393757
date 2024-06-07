{selector
 	{type "armoredcar_bullet"}; бронеавтомобиль или бтр с пулемётом винтовочного калибра
	{group
		{ignore {class airborne}}	
		{select {in_range 25}}
		{sort {class car}}		
		{sort {class human}}
		{sort {class cannon}}
		{sort {class cannon_howitzer}}
		{sort {class cannon_tower}}	
		{sort {class house}}
		{sort {weapon "fg"}}		
		{sort distance}
	}
	{group
		{select {in_range 50}}
		{sort {class car}}		
		{sort {class human}}
		{sort {class cannon}}
		{sort {class cannon_howitzer}}
		{sort {class cannon_tower}}			
		{sort {class house}}		
		{sort distance}
	}
	{group
		{select {in_range 100}}
		{sort {class car}}		
		{sort {class human}}
		{sort {class cannon}}
		{sort {class cannon_howitzer}}
		{sort {class cannon_tower}}			
		{sort {class house}}		
		{sort distance}
	}
	{group
		{select}	
		{sort {class car}}		
		{sort {class human}}
		{sort {class cannon}}
		{sort {class cannon_howitzer}}
		{sort {class cannon_tower}}			
		{sort {class house}}		
		{sort distance}
	}	
}
