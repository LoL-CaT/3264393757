{"inventory_transfer"
	{on spawn
		{call "add_inventory_transfer_sound"}
	}
	{on "add_inventory_transfer_sound"
		{link_sound "weapon_change" "human/troop_weapon_change"}
		{link_sound "inventory_fill" "human/inventory_fill"}
		{link_sound "drop_item" "weapon/melee/shovel_stub"}
	}
	{on "weapon_change"
		{if stuff "weapon" or stuff "grenade" or stuff "melee" or stuff "armor"
			{play_sound "weapon_change"}
		}
	}
	{on "inventory_transfer"
		{if name "UseItem"
			;{con "UseItem"}
			{call "weapon_change"}
		else name "Xchange"
			;{con "Xchange"}
			{play_sound "inventory_fill"}
		else name "Unmount"
			;{con "Unmount"}
			{call "weapon_change"}
		else name "PutFromRight"
			;{con "PutFromRight"}
			{play_sound "weapon_change"};fix
		else name "PutFromLeft"
			;{con "PutFromLeft"}
			{play_sound "weapon_change"};fix
		else name "UnmountRight"
			;{con "UnmountRight"}
			{call "weapon_change"}
		else name "SwapHands"
			;{con "SwapHands"}
			{play_sound "weapon_change"};fix
		else name "TakeToRight"
			;{con "TakeToRight"}
			{call "weapon_change"}
		else name "PrepareForItem"
			;{con "PrepareForItem"}
		else name "FreeHands"
			;{con "FreeHands"}
		else name "DropFromHand"
			;{con "DropFromHand"}
			{play_sound "drop_item"};placeholder
		else name "DropToGround"
			;{con "DropToGround"}
			{play_sound "drop_item"};placeholder
		else name "PickupToRight"
			;{con "PickupToRight"}
			{call "weapon_change"}
		}
	}
}
{"vehicle inventory_transfer"
	{on "add_inventory_transfer_sound" overload
		{link_sound "weapon_change" "human/troop_weapon_change"}
		{link_sound "inventory_fill" "ui/add_item_to_vehicle"}
		{link_sound "drop_item" "weapon/melee/shovel_stub"}
	}
}