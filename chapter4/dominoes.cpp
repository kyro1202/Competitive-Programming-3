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
vvi adj;
vi visited;
stack<int> topsort;
int n,m,flag;
void dfs(int u)
{
    visited[u] = 1;
    FOR0(i,SZ(adj[u]))
    {
        if(visited[adj[u][i]] == 0)
        {
            dfs(adj[u][i]);
        }
    }
    topsort.push(u);
}
void dfs2(int u)
{
    visited[u] = 1;
    FOR0(i,SZ(adj[u]))
    {
        if(visited[adj[u][i]] == 0)
        {
            dfs(adj[u][i]);
        }
    }
}
int main()
{
    int test,a,b;
    cin >> test;
    while(test--)
    {
        flag = 0;
        cin >> n >> m;
        adj.resize(n,vi()); adj.clear(); visited.assign(n,0);
        while(!topsort.empty())
            topsort.pop();
        FOR0(i,m)
        {
            cin >> a >> b;
            a--; b--;
            adj[a].pb(b);
        }
        FOR0(i,n)
        {
            if(visited[i] == 0)
                dfs(i);
        }
        visited.assign(n,0);
        while(!topsort.empty())
        {
            int v = topsort.top(); topsort.pop();
            if(visited[v] == 0)
            {
                flag++;
                dfs2(v);
            }
        }
        cout << flag << endl;
    }
}