#include <bits/stdc++.h>
using namespace std;
bool func(int a,int b) {return a>b;}
int main()
{
    ios::sync_with_stdio(false);
    int n,d,r;
    while(true)
    {
        cin >> n >> d >> r;
        if(!(n+d+r))
            break;
        int down[n],up[n];
        for(int i = 0 ; i < n ; i++)
            cin >> down[i];
        for(int i = 0 ; i < n ; i++)
            cin >> up[i];
        sort(up,up+n,func); sort(down,down+n);
        int cost = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if((down[i] + up[i]) > d)
            {
                cost += (down[i] + up[i] - d)*r;
            }
        }
        cout << cost << endl;
    }
}