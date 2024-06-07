{selector
 	{type "armoredcar_bullet_aa"};бронеавтомобили пво с орудием винтовчного калибра	
 	{aim_mode "anti_airborne"};в режиме пво 
	{group 
		{select {class airborne}}			
		{sort {weapon "bomb"}}
		{sort {weapon "mrl"}}
		{sort {weapon "fg"}}
	}	
	{group 
		{select {class airborne}}	
		{select {in_range 100}}		
		{sort {class car}}		
		{sort {class human}}
		{sort {class cannon}}
		{sort {class cannon_howitzer}}
		{sort {class cannon_tower}}			
		{sort {class house}}			
		{sort distance}	
	}
}
{selector
	{type "armoredcar_bullet_aa"};бронеавтомобили пво с орудием винтовчного калибра
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
