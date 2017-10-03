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
int m;
map<string,int> ind;
map<int,string> ret;
vector<vii> adj;
vector<pair<string,string> > lan;
vi dist;
int main()
{
    string s,d,l1,l2,w;
    while(cin >> m)
    {
        ind.clear(); ret.clear(); dist.clear(); adj.clear(); adj.resize(m+2,vii()); dist.assign(m+2,INF);
        lan.clear(); lan.assign(m+2,mp("",""));
        if(!m)
            break;
        cin >> s >> d;
        int mark = 1;
        FOR0(i,m)
        {
            cin >> l1 >> l2 >> w;
            ind[w] = mark; ret[mark] = w; 
            lan[mark] = mp(l1,l2);
            if(l1 == s || l2 == s)
            {
                adj[0].pb(mp(mark,w.length()));
            }
            if(l1 == d || l2 == d)
            {
                adj[mark].pb(mp(m+1,0));
            }
            FOR(j,1,mark)
            {
                if(lan[j].ff == lan[mark].ff || lan[j].ff == lan[mark].ss || lan[j].ss == lan[mark].ff || lan[j].ss == lan[mark].ss)
                {
                    if(ret[mark][0] != ret[j][0])
                    {
                        adj[j].pb(mp(mark,w.length()));
                        adj[mark].pb(mp(j,ret[j].length()));
                    }
                }
            }
            mark++;
        }
        priority_queue< ii , vii , greater<ii> > dij;
        dij.push(mp(0,0));
        dist[0] = 0;
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
        if(dist[m+1] == INF)
            cout << "impossivel" << endl;
        else
            cout << dist[m+1] << endl;
    }
}