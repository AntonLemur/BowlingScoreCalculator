#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <sstream>
#include "calculate.h"

using namespace std;

// TEST(TEST_SUITE, TEST_CASE)

TEST(BowlingScoreCalculator, CalcScoreOneOpenFrame)
{
    unsigned short frame_result=0;
    vector<unsigned short> frame;
    
    for(int j=0;j<2;j++) //броски
    {
	unsigned short pins;
	cout<<"Введите количество сбитых кеглей:"<<endl;
	cin>>pins;
	frame_result+=pins;
	frame.push_back(frame_result);
	if(frame_result==10)
	    break;
    }

    cout<<"Бросков - "<<frame.size()<<endl;
    for(int j=0;j<frame.size();j++)
	cout<<"Бросок "<<j+1<<", результат фрейма - "<<frame[j]<<endl;
    
    ASSERT_EQ(calculate_score(frame), frame_result);
}

TEST(BowlingScoreCalculator, CalcScoreSpare)
{
    vector<vector<unsigned short>> game; //игра
    unsigned short cnt_frames=0;
    unsigned short prev_frame_result=0;

    cout<<"Введите количество фреймов:"<<endl;
    cin>>cnt_frames;
    for(int i=0;i<cnt_frames;i++) //фреймы
    {
        vector<unsigned short> frame;
        unsigned short frame_result=0;
	for(int j=0;j<2;j++) //броски
	{
	    unsigned short pins;
	    cout<<"Введите количество сбитых кеглей:"<<endl;
	    cin>>pins;
	    frame_result+=pins;
	    frame.push_back(frame_result);
	    if(frame_result==10)
		break;
	}

        cout<<"Фрейм - "<<i+1<<endl;
        cout<<"Бросков - "<<frame.size()<<endl;
        for(int j=0;j<frame.size();j++)
	    cout<<"Бросок "<<j+1<<", результат фрейма - "<<frame[j]<<endl;

	game.push_back(frame);
	if(i>0)
	{
    	    unsigned short res=calculate_score_spare(game,i);
	    //цена фрейма фактически не записывается до тех пор, пока вы не перейдете к следующему фрейму
    	    ASSERT_EQ(game[i-1][game[i-1].size()-1], prev_frame_result+frame[0]); //проверка результата предыдущего фрейма
	}
	prev_frame_result=frame[frame.size()-1];
    }
}