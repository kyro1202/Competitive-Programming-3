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
vector<double> prob;
int n,k,m;
double memo[1005];
double get(int gen)
{
    if(gen == 1)
        return prob[0];
    if(memo[gen] != -1.0)
        return memo[gen];
    double ret = 0;
    FOR0(i,n)
    {
        ret += (pow(get(gen-1),i)*prob[i]);
    }
    return memo[gen] = ret;
}
int main()
{
    SYNC
    int counter = 0;
    int test; cin >> test;
    double temp;
    while(test--)
    {
        cin >> n >> k >> m;
        FOR0(i,m+1)
            memo[i] = -1.0;
        prob.clear();
        counter++;
        FOR0(i,n)
        {
            cin >> temp;
            prob.pb(temp);
        }
        double ans = 0;
        ans = get(m);
        ans = pow(ans,k);
        cout << "Case #" << counter << ": ";
        cout << setprecision(7) << fixed << ans << endl;
    }
}