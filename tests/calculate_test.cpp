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
    vector<vector<unsigned short>> game_const={{1,2}}; //броски
    vector<vector<unsigned short>> game=game_const; //игра
    
    for(int j=0;j<game[0].size();j++)
	cout<<"Сбитых кеглей "<<game[0][j]<<", результат фрейма "<<(frame_result+=game[0][j])<<endl;
    
    unsigned short res=calculate_score(game,0);
    cout<<"Тест EXPECT_EQ(game[0][game[0].size()-1], 3)"<<endl;
    EXPECT_EQ(game[0][game[0].size()-1], 1+2);
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

    unsigned short res=calculate_score(game,0);
    res=calculate_score(game,1);
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

    unsigned short res=calculate_score(game,0);
    res=calculate_score(game,1);
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

    unsigned short res=calculate_score(game,0);
    res=calculate_score(game,1);
    res=calculate_score(game,2);
    cout<<"Тест EXPECT_EQ(game[0][game[0].size()-1], 10+10+1)"<<endl;
    //цена фрейма фактически не записывается до тех пор, пока вы не перейдете к следующему фрейму
    EXPECT_EQ(game[0][game[0].size()-1], 10+10+1); //проверка результата предпредпоследнего фрейма
    cout<<"Тест EXPECT_EQ(game[1][game[1].size()-1], 10+10+1+10+1+2)"<<endl;
    EXPECT_EQ(game[1][game[1].size()-1], 10+10+1+10+1+2); //проверка результата предыдущего фрейма
    cout<<"Тест EXPECT_EQ(game[2][game[2].size()-1], 10+10+1+10+1+2+1+2)"<<endl;
    EXPECT_EQ(game[2][game[2].size()-1], 10+10+1+10+1+2+1+2); //проверка результата текущего фрейма
}

TEST(BowlingScoreCalculator, CalcScoreTripleStrike)
{
    vector<vector<unsigned short>> game_const={{10},{10},{10}}; //броски 
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

    unsigned short res=calculate_score(game,0);
    res=calculate_score(game,1);
    res=calculate_score(game,2);
    cout<<"Тест EXPECT_EQ(game[0][game[0].size()-1], 10+10+10)"<<endl;
    //цена фрейма фактически не записывается до тех пор, пока вы не перейдете к следующему фрейму
    EXPECT_EQ(game[0][game[0].size()-1], 10+10+10); //проверка результата предпредпоследнего фрейма
    cout<<"Тест EXPECT_EQ(game[1][game[1].size()-1], 10+10+10+10+10)"<<endl;
    EXPECT_EQ(game[1][game[1].size()-1], 10+10+10+10+10); //проверка результата предыдущего фрейма
    cout<<"Тест EXPECT_EQ(game[2][game[2].size()-1], 10+10+10+10+10+10)"<<endl;
    EXPECT_EQ(game[2][game[2].size()-1], 10+10+10+10+10+10); //проверка результата текущего фрейма
}

TEST(BowlingScoreCalculator, CalcScoreMax)
{
    vector<vector<unsigned short>> game_const={{10},{10},{10},{10},{10},{10},{10},{10},{10},{10},{10},{10}}; //броски 
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

    unsigned short res=0;
    for(int i=0;i<game.size();i++)
	res=calculate_score(game,i);
    
    for(int i=0;i<game.size()-2;i++)
    {
	cout<<"Тест EXPECT_EQ(game["<<i<<"][game[<<"<<i<<"].size()-1],"<<30*(i+1)<<")"<<endl;
	EXPECT_EQ(game[i][game[i].size()-1], 30*(i+1));
    }    
}

TEST(BowlingScoreCalculator, CalcScoreRandom)
{
    vector<vector<unsigned short>> game_const={{9,0},{10},{10},{7,2},{10},{8,2},{8,2},{9,1},{9,1},{9,0}}; //броски 
    vector<vector<unsigned short>> game=game_const;//игра
    vector<pair<int,string>> frames_results={{9+0,"Тест EXPECT_EQ(game[0][game[0].size()-1],9+0)"},{9+10+10+7,"Тест EXPECT_EQ(game[1][game[1].size()-1],9+10+10+7)"}
	,{36+10+7+2,"Тест EXPECT_EQ(game[2][game[2].size()-1],36+10+7+2)"},{55+7+2,"Тест EXPECT_EQ(game[3][game[3].size()-1],55+7+2)"}
	,{64+10+8+2,"Тест EXPECT_EQ(game[4][game[4].size()-1],64+10+8+2)"},{84+8+2+8,"Тест EXPECT_EQ(game[5][game[5].size()-1],84+8+2+8)"}
	,{102+8+2+9,"Тест EXPECT_EQ(game[6][game[6].size()-1],102+8+2+9)"},{121+9+1+9,"Тест EXPECT_EQ(game[7][game[7].size()-1],121+9+1+9)"}
	,{140+9+1+9,"Тест EXPECT_EQ(game[8][game[8].size()-1],140+9+1+9)"},{159+9+0,"Тест EXPECT_EQ(game[9][game[9].size()-1],159+9+0)"}}; //результаты фреймов 

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

    unsigned short res=0;
    for(int i=0;i<game.size();i++)
	res=calculate_score(game,i);
    
    for(int i=0;i<game.size();i++)
    {
	cout<<frames_results[i].second<<endl;
	EXPECT_EQ(game[i][game[i].size()-1], frames_results[i].first);
    }    
}

TEST(BowlingScoreCalculator, CalcScoreAnotherOneRandom)
{
    vector<vector<unsigned short>> game_const={{4,6},{10},{8,2},{4,5},{9,0},{3,0},{9,1},{9,0},{8,2},{9,0}}; //броски 
    vector<vector<unsigned short>> game=game_const;//игра
    vector<pair<int,string>> frames_results={{4+6+10,"Тест EXPECT_EQ(game[0][game[0].size()-1],4+6+10)"},{20+10+8+2,"Тест EXPECT_EQ(game[1][game[1].size()-1],20+10+8+2)"}
	,{40+8+2+4,"Тест EXPECT_EQ(game[2][game[2].size()-1],40+8+2+4)"},{54+4+5,"Тест EXPECT_EQ(game[3][game[3].size()-1],54+4+5)"}
	,{63+9+0,"Тест EXPECT_EQ(game[4][game[4].size()-1],63+9+0)"},{72+3+0,"Тест EXPECT_EQ(game[5][game[5].size()-1],72+3+0)"}
	,{75+9+1+9,"Тест EXPECT_EQ(game[6][game[6].size()-1],75+9+1+9)"},{94+9+0,"Тест EXPECT_EQ(game[7][game[7].size()-1],94+9+0)"}
	,{103+8+2+9,"Тест EXPECT_EQ(game[8][game[8].size()-1],103+8+2+9)"},{122+9+0,"Тест EXPECT_EQ(game[9][game[9].size()-1],122+9+0)"}}; //результаты фреймов 

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

    unsigned short res=0;
    for(int i=0;i<game.size();i++)
	res=calculate_score(game,i);
    
    for(int i=0;i<game.size();i++)
    {
	cout<<frames_results[i].second<<endl;
	EXPECT_EQ(game[i][game[i].size()-1], frames_results[i].first);
    }    
}