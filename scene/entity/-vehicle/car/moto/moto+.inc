	{armor {health 105}}
	("chassis_add" speed(120))
	
	{targetClass "car"}
	{targetSelector "moto"}
	
	{sensor
		{Visor "main"
			{vision "moto_main_mgun"}
			{bone "visor2"}
		}
		{Visor "crew"
			{vision "moto_driver"}
			{bone "visor1"}
		}
		{visor "view-around"
			{vision "moto_around"}
			{bone "basis"}
		}
	}


{Placer
	{place "driver" {Group "driver"} {LinkBone "driver"} {visor "crew"} {turnoff {sensor}{shadow}}}
	{place "gunner" {Group "driver"} {LinkBone "gunner"}	{visor "main"} {turnoff {sensor}{shadow}}}
	{place "passenger" {Group "driver"} {LinkBone "passenger"} {turnoff {sensor}{shadow}}}
}
{boarder
	{door "emit1"}
	{door "emit2"}
	{door "emit3"}

	{anm "driver" {forward  {end "seat_driver_moto"}}}
	{anm "gunner" {forward  {end "seat_gunner_moto"}}}
	{anm "passenger" {forward  {end "seat_passenger"}}}

	{link "emit1" "driver"    {anm "driver"} {forward putoff} {reverse puton}}
	{link "emit2" "passenger" {anm "passenger"} {forward putoff} {reverse puton}}
	{link "emit3" "gunner"	  {anm "gunner"} {forward putoff} {reverse puton}}
}
{extender "inventory"
	{weapon "mgun"
		{mask "weapon mgun"}
	}
	{Box
		{item "repair_kit" 1}
	}
}
	{mass 162}
	
	{bone "gun_rot"
		{limits -45 45} 
	}	