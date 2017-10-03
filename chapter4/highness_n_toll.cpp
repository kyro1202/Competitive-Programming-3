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
int n,m,s,t,p;
vector<vii> adj,adj2;
vi dists,distt;
vector<pair<int,ii> > E;
int main()
{
    int test; cin >> test;
    int a,b,w;
    while(test--)
    {
        cin >> n >> m >> s >> t >> p;
        adj.resize(n,vii()); adj.clear(); dists.clear(); distt.clear(); dists.assign(n,INF); distt.assign(n,INF);
        adj2.resize(n,vii()); adj2.clear();
        E.clear();
        s--; t--;
        FOR0(i,m)
        {
            cin >> a >> b >> w;
            a--; b--;
            E.pb(mp(w,mp(a,b)));
            adj[a].pb(mp(b,w));
            adj2[b].pb(mp(a,w));
        }
        priority_queue< ii , vii , greater<ii> > dij;
        dij.push(mp(0,s));
        dists[s] = 0;
        while(!dij.empty())
        {
            ii u = dij.top(); dij.pop();
            if(u.ff > dists[u.ss])
                continue;
            FOR0(i,SZ(adj[u.ss]))
            {
                if(dists[adj[u.ss][i].ff] > dists[u.ss] + adj[u.ss][i].ss)
                {
                    dists[adj[u.ss][i].ff] = dists[u.ss] + adj[u.ss][i].ss;
                    dij.push(mp(dists[adj[u.ss][i].ff],adj[u.ss][i].ff));
                }
            }
        }
        dij.push(mp(0,t));
        distt[t] = 0;
        while(!dij.empty())
        {
            ii u = dij.top(); dij.pop();
            if(u.ff > distt[u.ss])
                continue;
            FOR0(i,SZ(adj2[u.ss]))
            {
                if(distt[adj2[u.ss][i].ff] > distt[u.ss] + adj2[u.ss][i].ss)
                {
                    distt[adj2[u.ss][i].ff] = distt[u.ss] + adj2[u.ss][i].ss;
                    dij.push(mp(distt[adj2[u.ss][i].ff],adj2[u.ss][i].ff));
                }
            }
        }
        int ans = -1;
        FOR0(i,SZ(E))
        {
            if(dists[E[i].ss.ff] + distt[E[i].ss.ss] + E[i].ff <= p)
            {
                ans = max(ans,E[i].ff);
            }
        }
        cout << ans << endl;
    }
}