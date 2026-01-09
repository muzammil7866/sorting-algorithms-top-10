#include <iostream>
using namespace std;

/**
 * Selection Sort Algorithm
 * Time Complexity: O(n²) for all cases
 * Space Complexity: O(1)
 * Stable: No
 * 
 * Description:
 * Divides the array into sorted and unsorted regions. Repeatedly
 * selects the minimum element from the unsorted region and moves
 * it to the end of the sorted region.
 */

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        // Find the minimum element in unsorted array
        int minIndex = i;
        
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swap the found minimum element with the first element
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
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
    int arr[8] = {64, 25, 12, 22, 11, 90, 88, 34};
    
    cout << "Original array:";
    display(arr, size);
    
    selectionSort(arr, size);
    
    cout << "Sorted array:";
    display(arr, size);
    
    return 0;
}
