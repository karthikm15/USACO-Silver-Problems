/*
The cows are having their first election after overthrowing the
tyrannical Farmer John, and Bessie is one of N cows (1 <= N <=
50,000) running for President. Before the election actually happens,
however, Bessie wants to determine who has the best chance of
winning.

The election consists of two rounds. In the first round, the K cows
(1 <= K <= N) cows with the most votes advance to the second round.
In the second round, the cow with the most votes becomes President.

Given that cow i expects to get A_i votes (1 <= A_i <= 1,000,000,000)
in the first round and B_i votes (1 <= B_i <= 1,000,000,000) in the
second round (if he or she makes it), determine which cow is expected
to win the election. Happily for you, no vote count appears twice
in the A_i list; likewise, no vote count appears twice in the B_i
list.

PROBLEM NAME: elect

INPUT FORMAT:

* Line 1: Two space-separated integers: N and K

* Lines 2..N+1: Line i+1 contains two space-separated integers: A_i
        and B_i

SAMPLE INPUT:

5 3
3 10
9 2
5 6
8 4
6 5

INPUT DETAILS:

There are 5 cows, 3 of which will advance to the second round. The cows
expect to get 3, 9, 5, 8, and 6 votes, respectively, in the first round and
10, 2, 6, 4, and 5 votes, respectively, in the second.

OUTPUT FORMAT:

* Line 1: The index of the cow that is expected to win the election.

SAMPLE OUTPUT:

5

OUTPUT DETAILS:

Cows 2, 4, and 5 advance to the second round; cow 5 gets 5 votes in the
second round, winning the election.
*/
#include <iostream>
#include <algorithm>
using namespace std;
struct Point{
    int index, vote;
};
bool comp (Point a, Point b) {
    return a.vote > b.vote;
}
bool comp2 (Point a, Point b) {
    return a.vote > b.vote;
}
int main() {
    int ncow, kcow;
    cin >> ncow >> kcow;
    
    int kvote[kcow];
    Point ktwo[kcow];
    Point kcows[ncow];
    Point ncows[ncow];
    
    for (int i = 0; i < ncow; i++) {
        cin >> ncows[i].vote >> kcows[i].vote;
        ncows[i].index = i;
        kcows[i].index = i;
    }
    
    sort (ncows, ncows+ncow, comp);
    for (int i = 0; i < kcow; i++) {
        kvote[i] = ncows[i].index;
    }
    int counter = 0;
    for (int i = 0; i < ncow; i++) {
        bool isTrue = false;
        for (int j = 0; j < kcow; j++) {
            if (kcows[i].index == kvote[j]) {
                isTrue = true;
            }
        }
        if (isTrue) {
            ktwo[counter] = kcows[i];
            counter++;
        }
    }
    sort (ktwo, ktwo+kcow, comp2);
    cout << ktwo[0].index + 1;
}