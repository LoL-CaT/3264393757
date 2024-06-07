;(define "common_set_wp"
;		{common
;			{unitset "inf|squad|mortar|degtyarev_stan|mg34_stan|m37|pak35|m3cannon|browning_stan^at_miners|at_rifle|bazookers|engineers"}
;			{commandPoints "stormtroopers=18;snipers=15;scouts=15;officer=10;infantry=48;cannon=45;mortar=35"}
;			{chargeFactors "*=1"}
;			{budgets
;				{squad   
;					{resource 
;						{start 		8}
;						{finish 	100}
;						{speed 		12}
;						{limitmin	10}
;						{limitmax	50}
;						{speedset 	"5 8 12 16 20"}
;					} 
;					{buttons "squad1 squad2 vh_cn vh_cn1 lt ht asu"} 
;					{growFactors "0/1;30/0.65;50/0.3;200/0.5"}
;				}
;			} 
;		}
;)

;(define "common_set_pu"
;		{common
;			{unitset "squad|mortar|degtyarev_stan|mg34_stan|browning_stan^at_miners"}
;			{commandPoints "stormtroopers=10"}
;			{chargeFactors "moto=1;*=0"}
;			{budgets
;				{squad 
;					{resource 
;						{start 		15}
;						{finish 	100}
;						{speed 		30}
;						{limitmin	10}
;						{limitmax	70}
;						{period		180}
;					} 
;					{buttons "squad1 squad2 vh_cn vh_cn1 lt ht asu"} 
;					{growFactors "0/1;80/0.7;200/0.5"}
;				}
;			} 
;		}
;)


(define "instant_infantry"
	{common
		{unitset "inf|squad|mortar|degtyarev_stan|mg34_stan|browning_stan|vickers_mgun|type1hmg_stan|m37|pak35|m3cannon|qf2|pak47^at_miners|at_rifle|bazookers|engineers|tankmans|isuzutx40_mort|type4_200mm|kamikaze"}
		{commandPoints "inf=20;sniper=20;scout=20;officer=20;cannon=45;mortar=45;degtyarev_stan=75;mg34_stan=75;browning_stan=75;vickers_mgun=75;type1hmg_stan=75;*=%cp"}
		{chargeFactors "inf=1.5;cannon=1.5;mortar=1.5;degtyarev_stan=1.5;mg34_stan=1.5;browning_stan=1.5;vickers_mgun=1.5:type1hmg_stan=1.5;*=1"}
		{budgets
			{vehicle 
				{mode "without_update"}
				{resource 
					{start 		%start}
					{finish 	800}
					{speed 		0}
					{limitmin	100}
					{limitmax	800}
					{speedset 	"100 150 200 250 300"}
				} 
				{buttons "squad1 squad2 auto vh_cn"}
			}

		} 
	}
)

; with payback
(define "payback_infantry"
	{common
		{unitset "inf|squad|mortar|degtyarev_stan|mg34_stan|browning_stan|vickers_mgun|type1hmg_stan|m37|pak35|m3cannon|qf2|pak47^at_miners|at_rifle|bazookers|engineers|tankmans|isuzutx40_mort|type4_200mm|kamikaze"}
		{chargeFactors "inf=1.5;cannon=1.5;mortar=1.5;degtyarev_stan=1.5;mg34_stan=1.5;browning_stan=1.5;vickers_mgun=1.5:type1hmg_stan=1.5;*=1"}
		{commandPoints "inf=20;sniper=20;scout=20;officer=20;cannon=45;mortar=45;degtyarev_stan=75;mg34_stan=75;browning_stan=75;vickers_mgun=75;type1hmg_stan=75;*=%cp"}
		{budgets
			{vehicle
				{mode "with_payback"}
				{resource 
					{start 		%start}
					{finish 	%finish}
					{growTime	0.7}			; round time when money growing
					{restoreBegin 	%restoreBegin}		; points per sec
					{restoreEnd 	%restoreEnd}		; points per sec
				} 
				{buttons "squad1 squad2 auto vh_cn"}
			}

		} 
	}
)

