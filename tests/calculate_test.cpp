#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include "calculate.h"

using namespace std;

// TEST(TEST_SUITE, TEST_CASE)

TEST(BowlingScoreCalculator, CalcScoreOneOpenFrame)
{
    unsigned short frame_result=0;
    vector<unsigned short> frame={1,2};
    
    for(int j=0;j<frame.size();j++)
	cout<<"Сбитых кеглей "<<frame[j]<<", результат фрейма "<<(frame_result+=frame[j])<<endl;
    
    cout<<"Тест EXPECT_EQ(calculate_score(frame), 3)"<<endl;
    EXPECT_EQ(calculate_score(frame), 3);
}