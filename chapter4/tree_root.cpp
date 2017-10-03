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
vi dist,par;
int n,curr;
int bfs(int id)
{
    dist.assign(n,-1); par.assign(n,-1);
    queue<int> q;
    dist[id] = 0;
    q.push(id);
    int furthest = id; int d = 0;
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        if(dist[u] > d)
        {
            d = dist[u];
            furthest = u;
        }
        FOR0(i,SZ(adj[u]))
        {
            if(dist[adj[u][i]] == -1)
            {
                dist[adj[u][i]] = dist[u] + 1;
                par[adj[u][i]] = u;
                q.push(adj[u][i]);
            }
        }
    }
    return furthest;
}
int main()
{
    //SYNC
    int m,a;
    while(cin >> n)
    {
        adj.clear(); adj.resize(n,vi());
        FOR0(i,n)
        {
            cin >> m;
            FOR0(j,m)
            {
                cin >> a;
                a--;
                adj[i].pb(a);
                adj[a].pb(i);
            }
        }
        int gmax = -1,gmin = INF;
        vi bad,good;
        int u = bfs(0);
        int v = bfs(u);
        int diameter = dist[v];
        int good0 = -1,good1 = -1;
        if(diameter%2)
        {
            for(int i = v ; i != -1 ; i = par[i])
            {
                if(dist[i] == (diameter+1)/2)
                    good1 = i;
                else if(dist[i] == diameter/2)
                    good0 = i;
            }
            if(good0 > good1)
                swap(good0,good1);
        }
        else
        {
            for(int i = v ; i != -1 ; i = par[i])
            {
                if(diameter/2 == dist[i])
                    good0 = i;
            }
        }
        v = bfs(good0);
        FOR0(i,n)
        {
            if(dist[i] == dist[v])
                bad.pb(i+1);
        }
        if(good1 != -1)
        {
            v = bfs(good1);
            FOR0(i,n)
            {
                if(dist[i] == dist[v])
                    bad.pb(i+1);
            }
        }
        sort(bad.begin(),bad.end());
        cout << "Best Roots  : " << good0+1;
        if(good1 != -1)
            cout << " " << good1+1;
        cout << endl;
        cout << "Worst Roots : ";
        FOR0(i,SZ(bad))
        {
            cout << bad[i];
            if(i != SZ(bad) - 1)
                cout << " ";
        }
        cout << endl;
    }
}