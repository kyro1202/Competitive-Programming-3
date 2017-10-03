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
queue<ii> bfs;
int grid[2005][2005];
int level[2005][2005];
int dx[4] = { 0 , 0 , 1 , -1 };
int dy[4] = { 1 , -1 , 0 , 0 };
int find()
{
    while(!bfs.empty())
    {
        ii u = bfs.front(); bfs.pop();
        FOR0(i,4)
        {
            if(u.ff+dx[i] < 0 || u.ff+dx[i] >= 2001 || u.ss+dy[i] < 0 || u.ss+dy[i] >= 2001)
                continue;
            if(level[u.ff+dx[i]][u.ss+dy[i]] == -1)
            {
                level[u.ff+dx[i]][u.ss+dy[i]] = level[u.ff][u.ss]+1;
                bfs.push(mp(u.ff+dx[i],u.ss+dy[i]));
                if(grid[u.ff+dx[i]][u.ss+dy[i]] == 2)
                    return level[u.ff+dx[i]][u.ss+dy[i]];
            }
        }
    }
    return -1;
}
int main()
{
    int a; int x,y;
    while(cin >> a)
    {
        if(!a)
            break;
        while(!bfs.empty())
            bfs.pop();
        memset(grid,0,sizeof(grid));
        memset(level,-1,sizeof(level));
        FOR0(i,a)
        {
            cin >> x >> y;
            bfs.push(mp(x,y));
            level[x][y] = 0;
            grid[x][y] = 1;
        }
        cin >> a;
        FOR0(i,a)
        {
            cin >> x >> y;
            grid[x][y] = 2;
        }
        cout << find() << endl;
    }
}