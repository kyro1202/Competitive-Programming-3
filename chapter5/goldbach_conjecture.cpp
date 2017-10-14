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
bool prime[1000000];
void pre()
{
    memset(prime,true,sizeof(prime));
    prime[0] = prime[1] = false;
    for(ll i = 2 ; i < 1000000 ; i++)
    {
        if(!prime[i])
            continue;
        for(ll j = i*i ; j < 1000000 ; j += i)
            prime[j] = false;
    }
}
int main()
{
    SYNC
    pre();
    int n;
    while(cin >> n)
    {
        if(!n)
            break;
        int a = -1,b = -1;
        FOR(i,2,n/2+1)
        {
            if(prime[i] && prime[n-i])
            {
                a = i; b = n-i;
                break;
            }
        }
        if(a > b) swap(a,b);
        if(a == -1 || b == -1)
            cout << "Goldbach's conjecture is wrong." << endl;
        else
            cout << n << " = " << a << " + " << b << endl;
    }
}