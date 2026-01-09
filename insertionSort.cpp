#include <iostream>
using namespace std;

/**
 * Insertion Sort Algorithm
 * Time Complexity: O(n²) worst/average case, O(n) best case
 * Space Complexity: O(1)
 * Stable: Yes
 * 
 * Description:
 * Builds the final sorted array one item at a time. Takes each
 * element and inserts it into its correct position in the sorted
 * portion of the array. Efficient for small datasets.
 */

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Move elements greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
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
    int arr[8] = {12, 11, 13, 5, 6, 7, 22, 18};
    
    cout << "Original array:";
    display(arr, size);
    
    insertionSort(arr, size);
    
    cout << "Sorted array:";
    display(arr, size);
    
    return 0;
}
