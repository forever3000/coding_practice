// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// Function to run quicksort on an array of integers
// l is the leftmost starting index, which begins at 0
// r is the rightmost starting index, which begins at array length - 1
void quicksort(vector<int> &A, int l, int r)
{
    // Base case: No need to sort arrays of length <= 1
    if (l >= r)
    {
        return;
    }
    
    // Choose pivot to be the last element in the subarray
    int pivot = A.at(r);

    // Index indicating the "split" between elements smaller than pivot and 
    // elements greater than pivot
    int cnt = l;

    // Traverse through array from l to r
    for (int i = l; i <= r; i++)
    {
        // If an element less than or equal to the pivot is found...
        if (A.at(i) <= pivot)
        {
            // Then swap arr[cnt] and arr[i] so that the smaller element arr[i] 
            // is to the left of all elements greater than pivot
            int temp = A.at(cnt);
            A.at(cnt) = A.at(i);
            A.at(i) = temp;

            // Make sure to increment cnt so we can keep track of what to swap
            // arr[i] with
            cnt++;
        }
    }
    
    // NOTE: cnt is currently at one plus the pivot's index 
    // (Hence, the cnt-2 when recursively sorting the left side of pivot)
    quicksort(A, l, cnt-2); // Recursively sort the left side of pivot
    quicksort(A, cnt, r);   // Recursively sort the right side of pivot
}

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int max_1;
    int max_2;
    
    quicksort (A, 0, A.size() - 1);
    
    max_1 = A.at(0) * A.at(1) * A.at(A.size() - 1);
    max_2 = A.at(A.size() - 3) * A.at(A.size() - 2) * A.at(A.size() - 1);
    
    return (max_1 > max_2 ? max_1 : max_2);
}


// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int max[3] = {-2000, -2000, -2000};
    int min[2] = {2000, 2000};
    int i;
    int max_product[2];
    
    for (i = 0; i < A.size(); i++)
    {
        if (A.at(i) > max[2])
        {
            max[0] = max[1];
            max[1] = max[2];
            max[2] = A.at(i);
        } else if (A.at(i) > max[1])
        {
            max[0] = max[1];
            max[1] = A.at(i);
        } else if (A.at(i) > max[0])
        {
            max[0] = A.at(i);
        }
        
        if (A.at(i) < min[1])
        {
            min[0] = min[1];
            min[1] = A.at(i);
        } else if (A.at(i) < min[0])
        {
            min[0] = A.at(i);    
        }
    }
    
    max_product[0] = min[0] * min[1] * max[2];
    max_product[1] = max[0] * max[1] * max[2];
    
    return (max_product[0] > max_product[1] ? max_product[0] : max_product[1]);
}