(define "view"
	{param "name" optional blockinfo string}
	{param "offset" optional Vector3}
	{param "delay" optional float}
	{block "nightonly" optional}
	{block "fire" optional}
)
{block "spriteview"
	("view")
	{block "sprite" prefer defined}
	{block "ground" optional}
	{block "layer" optional
		{param "id" blockinfo enum
			{values "background" "ground" "groundstatic" "grounddynamic" "groundshadow"
					"water" "entity" "watert" "reflection" "alphaentity"
					"debug" "info" "dialog"
			}
			{default "entity"}
		}
	}
	{block "blend" optional
		{param "type" blockinfo optional enum
			{values "none" "shadow" "alpha" "light"}
		}
	}
	{block "orientation" optional
		{param "type" blockinfo enum
			{values "normal" "normalXY" "normalXZ" "normalYZ" "billboard" "trace"}
		}
	}
	{block "notifyowner" optional}
	{block "usedirection" optional}
	{block "usescale" optional}
	{block "autovisible" optional}
	{block "halo" optional
		{block "usedirection" optional}
		{block "constantsize" optional}
	}	
}

{block "animator"
	{block "timer" optional prefer
		{block "mode" prefer
			{param "value" blockinfo set {values "play" "reset" "stop" "forward" "reverse" "loop" "onepass" "pingpong" "rotation"}}
		}
		{param "duration" prefer RandomParameter}
	}
	{block "visibility"	optional defined "channel"}
	{block "highlight"	optional
		{param "color" blockinfo color {default 0x00FFFFFF}}
	}
	{block "scale"	optional defined "channel"}
}

{block "lightview"
	("view")
	{block "animator" prefer defined}
	{Block "type" optional
		{param "typevalues" blockinfo enum {values "point" "spot"} {default "point"}}
	}
	{block "radius" optional
		{param "value" blockinfo float {default 20}}
	}
	{block "intensity" optional
		{param "value" blockinfo float {default 1}}
	}
	{block "compression" optional
		{param "value" blockinfo float {default 2}}
	}
	{block "falloff" optional
		{param "value" blockinfo float {default 0.5}}
	}
	{block "phi" optional
		{param "value" blockinfo float {default 60}}
	}
	{block "theta" optional
		{param "value" blockinfo float {default 30}}
	}
	{param "pulseperiod" optional RandomParameter}
	{block "effectonground" optional}
	{block "priority" optional
		{param "value" blockinfo int {default 0}}
	}
}

(define "gen"
	{param "totalparticles"   	optional RandomParameter}
	{param "particlesinblock"   optional RandomParameter}
	{param "timetolive"   		optional RandomParameter}
	{block "emissionarea" prefer
		{param "radius"   	optional RandomParameter {default 1}}
		{param "alpha0"   	optional RandomParameter}
		{param "alpha1"   	optional RandomParameter}
		{param "psi"   		optional RandomParameter}
		{param "theta"   	optional RandomParameter}
		{param "speed"   	optional RandomParameter {default 1}}
		{param "distributionlaw" optional enum
			{values "disk" "sphere"} {default "disk"}
		}
	}
	{block "particleinit" prefer
		{param "speed"   	RandomParameter {default 1}}
		{param "lifetime"   RandomParameter {default 1}}
	}
	{block "axisz" optional}
	{block "autoturn" optional}
	{block "ownerspeed" optional}
	{block "color" optional multi
		{param "color" blockinfo color {default 0x00FFFFFF}}
	}
	{block "killparticlesafterstop" optional}
)

{block "generator" prefer optional
	("gen")
}

{block "entitygenerator" optional
	("gen")
	{block "entity" optional multi
		{param "name" blockinfo resource entity}
		{block "fx" optional
			{param "name" blockinfo resource entity}
		}
		{block "frequency" optional
			{param "value" blockinfo float {default 1}}
		}
		{block "aimed" optional
			{param "additionalSpeed" optional RandomParameter}
		}
	}
}

{block "mover" prefer
	{param "damping" optional casegroup RandomParameter {default 1}}
	{block "gravity" optional
		{block "value" prefer
			{param "value" blockinfo float}
		}
	}
	{block "collisions" optional
		{block "terrain" optional}
		{block "objects" optional}
		{block "once" optional}
		{block "restitution" optional
			{param "value" blockinfo float {min 0} {max 10} {default 1}}
		}
	}
	{block "nodependonwind" optional}
}

{block "visualizer"
	{block "stage" multi
		{param "stages" blockinfo optional set {values "initial" "collided" "dying"}}
		{block "flags" optional
			{param "flags" blockinfo set {values "killparticle" "matchsprites" "randomsprites" "ground" "trace" "disablesoftedge"}}
		}
		{block "sprite" multi defined}
	}
}

{block "particleview"
	("view")
	{block "generator"  prefer defined}
	{block "entitygenerator" optional defined}
	{block "mover"      prefer defined}
	{block "visualizer" prefer defined}
	{block "ground" optional}
	{block "notifyowner" optional}
}

(define "std_views"
	{block "spriteview" prefer multi defined}
	{block "decalview" optional multi defined "spriteview"}
	{block "lightview" optional multi defined}
	{block "particleview" optional multi defined}
)
