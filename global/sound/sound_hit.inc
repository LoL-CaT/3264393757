(define "hdr_hit"
	{loudness 72}
	{loudness_envelope 
		0 	0
		0.75   	0
		1	-72
	}
	{loudness_attenuation table
		0	0
		20	0
		40	-12
		50	-24
		75	-72
	}
	{hdr {output "environment" "footstep"}}
)

{loudness "hit_close"
	{playback_limit
		{max_count 1}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0 	2.0
		30	1.0
		50  0.50
		70	0.0			
	}
	("hdr_hit")
}
{loudness "hit_medium"
	{playback_limit
		{max_count 2}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0 	0.0
		20	1.25
		40  1.0
		70  0.70
		135 0.0			
	}
	("hdr_default")
}
{loudness "hit_far"
	{playback_limit
		{max_count 2}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0   0.0
		5 	0.0
		50	0.13
		75	0.60
		95	1.75
		120  1.0
		180 0.30
		300 0.0
	}
	("hdr_default")
}
{loudness "hit_distant"
	{playback_limit
		{max_count 2}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0   0.0
		5 	0.0
		6	0.0
		8 	0.0
		65	0.30
		95	1.00
		120 0.45
		300 0.25
		600 0.0
	}
	("hdr_default")
}
{loudness "hit_groundfall"
	{playback_limit
		{max_count 1}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0 	1.0
		30	0.1
		70  0.0		
	}
	("hdr_default")
}