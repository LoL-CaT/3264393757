(define "unitLimits"
	{unitLimits "|engineers=2;|uni_miners=1;|corpsman=10;|single=30;|crewman=4;|snipers=2;|elite_snipers=1;|spotters=6;|saboteurs=4;|recon=4;|airstrike=3;|crate=7;|supp=2;|officer=5"}
)
(define "test_mode"
	{common
		{unitset "%unitset"}
		{chargeFactors "*=%cf"}
		{commandPoints %cp}
		;{inventory "classic"} ; from commander_inventory.set
		{budgets
			{vehicle
				{mode "with_payback"}
				{resource 
					{start 		%start}
					{finish 	%finish}
					{growTime	%growTime}				; round time when money growing
					{restoreBegin 	1}	; points per sec
					{restoreEnd 	1}	; points per sec
					{growTable 	"%growTable"}
					{payback
						{cp	     "0    25   50   75    100"}
						{restore "0.8  0.7  0.6  0.5  0.4"}
					}
				} 
				{buttons "01_squad1 02_squad2 03_car 04_cannon 05_light_armor 06_armor 07_spg 08_aviation"}
			}
			{x_special
				{resource 
					{start %sp}
				} 
				{buttons "special"}
			}			
		}
	}
)

; with payback
(define "payback_vehicles"
	{common
		{unitset "%unitset"}
		{chargeFactors "*=%cf"}
		{commandPoints %cp}
		{inventory "classic"} ; from commander_inventory.set
		("unitLimits")
		{budgets
			{vehicle
				{mode "with_payback"}
				{resource 
					{start 		%start}
					{finish 	%finish}
					{growTime	%growTime}				; round time when money growing
					{restoreBegin 	1}	; points per sec
					{restoreEnd 	1}	; points per sec
					{growTable 	"%growTable"}
					{payback
						{cp	     "0    25   50   75    100"}
						{restore "0.8  0.7  0.6  0.5  0.4"}
					}
				} 
				{buttons "01_squad1 02_squad2 03_car 04_cannon 05_light_armor 06_armor 07_spg 08_aviation"}
			}
			{x_special
				{resource 
					{start %sp}
				} 
				{buttons "special"}
			}			
		}
	}
)
(define "payback_vehicles_without_timers"
	{common
		{unitset "%unitset"}
		{chargeFactors "*=%cf"}
		{commandPoints %cp}
		{inventory "classic"} ; from commander_inventory.set
		("unitLimits")
		{budgets
			{vehicle
				{mode "with_payback"}
				{resource 
					{start 		%start}
					{finish 	%finish}
					{growTime	%growTime}				; round time when money growing
					{restoreBegin 	1}	; points per sec
					{restoreEnd 	1}	; points per sec
					{growTable 	"%growTable"}
					{payback
						{cp	     "0    25   50   75    100"}
						{restore "0.8  0.7  0.6  0.5  0.4"}
					}
				} 
				{buttons "01_squad1 02_squad2 03_car 04_cannon 05_light_armor 06_armor 07_spg 08_aviation"}
			}
			{x_special
				{resource 
					{start 		10}
					{finish 	%sp}
					{growTime	%growTime}				; round time when money growing
					{growTable 	"%growTable"}
					{limitmin	10}
					{limitmax	%sp}
					{speedset 	"100"}
				}  
				{buttons "special"}
			}				
		}
	}
)
(define "tanks_only"
	{common
		{unitset "tanks_only"}
		{chargeFactors "*=%cf"}
		{commandPoints %cp}
		;{inventory "classic"} ; from commander_inventory.set
		;("unitLimits")
		{budgets
			{vehicle
				{mode "with_payback"}
				{resource 
					{start 		%start}
					{finish 	%finish}
					{growTime	%growTime}				; round time when money growing
					{restoreBegin 	1}	; points per sec
					{restoreEnd 	1}	; points per sec
					{growTable 	"%growTable"}
					{payback
						{cp	     "0    25   50   75    100"}
						{restore "0.8  0.7  0.6  0.5  0.4"}
					}
				} 
				{buttons "02_squad2 03_car 05_light_armor 06_armor 07_spg"}
			}
			{x_special
				{resource 
					{start 		10}
					{finish 	%sp}
					{growTime	%growTime}				; round time when money growing
					{growTable 	"%growTable"}
					{limitmin	10}
					{limitmax	%sp}
					{speedset 	"100"}
				}  
				{buttons "special"}
			}			
		}
	}
)

