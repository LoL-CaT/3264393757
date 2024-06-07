{selector
 	{type "cannon_hmgun_aa"};стационарные зенитные пулемётные установки ПВО под патрон 12-15мм
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
		{sort {class airborne}}	
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
	{type "cannon_hmgun_aa"};стационарные зенитные пулемётные установки под патрон 12-15мм
	{group 
		{select {class airborne}}		
		{sort {weapon "bomb"}}
		{sort {weapon "mrl"}}
		{sort {weapon "fg"}}
	}
	{group
		{select {in_range 35}}  
		{sort {class airborne}}	
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
		{sort {class airborne}}	
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

