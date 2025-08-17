#include <iostream>
#include <numeric> //accumalate
#include "calculate.h"

using namespace std;

unsigned short calculate_score(vector<vector<unsigned short>>& game, int i)
{
    unsigned short result=0;
    
    if(i>0)
    {
        result=accumulate(game[i-1].begin(),game[i-1].end(),0);
	if(result==10) //спэа
    	    game[i-1][game[i-1].size()-1]=result+game[i][0]; //"Spare считается как 10 кеглей плюс количество кеглей, сбитых в следующем броске"
	//обновляем текущий фрейм
	result=accumulate(game[i].begin(),game[i].end(),0);
	game[i][game[i].size()-1]=result+game[i-1][game[i-1].size()-1];
    }
    else
        result=accumulate(game[i].begin(),game[i].end(),0);

    return result;
}
