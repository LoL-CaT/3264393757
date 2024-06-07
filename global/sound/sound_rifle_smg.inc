(define "hdr_rifle_smg"
	{loudness 60}
	{loudness_envelope
		0.0 	0
		0.5 	0
		0.6 	-60
	}
	{loudness_attenuation table
		0 		0
		25	 	0
		35 		-60
	}
	{hdr "default" {output "environment" "footstep"}}
)

{loudness "rifle_smg_close"
	{group "shot"}
	{playback_limit_per_source
		{max_count 2}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0 	1.0
		30	0.8
		50  0.50
		70	0.0			
	}
	("hdr_rifle_smg")
}
{loudness "rifle_smg_medium"
	{group "shot"}
	{playback_limit_per_source
		{max_count 2}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0 	0.0
		15	0.0
		40  1.0
		80  0.5
		130 0.0			
	}
	("hdr_default")
}
{loudness "rifle_smg_far"
	{playback_limit_per_source
		{max_count 2}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		0   0.0
		15	0.0
		35	0.2
		50  0.4
		80  1.0
		200 0.0
	}
	("hdr_default")
}
{loudness "rifle_smg_distant"
	{playback_limit_per_source
		{max_count 2}
		{discard_type stop_oldest}
	}
	{volume_attenuation table 
		5 	0.0
		15	0.1
		50  0.4
		90  1.0
		400 0.00
	}
	("hdr_default")
}		
