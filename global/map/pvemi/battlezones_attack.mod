{Modifiers
	{modifier
		{name at}
		{filter
			{include
				{player
					{player 2}
				}
				{tag
					{tag at}
				}
			}
			{exclude
				{state
					{state inactive}
				}
			}
		}
		{parameters
			{aim_range
				{place "gun*"}
				{scale 0.75}
			}
			{accuracy
				{place "gun*"}
				{scale 0.75}
			}
		}
	}
	{modifier
		{name arty}
		{filter
			{include
				{player
					{player 2}
				}
				{tag
					{tag arty}
				}
			}
			{exclude
				{state
					{state inactive}
				}
			}
		}
		{parameters
			{aim_range
				{place "gun*"}
				{scale 0.5}
			}
			{accuracy
				{place "gun*"}
				{scale 0.5}
			}
		}
	}
}
