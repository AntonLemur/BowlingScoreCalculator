#include <iostream>
#include <numeric> //accumalate
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
    		game[i-1][game[i-1].size()-1]+=game[i][0]; //"Spare считается как 10 кеглей плюс количество кеглей, сбитых в следующем броске"
	    else //страйк
    	    {
		if(i>1)
		{
		     //двойные, тройные
		    if(game[i-2].size()==2 && game[i-1].size()==2) //если перед текущим фреймом были два страйка подряд 
		    {
			//цена фрейма фактически не записывается до тех пор, пока вы не перейдете к следующему фрейму
	    		game[i-2][1]+=game[i][0];
			//обновляем общий результат предыдущего фрейма, туда прилетает и с предыдущего(i-2) и с текущего
			game[i].size()==1?game[i-1][1]+=game[i][0]*2:game[i-1][1]+=game[i][0]+current_sum; 
		    }
		    else
			game[i-1][game[i-1].size()-1]+=current_sum; //обновляем общий результат предыдущего фрейма
		}
		else
		    game[i-1][game[i-1].size()-1]+=current_sum; //обновляем общий результат предыдущего фрейма
    	    }
        game[i].push_back(game[i-1][game[i-1].size()-1]+current_sum); //добавляем элемент общего результата для текущего фрейма
    }
    else
        game[i].push_back(current_sum); //добавляем элемент общего результата для текущего фрейма

    return result;
}
