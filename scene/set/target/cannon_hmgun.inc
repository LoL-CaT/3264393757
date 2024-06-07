{selector
  {type "cannon_hmgun"};стационарные пулемётные установки под патрон 12-15мм
	{group
		{ignore {class airborne}}		
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
