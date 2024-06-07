{selector
	{unit "human" "bullet"};хуман с bullet weapon
	{group
		{ignore {class airborne}}	
		{select {in_range 20}}
		{sort	 {attacking}}
		{sort	 {class human} {weapon "bullet"}}
		{sort	 {class human} {weapon}}
		{sort	 {class human}}
		{sort	 {class car}}
		{sort  {class cannon}}
		{sort  {class cannon_howitzer}}		
		{sort	 {class house}}	
		{sort	 {threating}}
		{sort	 distance}
	}
	{group
		{select}	
		{sort	 {class human}}		
		{sort	 {class human} {weapon "bullet"}}
		{sort	 {class human} {weapon}}
		{sort  {class human} time_to_aim}		
		{sort	 {class car}}
		{sort  {class cannon}}
		{sort  {class cannon_howitzer}}			
		{sort	 {class house}}	
		{sort  distance}
	}	
}