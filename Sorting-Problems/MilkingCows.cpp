/*
Three farmers rise at 5 am each morning and head for the barn to 
milk three cows. The first farmer begins milking his cow at time 
300 (measured in seconds after 5 am) and ends at time 1000. The 
second farmer begins at time 700 and ends at time 1200. The third 
farmer begins at time 1500 and ends at time 2100. The longest 
continuous time during which at least one farmer was milking a cow 
was 900 seconds (from 300 to 1200). The longest time no milking was 
done, between the beginning and the ending of all milking, was 300 
seconds (1500 minus 1200).

Your job is to write a program that will examine a list of beginning 
and ending times for N (1 <= N <= 5000) farmers milking N cows and 
compute (in seconds):

* The longest time interval at least one cow was milked.

* The longest time interval (after milking starts) during which no 
cows were being milked. 

PROGRAM NAME: milk2

INPUT FORMAT:

* Line 1: The single integer

* Lines 2..N+1: Two non-negative integers less than 1000000, the 
           starting and ending time in seconds after 0500

SAMPLE INPUT:

3
300 1000
700 1200
1500 2100

OUTPUT FORMAT:

A single line with two integers that represent the longest 
continuous time of milking and the longest idle time.

SAMPLE OUTPUT:

900 300
*/
#include <iostream>
#include <algorithm>
using namespace std;
struct Point{
    int start;
    int end;
};
bool comp(Point a, Point b) {
    return a.start < b.start;
}
int main() {
    int n;
    cin >> n;
    
    Point cows[n];
    for (int i = 0; i < n; i++) {
        cin >> cows[i].start;
        cin >> cows[i].end;
    }
    sort(cows, cows+n, comp);
    
    int maxNoTime = 0;
    int placeholder = 0;
    int maxCount = 0;
    int count = 0;
    int maxEnd = cows[0].end;
    for (int i = 0; i < (n-1); i++) {
        placeholder = 0;
        if (maxEnd <= cows[i+1].start) {
            if (cows[i].end < cows[i+1].start) {
               count = 0;
           }
           placeholder = abs(maxEnd-cows[i+1].start);
           
           if (maxCount < (count + abs(cows[i+1].start-cows[i+1].end))) {
               maxCount = count + abs(cows[i+1].start - cows[i+1].end);
           }
           
           if (maxEnd < cows[i+1].end) {
               maxEnd = cows[i+1].end;
           }
        }
        if (cows[i].end >= cows[i+1].start) {
            count += abs(cows[i].start - cows[i+1].start);
            if (maxCount < count) {
               maxCount = count;
            }
        }
        if (placeholder > maxNoTime) {
            maxNoTime = placeholder;
        }
        if (abs(cows[i].start-cows[i].end) > maxCount) {
               maxCount = abs(cows[i].start - cows[i].end);
        }
           
        if (abs(cows[i+1].start-cows[i+1].end) > maxCount) {
            maxCount = abs(cows[i+1].start - cows[i+1].end);
        }
        if (maxCount < count) {
               maxCount = count;
        }
    }
    if (n == 1) {
        cout << abs(cows[0].start - cows[0].end) << " ";
        cout << 0;
    }
    else {
        cout << maxCount << " ";
        cout << maxNoTime << endl;
    }
}