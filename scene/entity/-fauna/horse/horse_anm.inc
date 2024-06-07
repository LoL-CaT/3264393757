		{sequence "eat" {speed 0.6}}
		{sequence "death" {speed 0.6}		{event 9 "step"} {event 12 "die"}};fall 17 21
		{sequence "passive" {speed 0.6}		{event 6 "idle"}}
		{sequence "passive1" {speed 0.6}	{event 44 "idle"} {event 55 "idle"} {event 14 "step"} {event 27 "step"} {event 40 "step"} {event 52 "step"} {event 65 "step"}}
		{sequence "passive2" {speed 0.6}}
		{sequence "run" {speed 0.4}		{event 2 "step"}{event 8 "step"}{event 10 "step"}{event 12 "step"}}
		{sequence "run1" {speed 0.3}		{event 9 "step"}{event 11 "step"}{event 13 "step"}}
		{sequence "walk" {speed 0.6}		{event 3 "step"}{event 12 "step"}}
		{sequence "run_left" {speed 0.6}	{event 3 "step"}{event 12 "step"}}
		{sequence "run_right" {speed 0.6}	{event 3 "step"}{event 12 "step"}}
		{sequence "run1_left" {speed 0.6}	{event 9 "step"}{event 11 "step"}{event 13 "step"}}
		{sequence "run1_right" {speed 0.6}	{event 9 "step"}{event 11 "step"}{event 13 "step"}}
		{sequence "walk_left" {speed 0.6}	{event 8 "step"}{event 14 "step"}{event 22 "step"}{event 28 "step"}}
		{sequence "walk_right" {speed 0.6}	{event 8 "step"}{event 14 "step"}{event 22 "step"}{event 28 "step"}}
		{sequence "demage_left" {speed 0.6}	{event 3 "scream"}}
		{sequence "demage_right" {speed 0.6}	{event 3 "scream"}}
		{sequence "demage_front" {speed 0.6}	{event 2 "scream"}}
		{sequence "demage_back" {speed 0.6}	{event 3 "scream"}}