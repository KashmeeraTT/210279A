#include <iostream>
#include <stack>
#include <utility>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

void swap(int *a,int *b) {
    int temp = *a;
    *a=*b;
    *b = temp;
} 
int partition (int A[], int p, int r){
    int x = A[r];
    int i = p - 1;
    for (int j = p; j <= r- 1; j++) {
        if (A[j] <= x) {
            i++;
            swap (&A[i], &A[j]);
        }
    } 
    swap (&A[i + 1], &A[r]);
    return (i + 1);
}
void quickSortrecursive(int A[], int p, int r) {
    if (p < r) {
        int q = partition(A, p,r);
        quickSortrecursive(A, p, q - 1);
        quickSortrecursive(A, q + 1, r);
    }
}
void quickSortIterative(int arr[], int low, int high) {
    vector<int> stack(high - low + 1);

    int top = -1;

    stack[++top] = low;
    stack[++top] = high;

    while (top >= 0) {
        high = stack[top--];
        low = stack[top--];

        int p = partition(arr, low, high);

        if (p - 1 > low) {
            stack[++top] = low;
            stack[++top] = p - 1;
        }

        if (p + 1 < high) {
            stack[++top] = p + 1;
            stack[++top] = high;
        }
    }
}



int main() {
    const long n1 = 30000;
    vector<int> arr1(n1);

    for (int i = 0; i < n1; i++) {
        arr1[i] = rand() % 100;
    }

    auto start = chrono::high_resolution_clock::now();
        quickSortrecursive(arr1.data(), 0, n1 - 1);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Array length: " << n1 << endl;
    cout << "Time taken by Recursion: " << duration  << " microseconds" << endl;

    auto start1 = chrono::high_resolution_clock::now();
        quickSortIterative(arr1.data(), 0, n1 - 1);
    auto end1 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::microseconds>(end1 - start1).count();
    cout << "Array length: " << n1 << endl;
    cout << "Time taken by Iteration: " << duration1  << " microseconds" << endl;
}
