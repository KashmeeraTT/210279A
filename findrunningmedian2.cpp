#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    vector<int> nums; // to store the input integers
    int arr[] = {6, 5, 8, 1, 3, 2, 4, 7, 9};
    int n = sizeof(arr)/sizeof(arr[0]); // number of integers
  

    for (int i = 0; i < n; i++) {
        int x = arr[i];
        nums.push_back(x); // add the ith integer to the list
        sort(nums.begin(), nums.end()); // sort the list

        double median; // to store the median

        if (i % 2 == 0) { // if the list contains an odd number of elements
            median = nums[i/2];
        } else { // if the list contains an even number of elements
            median = (double)(nums[i/2] + nums[i/2 + 1]) / 2;
        }

        cout << "Sorted Array: ";
        for (int j = 0; j <= i; j++) {
            cout << nums[j] << " ";
        }
        cout << endl;

        cout << "Median: " << fixed << setprecision(1) << median << endl; // print the updated median
    }

    return 0;
}
