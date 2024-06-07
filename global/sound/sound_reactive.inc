(define "hdr_reactive"
	{loudness 60}
	{loudness_envelope
		0.0 	0
		0.75 	0
		1 	-60
	}
	{loudness_attenuation table
		0 	0
		30 	0
		35 -60
	}
	{hdr {output "environment" "footstep"}}
)

{loudness "reactive_close"
	{playback_limit_per_source
		{max_count 4}
		{discard_type stop_oldest}
	}
	{volume_attenuation table
		0 	2.0
		30	1.0
		55	0.50
		85	0.0			
	}
	("hdr_reactive")
}
{loudness "reactive_medium"
	{playback_limit_per_source
		{max_count 4}
		{discard_type stop_oldest}
	}
	{volume_attenuation table
		0 	0.0
		15	0.5
		40  1.0
		70  0.40
		120 0.0			
	}
	("hdr_default")
}
{loudness "reactive_distant"
	{playback_limit_per_source
		{max_count 4}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0 	0.0
		15	0.0
		35	0.5
		50  0.7
		80  1.0
		400 0.0
	}
	("hdr_default")
}
