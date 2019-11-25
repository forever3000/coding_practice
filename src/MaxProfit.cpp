// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> stack;
    int max = 0;
    
    if (A.size() < 2)
    {
        return 0;
    }
    else
    {
        stack.push_back(A.at(0));
        for (unsigned int i = 1; i < A.size(); i++)
        {
            if (A.at(i) > stack.at(stack.size()-1))
            {
                stack.push_back(A.at(i));
                if ((stack.at(stack.size() - 1) - stack.at(0)) > max)
                {
                    max = stack.at(stack.size() - 1) - stack.at(0);
                }
            }
            else
            {
                while (stack.size() > 0 && A.at(i) < stack.at(stack.size()-1))
                {
                    stack.pop_back();
                }
                stack.push_back(A.at(i));
            }
        }
        
        if ((stack.at(stack.size() - 1) - stack.at(0)) > max)
        {
            max = stack.at(stack.size() - 1) - stack.at(0);
        }
        
        return max;
    }
}