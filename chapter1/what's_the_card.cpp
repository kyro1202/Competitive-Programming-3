#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test; cin >> test; string x;
    for(int ti = 1 ; ti <= test ; ti++)
    {
        int pos = 26; int v,y = 0;
        vector<string> deck;
        for(int i = 0 ; i < 52 ; i++)
        {
            cin >> x;
            deck.push_back(x);
        }
        for(int i = 0 ; i < 3 ; i++)
        {
            x = *(deck.begin() + pos);
            v = x[0] - '0';
            if(v < 2 || v > 9)
            v = 10;
            y += v;
            pos -= ( 10 - v );
            deck.erase(deck.begin()+pos,deck.begin()+pos+10-v+1);
            pos--;
        }
        x = *(deck.begin() + y - 1);
        cout << "Case " << ti << ": " << x << endl;
    }
}