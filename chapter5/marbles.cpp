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
ll n,d;
ll c1,c2,n1,n2;
ll x,y;
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
    while(true)
    {
        cin >> n;
        bool changed = false;
        if(!n)
            break;
        cin >> c1 >> n1;
        cin >> c2 >> n2;
        if((1.0)*c1/n1 > (1.0)*c2/n2)
        {
            swap(c1,c2);
            swap(n1,n2);
            changed = true;
        }
        extendedeuclid(n1,n2);
        if(n%d != 0)
        {
            cout << "failed" << endl;
            continue;
        }
        ll mult = n/d;
        x = x*mult; y = y*mult;
        ll lower = ceil(-1.0*x*d/n2);
        ll upper = floor(1.0*y*d/n1);
        if(lower > upper)
        {
            cout << "failed" << endl;
            continue;       
        }
        x = x + n2*upper/d;
        y = y - n1*upper/d;
        if(changed)
        {
            swap(x,y);
        }
        cout << x << " " << y << endl;    
    }
}