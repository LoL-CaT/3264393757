(define "hdr_gun"
	{loudness 72}
	{loudness_envelope 
		0 	0
		0.75   	0
		1	-72
	}
	{loudness_attenuation table
		0	0
		25	0
		50	-12
		75	-72
	}
	{hdr "default" {output "environment" "footstep"}}
)

{loudness "gun_close"
	{group "shot"}
	{playback_limit
		{max_count 2}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0 	2.0
		65  1.0
		70	0.0			
	}
	("hdr_default")
}
{loudness "gun_medium"
	{group "shot"}
	{playback_limit
		{max_count 2}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0 	0.4
		65	0.6
		80  	1.0
		115 	0.0			
	}
	("hdr_gun")
}
{loudness "gun_far"
	{playback_limit
		{max_count 2}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0   0.0
		5 	0.05
		20	0.16
		40 	0.48
		75	1.0
		95	0.75
		115  1.0
		150 0.50
		300 0.0
	}
	("hdr_default")
}
{loudness "gun_distant"
	{playback_limit
		{max_count 2}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0   0.0
		60	0.0
		80 	0.38
		100	0.5
		120	0.9
		150 1.0
		170 0.75
		200 0.50
		899 0.0
	}
	("hdr_default")
}