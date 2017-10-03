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
vi par,r;
vector<pair<int,ii> > E;
int n,m;
int find(int x)
{
    return par[x] == x ? x : par[x] = find(par[x]);
}
void makeunion(int a,int b)
{
    int x = find(a),y = find(b);
    if(x != y)
    {
        if(r[x] > r[y])
            par[y] = x;
        else
        {
            if(r[y] > r[x])
                par[x] = y;
            else
            {
                par[x] = y;
                r[x]++;
            }
        }
    }
}
int main()
{
    int a,b,w;
    while(cin >> n >> m)
    {
        if(!(n+m))
            break;
        int sum = 0;
        r.assign(n,0); par.resize(n);
        E.clear();
        FOR0(i,n)
            par[i] = i;
        FOR0(i,m)
        {
            cin >> a >> b >> w;
            sum += w;
            E.pb(mp(w,mp(a,b)));
        }
        sort(E.begin(),E.end());
        int cost = 0;
        FOR0(i,SZ(E))
        {
            if(find(E[i].ss.ff) != find(E[i].ss.ss))
            {
                cost += E[i].ff;
                makeunion(E[i].ss.ff,E[i].ss.ss);
            }
        }
        cout << sum-cost << endl;
    }
}