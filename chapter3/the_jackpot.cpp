#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    while(true)
    {
        int n; cin >> n;
        if(!n)
            break;
        int arr[n]; int minus = 0;
        for(int i = 0 ; i < n ; i++)
        {
            cin >> arr[i];
            if(arr[i] < 0)
            minus++;
        }
        if(minus == n)
        {
            cout << "Losing streak." << endl;
            continue;
        }
        int sum = 0,anx = -10000;
        for(int i = 0 ; i < n ; i++)
        {
            sum += arr[i];
            anx = max(anx,sum);
            if(sum < 0)
                sum = 0;
        }
        if(anx == 0)
        cout << "Losing streak." << endl;
        else
        cout << "The maximum winning streak is " << anx << ".\n";
    }
}