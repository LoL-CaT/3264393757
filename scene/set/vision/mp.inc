(include "generic.inc")

;= HUMAN =====================================
;-----------------------------TT by Pheonix-------------------------
{"tt_tankman"}
;------------------------------End of TT------------------------------
{"human"
	{uncover 0.1}
	("vision_tankman" args 0)
	{h_fov 70}
	{v_fov 90}
	{uncover 0}
}

{"mp_soldier"
	{uncover 5}
	("vision_human" args 40)
	{h_fov 90}
	{v_fov 120}
}

{"mp_officer"
	{uncover 30}
	("vision_officer" args 60)
	{h_fov 120}
	{v_fov 120}
}

{"mp_sniper"
	{uncover 30}
	("vision_officer" args 50)
	{h_fov 120}
	{v_fov 120}
}

{"mp_specnaz"
	{uncover 20}
	("vision_human" args 50)
	{h_fov 230}
	{v_fov 120}
}

;= SPECIAL ===================================

{"soldier_focused"
	{uncover 7}
	("vision_human" args 10)
	{v_fov 120}
	{h_fov 270}
}

{"rifle_telescope"
	{uncover 7}
	("glass" args 7)
	{h_fov 360}
	{v_fov 120}
}

{"field_glass"
	{uncover 15}
	("glass" args 15)
	{h_fov 360}
	{v_fov 120}
}

;= CANNON ========================================

{"cannon_main"
	{uncover 5}
    ("vision_optic" args 100)
	{h_fov 60}
	{v_fov 140}
}

{"cannon_mgun"
	{uncover 5}
	("vision_human" args 60)
	{h_fov 90}
	{v_fov 140}
}

{"cannon_main-far"
	{uncover 5}
   ("vision_optic" args 100)
	{h_fov 60}
	{v_fov 140}
}

{"cannon_crew"
	{uncover 5}
    ("vision_human" args 35)
	{h_fov 240}
	{v_fov 140}
}

;= VEHICLE & MOTO ============================

{"vehicle_main"
	("vision_human" args 30)
	{h_fov 90}
	{v_fov 140}
}

{"vehicle_top_mgun"
	("vision_human" args 40)
	{h_fov 90}
	{v_fov 140}
}

{"vehicle_top_turret"
	{uncover 3}
	("vision_optic" args 40)
	{h_fov 40}
	{v_fov 140}
}

{"moto_crew"
	{uncover 3}
	("vision_human" args 60)
	{h_fov 100}
	{v_fov 60}
}

{"moto_around"
	{uncover 3}
	("human_stand" args 30)
	{h_fov 360}
	{v_fov 60}
}

;= TANK ======================================

{"tank_main-l"
	{uncover 5}
    ("vision_optic" args 90)
	{h_fov 30}
	{v_fov 140}
	{wide 2}
}

{"tank_main-m"
	{uncover 5}
    ("vision_optic" args 100)
	{h_fov 25}
	{v_fov 140}
	{wide 2}
}

{"tank_main-h"
	{uncover 5}
    ("vision_optic" args 100)
	{h_fov 25}
	{v_fov 140}
	{wide 2.5}
}

{"tank_driver"
	{uncover 3}
   ("vision_human" args 30)
	{h_fov 100}
	{v_fov 90}
}

{"tank_back"
	{uncover 3}
   ("vision_human" args 30)
	{h_fov 80}
	{v_fov 120}
}

{"tank_around-l"
	{uncover 1}
    ("human_stand" args 30)
	{h_fov 360}
	{v_fov 170}
}

{"tank_around-m"
	{uncover 1}
    ("human_stand" args 20)
	{h_fov 360}
	{v_fov 170}
}

{"tank_around-h"
	{uncover 1}
   ("human_stand" args 20)
	{h_fov 360}
	{v_fov 170}
}
