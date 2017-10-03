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
int n,e,t,m;
vector<vii> adj;
vi dist;
int main()
{
    int test; cin >> test;
    int a,b,w;
    while(test--)
    {
        cin >> n >> e >> t >> m; e--;
        adj.clear(); dist.clear(); adj.resize(n,vii()); dist.assign(n,INF);
        FOR0(i,m)
        {
            cin >> a >> b >> w;
            a--; b--;
            adj[b].pb(mp(a,w));
        }
        priority_queue< ii , vii , greater<ii> > dij;
        dij.push(mp(0,e));
        dist[e] = 0;
        while(!dij.empty())
        {
            ii u = dij.top(); dij.pop();
            if(u.ff > dist[u.ss])
                continue;
            FOR0(i,SZ(adj[u.ss]))
            {
                if(dist[adj[u.ss][i].ff] > dist[u.ss] + adj[u.ss][i].ss)
                {
                    dist[adj[u.ss][i].ff] = dist[u.ss] + adj[u.ss][i].ss;
                    dij.push(mp(dist[adj[u.ss][i].ff],adj[u.ss][i].ff));
                }
            }
        }
        int ans = 0;
        FOR0(i,n)
        {
            if(dist[i] <= t)
                ans++;
        }
        cout << ans << endl;
        if(test)
            cout << endl;
    }
}