(define "accuracy_radius_rifle" 
	{spreading 
		{radiusTable {0 0} {5 %r1} {30 %r2} {40 %r3} {60 %r4} {80 %r5}}
	}		
)
(define "accuracy_radius_smg" 
	{spreading 
		{radiusTable {0 0} {5 %r1} {20 %r2} {30 %r3} {40 %r4} {60 %r5}}
	}		
)
(define "accuracy_radius_mgun" 
	{spreading 
		{radiusTable {0 0} {5 %r1} {30 %r2} {40 %r3} {60 %r4} {80 (* 1.5 %r5)} {120 (* 2 %r5)}}
	}		
)