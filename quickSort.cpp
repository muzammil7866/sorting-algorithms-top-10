#include <iostream>
using namespace std;

/**
 * Quick Sort Algorithm
 * Time Complexity: O(n log n) average, O(n²) worst case
 * Space Complexity: O(log n) due to recursion
 * Stable: No
 * 
 * Description:
 * Picks a pivot element and partitions the array around it such that
 * elements smaller than pivot are on left and larger are on right.
 * Then recursively sorts the sub-arrays. Very efficient in practice.
 */

int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choose last element as pivot
    int i = low - 1;  // Index of smaller element
    
    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    // Swap arr[i+1] and arr[high] (pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partitioning index
        int pi = partition(arr, low, high);
        
        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    int size = 10;
    int arr[10] = {10, 7, 8, 9, 1, 5, 14, 3, 6, 2};
    
    cout << "Original array:";
    display(arr, size);
    
    quickSort(arr, 0, size - 1);
    
    cout << "Sorted array:";
    display(arr, size);
    
    return 0;
}
