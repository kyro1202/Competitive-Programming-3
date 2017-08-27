#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test,temp;
    map<set<int>,int> list;
    map<set<int>,int>::iterator it;
    set<int> course;
    while(true)
    {
        cin >> test;
        if(!test)
            break;
        list.clear();
        course.clear();
        for(int i = 0 ; i < test ; i++)
        {
            course.clear();
            for(int j = 0 ; j < 5 ; j++)
            {
                cin >> temp;
                course.insert(temp);
            }
            it = list.find(course);
            if(it != list.end())
                list[course] += 1;
            else
                list[course] = 1;
        }
        int currmax = 0,stud = 0;
        bool changed = false;
        it = list.begin();
        /*while(it != list.end())
        {
            cout << (*it).first.size() << " " << (*it).second << endl;
            it++;
        }*/
        while(it != list.end())
        {
            if((*it).second > currmax)
            {
                currmax = (*it).second;
                stud = currmax;
            }
            else if((*it).second == currmax)
                stud += currmax;
            it++;
        }
        cout << stud << endl;
    }
}