	(include "/properties/construction.inc")
	{props "ice" "parts" "construction" "no_destroyed_stamp" "disable_area"}
;	{Extension "ice_block01_p01.mdl"}
	(define "v_body"
	{Volume "body%n"
		{Tags  "body"}
		{able clear {overlap 1} {blast 1}}
		{thickness 10}
	}
	)
	("v_body" n(01))
	{Extender "land_patch"
		{TerrainType "ice" "ice"}
	}
	{NoCastShadows}
	{constrain water}
	("armor_light" args 1.0)