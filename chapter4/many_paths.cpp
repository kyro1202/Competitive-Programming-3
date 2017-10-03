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
int n,m;
vvi adj;
vector<long long int> path;
bool visited[2005];
stack<int> top;
void dfs(int ind)
{
    visited[ind] = true;
    FOR0(i,SZ(adj[ind]))
    {
        if(visited[adj[ind][i]] == false)
            dfs(adj[ind][i]);
    }
    top.push(ind);
}
int main()
{
    int t; bool p = false;
    while(cin >> n)
    {
        adj.resize(n,vi()); adj.clear(); path.clear(); path.assign(n,0);
        memset(visited,false,sizeof(visited));
        long long int ans = 0;
        FOR0(i,n)
        {
            cin >> m;
            FOR0(j,m)
            {
                cin >> t;
                adj[i].pb(t);
            }
        }
        dfs(0);
        path[0] = 1;
        while(!top.empty())
        {
            int u = top.top(); top.pop();
            FOR0(i,SZ(adj[u]))
            {
                path[adj[u][i]] += path[u];
            }
            if(!SZ(adj[u]))
                ans += path[u];
        }
        if(p) cout << endl;
        p = true;
        cout << ans << endl;
    }
}