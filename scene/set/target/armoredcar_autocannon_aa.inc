{selector
 	{type "armoredcar_autocannon_aa"};зенитный бронеавтомобиль с автопушкой
 	{aim_mode "anti_airborne"};в режиме пво	
	{group 
		{select {class airborne}}			
		{sort {weapon "bomb"}}
		{sort {weapon "mrl"}}
		{sort {weapon "fg"}}	
	}	
	{group 
		{select {class airborne}}			
		{select {in_range 100} {accessible}}		
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
{selector
 	{type "armoredcar_autocannon_aa"}; зенитный бронеавтомобиль с автопушкой
	{group
		{select {in_range 150} {linked "paratrooper_in_flight"}}
		{sort {class human}}			
		{sort distance}
	}
	{group
		{select {class airborne}}	 	
		{sort {weapon "bomb"}}
		{sort {weapon "mrl"}}
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
