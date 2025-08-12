#include <iostream>
#include <vector>
#include <sstream>
#include <numeric> // Required for std::accumulate
#include <iomanip>
#include "includes/calculate.h"

using namespace std;

void show_game(const vector<vector<unsigned short>>& game)
{
    //отображение игры
    for(int i=0;i<game.size();i++)
    {
        stringstream ss;
        ss<<i+1;

        int totalPadding = 10 - ss.str().length();
	int leftPadding = totalPadding / 2;
	int rightPadding = totalPadding - leftPadding;

        cout << setw(leftPadding + ss.str().length()) << right << ss.str()
              << setw(rightPadding) << "" <<"|";
    }
    cout<<endl;
    for(int i=0;i<game.size();i++)
    cout<<"__________"<<"|";
    cout<<endl;
    for(int i=0;i<game.size();i++)
    {
	if(game[i].size()==3)
	{
    	    stringstream ss;
    	    game[i][0]+game[i][1]==10?ss<<game[i][0]<<"        "<<"/":ss<<game[i][0]<<"        "<<game[i][1];
    
    	    int totalPadding = 10 - ss.str().length();
    	    int leftPadding = totalPadding / 2;
    	    int rightPadding = totalPadding - leftPadding;
    
    	    cout << setw(leftPadding + ss.str().length()) << right << ss.str()
              << setw(rightPadding) << "" <<"|";
	}
	else if (game[i][0]==10)
    	    cout<<setw(10)<<left<<"X"<<"|";
    }
    cout<<endl;
    for(int i=0;i<game.size();i++)
    {
        stringstream ss;
        ss<<game[i][game[i].size()-1];

        int totalPadding = 10 - ss.str().length();
        int leftPadding = totalPadding / 2;
	int rightPadding = totalPadding - leftPadding;

        cout << setw(leftPadding + ss.str().length()) << right << ss.str()
              << setw(rightPadding) << "" <<"|";
    }
    cout<<endl;
    cout<<endl;
}

int main(int argc, char* argv[])
{
    std::cout << "Hello world!" << std::endl;

    vector<vector<unsigned short>> game; //игра
    unsigned short cnt_frames=0;

    cout<<"Введите количество фреймов:"<<endl;
    cin>>cnt_frames;
    if(cnt_frames==0) return -1;
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
	game.push_back(frame);
	unsigned short result=calculate_score(game,i);
    } while(++i<cnt_frames); //фреймы

    unsigned short frame10_result = accumulate(game[i-1].begin(), game[i-1].begin()+game[i-1].size()-1,0);
    if(frame10_result==10) //проверка десятого фрейма
    {
        cout<< "\033[" << 32 << "m"<<"Бонусные броски"<< "\033[" << 39 << "m"<<endl;
        vector<unsigned short> frame;
        for(int j=0;j<(game[i-1].size()==3?1:2);j++) //броски
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
	unsigned short result=calculate_score(game,i);
    }

    show_game(game);

    return 0;
}