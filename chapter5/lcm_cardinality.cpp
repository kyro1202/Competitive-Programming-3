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
ll ans,n;
ll gcd(ll a,ll b)
{
    return b == 0 ? a : gcd(b,a%b) ;
}
ll lcm(ll a,ll b)
{
    return (a*b)/(gcd(a,b));
}
vector<ll> f;
int main()
{
    SYNC
    while(cin >> n)
    {
        if(!n)
            break;
        if(n == 1)
        {
            cout << "1 1" << endl;
            continue;
        }
        ans = 0; f.clear();
        for(ll i = 1 ; i*i < n ; i++)
        {
            if(n%i == 0)
            {
                f.pb(i);
                if(i != n/i) f.pb(n/i);
            }
        }
        FOR0(i,SZ(f))
        {
            FOR(j,i,SZ(f))
            {
                if(lcm(f[i],f[j]) == n)
                    ans++;
            }
        }
        double ffddf = sqrt(n);
        ll sdfsf = ffddf;
        if(ffddf == sdfsf)
            ans++;
        cout << n << " " << ans << endl;
    }
}