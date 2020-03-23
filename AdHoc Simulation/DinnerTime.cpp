/**
Farmer John's N (1 <= N <= 1,000) cows conveniently numbered 1..N
are participating in the IOI in Bulgaria. The cows like the Bulgarian
sun and are enjoying their holiday. All seems well.

This changes around dinner time. The restaurant is rather small,
having only M (1 <= M <= N) cow seats conveniently numbered 1..M.
Each cow starts at a location CX_i, CY_i (-1,000,000 <= CX_i <=
1,000,000; -1,000,000 <= CY_i <= 1,000,000); the seats can be found
at SX_j, SY_j (-1,000,000 <= SX_j <= 1,000,000; -1,000,000 <= SY_j
<= 1,000,000).

The cows have a very efficient (though primitive) method to distribute
themselves into the seats. As soon as a cow is certain she will get
to a seat first, she rushes there as fast as she can (all cows runs
equally fast).

Farmer John's cows, like all prize cows, have no problem jumping
over seats, tables, or other cows, so they can run in a straight
line. When multiple cows can reach a seat at the very same time,
the oldest cow (the one appearing earlier in the input data) gets
the seat.  Likewise, when a cow can be the first to reach multiple
seats she will also choose the one appearing earliest in the input.

Some cows won't be able to eat dinner, and those hungry cows are
collectively planning to steal Farmer John's very own food. Farmer
John would like a list of cows he should be wary of. (In the case
when there are no hungry cows, output 0). Can you help him?

NOTE: Standard distance calculations will likely require an
intermediate result that will fit into a 64-bit integer but not
into a 32-bit integer.

PROBLEM NAME: dinner

INPUT FORMAT:

* Line 1: Two space-separated integers: N and M

* Lines 2..N+1: Line i+1 contains two space separated integers: CX_i
        and CY_i

* Lines N+2..N+M+1: Line j+N+1 contains two space separated integers:
        SX_j and SY_j

SAMPLE INPUT:

2 1
0 1
1 0
1 10

INPUT DETAILS:

2 cows: Cow 1 starts at (0, 1) and cow 2 at (1, 0). There
is only 1 seat at (1, 10).

OUTPUT FORMAT:

* Lines 1..N-M: Line i contains the number of the ith cow that Farmer
        John should be wary of. The cow numbers should be listed in
        increasing order.

SAMPLE OUTPUT:

2

OUTPUT DETAILS:

Cow 1 is closer to the seat than cow 2, so cow 1 will get the only seat.
*/
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

struct Position{
    int x, y;
};
int main() {
    int cows, seats;
    cin >> cows >> seats;
    Position cow[cows];
    Position seat[seats];
    
    for (int i = 0; i < cows; i++) {
        cin >> cow[i].x >> cow[i].y;
    }
    for (int i = 0; i < seats; i++) {
        cin>> seat[i].x >> seat[i].y;
    }
    
    double minimum[cows][seats];
    for (int i = 0; i < cows; i++) {
        for (int j = 0; j < seats; j++) {
            minimum[i][j] = sqrt(pow((cow[i].x - seat[j].x), 2) + pow((cow[i].y - seat[j].y), 2));
        }
    }
    vector<int> nonsuspicious;
    for (int i = 0; i < seats; i++) {
        double min = 10000000;
        int index = 0;
        for (int j = 0; j < cows; j++) {
            if ((minimum[j][i] < min) && (!(find(nonsuspicious.begin(), nonsuspicious.end(), j+1) != nonsuspicious.end()))) {
                min = minimum[j][i];
                index = j;
            }
        } 
        nonsuspicious.push_back(index+1);
    }
    if (nonsuspicious.size() == cows) {
        cout << 0 << endl;
    }
    else {
        for (int i = 1; i < (cows+1); i++) {
            if (!(find(nonsuspicious.begin(), nonsuspicious.end(), i) != nonsuspicious.end())) {
                cout << i << endl;
            }
        }
    }

}