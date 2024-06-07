{selector
 	{type "armoredcar_hmgun_aa"};зенитный бронеавтомбиль с пулемётом калибра 12-14мм
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
{selector
 	{type "armoredcar_hmgun_aa"}; зенитный бронеавтомбиль с пулемётом калибра 12-14мм
	{group
		{select {class airborne}}	
		{sort {weapon "bomb"}}
		{sort {weapon "mrl"}}
		{sort {weapon "fg"}}
	}
	{group	
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
