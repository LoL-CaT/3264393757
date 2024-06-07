;SDL
;============================= SPAWN DISTANCE =================================
;generic
(define "spawn_distance_default" 	{spawn_distance 190})

;vehicles
(define "spawn_distance_mortar" 	{spawn_distance 95})
(define "spawn_distance_airborne"	{spawn_distance 500})

;soldiers
(define "spawn_distance_corpsman"	{spawn_distance 30})
(define "spawn_distance_miner"		{spawn_distance 150})

;================================	 CW	  =====================================
;generic
(define "cw_s0"					{cw 0})

;vehicles
(define "cw_s1"					{cw 15 20 25 0})
(define "cw_s2"					{cw 5 3 20 0})
(define "cw_s3"					{cw 3 10 5 0})
(define "cw_s8"					{cw 25 25 25 0})

;soldiers
(define "cw_s4"					{cw 25 1 30 0})
(define "cw_s5"					{cw 25 2 30 0})
(define "cw_s6"					{cw 15 3 25 0})
(define "cw_s7"					{cw 25 0.5 30 0})
(define "cw_sp"					{cw 15 0.95 20 0.75 30 0})
(define "cw_officer"			{cw 15 5 25 0})

;===============================	 SCORE	  ===================================
(define "score"					{score (/ %sc 3)})