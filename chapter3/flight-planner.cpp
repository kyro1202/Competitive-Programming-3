#include <bits/stdc++.h>
using namespace std;
#define inf 1e9;
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
int dis;
int winds[10][1005];
int dp[10][1005];
int getf(int curr,int level)
{
    if(level > 9 || level < 0 || curr > dis)
        return inf;
    if(curr == dis)
    {
        if(level == 0)
            return 0;
        else
            return inf;
    }
    if(dp[level][curr] != -1)
        return dp[level][curr];
    int p;
    p = MIN3((getf(curr+1,level)+30-winds[level][curr]),(getf(curr+1,level-1)+20-winds[level][curr]),(getf(curr+1,level+1)+60-winds[level][curr]));
    return dp[level][curr] = p;
}
int main()
{
    ios::sync_with_stdio(false);
    int test; cin >> test;
    while(test--)
    {
        cin >> dis;
        memset(dp,-1,sizeof(dp));
        for(int i = 9 ; i >= 0 ; i--)
        {
            for(int j = 0 ; j < dis/100 ; j++)
            {
                cin >> winds[i][j];
            }
        }
        dis /= 100;
        cout << getf(0,0) << endl;
        cout << endl;
    }
}