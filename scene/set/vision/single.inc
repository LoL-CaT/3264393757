(include "generic.inc")

{"human"
	{uncover 3}
	("vision_optic" args 30)
	{h_fov 120}
	{v_fov 120}
}

{"mp_soldier"
	{uncover 5}
	("vision_optic" args 50)
	{h_fov 90}
	{v_fov 120}
}

;= SPECIAL ===================================

{"soldier_focused"
	{uncover 2}
	{v_fov 120}
	{h_fov 270}
}

{"rifle_telescope"
	{uncover 6}
	{h_fov 360}
	{v_fov 120}
}

{"field_glass"
	{uncover 8.5}
	{h_fov 360}
	{v_fov 120}
}

;= CANNON ====================================

{"cannon_main"
    ("vision_optic" args 30)
	{h_fov 35}
	{wide 2}
	{v_fov 120}
}

{"cannon_mgun"
    ("vision_optic" args 25)
	{h_fov 40}
	{wide 2}
	{v_fov 120}
}

{"cannon_main-far"
    ("vision_optic" args 45)
	{h_fov 30}
	{wide 2}
	{v_fov 120}
}

{"cannon_crew"
    ("vision_optic" args 14)
	{h_fov 270}
	{v_fov 60}
}

;= VEHICLE & MOTO ============================

{"vehicle_main"
    ("vision_optic" args 25)
	{h_fov 60}
	{wide 2}
	{v_fov 120}
}

{"vehicle_top_mgun"
    ("vision_optic" args 20)
	{h_fov 55}
	{wide 2}
	{v_fov 90}
}

{"vehicle_top_turret"
    ("vision_optic" args 45)
	{h_fov 40}
	{v_fov 140}
}

{"moto_crew"
    ("vision_optic" args 20)
	{h_fov 160}
	{v_fov 60}
}

;= TANK ======================================

{"tank_main-l"
	{uncover 60}
    ("vision_optic" args 40)
	{h_fov 25}
	{wide 2}
	{v_fov 140}
}

{"tank_main-m"
	{uncover 70}
    ("vision_optic" args 40)
	{h_fov 18}
	{wide 2}
	{v_fov 140}
}

{"tank_main-h"
	{uncover 80}
    ("vision_optic" args 45)
	{h_fov 18}
	{wide 2}
	{v_fov 140}
}

{"tank_driver"
    ("vision_optic" args 20)
	{h_fov 80}
	{v_fov 90}
}

{"tank_back"
    ("vision_optic" args 20)
	{h_fov 35}
	{wide 2}
	{v_fov 90}
}

{"tank_around-l"
}

{"tank_around-m"
}

{"tank_around-h"
}
