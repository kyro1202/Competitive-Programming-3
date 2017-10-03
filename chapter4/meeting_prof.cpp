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
int n;
int adjmat1[26][26];
int adjmat2[26][26];
int main()
{
    char a,b,c,d;
    int cost;
    while(cin >> n)
    {
        if(!n)
            break;
        FOR0(i,26)
        {
            FOR0(j,26)
            {
                adjmat1[i][j] = INF;
                adjmat2[i][j] = INF;
            }
            adjmat1[i][i] = adjmat2[i][i] = 0;
        }
        FOR0(i,n)
        {
            cin >> a >> b >> c >> d >> cost;
            if(a == 'Y')
            {
                adjmat1[c-'A'][d-'A'] = min(cost,adjmat1[c-'A'][d-'A']);
                if(b == 'B')
                adjmat1[d-'A'][c-'A'] = min(cost,adjmat1[d-'A'][c-'A']);
            }
            else
            {
                adjmat2[c-'A'][d-'A'] = min(cost,adjmat2[c-'A'][d-'A']);
                if(b == 'B')
                adjmat2[d-'A'][c-'A'] = min(cost,adjmat2[d-'A'][c-'A']);
            }
        }
        FOR0(i,26)
            FOR0(j,26)
                FOR0(k,26)
                {
                    adjmat1[j][k] = min(adjmat1[j][k],adjmat1[j][i]+adjmat1[i][k]);
                    adjmat2[j][k] = min(adjmat2[j][k],adjmat2[j][i]+adjmat2[i][k]);
                }
        cin >> a >> b;
        int ans = INF;
        vector<char> out;
        FOR0(i,26)
        {
            int curr = adjmat1[a-'A'][i] + adjmat2[b-'A'][i];
            if(curr < ans)
            {
                ans = curr;
                out.clear();
                out.pb(i+'A');
            }
            else if(curr == ans)
                out.pb(i+'A');
        }
        if(ans == INF)
            cout << "You will never meet." << endl;
        else
        {
            cout << ans;
            FOR0(i,SZ(out))
                cout << " " << out[i];
            cout << endl;
        }
    }
}