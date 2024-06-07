;SDL
(define "place-chance"
	{place "%name" (+ %chance %k)}
)
(define "kill_crew_ex"
	{if rand 0.33
		{kill_crew_by_weapon
			{weapon %weapon}
			{max_kill %max_kill}
			("place-chance" name(charger) chance(%charger) k(%k))
			("place-chance" name(charger2) chance(%charger2) k(%k))
			("place-chance" name(gunner) chance(%gunner) k(%k))
			("place-chance" name(driver) chance(%driver) k(%k))
			("place-chance" name(commander) chance(%commander) k(%k))
			("place-chance" name(gunner2) chance(%gunner2) k(%k))
			("place-chance" name(gunner3) chance(%gunner3) k(%k))
			("place-chance" name(gunner4) chance(%gunner4) k(%k))
		}
	else rand 0.5
		{kill_crew_by_weapon
			{weapon %weapon}
			{max_kill %max_kill}
			("place-chance" name(commander) chance(%commander) k(%k))
			("place-chance" name(gunner4) chance(%gunner4) k(%k))
			("place-chance" name(gunner3) chance(%gunner3) k(%k))
			("place-chance" name(gunner2) chance(%gunner2) k(%k))
			("place-chance" name(gunner) chance(%gunner) k(%k))
			("place-chance" name(driver) chance(%driver) k(%k))
			("place-chance" name(charger) chance(%charger) k(%k))
			("place-chance" name(charger2) chance(%charger2) k(%k))
		}
	else
		{kill_crew_by_weapon
			{weapon %weapon}
			{max_kill %max_kill}
			("place-chance" name(gunner2) chance(%gunner2) k(%k))
			("place-chance" name(gunner4) chance(%gunner4) k(%k))
			("place-chance" name(charger) chance(%charger) k(%k))
			("place-chance" name(charger2) chance(%charger2) k(%k))
			("place-chance" name(driver) chance(%driver) k(%k))
			("place-chance" name(commander) chance(%commander) k(%k))
			("place-chance" name(gunner) chance(%gunner) k(%k))
			("place-chance" name(gunner3) chance(%gunner3) k(%k))
		}
	}
)
(define "set_all_params_kill_crew"
	{if flag "open_wheelhouse" and not component "body"
	("kill_crew_ex" 
		weapon("") 
		max_kill(%max_kill)
		k(0.75)
		charger(%charger)
		charger2(%charger2)
		driver(%driver) 
		gunner(%gunner) 
		commander(%commander) 
		gunner2(%gunner2)
		gunner3(%gunner3)
		gunner4(%gunner4)
	)
	else
	("kill_crew_ex" 
		weapon("") 
		max_kill(%max_kill)
		k(0)
		charger(%charger)
		charger2(%charger2)
		driver(%driver) 
		gunner(%gunner) 
		commander(%commander) 
		gunner2(%gunner2)
		gunner3(%gunner3)
		gunner4(%gunner4)
	)
	}
)