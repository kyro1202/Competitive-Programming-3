#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    while(cin >> test, test)
    {
        int temp;
        priority_queue<int , vector<int> , greater<int> > q;
        while(test--)
        {
            cin >> temp;
            q.push(temp);
        }
        int cost = 0;
        int tot = 0;
        while(q.size() > 1)
        {
            tot = q.top(); q.pop();
            tot += q.top(); q.pop();
            cost += tot;
            q.push(tot);
        }
        cout << cost << endl;
    }
}