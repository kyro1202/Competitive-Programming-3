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
int main()
{
    int V;
    while(cin >> V)
    {
        if(!V)
            break;
        vi color(V,INF);
        adj.resize(V,vi());
        adj.clear();
        int a,b;
        while(cin >> a >> b)
        {
            if(!(a+b))
                break;
            a--; b--;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        queue<int> q;
        q.push(0);
        color[0] = 0;
        bool bipar = true;
        while(!q.empty() && bipar)
        {
            int p = q.front(); q.pop();
            FOR0(i,SZ(adj[p]))
            {
                if(color[adj[p][i]] == INF)
                {
                    color[adj[p][i]] = 1 - color[p];
                    q.push(adj[p][i]);
                }
                else if(color[adj[p][i]] == color[p])
                {
                    bipar = false; break;
                }
            }
        }
        if(bipar)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}