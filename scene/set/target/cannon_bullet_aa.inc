{selector
 	{type "cannon_bullet_aa"};стационарные пулемётные установки ПВО под патрон винтовочного калибра
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
		{sort {class human}} 
		{sort {class car}}
		{sort {class house}}
		{sort {class cannon}}
		{sort {class cannon_howitzer}}
		{sort {class cannon_tower}}	
		{sort {weapon "fg"}}
		{sort {weapon "ap"}}
		{sort {weapon}}
		{sort distance}		
	}
}
{selector
	{type "cannon_bullet_aa"}; стационарные пулемётные установки ПВО под патрон винтовочного калибра
	{group 
		{select {class airborne}}		
		{sort {weapon "bomb"}}
		{sort {weapon "mrl"}}
		{sort {weapon "fg"}}
	}	
	{group	
		{select {in_range 25}} 	 	
		{sort {class human}} 
		{sort {class car}}
		{sort {class house}}
		{sort {class cannon}}
		{sort {class cannon_howitzer}}
		{sort {class cannon_tower}}	
		{sort {weapon "fg"}}
		{sort {weapon "ap"}}
		{sort {weapon}}
		{sort distance}
	}
	{group
		{select} 		
		{sort {class human}} 
		{sort {class car}}
		{sort {class house}}
		{sort {class cannon}}
		{sort {class cannon_howitzer}}
		{sort {class cannon_tower}}	
		{sort {weapon "fg"}}
		{sort {weapon "ap"}}
		{sort {weapon}}
		{sort distance}
	}
}
