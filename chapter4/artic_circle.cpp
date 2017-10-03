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
vector<pair<double,ii> > E;
vi p,r;
vii V;
int s,o;
int find(int a)
{
    return p[a] == a ? a : p[a] = find(p[a]);
}
int make(int a,int b)
{
    if(r[a] > r[b])
        p[b] = a;
    else
    {
        p[a] = b;
        if(r[a] == r[b])
            r[b]++;
    }
}
int main()
{
    int test; cin >> test;
    int a,b;
    while(test--)
    {
        cin >> s >> o;
        if(s == o)
        {
            cout << "0" << endl;
            continue;
        }
        E.clear(); p.clear(); r.assign(o,0); V.clear();
        FOR0(i,o)
            p.pb(i);
        FOR0(i,o)
        {
            cin >> a >> b;
            V.pb(mp(a,b));
        }
        FOR0(i,o)
            FOR(j,i+1,o)
            {
                E.pb(mp(hypot(abs(V[i].ff-V[j].ff),abs(V[i].ss-V[j].ss)),mp(i,j)));
            }
        sort(E.begin(),E.end());
        double ans = -1;
        int num = 0;
        //FOR0(i,SZ(E))
            //cout << E[i].ff << endl;
        FOR0(i,SZ(E))
        {
            int x = find(E[i].ss.ff),y = find(E[i].ss.ss);
            if(x != y)
            {
                ans = E[i].ff;
                num++;
                make(x,y);
            }
            if(num == o-s)
                break;
        }        
        cout << fixed << setprecision(2) << ans << endl;
    }
}