{const "charge/ignore_enemies" 15}		; ¬рем€ действи€ режима 'ignore enemies'
{const "charge/cooldown" 30}	; in seconds
{const "morale/ignore_enemies" -1}		; –ежим 'ignore enemies' выключаетс€ если мораль падает ниже этого значени€
;{const "ai_squad/last_underfire_passed_to_crawl" 4} ; ≈сли любой юнит из сквада был атакован менее секунд назад, весь сквад будет перемещатьс€ ползком
;{const "ai_squad/last_underfire_passed_to_lie" 6} 	; ≈сли любой юнит из сквада был атакован менее секунд назад, весь сквад
							; между перемещени€ми будет лежать
{const "ai_squad/morale_to_lie_threshold" 85} ; ≈сли мораль сквада падает ниже этого значени€, весь сквад будет лежать\передвигатьс€ ползком

{morale                                 		
	{full_gather_time 60}			; ¬рем€ полного восстановлени€ морали естественным образом в секундах.
	{mod_inc_by_power_ratio {1 1}}  	; allyPower/enemyPower k (на k умножаетс€ величина приращени€ морали)
	{mod_dec_by_power_ratio {1 1}}  	; allyPower/enemyPower k (на k умножаетс€ величина уменьшени€ морали)
	{advance_threshold 31}			; минимальное значение морали, необходимое дл€ наступлени€
	{retreat_threshold 0}			; если мораль упадет ниже значени€, юнит будет отступать
	{flee_threshold 0}			; если мораль упадет ниже значени€, юнит будет спасатьс€ бегством
	{motion_interval {1 0.1} {29 5} {31 5} {50 2} {100 1}} ; интервал между перебежками в зависимости от морали
						; мораль <= retreat_threshold - перебежки будут в обратную сторону 
}