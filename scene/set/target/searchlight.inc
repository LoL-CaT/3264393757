{selector
	{type "searchlight"};прожектор, которым аггром освещает цель
	{group
		{select {in_range 50}}	
		{sort {class airborne}}	
		{sort {class human}}	
		{sort {class tank}}
		{sort {class light_tank}}			
		{sort {class armoredcar}}
		{sort {class car}}
		{sort {class cannon}}
		{sort {class cannon_howitzer}}
		{sort {class cannon_tower}}	
		{sort {class house}}			
	}
	{group	
		{select}		
		{sort {class airborne}}	
		{sort {class human}}	
		{sort {class tank}}
		{sort {class light_tank}}			
		{sort {class armoredcar}}
		{sort {class car}}
		{sort {class cannon}}
		{sort {class cannon_howitzer}}
		{sort {class house}}			
	}	
	{group		
		{sort time_to_aim}
	}	
}