{on pierce
	{call "check_ur_pierce"}
	{call "breakage"}
;	{call "step_killing_of_passengers"}
   ;///////////////////////////////////////////////////////// hmgun
    ("damage_process_pierce"
        staff(hmgun)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0.1)
        pierce_front_back_track(0.08)
        pierce_left_right_track(0.04)
        pierce_inventory__explosive(0)
    ;--------------------------
        insta_kill(0)
        pierce_body__body_brake(0)
        pierce_body__body_destroy(0)
    ;--------------------------
		  crew_shock_time(0)
		  pierce_rand_contusion(0)
    ;--------------------------
        pierce_turret__explosive(0)

        pierce_turret_front__turret_brake(0)
        pierce_turret_back__turret_brake(0)
        pierce_turret_left_right__turret_brake(0)

        pierce_turret_front__gun_brake(0.2)   pierce_mantlet__gun_brake(0.5)
        pierce_turret_back__gun_brake(0.2)
        pierce_turret_left_right__gun_brake(0.2)

    ;---------------------------
        pierce_engine__engine_brake(0.2)
        pierce_engine__engine_burn(0.15)
    ;--------------------------
		pierce_shield(0)

    ;Probability crew die
		max_kill(0)
    ;--------------------------
        pierce_body__kill_charger(0)
		pierce_body__kill_charger2(0)
        pierce_body__kill_gunner(0)
		pierce_body__kill_gunner3(0)
		pierce_body__kill_gunner4(0)
        pierce_body__kill_driver(0)
        pierce_body__kill_commander(0)
        pierce_body__kill_gunner2(0)
    ;--------------------------
        pierce_turret__kill_charger(0)
		pierce_turret__kill_charger2(0)
        pierce_turret__kill_gunner(0)
		pierce_turret__kill_gunner3(0)
		pierce_turret__kill_gunner4(0)
        pierce_turret__kill_driver(0)
        pierce_turret__kill_commander(0)
        pierce_turret__kill_gunner2(0)
    )
    ;///////////////////////////////////////////////////////// ptr
   ("damage_process_pierce"
        staff(ptr)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0.6)
        pierce_front_back_track(0.6)
        pierce_left_right_track(0.4)
        pierce_inventory__explosive(0.1)
    ;--------------------------
        insta_kill(0)
        pierce_body__body_brake(0.25)
        pierce_body__body_destroy(0.15)
    ;--------------------------
		  crew_shock_time(3.7)
		  pierce_rand_contusion(1.0)
    ;--------------------------
        pierce_turret__explosive(0.15)

        pierce_turret_front__turret_brake(1.0)
        pierce_turret_back__turret_brake(1.0)
        pierce_turret_left_right__turret_brake(1.0)

        pierce_turret_front__gun_brake(1.0) pierce_mantlet__gun_brake(1.0)
        pierce_turret_back__gun_brake(1.0)
        pierce_turret_left_right__gun_brake(1.0)

    ;---------------------------
        pierce_engine__engine_brake(1.0)
        pierce_engine__engine_burn(0.15)

    ;--------------------------
		pierce_shield(0)

    ;Probability crew die
		max_kill(1)
    ;--------------------------
        pierce_body__kill_charger(0.65)
		pierce_body__kill_charger2(0.65)
        pierce_body__kill_gunner(0.65)
		pierce_body__kill_gunner3(0.65)
		pierce_body__kill_gunner4(0.65)
        pierce_body__kill_driver(0.65)
        pierce_body__kill_commander(0.65)
        pierce_body__kill_gunner2(0.65)
    ;--------------------------
        pierce_turret__kill_charger(0.65)
		pierce_turret__kill_charger2(0.65)
        pierce_turret__kill_gunner(0.65)
		pierce_turret__kill_gunner3(0.65)
		pierce_turret__kill_gunner4(0.65)
        pierce_turret__kill_driver(0.65)
        pierce_turret__kill_commander(0.65)
        pierce_turret__kill_gunner2(0.65)
    )
    ;///////////////////////////////////////////////////////// 20mm
   ("damage_process_pierce"
        staff(20mm)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0.3)
        pierce_front_back_track(0.15)
        pierce_left_right_track(0.1)
        pierce_inventory__explosive(0.15)
    ;--------------------------
        insta_kill(0)
        pierce_body__body_brake(0.1)
        pierce_body__body_destroy(0.1)
    ;--------------------------
		  crew_shock_time(0)
		  pierce_rand_contusion(0)
    ;--------------------------
        pierce_turret__explosive(0)

        pierce_turret_front__turret_brake(0)
        pierce_turret_back__turret_brake(0)
        pierce_turret_left_right__turret_brake(0)

        pierce_turret_front__gun_brake(0.4) pierce_mantlet__gun_brake(0.8)
        pierce_turret_back__gun_brake(0.3)
        pierce_turret_left_right__gun_brake(0.2)

    ;---------------------------
        pierce_engine__engine_brake(0.5)
        pierce_engine__engine_burn(0.3)

    ;--------------------------
		pierce_shield(0)

    ;Probability crew die
		max_kill(0)
    ;--------------------------
        pierce_body__kill_charger(0.35)
		pierce_body__kill_charger2(0.35)
        pierce_body__kill_gunner(0.4)
		pierce_body__kill_gunner3(0.4)
		pierce_body__kill_gunner4(0.4)
        pierce_body__kill_driver(0.4)
        pierce_body__kill_commander(0.3)
        pierce_body__kill_gunner2(0)
    ;--------------------------
        pierce_turret__kill_charger(0.25)
		pierce_turret__kill_charger2(0.25)
        pierce_turret__kill_gunner(0.4)
		pierce_turret__kill_gunner3(0.4)
		pierce_turret__kill_gunner4(0.4)
        pierce_turret__kill_driver(0)
        pierce_turret__kill_commander(0.4)
        pierce_turret__kill_gunner2(0.35)
    )
    ;///////////////////////////////////////////////////////// 28_apcr
   ("damage_process_pierce"
        staff(28_apcr)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0.4)
        pierce_front_back_track(0.6)
        pierce_left_right_track(0.3)
        pierce_inventory__explosive(0.2)
    ;--------------------------
        insta_kill(0)
        pierce_body__body_brake(0.05)
        pierce_body__body_destroy(0.025)
    ;--------------------------
		  crew_shock_time(3.7)
		  pierce_rand_contusion(1.0)
    ;--------------------------
        pierce_turret__explosive(0)

        pierce_turret_front__turret_brake(1.0)
        pierce_turret_back__turret_brake(1.0)
        pierce_turret_left_right__turret_brake(1.0)

        pierce_turret_front__gun_brake(1.0) pierce_mantlet__gun_brake(1.0)
        pierce_turret_back__gun_brake(1.0)
        pierce_turret_left_right__gun_brake(1.0)

    ;---------------------------
        pierce_engine__engine_brake(1.0)
        pierce_engine__engine_burn(0.15)

    ;--------------------------
		pierce_shield(0)

    ;Probability crew die
		max_kill(1)
    ;--------------------------
        pierce_body__kill_charger(0.65)
		pierce_body__kill_charger2(0.65)
        pierce_body__kill_gunner(0.65)
		pierce_body__kill_gunner3(0.65)
		pierce_body__kill_gunner4(0.65)
        pierce_body__kill_driver(0.65)
        pierce_body__kill_commander(0.65)
        pierce_body__kill_gunner2(0.65)
    ;--------------------------
        pierce_turret__kill_charger(0.65)
		pierce_turret__kill_charger2(0.65)
        pierce_turret__kill_gunner(0.65)
		pierce_turret__kill_gunner3(0.65)
		pierce_turret__kill_gunner4(0.65)
        pierce_turret__kill_driver(0.65)
        pierce_turret__kill_commander(0.65)
        pierce_turret__kill_gunner2(0.65)
    )
	
    ;///////////////////////////////////////////////////////// 37to47
    ("damage_process_pierce"
        staff(37to47_apcr)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0.4)
        pierce_front_back_track(0.6)
        pierce_left_right_track(0.3)
        pierce_inventory__explosive(0.2)
    ;--------------------------
        insta_kill(0)
        pierce_body__body_brake(0.1)
        pierce_body__body_destroy(0.1)
    ;--------------------------
		  crew_shock_time(0)
		  pierce_rand_contusion(0)
    ;--------------------------
        pierce_turret__explosive(0.1)

        pierce_turret_front__turret_brake(0)
        pierce_turret_back__turret_brake(0)
        pierce_turret_left_right__turret_brake(0)

        pierce_turret_front__gun_brake(0.2) pierce_mantlet__gun_brake(0.8)
        pierce_turret_back__gun_brake(0.2)
        pierce_turret_left_right__gun_brake(0.2)

    ;---------------------------
        pierce_engine__engine_brake(0.5)
        pierce_engine__engine_burn(0.3)

    ;--------------------------
		pierce_shield(0)

    ;Probability crew die
		max_kill(1)
    ;--------------------------
        pierce_body__kill_charger(0.1)
		pierce_body__kill_charger2(0.1)
        pierce_body__kill_gunner(0.1)
		pierce_body__kill_gunner3(0.1)
		pierce_body__kill_gunner4(0.1)
        pierce_body__kill_driver(0.1)
        pierce_body__kill_commander(0.1)
        pierce_body__kill_gunner2(0)
    ;--------------------------
        pierce_turret__kill_charger(0.1)
		pierce_turret__kill_charger2(0.1)
        pierce_turret__kill_gunner(0.1)
		pierce_turret__kill_gunner3(0.1)
		pierce_turret__kill_gunner4(0.1)
        pierce_turret__kill_driver(0)
        pierce_turret__kill_commander(0.15)
        pierce_turret__kill_gunner2(0.1)
    )	
   ("damage_process_pierce"
        staff(37to47)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0.4)
        pierce_front_back_track(0.6)
        pierce_left_right_track(0.3)
        pierce_inventory__explosive(0.2)
    ;--------------------------
        insta_kill(0)
        pierce_body__body_brake(0.3)
        pierce_body__body_destroy(0.2)
    ;--------------------------
		  crew_shock_time(0)
		  pierce_rand_contusion(0)
    ;--------------------------
        pierce_turret__explosive(0.15)

        pierce_turret_front__turret_brake(0)
        pierce_turret_back__turret_brake(0)
        pierce_turret_left_right__turret_brake(0)

        pierce_turret_front__gun_brake(0.2) pierce_mantlet__gun_brake(0.8)
        pierce_turret_back__gun_brake(0.2)
        pierce_turret_left_right__gun_brake(0.2)

    ;---------------------------
        pierce_engine__engine_brake(0.5)
        pierce_engine__engine_burn(0.3)

    ;--------------------------
		pierce_shield(0)

    ;Probability crew die
		max_kill(1)
    ;--------------------------
        pierce_body__kill_charger(0.2)
		pierce_body__kill_charger2(0.2)
        pierce_body__kill_gunner(0.2)
		pierce_body__kill_gunner3(0.2)
		pierce_body__kill_gunner4(0.2)
        pierce_body__kill_driver(0.2)
        pierce_body__kill_commander(0.15)
        pierce_body__kill_gunner2(0)
    ;--------------------------
        pierce_turret__kill_charger(0.1)
		pierce_turret__kill_charger2(0.1)
        pierce_turret__kill_gunner(0.2)
		pierce_turret__kill_gunner3(0.2)
		pierce_turret__kill_gunner4(0.2)
        pierce_turret__kill_driver(0)
        pierce_turret__kill_commander(0.25)
        pierce_turret__kill_gunner2(0.2)
    )
    ;///////////////////////////////////////////////////////// 50to57
	("damage_process_pierce"
        staff(50to57_apcr)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1)
        pierce_front_back_track(0.8)
        pierce_left_right_track(0.3)
        pierce_inventory__explosive(0.2)
    ;--------------------------
        insta_kill(0)
        pierce_body__body_brake(0.1)
        pierce_body__body_destroy(0.1)
    ;--------------------------
		  crew_shock_time(0)
		  pierce_rand_contusion(0)
    ;--------------------------
        pierce_turret__explosive(0.1)

        pierce_turret_front__turret_brake(0)
        pierce_turret_back__turret_brake(0)
        pierce_turret_left_right__turret_brake(0)

        pierce_turret_front__gun_brake(0.4) pierce_mantlet__gun_brake(0.8)
        pierce_turret_back__gun_brake(0.3)
        pierce_turret_left_right__gun_brake(0.2)

    ;---------------------------
        pierce_engine__engine_brake(0.75)
        pierce_engine__engine_burn(0.3)

    ;--------------------------
		pierce_shield(0)

    ;Probability crew die
		max_kill(1)
    ;--------------------------
        pierce_body__kill_charger(0.15)
		pierce_body__kill_charger2(0.15)
        pierce_body__kill_gunner(0.15)
		pierce_body__kill_gunner2(0.15)
		pierce_body__kill_gunner3(0.15)
        pierce_body__kill_driver(0.15)
        pierce_body__kill_commander(0.15)
        pierce_body__kill_gunner2(0)
    ;--------------------------
        pierce_turret__kill_charger(0.1)
		pierce_turret__kill_charger2(0.1)
        pierce_turret__kill_gunner(0.15)
		pierce_turret__kill_gunner3(0.15)
		pierce_turret__kill_gunner4(0.15)
        pierce_turret__kill_driver(0)
        pierce_turret__kill_commander(0.2)
        pierce_turret__kill_gunner2(0.15)
    )
   ("damage_process_pierce"
        staff(50to57)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1)
        pierce_front_back_track(0.8)
        pierce_left_right_track(0.3)
        pierce_inventory__explosive(0.2)
    ;--------------------------
        insta_kill(0)
        pierce_body__body_brake(0.4)
        pierce_body__body_destroy(0.3)
    ;--------------------------
		  crew_shock_time(0)
		  pierce_rand_contusion(0)
    ;--------------------------
        pierce_turret__explosive(0.2)

        pierce_turret_front__turret_brake(0)
        pierce_turret_back__turret_brake(0)
        pierce_turret_left_right__turret_brake(0)

        pierce_turret_front__gun_brake(0.4) pierce_mantlet__gun_brake(0.8)
        pierce_turret_back__gun_brake(0.3)
        pierce_turret_left_right__gun_brake(0.2)

    ;---------------------------
        pierce_engine__engine_brake(0.75)
        pierce_engine__engine_burn(0.3)

    ;--------------------------
		pierce_shield(0)

    ;Probability crew die
		max_kill(1)
    ;--------------------------
        pierce_body__kill_charger(0.3)
		pierce_body__kill_charger2(0.3)
        pierce_body__kill_gunner(0.3)
		pierce_body__kill_gunner2(0.3)
		pierce_body__kill_gunner3(0.3)
        pierce_body__kill_driver(0.3)
        pierce_body__kill_commander(0.25)
        pierce_body__kill_gunner2(0)
    ;--------------------------
        pierce_turret__kill_charger(0.2)
		pierce_turret__kill_charger2(0.2)
        pierce_turret__kill_gunner(0.3)
		pierce_turret__kill_gunner3(0.3)
		pierce_turret__kill_gunner4(0.3)
        pierce_turret__kill_driver(0)
        pierce_turret__kill_commander(0.35)
        pierce_turret__kill_gunner2(0.3)
    )
    ;///////////////////////////////////////////////////////// 75to76
	("damage_process_pierce"
        staff(75to76_apcr)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1)
        pierce_front_back_track(1)
        pierce_left_right_track(0.5)
        pierce_inventory__explosive(0.35)
    ;--------------------------
        insta_kill(0)
        pierce_body__body_brake(0.2)
        pierce_body__body_destroy(0.15)
    ;--------------------------
		  crew_shock_time(0)
		  pierce_rand_contusion(0)
    ;--------------------------
        pierce_turret__explosive(0.15)

        pierce_turret_front__turret_brake(0)
        pierce_turret_back__turret_brake(0)
        pierce_turret_left_right__turret_brake(0)

        pierce_turret_front__gun_brake(0.4) pierce_mantlet__gun_brake(0.8)
        pierce_turret_back__gun_brake(0.3)
        pierce_turret_left_right__gun_brake(0.2)

    ;---------------------------
        pierce_engine__engine_brake(0.75)
        pierce_engine__engine_burn(0.35)

    ;--------------------------
		pierce_shield(0)

    ;Probability crew die
		max_kill(2)
    ;--------------------------
        pierce_body__kill_charger(0.25)
		pierce_body__kill_charger2(0.25)
        pierce_body__kill_gunner(0.25)
		pierce_body__kill_gunner3(0.25)
		pierce_body__kill_gunner4(0.25)
        pierce_body__kill_driver(0.25)
        pierce_body__kill_commander(0.225)
        pierce_body__kill_gunner2(0)
    ;--------------------------
        pierce_turret__kill_charger(0.125)
		pierce_turret__kill_charger2(0.125)
        pierce_turret__kill_gunner(0.125)
		pierce_turret__kill_gunner3(0.125)
		pierce_turret__kill_gunner4(0.125)
        pierce_turret__kill_driver(0)
        pierce_turret__kill_commander(0.275)
        pierce_turret__kill_gunner2(0.25)
    )
	
   ("damage_process_pierce"
        staff(75to76)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1)
        pierce_front_back_track(1)
        pierce_left_right_track(0.5)
        pierce_inventory__explosive(0.35)
    ;--------------------------
        insta_kill(1)
        pierce_body__body_brake(1.6)
        pierce_body__body_destroy(0.5)
    ;--------------------------
		  crew_shock_time(0)
		  pierce_rand_contusion(0)
    ;--------------------------
        pierce_turret__explosive(0.3)

        pierce_turret_front__turret_brake(0)
        pierce_turret_back__turret_brake(0)
        pierce_turret_left_right__turret_brake(0)

        pierce_turret_front__gun_brake(0.4) pierce_mantlet__gun_brake(0.8)
        pierce_turret_back__gun_brake(0.3)
        pierce_turret_left_right__gun_brake(0.2)

    ;---------------------------
        pierce_engine__engine_brake(0.75)
        pierce_engine__engine_burn(0.35)

    ;--------------------------
		pierce_shield(0)

    ;Probability crew die
		max_kill(2)
    ;--------------------------
        pierce_body__kill_charger(0.5)
		pierce_body__kill_charger2(0.5)
        pierce_body__kill_gunner(0.5)
		pierce_body__kill_gunner3(0.5)
		pierce_body__kill_gunner4(0.5)
        pierce_body__kill_driver(0.5)
        pierce_body__kill_commander(0.45)
        pierce_body__kill_gunner2(0)
    ;--------------------------
        pierce_turret__kill_charger(0.25)
		pierce_turret__kill_charger2(0.25)
        pierce_turret__kill_gunner(0.5)
		pierce_turret__kill_gunner3(0.5)
		pierce_turret__kill_gunner4(0.5)
        pierce_turret__kill_driver(0)
        pierce_turret__kill_commander(0.55)
        pierce_turret__kill_gunner2(0.5)
    )
    ;///////////////////////////////////////////////////////// 85mm
	("damage_process_pierce"
        staff(85mm_apcr)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1)
        pierce_front_back_track(0.9)
        pierce_left_right_track(0.3)
        pierce_inventory__explosive(0.5)
    ;--------------------------
        insta_kill(0)
        pierce_body__body_brake(0.3)
        pierce_body__body_destroy(0.3)
    ;--------------------------
		  crew_shock_time(0)
		  pierce_rand_contusion(0)
    ;--------------------------
        pierce_turret__explosive(0.3)

        pierce_turret_front__turret_brake(0)
        pierce_turret_back__turret_brake(0)
        pierce_turret_left_right__turret_brake(0)

        pierce_turret_front__gun_brake(0.4) pierce_mantlet__gun_brake(0.8)
        pierce_turret_back__gun_brake(0.3)
        pierce_turret_left_right__gun_brake(0.2)

    ;---------------------------
        pierce_engine__engine_brake(1)
        pierce_engine__engine_burn(0.3)

    ;--------------------------
		pierce_shield(0)

    ;Probability crew die
		max_kill(2)
    ;--------------------------
        pierce_body__kill_charger(0.3)
		pierce_body__kill_charger2(0.3)
        pierce_body__kill_gunner(0.3)
		pierce_body__kill_gunner3(0.3)
		pierce_body__kill_gunner4(0.3)
        pierce_body__kill_driver(0.3)
        pierce_body__kill_commander(0.25)
        pierce_body__kill_gunner2(0.15)
    ;--------------------------
        pierce_turret__kill_charger(0.15)
		pierce_turret__kill_charger2(0.15)
        pierce_turret__kill_gunner(0.25)
		pierce_turret__kill_gunner3(0.25)
		pierce_turret__kill_gunner4(0.25)
        pierce_turret__kill_driver(0.15)
        pierce_turret__kill_commander(0.3)
        pierce_turret__kill_gunner2(0.25)
    )
   ("damage_process_pierce"
        staff(85mm)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1)
        pierce_front_back_track(0.9)
        pierce_left_right_track(0.3)
        pierce_inventory__explosive(0.5)
    ;--------------------------
        insta_kill(1)
        pierce_body__body_brake(1.6)
        pierce_body__body_destroy(1.0)
    ;--------------------------
		  crew_shock_time(0)
		  pierce_rand_contusion(0)
    ;--------------------------
        pierce_turret__explosive(0.4)

        pierce_turret_front__turret_brake(0)
        pierce_turret_back__turret_brake(0)
        pierce_turret_left_right__turret_brake(0)

        pierce_turret_front__gun_brake(0.4) pierce_mantlet__gun_brake(0.8)
        pierce_turret_back__gun_brake(0.3)
        pierce_turret_left_right__gun_brake(0.2)

    ;---------------------------
        pierce_engine__engine_brake(1)
        pierce_engine__engine_burn(0.3)

    ;--------------------------
		pierce_shield(0)

    ;Probability crew die
		max_kill(2)
    ;--------------------------
        pierce_body__kill_charger(0.55)
		pierce_body__kill_charger2(0.55)
        pierce_body__kill_gunner(0.55)
		pierce_body__kill_gunner3(0.55)
		pierce_body__kill_gunner4(0.55)
        pierce_body__kill_driver(0.55)
        pierce_body__kill_commander(0.5)
        pierce_body__kill_gunner2(0.27)
    ;--------------------------
        pierce_turret__kill_charger(0.27)
		pierce_turret__kill_charger2(0.27)
        pierce_turret__kill_gunner(0.55)
		pierce_turret__kill_gunner3(0.55)
		pierce_turret__kill_gunner4(0.55)
        pierce_turret__kill_driver(0.27)
        pierce_turret__kill_commander(0.6)
        pierce_turret__kill_gunner2(0.55)
    )
    ;///////////////////////////////////////////////////////// 88to105
	("damage_process_pierce"
        staff(88to105_apcr)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1)
        pierce_front_back_track(1)
        pierce_left_right_track(0.5)
        pierce_inventory__explosive(0.6)
    ;--------------------------
        insta_kill(0)
        pierce_body__body_brake(0.3)
        pierce_body__body_destroy(0.3)
    ;--------------------------
		  crew_shock_time(0)
		  pierce_rand_contusion(0)
    ;--------------------------
        pierce_turret__explosive(0.3)

        pierce_turret_front__turret_brake(0)
        pierce_turret_back__turret_brake(0)
        pierce_turret_left_right__turret_brake(0)

        pierce_turret_front__gun_brake(0.4) pierce_mantlet__gun_brake(0.8)
        pierce_turret_back__gun_brake(0.3)
        pierce_turret_left_right__gun_brake(0.2)

    ;---------------------------
        pierce_engine__engine_brake(1)
        pierce_engine__engine_burn(0.3)

    ;--------------------------
		pierce_shield(0)

    ;Probability crew die
		max_kill(2)
    ;--------------------------
        pierce_body__kill_charger(0.3)
		pierce_body__kill_charger2(0.3)
        pierce_body__kill_gunner(0.3)
		pierce_body__kill_gunner3(0.3)
		pierce_body__kill_gunner4(0.3)
        pierce_body__kill_driver(0.3)
        pierce_body__kill_commander(0.25)
        pierce_body__kill_gunner2(0.15)
    ;--------------------------
        pierce_turret__kill_charger(0.15)
		pierce_turret__kill_charger2(0.15)
        pierce_turret__kill_gunner(0.3)
		pierce_turret__kill_gunner3(0.3)
		pierce_turret__kill_gunner4(0.3)
        pierce_turret__kill_driver(0.15)
        pierce_turret__kill_commander(0.35)
        pierce_turret__kill_gunner2(0.3)
    )
   ("damage_process_pierce"
        staff(88to105)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1)
        pierce_front_back_track(1)
        pierce_left_right_track(0.5)
        pierce_inventory__explosive(0.6)
    ;--------------------------
        insta_kill(1)
        pierce_body__body_brake(1.6)
        pierce_body__body_destroy(1.1)
    ;--------------------------
		  crew_shock_time(0)
		  pierce_rand_contusion(0)
    ;--------------------------
        pierce_turret__explosive(0.45)

        pierce_turret_front__turret_brake(0)
        pierce_turret_back__turret_brake(0)
        pierce_turret_left_right__turret_brake(0)

        pierce_turret_front__gun_brake(0.4) pierce_mantlet__gun_brake(0.8)
        pierce_turret_back__gun_brake(0.3)
        pierce_turret_left_right__gun_brake(0.2)

    ;---------------------------
        pierce_engine__engine_brake(1)
        pierce_engine__engine_burn(0.3)

    ;--------------------------
		pierce_shield(0)

    ;Probability crew die
		max_kill(2)
    ;--------------------------
        pierce_body__kill_charger(0.6)
		pierce_body__kill_charger2(0.6)
        pierce_body__kill_gunner(0.6)
		pierce_body__kill_gunner3(0.6)
		pierce_body__kill_gunner4(0.6)
        pierce_body__kill_driver(0.6)
        pierce_body__kill_commander(0.55)
        pierce_body__kill_gunner2(0.3)
    ;--------------------------
        pierce_turret__kill_charger(0.3)
		pierce_turret__kill_charger2(0.3)
        pierce_turret__kill_gunner(0.6)
		pierce_turret__kill_gunner3(0.6)
		pierce_turret__kill_gunner4(0.6)
        pierce_turret__kill_driver(0.3)
        pierce_turret__kill_commander(0.65)
        pierce_turret__kill_gunner2(0.6)
    )
    ;///////////////////////////////////////////////////////// 122to128
   ("damage_process_pierce"
        staff(122to128)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1)
        pierce_front_back_track(1)
        pierce_left_right_track(0.7)
        pierce_inventory__explosive(1)
    ;--------------------------
        insta_kill(1)
        pierce_body__body_brake(1.6)
        pierce_body__body_destroy(1.15)
    ;--------------------------
		  crew_shock_time(1)
		  pierce_rand_contusion(0.5)
    ;--------------------------
        pierce_turret__explosive(0.65)

        pierce_turret_front__turret_brake(0)
        pierce_turret_back__turret_brake(0)
        pierce_turret_left_right__turret_brake(0)

        pierce_turret_front__gun_brake(1) pierce_mantlet__gun_brake(1)
        pierce_turret_back__gun_brake(0.8)
        pierce_turret_left_right__gun_brake(0.6)

    ;---------------------------
        pierce_engine__engine_brake(1)
        pierce_engine__engine_burn(0.5)

    ;--------------------------
		pierce_shield(0)

    ;Probability crew die
		max_kill(2)
    ;--------------------------
        pierce_body__kill_charger(0.65)
		pierce_body__kill_charger2(0.65)
        pierce_body__kill_gunner(0.65)
		pierce_body__kill_gunner3(0.65)
		pierce_body__kill_gunner4(0.65)
        pierce_body__kill_driver(0.65)
        pierce_body__kill_commander(0.6)
        pierce_body__kill_gunner2(0.32)
    ;--------------------------
        pierce_turret__kill_charger(0.32)
		pierce_turret__kill_charger2(0.32)
        pierce_turret__kill_gunner(0.65)
		pierce_turret__kill_gunner3(0.65)
		pierce_turret__kill_gunner4(0.65)
        pierce_turret__kill_driver(0.32)
        pierce_turret__kill_commander(0.7)
        pierce_turret__kill_gunner2(0.65)
    )
    ;///////////////////////////////////////////////////////// 150to152
   ("damage_process_pierce"
        staff(150to152)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1)
        pierce_front_back_track(1)
        pierce_left_right_track(1)
        pierce_inventory__explosive(1)
    ;--------------------------
        insta_kill(1)
        pierce_body__body_brake(1.6)
        pierce_body__body_destroy(1.3)
    ;--------------------------
		  crew_shock_time(1)
		  pierce_rand_contusion(0.5)
    ;--------------------------
        pierce_turret__explosive(0.75)

        pierce_turret_front__turret_brake(0)
        pierce_turret_back__turret_brake(0)
        pierce_turret_left_right__turret_brake(0)

        pierce_turret_front__gun_brake(1) pierce_mantlet__gun_brake(1)
        pierce_turret_back__gun_brake(1)
        pierce_turret_left_right__gun_brake(1)

    ;---------------------------
        pierce_engine__engine_brake(1)
        pierce_engine__engine_burn(0.5)

    ;--------------------------
		pierce_shield(0)

    ;Probability crew die
		max_kill(2)
    ;--------------------------
        pierce_body__kill_charger(0.7)
		pierce_body__kill_charger2(0.7)
        pierce_body__kill_gunner(0.7)
		pierce_body__kill_gunner3(0.7)
		pierce_body__kill_gunner4(0.7)
        pierce_body__kill_driver(0.7)
        pierce_body__kill_commander(0.65)
        pierce_body__kill_gunner2(0.35)
    ;--------------------------
        pierce_turret__kill_charger(0.35)
		pierce_turret__kill_charger2(0.35)
        pierce_turret__kill_gunner(0.7)
		pierce_turret__kill_gunner3(0.7)
		pierce_turret__kill_gunner4(0.7)
        pierce_turret__kill_driver(0.35)
        pierce_turret__kill_commander(0.75)
        pierce_turret__kill_gunner2(0.7)
    )
    ;///////////////////////////////////////////////////////// rocketlauncher
   ("damage_process_pierce"
        staff(rocketlauncher)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1)
        pierce_front_back_track(1)
        pierce_left_right_track(0.7)
        pierce_inventory__explosive(0)
    ;--------------------------
        insta_kill(1)
        pierce_body__body_brake(0.5)
        pierce_body__body_destroy(0.4)
    ;--------------------------
		  crew_shock_time(2)
		  pierce_rand_contusion(1)
    ;--------------------------
        pierce_turret__explosive(0.4)

        pierce_turret_front__turret_brake(1)
        pierce_turret_back__turret_brake(1)
        pierce_turret_left_right__turret_brake(1)

        pierce_turret_front__gun_brake(0.4) pierce_mantlet__gun_brake(0.5)
        pierce_turret_back__gun_brake(0.2)
        pierce_turret_left_right__gun_brake(0.2)

    ;---------------------------
        pierce_engine__engine_brake(1)
        pierce_engine__engine_burn(0.5)

    ;--------------------------
		pierce_shield(0.5)

    ;Probability crew die
		max_kill(2)
    ;--------------------------
        pierce_body__kill_charger(0.7)
		pierce_body__kill_charger2(0.7)
        pierce_body__kill_gunner(0.7)
		pierce_body__kill_gunner3(0.7)
		pierce_body__kill_gunner4(0.7)
        pierce_body__kill_driver(0.7)
        pierce_body__kill_commander(0.7)
        pierce_body__kill_gunner2(0.4)
    ;--------------------------
        pierce_turret__kill_charger(0.4)
		pierce_turret__kill_charger2(0.4)
        pierce_turret__kill_gunner(0.7)
		pierce_turret__kill_gunner3(0.7)
		pierce_turret__kill_gunner4(0.7)
        pierce_turret__kill_driver(0.4)
        pierce_turret__kill_commander(0.7)
        pierce_turret__kill_gunner2(0.7)
    )
	;///////////////////////////////////////////////////////// AT grenade
   ("damage_process_pierce"
        staff(cumulative_charge)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1)
        pierce_front_back_track(1)
        pierce_left_right_track(0.7)
        pierce_inventory__explosive(0)
    ;--------------------------
        insta_kill(1)
        pierce_body__body_brake(0.6)
        pierce_body__body_destroy(0.35)
    ;--------------------------
		  crew_shock_time(2)
		  pierce_rand_contusion(1)
    ;--------------------------
        pierce_turret__explosive(0.35)

        pierce_turret_front__turret_brake(1)
        pierce_turret_back__turret_brake(1)
        pierce_turret_left_right__turret_brake(1)

        pierce_turret_front__gun_brake(0.4) pierce_mantlet__gun_brake(0.5)
        pierce_turret_back__gun_brake(0.2)
        pierce_turret_left_right__gun_brake(0.2)

    ;---------------------------
        pierce_engine__engine_brake(1)
        pierce_engine__engine_burn(0.5)

    ;--------------------------
		pierce_shield(0)

    ;Probability crew die
		max_kill(2)
    ;--------------------------
        pierce_body__kill_charger(0.8)
		pierce_body__kill_charger2(0.8)
        pierce_body__kill_gunner(0.8)
		pierce_body__kill_gunner3(0.8)
		pierce_body__kill_gunner4(0.8)
        pierce_body__kill_driver(0.8)
        pierce_body__kill_commander(0.8)
        pierce_body__kill_gunner2(0.4)
    ;--------------------------
        pierce_turret__kill_charger(0.4)
		pierce_turret__kill_charger2(0.4)
        pierce_turret__kill_gunner(0.8)
		pierce_turret__kill_gunner3(0.8)
		pierce_turret__kill_gunner4(0.8)
        pierce_turret__kill_driver(0.4)
        pierce_turret__kill_commander(0.8)
        pierce_turret__kill_gunner2(0.8)
    )

   ("damage_process_pierce"
        staff(cumulative_charge_shell75_76)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0.5)
        pierce_front_back_track(0.5)
        pierce_left_right_track(0.35)
        pierce_inventory__explosive(0)
    ;--------------------------
        insta_kill(0)
        pierce_body__body_brake(0.5)
        pierce_body__body_destroy(0.15)
    ;--------------------------
		  crew_shock_time(2)
		  pierce_rand_contusion(1)
    ;--------------------------
        pierce_turret__explosive(0.15)

        pierce_turret_front__turret_brake(0.5)
        pierce_turret_back__turret_brake(0.5)
        pierce_turret_left_right__turret_brake(0.5)

        pierce_turret_front__gun_brake(0.2) pierce_mantlet__gun_brake(0.25)
        pierce_turret_back__gun_brake(0.1)
        pierce_turret_left_right__gun_brake(0.1)

    ;---------------------------
        pierce_engine__engine_brake(0.5)
        pierce_engine__engine_burn(0.3)

    ;--------------------------
		pierce_shield(0)

    ;Probability crew die
		max_kill(1)
    ;--------------------------
        pierce_body__kill_charger(0.4)
		pierce_body__kill_charger2(0.4)
        pierce_body__kill_gunner(0.4)
		pierce_body__kill_gunner3(0.4)
		pierce_body__kill_gunner4(0.4)
        pierce_body__kill_driver(0.4)
        pierce_body__kill_commander(0.4)
        pierce_body__kill_gunner2(0.2)
    ;--------------------------
        pierce_turret__kill_charger(0.2)
		pierce_turret__kill_charger2(0.2)
        pierce_turret__kill_gunner(0.4)
		pierce_turret__kill_gunner3(0.4)
		pierce_turret__kill_gunner4(0.4)
        pierce_turret__kill_driver(0.2)
        pierce_turret__kill_commander(0.4)
        pierce_turret__kill_gunner2(0.4)
    )
	{call "destroy_or_explosion"}
}; end of pierce
;=================================================================================================================================================
{on bullet_hit
	{if stuff "ani_play_hit"
		{ani_play "hit"}
	}
	{if stuff "fg" or stuff "fr"
		{set "hit_bullet_fg" 1};for blast
	}
	{if relation "enemy"
		{if stuff "fg 150to152" or stuff "fr 150to152"
			{if component "wheelleft" or component "wheelleft1" or component "wheelleft2" or component "wheelleft3" or component "wheelleft4" or component "wheelright" or component "wheelright1" or component "wheelright2" or component "wheelright3" or component "wheelright4" or component "trackright" or component "trackleft"
				{component break}
;			else component "body" or component "turret"
;				{call "explosion"}
			}
		else stuff "fg 122to128" or stuff "fr 122to128"
			{if component "wheelleft" or component "wheelleft1" or component "wheelleft2" or component "wheelleft3" or component "wheelleft4" or component "wheelright" or component "wheelright1" or component "wheelright2" or component "wheelright3" or component "wheelright4" or component "trackright" or component "trackleft"
				{component break}
;			else component "body" or component "turret"
;				{if rand 0.5
;					{call "explosion"}
;				else rand 0.25
;					{call "mp_destroy"}
;				}				
			}
		else stuff "fg 88to105" or stuff "fr 88to105"
			{if component "wheelleft" or component "wheelleft1" or component "wheelleft2" or component "wheelleft3" or component "wheelleft4" or component "wheelright" or component "wheelright1" or component "wheelright2" or component "wheelright3" or component "wheelright4" or component "trackright" or component "trackleft"
				{component break}
			else component "body" or component "turret"
;				{if rand 0.33
;					{call "explosion"}
;				else rand 0.2
;					{call "mp_destroy"}
;				}				
			}
		else stuff "fg fx77_90" or stuff "fr fx77_90"
			{if component "wheelleft" or component "wheelleft1" or component "wheelleft2" or component "wheelleft3" or component "wheelleft4" or component "wheelright" or component "wheelright1" or component "wheelright2" or component "wheelright3" or component "wheelright4" or component "trackright" or component "trackleft"
				{component break}
			}
		else stuff "fg fx61_76" or stuff "fr fx61_76"
			{if component "wheelleft" or component "wheelleft1" or component "wheelleft2" or component "wheelleft3" or component "wheelleft4" or component "wheelright" or component "wheelright1" or component "wheelright2" or component "wheelright3" or component "wheelright4" or component "trackright" or component "trackleft"
				{component break}
			}
		else stuff "fg fx47_60" or stuff "fr fx47_60"
			{if component "wheelleft" or component "wheelleft1" or component "wheelleft2" or component "wheelleft3" or component "wheelleft4" or component "wheelright" or component "wheelright1" or component "wheelright2" or component "wheelright3" or component "wheelright4" or component "trackright" or component "trackleft"
				{component break}
			}
		}
	}
}; end of bullet_hit

	{on blast ;higher energy must be first
		{if flag "hit_bullet_fg" and can_be_damaged
			{set "hit_bullet_fg" 0}
			("blast_damage_contusion"
			blast_rand_contusion(1)
			blast_energy(10)
			blast_crew_shock_time(6)
			)
			("blast_damage_contusion"
			blast_rand_contusion(1)
			blast_energy(8)
			blast_crew_shock_time(3.75)
			)
			("blast_damage_contusion"
			blast_rand_contusion(1)
			blast_energy(5)
			blast_crew_shock_time(3)
			)
			("blast_damage_contusion"
			blast_rand_contusion(0.6)
			blast_energy(2)
			blast_crew_shock_time(2.25)
			)
		}
		{delay 0.1
			{if armor_health -399
				{call "mp_destroy_off"}
			}
		}
	}
	
