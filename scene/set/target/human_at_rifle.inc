{selector
	{unit "human" "at_rifle"};хумана с at_rifle weapon
	{group
		{ignore {class airborne}}	
		{select {in_range 70} {accessible}}	
		{sort {class armoredcar}}
		{sort {class car}}		
		{sort {class light_tank}}
		{sort {class tank}}
		{sort {class cannon}}
		{sort {class cannon_howitzer}}
		{sort {class human}}	
		{sort {class house}}		
		{sort {attacking}}
		{sort distance}
    }
}