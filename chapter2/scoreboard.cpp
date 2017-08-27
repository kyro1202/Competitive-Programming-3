#include <bits/stdc++.h>
using namespace std;

struct contestant
{
    bool solved[10];
    int score,time,attempt[10];
};

map<int,contestant> scoreboard;

bool myfun(int a,int b)
{
    if(scoreboard[a].score != scoreboard[b].score)
        return scoreboard[a].score > scoreboard[b].score;
    if(scoreboard[a].time != scoreboard[b].time)
        return scoreboard[a].time < scoreboard[b].time;
    return a < b;
}
int main()
{
    int test; cin >> test;
    string temp; getline(cin,temp); getline(cin,temp);
    string ss;
    stringstream s;
    while(test--)
    {
        vector<int> index;
        scoreboard.clear(); 
        int c,p,t; char r;
        while(true)
        {
            getline(cin,ss);
            if(!ss.length())
                break;
            s.clear();
            s << ss;
            s >> c >> p >> t >> r;
            //cout << c << p << t << r;
            if(scoreboard.find(c) == scoreboard.end())
            {
                contestant fresh;
                memset(fresh.solved,false,sizeof(fresh.solved));
                memset(fresh.attempt,0,sizeof(fresh.attempt));
                fresh.score = 0; fresh.time = 0;
                index.push_back(c);
                scoreboard[c] = fresh;
            }
            if(r == 'C' || r == 'I')
            {
                if(scoreboard[c].solved[p] == true)
                    continue;
                if(r == 'C')
                {
                    scoreboard[c].solved[p] = true;
                    scoreboard[c].time += (20*scoreboard[c].attempt[p]) + t;
                    scoreboard[c].score += 1;
                }
                else
                    scoreboard[c].attempt[p] += 1;    
            }
        }
        sort(index.begin(),index.end(),myfun);
        for(int i = 0 ; i < index.size() ; i++)
        {
            cout << index[i] << " " << scoreboard[index[i]].score << " " << scoreboard[index[i]].time << endl;
        }
        if(test)
            cout << endl;
    }
}