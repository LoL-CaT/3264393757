{selector
	{unit "human" "ap"};хумана с ap weapon
	{group
;		{ignore {class human}}
		{ignore {class airborne}}		
		{select {in_range 20}}	
		{sort {class tank}}
		{sort {class light_tank}}		
		{sort {class armoredcar}}
		{sort {class car}}
		{sort {class cannon}}
		{sort {class cannon_howitzer}}
		{sort {class cannon_tower}}
		{sort {class house}}		
		{sort {attacking}}
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
		{sort {class house}}		
		{sort {attacking}}
		{sort distance}
    }	
}