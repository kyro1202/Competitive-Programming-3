#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    while(true)
    {
        cin >> n >> m;
        if(!(n+m))
            break;
        int dia[n],hei[m],gold = 0;
        for(int i = 0 ; i < n ; i++)
            cin >> dia[i];
        for(int i = 0 ; i < m ; i++)
            cin >> hei[i];
        sort(dia,dia+n); sort(hei,hei+m);
        int d = 0,h = 0;
        while(d < n && h < m)
        {
            while(dia[d] > hei[h] && h < m) h++;
            if(h == m)
            {
                break;
            }
            gold += hei[h];
            h++;
            d++;
        }
        if(d == n)
        cout << gold << endl;
        else
        cout << "Loowater is doomed!" << endl;
    }
}