{switch_to_time 0.05}								; Время перехода в данный control mode
; В этом режиме параметры камеры изменяются при вращении колеса мыши. 
; Условно говоря вращение колеса мыши меняет некоторый коэффициент k в диапазоне [0..1].
; Для range параметров первое число соответствует k=0 (максимальное приближение к сущности), второе - k=1 (максимальное отдаление от сущности).
{parameters
	{range_degrees "camera_fov"		60	60}	; Угол раскрытия камеры
	{range_degrees "camera_pitch_min" 	-35	-35}	; Нижний порог диапазона углов наклона камеры (90 - вертикально вверх, -90 - вертикально вниз)
	{range_degrees "camera_pitch_max"	15	2}	; Верхний порог диапазона углов наклона камеры (90 - вертикально вверх, -90 - вертикально вниз)
	{range "camera_offset_up"		4	4}	; Смещение точки внимания по вертикальной оси
	{range "camera_offset_side"		0	0}	; Смещение точки внимания по горизонтальной оси
	{range "camera_offset_forward" 		2	0}	; Смещение точки внимания по продольной оси
	{range "camera_distance"		2	12.5}	; Смещение камеры по продольной оси
	{float "aim_spot_offset"			5}	; Смещение прицела по вертикальной оси
	{bool "aim_spot_disabled" 0}
	{cursor_relative_mode ""}
	{float "zoom_steps"				16}	; Количество шагов масштабирования
	{sprite "sprite" ""}
	{visual_set "visual_set" "tps_tank"}
	{fogmap_disable_paint "fogmap_disable_paint"}
	{bool "hide_own_icon" 1} 				; именнованные параметры могут использоваться в условиях для иконок,
								; напрмер {if control_mode_parameter_on "hide_own_icon" ..} сработает
								; если текущее значение параметра "hide_own_icon" больше 0.5
	{selection_sprite_hide "selection_sprite_hide" 1}
	{float "listener_fps"				0}
}
;{suitable "tank tps" {priority 10}}						; Условия срабатывания
{next "snipe"}
{camera "tps"}


