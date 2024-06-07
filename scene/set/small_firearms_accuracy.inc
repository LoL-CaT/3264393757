;SDL
(define "accuracy_3" 
	{spreading 
		{radiusTable {0 0} {20 %r1} {40 %r2} {55 %r3} {100 %r4}}
	}		
)
(define "accuracy_4" 
	{spreading 
		{radiusTable {0 0} {5 %r1} {15 %r2} {30 %r3} {60 %r4} {120 (* 3 %r4)} {240 (* 6 %r4)}}
	}		
)
(define "accuracy_5" 
	{spreading 
		{radiusTable {0 0} {5 %r1} {15 %r2} {25 %r3} {35 %r4}}
	}		
)
(define "accuracy_6" 
	{spreading 
		{radiusTable {0 0} {5 %r1} {10 %r2} {20 %r3} {35 %r4}}
	}		
)
(define "accuracy_radius_smg" 
	{spreading 
		{radiusTable {0 0} {5 %r1} {20 %r2} {30 %r3} {40 %r4} {60 %r5}}
	}		
)
(define "accuracy_radius_pistol" 
	{spreading 
		{radiusTable {0 0} {15 %r1} {30 %r2} {45 %r3} {60 %r4}}
	}		
)
(define "accuracy_radius_rifle" 
	{spreading 
		{radiusTable {0 0} {5 %r1} {15 %r2} {25 %r3} {35 %r4} {60 %r5}}
	}		
)
(define "accuracy_radius_rifle_grenade" 
	{spreading 
		{radiusTable {0 0} {5 1} {10 1} {20 1.4} {30 1.8} {60 1.8}}
	}	
	{parameters "fg"
		{spreading
			{radiusTable {0 0} {5 %r1} {10 %r2} {20 %r3} {30 %r4} {60 %r5}}
		}		
	}	
)
(define "accuracy_radius_recoilless" 
	{spreading 
		{radiusTable {0 0} {5 %r1} {10 %r2} {20 %r2} {30 %r2} {60 %r2}}
		{SmokeHitMultiplier 30}		
	}	
	{parameters "fg"
		{spreading
			{radiusTable {0 0} {5 %r1} {10 %r2} {20 %r3} {30 %r4} {60 %r5}}
			{SmokeHitMultiplier 7}
		}		
	}	
)
(define "accuracy_radius_mgun" 
	{spreading 
		{radiusTable {0 0} {5 %r1} {15 %r2} {30 %r3} {40 %r4} {60 (* 1.5 %r5)} {120 (* 2 %r5)}}
	}		
)
(define "accuracy_radius_shotgun" 
	{spreading 
		{radiusTable {0 0} {5 %r1} {10 %r2} {20 %r3} {35 %r4} {60 %r5}}
	}		
)
;________________________________________________________________
;Rifle

