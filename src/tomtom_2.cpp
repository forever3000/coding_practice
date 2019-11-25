#include <vector>
#include <iostream>
#include <string>
using namespace std;

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int isSort(vector<int> &A)
{
    for (unsigned int i = 0; i < A.size() - 1; i++)
    {
        if (A.at(i) > A.at(i + 1))
        {
            return 0;
        }
    }
    return 1;
}

bool solution() {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> A {1,5,3,3,7};
    int swap = 0;
    
    if (A.size() == 0)
    {
        return false;
    }
    else if (A.size() == 1 || isSort(A))
    {
        return true;
    }
    else
    {
        unsigned int temp_index = 0;
        int temp = A.at(0);
    
        for (unsigned int i = 0; i < A.size() - 1; i++)
        {
            if (A.at(i) > A.at(i + 1))
            {
                temp_index = i;
                temp = A.at(i);
                break;
            }
        }
        
        for (unsigned int i = temp_index + 1; i < A.size(); i++)
        {
            if (A.at(temp_index) <= A.at(i))
            {
                A.at(temp_index) = A.at(i - 1);
                A.at(i - 1) = temp;
                break;
            }
            
            if (i == A.size() - 1)
            {
                A.at(temp_index) = A.at(i);
                A.at(i) = temp;
                break;
            }
        }
        
        if (isSort(A))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int main (void)
{
    if (solution())
        cout << "True";
    else
        cout << "False";
        
        
    return 0;
}
