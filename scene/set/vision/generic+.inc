;common rules
(define "arena_rules"
	{radius (* %0 1.5)}	
	{rules
		{human 1
			{stand 1
				{camouflage 0.5
					{stealth 0.4}
				}
				{stealth 0.5}
			}			
			{squat 0.8
				{camouflage 0.5
					{stealth 0.3}
				}
				{stealth 0.4}
			}
			{crawl 0.65
				{camouflage 0.5
					{stealth 0.2}
				}
				{stealth 0.3}				
			}			
		}
		{goliath 0.75
			{camouflage 0.375}
		}		
		{mg_stan_small 0.75
			{camouflage 0.375}
		}		
		{vehicle 1		
			{camouflage 0.5}
		}	
		{firing_silent_welrod 0}
		{firing_silent_nagan 0}
		{firing_silent_delisle 0}		
		{knife_ger 0}
		{knife_rus 0}
		{knife_union 0}
		{f1 0}
		{m18 0}
		{m24 0}
		{m24x7 0}
		{m39 0}
		{m61 0}
		{mk1 0}
		{molotov_coctail 0}
		{n73at 0}
		{pwm1 0}
		{rg42x3 0}
		{rpg40 0}
		{rpg43 0}
		{smoke 0}
		{type_3_at 0}
		{type_97 0}
		{signal_grenade 0}
		{sapper_shovel 0}
		{dynamite 0}		
		{firing 1}		
	}
)
(define "arena_rules_aa"
	{radius (* %0 1.5)}	
	{rules
		{human 1
			{stand 1
				{camouflage 0.5
					{stealth 0.4}
				}
				{stealth 0.5}
			}			
			{squat 0.8
				{camouflage 0.5
					{stealth 0.3}
				}
				{stealth 0.4}
			}
			{crawl 0.65
				{camouflage 0.5
					{stealth 0.2}
				}
				{stealth 0.3}				
			}			
		}
		{glider 0.1}
		{goliath 0.75
			{camouflage 0.375}
		}		
		{mg_stan_small 0.75
			{camouflage 0.375}
		}		
		{vehicle 1
			{camouflage 0.5}	
		}	
		{firing_silent_welrod 0}
		{firing_silent_nagan 0}
		{firing_silent_delisle 0}		
		{knife_ger 0}
		{knife_rus 0}
		{knife_union 0}
		{f1 0}
		{m18 0}
		{m24 0}
		{m24x7 0}
		{m39 0}
		{m61 0}
		{mk1 0}
		{molotov_coctail 0}
		{n73at 0}
		{pwm1 0}
		{rg42x3 0}
		{rpg40 0}
		{rpg43 0}
		{smoke 0}
		{type_3_at 0}
		{type_97 0}
		{signal_grenade 0}
		{sapper_shovel 0}
		{dynamite 0}		
		{firing 1}		
	}
)
(define "arena_rules_inf"
	{radius (* %0 1.5)}	
	{rules
		{human 1
			{stand 1
				{camouflage 0.5
					{stealth 0.4}
				}
				{stealth 0.5}
			}			
			{squat 0.8
				{camouflage 0.5
					{stealth 0.3}
				}
				{stealth 0.4}
			}
			{crawl 0.75
				{camouflage 0.5
					{stealth 0.2}
				}
				{stealth 0.3}				
			}			
		}
		{goliath 0.75
			{camouflage 0.375}
		}		
		{mg_stan_small 0.75
			{camouflage 0.375}
		}		
		{cannon 1
			{camouflage 0.5}
		}		
		{light 1.375
			{camouflage 0.5}
		}	
		{medium 1.375
			{camouflage 0.5}
		}
		{heavy 1.375
			{camouflage 0.5}
		}		
		{armored_car 1
			{camouflage 0.5}
		}		
		{firing_silent_welrod 0}
		{firing_silent_nagan 0}
		{firing_silent_delisle 0}		
		{knife_ger 0}
		{knife_rus 0}
		{knife_union 0}
		{f1 0}
		{m18 0}
		{m24 0}
		{m24x7 0}
		{m39 0}
		{m61 0}
		{mk1 0}
		{molotov_coctail 0}
		{n73at 0}
		{pwm1 0}
		{rg42x3 0}
		{rpg40 0}
		{rpg43 0}
		{smoke 0}
		{type_3_at 0}
		{type_97 0}
		{signal_grenade 0}
		{sapper_shovel 0}
		{dynamite 0}		
		{firing 1}		
	}
)
(define "arena_rules_antistealth"
	{radius (* %0 1.5)}	
	{rules
		{human 1
			{stand 1
				{camouflage 1
					{stealth 0.8}
				}
				{stealth 0.8}
			}			
			{squat 1
				{camouflage 1
					{stealth 0.7}
				}
				{stealth 0.7}
			}
			{crawl 1
				{camouflage 1
					{stealth 0.6}
				}
				{stealth 0.6}				
			}			
		}
		{vehicle 1
			{camouflage 1}
		}		
		{firing_silent_welrod 0}
		{firing_silent_nagan 0}
		{firing_silent_delisle 0}		
		{knife_ger 0}
		{knife_rus 0}
		{knife_union 0}
		{f1 0}
		{m18 0}
		{m24 0}
		{m24x7 0}
		{m39 0}
		{m61 0}
		{mk1 0}
		{molotov_coctail 0}
		{n73at 0}
		{pwm1 0}
		{rg42x3 0}
		{rpg40 0}
		{rpg43 0}
		{smoke 0}
		{type_3_at 0}
		{type_97 0}
		{signal_grenade 0}
		{sapper_shovel 0}
		{dynamite 0}		
		{firing 1}	
	}
)
(define "arena_rules_antistealth_inf"
	{radius (* %0 1.5)}	
	{rules
		{human 1
			{stand 1
				{camouflage 1
					{stealth 0.8}
				}
				{stealth 0.8}
			}			
			{squat 1
				{camouflage 1
					{stealth 0.7}
				}
				{stealth 0.7}
			}
			{crawl 1
				{camouflage 1
					{stealth 0.6}
				}
				{stealth 0.6}				
			}			
		}
		{cannon 1
			{camouflage 1}
		}		
		{light 1.375
			{camouflage 1}
		}	
		{medium 1.375
			{camouflage 1}
		}
		{heavy 1.375
			{camouflage 1}
		}		
		{armored_car 1
			{camouflage 1}
		}		
		{firing_silent_welrod 0}
		{firing_silent_nagan 0}
		{firing_silent_delisle 0}		
		{knife_ger 0}
		{knife_rus 0}
		{knife_union 0}
		{f1 0}
		{m18 0}
		{m24 0}
		{m24x7 0}
		{m39 0}
		{m61 0}
		{mk1 0}
		{molotov_coctail 0}
		{n73at 0}
		{pwm1 0}
		{rg42x3 0}
		{rpg40 0}
		{rpg43 0}
		{smoke 0}
		{type_3_at 0}
		{type_97 0}
		{signal_grenade 0}
		{sapper_shovel 0}
		{dynamite 0}		
		{firing 1}	
	}
)
(define "arena_rules_air_recon"
	{radius (* %0 1.5)}
	{rules
		{human 1
			{stealth 0}
			{camouflage 0}			
		}
		{vehicle 1
			{camouflage 0}
		}		
		{firing_silent_welrod 0}
		{firing_silent_nagan 0}
		{knife_ger 0}
		{knife_rus 0}
		{knife_union 0}
		{f1 0}
		{m18 0}
		{m24 0}
		{m24x7 0}
		{m39 0}
		{m61 0}
		{mk1 0}
		{molotov_coctail 0}
		{n73at 0}
		{pwm1 0}
		{rg42x3 0}
		{rpg40 0}
		{rpg43 0}
		{smoke 0}
		{type_3_at 0}
		{type_97 0}
		{signal_grenade 0}		
		{firing 1}	
	}
)
;HUMAN========================================
(define "vision_around_soldier"
	("arena_rules_inf" args %0)
	{uncover (* 0.1 %0)}	
	{h_fov 120}
	{v_fov 360}
)
(define "vision_around_soldier_antistealth"
	("arena_rules_antistealth_inf" args %0)
	{uncover (* 0.1 %0)}		
	{h_fov 120}
	{v_fov 360}
)
(define "glass_soldier_antistealth"
	("arena_rules_antistealth_inf" args %0)
	{uncover (* 1 %0)}		
	{h_fov 120}
	{v_fov 360}
)
(define "vision_around_human"
	("arena_rules_inf" args %0)
	{uncover (* 0.1 %0)}	
	{h_fov 360}
	{v_fov 360}
)
;VEHICLE======================================
(define "vision_around_vehicle"
	("arena_rules" args 2)
	{uncover (* 0.1 %0)}		
	{h_fov 360}
	{v_fov 360}
)
(define "vision_around_vehicle_antistealth"
	("arena_rules_antistealth" args %0)
	{uncover (* 0.1 %0)}		
	{h_fov 120}
	{v_fov 360}
)
(define "vision_optic"
	{radius (* %0 1.5)}
	{rules
		{human 0.6
			{firing 0.65}
			{cover 0.55
				{stealth 0.3}
				{stand 0.55}
				{squat 0.5}
				{crawl 0.35}
			}
			{squat 0.6
				{stealth 0.25}
			}
			{crawl 0.6
				{##still 0.15
					{stealth 0.17}
				}
				{stealth 0.22}
			}
		}


		{cannon_01 0.8			;heavy mgun, infantry mortar
			{firing 1}
			{visible 0.9}
;			{still 0.8}
		}
		{cannon_02 0.5    		;light gun
			{firing 1.1}
			{visible 0.8}
;			{still 0.45}
		}
		{cannon_03 0.7			;middle gun
			{firing 1.1}
			{visible 0.9}
;			{still 0.6}
		}
		{cannon_04 0.8			;heavy gun
			{firing 1.3}
			{visible 1.2}
;			{still 0.7}
		}
		{cannon_05 1			;howitzer
			{firing 1.5}
			{visible 1.5}
;			{still 0.8}
		}
		{vehicle_00 0.5			;moto
			{firing 0.6}
			{visible 0.7}
;			{still 0.45}
		}
		{vehicle_01 0.65		;jeep
			{firing 0.6}
			{visible 0.9}
;			{still 0.55}
		}
		{vehicle_02 0.7			;light armoredcars
			{firing 0.95}
			{visible 1}
;			{still 0.6}
		}
		{vehicle_03 0.75		;light SPA, armoredcars, trucks
			{firing 1.3}
			{visible 1.1}
;			{still 0.65}
		}
		{vehicle_04 0.8			;light tanks
			{firing 1.3}
			{visible 1.3}
;			{still 0.7}
		}
		{vehicle_04_spa 0.9		;middle SPA
			{firing 1.3}
			{visible 1.4}
;			{still 0.8}
		}
		{vehicle_05 1			;middle tanks
			{firing 1.3}
			{visible 1.4}
;			{still 0.9}
		}
		{vehicle_06 1.1			;heavy tanks
			{firing 1.4}
			{visible 1.5}
;			{still 1}
		}
		{vehicle_07 0.75		;rocket artillery
			{firing 1.5}
			{visible 1.1}
;			{still 0.65}
		}
	}
	{mods
		{stand 1}
	}
)

