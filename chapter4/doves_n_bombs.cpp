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
vi num,low,parent,ans;
int n,m;
int root,child,counter;
vii bombs;
bool func(ii a,ii b)
{
    if(a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}
void apab(int u)
{
    num[u] = low[u] = counter++;
    FOR0(i,SZ(adj[u]))
    {
        if(num[adj[u][i]] == INF)
        {
            parent[adj[u][i]] = u;
            if(u == root)   child++;
            apab(adj[u][i]);
            if(low[adj[u][i]] >= num[u])
                ans[u]++;
            low[u] = min(low[u],low[adj[u][i]]);
        }
        else if(adj[u][i] != parent[u])
            low[u] = min(low[u],num[adj[u][i]]);
    }
}
int main(){
    int u,v;
    while(scanf("%d %d", &n, &m) && n){
    num.assign(n,INF); low.assign(n,0); parent.assign(n,0);
    adj.resize(n,vi()); adj.clear();
    bombs.clear(); ans.assign(n,0);
    while(1){
           scanf("%d %d", &u, &v);
           if (u == -1) break;
           adj[u].push_back(v);
           adj[v].push_back(u);
    }  	
    for (int i = 0; i < n; i++){
        if (num[i] == INF){
            child = 0;
            root = i;
        apab(i);
        ans[i] = (child > 1);
        }
    }
      
    for (int i = 0; i < n; i++){
        ans[i]++;
        bombs.push_back(mp(ans[i], i));
    }
      
    sort(bombs.begin(), bombs.end(), func);
    for (int i = 0; i < n; i++)
    {
          printf("%d %d\n", bombs[i].second, bombs[i].first);       
          if (i == m-1) break;
      }
      printf("\n");
    }
    return 0;
}