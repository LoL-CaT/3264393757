{listener 
	; look_at_offset - offset of the "ears" towards the point where the camera is looking: 1st argument for a "horizontal" camera, 2nd - for a "vertical" one
	; pitch_enabled - camera tilt taken into account
	; stereo_pan - {angle {left right}}
	; 		 angle - the angle between the listener's viewing direction in the 2d plane and the direction to the sound source; in the range 0.. 360 (0 - source front, 90 - right, 180 - rear, 270 - left)
	;		 left - left channel volume
	;		 right - right channel volume
	; lpf_from_pan - mute high frequencies behind the listener
	; sector - opening angle from the listener to the 3D sounds into which the stereo 3D sound is divided (60 degrees by default)

	{look_at_offset 0.0 0.0}
	{pitch_enabled}
	{stereo_pan
		{sector 60}
		{volumes
			{0 	{1 	1}}
			{90 	{0.2 	1}}
			{180 	{1 	1}}
			{270 	{1 	0.2}}
		}
	}
	{lpf_from_pan 0.4}

	; The HDR window is used to convert sounds from a wide range to the device range, where:
	; 	 wide range (dB) - the range of “virtual” game sounds
	;	 device range (dBFS) - the upper value corresponds to the maximum sound volume; every -6 dB the volume is halved
	; The window has its position in a wide range. It moves so that the loudest sound hits the upper border of the window
	; The sound above the window corresponds to the upper range of the device
	; The sound inside the window is converted to the range of the device
	; The sound below the window is not audible
	;
	; There are 3 instances of the window with general settings available. They work independently of each other. A sample can affect several windows, but can only be controlled by one. See sample parameter description and example (2)

	; Options:
	; 	 threshold - the initial position of the window (its upper border); the loudest sound moves the window up (dB)
	; 	 range - window size (dB)
	; 	 release_speed - speed of the window returning to its original position (full adaptation) (dB). The first argument of the table is the current position of the window.
	; 	 audibility a0 a1 - a0 attenuation at the beginning of the loss of *audibility, a1 - attenuation at the complete loss of audibility (dB)
	; 	 * audibility - mechanics to reduce the volume of enemy units in the fog of war
	{hdr "environment"
		{threshold 0}
		{range 40}
		{release
			{time 4}
			{curve 2}
		}
		{audibility 0 0}
	}

	{hdr "storm"
		{threshold 0}
		{range 40}
		{release
			{time 2}
			{curve 2}
		}
		{audibility 0 0}
	}
	
	{hdr "footstep"
		{threshold 0}
		{range 40}
		{release
			{time 2}
			{curve 2}
		}
		{audibility 0 0}
	}
	
	{hdr "default"
		{threshold 0}
		{range 40}
		{release
			{time 1}
			{curve 1}
		}
		{audibility 0 0}
	}

	; playback_limit - criteria that the sounds are the same and playback restrictions are triggered for them
	;	 angle - the difference in the horizontal component of the angle between the directions from the listener to the sound source
	;	 volume - difference in final volume
	;	 start_time_interval - the maximum allowable time difference (in seconds) between the launched sound; if the difference is smaller, the sound does not start
	{playback_limit
		{angle 33}
		{volume 0.25}
		{start_time_interval 0.066}
	}
	
	; suppress - suppresses the volume of the stage sound for the period of playing lines launched from missions
	; fade_out - time during which the stage sound returns to its original volume
	; volume - stage sound volume multiplier, which is applied for the period of cue playback	
	{suppress
		{fade_out 1.0}
		{volume 0.05}
	}
}