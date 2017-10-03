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
int main()
{
    int test,n,m,a,b,w; cin >> test;
    vector<vii> adj;
    vi dist;
    while(test--)
    {
        cin >> n >> m;
        adj.clear(); adj.resize(n,vii()); dist.clear(); dist.assign(n,INF);
        FOR0(i,m)
        {
            cin >> a >> b >> w;
            adj[a].pb(mp(b,w));
        }
        dist[0] = 0;
        FOR0(i,n-1)
        {
            FOR0(j,n)
            {
                FOR0(k,SZ(adj[j]))
                {
                    dist[adj[j][k].ff] = min(dist[j]+adj[j][k].ss,dist[adj[j][k].ff]); 
                }
            }
        }
        bool cycle = false;
        FOR0(i,n)
        {
            FOR0(k,SZ(adj[i]))
            {
                if(dist[adj[i][k].ff] > dist[i] + adj[i][k].ss)
                {
                    cycle = true;
                    break;
                }
            }
        }
        if(!cycle)
            cout << "not possible" << endl;
        else
            cout << "possible" << endl;
    }
}