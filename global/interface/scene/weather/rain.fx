;SDL
{weatherfx rain
	{stage air "$/particles/raindrop01.ebm"
		{timer
			{mode play}
			{duration 1.8}
		}
		{visibility 0.075 0.025}
		{preturn 270 5}
		{scalex 0.65 0.05}
		{scaley 0.05 0.015}
	}
	{stage water "$/water/water_circle02.ebm"
		{visibility 1
						{npower
							{min 0.275 0.05}
							{max 0}
							{pow 1}
						}
					}
		{scale 1
						{npower
							{min 0}
							{max 0.325 0.05}
							{pow 0.6}
						}
					}
					{preturn 180 180}
		{timer
						{mode play }
						{duration 0.55 0.1}
					}
	}
	{stage ground "$/water/water_circle02.ebm"
		{visibility 1
						{npower
							{min 0.2125 0.0375}
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
}
