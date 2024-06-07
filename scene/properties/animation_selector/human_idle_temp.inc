;SDL
{squat_breath
	{if human_stuff holding "pistol"
		{anm "squat_idle_pistol_1"}
	}
	{if human_stuff holding "smg"
		{random_select
			{weight 1	"squat_idle_smg_1"}
			{weight 1	"squat_idle_smg_4"}
		}
	}
	{if human_stuff holding "mgun"
		{anm "squat_idle_mgun_4"}
	}
	{if human_stuff holding "rifle"
		{anm "squat_idle_rifle_1"}
	}
	{anm ""} ; animations required
}
{squat_idle
	{if human_stuff holding "nothing"
		{random_select
			{weight 1	"squat_idle_empty_0"}
			{weight 1	"squat_idle_empty_1"}
			{weight 1	"squat_idle_empty_2"}
			{weight 1	"squat_idle_empty_3"}			
		}	
	}
	{if human_stuff holding "pistol"
		{random_select
			{weight 1	"squat_idle_pistol_2"}
			{weight 1	"squat_idle_pistol_3"}
			{weight 1	"squat_idle_pistol_4"}
		}
	}
	{if human_stuff holding "smg"
		{random_select
			{weight 1	"squat_idle_smg_2"}
			{weight 1	"squat_idle_smg_3"}
		}
	}
	{if human_stuff holding "mgun"
		{random_select
			{weight 3	"squat_idle_mgun_2"}
			{weight 3	"squat_idle_mgun_3"}
			{weight 4	"squat_idle_mgun_1"}
		}
	}
	{if human_stuff holding "rifle"
		{random_select
			{weight 1	"squat_idle_rifle_2"}
			{weight 1	"squat_idle_rifle_3"}
			{weight 1	"squat_idle_rifle_4"}
			{weight 1	"squat_idle_rifle_5"}
			{weight 1	"squat_idle_rifle_6"}
		}
	}
	{anm ""}
}
{stand_breath
	{if human_stuff holding "nothing"
		{if human_hold_strap
			{anm "stand_idle_strap_1"}
		}
		; no strap
		{anm "stand_idle_empty_1"}
	}
	{if human_stuff holding "1hand"
		{anm "stand_idle_1hand"}
	}
	{if human_stuff holding "rifle"
		{anm "stand_look_around_gun"}
	}
	{if human_stuff holding "mgun"
		{anm "stand_look_around_mgun"}
	}
	{if human_stuff holding "pistol"
		{anm "stand_idle_1hand"}				; дыханиек с пистолетом?
	}	
	{if human_stuff holding "smg" "flamer"
		{anm "stand_look_around_gun"}
	}
	{if human_stuff holding "bazooka"	
		{anm "stand_look_around_bazooka"}
	}
	{if human_stuff holding "small"
		{anm "stand_idle_empty_1"}
	}	
	{anm ""}
}
{stand_idle
	{if human_stuff holding "rifle"
		{random_select
			{weight 1	"stand_look_around_gun_1"}
			{weight 1	"stand_look_around_gun_2"}
			{weight 1	"stand_look_around_gun_3"}			
		}
	}
	{if human_stuff holding "mgun" 
		{random_select
			{weight 1	"stand_look_around_mgun_1"}
			{weight 1	"stand_look_around_mgun_2"}
			{weight 1	"stand_look_around_mgun_3"}			
		}
	}
	{if human_stuff holding "pistol" 
		{random_select
			{weight 1	"stand_look_around_pistol_1"}
			{weight 1	"stand_look_around_pistol_2"}
			{weight 1	"stand_look_around_pistol_3"}
			{weight 1	"stand_look_around_pistol_4"}			
		}
	}	
	{if human_stuff holding "smg" "flamer"
		{random_select		
			{weight 1	"stand_smg_idle_1"}			
			{weight 1	"stand_smg_idle_2"}
			{weight 1	"stand_smg_idle_3"}
			{weight 1	"stand_smg_idle_4"}
;			{weight 1	"stand_smg_idle_5"}				нужна доработка анимации. Автомат летает над руками		
		}
	}	
	{if human_stuff holding "bazooka"
		{random_select
			{weight 1	"stand_look_around_bazooka_1"}
			{weight 1	"stand_look_around_bazooka_2"}	
			{weight 1	"stand_look_around_bazooka_3"}			
		}
	}
	{if human_stuff holding "1hand"
		{anm "stand_idle_1hand"}		
	}
	{if human_stuff holding "small"
		{random_select
			{weight 1	"stand_idle_empty_2"}			
			{weight 1	"stand_idle_empty_3"}
			{weight 1	"stand_idle_empty_4"}
		}
	}
	{if human_stuff holding "nothing"
		{if human_hold_strap
			{if able "attention"
				{anm "stand_idle_strap_1"}					
			}
			{random_select
					{weight 1	"stand_idle_strap_2"}
					{weight 1	"stand_idle_strap_3"}
					{weight 1	"stand_idle_strap_4"}
					{weight 1	"stand_idle_strap_5"}
			}
		}
		; no strap
		{if able "attention"
			{anm "stand_idle_empty_1"}
		}
		{random_select
			{weight 1	"stand_idle_empty_2"}			
			{weight 1	"stand_idle_empty_3"}
			{weight 1	"stand_idle_empty_4"}
		}		
	}
	{anm ""}
}
{lie_idle										;нужен для empty или small
	{if human_stuff holding "rifle" 
		{random_select
			{weight 1	"lie_rifle_idle_1"}
			{weight 1	"lie_rifle_idle_2"}
			{weight 1	"lie_rifle_idle_3"}				
		}
	}
	{if human_stuff holding "smg" "flamer"
		{random_select
			{weight 1	"lie_smg_idle_1"}
			{weight 1	"lie_smg_idle_2"}
			{weight 1	"lie_smg_idle_3"}				
		}	
	}
	{if human_stuff holding "mgun"
		{random_select
			{weight 1	"lie_mgun_idle_1"}
			{weight 1	"lie_mgun_idle_2"}
			{weight 1	"lie_mgun_idle_3"}				
		}	
	}
	{if human_stuff holding "bazooka"
		{random_select
			{weight 1	"lie_bazooka_idle_1"}
			{weight 1	"lie_bazooka_idle_2"}
			{weight 1	"lie_bazooka_idle_3"}				
		}	
	}
	{if human_stuff holding "pistol"
		{random_select
			{weight 1	"lie_pistol_idle_1"}
			{weight 1	"lie_pistol_idle_2"}
			{weight 1	"lie_pistol_idle_3"}				
		}	
	}
	{if human_stuff holding "nothing"
		{random_select
			{weight 1	"lie_empty_idle_1"}
			{weight 1	"lie_empty_idle_2"}
			{weight 1	"lie_empty_idle_3"}
			{weight 1	"lie_empty_idle_4"}		
		}	
	}	
	{anm "crawl" 0.1}
}
{lie_breath										;нужен для empty или small
	{if human_stuff holding "rifle"
		{anm "lie_rifle_idle"}
	}
	{if human_stuff holding "smg" "flamer"
		{anm "lie_smg_idle"}
	}
	{if human_stuff holding "mgun"
		{anm "lie_mgun_idle"}
	}
	{if human_stuff holding "bazooka"
		{anm "lie_bazooka_idle"}
	}
	{if human_stuff holding "pistol"
		{anm "lie_pistol_idle"}
	}
	{if human_stuff holding "nothing"
		{anm	"lie_empty_idle_0"}				
	}	
	{anm ""} ; animations required
}
; light up the cigarette
{stand_smoking_begin
	{anm "stand_smoke_1"}
}
; took a drag on a cigarette
{stand_smoking_process
	{anm "stand_smoke_2"}
}
; put out a cigarette
{stand_smoking_end
	{anm "stand_smoke_3"}
}
; standing with lighted cigarette
{stand_smoking_idle
	{anm ""}
}
{snipe_breath															;нужны айдлы с оружием для стоячего укрытия	
	{if human_stuff holding "rifle"
		{random_select
			{weight 1	"stand_look_around_gun_1"}
			{weight 1	"stand_look_around_gun_2"}
			{weight 1	"stand_look_around_gun_3"}			
		}
	}
	{if human_stuff holding "mgun" 
		{random_select
			{weight 1	"stand_look_around_mgun_1"}
			{weight 1	"stand_look_around_mgun_2"}
			{weight 1	"stand_look_around_mgun_3"}			
		}
	}
	{if human_stuff holding "pistol" 
		{random_select
			{weight 1	"stand_look_around_pistol_1"}
			{weight 1	"stand_look_around_pistol_2"}
			{weight 1	"stand_look_around_pistol_3"}
			{weight 1	"stand_look_around_pistol_4"}			
		}
	}	
	{if human_stuff holding "smg" "flamer"
		{random_select		
			{weight 1	"stand_look_around_gun_1"}			;нужны айдля для смг
			{weight 1	"stand_look_around_gun_2"}
			{weight 1	"stand_look_around_gun_3"}			
		}
	}	
	{if human_stuff holding "bazooka"
		{random_select
			{weight 1	"stand_look_around_bazooka_1"}
			{weight 1	"stand_look_around_bazooka_2"}	
			{weight 1	"stand_look_around_bazooka_3"}			
		}
	}
	{if human_stuff holding "1hand"
		{anm "stand_idle_1hand"}		
	}
	{if human_stuff holding "small"
		{random_select
			{weight 1	"stand_idle_empty_2"}			
			{weight 1	"stand_idle_empty_3"}
			{weight 1	"stand_idle_empty_4"}
		}
	}
	{if human_stuff holding "nothing"
		{if human_hold_strap
			{if able "attention"
				{anm "stand_idle_strap_1"}					
			}
			{random_select
					{weight 1	"stand_idle_strap_2"}
					{weight 1	"stand_idle_strap_3"}
					{weight 1	"stand_idle_strap_4"}
					{weight 1	"stand_idle_strap_5"}
			}
		}
		; no strap
		{if able "attention"
			{anm "stand_idle_empty_1"}
		}
		{random_select
			{weight 1	"stand_idle_empty_2"}			
			{weight 1	"stand_idle_empty_3"}
			{weight 1	"stand_idle_empty_4"}
		}		
	}
	{anm ""}
}
