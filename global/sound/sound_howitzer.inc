(define "hdr_howitzer"
	{loudness 72}
	{loudness_envelope 
		0 	0
		1.5 0
		2	-72
	}
	{loudness_attenuation table
		0	0
		50	0
		75	-12
		125	-24
		150	-72
	}
	{hdr "default" {output "environment" "footstep"}}
)

{loudness "howitzer_close"
	{playback_limit
		{max_count 1}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0 	2.0
		10	1.0
		30  0.50
		55	0.0			
	}
	("hdr_default")
}
{loudness "howitzer_medium"
	{playback_limit
		{max_count 2}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0 	0.5
		15	1.25
		40  1.0
		70  0.50
		115 0.0			
	}
	("hdr_howitzer")
}
{loudness "howitzer_far"
	{playback_limit
		{max_count 2}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0   0.0
		5 	0.0
		6	0.13
		8 	0.48
		15	1.0
		35	0.75
		50  0.55
		100 0.30
		400 0.0
	}
	("hdr_howitzer")
}
{loudness "howitzer_distant"
	{playback_limit
		{max_count 2}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0   0.0
		5 	0.0
		6	0.13
		8 	0.48
		15	1.0
		35	0.75
		50  0.65
		100 0.55
		1500 0.0
	}
	("hdr_default")
}
{loudness "background_howitzer"
	{playback_limit
		{max_count 2}
		{discard_type dont_play}
	}
	{volume_attenuation gem2 750 1000}
	("hdr_default")
}
