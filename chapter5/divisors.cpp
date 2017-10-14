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
ll pf(ll a)
{
    factors.clear();
    int index = 0; int d = p[0];
    ll ret = 1;
    while(d*d <= a)
    {
        int count = 0;
        while(a%d == 0)
        {
            count++;
            a = a/d;
        }
        ret = ret*(count+1);
        if(index == p.size()-1)
            break;
        d = p[++index];
    }
    if(a != 1)  ret = ret*2;
    return ret;
}
int main()
{
    SYNC; 
    p.clear();
    pre();
    ll l,r; int test; cin >> test;
    while(test--)
    {
        cin >> l >> r;
        ll divi;
        ll val,num = 0;
        for(ll i = l ; i <= r ; i++)
        {
            divi = pf(i);
            if(divi > num)
            {
                val = i;
                num = divi;
            }
        }
        cout << "Between " << l << " and " << r << ", " << val << " has a maximum of " << num << " divisors." << endl; 
    }
}