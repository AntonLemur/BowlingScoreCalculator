#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "calculate.h"

using namespace std;

// TEST(TEST_SUITE, TEST_CASE)

TEST(BowlingScoreCalculator, CalcScoreOneOpenFrame)
{
    unsigned short frame_result=0;
    vector<vector<unsigned short>> game={{1,2}};
    
    for(int j=0;j<game[0].size();j++)
	cout<<"Сбитых кеглей "<<game[0][j]<<", результат фрейма "<<(frame_result+=game[0][j])<<endl;
    
    cout<<"Тест EXPECT_EQ(calculate_score(frame), 3)"<<endl;
    EXPECT_EQ(calculate_score(game,0), 3);
}

TEST(BowlingScoreCalculator, CalcScoreSpare)
{
    vector<vector<unsigned short>> game_const={{1,9},{1,2}}; //броски
    vector<vector<unsigned short>> game=game_const; //игра

    cout<<"game: "<<endl;
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

    unsigned short res=calculate_score(game,1);
    cout<<"Тест EXPECT_EQ(game[0][game[0].size()-1], 1+9+1)"<<endl;
    //цена фрейма фактически не записывается до тех пор, пока вы не перейдете к следующему фрейму
    EXPECT_EQ(game[0][game[0].size()-1], 1+9+1); //проверка результата предыдущего фрейма
    cout<<"Тест EXPECT_EQ(game[1][game[1].size()-1], 1+9+1+1+2)"<<endl;
    EXPECT_EQ(game[1][game[1].size()-1], 1+9+1+1+2); //проверка результата текущего фрейма
}

TEST(BowlingScoreCalculator, CalcScoreStrike)
{
    vector<vector<unsigned short>> game_const={{10},{1,2}}; //броски
    vector<vector<unsigned short>> game=game_const; //игра

    cout<<"game: "<<endl;
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

    unsigned short res=calculate_score(game,1);
    cout<<"Тест EXPECT_EQ(game[0][game[0].size()-1], 10+1+2)"<<endl;
    //цена фрейма фактически не записывается до тех пор, пока вы не перейдете к следующему фрейму
    EXPECT_EQ(game[0][game[0].size()-1], 10+1+2); //проверка результата предыдущего фрейма
    cout<<"Тест EXPECT_EQ(game[1][game[1].size()-1], 10+1+2+1+2)"<<endl;
    EXPECT_EQ(game[1][game[1].size()-1], 10+1+2+1+2); //проверка результата текущего фрейма
}

TEST(BowlingScoreCalculator, CalcScoreDoubleStrike)
{
    vector<vector<unsigned short>> game_const={{10},{10},{1,2}}; //броски 
    vector<vector<unsigned short>> game=game_const;//игра

    cout<<"game: "<<endl;
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

    unsigned short res=calculate_score(game,1);
    res=calculate_score(game,2);
    cout<<"Тест EXPECT_EQ(game[0][game[0].size()-1], 10+10+1)"<<endl;
    //цена фрейма фактически не записывается до тех пор, пока вы не перейдете к следующему фрейму
    EXPECT_EQ(game[0][game[0].size()-1], 10+10+1); //проверка результата предпредпоследнего фрейма
    cout<<"Тест EXPECT_EQ(game[1][game[1].size()-1], 10+10+1+10+1+2)"<<endl;
    EXPECT_EQ(game[1][game[1].size()-1], 10+10+1+10+1+2); //проверка результата предыдущего фрейма
    cout<<"Тест EXPECT_EQ(game[2][game[2].size()-1], 10+10+1+10+1+2+1+2)"<<endl;
    EXPECT_EQ(game[2][game[2].size()-1], 10+10+1+10+1+2+1+2); //проверка результата текущего фрейма
}