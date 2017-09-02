#include <bits/stdc++.h>
using namespace std;
long long int dp[105][105];
long long int solve(int n,int k)
{
    if(n == 0 || k == 1)
    {
        return 1LL;
    }
    if(dp[n][k] != -1)
        return dp[n][k];
    long long int ans = 0;
    for(long long int i = 0 ; i <= n ; i++)
    {
        ans = (ans + solve(n-i,k-1))%1000000LL;
    }
    return dp[n][k] = ans;
}
int main()
{
    ios::sync_with_stdio(false);
    int n,k;
    memset(dp,-1,sizeof(dp));
    while(cin >> n >> k)
    {
        if(!(n+k))
            break;
        cout << solve(n,k) << endl;
    }
}