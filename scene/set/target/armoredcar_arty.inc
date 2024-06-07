{selector
	{type "armoredcar_arty"}; бронеавтомобиль или бронетранспортёр, вооружённый фугасницей для борьбы с артиллерией
	{group
		{ignore {class airborne}}
		{select {in_range 25}}					
		{sort {class human}}			
		{sort {weapon "ap"}}
		{sort {weapon "fg"}}		
		{sort distance}
	}
	{group
		{select	{in_range 60}}
		{sort {class human}}		
		{sort {class cannon_howitzer}}
		{sort {class cannon_tower}}	
		{sort {class cannon}}
		{sort {class car}}			
		{sort {class light_tank}}				
		{sort {class armoredcar}}
		{sort {class house}}	
		{sort {class tank}}		
		{sort {weapon "ap"}}
		{sort {weapon "fg"}}
		{sort distance}
	}	
	{group
		{select 	{in_range 150}}
		{sort {class cannon_howitzer}}
		{sort {class cannon_tower}}	
		{sort {class cannon}}
		{sort {class house}}
		{sort {class human}}		
		{sort {class tank}}			
		{sort {class light_tank}}				
		{sort {class armoredcar}}
		{sort {class car}}			
		{sort {weapon "ap"}}
		{sort {weapon "fg"}}
		{sort distance}
	}	
	{group	
		{select}	
		{sort {class cannon_howitzer}}
		{sort {class cannon_tower}}	
		{sort {class cannon}}
		{sort {class house}}
		{sort {class human}}		
		{sort {class tank}}			
		{sort {class light_tank}}				
		{sort {class armoredcar}}
		{sort {class car}}				
		{sort {weapon "ap"}}
		{sort {weapon "fg"}}
		{sort distance}
	}
}
