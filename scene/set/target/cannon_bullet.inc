{selector
	{type "cannon_bullet"};стационарные пулемётные установки под патрон винтовочного калибра
	{group
		{ignore {class airborne}}		
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
