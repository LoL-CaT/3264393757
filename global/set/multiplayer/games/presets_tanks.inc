;by Pheonix
; without update, tanks only
(define "instant_tanks"
	{common
		{unitset "tanks_only"}
		{chargeFactors "light=1;supply=1;basic=0;*=0.75"}
		{commandPoints "supply=1;light=3.1;basic=3.1;*=%cp_total"}
		{budgets
			{vehicle
				{mode "without_update"}
				{resource 
					{start 		%start}
					{finish 	800}
					{speed 		0}
					{limitmin	100}
					{limitmax	600}
					{speedset 	"200 250 300 350 400 500 600"}
				} 
				{buttons "squad1 squad2 lt ht asu auto"}
			}

		} 
	}
)

; with payback, tanks only
(define "payback_tanks"
	{common
		{unitset "tanks_only"}
		{chargeFactors "light=1;supply=1;basic=0;*=0.35"}
		{commandPoints "supply=1;light=3.1;basic=3.1;*=%cp"}
		{budgets
			{vehicle
				{mode "with_payback"}
				{resource 
					{start 		%start}
					{finish 	%finish}
					{growTime	%growTime}			; round time when money growing
					{restoreBegin 	%restoreBegin}	; points per sec
					{restoreEnd 	%restoreEnd}	; points per sec
					{growTable 	"%growTable"}
				} 
				{buttons "squad1 squad2 lt ht asu auto"}
			}

		} 
	}
)

; without payback
(define "without_payback_tanks"
	{common
		{unitset "tanks_only"}
			{chargeFactors "light=1;supply=1;basic=0;*=0.5"}
			{commandPoints "supply=1;light=3.1;basic=3.1;*=%cp"}
		{budgets
			{vehicle
				{mode "without_payback"}
				{resource 
					{start 		%start}
					{finish 	%finish}
					{growTime	%growTime}				; round time when money growing
					{growTable 	"%growTable"}
					{limitmin	150}
					{limitmax	600}
					{speedset 	"200 250 300 350 400 500 600"}
				} 
				{buttons "squad1 squad2 lt ht asu auto"}
			}

		} 
	}
)

{presets
	{"p:no_payback_3"	
		{gameMode "without_payback"}
		{unitMode "tanks_only"}
		{specMode "tankcp_3"}
		{apply "tanks_expense"}
		("without_payback_tanks" start(20) finish(300) growTime(0.6) growTable(1 1 1 1 1 1 1) cp(3.1))
	}
	{"p:no_payback_4"	
		{gameMode "without_payback"}
		{unitMode "tanks_only"}
		{specMode "tankcp_4"}
		{apply "tanks_expense"}
		("without_payback_tanks" start(20) finish(400) growTime(0.6) growTable(1 1 1 1 1 1 1) cp(4.1))
	}
	{"p:no_payback_5"	
		{gameMode "without_payback"}
		{unitMode "tanks_only"}
		{specMode "tankcp_5"}
		{apply "tanks_expense"}
		("without_payback_tanks" start(20) finish(500) growTime(0.6) growTable(1 1 1 1 1 1 1) cp(5.1))
	}
	{"p:no_payback_6"	
		{gameMode "without_payback"}
		{unitMode "tanks_only"}
		{specMode "tankcp_6"}
		{apply "tanks_expense"}
		("without_payback_tanks" start(20) finish(600) growTime(0.6) growTable(1 1 1 1 1 1 1) cp(6.1))
	}
;------------------------------------------------------------------------------------------------------------
	{"p:payback_2"	
		{gameMode "with_payback"}
		{unitMode "tanks_only"}
		{specMode "tankcp_2"}
		{apply "tanks_expense"}
		("payback_tanks" restoreBegin(0.14) restoreEnd(0.3) start(20) finish(120) growTime(0.7) growTable(1) cp(2.1))
	}	
	{"p:payback_3"	
		{gameMode "with_payback"}
		{unitMode "tanks_only"}
		{specMode "tankcp_3"}
		{apply "tanks_expense"}
		("payback_tanks" restoreBegin(0.14) restoreEnd(0.3) start(20) finish(120) growTime(0.7) growTable(1) cp(3.1))
	}	
	{"p:payback_4"	
		{gameMode "with_payback"}
		{unitMode "tanks_only"}
		{specMode "tankcp_4"}
		{apply "tanks_expense"}
		("payback_tanks" restoreBegin(0.14) restoreEnd(0.3) start(20) finish(120) growTime(0.7) growTable(1) cp(4.1) )
	}	
	{"p:payback_5"	
		{gameMode "with_payback"}
		{unitMode "tanks_only"}
		{specMode "tankcp_5"}
		{apply "tanks_expense"}
		("payback_tanks" restoreBegin(0.16) restoreEnd(0.34) start(20) finish(140) growTime(0.7) growTable(1) cp(5.1) )
	}	
	{"p:payback_6"	
		{gameMode "with_payback"}
		{unitMode "tanks_only"}
		{specMode "tankcp_6"}
		{apply "tanks_expense"}
		("payback_tanks" restoreBegin(0.2) restoreEnd(0.4) start(20) finish(160) growTime(0.7) growTable(1) cp(6.1) )
	}
;------------------------------------------------------------------------------------------------------------
;by Pheonix
	{"wu:without_update_2"
		{gameMode "without_update"}
		{unitMode "tanks_only"}
		{specMode "tankcp_2"}
		{apply "tanks_expense"}
		("instant_tanks" cp_total(2.1) start(250))
	}
	{"wu:without_update_3"
		{gameMode "without_update"}
		{unitMode "tanks_only"}
		{specMode "tankcp_3"}
		{apply "tanks_expense"}
		("instant_tanks" cp_total(3.1) start(300))
	}
	{"wu:without_update_4"
		{gameMode "without_update"}
		{unitMode "tanks_only"}
		{specMode "tankcp_4"}
		{apply "tanks_expense"}
		("instant_tanks" cp_total(4.1) start(400))
	}
	{"wu:without_update_5"
		{gameMode "without_update"}
		{unitMode "tanks_only"}
		{specMode "tankcp_5"}
		{apply "tanks_expense"}
		("instant_tanks" cp_total(5.1) start(500))
	}
	{"wu:without_update_6"
		{gameMode "without_update"}
		{unitMode "tanks_only"}
		{specMode "tankcp_6"}
		{apply "tanks_expense"}
		("instant_tanks" cp_total(6.1) start(600))
	}
}
