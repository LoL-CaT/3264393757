(define "hdr_rifle_auto"
	{loudness 66}
	{loudness_envelope 
		0 	0
		0.25    0
		0.5	-66
	}
	{loudness_attenuation table
		0	0
		25	0
		40	-6
		60	-6
		80	-66
	}
	{hdr "default" {output "environment" "footstep"}}
)

{loudness "rifle_auto_close"
	{group "shot"}
	{playback_limit_per_source
		{max_count 2}
		{discard_type stop_oldest}
	}
	{volume_attenuation table
		0 	1.0
		30	0.8
		55	0.50
		80	0.0			
	}
	("hdr_rifle_auto")
}
{loudness "rifle_auto_medium"
	{group "shot"}
	{playback_limit_per_source
		{max_count 2}
		{discard_type stop_oldest}
	}
	{volume_attenuation table
		0 	0.0
		15	0.5
		40  1.0
		70  0.42
		120 0.0			
	}
	("hdr_default")
}
{loudness "rifle_auto_far"
	{playback_limit_per_source
		{max_count 2}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0   0.0
		15	0.0
		35	0.65
		50  1.5
		100 0.75
		250 0.0
	}
	("hdr_default")
}
{loudness "rifle_auto_distant"
	{playback_limit_per_source
		{max_count 2}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0 	0.0
		15	0.1
		35	0.5
		50  0.7
		80  1.0
		500 0.0
	}
	("hdr_default")
}
