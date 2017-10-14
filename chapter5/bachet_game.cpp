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
int n,m;
vi s;
bool memo[1000005];
int main()
{
    SYNC
    int temp;
    while(cin >> n >> m)
    {
        s.clear();
        FOR0(i,m)
        {
            cin >> temp;
            memo[temp] = true;
            s.pb(temp);
        }
        FOR0(i,n+1)
            memo[i] = false;
        memo[0] = false;
        FOR(i,1,n+1)
        {
            FOR0(j,m)
            {
                if(i >= s[j] && !memo[i-s[j]])
                {
                    memo[i] = true;
                }
            }
        }
        if(memo[n])
            cout << "Stan wins" << endl;
        else
            cout << "Ollie wins" << endl;
    }
}