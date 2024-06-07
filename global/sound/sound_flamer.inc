{loudness "flamer"
	{volume_attenuation table 
		0 	1.0
		50	0.75
		75	0.3
		180	0.0
	}
	{loudness 60}
	{loudness_envelope
		0.0 	0
		0.5 	0
		0.6 	-60
	}
	{loudness_attenuation table
		0 	0
		10 	0
		20 	-60
	}
	{hdr {output "environment" "footstep"}}
}

{loudness "flamer_loop"
	{volume_attenuation table 
		0 	1.0
		50	0.75
		75	0.3
		180	0.0
	}
	{loudness 60}
	{loudness_envelope
		0.0 	0
	}
	{loudness_attenuation table
		0 	0
		10 	0
		20 	-60
	}
	{hdr {output "environment" "footstep"}}
}

{loudness "flamer_weak"
	{volume_attenuation table 
		0 	1.0
		50	0.5
		75	0.15
		120	0.0
	}
	{loudness 60}
	{loudness_envelope
		0.0 	0
		0.5 	0
		0.6 	-60
	}
	{loudness_attenuation table
		0 	0
		10 	0
		20 	-60
	}
	{hdr {output "environment" "footstep"}}
}

{loudness "flamer_weak_loop"
	{volume_attenuation table 
		0 	1.0
		50	0.5
		75	0.15
		120	0.0
	}
	{loudness 60}
	{loudness_envelope
		0.0 	0
	}
	{loudness_attenuation table
		0 	0
		10 	0
		20 	-60
	}
	{hdr {output "environment" "footstep"}}
}