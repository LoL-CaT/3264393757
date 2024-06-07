	{props "steel" "air_bomb_stuff"}
	{constrain ground}
	{extender "stuff"
		{item "%item"}
	}
	(define "range"	(* (+ %p1 (* %p2 (- %cal 75))) 20))
	(define "r1"		("range" p1(2.5) p2(0.02666666667) cal(%cal)))
	(define "r2"		("range" p1(3.5) p2(0.07666666667) cal(%cal)))
	(define "r3"		("range" p1(5) p2(0.07666666667) cal(%cal)))
	(define "r4"		("range" p1(6) p2(0.09) cal(%cal)))
	(define "r5"		("range" p1(8) p2(0.09) cal(%cal)))
	(define "r6"		("range" p1(10.4) p2(0.09) cal(%cal)))
	(define "r7"		("range" p1(10.5) p2(0.09) cal(%cal)))

	(define "circle"
		{volume "circle%n"
			{cylinder ("r%n" cal(%cal)) 1}
			{bone "root"}
		}
	)
	(define "circles"
		("circle" n(1) cal(%cal))
		("circle" n(2) cal(%cal))
		("circle" n(3) cal(%cal))
		("circle" n(4) cal(%cal))
		("circle" n(5) cal(%cal))
		("circle" n(6) cal(%cal))
		("circle" n(7) cal(%cal))
	)

	(define "low_range"	(* %p1 %p2 20))
	(define "low_r1"		("low_range" p1(0.9) p2(%range_k)))
	(define "low_r2"		("low_range" p1(2.4) p2(%range_k)))
	(define "low_r3"		("low_range" p1(3.9) p2(%range_k)))
	(define "low_r4"		("low_range" p1(4.4) p2(%range_k)))
	(define "low_r5"		("low_range" p1(5.4) p2(%range_k)))
	(define "low_r6"		("low_range" p1(6.4) p2(%range_k)))
	(define "low_r7"		("low_range" p1(6.5) p2(%range_k)))

	(define "circle_low"
		{volume "circle%n"
			{cylinder ("low_r%n" range_k(%range_k)) 1}
			{bone "root"}
		}
	)
	(define "circles_low"
		("circle_low" n(1) range_k(%range_k))
		("circle_low" n(2) range_k(%range_k))
		("circle_low" n(3) range_k(%range_k))
		("circle_low" n(4) range_k(%range_k))
		("circle_low" n(5) range_k(%range_k))
		("circle_low" n(6) range_k(%range_k))
		("circle_low" n(7) range_k(%range_k))
	)