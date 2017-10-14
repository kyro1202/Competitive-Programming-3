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
#define MAX 2000001
int diff[MAX];
ll phi[MAX];
ll dphi[MAX];
ll SODF[MAX];
int get(int a)
{
    if(a == 1)
        return 1;
    if(dphi[a] != -1)
        return dphi[a]+1;
    ll ret = 1;
    ret += get(phi[a]);
    return dphi[a] = ret;
}
void pre()
{
    memset(diff,0,sizeof(diff));
    memset(dphi,-1,sizeof(dphi));
    phi[1] = 1;
    FOR(i,2,MAX)
        phi[i] = i;
    FOR(i,2,MAX)
    {
        if(diff[i] == 0)
            for(int j = i ; j < MAX ; j += i)
            {
                diff[j]++;
                phi[j] -= phi[j]/i;
            }
    }
    FOR(i,2,MAX)
        dphi[i] = get(phi[i]);
    FOR(i,3,MAX)
        SODF[i] = SODF[i-1] + dphi[i];
}
int main()
{
    SYNC
    pre();
    int l,r,test; cin >> test;
    while(test--)
    {
        cin >> l >> r;
        //cout << dphi[13] << endl;
        cout << SODF[r] - SODF[l] + dphi[l] << endl;
    }
}