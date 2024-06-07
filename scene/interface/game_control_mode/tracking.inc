{switch_to_time 0.05}								; Время перехода в данный control mode
{parameters
	{bool "aim_spot_disabled" 0}
	{float "zoom_steps"				3}	; Количество шагов масштабирования
	{sprite "sprite" ""}
	{selection_sprite_hide "selection_sprite_hide" 0}
	{visual_set "visual_set" "tracking_tank"}
	{float "listener_fps"				0}
}
{camera "tracking"}		; камера движется вместе с юнитом, но ее можно и перемещать и вращать как обычно
