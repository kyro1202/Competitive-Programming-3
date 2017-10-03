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
vector<string> dic;
map<string,int> level;
map<string,vector<string> > adj;
bool check(string a,string b)
{
    if(a.length() != b.length())
        return false;
    int diff = 0;
    FOR0(i,SZ(a))
    {
        if(a[i] != b[i])
        {
            diff++;
            if(diff == 2)
                return false;
        }
    }
    if(diff == 1)
        return true;
    return false;
}
int main()
{
    int test; cin >> test;
    string word,s,d;
    while(test--)
    {
        dic.clear(); adj.clear();
        while(cin >> word)
        {
            if(word[0] == '*')
                break;
            dic.pb(word);
            FOR0(i,SZ(dic))
            {
                if(check(word,dic[i]))
                {
                    adj[word].pb(dic[i]);
                    adj[dic[i]].pb(word);
                }
            }
        }
        getline(cin,word);
        while(getline(cin,word))
        {
        if(word == "")
            break;
        int pos = word.find(" ");
        s = word.substr(0,pos);
        d = word.substr(pos+1,word.length());
        queue<string> bfs;
        bfs.push(s);
        level.clear();
        level[s] = 0;
        while(!bfs.empty())
        {
            string u = bfs.front(); bfs.pop();
            if(u == d)
                break;
            FOR0(i,SZ(adj[u]))
            {
                if(!level.count(adj[u][i]))
                {
                    level[adj[u][i]] = level[u] + 1;
                    bfs.push(adj[u][i]);
                }
            }
        }
        cout << s << " " << d << " " << level[d] << endl;
        }
        if(test)
        cout << endl;
    }
}