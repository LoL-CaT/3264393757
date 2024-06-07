	(include "/properties/construction.inc")
	{extension "watch_tower_01.mdl"}
	{props "small" "cornered" "parts" "construction" "watch_tower" "wood" "burning" "disable_area" "no_destroyed_stamp"}
	("armor_watch_tower")

	{volume "body01"
		{thickness 20}
		{tags "body"}
		{able {visible 0}{Obstacle 0}}
	}
	{volume "body02"
		{thickness 20}
		{tags "body"}
		{able {visible 0}{Obstacle 0}}
	}
	{volume "body03"
		{thickness 20}
		{tags "body"}
		{able {visible 0}{Obstacle 0}}
	}
	{volume "body04"
		{thickness 20}
		{tags "body"}
		{able {visible 0}{Obstacle 0}}
	}
	{volume "body05"
		{thickness 20}
		{tags "body"}
		{able {visible 0}{Obstacle 0}}
	}
	{volume "body06"
		{thickness 20}
		{tags "body"}
	}
	{volume "body07"
		{thickness 20}
		{tags "body"}
	}
	{volume "body08"
		{thickness 20}
		{tags "body"}
	}
	{volume "body09"
		{thickness 20}
		{tags "body"}
	}
	{volume "body10"
		{thickness 20}
		{tags "body"}
		{able {visible 0}{Obstacle 0}}
	}
	{volume "body11"
		{thickness 20}
		{tags "body"}
	}
	{volume "body12"
		{thickness 20}
		{tags "body"}
	}
	{volume "land01"
	}
	{Extender "land_patch"}
	
	{Volume "place2"
		{Tags  "attach" "2"}
		{able clear {bullet 0}{touch 1}}
	}
	{Volume "place1"
		{Tags  "attach" "1"}
		{able clear {bullet 0}{touch 1}}
	}
	{Volume "place3"
		{Tags  "attach" "3"}
		{able clear {bullet 0}{touch 1}}
	}
	{Volume "place4"
		{Tags  "attach" "4"}
		{able clear {bullet 0}{touch 1}}
	}

	
	{Boarder
		{door "emit" {queue 0}}
		{node "node_ladder_bottom"}
		{node "node_ladder_top"}
		{node "node01"}
		{anm "ladder_bind"
			{forward	{speed 0.8}{begin	"ladder_climbing_start"}}
			{reverse	{speed 0.8}{end	"ladder_climbing_start" -1}}
		}
		{anm "ladder"
			{forward	{speed 0.8} {loop "ladder_climbing"}}
			{reverse	{speed 0.8} {loop "ladder_climbing" -1}}
		}
		{anm "ladder_stop"
			{forward	{speed 0.8} {begin "ladder_climbing_stop"}}
			{reverse	{speed 0.8} {end "ladder_climbing_stop" -1}}
		}
		{link "emit" "node_ladder_bottom" {anm "ladder_bind"} {forward putoff} {reverse puton}}
		{link "node_ladder_bottom" "node_ladder_top" {anm "ladder"}}
		{link "node_ladder_top" "node01" {anm ""} {forward puton} {reverse putoff}}

        {link "node01" "mgun" {anm "[fsm]"}}
		{link "node01" "1" {anm "[fsm]"}}
		{link "node01" "2" {anm "[fsm]"}}
		{link "node01" "3" {anm "[fsm]"}}
		{link "node01" "4" {anm "[fsm]"}}
	
		{link "1" "2" {anm "[fsm]"}}
		{link "1" "3" {anm "[fsm]"}}
		{link "1" "4" {anm "[fsm]"}}
		{link "2" "3" {anm "[fsm]"}}
		{link "2" "4" {anm "[fsm]"}}
	}
