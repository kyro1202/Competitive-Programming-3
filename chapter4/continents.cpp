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
bool visited[22][22];
char field[22][22];
int m,n;
int dfs(int x,int y)
{
    if(visited[x][y])
        return 0;
    if(field[x][y] == 'w')
        return 0;
    visited[x][y] = true;
    int count = 1;
    if(x - 1 >= 0) count += dfs(x-1,y);
    if(x+1 < m) count += dfs(x+1,y);
    count += dfs(x,(y-1+n)%n);
    count += dfs(x,(y+1)%n);
    return count;
}
int main()
{
    int sx,sy;
    while(cin >> m >> n)
    {   
        string temp;
        memset(visited,false,sizeof(visited)); memset(field,'w',sizeof(field));
        FOR0(i,m)
        {
            cin >> temp;
            FOR0(j,n)
            {
                //mark[i][j] = -1;
                field[i][j] = temp[j];
            }
        }
        cin >> sx >> sy;
        char land = field[sx][sy];
        FOR0(i,m)
        {
            FOR0(j,n)
            {
                if(field[i][j] != land)
                    field[i][j] = 'w';
                else
                    field[i][j] = 'l';
            }
        }
        int ans = 0;
        dfs(sx,sy);
        FOR0(i,m)
        {
            FOR0(j,n)
            {
                if(!visited[i][j])
                    ans = max(ans,dfs(i,j));
            }
        }
            cout << ans << endl;
    }
}