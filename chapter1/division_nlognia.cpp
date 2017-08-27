#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k; int divx,divy; int resx,resy;
    while(1)
    {
        cin >> k; 
        if(k == 0)
            break;
        cin >> divx >> divy;
        for(int i = 0 ; i < k ; i++)
        {
            cin >> resx >> resy;
            if(resx == divx || resy == divy)
            {
                cout << "divisa" << endl;
                continue;
            }
            if(resy < divy)
            cout << "S";
            else
            cout << "N";
            if(resx < divx)
            cout << "O";
            else
            cout << "E";
            cout << endl;
        }    
    }
}