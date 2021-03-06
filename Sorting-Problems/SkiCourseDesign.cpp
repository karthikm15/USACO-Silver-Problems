/*Farmer John has N hills on his farm (1 <= N <= 1,000), each with an
integer elevation in the range 0 .. 100.  In the winter, since there is
abundant snow on these hills, FJ routinely operates a ski training camp.

Unfortunately, FJ has just found out about a new tax that will be assessed
next year on farms used as ski training camps.  Upon careful reading of the
law, however, he discovers that the official definition of a ski camp
requires the difference between the highest and lowest hill on his property
to be strictly larger than 17.  Therefore, if he shortens his tallest hills
and adds mass to increase the height of his shorter hills, FJ can avoid
paying the tax as long as the new difference between the highest and lowest
hill is at most 17.  

If it costs x^2 units of money to change the height of a hill by x units,
what is the minimum amount of money FJ will need to pay?  FJ is only
willing to change the height of each hill by an integer amount.

PROBLEM NAME: skidesign

INPUT FORMAT:

* Line 1: The integer N.

* Lines 2..1+N: Each line contains the elevation of a single hill.

SAMPLE INPUT:

5
20
4
1
24
21

INPUT DETAILS:

FJ's farm has 5 hills, with elevations 1, 4, 20, 21, and 24.

OUTPUT FORMAT:

* Line 1: The minimum amount FJ needs to pay to modify the elevations
        of his hills so the difference between largest and smallest is
        at most 17 units.

SAMPLE OUTPUT:

18

OUTPUT DETAILS:

FJ keeps the hills of heights 4, 20, and 21 as they are.  He adds mass to the
hill of height 1, bringing it to height 4 (cost = 3^2 = 9).  He shortens
the hill of height 24 to height 21, also at a cost of 3^2 = 9.
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int count, count2;
    int arr[n];
    count2 = 0;
    for (int i = 0; i < n; i++) {
        int placeholder;
        cin >> placeholder;
        arr[i] == placeholder;
    }
    int n1 = sizeof(arr) / sizeof(arr[0]); 
    sort (arr, arr+n1);
    int maximum = arr[n-1];
    int minimum = arr[0];
    while ((maximum-minimum) > 17) {
        count += ((maximum - minimum)/2);
        count2 += 2;
        int arr2[n-count2];
        int count3 = 0;
        for (int i = 0; i < n; i++) {
            if ((i != 0) && (i != n-1)) {
                arr2[count3] = arr[i];
                count3++;
            }
        }
        maximum = arr[n-count2-1];
        minimum = arr[0];
    }
    
    cout << pow(count, 2);
    
}