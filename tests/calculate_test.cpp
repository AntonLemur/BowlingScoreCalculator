#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <numeric> // Required for std::accumulate
#include <algorithm>
#include "calculate.h"

using namespace std;

// TEST(TEST_SUITE, TEST_CASE)

TEST(BowlingScoreCalculator, CalcScoreOneOpenFrame)
{
    unsigned short frame_result=0;
    vector<vector<unsigned short>> game;
    vector<unsigned short> frame;
    
    for(int j=0;j<2;j++) //броски
    {
	unsigned short pins;
	cout<<"Введите количество сбитых кеглей:"<<endl;
	cin>>pins;
        frame.push_back(pins);
        frame_result+=pins;
        if(pins==10)
	    break;
    }

    cout<<"Бросков - "<<frame.size()<<endl;
    for(int j=0;j<frame.size();j++)
	cout<<"Бросок "<<j+1<<", результат фрейма - "<<frame[j]<<endl;
    
    game.push_back(frame);
    ASSERT_EQ(calculate_score(game,0), frame_result);
}

TEST(BowlingScoreCalculator, CalcScoreSpare)
{
    vector<vector<unsigned short>> game; //игра
    unsigned short cnt_frames=0;
    unsigned short prev_frame_result=0;

    cout<<"Введите количество фреймов:"<<endl;
    cin>>cnt_frames;
    if(cnt_frames==0) return;
    int i=0;
    do{
        vector<unsigned short> frame;
	for(int j=0;j<2;j++) //броски
	{
	    unsigned short pins;
	    cout<<"Фрейм "<<i+1<<", бросок "<<j+1<<endl<<"Введите количество сбитых кеглей:"<<endl;
	    cin>>pins;
	    if(pins>10 || j>0 && pins+frame[j-1]>10)
	    {
		cout<< "\033[" << 31 << "m" <<"Значение не должно быть больше 10."<< "\033[" << 39 << "m"<<endl;
		j--;
		continue;
	    }
	    frame.push_back(pins);
	    if(pins==10)
		break;
	}
        unsigned short current_sum=accumulate(frame.begin(), frame.end(),0);

	game.push_back(frame);
	if(i>0)
	{
	    prev_frame_result+=frame[0];
    	    ASSERT_EQ(calculate_score(game,i), prev_frame_result); //проверка результата предыдущего фрейма
	}
	else
    	    ASSERT_EQ(calculate_score(game,i), current_sum); //проверка результата предыдущего фрейма

	prev_frame_result=current_sum;
    } while(++i<cnt_frames); //фреймы

    cout<< "\033[" << 32 << "m"<<"Бонусные броски"<< "\033[" << 39 << "m"<<endl;
    unsigned short frame10_result = accumulate(game[i-1].begin(), game[i-1].begin()+game[i-1].size()-1,0);
    if(frame10_result==10) //проверка десятого фрейма
    {
        vector<unsigned short> frame;
        for(int j=0;j<1;j++) //броски
        {
	    unsigned short pins;
	    cout<<"Фрейм "<<i+1<<", бросок "<<j+1<<endl<<"Введите количество сбитых кеглей:"<<endl;
	    cin>>pins;
	    if(pins>10)
	    {
	        cout<< "\033[" << 31 << "m" <<"Значение не должно быть больше 10."<< "\033[" << 39 << "m"<<endl;
	        j--;
	        continue;
	    }
	    frame.push_back(pins);
	}
	game.push_back(frame);
        prev_frame_result+=frame[0];
	ASSERT_EQ(calculate_score(game,i), prev_frame_result); //проверка результата предыдущего фрейма
    }

    //печать сохранённой игры
    for_each(game.begin(), game.end(),
        [](const vector<unsigned short>& frame) {
            stringstream ss;
            for_each(frame.begin(), frame.end(), 
                [&ss](unsigned short item) {
                    ss << item << ",";
                });
	    string s=ss.str();
	    s.pop_back();
            cout<<"["<<s<<"]"<<endl;
        });
}

TEST(BowlingScoreCalculator, CalcScoreStrike)
{
    vector<vector<unsigned short>> game; //игра
    unsigned short cnt_frames=0;
    unsigned short prev_frame_result=0;

    cout<<"Введите количество фреймов:"<<endl;
    cin>>cnt_frames;
    if(cnt_frames==0) return;
    int i=0;
    do
    {
        vector<unsigned short> frame;
	for(int j=0;j<2;j++) //броски
	{
	    unsigned short pins;
	    cout<<"Фрейм "<<i+1<<", бросок "<<j+1<<endl<<"Введите количество сбитых кеглей:"<<endl;
	    cin>>pins;
	    if(pins>10 || j>0 && pins+frame[j-1]>10)
	    {
		cout<< "\033[" << 31 << "m" <<"Значение не должно быть больше 10."<< "\033[" << 39 << "m"<<endl;
		j--;
		continue;
	    }
	    frame.push_back(pins);
	    if(pins==10)
		break;
	}
        unsigned short current_sum=accumulate(frame.begin(), frame.end(),0);

	game.push_back(frame);
	if(i>0)
	{
    	    unsigned short current_frame_result=accumulate(frame.begin(), frame.end(), 0);
	    prev_frame_result+=current_frame_result;
    	    ASSERT_EQ(calculate_score(game,i), prev_frame_result); //проверка результата предыдущего фрейма
	}
	else
    	    ASSERT_EQ(calculate_score(game,i), current_sum); //проверка результата предыдущего фрейма

	prev_frame_result=current_sum;
    }  while(++i<cnt_frames); //фреймы

    cout<< "\033[" << 32 << "m"<<"Бонусные броски"<< "\033[" << 39 << "m"<<endl;
    unsigned short frame10_result = accumulate(game[i-1].begin(), game[i-1].begin()+game[i-1].size()-1,0);
    if(frame10_result==10) //проверка десятого фрейма
    {
        vector<unsigned short> frame;
        for(int j=0;j<2;j++) //броски
        {
	    unsigned short pins;
	    cout<<"Фрейм "<<i+1<<", бросок "<<j+1<<endl<<"Введите количество сбитых кеглей:"<<endl;
	    cin>>pins;
	    if(pins>10)
	    {
	        cout<< "\033[" << 31 << "m" <<"Значение не должно быть больше 10."<< "\033[" << 39 << "m"<<endl;
	        j--;
	        continue;
	    }
	    frame.push_back(pins);
	}
	game.push_back(frame);
        unsigned short current_frame_result=accumulate(frame.begin(), frame.end(), 0);
        prev_frame_result+=current_frame_result;
	ASSERT_EQ(calculate_score(game,i), prev_frame_result); //проверка результата предыдущего фрейма
    }

    //печать сохранённой игры
    for_each(game.begin(), game.end(),
        [](const vector<unsigned short>& frame) {
            stringstream ss;
            for_each(frame.begin(), frame.end(), 
                [&ss](unsigned short item) {
                    ss << item << ",";
                });
	    string s=ss.str();
	    s.pop_back();
            cout<<"["<<s<<"]"<<endl;
        });
}