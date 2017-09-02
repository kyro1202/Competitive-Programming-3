#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test; cin >> test;
    while(test--)
    {
        int t,temp; cin >> t; ++t;
        vector<int> p;
        while(t--)
        {
            cin >> temp;
            p.push_back(temp);
        }
        int d,k; cin >> d; long long int ans = 0;
        cin >> k; int limit = 0;
        for(int i = 1 ; i <= k ; i++)
        {
            limit += i*d;
            if(limit >= k)
            {
                for(int j = 0 ; j < p.size() ; j++)
                {
                    ans += (long long int)p[j]*pow(i,j);
                }
                break;
            }
        }
        cout << ans << endl;
    }
}