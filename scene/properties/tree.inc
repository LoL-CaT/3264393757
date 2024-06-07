game_entity
	(include "seasons.inc")
	(define "v_bole"
	{volume "bole%n"
		{able {touch 0} {visible 0}}
		{thickness 3}
	}
	)
	("v_bole" n())
	(define "v_crown"
	{volume "crown%n"
		{able
			{contact 0} {contact_ground 0}
			{bullet 0} {obstacle 0}
			{overlap 1}
			{touch 0}
		}
		{density %density}
		{tags "crown"}
	}
	)
	(define "v_crown_std"		("v_crown" n(%n) density(0.00001)))
	(define "v_crown_density"	("v_crown" n(%n) density(%density)))

	("v_crown_std" n())

	{simulatorId "pillar"}
	{collider 	"tree"}
	{obstacleID "tree"}
	{mass 200}
	{props "tree"}
;	{NoCastShadows}
;	{NoGetShadows}
	{NoGroupMesh 1}
	{volume defaultmaterial "wood"}
	{lodclass "flora_medium"}

	{ZClipVisibility 1}
	{armor
		{setting "bullet_pass_only"
			{threshold
				{pierce {calibre 10000}}
				{blast {value 10000}}
			}
		}
	}