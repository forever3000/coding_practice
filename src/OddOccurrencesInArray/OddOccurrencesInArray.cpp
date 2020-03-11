// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int result = 0;
    unsigned int i =0;
    
    for (i = 0; i < A.size(); i++)
    {
        result = result ^ A.at(i);
    }
    
    return result;
}