{efx_template
	(include "sprite.tpl")
	(include "view.tpl")
	
	{block "sound"
		{param "name" blockinfo resource sound}
	}
	{block "damage"
		{param "type" blockinfo enum {values "fire"} {default "fire"}}
		{block "radius" prefer
			{param "value" blockinfo float {default 2}}
		}
		{block "time" prefer
			{param "value" blockinfo float {default 7}}
		}
	}

	{block "fx"
		("std_views")
		{block "sound" optional defined}
		{block "damage" optional defined}
		{block "storeable" optional
			{param "value" blockinfo int {min 0} {max 1} {default 1}}
		}
		{block "fire" optional}
	}
}
