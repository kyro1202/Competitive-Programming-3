#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,t;
    while(true)
    {
        cin >> n >> m;
        if(n + m == 0)
            break;
        vector<vector<int> > heights;
        for(int i = 0 ; i < n ; i++)
        {
            vector<int> temp;
            for(int j = 0 ; j < m ; j++)
            {
                cin >> t;
                temp.push_back(t);
            }
            heights.push_back(temp);
        }
        int q; cin >> q;
        while(q--)
        {
            int l,u,ans = 0; cin >> l >> u;
            for(int i = 0 ; i < n ; i++)
            {
                vector<int>::iterator low = lower_bound(heights[i].begin(),heights[i].end(),l);
                if(low == heights[i].end())
                    continue;
                if(*low > u)
                    continue;
                int side = low - heights[i].begin();
                int pos = side; int diff = m - side - 1;
                diff = min(diff,n-i-1);
                while(heights[i+diff][pos+diff] > u)
                {
                    diff--;
                }
                ans = max(ans,diff+1);
            }
            cout << ans << endl;
        }
        cout << "-" << endl;
    }
}