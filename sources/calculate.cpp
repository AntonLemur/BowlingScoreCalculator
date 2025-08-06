#include <iostream>
#include "calculate.h"

using namespace std;

unsigned short calculate_score(vector<vector<unsigned short>>& game, int i)
{
    unsigned short result=0;

    if(i>0)
    {
	if(game[i-1].size()==2 && game[i-1][game[i-1].size()-1]==10) //спэа
	    game[i-1][game[i-1].size()-1]+=game[i][0]; //"Spare считается как 10 кеглей плюс количество кеглей, сбитых в следующем броске"
        result=game[i-1][game[i-1].size()-1];
    }
    else
        result=game[i][game[i].size()-1];

    return result;
}

