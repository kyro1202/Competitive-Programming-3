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
vector<pair<int,ii> > E;
vi r,flag;
int p[105];
int n,m,sets;
int find(int a)
{
    return p[a] == a ? a : p[a] = find(p[a]);
}
void make(int a,int b)
{
    if(r[a] > r[b])
        p[b] = a;
    else
    {
        p[a] = b;
        if(r[a] == r[b])
            r[b]++;
    }
    sets--;
}
int main()
{
    int test; cin >> test;
    int a,b,c;
    while(test--)
    {
        cin >> n >> m;
        E.clear(); r.assign(n,0); flag.clear();
        FOR0(i,n)
            p[i] = i;
        FOR0(i,m)
        {
            cin >> a >> b >> c;
            a--; b--;
            E.pb(mp(c,mp(a,b)));
        }
        sort(E.begin(),E.end());
        int ans1 = 0;
        int count = 0;
        FOR0(i,SZ(E))
        {
            int x = find(E[i].ss.ff),y = find(E[i].ss.ss);
            if(x != y)
            {
                ans1 += E[i].ff;
                make(x,y);
                flag.pb(i);
                count++;
            }
        }
        int ans2 = INF;
        FOR0(j,count)
        {
            int temp = 0;
            for(int i = 0 ; i < n ; i++)
                p[i] = i;
            sets = n;
            FOR0(i,SZ(E))
            {
                if(i == flag[j])
                    continue;
                int x = find(E[i].ss.ff),y = find(E[i].ss.ss);
                if(x != y)
                {
                    temp += E[i].ff;
                    make(x,y);
                    flag[i] = 0;
                    count++;
                }
            }
            if(sets != 1)
                temp = INF;
            ans2 = min(ans2,temp);
        }
        if(ans2 == INF)
            ans2 = ans1;
        cout << ans1 << " " << ans2 << endl;
    }
}