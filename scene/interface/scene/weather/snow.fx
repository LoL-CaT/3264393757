;SDL
{weatherfx snow
	{stage air "$/particle/snow.ebm"
		{visibility 0.8 0.2}
		{scale 0.3 0.1}
		{preturn 90 90}
		{turn
			{linear
				{min 90 90}
				{max 0 360}
			}
		}
		{timer
			{mode play loop}
			{duration 1}
		}
	}
}
