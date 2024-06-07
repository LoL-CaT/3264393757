{"mortar smoke"
	{on spawn
		{call "add_smoke"}
		{link_sound "smoke" "detonation/grenade_smoke/grenade_smoke"}
	}
	{on "add_smoke"
		{add_view "smoke_cover-up_small"	"smoke1" "root"}
		{add_view "smoke_cover-up_norm"		"smoke2" "root"}
		{add_view "smoke_cover-up_big"		"smoke3" "root"}
	}
	{on "onThrow"
		{volumes disable touch select}
	}
	{on "activate"
		{play_sound "smoke" 1}
		{tags add "smoke"}
		{view stop "smoke1"}
		{view start "smoke2"}
		{volumes "smoke1" enable visible}
		{update_visibility_patch}
		{delay 2
			{view stop "smoke2"}
			{view start "smoke3"}
			{volumes "smoke1" disable visible}
			{volumes "smoke2" enable visible}
			{update_visibility_patch}
		}
		{delay 5
			{volumes "smoke2" disable visible}
			{volumes "smoke3" enable visible}
			{update_visibility_patch}
		}
		{delay 60
			{view stop "smoke3"}
			{stop_sound "smoke"}
		}
		{delay 62
			{hide 1}
		}
	}
	{on ground_hit
		{if stuff_activated
			{if not flag "activated"
				{set "activated" 1}
				{if under_water
					{hide 1}
				else
					{delay 3
						{call "activate"}
					}
				}
			}
		}
	}
	{on contact
		{if stuff_activated
			{if not flag "activated"
				{set "activated" 1}
				{delay 3
					{call "activate"}
				}
			}
		}
	}
}