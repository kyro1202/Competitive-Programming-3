#include <bits/stdc++.h>
using namespace std;

int md[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int mdl[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
bool isleap(int year)
{
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}
int monthstodays(int month,int year)
{
    int temp = 0;
    for(int i = 0 ; i < month ; i++)
    {
        temp += md[i];
    }
    if(month > 1 && isleap(year))
    temp++;
    return temp;
}
int yearstodays(int year)
{
    int temp = year*365;
    temp += year/4 - year/100 + year/400;
    return temp;
}
int daystoyears(int* d)
{
    int year = 1;
    int yearsize = 365;
    while(*d > yearsize)
    {
        year++;
        *d -= yearsize;
        yearsize = (isleap(year)) ? 366 : 365 ;
    }
    return year;
}
int daystomonths(int* d,int year)
{
    int months = 0;
    int* monthsize = isleap(year) ? mdl : md;
    while(*d > monthsize[months])
    {
        *d -= monthsize[months];
        months++;        
    }
    return months+1;
}
int main()
{
    int days,dd,mm,yy;
    while(cin >> days >> dd >> mm >> yy, days + dd + mm + yy != 0)
    {
        --mm; --yy;
        days += dd;
        days += monthstodays(mm,yy);
        days += yearstodays(yy);
        yy = daystoyears(&days);
        mm = daystomonths(&days,yy);
        cout << days << " " << mm << " " << yy << endl;
    }
}