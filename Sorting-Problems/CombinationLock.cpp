/*
Farmer John's cows keep escaping from his farm and causing mischief. To try
and prevent them from leaving, he purchases a fancy combination lock to
keep his cows from opening the pasture gate. 

Knowing that his cows are quite clever, Farmer John wants to make sure they
cannot easily open the lock by simply trying many different combinations. 
The lock has three dials, each numbered 1..N (1 <= N <= 100), where 1 and N
are adjacent since the dials are circular.  There are two combinations that
open the lock, one set by Farmer John, and also a "master" combination set
by the lock maker.  The lock has a small tolerance for error, however, so
it will open even if the numbers on the dials are each within at most 2
positions of a valid combination.  For example, if Farmer John's
combination is (1,2,3) and the master combination is (4,5,6), the lock will
open if its dials are set to (1,N,5) (since this is close enough to Farmer
John's combination) or to (2,4,8) (since this is close enough to the master
combination).  Note that (1,5,6) would not open the lock, since it is not
close enough to any one single combination.

Given Farmer John's combination and the master combination, please
determine the number of distinct settings for the dials that will open the
lock.  Order matters, so the setting (1,2,3) is distinct from (3,2,1).

PROBLEM NAME: combo

INPUT FORMAT:

* Line 1: The integer N.

* Line 2: Three space-separated integers, specifying Farmer John's
        combination.

* Line 3: Three space-separated integers, specifying the master
        combination (possibly the same as Farmer John's combination).

SAMPLE INPUT:

50
1 2 3
5 6 7

INPUT DETAILS:

Each dial is numbered 1..50.  Farmer John's combination is (1,2,3), and the
master combination is (5,6,7).

OUTPUT FORMAT:

* Line 1: The number of distinct dial settings that will open the
        lock.

SAMPLE OUTPUT:

249
*/
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int farmer[3];
    int master[3];
    
    
    for (int i = 0; i < 3; i++) {
        cin >> farmer[i];
    }
    for (int i = 0; i < 3; i++) {
        cin >> master[i];
    }
    int count = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (((farmer[0] == i) || (farmer[0] == i+1) || (farmer[0] == i+2) || (farmer[0] == i-1) || (farmer[0] == i-2)) &&
                   ((farmer[1] == j) || (farmer[1] == j+1) || (farmer[1] == j+2) || (farmer[1] == j-1) || (farmer[1] == j-2)) &&
                   ((farmer[2] == k) || (farmer[2] == k+1) || (farmer[2] == k+2) || (farmer[2] == k-1) || (farmer[2] == k-2))) {
                       count++;
                }
                else if (((master[0] == i) || (master[0] == i+1) || (master[0] == i+2) || (master[0] == i-1) || (master[0] == i-2)) &&
                   ((master[1] == j) || (master[1] == j+1) || (master[1] == j+2) || (master[1] == j-1) || (master[1] == j-2)) &&
                   ((master[2] == k) || (master[2] == k+1) || (master[2] == k+2) || (master[2] == k-1) || (master[2] == k-2))) {
                       count++;
                }
                else if ((i == n) || (j == n) || (k == n)){
                    if ((i == n) && (j == n) && (k==n)) {
                        if (((farmer[0] == 1) || (farmer[0] == 2) || (farmer[0] == i) || (farmer[0] == i+1) || (farmer[0] == i+2) || (farmer[0] == i-1) || (farmer[0] == i-2))&&
                        ((farmer[1] == 1) || (farmer[1] == 2) || (farmer[1] == j) || (farmer[1] == j+1) || (farmer[1] == j+2) || (farmer[1] == j-1) || (farmer[1] == j-2)) &&
                        ((farmer[2] == 1) || (farmer[2] == 2) || (farmer[2] == k) || (farmer[2] == k+1) || (farmer[2] == k+2) || (farmer[2] == k-1) || (farmer[2] == k-2))) {
                            count++;
                        }
                        else if (((master[0] == 1) || (master[0] == 2) || (master[0] == i) || (master[0] == i+1) || (master[0] == i+2) || (master[0] == i-1) || (master[0] == i-2))&&
                        ((master[1] == 1) || (master[1] == 2) || (master[1] == j) || (master[1] == j+1) || (master[1] == j+2) || (master[1] == j-1) || (master[1] == j-2)) &&
                        ((master[2] == 1) || (master[2] == 2) || (master[2] == k) || (master[2] == k+1) || (master[2] == k+2) || (master[2] == k-1) || (master[2] == k-2))) {
                            count++;
                        }
                    }
                    else if ((i == n) && (j == n)) {
                        if (((farmer[0] == 1) || (farmer[0] == 2) || (farmer[0] == i) || (farmer[0] == i+1) || (farmer[0] == i+2) || (farmer[0] == i-1) || (farmer[0] == i-2))&&
                        ((farmer[1] == 1) || (farmer[1] == 2) || (farmer[1] == j) || (farmer[1] == j+1) || (farmer[1] == j+2) || (farmer[1] == j-1) || (farmer[1] == j-2)) &&
                        ((farmer[2] == k) || (farmer[2] == k+1) || (farmer[2] == k+2) || (farmer[2] == k-1) || (farmer[2] == k-2))) {
                            count++;
                        }
                        else if (((master[0] == 1) || (master[0] == 2) || (master[0] == i) || (master[0] == i+1) || (master[0] == i+2) || (master[0] == i-1) || (master[0] == i-2))&&
                        ((master[1] == 1) || (master[1] == 2) || (master[1] == j) || (master[1] == j+1) || (master[1] == j+2) || (master[1] == j-1) || (master[1] == j-2)) &&
                        ((master[2] == 1) || (master[2] == 2) || (master[2] == k) || (master[2] == k+1) || (master[2] == k+2) || (master[2] == k-1) || (master[2] == k-2))) {
                            count++;
                        }
                    }
                    else if ((j==n) && (k==n)) {
                        if (((farmer[0] == i) || (farmer[0] == i+1) || (farmer[0] == i+2) || (farmer[0] == i-1) || (farmer[0] == i-2))&&
                        ((farmer[1] == 1) || (farmer[1] == 2) || (farmer[1] == j) || (farmer[1] == j+1) || (farmer[1] == j+2) || (farmer[1] == j-1) || (farmer[1] == j-2)) &&
                        ((farmer[2] == 1) || (farmer[2] == 2) || (farmer[2] == k) || (farmer[2] == k+1) || (farmer[2] == k+2) || (farmer[2] == k-1) || (farmer[2] == k-2))) {
                            count++;
                        }
                        else if (((master[0] == i) || (master[0] == i+1) || (master[0] == i+2) || (master[0] == i-1) || (master[0] == i-2))&&
                        ((master[1] == 1) || (master[1] == 2) || (master[1] == j) || (master[1] == j+1) || (master[1] == j+2) || (master[1] == j-1) || (master[1] == j-2)) &&
                        ((master[2] == 1) || (master[2] == 2) || (master[2] == k) || (master[2] == k+1) || (master[2] == k+2) || (master[2] == k-1) || (master[2] == k-2))) {
                            count++;
                        }
                    }
                    else if ((i==n)&&(k==n)) {
                        if (((farmer[0] == 1) || (farmer[0] == 2) || (farmer[0] == i) || (farmer[0] == i+1) || (farmer[0] == i+2) || (farmer[0] == i-1) || (farmer[0] == i-2))&&
                        ((farmer[1] == j) || (farmer[1] == j+1) || (farmer[1] == j+2) || (farmer[1] == j-1) || (farmer[1] == j-2)) &&
                        ((farmer[2] == 1) || (farmer[2] == 2) || (farmer[2] == k) || (farmer[2] == k+1) || (farmer[2] == k+2) || (farmer[2] == k-1) || (farmer[2] == k-2))) {
                            count++;
                        }
                        else if (((master[0] == 1) || (master[0] == 2) || (master[0] == i) || (master[0] == i+1) || (master[0] == i+2) || (master[0] == i-1) || (master[0] == i-2))&&
                        ((master[1] == j) || (master[1] == j+1) || (master[1] == j+2) || (master[1] == j-1) || (master[1] == j-2)) &&
                        ((master[2] == 1) || (master[2] == 2) || (master[2] == k) || (master[2] == k+1) || (master[2] == k+2) || (master[2] == k-1) || (master[2] == k-2))) {
                            count++;
                        }
                    }
                    else if (i==n) {
                        if (((farmer[0] == 1) || (farmer[0] == 2) || (farmer[0] == i) || (farmer[0] == i+1) || (farmer[0] == i+2) || (farmer[0] == i-1) || (farmer[0] == i-2))&&
                        ((farmer[1] == j) || (farmer[1] == j+1) || (farmer[1] == j+2) || (farmer[1] == j-1) || (farmer[1] == j-2)) &&
                        ((farmer[2] == k) || (farmer[2] == k+1) || (farmer[2] == k+2) || (farmer[2] == k-1) || (farmer[2] == k-2))) {
                            count++;
                        }
                        else if (((master[0] == 1) || (master[0] == 2) || (master[0] == i) || (master[0] == i+1) || (master[0] == i+2) || (master[0] == i-1) || (master[0] == i-2))&&
                        ((master[1] == j) || (master[1] == j+1) || (master[1] == j+2) || (master[1] == j-1) || (master[1] == j-2)) &&
                        ((master[2] == k) || (master[2] == k+1) || (master[2] == k+2) || (master[2] == k-1) || (master[2] == k-2))) {
                            count++;
                        }
                    }
                    else if (j==n) {
                        if (((farmer[0] == i) || (farmer[0] == i+1) || (farmer[0] == i+2) || (farmer[0] == i-1) || (farmer[0] == i-2))&&
                        ((farmer[1] == 1) || (farmer[1] == 2) || (farmer[1] == j) || (farmer[1] == j+1) || (farmer[1] == j+2) || (farmer[1] == j-1) || (farmer[1] == j-2)) &&
                        ((farmer[2] == k) || (farmer[2] == k+1) || (farmer[2] == k+2) || (farmer[2] == k-1) || (farmer[2] == k-2))) {
                            count++;
                        }
                        else if (((master[0] == i) || (master[0] == i+1) || (master[0] == i+2) || (master[0] == i-1) || (master[0] == i-2))&&
                        ((master[1] == 1) || (master[1] == 2) || (master[1] == j) || (master[1] == j+1) || (master[1] == j+2) || (master[1] == j-1) || (master[1] == j-2)) &&
                        ((master[2] == k) || (master[2] == k+1) || (master[2] == k+2) || (master[2] == k-1) || (master[2] == k-2))) {
                            count++;
                        }
                    }
                    else if (k==n) {
                        if (((farmer[0] == i) || (farmer[0] == i+1) || (farmer[0] == i+2) || (farmer[0] == i-1) || (farmer[0] == i-2))&&
                        ((farmer[1] == j) || (farmer[1] == j+1) || (farmer[1] == j+2) || (farmer[1] == j-1) || (farmer[1] == j-2)) &&
                        ((farmer[2] == 1) || (farmer[2] == 2) || (farmer[2] == k) || (farmer[2] == k+1) || (farmer[2] == k+2) || (farmer[2] == k-1) || (farmer[2] == k-2))) {
                            count++;
                        }
                        else if (((master[0] == i) || (master[0] == i+1) || (master[0] == i+2) || (master[0] == i-1) || (master[0] == i-2))&&
                        ((master[1] == j) || (master[1] == j+1) || (master[1] == j+2) || (master[1] == j-1) || (master[1] == j-2)) &&
                        ((master[2] == 1) || (master[2] == 2) || (master[2] == k) || (master[2] == k+1) || (master[2] == k+2) || (master[2] == k-1) || (master[2] == k-2))) {
                            count++;
                        }
                    }
                }
                else if ((i == 1) || (i == 2) || (j == 1) || (j == 2) || (k == 1) || (k == 2)) {
                    if ((i==1) && (j == 1) && (k==1)) {
                        if (((farmer[0] == n-1) || (farmer[0] == n-2) || (farmer[0] == i) || (farmer[0] == i+1) || (farmer[0] == i+2) || (farmer[0] == i-1) || (farmer[0] == i-2))&&
                        ((farmer[1] == n-1) || (farmer[1] == n-2) || (farmer[1] == j) || (farmer[1] == j+1) || (farmer[1] == j+2) || (farmer[1] == j-1) || (farmer[1] == j-2)) &&
                        ((farmer[2] == n-1) || (farmer[2] == n-2) || (farmer[2] == k) || (farmer[2] == k+1) || (farmer[2] == k+2) || (farmer[2] == k-1) || (farmer[2] == k-2))) {
                            count++;
                        }
                        else if (((master[0] == n-1) || (master[0] == n-2) || (master[0] == i) || (master[0] == i+1) || (master[0] == i+2) || (master[0] == i-1) || (master[0] == i-2))&&
                        ((master[1] == n-1) || (master[1] == n-2) || (master[1] == j) || (master[1] == j+1) || (master[1] == j+2) || (master[1] == j-1) || (master[1] == j-2)) &&
                        ((master[2] == n-1) || (master[2] == n-2) || (master[2] == k) || (master[2] == k+1) || (master[2] == k+2) || (master[2] == k-1) || (master[2] == k-2))) {
                            count++;
                        }
                    }
                    else if ((i==1) && (j == 1) && (k==2)) {
                        if (((farmer[0] == n-1) || (farmer[0] == n-2) || (farmer[0] == i) || (farmer[0] == i+1) || (farmer[0] == i+2) || (farmer[0] == i-1) || (farmer[0] == i-2))&&
                        ((farmer[1] == n-1) || (farmer[1] == n-2) || (farmer[1] == j) || (farmer[1] == j+1) || (farmer[1] == j+2) || (farmer[1] == j-1) || (farmer[1] == j-2)) &&
                        ((farmer[2] == n-1) || (farmer[2] == k) || (farmer[2] == k+1) || (farmer[2] == k+2) || (farmer[2] == k-1) || (farmer[2] == k-2))) {
                            count++;
                        }
                        else if (((master[0] == n-1) || (master[0] == n-2) || (master[0] == i) || (master[0] == i+1) || (master[0] == i+2) || (master[0] == i-1) || (master[0] == i-2))&&
                        ((master[1] == n-1) || (master[1] == n-2) || (master[1] == j) || (master[1] == j+1) || (master[1] == j+2) || (master[1] == j-1) || (master[1] == j-2)) &&
                        ((master[2] == n-1) || (master[2] == k) || (master[2] == k+1) || (master[2] == k+2) || (master[2] == k-1) || (master[2] == k-2))) {
                            count++;
                        }
                    }
                    else if ((i==1) && (j == 2) && (k==1)) {
                        if (((farmer[0] == n-1) || (farmer[0] == n-2) || (farmer[0] == i) || (farmer[0] == i+1) || (farmer[0] == i+2) || (farmer[0] == i-1) || (farmer[0] == i-2))&&
                        ((farmer[1] == n-1) || (farmer[1] == j) || (farmer[1] == j+1) || (farmer[1] == j+2) || (farmer[1] == j-1) || (farmer[1] == j-2)) &&
                        ((farmer[2] == n-1) || (farmer[2] == n-2) || (farmer[2] == k) || (farmer[2] == k+1) || (farmer[2] == k+2) || (farmer[2] == k-1) || (farmer[2] == k-2))) {
                            count++;
                        }
                        else if (((master[0] == n-1) || (master[0] == n-2) || (master[0] == i) || (master[0] == i+1) || (master[0] == i+2) || (master[0] == i-1) || (master[0] == i-2))&&
                        ((master[1] == n-1) || (master[1] == j) || (master[1] == j+1) || (master[1] == j+2) || (master[1] == j-1) || (master[1] == j-2)) &&
                        ((master[2] == n-1) || (master[2] == n-2) || (master[2] == k) || (master[2] == k+1) || (master[2] == k+2) || (master[2] == k-1) || (master[2] == k-2))) {
                            count++;
                        }
                    }
                    else if ((i==1) && (j == 2) && (k==2)) {
                        if (((farmer[0] == n-1) || (farmer[0] == n-2) || (farmer[0] == i) || (farmer[0] == i+1) || (farmer[0] == i+2) || (farmer[0] == i-1) || (farmer[0] == i-2))&&
                        ((farmer[1] == n-1) || (farmer[1] == j) || (farmer[1] == j+1) || (farmer[1] == j+2) || (farmer[1] == j-1) || (farmer[1] == j-2)) &&
                        ((farmer[2] == n-1) || (farmer[2] == k) || (farmer[2] == k+1) || (farmer[2] == k+2) || (farmer[2] == k-1) || (farmer[2] == k-2))) {
                            count++;
                        }
                        else if (((master[0] == n-1) || (master[0] == n-2) || (master[0] == i) || (master[0] == i+1) || (master[0] == i+2) || (master[0] == i-1) || (master[0] == i-2))&&
                        ((master[1] == n-1) || (master[1] == j) || (master[1] == j+1) || (master[1] == j+2) || (master[1] == j-1) || (master[1] == j-2)) &&
                        ((master[2] == n-1) || (master[2] == k) || (master[2] == k+1) || (master[2] == k+2) || (master[2] == k-1) || (master[2] == k-2))) {
                            count++;
                        }
                    }
                    else if ((i==2) && (j == 1) && (k==1)) {
                        if (((farmer[0] == n-1) || (farmer[0] == i) || (farmer[0] == i+1) || (farmer[0] == i+2) || (farmer[0] == i-1) || (farmer[0] == i-2))&&
                        ((farmer[1] == n-1) || (farmer[1] == n-2) || (farmer[1] == j) || (farmer[1] == j+1) || (farmer[1] == j+2) || (farmer[1] == j-1) || (farmer[1] == j-2)) &&
                        ((farmer[2] == n-1) || (farmer[2] == n-2) || (farmer[2] == k) || (farmer[2] == k+1) || (farmer[2] == k+2) || (farmer[2] == k-1) || (farmer[2] == k-2))) {
                            count++;
                        }
                        else if (((master[0] == n-1) || (master[0] == i) || (master[0] == i+1) || (master[0] == i+2) || (master[0] == i-1) || (master[0] == i-2))&&
                        ((master[1] == n-1) || (master[1] == n-2) || (master[1] == j) || (master[1] == j+1) || (master[1] == j+2) || (master[1] == j-1) || (master[1] == j-2)) &&
                        ((master[2] == n-1) || (master[2] == n-2) || (master[2] == k) || (master[2] == k+1) || (master[2] == k+2) || (master[2] == k-1) || (master[2] == k-2))) {
                            count++;
                        }
                    }
                    else if ((i==2) && (j == 1) && (k==2)) {
                        if (((farmer[0] == n-1) || (farmer[0] == i) || (farmer[0] == i+1) || (farmer[0] == i+2) || (farmer[0] == i-1) || (farmer[0] == i-2))&&
                        ((farmer[1] == n-1) || (farmer[1] == n-2) || (farmer[1] == j) || (farmer[1] == j+1) || (farmer[1] == j+2) || (farmer[1] == j-1) || (farmer[1] == j-2)) &&
                        ((farmer[2] == n-1) || (farmer[2] == k) || (farmer[2] == k+1) || (farmer[2] == k+2) || (farmer[2] == k-1) || (farmer[2] == k-2))) {
                            count++;
                        }
                        else if (((master[0] == n-1) ||  (master[0] == i) || (master[0] == i+1) || (master[0] == i+2) || (master[0] == i-1) || (master[0] == i-2))&&
                        ((master[1] == n-1) || (master[1] == n-2) || (master[1] == j) || (master[1] == j+1) || (master[1] == j+2) || (master[1] == j-1) || (master[1] == j-2)) &&
                        ((master[2] == n-1) ||  (master[2] == k) || (master[2] == k+1) || (master[2] == k+2) || (master[2] == k-1) || (master[2] == k-2))) {
                            count++;
                        }
                    }
                    else if ((i==2) && (j == 2) && (k==1)) {
                        if (((farmer[0] == n-1) || (farmer[0] == i) || (farmer[0] == i+1) || (farmer[0] == i+2) || (farmer[0] == i-1) || (farmer[0] == i-2))&&
                        ((farmer[1] == n-1) || (farmer[1] == j) || (farmer[1] == j+1) || (farmer[1] == j+2) || (farmer[1] == j-1) || (farmer[1] == j-2)) &&
                        ((farmer[2] == n-1) || (farmer[2] == n-2) || (farmer[2] == k) || (farmer[2] == k+1) || (farmer[2] == k+2) || (farmer[2] == k-1) || (farmer[2] == k-2))) {
                            count++;
                        }
                        else if (((master[0] == n-1) || (master[0] == i) || (master[0] == i+1) || (master[0] == i+2) || (master[0] == i-1) || (master[0] == i-2))&&
                        ((master[1] == n-1) || (master[1] == j) || (master[1] == j+1) || (master[1] == j+2) || (master[1] == j-1) || (master[1] == j-2)) &&
                        ((master[2] == n-1) || (master[2] == n-2) || (master[2] == k) || (master[2] == k+1) || (master[2] == k+2) || (master[2] == k-1) || (master[2] == k-2))) {
                            count++;
                        }
                    }
                    else if ((i==2) && (j == 2) && (k==2)) {
                        if (((farmer[0] == n-1) || (farmer[0] == i) || (farmer[0] == i+1) || (farmer[0] == i+2) || (farmer[0] == i-1) || (farmer[0] == i-2))&&
                        ((farmer[1] == n-1) || (farmer[1] == j) || (farmer[1] == j+1) || (farmer[1] == j+2) || (farmer[1] == j-1) || (farmer[1] == j-2)) &&
                        ((farmer[2] == n-1) || (farmer[2] == k) || (farmer[2] == k+1) || (farmer[2] == k+2) || (farmer[2] == k-1) || (farmer[2] == k-2))) {
                            count++;
                        }
                        else if (((master[0] == n-1) || (master[0] == i) || (master[0] == i+1) || (master[0] == i+2) || (master[0] == i-1) || (master[0] == i-2))&&
                        ((master[1] == n-1) || (master[1] == j) || (master[1] == j+1) || (master[1] == j+2) || (master[1] == j-1) || (master[1] == j-2)) &&
                        ((master[2] == n-1) || (master[2] == k) || (master[2] == k+1) || (master[2] == k+2) || (master[2] == k-1) || (master[2] == k-2))) {
                            count++;
                        }
                    }
                    else if (i==1) {
                        if (((farmer[0] == n-1) || (farmer[0] == n-2) || (farmer[0] == i) || (farmer[0] == i+1) || (farmer[0] == i+2) || (farmer[0] == i-1) || (farmer[0] == i-2))&&
                        ((farmer[1] == j) || (farmer[1] == j+1) || (farmer[1] == j+2) || (farmer[1] == j-1) || (farmer[1] == j-2)) &&
                        ((farmer[2] == k) || (farmer[2] == k+1) || (farmer[2] == k+2) || (farmer[2] == k-1) || (farmer[2] == k-2))) {
                            count++;
                        }
                        else if (((master[0] == n-1) || (master[0] == n-2) || (master[0] == i) || (master[0] == i+1) || (master[0] == i+2) || (master[0] == i-1) || (master[0] == i-2))&&
                        ((master[1] == j) || (master[1] == j+1) || (master[1] == j+2) || (master[1] == j-1) || (master[1] == j-2)) &&
                        ((master[2] == k) || (master[2] == k+1) || (master[2] == k+2) || (master[2] == k-1) || (master[2] == k-2))) {
                            count++;
                        }
                    }
                    else if (j==1) {
                        if (((farmer[0] == i) || (farmer[0] == i+1) || (farmer[0] == i+2) || (farmer[0] == i-1) || (farmer[0] == i-2))&&
                        ((farmer[1] == n-1) || (farmer[1] == n-2) || (farmer[1] == j) || (farmer[1] == j+1) || (farmer[1] == j+2) || (farmer[1] == j-1) || (farmer[1] == j-2)) &&
                        ((farmer[2] == k) || (farmer[2] == k+1) || (farmer[2] == k+2) || (farmer[2] == k-1) || (farmer[2] == k-2))) {
                            count++;
                        }
                        else if (((master[0] == i) || (master[0] == i+1) || (master[0] == i+2) || (master[0] == i-1) || (master[0] == i-2))&&
                        ((master[1] == n-1) || (master[1] == n-2) || (master[1] == j) || (master[1] == j+1) || (master[1] == j+2) || (master[1] == j-1) || (master[1] == j-2)) &&
                        ((master[2] == k) || (master[2] == k+1) || (master[2] == k+2) || (master[2] == k-1) || (master[2] == k-2))) {
                            count++;
                        }
                    }
                    else if (k==1) {
                        if (((farmer[0] == i) || (farmer[0] == i+1) || (farmer[0] == i+2) || (farmer[0] == i-1) || (farmer[0] == i-2))&&
                        ((farmer[1] == j) || (farmer[1] == j+1) || (farmer[1] == j+2) || (farmer[1] == j-1) || (farmer[1] == j-2)) &&
                        ((farmer[2] == n-1) || (farmer[2] == n-2) || (farmer[2] == k) || (farmer[2] == k+1) || (farmer[2] == k+2) || (farmer[2] == k-1) || (farmer[2] == k-2))) {
                            count++;
                        }
                        else if (((master[0] == i) || (master[0] == i+1) || (master[0] == i+2) || (master[0] == i-1) || (master[0] == i-2))&&
                        ((master[1] == j) || (master[1] == j+1) || (master[1] == j+2) || (master[1] == j-1) || (master[1] == j-2)) &&
                        ((master[2] == k) || (master[2] == k+1) || (master[2] == k+2) || (master[2] == k-1) || (master[2] == k-2))) {
                            count++;
                        }
                    }
                    else if (i==2) {
                        if (((farmer[0] == n-1) || (farmer[0] == i) || (farmer[0] == i+1) || (farmer[0] == i+2) || (farmer[0] == i-1) || (farmer[0] == i-2))&&
                        ((farmer[1] == j) || (farmer[1] == j+1) || (farmer[1] == j+2) || (farmer[1] == j-1) || (farmer[1] == j-2)) &&
                        ((farmer[2] == k) || (farmer[2] == k+1) || (farmer[2] == k+2) || (farmer[2] == k-1) || (farmer[2] == k-2))) {
                            count++;
                        }
                        else if (((master[0] == n-1) || (master[0] == i) || (master[0] == i+1) || (master[0] == i+2) || (master[0] == i-1) || (master[0] == i-2))&&
                        ((master[1] == j) || (master[1] == j+1) || (master[1] == j+2) || (master[1] == j-1) || (master[1] == j-2)) &&
                        ((master[2] == k) || (master[2] == k+1) || (master[2] == k+2) || (master[2] == k-1) || (master[2] == k-2))) {
                            count++;
                        }
                    }
                    else if (j==2) {
                        if (((farmer[0] == i) || (farmer[0] == i+1) || (farmer[0] == i+2) || (farmer[0] == i-1) || (farmer[0] == i-2))&&
                        ((farmer[1] == n-1) || (farmer[1] == j) || (farmer[1] == j+1) || (farmer[1] == j+2) || (farmer[1] == j-1) || (farmer[1] == j-2)) &&
                        ((farmer[2] == k) || (farmer[2] == k+1) || (farmer[2] == k+2) || (farmer[2] == k-1) || (farmer[2] == k-2))) {
                            count++;
                        }
                        else if (((master[0] == i) || (master[0] == i+1) || (master[0] == i+2) || (master[0] == i-1) || (master[0] == i-2))&&
                        ((master[1] == n-1) || (master[1] == j) || (master[1] == j+1) || (master[1] == j+2) || (master[1] == j-1) || (master[1] == j-2)) &&
                        ((master[2] == k) || (master[2] == k+1) || (master[2] == k+2) || (master[2] == k-1) || (master[2] == k-2))) {
                            count++;
                        }
                    }
                    else if (k==2) {
                        if (((farmer[0] == i) || (farmer[0] == i+1) || (farmer[0] == i+2) || (farmer[0] == i-1) || (farmer[0] == i-2))&&
                        ((farmer[1] == j) || (farmer[1] == j+1) || (farmer[1] == j+2) || (farmer[1] == j-1) || (farmer[1] == j-2)) &&
                        ((farmer[2] == n-1) || (farmer[2] == k) || (farmer[2] == k+1) || (farmer[2] == k+2) || (farmer[2] == k-1) || (farmer[2] == k-2))) {
                            count++;
                        }
                        else if (((master[0] == i) || (master[0] == i+1) || (master[0] == i+2) || (master[0] == i-1) || (master[0] == i-2))&&
                        ((master[1] == j) || (master[1] == j+1) || (master[1] == j+2) || (master[1] == j-1) || (master[1] == j-2)) &&
                        ((master[2] == n-1) ||(master[2] == k) || (master[2] == k+1) || (master[2] == k+2) || (master[2] == k-1) || (master[2] == k-2))) {
                            count++;
                        }
                    }
                }
            }
        }
    }
    cout << count;
}