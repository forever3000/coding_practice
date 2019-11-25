// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <iostream>
#include <vector>
using namespace std;


int match (char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
}

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    vector<char> A;
    
    if (S.length() == 0)
    {
        return 1;
    }
    else if (S.length() % 2 != 0)
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < S.length() ; i++)
        {
            if (S[i] == '(')
            {
                A.push_back(S[i]);            
            }
            else
            {
                if (A.size() == 0)
                {
                    return 0;
                }
                else
                {
                    char last = A.at(A.size() - 1);
                    A.pop_back();
                    
                    if (match(last, S[i]) == 0)
                    {
                        return 0;
                    }
                }
            }
        }
    }
    
    if (A.size() == 0)
        return 1;
    else
        return 0;
}