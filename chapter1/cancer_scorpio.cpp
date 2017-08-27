#include <bits/stdc++.h>
using namespace std;

int md[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
string sign[] = {"capricorn","aquarius","pisces","aries","taurus","gemini","cancer","leo","virgo","libra","scorpio","sagittarius","capricorn"}; 
int dates[] = { 21,20,21,21,22,22,23,22,24,24,23,23 };
bool isleap(int year)
{
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}
int main()
{
    int days,dd,mm,yy,test; cin >> test; int count = 1; string s;
    while(test--)
    {
        cin >> s;
        days = 40*7;
        string temp = "";
        temp += s[0]; temp += s[1]; mm = atoi(temp.c_str());
        temp = ""; temp.append(s,2,2); dd = atoi(temp.c_str());
        temp = ""; temp.append(s,4,4); yy = atoi(temp.c_str());
        md[1] = isleap(yy) ? 29 : 28 ;
        while(days >= md[mm-1])
        {
            days -= md[mm-1];
            mm++;
            if( mm == 13 )
            {
                mm = 1; yy++; md[1] = isleap(yy) ? 29 : 28 ;
            }
        }
        dd += days;
        if(dd > md[mm-1] )
        {
            dd -= md[mm-1];
            mm++;
        }
        if( mm == 13)
        {
            mm = 1;
            yy++;
        }
        printf("%d %.2d/%.2d/%.2d ", count,mm,dd,yy);
        count++;
        if( dd >= dates[mm-1] )
        {
            cout << sign[mm] << endl;
        }
        else
        {
            cout << sign[mm-1] << endl;
        }
    }
}