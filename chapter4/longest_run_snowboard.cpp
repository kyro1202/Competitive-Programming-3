#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define SZ(a) ((int)((a).size()))
#define pb push_back
#define mp make_pair
#define INF ((int)1e9)
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
int r,c;
int grid[105][105];
int dx[4] = { 0 , 0 , -1 , 1 };
int dy[4] = { 1 , -1 , 0 , 0 };
vvi adj;
vi dp;
int dfs(int x)
{
    if(dp[x] != -1)
        return dp[x];
    int val = 0;
    FOR0(i,SZ(adj[x]))
    {
        val = max(val,1+dfs(adj[x][i]));
    }
    return dp[x] = val;
}
int main()
{
    int test; cin >> test;
    string name;
    FOR(ti,1,test+1)
    {
        cin >> name >> r >> c;
        adj.resize(r*c,vi()); adj.clear();
        dp.clear(); dp.resize(r*c,-1);
        FOR0(i,r)
            FOR0(j,c)
                cin >> grid[i][j];
        FOR0(i,r)
            FOR0(j,c)
                FOR0(k,4)
                {
                    if(i + dx[k] < 0 || i + dx[k] >= r || j + dy[k] < 0 || j + dy[k] >= c)
                        continue;
                    if(grid[i+dx[k]][j+dy[k]] < grid[i][j])
                        adj[i*c+j].pb((i+dx[k])*c + j+dy[k]);
                }
        int ans = -1;
        FOR0(i,r)
            FOR0(j,c)
                ans = max(ans,dfs(i*c+j));
        cout << name << ": " << ans+1 << endl;
    }
}