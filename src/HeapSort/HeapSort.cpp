// A binary search based program to find the 
// only missing number in a sorted array of 
// distinct elements within limited range. 
#include <iostream> 
using namespace std;

void Heapify(int arr[], int n, int index) {
    int largest = index;
    int left = index*2 + 1;
    int right = index*2 + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != index) {
        swap(arr[largest], arr[index]);
        Heapify(arr, n, largest);
    }
}
  
void HeapSort (int arr[], int n) {
    // Build the max heap from array
    for (int i = n/2 - 1; i >= 0; i--) {
        Heapify(arr, n, i);
    }
    
    // Swap the root to end of array and 
    // build the max heap again from the reduced array
    for (int i=n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        Heapify(arr, i, 0);
    }
}

int main (void) {
    int arr[] = {2,5,6,7,4,3,1,9};
    int n = sizeof(arr)/sizeof(int);
    HeapSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
