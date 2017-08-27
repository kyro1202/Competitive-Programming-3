#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test; cin >> test;
    while(test--)
    {
        int arrival[10050],departure[10050];
        int tot = 0;
        int bank = 0;
        queue<int> q[2];
        int n,t,m,temp; cin >> n >> t >> m; string temp2;
        for(int i = 0 ; i < m ; i++)
        {
            cin >> temp >> temp2;
            if(temp2 == "right")
                q[1].push(i);
            else
                q[0].push(i);
            arrival[i] = temp;
        }
        int count;
        while(!q[1].empty() || !q[0].empty())
        {
            int next = 0;
            if(q[0].empty()) next = arrival[q[1].front()];
            else if(q[1].empty()) next = arrival[q[0].front()];
            else next = min(arrival[q[0].front()],arrival[q[1].front()]);
            tot = max(tot,next);
            count = 0;
            while(!q[bank].empty() && tot >= arrival[q[bank].front()] && count < n)
            {
                departure[q[bank].front()] = tot + t;
                q[bank].pop(); count++;
            }
            tot += t;
            bank = abs(bank-1);
        }
        for(int i = 0 ; i < m ; i++)
        {
            cout << departure[i] << endl;
        }
        if(test)
            cout << endl;
    }
}