; without payback
(define "without_payback_infantry"
	{common
		{unitset "inf|squad|mortar|degtyarev_stan|mg34_stan|browning_stan|vickers_mgun|type1hmg_stan|m37|pak35|m3cannon|qf2|pak47^at_miners|at_rifle|bazookers|engineers|tankmans|isuzutx40_mort|type4_200mm|kamikaze"}
		{chargeFactors "inf=1.5;cannon=1.5;mortar=1.5;degtyarev_stan=1.5;mg34_stan=1.5;browning_stan=1.5;vickers_mgun=1.5:type1hmg_stan=1.5;*=1"}
		{commandPoints "inf=40;sniper=20;scout=20;officer=20;cannon=45;mortar=45;degtyarev_stan=75;mg34_stan=75;browning_stan=75;vickers_mgun=75;type1hmg_stan=75;*=%cp"}
		{budgets
			{vehicle
				{mode "without_payback"}
				{resource 
					{start 		%start}
					{finish 	%finish}
					{growTime	%growTime}				; part-time round when money growing
					{growTable 	"%growTable"}
					{limitmin	100}
					{limitmax	400}
					{speedset 	"100 150 200 250 300"}
				} 
				{buttons "squad1 squad2 auto vh_cn"}
			}

		} 
	}
)

{presets
	{"p:no_payback_60_inf"	
		{gameMode "without_payback"}
		{unitMode "infantry"}
		{specMode "squad_60"}
		{apply "squads_expense"}
		("without_payback_infantry" start(8) finish(100) growTime(0.6) growTable(0.5 0.6 0.6 0.7 0.7 0.8 0.9 1 1 1 1 1) cp(60))
	}		
	{"p:no_payback_80_inf"	
		{gameMode "without_payback"}
		{unitMode "infantry"}
		{specMode "platoon_80"}
		{apply "squads_expense"}
		("without_payback_infantry" start(8) finish(200) growTime(0.6) growTable(0.5 0.6 0.6 0.7 0.7 0.8 0.9 1 1 1 1 1) cp(80))
	}
	{"p:no_payback_100_inf"	
		{gameMode "without_payback"}
		{unitMode "infantry"}
		{specMode "company_100"}
		{apply "squads_expense"}
		("without_payback_infantry" start(8) finish(250) growTime(0.6) growTable(0.5 0.6 0.6 0.7 0.7 0.8 0.9 1 1 1 1 1) cp(100))
	}
;--------------------------------------------------------------------------------------------
	{"p:payback_60_inf"	
		{gameMode "with_payback"}
		{unitMode "infantry"}
		{specMode "squad_60"}
		{apply "squads_expense"}
		("payback_infantry" restoreBegin(0.20) restoreEnd(0.28) start(8) finish(100) cp(60))
	}
	{"p:payback_80_inf"	
		{gameMode "with_payback"}
		{unitMode "infantry"}
		{specMode "platoon_80"}
		{apply "squads_expense"}
		("payback_infantry" restoreBegin(0.24) restoreEnd(0.32) start(8) finish(120) cp(80))
	}	
	{"p:payback_100_inf"	
		{gameMode "with_payback"}
		{unitMode "infantry"}
		{specMode "company_100"}
		{apply "squads_expense"}
		("payback_infantry" restoreBegin(0.24) restoreEnd(0.38) start(8) finish(140) cp(100))
	}	
;--------------------------------------------------------------------------------------------
	{"wu:without_update_low_inf"
		{gameMode "without_update"}
		{unitMode "infantry"}
		{specMode "squad_60"}
		{apply "squads_expense"}
		("instant_infantry" cp(60) start(150))
	}
	{"wu:without_update_normal_inf"
		{gameMode "without_update"}
		{unitMode "infantry"}
		{specMode "platoon_80"}
		{apply "squads_expense"}
		("instant_infantry" cp(80) start(200))
	}
	{"wu:without_update_high_inf"
		{gameMode "without_update"}
		{unitMode "infantry"}
		{specMode "company_100"}
		{apply "squads_expense"}
		("instant_infantry" cp(100) start(250))
	}
}
