; without update
(define "instant_vehicles"
	{common
		{unitset "^man|alter|inf|d1|sfh18|bl6|m114"}
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
				{buttons "squad1 squad2 auto vh_cn lt ht asu"}
			}

		} 
	}
)

; with payback
(define "payback_vehicles"
	{common
		{unitset "^man|alter|inf|d1|sfh18|bl6|m114"}
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
				{buttons "squad1 squad2 auto vh_cn lt ht asu"}
			}

		} 
	}
)

; without payback
(define "without_payback_vehicles"
	{common
		{unitset "^man|alter|inf|d1|sfh18|bl6|m114"}
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
				{buttons "squad1 squad2 auto vh_cn lt ht asu"}
			}

		} 
	}
)

{presets
	{"p:no_payback_100"	
		{gameMode "without_payback"}
		{unitMode "vehicles"}
		{specMode "company_100"}
		("without_payback_vehicles" start(16) finish(260) growTime(0.8) growTable(0.6 0.9 1) cp("vehicle=45;*=70"))
	}
	{"p:no_payback_80"	
		{gameMode "without_payback"}
		{unitMode "vehicles"}
		{specMode "platoon_80"}
		("without_payback_vehicles" start(16) finish(210) growTime(0.8) growTable(0.6 0.9 1) cp("vehicle=35;*=50"))
	}		
	{"p:no_payback_120"	
		{gameMode "without_payback"}
		{unitMode "vehicles"}
		{specMode "battalion_120"}
		("without_payback_vehicles" start(16) finish(315) growTime(0.8) growTable(0.6 0.9 1) cp("vehicle=55;*=90"))
	}
;------------------------------------------------------------------------------------------------------------
	{"p:payback_120"	
		{gameMode "with_payback"}
		{unitMode "vehicles"}
		{specMode "battalion_120"}
		("payback_vehicles" restoreBegin(0.14) restoreEnd(0.3) start(12) finish(140) growTime(0.8) growTable(1) cp("*=80"))
	}
	{"p:payback_80"	
		{gameMode "with_payback"}
		{unitMode "vehicles"}
		{specMode "platoon_80"}
		("payback_vehicles" restoreBegin(0.14) restoreEnd(0.3) start(12) finish(120) growTime(0.8) growTable(1) cp("*=80"))
	}	
	{"p:payback_100"	
		{gameMode "with_payback"}
		{unitMode "vehicles"}
		{specMode "company_100"}
		("payback_vehicles" restoreBegin(0.14) restoreEnd(0.3) start(12) finish(160) growTime(0.8) growTable(1) cp("*=80"))
	}	
;------------------------------------------------------------------------------------------------------------
	{"wu:without_update_100"
		{gameMode "without_update"}
		{unitMode "vehicles"}
		{specMode "company_100"}
		("instant_vehicles" cp_total(100) start(260))
	}
	{"wu:without_update_80"
		{gameMode "without_update"}
		{unitMode "vehicles"}
		{specMode "platoon_80"}
		("instant_vehicles" cp_total(80) start(210))
	}
	{"wu:without_update_120"
		{gameMode "without_update"}
		{unitMode "vehicles"}
		{specMode "battalion_120"}
		("instant_vehicles" cp_total(120) start(315))
	}
}
