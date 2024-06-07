{selector
 	{type "cannon_shell_aa"}; зенитные пушки, стреляющие снарядами и одиночным выстрелом
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
		{sort {class tank}}
		{sort {class light_tank}}		
		{sort {class armoredcar}}
		{sort {class car}}
		{sort {class cannon_howitzer}}
		{sort {class cannon_tower}}		
		{sort {class cannon}}	
		{sort {weapon "sniper"}}		
		{sort {class house}}
		{sort {class human}}		
		{sort {weapon "fg"}}		
		{sort distance}	
	}
}
{selector
 	{type "cannon_shell_aa"}; зенитные пушки, стреляющие снарядами и одиночным выстрелом
	{group 
		{select {class airborne}}		
		{sort {weapon "bomb"}}
		{sort {weapon "mrl"}}
		{sort {weapon "fg"}}		
	}
	{group	
		{select {in_range 25} {accessible}}
		{sort {class tank}}
		{sort {class light_tank}}		
		{sort {class armoredcar}}
		{sort {class car}}	
		{sort {class human}}		
		{sort {class cannon_howitzer}}
		{sort {class cannon_tower}}		
		{sort {class cannon}}	
		{sort {class house}}		
		{sort {weapon "fg"}}
		{sort distance}		
	}		
	{group
		{select {in_range 150} {accessible}}
		{sort {class tank}}
		{sort {class light_tank}}		
		{sort {class armoredcar}}
		{sort {class car}}
		{sort {class cannon_howitzer}}
		{sort {class cannon_tower}}		
		{sort {class cannon}}	
		{sort {weapon "sniper"}}		
		{sort {class house}}
		{sort {class human}}		
		{sort {weapon "fg"}}
		{sort distance}		
	}	
	{group
		{select}	
		{sort{class cannon_howitzer}}			
		{sort {class cannon}}	
		{sort {class tank}}
		{sort {class light_tank}}			
		{sort {class armoredcar}}
		{sort {class car}}
		{sort {weapon "sniper"}}			
		{sort {class house}}
		{sort {class human}}			
		{sort {weapon "fg"}}
		{sort {weapon}}
		{sort distance}
	}
}
