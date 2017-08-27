#include <bits/stdc++.h>
using namespace std;
bool deck[4][13] = {false};
int suits[4] = {0};
char check(int a)
{
    if(a == 1)
    return 'H'; 
    if(a == 2)
    return 'D';
    if(a == 3)
    return 'C';
}
void place(string i)
{
    int x,y;
    if( i[1] == 'S')
    { x = 0; suits[0]++; }
    else if( i[1] == 'H' )
    { x = 1; suits[1]++; }
    else if( i[1] == 'D' )
    { x = 2; suits[2]++; }
    else if( i[1] == 'C' )
    { x = 3; suits[3]++; }
    if( i[0] == 'A' )
    y = 12;
    else if( i[0] == 'K' )
    y = 11;
    else if( i[0] == 'Q' )
    y = 10;
    else if( i[0] == 'J' )
    y = 9;
    else if( i[0] == 'T' )
    y = 8;
    else
    y = i[0] - '0' - 2;
    deck[x][y] = true;
}

int main()
{
    string x;
    while(1)
    {
        int points = 0; bool stopped[4] = {false}; int checknotrump = 0; 
        for(int i = 0 ; i < 13 ; i++)
        {
            cin >> x;
            place(x);
        }
        for(int i = 0 ; i < 4 ; i++)
        {
            if( deck[i][12] == true )
            { points += 4; stopped[i] = true; }
            if( deck[i][11] == true )
            { points += 3; 
            if(suits[i] == 1)
            points--;
            if( suits[i] > 1)
            stopped[i] = true;
            }
            if( deck[i][10] == true )
            { points += 2;
            if( suits[i] <= 2 )
            points--;
            if( suits[i] > 2)
            stopped[i] = true;
            }
            if( deck[i][9] == true )
            { points += 1;
            if(suits[i] <= 3)
            points--;
            }
        }
        if(points >= 16)
        checknotrump = 1;
        for(int i = 0 ; i < 4 ; i++)
        {
            if(suits[i] == 0)
            points += 2;
            else if(suits[i] == 1)
            points += 2;
            else if(suits[i] == 2)
            points += 1;
        }
        if( points < 14)
        cout << "PASS" << endl;
        else
        {
            if(checknotrump == 1)
            {
                if(stopped[0] && stopped[1] && stopped[2] && stopped[3])
                { cout << "BID NO-TRUMP" << endl; continue; }
            }
            char c = 'S'; int max = suits[0];
            for(int i = 1 ; i < 4 ; i++)
            {
                if(suits[i] > max)
                {
                    max = suits[i];
                    c = check(i);
                }
            } 
            cout << "BID " << c << endl;
        }

    }
}