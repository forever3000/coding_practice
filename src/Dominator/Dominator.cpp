// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> stack;
    int most_occurence;
    int most_index;
    int count = 0;
    
    if (A.size() == 0)
    {
        return -1;
    }
    
    for (unsigned int i =0; i < A.size(); i++)
    {
        if (stack.size() == 0)
        {
            stack.push_back(A.at(i));
        }
        else
        {
            if (stack.at(stack.size() - 1) == A.at(i))
            {
                stack.push_back(A.at(i));
            }
            else
            {
                stack.pop_back();
            }
        }
    }
    
    if (stack.size() == 0)
    {
        return - 1;
    }
    
    most_occurence = stack.at(stack.size() - 1);
    
    for (unsigned int i = 0; i < A.size(); i++)
    {
        if (most_occurence == A.at(i))
        {
            most_index = i;
            count ++;        
        }
    }
    
    if (count > (A.size()/2))
        return most_index;
    else
        return -1;
}