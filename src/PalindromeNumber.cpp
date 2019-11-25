class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
        {
            return false;
        }
        else if (x == 0)
        {
            return true;
        }
        else
        {
            vector<int> A;
            
            do
            {
                A.push_back(x % 10);
                x = x / 10;
            } while (x != 0);
                
            for (unsigned int i = 0; i < A.size(); i++)
            {
                if (A.at(i) != A.at(A.size() - 1 - i))
                {
                    return false;
                }
            }
            
            return true;
        }   
    }
};

class Solution {
public:
    bool isPalindrome(int x) {
      if (x < 0) return false;
	long result = 0;
	long y = x;
	while (x) {
		result = result * 10 + x % 10;
		x /= 10;
	}
	if (y == result) return true;
	return false;
    }
};