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
long int r; int n;
vector<pair<double,ii> > E;
vii V;
vi par;
vi ra;
int find(int a)
{    return par[a] == a ? a : par[a] = find(par[a]);    }
void make(int a,int b)
{
    int x = find(a),y = find(b);
    if(ra[x] > ra[y])
    {
        par[y] = x;
    }
    else
    {
        par[x] = y;
        if(ra[y] == ra[x])
            ra[y]++;
    }
}
int main()
{
    int test; cin >> test;
    int a,b; int counter = 0;
    while(test--)
    {
        counter++;
        E.clear();V.clear();
        par.clear(); ra.clear(); 
        cin >> n >> r;
        FOR0(i,n)
            par.pb(i);
        ra.assign(n,0);
        FOR0(i,n)
        {
            cin >> a >> b;
            V.pb(mp(a,b));
        }
        FOR0(i,n)
        {
            FOR(j,i+1,n)
            {
                E.pb(mp(sqrt((V[i].ff-V[j].ff)*(V[i].ff-V[j].ff)+(V[i].ss-V[j].ss)*(V[i].ss-V[j].ss)),mp(i,j)));
            }
        }
        sort(E.begin(),E.end());
        double road = 0,rail = 0;
        int state = 0;
        FOR0(i,SZ(E))
        {
            int x = find(E[i].ss.ff); int y = find(E[i].ss.ss);
            if(x != y)
            {
                par[x] = y;
                if(E[i].ff <= r)
                {
                    state++;
                    road += E[i].ff;
                }
                else
                {
                    rail += E[i].ff;
                }
            }
        }
        cout << "Case #" << counter << ": " << n - state << " " << round(road) << " " << round(rail) << endl;
    }
}