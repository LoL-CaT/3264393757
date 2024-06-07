{loudness "local environment small"
	{tag environment}
	{playback_limit
		{max_count 2}
		{discard_type dont_play}
	}
	{volume_attenuation gem2 15 30}
	{loudness 36}
	{hdr "environment"}
}
{loudness "local environment medium"
	{tag environment}
	{playback_limit
		{max_count 4}
		{discard_type dont_play}
	}
	{volume_attenuation gem2 20 80}
	{loudness 60}
	{hdr "environment"}
}
{loudness "global environment weak"
	{tag environment}
	{loudness 60}
	{volume 0.15}
	{hdr "environment"}
}

{loudness "global environment storm"
	{tag environment}
	{loudness 60}
	{volume 0.1}
	{hdr "storm"}
}

{loudness "global environment rain"
	{tag environment}
	{loudness 60}
	{volume 0.5}
	{hdr "storm"}
}
{loudness "local environment rain"
	{tag environment}
	{playback_limit
		{max_count 4}
		{discard_type dont_play}
	}
	{volume_attenuation table 
		0 	1.0
		80	1.0
		120	0.0
	}
	{loudness 60}
	{hdr "storm"}
}