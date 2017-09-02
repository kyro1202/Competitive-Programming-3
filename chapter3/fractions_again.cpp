#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin >> n)
    {
        int x,temp;
        vector<pair<int,int> > ans;
        for(x = n + 1 ; x <= 2*n ; x++)
        {
            temp = (n*x)/(x-n);
            if((n*x)%(x-n) == 0)
            {
                ans.push_back(make_pair(temp,x));
            }
        }
        cout << ans.size() << endl;
        for(int i = 0 ; i < ans.size() ; i++)
        {
            cout <<  "1/" << n << " = 1/" << ans[i].first << " + " << "1/" << ans[i].second << endl;
        }
    }
}