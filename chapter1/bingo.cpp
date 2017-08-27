#include <bits/stdc++.h>
using namespace std;

int card[5][5];  int temp;
int check(int c)
{
    for(int i = 0 ; i < 5 ; i++)
    {
        if(card[i][c] == temp)
        { card[i][c] = 0; return i; }
    }
    return -1;
}
int main()
{
    int test; cin >> test; bool bingo = false;
    while(test--)
    {
        card[2][2] = 0;
        for(int i = 0 ; i < 5 ; i++)
        {
            for(int j = 0 ; j < 5 ; j++)
            {
                if(i == 2 && j == 2)
                continue;
                cin >> card[i][j];
            }
        }
        int ball;
        for( ball = 1 ; ball <= 75 ; ball++)
        {
            cin >> temp;
            int col = (temp-1)/15;
            int i = check(col);
            if( i == -1 )
            continue;
            bingo = true;
            for(int j = 0 ; j < 5 ; j++)
            {
                if(card[j][col]) { bingo = false; break; }
            }
            if(!bingo)
            {
                bingo = true;
                for(int j = 0 ; j < 5 ; j++)
                {
                    if(card[i][j]) { bingo = false; break; }
                }
            }
            if(!bingo)
            {
                if(i == col)
                {
                    bingo = true;
                    for(int j = 0 ; j < 5 ; j++)
                    {
                        if(card[j][j])
                        {
                            bingo = false; break;
                        }
                    }
                }
                if( i == 4 - col)
                {
                    bingo = true;
                    for(int j = 0 ; j < 5 ; j++)
                    {
                        if(card[4-j][j])
                        {
                            bingo = false; break;
                        }
                    }
                }
            }
            if(bingo)
            {
                cout << "BINGO after " << ball <<  " numbers announced" << endl;
                break;
            }
        }
        for( ; ball < 75 ; ball++)
        {
            cin >> temp;
        }
    }
}