{on break_armor
	{if name "blast" and stuff "mine antitank"	{call "pierce_or_blast"}}
	{call "destroy_or_explosion_break_armor"}
}
{on "kill_pass"
		(define "seat_places"
			{place "seat1" %0}
			{place "seat2" %0}
			{place "seat3" %0}
			{place "seat4" %0}
			{place "seat5" %0}
			{place "seat6" %0}
			{place "seat7" %0}
			{place "seat8" %0}
			{place "seat9" %0}
			{place "seat10" %0}
		)
		{kill_crew_by_weapon
			{weapon ""}
			{max_kill 2}
			{min_crew_count 1}
			("seat_places" args 0.2)
			{place "gunner" 0}
			{place "gunner1" 0}
			{place "gunner2" 0}
			{place "charger" 0}
			{place "commander" 0}
			{place "driver" 0}
		}
}
{on "step_killing_of_passengers"
		(define "step_killing"
			{if armor_health %hp and %not1 flag "kill_crew_state1" and %not2 flag "kill_crew_state2" and %not3 flag "kill_crew_state3"
				{call "kill_pass"}
				{set "kill_crew_state1"	%set1}
				{set "kill_crew_state2"	%set2}
				{set "kill_crew_state3"	%set3}
			}
		)
		("step_killing" hp(300)	not1(not)	not2(not)	not3(not)		set1(0) set2(0) set3(1))
		("step_killing" hp(250)	not1(not)	not2(not)	not3() 			set1(0) set2(1) set3(0))
		("step_killing" hp(200)	not1(not)	not2()		not3(not) 		set1(0) set2(1) set3(1))
		("step_killing" hp(150)	not1(not)	not2()		not3() 			set1(1) set2(0) set3(0))
		("step_killing" hp(100)	not1()		not2(not)	not3(not) 		set1(1) set2(0) set3(1))
		("step_killing" hp(50)	not1()		not2(not)	not3() 			set1(1) set2(1) set3(1))
}