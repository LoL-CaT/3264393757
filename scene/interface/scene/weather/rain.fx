;SDL
{weatherfx rain
	{stage air "$/flash/rain.ebm"
		{timer
			{mode play}
			{duration 1.8}
		}
		{Visibility
			{Linear
				{min 0.65 0.3}
				{max 0.2}
			}
		}
		{preTurn 180}
		{ScaleX 0.3 0.1}
		{ScaleY 0.18 0.05}
	}
	{stage water "$/flash/ripples_w.ebm"
		{Visibility
			{Linear
				{min 0.8 0.2}
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
				{min 0.8 0.2}
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
