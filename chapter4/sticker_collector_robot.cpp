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
int n,m,s,sx,sy,dir,count1 = 0;
char grid[110][110];
string ins;
void solve()
{
    int x,y;
    for(int k = 0 ; k < s ; k++)
    {
        if(ins[k] == 'D')
            dir = (dir+1)%4;
        else if(ins[k] == 'E')
        {
            dir--;
            if(dir < 0)
                dir = 3;
        }
        else
        {
            x = sx; y = sy;
            if(dir == 0) x--;
            else if(dir == 1) y++;
            else if(dir == 2) x++;
            else y--;
            if (y<0 || y>=m || x<0 || x>=n || grid[x][y]=='#') continue;
            grid[sx][sy] = '.';
            if(grid[x][y] == '*')
                count1++;
            sx = x; sy = y;
        }
    }
}
int main()
{
    while(true)
    {
        count1 = 0;
        cin >> n >> m >> s;
        if(!(n+m+s))
            break;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                cin >> grid[i][j];
                if(grid[i][j] != '.' && grid[i][j] != '*' && grid[i][j] != '#')
                {
                    sx = i; sy = j;
                }
            }
        }
        if(grid[sx][sy] == 'N')
            dir = 0;
        if(grid[sx][sy] == 'L')
            dir = 1;
        if(grid[sx][sy] == 'S')
            dir = 2;
        if(grid[sx][sy] == 'O')
            dir = 3;
        cin >> ins;
        solve();
        cout << count1 << endl;
    }
}