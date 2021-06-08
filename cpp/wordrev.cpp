#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str[] = "  My name is aditya";
    char *ptr = str;
    char *start, *end;
    char prev = ' ', temp;

    while (1)
    {
        if (prev == ' ' && *ptr != ' ')
        {
            start = ptr;
        }

        if (prev != ' ' && ((*ptr == ' ') || (*ptr == 0)))
        {
            end = ptr -1;

            while (start < end)
            {
                temp = *start;
                *start = *end;
                *end = temp;
                start++; end--;
            }
        }

        prev = *ptr;
        ptr++;

        if (prev == 0)
        {
            break;
        }
    }

    start = str;
    end = str + (strlen(str) -1);

    cout<<"\n"<<str<<"\n";
    while (start < end)
    {
        temp = *start;
        *start = *end;
        *end = temp;
        start++; end--;
    }

    cout<<"\n"<<str<<"\n";
    return 0;
}
