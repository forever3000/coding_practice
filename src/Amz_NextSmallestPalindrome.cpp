#include <iostream> 
#include <vector>
using namespace std;

void BuildPalindromeNumber (vector<int> &a) {
    int left, right;
    int N = a.size();

    if (N % 2 == 0) {
        left = N/2 - 1;
        right = N/2;
    } else {
        left = right = N/2;
    }

    while (left >= 0 && right <= (N - 1)) {
        a.at(right) = a.at(left);
        left --;
        right ++;
    }

    return;
}

void NextSmallestPalindrome (vector<int> &a) {
    int N = a.size();
    vector<int> temp = a;
    int mid;
    bool less = false;
    
    // Build Palindrome based on input
    BuildPalindromeNumber(a);

    // Compare nex Palindrome number with original number
    for (int i = 0; i < N; i++){
        if (a.at(i) > temp.at(i)) {
            less = false;
            break;
        } else if (a.at(i) < temp.at(i)) {
            less = true;
            break;
        }
    }

    // Return if Palindrome number is larger than original number
    if (less == false) {
        return;
    }

    // Build the next Palindrome number
    if (N % 2 == 0) {
        mid = N/2 - 1;
    } else {
        mid = N/2;
    }

    while (mid >= 0) {
        if (a.at(mid) == 9) {
            a.at(mid) = 0;
            mid --;
        } else {
            a.at(mid) += 1;
            break;
        }
    }

    BuildPalindromeNumber(a);

    return;
}

int main (void) {
    vector<int> a= {9,4,1,8,7,9,7,8,3,2,2};
    NextSmallestPalindrome(a);

    for (int i = 0; i < a.size(); i++) {
        cout << a.at(i) << " ";
    }
    return 0;
}
