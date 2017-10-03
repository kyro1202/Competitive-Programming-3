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
int main()
{
    int test; cin >> test; int ocunter = 0;
    while(test--)
    {
        char grid[105][105];
        int moves[105][105];
        ocunter++;
        cin >> n;
        memset(moves,0,sizeof(moves));
        FOR0(i,n)
            cin >> grid[i];
        FOR0(i,n)
            if(grid[0][i] != 'B') moves[0][i] = 1;
        FOR0(i,n)
        {
            FOR0(j,n)
            {
                if(i+1 < n && j+1 < n)
                {
                    if(grid[i+1][j+1] != 'B')
                        moves[i+1][j+1] = (moves[i+1][j+1] + moves[i][j])%1000007;
                    else if(i+2 < n && j+2 < n)
                    {
                        if(grid[i+2][j+2] != 'B')
                            moves[i+2][j+2] = (moves[i+2][j+2] + moves[i][j])%1000007;
                    }
                }
                if(i+1 < n && j-1 >= 0)
                {
                    if(grid[i+1][j-1] != 'B')
                    moves[i+1][j-1] = (moves[i+1][j-1] + moves[i][j])%1000007;
                    else if(i+2 < n && j-2 >= 0)
                    {
                        if(grid[i+2][j-2] != 'B')
                            moves[i+2][j-2] = (moves[i+2][j-2] + moves[i][j])%1000007;
                    }
                }
            }
        }
        long int ans = 0;
        FOR0(i,n)
            FOR0(j,n)
            {
                if(grid[i][j] == 'W')
                {
                    ans = moves[i][j];
                    break;
                }
            }
        cout << "Case " << ocunter << ": " << ans << endl;
    }
}