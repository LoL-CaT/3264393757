{selector
 	{type "car_bazooka"}; машинки, вооружённые только противотанковым гранатомётом
	{group
		{ignore {class human}}
		{ignore {class airborne}}
		{ignore {class house}}
		{select {in_range 32} {accessible}}
		{sort {class tank}}
		{sort {class light_tank}}		
		{sort {class armoredcar}}
		{sort {class car}}		
		{sort {class cannon}}
		{sort {class cannon_howitzer}}
		{sort {class cannon_tower}}			
		{sort distance}		
	}

	{group
		{select}
		{sort {class tank}}
		{sort {class light_tank}}		
		{sort {class armoredcar}}
		{sort {class car}}		
		{sort {class cannon}}
		{sort {class cannon_howitzer}}
		{sort {class cannon_tower}}			
		{sort distance}			
	}
}

