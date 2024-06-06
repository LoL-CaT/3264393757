{on pierce
	{call "check_ur_pierce"}
	{call "breakage"}
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
        pierce_turret_left_right__gun_brake(0)

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
        pierce_front_back_track(1)
        pierce_left_right_track(1)
        pierce_inventory__explosive(0.4)
    ;--------------------------
        insta_kill(0)
        pierce_body__body_brake(0.2)
        pierce_body__body_destroy(0.1)
    ;--------------------------
		  crew_shock_time(0)
		  pierce_rand_contusion(0)
    ;--------------------------
        pierce_turret__explosive(0.1)

        pierce_turret_front__turret_brake(0.3)
        pierce_turret_back__turret_brake(0.3)
        pierce_turret_left_right__turret_brake(0.3)

        pierce_turret_front__gun_brake(0.4) pierce_mantlet__gun_brake(0.8)
        pierce_turret_back__gun_brake(0.3)
        pierce_turret_left_right__gun_brake(0)

    ;---------------------------
        pierce_engine__engine_brake(0.5)
        pierce_engine__engine_burn(0.3)

    ;--------------------------
		pierce_shield(1)

    ;Probability crew die
		max_kill(1)
    ;--------------------------
        pierce_body__kill_charger(0.1)
		pierce_body__kill_charger2(0.1)
        pierce_body__kill_gunner(0.1)
		pierce_body__kill_gunner3(0.1)
		pierce_body__kill_gunner4(0.1)
        pierce_body__kill_driver(0.1)
        pierce_body__kill_commander(0.07)
        pierce_body__kill_gunner2(0)
    ;--------------------------
        pierce_turret__kill_charger(0.07)
		pierce_turret__kill_charger2(0.07)
        pierce_turret__kill_gunner(0.1)
		pierce_turret__kill_gunner3(0.1)
		pierce_turret__kill_gunner4(0.1)
        pierce_turret__kill_driver(0)
        pierce_turret__kill_commander(0.15)
        pierce_turret__kill_gunner2(0.1)
    )
    ;///////////////////////////////////////////////////////// 20mm
   ("damage_process_pierce"
        staff(20mm)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0.3)
        pierce_front_back_track(0.12)
        pierce_left_right_track(0.05)
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

        pierce_turret_front__gun_brake(0) pierce_mantlet__gun_brake(0)
        pierce_turret_back__gun_brake(0)
        pierce_turret_left_right__gun_brake(0)

    ;---------------------------
        pierce_engine__engine_brake(0.5)
        pierce_engine__engine_burn(0.15)

    ;--------------------------
		pierce_shield(1)

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

    ;///////////////////////////////////////////////////////// 28_apcr
   ("damage_process_pierce"
        staff(28_apcr)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0.4)
        pierce_front_back_track(0.6)
        pierce_left_right_track(0.3)
        pierce_inventory__explosive(0)
    ;--------------------------
        insta_kill(0)
        pierce_body__body_brake(0.025)
        pierce_body__body_destroy(0.01)
    ;--------------------------
		  crew_shock_time(0)
		  pierce_rand_contusion(0)
    ;--------------------------
        pierce_turret__explosive(0)

        pierce_turret_front__turret_brake(0)
        pierce_turret_back__turret_brake(0)
        pierce_turret_left_right__turret_brake(0)

        pierce_turret_front__gun_brake(0) pierce_mantlet__gun_brake(0)
        pierce_turret_back__gun_brake(0)
        pierce_turret_left_right__gun_brake(0)

    ;---------------------------
        pierce_engine__engine_brake(0.5)
        pierce_engine__engine_burn(0.15)

    ;--------------------------
		pierce_shield(1)

    ;Probability crew die
		max_kill(1)
    ;--------------------------
        pierce_body__kill_charger(0.12)
		pierce_body__kill_charger2(0.12)
        pierce_body__kill_gunner(0.12)
		pierce_body__kill_gunner3(0.12)
		pierce_body__kill_gunner4(0.12)
        pierce_body__kill_driver(0.12)
        pierce_body__kill_commander(0.08)
        pierce_body__kill_gunner2(0)
    ;--------------------------
        pierce_turret__kill_charger(0.07)
		pierce_turret__kill_charger2(0.07)
        pierce_turret__kill_gunner(0.12)
		pierce_turret__kill_gunner3(0.12)
		pierce_turret__kill_gunner4(0.12)
        pierce_turret__kill_driver(0)
        pierce_turret__kill_commander(0.17)
        pierce_turret__kill_gunner2(0.12)
    )

    ;///////////////////////////////////////////////////////// 37to47
	("damage_process_pierce"
        staff(37to47_apcr)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0.4)
        pierce_front_back_track(0.6)
        pierce_left_right_track(0.3)
        pierce_inventory__explosive(0)
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

        pierce_turret_front__gun_brake(0) pierce_mantlet__gun_brake(0)
        pierce_turret_back__gun_brake(0)
        pierce_turret_left_right__gun_brake(0)

    ;---------------------------
        pierce_engine__engine_brake(0.5)
        pierce_engine__engine_burn(0.15)

    ;--------------------------
		pierce_shield(1)

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
        pierce_turret__kill_charger(0.07)
		pierce_turret__kill_charger2(0.07)
        pierce_turret__kill_gunner(0.1)
		pierce_turret__kill_gunner3(0.1)
		pierce_turret__kill_gunner4(0.1)
        pierce_turret__kill_driver(0)
        pierce_turret__kill_commander(0.1)
        pierce_turret__kill_gunner2(0.1)
    )
   ("damage_process_pierce"
        staff(37to47)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0.4)
        pierce_front_back_track(0.6)
        pierce_left_right_track(0.3)
        pierce_inventory__explosive(0)
    ;--------------------------
        insta_kill(0)
        pierce_body__body_brake(0.25)
        pierce_body__body_destroy(0.1)
    ;--------------------------
		  crew_shock_time(0)
		  pierce_rand_contusion(0)
    ;--------------------------
        pierce_turret__explosive(0.1)

        pierce_turret_front__turret_brake(0)
        pierce_turret_back__turret_brake(0)
        pierce_turret_left_right__turret_brake(0)

        pierce_turret_front__gun_brake(0) pierce_mantlet__gun_brake(0)
        pierce_turret_back__gun_brake(0)
        pierce_turret_left_right__gun_brake(0)

    ;---------------------------
        pierce_engine__engine_brake(0.5)
        pierce_engine__engine_burn(0.15)

    ;--------------------------
		pierce_shield(1)

    ;Probability crew die
		max_kill(1)
    ;--------------------------
        pierce_body__kill_charger(0.15)
		pierce_body__kill_charger2(0.15)
        pierce_body__kill_gunner(0.15)
		pierce_body__kill_gunner3(0.15)
		pierce_body__kill_gunner4(0.15)
        pierce_body__kill_driver(0.15)
        pierce_body__kill_commander(0.1)
        pierce_body__kill_gunner2(0)
    ;--------------------------
        pierce_turret__kill_charger(0.07)
		pierce_turret__kill_charger2(0.07)
        pierce_turret__kill_gunner(0.15)
		pierce_turret__kill_gunner3(0.15)
		pierce_turret__kill_gunner4(0.15)
        pierce_turret__kill_driver(0)
        pierce_turret__kill_commander(0.2)
        pierce_turret__kill_gunner2(0.15)
    )
    ;///////////////////////////////////////////////////////// 50to57
	("damage_process_pierce"
        staff(50to57_apcr)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1)
        pierce_front_back_track(0.9)
        pierce_left_right_track(0.3)
        pierce_inventory__explosive(0)
    ;--------------------------
        insta_kill(0)
        pierce_body__body_brake(0.15)
        pierce_body__body_destroy(0.1)
    ;--------------------------
		  crew_shock_time(0)
		  pierce_rand_contusion(0)
    ;--------------------------
        pierce_turret__explosive(0.1)

        pierce_turret_front__turret_brake(0)
        pierce_turret_back__turret_brake(0)
        pierce_turret_left_right__turret_brake(0)

        pierce_turret_front__gun_brake(0) pierce_mantlet__gun_brake(0)
        pierce_turret_back__gun_brake(0)
        pierce_turret_left_right__gun_brake(0)

    ;---------------------------
        pierce_engine__engine_brake(0.75)
        pierce_engine__engine_burn(0.15)

    ;--------------------------
		pierce_shield(1)

    ;Probability crew die
		max_kill(1)
    ;--------------------------
        pierce_body__kill_charger(0.15)
		pierce_body__kill_charger2(0.15)
        pierce_body__kill_gunner(0.15)
		pierce_body__kill_gunner3(0.15)
		pierce_body__kill_gunner4(0.15)
        pierce_body__kill_driver(0.15)
        pierce_body__kill_commander(0.1)
        pierce_body__kill_gunner2(0)
    ;--------------------------
        pierce_turret__kill_charger(0.1)
		pierce_turret__kill_charger2(0.1)
        pierce_turret__kill_gunner(0.15)
		pierce_turret__kill_gunner3(0.15)
		pierce_turret__kill_gunner4(0.15)
        pierce_turret__kill_driver(0)
        pierce_turret__kill_commander(0.15)
        pierce_turret__kill_gunner2(0.15)
    )
   ("damage_process_pierce"
        staff(50to57)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1)
        pierce_front_back_track(0.9)
        pierce_left_right_track(0.3)
        pierce_inventory__explosive(0)
    ;--------------------------
        insta_kill(0)
        pierce_body__body_brake(0.25)
        pierce_body__body_destroy(0.15)
    ;--------------------------
		  crew_shock_time(0)
		  pierce_rand_contusion(0)
    ;--------------------------
        pierce_turret__explosive(0.15)

        pierce_turret_front__turret_brake(0)
        pierce_turret_back__turret_brake(0)
        pierce_turret_left_right__turret_brake(0)

        pierce_turret_front__gun_brake(0) pierce_mantlet__gun_brake(0)
        pierce_turret_back__gun_brake(0)
        pierce_turret_left_right__gun_brake(0)

    ;---------------------------
        pierce_engine__engine_brake(0.75)
        pierce_engine__engine_burn(0.15)

    ;--------------------------
		pierce_shield(1)

    ;Probability crew die
		max_kill(1)
    ;--------------------------
        pierce_body__kill_charger(0.25)
		pierce_body__kill_charger2(0.25)
        pierce_body__kill_gunner(0.25)
		pierce_body__kill_gunner3(0.25)
		pierce_body__kill_gunner4(0.25)
        pierce_body__kill_driver(0.25)
        pierce_body__kill_commander(0.2)
        pierce_body__kill_gunner2(0)
    ;--------------------------
        pierce_turret__kill_charger(0.15)
		pierce_turret__kill_charger2(0.15)
        pierce_turret__kill_gunner(0.25)
		pierce_turret__kill_gunner3(0.25)
		pierce_turret__kill_gunner4(0.25)
        pierce_turret__kill_driver(0)
        pierce_turret__kill_commander(0.3)
        pierce_turret__kill_gunner2(0.25)
    )
    ;///////////////////////////////////////////////////////// 75to76
	   ("damage_process_pierce"
        staff(75to76_apcr)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1)
        pierce_front_back_track(1)
        pierce_left_right_track(0.5)
        pierce_inventory__explosive(0)
    ;--------------------------
        insta_kill(0)
        pierce_body__body_brake(0.15)
        pierce_body__body_destroy(0.15)
    ;--------------------------
		  crew_shock_time(0)
		  pierce_rand_contusion(0)
    ;--------------------------
        pierce_turret__explosive(0.15)

        pierce_turret_front__turret_brake(0)
        pierce_turret_back__turret_brake(0)
        pierce_turret_left_right__turret_brake(0)

        pierce_turret_front__gun_brake(0) pierce_mantlet__gun_brake(0)
        pierce_turret_back__gun_brake(0)
        pierce_turret_left_right__gun_brake(0)

    ;---------------------------
        pierce_engine__engine_brake(0.75)
        pierce_engine__engine_burn(0.15)

    ;--------------------------
		pierce_shield(1)

    ;Probability crew die
		max_kill(2)
    ;--------------------------
        pierce_body__kill_charger(0.225)
		pierce_body__kill_charger2(0.225)
        pierce_body__kill_gunner(0.225)
		pierce_body__kill_gunner3(0.225)
		pierce_body__kill_gunner4(0.225)
        pierce_body__kill_driver(0.225)
        pierce_body__kill_commander(0.2)
        pierce_body__kill_gunner2(0)
    ;--------------------------
        pierce_turret__kill_charger(0.11)
		pierce_turret__kill_charger2(0.11)
        pierce_turret__kill_gunner(0.225)
		pierce_turret__kill_gunner3(0.225)
		pierce_turret__kill_gunner4(0.225)
        pierce_turret__kill_driver(0)
        pierce_turret__kill_commander(0.25)
        pierce_turret__kill_gunner2(0.225)
    )
	
   ("damage_process_pierce"
        staff(75to76)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1)
        pierce_front_back_track(1)
        pierce_left_right_track(0.5)
        pierce_inventory__explosive(0)
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

        pierce_turret_front__gun_brake(0) pierce_mantlet__gun_brake(0)
        pierce_turret_back__gun_brake(0)
        pierce_turret_left_right__gun_brake(0)

    ;---------------------------
        pierce_engine__engine_brake(0.75)
        pierce_engine__engine_burn(0.15)

    ;--------------------------
		pierce_shield(1)

    ;Probability crew die
		max_kill(2)
    ;--------------------------
        pierce_body__kill_charger(0.45)
		pierce_body__kill_charger2(0.45)
        pierce_body__kill_gunner(0.45)
		pierce_body__kill_gunner3(0.45)
		pierce_body__kill_gunner4(0.45)
        pierce_body__kill_driver(0.45)
        pierce_body__kill_commander(0.4)
        pierce_body__kill_gunner2(0)
    ;--------------------------
        pierce_turret__kill_charger(0.22)
		pierce_turret__kill_charger2(0.22)
        pierce_turret__kill_gunner(0.45)
		pierce_turret__kill_gunner3(0.45)
		pierce_turret__kill_gunner4(0.45)
        pierce_turret__kill_driver(0)
        pierce_turret__kill_commander(0.5)
        pierce_turret__kill_gunner2(0.45)
    )
    ;///////////////////////////////////////////////////////// 85mm
   ("damage_process_pierce"
        staff(85mm_apcr)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1)
        pierce_front_back_track(0.9)
        pierce_left_right_track(0.3)
        pierce_inventory__explosive(0)
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

        pierce_turret_front__gun_brake(0) pierce_mantlet__gun_brake(0)
        pierce_turret_back__gun_brake(0)
        pierce_turret_left_right__gun_brake(0)

    ;---------------------------
        pierce_engine__engine_brake(1)
        pierce_engine__engine_burn(0.15)

    ;--------------------------
		pierce_shield(1)

    ;Probability crew die
		max_kill(2)
    ;--------------------------
        pierce_body__kill_charger(0.25)
		pierce_body__kill_charger2(0.25)
        pierce_body__kill_gunner(0.25)
		pierce_body__kill_gunner3(0.25)
		pierce_body__kill_gunner4(0.25)
        pierce_body__kill_driver(0.25)
        pierce_body__kill_commander(0.2)
        pierce_body__kill_gunner2(0.15)
    ;--------------------------
        pierce_turret__kill_charger(0.15)
		pierce_turret__kill_charger2(0.15)
        pierce_turret__kill_gunner(0.25)
		pierce_turret__kill_gunner3(0.25)
		pierce_turret__kill_gunner4(0.25)
        pierce_turret__kill_driver(0.15)
        pierce_turret__kill_commander(0.30)
        pierce_turret__kill_gunner2(0.25)
    )
	("damage_process_pierce"
        staff(85mm)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1)
        pierce_front_back_track(0.9)
        pierce_left_right_track(0.3)
        pierce_inventory__explosive(0)
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

        pierce_turret_front__gun_brake(0) pierce_mantlet__gun_brake(0)
        pierce_turret_back__gun_brake(0)
        pierce_turret_left_right__gun_brake(0)

    ;---------------------------
        pierce_engine__engine_brake(1)
        pierce_engine__engine_burn(0.15)

    ;--------------------------
		pierce_shield(1)

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
        pierce_body__kill_gunner2(0.25)
    ;--------------------------
        pierce_turret__kill_charger(0.25)
		pierce_turret__kill_charger2(0.25)
        pierce_turret__kill_gunner(0.5)
		pierce_turret__kill_gunner3(0.5)
		pierce_turret__kill_gunner4(0.5)
        pierce_turret__kill_driver(0.25)
        pierce_turret__kill_commander(0.55)
        pierce_turret__kill_gunner2(0.5)
    )
    ;///////////////////////////////////////////////////////// 88to105
   ("damage_process_pierce"
        staff(88to105_apcr)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1)
        pierce_front_back_track(1)
        pierce_left_right_track(0.5)
        pierce_inventory__explosive(0)
    ;--------------------------
        insta_kill(1)
        pierce_body__body_brake(1.0)
        pierce_body__body_destroy(0.5)
    ;--------------------------
		  crew_shock_time(0)
		  pierce_rand_contusion(0)
    ;--------------------------
        pierce_turret__explosive(0.3)

        pierce_turret_front__turret_brake(0)
        pierce_turret_back__turret_brake(0)
        pierce_turret_left_right__turret_brake(0)

        pierce_turret_front__gun_brake(0) pierce_mantlet__gun_brake(0)
        pierce_turret_back__gun_brake(0)
        pierce_turret_left_right__gun_brake(0)

    ;---------------------------
        pierce_engine__engine_brake(1)
        pierce_engine__engine_burn(0.15)

    ;--------------------------
		pierce_shield(1)

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
        pierce_turret__kill_commander(0.3)
        pierce_turret__kill_gunner2(0.3)
    )
	("damage_process_pierce"
        staff(88to105)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1)
        pierce_front_back_track(1)
        pierce_left_right_track(0.5)
        pierce_inventory__explosive(0)
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

        pierce_turret_front__gun_brake(0) pierce_mantlet__gun_brake(0)
        pierce_turret_back__gun_brake(0)
        pierce_turret_left_right__gun_brake(0)

    ;---------------------------
        pierce_engine__engine_brake(1)
        pierce_engine__engine_burn(0.15)

    ;--------------------------
		pierce_shield(1)

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
    ;///////////////////////////////////////////////////////// 122to128
   ("damage_process_pierce"
        staff(122to128)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1)
        pierce_front_back_track(1)
        pierce_left_right_track(0.7)
        pierce_inventory__explosive(0)
    ;--------------------------
        insta_kill(0)
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

        pierce_turret_front__gun_brake(0) pierce_mantlet__gun_brake(0)
        pierce_turret_back__gun_brake(0)
        pierce_turret_left_right__gun_brake(0)

    ;---------------------------
        pierce_engine__engine_brake(1)
        pierce_engine__engine_burn(0.15)

    ;--------------------------
		pierce_shield(1)

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
    ;///////////////////////////////////////////////////////// 150to152
   ("damage_process_pierce"
        staff(150to152)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1)
        pierce_front_back_track(1)
        pierce_left_right_track(1)
        pierce_inventory__explosive(0)
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

        pierce_turret_front__gun_brake(0) pierce_mantlet__gun_brake(0)
        pierce_turret_back__gun_brake(0)
        pierce_turret_left_right__gun_brake(0)

    ;---------------------------
        pierce_engine__engine_brake(1)
        pierce_engine__engine_burn(0.15)

    ;--------------------------
		pierce_shield(1)

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
    ;///////////////////////////////////////////////////////// rocketlauncher
   ("damage_process_pierce"
        staff(rocketlauncher)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(1)
        pierce_front_back_track(1)
        pierce_left_right_track(0.4)
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
        pierce_turret_back__gun_brake(0)
        pierce_turret_left_right__gun_brake(0)

    ;---------------------------
        pierce_engine__engine_brake(1)
        pierce_engine__engine_burn(0.5)

    ;--------------------------
		pierce_shield(1)

    ;Probability crew die
		max_kill(2)
    ;--------------------------
        pierce_body__kill_charger(0.69)
		pierce_body__kill_charger2(0.69)
        pierce_body__kill_gunner(0.69)
		pierce_body__kill_gunner3(0.69)
		pierce_body__kill_gunner4(0.69)
        pierce_body__kill_driver(0.69)
        pierce_body__kill_commander(0.69)
        pierce_body__kill_gunner2(0.4)
    ;--------------------------
        pierce_turret__kill_charger(0.4)
		pierce_turret__kill_charger2(0.4)
        pierce_turret__kill_gunner(0.69)
		pierce_turret__kill_gunner3(0.69)
		pierce_turret__kill_gunner4(0.69)
        pierce_turret__kill_driver(0.4)
        pierce_turret__kill_commander(0.69)
        pierce_turret__kill_gunner2(0.69)
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
        pierce_body__body_brake(0.6);(0.8)
        pierce_body__body_destroy(0.35);(1)
    ;--------------------------
		  crew_shock_time(2)
		  pierce_rand_contusion(1)
    ;--------------------------
        pierce_turret__explosive(0.35)

        pierce_turret_front__turret_brake(1)
        pierce_turret_back__turret_brake(1)
        pierce_turret_left_right__turret_brake(1)

        pierce_turret_front__gun_brake(0.4) pierce_mantlet__gun_brake(0.5)
        pierce_turret_back__gun_brake(0)
        pierce_turret_left_right__gun_brake(0)

    ;---------------------------
        pierce_engine__engine_brake(1)
        pierce_engine__engine_burn(0.5)

    ;--------------------------
		pierce_shield(0)

    ;Probability crew die
		max_kill(1)
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
        pierce_body__body_brake(0.5);(0.8)
        pierce_body__body_destroy(0.15);(1)
    ;--------------------------
		  crew_shock_time(2)
		  pierce_rand_contusion(1)
    ;--------------------------
        pierce_turret__explosive(0.15)

        pierce_turret_front__turret_brake(0.5)
        pierce_turret_back__turret_brake(0.5)
        pierce_turret_left_right__turret_brake(0.5)

        pierce_turret_front__gun_brake(0.2) pierce_mantlet__gun_brake(0.25)
        pierce_turret_back__gun_brake(0)
        pierce_turret_left_right__gun_brake(0)

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
			{if component "trackright" or component "trackleft"
				{component break}
;			else component "body" or component "turret"
;				{call "explosion"}				
			}
		else stuff "fg 122to128" or stuff "fr 122to128"
			{if component "trackright" or component "trackleft"
				{component break}
;			else component "body" or component "turret"
;				{if rand 0.45
;					{call "explosion"}
;				}				
			}
		else stuff "fg 88to105" or stuff "fr 88to105"
			{if component "trackright" or component "trackleft"
				{component break}
;			else component "body" or component "turret"
;				{if rand 0.25
;					{call "mp_destroy"}
;				}				
			}
		else stuff "fg fx77_90" or stuff "fr fx77_90"
			{if component "trackright" or component "trackleft"
				{component break}
			}
		else stuff "fg fx61_76" or stuff "fr fx61_76"
			{if component "trackright" or component "trackleft"
				{component break}
			}
		}
	}
}; end of bullet_hit

	{on blast ; higher energy must be first
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
			blast_crew_shock_time(3)
			)
			("blast_damage_contusion"
			blast_rand_contusion(0.8)
			blast_energy(6)
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
	{if component "body" or component "turret" or component "engine" or component "trackleft" or component "trackright"
		{if name "blast" and stuff "mine antitank"
			{if flag "mine_under_track"
				{if rand 0.9
					{call "pierce_or_blast"}
				else
					("set_all_params_kill_crew"
						max_kill(5)
						charger(0.97)
						charger2(0.97)
						driver(0.97)
						gunner(0.97)
						commander(0.97)
						gunner2(0.97)
						gunner3(0.97)
						gunner4(0.97)
					)
				}
			else
				{call "pierce_or_blast"}
			}
		}
	}
	{call "destroy_or_explosion_break_armor"}
}