#include <bits/stdc++.h>
using namespace std;
int main()
{   
    int test,n; cin >> test;
    while(test--)
    {
        cin >> n;
        int arr[n];
        for(int i = 0 ; i < n ; i++)
        {
            cin >> arr[i];
        }
        int sum = 0;
        for(int i = 1 ; i < n ; i++)
        {
            for(int j = 0 ; j < i ; j++)
            {
                if(arr[j] <= arr[i])
                sum++;
            }
        }
        cout << sum << endl;
    }
}