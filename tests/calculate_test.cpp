#include <gtest/gtest.h>
#include <iostream>
#include <vector>
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
