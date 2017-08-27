#include <bits/stdc++.h>
using namespace std;

int main()
{
    int hours,min;
    while(true)
    {
        scanf("%d:%d", &hours,&min);
        if( !hours && !min )
        break;
        float angle;
        angle = hours/12.0 * 360.0;
        angle += min/2.0;
        angle -= min/60.0 * 360.0;
        angle = abs(angle);
        if(angle > 180)
        { angle = 360 - angle; printf("%.3f\n", angle); }
        else
        printf("%.3f\n", angle);  
    }
}