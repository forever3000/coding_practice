// Simple C++ program to print 
// next greater elements in a 
// given array 
#include <iostream>
#include <stack>

using namespace std; 
  
/* prints element and NGE pair  
for all elements of arr[] of size n */
void printNGE(int arr[], int n) 
{ 
    stack<int> s;

    for (int i = 0; i < n; i++) {
        if (s.empty()) {
            s.push(arr[i]);
            continue;
        }

        while (s.empty() == false && s.top() < arr[i]) {
            cout << s.top() << "--> " << arr[i] << endl;
            s.pop();
        }

        s. push(arr[i]);
    }

    while (s.empty() == false) {
        cout << s.top() << "--> " << -1 << endl;
        s.pop();
    }
} 
  
// Driver Code 
int main() 
{ 
    int arr[] = {11, 5, 13, 21, 3}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printNGE(arr, n); 
    return 0; 
}
