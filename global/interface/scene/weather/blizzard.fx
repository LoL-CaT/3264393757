;SDL
{weatherfx snow
	{stage air "$/smoke/smoke_white01.ebm"
		{visibility 0.075 0.025
						{peak
							{min 0}
							{max 0.0075 0.0025}
						}
					}
		{scale 1
						{npower
							{min 2 0.5}
							{max 4.75 0.75}
							{pow 0.6 0.2}
						}
					}
		{preturn 180 180}
		{turn 1
						{npower
							{min 0}
							{max 0 240}
							{pow 1}
						}
					}
		{timer
			{mode play loop}
			{duration 1.5}
		}
	}
}
