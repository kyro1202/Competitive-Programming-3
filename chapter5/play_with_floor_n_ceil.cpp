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
ll tot,k;
ll a,b;
ll x,y,d;
void extendedeuclid(ll a,ll b)
{
    if(b == 0)
    {
        x = 1; y = 0; d = a;
        return;
    }
    extendedeuclid(b,a%b);
    ll x1 = y;
    ll y1 = x - (a/b)*y;
    x = x1;
    y = y1;
}
int main()
{
    SYNC
    int test; cin >> test;
    while(test--)
    {
        cin >> tot >> k;
        bool changed = false;
        a = floor(1.0*tot/k);
        b = ceil(1.0*tot/k);
        extendedeuclid(a,b);
        cout << x*tot/d << " " << y*tot/d << endl;
    }
}