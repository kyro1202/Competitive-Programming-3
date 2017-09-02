#include <bits/stdc++.h>
using namespace std;
vector<int> lengths;
int main()
{
    int test,n,temp,w; cin >> test;
    while(test--)
    {
        cin >> w;
        cin >> n;
        bool dp[1005] = {};
        dp[0] = true;
        for(int i = 0 ; i < n ; i++)
        {
            cin >> temp;
            for(int j = w - temp ; j >= 0 ; j--)
            {
                if(dp[j])
                    dp[j+temp] = true;
            }
        }
        if(dp[w])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}