(define "vision_tankman"
	{radius (* %0 1.5)}
	{rules
		{human 1}

		{cannon_01 1}
		{cannon_02 1}
		{cannon_03 1}
		{cannon_04 1}
		{cannon_05 1}
		{vehicle_00 1}
		{vehicle_01 1}
		{vehicle_02 1}
		{vehicle_03 1}
		{vehicle_04 1}
		{vehicle_04_spa 1}
		{vehicle_05 1}
		{vehicle_06 1}
		{vehicle_07 1}
	}
)




(define "vision_human"
	{radius (* %0 1.5)}
	{rules
		{human 1
			{firing 1.5
				{firing_silent 0.1}
				{firing_delisle 0.2}
				{knife_ger 0.1}
				{knife_rus 0.1}
				{knife_union 0.1}
				{f1 0.1}
				{m18 0.1}
				{m24 0.1}
				{m24x7 0.1}
				{m39 0.1}
				{m61 0.1}
				{mk1 0.1}
				{molotov_coctail 0.1}
				{n73at 0.1}
				{pwm1 0.1}
				{rg42x3 0.1}
				{rpg40 0.1}
				{rpg43 0.1}
				{smoke 0.1}
				{type_3_at 0.1}
				{type_97 0.1}
				{squat 1.4}
				{crawl 1.3}
				{cover 1.3}
			}
			{cover 0.6
				{kamikaze 0.4}
				{sniper 0.4}
				{stealth 0.3}
				{stand 0.6}
				{squat 0.6}
				{crawl 0.6}
			}
			{squat 1
				{sniper 0.5}
				{stealth 0.5}
			}
			{crawl 1
				{still 0.55
					{kamikaze 0.4}
					{sniper 0.35}
					{stealth 0.25}
				}
				{kamikaze 0.5}
				{sniper 0.45}
				{stealth 0.4}
			}
;			{still 0.8}
		}

		{cannon_01 1			;heavy mgun, infantry mortar
			{firing 1.5}
			{visible 1.2}
;			{still 0.9}
		}
		{cannon_02 1.1    		;light gun
			{firing 1.5}
			{visible 1.2}
;			{still 1}
		}
		{cannon_03 1.4			;middle gun
			{firing 1.7}
			{visible 1.5}
;			{still 1.2}
		}
		{cannon_04 1.5			;heavy gun
			{firing 2}
			{visible 1.7}
;			{still 1.4}
		}
		{cannon_05 2			;howitzer
			{firing 2.5}
			{visible 1.7}
;			{still 1.8}
		}
		{vehicle_00 1.1			;moto
			{firing 1.6}
			{visible 1.3}
;			{still 0.9}
		}
		{vehicle_01 1.4			;jeep
			{firing 1.6}
			{visible 1.7}
;			{still 1}
		}
		{vehicle_02 1.4			;light armoredcars
			{firing 1.8}
			{visible 1.7}
;			{still 1.1}
		}
		{vehicle_03 1.6			;light SPA, armoredcars, trucks
			{firing 2.4}
			{visible 1.7}
;			{still 1.2}
		}
		{vehicle_04 1.8			;light tanks
			{firing 2.6}
			{visible 1.7}
;			{still 1.4}
		}
		{vehicle_04_spa 2		;middle SPA
			{firing 2.8}
			{visible 2.3}
;			{still 1.4}
		}
		{vehicle_05 2			;middle tanks
			{firing 2.8}
			{visible 2.3}
;			{still 1.6}
		}
		{vehicle_06 2.2			;heavy tanks
			{firing 3}
			{visible 2.5}
;			{still 2}
		}
		{vehicle_07 2			;rocket artillery
			{firing 3.6}
			{visible 2.5}
;			{still 1.8}
		}
	}
	{mods
		{stand 1}
	}
)

