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
int n,m;
vvi adj;
int main()
{
    //SYNC
    int test,a,b; cin >> test;
    FOR0(ti,test)
    {
        cin >> n >> m;
        adj.clear(); adj.resize(n+m,vi(n+m,INF));
        int extra = n;
        FOR0(j,m)
        {
            cin >> a >> b;
            adj[a][extra] = adj[extra][b] = 1;
            adj[b][extra] = adj[extra][a] = 1;
            extra++;
        }
        FOR0(i,extra)
            adj[i][i] = 0;
        FOR0(i,extra)
            FOR0(j,extra)
                FOR0(k,extra)
                    adj[j][k] = min(adj[j][k],adj[j][i]+adj[i][k]);
        
        int ans = INF;
        FOR0(i,extra)
        {
            int fmax = 0,smax = 0;
            FOR0(j,n)
            {
                if(adj[i][j] > fmax)
                {
                    smax = fmax;
                    fmax = adj[i][j];
                }
                else if(adj[i][j] > smax)
                    smax = adj[i][j];
            }
            ans = min(ans,fmax+smax);
        }
        cout << "Case #" << ti+1 << ":" << endl;
        cout << ans/2 << endl;
        cout << endl;
    }
}