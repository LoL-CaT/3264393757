	(include "/properties/stuff.ext")
	{props "-steel" "wood" "fence" "construction" "spread_items" "fx_link" "xmas"}
	{collider "stuff.construction"}
	{simulation {able 1} {state 1}}
	{Volume "box"
		{thickness 1}
		{able {touch}}
	}
	{extender "bone_rotator"
		{"rotate"}
	}