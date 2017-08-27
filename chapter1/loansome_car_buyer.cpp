#include <bits/stdc++.h>
using namespace std;

int main()
{
    double loan,carcost,inst,tempd,downpay; int months,num,tempi;
    while(1)
    {
        int count = 0,track = 1,mark = 1;
        cin >> months >> downpay >> loan >> num;
        if(months < 0)
            break;
        inst = loan / months;    
        pair<int,double> array[num];
        for(int i = 0 ; i < num ; i++)
        {
            cin >> tempi >> tempd;
            array[i] = make_pair(tempi,tempd);
        }
        double perc; carcost = (loan + downpay)*(1 - array[0].second);
        while( carcost <= loan )
        {
            count++;
            loan -= inst;
            if(mark < num)
            {
            if(array[mark].first == track )
            {
                perc = array[mark].second; mark++;
            }
            }
            track++;
            carcost *= (1 - perc);
        } 
        if(count == 1)
        cout << "1 month" << endl;
        else
        cout << count << " months" << endl;   
    }
}