#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test; cin >> test;
    while(test--)
    {
        int bank = 0;
        int l,m,temp; string temp2,prev;
        cin >> l >> m;
        l = l*100;
        bool changed = false;
        queue<int> q[2];
        for(int i = 0 ; i < m ; i++)
        {
            cin >> temp >> temp2;
            if(temp2 == "left")
                q[0].push(temp);
            else
                q[1].push(temp);
        }
        int trips = 0; int tot;
        while(!q[0].empty() || !q[1].empty())
        {
            tot = 0;
            while(!q[bank].empty())
            {
                tot += q[bank].front();
                if(tot > l)
                    break;
                q[bank].pop();
            }
            trips++;
            bank = abs(bank-1);
        }
        cout << trips << endl;
    }
}