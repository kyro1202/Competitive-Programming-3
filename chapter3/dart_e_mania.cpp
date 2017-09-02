#include <bits/stdc++.h>
using namespace std;
void line()
{
    for(int i = 0 ; i < 70 ; i++)
        cout << "*";
    cout << endl;
}
int main()
{
    int n; bool taken[61][61][61];
    while(true)
    {
        cin >> n;
        if(n < 1)
        {
            cout << "END OF OUTPUT" << endl;
            break;
        }
        set<int> scores;
        for(int i = 1 ; i <= 20 ; i++)
        {
            scores.insert(i);
            scores.insert(2*i);
            scores.insert(3*i);
        }
        memset(taken,false,sizeof(taken));
        scores.insert(50); int p = 0,c = 0;
        scores.insert(0);
        vector<int> values(scores.begin(),scores.end());
        for(int i = 0 ; i < values.size() ; i++)
        {
            for(int j = 0 ; j < values.size() ; j++)
            {
                for(int k = 0 ; k < values.size() ; k++)
                {
                    if((values[i]+values[j]+values[k]) != n)
                        continue;
                    p++;
                    if(!taken[values[i]][values[j]][values[k]])
                    {
                        c++;
                        taken[values[i]][values[j]][values[k]] = true;
                        taken[values[i]][values[k]][values[j]] = true;
                        taken[values[j]][values[i]][values[k]] = true;
                        taken[values[j]][values[k]][values[i]] = true;
                        taken[values[k]][values[j]][values[i]] = true;
                        taken[values[k]][values[i]][values[j]] = true;
                    }
                }
            }
        }
        if(p != 0 && c != 0)
        {
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << c << "." << endl;
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << p << "." << endl;
            line();
        }
        else
        {
            cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS." << endl;
            line();
        }
    }
}