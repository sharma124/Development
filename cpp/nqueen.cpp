#include <iostream>
#define MAX 30

using namespace std;

//int dontrecur = 0;
void func(char mat[][MAX], int r);


int main()
{
    char mat[MAX][MAX];

    int i,j;

    //initializations
    for (i=0; i<MAX; i++)
    {
        for (j=0; j<MAX; j++)
        {
            mat[i][j] = '-';
        }
    }

    func(mat, 0);

    return 0;
}

bool safe(char mat[][MAX], int r, int c)
{
    int i,j;

    for (i=r-1; i>=0; i--)
    {
        if (mat[i][c] == 'Q')
        {
            return false;
        }
    }

    //diagonal left-up
    for (i=r-1, j=c-1; (i>=0  && j>=0); i--, j--)
    {
        if (mat[i][j] == 'Q')
        {
            return false;
        }
    }

    //diagonal right-up
    for (i=r-1, j=c+1; (i>=0 && j<MAX); i--, j++)
    {
        if (mat[i][j] == 'Q')
        {
            return false;
        }
    }

    return true;
}

void func(char mat[][MAX], int r)
{
    int i;
    static int dontrecur = 0;

    if (r == MAX)
    {
        for (int a=0; a<MAX; a++)
        {
            for (int b=0; b<MAX; b++)
            {
                cout<<mat[a][b]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";

        dontrecur = 1;

        return;
    }

    for (i=0; i<MAX; i++)
    {
        if (safe(mat, r, i))
        {
            mat[r][i] = 'Q';

            func(mat, r+1);

            if (dontrecur)
            {
                break;
            }

            mat[r][i] = '-';
        }
    }
}
