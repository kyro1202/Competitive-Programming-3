#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m,n;
    while(true)
    {
        if( scanf("%d",&m) != 1)
        break;
        scanf("%d",&n);
        int mat[n][m];
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            mat[i][j] = 0;
        }
        int num,temp; vector<int> index;
        for(int i = 0 ; i < m ; i++)
        {
            index.clear();
            cin >> num;
            for(int j = 0 ; j < num ; j++)
            {
                cin >> temp;
                index.push_back(temp);
            }
            for(int j = 0 ; j < num ; j++)
            {
                cin >> temp;
                mat[index[j]-1][i] = temp;
            }
        }
        cout << n << " " << m << endl;
        vector<int> values;
        for(int i = 0 ; i < n ; i++)
        {
            index.clear();
            values.clear();
            int printed = 0;
            for(int j = 0 ; j < m ; j++)
            {
                if(mat[i][j])
                { index.push_back(j+1); values.push_back(mat[i][j]); }
            }
            cout << index.size();
            for(int j = 0 ; j < index.size() ; j++)
            {
                cout << " ";
                cout << index[j];
            }
            cout << endl;
            for(int j = 0 ; j < values.size() ; j++)
            {
                if(j)
                cout << " ";
                cout << values[j];
            }
            cout << endl;
        }
    }
}