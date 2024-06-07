
	(include "/properties/railway.ext")
	(include "/properties/selection/vehicle.inc"  scale(1.0))
    {mass 10000}
    {props "vehicle" "steel" "carriage" "platform" "train_part" "no_minimap_view" "anm_tank" "platform_attach_icon_rules"}
    {extension "crew.ext"}
    {extension "sensor.ext"}	
	{targetClass "unknown"}

	{Extension "platform_attach.mdl"}
	;{Placer
	;	{place "1"
	;		{Linkbone "attach_vehicle1"}
	;		{entity 	""}
	;		{handlebone "basis"}
	;	}
	;}

	{extender "enumerator"
		{group "usa"}
	}
		
	("wheel" args "wheelright1")
	("wheel" args "wheelleft1")
	("wheel" args "wheelright2")
	("wheel" args "wheelleft2")

	("v_body" n(01) t())
	("v_body" n(02) t())
	("v_body" n(03) t())
	("v_body" n(04) t())
	("v_body" n(05) t())
	("v_body" n(06) t())
	("arena_armor_train" body(10) wheel(50) hp(750))  
	{extender "inventory"
		{box
			{size 8 6}
			{Weight 25000}
		}
	}
