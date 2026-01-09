#include <iostream>
using namespace std;

/**
 * Bubble Sort Algorithm
 * Time Complexity: O(n²) worst/average case, O(n) best case
 * Space Complexity: O(1)
 * Stable: Yes
 * 
 * Description:
 * Repeatedly steps through the list, compares adjacent elements
 * and swaps them if they're in the wrong order. The pass through
 * the list is repeated until no swaps are needed.
 */

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        
        // Last i elements are already in place
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        
        // If no swaps occurred, array is sorted
        if (!swapped) {
            break;
        }
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
    int size = 8;
    int arr[8] = {64, 34, 25, 12, 22, 11, 90, 88};
    
    cout << "Original array:";
    display(arr, size);
    
    bubbleSort(arr, size);
    
    cout << "Sorted array:";
    display(arr, size);
    
    return 0;
}
