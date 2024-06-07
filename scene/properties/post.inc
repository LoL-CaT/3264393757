game_entity
	{volume "post"
		{thickness 3}
	}
	{simulatorId "pillar"}
	{collider "tree"}
	{obstacleID "tree"}
	{mass 200}
	{props "post"}
;	(include "/properties/shadow/construction.inc" sx(1) sy(0.18))
	(include "seasons.inc")
	(include "construction_generic.inc")
	{extender "light"
		{lightfx "light_lantern"}
		{breakfx "lamp_hit"}
	}
	{lodclass "decor_small"}