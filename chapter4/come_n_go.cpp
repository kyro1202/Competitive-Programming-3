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
vi low,num;
int counter,n,m;
bool visited[2005];
int ans;
stack<int> temp;
void tarjanscc(int u)
{
    num[u] = low[u] = counter++;
    temp.push(u);
    visited[u] = true;
    FOR0(i,SZ(adj[u]))
    {
        if(num[adj[u][i]] == INF)
            tarjanscc(adj[u][i]);
        if(visited[adj[u][i]])
            low[u] = min(low[u],low[adj[u][i]]);
    }
    if(num[u] == low[u])
    {
        ans++;
        while(true)
        {
            int v = temp.top(); temp.pop();
            visited[v] = false;
            if(u == v)
                break;
        }
    }
}
int main()
{
    int a,b,p;
    while(cin >> n >> m)
    {
        ans = 0;
        if(!(n+m))
            break;
        adj.resize(n,vi()); adj.clear(); num.assign(n,INF); low.assign(n,0);
        memset(visited,false,sizeof(visited));
        while(!temp.empty())
            temp.pop();
        counter = 0;
        FOR0(i,m)
        {
            cin >> a >> b >> p;
            a--; b--;
            if(p == 1)
                adj[a].pb(b);
            else
            {
                adj[a].pb(b);
                adj[b].pb(a);
            }
        }
        FOR0(i,n)
        {
            if(num[i] == INF)
            {
                tarjanscc(i);
            }
        }
        if(ans == 1)
            cout << ans << endl;
        else
            cout << "0" << endl;
    }
}