;SDL
{weatherfx snow
	{stage air "$/particles/snowflake01.ebm"
		{visibility 0.3 0.05}
		{scale 0.08 0.02}
		{preturn 180 180}
		{turn 1
						{npower
							{min 0}
							{max 0 1500}
							{pow 1}
						}
					}
		{timer
			{mode play loop}
			{duration 1}
		}
	}
}
