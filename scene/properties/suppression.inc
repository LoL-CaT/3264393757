{suppression
	{behaviour "soldier"
		; levels - отсортированный список уровней подавленности, 
		; параметр - время подавленности
		; уровни задаются строго в порядке увеличения
		; наборы уровней индектируются от 0 и по далее порядку, индекс берётся в зависимости от абилки "suppressresistance"
		; signals - какие сигналы приводят к подавлению, доступны: hit, shot, injure, explosion
		{signals hit injure explosion}
		{levels ;"none"
			{level
				{threshold 5}
				{shot_timeout 0.0}
				{hide_timeout 1.5 2.5}
				{open_timeout 3 5}
				{resistance 1.0}
			}
			{level
				{threshold 7.5}
				{shot_timeout 1.0}
				{hide_timeout 3 5}
				{open_timeout 2 3}
				{resistance 1.0}
			}
			{level
				{threshold 12.5}
				{resistance 1.0}			
			}
		}
		{levels ;"basic"
			{level
				{threshold 5}
				{shot_timeout 0.0}
				{hide_timeout 1.5 2.5}
				{open_timeout 3 5}
				{resistance 1.5}
			}
			{level
				{threshold 7.5}
				{shot_timeout 1.0}
				{hide_timeout 3 5}
				{open_timeout 2 3}
				{resistance 1.5}
			}
			{level
				{threshold 12.5}			
				{resistance 1.5}
			}
		}
		{levels ;"advanced"
			{level
				{threshold 5}
				{shot_timeout 0.0}
				{hide_timeout 1.5 2.5}
				{open_timeout 3 5}
				{resistance 1}
			}
			{level
				{threshold 7.5}
				{shot_timeout 0.5}
				{hide_timeout 3 5}
				{open_timeout 2 3}
				{resistance 1.5}
			}
			{level
				{threshold 12.5}		
				{resistance 2.0}
			}
		}
		{levels ;"expert"
			{level
				{threshold 5}
				{shot_timeout 0.25}
				{hide_timeout 1.5 2.5}
				{open_timeout 3 5}
				{resistance 2.5}
			}
			{level
				{threshold 7.5}
				{shot_timeout 0.0}
				{hide_timeout 3 5}
				{open_timeout 2 3}
				{resistance 2.5}
			}
			{level
				{threshold 12.5}
				{resistance 2.5}				
			} 
		}
		{levels ;"master"
			{level
				{threshold 5}
				{shot_timeout 0.0}
				{hide_timeout 1.5 2.5}
				{open_timeout 3 5}
				{resistance 3.0}
			}
			{level
				{threshold 7.5}
				{shot_timeout 0.0}
				{hide_timeout 3 5}
				{open_timeout 2 3}
				{resistance 3.0}
			}
			{level
				{threshold 12.5}
				{resistance 3.0}			
			} 
		}
		{levels ;"hero"
			{level
				{threshold 5}
				{shot_timeout 0.0}
				{hide_timeout 1.5 2.5}
				{open_timeout 3 5}
				{resistance 5.0}
			}
			{level
				{threshold 7.5}
				{shot_timeout 0.0}
				{hide_timeout 3 5}
				{open_timeout 2 3}
				{resistance 5.0}
			}
			{level
				{threshold 12.5}
				{resistance 5.0}
			} 
		}
		
		; impacts - попадание из заданного оружия или гранаты наращивает счетчик в единицах времени, каждый раз по достижении минимального уровня подавленности юнит прячется
		; порядок определяет убывание приоритета сверху вниз: если попадание из "gun" то нарастится время из максимально приоритетного блока
		; attenuation задаёт затухание параметра time на максимальном расстоянии
		
		{impact
			{weapon "gun"}
			{ammo "zenite"}
			{time 0.5
			 {if in_fortification "trench"  5}
			}
			{max_level 2}
			{attenuation 10 0.2 0 1}
		}
		{impact
			{weapon "gun"}
			{ammo "size3"}
			{time 10
			 {if in_fortification "trench"  1}
			}
			{max_level 2}
			{attenuation 25 0.2 10 1}
		}	
		{impact
			{weapon "gun"}
			{ammo "field"}
			{time 10
			 {if in_fortification "trench"  1}
			}
			{max_level 2}
			{attenuation 25 0.2 5 1}
		}	
		{impact
			{weapon "gun"}
			{ammo "fg"}
			{time 8
			 {if in_fortification "trench" 1}
			}
			{max_level 2}
			{attenuation 10 0.2 0 1}
		}	
		{impact
			{weapon "mgun"}
			{time 1
			 {if in_fortification "trench" 4}
			 {if in_house 4}
			}
			{max_level 2}
			{attenuation 10.1 0 10 0.5 0 1}
		}
		{impact
			{weapon "rifle"}
			{time 0.125
			 {if in_fortification "trench" 4}
			}
			{max_level 1}
			{attenuation 10.1 0 10 0.5 0 1}
		}
		{impact
			{weapon "sniper"}
			{time 10
			 {if in_fortification "trench" 4}
			}
			{max_level 2}
			{attenuation 10.1 0 10 0.5 0 1}
		}	
		{impact
			{weapon "autorifle"}
			{time 0.125
			 {if in_fortification "trench" 2}
			 {if in_house 2}
			}
			{max_level 1}
			{attenuation 10.1 0 10 0.5 0 1}
		}	
		{impact
			{weapon "smg"}
			{time 0.005
			 {if in_fortification "trench" 0.6}
			 {if in_house 0.6}
			}
			{max_level 1}
			{attenuation 10.1 0 10 0.5 0 1}
		}
	}
	{behaviour "civilian"
		{signals injure hit explosion shot}
		{levels ;"none"
			{level
				{threshold 5}
				{resistance 1.0}
			}
			{level
				{threshold 20}
				{resistance 1.0}
			}
		}
		{impact
			{weapon "gun"}
			{time 40}
			{max_level 1}
			{attenuation 70 0 20 1}
		}
		{impact
			{ammo "grenade"}
			{time 40}
			{max_level 1}
			{attenuation 70 0 20 1}
		}
		{impact
			{ammo "dynamite"}
			{time 40}
			{max_level 1}
			{attenuation 70 0 20 1}
		}
		{impact
			{time 15}
			{max_level 1}
			{attenuation 70 0 20 1}
		}
	}
}