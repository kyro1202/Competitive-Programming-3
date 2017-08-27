#include <bits/stdc++.h>
using namespace std;

int main()
{
    while(true)
    {
        int g[3],b[2];
        cin >> g[0] >> g[1] >> g[2] >> b[0] >> b[1];
        if( g[0] + g[1] + g[2] + b[0] + b[1] == 0)
        return 0;
        bool deck[53];
        memset(deck,1,53);
        
        for(int i = 0  ; i < 3 ; i++)
        {
            deck[g[i]] = false;
            if( i < 2)
            deck[b[i]] = false;
        }
        sort(g,g+3);
        sort(b,b+2);
        int b3 = 53;
        if( b[0] > g[2] )
        {
            for(int i = 1 ; i < 53 && i < b3 ; i++ )
            {
                if(deck[i])
                b3 = i;
            }
        }
        if( b[1] > g[2] )
        {
            for(int i = g[2] + 1 ; i < 53 && i < b3 ; i++ )
            {
                if(deck[i])
                b3 = i;
            }
        }
        if(b[0] > g[1])
        {
            for(int i = g[1] + 1 ; i < 53 && i < b3 ; i++ )
            {
                if(deck[i])
                b3 = i;
            }
        }
        if( b3 == 53)
        b3 = -1;
        cout << b3 << endl;
    }
}