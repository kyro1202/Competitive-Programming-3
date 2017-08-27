#include <bits/stdc++.h>
using namespace std;
map<char,bool> woken;
map<char,int> conn;
map<char,char> p;
int main()
{
    int n,m;char c,b;
    while(true)
    {
        int count = 0;
        cin >> n;
        woken.clear();
        conn.clear();
        p.clear();
        cin >> m;
        for(int i = 0 ; i < 3 ; i++)
        {
            cin >> c;
            woken[c] = true;
        }
        while(m--)
        {
            cin >> c >> b;
            p[c] = b; p[b] = c;
            if(woken[c] || woken[b])
            {
                conn[c]++; conn[b]++;
                if(conn[c] > 2)
                woken[c] = true;
                if(conn[b] > 2)
                woken[b] = true;
            }
        } 
    }
}