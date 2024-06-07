{selector
	{unit "human" "sniper"};хуман с sniper weapon
	{group
		{select {in_range 20} {accessible}}	
		{ignore {not class human}}	
		{sort	{weapon "bullet"}}
		{sort	{weapon}}
		{sort	distance}
	}
	{group
		{select {accessible}}	
		{sort	{weapon "bullet"}}
		{sort	{weapon}}
		{sort	distance}
	}	
}