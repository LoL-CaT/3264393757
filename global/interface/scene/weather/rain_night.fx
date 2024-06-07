;SDL
{weatherfx rain
	{stage air "$/particles/raindrop01.ebm"
		{timer
			{mode play}
			{duration 1.8}
		}
		{visibility 0.3 0.05}
		{preturn 270 5}
		{scalex 0.725 0.075}
					{scaley 0.05 0.01}
	}
	{stage water "$/water/water_circle02.ebm"
		{visibility 1
						{npower
							{min 0.3 0.05}
							{max 0}
							{pow 1}
						}
					}
		{scale 1
						{npower
							{min 0}
							{max 0.3 0.05}
							{pow 0.6}
						}
					}
					{preturn 180 180}
		{timer
						{mode play }
						{duration 0.425 0.075}
					}
	}
	{stage ground "$/water/water_circle02.ebm"
		{visibility 1
						{npower
							{min 0.35 0.05}
							{max 0}
							{pow 1}
						}
					}
		{scale 1
						{npower
							{min 0}
							{max 0.35 0.05}
							{pow 0.6}
						}
					}
		{preturn 180 180}
		{timer
						{mode play }
						{duration 0.5 0.1}
					}
	}
}
