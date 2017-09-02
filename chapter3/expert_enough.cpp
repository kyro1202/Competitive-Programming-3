#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test; cin >> test;
    vector<pair<string,pair<int,int> > > d;
    while(test--)
    {
        int n; cin >> n;
        d.clear();
        string s; int t1,t2;
        while(n--)
        {
            cin >> s >> t1 >> t2;
            d.push_back(make_pair(s,make_pair(t1,t2)));
        }
        int q; cin >> q;
        while(q--)
        {
            int count = 0;
            string ans;
            int p; cin >> p;
            for(int j = 0 ; j < d.size() ; j++)
            {
                if( (p >= d[j].second.first) && (p <= d[j].second.second) )
                {
                    count++;
                    if(count == 2)
                        break;
                    ans = d[j].first;
                }
            }
            if(count == 2 || count == 0)
            cout << "UNDETERMINED" << endl;
            else
            cout << ans << endl;
        }
        if(test)
        cout << endl;
    }
}