{switch_to_time 0.05}								; ¬рем€ перехода в данный control mode
; ¬ этом режиме FOV камеры измен€етс€ при вращении колеса мыши (соответственно мен€етс€ zoom)
; ƒл€ range параметров первое число соответствует максимальному приближению, второе - минимальному
{parameters
	{range_degrees "camera_fov"		10	25}	; ”гол раскрыти€ камеры
	{range_degrees "camera_pitch_min"	-10	-10}	; Ќижний порог диапазона углов наклона камеры (90 - вертикально вверх, -90 - вертикально вниз)
	{range_degrees "camera_pitch_max"	75	5}	; ¬ерхний порог диапазона углов наклона камеры (90 - вертикально вверх, -90 - вертикально вниз)
	{range "camera_offset_up"		2.8	2.8}	; —мещение точки внимани€ по вертикальной оси
	{range "camera_offset_side"		0	0}	; —мещение точки внимани€ по горизонтальной оси
	{range "camera_offset_forward" 		10	10}	; —мещение точки внимани€ по продольной оси
	{range "camera_distance"		6	6}	; —мещение камеры по продольной оси
	{float "aim_spot_offset"			0}	; —мещение прицела по вертикальной оси
	{bool "aim_spot_disabled" 1}
	{cursor_relative_mode ""}
	{float "zoom_steps"				4}	;  оличество шагов масштабировани€
	{sprite "sprite" "/interface/fullscreen/mask_widescreen"}
	{visual_set "visual_set" "tps_tank"}
	{highlight_silhouettes "highlight_silhouettes" 0}
	{fogmap_disable_paint "fogmap_disable_paint"}
	{bool "hide_own_icon" 1} 				; именнованные параметры могут использоватьс€ в услови€х дл€ иконок,
								; напрмер {if control_mode_parameter_on "hide_own_icon" ..} сработает
								; если текущее значение параметра "hide_own_icon" больше 0.5
	{selection_sprite_hide "selection_sprite_hide" 1}
	{float "listener_fps" 1}
	{hide_hud_panel "hide_hud_panel" "hotbar_auto" "minimap" "map_control" "hud2_mp_unit_spawn" "mp_spawn_prepare_dialog" "hotbar_states_left" "hotbar_states_right" "hotbar_actions_1" "hotbar_states_center"}
}
{previous "tps"}
{camera "tps"}
