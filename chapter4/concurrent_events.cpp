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
int n,m;
bool adjmat[405][405];
int main()
{
    string s,t; int counter = 0;
    while(true)
    {
        cin >> n;
        if(!n)
            break;
        counter++;
        map<string,int> ind;
        vector<string> temp;
        FOR0(i,405)
            FOR0(j,405)
                adjmat[i][j] = false;
        int num = 0;
        FOR0(i,n)
        {
            cin >> m;
            int curr = num;
            FOR0(i,m)
            {
                cin >> s;
                temp.pb(s);
                ind[s] = num;
                num++;
            }
            FOR(i,curr,num-1)
            {
                adjmat[ind[temp[i]]][ind[temp[i+1]]] = true;
            }
        }
        cin >> m;
        FOR0(i,m)
        {
            cin >> s >> t;
            adjmat[ind[s]][ind[t]] = true;
        }
        FOR0(i,num)
            FOR0(j,num)
                FOR0(k,num)
                {
                    adjmat[j][k] |= (adjmat[j][i] & adjmat[i][k]);
                }
        int count = 0;
        string out = "";
        FOR0(i,num)
            FOR(j,i+1,num)
            {
                if(!adjmat[i][j] && !adjmat[j][i])
                {
                    count++;
                    if(count <= 2)
                    {
                        out += "(" + temp[i] + "," + temp[j] + ") ";
                    }
                }
            }
        cout << "Case " << counter << ", ";
        if(!count)
            cout << "no concurrent events." << endl;
        else
        {
            cout << count << " concurrent events:" << endl;
            cout << out << endl;
        }
    }
}