{mission
	{Clips
		{"[auto]"
			{world -5009.53 -5009.53 5010.47 5010.47}
			{camera -5009.53 -5009.53 5010.47 5010.47}
			{pather -5009.53 -5009.53 5010.47 5010.47}
			{haze -5509.53 -5509.53 5510.47 5510.47}
		}
	}
	{Helpers
		{event "action_music"}
		{reinforcements
			{scoreTotal 0}
			{scoreCurrent 0}
		}
		{triggers
			{"music/action"
				{condition
					{terms
						{"1.event"
							{id "action_music"}
						}
					}
				}
				{actions
					{"switch"
						{"case"
							{condition
								{type rand}
								{value 0.0666}
							}
							{"music"
								{start "/music/bpo_battle1_prefinal.ogg"}
								{stop_all}
								{volume game}
								{fade 3}
							}
							{"delay"
								{time 124}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.0714}
							}
							{"music"
								{start "/music/battle6.ogg"}
								{stop_all}
								{volume game}
								{fade 3}
							}
							{"delay"
								{time 140}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.0769}
							}
							{"music"
								{start "/music/battle5.ogg"}
								{stop_all}
								{volume game}
								{fade 3}
							}
							{"delay"
								{time 130}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.0833}
							}
							{"music"
								{start "/music/battle4.ogg"}
								{stop_all}
								{volume game}
								{fade 3}
							}
							{"delay"
								{time 143}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.0909}
							}
							{"music"
								{start "/music/battle1.ogg"}
								{stop_all}
								{volume game}
								{fade 3}
							}
							{"delay"
								{time 124}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.1}
							}
							{"music"
								{start "/music/danger02_addon.ogg"}
								{stop_all}
								{volume game}
								{fade 3}
							}
							{"delay"
								{time 96}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.111111}
							}
							{"music"
								{start "/music/Battle04_Addon.ogg"}
								{stop_all}
								{volume game}
								{fade 3}
							}
							{"delay"
								{time 109}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.125}
							}
							{"music"
								{start "/music/battle02_addon.ogg"}
								{stop_all}
								{volume game}
								{fade 3}
							}
							{"delay"
								{time 121}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.1428}
							}
							{"music"
								{start "/music/battle2.ogg"}
								{stop_all}
								{volume game}
								{fade 3}
							}
							{"delay"
								{time 131}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.1666}
							}
							{"music"
								{start "/music/bpo_battle3_prefinal.ogg"}
								{stop_all}
								{volume game}
								{fade 3}
							}
							{"delay"
								{time 133}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.2}
							}
							{"music"
								{start "/music/battle3.ogg"}
								{stop_all}
								{volume game}
								{fade 3}
							}
							{"delay"
								{time 155}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.25}
							}
							{"music"
								{start "/music/bpo_battle2.ogg"}
								{stop_all}
								{volume game}
								{fade 3}
							}
							{"delay"
								{time 160}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.33}
							}
							{"music"
								{start "/music/battle01_addon.ogg"}
								{stop_all}
								{volume game}
								{fade 3}
							}
							{"delay"
								{time 199}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.5}
							}
							{"music"
								{start "/music/main_theme2.ogg"}
								{stop_all}
								{volume game}
								{fade 3}
							}
							{"delay"
								{time 269}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 1}
							}
							{"music"
								{start "/music/Battle03_Addon.ogg"}
								{stop_all}
								{volume game}
								{fade 3}
							}
							{"delay"
								{time 199}
							}
						}
					}
					{"trigger"
						{name "music/action"}
					}
				}
			}
			{"music/start"
				{condition
					{expression "1 & !2"}
					{terms
						{"1.event"
							{id "start_true"}
						}
						{"2.event"
							{id "action_music"}
						}
					}
				}
				{actions
					{"switch"
						{"case"
							{condition
								{type rand}
								{value 0.1}
							}
							{"music"
								{start "/music/theme4.ogg"}
								{stop_all}
								{volume game}
								{fade 3}
							}
							{"delay"
								{time 183}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.11111}
							}
							{"music"
								{start "/music/theme3.ogg"}
								{stop_all}
								{volume game}
								{fade 3}
							}
							{"delay"
								{time 208}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.125}
							}
							{"music"
								{start "/music/stealth3.ogg"}
								{stop_all}
								{volume game}
								{fade 3}
							}
							{"delay"
								{time 114}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.1428}
							}
							{"music"
								{start "/music/bpo_theme3.ogg"}
								{stop_all}
								{volume game}
								{fade 3}
							}
							{"delay"
								{time 157}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.1666}
							}
							{"music"
								{start "/music/theme5.ogg"}
								{stop_all}
								{volume game}
								{fade 3}
							}
							{"delay"
								{time 205}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.2}
							}
							{"music"
								{start "/music/theme2.ogg"}
								{stop_all}
								{volume game}
								{fade 3}
							}
							{"delay"
								{time 198}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.25}
							}
							{"music"
								{start "/music/mow_stealth_theme3.ogg"}
								{stop_all}
								{volume game}
								{fade 3}
							}
							{"delay"
								{time 177}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.33}
							}
							{"music"
								{start "/music/stealth1.ogg"}
								{stop_all}
								{volume game}
								{fade 3}
							}
							{"delay"
								{time 157}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.5}
							}
							{"music"
								{start "/music/danger01_addon.ogg"}
								{stop_all}
								{volume game}
								{fade 3}
							}
							{"delay"
								{time 122}
							}
						}
						{"case"
							{condition
								{type rand}
								{value 1}
							}
							{"music"
								{start "/music/bpo_theme1.ogg"}
								{stop_all}
								{volume game}
								{fade 3}
							}
							{"delay"
								{time 137}
							}
						}
					}
					{"event"
						{event "action_music"}
						{mode set}
						{delay 0}
					}
					{"trigger"
						{name "music/start"}
					}
				}
			}
			{## "music/event/action"
				{disabled}
				{condition
					{terms
						{"1.signal"
							{zone "allmap"}
							{signals shot}
						}
					}
				}
				{actions
					{"event"
						{event "action_music"}
						{mode set}
						{delay 0}
					}
				}
			}
		}
	}
}
