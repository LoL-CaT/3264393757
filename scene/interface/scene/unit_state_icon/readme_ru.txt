Иконки состояния юнита отображаются в соответствии с приоритетом
Приоритет зависит от расположения в файле (иконки объявленные ранее имеют более высокий приоритет)
Условия имеют иерархическую структуру. Если основное условие выполняется, то проверяются вложенные и т.д.
Под-условия объявленные в начале списка имеют более высокий приоритет
Все условия можно инвертировать с помощью добавления слова "not" перед условием

Формат записи условий: 
{if [not] <term0> [and|or [not] term1 .. [and|or [not] termN]]  
	{..}
}

Основные настройки для узлов
	{icon "<sprite:string>"}
	{background "<string>"}
	{duration <value:float>}
	{group "<group_name:string>"}
	{row_priority <value:int>}
	{column_priority <value:int>}
	{layout_manager "<name:string>"} - название компоновщика иконок
	{distance_scalable "<value:bool>"} - масштабируется в зависимости от расстояния между камерой и сущностью
	{state "state_name" .. } - модификатор для иконок: текст, прогресс бар, смена цвета и т.д. Более детально ниже
	{action "action_name" .. } - действие при одинарном клике на иконку
	{action_double_click "action_name" .. } - действие при двойном клике на иконку

Формат записи action-a, action_double_click имеет аналогичный синтаксис
	{action "<action_name:string>"
		{executor "<type:string>"} - возможные значения: "self", "active_entity", "selection", "first_from_selection", "nearest_from_selection"
		{cursor "<sprite:string>"} - курсор при наведении на иконку, если не задан в Interface::eAction
	}

Если в узле не указан фон, то он берется из родительского узла и выше.
Если в узле не указана длительность, то берется из родительского узла и выше. Если и в этом случае длительность не задана, то длительность устанавливается 0.01 секунда (иконка будет отображаться до следующего составления списка активных иконок)
Если в узле или в родительских узлах не указана группа, то иконка считается в группе "default"
Если в узле или в родительских узлах не указан параметр row_priority, то устанавливается значение 0
Если в узле или в родительских узлах не указан параметр column_priority, то устанавливается значение 0
Если в узле или в родительских узлах не указан параметр layout_manager, то используется стандартный компоновщик иконок

В узле можно указать флаги:
	disable_action_from_parent - не использовать action из родительских узлов
	disable_action_double_click_from_parent - не использовать action_double_click из родительских узлов
	disable_states_from_parent - не использовать states из родительских узлов
	no_modifiers_for_parent - все параметры в текущем узле не влияют на соседние узлы (параметры применяются только локально в текущем узле и дочерних)

Количество иконок отображаемых в момент времени регулируется с помощью групп.
Все иконки по умолчанию находятся в группе с названием "default".
Если необходимо отображать несколько иконок в один момент времени, необходимо увеличить кол-во в блоке "groups" или добавить специальную группу для этого типа иконок 
Например, добавить блок {group "ammo_tag"} в узел и добавить {ammo_tag 1} в блок "groups"

