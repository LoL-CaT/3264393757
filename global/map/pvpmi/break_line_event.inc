{mission
	{Entity "pointer_placer" 0x8004
		{Position -120.27 0.79}
	}
	{Entity "pointer_placer" 0x8005
		{Position -59.81 1.03}
	}
	{Entity "pointer_placer" 0x8006
		{Position 60.62 1.45}
	}
	{Entity "pointer_placer" 0x8007
		{Position 120.08 2.91}
	}
	{Tags "break_line_a_1_pointer" 0x8004}
	{Tags "break_line_a_2_pointer" 0x8005}
	{Tags "break_line_b_1_pointer" 0x8006}
	{Tags "break_line_b_2_pointer" 0x8007}
	{Helpers
		{event "conversations/break_line_event/charge_a_1"}
		{event "conversations/break_line_event/charge_a_2"}
		{event "conversations/break_line_event/charge_b_1"}
		{event "conversations/break_line_event/charge_b_2"}
		{event "conversations/break_line_event/defend_a_1"}
		{event "conversations/break_line_event/defend_a_2"}
		{event "conversations/break_line_event/defend_b_1"}
		{event "conversations/break_line_event/defend_b_2"}
		{event "conversations/break_line_event/prepare_a_1"}
		{event "conversations/break_line_event/prepare_a_2"}
		{event "conversations/break_line_event/prepare_b_1"}
		{event "conversations/break_line_event/prepare_b_2"}
		{event "conversations/dialog_event_a"}
		{event "conversations/dialog_event_b"}
		{event "start_true"}
		{event "tasks/break_line/show/a1"}
		{event "tasks/break_line/show/a2"}
		{event "tasks/break_line/show/b1"}
		{event "tasks/break_line/show/b2"}
		{tasks
			{"break_line_a_1"
				{desc "$/ground_control/tasks/break_line"}
				{state hidden}
				{point break_line_a_1_pointer}
				{team a}
			}
			{"break_line_a_2"
				{desc "$/ground_control/tasks/break_line"}
				{state hidden}
				{point break_line_a_2_pointer}
				{team a}
			}
			{"break_line_b_1"
				{desc "$/ground_control/tasks/break_line"}
				{state hidden}
				{point break_line_b_1_pointer}
				{team b}
			}
			{"break_line_b_2"
				{desc "$/ground_control/tasks/break_line"}
				{state hidden}
				{point break_line_b_2_pointer}
				{team b}
			}
		}
		{reinforcements
			{scoreTotal 0}
			{scoreCurrent 0}
		}
		{triggers
			{"game_events/break_line/phase1_timeline"
				{condition
					{terms
						{"1.event"
							{id "start_true"}
						}
					}
				}
				{actions
					{"delay"
						{time 40}
					}
					{"switch"
						{"case"
							{condition
								{type rand}
								{value 0.5}
							}
							{"delay"
								{time 30 10}
							}
							{"mp_event"
								{event frontline_break}
								{team b}
								{param "60,180"}
							}
							{"event"
								{event "conversations/break_line_event/prepare_b_1"}
								{mode set}
								{delay 0}
							}
							{"delay"
								{time 60}
							}
							{"event"
								{event "conversations/break_line_event/charge_b_1"}
								{mode set}
								{delay 0}
							}
							{"event"
								{event "tasks/break_line/show/b1"}
								{mode set}
								{delay 0}
							}
							{"delay"
								{time 120}
							}
							{"event"
								{event "conversations/break_line_event/defend_b_1"}
								{mode set}
								{delay 0}
							}
							{"delay"
								{time 20 20}
							}
							{"mp_event"
								{event frontline_break}
								{team a}
								{param "60,180"}
							}
							{"event"
								{event "conversations/break_line_event/prepare_a_1"}
								{mode set}
								{delay 0}
							}
							{"delay"
								{time 60}
							}
							{"event"
								{event "conversations/break_line_event/charge_a_1"}
								{mode set}
								{delay 0}
							}
							{"event"
								{event "tasks/break_line/show/a1"}
								{mode set}
								{delay 0}
							}
							{"delay"
								{time 120}
							}
							{"event"
								{event "conversations/break_line_event/defend_a_1"}
								{mode set}
								{delay 0}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 1}
							}
							{"delay"
								{time 20 20}
							}
							{"mp_event"
								{event frontline_break}
								{team a}
								{param "60,180"}
							}
							{"event"
								{event "conversations/break_line_event/prepare_a_1"}
								{mode set}
								{delay 0}
							}
							{"delay"
								{time 60}
							}
							{"event"
								{event "conversations/break_line_event/charge_a_1"}
								{mode set}
								{delay 0}
							}
							{"event"
								{event "tasks/break_line/show/a1"}
								{mode set}
								{delay 0}
							}
							{"delay"
								{time 120}
							}
							{"event"
								{event "conversations/break_line_event/defend_a_1"}
								{mode set}
								{delay 0}
							}
							{"delay"
								{time 30 10}
							}
							{"mp_event"
								{event frontline_break}
								{team b}
								{param "60,180"}
							}
							{"event"
								{event "conversations/break_line_event/prepare_b_1"}
								{mode set}
								{delay 0}
							}
							{"delay"
								{time 60}
							}
							{"event"
								{event "conversations/break_line_event/charge_b_1"}
								{mode set}
								{delay 0}
							}
							{"event"
								{event "tasks/break_line/show/b1"}
								{mode set}
								{delay 0}
							}
							{"delay"
								{time 120}
							}
							{"event"
								{event "conversations/break_line_event/defend_b_1"}
								{mode set}
								{delay 0}
							}
						}
					}
				}
			}
			{"game_events/break_line/phase2_timeline"
				{condition
					{terms
						{"1.event"
							{id "start_true"}
						}
					}
				}
				{actions
					{"delay"
						{time 500}
					}
					{"switch"
						{"case"
							{condition
								{type rand}
								{value 0.5}
							}
							{"delay"
								{time 30 10}
							}
							{"mp_event"
								{event frontline_break}
								{team b}
								{param "60,180"}
							}
							{"event"
								{event "conversations/break_line_event/prepare_b_2"}
								{mode set}
								{delay 0}
							}
							{"delay"
								{time 60}
							}
							{"event"
								{event "conversations/break_line_event/charge_b_2"}
								{mode set}
								{delay 0}
							}
							{"event"
								{event "tasks/break_line/show/b2"}
								{mode set}
								{delay 0}
							}
							{"delay"
								{time 120}
							}
							{"event"
								{event "conversations/break_line_event/defend_b_2"}
								{mode set}
								{delay 0}
							}
							{"delay"
								{time 20 20}
							}
							{"mp_event"
								{event frontline_break}
								{team a}
								{param "60,180"}
							}
							{"event"
								{event "conversations/break_line_event/prepare_a_2"}
								{mode set}
								{delay 0}
							}
							{"delay"
								{time 60}
							}
							{"event"
								{event "conversations/break_line_event/charge_a_2"}
								{mode set}
								{delay 0}
							}
							{"event"
								{event "tasks/break_line/show/a2"}
								{mode set}
								{delay 0}
							}
							{"delay"
								{time 120}
							}
							{"event"
								{event "conversations/break_line_event/defend_a_2"}
								{mode set}
								{delay 0}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 1}
							}
							{"delay"
								{time 20 20}
							}
							{"mp_event"
								{event frontline_break}
								{team a}
								{param "60,180"}
							}
							{"event"
								{event "conversations/break_line_event/prepare_a_2"}
								{mode set}
								{delay 0}
							}
							{"delay"
								{time 60}
							}
							{"event"
								{event "conversations/break_line_event/charge_a_2"}
								{mode set}
								{delay 0}
							}
							{"event"
								{event "tasks/break_line/show/a2"}
								{mode set}
								{delay 0}
							}
							{"delay"
								{time 120}
							}
							{"event"
								{event "conversations/break_line_event/defend_a_2"}
								{mode set}
								{delay 0}
							}
							{"delay"
								{time 30 10}
							}
							{"mp_event"
								{event frontline_break}
								{team b}
								{param "60,180"}
							}
							{"event"
								{event "conversations/break_line_event/prepare_b_2"}
								{mode set}
								{delay 0}
							}
							{"delay"
								{time 60}
							}
							{"event"
								{event "conversations/break_line_event/charge_b_2"}
								{mode set}
								{delay 0}
							}
							{"event"
								{event "tasks/break_line/show/b2"}
								{mode set}
								{delay 0}
							}
							{"delay"
								{time 120}
							}
							{"event"
								{event "conversations/break_line_event/defend_b_2"}
								{mode set}
								{delay 0}
							}
						}
					}
				}
			}
			{"game_events/break_line/conversations/a/prepare1"
				{condition
					{expression "1 & !2"}
					{terms
						{"1.event"
							{id "conversations/break_line_event/prepare_a_1"}
						}
						{"2.event"
							{id "conversations/dialog_event_a"}
						}
					}
				}
				{actions
					{"event"
						{event "conversations/dialog_event_a"}
						{mode set}
						{delay 0}
					}
					{"talk"
						{selector
							{amount 1
							}
							{tag radio_a}
						}
						{text_target team_a}
						{text "$/ground_control/talks/radio/prepare_to_attack"}
					}
					{"delay"
						{time 5}
					}
					{"event"
						{event "conversations/dialog_event_a"}
						{mode reset}
						{delay 0}
					}
				}
			}
			{"game_events/break_line/conversations/a/prepare2"
				{condition
					{expression "1 & !2"}
					{terms
						{"1.event"
							{id "conversations/break_line_event/prepare_a_2"}
						}
						{"2.event"
							{id "conversations/dialog_event_a"}
						}
					}
				}
				{actions
					{"event"
						{event "conversations/dialog_event_a"}
						{mode set}
						{delay 0}
					}
					{"talk"
						{selector
							{amount 1
							}
							{tag radio_a}
						}
						{text_target team_a}
						{text "$/ground_control/talks/radio/prepare_to_attack"}
					}
					{"delay"
						{time 5}
					}
					{"event"
						{event "conversations/dialog_event_a"}
						{mode reset}
						{delay 0}
					}
				}
			}
			{"game_events/break_line/conversations/b/prepare1"
				{condition
					{expression "1 & !2"}
					{terms
						{"1.event"
							{id "conversations/break_line_event/prepare_b_1"}
						}
						{"2.event"
							{id "conversations/dialog_event_b"}
						}
					}
				}
				{actions
					{"event"
						{event "conversations/dialog_event_b"}
						{mode set}
						{delay 0}
					}
					{"talk"
						{selector
							{amount 1
							}
							{tag radio_b}
						}
						{text_target team_b}
						{text "$/ground_control/talks/radio/prepare_to_attack"}
					}
					{"delay"
						{time 5}
					}
					{"event"
						{event "conversations/dialog_event_b"}
						{mode reset}
						{delay 0}
					}
				}
			}
			{"game_events/break_line/conversations/b/prepare2"
				{condition
					{expression "1 & !2"}
					{terms
						{"1.event"
							{id "conversations/break_line_event/prepare_b_2"}
						}
						{"2.event"
							{id "conversations/dialog_event_b"}
						}
					}
				}
				{actions
					{"event"
						{event "conversations/dialog_event_b"}
						{mode set}
						{delay 0}
					}
					{"talk"
						{selector
							{amount 1
							}
							{tag radio_b}
						}
						{text_target team_b}
						{text "$/ground_control/talks/radio/prepare_to_attack"}
					}
					{"delay"
						{time 5}
					}
					{"event"
						{event "conversations/dialog_event_b"}
						{mode reset}
						{delay 0}
					}
				}
			}
			{"game_events/break_line/tasks/break_line/a1/shown"
				{condition
					{terms
						{"1.event"
							{id "start_true"}
						}
						{"2.event"
							{id "tasks/break_line/show/a1"}
						}
					}
				}
				{actions
					{"delay"
						{time 1}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag frontline_break}
									}
								}
							}
						}
						{tag_add break_line_a_1}
					}
					{"task"
						{name "break_line_a_1"}
					}
				}
			}
			{"game_events/break_line/conversations/a/charge1"
				{condition
					{expression "1 & !2"}
					{terms
						{"1.event"
							{id "conversations/break_line_event/charge_a_1"}
						}
						{"2.event"
							{id "conversations/dialog_event_a"}
						}
					}
				}
				{actions
					{"event"
						{event "conversations/dialog_event_a"}
						{mode set}
						{delay 0}
					}
					{"talk"
						{selector
							{amount 1
							}
							{tag radio_a}
						}
						{text_target team_a}
						{text "$/ground_control/talks/radio/attack_marked_positions"}
					}
					{"delay"
						{time 5}
					}
					{"event"
						{event "conversations/dialog_event_a"}
						{mode reset}
						{delay 0}
					}
				}
			}
			{"game_events/break_line/conversations/a/charge2"
				{condition
					{expression "1 & !2"}
					{terms
						{"1.event"
							{id "conversations/break_line_event/charge_a_2"}
						}
						{"2.event"
							{id "conversations/dialog_event_a"}
						}
					}
				}
				{actions
					{"event"
						{event "conversations/dialog_event_a"}
						{mode set}
						{delay 0}
					}
					{"talk"
						{selector
							{amount 1
							}
							{tag radio_a}
						}
						{text_target team_a}
						{text "$/ground_control/talks/radio/attack_marked_positions"}
					}
					{"delay"
						{time 5}
					}
					{"event"
						{event "conversations/dialog_event_a"}
						{mode reset}
						{delay 0}
					}
				}
			}
			{"game_events/break_line/conversations/b/charge1"
				{condition
					{expression "1 & !2"}
					{terms
						{"1.event"
							{id "conversations/break_line_event/charge_b_1"}
						}
						{"2.event"
							{id "conversations/dialog_event_b"}
						}
					}
				}
				{actions
					{"event"
						{event "conversations/dialog_event_b"}
						{mode set}
						{delay 0}
					}
					{"talk"
						{selector
							{amount 1
							}
							{tag radio_b}
						}
						{text_target team_b}
						{text "$/ground_control/talks/radio/attack_marked_positions"}
					}
					{"delay"
						{time 5}
					}
					{"event"
						{event "conversations/dialog_event_b"}
						{mode reset}
						{delay 0}
					}
				}
			}
			{"game_events/break_line/conversations/b/charge2"
				{condition
					{expression "1 & !2"}
					{terms
						{"1.event"
							{id "conversations/break_line_event/charge_b_2"}
						}
						{"2.event"
							{id "conversations/dialog_event_b"}
						}
					}
				}
				{actions
					{"event"
						{event "conversations/dialog_event_b"}
						{mode set}
						{delay 0}
					}
					{"talk"
						{selector
							{amount 1
							}
							{tag radio_b}
						}
						{text_target team_b}
						{text "$/ground_control/talks/radio/attack_marked_positions"}
					}
					{"delay"
						{time 5}
					}
					{"event"
						{event "conversations/dialog_event_b"}
						{mode reset}
						{delay 0}
					}
				}
			}
			{"game_events/break_line/conversations/a/defend1"
				{condition
					{expression "1 & !2"}
					{terms
						{"1.event"
							{id "conversations/break_line_event/defend_a_1"}
						}
						{"2.event"
							{id "conversations/dialog_event_a"}
						}
					}
				}
				{actions
					{"event"
						{event "conversations/dialog_event_a"}
						{mode set}
						{delay 0}
					}
					{"talk"
						{selector
							{amount 1
							}
							{tag radio_a}
						}
						{text_target team_a}
						{text "$/ground_control/talks/radio/time_to_defend"}
					}
					{"delay"
						{time 5}
					}
					{"event"
						{event "conversations/dialog_event_a"}
						{mode reset}
						{delay 0}
					}
				}
			}
			{"game_events/break_line/tasks/break_line/a1/complete"
				{condition
					{terms
						{"1.task"
							{name "break_line_a_1"}
							{state shown}
						}
						{"2.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag break_line_a_1}
										}
									}
									{include
										{territory_team
											{team a}
										}
									}
									{exclude
										{territory_surrounded
											{team a}
										}
									}
								}
							}
						}
					}
				}
				{actions
					{"task"
						{name "break_line_a_1"}
						{state complete}
					}
					{"mp_score"
						{amount 200}
						{team a}
					}
					{"delete"
						{selector
							{tag break_line_a_1}
						}
					}
					{"mp_event"
						{event frontline_break_stop}
						{team a}
					}
				}
			}
			{"game_events/break_line/tasks/break_line/a1/fail"
				{condition
					{expression "1 & !2 & 3"}
					{terms
						{"1.task"
							{name "break_line_a_1"}
							{state shown}
						}
						{"2.task"
							{name "break_line_a_1"}
						}
						{"3.entities"
							{selector
								{tag frontline_break}
							}
							{count
								{op "=="}
								{value 0}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 1}
					}
					{"task"
						{name "break_line_a_1"}
						{state fail}
					}
				}
			}
			{"game_events/break_line/tasks/break_line/a2/shown"
				{condition
					{terms
						{"1.event"
							{id "start_true"}
						}
						{"2.event"
							{id "tasks/break_line/show/a2"}
						}
					}
				}
				{actions
					{"delay"
						{time 1}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag frontline_break}
									}
								}
							}
						}
						{tag_add break_line_a_2}
					}
					{"task"
						{name "break_line_a_2"}
					}
				}
			}
			{"game_events/break_line/tasks/break_line/b1/shown"
				{condition
					{terms
						{"1.event"
							{id "start_true"}
						}
						{"2.event"
							{id "tasks/break_line/show/b1"}
						}
					}
				}
				{actions
					{"delay"
						{time 1}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag frontline_break}
									}
								}
							}
						}
						{tag_add break_line_b_1}
					}
					{"task"
						{name "break_line_b_1"}
					}
				}
			}
			{"game_events/break_line/tasks/break_line/b2/shown"
				{condition
					{terms
						{"1.event"
							{id "start_true"}
						}
						{"2.event"
							{id "tasks/break_line/show/b2"}
						}
					}
				}
				{actions
					{"delay"
						{time 1}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag frontline_break}
									}
								}
							}
						}
						{tag_add break_line_b_2}
					}
					{"task"
						{name "break_line_b_2"}
					}
				}
			}
			{"game_events/break_line/tasks/break_line/a2/complete"
				{condition
					{terms
						{"1.task"
							{name "break_line_a_2"}
							{state shown}
						}
						{"2.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag break_line_a_2}
										}
									}
									{include
										{territory_team
											{team a}
										}
									}
									{exclude
										{territory_surrounded
											{team a}
										}
									}
								}
							}
						}
					}
				}
				{actions
					{"task"
						{name "break_line_a_2"}
						{state complete}
					}
					{"mp_score"
						{amount 200}
						{team a}
					}
					{"delete"
						{selector
							{tag break_line_a_2}
						}
					}
					{"mp_event"
						{event frontline_break_stop}
						{team a}
					}
				}
			}
			{"game_events/break_line/tasks/break_line/b1/complete"
				{condition
					{terms
						{"1.task"
							{name "break_line_b_1"}
							{state shown}
						}
						{"2.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag break_line_b_1}
										}
									}
									{include
										{territory_team
											{team b}
										}
									}
									{exclude
										{territory_surrounded
											{team b}
										}
									}
								}
							}
						}
					}
				}
				{actions
					{"task"
						{name "break_line_b_1"}
						{state complete}
					}
					{"mp_score"
						{amount 200}
						{team b}
					}
					{"delete"
						{selector
							{tag break_line_b_1}
						}
					}
					{"mp_event"
						{event frontline_break_stop}
						{team b}
					}
				}
			}
			{"game_events/break_line/tasks/break_line/b2/complete"
				{condition
					{terms
						{"1.task"
							{name "break_line_b_2"}
							{state shown}
						}
						{"2.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag break_line_b_2}
										}
									}
									{include
										{territory_team
											{team b}
										}
									}
									{exclude
										{territory_surrounded
											{team b}
										}
									}
								}
							}
						}
					}
				}
				{actions
					{"task"
						{name "break_line_b_2"}
						{state complete}
					}
					{"mp_score"
						{amount 200}
						{team b}
					}
					{"delete"
						{selector
							{tag break_line_b_2}
						}
					}
					{"mp_event"
						{event frontline_break_stop}
						{team b}
					}
				}
			}
			{"game_events/break_line/tasks/break_line/a2/fail"
				{condition
					{expression "1 & !2 & 3"}
					{terms
						{"1.task"
							{name "break_line_a_2"}
							{state shown}
						}
						{"2.task"
							{name "break_line_a_2"}
						}
						{"3.entities"
							{selector
								{tag frontline_break}
							}
							{count
								{op "=="}
								{value 0}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 1}
					}
					{"task"
						{name "break_line_a_2"}
						{state fail}
					}
				}
			}
			{"game_events/break_line/tasks/break_line/b1/fail"
				{condition
					{expression "1 & !2 & 3"}
					{terms
						{"1.task"
							{name "break_line_b_1"}
							{state shown}
						}
						{"2.task"
							{name "break_line_b_1"}
						}
						{"3.entities"
							{selector
								{tag frontline_break}
							}
							{count
								{op "=="}
								{value 0}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 1}
					}
					{"task"
						{name "break_line_b_1"}
						{state fail}
					}
				}
			}
			{"game_events/break_line/tasks/break_line/b2/fail"
				{condition
					{expression "1 & !2 & 3"}
					{terms
						{"1.task"
							{name "break_line_b_2"}
							{state shown}
						}
						{"2.task"
							{name "break_line_b_2"}
						}
						{"3.entities"
							{selector
								{tag frontline_break}
							}
							{count
								{op "=="}
								{value 0}
							}
						}
					}
				}
				{actions
					{"delay"
						{time 1}
					}
					{"task"
						{name "break_line_b_2"}
						{state fail}
					}
				}
			}
			{"game_events/break_line/tasks/break_line/pointers/a1"
				{condition
					{terms
						{"1.task"
							{name "break_line_a_1"}
							{state shown}
						}
					}
				}
				{actions
					{"placement"
						{selector
							{tag break_line_a_1_pointer}
						}
						{target
							{tag frontline_break}
						}
					}
				}
			}
			{"game_events/break_line/tasks/break_line/pointers/a2"
				{condition
					{terms
						{"1.task"
							{name "break_line_a_2"}
							{state shown}
						}
					}
				}
				{actions
					{"placement"
						{selector
							{tag break_line_a_2_pointer}
						}
						{target
							{tag frontline_break}
						}
					}
				}
			}
			{"game_events/break_line/tasks/break_line/pointers/b1"
				{condition
					{terms
						{"1.task"
							{name "break_line_b_1"}
							{state shown}
						}
					}
				}
				{actions
					{"placement"
						{selector
							{tag break_line_b_1_pointer}
						}
						{target
							{tag frontline_break}
						}
					}
				}
			}
			{"game_events/break_line/tasks/break_line/pointers/b2"
				{condition
					{terms
						{"1.task"
							{name "break_line_b_2"}
							{state shown}
						}
					}
				}
				{actions
					{"placement"
						{selector
							{tag break_line_b_2_pointer}
						}
						{target
							{tag frontline_break}
						}
					}
				}
			}
			{"game_events/break_line/conversations/a/complete1"
				{condition
					{expression "1 & !2"}
					{terms
						{"1.task"
							{name "break_line_a_1"}
						}
						{"2.event"
							{id "conversations/dialog_event_a"}
						}
					}
				}
				{actions
					{"event"
						{event "conversations/dialog_event_a"}
						{mode set}
						{delay 0}
					}
					{"talk"
						{selector
							{amount 1
							}
							{tag radio_a}
						}
						{text_target team_a}
						{text "$/ground_control/talks/radio/charge_complete"}
					}
					{"delay"
						{time 5}
					}
					{"event"
						{event "conversations/dialog_event_a"}
						{mode reset}
						{delay 0}
					}
				}
			}
			{"game_events/break_line/conversations/a/complete2"
				{condition
					{expression "1 & !2"}
					{terms
						{"1.task"
							{name "break_line_a_2"}
						}
						{"2.event"
							{id "conversations/dialog_event_a"}
						}
					}
				}
				{actions
					{"event"
						{event "conversations/dialog_event_a"}
						{mode set}
						{delay 0}
					}
					{"talk"
						{selector
							{amount 1
							}
							{tag radio_a}
						}
						{text_target team_a}
						{text "$/ground_control/talks/radio/charge_complete"}
					}
					{"delay"
						{time 5}
					}
					{"event"
						{event "conversations/dialog_event_a"}
						{mode reset}
						{delay 0}
					}
				}
			}
			{"game_events/break_line/conversations/b/complete1"
				{condition
					{expression "1 & !2"}
					{terms
						{"1.task"
							{name "break_line_b_1"}
						}
						{"2.event"
							{id "conversations/dialog_event_b"}
						}
					}
				}
				{actions
					{"event"
						{event "conversations/dialog_event_b"}
						{mode set}
						{delay 0}
					}
					{"talk"
						{selector
							{amount 1
							}
							{tag radio_b}
						}
						{text_target team_b}
						{text "$/ground_control/talks/radio/charge_complete"}
					}
					{"delay"
						{time 5}
					}
					{"event"
						{event "conversations/dialog_event_b"}
						{mode reset}
						{delay 0}
					}
				}
			}
			{"game_events/break_line/conversations/b/complete2"
				{condition
					{expression "1 & !2"}
					{terms
						{"1.task"
							{name "break_line_b_2"}
						}
						{"2.event"
							{id "conversations/dialog_event_b"}
						}
					}
				}
				{actions
					{"event"
						{event "conversations/dialog_event_b"}
						{mode set}
						{delay 0}
					}
					{"talk"
						{selector
							{amount 1
							}
							{tag radio_b}
						}
						{text_target team_b}
						{text "$/ground_control/talks/radio/charge_complete"}
					}
					{"delay"
						{time 5}
					}
					{"event"
						{event "conversations/dialog_event_b"}
						{mode reset}
						{delay 0}
					}
				}
			}
			{"game_events/break_line/conversations/a/defend2"
				{condition
					{expression "1 & !2"}
					{terms
						{"1.event"
							{id "conversations/break_line_event/defend_a_2"}
						}
						{"2.event"
							{id "conversations/dialog_event_a"}
						}
					}
				}
				{actions
					{"event"
						{event "conversations/dialog_event_a"}
						{mode set}
						{delay 0}
					}
					{"talk"
						{selector
							{amount 1
							}
							{tag radio_a}
						}
						{text_target team_a}
						{text "$/ground_control/talks/radio/time_to_defend"}
					}
					{"delay"
						{time 5}
					}
					{"event"
						{event "conversations/dialog_event_a"}
						{mode reset}
						{delay 0}
					}
				}
			}
			{"game_events/break_line/conversations/b/defend1"
				{condition
					{expression "1 & !2"}
					{terms
						{"1.event"
							{id "conversations/break_line_event/defend_b_1"}
						}
						{"2.event"
							{id "conversations/dialog_event_b"}
						}
					}
				}
				{actions
					{"event"
						{event "conversations/dialog_event_b"}
						{mode set}
						{delay 0}
					}
					{"talk"
						{selector
							{amount 1
							}
							{tag radio_b}
						}
						{text_target team_b}
						{text "$/ground_control/talks/radio/time_to_defend"}
					}
					{"delay"
						{time 5}
					}
					{"event"
						{event "conversations/dialog_event_b"}
						{mode reset}
						{delay 0}
					}
				}
			}
			{"game_events/break_line/conversations/b/defend2"
				{condition
					{expression "1 & !2"}
					{terms
						{"1.event"
							{id "conversations/break_line_event/defend_b_2"}
						}
						{"2.event"
							{id "conversations/dialog_event_b"}
						}
					}
				}
				{actions
					{"event"
						{event "conversations/dialog_event_b"}
						{mode set}
						{delay 0}
					}
					{"talk"
						{selector
							{amount 1
							}
							{tag radio_b}
						}
						{text_target team_b}
						{text "$/ground_control/talks/radio/time_to_defend"}
					}
					{"delay"
						{time 5}
					}
					{"event"
						{event "conversations/dialog_event_b"}
						{mode reset}
						{delay 0}
					}
				}
			}
		}
	}
}
