{loudness "airborne"
	{playback_limit
		{max_count 4}
		{discard_type dont_play}
	}
	{volume_attenuation gem2 150 300}
	{loudness 66}
	{loudness_attenuation table
		0 	0
		10 	-6
		20	-6
		30 -66
	}
	{hdr "default" {output "footstep"}}
}
{loudness "start_airborne"
	{playback_limit
		{max_count 4}
		{discard_type dont_play}
	}
	{volume_attenuation gem2 30 60}
	("hdr_default")
}
{loudness "air attack"
	{playback_limit
		{max_count 4}
		{discard_type dont_play}
	}
	{volume_attenuation gem2 400 1000}
	{loudness 72}
	{loudness_attenuation table
		0 	0
		50 	0
		100	-12
		150	-72
	}
	{hdr "default" {output "footstep"}}	
}
{loudness "airborne_close"
	{playback_limit
		{max_count 10}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0 	2.0
		10	1.0
		30  0.50
		60	0.0			
	}
	("hdr_default")
}
{loudness "airborne_medium"
	{playback_limit
		{max_count 10}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0 	0.20
		10	0.50
		60  1.00
		90	0.0			
	}
	{loudness 72}
	{loudness_attenuation table
		0 	0
		50 	0
		100	-12
		150	-72
	}
	{hdr "default" {output "footstep"}}

}	
{loudness "airborne_distant"
	{playback_limit
		{max_count 10}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0   0.0
		5 	0.0
		15	0.13
		25 	0.48
		35	1.0
		45	0.65
		55  0.75
		100 1.00
		500 0.0
	}
	("hdr_default")
}		
