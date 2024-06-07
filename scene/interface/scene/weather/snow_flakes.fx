;SDL
{weatherfx snow
	{stage air "$/particle/snowflake.ebm"
		{visibility 1.0 0.8}
		{scale 0.1 0.05}
		{preturn 90 90}
		{turn
			{linear
				{min 90 90}
				{max 0 360}
			}
		}
		{timer
			{mode play loop}
			{duration 3}
		}
	}
}
