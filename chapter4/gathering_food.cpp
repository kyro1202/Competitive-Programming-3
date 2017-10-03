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
char grid[11][11];
int dx[] = { 1 , -1 , 0 , 0 };
int dy[] = { 0 , 0 , 1 , -1 };
int dp[11][11];
int ways[11][11];
int main()
{
    int counter = 0;
    while(cin >> n)
    {
        counter++;
        int tot = 0,cx,cy;
        int dist = 0;
        long long int ret = 1;
        if(!n)
            break;
        FOR0(i,n)
            cin >> grid[i];
        FOR0(i,n)
            FOR0(j,n)
            {
                if(grid[i][j] >= 'A' && grid[i][j] <= 'Z')
                    tot++;
                if(grid[i][j] == 'A')
                {
                    cx = i; cy = j;
                }
            }
        FOR(k,1,tot)
        {
            FOR0(i,n)
                FOR0(j,n)
                {
                    dp[i][j] = INF; ways[i][j] = 0;
                }
            dp[cx][cy] = 0;
            ways[cx][cy] = 1;
            queue<ii> q;
            q.push(mp(cx,cy));
            grid[cx][cy] = '.';
            while(!q.empty())
            {
                int x = q.front().ff,y = q.front().ss;
                if(grid[x][y] == 'A'+k)
                {
                    ret *= ways[x][y];
                    ret = ret%20437;
                    dist += dp[x][y];
                    cx = x; cy = y;
                    break;
                } 
                q.pop();
                FOR0(i,4)
                {
                    int xx = x + dx[i],yy = y + dy[i],cc = dp[x][y]+1;
                    if(xx < 0 || xx >= n || yy < 0 || yy >= n || (grid[xx][yy] != '.' && grid[xx][yy] != 'A'+k) || cc > dp[xx][yy])
                        continue;
                    ways[xx][yy] += ways[x][y];
                    ways[xx][yy] = ways[xx][yy]%20347;
                    if(cc < dp[xx][yy])
                    {
                        dp[xx][yy] = dp[x][y] + 1;
                        q.push(mp(xx,yy));
                    }
                }
            }
            if(q.empty())
            {
                ret = 0; break;
            }
        }
        ret = ret%20347;
        cout << "Case " << counter << ": ";
        if(ret == 0)
            cout << "Impossible" << endl;
        else
            cout << dist << " " << ret << endl;
    }
}