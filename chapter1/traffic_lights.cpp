#include <bits/stdc++.h>
using namespace std;
int i;
bool lights(int a[],int b[],int c)
{
    for(int j = 0 ; j < i ; j++)
    {
        if( (c%b[j]) >= (a[j] - 5) )
        return false;
    }
    return true;
}

int main()
{
    while(true)
    {
        int time1[100];int temp; int time2[100]; int min = 1 << 8;
        i = 0;
        for( ; i < 101 ; i++)
        {
            cin >> temp;
            if(temp == 0 && i == 0)
            return 0;
            if(temp == 0)
            break;
            time1[i] = temp;
            if(temp < min)
            min = temp;
            time2[i] = 2*temp;
        }
        int sec = 2*min;
        bool allgreen = false;
        while(!allgreen && sec <= 5*3600)
        {
            allgreen = lights(time1,time2,sec);
            sec++;
        }
        sec--;
        if(allgreen)
        {
            int hours = sec/3600;
            int min = (sec%3600)/60;
            printf("%02d:%02d:%02d\n", hours,min,sec - hours*3600 - min*60);
        }
        else
        {
            cout << "Signals fail to synchronise in 5 hours" << endl;
        }
    }
}