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
int m,n,sx,sy,dx,dy,d;
int grid[53][53];
int level[4][53][53];
int dir[4] = {0,1,2,3};
int dirx[4] = {0,0,1,-1};
int diry[4] = {1,-1,0,0};

bool check(int x, int y)
{
    if(x<=0 || y<=0 || x>=m || y>=n) 
        return false;
    if(grid[x-1][y-1]) return false;
    if(grid[x-1][y]) return false; 
    if(grid[x][y-1]) return false;
    if(grid[x][y]) return false;
    
    return true;
}
int main()
{
    string temp;
    while(cin >> m >> n)
    {
        if(!(m+n))
            break;
        memset(level,-1,sizeof(level));
        FOR0(i,m)
            FOR0(j,n)
                cin >> grid[i][j];
        cin >> sx >> sy >> dx >> dy;
        cin >> temp;
        if(temp[0] == 'n')
            d = 0;
        else if(temp[0] == 'e')
            d = 1;
        else if(temp[0] == 's')
            d = 2;
        else
            d = 3;
        queue<pair<int,ii> > bfs;
        bfs.push(mp(d,mp(sx,sy)));
        level[d][sx][sy] = 0;
        while(!bfs.empty())
        {
            pair<int,ii> u = bfs.front(); bfs.pop();
            if(level[(u.ff+1)%4][u.ss.ff][u.ss.ss] == -1)
            {
                level[(u.ff+1)%4][u.ss.ff][u.ss.ss] = level[u.ff][u.ss.ff][u.ss.ss] + 1;
                bfs.push(mp((u.ff+1)%4,mp(u.ss.ff,u.ss.ss)));
            }
            if(level[(u.ff-1)%4][u.ss.ff][u.ss.ss] == -1)
            {
                level[(u.ff-1)%4][u.ss.ff][u.ss.ss] = level[u.ff][u.ss.ff][u.ss.ss] + 1;
                bfs.push(mp((u.ff-1)%4,mp(u.ss.ff,u.ss.ss)));
            }
            for(int i=1;i<=3;i++)
            {
                if(check(u.ss.ff+dirx[u.ff]*i,u.ss.ss+diry[u.ff]*i))
                {
                    if(level[u.ff][u.ss.ff+dirx[u.ff]*i][u.ss.ss+diry[u.ff]*i] != -1) 
                        continue;
                    level[u.ff][u.ss.ff+dirx[u.ff]*i][u.ss.ss+diry[u.ff]*i]=level[u.ff][u.ss.ff][u.ss.ss] + 1;
                    bfs.push(mp(u.ff,mp(u.ss.ff+dirx[u.ff]*i,u.ss.ss+diry[u.ff]*i)));
                }
                else 
                    break;
            }
        }
        cout << min(min(level[0][dx][dy],level[1][dx][dy]),min(level[2][dx][dy],level[3][dx][dy])) << endl;
    }
}