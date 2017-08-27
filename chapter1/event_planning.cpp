#include <bits/stdc++.h>

using namespace std;

int main()
{
    int pants,hotels,weeks; long int budget,price; 
    while( scanf("%d%ld%d%d", &pants,&budget,&hotels,&weeks) != EOF )
    {
        int temp,max = 0,mark = 0;
        //cin >> pants >> budget >> hotels >> weeks;
        long int pricelist[19];
        for(int i = 0 ; i < hotels ; i++)
        {
            cin >> price;
            for(int j = 0 ; j < weeks ; j++)
            {
                cin >> temp;
                if(temp > max)
                max = temp;
            }
            if(max >= pants)
            { pricelist[mark] = price*pants; mark++; }
        }
        long int minelement = *min_element(pricelist,pricelist+mark);
        if(mark == 0 || minelement > budget )
        {
            cout << "stay home" << endl;
        }
        else
        {
            cout << minelement << endl;
        }
    }
}