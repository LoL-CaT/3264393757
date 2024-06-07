(define "hdr_vehicle_engine"
	{loudness 66}
	{loudness_attenuation table
		0 	0
		25 	-6
		100	-6
		150 	-66
	}
	{hdr "default" {output "footstep"}}
)

{loudness "vehicle_engine_super_close"
	{playback_limit
		{max_count 2}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0 	1.0
		10	0.1
		20	0.0
	}
	{group "engine"}
	("hdr_default")
}	
{loudness "vehicle_engine_close"
	{playback_limit
		{max_count 2}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0 	1.0
		15	0.7
		30	0.3
		50	0.0
	}
	{group "engine"}
	("hdr_default")
}
{loudness "vehicle_engine_far"
	{playback_limit
		{max_count 2}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0 	0.1
		25	0.4
		45	0.75
		95	0.0
	}
	("hdr_vehicle_engine")
}
{loudness "vehicle_engine_distant"
	{playback_limit
		{max_count 2}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0 	0.0
		30	0.0
		50	0.2
		90 	0.4
		130	0.1
		190	0.0
	}
	("hdr_vehicle_engine")
}
{loudness "vehicle_tracks"
	{playback_limit
		{max_count 2}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0 	1.0
		15	0.5
		35	0.1
		60	0.0
	}
	{group "tracks"}
	("hdr_default")
}
{loudness "vehicle_turret"
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