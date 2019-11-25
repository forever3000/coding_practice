// Find longest sequence of zeros in binary representation of an integer.
// you can also use imports, for example:
// import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class Solution {
    public int solution(int N) {
        // write your code in Java SE 8
        boolean start_flag = false;
        boolean end_flag = false;
        int count = 0;
        int max = 0;
        
        while (N > 0)
        {
            if (N % 2 == 1)
            {
                if (!start_flag)
                {
                    start_flag = true;
                } else if (start_flag)
                {
                    end_flag = true;
                }
            }
            
            if (start_flag)
            {
                if (N % 2 == 0)
                {
                    count ++;
                }
            }
            
            if (start_flag && end_flag)
            {
                if (count > max)
                {
                    max = count;
                }
                count = 0;
                end_flag = false;
            }
            
            N = N/2;
        }
        
        return max;
    }
}