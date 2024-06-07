{Modifiers
	{modifier
		{name local_pz3n_aim_range}
		{filter
			{include
				{tag
					{tag pz3n}
				}
			}
		}
		{parameters
			{aim_range
				{place "gun*"}
				{scale 250}
			}
		}
	}
	{modifier
		{name local_accuracy_team_b}
		{filter
			{include
				{team
					{team b}
				}
			}
		}
		{parameters
			{accuracy
				{place "gun*"}
				{scale 0.75}
			}
		}
	}
	{modifier
		{name local_at_regiment}
		{filter
			{include
				{prop
					{prop vehicle}
				}
				{player
					{player 9}
				}
				{state
					{state inhabited}
				}
			}
			{exclude
				{state
					{state broken}
				}
				{state
					{state inactive}
				}
			}
		}
		{parameters
			{aim_range
				{place gun}
				{scale 0.5}
			}
		}
	}
	{modifier
		{name local_recon_regimen_guns}
		{filter
			{include
				{tag
					{tag recon_regiment_guns}
				}
				{player
					{player 2}
				}
			}
		}
		{parameters
			{accuracy
				{place "gun*"}
				{scale 0.5}
			}
		}
	}
}
