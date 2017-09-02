#include <bits/stdc++.h>
using namespace std;
bool profit(int ar[],int s,int d,int month)
{
    if(month > 4)
    {
        int tot = accumulate(ar+month-5,ar+month,0);
        if(tot > 0)
        return false;
    }
    if(month == 12)
    {
        int ans = accumulate(ar,ar+12,0);
        if(ans > 0)
        cout << ans << endl;
        else
        cout << "Deficit" << endl;
        return true;
    }
    ar[month] = s;
    if(!profit(ar,s,d,month+1))
    {
        ar[month] = -d;
        return profit(ar,s,d,month+1);
    }
    return true;
}
int main()
{
    int s,d;
    while(scanf("%d %d", &s,&d) == 2)
    {
        int ar[12];
        profit(ar,s,d,0);
    }
}