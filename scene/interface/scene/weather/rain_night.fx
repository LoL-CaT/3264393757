;SDL
{weatherfx rain
	{stage air "$/flash/rain_light.ebm"
		{timer
			{mode play}
			{duration 1.8}
		}
		{Light
			{Linear
				{min 0.25 0.1}
				{max 0.1}
			}
		}
		{preTurn 180}
		{ScaleX 0.4 0.15}
		{ScaleY 0.08 0.02}
	}
	{stage water "$/flash/ripples_w.ebm"
		{Visibility
			{Linear
				{min 0.9 0.2}
				{max 0}
			}
		}
		{Scale
			{Linear
				{min 0.1 0.05}
				{max 0.4 0.2}
			}
		}
		{timer
			{mode play}
			{duration 0.5}
		}
	}
	{stage ground "$/flash/ripples_w.ebm"
		{Visibility
			{Linear
				{min 0.9 0.2}
				{max 0}
			}
		}
		{Scale
			{linear
				{min 0}
				{max 0.2 0.05}
			}
		}
		{timer
			{mode play}
			{duration 0.2}
		}
	}
}
