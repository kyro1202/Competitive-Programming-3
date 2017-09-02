#include <bits/stdc++.h>
using namespace std;
int n,x,y,sx,sy;
int memo[15][1<<12];
int dis[15][15];
int be[15][15];
int xpos[15],ypos[15];
bool check(int a,int b)
{
    return (1<<a)&b;
}
int tsp(int id,int mask)
{
    mask = mask | (1 << id);
    if(mask == (1<<n)-1)
        return dis[id][0];
    int cost = memo[id][mask];
    if(cost == -1)
    {
        cost = 1e9;
        for(int i = 1 ; i < n ; i++)
        {
            if(!check(i,mask))
                cost = min(cost,dis[id][i] + tsp(i,mask));
        }
    }
    memo[id][mask] = cost;
    return cost;
}
int main()
{
    ios::sync_with_stdio(false);
    int test; cin >> test;
    while(test--)
    {
        int a,b;
        cin >> x >> y;
        cin >> xpos[0] >> ypos[0];
        cin >> n; n++;        
        memset(memo,-1,sizeof(memo));
        for(int i = 1 ; i < n ; i++)
        {
            cin >> xpos[i] >> ypos[i];
            for(int j = 0 ; j < i ; j++)
            {
                dis[i][j] = dis[j][i] = abs(xpos[i] - xpos[j]) + abs(ypos[i]-ypos[j]);
            }
        }
        int ans = tsp(0,0);
        cout << "The shortest path has length ";
        cout << ans << endl;
    }
}