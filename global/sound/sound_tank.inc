(define "hdr_tank_engine"
	{loudness 66}
	{loudness_attenuation table
		0 	0
		25 	-6
		100	-6
		150 	-66
	}
	{hdr "default" {output "footstep"}}
)

{loudness "tank_engine_super_close"
	{playback_limit
		{max_count 2}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0 	1.0
		25	0.1
		35	0.0
	}
	{group "engine"}
	("hdr_default")
}	
{loudness "tank_engine_close"
	{playback_limit
		{max_count 2}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0 	1.0
		25	0.8
		60	0.4
		80	0.0
	}
	{group "engine"}
	("hdr_default")
}
{loudness "tank_engine_far"
	{playback_limit
		{max_count 2}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0 	0.5
		35	0.5
		60	1.0
		120	0.0
	}
	("hdr_tank_engine")
}
{loudness "tank_engine_distant"
	{playback_limit
		{max_count 2}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0 	0.0
		35	0.0
		60	0.5
		100 1.0
		200	0.1
		220	0.0
	}
	("hdr_tank_engine")
}
{loudness "tank_tracks"
	{playback_limit
		{max_count 2}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0 	1.0
		25	0.8
		35	0.7
		50	0.5
		100	0.0
	}
	{group "tracks"}
	("hdr_default")
}
{loudness "tank_turret"
	{playback_limit
		{max_count 2}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0 	0.8
		25	0.5
		60	0.3
		70	0.0
	}
	{group "turret"}
	("hdr_default")
}