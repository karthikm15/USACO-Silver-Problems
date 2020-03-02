/*
Farmer John's N (1 <= N <= 100,000) cows, conveniently numbered
1..N, are once again standing in a row. Cow i has height H_i (1 <=
H_i <= 1,000,000).

Each cow is looking to her left toward those with higher index
numbers. We say that cow i 'looks up' to cow j if i < j and H_i <
H_j. For each cow i, FJ would like to know the index of the first
cow in line looked up to by cow i.

Note: about 50% of the test data will have N <= 1,000.

PROBLEM NAME: lookup

INPUT FORMAT:

* Line 1: A single integer: N

* Lines 2..N+1: Line i+1 contains the single integer: H_i

SAMPLE INPUT:

6
3
2
6
1
1
2

INPUT DETAILS:

FJ has six cows of heights 3, 2, 6, 1, 1, and 2.

OUTPUT FORMAT:

* Lines 1..N: Line i contains a single integer representing the
        smallest index of a cow up to which cow i looks. If no such
        cow exists, print 0.

SAMPLE OUTPUT:

3
3
0
6
6
0

OUTPUT DETAILS:

Cows 1 and 2 both look up to cow 3; cows 4 and 5 both look up to cow 6; and
cows 3 and 6 do not look up to any cow.
*/
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    stack<int> stack1;
    for (int i = 0; i < n; i++) {
        int placeholder;
        cin >> placeholder;
        
        stack1.push(placeholder);
    }
    
    vector<int> v;
    vector<int> numbers;
    while (!stack1.empty()) {
        int top = stack1.top();
        stack1.pop();
        
        numbers.push_back(top);
        bool isTrue = false;
        for (unsigned int i = (numbers.size()-1); i >= 0; i--) {
            if (top < numbers[i]) {
                v.push_back(n-i);
                isTrue = true;
                break;
                cout << "IT WORKS" << endl;
            }
        }
        if (!isTrue) {
            v.push_back(0);
        }
    }
    
    for (unsigned int i = (v.size()-1); i >= 0; i--) {
        cout << v[i] << endl;
    }
    
}