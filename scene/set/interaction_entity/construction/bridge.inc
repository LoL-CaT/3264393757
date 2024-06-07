{"bridge"
	{on "criticalhit" overload}
}
{"bridge abutments parts"
	{on "cut_parts"
		(define "cut_part"
			{if rand 0.5
				{tear "building_part_steel" bone "part%0"
					{volumes enable contact}
					{impulse up 0.5 0.2 dir 3.5 1.3 cx 3 1 cy 3 1 rnd_dir 1 no_position}
				}
			}
		)
		("cut_part" args 1)
		("cut_part" args 2)
		("cut_part" args 3)
		("cut_part" args 4)
		("cut_part" args 5)
		("cut_part" args 6)
		("cut_part" args 7)
		("cut_part" args 8)
		("cut_part" args 9)
		("cut_part" args 10)
	}
	{on "cut_pieces"
		{call "cut_parts"}
	}
}
{"obstacle_construction"
	{on "obstacle_construction"
		{volumes enable obstacle}
		{area rebuild}
	}
}
{"obstacle_amount_1"
	{on "change_model"
		{delay_ex 0.33
			{tear "obstacle_construction" bone "obst1"
				{call "obstacle_construction"}	
			}
		}
	}
}
{"obstacle_amount_2"
	{on "change_model"
		{delay_ex 0.33
			{tear "obstacle_construction" bone "obst1"
				{call "obstacle_construction"}	
			}
			{tear "obstacle_construction" bone "obst2"
				{call "obstacle_construction"}
			}

		}
	}
}