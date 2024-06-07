Displayed icons of the unit status with the highest priority.
The priority icons are set in descending file (icon defined earlier has a higher priority).
Conditions have a hierarchical structure. If basic condition truthfully then checked sub-conditions.
Sub-condition specified in the beginning of the list has a higher priority.
All condition possible inverse by added word "not" before "condition"

Condition expression format: 
{if [not] <term0> [and|or [not] term1 .. [and|or [not] termN]]  
	{..}
}

Basic settings for nodes
	{icon "<sprite:string>"}
	{background "<string>"}
	{duration <value:float>}
	{group "<group_name:string>"}
	{row_priority <value:int>}
	{column_priority <value:int>}
	{layout_manager "<name:string>"}
	{distance_scalable "<value:bool>"}
	{state "state_name" .. } - модификатор для иконок: текст, прогресс бар, смена цвета и т.д. Более детально ниже.
	{action "action_name" .. } - действие при одинарном клике на иконку
	{action_double_click "action_name" .. } - действие при двойном клике на иконку

Настройки для action-a
	Формат записи:
	{action "<action_name:string>"
		{executor - <type:string>}; - возможные значения: "self", "active_entity", "selection", "first_from_selection", "nearest_from_selection"
		{cursor "sprite:string"}; - курсор при наведении на иконку, если не задан в Interface::eAction

If in condition is not specified background, it is taken from the parent and so on.
If action is valid, the cursor sprite is taken from him.

Count of icons displayed  at the same time can be controlled by groups.
All icons by default consist in group with name "default".
If necessary show several icons at the same time, increment count in block "groups" or add special group for this type of icon 
For example add block {group "ammo_tag"} to condition and then add block {ammo_tag 1} to block "groups"

Available terms:
	abandoned - is entity abandoned
	active_entity - сущность не "inactive"
	active_human - human is sensible, not inactive and not linked
	ai_squad - актер является участником ai squad
	ammo_tag - is ammo stuff for active weapon contain tag, additional parameter: "tag" <string>
	ammo_tag_after_load - is ammo stuff after load for active weapon contain tag, additional parameter: "tag" <strin
	ammo_tag_for_weapon - 
	ammo_tag_for_weapon_after_load -
	anti_airborne_mode -
	available_places - check is exist available places in entity
	breed_mask - is breed tag correspond mask, additional parameter: "mask" <string>
	camouflage
	can_board - 
	can_spawn_paramedic - 
	charge - актер движется с состоянием "charge"
	component_state - check component state, additional parameter: "component" <string>, "component_state" <string> ("work", "broken", "destroyed")
	cover_kind - сущность за определенном типом укрытия. Параметр "<type:string>". Возможные значения типа укрытия: "none", "vertical", "horizontal", "bush", "terrain". Можно задать несколько типов
		Пример {if cover_kind "vertical" "horizontal"
	crew_count - check count of crew, additional parameter: "type" <string> ("all", "worker", "other"), "count" <int>, "operator" <string>:
		"equ" - equal
		"neq" - not equal
		"lss" - less than
		"leq" - less than or equal
		"gtr" - greater than
		"geq" - greater than or equal
	crew_full - vehicle is fully staffed crew, additional parameter: "type" <string> ("all", "worker", "other")
	crew_place_count -
	current_user - entity owner is current user
	current_weapon_place -
	dead - entity is dead
	dying - entity is dying 
	dying_cant_hospitalize - 
	dying_on_friendly_territory - 
	dying_on_enemy_territory - 
	evacuating - entity is evacuating by paramedic
	fire_mode - check fire mode, additional parameter: "mode" <string> ("hold", "return", "open")
	fsm_tags - есть ли заданные теги в fsm. Параметр "<string>". Можно задать только 1 набор тегов
		Пример: {if fsm_tags "tag1 tag2 tag3" .. }
	has_order - entity has order. Формат {if has order "order_name" ..	
	heal - check that entity is healing
	house - is entity house
	house_fortification_state - тип укрепления дома. Формат {if house_fortification_state "state".
		Допустимые значения: enabled, disabled, stopped, paused, working
	house_has_user_dwellers - в доме есть юниты игрока
	house_is_assaulted - 
	house_is_empty - 
	human - is entity hman	
	human_motion - сущность движется в заданном режиме. Возможные значения: "flee", "retreat", "none", "advance", "charge"
		Пример: {if human_motion "flee" .. }
	icon_event - в данный момент для сущности существует событие с заданным именем
		Пример: {if icon_event "damage_current_user" .. }
	in_assault - is human assault house
	in_fog - entity in fog
	in_fortification - актер находится в укреплении с заданными тегами. Формат {if in_fortification "tag1 tag2"
	in_house - is human linked to house
	install - check is entity installs something
	item_in_hand - проверяет имеет ли предмет в руке такие теги. Можно задать несколько наборов тегов {"tag" "tag1"} {"tag" "tag2"}
		Формат: {if item_in_hand "tag1 tag2" "tag3 tag4" ..}
	is_mouse_focused - entity is focused by mouse
	is_vehicle_mined - vehicle is mined
	linked - is entity linked
	manual_control - check is entity in manual control
	morale - мораль актера в заданных пределах (float). Формат {if <min> <max>
	move_mode - check move mode, additional parameter: "mode" <string> ("hold", "zone", "free")
	mp_game - mp game is active
	need_ammo - active weapon hasn't ammo
	need_fuel - entity has fuel tank but it is empty
	need_repair - entity is vehicle and necessary repair
	need_weapon - entity has not active weapon			
	observed - сущность видна врагом	
	props - check tags exist in entity props, additional parameter: "tag" <string>. Possible set several tags {"tag" "tag1"} {"tag" "tag2"}		
	relation - check relation of current user for entity, additional parameter: "type" <string> ("neutral", "enemy", "ally")		
	reloading - active weapon is recharges
	repairing - сущность ремонтируется в даный момент
	sensible - is entity is sensible
	suppressed - актер под определенном уровнем подавления. Формат {if supressed 1 ..
	suspect_stage - актер на определенной стадии "свечения" для противника. Формат {if suspect_stage "stage_name"
	tags - check tags exist in entity tags. additional parameter: "tag" <string>. Possible set several tags {"tag" "tag1"} {"tag" "tag2"}
	territory_type - check which team is owner of territory, where entity is located, additional parameter: "type" <string> ("friendly", "enemy")
	true - всегда возвращает истину
	unfogged - сущность имеет флаг "unfogged". Примечание: НЕ тоже самое что и проверка "in_fog"
	vehicle - is entity vehicle
	visible - 
	weapon - check active weapon, additional parameter: "tag" <string>, "mask" <string>. Possible set several tags {"tag" "tag1"} {"tag" "tag2"} or masks
	weapon_place - оружие с конкретным названием находится в заданном place. Парметры: "<place_name:string>" "<place_type:string>"
		Пример: {if weapon_place "mgun2" "place_type" .. }
	weapon_skill - check level skill for current weapon
		{if weapon_skill "none"
			{background "background/infantry_base_level1"}
			("icons_by_weapon")
		}
		{if weapon_skill "basic"
			{background "background/infantry_base_level2"}
			("icons_by_weapon")
		}
		{if weapon_skill "expert"
			{background "background/infantry_base_level3"}
			("icons_by_weapon")
		}

"state" is modifier for unit state icon. For example: add text or progress bar, change color or location of icon

Possible use state or action only if embedded conditions are satisfied.
For example, add progress bar only if entity reloading at the same time
{if ..
	{icon "shell_type/ap"}
	{if reloading
		{state "progress_bar:recharge"}
	}
}

Basic settings for state "text"
	location - <Point2> - location of text
	offset - <Point2> - offset of text relative to icon. Possible use negative numbers
	align - <string> <string> - align of text. Possible values: "begin", "center", "end". Note: no quotes in block {align ..}
	color - array of {"<key>" "<color>"}. Default value set by {"normal" "<color>"}
	font_style - <string> - support all gem2 font modifiers, except s(..), because font size calculated in run-time

Basic settings for state "progress bar"
	size - size of progress bar
	location - location of progress bar
	offset - offset of progress bar relative to icon. Possible use negative numbers

Available states:
	"color:human_damaged" - change color of icons during house assault
	"count:house_empty_place" - generate icons for each empty place in house
	"picture:usual" - отображение дополнительного спрайта кроме фона и самой иконки. Отрисовывается поверх них
		Пример:
			{state "picture:usual"
				{sprite "gold_box"}
			}
	"position:vertical_shift" - сдвиг всех элементов иконки, кроме указанного
		{type "down"} - все вниз, кроме указанного
		{type "up"} - все вверх кроме указанного
		Пример:
		{state "position:shift"
			{offset 4}
			{anchor_modifier "progress_bar:human_vitality"}
			{type "up"}
			{priority -1}
		}
	"progress_bar:camouflage" - прогресс маскировки
	"progress_bar:charge - прогресс действия "рывка"
	"progress_bar:house_fortification" - progress bar of house fortification
	"progress_bar:human_vitality" - progress bar of human hp
	"progress_bar:icon_event" - отображения времени определенного события
	"progress_bar:not_sensible" - время оглушения
	"progress_bar:recharge" - progress bar of recharge weapon
	"progress_bar:repair" - прогресс ремонта
	"progress_bar:suppressed" - степень подавленности юнита
	"progress_bar:suspect" - степень "засвета" юнита
	"progress_bar:vehicle_armor" - отображение хп техники
	"text:actor_uid" - отображает uid актер-а в виде текста
	"text:ammo_count" - count of ammo. Text format:
		if capacity of holder > 1 - text is "<in_holder>/<in_inventory>"
		if capacity of holder equal 1 - text is "<in_inventory>"
	"text:ammo_type" - тип заряженного снаряда. Локализация берется по пути "desc/ammo/type/%1%"
		Пример:
			{state "text:ammo_type"
				{ammo_tag "fg"}
			}
	"text:cp_for_capture" - count of cp for capture. Text format:
		if(cp_cost == 0) text is empty
		else if(cp_cost > 0 && player_cp >= cp_cost) text is <cp_cost>
		else if(cp_cost > 0 && player_cp < cp_cost) text is <player_cp>/<cp_cost>
		Special block for color: {"not_enough_cp" "red"}
	"text:crew_info" - count of crew in vehicle, additional parameter for color {"lss:<float>" "<color>"} 
		if occupancy of vehicle is less than coefficient ("lss:<float>") change default color
	"text:free_place_count" - count of free place in house
	"text:place_idx" - отоборажение номера place-а
	"text:vehicle_armor" - отображение хп техники 
	"text:vehicle_mine_time_left" - display of time before the explosion
	"text:weapon_place_type" - тип установлненного оружия. Локализация берется по пути "desc/weapon/type/abbreviation/%1%"
		Пример:
			{state "text:weapon_place_type"
				{place_name "%place_name"}
			}
