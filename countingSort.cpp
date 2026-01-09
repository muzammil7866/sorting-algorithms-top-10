#include <iostream>
using namespace std;

/**
 * Counting Sort Algorithm
 * Time Complexity: O(n + k) where k is the range of input
 * Space Complexity: O(k)
 * Stable: Yes
 * 
 * Description:
 * Non-comparison sorting algorithm. Counts the occurrences of each
 * distinct element, then uses arithmetic to calculate positions.
 * Efficient for integers with limited range.
 */

void countingSort(int arr[], int size) {
    // Find the maximum element
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    
    // Create count array with size (max + 1) initialized to 0
    int* count = new int[max + 1]();
    
    // Store count of each element
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }
    
    // Modify count array to contain actual positions
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }
    
    // Build output array
    int* output = new int[size];
    for (int i = size - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    
    // Copy output array to original array
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
    
    delete[] count;
    delete[] output;
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
    int arr[10] = {4, 2, 2, 8, 3, 3, 1, 7, 5, 6};
    
    cout << "Original array:";
    display(arr, size);
    
    countingSort(arr, size);
    
    cout << "Sorted array:";
    display(arr, size);
    
    return 0;
}
