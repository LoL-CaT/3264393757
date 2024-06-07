; without update
(define "without_budget"
	{common
		{unitset ""}
		{commandPoints %cp}
		{chargeFactors "*=1"}
	}
)
(define "instant_vehicles"
	{common
		{unitset "man_power^man|alter|inf|d1|sfh18|bl6|m114"}
		{commandPoints "*=%cp_total"}
		{chargeFactors "*=1"}
		{budgets
			{vehicle
				{mode "without_update"}
				{resource 
					{start 		%start}
					{finish 	800}
					{speed 		0}
					{limitmin	100}
					{limitmax	500}
					{speedset 	"50 100 150 200 250 300"}
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

; with payback
(define "payback_vehicles"
	{common
		{unitset "man_power^man|alter|inf|d1|sfh18|bl6|m114"}
		{chargeFactors "*=1"}
		{commandPoints %cp}
		{budgets
			{vehicle
				{mode "with_payback"}
				{resource 
					{start 		%start}
					{finish 	%finish}
					{growTime	%growTime}				; round time when money growing
					{restoreBegin 	%restoreBegin}	; points per sec
					{restoreEnd 	%restoreEnd}	; points per sec
					{growTable 	"%growTable"}
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

; without payback
(define "without_payback_vehicles"
	{common
		{unitset "man_power^man|alter|inf|d1|sfh18|bl6|m114"}
		{chargeFactors "*=1"}
		{commandPoints %cp}
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
	{"p:no_budget"	
		{gameMode "without_update"}
		("without_budget" cp("vehicle=15;*=15"))
	}	
}
