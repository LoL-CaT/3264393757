(include "/properties/cannon.ext")
(include "/properties/shadow/tank.inc"  scale(0.6))

{props "vehicle" "cannon" "cannon_small" "truck_mortar" "round_sandbag" "vision_lev01_can"}
{collider "cannon_small"}
{targetSelector "cannon_rocket"}
(mod not "mp"
	{able "emit_on_attack"}
)
{patherId "cannon.carried"}

("armor_mortar")

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

{extender "inventory"
	{box
		{item "ammo mortar" 60}
		(mod "mp"
			{item "sandbag_kit2"}
		)
	}
}

{extender "cannon"
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
	("loco_carrier")
}

{Weaponry
	{place "gun"
		{Barrels 1}
		{weapon "weapon werfer42" filled}
		{Rotate}
	}
}
{mass 150}
{Extension "sgrw42.mdl"}
{bone "turret"
	{limits -30 30}
	{speed 0.004}
}
{sensor
	{visor "main"
		{vision "cannon_main-far"}
	}
}
(include "/properties/selection/cannon.inc"  scale(0.7))
