#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n; 
    while(true)
    {
        cin >> n;
        if(!n)
            break;
        long int bags[n];
        for(int i = 0 ; i < n ; i++)
            cin >> bags[i];
        sort(bags,bags+n);
        int maxstr = -1; int currstr = 1;
        for(int i = 1 ; i <= n ; i++)
        {
            if(bags[i] == bags[i-1])
            {
                currstr++;
            }
            else
            {
                maxstr = max(maxstr,currstr);
                currstr = 1;
            }
        }
        cout << maxstr << endl;
        int j = 0;
        for(int i = 0 ; i < maxstr ; i++)
        {
            bool first = true;
            for( j = i ; j < n ; j += maxstr)
            {
                if(first)
                { cout << bags[j]; first = false;}
                else
                cout << " " << bags[j];
            }
            cout << endl;
        }
        cout << endl;
    }
}