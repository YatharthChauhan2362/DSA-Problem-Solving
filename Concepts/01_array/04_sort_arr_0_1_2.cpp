/*

    logic: iterate mid and if mid==0 then swap with low and then low++, mid++
           if mid==2 then swap with high and then high--, mid
           else mid++ as it would be 1.

    variation: 2-pointer
*/



#include<bits/stdc++.h>
using namespace std;

// Function to sort an array containing 0s, 1s, and 2s
void sort012(int a[], int n) {
    int low = 0; // Start index of 0s
    int high = n - 1; // End index of 2s
    int mid = 0; // Current index

    // Loop until mid is less than or equal to high
    while (mid <= high) {
        // If the current element is 0, swap it with the element at low index and increment both low and mid
        if (a[mid] == 0) {
            swap(a[mid++], a[low++]);
        }
        // If the current element is 1, increment the mid index
        else if (a[mid] == 1) {
            mid++;
        }
        // If the current element is 2, swap it with the element at the high index and decrement the high index
        else {
            swap(a[mid], a[high--]);
        }
    }

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

int main() {
    int n = 5;
    int arr[] = { 0, 2, 1, 2, 0 };
    sort012(arr, n);

    return 0;
}

