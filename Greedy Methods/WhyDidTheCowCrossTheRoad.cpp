/**
Farmer John's cows are trying to learn to cross the road effectively. 
Remembering the old "why did the chicken cross the road?" joke, they 
figure the chickens must be experts on crossing the road, and go off 
in search of chickens to help them.

As it turns out, chickens are very busy creatures and have limited 
time to help the cows. There are C chickens on the farm (1 <= C <=
20,000), conveniently numbered 1...C, and each chicken i is only 
willing to help a cow at precisely time T_i. The cows, never in a 
hurry, have more flexibility in their schedules. There are N cows 
on the farm (1 <= N <= 20,000), conveniently numbered 1...N, where 
cow j is able to cross the road between time A_j and time B_j. 
Figuring the "buddy system" is the best way to proceed, each cow j 
would ideally like to find a chicken i to help her cross the road; 
in order for their schedules to be compatible, i and j must satisfy 
A_j <= T_i <= B_j.

If each cow can be paired with at most one chicken and each chicken 
with at most one cow, please help compute the maximum number of 
cow-chicken pairs that can be constructed.

PROBLEM NAME: helpcross

INPUT FORMAT:

The first line of input contains C and N. The next C lines contain 
T_1...T_C, and the next N lines contain A_j and B_j (A_j <= B_j) for 
j=1...N. The A's, B's, and T's are all non-negative integers (not 
necessarily distinct) of size at most 1,000,000,000.

OUTPUT FORMAT:

Please compute the maximum possible number of cow-chicken pairs.

SAMPLE INPUT:

5 4
7
8
6
2
9
2 5
4 9
0 3
8 13

SAMPLE OUTPUT:

3
*/
#include <iostream>
#include <algorithm>
using namespace std;
struct cowTime {
    int start, end;
    bool isDone;
};
bool comp (cowTime a, cowTime b) {
    return a.start < b.start;
}
int main() {
    int chicken, cow;
    cin >> chicken >> cow;
    
    int chickens[chicken];
    for (int i = 0; i < chicken; i++) {
        cin >> chickens[i];
    }
    
    cowTime cows[cow];
    for (int i = 0; i < cow; i++) {
        cin >> cows[i].start;
        cin >> cows[i].end;
        cows[i].isDone = false;
    }
    
    sort (chickens, chickens+chicken);
    sort (cows, cows+cow, comp);
    int count = 0;
    for (int i = 0; i < chicken; i++) {
        for (int j = 0; j < cow; j++) {
            if ((cows[j].start <= chickens[i]) && (cows[j].end >= chickens[i]) && (!(cows[j].isDone))) {
                count++;
                cows[j].isDone = true;
                break;
            }
        }
    }
    cout << count;
    
}