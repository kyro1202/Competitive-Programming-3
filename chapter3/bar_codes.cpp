#include <bits/stdc++.h>
using namespace std;
long long int dp[51][51][51];
long long int solve(int n,int k,int m)
{
    if(k == 0)
    {
        if(n)
            return 0;
        return 1;
    }
    if(dp[n][k][m] != -1)
        return dp[n][k][m];
    long long int p = 0;
    for(int i = 1 ; i <= m ; i++)
    {
        if(n>=i)
            p += solve(n-i,k-1,m);
        else break;
    }
    return dp[n][k][m] = p;
}
int main()
{
    ios::sync_with_stdio(false);
    int n,k,m;
    memset(dp,-1,sizeof(dp));
    while(cin >> n >> k >> m)
    {
        memset(dp,-1,sizeof(dp));
        cout << solve(n,k,m) << endl;
    }
}