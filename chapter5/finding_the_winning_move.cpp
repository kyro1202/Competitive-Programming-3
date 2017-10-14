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
int n = 4;
string grid[4];
int check()
{
    char prev;
    bool pos;
    FOR0(i,4)
    {
        pos = true;
        FOR0(j,4)
        {
            if(j == 0)
                prev = grid[i][j];
            else if(prev != grid[i][j])
            {   pos = false;    break;  }
            else
                prev = grid[i][j];
        }
        if(pos)
        {
            return (grid[i][0] == 'x') ? 1 : 0 ;
        }
    }
    FOR0(i,4)
    {
        pos = true;
        FOR0(j,4)
        {
            if(j == 0)
                prev = grid[j][i];
            else if(prev != grid[j][i])
            {   pos = false;    break;  }
            else
                prev = grid[j][i];
        }
        if(pos)
        {
            return (grid[0][i] == 'x') ? 1 : 0 ;
        }
    }
    if(grid[3][3] == grid[0][0] && grid[1][1] == grid[2][2] && grid[1][1] == grid[0][0])
        return (grid[0][0] == 'x') ? 1 : 0 ;
    if(grid[3][0] == grid[0][3] && grid[1][2] == grid[2][1] && grid[1][2] == grid[0][3])
        return (grid[0][0] == 'x') ? 1 : 0 ;
    return -1;
}
int get(int x,int y,int id)
{
    grid[x][y] = (id == 1) ? 'o' : 'x' ;
    int win = check();
    if(win != -1)
        return win;
    int ret = 1-id;
    FOR0(i,4)
        FOR0(j,4)
        {
            if(grid[i][j] == '.')
            {
                win = get(i,y,1-id);
                if(win == id)
                {
                    win = id;
                }
            }
            grid[i][j] = '.';
        }
    return win;    
}
int main()
{
    SYNC
    char c; string s;
    while(cin >> c)
    {
        if(c == '$')
            break;
        FOR0(i,4)
            cin >> grid[i];
        int win = -1;
        bool print = false;
        FOR0(i,4)
        {
            if(print)
                break;
            FOR0(j,4)
            {
                if(grid[i][j] == '.')
                {
                    win = get(i,j,0);
                    if(win == 0)
                    {
                        cout << "(" << i << "," << j << ")" << endl;
                        print = true;
                        break;
                    }
                }
            }
        }
        if(!print)
            cout << "#####" << endl;
    }
}