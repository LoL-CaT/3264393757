{"fortification"
	{on bullet_hit
		{if volume "target"
			{damage_human_in_window}
			{bullet_detonate}
		}
	}
}