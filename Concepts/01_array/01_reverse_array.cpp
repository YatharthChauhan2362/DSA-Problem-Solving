#include <iostream>
using namespace std;

// Function to reverse an array
void reverseArray(int arr[], int start, int end) {
    // Loop until start index is less than end index
    while (start < end) {
        // Swap elements at start and end indices
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        // Increment start index
        start++;
        // Decrement end index
        end--;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    // Calculate the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Reverse the array using the reverseArray function
    reverseArray(arr, 0, n - 1);

    // Print the reversed array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

// The time complexity of this algorithm is O(N) as the loop iterates through the entire array once.