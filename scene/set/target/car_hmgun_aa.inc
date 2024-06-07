{selector
 	{type "car_hmgun_aa"}; зенитный автомобиль с пулемётом калибра 12-14мм
 	{aim_mode "anti_airborne"};в режиме пво	
	{group 
		{select {class airborne}}			
		{sort {weapon "bomb"}}
		{sort {weapon "mrl"}}
		{sort {weapon "fg"}}	
	}	
	{group 
		{select {class airborne}}		
		{select} 	
		{sort {class car}} 
		{sort {class armoredcar}}
		{sort {class human}}	
		{sort {class house}}
		{sort {class cannon}}
		{sort {class cannon_howitzer}}
		{sort {class light_tank}}		
		{sort {weapon "fg"}}
		{sort {weapon "ap"}}
		{sort {weapon}}
		{sort distance}		
	}
}
{selector
 	{type "car_hmgun_aa"}; зенитный автомобиль с пулемётом калибра 12-14мм
	{group 
		{select {class airborne}}		
		{sort {weapon "bomb"}}
		{sort {weapon "mrl"}}
		{sort {weapon "fg"}}	
	}	
	{group	
		{select {in_range 35}} 	
		{sort {class car}} 
		{sort {class armoredcar}}
		{sort {class human}}	
		{sort {class house}}
		{sort {class cannon}}
		{sort {class cannon_howitzer}}
		{sort {class light_tank}}		
		{sort {weapon "fg"}}
		{sort {weapon "ap"}}
		{sort {weapon}}
		{sort distance}
	}
	{group
		{select} 	
		{sort {class car}} 
		{sort {class armoredcar}}
		{sort {class human}}	
		{sort {class house}}
		{sort {class cannon}}
		{sort {class cannon_howitzer}}
		{sort {class light_tank}}		
		{sort {weapon "fg"}}
		{sort {weapon "ap"}}
		{sort {weapon}}
		{sort distance}
	}	
}