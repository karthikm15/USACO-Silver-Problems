/*
Farmer John's N (1 <= N <= 1000) cows (conveniently numbered 1..N)
are going to play a game of Serious Cow Tag. In Serious Cow Tag,
each cow chooses a grid point in the pasture (-7500 <= X <= 7500,
-7500 <= Y <= 7500) such that the distances between all pairs of
cows are unique.

The cows play in turn, starting with cow #1 and continuing with
cows #2, #3, and so on (as long as the cow is still in the game).
When it is a cow's turn to play, she finds the nearest cow still
playing, ambles over to that cow to tag her, and then returns to
her original location. As soon as a cow is tagged, she is out of
the game.

The game ends when only one cow remains, and she is declared the
winner.

Farmer John is taking bets with neighboring farmers as to which cow
will win, so he would like to know the winner in advance. Write a
program that will read a description of the cows' positions and
determine the winner.

PROBLEM NAME: cowtag

INPUT FORMAT:

* Line 1: A single integer N, the number of cows

* Lines 2..N+1: Line i+1 contains two space-separated integers that
        describe the location of cow i.

SAMPLE INPUT:

3
0 0
0 3
4 3

INPUT DETAILS:

Three cows at (0, 0), (0, 3) and (4, 3).

OUTPUT FORMAT:

* Line 1: The number of the winning cow.

SAMPLE OUTPUT:

3

OUTPUT DETAILS:

Cow 1 goes first and tags the nearest cow, cow 2. Cow 2 is eliminated
so she does not get a turn. Cow 3 then tags the only remaining cow,
cow 1.  She is the last cow left, so she wins.
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
struct Point{
    int start, end;
};
struct Point2 {
    int distance;
    int index;
};
bool comp(Point2 a, Point2 b) {
    return a.distance > b.distance;
}
int main() {
    int n;
    cin >> n;
    
    Point cows[n];
    Point cows1[n];
    
    for (int i = 0; i < n; i++) {
        cin >> cows[i].start >> cows[i].end;
        cows1[i].start = cows[i].start;
        cows1[i].end = cows[i].end;
    }
    vector<Point2> distances;
    vector<Point2> noUse;
    double square1, square2;
    double distance;
    square1 = 0;
    square2 = 0;
    distance = 0;
    for (int i = 0; i < n; i++) {
        bool isIn = false;
        if (noUse.size() == (n-1)) {
            break;
        }
        for (vector<Point2>:: iterator j = noUse.begin(); j != noUse.end(); j++) {
            if (((*j).index) == i) {
                isIn = true;
            }
        }
        if (!isIn){
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    square1 = pow(abs((cows[i].start)-(cows[j].start)), 2);
                    square2 = pow(abs(cows[i].end-cows[j].end), 2);
                    
                    distance = sqrt(square1+square2);
                    distances.push_back({distance, j});
                }
            }
            int n = sizeof(distances)/sizeof(distances[0]); 
            sort(distances, distances+n, comp);
        
            for (vector<Point2>:: iterator j = distances.begin(); j != distances.end(); j++) {
                noUse.push_back(*j);
                break;
            }
        }
    }
}