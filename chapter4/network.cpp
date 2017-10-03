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
bool ans[105];
int root,child;
vvi adj;
vi num,low,parent;
int n;
int counter;
void apab(int ind)
{
    num[ind] = low[ind] = counter++;
    FOR0(i,SZ(adj[ind]))
    {
        if(num[adj[ind][i]] == INF)
        {
            parent[adj[ind][i]] = ind;
            if(ind == root)
                child++;
            apab(adj[ind][i]);
            if(low[adj[ind][i]] >= num[ind])
                ans[ind] = true;
            low[ind] = min(low[ind],low[adj[ind][i]]);
        }
        else if(adj[ind][i] != parent[ind])
        {
            low[ind] = min(low[ind],num[adj[ind][i]]);
        }
    }
}
int main()
{
    string s;
    int u,v;
    while(true)
    {
        counter = 0; int val = 0;
        scanf("%d\n", &n);
        if(!n)
            break;
        adj.resize(n,vi());
        adj.clear();
        memset(ans,false,sizeof(ans));
        num.assign(n,INF); low.assign(n,0); parent.assign(n,-1);
        while(true)
        {
            getline(cin,s);
            istringstream ss(s);
            ss >> u;
            if(u == 0)
                break;
            u--;
            while(ss >> v)
            {
                v--;
                adj[u].pb(v);
                adj[v].pb(u);
            }
        }
        FOR0(i,n)
        {
            if(num[i] == INF)
            {
                root = i; child = 0; apab(i);
                ans[root] = (child > 1); 
            }
        }
        FOR0(i,n)
        {
            if(ans[i])
                val++;
        }
        cout << val << endl;
    }
}