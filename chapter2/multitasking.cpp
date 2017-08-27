#include <bits/stdc++.h>
using namespace std;

int main()
{
    bitset<1000001> cal;
    bool overlap;
    int n,m,st,en,rp;
    while(true)
    {
        overlap = false;
        cin >> n >> m;
        if( !(n+m) )
            break;
        cal.reset();
        while(n--)
        {
            cin >> st >> en;
            for(int i = st ; i < en ; i++)
            {
                if(cal[i] == 1)
                {
                    overlap = true;
                }
                cal[i] = 1;
            }
        }
        while(m--)
        {
            cin >> st >> en >> rp;
            while(true)
            {
                if(st > 1000000)
                break;
                if(en > 1000000)
                en = 1000000;
                for(int i = st ; i < en ; i++)
                {
                    if(cal.test(i))
                        overlap = true;
                    cal[i] = 1;
                }
                st += rp;
                en += rp;                
            }
        }
        if(overlap)
        cout << "CONFLICT" << endl;
        else
        cout << "NO CONFLICT" << endl; 
    }    
}