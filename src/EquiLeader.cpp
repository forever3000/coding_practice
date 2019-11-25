// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> stack;
    int most_occurence_value = 0;
    int most_occurence_count = 0;
    int temp_count = 0;
    int result = 0;
    
    if (A.size() < 2)
    {
        return 0;
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
        return 0;
    }
    
    most_occurence_value = stack.at(stack.size() - 1);
    
    for (unsigned int i = 0; i < A.size(); i++)
    {
        if (most_occurence_value == A.at(i))
        {
            most_occurence_count ++;        
        }
    }
    
    for (unsigned int i = 0; i < A.size(); i++)
    {
        if (most_occurence_value == A.at(i))
        {
            temp_count++;
        }
        
        if (temp_count > ((i + 1) / 2) && (most_occurence_count - temp_count) > (A.size() - (i+1))/2)
        {
            result ++;
        }
    }
    
    return result;
}