(define "vision_officer"
	{radius (* %0 1.5)}
	{rules
		{human 1
			{firing 1.5
				{firing_silent 0.1}
				{firing_delisle 0.2}
				{knife_ger 0.1}
				{knife_rus 0.1}
				{knife_union 0.1}
				{f1 0.1}
				{m18 0.1}
				{m24 0.1}
				{m24x7 0.1}
				{m39 0.1}
				{m61 0.1}
				{mk1 0.1}
				{molotov_coctail 0.1}
				{n73at 0.1}
				{pwm1 0.1}
				{rg42x3 0.1}
				{rpg40 0.1}
				{rpg43 0.1}
				{smoke 0.1}
				{type_3_at 0.1}
				{type_97 0.1}
				{squat 1.5}
				{crawl 1.5}
				{cover 1.3}
			}
			{cover 0.85
				{stand 0.7}
				{squat 0.7}
				{crawl 0.7}
				{stealth 0.7}
			}
			{squat 1
				{sniper 0.7}
				{stealth 0.7}
			}
			{crawl 1
				{still 0.6}
				{sniper 0.7}
				{stealth 0.6}
			}
;			{still 0.8}
		}

		{cannon_01 1.5			;heavy mgun, infantry mortar
			{firing 2}
			{visible 2}
;			{still 1.3}
		}
		{cannon_02 1.5    		;light gun
			{firing 1.8}
			{visible 1.8}
;			{still 1.4}
		}
		{cannon_03 1.5			;middle gun
			{firing 2}
			{visible 2}
;			{still 1.5}
		}
		{cannon_04 1.7			;heavy gun
			{firing 2}
			{visible 2}
;			{still 1.7}
		}
		{cannon_05 2			;howitzer
			{firing 2.5}
			{visible 2.5}
;			{still 2}
		}
		{vehicle_00 1.4			;moto, jeep
			{firing 1.7}
			{visible 1.7}
;			{still 1.1}
		}
		{vehicle_01 2			;moto, jeep
			{firing 2.1}
			{visible 2.1}
;			{still 2}
		}
		{vehicle_02 1.5			;light armoredcars
			{firing 2.1}
			{visible 2.1}
;			{still 1.5}
		}
		{vehicle_03 1.5			;light SPA, armoredcars, trucks
			{firing 2}
			{visible 2}
;			{still 1.5}
		}
		{vehicle_04 1.8			;light tanks
			{firing 2.2}
			{visible 2.2}
;			{still 1.8}
		}
		{vehicle_04_spa 2		;middle SPA
			{firing 2.3}
			{visible 2.3}
;			{still 2}
		}
		{vehicle_05 2.1			;middle tanks
			{firing 2.4}
			{visible 2.4}
;			{still 2.1}
		}
		{vehicle_06 2.2			;heavy tanks
			{firing 2.5}
			{visible 2.5}
;			{still 2.2}
		}
		{vehicle_07 2			;rocket artillery
			{firing 3}
			{visible 3}
;			{still 2}
		}
	}
	{mods
		{stand 1}
	}
)

