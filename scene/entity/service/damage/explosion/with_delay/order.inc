	{tag "pointer_fleet_strike"}
	{NoGetShadows}
	{spriteview round
		{notifyowner}
		{sprite "/texture/fx/marker/marker04"
			{timer
				{mode play loop }
				{duration 9}
			}
			{scale 1
				{linear
					{min 0.35}
					{max 0.015}
				}
			}
			{turn 1
				{linear
					{min 0}
					{max 90}
				}
			}
			{highlight 0xffff0000}
		}
		{ground}
		{layer debug}
		{offset 0 0 5}
	}
	{spriteview top
		{notifyowner}
		{sprite "/texture/fx/ico/%sprite"
			{timer
				{mode play loop }
				{duration 1.5}
			}
			{scale 1
				{peak
					{min 0.3}
					{max 0.35}
				}
			}
			{visibility 1}
		}
		{layer debug}
		{offset 0 0 60}
	}
