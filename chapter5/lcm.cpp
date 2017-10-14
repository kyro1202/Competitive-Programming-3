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
bool prime[20000000];
vi p;
vector<ll> factors;
void pre()
{
    memset(prime,true,sizeof(prime));
    prime[0] = prime[1] = false;
    for(ll i = 2 ; i < 20000000 ; i++)
    {
        if(!prime[i])
            continue;
        for(ll j = i*i ; j < 20000000 ; j += i)
            prime[j] = false;
        p.pb(i);
    }
}
void pf(int a)
{
    factors.clear();
    int index = 0; int d = p[0];
    while(d*d <= a)
    {
        while(a%d == 0)
        {
            factors.pb(d);
            a = a/d;
        }
        if(index == p.size()-1)
            break;
        d = p[++index];
    }
    if(a != 1)  factors.pb(a);
}
int main()
{
    SYNC
    p.clear();
    pre();
    int n;
    swap(p[1],p[2]);
    while(cin >> n)
    {
        if(!n)
            break;
        int ct2 = 0,ct5 = 0;
        for(ll i = 2 ; i <= n ; i *= 2) ct2++;
        for(ll i = 5 ; i <= n ; i *= 5) ct5++;
        int ans = 1;
        for(ll i = 0 ; i < ct2-ct5 ; i++) ans = (ans*2)%10;
        FOR(i,2,SZ(p))
        {
            if(p[i] > n)
                break;
            for(ll j = p[i] ; j <= n ; j *= p[i]) ans = (ans*p[i])%10;
        }
        cout << ans%10 << endl;
    }
}