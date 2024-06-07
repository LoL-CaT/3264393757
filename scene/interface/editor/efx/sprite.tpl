{block "channel"
	{param "value" blockinfo optional RandomParameter {default 1}}
	{block "linear" optional casegroup
		{param "min" prefer RandomParameter {default 0}}
		{param "max" prefer RandomParameter {default 1}}
	}
	{block "peak" optional casegroup
		{param "min" prefer RandomParameter {default 0}}
		{param "max" prefer RandomParameter {default 1}}
	}
	{block "power" optional casegroup
		{param "min" prefer RandomParameter {default 0}}
		{param "max" prefer RandomParameter {default 1}}
		{param "pow" prefer RandomParameter {default 1}}
	}
	{block "npower" optional casegroup
		{param "min" prefer RandomParameter {default 0}}
		{param "max" prefer RandomParameter {default 1}}
		{param "pow" prefer RandomParameter {default 1}}
	}
}

{block "sprite"
	{param "bitmap" blockinfo resource texture}
	{block "timer" optional
		{block "mode" prefer
			{param "value" blockinfo set {values "play" "reset" "stop" "forward" "reverse" "loop" "onepass" "pingpong" "rotation"}}
		}
		{param "duration" prefer RandomParameter}
	}
	{block "visibility"		optional defined "channel"}
	{block "light"			optional defined "channel"}
	{block "redlight"		optional defined "channel"}
	{block "greenlight"		optional defined "channel"}
	{block "bluelight"		optional defined "channel"}
	{block "highlight" optional
		{param "color" blockinfo color {default 0x00FFFFFF}}
	}
	{block "prescalex"		optional defined "channel"}
	{block "prescaley"		optional defined "channel"}
	{block "preturn"  		optional defined "channel"}
	{block "preshiftx"		optional defined "channel"}
	{block "preshifty"		optional defined "channel"}
	{block "preshiftz"		optional defined "channel"}
	{block "scalex"  		optional defined "channel"}
	{block "Scaley"  		optional defined "channel"}
	{block "scale"  		optional defined "channel"}
	{block "turn"    		optional defined "channel"}
	{block "shiftx"			optional defined "channel"}
	{block "shifty"			optional defined "channel"}
	{block "shiftz"			optional defined "channel"}
}
