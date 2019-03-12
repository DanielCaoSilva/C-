#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

class Die
{
private:
    int sides;
    int value;
public:
    Die();
    void roll();
    int getSides();
    int getValue();
};
Die::Die()
{
    unsigned seed = time(0);
    srand(seed);
    sides = 6;
    roll();
}
void Die::roll()
{
    value =(rand()%6)+1;
}
int Die::getSides()
{
    return sides;
}
int Die::getValue()
{
    return value;
}
void beginGame();
void takeTurn(int &sum, Die d[2]);
void checkWinner(int pSum,int cSum);

int main(int argc, char *argv[])
{
    beginGame();
    Die d[2];
    const int MAX_PTS = 21;
    char ans = 'y';
    int playerSum = 0;
    int computerSum = 0;
    while(playerSum<21&&ans=='y')
    {
        takeTurn(computerSum,d);
        cout<<"Would you like to roll?[y/n]\n";
        cin>>ans;
        if(ans=='y'&&playerSum!=21)
            takeTurn(playerSum,d);
        if(ans=='n'||playerSum>21)
            break;
        cout<<"Your total is "<<playerSum<<endl;

    }
    checkWinner(playerSum,computerSum);
    return 0;
}
void beginGame()
{
    cout << "Welcome to the game of 21!\n\n";
}
void takeTurn(int &sum,Die d[2])
{
    for(int i = 0;i<2;i++)
    {
        d[i].roll();
        sum+=d[i].getValue();
    }
}
void checkWinner(int pSum, int cSum)
{
    cout<<"\nHere are the final results!\n\n";
    cout<<"Your total is "<<pSum<<endl;
    cout<<"The Computer total is "<<cSum<<endl<<endl;
    if((pSum>cSum&&pSum<=21)||(cSum>21&&pSum<=21))
        cout<<"You Win!\n";
    else if((cSum>pSum&&cSum<=21)||(pSum>21&&cSum<=21))
        cout<<"The Computer Wins!\n";
    else if(pSum == cSum&&pSum<=21)
        cout<<"It is a tie!\n";
    else if(pSum>21&&cSum>21)
        cout<<"You both lost!\n";
}




















