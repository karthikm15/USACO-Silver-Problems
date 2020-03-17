/**
One day, Bessie was gazing off into the distance at the beautiful 
Wisconsin mountains when she wondered to herself: which is the 
widest one?

She decided to take N (1 <= N <= 10,000) height measurements H_i
(1 <= H_i <= 1,000,000,000) sequentially along the horizon using
her new Acme Long Distance Geoaltimeter. 

A mountain is defined to be a consecutive sequence of H_i values
which increases (or stays the same) and then decreases (or stays     
the same), e.g., 2, 3, 3, 5, 4, 4, 1. It is possible for a mountain
on the edge of her field of vision only to increase or only to      
decrease in height, as well.

The width of a mountain is the number of measurements it encompasses.
Help Bessie identify the widest mountain.

Here's a simple example of a typical horizon:

           *******                   *
          *********                 ***
          **********               *****
          ***********           *********               *
*      *****************       ***********             *** *
**    *******************     *************   * *     *******      *
**********************************************************************
?ddsssuussuussssssddddssddssssuuuuuuuuddddddssududssssuuudduddsssssuds
3211112333677777776543332111112344456765432111212111112343232111111211
aaaaa                     cccccccccccccccccccc eeeeeee    ggggggggg
  bbbbbbbbbbbbbbbbbbbbbbbbbbbb             ddddd ffffffffff  hhhhhhhhh

The mountains are marked 'a', 'b', etc.  Obviously, mountain b is
widest with width 28.

Hint: Sometimes it's easiest to find a mountain's width by knowing
where its highest parts are.

PROBLEM NAME: mount

INPUT FORMAT:

* Line 1: A single integer: N

* Lines 2..N+1: Line i+1 contains a single integer: H_i

SAMPLE INPUT:

7
3
2
3
5
4
1
6

INPUT DETAILS:

The height measurements are 3, 2, 3, 5, 4, 1, 6.

OUTPUT FORMAT:

* Line 1: A single line with a single integer that is the width of the
        widest mountain.

SAMPLE OUTPUT:

5

OUTPUT DETAILS:

The widest mountain consists of the measurements 2, 3, 5, 4, 1. Other
mountains include 3, 2 and 1, 6
*/
/**
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int count = 0;
    int maximum = 0;
    for (int i = 1; i < n; i++) {
        count = 1;
        bool isIncreasing = true;
        bool isDecreasing = false;
        if (arr[i] > arr[i-1]) {
            for (int j = i; j < n; j++) {
                if ((isIncreasing) && (arr[j] >= arr[j-1])) {
                    count++;
                }
                else if ((isIncreasing) && (arr[j] < arr[j-1])) {
                    isIncreasing = false;
                    isDecreasing = true;
                    count++;
                }
                else if ((isDecreasing) && (arr[j] < arr[j-1])) {
                    count++;
                }
                else {
                    break;
                }
            }
        }
        
        
        if (count > maximum) {
            maximum = count;
        }
    }
    
    cout << maximum;
}
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    long long int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int count = 0;
    int maximum = 0;
    for (int i = 1; i < n; i++) {
        count = 1;
        bool isIncreasing = true;
        bool isDecreasing = false;
        for (int j = 1; j < n; j++) {
            //cout << arr[i-j] << " " << arr[i+j] << endl;
            if ((arr[i-j] < arr[i-j+1]) && (arr[i+j] < arr[i+j-1])) {
                count += 2;
            }
            else if (arr[i-j] < arr[i-j+1]){
                count++;
                for (int k = (i-j-1); k > 0; k--) {
                    if (arr[k] > arr[k-1]) {
                        count++;
                    }
                    else {
                        break;
                    }
                }
                
                break;
            }
            else if (arr[i+j] < arr[i+j-1]){
                count++;
                for (int k = (i+j+1); k < n; k++) {
                    if (arr[k] > arr[k+1]) {
                        count++;
                    }
                    else {
                        break;
                    }
                }
                break;
            }
            else {
                break;
            }
            
        }
        
        if (count > maximum) {
            maximum = count;
        }
    }
    int count2 = 1;
    int count3 = 1;
    for (int i = (n-1); i > 0; i--) {
        if (arr[i] >= arr[i-1]){
            count2++;
        }
        else {
            break;
        }
    }
    for (int i = 0; i < (n-1); i++) {
        if (arr[i] >= arr[i+1]) {
            count3++;
        }
        else {
            break;
        }
    }
    int arr2[3] = {maximum, count2, count3};
    int *il;
    il = max_element(arr2, arr2+3);
    cout << int(*il);
}
