;SDL
{weatherfx snow
	{stage air "$/smoke/smoke_turb2.ebm"
		{visibility
			{peak
				{min 0}
				{max 0.25 0.1}
			}
		}
		{scale 2.1 1.4}
		{preturn -180 180}
		{turn
			{linear
				{min 0 0}
				{max -30 -50}
			}
		}
		{timer
			{mode play loop}
			{duration 1}
		}
	}
}
