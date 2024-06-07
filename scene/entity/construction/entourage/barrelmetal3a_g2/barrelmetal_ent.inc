;SDL
game_entity

{volume "body"
	{able clear {visible} {bullet} {select} {contact_ground} {touch} {contact} {blast} {obstacle}}
	{thickness 1}
}
{volume "select"
	{able clear {select}}
	{density 0}
}
{props "explosive_barrel" "steel" "capacity" "stuff"}
{tag "barrel_ent"}
{obstacleID "construction"}
{collider "particle.small"}

{simulation {able 1}}
{constrain ground}

{lodclass "decor_small"}
{armor
	{setting "body"
		{whole_wound}
		{durability
			{pierce	{koef 0.99} {value 3}}
		}
		{health_reducing
			{pierce {koef 0}}
			{blast {koef 0}}
		}
		{bullet_pass
			{threshold 100
				{destroyed 1}
			}
		}
		{threshold_weakness_calibre 1}
	}
}