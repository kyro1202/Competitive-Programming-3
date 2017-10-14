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
double prob[16][16];
string teams[16];
double ans[16][4];
int main()
{
    FOR0(i,16)
        cin >> teams[i];
    FOR0(i,16)
        FOR0(j,16)
        {
            cin >> prob[i][j];
            prob[i][j] /= 100;
        }
    FOR0(i,16)
    {
        if(i%2)
            ans[i][0] = prob[i][i-1];
        else
            ans[i][0] = prob[i][i+1];
    }
    FOR0(i,16)
    {
        if(i < 4)
        {
            if(i < 2)
                ans[i][1] = ans[i][0]*(ans[2][0]*prob[i][2]+ans[3][0]*prob[i][3]);
            else
                ans[i][1] = ans[i][0]*(ans[0][0]*prob[i][0]+ans[1][0]*prob[i][1]);
        }
        else if(i < 8)
        {
            if(i < 6)
                ans[i][1] = ans[i][0]*(ans[6][0]*prob[i][6]+ans[7][0]*prob[i][7]);
            else
                ans[i][1] = ans[i][0]*(ans[4][0]*prob[i][4]+ans[5][0]*prob[i][5]);
        }
        else if(i < 12)
        {
            if(i < 10)
                ans[i][1] = ans[i][0]*(ans[10][0]*prob[i][10]+ans[11][0]*prob[i][11]);
            else
                ans[i][1] = ans[i][0]*(ans[8][0]*prob[i][8]+ans[9][0]*prob[i][9]);
        }
        else
        {
            if(i < 14)
                ans[i][1] = ans[i][0]*(ans[14][0]*prob[i][14]+ans[15][0]*prob[i][15]);
            else
                ans[i][1] = ans[i][0]*(ans[12][0]*prob[i][12]+ans[13][0]*prob[i][13]);
        }
    }
    FOR0(i,16)
    {
        if(i < 8)
        {
            if(i < 4)
            {
                double temp = 0;
                FOR(j,4,8)
                    temp += ans[j][1]*prob[i][j];
                ans[i][2] = ans[i][1]*temp;
            }
            else
            {
                double temp = 0;
                FOR(j,0,4)
                    temp += ans[j][1]*prob[i][j];
                ans[i][2] = ans[i][1]*temp;
            }
        }
        else
        {
            if(i < 12)
            {
                double temp = 0;
                FOR(j,12,16)
                    temp += ans[j][1]*prob[i][j];
                ans[i][2] = ans[i][1]*temp;
            }
            else
            {
                double temp = 0;
                FOR(j,8,12)
                    temp += ans[j][1]*prob[i][j];
                ans[i][2] = ans[i][1]*temp;
            }
        }
    }
    FOR0(i,16)
    {
        if(i < 8)
        {
            double temp = 0;
            FOR(j,8,16)
                temp += ans[j][2]*prob[i][j];
            ans[i][3] = ans[i][2]*temp;
        }
        else
        {
            double temp = 0;
            FOR(j,0,8)
                temp += ans[j][2]*prob[i][j];
            ans[i][3] = ans[i][2]*temp;
        }
    }
    FOR0(i,16)
    {
        cout << teams[i];
        ans[i][3] *= 100;
        FOR(j,teams[i].length(),11)
            cout << " ";
        cout << "p=" << setprecision(2) << fixed << ans[i][3];
        cout << "%" << endl;
    }
}