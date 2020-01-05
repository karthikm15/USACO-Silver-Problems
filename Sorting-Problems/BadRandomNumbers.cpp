/*
Bessie is trying to generate random numbers. She stumbled upon an
old reference to the 'middle square' method for making numbers that
appear to be random. It works like this:

        * Pick a starting four digit number (1 <= N <= 9999)

        * Extract its middle two digits as a number

        * Compute the square of those two digits

	* That square is the 'random number' and becomes the new
	  starting number

Here's a sample:

                Num  Middle  Square
               7339    33     1089
               1089     8       64
                 64     6       36
                 36     3        9
                  9     0        0
                  0     0        0

The 'pigeon hole principle' tells us that the random numbers surely
must repeat after no more than 10,000 of them -- and the sequence
above repeats after just six numbers (the next number and all
subsequent numbers are 0).

Note that some sequences repeat in a more complex way; this one
alternates back and forth between 576 and 3249:

                Num  Middle  Square
                2245   24      576  
                 576   57     3249 
                3249   24      576  

Your job is to tell Bessie the count of 'random numbers' that can
be generated from a starting number before the sequence repeats
a previously seen number. In the first case above, the answer is
'6'. In the 'alternating' case, the answer is '3'.

PROBLEM NAME: badrand

INPUT FORMAT:

* Line 1: A single integer: N

SAMPLE INPUT:

7339

OUTPUT FORMAT:

* Line 1: A single integer that is the count of iterations through the
        middle square random number generator before a previous value
        is repeated

SAMPLE OUTPUT:

6
*/

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int n1;
    cin >> n1;
    string num;
    num = to_string(n1);
    int number = n1;
    int arr[10000] = {0};
    int count;
    while (true) {
        //cout << "Number is: " << number << endl;
        int placeholder = number;
        num = to_string(number);
        if (num.length() == 4) {
            number = ((placeholder/10)%100);
        }
        if (num.length() == 3) {
            number = (placeholder/10)%100;
        }
        if (num.length() == 2) {
            number = (placeholder/10) % 10;
        }
        if (num.length() == 1) {
            number = 0;
        }
        
        //cout << number << endl;
        number = pow(number, 2);
        //cout << number << endl;
        
        if (binary_search(arr, arr+number, number)) {
            break;
        }
        if (number == 0) {
            count++;
            break;
        }
        else {
            count++;
        }
        arr[number-1] = number;
    }
    cout << count+1;
}