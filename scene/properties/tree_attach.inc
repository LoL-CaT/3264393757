(define "set_ladder_bones"
	{##skeleton
			{bone "1"
				{Position (+ %0 -6.50903)	(+ %1 -2.24883)	%2}
			}
			{bone "door01"
				{Position -6.50903	-2.24883	2.13353}
			}
			{bone "node_ladder_bottom"
				{Position -6.50903	-2.24883	27.4756}
			}
			{bone "node_ladder_top"
				{Position (+ %0 -6.50903) (+ %1 -2.24883) (- %2 23.66)}
			}
	}
)
{Volume "bole"
	{tags  "attach" "1"}
	{able {touch 1}}
}
{placer
	{place "1" {attach squat_lie} {linkbone "1"}};{stealth}
}	
{boarder
	{door "door01" {queue 0}}
	{node "node_ladder_bottom"}
	{node "node_ladder_top"}

	{anm "ladder_bind"
		{forward	{begin	"stand_climb_stairs"}}
		{reverse	{end	"stand_climb_stairs" -1}}
	}
	{anm "ladder"
		{forward {speed 1.2} {loop "stand_upstairs"} {fix_orientation}}
		{reverse {speed 1.2} {loop "stand_upstairs" -1} {fix_orientation}}
	}

	{link "door01" "node_ladder_bottom"	{anm "ladder"}}
	{link "node_ladder_bottom" "node_ladder_top" {anm "ladder"}}
	{link "node_ladder_top" "1" {anm "ladder"}}
}