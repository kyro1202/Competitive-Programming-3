#include <bits/stdc++.h>
using namespace std;

int main()
{
    char c;
    while(1)
    {
        int game; cin >> game;
        if( game == -1 )
        break;
        c = getchar();
        bool check[26] = {0}; string word,guess; int wc = 0,gc = 0; int strokes = 0,correct = 0;
        while( c = getchar(), c != '\n' )
        {
            if(!check[c - 'a'])
            {
                word[wc] = c; wc++;
                check[c - 'a'] = true;
            }
        }
        //c = getchar();
        bool check2[26] = {0};
        while( c = getchar(), c != '\n' )
        {
            if(!check2[c - 'a'])
            {
                guess[gc] = c; gc++;
                check2[c - 'a'] = true;
            }
        }
        cout << "Round " << game << endl;
        for(int i = 0 ; i < gc ; i++)
        {
            if(!check[guess[i]-'a'])
            {
                strokes++;
                if(strokes == 7)
                {
                    cout << "You lose." << endl;
                    break;
                }
            }
            else
            {
                correct++;
                if(correct == wc)
                {
                    cout << "You win." << endl;
                    break; 
                }
            }
            if(i == gc - 1)
            {
                cout << "You chickened out." << endl;
                break;
            }
        }
    }
}