#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > table;
bool r[30],ld[30],rd[30];
int ans[92][8]; int temp[8]; int mark;
void backtrack(vector<int> col,int ind)
{
    if(ind == 8)
    {
        table.push_back(col);
        return;
    }
    for(int i = 0 ; i < 8 ; i++)
    {
        if( !r[i] && !ld[8 + i - ind] && !rd[i + ind])
        {
            col.push_back(i);
            r[i] = ld[8+i-ind] = rd[i+ind] = true;
            backtrack(col,ind+1);
            r[i] = ld[8+i-ind] = rd[i+ind] = false;
            col.erase(find(col.begin(),col.end(),i));
        }
    }
}
int main()
{
    for(int i = 0 ; i < 30 ; i++)
    {
        r[i] = ld[i] = rd[i] = false;
    }
    mark = 0;
    vector<int> col;
    backtrack(col,0);
    int temp;
    int count = 0;
    while(scanf("%d", &temp) == 1)
    {
        count++;
        col.clear();
        col.push_back(temp-1);
        for(int i = 1 ; i < 8 ; i++)
        {
            cin >> temp;
            col.push_back(temp-1);
        }
        int minsteps = 10;
        for(int i = 0 ; i < 92 ; i++)
        {
            int steps = 0;
            for(int j = 0 ; j < 8 ; j++)
            {
                if(col[j] != table[i][j])
                steps++;
            }
            minsteps = min(steps,minsteps);
        }
        cout << "Case " << count << ": " << minsteps << endl;
    }
}