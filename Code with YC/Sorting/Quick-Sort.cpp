#include<iostream>
using namespace std;

// This function takes an array `arr`, the starting index `s` and the ending index `e`
// as input and returns the index of the pivot element after partitioning the array.
int partition( int arr[], int s, int e) {

    // The first element of the array is selected as pivot.
    int pivot = arr[s];

    // Count the number of elements less than or equal to the pivot.
    int cnt = 0;
    for(int i = s+1; i<=e; i++) {
        if(arr[i] <=pivot) {
            cnt++;
        }
    }

    // Place the pivot at the right position in the array.
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    // Keep track of the elements to the left and right of the pivot.
    int i = s, j = e;

    // Loop until the pointers `i` and `j` cross each other.
    while(i < pivotIndex && j > pivotIndex) {

        // Increment `i` until an element greater than the pivot is found.
        while(arr[i] <= pivot) 
        {
            i++;
        }

        // Decrement `j` until an element less than or equal to the pivot is found.
        while(arr[j] > pivot) {
            j--;
        }

        // If both pointers have not crossed each other, swap the elements at `i` and `j`.
        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }

    }

    // Return the index of the pivot.
    return pivotIndex;

}

// This function takes an array `arr`, the starting index `s` and the ending index `e`
// as input and sorts the elements of the array in increasing order using QuickSort.
void quickSort(int arr[], int s, int e) {

    // Base case: If the starting index is greater than or equal to the ending index,
    // there's no need to sort the array as it's already sorted or contains 0 or 1 element.
    if(s >= e) 
        return ;

    // Partition the array around a pivot element.
    int p = partition(arr, s, e);

    // Sort the left part of the partitioned array.
    quickSort(arr, s, p-1);

    // Sort the right part of the partitioned array.
    quickSort(arr, p+1, e);

}

int main() {

    // Initialize an array of 10 integers.
    int arr[5] = {2,4,1,6,9};
    int n = 5;

    // Sort the array using QuickSort.
    quickSort(arr, 0, n-1);

    // Print the sorted array.
    for(int i=0; i<n; i++) 
    {
        cout << arr[i] << " ";
    }

    return 0;
}

// The time complexity of Quick sort is O(n log n) on average
// O(n^2) in the worst case. 

// It is a divide and conquer algorithm that selects a pivot element and rearranges the elements around it to divide the array into two sub-arrays. 

// The pivot element is placed at its final position and the two sub-arrays are sorted recursively. 

// The best-case scenario occurs when the pivot is chosen optimally and the partitioning leads to balanced sub-arrays, 

// while the worst-case scenario occurs when the pivot is chosen poorly and the partitioning results in one sub-array of size n-1 and the other sub-array of size 0.