;SDL
{Split 2}
 
{Request "dead"   			{priority 50} {interrupt}}
{Request "corpse"  			{priority 0}}

{Request "throwoff" 		{priority 48} {interrupt}}
{Request "knock-down" 		{priority 47} {interrupt}}
{Request "kick"	 			{priority 46} {interrupt}}
{Request "stop-heal-fast"	{priority 46} {interrupt}}
{Request "keep-knock-down" 	{priority 46} {duration 2}}

{Request "hold-item"		{priority 45}}
{Request "hold-nothing"		{priority 45}}
{Request "hold-bazooka"		{priority 45}}
{Request "board"			{priority 45}}

{Request "item-pick" 		{priority 43}}
{Request "item-drop"		{priority 43}}
{Request "inventory-pick-stand"	{priority 43}}
{Request "inventory-pick"	{priority 43}}
{Request "inventory-drop"	{priority 43}}
{Request "bazooka-pick"		{priority 43}}
{Request "bazooka-drop"		{priority 43}}
{Request "belt-pick"		{priority 43}}
{Request "belt-drop"		{priority 43}}
{Request "pistol-pick"		{priority 43}}
{Request "pistol-drop"		{priority 43}}
{Request "throw"			{priority 43}}
{Request "switch-weapon"	{priority 43}}

{Request "pickup-stand"		{priority 43}}
{Request "pickup-hand"		{priority 43}}
{Request "pickup-bazooka"	{priority 43}}
{Request "ground-drop"		{priority 43}}

{Request "up"	  			{priority 40}}
{Request "down"	  			{priority 40} {interrupt}}
{Request "quick-down"		{priority 40} {interrupt}}
{Request "quick-up"			{priority 40}}
{Request "squat"			{priority 40}}
{Request "swim"				{priority 40}}

{Request "reload" 			{priority 30}}
{Request "reload-bazooka" 	{priority 30}}
{Request "unload" 			{priority 29}}
{Request "unload-bazooka" 	{priority 29}}

{Request "stop-move"		{priority 32} {switch "walk" 0}}
{Request "switch-move"		{priority 32}}
{Request "stop-hold-back"	{priority 32}}
{Request "look-out" 		{priority 32}}
{Request "look-left-in"		{priority 32}}
{Request "look-right-in"	{priority 32}}
{Request "look-sleft-in"	{priority 32}}
{Request "look-sright-in"	{priority 32}}
{Request "peep-left-in"		{priority 32}}
{Request "peep-right-in"	{priority 32}}
{Request "squat-hide"		{priority 32}}
{Request "squat-cover"		{priority 32}}
{Request "rotate-l45"		{priority 32}}
{Request "rotate-r45"		{priority 32}}

{Request "grenade-lie"		{priority 32}}
{Request "grenade-cover"	{priority 32}}

{Request "stop-rotate"		{priority 30}}
{Request "stop-repair"		{priority 30}}
{Request "stop-animation" 	{priority 30}}
{Request "move"	  			{priority 30} {duration 1} {exit "stop-move"} {switch "walk" 1}}
{Request "rotate"			{priority 30} {duration 1} {exit "stop-rotate"}}
{Request "unboard-to-ground"	{priority 30}}
{Request "unboard-to-water"		{priority 30}}

{Request "rush"				{priority 30} {duration 1} {exit "stop-move"}}

{Request "recoil"			{priority 30}}
{Request "snipe"			{priority 29}}
{Request "hold-back"		{priority 27}}
{Request "fire" 			{priority 25}}
{Request "fire-bazooka" 	{priority 25}}
{Request "aim"				{priority 20}}
{Request "aim-thrower"		{priority 20}}
{Request "aim-bazooka"		{priority 20}}

{Request "repair" 			{priority  5} {duration 2} {exit "stop-repair"}}
{Request "heal-head"		{priority  5} {duration 1} {exit "stop-repair"}}
{Request "heal-hand"		{priority  5} {duration 1} {exit "stop-repair"}}
{Request "heal-leg"			{priority  5} {duration 1} {exit "stop-repair"}}

{Request "step-aside-left"	{priority  2} {duration 1} {exit "stop-hold-back"}}
{Request "step-aside-right"	{priority  2} {duration 1} {exit "stop-hold-back"}}

{Request "animation"		{priority  0} {duration 1} {exit "stop-animation"}}
{Request "board-begin"		{priority  0}}
{Request "idle" 			{priority  0}}
{Request "idle-prepare" 	{priority  0}}

{Start "stand"}
