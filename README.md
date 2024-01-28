# PercentChance
```pawn
Author: Tornamic (Kirill Tymoshchenko)

Discord: https://pastebin.com/raw/LMBNfFHE
Github: https://github.com/Tornamic
pawn.wiki https://pawn.wiki/i.php?/user/54232-tornamic/

native ProcessChance(playerid, varid);
native SetVarChance(varid, chance);
native SetPlayerChanceValue(playerid, varid, value);
native GetPlayerChanceValue(playerid, varid);
```
# Example
```pawn
#define CHANCE_TEST 0
public OnGameModeInit()
{
	SetVarChance(CHANCE_TEST, 33);
	return 1;
}
CMD:chance_test(playerid)
{
	if(ProcessChance(playerid, CHANCE_TEST)) return SendClientMessage(playerid, 0x00FF00FF, "Success");
	return SendClientMessage(playerid, 0xFF0000FF, "Failure");
}
```
