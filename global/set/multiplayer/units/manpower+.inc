{units
    (include "soldiers_manpower.inc")
	(define "ch"
		{charge %c} {fore (/ %fore %c)} {dont_unfog_by_territory}
	)


    ;{"pz4g_inf"				{tags "man_power"} {cost 135} {button "01_squad1"} ("ch" c(240) fore(-360))}	
    ;{"t34_2_inf"			{tags "man_power"} {cost 135} {button "01_squad1"} ("ch" c(240) fore(-360))}	
    ;{"m4a3dd_inf"			{tags "man_power"} {cost 135} {button "01_squad1"} ("ch" c(240) fore(-360))}
    ;{"opel_blitz_highback"	{tags "man_power"} {cost 31} {button "01_squad1"} {group "motorised"} ("ch" c(30) fore(-30))}
    ;{"gaz_aa_untented"		{tags "man_power"} {cost 31} {button "01_squad1"} {group "motorised"} ("ch" c(30) fore(-30))}
    ;{"gmc_inf"				{tags "man_power"} {cost 31} {button "01_squad1"} {group "motorised"} ("ch" c(30) fore(-30))}	
    ;{"universal_carrier_inf_usa"	{tags "man_power"} {cost 35} {button "01_squad1"} {group "motorised"} ("ch" c(60) fore(0))}	
    ;{"m2"			{tags "man_power"} {cost 45} {button "01_squad1"} {group "motorised"} ("ch" c(60) fore(0))}	
    ;{"m3_scout"		{tags "man_power"} {cost 50} {button "01_squad1"} ("ch" c(60) fore(-270))}
    ;{"m3_ally"		{tags "man_power"} {cost 40} {button "01_squad1"} {group "motorised"} ("ch" c(60) fore(0))}
    ;{"m4a1_inf"		{tags "man_power"} {cost 100} {button "special"} ("ch" c(240) fore(-340))}
	;{"pz4f2_inf"	{tags "man_power"} {cost 100} {button "special"} ("ch" c(240) fore(-340))}
	;{"t34_76_inf"	{tags "man_power"} {cost 100} {button "special"} ("ch" c(240) fore(-340))}	
	;{"bombermans(usa)"				{tags "man_power"} {cost 15} {button "02_squad2"} ("ch" c(10) fore(10))}
	;{"at_rifle(rus)"				{tags "man_power"} {cost 8} {button "02_squad2"} ("ch" c(15) fore(15))
	;                                {content "arena_mp/rus/at_rifle:1"}
	;}
	;{"scouts(ger)"					{tags "man_power"} {cost 45} {button "02_squad2"} ("ch" c(60) fore(-180))}
	;{"scouts(rus)"					{tags "man_power"} {cost 45} {button "02_squad2"} ("ch" c(60) fore(-180))}	
	;{"scouts(usa)"					{tags "man_power"} {cost 45} {button "02_squad2"} ("ch" c(60) fore(-180))}
	;{"sappers_veteran(ger)"				{tags "man_power"} {cost 30} {button "02_squad2"} ("ch" c(30) fore(-270))}	
	;{"sappers_veteran(rus)"				{tags "man_power"} {cost 30} {button "02_squad2"} ("ch" c(30) fore(-270))}
	;{"sappers_veteran(usa)"				{tags "man_power"} {cost 30} {button "02_squad2"} ("ch" c(30) fore(-270))}
	;{"mg34_stan"						{tags "man_power"} {cost 20} {button "04_cannon"} ("ch" c(120) fore(0))}	
	;{"smgs_rookie_ppd(rus)"		{tags "man_power"} {cost 25} {button "special"} ("ch" c(60) fore(-60))}
	;{"mg34_sit"					{tags "man_power"} {cost 25} {button "special"} ("ch" c(120) fore(0))}
	;{"at_rifle_solothurn(ger)"	{tags "man_power"} {cost 25} {button "special"} ("ch" c(60) fore(-60))}
	;{"rifle_grenadiers(rus)"	{tags "man_power"} {cost 25} {button "special"} ("ch" c(60) fore(-120))}	
	;{"at_rifle(usa)"			{tags "man_power"} {cost 25} {button "special"} ("ch" c(15) fore(-45))}
    ;{"is2_early"	{tags "man_power"} {cost 150} {button "special"} ("ch" c(240) fore(-775))}
	;{"t40"			                    {tags "man_power"} {cost 40} {button "05_light_armor"} ("ch" c(120) fore(60))}
	;{"pz2l"						{tags "man_power"} {cost 35} {button "special"} ("ch" c(120) fore(-120))}
	;{"t26e"						{tags "man_power"} {cost 30} {button "special"} ("ch" c(120) fore(0))}	
	;{"1927_cannon_trailer(rus)"	{tags "man_power"} {cost 40} {button "special"} ("ch" c(180) fore(-120))}	
	;{"ab41"	{tags "man_power"} {cost 35} {button "special"} ("ch" c(180) fore(-60))}	
	;{"m4a3dd"				{tags "man_power"} {cost 80} {button "special"} ("ch" c(240) fore(-240))}
	;{"is2"					            {tags "man_power"} {cost 330} {button "06_armor"} ("ch" c(180) fore(-775))}
	;{"mgs(ger)"				        {tags "man_power"} {cost 33} {button "01_squad1"} {group "mgs"} ("ch" c(30) fore(-30))
	;						        {content "arena_mp/ger/rifle:1 arena_mp/ger/mgun_supporter:1 arena_mp/ger/mgun:1 arena_mp/ger/mgun_commander:1 arena_mp/ger/mgun:1 arena_mp/ger/mgun_supporter:1 arena_mp/ger/rifle:1"}
	;}                               
	;{"mgs(rus)"				        {tags "man_power"} {cost 33} {button "01_squad1"} {group "mgs"} ("ch" c(30) fore(-30))
	;						        {content "arena_mp/rus/rifle:1 arena_mp/rus/mgun_supporter:1 arena_mp/rus/mgun:1 arena_mp/rus/mgun_commander:1 arena_mp/rus/mgun:1 arena_mp/rus/mgun_supporter:1 arena_mp/rus/rifle:1"}
	;}	                            
	;{"mgs(usa)"				        {tags "man_power"} {cost 37} {button "01_squad1"} {group "mgs"} ("ch" c(30) fore(-30))
	;						        {content "arena_mp/usa/rifle:1 arena_mp/usa/mgun_supporter:1 arena_mp/usa/mgun:1 arena_mp/usa/mgun_commander:1 arena_mp/usa/mgun:1 arena_mp/usa/mgun_supporter:1 arena_mp/usa/rifle:1"}
	;}
;=======01_squad1=======
;rus
    {"recruits_squad(rus)"				{tags "man_power infantry_only"} {cost 40} {button "01_squad1"} {group "infantry"} {icon 100} ("ch" c(30) fore(30))}   
    {"infantry_squad(rus)"				{tags "man_power infantry_only"} {cost 75} {button "01_squad1"} {group "infantry_1"} {icon 101} ("ch" c(30) fore(30))}
	{"hunters(rus)"					    {tags "man_power infantry_only"} {cost 80} {button "01_squad1"} {group "infantry_1"} {icon 102} ("ch" c(60) fore(60))
	                                    {content "arena_mp/rus/hunter_ai_commander:1 arena_mp/rus/hunter:3"}
	}
	{"assault_squad(rus)"				{tags "man_power infantry_only"} {cost 90} {button "01_squad1"} {group "infantry_1"} {icon 103} ("ch" c(30) fore(30))}
	{"mgs_late(rus)"                    {tags "man_power infantry_only"} {cost 100} {button "01_squad1"} {group "infantry_1"} {icon 104} ("ch" c(30) fore(-90))
	                                    {content "arena_mp/rus/mgun_supporter_late:1 arena_mp/rus/mgun_late:1 arena_mp/rus/mgun_commander_late:1 arena_mp/rus/mgun_late:1 arena_mp/rus/mgun_supporter_late:1 arena_mp/rus/smg:2"}
	}
	{"marines(rus)"					    {tags "man_power infantry_only"} {cost 125} {button "01_squad1"} {group "infantry_2"} {icon 105} ("ch" c(60) fore(-180))
									    {content "arena_mp/rus/marine:2 arena_mp/rus/marine_mgun:1 arena_mp/rus/marine:1 arena_mp/rus/marine_avs:1 arena_mp/rus/marine:1 arena_mp/rus/marine_mgun:1 arena_mp/rus/marine:1"}	
	}
	{"stormtroopers(rus)"			    {tags "man_power infantry_only"} {cost 175} {button "01_squad1"} {group "infantry_3"} {icon 106} ("ch" c(120) fore(-540))
									    {content "arena_mp/rus/sturmovik:3 arena_mp/rus/sturmovik_rifle:2 arena_mp/rus/sturmovik_atr:1 arena_mp/rus/sturmovik_flame:1  arena_mp/rus/sturmovik_mgun:1"}
	}
    {"paratroopers(rus)"				{tags "man_power infantry_only"} {cost 160} {button "01_squad1"} {group "paratroopers"} {icon 107} ("ch" c(120) fore(-540))
										{content "dc-47_rus ( arena_mp/rus/pilot:2 arena_mp/rus/paratrooper:5 arena_mp/rus/paratrooper_mgun:1 )"}
	}
	{"saboteurs(rus)"		            {tags "man_power infantry_only saboteurs"} {cost 220} {button "01_squad1"} {icon 108} ("ch" c(360) fore(-320))}
    {"t20"				               	{tags "man_power"} {cost 125} {button "01_squad1"} {icon 109} ("ch" c(120) fore(-60))}
    {"m3_g"				                {tags "man_power"} {cost 175} {button "01_squad1"} {group "infantry_2"} {icon 110} ("ch" c(120) fore(-540))}	
	{"riflemans_reserv(rus)"				{tags "infantry_only"} {cost 65} {button "01_squad1"} {group "infantry"} {icon 111} ("ch" c(60) fore(-30))}
;ger    
	{"recruits_squad(ger)"				{tags "man_power infantry_only"} {cost 40} {button "01_squad1"} {group "infantry"} {icon 100} ("ch" c(30) fore(30))}
	{"infantry_squad(ger)"				{tags "man_power infantry_only"} {cost 75} {button "01_squad1"} {group "infantry_1"} {icon 101} ("ch" c(30) fore(30))}
	{"hunters(ger)"					    {tags "man_power infantry_only"} {cost 80} {button "01_squad1"} {group "infantry_1"} {icon 102} ("ch" c(60) fore(60))
	                                    {content "arena_mp/ger/hunter_ai_commander:1 arena_mp/ger/hunter:3"}
	}	
	{"assault_squad(ger)"				{tags "man_power infantry_only"} {cost 90} {button "01_squad1"} {group "infantry_1"} {icon 103} ("ch" c(30) fore(30))}
	{"mgs_late(ger)"                    {tags "man_power infantry_only"} {cost 100} {button "01_squad1"} {group "infantry_1"} {icon 104} ("ch" c(30) fore(-90))
	                                    {content "arena_mp/ger/mgun_supporter_late:1 arena_mp/ger/mgun_late:1 arena_mp/ger/mgun_commander_late:1 arena_mp/ger/mgun_late:1 arena_mp/ger/mgun_supporter_late:1 arena_mp/ger/smg:2"}
	}
	{"edelweiss(ger)"				    {tags "man_power infantry_only"} {cost 125} {button "01_squad1"} {group "infantry_2"} {icon 105} ("ch" c(60) fore(-180))
									    {content "arena_mp/ger/edelweiss:1 arena_mp/ger/edelweiss_g43:2 arena_mp/ger/edelweiss_fg42:1 arena_mp/ger/edelweiss_mgun:1 arena_mp/ger/edelweiss_g43:2 arena_mp/ger/edelweiss:1"}
	}
	{"grenadiers(ger)"				    {tags "man_power infantry_only"} {cost 175} {button "01_squad1"} {group "infantry_2"} {icon 106} ("ch" c(120) fore(-540))
									    {content "arena_mp/ger/grenadier:2 arena_mp/ger/grenadier_pfaust:2 arena_mp/ger/grenadier_mgun:1 arena_mp/ger/grenadier_pfaust:1 arena_mp/ger/grenadier:2"}
	}
	{"sturmpioneers(ger)"				{tags "man_power infantry_only"} {cost 175} {button "01_squad1"} {group "infantry_3"} {icon 107} ("ch" c(120) fore(-540))
										{content "arena_mp/ger/sturmpioneer_saper:2 arena_mp/ger/sturmpioneer_mgun:1 arena_mp/ger/sturmpioneer_flamer:1 arena_mp/ger/sturmpioneer_commander:1 arena_mp/ger/sturmpioneer_flamer:1 arena_mp/ger/sturmpioneer_radioman:1 arena_mp/ger/sturmpioneer_mgun:1 arena_mp/ger/sturmpioneer_saper:2"}	
	}
	{"paratroopers(ger)"				{tags "man_power infantry_only"} {cost 160} {button "01_squad1"} {group "paratroopers"} {icon 108} ("ch" c(120) fore(-790))
										{content "ju-52 ( arena_mp/ger/pilot:3 arena_mp/ger/paratrooper:5 arena_mp/ger/paratrooper_mgun:1 )"}	
	}
	{"saboteurs(ger)"		            {tags "man_power infantry_only saboteurs"} {cost 220} {button "01_squad1"} {icon 109} ("ch" c(360) fore(-320))}
	{"sdkfz251c"	                    {tags "man_power"} {cost 125} {button "01_squad1"} {group "motorised"} {icon 110} ("ch" c(120) fore(-60))}
	{"stormtroopers(ger)"	            {tags "man_power"} {cost 200} {button "01_squad1"} {group "infantry_3"} {icon 111} ("ch" c(120) fore(-540))}
;usa	
	{"recruits_squad(usa)"				{tags "man_power infantry_only"} {cost 40} {button "01_squad1"} {group "infantry"} {icon 100} ("ch" c(30) fore(30))}
	{"infantry_squad(usa)"				{tags "man_power infantry_only"} {cost 75} {button "01_squad1"} {group "infantry_1"} {icon 101} ("ch" c(30) fore(30))}
	{"hunters(usa)"					    {tags "man_power infantry_only"} {cost 80} {button "01_squad1"} {group "infantry_1"} {icon 102} ("ch" c(60) fore(60))
	                                    {content "arena_mp/usa/hunter_ai_commander:1 arena_mp/usa/hunter:3"}
	}
	{"assault_squad(usa)"				{tags "man_power infantry_only"} {cost 90} {button "01_squad1"} {group "infantry_1"} {icon 103} ("ch" c(30) fore(30))}
	{"mgs_late(usa)"                    {tags "man_power infantry_only"} {cost 100} {button "01_squad1"} {group "infantry_1"} {icon 104} ("ch" c(30) fore(-90))
	                                    {content "arena_mp/usa/mgun_supporter_late:1 arena_mp/usa/mgun_late:1 arena_mp/usa/mgun_commander_late:1 arena_mp/usa/mgun_late:1 arena_mp/usa/mgun_supporter_late:1 arena_mp/usa/smg:2"}
	}
	{"marines(usa)"					    {tags "man_power infantry_only"} {cost 125} {button "01_squad1"} {group "infantry_2"} {icon 105} ("ch" c(60) fore(-180))
									    {content "arena_mp/usa/marine_bar:1 arena_mp/usa/marine:2 arena_mp/usa/marine_radioman:1 arena_mp/usa/marine:1 arena_mp/usa/marine_mgun:1 arena_mp/usa/marine_bar:1 arena_mp/usa/marine:1"}
	}
	{"stormtroopers(usa)"			    {tags "man_power infantry_only"} {cost 175} {button "01_squad1"} {group "infantry_3"} {icon 106} ("ch" c(120) fore(-540))
									    {content "arena_mp/usa/ranger:2 arena_mp/usa/ranger_mgun:1 arena_mp/usa/ranger_shotgun:2  arena_mp/usa/ranger_mgun:1 arena_mp/usa/ranger:2"}
	}
	{"paratroopers(usa)"				{tags "man_power infantry_only"} {cost 160} {button "01_squad1"} {group "paratroopers"} {icon 107} ("ch" c(120) fore(-790))
										{content "dc-47 ( arena_mp/usa/pilot:2 arena_mp/usa/paratrooper:5 arena_mp/usa/paratrooper_mgun:1 )"}	
	}
	{"saboteurs(usa)"		            {tags "man_power infantry_only saboteurs"} {cost 220} {button "01_squad1"} {icon 108} ("ch" c(360) fore(-320))}
	{"paratroopers_elite(usa)"			{tags "man_power infantry_only"} {cost 200} {button "01_squad1"} {group "paratroopers"} {icon 109} ("ch" c(120) fore(-840))
										{content "dc-47 ( arena_mp/usa/pilot:2 arena_mp/usa/paratrooper_elite:2 arena_mp/usa/paratrooper_elite_mgun:1 arena_mp/usa/paratrooper_elite_smg:3 )"}	
	}
	{"m3_ally_g"	                    {tags "man_power"} {cost 175} {button "01_squad1"} {group "infantry_2"} {icon 110} ("ch" c(120) fore(-540))}	
	{"m2_ally"		                    {tags "man_power"} {cost 150} {button "01_squad1"} {icon 111} ("ch" c(120) fore(-60))}
	
	
;=======02_squad2=======
;rus    
    {"riflemans(rus)"				    {tags "man_power infantry_only single"} {cost 8} {button "02_squad2"} {icon 201} ("ch" c(1) fore(1))
	                                    {content "arena_mp/rus/rifle:1"}
	}                                   
    {"smgs(rus)"					    {tags "man_power infantry_only single"} {cost 10} {button "02_squad2"} {icon 202} ("ch" c(1) fore(1))
	                                    {content "arena_mp/rus/smg:1"}
	}
    {"mgs(rus)"				            {tags "man_power infantry_only"} {cost 25} {button "02_squad2"} {icon 203} ("ch" c(15) fore(15))
							            {content "arena_mp/rus/mgun:1 arena_mp/rus/mgun_supporter:1"}
	}	
	{"at_rifle_ptrs(rus)"			    {tags "man_power"} {cost 30} {button "02_squad2"} {icon 204} ("ch" c(15) fore(15))
	                                    {content "arena_mp/rus/at_rifle_ptrs:1 arena_mp/rus/smg:1"}
	}                                   
    {"bazookers(rus)"				    {tags "man_power"} {cost 40} {button "02_squad2"} {icon 205} ("ch" c(15) fore(15))}
    {"flamers(rus)"					    {tags "man_power infantry_only"} {cost 40} {button "02_squad2"} {icon 206} ("ch" c(30) fore(-270))
										{content "arena_mp/rus/flamer:1 arena_mp/rus/bottle_thrower:1"}
	}
	{"snipers(rus)"					    {tags "man_power infantry_only snipers"} {cost 100} {button "02_squad2"} {icon 207} ("ch" c(60) fore(-240))
	                                    {content "arena_mp/rus/sniper:1"}
	}	
	{"arty_spotters(rus)"			    {tags "man_power infantry_only spotters"} {cost 70} {button "02_squad2"} {icon 208} ("ch" c(60) fore(-240))
	                                    {content "arena_mp/rus/arty_spotter:1"}
	}
	;{"officer(rus)"				        {tags "man_power infantry_only officer"} {cost 70} {button "02_squad2"} {icon 209} ("ch" c(300) fore(0))}
	{"sappers(rus)"					    {tags "man_power infantry_only"} {cost 40} {button "02_squad2"} {icon 210} ("ch" c(180) fore(0))
										{content "arena_mp/rus/saper_veteran:1 arena_mp/rus/saper:2"}
	}
	{"tankmans(rus)"				    {tags "man_power tanks_only crewman"} {cost 20} {button "02_squad2"} {icon 211} ("ch" c(30) fore(-60))}
    {"artman(rus)"					    {tags "man_power crewman"} {cost 20} {button "02_squad2"} {icon 212} ("ch" c(30) fore(-60))}	
;ger                                    	
    {"riflemans(ger)"				    {tags "man_power infantry_only single"} {cost 8} {button "02_squad2"} {icon 201} ("ch" c(1) fore(1))
	                                    {content "arena_mp/ger/rifle:1"}
	}                                   
    {"smgs(ger)"					    {tags "man_power infantry_only single"} {cost 10} {button "02_squad2"} {icon 202} ("ch" c(1) fore(1))
	                                    {content "arena_mp/ger/smg:1"}
	}
    {"mgs(ger)"				            {tags "man_power infantry_only"} {cost 25} {button "02_squad2"} {icon 203} ("ch" c(15) fore(15))
							            {content "arena_mp/ger/mgun:1 arena_mp/ger/mgun_supporter:1"}
	}	
    {"at_rifle(ger)"				    {tags "man_power"} {cost 25} {button "02_squad2"} {icon 204} ("ch" c(15) fore(15))
	                                    {content "arena_mp/ger/at_rifle:1 arena_mp/ger/smg:1"}
	}
	{"at_rifle_solothurn(ger)"			{tags "man_power officer"} {cost 35} {button "02_squad2"} {icon 205} ("ch" c(180) fore(0))
	                                    {content "arena_mp/ger/at_rifle_solothurn:2 arena_mp/ger/smg:1"}
	}
    {"rifle_panzerfaust(ger)"		    {tags "man_power"} {cost 14} {button "02_squad2"} {icon 206} ("ch" c(15) fore(15))
	                                    {content "arena_mp/ger/rifle_panzerfaust:1"}
	}
    {"bazookers(ger)"				    {tags "man_power"} {cost 40} {button "02_squad2"} {icon 207} ("ch" c(15) fore(15))}
    {"flamers(ger)"					    {tags "man_power infantry_only"} {cost 40} {button "02_squad2"} {icon 208} ("ch" c(30) fore(-270))
										{content "arena_mp/ger/flamer:1 arena_mp/ger/smg:1"}
	}
	{"snipers(ger)"					    {tags "man_power infantry_only snipers"} {cost 100} {button "02_squad2"} {icon 209} ("ch" c(60) fore(-240))
	                                    {content "arena_mp/ger/sniper:1"}
	}
	{"arty_spotters(ger)"			    {tags "man_power infantry_only spotters"} {cost 70} {button "02_squad2"} {icon 210} ("ch" c(60) fore(-240))
	                                    {content "arena_mp/ger/arty_spotter:1"}
	}
	;{"officer(ger)"				        {tags "man_power infantry_only officer"} {cost 70} {button "02_squad2"} {icon 210} ("ch" c(300) fore(0))}
	{"sappers(ger)"					    {tags "man_power infantry_only"} {cost 40} {button "02_squad2"} {icon 211} ("ch" c(180) fore(0))
										{content "arena_mp/ger/saper_veteran:1 arena_mp/ger/saper:2"}
	}
	{"tankmans(ger)"				    {tags "man_power tanks_only crewman"} {cost 20} {button "02_squad2"} {icon 212} ("ch" c(30) fore(-60))}	
    {"artman(ger)"					    {tags "man_power crewman"} {cost 20} {button "02_squad2"} {icon 213} ("ch" c(30) fore(-60))}	
;usa	                                		
	{"riflemans(usa)"				    {tags "man_power infantry_only single"} {cost 10} {button "02_squad2"} {icon 201} ("ch" c(1) fore(1))
	                                    {content "arena_mp/usa/rifle:1"}
	}                                   
	{"smgs(usa)"					    {tags "man_power infantry_only single"} {cost 10} {button "02_squad2"} {icon 202} ("ch" c(1) fore(1))
	                                    {content "arena_mp/usa/smg:1"}
	}
    {"mgs(usa)"				            {tags "man_power infantry_only"} {cost 20} {button "02_squad2"} {icon 203} ("ch" c(15) fore(15))
							            {content "arena_mp/usa/mgun:1 arena_mp/usa/mgun_supporter:1"}
	}
    {"at_rifle(usa)"			        {tags "man_power"} {cost 30} {button "02_squad2"} {icon 204} ("ch" c(15) fore(15))
	                                    {content "arena_mp/usa/at_rifle:1 arena_mp/usa/smg:1"}
	}	
	{"bazookers(usa)"				    {tags "man_power"} {cost 40} {button "02_squad2"} {icon 205} ("ch" c(15) fore(15))}
	{"flamers(usa)"					    {tags "man_power infantry_only"} {cost 40} {button "02_squad2"} {icon 206} ("ch" c(30) fore(-270))
										{content "arena_mp/usa/flamer:1 arena_mp/usa/smg:1"}
	}
    {"snipers(usa)"					    {tags "man_power infantry_only snipers"} {cost 100} {button "02_squad2"} {icon 207} ("ch" c(60) fore(-240))
	                                    {content "arena_mp/usa/sniper:1"}
	}
    {"arty_spotters(usa)"			    {tags "man_power infantry_only spotters"} {cost 70} {button "02_squad2"} {icon 208} ("ch" c(60) fore(-240))
	                                    {content "arena_mp/usa/arty_spotter:1"}
	}
	;{"officer(usa)"				        {tags "man_power infantry_only officer"} {cost 70} {button "02_squad2"} {icon 209} ("ch" c(300) fore(0))}	
    {"sappers(usa)"					    {tags "man_power infantry_only"} {cost 40} {button "02_squad2"} {icon 210} ("ch" c(180) fore(0))
										{content "arena_mp/usa/saper_veteran:1 arena_mp/usa/saper:2"}
	}
	{"tankmans(usa)"				    {tags "man_power tanks_only crewman"} {cost 20} {button "02_squad2"} {icon 211} ("ch" c(30) fore(-60))}
	{"artman(usa)"					    {tags "man_power crewman"} {cost 20} {button "02_squad2"} {icon 212} ("ch" c(30) fore(-60))}
	
	
 
    {"engineers(rus)"					{tags "man_power infantry_only engineers"} {cost 15} {button "02_squad2"} {icon 224} ("ch" c(1) fore(1))}
    {"engineers(ger)"					{tags "man_power infantry_only engineers"} {cost 15} {button "02_squad2"} {icon 224} ("ch" c(1) fore(1))}		
	{"engineers(usa)"					{tags "man_power infantry_only engineers"} {cost 15} {button "02_squad2"} {icon 224} ("ch" c(1) fore(1))}
	{"uni_miners(rus)"					{tags "man_power infantry_only uni_miners"} {cost 25} {button "02_squad2"} {icon 225} ("ch" c(1) fore(1))}
    {"uni_miners(ger)"					{tags "man_power infantry_only uni_miners"} {cost 25} {button "02_squad2"} {icon 225} ("ch" c(1) fore(1))}		
	{"uni_miners(usa)"					{tags "man_power infantry_only uni_miners"} {cost 25} {button "02_squad2"} {icon 225} ("ch" c(1) fore(1))}
	{"corpsman(rus)"					{tags "man_power infantry_only corpsman"} {cost 5} {button "02_squad2"} {icon 226} ("ch" c(1) fore(1))}
	{"corpsman(ger)"					{tags "man_power infantry_only corpsman"} {cost 5} {button "02_squad2"} {icon 226} ("ch" c(1) fore(1))}	
	{"corpsman(usa)"					{tags "man_power infantry_only corpsman"} {cost 5} {button "02_squad2"} {icon 226} ("ch" c(1) fore(1))}
	
	
;=======03_car=======    
    {"inventory_crate_ger"		        {tags "man_power infantry_only crate"} {cost 10} {button "03_car"} {cp 1} {icon 301} ("ch" c(30) fore(30))}
	{"inventory_crate_rus"		        {tags "man_power infantry_only crate"} {cost 10} {button "03_car"} {cp 1} {icon 301} ("ch" c(30) fore(30))}
	{"inventory_crate_usa"		        {tags "man_power infantry_only crate"} {cost 10} {button "03_car"} {cp 1} {icon 301} ("ch" c(30) fore(30))}
	{"opel_blitz"		            	{tags "man_power supp"} {cost 10} {button "03_car"} {cp 1} {icon 302} ("ch" c(60) fore(60))}
	{"gaz_aa"			            	{tags "man_power supp"} {cost 10} {button "03_car"} {cp 1} {icon 302} ("ch" c(60) fore(60))}
	{"gmc"				            {tags "man_power supp"} {cost 10} {button "03_car"} {cp 1} {icon 302} ("ch" c(60) fore(60))}
	{"opel_blitz_supp"		            {tags "man_power supp tanks_only"} {cost 30} {button "03_car"} {cp 1} {icon 303} ("ch" c(60) fore(-120))}
	{"gaz_aa_supp"			            {tags "man_power supp tanks_only"} {cost 30} {button "03_car"} {cp 1} {icon 303} ("ch" c(60) fore(-120))}
	{"gmc_supp"				            {tags "man_power supp tanks_only"} {cost 30} {button "03_car"} {cp 1} {icon 303} ("ch" c(60) fore(-120))}
	{"opel_blitz_fuel"		            {tags "man_power supp tanks_only"} {cost 15} {button "03_car"} {cp 1} {icon 304} ("ch" c(60) fore(-120))}
	{"gaz_aa_fuel"			            {tags "man_power supp tanks_only"} {cost 15} {button "03_car"} {cp 1} {icon 304} ("ch" c(60) fore(-120))}
	{"gmc_fuel"				            {tags "man_power supp tanks_only"} {cost 15} {button "03_car"} {cp 1} {icon 304} ("ch" c(60) fore(-120))}
	{"opel_blitz_med"		            {tags "man_power supp tanks_only"} {cost 15} {button "03_car"} {cp 1} {icon 305} ("ch" c(60) fore(-120))}
	{"gaz_aa_med"			            {tags "man_power supp"} {cost 15} {button "03_car"} {cp 1} {icon 305} ("ch" c(60) fore(-120))}
	{"dodge_med"			            {tags "man_power supp"} {cost 15} {button "03_car"} {cp 1} {icon 305} ("ch" c(60) fore(-120))}	
	
;rus
	{"m72"		                        {tags "man_power"} {cost 55} {button "03_car"} {cp 5} {icon 311} ("ch" c(60) fore(20))}
	{"gaz67b"	                        {tags "man_power"} {cost 70} {button "03_car"} {cp 5} {icon 312} ("ch" c(60) fore(20))}
	{"dshk_aaa"					        {tags "man_power"} {cost 75} {button "03_car"} {cp 7} {icon 313} ("ch" c(180) fore(-180))}	
;ger	
	{"r12"		                        {tags "man_power"} {cost 55} {button "03_car"} {cp 5} {icon 311} ("ch" c(60) fore(20))}
	{"kubel_mgun"	                    {tags "man_power"} {cost 70} {button "03_car"} {cp 5} {icon 312} ("ch" c(60) fore(20))}
;usa	
	{"hd"		                        {tags "man_power"} {cost 55} {button "03_car"} {cp 5} {icon 311} ("ch" c(60) fore(20))}
    {"willysmb"	                        {tags "man_power"} {cost 70} {button "03_car"} {cp 5} {icon 312} ("ch" c(60) fore(20))}
	{"willysat_mgun"					{tags "man_power"} {cost 85} {button "03_car"} {cp 5} {icon 313} ("ch" c(120) fore(-20))}
    {"willysat"	                        {tags "man_power"} {cost 90} {button "03_car"} {cp 11} {icon 314} ("ch" c(180) fore(100))}	
	
;=======04_cannon=======      
;rus
    {"maxim"							{tags "man_power"} {cost 40} {button "04_cannon"} {cp 5} {icon 401} ("ch" c(120) fore(0))}
	{"degtyarev_stan"					{tags "man_power"} {cost 40} {button "04_cannon"} {cp 5} {icon 402} ("ch" c(120) fore(0))}   
	{"61k_trailer(rus)"					{tags "man_power"} {cost 100} {button "04_cannon"} {icon 403} ("ch" c(240) fore(-120))}
	{"52k_trailer(rus)"					{tags "man_power"} {cost 350} {button "04_cannon"} {icon 404} ("ch" c(300) fore(-440))}
    {"rm38"								{tags "man_power art"} {cost 70} {button "04_cannon"} {cp 11} {icon 405} ("ch" c(120) fore(40))}
    {"bm37"								{tags "man_power art"} {cost 90} {button "04_cannon"} {cp 14} {icon 406} ("ch" c(180) fore(0))}
    {"pm41"								{tags "man_power art"} {cost 120} {button "04_cannon"} {cp 16} {icon 407} ("ch" c(300) fore(-180))}
    {"1943_cannon_trailer(rus)"			{tags "man_power"} {cost 120} {button "04_cannon"} {icon 408} ("ch" c(180) fore(0))}	
	{"53k_trailer(rus)"			        {tags "man_power"} {cost 75} {button "04_cannon"} {icon 409} ("ch" c(120) fore(40))}
	{"m42_trailer(rus)"			        {tags "man_power"} {cost 90} {button "04_cannon"} {icon 410} ("ch" c(180) fore(-180))}
	{"zis3_trailer(rus)"		        {tags "man_power"} {cost 150} {button "04_cannon"} {icon 411} ("ch" c(180) fore(-240))}
	{"zis2_trailer(rus)"		        {tags "man_power"} {cost 155} {button "04_cannon"} {icon 412} ("ch" c(180) fore(-400))}
	{"bs3_trailer(rus)"			        {tags "man_power"} {cost 500} {button "04_cannon"} {icon 413} ("ch" c(420) fore(-720))}
	{"m30_trailer(rus)"			        {tags "man_power art"} {cost 500} {button "04_cannon"} {icon 414} ("ch" c(300) fore(-180))}
	{"ml20_trailer(rus)"		        {tags "man_power art"} {cost 700} {button "04_cannon"} {icon 415} ("ch" c(420) fore(-400))}
	{"bm13"								{tags "man_power art"} {cost 700} {button "04_cannon"} {cp 30} {icon 416} ("ch" c(480) fore(-660))}
;ger
	{"mg42_stan"						{tags "man_power"} {cost 40} {button "04_cannon"} {cp 5} {icon 401} ("ch" c(120) fore(0))}
	{"flak38_wheeled_trailer(ger)"		{tags "man_power"} {cost 85} {button "04_cannon"} {icon 402} ("ch" c(180) fore(-120))}
	{"flak18_trailer(ger)"				{tags "man_power"} {cost 350} {button "04_cannon"} {icon 403} ("ch" c(300) fore(-440))}
    {"legrw36"							{tags "man_power"} {cost 70} {button "04_cannon"} {cp 11} {icon 404} ("ch" c(120) fore(40))}
    {"sgrw34"							{tags "man_power"} {cost 90} {button "04_cannon"} {cp 14} {icon 405} ("ch" c(180) fore(0))}
    {"sgrw42"							{tags "man_power"} {cost 120} {button "04_cannon"} {cp 16} {icon 406} ("ch" c(300) fore(-180))}
    {"lelg18_trailer(ger)"				{tags "man_power"} {cost 120} {button "04_cannon"} {icon 407} ("ch" c(180) fore(0))}
	{"lg_40"					        {tags "man_power"} {cost 200} {button "04_cannon"} {cp 18} {icon 408} ("ch" c(180) fore(-340))}
	{"pak35_trailer(ger)"		        {tags "man_power"} {cost 75} {button "04_cannon"} {icon 409} ("ch" c(120) fore(40))}
	{"pak38_trailer(ger)"		        {tags "man_power"} {cost 120} {button "04_cannon"} {icon 410} ("ch" c(180) fore(-180))}
	{"pak40_trailer(ger)"		        {tags "man_power"} {cost 170} {button "04_cannon"} {icon 411} ("ch" c(180) fore(-400))}	
	{"pak43_trailer(ger)"		        {tags "man_power"} {cost 500} {button "04_cannon"} {icon 412} ("ch" c(420) fore(-720))}
	{"lefh18_trailer(ger)"		        {tags "man_power"} {cost 500} {button "04_cannon"} {icon 413} ("ch" c(300) fore(-180))}
	{"sfh18_trailer(ger)"		        {tags "man_power"} {cost 700} {button "04_cannon"} {icon 415} ("ch" c(420) fore(-400))}
    {"nebelwerfer41_trailer(ger)"		{tags "man_power"} {cost 700} {button "04_cannon"} {icon 416} ("ch" c(480) fore(-660))}
    {"nebelwerfer42_trailer(ger)"		{tags "man_power"} {cost 750} {button "04_cannon"} {icon 417} ("ch" c(480) fore(-660))}
	{"sdkfz4"						    {tags "man_power"} {cost 750} {button "04_cannon"} {cp 30} {icon 418} ("ch" c(480) fore(-660))}
;usa
    {"browning_stan"					{tags "man_power"} {cost 40} {button "04_cannon"} {cp 3} {icon 401} ("ch" c(120) fore(0))}
    {"browning_m2_stan"					{tags "man_power"} {cost 65} {button "04_cannon"} {cp 11} {icon 402} ("ch" c(120) fore(-60))}	
	{"maxson_trailer(usa)"				{tags "man_power"} {cost 75} {button "04_cannon"} {icon 403} ("ch" c(180) fore(0))}
	{"bofors_trailer(usa)"				{tags "man_power"} {cost 100} {button "04_cannon"} {icon 404} ("ch" c(240) fore(-120))}
	{"m2cannon90mm_trailer(usa)"		{tags "man_power art"} {cost 400} {button "04_cannon"} {icon 405} ("ch" c(300) fore(-620))}
    {"m2mortar"							{tags "man_power art"} {cost 70} {button "04_cannon"} {cp 11} {icon 406} ("ch" c(120) fore(40))}	
    {"m1mortar"							{tags "man_power art"} {cost 90} {button "04_cannon"} {cp 14} {icon 407} ("ch" c(180) fore(0))}
    {"m2mortar107mm"					{tags "man_power art"} {cost 120} {button "04_cannon"} {cp 16} {icon 408} ("ch" c(300) fore(-180))}
	{"m2_ally_m"	                    {tags "man_power art"} {cost 120} {button "04_cannon"} {cp 15} {icon 507} ("ch" c(180) fore(-80))}
    {"m8_howitzer_trailer(usa)"		    {tags "man_power art"} {cost 140} {button "04_cannon"} {icon 409} ("ch" c(240) fore(-60))}
	{"m3cannon_trailer(usa)"	        {tags "man_power"} {cost 75} {button "04_cannon"} {icon 410} ("ch" c(120) fore(40))}
	{"m1_trailer(usa)"			        {tags "man_power"} {cost 140} {button "04_cannon"} {icon 411} ("ch" c(180) fore(-240))}
	{"m5_trailer(usa)"			        {tags "man_power"} {cost 170} {button "04_cannon"} {icon 412} ("ch" c(180) fore(-400))}
	{"m2a1l_trailer(usa)"		        {tags "man_power art"} {cost 500} {button "04_cannon"} {icon 413} ("ch" c(300) fore(-180))}
	{"m114_trailer(usa)"		        {tags "man_power art"} {cost 700} {button "04_cannon"} {icon 414} ("ch" c(420) fore(-400))}
	
	
;=======05_light_armor======= 	
;rus
    {"ba20"			                    {tags "man_power"} {cost 85} {button "05_light_armor"} {cp 7} {group "ba"} {icon 501} ("ch" c(120) fore(20))}
	{"ba64"			                    {tags "man_power"} {cost 85} {button "05_light_armor"} {cp 7} {group "ba"} {icon 502} ("ch" c(120) fore(20))}
	{"ba11"			                    {tags "man_power tanks_only"} {cost 100} {button "05_light_armor"} {cp 11} {icon 503} ("ch" c(120) fore(-40))}
	{"t40_tns"		                    {tags "man_power tanks_only"} {cost 100} {button "05_light_armor"} {cp 11} {icon 504} ("ch" c(120) fore(-80))}	
	{"t26e"			                    {tags "man_power tanks_only"} {cost 110} {button "05_light_armor"} {cp 15} {icon 505} ("ch" c(120) fore(-40))}
	{"t60"			                    {tags "man_power tanks_only"} {cost 120} {button "05_light_armor"} {cp 15} {icon 506} ("ch" c(120) fore(-80))}
	{"bt7"			                    {tags "man_power tanks_only"} {cost 130} {button "05_light_armor"} {cp 15} {icon 507} ("ch" c(120) fore(-80))}	
	{"t70"			                    {tags "man_power tanks_only"} {cost 140} {button "05_light_armor"} {cp 20} {icon 508} ("ch" c(120) fore(-80))}	
	{"ht26"	                            {tags "man_power tanks_only"} {cost 140} {button "05_light_armor"} {cp 20} {icon 509} ("ch" c(240) fore(-240))}		
;ger
    {"sdkfz223"		                    {tags "man_power"} {cost 85} {button "05_light_armor"} {cp 7} {icon 501} ("ch" c(120) fore(20))}
	{"sdkfz222"		                    {tags "man_power tanks_only"} {cost 100} {button "05_light_armor"} {cp 11} {icon 502} ("ch" c(120) fore(-80))}
	{"sdkfz221"		                    {tags "man_power tanks_only"} {cost 100} {button "05_light_armor"} {cp 11} {icon 503} ("ch" c(120) fore(-40))}
	{"pz1b"			                    {tags "man_power"} {cost 100} {button "05_light_armor"} {cp 11} {icon 504} ("ch" c(120) fore(40))}
	{"sdkfz232"		                    {tags "man_power tanks_only"} {cost 120} {button "05_light_armor"} {cp 15} {icon 505} ("ch" c(120) fore(-80))}			
	{"pz1c"			                    {tags "man_power tanks_only"} {cost 120} {button "05_light_armor"} {cp 15} {icon 506} ("ch" c(120) fore(-80))}
	{"pz35t"			                {tags "man_power tanks_only"} {cost 120} {button "05_light_armor"} {cp 15} {icon 507} ("ch" c(120) fore(-40))}	
	{"pz38g"		                    {tags "man_power tanks_only"} {cost 150} {button "05_light_armor"} {cp 15} {icon 508} ("ch" c(120) fore(-80))}
	{"carro15"		                    {tags "man_power tanks_only"} {cost 160} {button "05_light_armor"} {cp 15} {icon 509} ("ch" c(120) fore(-180))}
	{"sdkfz234"		                    {tags "man_power tanks_only"} {cost 130} {button "05_light_armor"} {cp 15} {icon 510} ("ch" c(120) fore(-180))}
	{"sdkfz251_17"				        {tags "man_power"} {cost 100} {button "05_light_armor"} {cp 15} {icon 512} ("ch" c(180) fore(-180))}
	{"sdkfz251_16"	                    {tags "man_power"} {cost 140} {button "05_light_armor"} {cp 15} {icon 513} ("ch" c(240) fore(-240))}									    
;usa                                    
    {"m20"			                    {tags "man_power"} {cost 90} {button "05_light_armor"} {cp 7} {icon 501} ("ch" c(120) fore(20))}
	{"m8grayhound"	                    {tags "man_power tanks_only"} {cost 130} {button "05_light_armor"} {cp 15} {icon 502} ("ch" c(120) fore(-40))}
	{"lvt1"			                    {tags "man_power tanks_only"} {cost 130} {button "05_light_armor"} {cp 15} {icon 503} ("ch" c(120) fore(-40))}
	{"m3a1"			                    {tags "man_power tanks_only"} {cost 130} {button "05_light_armor"} {cp 15} {icon 504} ("ch" c(120) fore(-40))}	
	{"m5a1"			                    {tags "man_power tanks_only"} {cost 150} {button "05_light_armor"} {cp 15} {icon 505} ("ch" c(120) fore(-80))}	
	{"m24"			                    {tags "man_power tanks_only"} {cost 180} {button "05_light_armor"} {cp 15} {icon 506} ("ch" c(120) fore(-200))}
;=======06_armor=======	
;rus
    {"t28"		                        {tags "man_power tanks_only"} {cost 160} {button "06_armor"} {cp 20} {icon 601} ("ch" c(1) fore(-320))}
	{"t35"		                        {tags "man_power tanks_only"} {cost 170} {button "06_armor"} {cp 20} {icon 602} ("ch" c(1) fore(-320))}
	{"t34_76"	                        {tags "man_power tanks_only"} {cost 180} {button "06_armor"} {cp 20} {icon 603} ("ch" c(1) fore(-400))}
	{"t34_1"	                        {tags "man_power tanks_only"} {cost 200} {button "06_armor"} {cp 20} {icon 604} ("ch" c(1) fore(-520))}	
	{"t34_2"	                        {tags "man_power tanks_only"} {cost 215} {button "06_armor"} {cp 20} {icon 605} ("ch" c(1) fore(-520))}
	{"t34m"		                        {tags "man_power tanks_only"} {cost 215} {button "06_armor"} {cp 20} {icon 606} ("ch" c(1) fore(-520))}
	{"ot34_76_42"	                    {tags "man_power tanks_only"} {cost 240} {button "06_armor"} {cp 20} {icon 607} ("ch" c(240) fore(-500))}
	{"kv1"		                        {tags "man_power tanks_only"} {cost 240} {button "06_armor"} {cp 25} {icon 608} ("ch" c(1) fore(-520))}
	{"kv1s"		                        {tags "man_power tanks_only"} {cost 250} {button "06_armor"} {cp 25} {icon 609} ("ch" c(1) fore(-520))}	
	{"kv8"		                        {tags "man_power tanks_only"} {cost 250} {button "06_armor"} {cp 25} {icon 610} ("ch" c(240) fore(-500))}
	{"t34_85"	                        {tags "man_power tanks_only"} {cost 340} {button "06_armor"} {cp 25} {icon 611} ("ch" c(1) fore(-660))}
	{"t34_85m"				            {tags "man_power tanks_only"} {cost 370} {button "06_armor"} {cp 25} {icon 612} ("ch" c(1) fore(-680))}
	{"kv85"					            {tags "man_power tanks_only"} {cost 550} {button "06_armor"} {cp 30} {icon 613} ("ch" c(1) fore(-660))}
	{"is1"					            {tags "man_power tanks_only"} {cost 650} {button "06_armor"} {cp 35} {icon 614} ("ch" c(1) fore(-680))}
	{"is2_44"				            {tags "man_power tanks_only"} {cost 900} {button "06_armor"} {cp 45} {icon 615} ("ch" c(1) fore(-1140))}
;ger
	{"pz3m"		                        {tags "man_power tanks_only"} {cost 100} {button "06_armor"} {cp 10} {icon 600} ("ch" c(1) fore(-320))}
    {"pz3f"		                        {tags "man_power tanks_only"} {cost 150} {button "06_armor"} {cp 20} {icon 601} ("ch" c(1) fore(-320))}
    {"pzb2740f"				            {tags "man_power tanks_only"} {cost 190} {button "06_armor"} {cp 25} {icon 602} ("ch" c(1) fore(-320))}
	{"pz4e"		                        {tags "man_power tanks_only"} {cost 160} {button "06_armor"} {cp 20} {icon 603} ("ch" c(1) fore(-400))}
	{"pz3j"		                        {tags "man_power tanks_only"} {cost 170} {button "06_armor"} {cp 20} {icon 604} ("ch" c(1) fore(-400))}	
	{"pz4f2"	                        {tags "man_power tanks_only"} {cost 200} {button "06_armor"} {cp 20} {icon 605} ("ch" c(1) fore(-400))}
	{"pz4g"		                        {tags "man_power tanks_only"} {cost 220} {button "06_armor"} {cp 20} {icon 606} ("ch" c(1) fore(-520))}	
	{"pz4h"		                        {tags "man_power tanks_only"} {cost 240} {button "06_armor"} {cp 25} {icon 607} ("ch" c(1) fore(-520))}	
	{"pz5a"		                        {tags "man_power tanks_only"} {cost 440} {button "06_armor"} {cp 30} {icon 608} ("ch" c(1) fore(-660))}
	{"pz5g"					            {tags "man_power tanks_only"} {cost 500} {button "06_armor"} {cp 30} {icon 609} ("ch" c(1) fore(-680))}
	{"pz6h"					            {tags "man_power tanks_only"} {cost 600} {button "06_armor"} {cp 35} {icon 610} ("ch" c(1) fore(-660))}	
	{"pz6e"					            {tags "man_power tanks_only"} {cost 650} {button "06_armor"} {cp 35} {icon 611} ("ch" c(1) fore(-680))}
	{"pz6bh"				            {tags "man_power tanks_only"} {cost 900} {button "06_armor"} {cp 45} {icon 612} ("ch" c(1) fore(-1140))}	
;usa
    {"m2a1_med"	                        {tags "man_power tanks_only"} {cost 160} {button "06_armor"} {cp 20} {icon 601} ("ch" c(1) fore(-320))}
	{"m3_lee"	                        {tags "man_power tanks_only"} {cost 170} {button "06_armor"} {cp 20} {icon 602} ("ch" c(1) fore(-320))}	
	{"m4a1"		                        {tags "man_power tanks_only"} {cost 190} {button "06_armor"} {cp 20} {icon 603} ("ch" c(1) fore(-400))}	
	{"m4a2"	                        	{tags "man_power tanks_only"} {cost 210} {button "06_armor"} {cp 20} {icon 604} ("ch" c(1) fore(-520))}
	{"m4a3m"	                        {tags "man_power tanks_only"} {cost 215} {button "06_armor"} {cp 20} {icon 605} ("ch" c(1) fore(-520))}
	{"m4a3e2"	                        {tags "man_power tanks_only"} {cost 300} {button "06_armor"} {cp 25} {icon 606} ("ch" c(1) fore(-520))}
	{"m4a3_zippo"	                    {tags "man_power tanks_only"} {cost 320} {button "06_armor"} {cp 25} {icon 607} ("ch" c(240) fore(-500))}	
	{"m4a3e8"	                        {tags "man_power tanks_only"} {cost 330} {button "06_armor"} {cp 25} {icon 608} ("ch" c(1) fore(-660))}
	{"m4a3e2_jumbo_76"	                {tags "man_power tanks_only"} {cost 370} {button "06_armor"} {cp 25} {icon 609} ("ch" c(1) fore(-660))}
    {"m26"					            {tags "man_power tanks_only"} {cost 700} {button "06_armor"} {cp 40} {icon 610} ("ch" c(1) fore(-910))}
	
    
	
;=======07_spg=======	
;rus
    {"su76"					            {tags "man_power tanks_only"} {cost 170} {button "07_spg"} {cp 15} {icon 701} ("ch" c(1) fore(-400))}
	{"bt7a"		                        {tags "man_power"} {cost 200} {button "07_spg"} {cp 20} {icon 702} ("ch" c(1) fore(-400))}
	{"zis_30"				            {tags "man_power tanks_only"} {cost 200} {button "07_spg"} {cp 15} {icon 703} ("ch" c(1) fore(-400))}
	{"su85"					            {tags "man_power tanks_only"} {cost 300} {button "07_spg"} {cp 20} {icon 704} ("ch" c(1) fore(-660))}
	{"su100"				            {tags "man_power tanks_only"} {cost 650} {button "07_spg"} {cp 35} {icon 705} ("ch" c(420) fore(-720))}
	{"su122"				            {tags "man_power tanks_only art"} {cost 650} {button "07_spg"} {cp 35} {icon 706} ("ch" c(300) fore(-220))}
	{"su152"				            {tags "man_power tanks_only art"} {cost 850} {button "07_spg"} {cp 40} {icon 707} ("ch" c(420) fore(-480))}
	{"isu152"				            {tags "man_power tanks_only art"} {cost 900} {button "07_spg"} {cp 45} {icon 708} ("ch" c(420) fore(-720))}	
;ger                                    
    {"pzjager1"				            {tags "man_power tanks_only"} {cost 70} {button "07_spg"} {cp 10} {icon 701} ("ch" c(1) fore(-240))}
	{"stug3b"				            {tags "man_power tanks_only"} {cost 130} {button "07_spg"} {cp 15} {icon 702} ("ch" c(1) fore(-400))}
	{"marder2"				            {tags "man_power tanks_only"} {cost 215} {button "07_spg"} {cp 20} {icon 703} ("ch" c(1) fore(-400))}	
	{"sdkfz251_22"			            {tags "man_power tanks_only"} {cost 220} {button "07_spg"} {cp 15} {icon 704} ("ch" c(1) fore(-520))}
	{"stug3f"				            {tags "man_power tanks_only"} {cost 220} {button "07_spg"} {cp 20} {icon 705} ("ch" c(1) fore(-520))}	
	{"stug3g"				            {tags "man_power tanks_only"} {cost 240} {button "07_spg"} {cp 20} {icon 706} ("ch" c(1) fore(-520))}
	{"jagdpanzer_iv"		            {tags "man_power tanks_only"} {cost 260} {button "07_spg"} {cp 20} {icon 708} ("ch" c(1) fore(-660))}
	{"nashorn"				            {tags "man_power tanks_only"} {cost 340} {button "07_spg"} {cp 25} {icon 709} ("ch" c(420) fore(-320))}	
	{"jagdpanther"			            {tags "man_power tanks_only"} {cost 700} {button "07_spg"} {cp 35} {icon 710} ("ch" c(420) fore(-720))}
	{"jagdtiger"			            {tags "man_power tanks_only"} {cost 900} {button "07_spg"} {cp 50} {icon 711} ("ch" c(420) fore(-720))}
	{"sdkfz124"				            {tags "man_power art"} {cost 300} {button "07_spg"} {cp 30} {icon 712} ("ch" c(300) fore(-220))}
	{"stuh42"				            {tags "man_power tanks_only art"} {cost 600} {button "07_spg"} {cp 35} {icon 713} ("ch" c(300) fore(-220))}
	{"sturmpz1"				            {tags "man_power art"} {cost 650} {button "07_spg"} {cp 35} {icon 714} ("ch" c(420) fore(-480))}
	{"hummel"				            {tags "man_power art"} {cost 850} {button "07_spg"} {cp 40} {icon 715} ("ch" c(420) fore(-480))}
			
;usa                                    
    {"dodgewc51_m6"			            {tags "man_power tanks_only"} {cost 90} {button "07_spg"} {cp 15} {icon 701} ("ch" c(120) fore(-120))}
    {"lvt4"				            	{tags "man_power tanks_only"} {cost 200} {button "07_spg"} {cp 15} {icon 702} ("ch" c(1) fore(-400))}
	{"m8"					            {tags "man_power"} {cost 200} {button "07_spg"} {cp 15} {icon 703} ("ch" c(1) fore(-400))}
    {"m18"					            {tags "man_power tanks_only"} {cost 240} {button "07_spg"} {cp 20} {icon 704} ("ch" c(1) fore(-520))}
    {"m36"					            {tags "man_power tanks_only"} {cost 500} {button "07_spg"} {cp 30} {icon 706} ("ch" c(420) fore(-480))}
    {"m7"					            {tags "man_power art"} {cost 700} {button "07_spg"} {cp 35} {icon 707} ("ch" c(300) fore(-220))}
	{"m12gmc"				            {tags "man_power art"} {cost 850} {button "07_spg"} {cp 40} {icon 708} ("ch" c(420) fore(-480))}


;=======08_aviation=======
;rus
    {"po-2_scout"			            {tags "man_power recon"} {cost 20} {button "08_aviation"} {icon 801} ("ch" c(60) fore(-300))}
	{"airstrike_po-2(rus)"	            {tags "man_power airstrike"} {cost 125} {button "08_aviation"} {group "airstrike"} {icon 802} ("ch" c(120) fore(-440))}
	{"airstrike_i-16(rus)"	            {tags "man_power airstrike"} {cost 150} {button "08_aviation"} {group "airstrike"} {icon 803} ("ch" c(120) fore(-440))}
	{"airstrike(rus)"		            {tags "man_power airstrike"} {cost 200} {button "08_aviation"} {group "airstrike_2"} {icon 804} ("ch" c(120) fore(-860))}						            
;ger                                    
    {"fi156"				            {tags "man_power recon"} {cost 50} {button "08_aviation"} {icon 801} ("ch" c(60) fore(-300))}
	{"airstrike_bf109g(ger)"		    {tags "man_power airstrike"} {cost 150} {button "08_aviation"} {group "airstrike"} {icon 802} ("ch" c(120) fore(-440))}
	{"airstrike(ger)"			        {tags "man_power airstrike"} {cost 200} {button "08_aviation"} {group "airstrike_2"} {icon 803} ("ch" c(120) fore(-860))}	
;usa
    {"l-4"					            {tags "man_power recon"} {cost 50} {button "08_aviation"} {icon 801} ("ch" c(60) fore(-300))}
	{"airstrike_p51(usa)"	            {tags "man_power airstrike"} {cost 150} {button "08_aviation"} {group "airstrike"}  {icon 802} ("ch" c(120) fore(-440))}
	{"airstrike(usa)"		            {tags "man_power airstrike"} {cost 175} {button "08_aviation"} {group "airstrike_2"} {icon 803} ("ch" c(120) fore(-860))}
	{"airstrike_a20(usa)"	            {tags "man_power airstrike"} {cost 200} {button "08_aviation"} {group "airstrike_2"} {icon 804} ("ch" c(120) fore(-860))}

	
;=======Special=======
;rus
    {"rifle_grenadiers(rus)"			{tags "man_power"} {cost 5} {button "special"} {icon 901} ("ch" c(180) fore(0))
										{content "arena_mp/rus/rifle_grenadier:2 arena_mp/rus/light_assault_commander:1"}
	}
    {"rus_riflemen41(rus)"				{tags "man_power"} {cost 20} {button "special"} {icon 902} ("ch" c(300) fore(0))}
	{"sniper_elite(rus)"	            {tags "man_power elite_snipers"} {cost 50} {button "special"} {icon 903} ("ch" c(360) fore(-380))
										{content "arena_mp/rus/sniper_elite:2 arena_mp/rus/arty_spotter:1"}
	}
	
	{"dshk_stan"						{tags "man_power"} {cost 10} {button "special"} {cp 11} {icon 904} ("ch" c(120) fore(-60))}
	{"zsu37"					        {tags "man_power tanks_only"} {cost 25} {button "special"} {cp 20} {icon 905} ("ch" c(240) fore(-280))}
	{"29k"					            {tags "man_power"} {cost 50} {button "special"} {cp 20} {icon 906} ("ch" c(240) fore(-500))}
	
	{"f22_trailer(rus)"			        {tags "man_power"} {cost 20} {button "special"} {icon 907} ("ch" c(180) fore(-340))}
	{"d1_trailer(rus)"			        {tags "man_power art"} {cost 90} {button "special"} {icon 908} ("ch" c(420) fore(-560))}
	{"203b4_trailer(rus)"		        {tags "man_power art"} {cost 150} {button "special"} {icon 909} ("ch" c(480) fore(-960))}  	
	
	{"t28e"								{tags "man_power tanks_only"} {cost 25} {button "special"} {cp 20} {icon 910} ("ch" c(180) fore(-240))}	
	{"t34_armored"			            {tags "man_power tanks_only"} {cost 35} {button "special"} {cp 20} {icon 911} ("ch" c(180) fore(-680))}
	{"kv1e"					            {tags "man_power tanks_only"} {cost 50} {button "special"} {cp 25} {icon 912} ("ch" c(180) fore(-680))}
	
	{"kv2"		                        {tags "man_power tanks_only art"} {cost 85} {button "special"} {cp 30} {icon 913} ("ch" c(300) fore(-680))}
	{"isu122"		                    {tags "man_power tanks_only"} {cost 100} {button "special"} {cp 40} {icon 914} ("ch" c(180) fore(-1260))}
	{"is3"					            {tags "man_power tanks_only"} {cost 150} {button "special"} {cp 50} {icon 915} ("ch" c(180) fore(-1260))}		
;ger
    {"goliath"		                    {tags "man_power tanks_only"} {cost 5} {button "special"} {cp 1} {icon 901} ("ch" c(60) fore(-120))}
	{"ger_riflemen41(ger)"				{tags "man_power"} {cost 20} {button "special"} {icon 902} ("ch" c(300) fore(0))}
	{"sniper_elite(ger)"	            {tags "man_power elite_snipers"} {cost 50} {button "special"} {icon 903} ("ch" c(360) fore(-380))
										{content "arena_mp/ger/sniper_elite:2 arena_mp/ger/arty_spotter:1"}
	}
	{"pz1"						        {tags "man_power tanks_only"} {cost 15} {button "special"} {cp 15} {icon 904} ("ch" c(180) fore(-180))}
	{"sdkfz7_1"					        {tags "man_power"} {cost 20} {button "special"} {cp 15} {icon 905} ("ch" c(180) fore(-340))}
	{"welberwind"				        {tags "man_power tanks_only"} {cost 25} {button "special"} {cp 20} {icon 906} ("ch" c(180) fore(-680))}
    
	{"pak36_trailer(ger)"		        {tags "man_power"} {cost 25} {button "special"} {icon 907} ("ch" c(180) fore(-340))}
	{"sk18_trailer(ger)"		        {tags "man_power art"} {cost 65} {button "special"} {icon 908} ("ch" c(420) fore(-560))}
	{"mrs18_trailer(ger)"		        {tags "man_power art"} {cost 150} {button "special"} {icon 909} ("ch" c(480) fore(-960))}
	
	{"pz3n"	                            {tags "man_power tanks_only"} {cost 30} {button "special"} {cp 20} {icon 910} ("ch" c(240) fore(-280))}
	{"brumbar"		                    {tags "man_power tanks_only art"} {cost 65} {button "special"} {cp 30} {icon 911} ("ch" c(180) fore(-800))}
	{"sturmtiger"			            {tags "man_power tanks_only art"} {cost 150} {button "special"} {cp 50} {icon 912} ("ch" c(180) fore(-1260))}
	
	{"hetzer"				            {tags "man_power tanks_only"} {cost 30} {button "special"} {cp 20} {icon 913} ("ch" c(180) fore(-560))}	
	{"ferdinand"	                    {tags "man_power tanks_only"} {cost 90} {button "special"} {cp 45} {icon 914} ("ch" c(180) fore(-1260))}
	{"pz6b"	                            {tags "man_power tanks_only"} {cost 120} {button "special"} {cp 45} {icon 915} ("ch" c(180) fore(-1260))}
	
		
;usa
    {"bazookers_m18(usa)"			    {tags "man_power"} {cost 5} {button "special"} {icon 901} ("ch" c(180) fore(0))
										{content "arena_mp/usa/bazooker_m18:2 arena_mp/usa/light_assault_commander:1"}
	}
    {"usa_riflemen41(usa)"				{tags "man_power"} {cost 20} {button "special"} {icon 902} ("ch" c(300) fore(0))}
	{"sniper_elite(usa)"	            {tags "man_power elite_snipers"} {cost 50} {button "special"} {icon 903} ("ch" c(360) fore(-380))
										{content "arena_mp/usa/sniper_elite:2 arena_mp/usa/arty_spotter:1"}
	}	
	{"m16"						        {tags "man_power"} {cost 15} {button "special"} {cp 15} {icon 904} ("ch" c(180) fore(-180))}
	{"m1_aa_trailer(usa)"				{tags "man_power"} {cost 20} {button "special"} {icon 905} ("ch" c(240) fore(-120))}
	{"m19"		                        {tags "man_power"} {cost 25} {button "special"} {cp 15} {icon 906} ("ch" c(300) fore(-440))}
	
	{"m4a3_105"	                        {tags "man_power tanks_only art"} {cost 50} {button "special"} {cp 30} {icon 907} ("ch" c(180) fore(-560))}
	{"m4a3c"				            {tags "man_power tanks_only"} {cost 100} {button "special"} {cp 30} {icon 908} ("ch" c(180) fore(-960))}
	{"203_m1_trailer(usa)"		        {tags "man_power art"} {cost 150} {button "special"} {icon 909} ("ch" c(480) fore(-960))}
	
	{"m4a3_75"							{tags "man_power tanks_only"} {cost 30} {button "special"} {cp 20} {icon 910} ("ch" c(180) fore(-560))}
	{"m4a2_76w"		            		{tags "man_power tanks_only"} {cost 40} {button "special"} {cp 25} {icon 911} ("ch" c(180) fore(-800))}
	{"m26e4"				            {tags "man_power tanks_only"} {cost 120} {button "special"} {cp 45} {icon 912} ("ch" c(180) fore(-1260))}
	
	{"m1_t48"				            {tags "man_power tanks_only"} {cost 20} {button "special"} {cp 15} {icon 913} ("ch" c(180) fore(-340))}
	{"m10wolverine"			            {tags "man_power tanks_only"} {cost 35} {button "special"} {cp 20} {icon 914} ("ch" c(180) fore(-460))}
	{"t95"			                    {tags "man_power tanks_only"} {cost 150} {button "special"} {cp 45} {icon 915} ("ch" c(180) fore(-1260))}
	
	
;for bots
	{"fighters_light_bot(ger)" ("ch" c(30) fore(30))}
	{"fighters_light_bot(rus)" ("ch" c(30) fore(30))}
	{"fighters_light_bot(usa)" ("ch" c(30) fore(30))}	
	
;cannons without tractors
;rus
    {"61k"					{tags "man_power"} {cost 70} {button "x_button"} {cp 10} ("ch" c(240) fore(-120))}
	{"52k"					{tags "man_power"} {cost 200} {button "x_button"} {cp 20} ("ch" c(300) fore(-440))}
    {"1927_cannon"			{tags "man_power"} {cost 100} {button "x_button"} {cp 14} ("ch" c(180) fore(0))}
    {"1943_cannon"			{tags "man_power"} {cost 100} {button "x_button"} {cp 14} ("ch" c(180) fore(0))}	
	{"53k"			        {tags "man_power"} {cost 50} {button "x_button"} {cp 10} ("ch" c(120) fore(40))}
	{"m42"			        {tags "man_power"} {cost 60} {button "x_button"} {cp 12} ("ch" c(180) fore(-180))}
	{"zis3"		            {tags "man_power"} {cost 70} {button "x_button"} {cp 15} ("ch" c(180) fore(-240))}
	{"zis2"		            {tags "man_power"} {cost 70} {button "x_button"} {cp 15} ("ch" c(180) fore(-400))}
	{"bs3"			        {tags "man_power"} {cost 500} {button "x_button"} {cp 20} ("ch" c(480) fore(-660))}
	{"m30"			        {tags "man_power"} {cost 500} {button "x_button"} {cp 20} ("ch" c(300) fore(-180))}
	{"ml20"		            {tags "man_power"} {cost 900} {button "x_button"} {cp 25} ("ch" c(420) fore(-400))}
	{"d1"		            {tags "man_power"} {cost 900} {button "x_button"} {cp 25} ("ch" c(420) fore(-400))}
	{"f22"			        {tags "man_power"} {cost 30} {button "x_button"} {cp 15} ("ch" c(180) fore(-240))}
	{"203b4"		        {tags "man_power"} {cost 150} {button "x_button"} {cp 30} ("ch" c(480) fore(-660))}  
;ger
	{"flak38_wheeled"		{tags "man_power"} {cost 60} {button "x_button"} {cp 10} ("ch" c(180) fore(-120))}
	{"flak18"				{tags "man_power"} {cost 200} {button "x_button"} {cp 20} ("ch" c(300) fore(-440))}
    {"lelg18"				{tags "man_power"} {cost 100} {button "x_button"} {cp 14} ("ch" c(180) fore(0))}
	{"pak35"		        {tags "man_power"} {cost 50} {button "x_button"} {cp 10} ("ch" c(120) fore(40))}
	{"pak38"		        {tags "man_power"} {cost 60} {button "x_button"} {cp 12} ("ch" c(180) fore(-180))}
	{"pak40"		        {tags "man_power"} {cost 80} {button "x_button"} {cp 15} ("ch" c(180) fore(-400))}	
	{"sk18"		            {tags "man_power"} {cost 150} {button "x_button"} {cp 20} ("ch" c(240) fore(-400))}
	{"pak43"		        {tags "man_power"} {cost 500} {button "x_button"} {cp 20} ("ch" c(480) fore(-660))}
	{"lefh18"		        {tags "man_power"} {cost 500} {button "x_button"} {cp 20} ("ch" c(300) fore(-180))}
	{"sfh18"		        {tags "man_power"} {cost 900} {button "x_button"} {cp 25} ("ch" c(420) fore(-400))}
    {"nebelwerfer41"		{tags "man_power"} {cost 700} {button "x_button"} {cp 25} ("ch" c(480) fore(-660))}
    {"nebelwerfer42"		{tags "man_power"} {cost 900} {button "x_button"} {cp 30} ("ch" c(480) fore(-660))} 
    {"pak36"		        {tags "man_power"} {cost 40} {button "x_button"} {cp 15} ("ch" c(180) fore(-240))}
	{"mrs18"		        {tags "man_power"} {cost 150} {button "x_button"} {cp 30} ("ch" c(480) fore(-660))}	
;usa	
	{"maxson"				{tags "man_power"} {cost 30} {button "x_button"} {cp 8} ("ch" c(180) fore(0))}
	{"bofors"				{tags "man_power"} {cost 70} {button "x_button"} {cp 10} ("ch" c(240) fore(-120))}
	{"m2cannon90mm"		    {tags "man_power"} {cost 250} {button "x_button"} {cp 20} ("ch" c(300) fore(-840))}
    {"m8_howitzer"		    {tags "man_power"} {cost 100} {button "x_button"} {cp 14} ("ch" c(240) fore(-60))}
	{"m3cannon"	            {tags "man_power"} {cost 50} {button "x_button"} {cp 10} ("ch" c(120) fore(40))}
	{"m1"			        {tags "man_power"} {cost 70} {button "x_button"} {cp 12} ("ch" c(180) fore(-240))}
	{"m5"			        {tags "man_power"} {cost 80} {button "x_button"} {cp 15} ("ch" c(180) fore(-400))}
	{"m2a1l"		        {tags "man_power"} {cost 500} {button "x_button"} {cp 20} ("ch" c(300) fore(-180))}
	{"m114"		            {tags "man_power"} {cost 900} {button "x_button"} {cp 25} ("ch" c(420) fore(-400))}
    {"m1_aa"				{tags "man_power"} {cost 30} {button "x_button"} {cp 10} ("ch" c(240) fore(-120))}
	{"203_m1"		        {tags "man_power"} {cost 150} {button "x_button"} {cp 30} ("ch" c(480) fore(-660))}
}