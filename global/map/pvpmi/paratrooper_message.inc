{mission
	{Helpers
		{reinforcements
			{scoreTotal 0}
			{scoreCurrent 0}
		}
		{triggers
			{"+notifications/hq/paratroopers/a"
				{condition
					{expression "1 & !2"}
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag need_promotion}
										}
									}
									{include
										{team
											{team b}
										}
									}
									{exclude
										{state
											{state inactive}
										}
									}
								}
							}
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
						{text "$/ground_control/talks/radio/paratroopers_income"}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag need_promotion}
									}
								}
								{include
									{team
										{team b}
									}
								}
								{exclude
									{state
										{state inactive}
									}
								}
							}
							{amount 1
							}
						}
						{tag_remove need_promotion}
					}
					{"delay"
						{time 3}
					}
					{"event"
						{event "conversations/dialog_event_a"}
						{mode reset}
						{delay 0}
					}
					{"trigger"
						{name "+notifications/hq/paratroopers/a"}
					}
				}
			}
			{"+notifications/hq/paratroopers/b"
				{condition
					{expression "1 & !2"}
					{terms
						{"1.entities"
							{selector
								{source advanced}
								{group
									{select
										{tag
											{tag need_promotion}
										}
									}
									{include
										{team
											{team a}
										}
									}
									{exclude
										{state
											{state inactive}
										}
									}
								}
							}
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
						{text "$/ground_control/talks/radio/paratroopers_income"}
					}
					{"entity_state"
						{selector
							{source advanced}
							{group
								{select
									{tag
										{tag need_promotion}
									}
								}
								{include
									{team
										{team a}
									}
								}
								{exclude
									{state
										{state inactive}
									}
								}
							}
							{amount 1
							}
						}
						{tag_remove need_promotion}
					}
					{"delay"
						{time 3}
					}
					{"event"
						{event "conversations/dialog_event_b"}
						{mode reset}
						{delay 0}
					}
					{"trigger"
						{name "+notifications/hq/paratroopers/b"}
					}
				}
			}
		}
	}
}
