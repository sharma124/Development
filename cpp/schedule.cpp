#include <iostream>
#include <vector>

using namespace std;

int maxEvents(vector<vector<int> >& events)
{
    int n = events.size();
    int i, j;
    int endtime, cnt;
    int max=0;
    //vector<int> *p;

    for (i=1; i<(1<<n); i++)
    {
        endtime = 0; cnt=0;
        for (j=0; j<n; j++)
        {
            //p = &events[j];
            if ((i & (1<<j))  && (endtime <= events[j][0]))
            {
                cnt++;
                endtime = events[j][1];
            }
        }

        if (max < cnt)
        {
            max = cnt;
        }
    }

    return max;
}

int main()
{
    vector<vector<int> > vect(7, vector<int> (2));


    vect[0][0] = 1;
    vect[0][1] = 1;
    vect[1][0] = 1;
    vect[1][1] = 2;
    vect[2][0] = 1;
    vect[2][1] = 3;
    vect[3][0] = 1;
    vect[3][1] = 4;
    vect[4][0] = 1;
    vect[4][1] = 5;
    vect[5][0] = 1;
    vect[5][1] = 6;
    vect[6][0] = 1;
    vect[6][1] = 7;
        //[[1,1],[1,2],[1,3],[1,4],[1,5],[1,6],[1,7]]
       // {1, 2},{2,3},{3,4},{1,2}

    cout<<maxEvents(vect);

    cout<<"\n";
    return 0;
}
