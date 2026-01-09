#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Bucket Sort Algorithm
 * Time Complexity: O(n + k) average, O(n²) worst case
 * Space Complexity: O(n)
 * Stable: Yes
 * 
 * Description:
 * Distributes elements into buckets, sorts each bucket individually,
 * then concatenates. Works well for uniformly distributed data.
 * This implementation works for integers.
 */

void bucketSort(int arr[], int size) {
    if (size <= 0) return;
    
    // Find maximum and minimum values
    int maxVal = arr[0], minVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) maxVal = arr[i];
        if (arr[i] < minVal) minVal = arr[i];
    }
    
    // Create buckets
    int bucketCount = size;
    int range = maxVal - minVal + 1;
    vector<int>* buckets = new vector<int>[bucketCount];
    
    // Distribute elements into buckets
    for (int i = 0; i < size; i++) {
        int bucketIndex = (bucketCount - 1) * (arr[i] - minVal) / range;
        buckets[bucketIndex].push_back(arr[i]);
    }
    
    // Sort individual buckets and concatenate
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        // Sort using built-in sort (or any other sorting algorithm)
        sort(buckets[i].begin(), buckets[i].end());
        
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
    
    delete[] buckets;
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
    int arr[10] = {42, 32, 33, 52, 37, 47, 51,  29, 41, 38};
    
    cout << "Original array:";
    display(arr, size);
    
    bucketSort(arr, size);
    
    cout << "Sorted array:";
    display(arr, size);
    
    return 0;
}
