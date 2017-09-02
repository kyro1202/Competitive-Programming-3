#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > grid;
int main()
{
    int test,n,temp; cin >> test;
    while(test--)
    {
        int candy = 1001*8;
        grid.clear();
        cin >> n;
        vector<int> vt;
        for(int i = 0 ; i < n ; i++)
        {
            vt.clear();
            for(int j = 0 ; j < n ; j++)
            {
                cin >> temp;
                vt.push_back(temp);
            }
            grid.push_back(vt);
        }
        int choice[8] = {0,1,2,3,4,5,6,7};
        do
        {
            int sum = 0;
            for(int i = 0 ; i < n ; i++)
                sum += grid[i][choice[i]];
            candy = min(candy,sum);
        }while(next_permutation(choice,choice+n));
        cout << candy << endl;
    }
}