(define "glass"
	{radius (* %0 1.5)}
)

(define "human_stand"
	{radius (* %0 1.5)}
	{rules
		{human 0.75
			{tankman2 1.5}
			{firing 1
				{firing_silent 0.2}
				{firing_delisle 0.2}
				{knife_ger 0.1}
				{knife_rus 0.1}
				{knife_union 0.1}
				{f1 0.1}
				{m18 0.1}
				{m24 0.1}
				{m24x7 0.1}
				{m39 0.1}
				{m61 0.1}
				{mk1 0.1}
				{molotov_coctail 0.1}
				{n73at 0.1}
				{pwm1 0.1}
				{rg42x3 0.1}
				{rpg40 0.1}
				{rpg43 0.1}
				{smoke 0.1}
				{type_3_at 0.1}
				{type_97 0.1}

				{squat 1.4}
				{crawl 1.4}
				{cover 1.2}
			}
			{crawl 0.75}
			{cover 0.75}
			{squat 0.75}
			{stealth 0.45}
;			{still 0.55}
		}

		{cannon_01 1.2			;станк.пулеметы, минометы
			{firing 1.5}
;			{still 1}
		}
		{cannon_02 1.5    		;легкие пушки, ...
			{firing 3}
;			{still 1.2}
		}
		{cannon_03 2			;средние пушки
			{firing 3.5}
;			{still 1.75}
		}
		{cannon_04 2.5			;тяжелые пушки
			{firing 4}
;			{still 2}
		}
		{cannon_05 3			;гаубицы
			{firing 5}
;			{still 2.5}
		}
		{vehicle_00 1.5
			{firing 2.5}
;			{still 1.3}
		}
		{vehicle_01 2
			{firing 3}
;			{still 1.75}
		}
		{vehicle_02 2.5
			{firing 3}
;			{still 2}
		}
		{vehicle_03 2.75
			{firing 3.25}
;			{still 2.25}
		}
		{vehicle_04 3
			{firing 3.5}
;			{still 2.25}
		}
		{vehicle_04_spa 3		;средние сау
			{firing 3.5}
;			{still 2.5}
		}
		{vehicle_05 3.25
			{firing 5}
;			{still 2.75}
		}
		{vehicle_06 3.5
			{firing 4}
;			{still 3}
		}
		{vehicle_07 3
			{firing 5}
;			{still 2.25}
		}
	}
	{mods
		{stand 1}
		{kamikaze 0.8}
	}
)