;Sub-machine guns________________________________________________
(define "accuracy_smg"
	("accuracy_5" 			r1(0.03) r2(0.75) r3(1.75) r4(2.5) r5(3.5))
)
(define "accuracy_smg_mp35"
	("accuracy_radius_smg" 	r1(0.03) r2(0.55) r3(1.5) r4(2.2) r5(3.5))
		{spreading
			{SpreadPower	1.1}
			{SpreadYadjust	0.1}			
		}	
)
(define "accuracy_smg_mp40"
	("accuracy_radius_smg" 	r1(0.03) r2(0.55) r3(1.5) r4(2.1) r5(3.5))
		{spreading
			{SpreadPower	1.3}
			{SpreadYadjust	0.1}			
		}	
)
(define "accuracy_smg_ppsh"
	("accuracy_radius_smg" 	r1(0.03) r2(0.60) r3(1.62) r4(2.3) r5(3.5))
		{spreading
			{SpreadPower	1}
			{SpreadYadjust	0.1}			
		}	
)
(define "accuracy_smg_pps43"
	("accuracy_radius_smg" 	r1(0.03) r2(0.5) r3(1.6) r4(2.3) r5(3.5))
		{spreading
			{SpreadPower	1.3}
			{SpreadYadjust	0.1}			
		}	
)
(define "accuracy_smg_pps43_fold"
	("accuracy_radius_smg" 	r1(0.03) r2(0.45) r3(1.6) r4(2.35) r5(3.55))
		{spreading
			{SpreadPower	1.3}
			{SpreadYadjust	0.1}			
		}	
)
(define "accuracy_smg_thompson"
	("accuracy_radius_smg" 	r1(0.03) r2(0.75) r3(1.75) r4(2.5) r5(3.5))
		{spreading
			{SpreadPower	1}
			{SpreadYadjust	0.1}				
		}	
)
(define "accuracy_smg_thompson_m1a1"
	("accuracy_radius_smg" 	r1(0.03) r2(0.55) r3(1.5) r4(2.5) r5(3.5))
		{spreading
			{SpreadPower	1}
			{SpreadYadjust	0.1}				
		}	
)
(define "accuracy_smg_m3"
	("accuracy_radius_smg" 	r1(0.03) r2(0.55) r3(1.5) r4(2.2) r5(3.5))
		{spreading
			{SpreadPower	1.2}
			{SpreadYadjust	0.1}			
		}	
)
(define "accuracy_smg_sten"
	("accuracy_radius_smg" 	r1(0.03) r2(0.55) r3(1.7) r4(2.2) r5(3.6))
		{spreading
			{SpreadPower	1.3}
			{SpreadYadjust	0.1}			
		}	
)
;Assault Rifle
(define "accuracy_assault_rifle"
	("accuracy_radius_rifle" r1(0.01) r2(0.5) r3(1.5) r4(2) r5(3.5))
)
;Rifle
(define "accuracy_rifle_g33"
	("accuracy_radius_rifle" r1(0.01) r2(0.28) r3(0.85) r4(1.1) r5(2.6))
)
(define "accuracy_rifle"
	("accuracy_radius_rifle" r1(0.01) r2(0.3) r3(0.9) r4(1.1) r5(2.6))
)
;Auto Rifle
(define "accuracy_automatic_rifle"
	("accuracy_radius_rifle" r1(0.01) r2(0.3) r3(0.9) r4(1.1) r5(2.6))
)
;Carbine
(define "accuracy_carabine"
	("accuracy_radius_rifle" r1(0.01) r2(0.5) r3(1.3) r4(1.6) r5(3.1))
)
;Sniper
(define "accuracy_sniper_rifle"
	("accuracy_radius_rifle" r1(0.01) r2(0.3) r3(0.8) r4(0.9) r5(2.5))
)
;rifle_grenade
(define "accuracy_rifle_grenade"
	("accuracy_radius_rifle_grenade" r1(1) r2(1.1) r3(1.65) r4(2.4) r5(3.25))
)
;recoilless rifle
(define "accuracy_rifle_m18rr"
	("accuracy_radius_recoilless" r1(0.23) r2(0.75) r3(2.2) r4(3.2) r5(5.8))
)
;Shotgun
(define "accuracy_shotgun"
	("accuracy_radius_shotgun" r1(0.01) r2(0.25) r3(1) r4(2) r5(3.2))
		{spreading
			{SpreadPower	2}
			{SpreadYadjust	0.1}				
		}	
)
;PISTOL
(define "accuracy_pistol"
	("accuracy_radius_pistol" r1(0.01) r2(1) r3(3) r4(5))
)
(define "accuracy_pistol_semiauto"
	("accuracy_radius_pistol" r1(0.01) r2(1.2) r3(4) r4(7))
)
(define "accuracy_pistol_silence"
	("accuracy_radius_pistol" r1(0.01) r2(1) r3(2) r4(3))
)
;MGUN
(define "accuracy_mgun"
	("accuracy_radius_mgun" r1(0.35) r2(0.5) r3(1.2) r4(2.2) r5(1.8))
)
(define "accuracy_mgun_light"
	("accuracy_radius_mgun" r1(0.3) r2(0.45) r3(1.2) r4(2.2) r5(1.725))
)
(define "accuracy_mgun_stan"
	("accuracy_radius_mgun" r1(0.25) r2(0.45) r3(1.0) r4(2.0) r5(1.725))
)
(define "accuracy_hmgun_stan"
	("accuracy_radius_mgun" r1(0.25) r2(0.45) r3(1.0) r4(2.0) r5(1.725))
)
(define "accuracy_mgun_vh"
	("accuracy_radius_mgun" r1(0.35) r2(0.55) r3(1.25) r4(2.25) r5(1.875))
)
(define "accuracy_hmgun_vh"
	("accuracy_radius_mgun" r1(0.35) r2(0.55) r3(1.25) r4(2.25) r5(1.875))
)
(define "accuracy_hmgun_plus_vh"
	("accuracy_radius_mgun" r1(0.25) r2(0.45) r3(1.0) r4(2.0) r5(1.725))
)
(define "accuracy_hmgun_plus_stan"
	("accuracy_radius_mgun" r1(0.25) r2(0.45) r3(1.0) r4(2.0) r5(1.725))
)
;OTHER___________________________________________________________





(define "accuracy_dshk"
	("accuracy_3" r1(2) r2(4) r3(6) r4(10))
)
(define "accuracy_uberbrowning"
	("accuracy_3" r1(0.25) r2(1.25) r3(2) r4(10))
)

