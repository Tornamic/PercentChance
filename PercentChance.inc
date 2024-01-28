/*

PercentChance include

Author: Tornamic (Kirill Tymoshchenko)
    Discord: https://pastebin.com/raw/LMBNfFHE
    Github: https://github.com/Tornamic
    pawn.wiki https://pawn.wiki/i.php?/user/54232-tornamic/

    native ProcessChance(playerid, varid);
    native SetVarChance(varid, chance);
    native SetPlayerChanceValue(playerid, varid, value);
    native GetPlayerChanceValue(playerid, varid);
*/


#if defined TORT_PERCENT_CHANCE_INCLUDED
    #endinput
#endif

#define TORT_PERCENT_CHANCE_INCLUDED

#define TORT_PERCENT_CHANCE_VERSION (1)

#if !defined MAX_PERCENT_VARS
    #define MAX_PERCENT_VARS 1000
#endif

new _t_perc_pdata[MAX_PLAYERS][MAX_PERCENT_VARS];
new _t_perc_cdata[MAX_PERCENT_VARS];
stock ProcessChance(playerid, varid)
{
    if(!_t_perc_cdata[varid]) return 0;
    if(!_t_perc_pdata[playerid][varid] && random(100) < _t_perc_cdata[varid]) return 1;
    new result = ((_t_perc_pdata[playerid][varid] += _t_perc_cdata[varid]) >= 100);
    if(result) _t_perc_pdata[playerid][varid] = 0;
    return result;
}
stock SetVarChance(varid, chance)
{
    _t_perc_cdata[varid] = chance;
    return 1;
}
stock SetPlayerChanceValue(playerid, varid, value)
{
    if(!IsPlayerConnected(playerid)) return 0;
    _t_perc_pdata[playerid][varid] = value;
    return 1;
}
stock GetPlayerChanceValue(playerid, varid)
{
    return _t_perc_pdata[playerid][varid];
}
public OnPlayerConnect(playerid)
{
    for(new i = 0; i < MAX_PERCENT_VARS; i++)
	    _t_perc_pdata[playerid][i] = 0;
    SendClientMessage(playerid, -1, "asdasdasd");
	#if defined _t_perc__OnPlayerConnect
		return _t_perc__OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect _t_perc__OnPlayerConnect
#if defined _t_perc__OnPlayerConnect
	forward _t_perc__OnPlayerConnect(playerid);
#endif