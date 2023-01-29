#include <iostream>
using namespace std;

int main() {
    int arr[] = { 1000, 11, 445, 1, 330, 3000 };
    int arr_size = 6;

    // Initialize the max and min values to the first element of the array
    int mx = arr[0];
    int mn = arr[0];

    // Loop through the array to find the max and min values
    for (int i = 1; i < arr_size; i++) {
        // Check if the current element is greater than the current max value
        if (arr[i] > mx) {
            mx = arr[i];
        }
        // Check if the current element is less than the current min value
        if (arr[i] < mn) {
            mn = arr[i];
        }
    }

    // Output the min and max values
    cout << "MIN: " << mn << " MAX: " << mx << endl;

    return 0;
}

// The time complexity of this algorithm is O(N) as the loop iterates through the entire array once.