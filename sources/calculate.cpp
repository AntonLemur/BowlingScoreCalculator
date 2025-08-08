#include <iostream>
#include <numeric> // Required for std::accumulate
#include "calculate.h"

using namespace std;

unsigned short calculate_score(vector<vector<unsigned short>>& game, int i)
{
    unsigned short result=0;
    unsigned short current_sum=0;
    unsigned short prev_sum=0;

    current_sum=accumulate(game[i].begin(), game[i].end(), 0); //результат текущего  фрейма
    if(i>0)
    {
	prev_sum=accumulate(game[i-1].begin(), game[i-1].begin() + game[i-1].size()-1, 0); //отдельный результат предыдущего фрейма
        if(prev_sum==10)
	    if(game[i-1].size()==3) //спэа
	    {
		prev_sum+=game[i][0]; //"Spare считается как 10 кеглей плюс количество кеглей, сбитых в следующем броске"
		//цена фрейма фактически не записывается до тех пор, пока вы не перейдете к следующему фрейму
		game[i-1][game[i-1].size()-1]+=game[i][0]; //обновляем общий результат предыдущего фрейма
	    }
	    else //страйк
    	    {
		if(i>1)
		{
		     //двойные, тройные
		    if(game[i-2].size()==2 && game[i-1].size()==2 /*&& (game[i-2][game[i-2].size()-1]%10==0)*/) //если перед текущим фреймом были два страйка подряд 
		    {
			//цена фрейма фактически не записывается до тех пор, пока вы не перейдете к следующему фрейму
	    		game[i-2][1]+=game[i][0];
			game[i].size()==1?game[i-1][1]+=game[i][0]*2:game[i-1][1]+=game[i][0]+current_sum; //обновляем общий результат предыдущего фрейма
		    }
		    else
			game[i-1][game[i-1].size()-1]+=current_sum; //обновляем общий результат предыдущего фрейма
		}
		else
		    game[i-1][game[i-1].size()-1]+=current_sum; //обновляем общий результат предыдущего фрейма
		prev_sum+=current_sum; //"Для strike вы добавляете значение следующих двух бросков к 10 кеглям"
    	    }
	result=prev_sum;
        game[i].push_back(game[i-1][game[i-1].size()-1]+current_sum); //добавляем элемент общего результата для текущего фрейма
    }
    else
    {
        result=current_sum;
        game[i].push_back(current_sum); //добавляем элемент общего результата для текущего фрейма
    }

    return result;
}

