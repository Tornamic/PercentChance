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

#if !defined MAX_PERCENT_VARS
    #define MAX_PERCENT_VARS            (1000)
#endif
#if !defined DEFAULT_MAX_CHANCE
    #define DEFAULT_MAX_CHANCE          (100)
#endif

static g_percent_vars_count;
static g_percent_player_data[MAX_PLAYERS][MAX_PERCENT_VARS];
static g_percent_chance_data[MAX_PERCENT_VARS];

stock ProcessChance(const playerid, const varid)
{
    if(!g_percent_chance_data[varid]) return false;

    new result = ((_t_perc_pdata[playerid][varid] += _t_perc_cdata[varid]) >= DEFAULT_MAX_CHANCE);
    if(result) g_percent_player_data[playerid][varid] -= DEFAULT_MAX_CHANCE;

    return result;
}
stock SetVarChance(const varid, const chance)
{
    if(!(0 <= varid <= MAX_PERCENT_VARS))
    {
        return false;
    }

    g_percent_vars_count++;
    g_percent_chance_data[varid] = chance;
    return true;
}
stock SetPlayerChanceValue(const playerid, const varid, const value)
{
    if(!IsPlayerConnected(playerid)) return false;

    g_percent_player_data[playerid][varid] = value;
    return true;
}
stock GetPlayerChanceValue(const playerid, const varid)
{
    return g_percent_player_data[playerid][varid];
}

stock GetPercentVarsCount() return g_percent_vars_count;

public OnPlayerConnect(playerid)
{
    for(new i = 0; i < GetPercentVarsCount(); i++)
	    g_percent_player_data[playerid][i] = 0;
    
	#if defined _t_perc__OnPlayerConnect
		return _t_perc__OnPlayerConnect(playerid);
	#else
		return true;
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
