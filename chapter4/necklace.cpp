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
int adj[52][52];
int n,s;
vi tour;
void dfs(int a)
{
    FOR0(i,52)
    {
        if(adj[a][i])
        {
            adj[a][i]--;
            adj[i][a]--;
            dfs(i);
        }
    }
    tour.pb(a);
}
int main()
{
    int test,a,b; cin >> test;
    FOR(ti,1,test+1)
    {
        cin >> n;
        tour.clear();
        memset(adj,0,sizeof(adj));
        FOR0(i,n)
        {
            cin >> a >> b;
            adj[a][b]++;
            adj[b][a]++;
            s = a;
        }
        bool imp = false;
        cout << "Case #" << ti << endl;
        FOR0(i,52)
        {
            int deg = 0;
            FOR0(j,52)
                deg += adj[i][j];
            if(deg%2)
            {
                cout << "some beads may be lost" << endl;
                imp = true;
                break;
            }
        }
        if(!imp)
        {
            dfs(s);
            FOR0(i,SZ(tour)-1)
            {
                cout << tour[i] << " " << tour[i+1] << endl;
            }
        }
        if(ti != test)
            cout << endl;
    }
}