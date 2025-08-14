#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include "calculate.h"

using namespace std;

// TEST(TEST_SUITE, TEST_CASE)

TEST(BowlingScoreCalculator, CalcScoreOneOpenFrame)
{
    unsigned short frame_result=0;
    vector<unsigned short> frame={1,2}; //1+2=3

    cout<<"Бросков - "<<frame.size()<<endl;
    for(int j=0;j<frame.size();j++)
	cout<<"Бросок "<<j+1<<", результат фрейма - "<<frame[j]<<endl;
    
    EXPECT_EQ(calculate_score(frame), 3);
}
