;SDL
	{skeleton
		{bone "climb1"
			{Matrix34
				0	1	0
				-1	0	0
				0	0	1
				-18.009	-21.0481	0
			}
			{visibility 0}
		}
		{bone "climb2"
			{Matrix34
				0	1	0
				-1	0	0
				0	0	1
				17.8658	-21.0481	0
			}
			{visibility 0}
		}
		{bone "climb3"
			{Matrix34
				0	-1	0
				1	0	0
				0	0	1
				-18.009	20.8778	0
			}
			{visibility 0}
		}
		{bone "climb4"
			{Matrix34
				0	-1	0
				1	0	0
				0	0	1
				17.8658	20.8778	0
			}
			{visibility 0}
		}
		{bone "socket0"
			{Matrix34
				-1	0	0
				0	1	0
				0	0	1
				-32	0	0
			}
			{visibility 0}
		}
		{bone "socket1"
			{Matrix34
				1	0	0
				0	1	0
				0	0	1
				32	0	0
			}
			{visibility 0}
		}
		{bone "socket2"
			{matrix34
				0 	 1 	 0
				-1 	 0 	 0
				0 	 0 	 1
				0 	 8 	 0
			}
			{visibility 0}
		}
		{bone "socket3"
			{matrix34
				0 	 -1 	 0
				1 	 0 	 0
				0 	 0 	 1
				0 	 -8 	 0
			}
			{visibility 0}
		}
	}
	{extender "fortification"
		{tag "sandbag"}
		{path_profile "sandbag"}
		{interval_min 4} ; do not install closest than <interval_min> to others fortifications
		{install_time 5}	                        	; время установки в секундах
		{install_pose "normal"}	
		{socket "socket0" 	; bone name
			{accept "%name"}
			{angle 90}
		}
		{socket "socket1" 	; bone name
			{accept "%name"}
			{angle 90}
		}
		{socket "socket2"}
		{socket "socket3"}
	}
