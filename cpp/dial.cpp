#include <iostream>
#include <vector>

using namespace std;


void getCharacter (char &a, char &one, char &two, char &three, char &four)
{
    switch(a)
    {
        case '2':
            one = 'a';
            two = 'b';
            three = 'c';
            break;
        case '3':
            one = 'd';
            two = 'e';
            three = 'f';
            break;
        case '4':
            one = 'g';
            two = 'h';
            three = 'i';
            break;
        case '5':
            one = 'j';
            two = 'k';
            three = 'l';
            break;
        case '6':
            one = 'm';
            two = 'n';
            three = 'o';
            break;
        case '7':
            one = 'p';
            two = 'q';
            three = 'r';
            four = 's';
            break;
        case '8':
            one = 't';
            two = 'u';
            three = 'v';
            break;
        case '9':
            one = 'w';
            two = 'x';
            three = 'y';
            four = 'z';
            break;
        default:;
    }
}
    
void func(string &digits, int i, vector<string> &vect, string s)
{
    char a1 = 0, a2 = 0, a3 = 0, a4 = 0;

    if (i == digits.length())
    {
        vect.push_back(s);
        return;
    }
    getCharacter(digits[i], a1, a2, a3, a4);

    func (digits, i+1, vect, s+a1);
    func (digits, i+1, vect, s+a2);
    func (digits, i+1, vect, s+a3);

    if (a4)
    {
        func (digits, i+1, vect, s+=a4);
    }
}
    
vector<string> letterCombinations(string digits) {

    vector<string> a;
    string s;

    func(digits, 0, a, s);

    return a;
}

int main()
{
    string digit = "23";
    vector <string> x = letterCombinations(digit);

    for (int i=0; i<x.size(); i++)
    {
        cout<<x[i]<<" ";
    }

    return 0;
}
