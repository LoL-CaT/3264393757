(define "hdr_hit_huge"
	{loudness 78}
	{loudness_envelope 
		0 	0
		0.75   	0
		1	-78
	}
	{loudness_attenuation table
		0	0
		37	0
		75	-78
	}
	{hdr "default" {output "environment" "footstep"}}
)

{loudness "hit_huge_close"
	{group "hit"}
	{playback_limit
		{max_count 1}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0 	2.0
		20	1.5
		40  1.0
		80	0.0			
	}
	("hdr_hit_huge")
}
{loudness "hit_huge_medium"
	{group "hit"}
	{playback_limit
		{max_count 2}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0 	0.0
		20	0.25
		50  1.0
		80  0.70
		125 0.0			
	}
	("hdr_default")
}
{loudness "hit_huge_far"
	{playback_limit
		{max_count 2}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0   0.0
		25	0.30
		35	1.75
		100 1.00
		300 0.0
	}
	("hdr_default")
}
{loudness "hit_huge_distant"
	{playback_limit
		{max_count 2}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0   0.0
		40	0.15
		100 0.55
		200 1.25
		700 0.0
	}
	("hdr_default")
}