; without payback
(define "without_payback_vehicles"
	{common
		{unitset "man_power^man|alter|inf|d1|sfh18|bl6|m114"}
		{chargeFactors "*=1"}
		{commandPoints %cp}
		{inventory "classic"} ; from commander_inventory.set
		{budgets
			{vehicle
				{mode "without_payback"}
				{resource 
					{start 		%start}
					{finish 	%finish}
					{growTime	%growTime}				; round time when money growing
					{growTable 	"%growTable"}
					{limitmin	110}
					{limitmax	325}
					{speedset 	"75"}
				} 
				{buttons "01_squad1 02_squad2 03_car 04_cannon 05_light_armor 06_armor 07_spg 08_aviation"}
			}
			{x_special
				{resource 
					{start 150}
				} 
				{buttons "special"}
			}			

		} 
	}
)

{presets
    {"p:payback_100"
		{gameMode "with_payback"}
		{unitMode "vehicles"}
		{specMode "battalion_100"}
		("payback_vehicles" unitset(man_power) cf(1) start(100) finish(2500) sp(150) growTime(0.45) growTable(0.8 0.9 1.0 1.1 1.3 1.5 1.6) cp("*=100"))
	}
	{"p:payback_125"
		{gameMode "with_payback"}
		{unitMode "vehicles"}
		{specMode "battalion_125"}
		("payback_vehicles" unitset(man_power) cf(1) start(100) finish(2500) sp(150) growTime(0.45) growTable(0.8 0.9 1.0 1.1 1.3 1.5 1.6) cp("*=125"))
	}
	{"p:payback_150"
		{gameMode "with_payback"}
		{unitMode "vehicles"}
		{specMode "battalion_150"}
		("payback_vehicles" unitset(man_power) cf(1) start(100) finish(2500) sp(150) growTime(0.45) growTable(0.8 0.9 1.0 1.1 1.3 1.5 1.6) cp("*=150"))
	}
	{"p:payback_without_timers"
		{gameMode "with_payback"}
		{unitMode "vehicles"}
		{specMode "without_timers"}
		("payback_vehicles_without_timers" unitset(man_power) cf(0) start(100) finish(2500) sp(150) growTime(0.45) growTable(0.8 0.9 1.0 1.1 1.3 1.5 1.6) cp("*=100"))
	}
	{"p:tanks_only"
		{gameMode "with_payback"}
		{unitMode "vehicles"}
		{specMode "tanks_only"}
		("tanks_only" cf(0.0) start(120) finish(5000) sp(300) growTime(0.45) growTable(0.8 0.9 1.0 1.1 1.3 1.5 1.6) cp("*=75"))
	}
	{"p:infantry_only"
		{gameMode "with_payback"}
		{unitMode "vehicles"}
		{specMode "infantry_only"}
		("payback_vehicles" unitset(infantry_only) cf(0.65) start(100) finish(2500) sp(150) growTime(0.45) growTable(0.8 0.9 1.0 1.1 1.3 1.5 1.6) cp("*=60"))
	}
	{"p:no_arty"
		{gameMode "with_payback"}
		{unitMode "vehicles"}
		{specMode "no_arty"}
		("payback_vehicles" unitset(man_power^art) cf(1) start(100) finish(2500) sp(150) growTime(0.45) growTable(0.8 0.9 1.0 1.1 1.3 1.5 1.6) cp("*=100"))
	}
	{"p:no_airstrike"
		{gameMode "with_payback"}
		{unitMode "vehicles"}
		{specMode "no_airstrike"}
		("payback_vehicles" unitset(man_power^airstrike) cf(1) start(100) finish(2500) sp(150) growTime(0.45) growTable(0.8 0.9 1.0 1.1 1.3 1.5 1.6) cp("*=100"))
	}
	{"p:payback_test"
		{gameMode "with_payback"}
		{unitMode "vehicles"}
		{specMode "test"}
		("test_mode" unitset(man_power) cf(0) start(10000) finish(25000) sp(15000) growTime(0.01) growTable(0.8 0.9 1.0 1.1 1.3 1.5 1.6) cp("*=1500"))
	}
}
