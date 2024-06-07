{Modifiers
	{modifier
		{filter
			{exclude
				{tag
					{tag boat}
				}
			}
		}
		{parameters
			{aim_range
				{place "*mgun"}
				{scale 3}
			}
		}
	}
	{modifier
		{filter
			{include
				{tag
					{tag beach_mg}
				}
			}
		}
		{parameters
			{aim_range
				{place "gun*"}
				{scale 2}
			}
		}
	}
	{modifier
		{filter
			{include
				{tag
					{tag beach_mortars}
				}
				{team
					{team b}
				}
			}
		}
		{parameters
			{aim_range
				{place "gun*"}
				{scale 0.3}
			}
		}
	}
	{modifier
		{filter
			{include
				{tag
					{tag flamer1}
				}
			}
		}
		{parameters
			{aim_range
				{place "gun*"}
				{scale 2}
			}
		}
	}
}
