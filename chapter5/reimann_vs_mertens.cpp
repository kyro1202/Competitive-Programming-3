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
#define MAX 1000001
int diff[MAX];
int mu[MAX],M[MAX];
void pre()
{
    memset(diff,0,sizeof(diff));
    memset(mu,2,sizeof(mu));
    mu[1] = 1; M[1] = 1;
    FOR(i,2,MAX)
    {
        if(diff[i] == 0)
            for(int j = i ; j < MAX ; j += i)
            {
                diff[j]++;
                if(j%(i*i) == 0)
                    mu[j] = 0;
            }
    }
    FOR(i,2,MAX)
    {
        if(mu[i] != 0)
        {
            if(diff[i]%2)
                mu[i] = -1;
            else
                mu[i] = 1;
        }
    }
    FOR(i,2,MAX)
        M[i] = M[i-1] + mu[i];
}
void print(int a)
{
    int mult = 1,digit = 0;
    if(a == 0)
        digit = 1;
    while(a/mult != 0)
    {
        digit++; mult *= 10;
    }
    if(a < 0)
        digit++;
    FOR0(i,8-digit)
        cout << " ";
    cout << a;
}
int main()
{
    SYNC
    int n;
    pre();
    while(cin >> n)
    {
        if(!n)
            break;
        print(n);  print(mu[n]);  print(M[n]);
        cout << endl;
    }
}