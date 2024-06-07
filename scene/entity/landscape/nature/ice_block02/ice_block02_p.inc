	(include "/properties/construction.inc")
	{props "ice" "parts" "construction" "no_destroyed_stamp" "disable_area"}
	(define "v_body"
	{Volume "body%n"
		{Tags  "body"}
		{able clear {blast} {overlap}}
		{thickness 10}
	}
	)
	("v_body" n(01))
	{Extender "land_patch"
		{TerrainType "ice" "ice"}
	}
	{NoCastShadows}
	{constrain water}
	("armor_ice")