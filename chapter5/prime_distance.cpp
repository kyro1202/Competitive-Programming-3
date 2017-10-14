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
bool prime[2000000];
vii memo;
vector<ll> p;
void pre()
{
    memset(prime,true,sizeof(prime));
    prime[0] = prime[1] = false;
    for(ll i = 2 ; i < 2000000 ; i++)
    {
        if(!prime[i])
            continue;
        for(ll j = i*i ; j < 2000000 ; j += i)
            prime[j] = false;
        p.pb(i);
    }
}
bool isprime(ll a)
{
    if(a < 2000000)
        return prime[a];
    FOR0(i,SZ(p))
    {
        if(a%p[i] == 0)
            return false;
    }
    p.pb(a);
    return true;
}
int main()
{
    pre();
    ll n,m;
    while(scanf("%lld %lld", &n,&m) == 2)
    {
        ll a = -1,b = INF,c = -1,d = -1;
        ll prev = -1,temp = -1;
        for(ll i = n ; i < m+1 ; i++)
        {
            if(isprime(i))
            {
                if(prev == -1)
                    prev = i;
                else
                {
                    temp = i;
                    if(temp-prev > d-c)
                        d = temp, c = prev;
                    if(temp-prev < b-a)
                        b = temp, a = prev;
                    prev = temp;
                }
            }
        }
        if(a == -1 || b == -1)
            cout << "There are no adjacent primes." << endl;
        else
            cout << a << "," << b << " are closest, " << c << "," << d << " are most distant." << endl;
    }
}