#include <bits/stdc++.h>
using namespace std;

string big[500],small[500];

int cal(int a,int b)
{
    int count = 0; int ans = 0;
    for(int i = 0 ; i < a ; i++)
    {
        for(int j = 0 ; j < a ; j++)
        {
            count = 0;
            for(int k = 0 ; k < b ; k++)
            {
                for(int l = 0 ; l < b ; l++)
                {
                    if(big[i+k][j+l] == small[k][l])
                        count++;
                }
            }
            if(count == b*b)
                ans++;
        }
    }
    return ans;
}
void rotate(int a)
{
    char temp[a][a];
    for(int i = 0 ; i < a ; i++)
    {
        for(int j = 0 ; j < a ; j++)
        {
            temp[i][j] = small[a-1-j][i];
        }
    }
    for(int i = 0 ; i < a ; i++)
    {
        for(int j = 0 ; j < a ; j++)
        {
            small[i][j] = temp[i][j];
        }
    }
    return;
}
int main()
{
    int n,m;
    while(true)
    {
        cin >> n >> m;
        if( n + m == 0 )
            break;
        for(int i = 0 ; i < n ; i++)
            cin >> big[i];
        for(int i = 0 ; i < m ; i++)
            cin >> small[i];
        for(int i = 0 ; i < 4 ; i++)
        {
            if(i)
                cout << " ";
            cout << cal(n,m);
            rotate(m);    
        }
        cout << endl;        
    } 
}        