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
int n,m,q;
vector<vii> adj;
vi dist; vi bu;
int main()
{
    int temp,a,b,counter = 0;
    while(cin >> n)
    {
        adj.clear(); adj.resize(n,vii()); dist.clear(); dist.assign(n,INF);
        bu.clear();
        FOR0(i,n)
        {
            cin >> temp;
            bu.pb(temp);
        }
        cin >> m;
        FOR0(i,m)
        {
            cin >> a >> b;
            a--; b--;
            int diff = bu[a] - bu[b];
            diff = diff*diff*diff;
            adj[a].pb(mp(b,diff));
        }
        dist[0] = 0;
        FOR0(i,n-1)
        {
            FOR0(j,n)
            {
                FOR0(k,SZ(adj[j]))
                {
                    dist[adj[j][k].ff] = min(dist[adj[j][k].ff],dist[j]+adj[j][k].ss);
                }
            }
        }
        FOR0(i,n)
        {
            FOR0(j,SZ(adj[i]))
            {
                if(dist[adj[i][j].ff] > dist[i] + adj[i][j].ss && dist[i] != INF)
                    dist[adj[i][j].ff] = INF;
            }
        }
        cin >> q;
        counter++;
        cout << "Set #" << counter << endl;
        FOR0(i,q)
        {
            cin >> temp;
            temp--;
            if(dist[temp] < 3 || dist[temp] == INF)
            {
                cout << "?" << endl;
            }
            else
                cout << dist[temp] << endl;
        }
    }
}