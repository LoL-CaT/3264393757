{selector
	{type "moto"};мотоцикл с пулемётом под патрон винтовочного калибра
	{group
		{ignore {class airborne}}
		{select {in_range 25}} 	
		{sort {class human} {weapon "ap"}}
		{sort {class human} {weapon}}
		{sort {class car}}
		{sort {class cannon}}
		{sort {class cannon_howitzer}}
		{sort {class cannon_tower}}	
		{sort {class house}}		
		{sort time_to_aim}
	}
	{group
		{select} 		
		{sort {class human} {weapon "ap"}}
		{sort {class human} {weapon}}
		{sort {class car}}
		{sort {class cannon}}
		{sort {class cannon_howitzer}}
		{sort {class cannon_tower}}		
		{sort {class house}}		
		{sort time_to_aim}
	}	
}