#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test; cin >> test;
    for(int ti = 1 ; ti <= test ; ti++)
    {
        string s1,s2;
        if(ti == 1)
        getline(cin,s1); 
        getline(cin,s1); bool check = true;
        int l1 = s1.length();
        for(int i = 0 ; i < l1 ; i++)
        {
            if( isalpha(s1[i]) )
            s2.append(s1,i,1);
        }
        double l2 = s2.length();
        double k = sqrt(l2);
        cout << "Case #" << ti << ":" << endl;
        if( k != (int)k )
        {
            cout << "No magic :(" << endl; continue;
        }
        int r = (int)k; int mark = 0;
        for(int i = 0 ; i < r ; i++)
        {
            if(s2[l2-1-i] != s2[mark])
            {
                cout << "No magic :(" << endl; check = false; break;
            }
            mark += r;
        }
        if(check)
        {for(int i = 0 ; i < l2/2 ; i++)
        {
            if(s2[i] != s2[l2-1-i])
            {
                cout << "No magic :(" << endl; check = false; break;
            }
        }}
        if(check) cout << r << endl;
    }    
}