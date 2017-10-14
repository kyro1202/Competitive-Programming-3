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
int grid[7];
int get(int left,int id)
{
    if(left == 0)
        return 1-id;
    int ret = 1 - id;
    FOR(i,1,7)
    {
        if(grid[i] > 0 && left-i >= 0)
        {
            grid[i]--;
            int win = get(left-i,1-id);
            if(win == id)
                ret = id;
            grid[i]++;
        }
    }
    return ret;
}
int main()
{
    SYNC
    string s;
    while(cin >> s)
    {
        int sum = 0;
        FOR(i,1,7)
        {
            grid[i] = 4;
        }
        FOR0(i,SZ(s))
        {
            sum += s[i] - '0';
            grid[s[i]-'0']--;
        }
        sum = 31-sum;
        cout << s << " ";
        int id = (s.length()%2 == 0) ? 0 : 1 ;
        int win = get(sum,id);
        if(win == 0)
            cout << "A" << endl;
        else
            cout << "B" << endl;
    }
}