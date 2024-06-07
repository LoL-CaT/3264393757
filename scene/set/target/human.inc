{selector
	{unit "human"}; базовые параметры для хумана
	{group
		{ignore {class airborne}}	
		{select {in_range 20}}
		{sort {class car}}	
		{sort {class armoredcar}}	
		{sort {class tank}}			
		{sort {class human} {weapon "bullet"}}
		{sort {class human} {weapon}}		
		{sort {class human}}	
		{sort {class cannon}}
		{sort {class cannon_howitzer}}
		{sort {class cannon_tower}}	
		{sort {class house}}		
		{sort {weapon}}
		{sort {attacking}}		
		{sort distance}
	}
	{group
		{ignore {class airborne}}		
		{select}			
		{sort {class human} time_to_aim}		
		{sort {class human} {weapon "bullet"}}
		{sort {class human} {weapon}}		
		{sort {class human}}
		{sort {class car}}		
		{sort {class cannon}}
		{sort {class cannon_howitzer}}
		{sort {class cannon_tower}}
		{sort {class house}}		
		{sort {weapon}}
		{sort {attacking}}		
		{sort distance}
	}
	{group
		{sort distance}
		{sort {attacking}}		
	}
}