Доступные проверки:
	abandoned - сущность покинута (актуально для техники)
	active_entity - сущность не "inactive"
	active_human - солдат "sensible", не "inactive" и не "linked"
	ai_squad - сущность является участником ai squad
	ammo_tag - боеприпасы для текущего оружия содержат тег. Параметр "<tag:string>". Можно задать несколько наборов тегов
		Пример: {if ammo_tag "ap rifle" "fg" .. }
	ammo_tag_after_load - боеприпасы после перезарядки для текущего оружия содержат тег. Параметр: "<tag:string>". Можно задать несколько наборов тегов.
		Пример: {if ammo_tag_after_load "ap rifle" "fg" .. }
	ammo_tag_for_weapon - боеприпасы для оружия в определенном place
		Пример: {if ammo_tag_for_weapon "%place_name" "%ammo_tag" .. }
	ammo_tag_for_weapon_after_load -
		Пример: {if ammo_tag_for_weapon_after_load "%place_name" "%ammo_tag" .. }
	anti_airborne_mode - у сущности активирован режим "пво"
	available_places - проверка есть ли в техники свободные place-ы
	breed_mask - тег breed-a соответствует маске. Параметр "<mask:string>". Можно задать несколько масок
		Пример: {if breed_mask "*/saboteur" "*/scout" .. }
	camouflage - состояние маскировки. Параметры "<camouflage_state:string>". Возможные значения состояния маскировки: "on", "off", "in_progress"
		Пример: {if camouflage "in_progress" .. }
	can_board - можно сесть в сущность (актуально для техники)
	can_spawn_paramedic - возможно вызвать парамедика для текущей сущности
	charge - сущность движется с состоянием "charge"
	component_state - состояние компонента. Параметры: "<component:string>" "<component_state:string>". Возможные значения состояния компонента: "work", "broken", "destroyed"
		Пример: {if component_state "gun" "destroyed" .. }
	cover_kind - сущность за определенном типом укрытия. Параметр "<type:string>". Возможные значения типа укрытия: "none", "vertical", "horizontal", "bush", "terrain". Можно задать несколько типов
		Пример {if cover_kind "vertical" "horizontal"
	crew_count - проверка количества экипажа. Параметры: "<type:string>" (возможные значения: "all", "worker", "other"), "<count:int>", "<operator:string">
		Возможные значения для оператора
			"equ" - equal
			"neq" - not equal
			"lss" - less than
			"leq" - less than or equal
			"gtr" - greater than
			"geq" - greater than or equal
		Пример: {if crew_count 2 "worker" "gtr" .. }
	crew_full - техника имеет полный экипаж. Параметр "<type:string>". Возможные значения: "all", "worker", "other"
		Пример: {if crew_full "worker" .. }
	crew_place_count - проверка количества мест, без учета занято ли оно
		Пример: {if crew_place_count 0 "worker" "gtr"
	current_user - сущность текущего игрока
	current_weapon_place - текущее оружие находится в заданном place. Параметр "<place_type:string>"
		Пример: {if current_weapon_place "place_type" .. }
	dead - сущность мертва
	dying - сущность умирает
	dying_cant_hospitalize - сущность умерла и ее невозможно эвакуировать
	dying_on_enemy_territory - 
	dying_on_friendly_territory - 
	evacuating - сущность эвакуируется с помощью парамедика
	fire_mode - проверка режима огня. Параметр "<mode:string>". Возможные значения: "hold", "return", "open"
		Пример: {if fire_mode "hold" .. }
	fsm_tags - есть ли заданные теги в fsm. Параметр "<string>". Можно задать только 1 набор тегов
		Пример: {if fsm_tags "tag1 tag2 tag3" .. }
	has_order - имеет приказ. Параметр "<order_name:string>"
		Пример: {if has_order "withdraw" .. }
	heal - сущность лечится (актуально для людей)
	house - сущность является домом
	house_fortification_state - тип укрепления дома. Параметр "<state:string>". Возможные значения: "enabled", "disabled", "stopped", "paused", "working"
		Пример: {if house_fortification_state "working" .. }
	house_has_user_dwellers - в доме есть юниты текущего игрока
	house_is_assaulted - дом подвергается штурму
	house_is_empty - дом пуст
	human - сущность является человеком
	human_motion - сущность движется в заданном режиме. Возможные значения: "flee", "retreat", "none", "advance", "charge"
		Пример: {if human_motion "flee" .. }
	icon_event - в данный момент для сущности существует событие с заданным именем
		Пример: {if icon_event "damage_current_user" .. }
	in_assault - солдат штурмует дом
	in_fog - в тумане
	in_fortification - сущность находится в укреплении с заданными тегами. Параметр "tag1 tag2". Примечание: только один набор тегов
		Пример: {if in_fortification "tag1 tag2"
	in_house - солдат в доме
	install - сущность устанавливает что-либо
	item_in_hand - имеет ли предмет в руке заданные теги. Параметр "<string>". Можно задать несколько наборов тегов
		Пример: {if item_in_hand "mine_detector stuff" "detector" .. }
	is_mouse_focused - сущность под курсором мыши
	is_vehicle_mined - техника заминирована
	linked - сущность прилинкована
	manual_control - сущность в прямом управлении
	morale - мораль актера находится в заданных пределах. Параметры: <min:float> <max:float>
		Пример: {if morale 50 70 .. }
	move_mode - проверка режима движения. Параметр "<mode:string>". Возможные значения: "hold", "zone", "free"
		Пример: {if move_mode "zone" .. }
	mp_game - мультиплеерный режим
	need_ammo - для текущего оружия отсутствуют боеприпасы
	need_fuel - сущность имеет бак, но он пуст (актуально для техники)
	need_repair - требуется ремонт (актуально для техники)
	need_weapon - у сущности нет текущего оружия
	observed - сущность видна врагом
	props - есть ли заданные теги в props-ах сущности. Параметр "<tag:string>" или "<tags:string>". Можно задать несколько наборов тегов
		Пример: {if props "map_point" "spawn_point" .. }
	relation - отношение текущего игрока с владельцем сущности. Параметр "<type:string>". Возможные значения: "neutral", "enemy", "ally"
		Пример: {if relation "enemy" .. }
	reloading - текущее оружие перезаряжается. Необязательный параметр "<place_name:string>" - если необходимо проверить перезарядку оружия в конкретном place
		Пример: {if reloading  .. }
		Пример 2: {if reloading "gun2" .. }
	repairing - сущность ремонтируется в данный момент
	sensible - сущность в сознании
	suppressed - под определенном уровнем подавления. Параметр <value:int>
		Пример: {if supressed 1 .. }
	suspect_stage - на определенной стадии "свечения" для противника. Параметр "<tag:string>"
		Пример: {if suspect_stage "detected"
	tags - есть ли заданные теги в tag-ах сущности. Параметры: "tag" <string>. Можно задать несколько наборов тегов {"tag" "tag1"} {"tag" "tag2"}
		Пример: {if tags "mission_target" .. }
	territory_type - какая команда является владельцем территории, на который находится сущность. Параметр "<type:string>. Возможные значения: "friendly", "enemy", "reverse_team"
		Пример: {if territory_type "reverse_team" .. }
	true - всегда возвращает истину. Примечание: может использоваться если необходимо отделить группу условий
	unfogged - сущность имеет флаг "unfogged". Примечание: НЕ тоже самое что проверка "in_fog"
	vehicle - сущность является техникой
	visible - сущность видима. Примечание: не важно видна ли для текущего игрока или находится ли в пределах экрана
	weapon - проверка текущего оружия. Параметр "<string>". Можно задать несколько наборов тегов
		Пример: {if weapon "mp35" "mp40" .. }
	weapon_place - оружие с конкретным названием находится в заданном place. Параметры: "<place_name:string>" "<place_type:string>"
		Пример: {if weapon_place "mgun2" "place_type" .. }
	weapon_skill - проверка уровня владения текущим оружием. Параметр "<skill_level:string>"
		Пример: {if weapon_skill "basic" .. }

-------------------------------------------------------------------------------

"state" - модификатор для иконки состояния юнита. Например: добавление текста или прогресс бара, изменение цвета или позиции иконки
Можно использовать модификаторы или действия при выполнении определенных условий
Например, отображать прогресс бар если сущность перезаряжается в данный момент
	{if ..
		{icon "shell_type/ap"}
		{if reloading
			{state "progress_bar:recharge"}
		}
	}

Общие параметры для всех модификаторов
	visibility_as_for_icon - <bool> - прозрачность как у иконки 
	priority - <int> - приоритет применения модификатора на иконку
	location - <Point2> - позиция
	offset - <Point2> - сдвиг относительно иконки. Можно использовать отрицательные значения
	align - <string> <string> - выравнивание теста. Доступные значения: "begin", "center", "end". Примечание: не использовать кавычки в блоке {align ..}

Основные параметры для модификатора "text"
	colors - массив из {"<key>" "<color>"}. Значение по умолчанию задается блоком {"normal" "<color>"}
	font_style - <string> - стиль шрифта. Поддерживаются все модификаторы шрифта, кроме размера s(..), потому что размер подбирается в реальном времени в зависимости от расстояния от камеры до юнита
	font_scale - <float> - масштабирование шрифта
	width_ratio - <float> - коэффициент ширины отведенный под текст, если размер превышает, то текст обрезается. По умолчанию значение 1.0
	shadow_text_size - <int> - размер тени для текста

Основные параметры для модификатора "progress_bar"
	vertical - <bool> - 
	size - <Point2> - размер прогресс бара
	clip_width - <int> - уменьшение ширины. Может использоваться в комбинации с {size -1 4} 

Основные параметры для модификатора "picture"
	size - <Point2> - размер спрайта

Доступные модификаторы:
	"color" - изменить цвет иконки. Параметры "background_color", "foreground_color"
		Пример:
		{state "color"
			{background_color 0xffffffff}
			{foreground_color 0xffffffff}
		}
	"color:human_damaged" - изменить цвет если солдат получил урон. Цвет красный и синий "установлены" в коде
		Пример: {state "color:human_damaged"}
	"count:house_empty_place" - для каждого пустого места в доме создается отдельная иконка
		Пример: {state "color:house_empty_place"}
	"picture:usual" - отображение дополнительного спрайта кроме фона и самой иконки (поверх них)
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
	"progress_bar:charge - прогресс действия "рывок"
	"progress_bar:house_fortification" - прогресс укрепления дома
	"progress_bar:human_vitality" - отображение жизни солдата
	"progress_bar:icon_event" - отображения времени определенного события
		Пример:
			{if icon_event "killed_by_sniper"
				{icon "headshot"}
				{duration 2.5}
			}
	"progress_bar:not_sensible" - время оглушения
	"progress_bar:recharge" - прогресс перезарядки оружия
	"progress_bar:repair" - прогресс ремонта
	"progress_bar:suppressed" - степень подавленности юнита
	"progress_bar:suspect" - степень "засвета" юнита
	"progress_bar:vehicle_armor" - отображение хп техники
	"text:actor_uid" - отображает uid актер-а
	"text:ammo_count" - кол-во боеприпасов. Формат текста:
		если возможно зарядить более 1 снаряда, то текст в виде "<in_holder>/<in_inventory>"
		если возможно зарядить не более 1 снаряда, то текст в виде "<in_inventory>"
	"text:ammo_type" - тип заряженного снаряда. Локализация берется по пути "desc/ammo/type/%1%"
		Пример:
			{state "text:ammo_type"
				{ammo_tag "fg"}
			}
	"text:cp_for_capture" - кол-во cp для захвата.
		Формат текста:
			if(cp_cost == 0) - текст отсутствует
			else if(cp_cost > 0 && player_cp >= cp_cost) - текст в виде "<cp_cost>"
			else if(cp_cost > 0 && player_cp < cp_cost) - текст в виде "<player_cp>/<cp_cost>"
		Дополнительный блок для цвета: {"not_enough_cp" "red"}
		Пример:
			{state "text:cp_for_capture"
				{color
					{"normal" "white"}
					{"not_enough_cp" "red"}
				}
			}
	"text:crew_info" - количество экипажа в технике
		Пример:
			{state "text:crew_info"
				{color
					{"normal" "white"}
					{"lss:1.0" "red"}; если заполненность техники экипажем менее заданного коэффициента, то установить цвет
				}
			}
	"text:free_place_count" - кол-во свободных мест в доме
		Пример:
			{state "text:free_place_count"}
	"text:place_idx" - отображение номера place-а
	"text:vehicle_armor" - отображение хп техники 
	"text:vehicle_mine_time_left" - отображение времени до взрыва заминированной техники
	"text:weapon_place_type" - тип установленного оружия. Локализация берется по пути "desc/weapon/type/abbreviation/%1%"
		Пример:
			{state "text:weapon_place_type"
				{place_name "%place_name"}
			}
