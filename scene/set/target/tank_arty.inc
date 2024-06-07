{selector
	{type "tank_arty"}; танк, вооружённый фугасницей для борьбы с артиллерией
	{group
		{ignore {class airborne}}
		{select 	{in_range 25}}			
		{sort {class tank}}		
		{sort {class human}}			
		{sort {weapon "ap"}}
		{sort distance}
	}
	{group
		{select	{in_range 60}}
		{sort {class cannon_howitzer}}
		{sort {class cannon_tower}}	
		{sort {class cannon}}
		{sort {class tank}}			
		{sort {class light_tank}}				
		{sort {class armoredcar}}
		{sort {class car}}	
		{sort {class house}}
		{sort distance}
	}		
	{group	
		{select}	
		{sort {class cannon_howitzer}}
		{sort {class cannon_tower}}	
		{sort {class cannon}}
		{sort {class tank}}			
		{sort {class house}}
		{sort {class human}}				
		{sort {class light_tank}}				
		{sort {class armoredcar}}
		{sort {class car}}				
		{sort {weapon "ap"} {attacking} {class tank}}
		{sort {weapon "ap"} {attacking}}
		{sort {weapon "ap"} {threating} {class tank}}
		{sort {weapon "ap"} {threating}}
		{sort {weapon "ap"} {class tank}}
		{sort {weapon "ap"}}
		{sort {weapon "fg"} {attacking}}
		{sort {weapon "fg"} {threating}}
		{sort {weapon "fg"}}
		{sort distance}

	}
}
