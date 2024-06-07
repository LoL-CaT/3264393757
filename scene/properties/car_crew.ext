;SDL

;//////////////////////////////////////////////////////////////////////////////

(define "board_animation"
	{boarder
		{anm "%place"
			{forward	{begin	"%board_begin"} {end "%board_end"} {base "%base"}}
			{reverse 	{end	"%board_begin" -1} {base "%base" -1}}
		}
	}
)

(define "crew_inside"
	("board_animation" place(driver)	board_begin(board_bigcar) board_end(seat_driver_car) base(doordriver))
	("board_animation" place(passenger)	board_begin(board_bigcar) board_end(seat_passenger)	 base(doorpassenger))
	("board_animation" place(commander)	board_begin(board_bigcar) board_end(seat_passenger)	 base(doorcommander))
)

(define "crew_human"
	{placer
		{place "%place"
			{group "%place"}
			{linkbone "%bone"}
			{turnoff {sensor} {shadow} {targetable}}
		}
	}
	{boarder
		{door "%door"}
		{link "%door" "%place" {anm "%animation"} {forward putoff} {reverse puton}}
	}
)

(define "crew_2_human"
	("crew_inside")
	("crew_human" place(driver)		bone(driver)	door(emit1) animation(driver))
	("crew_human" place(commander)	bone(commander)	door(emit2) animation(commander))
)

(define "crew_3_human"
	("crew_inside")
	("crew_human" place(driver)		bone(driver)	door(emit1) animation(driver))
	("crew_human" place(commander)	bone(commander)	door(emit2) animation(commander))
)

(define "passenger_2_human"
	("crew_human" place(seat1)	bone(seat01)	door(emit3)	animation(passenger))
	("crew_human" place(seat2)	bone(seat02)	door(emit4)	animation(passenger))
)
(define "passenger_10_human"
	("passenger_2_human")
	("crew_human" place(seat3)	bone(seat03)	door(emit3)	animation(passenger))
	("crew_human" place(seat4)	bone(seat04)	door(emit4)	animation(passenger))
	("crew_human" place(seat5)	bone(seat05)	door(emit3)	animation(passenger))
	("crew_human" place(seat6)	bone(seat06)	door(emit4)	animation(passenger))
	("crew_human" place(seat7)	bone(seat07)	door(emit3)	animation(passenger))
	("crew_human" place(seat8)	bone(seat08)	door(emit4) animation(passenger))
	("crew_human" place(seat9)	bone(seat09)	door(emit3) animation(passenger))
	("crew_human" place(seat10)	bone(seat10)	door(emit4) animation(passenger))
)

;//////////////////////////////////////////////////////////////////////////////
(define "seat_inside"
	{boarder
		{anm "passenger"
			{forward	{begin	"board_tank"}}
			{reverse 	{end	"board_tank" -1}}
		}
	}
)
(define "passenger_invisible"
	{placer
		{place "%place" {group "%place"} {linkbone "%bone"} {turnoff {sensor} {visible}}}
	}
	{boarder
		{door "%door"}
		{link "%door" "%place" {anm "%animation"} {forward putoff} {reverse puton}}
	}
)
(define "passenger_10_human_invisible"
	("seat_inside")
	("passenger_invisible" place(seat1)	bone(seat01)	door(emit3) animation(passenger))
	("passenger_invisible" place(seat2)	bone(seat02)	door(emit4)	animation(passenger))
	("passenger_invisible" place(seat3)	bone(seat03)	door(emit3)	animation(passenger))
	("passenger_invisible" place(seat4)	bone(seat04)	door(emit4)	animation(passenger))
	("passenger_invisible" place(seat5)	bone(seat05)	door(emit3)	animation(passenger))
	("passenger_invisible" place(seat6)	bone(seat06)	door(emit4)	animation(passenger))
	("passenger_invisible" place(seat7)	bone(seat07)	door(emit3)	animation(passenger))
	("passenger_invisible" place(seat8)	bone(seat08)	door(emit4)	animation(passenger))
	("passenger_invisible" place(seat9)	bone(seat09)	door(emit3)	animation(passenger))
	("passenger_invisible" place(seat10) bone(seat10)	door(emit4)	animation(passenger))
)
