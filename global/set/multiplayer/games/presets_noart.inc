; without update without artillery
(define "instant_noart"
	{common
		{unitset "^man|alter|inf|d1|sfh18|bl6|m114|bm37|sgrw42|m1mortar|ml3|how_a|bm13|nebelwerfer42|sdkfz4|land_mattress|m4a3c|su122|chi-ha120|ho-ni2|sturmpz1|hummel|m7|ho-ro|ha-to|t91_105m|bishop|pdr25|sturmtiger|isu152|kv2"}
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
					{speedset 	"200 250 300 350 400"}
				} 
				{buttons "squad1 squad2 auto vh_cn lt ht asu"}
			}

		} 
	}
)

; with payback, noart
(define "payback_noart"
	{common
		{unitset "^man|alter|inf|d1|sfh18|bl6|m114|bm37|sgrw42|m1mortar|ml3|how_a|bm13|nebelwerfer42|sdkfz4|land_mattress|m4a3c|su122|chi-ha120|ho-ni2|sturmpz1|hummel|m7|ho-ro|ha-to|t91_105m|bishop|pdr25|sturmtiger|isu152|kv2"}
		{chargeFactors "moto=1;use_charge=1;*=0"}
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

; without payback, noart
(define "without_payback_noart"
	{common
		{unitset "^man|alter|inf|d1|sfh18|bl6|m114|bm37|sgrw42|m1mortar|ml3|how_a|bm13|nebelwerfer42|sdkfz4|land_mattress|m4a3c|su122|chi-ha120|ho-ni2|sturmpz1|hummel|m7|ho-ro|ha-to|t91_105m|bishop|pdr25|sturmtiger|isu152|kv2"}
		{chargeFactors "moto=1;use_charge=1;*=0"}
		{commandPoints %cp}
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
					{speedset 	"200 250 300 350 400"}
				} 
				{buttons "squad1 squad2 auto vh_cn lt ht asu"}
			}

		} 
	}
)

{presets
	{"p:no_payback_80_noart"	
		{gameMode "without_payback"}
		{unitMode "no_howitzers"}
		{specMode "platoon_80"}
		("without_payback_noart" start(16) finish(300) growTime(0.6) growTable(0.6 0.7 0.7 0.7 0.8 0.8 0.8 0.9 0.9 1 1 1) cp("*=80"))
	}		
	{"p:no_payback_100_noart"	
		{gameMode "without_payback"}
		{unitMode "no_howitzers"}
		{specMode "company_100"}
		("without_payback_noart" start(16) finish(350) growTime(0.6) growTable(0.6 0.7 0.7 0.7 0.8 0.8 0.8 0.9 0.9 1 1 1) cp("*=100"))
	}
	{"p:no_payback_120_noart"	
		{gameMode "without_payback"}
		{unitMode "no_howitzers"}
		{specMode "battalion_120"}
		("without_payback_noart" start(16) finish(400) growTime(0.6) growTable(0.6 0.7 0.7 0.7 0.8 0.8 0.8 0.9 0.9 1 1 1) cp("*=120"))
	}
	{"p:no_payback_140_noart"	
		{gameMode "without_payback"}
		{unitMode "no_howitzers"}
		{specMode "regiment_140"}
		("without_payback_noart" start(16) finish(450) growTime(0.6) growTable(0.6 0.7 0.7 0.7 0.8 0.8 0.8 0.9 0.9 1 1 1) cp("*=140"))
	}
	{"p:no_payback_160_noart"	
		{gameMode "without_payback"}
		{unitMode "no_howitzers"}
		{specMode "division_160"}
		("without_payback_noart" start(16) finish(500) growTime(0.6) growTable(0.6 0.7 0.7 0.7 0.8 0.8 0.8 0.9 0.9 1 1 1) cp("*=160"))
	}
;------------------------------------------------------------------------------------------------------------
	{"p:payback_80_noart"	
		{gameMode "with_payback"}
		{unitMode "no_howitzers"}
		{specMode "platoon_80"}
		("payback_noart" restoreBegin(0.14) restoreEnd(0.3) start(12) finish(120) growTime(0.7) growTable(1) cp("*=80"))
	}	
	{"p:payback_100_noart"	
		{gameMode "with_payback"}
		{unitMode "no_howitzers"}
		{specMode "company_100"}
		("payback_noart" restoreBegin(0.14) restoreEnd(0.3) start(12) finish(120) growTime(0.7) growTable(1) cp("*=100"))
	}	
	{"p:payback_120_noart"	
		{gameMode "with_payback"}
		{unitMode "no_howitzers"}
		{specMode "battalion_120"}
		("payback_noart" restoreBegin(0.14) restoreEnd(0.3) start(12) finish(120) growTime(0.7) growTable(1) cp("*=120"))
	}	
	{"p:payback_140_noart"	
		{gameMode "with_payback"}
		{unitMode "no_howitzers"}
		{specMode "regiment_140"}
		("payback_noart" restoreBegin(0.16) restoreEnd(0.34) start(12) finish(140) growTime(0.7) growTable(1) cp("*=120"))
	}	
	{"p:payback_160_noart"	
		{gameMode "with_payback"}
		{unitMode "no_howitzers"}
		{specMode "division_160"}
		("payback_noart" restoreBegin(0.2) restoreEnd(0.4) start(12) finish(160) growTime(0.7) growTable(1) cp("*=120"))
	}
;------------------------------------------------------------------------------------------------------------
	{"wu:without_update_100_noart"
		{gameMode "without_update"}
		{unitMode "no_howitzers"}
		{specMode "company_100"}
		("instant_noart" cp_total(100) start(300))
	}
	{"wu:without_update_80_noart"
		{gameMode "without_update"}
		{unitMode "no_howitzers"}
		{specMode "platoon_80"}
		("instant_noart" cp_total(80) start(250))
	}
	{"wu:without_update_120_noart"
		{gameMode "without_update"}
		{unitMode "no_howitzers"}
		{specMode "battalion_120"}
		("instant_noart" cp_total(120) start(350))
	}
	{"wu:without_update_140_noart"
		{gameMode "without_update"}
		{unitMode "no_howitzers"}
		{specMode "regiment_140"}
		("instant_noart" cp_total(140) start(400))
	}
	{"wu:without_update_160_noart"
		{gameMode "without_update"}
		{unitMode "no_howitzers"}
		{specMode "division_160"}
		("instant_noart" cp_total(160) start(400))
	}
}
