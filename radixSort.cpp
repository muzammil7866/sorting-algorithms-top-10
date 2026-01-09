#include <iostream>
using namespace std;

/**
 * Radix Sort Algorithm
 * Time Complexity: O(d * (n + k)) where d is number of digits
 * Space Complexity: O(n + k)
 * Stable: Yes
 * 
 * Description:
 * Sorts numbers digit by digit starting from least significant digit
 * to most significant digit. Uses counting sort as a subroutine.
 * Efficient for fixed-length integer keys.
 */

int getMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void countingSortByDigit(int arr[], int size, int exp) {
    int* output = new int[size];
    int count[10] = {0};
    
    // Store count of occurrences
    for (int i = 0; i < size; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }
    
    // Change count[i] to contain actual position
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    
    // Build output array
    for (int i = size - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }
    
    // Copy output to arr
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
    
    delete[] output;
}

void radixSort(int arr[], int size) {
    int max = getMax(arr, size);
    
    // Do counting sort for every digit
    // exp is 10^i where i is current digit number
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSortByDigit(arr, size, exp);
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
    int arr[10] = {170, 45, 75, 90, 802, 24, 2, 66, 329, 123};
    
    cout << "Original array:";
    display(arr, size);
    
    radixSort(arr, size);
    
    cout << "Sorted array:";
    display(arr, size);
    
    return 0;
}
