#include <bits/stdc++.h>
using namespace std;

int sta;

bool check(queue<int> a[],stack<int> b)
{
    if(!b.empty())
        return true;
    for(int i = 0 ; i < sta ; i++)
    {
        if(!a[i].empty())
            return true;
    }
    return false;
}

int main()
{
    int test; cin >> test;
    while(test--)
    {
        int car,que,tot = 0;
        cin >> sta >> car >> que;
        queue<int> q[105];
        for(int i = 0 ; i < sta ; i++)
        {
            int len,temp; cin >> len;
            while(len--)
            {
                cin >> temp;
                q[i].push(temp);
            }
        }
        int load_num = 0;
        int sta_ind = 0;
        stack<int> carrier;
        while(check(q,carrier))
        {
            while(!carrier.empty())
            {
                if(carrier.top() == (sta_ind+1) )
                {
                    load_num++;
                    carrier.pop();
                }
                else
                {
                    if(q[sta_ind].size() >= que)
                        break;
                    load_num++;
                    q[sta_ind].push(carrier.top());
                    carrier.pop();
                }
            }
            while(!q[sta_ind].empty() && carrier.size() < car)
            {
                carrier.push(q[sta_ind].front());
                load_num++;
                q[sta_ind].pop();
            }
            load_num += 2;
            sta_ind++;
            sta_ind = sta_ind % sta;
        }
        cout << load_num-2 << endl;
    }
}