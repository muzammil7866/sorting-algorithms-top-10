#include <iostream>
using namespace std;

/**
 * Heap Sort Algorithm
 * Time Complexity: O(n log n) for all cases
 * Space Complexity: O(1)
 * Stable: No
 * 
 * Description:
 * Uses a binary heap data structure. First builds a max heap,
 * then repeatedly extracts the maximum element and rebuilds the heap.
 * In-place with guaranteed O(n log n) performance.
 */

void heapify(int arr[], int size, int i) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    // If left child is larger than root
    if (left < size && arr[left] > arr[largest])
        largest = left;
    
    // If right child is larger than largest so far
    if (right < size && arr[right] > arr[largest])
        largest = right;
    
    // If largest is not root
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        
        // Recursively heapify the affected sub-tree
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size) {
    // Build max heap
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);
    
    // Extract elements from heap one by one
    for (int i = size - 1; i > 0; i--) {
        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        
        // Heapify the reduced heap
        heapify(arr, i, 0);
    }
}

void display(int arr[], int size) {
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size = 9;
    int arr[9] = {12, 11, 13, 5, 6, 7, 22, 18, 9};
    
    cout << "Original array:";
    display(arr, size);
    
    heapSort(arr, size);
    
    cout << "Sorted array:";
    display(arr, size);
    
    return 0;
}
