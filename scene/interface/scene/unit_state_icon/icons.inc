; SDL
(define "human_need_observed_icon"
	 ability {"stealth"} or breed_mask "*/bazooker" "*/bazooker_m18" "*/flamer" "*/sturmovik_flame" "*/sniper" "*/jaeger_sniper" "*/nkvd_sniper" "*/devil_sniper"
)
(define "observed_or_suspected"
	;{if observed {icon "observed_%_type" {color DRED}}}
	{if %_condition_suspected 
		{fill
			{sprite "background/rhomb_fill_64"}
			{progress "suspect"}
		}
		{if suspect_stage "detected" {icon "suspect_%_type/stage3" {color DRED}}}
		{if suspect_stage "suspected" {icon "suspect_%_type/stage2" {color DYELLOW}}}
		{if suspect_stage "hidden" {icon "suspect_%_type/stage1" {color DGREEN}}}
	}
)