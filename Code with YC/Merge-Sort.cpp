#include<iostream>
using namespace std;

// Function to merge two sorted arrays
void merge(int *arr, int s, int e) {

    // Finding the middle index
    int mid = (s+e)/2;

    // Calculating the lengths of the two arrays
    int len1 = mid - s + 1;
    int len2 = e - mid;

    // Allocating memory for two arrays
    int *first = new int[len1];
    int *second = new int[len2];

    // Copying values from the main array to the two arrays
    int mainArrayIndex = s;
    for(int i=0; i<len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid+1;
    for(int i=0; i<len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    // Merging the two sorted arrays
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }   

    // Adding any remaining elements from first array
    while(index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    // Adding any remaining elements from second array
    while(index2 < len2 ) {
        arr[mainArrayIndex++] = second[index2++];
    }

    // Deallocating memory for the two arrays
    delete []first;
    delete []second;

}

// Function to perform the merge sort
void mergeSort(int *arr, int s, int e) {

    // Base case: If the start and end indices are equal or cross over, return
    if(s >= e) {
        return;
    }
    
    // Finding the middle index
    int mid = (s+e)/2;

    // Recursively sorting the left half of the array
    mergeSort(arr, s, mid);
    
    // Recursively sorting the right half of the array
    mergeSort(arr, mid+1, e);

    // Merging the two sorted arrays
    merge(arr, s, e);

}

int main() {

    int arr[15] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    int n = 15;

    // Sorting the array
    mergeSort(arr, 0, n-1);

    // Printing the sorted array
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    } cout << endl;

    return 0;
}

// The time complexity of the merge sort algorithm is O(n log n), where n is the number of elements in the array being sorted. 
// This makes it one of the more efficient sorting algorithms, especially for larger data sets.
