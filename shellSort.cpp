#include <iostream>
using namespace std;

/**
 * Shell Sort Algorithm
 * Time Complexity: O(n log n) to O(n^(4/3)) depending on gap sequence
 * Space Complexity: O(1)
 * Stable: No
 * 
 * Description:
 * Generalization of insertion sort. Allows exchange of items that
 * are far apart. The gap between compared elements is gradually
 * reduced. More efficient than insertion sort for larger arrays.
 */

void shellSort(int arr[], int size) {
    // Start with a large gap and reduce it
    for (int gap = size / 2; gap > 0; gap /= 2) {
        // Perform gapped insertion sort for this gap size
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            
            // Shift earlier gap-sorted elements up until correct location is found
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            
            // Put temp in its correct location
            arr[j] = temp;
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
    int size = 10;
    int arr[10] = {12, 34, 54, 2, 3, 9, 11, 7, 25, 18};
    
    cout << "Original array:";
    display(arr, size);
    
    shellSort(arr, size);
    
    cout << "Sorted array:";
    display(arr, size);
    
    return 0;
}
