{
	(include "/properties/animal.ext")
	(include "/properties/shadow/animal.inc")
	(include "/properties/selection/vehicle.inc"  scale(0.5))

    {props "horse" "tractor" "big" "riding" "horse_anm"}
	{targetClass "human"}
    {targetSelector "human"}
	{hearingBias 4.5} ; in meters
	{able "emit_on_attack" "select"}
	{obstacleID "horse"}
	{PatherID "horse"}
    	{collider "human"}
	{lodclass "human"}
	{NoGroupMesh 1}

	{Chassis "foot"
		{Quadruped}
		{Run
			{Slow	6  12	200}
			{Normal	7  12	250}
			{Fast	35	35	375}
		}
	}
	{sensor
		{OperatableRequired 0}
		{visor "main"
			{vision "car_open_around"}
			{bone "visor1"}
		}
	}

	{extender "inventory"
		{box
			{Size 6 10}
			{weight 300}
		}
	}
	
	{volume "body"
		{thickness 4}
	}
	{volume "body1"
		{thickness 4}
		{component "body"}
		{able {obstacle 0}}
	}
	{volume "body2"
		{thickness 4}
		{component "body"}
	}
	{volume "body3"
		{thickness 4}
		{component "body"}
	}
	{volume "body4"
		{thickness 4}
		{component "body"}
	}
	{volume "body5"
		{thickness 4}
		{component "body"}
	}


	{extender "vitality"
		{Health {max 500} {current 500} {inc 1}}
	}

	{placer
		{place "driver"
			{group "crew"}
			{linkbone "driver"}
		}
		{crew}
	}
	{##boarder
		{anm "driver"
			{forward	{begin	"board_SdKfz251-1"} {end "horse_driver"} {base "doorleft"}}
			{reverse 	{end	"board_SdKfz251-1" -1} {base "doorleft" -1}}
		}
		{door "emit2"}
		{door "emit1"}
		{link "emit2" "driver" {anm "driver"} {forward putoff} {reverse puton}}
		{link "emit1" "driver" {anm "driver"} {forward putoff} {reverse puton}}
	}

	{boarder
		{anm "driver"
			{forward	{begin	"board_SdKfz251-1"} {end "horse_driver_idle00"} {base "doorleft"}}
			{reverse 	{end	"board_SdKfz251-1" -1} {base "doorleft" -1}}
		}
		{door "emit2"}
		{door "emit1"}
		{link "emit2" "driver" {anm "driver"} {forward putoff} {reverse puton}}
		{link "emit1" "driver" {anm "driver"} {forward putoff} {reverse puton}}
	}


	{mass 500}
	{Extension "horse.mdl"}
	{Skeleton
		{animation
			{smooth 0.5}
			{blend "pose_stand"	{pose "passive" begin}}
		}
	}
	{extender "animation_sound"
		{event "idle"
			{play "animal/horse/idle"}
		}
		{event "step"
			{play "animal/horse/step"}
		}
		{event "scream"
			{play "animal/horse/scream"}
		}
		{event "die"
			{play "animal/horse/death"}
		}
	}
}
