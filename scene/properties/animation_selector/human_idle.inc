;SDL
; "" = empty animation
{board_breath
	{if linked "cannon"
		{if linked "anm_empty"
			{if place_mask "gunner"
			}
			{if place_mask "commander"
			}
			{if place_mask "seat*"
				{random_select
					{weight 6	"cannon_crew_idle_0"}
					{weight 1	"cannon_crew_idle_1"}
					{weight 1	"cannon_crew_idle_3"}
					{weight 1	"cannon_crew_idle_4"}
					{weight 1	"cannon_crew_idle_5"}
				}
			}
			{random_select
				{weight 10	"artillery_support_idle_l"}
				{weight 1	"artillery_support_idle_l_1"}
				{weight 1	"artillery_support_idle_l_2"}
				{weight 1	"artillery_support_idle_l_3"}
			}
		}
		{if linked "anm_stereoscope"
			{if place_mask "gunner"
			}
			{if place_mask "commander"
			}
		}
		{if linked "anm_heavy_2"
			{if place_mask "gunner"
			}
			{if place_mask "commander"
			}
			{if place_mask "charger_l1"
				{random_select
					{weight 7	"cannon_big_gunner_idle"}
					{weight 1	"cannon_big_gunner_idle_1"}
					{weight 1	"cannon_big_gunner_idle_2"}
					{weight 1	"cannon_big_gunner_idle_3"}
				}
			}
			{if place_mask "charger_r1"
				{random_select
					{weight 7	"cannon_big_commander_idle"}
					{weight 1	"cannon_big_commander_idle_1"}
					{weight 1	"cannon_big_commander_idle_2"}
					{weight 1	"cannon_big_commander_idle_3"}
				}
			}
			{if place_mask "charger_l2"
				{random_select
					{weight 7	"artillery_support_idle_l"}
					{weight 1	"artillery_support_idle_l_1"}
					{weight 1	"artillery_support_idle_l_2"}
					{weight 1	"artillery_support_idle_l_3"}
				}
			}
			{if place_mask "charger_r2"
				{random_select
					{weight 7	"artillery_support_idle_r"}
					{weight 1	"artillery_support_idle_r_1"}
					{weight 1	"artillery_support_idle_r_2"}
					{weight 1	"artillery_support_idle_r_3"}
				}
			}
			{if place_mask "seat*"
				{random_select
					{weight 6	"cannon_crew_idle_0"}
					{weight 1	"cannon_crew_idle_1"}
					{weight 1	"cannon_crew_idle_3"}
					{weight 1	"cannon_crew_idle_4"}
					{weight 1	"cannon_crew_idle_5"}
				}
			}
		}
		{if linked "anm_empty_aa"
			{if place_mask "gunner"
				{random_select
					{weight 5	"zenit_pointer_right_idle"}
					{weight 1	"zenit_pointer_right_idle_1"}
					{weight 1	"zenit_pointer_right_idle_3"}
				}
			}
			{if place_mask "commander"
			}
			{if place_mask "seat*"
				{random_select
					{weight 6	"cannon_crew_idle_0"}
					{weight 1	"cannon_crew_idle_1"}
					{weight 1	"cannon_crew_idle_3"}
					{weight 1	"cannon_crew_idle_4"}
					{weight 1	"cannon_crew_idle_5"}
				}
			}
			{random_select
				{weight 10	"artillery_support_idle_l"}
				{weight 1	"artillery_support_idle_l_1"}
				{weight 1	"artillery_support_idle_l_2"}
				{weight 1	"artillery_support_idle_l_3"}
			}
		}
		{if linked "anm_52k"
			{if place_mask "gunner"
				{random_select
					{weight 5	"zenit_pointer_right_idle"}
					{weight 1	"zenit_pointer_right_idle_1"}
					{weight 1	"zenit_pointer_right_idle_3"}
				}
			}
			{if place_mask "commander"
				{random_select
					{weight 7	"cannon_big_commander_idle"}
					{weight 1	"cannon_big_commander_idle_1"}
					{weight 1	"cannon_big_commander_idle_2"}
					{weight 1	"cannon_big_commander_idle_3"}
				}
			}
			{if place_mask "seat*"
				{random_select
					{weight 6	"cannon_crew_idle_0"}
					{weight 1	"cannon_crew_idle_1"}
					{weight 1	"cannon_crew_idle_3"}
					{weight 1	"cannon_crew_idle_4"}
					{weight 1	"cannon_crew_idle_5"}
				}
			}
			{if place_mask "charger_r1"
				{random_select
					{weight 7	"cannon_big_commander_idle"}
					{weight 1	"cannon_big_commander_idle_1"}
					{weight 1	"cannon_big_commander_idle_2"}
					{weight 1	"cannon_big_commander_idle_3"}
				}
			}
			{if place_mask "charger_l1"
				{random_select
					{weight 7	"cannon_big_gunner_idle"}
					{weight 1	"cannon_big_gunner_idle_1"}
					{weight 1	"cannon_big_gunner_idle_2"}
					{weight 1	"cannon_big_gunner_idle_3"}
				}
			}
			{if place_mask "charger_r2"
				{random_select
					{weight 10	"artillery_support_idle_r"}
					{weight 1	"artillery_support_idle_r_1"}
					{weight 1	"artillery_support_idle_r_2"}
					{weight 1	"artillery_support_idle_r_3"}
				}
			}
			{if place_mask "charger_l2"
				{random_select
					{weight 10	"artillery_support_idle_l"}
					{weight 1	"artillery_support_idle_l_1"}
					{weight 1	"artillery_support_idle_l_2"}
					{weight 1	"artillery_support_idle_l_3"}
				}
			}
		}
		{if linked "m1_aa_anm"
			{if place_mask "gunner"
				{random_select
					{weight 5	"cannon_aa_gunlayer_2_idle_0"}
					{weight 1	"cannon_aa_gunlayer_2_idle_1"}
					{weight 1	"cannon_aa_gunlayer_2_idle_2"}
					{weight 1	"cannon_aa_gunlayer_2_idle_3"}
				}
			}
			{if place_mask "commander"
				{random_select
					{weight 5	"cannon_aa_gunlayer_2_idle_0"}
					{weight 1	"cannon_aa_gunlayer_2_idle_1"}
					{weight 1	"cannon_aa_gunlayer_2_idle_2"}
					{weight 1	"cannon_aa_gunlayer_2_idle_3"}
				}
			}
			{if place_mask "seat*"
				{random_select
					{weight 6	"cannon_crew_idle_0"}
					{weight 1	"cannon_crew_idle_1"}
					{weight 1	"cannon_crew_idle_3"}
					{weight 1	"cannon_crew_idle_4"}
					{weight 1	"cannon_crew_idle_5"}
				}
			}
			{if place_mask "charger_r1"
				{random_select
					{weight 5	"zenit_pointer_right_idle"}
					{weight 1	"zenit_pointer_right_idle_1"}
					{weight 1	"zenit_pointer_right_idle_3"}
				}
			}
			{if place_mask "charger_l1"
				{random_select
					{weight 7	"artillery_support_idle_l"}
					{weight 1	"artillery_support_idle_l_1"}
					{weight 1	"artillery_support_idle_l_2"}
					{weight 1	"artillery_support_idle_l_3"}
				}
			}
			{if place_mask "charger_l2"
				{random_select
					{weight 7	"artillery_support_idle_l"}
					{weight 1	"artillery_support_idle_l_1"}
					{weight 1	"artillery_support_idle_l_2"}
					{weight 1	"artillery_support_idle_l_3"}
				}
			}
			{if place_mask "charger_r2"
				{random_select
					{weight 7	"artillery_support_idle_r"}
					{weight 1	"artillery_support_idle_r_1"}
					{weight 1	"artillery_support_idle_r_2"}
					{weight 1	"artillery_support_idle_r_3"}
				}
			}
		}
		{if linked "anm_61k"
			{if place_mask "gunner"
				{random_select
					{weight 5	"cannon_aa_gunlayer_2_idle_0"}
					{weight 1	"cannon_aa_gunlayer_2_idle_1"}
					{weight 1	"cannon_aa_gunlayer_2_idle_2"}
					{weight 1	"cannon_aa_gunlayer_2_idle_3"}
				}
			}
			{if place_mask "commander"
				{random_select
					{weight 5	"cannon_aa_gunlayer_2_idle_0"}
					{weight 1	"cannon_aa_gunlayer_2_idle_1"}
					{weight 1	"cannon_aa_gunlayer_2_idle_2"}
					{weight 1	"cannon_aa_gunlayer_2_idle_3"}
				}
			}
			{if place_mask "seat*"
				{random_select
					{weight 6	"cannon_crew_idle_0"}
					{weight 1	"cannon_crew_idle_1"}
					{weight 1	"cannon_crew_idle_3"}
					{weight 1	"cannon_crew_idle_4"}
					{weight 1	"cannon_crew_idle_5"}
				}
			}
			{if place_mask "charger_r1"
				{random_select
					{weight 7	"artillery_support_idle_r"}
					{weight 1	"artillery_support_idle_r_1"}
					{weight 1	"artillery_support_idle_r_2"}
					{weight 1	"artillery_support_idle_r_3"}
				}
			}
			{if place_mask "charger_l1"
				{random_select
					{weight 7	"artillery_support_idle_l"}
					{weight 1	"artillery_support_idle_l_1"}
					{weight 1	"artillery_support_idle_l_2"}
					{weight 1	"artillery_support_idle_l_3"}
				}
			}
		}
		{if linked "anm_flak18"
			{if place_mask "gunner"
				{random_select
					{weight 5	"zenit_pointer_right_idle"}
					{weight 1	"zenit_pointer_right_idle_1"}
					{weight 1	"zenit_pointer_right_idle_3"}
				}
			}
			{if place_mask "commander"
				{random_select
					{weight 5	"zenit_pointer_right_idle"}
					{weight 1	"zenit_pointer_right_idle_1"}
					{weight 1	"zenit_pointer_right_idle_3"}
				}
			}
			{if place_mask "seat*"
				{random_select
					{weight 6	"cannon_crew_idle_0"}
					{weight 1	"cannon_crew_idle_1"}
					{weight 1	"cannon_crew_idle_3"}
					{weight 1	"cannon_crew_idle_4"}
					{weight 1	"cannon_crew_idle_5"}
				}
			}
			{if place_mask "charger_l1"
				{random_select
					{weight 7	"cannon_big_gunner_idle"}
					{weight 1	"cannon_big_gunner_idle_1"}
					{weight 1	"cannon_big_gunner_idle_2"}
					{weight 1	"cannon_big_gunner_idle_3"}
				}
			}
			{if place_mask "charger_l2"
				{random_select
					{weight 7	"artillery_support_idle_l"}
					{weight 1	"artillery_support_idle_l_1"}
					{weight 1	"artillery_support_idle_l_2"}
					{weight 1	"artillery_support_idle_l_3"}
				}
			}
			{if place_mask "charger_r2"
				{random_select
					{weight 7	"artillery_support_idle_r"}
					{weight 1	"artillery_support_idle_r_1"}
					{weight 1	"artillery_support_idle_r_2"}
					{weight 1	"artillery_support_idle_r_3"}
				}
			}
			{if place_mask "charger_r1"
				{random_select
					{weight 7	"cannon_big_commander_idle"}
					{weight 1	"cannon_big_commander_idle_1"}
					{weight 1	"cannon_big_commander_idle_2"}
					{weight 1	"cannon_big_commander_idle_3"}
				}
			}		
		}
		{if linked "anm_flak"
			{if place_mask "gunner"
				{random_select
					{weight 5	"zenit_pointer_right_idle"}
					{weight 1	"zenit_pointer_right_idle_1"}
					{weight 1	"zenit_pointer_right_idle_3"}
				}
			}
			{if place_mask "charger"
				{random_select
					{weight 5	"zenit_pointer_right_idle"}
					{weight 1	"zenit_pointer_right_idle_1"}
					{weight 1	"zenit_pointer_right_idle_3"}
				}
			}
			{if place_mask "charger2"
				{random_select
					{weight 5	"zenit_pointer_right_idle"}
					{weight 1	"zenit_pointer_right_idle_1"}
					{weight 1	"zenit_pointer_right_idle_3"}
				}
			}		
		}
		{if linked "anm_aa_heavy"
			{if place_mask "gunner"
				{random_select
					{weight 5	"zenit_pointer_right_idle"}
					{weight 1	"zenit_pointer_right_idle_1"}
					{weight 1	"zenit_pointer_right_idle_3"}
				}
			}
			{if place_mask "commander"
				{random_select
					{weight 5	"zenit_pointer_right_idle"}
					{weight 1	"zenit_pointer_right_idle_1"}
					{weight 1	"zenit_pointer_right_idle_3"}
				}
			}
			{if place_mask "seat*"
				{random_select
					{weight 6	"cannon_crew_idle_0"}
					{weight 1	"cannon_crew_idle_1"}
					{weight 1	"cannon_crew_idle_3"}
					{weight 1	"cannon_crew_idle_4"}
					{weight 1	"cannon_crew_idle_5"}
				}
			}
			{if place_mask "charger_r1"
				{random_select
					{weight 7	"cannon_big_commander_idle"}
					{weight 1	"cannon_big_commander_idle_1"}
					{weight 1	"cannon_big_commander_idle_2"}
					{weight 1	"cannon_big_commander_idle_3"}
				}
			}
			{if place_mask "charger_l1"
				{random_select
					{weight 7	"cannon_big_gunner_idle"}
					{weight 1	"cannon_big_gunner_idle_1"}
					{weight 1	"cannon_big_gunner_idle_2"}
					{weight 1	"cannon_big_gunner_idle_3"}
				}
			}
			{if place_mask "charger_l2"
				{random_select
					{weight 7	"artillery_support_idle_l"}
					{weight 1	"artillery_support_idle_l_1"}
					{weight 1	"artillery_support_idle_l_2"}
					{weight 1	"artillery_support_idle_l_3"}
				}
			}
			{if place_mask "charger_r2"
				{random_select
					{weight 7	"artillery_support_idle_r"}
					{weight 1	"artillery_support_idle_r_1"}
					{weight 1	"artillery_support_idle_r_2"}
					{weight 1	"artillery_support_idle_r_3"}
				}
			}
		}
		{if linked "anm_searchlight"
			{if place_mask "gunner"
				{random_select
					{weight 5	"passenger_car_small_idle"}
					{weight 1	"passenger_car_small_idle_1"}
					{weight 1	"passenger_car_small_idle_2"}
					{weight 1	"passenger_car_small_idle_3"}
				}
			}
		}
		{if linked "anm_mortar_empty"
			{if place_mask "gunner"

			}
			{if place_mask "commander"
			}
		}
		{if linked "anm_mortar"
			{if place_mask "gunner"
				{random_select
					{weight 6	"cannon_small_commander_idle"}
					{weight 1	"cannon_small_commander_idle_1"}
					{weight 1	"cannon_small_commander_idle_2"}
					{weight 1	"cannon_small_commander_idle_3"}
				}
			}
			{if place_mask "commander"
				{random_select
					{weight 6	"cannon_small_charger_idle"}
					{weight 1	"cannon_small_charger_idle_1"}
					{weight 1	"cannon_small_charger_idle_2"}
					{weight 1	"cannon_small_charger_idle_3"}
				}
			}
		}
		{if linked "anm_aa"
			{if place_mask "gunner"
				{random_select
					{weight 5	"zenit_pointer_right_idle"}
					{weight 1	"zenit_pointer_right_idle_1"}
					{weight 1	"zenit_pointer_right_idle_3"}
				}
			}
			{if place_mask "commander"
				{random_select
					{weight 7	"cannon_small_commander_idle"}
					{weight 1	"cannon_small_commander_idle_1"}
					{weight 1	"cannon_small_commander_idle_2"}
					{weight 1	"cannon_small_commander_idle_3"}
				}
			}
			{if place_mask "seat*"
				{random_select
					{weight 6	"cannon_crew_idle_0"}
					{weight 1	"cannon_crew_idle_1"}
					{weight 1	"cannon_crew_idle_3"}
					{weight 1	"cannon_crew_idle_4"}
					{weight 1	"cannon_crew_idle_5"}
				}
			}
			{random_select
				{weight 7	"artillery_support_idle_l"}
				{weight 1	"artillery_support_idle_l_1"}
				{weight 1	"artillery_support_idle_l_2"}
				{weight 1	"artillery_support_idle_l_3"}
			}
		}
		{if linked "anm_empty_commander_small"
			{if place_mask "gunner"
			}
			{if place_mask "commander"
				{random_select
					{weight 7	"cannon_small_commander_idle"}
					{weight 1	"cannon_small_commander_idle_1"}
					{weight 1	"cannon_small_commander_idle_2"}
					{weight 1	"cannon_small_commander_idle_3"}
				}
			}
			{random_select
				{weight 7	"artillery_support_idle_l"}
				{weight 1	"artillery_support_idle_l_1"}
				{weight 1	"artillery_support_idle_l_2"}
				{weight 1	"artillery_support_idle_l_3"}
			}
			{if place_mask "seat1"
			}
			{if place_mask "seat2"
			}
			{if place_mask "seat3"
				{random_select
					{weight 6	"cannon_crew_idle_0"}
					{weight 1	"cannon_crew_idle_1"}
					{weight 1	"cannon_crew_idle_3"}
					{weight 1	"cannon_crew_idle_4"}
					{weight 1	"cannon_crew_idle_5"}
				}
			}
			{if place_mask "seat4"
				{random_select
					{weight 6	"cannon_crew_idle_0"}
					{weight 1	"cannon_crew_idle_1"}
					{weight 1	"cannon_crew_idle_3"}
					{weight 1	"cannon_crew_idle_4"}
					{weight 1	"cannon_crew_idle_5"}
				}
			}
		}
		{if linked "anm_empty_commander_big"
			{if place_mask "gunner"
			}
			{if place_mask "commander"
				{random_select
					{weight 7	"cannon_big_commander_idle"}
					{weight 1	"cannon_big_commander_idle_1"}
					{weight 1	"cannon_big_commander_idle_2"}
					{weight 1	"cannon_big_commander_idle_3"}
				}
			}
			{if place_mask "seat*"
				{random_select
					{weight 6	"cannon_crew_idle_0"}
					{weight 1	"cannon_crew_idle_1"}
					{weight 1	"cannon_crew_idle_3"}
					{weight 1	"cannon_crew_idle_4"}
					{weight 1	"cannon_crew_idle_5"}
				}
			}
			{random_select
				{weight 7	"artillery_support_idle_l"}
				{weight 1	"artillery_support_idle_l_1"}
				{weight 1	"artillery_support_idle_l_2"}
				{weight 1	"artillery_support_idle_l_3"}
			}
		}
		{if linked "anm_heavy"
			{if place_mask "gunner"
				{random_select
					{weight 7	"cannon_big_gunner_idle"}
					{weight 1	"cannon_big_gunner_idle_1"}
					{weight 1	"cannon_big_gunner_idle_2"}
					{weight 1	"cannon_big_gunner_idle_3"}
				}
			}
			{if place_mask "commander"
				{random_select
					{weight 7	"cannon_big_commander_idle"}
					{weight 1	"cannon_big_commander_idle_1"}
					{weight 1	"cannon_big_commander_idle_2"}
					{weight 1	"cannon_big_commander_idle_3"}
				}
			}
			{if place_mask "seat*"
				{random_select
					{weight 6	"cannon_crew_idle_0"}
					{weight 1	"cannon_crew_idle_1"}
					{weight 1	"cannon_crew_idle_3"}
					{weight 1	"cannon_crew_idle_4"}
					{weight 1	"cannon_crew_idle_5"}
				}
			}
			{if place_mask "charger_l*"
				{random_select
					{weight 7	"artillery_support_idle_l"}
					{weight 1	"artillery_support_idle_l_1"}
					{weight 1	"artillery_support_idle_l_2"}
					{weight 1	"artillery_support_idle_l_3"}
				}
			}
			{if place_mask "charger_r*"
				{random_select
					{weight 7	"artillery_support_idle_r"}
					{weight 1	"artillery_support_idle_r_1"}
					{weight 1	"artillery_support_idle_r_2"}
					{weight 1	"artillery_support_idle_r_3"}
				}
			}		
		}
		{if linked "anm_mgun_stan"
			{if place_mask "gunner"
				{random_select
					{weight 6	"stan_mgun_idle_0"}
					{weight 1	"stan_mgun_idle_1"}
					{weight 1	"stan_mgun_idle_2"}
					{weight 1	"stan_mgun_idle_3"}
					{weight 1	"stan_mgun_idle_4"}
				}
			}
			{random_select
				{weight 7	"artillery_support_idle_l"}
				{weight 1	"artillery_support_idle_l_1"}
				{weight 1	"artillery_support_idle_l_2"}
				{weight 1	"artillery_support_idle_l_3"}
			}		
		}
		{if linked "anm_mgun_lie"
		}
		{if place_mask "gunner"
			{random_select
				{weight 7	"cannon_small_commander_idle"}
				{weight 1	"cannon_small_commander_idle_1"}
				{weight 1	"cannon_small_commander_idle_2"}
				{weight 1	"cannon_small_commander_idle_3"}
			}
		}
		{if place_mask "commander"
			{random_select
				{weight 7	"cannon_small_charger_idle"}
				{weight 1	"cannon_small_charger_idle_1"}
				{weight 1	"cannon_small_charger_idle_2"}
				{weight 1	"cannon_small_charger_idle_3"}
			}
		}
		{if place_mask "seat*"
			{random_select
				{weight 6	"cannon_crew_idle_0"}
				{weight 1	"cannon_crew_idle_1"}
				{weight 1	"cannon_crew_idle_3"}
				{weight 1	"cannon_crew_idle_4"}
				{weight 1	"cannon_crew_idle_5"}
			}
		}
		{if place_mask "charger_l*"
			{random_select
				{weight 7	"artillery_support_idle_l"}
				{weight 1	"artillery_support_idle_l_1"}
				{weight 1	"artillery_support_idle_l_2"}
				{weight 1	"artillery_support_idle_l_3"}
			}
		}
		{if place_mask "charger_r*"
			{random_select
				{weight 7	"artillery_support_idle_r"}
				{weight 1	"artillery_support_idle_r_1"}
				{weight 1	"artillery_support_idle_r_2"}
				{weight 1	"artillery_support_idle_r_3"}
			}
		}
		{random_select
			{weight 7	"artillery_support_idle_l"}
			{weight 1	"artillery_support_idle_l_1"}
			{weight 1	"artillery_support_idle_l_2"}
			{weight 1	"artillery_support_idle_l_3"}
		}
	}
	{if linked "car"
		{if linked "marine"}
		{if linked "anm_multigun"
			{if place_mask "gunner1"
				{random_select
					{weight 1	"vehicle_mgun_1hand_idle_1"}
					{weight 1	"vehicle_mgun_1hand_idle_2"}
					{weight 1	"vehicle_mgun_1hand_idle_3"}
					{weight 1	"vehicle_mgun_1hand_idle_4"}
				}
			}
			{if place_mask "gunner2"
				{random_select
					{weight 1	"vehicle_mgun_1hand_idle_1"}
					{weight 1	"vehicle_mgun_1hand_idle_2"}
					{weight 1	"vehicle_mgun_1hand_idle_3"}
					{weight 1	"vehicle_mgun_1hand_idle_4"}
				}
			}
			{if place_mask "gunner3"
				{random_select
					{weight 1	"vehicle_mgun_1hand_idle_1"}
					{weight 1	"vehicle_mgun_1hand_idle_2"}
					{weight 1	"vehicle_mgun_1hand_idle_3"}
					{weight 1	"vehicle_mgun_1hand_idle_4"}
				}
			}
			{if place_mask "gunner4"
				{random_select
					{weight 1	"vehicle_mgun_1hand_idle_1"}
					{weight 1	"vehicle_mgun_1hand_idle_2"}
					{weight 1	"vehicle_mgun_1hand_idle_3"}
					{weight 1	"vehicle_mgun_1hand_idle_4"}
				}
			}
			{if place_mask "driver"
				{random_select
					{weight 5	"driver_car_small_idle"}
					{weight 1	"driver_car_small_idle_1"}
					{weight 1	"driver_car_small_idle_2"}
				}
			}
			{if place_mask "commander"
				{random_select
					{weight 5	"passenger_car_small_idle"}
					{weight 1	"passenger_car_small_idle_1"}
					{weight 1	"passenger_car_small_idle_2"}
					{weight 1	"passenger_car_small_idle_3"}
				}
			}
			{ if place_mask "seat_m*"
				{random_select 
					{weight 5	"idle_onboard_m0"}
					{weight 1	"idle_onboard_m2"}
					{weight 1	"idle_onboard_m3"}
					{weight 1	"idle_onboard_m4"}
				}
			}
			{random_select
				{weight 5	"passenger_car_small_idle"}
				{weight 1	"passenger_car_small_idle_1"}
				{weight 1	"passenger_car_small_idle_2"}
				{weight 1	"passenger_car_small_idle_3"}
			}

		}
		{if linked "one_hand_mgun_anm"
			{if place_mask "gunner"
				{random_select
					{weight 1	"vehicle_mgun_1hand_idle_1"}
					{weight 1	"vehicle_mgun_1hand_idle_2"}
					{weight 1	"vehicle_mgun_1hand_idle_3"}
					{weight 1	"vehicle_mgun_1hand_idle_4"}
				}
			}
			{if place_mask "driver"
				{random_select
					{weight 5	"driver_car_small_idle"}
					{weight 1	"driver_car_small_idle_1"}
					{weight 1	"driver_car_small_idle_2"}
				}
			}
			{if place_mask "commander"
				{random_select
					{weight 5	"passenger_car_small_idle"}
					{weight 1	"passenger_car_small_idle_1"}
					{weight 1	"passenger_car_small_idle_2"}
					{weight 1	"passenger_car_small_idle_3"}
				}
			}
		}
		{if linked "anm_bazooka"
			{if place_mask "gunner"
				{random_select
					{weight 5	"passenger_car_small_idle"}
					{weight 1	"passenger_car_small_idle_1"}
					{weight 1	"passenger_car_small_idle_2"}
					{weight 1	"passenger_car_small_idle_3"}
				}
			}
			{if place_mask "driver"
				{random_select
					{weight 5	"driver_car_small_idle"}
					{weight 1	"driver_car_small_idle_1"}
					{weight 1	"driver_car_small_idle_2"}
				}
			}
			{if place_mask "commander"
				{random_select
					{weight 5	"passenger_car_small_idle"}
					{weight 1	"passenger_car_small_idle_1"}
					{weight 1	"passenger_car_small_idle_2"}
					{weight 1	"passenger_car_small_idle_3"}
				}
			}
		}
		{if linked "29k_anm"
			{if place_mask "charger"
				{random_select
					{weight 5	"cannon_small_commander_idle"}
					{weight 1	"cannon_small_commander_idle_1"}
					{weight 1	"cannon_small_commander_idle_2"}
					{weight 1	"cannon_small_commander_idle_3"}
				}
			}
			{if place_mask "gunner"
				{random_select
					{weight 5	"zenit_pointer_right_idle"}
					{weight 1	"zenit_pointer_right_idle_1"}
					{weight 1	"zenit_pointer_right_idle_2"}
					{weight 1	"zenit_pointer_right_idle_3"}
				}
			}
			{random_select
				{weight 5	"passenger_car_small_idle"}
				{weight 1	"passenger_car_small_idle_1"}
				{weight 1	"passenger_car_small_idle_2"}
				{weight 1	"passenger_car_small_idle_3"}
			}
		}
		{if linked "aaa_anm"
			{if place_mask "charger"
				{random_select
					{weight 5	"zenit_pointer_right_idle"}
					{weight 1	"zenit_pointer_right_idle_1"}
					{weight 1	"zenit_pointer_right_idle_2"}
					{weight 1	"zenit_pointer_right_idle_3"}
				}
			}
			{if place_mask "gunner"
				{random_select
					{weight 5	"zenit_pointer_right_idle"}
					{weight 1	"zenit_pointer_right_idle_1"}
					{weight 1	"zenit_pointer_right_idle_2"}
					{weight 1	"zenit_pointer_right_idle_3"}
				}
			}
			{random_select
				{weight 5	"passenger_car_small_idle"}
				{weight 1	"passenger_car_small_idle_1"}
				{weight 1	"passenger_car_small_idle_2"}
				{weight 1	"passenger_car_small_idle_3"}
			}
		}
		{if linked "truck"
			{if place_mask "driver"
				{random_select
					{weight 5	"driver_car_small_idle"}
					{weight 1	"driver_car_small_idle_1"}
					{weight 1	"driver_car_small_idle_2"}
				}
			}
			{if place_mask "commander"
				{random_select
					{weight 5	"passenger_car_small_idle"}
					{weight 1	"passenger_car_small_idle_1"}
					{weight 1	"passenger_car_small_idle_2"}
					{weight 1	"passenger_car_small_idle_3"}
				}
			}
			{random_select
				{weight 5	"passenger_car_small_idle"}
				{weight 1	"passenger_car_small_idle_1"}
				{weight 1	"passenger_car_small_idle_2"}
				{weight 1	"passenger_car_small_idle_3"}
			}
		}
		{if linked "turret"
			{if place_mask "driver"
				{random_select
					{weight 5	"driver_car_small_idle"}
					{weight 1	"driver_car_small_idle_1"}
					{weight 1	"driver_car_small_idle_2"}
				}
			}
			{if place_mask "commander"
				{random_select
					{weight 5	"passenger_car_small_idle"}
					{weight 1	"passenger_car_small_idle_1"}
					{weight 1	"passenger_car_small_idle_2"}
					{weight 1	"passenger_car_small_idle_3"}
				}
			}
			{if place_mask "gunner1"
				{random_select
					{weight 5	"cannon_small_charger_idle"}
					{weight 1	"cannon_small_charger_idle_1"}
					{weight 1	"cannon_small_charger_idle_2"}
					{weight 1	"cannon_small_charger_idle_3"}
				}
			}
			{if place_mask "charger"
				{random_select
					{weight 5	"cannon_small_commander_idle"}
					{weight 1	"cannon_small_commander_idle_1"}
					{weight 1	"cannon_small_commander_idle_2"}
					{weight 1	"cannon_small_commander_idle_3"}
				}
			}
			{if place_mask "gunner"
				{random_select
					{weight 5	"passenger_car_small_idle"}
					{weight 1	"passenger_car_small_idle_1"}
					{weight 1	"passenger_car_small_idle_2"}
					{weight 1	"passenger_car_small_idle_3"}
				}
			}
			{random_select
				{weight 5	"passenger_car_small_idle"}
				{weight 1	"passenger_car_small_idle_1"}
				{weight 1	"passenger_car_small_idle_2"}
				{weight 1	"passenger_car_small_idle_3"}
			}
		}
		{if place_mask "driver"
			{random_select
				{weight 5	"driver_car_small_idle"}
				{weight 1	"driver_car_small_idle_1"}
				{weight 1	"driver_car_small_idle_2"}
			}
		}
		{if place_mask "commander"
			{random_select
				{weight 5	"passenger_car_small_idle"}
				{weight 1	"passenger_car_small_idle_1"}
				{weight 1	"passenger_car_small_idle_2"}
				{weight 1	"passenger_car_small_idle_3"}
			}
		}
		{if place_mask "gunner"
			{random_select
				{weight 1	"vehicle_mgun_2hand_idle_1"}
				{weight 1	"vehicle_mgun_2hand_idle_2"}
				{weight 1	"vehicle_mgun_2hand_idle_4"}
			}
		}	
		{random_select
			{weight 5	"passenger_car_small_idle"}
			{weight 1	"passenger_car_small_idle_1"}
			{weight 1	"passenger_car_small_idle_2"}
			{weight 1	"passenger_car_small_idle_3"}
		}	
	}
	{if linked "anm_moto"
		{if linked "moto_2h"
			{if place_mask "gunner"
				{random_select
					{weight 5	"moto_gunner_stand_idle_0"}
					{weight 1	"moto_gunner_stand_idle_1"}
					{weight 1	"moto_gunner_stand_idle_2"}
					{weight 1	"moto_gunner_stand_idle_3"}
					{weight 1	"moto_gunner_stand_idle_4"}
					{weight 1	"moto_gunner_stand_idle_5"}
				}
			}
		}
			{if place_mask "driver"
				{random_select
					{weight 5	"moto_driver_stand_idle_0"}
					{weight 1	"moto_driver_stand_idle_1"}
					{weight 1	"moto_driver_stand_idle_2"}
					{weight 1	"moto_driver_stand_idle_3"}
					{weight 1	"moto_driver_stand_idle_4"}
				}
			}
			{if place_mask "passenger"
				{random_select
					{weight 5	"moto_passanger_stand_idle_0"}
					{weight 1	"moto_passanger_stand_idle_1"}
					{weight 1	"moto_passanger_stand_idle_2"}
					{weight 1	"moto_passanger_stand_idle_3"}
					{weight 1	"moto_passanger_stand_idle_4"}
				}
			}
			{if place_mask "gunner"
				{random_select
					{weight 5	"moto_gunner_1_stand_idle_0"}
					{weight 1	"moto_gunner_1_stand_idle_1"}
					{weight 1	"moto_gunner_1_stand_idle_2"}
					{weight 1	"moto_gunner_1_stand_idle_3"}
					{weight 1	"moto_gunner_1_stand_idle_4"}
					{weight 1	"moto_gunner_1_stand_idle_5"}
				}
			}
		}
	{if linked "armored_car"
		{if linked "anm_m8grayhound"
			{if place_mask "gunner"
				{random_select
					{weight 25	"cannon_small_commander_idle"}
					{weight 1	"cannon_small_commander_idle_1"}
					{weight 1	"cannon_small_commander_idle_2"}
					{weight 1	"cannon_small_commander_idle_3"}
				}
			}
			{if place_mask "gunner1"
				{random_select
					{weight 1	"vehicle_mgun_2hand_idle_1"}
					{weight 1	"vehicle_mgun_2hand_idle_2"}
					{weight 1	"vehicle_mgun_2hand_idle_4"}
				}
			}
		}
		{if linked "anm_ac_2hand_mgun"
			{if place_mask "gunner"
				{random_select
					{weight 1	"vehicle_mgun_2hand_idle_1"}
					{weight 1	"vehicle_mgun_2hand_idle_2"}
					{weight 1	"vehicle_mgun_2hand_idle_4"}
				}
			}
			{if place_mask "driver"
				{random_select
					{weight 5	"driver_car_small_idle"}
					{weight 1	"driver_car_small_idle_1"}
					{weight 1	"driver_car_small_idle_2"}
				}
			}
			{random_select
				{weight 5	"passenger_car_small_idle"}
				{weight 1	"passenger_car_small_idle_1"}
				{weight 1	"passenger_car_small_idle_2"}
				{weight 1	"passenger_car_small_idle_3"}
			}	
		}
		{if linked "anm_251_17"
			{if place_mask "gunner"
				{random_select
					{weight 5	"zenit_pointer_right_idle"}
					{weight 1	"zenit_pointer_right_idle_1"}
					{weight 1	"zenit_pointer_right_idle_2"}
					{weight 1	"zenit_pointer_right_idle_3"}
				}
			}
			{if place_mask "driver"
				{random_select
					{weight 5	"driver_car_small_idle"}
					{weight 1	"driver_car_small_idle_1"}
					{weight 1	"driver_car_small_idle_2"}
				}
			}
			{if place_mask "charger"
				{random_select
					{weight 5	"cannon_big_commander_idle"}
					{weight 1	"cannon_big_commander_idle_1"}
					{weight 1	"cannon_big_commander_idle_2"}
					{weight 1	"cannon_big_commander_idle_3"}
				}
			}
			{random_select
				{weight 5	"passenger_car_small_idle"}
				{weight 1	"passenger_car_small_idle_1"}
				{weight 1	"passenger_car_small_idle_2"}
				{weight 1	"passenger_car_small_idle_3"}
			}	
		}
		{if linked "anm_251_9"
			{if place_mask "gunner"
				{random_select
					{weight 5	"zenit_pointer_right_idle"}
					{weight 1	"zenit_pointer_right_idle_1"}
					{weight 1	"zenit_pointer_right_idle_2"}
					{weight 1	"zenit_pointer_right_idle_3"}
				}
			}
			{if place_mask "driver"
				{random_select
					{weight 5	"driver_car_small_idle"}
					{weight 1	"driver_car_small_idle_1"}
					{weight 1	"driver_car_small_idle_2"}
				}
			}
			{if place_mask "gunner1"
				{random_select
					{weight 1	"vehicle_mgun_1hand_idle_1"}
					{weight 1	"vehicle_mgun_1hand_idle_2"}
					{weight 1	"vehicle_mgun_1hand_idle_3"}
					{weight 1	"vehicle_mgun_1hand_idle_4"}
				}
			}
			{random_select
				{weight 5	"passenger_car_small_idle"}
				{weight 1	"passenger_car_small_idle_1"}
				{weight 1	"passenger_car_small_idle_2"}
				{weight 1	"passenger_car_small_idle_3"}
			}	
		}
		{if linked "anm_ac_zenit"
			{if place_mask "gunner"
				{random_select
					{weight 5	"driver_car_small_idle"}
					{weight 1	"driver_car_small_idle_1"}
					{weight 1	"driver_car_small_idle_2"}
				}
			}
			{if place_mask "gunner2"
				{random_select
					{weight 5	"passenger_car_small_idle"}
					{weight 1	"passenger_car_small_idle_1"}
					{weight 1	"passenger_car_small_idle_2"}
					{weight 1	"passenger_car_small_idle_3"}
				}
			}
			{if place_mask "charger"
				{random_select
					{weight 5	"passenger_car_small_idle"}
					{weight 1	"passenger_car_small_idle_1"}
					{weight 1	"passenger_car_small_idle_2"}
					{weight 1	"passenger_car_small_idle_3"}
				}
			}
			{if place_mask "driver"
				{random_select
					{weight 5	"driver_car_small_idle"}
					{weight 1	"driver_car_small_idle_1"}
					{weight 1	"driver_car_small_idle_2"}
				}
			}
			{random_select
				{weight 5	"passenger_car_small_idle"}
				{weight 1	"passenger_car_small_idle_1"}
				{weight 1	"passenger_car_small_idle_2"}
				{weight 1	"passenger_car_small_idle_3"}
			}	
		}
		{if linked "anm_ac_2hand_mgun_com"
			{if place_mask "gunner"
				{random_select
					{weight 1	"vehicle_mgun_2hand_idle_1"}
					{weight 1	"vehicle_mgun_2hand_idle_2"}
					{weight 1	"vehicle_mgun_2hand_idle_4"}
				}
			}
			{if place_mask "commander"
				{random_select
					{weight 1	"vehicle_mgun_2hand_idle_1"}
					{weight 1	"vehicle_mgun_2hand_idle_2"}
					{weight 1	"vehicle_mgun_2hand_idle_4"}
				}
			}
			{if place_mask "driver"
				{random_select
					{weight 5	"driver_car_small_idle"}
					{weight 1	"driver_car_small_idle_1"}
					{weight 1	"driver_car_small_idle_2"}
				}
			}
			{random_select
				{weight 5	"passenger_car_small_idle"}
				{weight 1	"passenger_car_small_idle_1"}
				{weight 1	"passenger_car_small_idle_2"}
				{weight 1	"passenger_car_small_idle_3"}
			}	
		}
		{if linked "m2"
			{if place_mask "gunner"
				{random_select
					{weight 1	"vehicle_mgun_2hand_idle_1"}
					{weight 1	"vehicle_mgun_2hand_idle_2"}
					{weight 1	"vehicle_mgun_2hand_idle_4"}
				}
			}
			{if place_mask "gunner1"
				{random_select
					{weight 1	"vehicle_mgun_1hand_idle_1"}
					{weight 1	"vehicle_mgun_1hand_idle_2"}
					{weight 1	"vehicle_mgun_1hand_idle_3"}
					{weight 1	"vehicle_mgun_1hand_idle_4"}
				}
			}
			{if place_mask "gunner4"
				{random_select
					{weight 1	"vehicle_mgun_1hand_idle_1"}
					{weight 1	"vehicle_mgun_1hand_idle_2"}
					{weight 1	"vehicle_mgun_1hand_idle_3"}
					{weight 1	"vehicle_mgun_1hand_idle_4"}
				}
			}
			{if place_mask "driver"
				{random_select
					{weight 5	"driver_car_small_idle"}
					{weight 1	"driver_car_small_idle_1"}
					{weight 1	"driver_car_small_idle_2"}
				}
			}
			{random_select
				{weight 5	"passenger_car_small_idle"}
				{weight 1	"passenger_car_small_idle_1"}
				{weight 1	"passenger_car_small_idle_2"}
				{weight 1	"passenger_car_small_idle_3"}
			}	
		}
		{if linked "m3"
			{if place_mask "gunner"
				{random_select
					{weight 1	"vehicle_mgun_1hand_idle_1"}
					{weight 1	"vehicle_mgun_1hand_idle_2"}
					{weight 1	"vehicle_mgun_1hand_idle_4"}
				}
			}
			{if place_mask "gunner1"
				{random_select
					{weight 1	"vehicle_mgun_2hand_idle_1"}
					{weight 1	"vehicle_mgun_2hand_idle_2"}
					{weight 1	"vehicle_mgun_2hand_idle_4"}
				}
			}
			{if place_mask "gunner2"
				{random_select
					{weight 1	"vehicle_mgun_1hand_idle_1"}
					{weight 1	"vehicle_mgun_1hand_idle_2"}
					{weight 1	"vehicle_mgun_1hand_idle_3"}
					{weight 1	"vehicle_mgun_1hand_idle_4"}
				}
			}
			{if place_mask "gunner3"
				{random_select
					{weight 1	"vehicle_mgun_1hand_idle_1"}
					{weight 1	"vehicle_mgun_1hand_idle_2"}
					{weight 1	"vehicle_mgun_1hand_idle_3"}
					{weight 1	"vehicle_mgun_1hand_idle_4"}
				}
			}
			{if place_mask "driver"
				{random_select
					{weight 5	"driver_car_small_idle"}
					{weight 1	"driver_car_small_idle_1"}
					{weight 1	"driver_car_small_idle_2"}
				}
			}
			{random_select
				{weight 5	"passenger_car_small_idle"}
				{weight 1	"passenger_car_small_idle_1"}
				{weight 1	"passenger_car_small_idle_2"}
				{weight 1	"passenger_car_small_idle_3"}
			}	
		}
		{if linked "anm_m4"
			{if place_mask "gunner"
				{random_select
					{weight 1	"vehicle_mgun_2hand_idle_1"}
					{weight 1	"vehicle_mgun_2hand_idle_2"}
					{weight 1	"vehicle_mgun_2hand_idle_4"}
				}
			}
			{if place_mask "gunner1"
				{random_select
					{weight 1	"vehicle_mgun_1hand_idle_1"}
					{weight 1	"vehicle_mgun_1hand_idle_2"}
					{weight 1	"vehicle_mgun_1hand_idle_3"}
					{weight 1	"vehicle_mgun_1hand_idle_4"}
				}
			}
			{if place_mask "gunner4"
				{random_select
					{weight 1	"vehicle_mgun_1hand_idle_1"}
					{weight 1	"vehicle_mgun_1hand_idle_2"}
					{weight 1	"vehicle_mgun_1hand_idle_3"}
					{weight 1	"vehicle_mgun_1hand_idle_4"}
				}
			}
			{if place_mask "driver"
				{random_select
					{weight 5	"driver_car_small_idle"}
					{weight 1	"driver_car_small_idle_1"}
					{weight 1	"driver_car_small_idle_2"}
				}
			}
			{random_select
				{weight 5	"passenger_car_small_idle"}
				{weight 1	"passenger_car_small_idle_1"}
				{weight 1	"passenger_car_small_idle_2"}
				{weight 1	"passenger_car_small_idle_3"}
			}	
		}
		{if linked "m2_m"
			{if place_mask "gunner"
				{random_select
					{weight 1	"vehicle_mgun_2hand_idle_1"}
					{weight 1	"vehicle_mgun_2hand_idle_2"}
					{weight 1	"vehicle_mgun_2hand_idle_4"}
				}
			}
			{if place_mask "gunner1"
				{random_select
					{weight 1	"artillery_support_idle_l"}
					{weight 1	"artillery_support_idle_l_1"}
					{weight 1	"artillery_support_idle_l_2"}
					{weight 1	"artillery_support_idle_l_3"}
				}
			}
			{if place_mask "gunner2"
				{random_select
					{weight 1	"artillery_support_idle_l"}
					{weight 1	"artillery_support_idle_l_1"}
					{weight 1	"artillery_support_idle_l_2"}
					{weight 1	"artillery_support_idle_l_3"}
				}
			}
			{if place_mask "driver"
				{random_select
					{weight 5	"driver_car_small_idle"}
					{weight 1	"driver_car_small_idle_1"}
					{weight 1	"driver_car_small_idle_2"}
				}
			}
			{random_select
				{weight 5	"passenger_car_small_idle"}
				{weight 1	"passenger_car_small_idle_1"}
				{weight 1	"passenger_car_small_idle_2"}
				{weight 1	"passenger_car_small_idle_3"}
			}	
		}
		{if linked "anm_ac_mortair"
			{if place_mask "gunner1"
				{random_select
					{weight 1	"vehicle_mgun_1hand_idle_1"}
					{weight 1	"vehicle_mgun_1hand_idle_2"}
					{weight 1	"vehicle_mgun_1hand_idle_3"}
					{weight 1	"vehicle_mgun_1hand_idle_4"}
				}
			}
			{if place_mask "gunner"
				{random_select
					{weight 1	"artillery_support_idle_l"}
					{weight 1	"artillery_support_idle_l_1"}
					{weight 1	"artillery_support_idle_l_2"}
					{weight 1	"artillery_support_idle_l_3"}
				}
			}
			{if place_mask "gunner2"
				{random_select
					{weight 1	"artillery_support_idle_l"}
					{weight 1	"artillery_support_idle_l_1"}
					{weight 1	"artillery_support_idle_l_2"}
					{weight 1	"artillery_support_idle_l_3"}
				}
			}
			{if place_mask "driver"
				{random_select
					{weight 5	"driver_car_small_idle"}
					{weight 1	"driver_car_small_idle_1"}
					{weight 1	"driver_car_small_idle_2"}
				}
			}
			{random_select
				{weight 5	"passenger_car_small_idle"}
				{weight 1	"passenger_car_small_idle_1"}
				{weight 1	"passenger_car_small_idle_2"}
				{weight 1	"passenger_car_small_idle_3"}
			}	
		}
		{if linked "anm_cannon"
			{if place_mask "gunner"
				{random_select
					{weight 5	"zenit_pointer_right_idle"}
					{weight 1	"zenit_pointer_right_idle_1"}
					{weight 1	"zenit_pointer_right_idle_2"}
					{weight 1	"zenit_pointer_right_idle_3"}
				}
			}
			{if place_mask "commander"
				{random_select
					{weight 5	"zenit_pointer_right_idle"}
					{weight 1	"zenit_pointer_right_idle_1"}
					{weight 1	"zenit_pointer_right_idle_2"}
					{weight 1	"zenit_pointer_right_idle_3"}
				}
			}
		}
		{if linked "anm_cannon_big"
			{if place_mask "driver"
				{random_select
					{weight 5	"driver_car_small_idle"}
					{weight 1	"driver_car_small_idle_1"}
					{weight 1	"driver_car_small_idle_2"}
				}
			}
			{if place_mask "gunner"
				{random_select
					{weight 5	"cannon_small_commander_idle"}
					{weight 1	"cannon_small_commander_idle_1"}
					{weight 1	"cannon_small_commander_idle_2"}
					{weight 1	"cannon_small_commander_idle_3"}
				}
			}
			{if place_mask "commander"
				{random_select
					{weight 5	"passenger_car_small_idle"}
					{weight 1	"passenger_car_small_idle_1"}
					{weight 1	"passenger_car_small_idle_2"}
					{weight 1	"passenger_car_small_idle_3"}
				}
			}
			{if place_mask "charger"
				{random_select
					{weight 5	"cannon_small_charger_idle"}
					{weight 1	"cannon_small_charger_idle_1"}
					{weight 1	"cannon_small_charger_idle_2"}
					{weight 1	"cannon_small_charger_idle_3"}
				}
			}
			{if place_mask "gunner1"
				{random_select
					{weight 1	"vehicle_mgun_1hand_idle_1"}
					{weight 1	"vehicle_mgun_1hand_idle_2"}
					{weight 1	"vehicle_mgun_1hand_idle_3"}
					{weight 1	"vehicle_mgun_1hand_idle_4"}
				}
			}
		}

		{if place_mask "driver"
			{random_select
				{weight 5	"driver_car_small_idle"}
				{weight 1	"driver_car_small_idle_1"}
				{weight 1	"driver_car_small_idle_2"}
			}
		}
		{if place_mask "commander"
			{random_select
				{weight 5	"passenger_car_small_idle"}
				{weight 1	"passenger_car_small_idle_1"}
				{weight 1	"passenger_car_small_idle_2"}
				{weight 1	"passenger_car_small_idle_3"}
			}
		}
		{if place_mask "gunner"
			{random_select
				{weight 1	"vehicle_mgun_1hand_idle_1"}
				{weight 1	"vehicle_mgun_1hand_idle_2"}
				{weight 1	"vehicle_mgun_1hand_idle_3"}
				{weight 1	"vehicle_mgun_1hand_idle_4"}
			}
		}
		{if place_mask "gunner1"
			{random_select
				{weight 1	"vehicle_mgun_1hand_idle_1"}
				{weight 1	"vehicle_mgun_1hand_idle_2"}
				{weight 1	"vehicle_mgun_1hand_idle_3"}
				{weight 1	"vehicle_mgun_1hand_idle_4"}
			}
		}
		{if place_mask "gunner2"
			{random_select
				{weight 1	"vehicle_mgun_1hand_idle_1"}
				{weight 1	"vehicle_mgun_1hand_idle_2"}
				{weight 1	"vehicle_mgun_1hand_idle_3"}
				{weight 1	"vehicle_mgun_1hand_idle_4"}
			}
		}
		{if place_mask "gunner3"
			{random_select
				{weight 1	"vehicle_mgun_1hand_idle_1"}
				{weight 1	"vehicle_mgun_1hand_idle_2"}
				{weight 1	"vehicle_mgun_1hand_idle_3"}
				{weight 1	"vehicle_mgun_1hand_idle_4"}
			}
		}
		{random_select
			{weight 5	"passenger_car_small_idle"}
			{weight 1	"passenger_car_small_idle_1"}
			{weight 1	"passenger_car_small_idle_2"}
			{weight 1	"passenger_car_small_idle_3"}
		}	
	}
	{if linked "airborne"
		{if place_mask "driver"
			{random_select
				{weight 5	"driver_airplane_idle"}
				{weight 5	"driver_airplane_idle_1"}
				{weight 5	"driver_airplane_idle_2"}
				{weight 5	"driver_airplane_idle_3"}
			}
		}
		{random_select
			{weight 5	"passenger_car_small_idle"}
			{weight 5	"passenger_car_small_idle_1"}
			{weight 5	"passenger_car_small_idle_2"}
			{weight 5	"passenger_car_small_idle_3"}
		}	
	}
	{if linked "anm_tank"
		{ if place_mask "seat_r*"
			{random_select
				{weight 10	"idle_onboard_r0"}
				{weight 1	"idle_onboard_r1"}
				{weight 1	"idle_onboard_r2"}
				{weight 1	"idle_onboard_r3"}
			}
		}
		{ if place_mask "seat_l*"
			{random_select
				{weight 10	"idle_onboard_l0"}
				{weight 1	"idle_onboard_l1"}
				{weight 1	"idle_onboard_l2"}
				{weight 1	"idle_onboard_l3"}
				{weight 1	"idle_onboard_l4"}
				{weight 1	"idle_onboard_l5"}
			}
		}
		{ if place_mask "seat_m*"
			{random_select 
				{weight 5	"idle_onboard_m0"}
				{weight 1	"idle_onboard_m2"}
				{weight 1	"idle_onboard_m3"}
				{weight 1	"idle_onboard_m4"}
			}
		}
		{ if place_mask "seat*"
			{random_select
				{weight 10	"idle_onboard_0"}
				{weight 1	"idle_onboard_1"}
				{weight 1	"idle_onboard_2"}
				{weight 1	"idle_onboard_3"}
				{weight 1	"idle_onboard_4"}
			}
		}
		{ if place_mask "gunner*"
			{random_select
				{weight 1	"vehicle_mgun_1hand_idle_1"}
				{weight 1	"vehicle_mgun_1hand_idle_2"}
				{weight 1	"vehicle_mgun_1hand_idle_3"}
				{weight 1	"vehicle_mgun_1hand_idle_4"}
			}
		}	
	}
	{if linked "anm_tank_aa"
		{ if place_mask "seat_r*"
			{random_select
				{weight 10	"idle_onboard_r0"}
				{weight 1	"idle_onboard_r1"}
				{weight 1	"idle_onboard_r2"}
				{weight 1	"idle_onboard_r3"}
			}
		}
		{ if place_mask "seat_l*"
			{random_select
				{weight 10	"idle_onboard_l0"}
				{weight 1	"idle_onboard_l1"}
				{weight 1	"idle_onboard_l2"}
				{weight 1	"idle_onboard_l3"}
				{weight 1	"idle_onboard_l4"}
				{weight 1	"idle_onboard_l5"}
			}
		}
		{ if place_mask "seat*"
			{random_select
				{weight 10	"idle_onboard_0"}
				{weight 1	"idle_onboard_1"}
				{weight 1	"idle_onboard_2"}
				{weight 1	"idle_onboard_3"}
				{weight 1	"idle_onboard_4"}
			}
		}
		{ if place_mask "gunner*"
			{random_select
				{weight 5	"zenit_pointer_right_idle"}
				{weight 1	"zenit_pointer_right_idle_1"}
				{weight 1	"zenit_pointer_right_idle_2"}
				{weight 1	"zenit_pointer_right_idle_3"}
			}
		}
		{ if place_mask "charger*"
			{random_select
				{weight 5	"zenit_pointer_right_idle"}
				{weight 1	"zenit_pointer_right_idle_1"}
				{weight 1	"zenit_pointer_right_idle_2"}
				{weight 1	"zenit_pointer_right_idle_3"}
			}
		}
		{ if place_mask "commander*"
			{random_select
				{weight 5	"zenit_pointer_right_idle"}
				{weight 1	"zenit_pointer_right_idle_1"}
				{weight 1	"zenit_pointer_right_idle_2"}
				{weight 1	"zenit_pointer_right_idle_3"}
			}
		}	
	}
	{if linked "anm_tank_2h"
		{ if place_mask "seat_r*"
			{random_select
				{weight 10	"idle_onboard_r0"}
				{weight 1	"idle_onboard_r1"}
				{weight 1	"idle_onboard_r2"}
				{weight 1	"idle_onboard_r3"}
			}
		}
		{ if place_mask "seat_l*"
			{random_select
				{weight 10	"idle_onboard_l0"}
				{weight 1	"idle_onboard_l1"}
				{weight 1	"idle_onboard_l2"}
				{weight 1	"idle_onboard_l3"}
				{weight 1	"idle_onboard_l4"}
				{weight 1	"idle_onboard_l5"}
			}
		}
		{ if place_mask "seat_m*"
			{random_select 
				{weight 5	"idle_onboard_m0"}
				{weight 1	"idle_onboard_m2"}
				{weight 1	"idle_onboard_m3"}
				{weight 1	"idle_onboard_m4"}
			}
		}
		{ if place_mask "seat*"
			{random_select
				{weight 10	"idle_onboard_0"}
				{weight 1	"idle_onboard_1"}
				{weight 1	"idle_onboard_2"}
				{weight 1	"idle_onboard_3"}
				{weight 1	"idle_onboard_4"}
			}
		}
		{ if place_mask "gunner*"
			{random_select
				{weight 1	"vehicle_mgun_2hand_idle_2"}
				{weight 1	"vehicle_mgun_2hand_idle_2"}
			}
		}	
	}
	{if linked "anm_tank_2h_ext"
		{ if place_mask "seat_r*"
			{random_select
				{weight 10	"idle_onboard_r0"}
				{weight 1	"idle_onboard_r1"}
				{weight 1	"idle_onboard_r2"}
				{weight 1	"idle_onboard_r3"}
			}
		}
		{ if place_mask "seat_l*"
			{random_select
				{weight 10	"idle_onboard_l0"}
				{weight 1	"idle_onboard_l1"}
				{weight 1	"idle_onboard_l2"}
				{weight 1	"idle_onboard_l3"}
				{weight 1	"idle_onboard_l4"}
				{weight 1	"idle_onboard_l5"}
			}
		}
		{ if place_mask "seat_m*"
			{random_select 
				{weight 5	"idle_onboard_m0"}
				{weight 1	"idle_onboard_m2"}
				{weight 1	"idle_onboard_m3"}
				{weight 1	"idle_onboard_m4"}
			}
		}
		{ if place_mask "seat*"
			{random_select
				{weight 10	"idle_onboard_0"}
				{weight 1	"idle_onboard_1"}
				{weight 1	"idle_onboard_2"}
				{weight 1	"idle_onboard_3"}
				{weight 1	"idle_onboard_4"}
			}
		}
		{ if place_mask "gunner2"
			{random_select
				{weight 1	"vehicle_mgun_2hand_idle_1"}
				{weight 1	"vehicle_mgun_2hand_idle_2"}
				{weight 1	"vehicle_mgun_2hand_idle_4"}
			}
		}
		{ if place_mask "gunner"
			{random_select
				{weight 5	"cannon_small_commander_idle"}
				{weight 1	"cannon_small_commander_idle_2"}
			}
		}
		{ if place_mask "commander"
			{random_select
				{weight 5	"cannon_small_charger_idle"}
				{weight 1	"cannon_small_charger_idle_2"}
			}
		}
		{ if place_mask "charger"
			{random_select
					{weight 5	"passenger_car_small_idle"}
					{weight 1	"passenger_car_small_idle_2"}
					{weight 1	"passenger_car_small_idle_3"}
				}
		}	
	}
	{if linked "anm_tank_ext"
		{ if place_mask "seat_r*"
			{random_select
				{weight 10	"idle_onboard_r0"}
				{weight 1	"idle_onboard_r1"}
				{weight 1	"idle_onboard_r2"}
				{weight 1	"idle_onboard_r3"}
			}
		}
		{ if place_mask "seat_l*"
			{random_select
				{weight 10	"idle_onboard_l0"}
				{weight 1	"idle_onboard_l1"}
				{weight 1	"idle_onboard_l2"}
				{weight 1	"idle_onboard_l3"}
				{weight 1	"idle_onboard_l4"}
				{weight 1	"idle_onboard_l5"}
			}
		}
		{ if place_mask "seat*"
			{random_select
				{weight 10	"idle_onboard_0"}
				{weight 1	"idle_onboard_1"}
				{weight 1	"idle_onboard_2"}
				{weight 1	"idle_onboard_3"}
				{weight 1	"idle_onboard_4"}
			}
		}
		{ if place_mask "gunner2"
			{random_select
				{weight 1	"vehicle_mgun_1hand_idle_1"}
				{weight 1	"vehicle_mgun_1hand_idle_2"}
				{weight 1	"vehicle_mgun_1hand_idle_4"}
			}
		}
		{ if place_mask "gunner"
			{random_select
				{weight 5	"passenger_car_small_idle"}
				{weight 1	"passenger_car_small_idle_2"}
				{weight 1	"passenger_car_small_idle_3"}
			}
		}
		{ if place_mask "commander"
			{random_select
				{weight 5	"passenger_car_small_idle"}
				{weight 1	"passenger_car_small_idle_2"}
				{weight 1	"passenger_car_small_idle_3"}
			}
		}
		{ if place_mask "charger"
			{random_select
				{weight 5	"passenger_car_small_idle"}
				{weight 1	"passenger_car_small_idle_2"}
				{weight 1	"passenger_car_small_idle_3"}
			}
		}	
	}
	{if linked "anm_m19"
		{ if place_mask "seat_r*"
			{random_select
				{weight 10	"idle_onboard_r0"}
				{weight 1	"idle_onboard_r1"}
				{weight 1	"idle_onboard_r2"}
				{weight 1	"idle_onboard_r3"}
			}
		}
		{ if place_mask "seat_l*"
			{random_select
				{weight 10	"idle_onboard_l0"}
				{weight 1	"idle_onboard_l1"}
				{weight 1	"idle_onboard_l2"}
				{weight 1	"idle_onboard_l3"}
				{weight 1	"idle_onboard_l4"}
				{weight 1	"idle_onboard_l5"}
			}
		}
		{ if place_mask "seat*"
			{random_select
				{weight 10	"idle_onboard_0"}
				{weight 1	"idle_onboard_1"}
				{weight 1	"idle_onboard_2"}
				{weight 1	"idle_onboard_3"}
				{weight 1	"idle_onboard_4"}
			}
		}
		{ if place_mask "gunner*"
			{random_select
				{weight 5	"zenit_pointer_right_idle"}
				{weight 1	"zenit_pointer_right_idle_1"}
				{weight 1	"zenit_pointer_right_idle_2"}
				{weight 1	"zenit_pointer_right_idle_3"}
			}
		}
		{ if place_mask "charger*"
			{random_select
				{weight 5	"cannon_small_charger_idle"}
				{weight 1	"cannon_small_charger_idle_2"}
			}
		}	
	}
	{if linked "anm_marder3"
		{ if place_mask "seat_r*"
			{random_select
				{weight 10	"idle_onboard_r0"}
				{weight 1	"idle_onboard_r1"}
				{weight 1	"idle_onboard_r2"}
				{weight 1	"idle_onboard_r3"}
			}
		}
		{ if place_mask "seat_l*"
			{random_select
				{weight 10	"idle_onboard_l0"}
				{weight 1	"idle_onboard_l1"}
				{weight 1	"idle_onboard_l2"}
				{weight 1	"idle_onboard_l3"}
				{weight 1	"idle_onboard_l4"}
				{weight 1	"idle_onboard_l5"}
			}
		}
		{ if place_mask "charger*"
			{random_select
				{weight 5	"cannon_small_charger_idle"}
				{weight 1	"cannon_small_charger_idle_2"}
			}
		}
		{random_select
			{weight 5	"passenger_car_small_idle"}
			{weight 1	"passenger_car_small_idle_1"}
			{weight 1	"passenger_car_small_idle_2"}
			{weight 1	"passenger_car_small_idle_3"}
		}	
	}
	{if linked "anm_tank_cannon"
		{ if place_mask "seat_r*"
			{random_select
				{weight 10	"idle_onboard_r0"}
				{weight 1	"idle_onboard_r1"}
				{weight 1	"idle_onboard_r2"}
				{weight 1	"idle_onboard_r3"}
			}
		}
		{ if place_mask "seat_l*"
			{random_select
				{weight 10	"idle_onboard_l0"}
				{weight 1	"idle_onboard_l1"}
				{weight 1	"idle_onboard_l2"}
				{weight 1	"idle_onboard_l3"}
				{weight 1	"idle_onboard_l4"}
				{weight 1	"idle_onboard_l5"}
			}
		}
		{ if place_mask "driver*"
			{random_select
				{weight 5	"driver_car_small_idle"}
				{weight 1	"driver_car_small_idle_1"}
				{weight 1	"driver_car_small_idle_2"}
			}
		}
		{ if place_mask "charger*"
			{random_select
				{weight 5	"cannon_small_charger_idle"}
				{weight 1	"cannon_small_charger_idle_2"}
			}
		}
		{ if place_mask "gunner"
			{random_select
				{weight 5	"cannon_small_commander_idle"}
				{weight 1	"cannon_small_commander_idle_2"}
			}
		}
		{ if place_mask "gunner2"
			{random_select
				{weight 1	"vehicle_mgun_2hand_idle_1"}
				{weight 1	"vehicle_mgun_2hand_idle_2"}
				{weight 1	"vehicle_mgun_2hand_idle_4"}
			}
		}
		{ if place_mask "commander*"
			{random_select
				{weight 5	"cannon_small_charger_idle"}
				{weight 1	"cannon_small_charger_idle_2"}
			}
		}
	}
	{if linked "anm_tank_m7"
		{ if place_mask "seat_r*"
			{random_select
				{weight 10	"idle_onboard_r0"}
				{weight 1	"idle_onboard_r1"}
				{weight 1	"idle_onboard_r2"}
				{weight 1	"idle_onboard_r3"}
			}
		}
		{ if place_mask "seat_l*"
			{random_select
				{weight 10	"idle_onboard_l0"}
				{weight 1	"idle_onboard_l1"}
				{weight 1	"idle_onboard_l2"}
				{weight 1	"idle_onboard_l3"}
				{weight 1	"idle_onboard_l4"}
				{weight 1	"idle_onboard_l5"}
			}
		}
		{ if place_mask "driver*"
			{random_select
				{weight 5	"driver_car_small_idle"}
				{weight 1	"driver_car_small_idle_1"}
				{weight 1	"driver_car_small_idle_2"}
			}
		}
		{ if place_mask "charger*"
			{random_select
				{weight 5	"cannon_small_charger_idle"}
				{weight 1	"cannon_small_charger_idle_2"}
			}
		}
		{ if place_mask "gunner"
			{random_select
				{weight 5	"zenit_pointer_right_idle"}
				{weight 1	"zenit_pointer_right_idle_1"}
				{weight 1	"zenit_pointer_right_idle_2"}
				{weight 1	"zenit_pointer_right_idle_3"}
			}
		}
		{ if place_mask "gunner2"
			{random_select
				{weight 1	"vehicle_mgun_2hand_idle_1"}
				{weight 1	"vehicle_mgun_2hand_idle_2"}
				{weight 1	"vehicle_mgun_2hand_idle_4"}
			}
		}
		{ if place_mask "commander*"
			{random_select
				{weight 5	"cannon_small_charger_idle"}
				{weight 1	"cannon_small_charger_idle_2"}
			}
		}
	}
	{if linked "anm_tank_cannon_ext"
		{ if place_mask "seat_r*"
			{random_select
				{weight 10	"idle_onboard_r0"}
				{weight 1	"idle_onboard_r1"}
				{weight 1	"idle_onboard_r2"}
				{weight 1	"idle_onboard_r3"}
			}
		}
		{ if place_mask "seat_l*"
			{random_select
				{weight 10	"idle_onboard_l0"}
				{weight 1	"idle_onboard_l1"}
				{weight 1	"idle_onboard_l2"}
				{weight 1	"idle_onboard_l3"}
				{weight 1	"idle_onboard_l4"}
				{weight 1	"idle_onboard_l5"}
			}
		}
		{ if place_mask "charger*"
			{random_select
				{weight 5	"passenger_car_small_idle"}
				{weight 1	"passenger_car_small_idle_1"}
				{weight 1	"passenger_car_small_idle_2"}
				{weight 1	"passenger_car_small_idle_3"}
			}
		}
		{ if place_mask "gunner*"
			{random_select
				{weight 5	"cannon_small_commander_idle"}
				{weight 1	"cannon_small_commander_idle_2"}
			}
		}
		{ if place_mask "commander*"
			{random_select
				{weight 5	"passenger_car_small_idle"}
				{weight 1	"passenger_car_small_idle_1"}
				{weight 1	"passenger_car_small_idle_2"}
				{weight 1	"passenger_car_small_idle_3"}

			}
		}	
	}
	{if linked "anm_tank_cannon_2h_ext"
		{ if place_mask "seat_r*"
			{random_select
				{weight 10	"idle_onboard_r0"}
				{weight 1	"idle_onboard_r1"}
				{weight 1	"idle_onboard_r2"}
				{weight 1	"idle_onboard_r3"}
			}
		}
		{ if place_mask "seat_l*"
			{random_select
				{weight 10	"idle_onboard_l0"}
				{weight 1	"idle_onboard_l1"}
				{weight 1	"idle_onboard_l2"}
				{weight 1	"idle_onboard_l3"}
				{weight 1	"idle_onboard_l4"}
				{weight 1	"idle_onboard_l5"}
			}
		}
		{ if place_mask "seat_m*"
			{random_select 
				{weight 5	"idle_onboard_m0"}
				{weight 1	"idle_onboard_m2"}
				{weight 1	"idle_onboard_m3"}
				{weight 1	"idle_onboard_m4"}
			}
		}
		{ if place_mask "gunner"
			{random_select
				{weight 5	"zenit_pointer_right_idle"}
				{weight 1	"zenit_pointer_right_idle_1"}
				{weight 1	"zenit_pointer_right_idle_2"}
				{weight 1	"zenit_pointer_right_idle_3"}
			}
		}
		{if place_mask "gunner2"
			{random_select
				{weight 1	"vehicle_mgun_2hand_idle_1"}
				{weight 1	"vehicle_mgun_2hand_idle_2"}
				{weight 1	"vehicle_mgun_2hand_idle_4"}
			}
		}
		{ if place_mask "commander*"
			{random_select
				{weight 5	"zenit_pointer_right_idle"}
				{weight 1	"zenit_pointer_right_idle_1"}
				{weight 1	"zenit_pointer_right_idle_2"}
				{weight 1	"zenit_pointer_right_idle_3"}
			}
		}	
	}
	{if linked "anm_hummel"
		{ if place_mask "charger2"
			{random_select
				{weight 25	"artillery_support_idle_r"}
				{weight 1	"artillery_support_idle_r_1"}
				{weight 1	"artillery_support_idle_r_2"}
				{weight 1	"artillery_support_idle_r_3"}
			}
		}
		{ if place_mask "charger"
			{random_select
				{weight 10	"artillery_support_idle_l"}
				{weight 1	"artillery_support_idle_l_1"}
				{weight 1	"artillery_support_idle_l_2"}
				{weight 1	"artillery_support_idle_l_3"}
			}
		}
		{ if place_mask "gunner"
			{random_select
				{weight 25	"cannon_big_commander_idle"}
				{weight 1	"cannon_big_commander_idle_1"}
				{weight 1	"cannon_big_commander_idle_2"}
				{weight 1	"cannon_big_commander_idle_3"}
			}
		}
		{ if place_mask "commander*"
			{random_select
				{weight 5	"passenger_car_small_idle"}
				{weight 1	"passenger_car_small_idle_1"}
				{weight 1	"passenger_car_small_idle_2"}
				{weight 1	"passenger_car_small_idle_3"}
			}
		}
	}
	{if linked "anm_welberwind"
		{if place_mask "gunner"
			{random_select
				{weight 5	"zenit_pointer_right_idle"}
				{weight 1	"zenit_pointer_right_idle_1"}
				{weight 1	"zenit_pointer_right_idle_2"}
				{weight 1	"zenit_pointer_right_idle_3"}
			}
		}
		{if place_mask "charger*"
			{random_select
				{weight 5	"zenit_pointer_right_idle"}
				{weight 1	"zenit_pointer_right_idle_1"}
				{weight 1	"zenit_pointer_right_idle_2"}
				{weight 1	"zenit_pointer_right_idle_3"}
			}
		}
		{ if place_mask "seat_r*"
			{random_select
				{weight 10	"idle_onboard_r0"}
				{weight 1	"idle_onboard_r1"}
				{weight 1	"idle_onboard_r2"}
				{weight 1	"idle_onboard_r3"}
			}
		}
		{ if place_mask "seat_l*"
			{random_select
				{weight 10	"idle_onboard_l0"}
				{weight 1	"idle_onboard_l1"}
				{weight 1	"idle_onboard_l2"}
				{weight 1	"idle_onboard_l3"}
				{weight 1	"idle_onboard_l4"}
				{weight 1	"idle_onboard_l5"}
			}
		}	
	}
	{if linked "horse_anm"
		{random_select
			{weight 2	"horse_driver_idle_0"}
			{weight 1	"horse_driver_idle_1"}
			{weight 1	"horse_driver_idle_2"}
		}	
	}
	{if linked "sc_497_anm"
		{if place_mask "gunner"
			{random_select
				{weight 5	"zenit_pointer_right_idle"}
				{weight 1	"zenit_pointer_right_idle_1"}
				{weight 1	"zenit_pointer_right_idle_2"}
				{weight 1	"zenit_pointer_right_idle_3"}
			}
		}
		{if place_mask "charger"
			{random_select
				{weight 5	"zenit_pointer_right_idle"}
				{weight 1	"zenit_pointer_right_idle_1"}
				{weight 1	"zenit_pointer_right_idle_2"}
				{weight 1	"zenit_pointer_right_idle_3"}
			}
		}
		{if place_mask "gunner2"
			{random_select
				{weight 5	"zenit_pointer_right_idle"}
				{weight 1	"zenit_pointer_right_idle_1"}
				{weight 1	"zenit_pointer_right_idle_2"}
				{weight 1	"zenit_pointer_right_idle_3"}
			}
		}
		{if place_mask "charger2"
			{random_select
				{weight 5	"zenit_pointer_right_idle"}
				{weight 1	"zenit_pointer_right_idle_1"}
				{weight 1	"zenit_pointer_right_idle_2"}
				{weight 1	"zenit_pointer_right_idle_3"}
			}
		}
		{if place_mask "gunner5"
			{random_select
				{weight 3	"artillery_support_idle_r"}
				{weight 1	"artillery_support_idle_r_1"}
				{weight 1	"artillery_support_idle_r_2"}
				{weight 1	"artillery_support_idle_r_3"}
			}
		}
		{if place_mask "gunner6"
			{random_select
				{weight 3	"artillery_support_idle_l"}
				{weight 1	"artillery_support_idle_l_1"}
				{weight 1	"artillery_support_idle_l_2"}
				{weight 1	"artillery_support_idle_l_3"}
			}
		}
		{if place_mask "gunner3"
			{random_select
				{weight 1	"vehicle_mgun_2hand_idle_1"}
				{weight 1	"vehicle_mgun_2hand_idle_2"}
				{weight 1	"vehicle_mgun_2hand_idle_4"}
			}
		}
		{if place_mask "gunner4"
			{random_select
				{weight 1	"vehicle_mgun_2hand_idle_1"}
				{weight 1	"vehicle_mgun_2hand_idle_2"}
				{weight 1	"vehicle_mgun_2hand_idle_4"}
			}
		}
		{if place_mask "place*"
			{random_select 
				{weight 5	"idle_onboard_m0"}
				{weight 1	"idle_onboard_m2"}
				{weight 1	"idle_onboard_m3"}
				{weight 1	"idle_onboard_m4"}
			}
		}
	}
		
}