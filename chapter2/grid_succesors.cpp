#include <bits/stdc++.h>
using namespace std;

int grid[3][3];

void transform()
{
    int temp[3][3];
    temp[0][0] = grid[0][1] + grid[1][0];
    temp[0][1] = grid[0][0] + grid[0][2] + grid[1][1];
    temp[0][2] = grid[0][1] + grid[1][2];
    temp[1][0] = grid[0][0] + grid[2][0] + grid[1][1];
    temp[1][1] = grid[0][1] + grid[2][1] + grid[1][0] + grid[1][2];
    temp[1][2] = grid[0][2] + grid[2][2] + grid[1][1];
    temp[2][0] = grid[1][0] + grid[2][1];
    temp[2][1] = grid[2][0] + grid[2][2] + grid[1][1];
    temp[2][2] = grid[2][1] + grid[1][2];

    for(int i = 0 ; i < 3 ; i++)
        for(int j = 0 ; j < 3 ; j++)
            grid[i][j] = temp[i][j]%2;

    return;        
}
bool iszero()
{
    for(int i = 0 ; i < 3 ; i++)
    {
        for(int k = 0 ; k < 3 ; k++)
        {
            if(grid[i][k] != 0)
            return false;
        }
    }
    return true;
}
int main()
{
    int test; cin >> test;
    
    while(test--)
    {
        for(int i = 0 ; i < 3 ; i++)
        {
            for(int j = 0 ; j < 3 ; j++)
                scanf("%1d", &grid[i][j]);                  
        }

        int ans = -1;
        while(!iszero())
        {
            transform();
            ans++;
        }

        printf("%d\n", ans);
    }
}