(include "/properties/cannon.ext")
(include "/properties/shadow/tank.inc"  scale(0.6))

{props "vehicle" "cannon" "cannon_small" "truck_mortar" "mortar_launch_sound" "round_sandbag" "vision_lev01_can" "trace_interceptor"}
{collider "cannon_small"}
{targetSelector "cannon_mortar"}
{patherId "cannon.carried"}

("armor_mortar_hp" hp(100))

{volume "body"
	{tags "body"}
	{component "body"}
	{thickness 15}
}
{Volume "gun"
	{thickness 15}
	{able {Contact 1}}
}

("wheel" args "wheelright")
("wheel" args "wheelleft")

("crew_gun")

{boarder
	{anm "gunner"
		{forward	{end "pose_pak40_gunlayer" 10}}
	}
	{anm "commander"
		{forward	{end "pose_pak40_charger" 10}}
	}
	{anm "driver1"
		{forward {end "mortar_driver_r" 10}}
	}
	{anm "driver2"
		{forward {end "mortar_driver_l" 10}}
	}
}
(define "inventory"
	{extender "inventory"
		{box
			{item "ammo %name" 15}
			{item "sandbag_kit2"}
		}
	}
)
{extender "cannon"
	{state move}
	{animation
		{switch "close"}
		{move "mortar_driver_r" "mortar_driver_l"}
		{aim "" ""}
		{fire  "Squat_load_mortar_end" ""}
		{reload  "" ""}
	}
	{move {obstacle "close"}}
	{attack {obstacle "open"}}
}

{Chassis "human_carrier"
	{carrierPlace "driver1" "driver2"}
	{carrierBone  "handle1" "handle2"}
	("arena_mortar_medium_2gunners_carrier")
}
(define "weapon"
{Weaponry
	{place "gun"
		{Barrels 1}
		{weapon "weapon %name" filled}
		{Rotate}
		("abm_mortar")		
	}
}
)
("weapon" name(werfer42))
{mass 150}
("round_sandbag")
("round_dot")
