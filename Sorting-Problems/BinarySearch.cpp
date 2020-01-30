/*
Implement a binary search algorithm that returns the index of the
first occurrence of a number K, or -1 if it could not be found. You
will be supplied with a (sorted) list of N numbers (0 <= N <= 100,000).

For example, suppose you were given the following (sorted) array as
input.

2 3 4 4 9 11 12

Searching for 4 should return 2, searching for 9 should return 4, and
searching for 10 should return -1.

You will be asked to answer Q queries (1 <= Q <= 100,000), each of which
is a single number and should be answered as stated above.

PROBLEM NAME: binarysearch

INPUT FORMAT:

* Line 1: Two integers, N and Q.

* Line 2: N sorted integers. 

* Lines 3..Q+2: A single integer K on each line, representing a query.

SAMPLE INPUT:

7 2
2 3 4 4 9 11 12
9
10

OUTPUT FORMAT:

* Lines 1..Q: The index of the first occurrence of K in the supplied array,
        or -1 if not found.

SAMPLE OUTPUT:

4
-1

OUTPUT DETAILS:

The index of 9 is 4, and 10 is not in the array so the function returns -1.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int index = 0;
    for (int i = 0; i < q; i++) {
        int placeholder;
        cin >> placeholder;
        index = -1;
        int left = 0;
        int right = n;
        int mid = (left+right)/2;
        while ((left != (right+1)) && (left != (right-1)) && (left != right)) {
            if (placeholder == arr[mid]) {
                index = mid;
                break;
            }
            else if (placeholder < arr[mid]) {
                right = mid;
            }
            else {
                left = mid;
            }
            mid = (left+right)/2;
        }
        if (placeholder == arr[n-1]) {
            index = n-1;
        }
        if (placeholder == arr[0]) {
            index = 0;
        }
        int index2 = index;
        if (index != -1) {
            for (int j = index2; j > 0; j--) {
                if (arr[j] == arr[j-1]) {
                    index2 = j-1;
                }
                else {
                    break;
                }
            }
        }
        cout << index2 << endl;
    }
}